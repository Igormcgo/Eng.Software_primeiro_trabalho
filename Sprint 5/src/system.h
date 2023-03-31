#ifndef SYSTEM_INTERFACE
#define SYSTEM_INTERFACE

#include <string>
using namespace std;

class System{
    public:
        /**
         * @brief Destroy the System object
         * 
         */
        virtual ~System(){}
        
        /**
         * @brief Set the System value
         * @param double value for the System
         */
        virtual void setValue(double) = 0;
        
        /**
         * @brief Set the System name
         * 
         * @param string Name for the System
         */
        virtual void setName(string) = 0;

        /**
         * @brief Get the System value
         * 
         * @return double: Value from the System
         */
        virtual double getValue(void) const = 0;

        /**
         * @brief Get the System name
         * 
         * @return string: Name from the System 
         */
        virtual string getName(void) const = 0;
};

#endif