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
    if (!eventKeyMap.isKeyRegistered(eventName))
    {
        eventKeyMap.registerKey(eventName);
    }
    return eventKeyMap.getKeyID(eventName);
}

void cs::EventManager::addListener(cs::ID eventID, const cs::Listener& listener)
{
    listeners[eventID].push_back(listener);
}

void cs::EventManager::removeListener(cs::ID eventID, cs::Listener& listener)
{
    /*auto listener_it = std::find(listeners[eventID].begin(), listeners[eventID].end(), listener);
    listeners[eventID].erase(listener_it);
    if (listeners[eventID].empty())
    {
        auto event_it = listeners.find(eventID);
        listeners.erase(event_it);
    }*/
}

void cs::EventManager::trigger(cs::ID eventID, EventData* data)
{
    auto triggerOneListener = [&](cs::Listener& l){ l.onEvent(eventID, data); };
    std::for_each(listeners[eventID].begin(), listeners[eventID].end(), triggerOneListener);
}

