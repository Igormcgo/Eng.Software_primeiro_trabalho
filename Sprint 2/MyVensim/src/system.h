#ifndef SYSTEM
#define SYSTEM
#include <string>
using namespace std;

class System{
    public: 
        /**
         * @brief Construct a new System object
         * 
         */
        System();
        
        /**
         * @brief Construct a new System object
         * @param value initial value for System
         * @param name name for system
         * 
         */
        System(double, string);
        
        /**
         * @brief Destroy the System object
         * 
         */
        virtual ~System();
        
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
        double getValue(void);
        
        /**
         * @brief Get the System name
         * 
         * @return string: Name from the System 
         */
        string getName(void);

    
    private: 
        //attributes
        double value;
        string name;

        /**
         * @brief Construct a new System object by copy
         * 
         * @param sys object to be copied
         */
        System(const System& sys);
        
        /**
         * @brief Overload of the equal operator
         * 
         * @param sys A system
         * @return System& A system
         */
        System& operator= (const System& sys); 
};
#endif


