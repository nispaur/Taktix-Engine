#include <Engine/Managers/InputManager.hpp>

#include <Engine/TaktixEngine.hpp>

namespace Tx
{
    namespace Engine
    {
        InputManager::InputManager()
        {
            releaseInputsInternal();
        }

        InputManager::~InputManager()
        {

        }

        void InputManager::handleEvent( const sf::Event& event )
        {
            switch ( event.type )
            {
                case sf::Event::Closed:
                    {
                        TaktixEngine::instance()->m_renderWindow.close();
                    }
                    break;
                case sf::Event::Resized:
                    {
                        float width = static_cast<float>( event.size.width );
                        float height = static_cast<float>( event.size.height );

                        handleWindowResize( width, height );
                    }
                    break;
                case sf::Event::LostFocus:
                    {
                        // Will be implemented later...
                    }
                    break;
                case sf::Event::GainedFocus:
                    {
                        // Will be implemented later...
                    }
                    break;
                case sf::Event::TextEntered:
                    {
                        // Will be implemented later...
                    }
                    break;
                case sf::Event::KeyPressed:
                    {
                        keyPressed( event.key.code );
                    }
                    break;
                case sf::Event::KeyReleased:
                    {
                        keyReleased( event.key.code );
                    }
                    break;
                case sf::Event::MouseWheelMoved:
                    {
                        m_mousePosition.x = event.mouseWheel.x;
                        m_mousePosition.y = event.mouseWheel.y;

                        m_mouseWheelDelta = event.mouseWheel.delta;
                    }
                    break;
                case sf::Event::MouseWheelScrolled:
                    {
                        // Will be implemented later...
                    }
                    break;
                case sf::Event::MouseButtonPressed:
                    {
                        m_mousePosition.x = event.mouseButton.x;
                        m_mousePosition.y = event.mouseButton.y;

                        buttonPressed( event.mouseButton.button );
                    }
                    break;
                case sf::Event::MouseButtonReleased:
                    {
                        m_mousePosition.x = event.mouseButton.x;
                        m_mousePosition.y = event.mouseButton.y;

                        buttonReleased( event.mouseButton.button );
                    }
                    break;
                case sf::Event::MouseMoved:
                    {
                        m_mousePosition.x = event.mouseButton.x;
                        m_mousePosition.y = event.mouseButton.y;
                    }
                    break;
                case sf::Event::MouseEntered:
                    {
                        // Will be implemented later...
                    }
                    break;
                case sf::Event::MouseLeft:
                    {
                        // Will be implemented later...
                    }
                    break;
                case sf::Event::JoystickButtonPressed:
                    {
                        // Will be implemented later...
                    }
                    break;
                case sf::Event::JoystickButtonReleased:
                    {
                        // Will be implemented later...
                    }
                    break;
                case sf::Event::JoystickMoved:
                    {
                        // Will be implemented later...
                    }
                    break;
                case sf::Event::JoystickConnected:
                    {
                        // Will be implemented later...
                    }
                    break;
                case sf::Event::JoystickDisconnected:
                    {
                        // Will be implemented later...
                    }
                    break;
                case sf::Event::TouchBegan:
                    {
                        // Will be implemented later...
                    }
                    break;
                case sf::Event::TouchMoved:
                    {
                        // Will be implemented later...
                    }
                    break;
                case sf::Event::TouchEnded:
                    {
                        // Will be implemented later...
                    }
                    break;
                case sf::Event::SensorChanged:
                    {
                        // Will be implemented later...
                    }
                    break;
                default: break;
            }
        }

        bool InputManager::isKeyPressed( const sf::Keyboard::Key& key ) const
        {
            return m_keysPressed[key];
        }

        bool InputManager::isButtonPressed( const sf::Mouse::Button& button ) const
        {
            return m_buttonsPressed[button];
        }

        void InputManager::keyPressed( const sf::Keyboard::Key& key )
        {
            m_keysPressed[key] = true;
        }

        void InputManager::keyReleased( const sf::Keyboard::Key& key )
        {
            m_keysPressed[key] = false;
        }

        void InputManager::buttonPressed( const sf::Mouse::Button& button )
        {
            m_buttonsPressed[button] = true;
        }

        void InputManager::buttonReleased( const sf::Mouse::Button& button )
        {
            m_buttonsPressed[button] = false;
        }

        void InputManager::handleWindowResize( float width, float height )
        {

            sf::FloatRect dimensions( 0.0f, 0.0f, width, height );

            sf::View view = sf::View( dimensions );

            TaktixEngine::instance()->m_renderWindow.setView( view );
        }

        void InputManager::releaseInputsInternal()
        {
            for ( int i = 0 ; i < sf::Keyboard::Key::KeyCount ; ++i )
            {
                m_keysPressed[i] = false;
            }

            for ( int i = 0 ; i < sf::Mouse::Button::ButtonCount ; ++i )
            {
                m_buttonsPressed[i] = false;
            }
        }
    } // namespace Engine
} // namespace Tx
