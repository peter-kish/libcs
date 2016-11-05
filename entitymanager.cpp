#include <algorithm>
#include "entitymanager.h"
#include "cs.h"

bool cs::EntityManager::entityExists(cs::ID entityID)
{
    auto it = std::find_if(entities.begin(), entities.end(), [&](const Entity& e) { return e.getID() == entityID; });
    return it != entities.end();
}

cs::ID cs::EntityManager::addEntity(cs::Entity& entity)
{
    cs::Entity e = entity;
    e.setID(idFactory.getNewID());
    entities.push_back(e);
    return e.getID();
}

void cs::EntityManager::removeEntity(cs::ID entityID)
{
    auto it = std::find_if(entities.begin(), entities.end(), [&](const Entity& e) { return e.getID() == entityID; });
    if (it == entities.end())
    {
        throw cs::Exception("Entity doesn't exist!");
    }
    entities.erase(it);
}

