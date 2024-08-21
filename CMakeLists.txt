cmake_minimum_required(VERSION 3.30) # Проверка версии CMake.
									# Если версия установленой программы
									# старее указаной, произайдёт аварийный выход.

project(SummerSchool)				# Название проекта

set(SOURCE_EXE unit_tests.cpp)			# Установка переменной со списком исходников

set(SOURCE_LIB square.cpp)			# Тоже самое, но для библиотеки

add_library(square STATIC ${SOURCE_LIB})	# Создание статической библиотеки с именем foo

add_executable(main ${SOURCE_EXE})	# Создает исполняемый файл с именем main

target_link_libraries(main square)		# Линковка программы с библиотекой
