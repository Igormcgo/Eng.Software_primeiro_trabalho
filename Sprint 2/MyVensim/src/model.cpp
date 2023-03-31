#include "model.h"

//constructors and destructors
//public
Model::Model(){}
Model::~Model(){}

void Model::run(double initial, double end, double iteration){
    vector<double> values;

    for(int i = initial; i < end; i=i+iteration){    
        for(flowIterator it = beginFlow(); it < endFlow(); it++){
            values.push_back((*it)->execute());
        }

        vector<double>::iterator valuesIterator = values.begin();

        for(flowIterator it = beginFlow(); it < endFlow(); it++){
            (*it)->getOrigin()->setValue((*it)->getOrigin()->getValue() - (*valuesIterator));
            (*it)->getDestiny()->setValue((*it)->getDestiny()->getValue() + (*valuesIterator));
            valuesIterator++;
        }
        
        values.clear();
    }
}

void Model::add(System* sys){
    system.push_back(sys);
}

void Model::add(Flow* flow1){
    flow.push_back(flow1);
}

Model::systemIterator Model::beginSystem(){
    return system.begin();
}
Model::systemIterator Model::endSystem(){
    return system.end();
}
Model::flowIterator Model::beginFlow(){
    return flow.begin();
}
Model::flowIterator Model::endFlow(){
    return flow.end();
}

//private
Model::Model(const Model& model){
    for(std::vector<Flow *>::const_iterator i = model.flow.begin(); i < model.flow.end(); i++){
        add(*i);
    }

    for(std::vector<System *>::const_iterator i = model.system.begin(); i < model.system.end(); i++){
        add(*i);
    }
}

Model& Model::operator= (const Model& model){
    if(this == &model)
        return *this;
        
    for(std::vector<Flow *>::const_iterator i = model.flow.begin(); i < model.flow.end(); i++){
        add(*i);
    }

    for(std::vector<System *>::const_iterator i = model.system.begin(); i < model.system.end(); i++){
        add(*i);
    }
    return *this;
}

