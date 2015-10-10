project (analytics)
cmake_minimum_required(VERSION 2.8.4)

#----------------------------------
#general path env variables -------
#----------------------------------

set(Python_ADDITIONAL_VERSIONS 2.7)

set(PROTOBUF "/opt/dev/protobuf/2.6.1")
set(GSL_HOME "/opt/dev/gsl/1.16")
set(PYTHON_LIBRARY "/opt/dev/anaconda/2.3.0/lib")
set(PYTHON_INCLUDE_DIR "/opt/dev/anaconda/2.3.0/include/python2.7")
set(POCO_HOME "/opt/dev/poco/1.6.1")
set(MYSQL_HOME "/opt/dev/mysql/1.1.6")
set(POSTGRES_HOME "/opt/dev/postgres/4.0.1")
set(NLOPT_HOME "/opt/dev/nlopt/2.4.2")
set(ARMADILLO_HOME "/opt/dev/armadillo/6.100.0")
set(SDL_HOME "/opt/dev/sdl/2.2.3" )



set(BOOST_ROOT "/opt/dev/boost/1.59.0")


set(SPDLOG_HOME "/opt/dev/spdlog")


set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(USE_STATIC_BOOST 0)
set(BOOST_VERSION 1.59.0)


add_subdirectory(game)
enable_testing ()
add_test (NAME MyTest COMMAND Test)


set (copy_cmd "cp")
set (copy_arg1  "${CMAKE_SOURCE_DIR}/test/resources/alloc.proto")
set (copy_arg2  "/tmp/alloc.proto")
message(STATUS "cp cmd: ${copy_cmd}")
execute_process(COMMAND ${copy_cmd} ${copy_arg1} ${copy_arg2}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        RESULT_VARIABLE cp_result
        OUTPUT_VARIABLE cp_ver)

set (copy_arg1  "${CMAKE_SOURCE_DIR}/test/resources/allocresponse.proto")
set (copy_arg2  "/tmp/allocresponse.proto")
message(STATUS "cp cmd: ${copy_cmd}")
execute_process(COMMAND ${copy_cmd} ${copy_arg1} ${copy_arg2}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        RESULT_VARIABLE cp_result
        OUTPUT_VARIABLE cp_ver)

message(STATUS "copy ver[${git_result}]: ${git_ver}")
