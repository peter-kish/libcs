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
        cs::ID id;
        cs::Entity& parentEntity;
    };
}

#endif
