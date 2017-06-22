#include <SFML/Graphics.hpp>

int main( int argc, char * argv[] )
{
    ( void ) argc;
    ( void ) argv;

    sf::RenderWindow window( sf::VideoMode( 200, 200 ), "SFML works!" );
    sf::CircleShape shape( 100.0f );
    shape.setFillColor( sf::Color::Green );

    sf::Clock clock;

    while ( window.isOpen() )
    {
        sf::Event event;

        if ( clock.getElapsedTime().asSeconds() >= 3.0f )
        {
            window.close();
        }

        while ( window.pollEvent( event ) )
        {
            if ( event.type == sf::Event::Closed )
            {
                window.close();
            }
        }

        window.clear();
        window.draw( shape );
        window.display();
    }

    return 0;
}
