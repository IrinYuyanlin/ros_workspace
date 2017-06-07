#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include<iostream>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "motorcommand");
	ros::NodeHandle node_obj;
	ros::Publisher command_pub = node_obj.advertise<std_msgs::Int32>("/command", 5);
	int command = 0;
	while(ros::ok())
	{
		std_msgs::Int32 msg;
		std::cout << "input a key to start/stop machine: "
		<< "1(start)/2(stop)."
		<< std::endl;
		std::cin >> command;
		std::cout << "You input: " << command << std::endl;
		msg.data = command;
		command_pub.publish(msg);
		ros::spin();
	}
}
