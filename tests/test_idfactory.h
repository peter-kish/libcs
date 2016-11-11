#ifndef TEST_IDFACTORY_H
#define TEST_IDFACTORY_H

#include "cs.h"
#include <cppunit/extensions/HelperMacros.h>

class IDFactoryTests : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(IDFactoryTests);
    //CPPUNIT_TEST(testMaxNoOfIDs);
    CPPUNIT_TEST(testNewIDs);
    CPPUNIT_TEST_SUITE_END();
public:
    void setUp();
    void tearDown();

    void testMaxNoOfIDs();
    void testNewIDs();
private:
    int nNewIDs;
};

#endif // TEST_IDFACTORY_H
