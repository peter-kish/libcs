#include "test_entity.h"
#include "componentmanager.h"

CPPUNIT_TEST_SUITE_REGISTRATION(EntityTests);

void EntityTests::setUp()
{
}

void EntityTests::tearDown()
{

}

void EntityTests::testGetComponent()
{
    cs::ComponentManager componentManager;
    cs::ID componentID = componentManager.registerComponent("Component1");
    cs::Entity entity;
    auto component = std::make_shared<cs::Component>(&entity, componentID);
    entity.addComponent(component);
    std::shared_ptr<cs::Component> gotComponent = nullptr;
    CPPUNIT_ASSERT_NO_THROW(gotComponent = entity.getComponent(componentManager.getComponentID("Component1")));
    CPPUNIT_ASSERT_EQUAL(componentID, gotComponent->id);
}

void EntityTests::testHasComponent()
{
    cs::ComponentManager componentManager;
    cs::ID componentID = componentManager.registerComponent("Component1");
    cs::Entity entity;
    auto component = std::make_shared<cs::Component>(&entity, componentID);
    CPPUNIT_ASSERT_NO_THROW(entity.addComponent(component));
    CPPUNIT_ASSERT_EQUAL(true, entity.hasComponent(componentManager.getComponentID("Component1")));
}

void EntityTests::testAddComponent()
{
    cs::ComponentManager componentManager;
    cs::ID componentID = componentManager.registerComponent("Component1");
    cs::Entity entity;
    auto component = std::make_shared<cs::Component>(&entity, componentID);
    CPPUNIT_ASSERT_NO_THROW(entity.addComponent(component));
    CPPUNIT_ASSERT_EQUAL(true, entity.hasComponent(componentID));
}

void EntityTests::testRemoveComponent()
{
    cs::ComponentManager componentManager;
    cs::ID componentID = componentManager.registerComponent("Component1");
    cs::Entity entity;
    auto component = std::make_shared<cs::Component>(&entity, componentID);
    CPPUNIT_ASSERT_NO_THROW(entity.addComponent(component));
    entity.removeComponent(component);
    CPPUNIT_ASSERT_EQUAL(false, entity.hasComponent(componentID));
}
