#ifndef MODEL_INTERFACE
#define MODEL_INTERFACE

#include "flowImp.h"
#include <iterator>
#include <vector>
class Model{
    public:
        /**
         * @brief Create a Model and add to the Model vector
         * @param name Model's name
         * 
        */
        static Model& createModel(string);
        
        template <typename T_FLUX_IMPL>
        
        /**
         * @brief Construct a new Flow object and add to the Model vector
         * @param name Name for flow
         * @param origin The Flow's origin
         * @param destiny The Flow's destiny
         */
        Flow& createFlow(string name, System* origin, System* destiny){
            Flow* f = new FlowHandle<T_FLUX_IMPL>(name, origin, destiny);
            add(f);
            return *f;
        }

        /**
         * @brief Create a System and add to the Model
         * @param name System's name
         * @param value value from System
         * 
        */
        virtual System& createSystem(string, double) = 0;
        
        /**
         * @brief Destroy the Model object
         * 
         */
        virtual ~Model(){}
        
        typedef vector<System*>::iterator systemIterator;
        typedef vector<Flow*>::iterator flowIterator;
        typedef vector<Model*>::iterator modelIterator;
        
        /**
         * @brief Run the model
         * @param initial simulation start time
         * @param end simulation end time
         * @param iteration clock
         */
        virtual void run(double, double, double) = 0;

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

        /**
         * @brief Returns the beginning of the Model vector
         * 
         * @return modelIterator: A begin iterator for the Model
         */
        virtual modelIterator beginModel() = 0;
        
        /**
         * @brief Returns the end of the Model vector
         * 
         * @return modelIterator: An end iterator for the Model 
         */
        virtual modelIterator endModel() = 0;

    public:

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
         * @brief Add a Model to the Model vector
         * @param Model* Model to be added
         * 
        */
        virtual void add(Model*) = 0;

};
#endif