#ifndef IDFACTORY_H
#define IDFACTORY_H

#include <vector>

namespace cs
{
    typedef unsigned int ID;

    class IDFactory
    {
        public:
            IDFactory() : lastID(0) {};
            ID getNewID();
            static unsigned long getMaxNoOfIDs();
        private:
            std::vector<ID> discardedIDs;
            ID lastID;
    };
}

#endif
