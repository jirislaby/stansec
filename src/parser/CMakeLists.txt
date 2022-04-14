set(QT_COMPONENTS Core)
find_package(Qt6 QUIET COMPONENTS ${QT_COMPONENTS})
if (NOT Qt6_FOUND)
	find_package(Qt5 REQUIRED COMPONENTS ${QT_COMPONENTS})
endif()

add_compile_definitions(QT_NO_FOREACH)

find_package(LLVM REQUIRED CONFIG)

add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})

find_package(Clang REQUIRED)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

set(USE_MAP FALSE)
if (TARGET LLVMSupport)
	get_target_property(LLVMSupport_TYPE LLVMSupport TYPE)
	if (LLVMSupport STREQUAL SHARED_LIBRARY)
		set(USE_MAP TRUE)
	endif()
endif()
if (USE_MAP)
	llvm_map_components_to_libnames(llvm_libs support core)
else()
	set(llvm_libs LLVM)
endif()
message(STATUS "Mapped LLVM libs: ${llvm_libs}")

add_library(parser STATIC
    parser.cpp
    parser.h
    )

target_link_libraries(parser checker libclang clang-cpp ${llvm_libs} Qt::Core)
