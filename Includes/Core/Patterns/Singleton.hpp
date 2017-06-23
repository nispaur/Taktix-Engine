#ifndef HEADER_SINGLETON_HPP
#define HEADER_SINGLETON_HPP

#include <cassert>

namespace Tx
{
    namespace Core
    {
        template<class T>
        class Singleton
        {
        public:
            static T * instance();

        protected:
            explicit Singleton();
            virtual ~Singleton();

        protected:
            static T * s_instance;
        };
    } // namespace Core
} // namespace Tx

#include "Singleton.inl"

#endif // HEADER_SINGLETON_HPP
