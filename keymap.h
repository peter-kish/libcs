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
            void unregisterKey(std::string key);
            cs::ID  getKeyID(std::string key);
        private:
            std::map<std::string, cs::ID> keys;
            IDFactory idFactory;
    };
}

#endif // KEYMAP_H
