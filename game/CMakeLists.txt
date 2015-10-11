cmake_minimum_required(VERSION 2.8.4)
project (game)


include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)

if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fPIC")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 or C++0x support. Please use a different C++ compiler.")
endif()



set (PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)


set(USE_STATIC_BOOST 0)


file(GLOB_RECURSE projectsources  ${PROJECT_SOURCE_DIR}  *.cpp)
file(GLOB_RECURSE projectsources2  ${PROJECT_SOURCE_DIR}  *.cc)
file(GLOB_RECURSE projectheaders  ${PROJECT_SOURCE_DIR}  *.h)

message(${PROJECT_SOURCE_DIR})

include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")
include_directories(${ARMADILLO_HOME}/include)
include_directories(${PROTOBUF}/include)
include_directories(${Boost_INCLUDE_DIR}
        ${GSL_INCLUDE}
)
include_directories(${SDL_HOME}/include)

set(PROJECT1_SRCS
${projectsources}
${projectsources2}
${projectheaders} src/character_link.cpp include/character_link.h)


set(Boost_USE_STATIC_LIBS ${USE_STATIC_BOOST})
set(Boost_USE_MULTITHREADED ON)
include_directories(${Boost_INCLUDE_DIR})
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/logger/include)
include_directories(${SPDLOG_HOME}/include)

find_package(Boost REQUIRED COMPONENTS thread program_options system)

if(USE_STATIC_BOOST)
   message(STATUS "Linking against boost static libraries")
else(USE_STATIC_BOOST)
   message(STATUS "Linking against boost dynamic libraries")
endif(USE_STATIC_BOOST)

find_package( Boost ${BOOST_VERSION} COMPONENTS program_options REQUIRED )
find_package( Threads  REQUIRED)

add_executable(${PROJECT_NAME} ${PROJECT1_SRCS})
LINK_DIRECTORIES(${Boost_LIBRARY_DIRS} ${ARMADILLO_HOME}/lib ${GSL_HOME}/lib/ ${PROTOBUF}/lib ${SDL_HOME}/lib)
target_link_libraries(${PROJECT_NAME}
        ${Boost_LIBRARIES}
        ${SDL_HOME}/lib/libSDL2.so
        ${PROTOBUF}/lib/libprotobuf.so
        ${CMAKE_THREAD_LIBS_INIT})



#add_executable(${PROJECT_NAME} ${PROJECT1_SRCS})



