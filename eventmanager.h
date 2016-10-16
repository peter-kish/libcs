#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <memory>
#include <algorithm>
#include <string>
#include <memory>
#include "keymap.h"

namespace cs
{
    class EventData
    {
    public:
        virtual ~EventData() {}
    };

    class Listener
    {
    public:
        Listener(std::function<void(cs::ID, EventData*)> f) : func(f) {}
        void onEvent(cs::ID eventID, EventData* data = nullptr);
    private:
        std::function<void(cs::ID, EventData*)> func;
    };

    class EventManager
    {
    public:
        cs::ID getEventID(const std::string& eventName);
        cs::ID registerEvent(const std::string& eventName);
        void unregisterEvent(const std::string& eventName);
        void unregisterEvent(cs::ID eventID);
        void addListener(cs::ID eventID, std::shared_ptr<cs::Listener> listener);
        void removeListener(cs::ID eventID, std::shared_ptr<cs::Listener> listener);
        void trigger(cs::ID eventID, EventData* data = nullptr);
    private:
        cs::KeyMap eventKeyMap;
        std::map<cs::ID, std::vector<std::shared_ptr<cs::Listener>>> listeners;
    };
}
#endif
