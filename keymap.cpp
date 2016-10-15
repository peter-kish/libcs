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

void cs::KeyMap::unregisterKey(std::string key)
{
    //check if the key is registered
    auto it = keys.find(key);
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
