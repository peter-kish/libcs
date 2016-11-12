#include "test_componentmanager.h"
#include "cs.h"

CPPUNIT_TEST_SUITE_REGISTRATION(ComponentManagerTests);

void ComponentManagerTests::setUp()
{
    nNewComponents = 256;
}

void ComponentManagerTests::tearDown()
{

}

void ComponentManagerTests::testGetComponentID()
{
    cs::ComponentSystem componentSystem;
    cs::ID id = componentSystem.componentManager.getComponentID("Component1");
    CPPUNIT_ASSERT(id != cs::INVALID_ID);
}

