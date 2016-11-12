#include "componentmanager.h"

cs::ID cs::ComponentManager::getComponentID(std::string compName)
{
    if (!componentKeyMap.isKeyRegistered(compName))
    {
        componentKeyMap.registerKey(compName);
    }

    return componentKeyMap.getKeyID(compName);
}

