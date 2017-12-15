include(ExternalProject)

set(GTEST_INSTALL_DIR ${CMAKE_BINARY_DIR}/external)

ExternalProject_Add(googletest
    GIT_REPOSITORY https://github.com/google/googletest
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${GTEST_INSTALL_DIR} -DCMAKE_INSTALL_LIBDIR=${GTEST_INSTALL_DIR}/lib -DCMAKE_INSTALL_INCLUDEDIR=${GTEST_INSTALL_DIR}/include
)

link_directories(${GTEST_INSTALL_DIR}/lib)

add_executable(unittest
  ../src/context.cpp
  ../src/MIR.cpp
  graph.cpp
  test.cpp)

add_dependencies(unittest googletest)

target_include_directories(unittest
  PUBLIC
  ${GTEST_INSTALL_DIR}/include)

target_link_libraries(unittest gtest gtest_main pthread graph dominators)
