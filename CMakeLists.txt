cmake_minimum_required(VERSION 3.12)
project(Pong)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/Game/main.cpp src/Game/Application.cpp src/Entities/Ball.cpp src/Entities/Paddle.cpp src/Managers/CollisionManager.cpp src/Entities/PaddleBot.cpp)
add_executable(Pong ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Pong ${SFML_LIBRARIES})
endif()
