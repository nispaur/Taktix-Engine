#include <Engine/TaktixEngine.hpp>

#include <Engine/Managers/InputManager.hpp>
#include <Engine/Managers/ResourceManager.hpp>

namespace Tx
{
    namespace Engine
    {
        TaktixEngine::TaktixEngine() :
            m_renderWindow( sf::VideoMode( 640, 480 ), "Taktix-Engine" )
        {
            //m_renderWindow.setVerticalSyncEnabled( true );
            m_renderWindow.setFramerateLimit( 60 );

            TextureManager::instance()->registerDefaultResource("Assets/unknown.png");

            TextureManager::instance()->registerResource("logo", "Assets/Logos/logo_doxygen.png");
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
                InputManager::instance()->handleEvent( event );
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
            sf::Sprite sprite;
            sprite.setTexture( TextureManager::instance()->getResource("logo") );
            m_renderWindow.draw( sprite );

            m_renderWindow.display();
        }
    } // namespace Engine
} // namespace Tx
