cmake_minimum_required(VERSION 2.8.3)
project(ros_odev)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  nav_msgs
  geometry_msgs
  message_generation
)

include_directories(include ${catkin_INCLUDE_DIRS})

add_service_files(DIRECTORY srv FILES asansor.srv)
generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package()

add_executable(sicaklik_gonder src/sicaklik_gonder.cpp) 
target_link_libraries(sicaklik_gonder ${catkin_LIBRARIES})

add_executable(sicaklik_oku_gonder src/sicaklik_oku_gonder.cpp) 
target_link_libraries(sicaklik_oku_gonder ${catkin_LIBRARIES})

add_executable(servis_client src/servis_client.cpp) 
target_link_libraries(servis_client ${catkin_LIBRARIES})

add_executable(servis_server src/servis_server.cpp) 
target_link_libraries(servis_server ${catkin_LIBRARIES})

add_executable(konumdegis src/konumdegis.cpp) 
target_link_libraries(konumdegis ${catkin_LIBRARIES})
