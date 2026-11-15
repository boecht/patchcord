cmake_minimum_required(VERSION 3.31)

project(patchcord VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(AOO_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external/aoo")
if(NOT EXISTS "${AOO_DIR}/CMakeLists.txt")
    message(FATAL_ERROR
        "The AOO submodule at external/aoo is not checked out.\n"
        "Run: git submodule update --init --recursive")
endif()

# AOO build options: static library with bundled Opus, no networking layer,
# no examples (and so no PortAudio), no install rules.
set(AOO_USE_OPUS ON CACHE BOOL "" FORCE)
set(AOO_LOCAL_OPUS ON CACHE BOOL "" FORCE)
set(AOO_NET OFF CACHE BOOL "" FORCE)
set(AOO_USE_IPV6 ON CACHE BOOL "" FORCE)
set(AOO_BUILD_SHARED_LIBRARY OFF CACHE BOOL "" FORCE)
set(AOO_INSTALL_LIBRARY OFF CACHE BOOL "" FORCE)
set(AOO_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory("${AOO_DIR}" EXCLUDE_FROM_ALL)

add_executable(patchcord src/main.cpp)
target_compile_definitions(patchcord PRIVATE
    PATCHCORD_VERSION="${PROJECT_VERSION}")
target_link_libraries(patchcord PRIVATE Aoo::aoo)

enable_testing()
add_subdirectory(tests)
