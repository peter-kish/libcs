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

void EventManagerTests::testGetEventID()
{
    cs::ComponentSystem componentSystem;
    cs::EventManager& eventManager = componentSystem.eventManager;
    cs::ID gotID = eventManager.getEventID("Event1");
    CPPUNIT_ASSERT(gotID != cs::INVALID_ID);
}

void EventManagerTests::testAddListener()
{
    cs::ComponentSystem componentSystem;
    cs::EventManager& eventManager = componentSystem.eventManager;
    bool eventHappened = false;
    auto eventLambda = [&eventHappened](cs::ID eventID, cs::EventData* data) { eventHappened = true; };
    cs::Listener listener(eventLambda);
    CPPUNIT_ASSERT_NO_THROW(eventManager.addListener("Event1", listener));
    CPPUNIT_ASSERT_NO_THROW(eventManager.trigger("Event1"));
    CPPUNIT_ASSERT(eventHappened);
}

void EventManagerTests::testAddMultipleListeners()
{
    cs::ComponentSystem componentSystem;
    cs::EventManager& eventManager = componentSystem.eventManager;
    int eventCounter = 0;
    auto eventLambda = [&eventCounter](cs::ID eventID, cs::EventData* data) { ++eventCounter; };
    for(int i = 0; i < nNewListeners; ++i)
    {
        cs::Listener listener(eventLambda);
        CPPUNIT_ASSERT_NO_THROW(eventManager.addListener("Event1", listener));
    }
    CPPUNIT_ASSERT_NO_THROW(eventManager.trigger("Event1"));
    CPPUNIT_ASSERT(eventCounter == nNewListeners);
}

void EventManagerTests::testRemoveListener()
{
    /*cs::EventManager eventManager;
    cs::ID eventID = eventManager.registerEvent("Event1");
    bool eventHappened = false;
    auto eventLambda = [&eventHappened](cs::ID eventID, cs::EventData* data) { eventHappened = true; };
    auto listener = std::make_shared<cs::Listener>(eventLambda);
    CPPUNIT_ASSERT_NO_THROW(eventManager.addListener(eventID, std::static_pointer_cast<cs::Listener>(listener)));
    CPPUNIT_ASSERT_NO_THROW(eventManager.removeListener(eventID, std::static_pointer_cast<cs::Listener>(listener)));
    CPPUNIT_ASSERT_NO_THROW(eventManager.trigger(eventID));
    CPPUNIT_ASSERT(!eventHappened);*/
}

void EventManagerTests::testRemoveMultipleListeners()
{
    /*cs::EventManager eventManager;
    cs::ID eventID = eventManager.registerEvent("Event1");
    std::vector<std::shared_ptr<cs::Listener>> listeners;
    int eventCounter = 0;
    auto eventLambda = [&eventCounter](cs::ID eventID, cs::EventData* data) { ++eventCounter; };

    for(int i = 0; i < nNewListeners; i++)
    {
        auto listener = std::make_shared<cs::Listener>(eventLambda);
        listeners.push_back(listener);
        CPPUNIT_ASSERT_NO_THROW(eventManager.addListener(eventID, std::static_pointer_cast<cs::Listener>(listener)));
    }
    for(int i = 0; i < nNewListeners; i++)
    {
        std::shared_ptr<cs::Listener> listener = listeners.back();
        listeners.pop_back();
        CPPUNIT_ASSERT_NO_THROW(
                eventManager.removeListener(eventID, std::static_pointer_cast<cs::Listener>(listener)));
    }
    CPPUNIT_ASSERT_NO_THROW(eventManager.trigger(eventID));
    CPPUNIT_ASSERT(eventCounter == 0);*/
}

class TestData : public cs::EventData
{
public:
    virtual ~TestData() {}
    TestData(bool& b) : bref(b) {}
    bool& bref;
};

void EventManagerTests::testListenerParam()
{
    cs::ComponentSystem componentSystem;
    cs::EventManager& eventManager = componentSystem.eventManager;
    bool eventHappened = false;
    auto eventLambda = [](cs::ID eventID, cs::EventData* data) {
        dynamic_cast<TestData*>(data)->bref = true;
    };
    TestData testData(eventHappened);
    cs::Listener listener(eventLambda);

    CPPUNIT_ASSERT_NO_THROW(eventManager.addListener("Event1", listener));
    CPPUNIT_ASSERT_NO_THROW(eventManager.trigger("Event1", &testData));
    CPPUNIT_ASSERT(eventHappened);
}

