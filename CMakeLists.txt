# Set cmake minimum version
cmake_minimum_required(VERSION 3.22.1)

# Set project name
project (F-engine)

# Fetch Gtest
# see: https://google.github.io/googletest/quickstart-cmake.html
include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Fetch nlohmann json parser
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

# Set C++ language standard to version 17
set(CMAKE_CXX_STANDARD 17)

# NOTE: Windows alatt kell ez a definíció, különben az M_PI konstansra fordítási hibát dob
add_compile_definitions(_USE_MATH_DEFINES)

# Add files recursively
file (GLOB_RECURSE Fengine_SOURCES CONFIGURE_DEPENDS "engine/*.cpp")
file (GLOB_RECURSE Fengine_HEADERS CONFIGURE_DEPENDS "engine/*.h")

set (Fengine_INCLUDE_DIRS "")
foreach (_headerFile ${Fengine_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND Fengine_INCLUDE_DIRS ${_dir})
endforeach()
list (REMOVE_DUPLICATES Fengine_INCLUDE_DIRS)

add_executable(RunEngine ${Fengine_SOURCES})
target_include_directories(RunEngine PRIVATE ${Fengine_INCLUDE_DIRS})

## Add nlohmann json parser target link library
target_link_libraries(RunEngine PRIVATE nlohmann_json::nlohmann_json)

enable_testing()

# Add preprocessor compile definition for windows 10
add_compile_definitions(_HAS_STD_BYTE=0)

# Main test
add_executable(google_tests test/test_main.cpp)
target_link_libraries(google_tests gtest_main)
add_test(basic_test google_tests)
