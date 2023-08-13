find_package(Qt5 COMPONENTS Core Gui Widgets Network Sql REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


add_executable(S7_Demo)


target_sources(S7_Demo
    PUBLIC
	union_demo.h
    PRIVATE
    main.cpp
	union_demo.cpp
	union_demo.ui
)
target_link_libraries(S7_Demo
PRIVATE
	Qt5::Widgets
	Qt5::Core
    S7_MODEL
)
add_custom_command(
    TARGET S7_Demo
    POST_BUILD
    COMMAND "$<TARGET_FILE_DIR:Qt5::qmake>/windeployqt.exe" "--no-translations" $<TARGET_FILE:S7_Demo>
    WORKING_DIRECTORY $<TARGET_FILE_DIR:S7_Demo>
)