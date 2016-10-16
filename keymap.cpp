#include <algorithm>
#include "keymap.h"
#include "cs.h"

cs::ID cs::KeyMap::registerKey(std::string key)
{
    //check if the key is already registered
    auto it = keys.find(key);
    if (it != keys.end())
    {
        throw cs::Exception("Key already registered!");
    }

    keys[key] = idFactory.getNewID();
    return keys[key];
}

void cs::KeyMap::unregisterKeyID(cs::ID keyID)
{
    //check if the key is registered
    auto findKeyID = [keyID](const std::pair<std::string, cs::ID> p)->bool{ return p.second == keyID; };
    auto it = std::find_if(keys.begin(), keys.end(), findKeyID);
    if (it == keys.end())
    {
        throw cs::Exception("Unknown key!");
    }

    keys.erase(it);
}

cs::ID cs::KeyMap::getKeyID(std::string key)
{
    //check if the key is registered
    auto it = keys.find(key);
    if (it == keys.end())
    {
       throw cs::Exception("Unknown key!");
    }

    return keys[key];
}
