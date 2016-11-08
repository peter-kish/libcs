#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <memory>
#include "idfactory.h"
#include "component.h"

namespace cs
{
    class Entity
    {
    public:
        Entity() : id(cs::INVALID_ID) {}
        Entity(cs::ID entityID) : id(entityID) {}
        void addComponent(std::shared_ptr<cs::Component> component);
        void removeComponent(std::shared_ptr<cs::Component> component);
        bool hasComponent(cs::ID componentID);
        std::shared_ptr<cs::Component> getComponent(cs::ID componentID);
        cs::ID getID() const;
        void setID(cs::ID entityID);
    private:
        std::vector<std::shared_ptr<cs::Component>> components;
        cs::ID id;
    };
}

#endif
