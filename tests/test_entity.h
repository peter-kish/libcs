#ifndef TEST_ENTITY_H
#define TEST_ENTITY_H

#include "cs.h"
#include <cppunit/extensions/HelperMacros.h>

class EntityTests : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(EntityTests);
    CPPUNIT_TEST(testGetComponent);
    CPPUNIT_TEST(testHasComponent);
    CPPUNIT_TEST(testAddComponent);
    CPPUNIT_TEST(testRemoveComponent);
    CPPUNIT_TEST_SUITE_END();
public:
    void setUp();
    void tearDown();

    void testGetComponent();
    void testHasComponent();
    void testAddComponent();
    void testRemoveComponent();
private:
};

#endif // TEST_IDFACTORY_H
