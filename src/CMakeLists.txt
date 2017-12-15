find_package(Boost)

add_library(graph
  graph.cpp)
add_executable(gviz
  main.cpp)
target_include_directories(gviz
  PUBLIC
  ${Boost_INCLUDE_DIRS})

target_link_libraries(gviz
  boost_graph)

add_subdirectory(Analysis)
