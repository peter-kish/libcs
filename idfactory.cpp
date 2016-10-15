#include <climits>
#include "cs.h"
#include "idfactory.h"

cs::ID cs::IDFactory::getNewID()
{
    if (lastID == getMaxNoOfIDs())
    {
        throw cs::Exception("ID factory depleted!");
    }
    return lastID++;
}

unsigned long cs::IDFactory::getMaxNoOfIDs()
{
    return UINT_MAX;
}
