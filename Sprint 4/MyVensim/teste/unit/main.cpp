#include "unit_tests.h"
#include "unit_System.h"
#include "unit_Flow.h"
#include "unit_Model.h"
#include <iostream>

int main(){

        run_unit_tests_globals();

        run_unit_tests_System();

        run_unit_tests_Flow();

        run_unit_tests_Model();

        std::cout<<"OK!!";

        return true;
}