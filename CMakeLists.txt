cmake_minimum_required(VERSION 3.1)

project(oop_exercise_08)

find_package(Threads)

add_executable(oop_exercise_08
    main.cpp
    Figure.cpp
    Rectangle.cpp
    Rhombus.cpp
    Subscriber.cpp
    Trapeze.cpp
    Point.cpp)
set_property(TARGET oop_exercise_08 PROPERTY CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -Werror")

target_link_libraries(oop_exercise_08 ${CMAKE_THREAD_LIBS_INIT})
