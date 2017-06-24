#ifndef HEADER_RESOURCEMANAGER_HPP
#define HEADER_RESOURCEMANAGER_HPP

#include <iostream>

#include <Core/Patterns/Singleton.hpp>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

namespace Tx
{
    namespace Engine
    {
        template<class T>
        class ResourceManager
        {
        public:
            ResourceManager();
            ~ResourceManager();

            virtual void registerResource( const std::string& name,
                                           const std::string& path ) = 0;
            virtual void registerDefaultResource( const std::string& path ) = 0;

            T& getResource( const std::string& name );

        protected:
            std::map<std::string, T> m_resources;

            T m_defaultResource;
        };
    } // namespace Engine
} // namespace Tx

namespace Tx
{
    namespace Engine
    {
        class FontManager : public ResourceManager<sf::Font>,
                            public Core::Singleton<FontManager>
        {
        public:
            void registerResource( const std::string& name,
                                   const std::string& path ) override;
            void registerDefaultResource( const std::string& path ) override;
        };

        class ImageManager : public ResourceManager<sf::Image>,
                             public Core::Singleton<ImageManager>
        {
        public:
            void registerResource( const std::string& name,
                                   const std::string& path ) override;
            void registerDefaultResource( const std::string& path ) override;
        };

        class MusicManager : public ResourceManager<sf::Music>,
                             public Core::Singleton<MusicManager>
        {
        public:
            void registerResource( const std::string& name,
                                   const std::string& path ) override;
            void registerDefaultResource( const std::string& path ) override;
        };

        class SoundManager : public ResourceManager<sf::Sound>,
                             public Core::Singleton<SoundManager>
        {
        public:
            void registerResource( const std::string& name,
                                   const std::string& path ) override;
            void registerDefaultResource( const std::string& path ) override;
        };

        class TextureManager : public ResourceManager<sf::Texture>,
                               public Core::Singleton<TextureManager>
        {
        public:
            void registerResource( const std::string& name,
                                   const std::string& path ) override;
            void registerDefaultResource( const std::string& path ) override;
        };
    }
}

#include <Engine/Managers/ResourceManager.inl>

#endif // HEADER_RESOURCEMANAGER_HPP
