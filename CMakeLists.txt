cmake_minimum_required(VERSION 3.16)
project(Chess LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

set(INCLUDE_DIRECTORY ${PROJECT_SOURCE_DIR}/include)
set(INCLUDE_SOURCES ${INCLUDE_DIRECTORY}/Board.h ${INCLUDE_DIRECTORY}/Piece.h ${INCLUDE_DIRECTORY}/Game.h)

include(FetchContent)
FetchContent_Declare(
	SFML
	GIT_REPOSITORY https://github.com/SFML/SFML.git
	GIT_TAG 2.6.x
)
FetchContent_MakeAvailable(SFML)

add_executable(Chess src/main.cpp ${INCLUDE_SOURCES})
target_link_libraries(Chess PRIVATE sfml-graphics)
target_compile_features(Chess PRIVATE cxx_std_17)

target_include_directories(Chess PRIVATE ${INCLUDE_DIRECTORY})

if (WIN32)
	add_custom_command(
		TARGET Chess
		COMMENT "Copy OpenAL DLL"
		PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64, x86>/openal32.dll $<TARGET_FILE_DIR:Chess>
		VERBATIM
		)
endif()

install(TARGETS Chess)
