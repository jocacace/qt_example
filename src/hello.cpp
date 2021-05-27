#include <QtWidgets>
#include "ros/ros.h"
#include "boost/thread.hpp"
#include "std_msgs/String.h"

void qtWin(int argc, char *argv[]) {
	QApplication app(argc, argv);
	QWidget window;
	window.resize(320, 240);
	window.show();
	window.setWindowTitle(
	QApplication::translate("toplevel", "Top-level widget"));
	app.exec();
}



int main(int argc, char *argv[])
{

		boost::thread win_t( qtWin, argc, argv );
		
    ros::init(argc, argv, "qtexample");
    ros::NodeHandle n;
    ros::Publisher  msg_pub;
    msg_pub = n.advertise<std_msgs::String>("/msg", 1);
    std_msgs::String s;
    s.data = "Test in QT!";
    
    ros::Rate r(5);
    while(ros::ok() ) {
    
    
    	msg_pub.publish( s );
    	r.sleep();
    }
}

