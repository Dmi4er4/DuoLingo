cmake_minimum_required(VERSION 3.20)
project(DuoLingo)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address,undefined")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address,undefined")

set(QT_VERSION 6)
set(REQUIRED_LIBS Core Widgets Multimedia WebSockets)
set(REQUIRED_LIBS_QUALIFIED Qt6::Core Qt6::Widgets Qt6::Multimedia Qt6::WebSockets)
find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wall -Wextra")

set(SOURCES main.cpp main_window.h main_window.cpp choice_widget.h choice_widget.cpp menu.h menu.cpp
        difficulty_dialog.h difficulty_dialog.cpp
        central_widget.h central_widget.cpp exercise_widget.h exercise_widget.cpp
        translation_exercise.h translation_exercise.cpp grammar_exercise.h grammar_exercise.cpp
        empty_exercise.h empty_exercise.cpp grammar_question.h
        music_class.h music_class.cpp
        settings_dialog.h settings_dialog.cpp tasks_loader.h tasks_loader.cpp
        resources.qrc)

add_executable(${PROJECT_NAME} ${SOURCES} ${RESOURCES})
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})