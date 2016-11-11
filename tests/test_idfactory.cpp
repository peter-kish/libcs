#include "test_idfactory.h"
#include <vector>
#include <iostream>

// Registers the fixture into the "registry"
CPPUNIT_TEST_SUITE_REGISTRATION(IDFactoryTests);

void IDFactoryTests::setUp()
{
    nNewIDs = 256;
}

void IDFactoryTests::tearDown()
{

}

void IDFactoryTests::testMaxNoOfIDs()
{
    unsigned long idCount = 0;
    cs::IDFactory idFactory;
    unsigned long max = cs::IDFactory::getMaxNoOfIDs();

    std::cout << "Generating " << max << " IDs. This may take a while..." << std::endl;

    try {
        while(true)
        {
            ++idCount;
            cs::ID id = idFactory.getNewID();
        }
    }
    catch (cs::Exception& e)
    {
        CPPUNIT_ASSERT_EQUAL(max, idCount - 1);
    }
}

void IDFactoryTests::testNewIDs()
{
    std::vector<cs::ID> generatedIDs;
    cs::IDFactory idFactory;

    for(int i = 0; i < nNewIDs; i++)
    {
        generatedIDs.push_back(idFactory.getNewID());
    }

    // Check if all IDs are unique
    for(int i = 0; i < generatedIDs.size(); i++)
    {
        for(int j = i + 1 ; j < generatedIDs.size(); j++)
        {
            CPPUNIT_ASSERT(generatedIDs[i] != generatedIDs[j]);
        }
    }
}

