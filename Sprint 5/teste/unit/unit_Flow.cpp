#include "unit_Flow.h"
#include <assert.h>
#include "..\..\src\flowImp.h"
#include "..\..\src\systemImp.h"
#include <cmath>

//classe criada para realizar os testes pois flow nao pode ser instanciada
class ExponentialFlow : public FlowImp{
    public:
        ExponentialFlow(string nome, System* origin, System* destiny) : FlowImp(nome, origin, destiny){}
        virtual double execute(){
            return 0.01 * getOrigin()->getValue();
        }
};

void unit_Flow_constructor( void){
    Flow* f1 = new ExponentialFlow("f1", NULL, NULL);
    assert( f1->getName() == "f1" );
    assert( f1->getOrigin() == NULL );
    assert( f1->getDestiny() == NULL );
    delete f1;
}

void unit_Flow_destructor( void){
}

//Origin
void unit_Flow_setOrigin( void){
    Flow* f1 = new ExponentialFlow("f1", NULL, NULL);
    System* s1 = new SystemImp;

    f1->setOrigin(s1);
    assert(f1->getOrigin() == s1);
    delete f1;
    delete s1;
}

void unit_Flow_getOrigin( void){
    System* s1 = new SystemImp;
    Flow* f1 = new ExponentialFlow("f1", s1, NULL);

    assert(f1->getOrigin() == s1);
    delete f1;
    delete s1;
}

//Destiny
void unit_Flow_setDestiny( void){
    Flow* f1 = new ExponentialFlow("f1", NULL, NULL);
    System* s1 = new SystemImp;

    f1->setDestiny(s1);
    assert(f1->getDestiny() == s1);
    delete f1;
    delete s1;
}

void unit_Flow_getDestiny( void){
    System* s1 = new SystemImp;
    Flow* f1 = new ExponentialFlow("f1", NULL, s1);

    assert(f1->getDestiny() == s1);
    delete f1;
    delete s1;
}

//Name
void unit_Flow_getName( void){
    Flow* f1 = new ExponentialFlow("f1", NULL, NULL);
    assert( f1->getName() == "f1" );
    delete f1;
}

void unit_Flow_setName( void ){
    Flow* f1 = new ExponentialFlow("test", NULL, NULL);
    f1->setName("f1");

    assert( f1->getName() == "f1" );
    delete f1;
}

//Clear
void unit_Flow_clearDestiny( void){
    System* s1 = new SystemImp;
    Flow* f1 = new ExponentialFlow("f1", NULL, s1);

    f1->clearDestiny();
    assert(f1->getDestiny() == NULL);
    delete f1;
    delete s1;
}
void unit_Flow_clearOrigin( void){
    System* s1 = new SystemImp;
    Flow* f1 = new ExponentialFlow("f1", s1, NULL);

    f1->clearOrigin();
    assert(f1->getOrigin() == NULL);
    delete f1;
    delete s1;
}

//Execute
void unit_Flow_execute( void){
    System* pop1 = new SystemImp(100, "pop1");
    System* pop2 = new SystemImp(0, "pop2"); 

    Flow* f1 = new ExponentialFlow("f1", pop1, pop2);

    assert(fabs(f1->execute()) == 1);
    delete f1;
    delete pop1;
    delete pop2;
}

void run_unit_tests_Flow( void ){
    unit_Flow_constructor();
    unit_Flow_destructor();
    unit_Flow_setOrigin();
    unit_Flow_getOrigin();
    unit_Flow_setDestiny();
    unit_Flow_getDestiny();
    unit_Flow_getName();
    unit_Flow_setName();
    unit_Flow_clearDestiny();
    unit_Flow_clearOrigin();
    unit_Flow_execute();
}