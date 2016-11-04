#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <memory>
#include "component.h"

namespace cs
{
    class Entity
    {
    public:
        void addComponent(Component& component);
        void removeComponent(cs::ID componentID);
        bool hasComponent(cs::ID componentID);
        Component* getComponent(cs::ID componentID);
    private:
        std::vector<Component> components;
    };
}

#endif
