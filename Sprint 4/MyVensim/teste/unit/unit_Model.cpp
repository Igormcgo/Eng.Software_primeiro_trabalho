#include "unit_Model.h"
#include <assert.h>
#include <cmath>
#include "..\..\src\flowImp.h"
#include "..\..\src\systemImp.h"
#include "..\..\src\modelImp.h"

class ExponentialFlow : public FlowImp{
    public:
        ExponentialFlow(string nome, System* origin, System* destiny) : FlowImp(nome, origin, destiny){}
        virtual double execute(){
            return 0.01 * getOrigin()->getValue();
        }
};

void unit_Model_constructor( void){}
void unit_Model_destructor( void){}

//Usando um teste funcional como o exponencial para dar realizar a verificacao do metodo run
void unit_Model_run( void){
    System* pop1 = new SystemImp(100, "pop1");
    System* pop2 = new SystemImp(0, "pop2");

    Flow* f1 = new ExponentialFlow("f1", pop1, pop2);

    Model* model1 = new ModelImp;
    model1->add(pop1);
    model1->add(pop2);
    model1->add(f1);

    model1->run(0, 100, 1);

    assert(fabs(round((pop1->getValue() - 36.6032)*10000)) < 1);
    assert(fabs(round((pop2->getValue() - 63.3968)*10000)) < 1);

    delete pop1;
    delete pop2;
    delete f1;
    delete model1;
}

void unit_Model_add(void){
    System* s1 = new SystemImp;
    Flow* f1 = new ExponentialFlow ("f1", NULL, NULL);

    Model* model = new ModelImp;
    model->add(s1);
    model->add(f1);

    Model::flowIterator itFlow = model->beginFlow();
    Model::systemIterator itSystem = model->beginSystem();

    assert((*itFlow) ==  f1);
    assert((*itSystem) ==  s1);
    delete s1;
    delete f1;
}

//System vector
void unit_Model_beginSystem(void){
    System* s1 = new SystemImp;
    Model* model = new ModelImp;
    model->add(s1);

    Model::systemIterator itSystem = model->beginSystem();
    assert((*itSystem) ==  s1);
    delete s1;
    delete model;
}
void unit_Model_endSystem(void){
    System* s1 = new SystemImp;
    System* s2 = new SystemImp;
    Model* model = new ModelImp;
    model->add(s1);
    model->add(s2);

    Model::systemIterator itSystem = model->endSystem();
    itSystem--;
    assert((*itSystem) == s2);
    delete s1;
    delete s2;
    delete model;
}

//Flow vector
void unit_Model_beginFlow(void){
    Flow* f1 = new ExponentialFlow ("f1", NULL, NULL);
    Model* model = new ModelImp;
    model->add(f1);

    Model::flowIterator itFlow = model->beginFlow();
    assert((*itFlow) ==  f1);
    delete f1;
    delete model;
}
void unit_Model_endFlow(void){
    Flow* f1 = new ExponentialFlow ("f1", NULL, NULL);
    Flow* f2 = new ExponentialFlow ("f2", NULL, NULL);
    Model* model = new ModelImp;
    model->add(f1);
    model->add(f2);

    Model::flowIterator itFlow = model->endFlow();
    itFlow--;
    assert((*itFlow) ==  f2);
    delete f1;
    delete f2;
    delete model;
}

void run_unit_tests_Model( void ){
    unit_Model_constructor();
    unit_Model_destructor();
    unit_Model_run();
    unit_Model_add();
    unit_Model_beginSystem();
    unit_Model_endSystem();
    unit_Model_beginFlow();
    unit_Model_endFlow();
}
