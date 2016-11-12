#ifndef TEST_KEYMAP_H
#define TEST_KEYMAP_H

#include "cs.h"
#include <cppunit/extensions/HelperMacros.h>

class KeyMapTests : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(KeyMapTests);
    CPPUNIT_TEST(testRegisterKey);
    CPPUNIT_TEST(testRegisterSameKey);
    CPPUNIT_TEST(testIsKeyRegistered);
    CPPUNIT_TEST(testNewKeys);
    CPPUNIT_TEST(testUnregisterKey);
    CPPUNIT_TEST(testUnregisterSameKey);
    CPPUNIT_TEST(testGetKeyID);
    CPPUNIT_TEST_SUITE_END();
public:
    void setUp();
    void tearDown();

    void testRegisterKey();
    void testRegisterSameKey();
    void testIsKeyRegistered();
    void testNewKeys();
    void testUnregisterKey();
    void testUnregisterSameKey();
    void testGetKeyID();
private:
    int nNewKeys;
};

#endif // TEST_KEYMAP_H
