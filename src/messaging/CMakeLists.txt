add_subdirectory(routing)

add_library(messaging OBJECT
$<TARGET_OBJECTS:routing>
#$<TARGET_OBJECTS:application_layer>
)