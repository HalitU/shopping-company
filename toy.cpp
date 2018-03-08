/*
* @Author
* Student Name: Halit Uyan?k
* Student ID : 150140138
* Date: 7.05.2016
*/
#include "toy.h"
//deafult constructor in case some inconvenient thing may happen
Toy::Toy() {

}
//Toy constructor
Toy::Toy(string label, float weight, float length, float width, bool contBattery) {
	this->label = label;
	this->weight = weight;
	this->length = length;
	this->width = width;
	this->contBattery = contBattery;
}
//copy constructor
Toy& Toy::operator=(const Toy &anotherToy) {
	this->label = anotherToy.label;
	this->weight = anotherToy.weight;
	this->length = anotherToy.length;
	this->width = anotherToy.width;
	this->contBattery = anotherToy.contBattery;
	return *this;
}
//returns label of Toy
string Toy::getLabel() {
	return this->label;
}
//returns Weight of Toy
float Toy::getWeight() {
	return this->weight;
}
//returns length of Toy
float Toy::getLength() {
	return this->length;
}
//returns width of Toy
float Toy::getWidth() {
	return this->width;
}
//returns if Toy contains battery
bool Toy::containsBattery() {
	return this->contBattery;
}
//sets Toy battery status
void Toy::setContainsBattery(bool state) {
	this->contBattery = state;
}