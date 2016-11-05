#ifndef IDFACTORY_H
#define IDFACTORY_H

#include <vector>

namespace cs
{
    typedef unsigned int ID;
    const ID INVALID_ID = 0;

    class IDFactory
    {
        public:
            IDFactory() : lastID(1) {};
            ID getNewID();
            static unsigned long getMaxNoOfIDs();
        private:
            std::vector<ID> discardedIDs;
            ID lastID;
    };
}

#endif
