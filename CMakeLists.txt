cmake_minimum_required(VERSION 3.10)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

find_package(Assimp REQUIRED)
find_package(ImageMagick COMPONENTS Magick++ REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

if(Assimp_FOUND)
include_directories(${Assimp_INCLUDE_DIRS})
endif()

if(ImageMagick_FOUND)
include_directories(${ImageMagick_INCLUDE_DIRS})
endif()

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

add_executable(untitled main.cpp ModelLoader.h ModelLoader.cpp TextureLoader.h TextureLoader.cpp math_3d.h Mesh.cpp Mesh.h Vector3f.cpp Vector3f.h Vector2f.cpp Vector2f.h Utils.cpp Utils.h)

if(Assimp_FOUND)
target_link_libraries(untitled ${ASSIMP_LIBRARIES})
endif()

if(ImageMagick_FOUND)
target_link_libraries(untitled ${ImageMagick_LIBRARIES})
endif()

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})