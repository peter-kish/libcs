#include <algorithm>
#include "eventmanager.h"

void cs::Listener::onEvent(cs::ID eventID, EventData* data)
{
    if(func)
    {
        func(eventID, data);
    }
}

cs::ID cs::EventManager::getEventID(const std::string& eventName)
{
    return eventKeyMap.getKeyID(eventName);
}

cs::ID cs::EventManager::registerEvent(const std::string& eventName)
{
    return eventKeyMap.registerKey(eventName);
}

void cs::EventManager::unregisterEvent(const std::string& eventName)
{
    eventKeyMap.unregisterKeyID(eventKeyMap.getKeyID(eventName));
}

void cs::EventManager::unregisterEvent(cs::ID eventID)
{
    eventKeyMap.unregisterKeyID(eventID);
}

void cs::EventManager::addListener(cs::ID eventID, std::shared_ptr<cs::Listener> listener)
{
    listeners[eventID].push_back(listener);
}

void cs::EventManager::removeListener(cs::ID eventID, std::shared_ptr<cs::Listener> listener)
{
    auto it = std::find(listeners[eventID].begin(), listeners[eventID].end(), listener);
    listeners[eventID].erase(it);
    if (listeners[eventID].empty())
    {
        auto it = listeners.find(eventID);
        listeners.erase(it);
    }
}

void cs::EventManager::trigger(cs::ID eventID, EventData* data)
{
    auto triggerOneListener = [&](std::shared_ptr<cs::Listener>& l){ l->onEvent(eventID, data); };
    std::for_each(listeners[eventID].begin(), listeners[eventID].end(), triggerOneListener);
}

