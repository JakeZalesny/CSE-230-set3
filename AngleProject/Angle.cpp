#include <iostream>
#include "Angle.h"
#include <string.h>
#include<sstream>
using namespace std; 

namespace AngleProject {
	Angle::Angle() : radians(), degrees(0.0) {}

	double Angle::getDegrees() {
		return degrees; 
	}

	string Angle::getRadians() {
		return radians; 
	}

	void Angle::setDegrees(double newDegrees) {
		degrees = newDegrees;  
	}

	void Angle::setRadians(double newRadians) {
		radians = newRadians; 
	}

	double Angle::convertToDegrees(string &radians) {
		for (int i = 0; radians[i]; i++) {
			if (!isdigit(radians[i])) {
				radians.erase(i);
			}
		}
		double newRadians = atof(radians.c_str());
		degrees = newRadians * 180 / 3.1415926; 
		return degrees; 

	}

	string Angle::convertToRadians(double degrees) {
		double radianNumber = degrees / 180;
		string rad = to_string(radianNumber);
		radians = radianNumber + "π";
		return radians; 

	}

	double Angle::normalize(string &abnormal) {
		bool radian;
		double normalized;
		double newDegree; 
		for (int i = 0; abnormal[i]; i++) {
			if (!isdigit(abnormal[i])) {
				abnormal.erase(i);
				radian = true; 
			}
			else {
				radian = false; 
			}
		}
		if (radian == false) {
			double abnormalDegree = atof(abnormal.c_str());
			while (abnormalDegree > 180) {
				abnormalDegree -= 360;
			}
			normalized = abnormalDegree;
		}
		else {
			double abnormalRadian = atof(abnormal.c_str());
			
			if (abnormalRadian > 0) {
				newDegree = abnormalRadian * 180 / 3.1415926; 
			}

			else {
				newDegree = abnormalRadian * -180 / 3.1415926; 
			}

			while (newDegree > 180) {
				newDegree -= 360; 
			}
			normalized = newDegree; 

		}
		return normalized; 
	}


	void Angle::display() {
		cout << "Degrees: " << Angle::getDegrees() << "\n"
			<< "Radians: " << Angle::getRadians() << "\n";
	}
}