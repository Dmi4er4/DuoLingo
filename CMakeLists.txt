cmake_minimum_required(VERSION 3.20)
project(DuoLingo)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 6)
set(REQUIRED_LIBS Core Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt6::Core Qt6::Widgets)
find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wall -Wextra -O3")

set(SOURCES main.cpp main_window.h main_window.cpp choice_widget.h choice_widget.cpp menu.h menu.cpp
        difficulty_dialog.h difficulty_dialog.cpp
        central_widget.h central_widget.cpp exercise_widget.h exercise_widget.cpp
        translation_widget.h translation_widget.cpp grammar_widget.h grammar_widget.cpp)

add_executable(${PROJECT_NAME} ${SOURCES} ${RESOURCES})
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})