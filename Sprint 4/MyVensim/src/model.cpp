#include "modelImp.h"

//constructors and destructors
//public
ModelImp::ModelImp(){}
ModelImp::~ModelImp(){}

void ModelImp::run(double initial, double end, double iteration){
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

void ModelImp::add(System* sys){
    system.push_back(sys);
}

void ModelImp::add(Flow* flow1){
    flow.push_back(flow1);
}

Model::systemIterator ModelImp::beginSystem(){
    return system.begin();
}
Model::systemIterator ModelImp::endSystem(){
    return system.end();
}
Model::flowIterator ModelImp::beginFlow(){
    return flow.begin();
}
Model::flowIterator ModelImp::endFlow(){
    return flow.end();
}

//private
ModelImp::ModelImp(const ModelImp& model){
    for(std::vector<Flow *>::const_iterator i = model.flow.begin(); i < model.flow.end(); i++){
        add(*i);
    }

    for(std::vector<System *>::const_iterator i = model.system.begin(); i < model.system.end(); i++){
        add(*i);
    }
}

ModelImp& ModelImp::operator= (const ModelImp& model){
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

