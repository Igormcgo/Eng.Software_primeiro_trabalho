#ifndef SYSTEM
#define SYSTEM
#include "system.h"

class SystemImp : public System{
    public: 
        /**
         * @brief Construct a new System object
         * 
         */
        SystemImp();
        
        /**
         * @brief Construct a new System object
         * @param value initial value for System
         * @param name name for system
         * 
         */
        SystemImp(double, string);
        
        /**
         * @brief Destroy the System object
         * 
         */
        virtual ~SystemImp();
        
        /**
         * @brief Set the System value
         * @param value value for the System
         */
        void setValue(double value);
        
        /**
         * @brief Set the System name
         * 
         * @param name Name for the System
         */
        void setName(string name);
        
        /**
         * @brief Get the System value
         * 
         * @return double: Value from the System
         */
        double getValue(void) const;
        
        /**
         * @brief Get the System name
         * 
         * @return string: Name from the System 
         */
        string getName(void) const;

    
    private: 
        //attributes
        double value;
        string name;

        /**
         * @brief Construct a new System object by copy
         * 
         * @param sys object to be copied
         */
        SystemImp(const SystemImp& sys);
        
        /**
         * @brief Overload of the equal operator
         * 
         * @param sys A system
         * @return System& A system
         */
        SystemImp& operator= (const SystemImp& sys); 
};
#endif


