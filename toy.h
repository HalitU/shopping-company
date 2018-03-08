/*
* @Author
* Student Name: Halit Uyan?k
* Student ID : 150140138
* Date: 7.05.2016
*/
#pragma once
#ifndef TOY
#define TOY
#include <string>
#include <sstream>

using namespace std;
/*
*Toy item class and its functions
*Functions are described at header file Toy.cpp
*/
class Toy {
private:
	string label;
	float weight, length, width;
	bool contBattery;
public:
	Toy();
	Toy(string, float, float, float, bool);
	Toy& operator=(const Toy &);
	string getLabel();
	float getWeight();
	float getLength();
	float getWidth();
	bool containsBattery();
	void setContainsBattery(bool);
	friend ostream & operator << (ostream &out, Toy &obj) {
		out << "Toy Label: " << obj.getLabel() << " # " << obj.getLength() << "x" << obj.getWidth();
		out << " " << obj.getWeight() << "kg ";
		if (obj.containsBattery())
			out << " Contains Battery" << endl;
		else
			out << " No Battery" << endl;
		return out;
	};
};

#endif