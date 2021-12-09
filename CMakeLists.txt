cmake_minimum_required(VERSION 3.0.0)
project(openGLUtils VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(./include)

include(./sourcelist.cmake)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm REQUIRED)

add_library(openGLUtils ${SOURCES})

target_link_libraries(openGLUtils
    ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES}
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
