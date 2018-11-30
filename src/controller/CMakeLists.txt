set(SOURCES controller.c)
add_avr_executable(controller ${SOURCES})
avr_target_link_libraries(controller common)
