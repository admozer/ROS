#include "ros/ros.h"
#include "std_msgs/Float64.h"

std_msgs::Float64 tempre;


void Callback(const std_msgs::Float64::ConstPtr& msg)
{
  ROS_INFO("okunan değerim: [%.1f]", msg->data);
  tempre=*msg;
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "sicaklik_yayin1");

  ros::NodeHandle n;
  ros::Subscriber subscriber = n.subscribe("sicaklik", 1000, Callback);

  ros::Publisher publisher = n.advertise<std_msgs::Float64>("sicaklik1", 1000);
  ros::Rate loop_rate(1);
  
  while(ros::ok())
  {
    ros::spinOnce();
    publisher.publish(tempre);
    loop_rate.sleep();
  }

  return 0;
}
