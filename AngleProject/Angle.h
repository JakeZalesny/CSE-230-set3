#pragma once
#include <iostream>
using namespace std; 

namespace AngleProject {
	class Angle {
	public: 
		Angle(); 
		double getDegrees(); 
		string getRadians(); 
		void setDegrees(double newRadians); 
		void setRadians(double newDegrees); 
		void display(); 
	private:
		double degrees; 
		string radians; 
		double convertToDegrees(string &radians);
		string convertToRadians(double degrees);
		double normalize(string &abnormal);
	};
}