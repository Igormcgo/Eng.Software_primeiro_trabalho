#include "funcional_tests.h"
#include <iostream>
#include <cmath>

void exponentialFuncionalTest(){
    Model& model1 = Model::createModel("exponentialModel");
    
    System& pop1 = model1.createSystem("pop1", 100);
    System& pop2 = model1.createSystem("pop2", 0);

    Flow& f1 = model1.createFlow<ExponentialFlow>("f1", &pop1, &pop2);
   
    model1.run(0, 100, 1);

    assert(fabs(round((pop1.getValue() - 36.6032)*10000)) < 1);
    assert(fabs(round((pop2.getValue() - 63.3968)*10000)) < 1);

    delete &model1;
}

void logisticalFuncionalTest(){
    Model& model1 = Model::createModel("logisticalModel");
    
    System& pop1 = model1.createSystem("pop1", 100);
    System& pop2 = model1.createSystem("pop2", 10);

    Flow& f1 = model1.createFlow<LogisticFlow>("f1", &pop1, &pop2);

    model1.run(0, 100, 1);
    
    assert(fabs(round((pop1.getValue() - 88.2167)*10000)) < 1);
    assert(fabs(round((pop2.getValue() - 21.7833)*10000)) < 1);

    delete &model1;
}

void complexFuncionalTest(){
    Model& model1 = Model::createModel("complexModel");

    System& q1 = model1.createSystem("q1", 100);
    System& q2 = model1.createSystem("q2", 0);
    System& q3 = model1.createSystem("q3", 100);
    System& q4 = model1.createSystem("q4", 0);
    System& q5 = model1.createSystem("q5", 0);
    
    Flow& f = model1.createFlow<ModelFlow>("f", &q1, &q2);
    Flow& g = model1.createFlow<ModelFlow>("g", &q1, &q3);
    Flow& r = model1.createFlow<ModelFlow>("r", &q2, &q5);
    Flow& t = model1.createFlow<ModelFlow>("t", &q2, &q3);
    Flow& u = model1.createFlow<ModelFlow>("u", &q3, &q4);
    Flow& v = model1.createFlow<ModelFlow>("v", &q4, &q1);

    model1.run(0, 100, 1);

    assert(fabs(round((q1.getValue() - 31.8513) *10000)) < 1);
    assert(fabs(round((q2.getValue() - 18.4003) *10000)) < 1);
    assert(fabs(round((q3.getValue() - 77.1143) *10000)) < 1);
    assert(fabs(round((q4.getValue() - 56.1728) *10000)) < 1);
    assert(fabs(round((q5.getValue() - 16.4612) *10000)) < 1);

    delete &model1;
}