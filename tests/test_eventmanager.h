#ifndef TEST_EVENTMANAGER_H
#define TEST_EVENTMANAGER_H

#include "cs.h"
#include <cppunit/extensions/HelperMacros.h>

class EventManagerTests : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(EventManagerTests);
    CPPUNIT_TEST(testGetEventID);
    CPPUNIT_TEST(testRegisterEvent);
    CPPUNIT_TEST(testRegisterSameEvent);
    CPPUNIT_TEST(testRegisterNewEvents);
    CPPUNIT_TEST(testUnregisterEventName);
    CPPUNIT_TEST(testUnregisterEventID);
    CPPUNIT_TEST(testUnregisterSameEventName);
    CPPUNIT_TEST(testUnregisterSameEventID);
    CPPUNIT_TEST(testAddListener);
    CPPUNIT_TEST(testAddMultipleListeners);
    CPPUNIT_TEST(testRemoveListener);
    CPPUNIT_TEST(testRemoveMultipleListeners);
    CPPUNIT_TEST(testListenerParam);
    CPPUNIT_TEST_SUITE_END();
public:
    void setUp();
    void tearDown();

    void testRegisterEvent();
    void testGetEventID();
    void testRegisterSameEvent();
    void testRegisterNewEvents();
    void testUnregisterEventName();
    void testUnregisterEventID();
    void testUnregisterSameEventName();
    void testUnregisterSameEventID();
    void testAddListener();
    void testRemoveListener();
    void testAddMultipleListeners();
    void testRemoveMultipleListeners();
    void testListenerParam();
private:
    int nNewEvents;
    int nNewListeners;
};

#endif // TEST_IDFACTORY_H
