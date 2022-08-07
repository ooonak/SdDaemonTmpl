add_executable(MyService main.cpp)

target_link_libraries(MyService PRIVATE myproject::myproject)
install(TARGETS MyService DESTINATION bin)
