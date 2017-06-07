#! /usr/bin/env python
import rospy
from geometry_msgs.msg import Twist

rospy.init_node("green_red_light_node")
light_pub = rospy.Publisher("light_publisher", Twist, queue_size=1)

green_msg = Twist()
red_msg = Twist()
green_msg.linear.x = 0.5

drive_forward = False
light_change_time = rospy.Time.now()
rate = rospy.Rate(10)

while not rospy.is_shutdown():
    if drive_forward:
        light_pub.publish(green_msg)        
    else:
        light_pub.publish(red_msg)        
    if (light_change_time + rospy.Duration(3))  < rospy.Time.now():
        drive_forward = not drive_forward
        light_change_time = rospy.Time.now()        
    rate.sleep()