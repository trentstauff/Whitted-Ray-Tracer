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

SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "C:/boost_1_76_0")
SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "C:/boost_1_76_0/stage/lib")

FIND_PACKAGE(Boost)
IF (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
    ADD_DEFINITIONS( "-DHAS_BOOST" )
ENDIF()

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
	"src/primitives/matrix.cpp"
    "src/primitives/ray.cpp"
	)

add_library(
	helpers
	"src/helpers.cpp"
)

add_library(
	canvas
	"src/canvas/canvas.cpp"
)

add_library(
	shapes
	"src/shapes/sphere.cpp"
)

add_executable(tests
	"src/tests/tuple_test.cpp"
	"src/tests/colour_test.cpp"
	"src/tests/canvas_test.cpp"
	"src/tests/matrix_test.cpp"
	"src/tests/ray_test.cpp"
 )

target_link_libraries(tests gtest_main)
target_link_libraries(tests primitives)
target_link_libraries(tests helpers)
target_link_libraries(tests canvas)
target_link_libraries(tests shapes)

include(GoogleTest)
gtest_discover_tests(tests)