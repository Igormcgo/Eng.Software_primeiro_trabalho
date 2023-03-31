#include "funcional_tests.h"
#include <iostream>
#include <cmath>

void exponentialFuncionalTest(){
    System pop1(100, "pop1");
    System pop2(0, "pop2");

    ExponentialFlow f1("f1", &pop1, &pop2);

    Model model1;
    model1.add(&pop1);
    model1.add(&pop2);
    model1.add(&f1);

    model1.run(0, 100, 1);

    assert(fabs(round((pop1.getValue() - 36.6032)*10000)) < 1);
    assert(fabs(round((pop2.getValue() - 63.3968)*10000)) < 1);
}

void logisticalFuncionalTest(){
    System pop1(100, "pop1");
    System pop2(10, "pop2");

    LogisticFlow f1("f1", &pop1, &pop2);

    Model model1;
    model1.add(&pop1);
    model1.add(&pop2);
    model1.add(&f1);

    model1.run(0, 100, 1);
    
    assert(fabs(round((pop1.getValue() - 88.2167)*10000)) < 1);
    assert(fabs(round((pop2.getValue() - 21.7833)*10000)) < 1);
}

void complexFuncionalTest(){
    System q1(100, "q1");
    System q2(0, "q2");
    System q3(100, "q3");
    System q4(0, "q4");
    System q5(0, "q5");

    ModelFlow f("f", &q1, &q2);
    ModelFlow g("g", &q1, &q3);
    ModelFlow r("r", &q2, &q5);
    ModelFlow t("t", &q2, &q3);
    ModelFlow u("u", &q3, &q4);
    ModelFlow v("v", &q4, &q1);

    Model model1;
    model1.add(&q1);
    model1.add(&q2);
    model1.add(&q3);
    model1.add(&q4);
    model1.add(&q5);

    model1.add(&f);
    model1.add(&g);
    model1.add(&r);
    model1.add(&t);
    model1.add(&u);
    model1.add(&v);

    model1.run(0, 100, 1);

    assert(fabs(round((q1.getValue() - 31.8513) *10000)) < 1);
    assert(fabs(round((q2.getValue() - 18.4003) *10000)) < 1);
    assert(fabs(round((q3.getValue() - 77.1143) *10000)) < 1);
    assert(fabs(round((q4.getValue() - 56.1728) *10000)) < 1);
    assert(fabs(round((q5.getValue() - 16.4612) *10000)) < 1);
}