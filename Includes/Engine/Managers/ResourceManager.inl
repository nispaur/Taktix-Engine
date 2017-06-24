namespace Tx
{
    namespace Engine
    {
        template<class T>
        ResourceManager<T>::ResourceManager()
        {

        }

        template<class T>
        ResourceManager<T>::~ResourceManager()
        {

        }

        template<class T>
        T& ResourceManager<T>::getResource( const std::string& name )
        {
            for ( typename std::map<std::string, T>::iterator it = m_resources.begin()
                  ; it != m_resources.end()
                  ; ++it )
			{
				if ( it->first == name )
				{
					return it->second;
				}
			}

            // Handle errors with a Log (later)
            std::cerr << "There's no resource named \"" << name << "\" !" << std::endl;
            return m_defaultResource;
        }
    } // namespace Engine
} // namespace Tx
