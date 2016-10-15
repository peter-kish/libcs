#include <string>
#include <exception>

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
}
