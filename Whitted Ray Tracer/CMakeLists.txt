# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("Whitted Ray Tracer")

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(
	primitives
	"src/primitives/tuple.cpp"
	"src/primitives/colour.cpp"
 )

add_library(
	helpers
	"src/helpers.cpp"
)


add_executable(tests
	"src/tests/tuple_test.cpp"
	"src/tests/colour_test.cpp"
)

target_link_libraries(tests gtest_main)
target_link_libraries(tests primitives)
target_link_libraries(tests helpers)

include(GoogleTest)
gtest_discover_tests(tests)