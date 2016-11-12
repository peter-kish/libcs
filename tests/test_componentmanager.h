#ifndef TEST_COMPONENTMANAGER_H
#define TEST_COMPONENTMANAGER_H

#include "cs.h"
#include <cppunit/extensions/HelperMacros.h>

class ComponentManagerTests : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(ComponentManagerTests);
    CPPUNIT_TEST(testGetComponentID);
    CPPUNIT_TEST_SUITE_END();
public:
    void setUp();
    void tearDown();

    void testGetComponentID();
private:
    int nNewComponents;
};

#endif // TEST_IDFACTORY_H
