#include "eventmanager.h"

void cs::Listener::onEvent(cs::ID eventID)
{

}

template<typename T>
void cs::TListener<T>::onEvent(cs::ID eventID, T eventData)
{

}

cs::ID cs::EventManager::getEventID(const std::string& eventName)
{
    return 0;
}

cs::ID cs::EventManager::registerEvent(const std::string& eventName)
{
    return 0;
}

void cs::EventManager::unregisterEvent(const std::string& eventName)
{

}

void cs::EventManager::unregisterEvent(cs::ID eventID)
{

}

void cs::EventManager::addListener(std::shared_ptr<cs::Listener> listener)
{

}

void cs::EventManager::removeListener(std::shared_ptr<cs::Listener> listener)
{

}

void cs::EventManager::trigger(cs::ID eventID)
{

}

