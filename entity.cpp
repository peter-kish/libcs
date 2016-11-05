#include "cs.h"
#include "entity.h"
#include "component.h"

void cs::Entity::addComponent(cs::Component& component)
{
    components.push_back(component);
}

void cs::Entity::removeComponent(cs::ID componentID)
{
    for(auto it = components.begin(); it != components.end(); ++it)
    {
        if(it->id == componentID)
        {
            components.erase(it);
            return;
        }
    }
    throw cs::Exception("Component not found!");
}

bool cs::Entity::hasComponent(cs::ID componentID)
{
    for(auto it = components.begin(); it != components.end(); ++it)
    {
        if(it->id == componentID)
            return true;
    }
    return false;
}

cs::Component* cs::Entity::getComponent(cs::ID componentID)
{
    for(auto it = components.begin(); it != components.end(); ++it)
    {
        if(it->id == componentID)
            return &(*it);
    }
    throw cs::Exception("Component not found!");
}

cs::ID cs::Entity::getID() const
{
    return id;
}

void cs::Entity::setID(cs::ID entityID)
{
    id = entityID;
}
