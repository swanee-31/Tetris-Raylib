cmake_minimum_required(VERSION 3.15)
project(Tetris-Raylib VERSION 1.0.0 LANGUAGES CXX)

# Configuration standard C++ 
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Gestion de Raylib via FetchContent ---
include(FetchContent)
FetchContent_Declare(
  raylib
  GIT_REPOSITORY https://github.com/raysan5/raylib.git
  GIT_TAG        master  # Ou une version spécifique comme "5.0"
)

# On s'assure que Raylib ne build pas ses propres exemples pour gagner du temps
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(raylib)

# 1. On liste les fichiers sources (.cpp)
set(SOURCES
    main.cpp
    src/Game.cpp
    src/Grid.cpp
    src/Position.cpp
    src/Block.cpp
    src/Blocks.cpp
)

# 2. On crée l'exécutable en indiquant la cible et ses sources
add_executable(${PROJECT_NAME} ${SOURCES})

# 3. On indique où se trouvent les fichiers d'en-tête (.h) pour cette cible
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes)

# 4. Liens avec Raylib
target_link_libraries(${PROJECT_NAME} raylib)

# --- Options spécifiques à Windows pour éviter la console en arrière-plan ---
if(WIN32)
    target_link_options(${PROJECT_NAME} PRIVATE $<$<CONFIG:Release>:/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup>)
endif()



