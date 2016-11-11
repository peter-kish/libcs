#ifndef TEST_COMPONENTMANAGER_H
#define TEST_COMPONENTMANAGER_H

#include "cs.h"
#include <cppunit/extensions/HelperMacros.h>

class ComponentManagerTests : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(ComponentManagerTests);
    CPPUNIT_TEST(testRegisterComponent);
    CPPUNIT_TEST(testRegisterSameComponent);
    CPPUNIT_TEST(testRegisterNewComponents);
    CPPUNIT_TEST(testUnregisterComponentName);
    CPPUNIT_TEST(testUnregisterComponentID);
    CPPUNIT_TEST(testUnregisterSameComponentName);
    CPPUNIT_TEST(testUnregisterSameComponentID);
    CPPUNIT_TEST_SUITE_END();
public:
    void setUp();
    void tearDown();

    void testRegisterComponent();
    void testRegisterSameComponent();
    void testRegisterNewComponents();
    void testUnregisterComponentName();
    void testUnregisterComponentID();
    void testUnregisterSameComponentName();
    void testUnregisterSameComponentID();
private:
    int nNewComponents;
};

#endif // TEST_IDFACTORY_H
