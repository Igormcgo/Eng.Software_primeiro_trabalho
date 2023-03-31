#include "systemImp.h"

//constructors and destructors
//public 
SystemImp::SystemImp(){
    value = 0;
}
SystemImp::SystemImp(double value, string name){
    this->name = name;
    this->value = value;
}
SystemImp::~SystemImp(){}

//getters and setters
void SystemImp::setValue(double value){
    this->value = value;
}
void SystemImp::setName(string name){
    this->name = name;
}
double SystemImp::getValue(void) const{
    return this->value;
}
string SystemImp::getName(void) const{
    return this->name;
}

//private
SystemImp::SystemImp(const SystemImp& sys){
    this->value = sys.getValue();
    this->name = sys.getName();
}

SystemImp& SystemImp::operator= (const SystemImp& sys){
    if(this == &sys)
        return *this;
    
    //verificacao
    this->name = sys.getName();
    this->value = sys.getValue();
    return *this;
}