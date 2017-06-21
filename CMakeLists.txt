CMAKE_MINIMUM_REQUIRED( VERSION 2.8.3 )

# Project name

PROJECT( Taktix )

# Version number

SET( Taktix_VERSION_MAJOR 1 )
SET( Taktix_VERSION_MINOR 0 )

# Set compilation flags

SET( CMAKE_CXX_STANDARD 11 )
SET( CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++11 -g ${CMAKE_CXX_FLAGS}" )

# Update CMake's path

SET( CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake" ${CMAKE_MODULE_PATH} )

# Try to find SFML2
# Set includes directories

FIND_PACKAGE( SFML 2 REQUIRED network audio graphics window system )

IF( SFML_FOUND )
    INCLUDE_DIRECTORIES( ${SFML_INCLUDE_DIR} )
ELSE()
  MESSAGE( "SFML directory not found." )
ENDIF()

INCLUDE_DIRECTORIES( "${CMAKE_SOURCE_DIR}/Includes" )

# Sources files

FILE(
  GLOB_RECURSE
  SOURCES
  "${CMAKE_SOURCE_DIR}/Includes/*.hpp"
  "${CMAKE_SOURCE_DIR}/Sources/*.cpp"
)

# Create executable with its sources

ADD_EXECUTABLE( "Taktix" ${SOURCES} )

# Link SFML with the executable

TARGET_LINK_LIBRARIES( "Taktix" ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} )

# Copy includes folder in destination folder

FILE( COPY Assets DESTINATION "${CMAKE_SOURCE_DIR}/Build/." )
FILE( COPY Includes DESTINATION "${CMAKE_SOURCE_DIR}/Build/." )

# Put the executable in the same folder

INSTALL( TARGETS "Taktix" RUNTIME DESTINATION "${CMAKE_SOURCE_DIR}/Build/." )
