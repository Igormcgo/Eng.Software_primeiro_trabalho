#include "flowImp.h"

//constructors and destructors
//public 
FlowImp::FlowImp(){}
FlowImp::FlowImp(string name, System* origin, System* destiny){
    this->name = name;
    this->origin = origin;
    this->destiny = destiny;
}
FlowImp::~FlowImp(){}

//getters and setters
void FlowImp::setOrigin(System* origin){
    this->origin = origin;
}

void FlowImp::setDestiny(System* destiny){
    this->destiny = destiny;
}

void FlowImp::setName(string name){
    this->name = name;
}

System* FlowImp::getOrigin(void) const{
    return this->origin;
}

System* FlowImp::getDestiny(void) const{
    return this->destiny;
}

string FlowImp::getName(void) const{
    return this->name;
}

void FlowImp::clearOrigin(void){
    this->origin = NULL;
}

void FlowImp::clearDestiny(void){
    this->destiny = NULL;
}

//private
FlowImp::FlowImp(const FlowImp& flow){
    this->origin = flow.getOrigin();
    this->destiny = flow.getDestiny();
    this->name = flow.getName();
}

FlowImp& FlowImp::operator= (const FlowImp& flow){
    if(this == &flow)
        return *this;
    
    this->origin = flow.getOrigin();
    this->destiny = flow.getDestiny();
    this->name = flow.getName();
    return *this;
}

