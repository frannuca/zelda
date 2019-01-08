cmake_minimum_required(VERSION 3.7)

project(attackovertime)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(STATUS "this is project source" ${PROJECT_SOURCE_DIR})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

find_package( ZLIB REQUIRED )
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)


include_directories(${SDL2_INCLUDE_DIR}
                    ${SDL2_IMAGE_INCLUDE_DIR}
                    ${SDL2_TTF_INCLUDE_DIR}
                    ${ZLIB_INCLUDE_DIRS})

add_executable(attackovertime main.cpp Game.cpp Game.h TextureManager.cpp TextureManager.h Map.cpp Map.h ECS/ECS.h ECS/SpriteComponent.h ECS/TransformComponent.h ECS/Components.h Vector2D.cpp Vector2D.h ECS/KeyboardController.h ECS/ColliderComponent.h ECS/Collision.cpp ECS/Collision.h ECS/TileComponent.cpp ECS/TileComponent.h Observer.cpp Observer.h)

target_link_libraries(attackovertime ${SDL2_LIBRARY}
                             ${SDL2_IMAGE_LIBRARIES}
                             ${SDL2_TTF_LIBRARIES}
                             ${ZLIB_LIBRARIES})


