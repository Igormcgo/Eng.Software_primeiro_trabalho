#include "unit_System.h"
#include <assert.h>
#include "..\..\src\systemImp.h"

void unit_System_constructor( void){
        System* s1 = new SystemImp;
        assert( s1->getValue() == 0 );
        System* s2 = new SystemImp(10,"s2");
        assert( s2->getValue() == 10 );
        assert( s2->getName() == "s2" );
        delete s1;
        delete s2;
}

void unit_System_destructor( void){ };

//Value
void unit_System_getValue( void){
        System* s = new SystemImp(10,"s");
        assert( s->getValue() == 10 );
        delete s;
}

void unit_System_setValue( void ) {
        System* s = new SystemImp;
        s->setValue(100);
        assert( s->getValue() == 100 );
        delete s;
}

//Name
void unit_System_getName( void){
        System* s = new SystemImp(10,"s");
        assert( s->getName() == "s" );
        delete s;
}

void unit_System_setName( void ) {
        System* s = new SystemImp;
        s->setName("s");
        assert( s->getName() == "s" );
        delete s;
}


void run_unit_tests_System( void ){
        unit_System_constructor();
        unit_System_destructor();
        unit_System_getValue();
        unit_System_setValue();
        unit_System_getName();
        unit_System_setName();
}