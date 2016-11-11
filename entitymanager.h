#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <vector>
#include "entity.h"
#include "idfactory.h"

namespace cs
{
    class ComponentSystem;

    class EntityManager
    {
    public:
        EntityManager(ComponentSystem* parentSystem_) : parentSystem(parentSystem_) {}
        bool entityExists(cs::ID entityID);
        cs::ID addEntity(cs::Entity& entity);
        void removeEntity(cs::ID entityID);
    private:
        std::vector<Entity> entities;
        cs::IDFactory idFactory;
        ComponentSystem* parentSystem;
    };
}

#endif

