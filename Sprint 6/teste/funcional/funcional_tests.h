#ifndef FUNCIONAL_TESTS
#define FUNCIONAL_TESTS
#include "..\..\src\model.h"
#include <assert.h>

class ExponentialFlow : public FlowImp{
    public:
        ExponentialFlow(string nome="", System* origin=nullptr, System* destiny=nullptr) : FlowImp(nome, origin, destiny){}
        virtual double execute(){
            return 0.01 * getOrigin()->getValue();
        }
};

class LogisticFlow : public FlowImp{
    public:
        LogisticFlow(string nome="", System* origin=nullptr, System* destiny=nullptr) : FlowImp(nome, origin, destiny){}
        virtual double execute(){
            return 0.01 * getDestiny()->getValue() * (1 - getDestiny()->getValue() / 70);
        }
};

class ModelFlow : public FlowImp{
    public:
        ModelFlow(string nome="", System* origin=nullptr, System* destiny=nullptr) : FlowImp(nome, origin, destiny){}
        virtual double execute(){
            return 0.01 * getOrigin()->getValue();
        }
};

/**
 * @brief Exponential test
 * 
 */
void exponentialFuncionalTest();

/**
 * @brief Logistical test
 * 
 */
void logisticalFuncionalTest();

/**
 * @brief Complex test
 * 
 */
void complexFuncionalTest();
#endif