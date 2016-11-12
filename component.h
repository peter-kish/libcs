#ifndef COMPONENT_H
#define COMPONENT_H

#include "idfactory.h"

namespace cs
{
    class Entity;

    class Component
    {
    public:
        Component(cs::Entity& parentEntity_, cs::ID id) : parentEntity(parentEntity_), id(id) {}
        virtual void onAdd() {}
        virtual void onRemove() {}
        cs::ID id;
        cs::Entity& parentEntity;
    };
}

#endif
