
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

# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.

#
cmake_minimum_required (VERSION 3.8 FATAL_ERROR)
#
set(PROJECT_NAME "libasterix")
set(SUB_DIRS "libasterix")
#
project (${PROJECT_NAME})
#
set(SYSTEM "")
include("func.cmake")
get_operation_system()
message(STATUS ${PROJECT_NAME} " build is begin...")

# Включите подпроекты.
add_subdirectory (${SUB_DIRS})
set(CONFIG_DIR "libasterix/config")
set(CONFIG_FILE "asterix.config")
#
get_config_file()

#message("Find config file...")
#
#message("Config file is found.")


