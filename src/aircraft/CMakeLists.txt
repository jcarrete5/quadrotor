set(SOURCES aircraft.c)
add_avr_executable(aircraft ${SOURCES})
avr_target_link_libraries(aircraft common)
