cmake_minimum_required(VERSION 3.1.0)

# C needed for LLVM -> terminfo
project(stansec VERSION 1.0.0 LANGUAGES C CXX)

enable_testing()

include(GNUInstallDirs)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include_directories(include)
add_compile_options(-Wall)

if (USE_WEXTRA)
	add_compile_options(-Wextra -pedantic -Wno-unused-parameter)
endif()
if (USE_WERROR)
	add_compile_options(-Werror)
endif()

add_subdirectory(src)
add_subdirectory(test)
