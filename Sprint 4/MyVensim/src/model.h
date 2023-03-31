#ifndef MODEL_INTERFACE
#define MODEL_INTERFACE

#include "flow.h"
#include <iterator>
#include <vector>
class Model{
    public:
        /**
         * @brief Destroy the Model object
         * 
         */
        virtual ~Model(){}
        
        typedef vector<System*>::iterator systemIterator;
        typedef vector<Flow*>::iterator flowIterator;
        
        /**
         * @brief Run the model
         * @param initial simulation start time
         * @param end simulation end time
         * @param iteration clock
         */
        virtual void run(double, double, double) = 0;

        /**
         * @brief Add a System to the Model
         * @param System* System to be added
         */
        virtual void add(System*) = 0;

        /**
         * @brief Add a Flow to the Model 
         * @param Flow* Flow to be added
         */
        virtual void add(Flow*) = 0;

        /**
         * @brief Returns the beginning of the System vector
         * 
         * @return systemIterator: A begin iterator for the System
         */
        virtual systemIterator beginSystem() = 0;

        /**
         * 
         * @brief Returns the end of the System vector
         * 
         * @return systemIterator: An end iterator for the System
         */
        virtual systemIterator endSystem() = 0;

        /**
         * @brief Returns the beginning of the Flow vector
         * 
         * @return flowIterator: A begin iterator for the Flow
         */
        virtual flowIterator beginFlow() = 0;

        /**
         * @brief Returns the end of the Flow vector
         * 
         * @return flowIterator: An end iterator for the Flow 
         */
        virtual flowIterator endFlow() = 0;
};
#endif