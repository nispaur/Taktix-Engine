#ifndef HEADER_TAKTIXENGINE_HPP
#define HEADER_TAKTIXENGINE_HPP

#include <SFML/Graphics.hpp>

#include <Core/Patterns/Singleton.hpp>

namespace Tx
{
    namespace Engine
    {
        class TaktixEngine : public Core::Singleton<TaktixEngine>
        {
            friend class InputManager;

        public:
            TaktixEngine();
            ~TaktixEngine();

            void run();

        private:
            void initialize();

            void handleInput();
            void handleUpdate();
            void handleDisplay();

        private:
            sf::RenderWindow m_renderWindow;
        };
    }
}

#endif // HEADER_TAKTIXENGINE_HPP
