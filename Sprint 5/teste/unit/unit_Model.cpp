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

void unit_Model_destructor( void){
}

//Usando um teste funcional como o exponencial para dar realizar a verificacao do metodo run
void unit_Model_run( void){
    Model& model1 = Model::createModel("exponentialModel");
    
    System& pop1 = model1.createSystem("pop1", 100);
    System& pop2 = model1.createSystem("pop2", 0);

    Flow& f1 = model1.createFlow<ExponentialFlow>("f1", &pop1, &pop2);
   
    model1.run(0, 100, 1);

    assert(fabs(round((pop1.getValue() - 36.6032)*10000)) < 1);
    assert(fabs(round((pop2.getValue() - 63.3968)*10000)) < 1);

    delete &model1;
}

void unit_Model_add(void){
    Model& model1 = Model::createModel("test");

    System& s1 = model1.createSystem("s1", 0);
    
    Flow& f1 = model1.createFlow<ExponentialFlow>("f1", NULL, NULL);

    Model::flowIterator itFlow = model1.beginFlow();
    Model::systemIterator itSystem = model1.beginSystem();

    assert((*itFlow) ==  &f1);
    assert((*itSystem) ==  &s1);

    delete &model1;
}

//System vector
void unit_Model_beginSystem(void){
    Model& model1 = Model::createModel("test");
    System& s1 = model1.createSystem("s1", 0);

    Model::systemIterator itSystem = model1.beginSystem();
    assert((*itSystem) ==  &s1);

    delete &model1;
}

void unit_Model_endSystem(void){
    Model& model1 = Model::createModel("test");
    System& s1 = model1.createSystem("s1", 0);
    System& s2 = model1.createSystem("s2", 0);

    Model::systemIterator itSystem = model1.endSystem();
    itSystem--;
    assert((*itSystem) == &s2);

    delete &model1;
}

//Flow vector
void unit_Model_beginFlow(void){
    Model& model1 = Model::createModel("test");
    Flow& f1 = model1.createFlow<ExponentialFlow>("f1", NULL, NULL);

    Model::flowIterator itFlow = model1.beginFlow();
    assert((*itFlow) ==  &f1);

    delete &model1;
}
void unit_Model_endFlow(void){
    Model& model1 = Model::createModel("test");
    Flow& f1 = model1.createFlow<ExponentialFlow>("f1", NULL, NULL);
    Flow& f2 = model1.createFlow<ExponentialFlow>("f2", NULL, NULL);

    Model::flowIterator itFlow = model1.endFlow();
    itFlow--;
    assert((*itFlow) ==  &f2);

    delete &model1;
}

//Model vector
void unit_Model_beginModel(void){
    Model& model1 = Model::createModel("test");

    Model::modelIterator itModel = model1.beginModel();
    assert((*itModel) == &model1);

    delete &model1;
}
void unit_Model_endModel(void){
    Model& model1 = Model::createModel("test");
    Model& model2 = Model::createModel("test2");

    Model::modelIterator itModel = model1.endModel();
    itModel--;
    assert((*itModel) == &model2);

    delete &model1;
    delete &model2;
}

void unit_Model_createModel(void){
    Model& model1 = Model::createModel("test");

    Model::modelIterator itModel = model1.beginModel();
    assert((*itModel) == &model1);

    delete &model1;
}

void unit_Model_createSystem(void){
    Model& model1 = Model::createModel("test");
    System& sys = model1.createSystem("sys", 0);

    Model::systemIterator itSystem = model1.beginSystem();
    assert((*itSystem) ==  &sys);

    delete &model1;
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
    unit_Model_beginModel();
    unit_Model_endModel();
    unit_Model_createModel();
    unit_Model_createSystem();
}
