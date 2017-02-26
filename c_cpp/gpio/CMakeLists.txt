cmake_minimum_required(VERSION 2.8)

project(gpio)

set(BCM_LIBS
    bcm2835
)

set(sources
    #led.c
    button.c
)

add_executable(${PROJECT_NAME} ${sources})

target_link_libraries(${CMAKE_PROJECT_NAME} ${BCM_LIBS})