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

void ComponentManagerTests::testRegisterComponent()
{
    cs::ComponentManager componentManager;
    CPPUNIT_ASSERT_NO_THROW(componentManager.registerComponent("Component1"));
}

void ComponentManagerTests::testRegisterSameComponent()
{
    cs::ComponentManager componentManager;

    CPPUNIT_ASSERT_NO_THROW(componentManager.registerComponent("Component1"));
    CPPUNIT_ASSERT_THROW(componentManager.registerComponent("Component1"), cs::Exception);
}

void ComponentManagerTests::testRegisterNewComponents()
{
    cs::ComponentManager componentManager;
    std::vector<cs::ID> generatedComponentIDs;

    for(int i = 0; i < nNewComponents; i++)
    {
        std::string componentName = "Component";
        componentName += i;
        generatedComponentIDs.push_back(componentManager.registerComponent(componentName));
    }

    // Check if all IDs are unique
    for(int i = 0; i < generatedComponentIDs.size(); i++)
    {
        for(int j = i + 1 ; j < generatedComponentIDs.size(); j++)
        {
            CPPUNIT_ASSERT(generatedComponentIDs[i] != generatedComponentIDs[j]);
        }
    }
}

void ComponentManagerTests::testUnregisterComponentName()
{
    cs::ComponentManager componentManager;
    cs::ID id;
    CPPUNIT_ASSERT_NO_THROW(id = componentManager.registerComponent("Component1"));
    CPPUNIT_ASSERT_NO_THROW(componentManager.unregisterComponent("Component1"));
    CPPUNIT_ASSERT_NO_THROW(id = componentManager.registerComponent("Component1"));
}

void ComponentManagerTests::testUnregisterComponentID()
{
    cs::ComponentManager componentManager;
    cs::ID id;
    CPPUNIT_ASSERT_NO_THROW(id = componentManager.registerComponent("Component1"));
    CPPUNIT_ASSERT_NO_THROW(componentManager.unregisterComponent(id));
    CPPUNIT_ASSERT_NO_THROW(id = componentManager.registerComponent("Component1"));
}

void ComponentManagerTests::testUnregisterSameComponentName()
{
    cs::ComponentManager componentManager;

    CPPUNIT_ASSERT_NO_THROW(componentManager.registerComponent("Component1"));
    CPPUNIT_ASSERT_NO_THROW(componentManager.unregisterComponent("Component1"));
    CPPUNIT_ASSERT_THROW(componentManager.unregisterComponent("Component1"), cs::Exception);
}

void ComponentManagerTests::testUnregisterSameComponentID()
{
    cs::ComponentManager componentManager;
    cs::ID id;

    CPPUNIT_ASSERT_NO_THROW(id = componentManager.registerComponent("Component1"));
    CPPUNIT_ASSERT_NO_THROW(componentManager.unregisterComponent(id));
    CPPUNIT_ASSERT_THROW(componentManager.unregisterComponent("Component1"), cs::Exception);
}

