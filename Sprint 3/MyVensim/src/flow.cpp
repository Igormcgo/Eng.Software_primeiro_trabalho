#include "flow.h"
#include "system.h"

//constructors and destructors
//public 
Flow::Flow(){}
Flow::Flow(string name, System* origin, System* destiny){
    this->name = name;
    this->origin = origin;
    this->destiny = destiny;
}
Flow::~Flow(){}

//getters and setters
void Flow::setOrigin(System* origin){
    this->origin = origin;
}

void Flow::setDestiny(System* destiny){
    this->destiny = destiny;
}

void Flow::setName(string name){
    this->name = name;
}

System* Flow::getOrigin(void){
    return this->origin;
}

System* Flow::getDestiny(void){
    return this->destiny;
}

string Flow::getName(void){
    return this->name;
}

void Flow::clearOrigin(void){
    this->origin = NULL;
}

void Flow::clearDestiny(void){
    this->destiny = NULL;
}

//private
Flow::Flow(const Flow& flow){
    this->origin = flow.origin;
    this->destiny = flow.destiny;
    this->name = flow.name;
}

Flow& Flow::operator= (const Flow& flow){
    if(this == &flow)
        return *this;
    
    this->origin = flow.origin;
    this->destiny = flow.destiny;
    this->name = flow.name;
    return *this;
}

