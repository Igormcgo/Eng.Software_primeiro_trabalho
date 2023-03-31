#ifndef FLOW
#define FLOW
#include "flow.h"
#include "handleBodySemDebug.h"

class FlowImp : public Body{
    public:
        /**
         * @brief Construct a new Flow object
         * 
         */
        FlowImp();

        /**
         * @brief Construct a new Flow object
         * @param name Name for system
         * @param destiny The Flow's origin
         * @param destiny The Flow's destiny
         */
        FlowImp(string, System*, System*);

        /**
         * @brief Destroy the Flow object
         * 
         */
        virtual ~FlowImp();

        /**
         * @brief Set the Origin Flow
         * 
         * @param origin The Flow's origin
         */
        void setOrigin(System* origin);

        /**
         * @brief Set the Destiny Flow
         * 
         * @param destiny The Flow's destiny
         */
        void setDestiny(System* destiny);

        /**
         * @brief Set the Name Flow
         * 
         * @param name The Flow's name
         */
        void setName(string name);

        /**
         * @brief Get the Flow origin
         * 
         * @return System* : The Flow's origin
         */
        System* getOrigin(void) const;

        /**
         * @brief Get the Flow destiny
         * 
         * @return System* : The Flow's destiny
         */
        System* getDestiny(void) const;

        /**
         * @brief Get the Flow name
         * 
         * @return string : Name from the Flow
         */
        string getName(void) const;

        /**
         * @brief Clear the Flow origin
         * 
         */
        void clearOrigin(void);

        /**
         * @brief Clear the Flow destiny
         * 
         */
        void clearDestiny(void);

        /**
         * @brief Purely virtual method that calculates the Flow value 
         * 
         * @return double : The Flow's value
         */
        virtual double execute() = 0;
    protected:
        //attributes
        System* origin;
        System* destiny;
        string name;
    private:
        /**
         * @brief Construct a new Flow object by copy
         * 
         * @param flow Object to be copied
         */
        FlowImp(const FlowImp& flow);

        /**
         * @brief Overload of the equal operator
         * 
         * @param flow 
         * @return Flow& 
         */
        FlowImp& operator= (const FlowImp& flow);
};

template<typename T>
class FlowHandle : public Flow, public Handle<T>{
    public:
        FlowHandle(string name, System* origin, System* destiny){
            Handle<T>::pImpl_->setName(name);
            Handle<T>::pImpl_->setOrigin(origin);
            Handle<T>::pImpl_->setDestiny(destiny);
        }
        void setOrigin(System* origin){ return Handle<T>::pImpl_->setOrigin(origin);}
        void setDestiny(System* destiny){ return Handle<T>::pImpl_->setDestiny(destiny);}
        void setName(string name){ return Handle<T>::pImpl_->setName(name);}
        System* getOrigin(void) const { return Handle<T>::pImpl_->getOrigin();}
        System* getDestiny(void) const { return Handle<T>::pImpl_->getDestiny();}
        string getName(void) const { return Handle<T>::pImpl_->getName();}
        void clearOrigin(void){ return Handle<T>::pImpl_->clearOrigin();}
        void clearDestiny(void){ return Handle<T>::pImpl_->clearDestiny();}
        virtual double execute() { return Handle<T>::pImpl_->execute();}
};

#endif