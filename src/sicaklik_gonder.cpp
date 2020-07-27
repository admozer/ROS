#include "ros/ros.h"
#include "std_msgs/Float64.h"

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "sicaklik_yayin10");
  ros::NodeHandle n;
  ros::Publisher sicaklik_publisher = n.advertise<std_msgs::Float64>("sicaklik", 1000);
  ros::Rate loop_rate(10);
  double sayac = 25.0;

  while (ros::ok())
  {
    if(sayac==50.1)
    {
	    sayac = 25.0;
    }
    std_msgs::Float64 msg;
    msg.data = sayac;

    ROS_INFO("%.1f", msg.data);

    sicaklik_publisher.publish(msg);

    loop_rate.sleep();
    sayac = floor(sayac*10)/10;
    sayac=sayac+0.1;

  }


  return 0;
}

