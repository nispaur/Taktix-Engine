#ifndef HEADER_INPUTMANAGER_HPP
#define HEADER_INPUTMANAGER_HPP

#include <array>

#include <Core/Patterns/Singleton.hpp>

#include <SFML/Window.hpp>

namespace Tx
{
    namespace Engine
    {
        class InputManager : public Core::Singleton<InputManager>
        {
        public:
            InputManager();
            ~InputManager();

            void handleEvent( const sf::Event& event );

            bool isKeyPressed( const sf::Keyboard::Key& key ) const;
            bool isButtonPressed( const sf::Mouse::Button& button ) const;

        private:
            void keyPressed( const sf::Keyboard::Key& key );
            void keyReleased( const sf::Keyboard::Key& key );

            void buttonPressed( const sf::Mouse::Button& button );
            void buttonReleased( const sf::Mouse::Button& button );

            void handleWindowResize( float width, float height );

            void releaseInputsInternal();

        private:
            sf::Uint32 m_mouseWheelDelta;

            sf::Vector2i m_mousePosition;

            std::array<bool, sf::Keyboard::Key::KeyCount> m_keysPressed;
            std::array<bool, sf::Mouse::Button::ButtonCount> m_buttonsPressed;
        };
    } // namespace Engine
} // namespace Tx

#endif // HEADER_INPUTMANAGER_HPP
