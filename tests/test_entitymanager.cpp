#include "test_entitymanager.h"
#include "componentmanager.h"

CPPUNIT_TEST_SUITE_REGISTRATION(EntityManagerTests);

void EntityManagerTests::setUp()
{
}

void EntityManagerTests::tearDown()
{
}

void EntityManagerTests::testAddEntity()
{
    cs::EntityManager entityManager;
    cs::Entity entity;
    cs::ID id;
    CPPUNIT_ASSERT_NO_THROW(id = entityManager.addEntity(entity));
    CPPUNIT_ASSERT_EQUAL(true, entityManager.entityExists(id));
}

void EntityManagerTests::testEntityExists()
{
    cs::EntityManager entityManager;
    cs::Entity entity;
    cs::ID id;
    CPPUNIT_ASSERT_NO_THROW(id = entityManager.addEntity(entity));
    CPPUNIT_ASSERT_EQUAL(true, entityManager.entityExists(id));
}

void EntityManagerTests::testRemoveEntity()
{
    cs::EntityManager entityManager;
    cs::Entity entity;
    cs::ID id;
    CPPUNIT_ASSERT_NO_THROW(id = entityManager.addEntity(entity));
    CPPUNIT_ASSERT_NO_THROW(entityManager.removeEntity(id));
    CPPUNIT_ASSERT_EQUAL(false, entityManager.entityExists(id));
}
