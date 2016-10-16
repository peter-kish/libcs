#ifndef COMPONENTMANAGER_H
#define COMPONENTMANAGER_H

#include <string>
#include "keymap.h"

namespace cs
{
    class ComponentManager
    {
    public:
        cs::ID getComponentID(std::string compName);
        cs::ID registerComponent(std::string compName);
        void unregisterComponent(cs::ID compID);
    private:
        cs::KeyMap componentKeyMap;
    };
}
#endif

