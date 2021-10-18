find_package(Qt5 COMPONENTS Core REQUIRED)

add_compile_definitions(QT_NO_FOREACH)

find_package(LLVM REQUIRED CONFIG)

add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})

find_package(Clang REQUIRED)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

if (TARGET LLVMSupport)
	llvm_map_components_to_libnames(llvm_libs support core)
else()
	set(llvm_libs LLVM)
endif()
message(STATUS "Mapped LLVM libs: ${llvm_libs}")

add_library(parser STATIC
    parser.cpp
    parser.h
    )

target_link_libraries(parser libclang clang-cpp ${llvm_libs} Qt5::Core)
