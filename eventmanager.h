#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <string>
#include <memory>
#include "keymap.h"

namespace cs
{
    class EventData
    {
        
    };

    class Listener
    {
    public:
        Listener(std::function<void(cs::ID)> f) : func(f) {}
        void onEvent(cs::ID eventID);
    private:
        std::function<void(cs::ID)> func;
    };

    template<typename T>
    class TListener : public Listener
    {
    public:
        TListener(std::function<void(cs::ID, T)> f) : Listener(nullptr), tfunc(f) {}
        void onEvent(cs::ID eventID, T data);
    private:
        std::function<void(cs::ID, T)> tfunc;
    };

    class EventManager
    {
    public:
        cs::ID getEventID(const std::string& eventName);
        cs::ID registerEvent(const std::string& eventName);
        void unregisterEvent(const std::string& eventName);
        void unregisterEvent(cs::ID eventID);
        void addListener(std::shared_ptr<cs::Listener> listener);
        void removeListener(std::shared_ptr<cs::Listener> listener);
        void trigger(cs::ID eventID);
        template<typename T>
        void trigger(cs::ID eventID, T eventData) {}
    private:
        cs::KeyMap eventKeyMap;
        std::map<cs::ID, std::shared_ptr<cs::Listener>> listeners;
    };
}
#endif
