#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include<iostream>
#include<sys/io.h>
#include<stdio.h>
#include<ctime>



int caluint(int num)
{
    int ans = num + 22;
    std::cout << "test successful: " << ans << std::endl;
    sleep(3);
    ans = ans + 3;
    std::cout << "sus" << ans << std::endl;
    while(ans>0)
    {
        sleep(3);
        std::cin >> ans;
        std::cout << ans;
    }
    return ans;
}

bool forwardfun(float dist)
{

    float wheellen = 0.39; // wheel length
    float movesec = dist/wheellen;
    float onecirsec = 7.5; //sec per cir
    double iters = movesec * 30000;
    iters = (long)iters;
    long int iter;
    
    unsigned int indexp = 0x4e;
    unsigned int datap = 0x4f;
    unsigned char temp;
    iopl(3);
    // init GPIO
    outb(0x87, indexp);
    outb(0x87, indexp);
    outb(0x07, indexp);
    outb(0x09, datap);
    outb(0x2c, indexp);
    temp = (unsigned char)inb(datap);
    temp = 0x1f;
    //    temp = 0x03;
    outb(temp, datap);
    outb(0x30, indexp);
    outb(0x02, datap);
    
    for (iter = 1; iter<iters; iter++)
    {
        outb(0xf0, indexp);
        temp = (unsigned char)inb(datap);
        temp &= 0x7e;
        outb(temp, datap);
        outb(0xf1, indexp);
        temp = (unsigned char)inb(datap);
        temp |= 0x81;
        outb(temp, datap);
        usleep(50);

        outb(0xf0, indexp);
        temp = (unsigned char)inb(datap);
        temp &= 0x7e;
        outb(temp, datap);
        outb(0xf1, indexp);
        temp = (unsigned char)inb(datap);
        temp |= 0x7e;
        outb(temp, datap);
        usleep(50);
    }
    return true;
    
}

bool leftfun(float ang)
{
    float cirang = 70;
    float movesec = ang/cirang;
    long int iters = ((long)movesec) * 30000;
    long int iter;
    
    unsigned int indexp = 0x4e;
    unsigned int datap = 0x4f;
    unsigned char temp;
    iopl(3);
    // init GPIO
    outb(0x87, indexp);
    outb(0x87, indexp);
    outb(0x07, indexp);
    outb(0x09, datap);
    outb(0x2c, indexp);
    temp = (unsigned char)inb(datap);
    temp = 0x1f;
    //    temp = 0x03;
    outb(temp, datap);
    outb(0x30, indexp);
    outb(0x02, datap);
    
    for (iter = 1; iter<iters; iter++)
    {
        outb(0xf0, indexp);
        temp = (unsigned char)inb(datap);
        temp &= 0xbf;
        outb(temp, datap);
        outb(0xf1, indexp);
        temp = (unsigned char)inb(datap);
        temp &= 0xbf;
        outb(temp, datap);
        usleep(50);

        outb(0xf0, indexp);
        temp = (unsigned char)inb(datap);
        temp &= 0xbf;
        outb(temp, datap);
        outb(0xf1, indexp);
        temp = (unsigned char)inb(datap);
        temp |= 0x40;
        outb(temp, datap);
        usleep(50);
    }
    return true;
    
}

bool rightfun(float ang)
{
    float cirang = 70;
    float movesec = ang/cirang;
    long int iters = ((long)movesec) * 30000;
    long int iter;
    
    unsigned int indexp = 0x4e;
    unsigned int datap = 0x4f;
    unsigned char temp;
    iopl(3);
    // init GPIO
    outb(0x87, indexp);
    outb(0x87, indexp);
    outb(0x07, indexp);
    outb(0x09, datap);
    outb(0x2c, indexp);
    temp = (unsigned char)inb(datap);
    temp = 0x1f;
    //    temp = 0x03;
    outb(temp, datap);
    outb(0x30, indexp);
    outb(0x02, datap);
    
    for (iter = 1; iter<iters; iter++)
    {
        outb(0xf0, indexp);
        temp = (unsigned char)inb(datap);
        temp &= 0xfe;
        outb(temp, datap);
        outb(0xf1, indexp);
        temp = (unsigned char)inb(datap);
        temp &= 0xfe;
        outb(temp, datap);
        usleep(50);

        outb(0xf0, indexp);
        temp = (unsigned char)inb(datap);
        temp &= 0xfe;
        outb(temp, datap);
        outb(0xf1, indexp);
        temp = (unsigned char)inb(datap);
        temp |= 0x01;
        outb(temp, datap);
        usleep(50);
    }
    return true;
    
}

bool headfun(float ang)
{
    float cirang = 70;
    float movesec = ang/cirang;
    long int iters = ((long)movesec) * 30000;
    long int iter;
    
    unsigned int indexp = 0x4e;
    unsigned int datap = 0x4f;
    unsigned char temp;
    iopl(3);
    // init GPIO
    outb(0x87, indexp);
    outb(0x87, indexp);
    outb(0x07, indexp);
    outb(0x09, datap);
    outb(0x2c, indexp);
    temp = (unsigned char)inb(datap);
    temp = 0x1f;
    //    temp = 0x03;
    outb(temp, datap);
    outb(0x30, indexp);
    outb(0x02, datap);
    
    for (iter = 1; iter<iters; iter++)
    {
        outb(0xf0, indexp);
        temp = (unsigned char)inb(datap);
        temp &= 0x7f;
        outb(temp, datap);
        outb(0xf1, indexp);
        temp = (unsigned char)inb(datap);
        temp &= 0x7f;
        outb(temp, datap);
        usleep(1600);

        outb(0xf0, indexp);
        temp = (unsigned char)inb(datap);
        temp &= 0x7f;
        outb(temp, datap);
        outb(0xf1, indexp);
        temp = (unsigned char)inb(datap);
        temp |= 0x80;
        outb(temp, datap);
        usleep(1600);
    }
    return true;
    
}

void command_callback(const std_msgs::Int32::ConstPtr& msg)
{
    ROS_INFO("Receive: [%d]", msg->data);
    int bootmsg;
    bootmsg = msg->data;
    bool value = true;
    if (bootmsg!=1)
    {
        value = false;
    }
    while(value)
    {
        float dist;
        float ang;
        int mode;
        std::cout << "You want move 1(forward)/2(rotate)/3(head)?" << std::endl;
        std::cin >> mode;
        std::cout << "You input: " << mode << std::endl;
        if(mode==1)
        {
            std::cout << "Input the distance you want move: (m)" << std::endl;
            std::cin >> dist;
            std::cout << "You input: " << dist << std::endl;
            bool sus;
            sus = forwardfun(dist);
            if(sus)
            {
                std::cout << "Moving complete!\n\n";
            }
            else
            {
                std::cout << "Moving fail!\n";
                value = false;
            }
        }
        if(mode==2)
        {
            int dir;
            std::cout << "Turn right/left?\n";
            std::cout << "1(right)/2(left)\n";
            std::cin >> dir;
            std::cout << "You input: " << dir << std::endl;
            if(dir==1)
            {
                std::cout << "Input the angular (。)" << std::endl;
                std::cin >> ang;
                std::cout << "You input: " << ang << std::endl;
                bool sus;
                sus = rightfun(ang);
                if(sus)
                {
                    std::cout << "Moving complete!\n\n";
                }
                else
                {
                    std::cout << "Moving fail!\n";
                    value = false;
                }
            }
            if(dir==2)
            {
                std::cout << "Input the angular (。)" << std::endl;
                std::cin >> ang;
                std::cout << "You input: " << ang << std::endl;
                bool sus;
                sus = leftfun(ang);
                if(sus)
                {
                    std::cout << "Moving complete!\n\n";
                }
                else
                {
                    std::cout << "Moving fail!\n";
                    value = false;
                }
            }
        }
        if(mode==3)
        {
            
            std::cout << "You will move head.\n"
                    << "Sorry but only will can turn right.\n"
                    << "Input angle: ";
            std::cin >> ang;
            std::cout << "You input: " << ang << std::endl;
            bool sus;
            sus = headfun(ang);
            if(sus)
            {
                std::cout << "Moving complete!\n\n";
            }
            else
            {
                std::cout << "Moving fail!\n";
                value = false;
            }
            
        }
    }
}

int main(int argc, char **argv)
{

    ros::init(argc, argv, "motorcontroll");
    ros::NodeHandle node_obj2;
    ros::Subscriber motor_sub = node_obj2.subscribe("/command", 5, command_callback);
    ros::spin();
    return 0;
}
