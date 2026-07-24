cmake_minimum_required(VERSION 4.3)

project(
    IndustryGame
    VERSION 0.1.0
    DESCRIPTION "Mines, Factories and Trucks"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(IndustryGame)
target_sources(
    IndustryGame PRIVATE
    src/main.cpp
    src/game/game.cpp
    src/game/game.hpp
    src/game/world.hpp
    src/game/world.cpp
    src/core/color.hpp
    src/core/id.hpp
    src/core/position.hpp
    src/rendering/irenderer.hpp
    src/rendering/raylib_renderer.cpp
    src/rendering/raylib_renderer.hpp
    src/rendering/world_renderer.hpp
    src/resources/resource_definition.hpp
    src/resources/resource_storage.hpp
    src/resources/resource_processor.hpp
    src/trucks/truck_definition.hpp
    src/trucks/truck.hpp
    src/buildings/building_definition.hpp
    src/buildings/building.hpp
    src/rendering/world_renderer.cpp
    src/version.hpp
    src/managers/production_manager.hpp
    src/managers/production_manager.cpp
)

target_include_directories(IndustryGame PRIVATE src)


add_subdirectory(external/raylib)

target_link_libraries(IndustryGame PRIVATE raylib)
