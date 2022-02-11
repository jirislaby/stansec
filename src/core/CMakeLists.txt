include_directories(../ui)

add_compile_definitions(DATADIR="${CMAKE_INSTALL_FULL_DATADIR}")

set(QT_COMPONENTS Core Gui LinguistTools Widgets)
find_package(Qt6 QUIET COMPONENTS Core5Compat ${QT_COMPONENTS})
if (NOT Qt6_FOUND)
	find_package(Qt5 REQUIRED COMPONENTS ${QT_COMPONENTS})
endif()

qt_create_translation(QM_FILES
	${CMAKE_CURRENT_SOURCE_DIR}
	../ui
	../../trans/stansec_cs.ts)

add_compile_definitions(QT_NO_FOREACH)

add_executable(stansec
	CmdLineManager.cpp
	CmdLineManager.h
	main.cpp
	stansec.cpp
	stansec.h
	../ui/mainwindow.ui
	../ui/mainwindow.cpp
	../ui/mainwindow.h
	../ui/sourcecodeedit.cpp
	../ui/sourcecodeedit.h
	../ui/treeerrormodel.cpp
	../ui/treeerrormodel.h
	${QM_FILES}
    )

target_link_libraries(stansec checker parser Qt::Core Qt::Gui Qt::Widgets)
if (Qt6_FOUND)
    target_link_libraries(stansec Qt::Core5Compat)
endif()

install(TARGETS stansec
	RUNTIME DESTINATION bin)
