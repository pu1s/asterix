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


