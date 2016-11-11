#include "test_entitymanager.h"
#include "componentmanager.h"
#include "cs.h"

CPPUNIT_TEST_SUITE_REGISTRATION(EntityManagerTests);

void EntityManagerTests::setUp()
{
}

void EntityManagerTests::tearDown()
{
}

void EntityManagerTests::testAddEntity()
{
    cs::ComponentSystem componentSystem;
    cs::EntityManager& entityManager= componentSystem.entityManager;
    cs::Entity entity(&componentSystem);
    cs::ID id;
    CPPUNIT_ASSERT_NO_THROW(id = entityManager.addEntity(entity));
    CPPUNIT_ASSERT_EQUAL(true, entityManager.entityExists(id));
}

void EntityManagerTests::testEntityExists()
{
    cs::ComponentSystem componentSystem;
    cs::EntityManager& entityManager = componentSystem.entityManager;
    cs::Entity entity(&componentSystem);
    cs::ID id;
    CPPUNIT_ASSERT_NO_THROW(id = entityManager.addEntity(entity));
    CPPUNIT_ASSERT_EQUAL(true, entityManager.entityExists(id));
}

void EntityManagerTests::testRemoveEntity()
{
    cs::ComponentSystem componentSystem;
    cs::EntityManager& entityManager = componentSystem.entityManager;
    cs::Entity entity(&componentSystem);
    cs::ID id;
    CPPUNIT_ASSERT_NO_THROW(id = entityManager.addEntity(entity));
    CPPUNIT_ASSERT_NO_THROW(entityManager.removeEntity(id));
    CPPUNIT_ASSERT_EQUAL(false, entityManager.entityExists(id));
}
