
# MIT License

# Copyright (c) 2018 Alexander Gorin pu1s@outlook.com

# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

#
cmake_minimum_required (VERSION 3.8 FATAL_ERROR)
#
set(PROJECT_NAME "libasterix")
project (${PROJECT_NAME})
set("${PROJECT_NAME}_SOURCE_DIR" "src")
set("${PROJECT_NAME}_BINARY_DIR" "bin")
set (CMAKE_INCLUDE_PATH ${${PROJECT_NAME}_SOURCE_DIR})

message(STATUS ${CMAKE_INCLUDE_PATH})
message(STATUS ${PROJECT_NAME} " Build is begin...")

add_library(libasterix STATIC "${CMAKE_INCLUDE_PATH}/libasterix.cpp" "${CMAKE_INCLUDE_PATH}/libasterix.h")
set_property(TARGET libasterix PROPERTY CXX_STANDARD 17)
target_include_directories(libasterix PUBLIC ${CMAKE_INCLUDE_PATH})
set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/bin")
message(${CMAKE_INSTALL_PREFIX})
install(TARGETS libasterix DESTINATION ${CMAKE_INSTALL_PREFIX})
#install(FILES "${CMAKE_INCLUDE_PATH}/libasterix.h" DESTINATION ${CMAKE_INSTALL_PREFIX})
#add_custom_command(TARGET libasterix POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}"/${PROJECT_NAME}/${PROJECT_NAME}.lib" DESTINATION "${CMAKE_SOURCE_DIR}/build" )
