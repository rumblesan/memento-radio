
include_directories(include)

set(SOURCES "src/main.c")

add_executable(memento ${SOURCES})

target_link_libraries(memento libmemento)

install(TARGETS memento EXPORT MementoRadioTargets
    RUNTIME DESTINATION bin
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib)
