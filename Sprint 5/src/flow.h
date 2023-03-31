#ifndef FLOW_INTERFACE
#define FLOW_INTERFACE

#include "system.h"
#include <string>
using namespace std;

class Flow{
    public:
        /**
         * @brief Destroy the Flow object
         * 
         */
        virtual ~Flow(){} 
        
        /**
         * @brief Set the Origin Flow
         * 
         * @param origin The Flow's origin
         */
        virtual void setOrigin(System*) = 0;
        
        /**
         * @brief Set the Destiny Flow
         * 
         * @param destiny The Flow's destiny
         */
        virtual void setDestiny(System*) = 0;
        
        /**
         * @brief Set the Name Flow
         * 
         * @param name The Flow's name
         */
        virtual void setName(string) = 0;

        /**
         * @brief Get the Flow origin
         * 
         * @return System* : The Flow's origin
         */
        virtual System* getOrigin(void) const = 0;

        /**
         * @brief Get the Flow destiny
         * 
         * @return System* : The Flow's destiny
         */
        virtual System* getDestiny(void) const = 0;

        /**
         * @brief Get the Flow name
         * 
         * @return string : Name from the Flow
         */
        virtual string getName(void) const = 0;

        /**
         * @brief Clear the Flow origin
         * 
         */
        virtual void clearOrigin(void) = 0;

        /**
         * @brief Clear the Flow destiny
         * 
         */
        virtual void clearDestiny(void) = 0;

        /**
         * @brief Purely virtual method that calculates the Flow value 
         * 
         * @return double : The Flow's value
         */
        virtual double execute() = 0;
};

#endif