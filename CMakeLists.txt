cmake_minimum_required(VERSION 3.15)
project(SnakeGame VERSION 1.0.0 LANGUAGES CXX)

# Ustawienie standardu C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Pobieranie SFML bezpośrednio z GitHuba (wersja 2.6.2)
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.2
)
FetchContent_MakeAvailable(SFML)

# Podział na pliki źródłowe w folderze src/
# Dostosuj listę, jeśli Twoje pliki nazywają się inaczej
set(SOURCES
    src/main.cpp
    src/Game.cpp
    src/Snake.cpp
    src/Points.cpp
)

# Tworzenie pliku wykonywalnego
add_executable(SnakeGame ${SOURCES})

# Definiowanie folderu z plikami nagłówkowymi (.hpp / .h)
target_include_directories(SnakeGame PRIVATE include)

# Podlinkowanie modułów SFML (w tym sfml-audio)
target_link_libraries(SnakeGame PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)

# Automatyczna konfiguracja okna dla macOS (niezbędna przy FetchContent)
if(APPLE)
    set_target_properties(SnakeGame PROPERTIES
        MACOSX_BUNDLE TRUE
        MACOSX_BUNDLE_BUNDLE_NAME "Snake Game"
    )
endif()