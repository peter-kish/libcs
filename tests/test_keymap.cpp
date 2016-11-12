#include "test_keymap.h"
#include <vector>
#include <iostream>

// Registers the fixture into the "registry"
CPPUNIT_TEST_SUITE_REGISTRATION(KeyMapTests);

void KeyMapTests::setUp()
{
    nNewKeys = 256;
}

void KeyMapTests::tearDown()
{

}

void KeyMapTests::testRegisterKey()
{
    cs::KeyMap keyMap;

    CPPUNIT_ASSERT_NO_THROW(keyMap.registerKey("Key1"));
}

void KeyMapTests::testRegisterSameKey()
{
    cs::KeyMap keyMap;

    cs::ID id1 = keyMap.registerKey("Key1");
    CPPUNIT_ASSERT_THROW(keyMap.registerKey("Key1"), cs::Exception);
}

void KeyMapTests::testIsKeyRegistered()
{
    cs::KeyMap keyMap;

    keyMap.registerKey("Key1");
    CPPUNIT_ASSERT_EQUAL(true, keyMap.isKeyRegistered("Key1"));
}

void KeyMapTests::testNewKeys()
{
    cs::KeyMap keyMap;
    std::vector<cs::ID> generatedKeyIDs;

    for(int i = 0; i < nNewKeys; i++)
    {
        std::string key("Key");
        key += i;
        generatedKeyIDs.push_back(keyMap.registerKey(key));
    }
    //
    // Check if all IDs are unique
    for(int i = 0; i < generatedKeyIDs.size(); i++)
    {
        for(int j = i + 1 ; j < generatedKeyIDs.size(); j++)
        {
            CPPUNIT_ASSERT(generatedKeyIDs[i] != generatedKeyIDs[j]);
        }
    }
}

void KeyMapTests::testUnregisterKey()
{
    cs::KeyMap keyMap;

    CPPUNIT_ASSERT_NO_THROW(keyMap.registerKey("Key1"));
    CPPUNIT_ASSERT_NO_THROW(keyMap.unregisterKeyID(keyMap.getKeyID("Key1")));
    CPPUNIT_ASSERT_NO_THROW(keyMap.registerKey("Key1"));
}

void KeyMapTests::testUnregisterSameKey()
{
    cs::KeyMap keyMap;

    CPPUNIT_ASSERT_NO_THROW(keyMap.registerKey("Key1"));
    CPPUNIT_ASSERT_NO_THROW(keyMap.unregisterKeyID(keyMap.getKeyID("Key1")));
    CPPUNIT_ASSERT_THROW(keyMap.unregisterKeyID(keyMap.getKeyID("Key1")), cs::Exception);
}

void KeyMapTests::testGetKeyID()
{
    cs::KeyMap keyMap;
    cs::ID id;
    CPPUNIT_ASSERT_NO_THROW(id = keyMap.registerKey("Key1"));
    cs::ID gotID = keyMap.getKeyID("Key1");
    CPPUNIT_ASSERT_EQUAL(id, gotID);
}

