#include "model.h"
#include "modelImp.h"
#include "flowImp.h"
#include "systemImp.h"

vector<Model*> ModelImp::models;

Model& Model::createModel(string name){
    return ModelImp::createModel(name);
}

Model& ModelImp::createModel(string name){
    Model* m = new ModelImp(name);
    models.push_back(m);
    return *m;
}

System& ModelImp::createSystem(string name, double value){
    System* sys = new SystemImp(value,name);
    add(sys);
    return *sys;
}

//constructors and destructors
//public
ModelImp::ModelImp(string name1){
    name = name1;
}

ModelImp::ModelImp(){}
ModelImp::~ModelImp(){
    for(flowIterator it = beginFlow(); it < endFlow(); it++){
        delete *it;
    }
    for(systemIterator it = beginSystem(); it < endSystem(); it++){
        delete *it;
    }

    for(modelIterator it = beginModel(); it< endModel(); it++){
        if((*it) == this){
            models.erase(it);
            break;
        }
    }
}

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

Model::systemIterator ModelImp::beginSystem(){
    return systems.begin();
}
Model::systemIterator ModelImp::endSystem(){
    return systems.end();
}
Model::flowIterator ModelImp::beginFlow(){
    return flows.begin();
}
Model::flowIterator ModelImp::endFlow(){
    return flows.end();
}
Model::modelIterator ModelImp::beginModel(){
    return models.begin();
}
        
Model::modelIterator ModelImp::endModel(){
    return models.end();
}

//private
ModelImp::ModelImp(const ModelImp& model){
    for(std::vector<Flow *>::const_iterator i = model.flows.begin(); i < model.flows.end(); i++){
        add(*i);
    }

    for(std::vector<System *>::const_iterator i = model.systems.begin(); i < model.systems.end(); i++){
        add(*i);
    }
}

ModelImp& ModelImp::operator= (const ModelImp& model){
    if(this == &model)
        return *this;
        
    for(std::vector<Flow *>::const_iterator i = model.flows.begin(); i < model.flows.end(); i++){
        add(*i);
    }

    for(std::vector<System *>::const_iterator i = model.systems.begin(); i < model.systems.end(); i++){
        add(*i);
    }
    return *this;
}

void ModelImp::add(System* sys){
    systems.push_back(sys);
}

void ModelImp::add(Flow* flow){
    flows.push_back(flow);
}

void ModelImp::add(Model* m){
    models.push_back(m);
}