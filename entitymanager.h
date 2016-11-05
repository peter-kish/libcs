#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <vector>
#include "entity.h"
#include "idfactory.h"

namespace cs
{
    class EntityManager
    {
    public:
        bool entityExists(cs::ID entityID);
        cs::ID addEntity(cs::Entity& entity);
        void removeEntity(cs::ID entityID);
    private:
        std::vector<Entity> entities;
        cs::IDFactory idFactory;
    };
}

#endif

