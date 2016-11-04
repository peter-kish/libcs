#ifndef COMPONENT_H
#define COMPONENT_H

#include "idfactory.h"

namespace cs
{
    class Entity;

    class Component
    {
    public:
        Component(cs::Entity* parent, cs::ID id) : parent(parent), id(id) {}
        cs::ID id;
        cs::Entity* parent;
    };
}

#endif
