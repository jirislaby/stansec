include_directories(../ui)

add_definitions(-DDATADIR="${CMAKE_INSTALL_FULL_DATADIR}")

find_package(Qt5 COMPONENTS Core Gui LinguistTools Widgets REQUIRED)

qt5_create_translation(QM_FILES
	${CMAKE_CURRENT_SOURCE_DIR}
	../ui
	../../trans/stansec_cs.ts)

add_executable(stansec
    main.cpp
    ../ui/mainwindow.ui
    ../ui/mainwindow.cpp
    ../ui/sourcecodeedit.cpp
    ${QM_FILES}
    )

target_link_libraries(stansec parser Qt5::Core Qt5::Gui Qt5::Widgets)

install(TARGETS stansec
	RUNTIME DESTINATION bin)
