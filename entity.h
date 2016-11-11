#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <memory>
#include "idfactory.h"
#include "component.h"

namespace cs
{
    class ComponentSystem;

    class Entity
    {
    public:
        Entity(ComponentSystem* parentSystem_) : parentSystem(parentSystem_), id(cs::INVALID_ID) {}
        Entity(ComponentSystem* parentSystem_, cs::ID entityID) : parentSystem(parentSystem_), id(entityID) {}
        void addComponent(std::shared_ptr<cs::Component> component);
        void removeComponent(std::shared_ptr<cs::Component> component);
        bool hasComponent(cs::ID componentID);
        std::shared_ptr<cs::Component> getComponent(cs::ID componentID);
        cs::ID getID() const;
        void setID(cs::ID entityID);
    private:
        std::vector<std::shared_ptr<cs::Component>> components;
        cs::ID id;
        ComponentSystem* parentSystem;
    };
}

#endif
