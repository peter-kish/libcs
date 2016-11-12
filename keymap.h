#ifndef KEYMAP_H
#define KEYMAP_H

#include <string>
#include <map>
#include "idfactory.h"

namespace cs
{
    class KeyMap
    {
        public:
            cs::ID registerKey(std::string key);
            void unregisterKeyID(cs::ID keyID);
            cs::ID  getKeyID(std::string key);
            bool isKeyRegistered(std::string key);
        private:
            std::map<std::string, cs::ID> keys;
            IDFactory idFactory;
    };
}

#endif // KEYMAP_H
