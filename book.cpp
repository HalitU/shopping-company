/*
* @Author
* Student Name: Halit Uyan?k
* Student ID : 150140138
* Date: 7.05.2016
*/
#include "book.h"

#include <string>

using namespace std;
//default book constructor
Book::Book() {

}
//Book constructor
Book::Book(string label, float weight, float length, float width) {
	this->label = label;
	this->weight = weight;
	this->length = length;
	this->width = width;
};
//returns Book label
string Book::getLabel() {
	return this->label;
}
//returns weight of book
float Book::getWeight() {
	return this->weight;
}
//returns length of book
float Book::getLength() {
	return this->length;
}
//returns width of book
float Book::getWidth() {
	return this->width;
}