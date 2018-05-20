# CMakeList.txt: проект CMake для libasterix; включите исходный код и определения
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник для исполняемого файла этого проекта.
add_executable (libasterix "libasterix.cpp" "libasterix.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
