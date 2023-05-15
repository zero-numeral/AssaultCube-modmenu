cmake_minimum_required(VERSION 3.12)
project(AssaultCube-modmenu)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# main target
add_library(menu MODULE)

file(GLOB_RECURSE SOURCES "src/*.cxx")
target_sources(menu PRIVATE ${SOURCES})
target_include_directories(menu PRIVATE include)

# OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(menu PRIVATE OpenGL::GL)

# minhook
add_library(minhook STATIC IMPORTED)
target_include_directories(minhook INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/minhook/include)
set_target_properties(minhook PROPERTIES IMPORTED_LOCATION_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/minhook/lib/libMinHook-x86-v141-mtd.lib
                                         IMPORTED_LOCATION_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/minhook/lib/libMinHook-x86-v141-mt.lib)
target_link_libraries(menu PRIVATE minhook)

# imgui
add_library(imgui STATIC)
file(GLOB IMGUI_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/imgui/*.cpp")
file(GLOB IMGUI_SOURCES_BACKENDS "${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends/*.cpp")
target_sources(imgui PRIVATE ${IMGUI_SOURCES}
                     PRIVATE ${IMGUI_SOURCES_BACKENDS})
target_include_directories(imgui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/imgui
                                 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends)
target_link_libraries(menu PUBLIC imgui)

# x86 only
set_target_properties(menu imgui PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(menu PRIVATE DEBUG)
endif()