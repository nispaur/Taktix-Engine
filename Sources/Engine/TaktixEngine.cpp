#include <Engine/TaktixEngine.hpp>

namespace Tx
{
    namespace Engine
    {
        TaktixEngine::TaktixEngine() :
            m_renderWindow( sf::VideoMode( 640, 480 ), "Taktix-Engine" )
        {

        }

        TaktixEngine::~TaktixEngine()
        {

        }

        void TaktixEngine::run()
        {
            initialize();

            while ( m_renderWindow.isOpen() )
            {
                handleInput();
                handleUpdate();
                handleDisplay();
            }
        }

        void TaktixEngine::initialize()
        {
            // Some stuff here...
        }

        void TaktixEngine::handleInput()
        {
            sf::Event event;

            while ( m_renderWindow.pollEvent( event ) )
            {
                switch ( event.type )
                {
                    case sf::Event::Closed:
                        m_renderWindow.close();
                        break;
                    default:
                        break;
                }
            }
        }

        void TaktixEngine::handleUpdate()
        {
            // Some stuff here...
        }

        void TaktixEngine::handleDisplay()
        {
            m_renderWindow.clear( sf::Color( 0xFF, 0xFF, 0xFF, 0xFF ) );

            // Some stuff here

            m_renderWindow.display();
        }
    } // namespace Engine
} // namespace Tx
