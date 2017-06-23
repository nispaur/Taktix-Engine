#include <Engine/TaktixEngine.hpp>

int main( int argc, char * argv[] )
{
    ( void ) argc;
    ( void ) argv;

    Tx::Engine::TaktixEngine::instance()->run();

    return 0;
}
