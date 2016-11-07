#include <string>
#include <exception>
#include "componentmanager.h"
#include "eventmanager.h"
#include "entitymanager.h"
#include "entity.h"
#include "component.h"
#include "keymap.h"
#include "idfactory.h"

namespace cs
{
    class Exception: public std::exception
    {
        public:
            Exception(const char* what): w(what) {}
            Exception(std::string& what): w(what) {}

            virtual const char* what() const throw()
            {
                return w.c_str();
            }
        private:
            std::string w;
    };

    class ComponentSystem
    {
    public:
        ComponentManager componentManager;
        EventManager eventManager;
        EntityManager entityManager;
    };
}
