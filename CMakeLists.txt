cmake_minimum_required(VERSION 3.5)
project(robot_urdf)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)

# Add the executable for the updated node
add_executable(robot_controller src/robot_controller.cpp)
ament_target_dependencies(robot_controller rclcpp geometry_msgs nav_msgs)

# Install the executable
install(TARGETS
  robot_controller
  DESTINATION lib/${PROJECT_NAME})

# Install other resources (e.g., launch files, URDF, configs)
install(DIRECTORY
  launch urdf config worlds
  DESTINATION share/${PROJECT_NAME}/
)

# Enable testing
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

