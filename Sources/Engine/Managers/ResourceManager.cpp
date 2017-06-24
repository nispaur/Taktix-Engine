#include <Engine/Managers/ResourceManager.hpp>

namespace Tx
{
    namespace Engine
    {
        void ImageManager::registerResource( const std::string& name,
                                             const std::string& path )
        {
            sf::Image image;

            std::map<std::string, sf::Image>::iterator it = m_resources.find( name );

            if ( it != m_resources.end() )
            {
                // Handle errors with a Log (later)
                std::cerr << "Image \"" << name << "\" already exists !" << std::endl;
                return;
            }

            if ( !image.loadFromFile( path ) )
            {
                // Handle errors with a Log (later)
                std::cerr << "Unable to load \"" << name << "\" image !" << std::endl;
                return;
            }

            m_resources.insert( std::pair<std::string, sf::Image>( name, image ) );
        }

        void ImageManager::registerDefaultResource( const std::string& path )
        {
            sf::Image image;

            if ( !image.loadFromFile( path ) )
            {
                // Handle errors with a Log (later)
                std::cerr << "Unable to load default image !" << std::endl;
                return;
            }

            m_defaultResource = image;
        }

        void TextureManager::registerResource( const std::string& name,
                                               const std::string& path )
        {
            sf::Texture texture;

            std::map<std::string, sf::Texture>::iterator it = m_resources.find( name );

            if ( it != m_resources.end() )
            {
                // Handle errors with a Log (later)
                std::cerr << "Texture \"" << name << "\" already exists !" << std::endl;
                return;
            }

            if ( !texture.loadFromFile( path ) )
            {
                // Handle errors with a Log (later)
                std::cerr << "Unable to load \"" << name << "\" texture !" << std::endl;
                return;
            }

            m_resources.insert( std::pair<std::string, sf::Texture>( name, texture ) );
        }

        void TextureManager::registerDefaultResource( const std::string& path )
        {
            sf::Texture texture;

            if ( !texture.loadFromFile( path ) )
            {
                // Handle errors with a Log (later)
                std::cerr << "Unable to load default texture !" << std::endl;
                return;
            }

            m_defaultResource = texture;
        }
    } // namespace Engine
} // namespace Tx
