find_package(Qt5 COMPONENTS Core Gui Widgets Network Sql REQUIRED)

add_library(S7_MODEL STATIC)
target_sources(S7_MODEL
PUBLIC
	S7Model.h
	S7Model.cpp
PRIVATE
    ${THIRDPARTY_DIR}/Snap7/snap7.cpp
)
target_include_directories(S7_MODEL
PUBLIC 
	./
    ${THIRDPARTY_DIR}/Snap7/
)
target_link_libraries(S7_MODEL
PUBLIC 
    ${THIRDPARTY_DIR}/Snap7/snap7.lib
PRIVATE
	Qt5::Core
)