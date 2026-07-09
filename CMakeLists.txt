cmake_minimum_required(VERSION 4.3)

project(
    IndustryGame
    VERSION 0.1.0
    DESCRIPTION "Mines, Factories and Trucks"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(IndustryGame)
target_sources(
    IndustryGame PRIVATE
    src/main.cpp
    src/game/game.hpp
    src/core/color.hpp
    src/rendering/irenderer.hpp
    src/resources/resource_definition.hpp
    src/resources/resource.hpp
    src/resources/resource_storage.hpp
    src/buildings/building_definition.hpp
    src/trucks/truck_definition.hpp
    src/resources/resource_processor.hpp
    src/rendering/raylib_renderer.hpp
)

target_include_directories(IndustryGame PRIVATE src)


include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY
    https://github.com/raysan5/raylib.git
    GIT_TAG master)
FetchContent_MakeAvailable(raylib)

target_link_libraries(IndustryGame PRIVATE raylib)
