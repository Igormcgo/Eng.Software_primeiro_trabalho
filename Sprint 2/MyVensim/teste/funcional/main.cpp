#ifndef  MAIN_FUNCIONAL_TESTS
#define MAIN_FUNCIONAL_TESTS
#include "funcional_tests.h"
#include "..\..\src\model.h"
#include "..\..\src\system.h"
#include "..\..\src\flow.h"
#include <iostream>

int main(){

    exponentialFuncionalTest();

    logisticalFuncionalTest();

    complexFuncionalTest();

    std::cout<<"OK";

    return true;
}
#endif