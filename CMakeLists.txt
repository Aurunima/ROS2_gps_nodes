cmake_minimum_required(VERSION 3.5)
project(gps_communication)

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(${PROJECT_NAME} REQUIRED) # Include any other dependencies you need

# Generate custom messages
find_package(rosidl_default_generators REQUIRED)
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/GPSData.msg"
)

# Create publisher node
add_executable(gps_publisher src/gps_publisher.cpp)
ament_target_dependencies(gps_publisher rclcpp ${PROJECT_NAME})

# Create subscriber node
add_executable(gps_subscriber src/gps_subscriber.cpp)
ament_target_dependencies(gps_subscriber rclcpp ${PROJECT_NAME})

# Install executables
install(TARGETS
  gps_publisher
  gps_subscriber
  DESTINATION lib/${PROJECT_NAME}
)

# Install custom message files
install(DIRECTORY msg
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
