#include "componentmanager.h"

cs::ID cs::ComponentManager::getComponentID(std::string compName)
{
    return componentKeyMap.getKeyID(compName);
}

cs::ID cs::ComponentManager::registerComponent(std::string compName)
{
    return componentKeyMap.registerKey(compName);
}

void cs::ComponentManager::unregisterComponent(cs::ID compID)
{
    componentKeyMap.unregisterKeyID(compID);
}

void cs::ComponentManager::unregisterComponent(std::string compName)
{
    componentKeyMap.unregisterKeyID(componentKeyMap.getKeyID(compName));
}

