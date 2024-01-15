cmake_minimum_required(VERSION 3.8)
project(rd_map_server)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

include_directories(
  include
  include/${PROJECT_NAME}
)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(nav_msgs REQUIRED)

set(SOURCES
  src/rd_map_reader/rd_map_reader.cxx
  src/rd_map_server/rd_map_server.cxx
  src/main.cxx
)

set(DEPENDENCIES
  rclcpp
  nav_msgs
)

set(EXEC_NAME
  rd_map_server
)

add_executable(${EXEC_NAME}
  ${SOURCES}
)

ament_target_dependencies(${EXEC_NAME}
  ${DEPENDENCIES}
)

install(TARGETS ${EXEC_NAME}
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
