/*
* @Author
* Student Name: Halit Uyan?k
* Student ID : 150140138
* Date: 7.05.2016
*/
#pragma once
#ifndef BOOK
#define BOOK

#include <iostream>
#include <string>

using namespace std;
/*
*Book item class and its functions
*Functions are described at header file Book.cpp
*/
class Book {
private:
	string label;
	float weight, length, width;
public:
	Book();
	Book(string, float, float, float);
	string getLabel();
	float getWeight();
	float getLength();
	float getWidth();
	friend ostream & operator << (ostream &out, Book &obj) {
		out << "Book Label: " << obj.getLabel() << " # " << obj.getLength() << "x" << obj.getWidth() << " " 
			<< obj.weight << "kg " << endl;
		return out;
	};
};

#endif