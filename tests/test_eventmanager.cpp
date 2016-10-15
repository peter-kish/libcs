#include "test_eventmanager.h"
#include "cs.h"

CPPUNIT_TEST_SUITE_REGISTRATION(EventManagerTests);

void EventManagerTests::setUp()
{
    nNewEvents = 256;
    nNewListeners = 10;
}

void EventManagerTests::tearDown()
{

}

void EventManagerTests::testRegisterEvent()
{
    cs::EventManager eventManager;
    CPPUNIT_ASSERT_NO_THROW(eventManager.registerEvent("Event1"));
}

void EventManagerTests::testGetEventID()
{
    cs::EventManager eventManager;
    cs::ID id = eventManager.registerEvent("Event1");
    cs::ID gotID = eventManager.getEventID("Event1");
    CPPUNIT_ASSERT_EQUAL(id, gotID);
}

void EventManagerTests::testRegisterSameEvent()
{
    cs::EventManager eventManager;

    CPPUNIT_ASSERT_NO_THROW(eventManager.registerEvent("Event1"));
    CPPUNIT_ASSERT_THROW(eventManager.registerEvent("Event1"), cs::Exception);
}

void EventManagerTests::testRegisterNewEvents()
{
    cs::EventManager eventManager;
    std::vector<cs::ID> generatedEventIDs;

    for(int i = 0; i < nNewEvents; i++)
    {
        std::string eventName = "Event";
        eventName += i;
        generatedEventIDs.push_back(eventManager.registerEvent(eventName));
    }

    // Check if all IDs are unique
    for(int i = 0; i < generatedEventIDs.size(); i++)
    {
        for(int j = i + 1 ; j < generatedEventIDs.size(); j++)
        {
            CPPUNIT_ASSERT(generatedEventIDs[i] != generatedEventIDs[j]);
        }
    }

}

void EventManagerTests::testUnregisterEventName()
{
    cs::EventManager eventManager;
    cs::ID id;
    CPPUNIT_ASSERT_NO_THROW(id = eventManager.registerEvent("Event1"));
    CPPUNIT_ASSERT_NO_THROW(eventManager.unregisterEvent("Event1"));
    CPPUNIT_ASSERT_NO_THROW(id = eventManager.registerEvent("Event1"));
}

void EventManagerTests::testUnregisterEventID()
{
    cs::EventManager eventManager;
    cs::ID id;
    CPPUNIT_ASSERT_NO_THROW(id = eventManager.registerEvent("Event1"));
    CPPUNIT_ASSERT_NO_THROW(eventManager.unregisterEvent(id));
    CPPUNIT_ASSERT_NO_THROW(id = eventManager.registerEvent("Event1"));
}

void EventManagerTests::testUnregisterSameEventName()
{
    cs::EventManager eventManager;

    CPPUNIT_ASSERT_NO_THROW(eventManager.registerEvent("Event1"));
    CPPUNIT_ASSERT_NO_THROW(eventManager.unregisterEvent("Event1"));
    CPPUNIT_ASSERT_THROW(eventManager.unregisterEvent("Event1"), cs::Exception);
}

void EventManagerTests::testUnregisterSameEventID()
{
    cs::EventManager eventManager;
    cs::ID id;

    CPPUNIT_ASSERT_NO_THROW(id = eventManager.registerEvent("Event1"));
    CPPUNIT_ASSERT_NO_THROW(eventManager.unregisterEvent(id));
    CPPUNIT_ASSERT_THROW(eventManager.unregisterEvent(id), cs::Exception);

}

void EventManagerTests::testAddListener()
{
    cs::EventManager eventManager;
    cs::ID eventID = eventManager.registerEvent("Event1");
    bool eventHappened = false;
    auto eventLambda = [&eventHappened](cs::ID eventID) { eventHappened = true; };
    auto listener = std::make_shared<cs::Listener>(eventLambda);
    CPPUNIT_ASSERT_NO_THROW(eventManager.addListener(std::static_pointer_cast<cs::Listener>(listener)));
    CPPUNIT_ASSERT_NO_THROW(eventManager.trigger(eventID));
    CPPUNIT_ASSERT(eventHappened);
}

void EventManagerTests::testAddMultipleListeners()
{
    cs::EventManager eventManager;
    cs::ID eventID = eventManager.registerEvent("Event1");
    int eventCounter = 0;
    auto eventLambda = [&eventCounter](cs::ID eventID) { ++eventCounter; };
    for(int i = 0; i < nNewListeners; ++i)
    {
        auto listener = std::make_shared<cs::Listener>(eventLambda);
        CPPUNIT_ASSERT_NO_THROW(eventManager.addListener(std::static_pointer_cast<cs::Listener>(listener)));
    }
    CPPUNIT_ASSERT_NO_THROW(eventManager.trigger(eventID));
    CPPUNIT_ASSERT(eventCounter == nNewListeners);
}

void EventManagerTests::testRemoveListener()
{
    cs::EventManager eventManager;
    cs::ID eventID = eventManager.registerEvent("Event1");
    bool eventHappened = false;
    auto eventLambda = [&eventHappened](cs::ID eventID) { eventHappened = true; };
    auto listener = std::make_shared<cs::Listener>(eventLambda);
    CPPUNIT_ASSERT_NO_THROW(eventManager.addListener(std::static_pointer_cast<cs::Listener>(listener)));
    CPPUNIT_ASSERT_NO_THROW(eventManager.removeListener(std::static_pointer_cast<cs::Listener>(listener)));
    CPPUNIT_ASSERT_NO_THROW(eventManager.trigger(eventID));
    CPPUNIT_ASSERT(!eventHappened);
}

void EventManagerTests::testRemoveMultipleListeners()
{
    /*cs::EventManager eventManager;
    cs::ID eventID = eventManager.registerEvent("Event1");
    std::vector<std::shared_ptr<TestListener>> testListeners;

    for(int i = 0; i < nNewListeners; i++)
    {
        auto testListener = std::make_shared<TestListener>(eventID);
        testListeners.push_back(testListener);
        CPPUNIT_ASSERT_NO_THROW(eventManager.addListener(std::static_pointer_cast<cs::Listener>(testListener)));
    }
    for(int i = 0; i < nNewListeners; i++)
    {
        std::shared_ptr<TestListener> testListener = testListeners.back();
        testListeners.pop_back();
        CPPUNIT_ASSERT_NO_THROW(
                eventManager.removeListener(std::static_pointer_cast<cs::Listener>(testListener)));
    }
    eventHitCounter = 0;
    CPPUNIT_ASSERT_NO_THROW(eventManager.trigger(eventID));
    CPPUNIT_ASSERT(eventHitCounter == 0);*/
}

void EventManagerTests::testListenerParam()
{
    cs::EventManager eventManager;
    cs::ID eventID = eventManager.registerEvent("Event1");
    bool eventHappened = false;
    auto eventLambda = [](cs::ID eventID, bool& b) { b = true; };
    auto listener = std::make_shared<cs::TListener<bool&>>(eventLambda);

    CPPUNIT_ASSERT_NO_THROW(eventManager.addListener(std::static_pointer_cast<cs::Listener>(listener)));
    CPPUNIT_ASSERT_NO_THROW(eventManager.trigger<bool&>(eventID, eventHappened));
    CPPUNIT_ASSERT(!eventHappened);
}

