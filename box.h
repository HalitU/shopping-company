/*
* @Author
* Student Name: Halit Uyan?k
* Student ID : 150140138
* Date: 7.05.2016


"g++ main.cpp box.h box.cpp toy.h toy.cpp book.h book.cpp -o tst.exe"

*/
#pragma once
#ifndef BOX
#define BOX

#include <iostream>
#include <iomanip> 
#include <typeinfo>
#include <cxxabi.h>

using namespace std;
/*
*Box Class
*/
template <class T>
class Box {
private:
	T *objList;
	float weight;
	float length;
	float width;
	float maxWeight;
	int objCount;
public:
	Box() {

	}
	Box(float, float, float, float);
	float getWeight();
	float getLength();
	float getWidth();
	float getMaxWeight();
	float getTotalWeight();
	void add(T &);
	void add(T *, int);
	float calculateWeight();
	Box(const Box<T> &);
	T & operator [] (int);
	friend ostream & operator << (ostream &out, Box<T> &objBox) {
		setiosflags(ios::fixed);
		setprecision(2);
		//we need to remove all of the 'class' substrings from the type id when printing
		//since we can have multiple nested types, a loop is used to check until all class strings removed
		int st;
		string boxName(abi::__cxa_demangle(typeid(T).name(), NULL, NULL, &st));
		int startPos = 0;
		while (startPos != -1) {
			startPos = boxName.find("class");
			if(startPos != -1)
				boxName.erase(startPos, 6);
		}
		out << "*****" << "Box<" << boxName << ">*****" << endl;
		out << "Box item count: " << objBox.getObjCount() << endl;
		out << "Size: " << objBox.getLength() << "x" << objBox.getWidth();
		out << " Box Weight: " << objBox.getMaxWeight() << "kg " << "Total/Maximum Allowed Weight: ";
		out << objBox.getTotalWeight() << "/" << objBox.getMaxWeight() << endl;
		out << "Items:" << endl;
		for (int i = 0; i < objBox.getObjCount(); i++) {
			out << i+1 << ":" << objBox[i];
		}
		out << "*******************" << endl;
		return out;
	};
	int getObjCount() {
		return this->objCount;
	}
};
//Box constructor
template <class T>
Box<T>::Box(float weight, float length, float width, float maxWeight):objCount(0) {
	this->weight = weight;
	this->length = length;
	this->width = width;
	this->maxWeight = maxWeight;
	this->objList = NULL;
}
//returns the weight of the Box
template <class T>
float Box<T>::getWeight() {
	return this->weight;
}
//returns box length
template <class T>
float Box<T>::getLength() {
	return this->length;
}
//returns box width
template <class T>
float Box<T>::getWidth() {
	return this->width;
}
//returns maximum allowed weight
template <class T>
float Box<T>::getMaxWeight() {
	return this->maxWeight;
}
//returns total weight
template <class T>
float Box<T>::getTotalWeight() {
	return this->getWeight() + this->calculateWeight();
}
//addes an item to box
template <class T>
void Box<T>::add(T &element) {
	if (element.getWeight() + this->calculateWeight() > this->getMaxWeight())
		throw (string)"The total weight of the contained objects including the box may not exceed the maximum allowed weight for the box!";
	if (element.getWidth() >  this->getWidth() && element.getWidth() >  this->getLength())
		throw (string)"The dimensions of the contained object should be equal or smaller than those of the box!";
	if (element.getLength() >  this->getWidth() && element.getLength() >  this->getLength())
		throw (string)"The dimensions of the contained object should be equal or smaller than those of the box!";
	if (objCount == 0) {
		objList = new T[1];
		objList[0] = element;
		this->objCount++;
	}
	else {
		//destructor will be called for pass
		T *pass = new T[objCount + 1];
		for (int i = 0; i < objCount; i++) {
			pass[i] = objList[i];
		}
		pass[objCount] = element;
		delete[] objList;
		objList = pass;
		objCount++;
	}
}
//adds an items from a list with given item count
template <class T>
void Box<T>::add(T *elementList, int elementCount) {
	for (int i = 0; i < elementCount; i++) {
		this->add(elementList[i]);
	}
}
//returns weight of objects inside the box
template <class T>
float Box<T>::calculateWeight() {
	float result = 0;
	for (int i = 0; i < objCount; i++) {
		result += objList[i].getWeight();
	}
	result += this->getWeight();
	return result;
}
//copy constructor for the Box
template<class T>
Box<T>::Box(const Box<T> &anotherBox)
{
	length = anotherBox.length;
	maxWeight = anotherBox.maxWeight;
	objCount = anotherBox.objCount;
	weight = anotherBox.weight;
	width = anotherBox.width;
	objList = new T[objCount];
	for (int i = 0; i < objCount; i++) {
		objList[i] = anotherBox.objList[i];
	}
}
//returns an item
template <class T>
T& Box<T>::operator[](int number) {
	if (number >= objCount) throw (string)"Index out of bounds!";
	return this->objList[number];
}
#endif