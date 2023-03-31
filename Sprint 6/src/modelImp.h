#ifndef MODEL
#define MODEL
#include "model.h"
#include "flowImp.h"
#include "systemImp.h"
#include "handleBodySemDebug.h"
using namespace std;

class ModelImp : public Body{
    string name;
    public:
        /**
        * @brief Construct a new Model object
        * 
        */
        ModelImp();
        
        /**
         * @brief Construct a new Model Imp object
         * @param string name of model
         */
        ModelImp(string);

        /**
        * @brief Destroy the Model object
        * 
        */
        virtual ~ModelImp();

        /**
         * @brief Set the Name object
         * @param string name of model
         */
        void setName(string);

        /**
         * @brief Get the Name object
         * 
         * @return string name
         */
        string getName(void);

        /**
         * @brief Create a Model object
         * 
         * @return Model& 
         */
        static Model& createModel(string);

        /**
         * @brief Create a System object
         * 
         * @return System& 
         */
        virtual System& createSystem(string, double);

        /**
         * @brief Run the model
         * @param initial simulation start time
         * @param end simulation end time
         * @param iteration clock
         */
        void run(double, double, double);

        typedef vector<System*>::iterator systemIterator;
        typedef vector<Flow*>::iterator flowIterator;
        typedef vector<Model*>::iterator modelIterator;

        /**
         * @brief Returns the beginning of the System vector
         * 
         * @return systemIterator: A begin iterator for the System
         */
        systemIterator beginSystem();

        /**
        * 
        * @brief Returns the end of the System vector
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

        /**
         * @brief Returns the beginning of the Model vector
         * 
         * @return modelIterator : A begin iterator for the Model 
         */
        modelIterator beginModel();

        /**
         * @brief Returns the end of the Model vector
         * 
         * @return modelIterator: An end iterator for the Model
         */
        modelIterator endModel();

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
         * @brief Add a Model to the vector of Model
         * @param Model* Model to be added
         */
        void add(Model*);
    protected:
        //attributes
        vector<System*> systems;
        vector<Flow*> flows;
        static vector<Model*> models;
    private:
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

class ModelHandle : public Model, public Handle<ModelImp>{
    public:
        ModelHandle(string name){
            pImpl_->setName(name);
        }
        void setName(string name){ return pImpl_->setName(name);}
        string getName(void){ return pImpl_->getName();}
        Model& createModel(string name){ return pImpl_->createModel(name);}
        virtual System& createSystem(string name, double value){ return pImpl_->createSystem(name, value);}
        void run(double initial, double end, double iteration){ return pImpl_->run(initial, end, iteration);}
        typedef vector<System*>::iterator systemIterator;
        typedef vector<Flow*>::iterator flowIterator;
        typedef vector<Model*>::iterator modelIterator;
        systemIterator beginSystem(){ return pImpl_->beginSystem();}
        systemIterator endSystem(){ return pImpl_->endSystem();}
        flowIterator beginFlow(){ return pImpl_->beginFlow();}
        flowIterator endFlow(){ return pImpl_->endFlow();}
        modelIterator beginModel(){ return pImpl_->beginModel();}
        modelIterator endModel(){ return pImpl_->endModel();}
        void add(System* sys){ return pImpl_->add(sys);}
        void add(Flow* flow){ return pImpl_->add(flow);}
        void add(Model* model){ return pImpl_->add(model);}  
};

#endif