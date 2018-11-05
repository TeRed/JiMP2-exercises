project(point)

set(HEDEAR_FILES Point.h Square.h)
set(SOURCE_FILES Point.cpp Square.cpp)

add_library(libpoint STATIC ${SOURCE_FILES})
target_include_directories(libpoint PUBLIC .)

add_executable(point ${SOURCE_FILES} main.cpp)

target_link_libraries(point libpoint)

