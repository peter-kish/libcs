#include "cs.h"
#include "entity.h"
#include "component.h"

void cs::Entity::addComponent(std::shared_ptr<cs::Component> component)
{
    components.push_back(component);
    components.back()->onAdd();
}

void cs::Entity::removeComponent(std::shared_ptr<cs::Component> component)
{
    auto it = std::find(components.begin(), components.end(), component);
    if (it != components.end())
    {
        (*it)->onRemove();
        components.erase(it);
    }
    else
    {
        throw cs::Exception("Component not found!");
    }
}

bool cs::Entity::hasComponent(cs::ID componentID)
{
    for(auto it = components.begin(); it != components.end(); ++it)
    {
        if((*it)->id == componentID)
            return true;
    }
    return false;
}

std::shared_ptr<cs::Component> cs::Entity::getComponent(cs::ID componentID)
{
    for(auto it = components.begin(); it != components.end(); ++it)
    {
        if((*it)->id == componentID)
            return (*it);
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
