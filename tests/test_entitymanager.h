#ifndef TEST_ENTITY_MANAGER_H
#define TEST_ENTITY_MANAGER_H

#include "cs.h"
#include <cppunit/extensions/HelperMacros.h>

class EntityManagerTests : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(EntityManagerTests);
    CPPUNIT_TEST(testAddEntity);
    CPPUNIT_TEST(testEntityExists);
    CPPUNIT_TEST(testRemoveEntity);
    CPPUNIT_TEST_SUITE_END();
public:
    void setUp();
    void tearDown();

    void testAddEntity();
    void testEntityExists();
    void testRemoveEntity();
private:
};

#endif // TEST_IDFACTORY_H
