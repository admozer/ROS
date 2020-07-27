#include "ros/ros.h"
#include "ros_odev/asansor.h"

bool myfunc(ros_odev::asansor::Request  &req,
         ros_odev::asansor::Response &res )
{
  ros::Duration(10, 0).sleep();
  ROS_INFO("ASANSOR KALDIRILDI");
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "service_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("asansor_ser", myfunc);

  ros::spin();

  return 0;
}



