cmake_minimum_required(VERSION 3.16)
project(chess LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

set(SRC_DIRECTORY ${PROJECT_SOURCE_DIR}/src)
set(SRC_SOURCES ${SRC_DIRECTORY}/main.cpp ${SRC_DIRECTORY}/board.cpp ${SRC_DIRECTORY}/game.cpp ${SRC_DIRECTORY}/piece.cpp ${SRC_DIRECTORY}/player.cpp ${SRC_DIRECTORY}/sfmldisplay.cpp ${SRC_DIRECTORY}/input_manager.cpp ${SRC_DIRECTORY}/config.cpp ${SRC_DIRECTORY}/pieces/knight.cpp ${SRC_DIRECTORY}/pieces/pawn.cpp ${SRC_DIRECTORY}/pieces/rook.cpp ${SRC_DIRECTORY}/pieces/bishop.cpp ${SRC_DIRECTORY}/pieces/king.cpp ${SRC_DIRECTORY}/pieces/queen.cpp)

set(INCLUDE_DIRECTORY ${PROJECT_SOURCE_DIR}/include)
set(INCLUDE_SOURCES ${INCLUDE_DIRECTORY}/Board.h ${INCLUDE_DIRECTORY}/Piece.h ${INCLUDE_DIRECTORY}/Game.h ${INCLUDE_DIRECTORY}/Player.h ${INCLUDE_DIRECTORY}/Player.h ${INCLUDE_DIRECTORY}/SFMLDisplay.h ${INCLUDE_DIRECTORY}/InputManager.h ${INCLUDE_DIRECTORY}/Config.h ${INCLUDE_DIRECTORY}/Move.h ${INCLUDE_DIRECTORY}/Pieces/Pawn.h ${INCLUDE_DIRECTORY}/Pieces/Knight.h ${INCLUDE_DIRECTORY}/Pieces/Rook.h ${INCLUDE_DIRECTORY}/Pieces/Bishop.h ${INCLUDE_DIRECTORY}/Pieces/King.h ${INCLUDE_DIRECTORY}/Pieces/Queen.h)

# Assets
set(ASSETS_DIRECTORY ${PROJECT_SOURCE_DIR}/assets)
set(ASSETS_DEST_DIR ${CMAKE_BINARY_DIR})

include(FetchContent)

FetchContent_Declare(
	SFML
	GIT_REPOSITORY https://github.com/SFML/SFML.git
	GIT_TAG 2.6.x
)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

add_executable(chess ${SRC_SOURCES} ${INCLUDE_SOURCES})
target_link_libraries(chess PRIVATE sfml-graphics nlohmann_json::nlohmann_json)
target_compile_features(chess PRIVATE cxx_std_17)

target_include_directories(chess PRIVATE ${INCLUDE_DIRECTORY})

# Copy config.json to build directory
configure_file(config.json ${CMAKE_BINARY_DIR}/config.json COPYONLY)

# Copy assets to build directory
file(COPY ${ASSETS_DIRECTORY} DESTINATION ${ASSETS_DEST_DIR})


install(TARGETS chess)
