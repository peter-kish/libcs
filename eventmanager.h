#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <memory>
#include <algorithm>
#include <string>
#include <memory>
#include "keymap.h"

namespace cs
{
    class ComponentSystem;

    class EventData
    {
    public:
        virtual ~EventData() {}
    };

    typedef std::function<void(cs::ID, EventData*)> ListenerFunc;

    class Listener
    {
    public:
        Listener(ListenerFunc f) : func(f) {}
        void onEvent(cs::ID eventID, EventData* data = nullptr);
    private:
        ListenerFunc func;
    };

    class EventManager
    {
    public:
        EventManager(ComponentSystem* parentSystem_) : parentSystem(parentSystem_) {}
        cs::ID getEventID(const std::string& eventName);

        void addListener(cs::ID eventID, const cs::Listener& listener);
        void addListener(std::string eventName, const cs::Listener& listener) { addListener(getEventID(eventName), listener); }
        void addListener(cs::ID eventID, const ListenerFunc f) { addListener(eventID, cs::Listener(f)); }
        void addListener(std::string eventName, const ListenerFunc f) { addListener(getEventID(eventName), cs::Listener(f)); }

        void removeListener(cs::ID eventID, cs::Listener& listener);
        void removeListener(std::string eventName, cs::Listener& listener) { removeListener(getEventID(eventName), listener); }
        void trigger(cs::ID eventID, EventData* data = nullptr);
        void trigger(std::string eventName, EventData* data = nullptr) { trigger(getEventID(eventName), data); }
    private:
        cs::KeyMap eventKeyMap;
        std::map<cs::ID, std::vector<cs::Listener>> listeners;
        ComponentSystem* parentSystem;
    };
}
#endif
