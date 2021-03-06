#! /usr/bin/env python
import rospy
from sensor_msgs.msg import LaserScan

def scan_callback(msg):
    range_ahead = msg.ranges[len(msg.ranges)/2]    
    print("range ahead: " + str(range_ahead))
        
rospy.init_node("range_ahead");
range_sub = rospy.Subscriber('scan', LaserScan, scan_callback)
rospy.spin()