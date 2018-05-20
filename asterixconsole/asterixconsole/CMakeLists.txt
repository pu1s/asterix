# CMakeList.txt: проект CMake для asterixconsole; включите исходный код и определения
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник для исполняемого файла этого проекта.
add_executable (asterixconsole "asterixconsole.cpp" "asterixconsole.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
