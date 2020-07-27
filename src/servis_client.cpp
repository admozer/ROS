#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "ros_odev/asansor.h"

int sayac=0;

void callbacktime(const ros::TimerEvent&)
{
  sayac=1;
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<ros_odev::asansor>("asansor_ser");
  ros_odev::asansor srv;
  srv.request.a = 1;
  if (client.call(srv))
  {
    ROS_INFO("gelen response: %ld", (long int)srv.response.cevap);
  }
  else
  {
    ROS_ERROR("Failed to call service asansor");
  }
}

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "cmd_vel_yayini");
  ros::NodeHandle n;
  ros::Publisher publisher = n.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
  ros::Timer timer = n.createTimer(ros::Duration(5.0), callbacktime);

  ros::Rate loop_rate(10);  
  int count=0;
  while (ros::ok())
  {
    if(sayac==1){
      break;
    }
    geometry_msgs::Twist msg;
    //msg.data = count;
    msg.linear.x=1.0;
    
    ROS_INFO("%d", count);

    publisher.publish(msg);

    loop_rate.sleep();
    ros::spinOnce();
    count++;

  }

  return 0;
}

