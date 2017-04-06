
project(counter)

set(HEDEAR_FILES Counter.h)
set(SOURCE_FILES Counter.cpp)

add_library(libcounter STATIC ${SOURCE_FILES})
target_include_directories(libcounter PUBLIC .)

add_executable(counter ${SOURCE_FILES} main.cpp)

target_link_libraries(counter libcounter)

