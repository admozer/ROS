#include "ros/ros.h"
#include "nav_msgs/Odometry.h"

double konum=0.0;

void OdometryCallback(const nav_msgs::Odometry::ConstPtr& msg){
   double x=msg->pose.pose.position.x;
   double y=msg->pose.pose.position.y;
   konum=x;

   ROS_INFO("x: %f, y: %f",x,y);

}

int main (int argc, char** argv){
	ros::init(argc,argv,"konumbulucu");
	ros::NodeHandle nh;
	ros::Subscriber subscriber=nh.subscribe("odom",10,OdometryCallback);
	
    while(ros::ok()){
        ros::spinOnce();

        if(konum >= 10.0){
            ROS_INFO("ASANSOR KALDIRILDI");
            break;
        }

    }
    
	return 0;
}
