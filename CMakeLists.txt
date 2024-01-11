cmake_minimum_required(VERSION 3.20.0)
project(Onigiri VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(THIRD_PARTY_DIR third_party)
set(ONIGIRI_SOURCE_DIR src)
set(ONIGIRI_SOURCE_FILES 
        ${ONIGIRI_SOURCE_DIR}/main.cpp 
        ${ONIGIRI_SOURCE_DIR}/Application.cpp 
        ${ONIGIRI_SOURCE_DIR}/handlers/InputHandler.cpp
        ${ONIGIRI_SOURCE_DIR}/handlers/TextureHandler.cpp)

# exe
add_executable(${PROJECT_NAME} ${ONIGIRI_SOURCE_FILES})

# include
target_include_directories(${PROJECT_NAME} PUBLIC ${THIRD_PARTY_DIR}/include)

# lib
find_library(LIB_SDL NAMES SDL2 PATHS ${THIRD_PARTY_DIR}/lib/x64 REQUIRED)
find_library(LIB_SDL_MAIN NAMES SDL2main PATHS ${THIRD_PARTY_DIR}/lib/x64 REQUIRED)
find_library(LIB_SDL_IMAGE NAMES SDL2_image PATHS ${THIRD_PARTY_DIR}/lib/x64 REQUIRED)

target_link_libraries(${PROJECT_NAME} ${LIB_SDL} ${LIB_SDL_MAIN} ${LIB_SDL_IMAGE})

target_compile_options(${PROJECT_NAME} PRIVATE -w)