include_directories(../ui)

add_definitions(-DDATADIR="${CMAKE_INSTALL_FULL_DATADIR}")

find_package(Qt5 COMPONENTS Core Gui LinguistTools Widgets REQUIRED)

qt5_create_translation(QM_FILES
	${CMAKE_CURRENT_SOURCE_DIR}
	../ui
	../../trans/stansec_cs.ts)

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
	${QM_FILES}
    )

target_link_libraries(stansec parser Qt5::Core Qt5::Gui Qt5::Widgets)

install(TARGETS stansec
	RUNTIME DESTINATION bin)
