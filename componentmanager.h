#ifndef COMPONENTMANAGER_H
#define COMPONENTMANAGER_H

#include <string>
#include "keymap.h"

namespace cs
{
    class ComponentSystem;

    class ComponentManager
    {
    public:
        ComponentManager(ComponentSystem* parentSystem_) : parentSystem(parentSystem_) {}
        cs::ID getComponentID(std::string compName);
        cs::ID registerComponent(std::string compName);
        void unregisterComponent(cs::ID compID);
        void unregisterComponent(std::string compName);
    private:
        cs::KeyMap componentKeyMap;
        ComponentSystem* parentSystem;
    };
}
#endif

