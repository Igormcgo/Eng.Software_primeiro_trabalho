#include "system.h"

//constructors and destructors
//public 
System::System(){}
System::System(double value, string name){
    this->name = name;
    this->value = value;
}
System::~System(){}

//getters and setters
void System::setValue(double value){
    this->value = value;
}
void System::setName(string name){
    this->name = name;
}
double System::getValue(void){
    return this->value;
}
string System::getName(void){
    return this->name;
}

//private
System::System(const System& sys){
    this->value = sys.value;
    this->name = sys.name;
}

System& System::operator= (const System& sys){
    if(this == &sys)
        return *this;
    
    //verificacao
    this->name = sys.name;
    this->value = sys.value;
    return *this;
}