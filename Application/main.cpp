#include <iostream>

#include <SFML/Graphics.hpp>

int main( int argc, char * argv[] )
{
    ( void ) argc;
    ( void ) argv;

    sf::RenderWindow window( sf::VideoMode(640, 480), "Taktix-Engine" );

    sf::Image logoImage;
    sf::Texture logoTexture;
    sf::Sprite logoSprite;

    logoImage.loadFromFile( "Assets/Logos/logo_doxygen.png" );
    logoTexture.loadFromImage( logoImage );
    logoSprite.setTexture( logoTexture, true );

    logoSprite.setPosition( ( window.getSize().x - logoSprite.getGlobalBounds().width ) / 2,
                            ( window.getSize().y - logoSprite.getGlobalBounds().height ) / 2 );

    while (window.isOpen())
    {
        sf::Event event;

        while ( window.pollEvent( event ) )
        {
            if ( event.type == sf::Event::Closed )
            {
                window.close();
            }
        }

        window.clear();

        window.draw( logoSprite );

        window.display();
    }

    return 0;
}
