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
        void addComponent(Component& component);
        void removeComponent(cs::ID componentID);
        bool hasComponent(cs::ID componentID);
        Component* getComponent(cs::ID componentID);
        cs::ID getID() const;
        void setID(cs::ID entityID);
    private:
        std::vector<Component> components;
        cs::ID id;
    };
}

#endif
