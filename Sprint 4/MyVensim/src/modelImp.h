#ifndef MODEL
#define MODEL
#include "model.h"
using namespace std;

class ModelImp : public Model{
    public:
        /**
         * @brief Construct a new Model object
         * 
         */
        ModelImp();
        
        /**
         * @brief Destroy the Model object
         * 
         */
        virtual ~ModelImp();
        
        /**
         * @brief Run the model
         * @param initial simulation start time
         * @param end simulation end time
         * @param iteration clock
         */
        void run(double, double, double);
        
        /**
         * @brief Add a System to the Model
         * @param System* System to be added
         */
        void add(System*);
        
        /**
         * @brief Add a Flow to the Model 
         * @param Flow* Flow to be added
         */
        void add(Flow*);

        /**
         * @brief Returns the beginning of the System vector
         * 
         * @return systemIterator: A begin iterator for the System
         */
        systemIterator beginSystem();
        
        /**
         * 
         * @brief Returns the end of the System vector
         * 
         * @return systemIterator: An end iterator for the System
         */
        systemIterator endSystem();
        
        /**
         * @brief Returns the beginning of the Flow vector
         * 
         * @return flowIterator: A begin iterator for the Flow
         */
        flowIterator beginFlow();
        
        /**
         * @brief Returns the end of the Flow vector
         * 
         * @return flowIterator: An end iterator for the Flow 
         */
        flowIterator endFlow();

    private:
        //attributes
        vector<System*> system;
        vector<Flow*> flow;

        /**
         * @brief Construct a new Model object by copy
         * 
         * @param model object to be copied
         */
        ModelImp(const ModelImp& model);
        
        /**
         * @brief Overload of the equal operator
         * 
         * @param model A Model
         * @return Model& A Model
         */
        ModelImp& operator= (const ModelImp& model);
};
#endif