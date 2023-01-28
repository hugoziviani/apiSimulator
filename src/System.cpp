//
// Created by Hugo Ziviani on 1/27/23.
//

#include "System.hpp"

System::System(){
    this->name = "";
    this->value = 0.0;
}
System::System(string name, double value) { // Mudar string
    this->name = name;
    this->value = value;
}
System::~System(){}
void System::setName(string name) {
    this->name = name;
}
void System::setValue(double value) {
    this->value = value;
}
string System::getName() {
    return this->name;
}
double System::getValue() {
    return this->value;
}
System* System::operator=(System* system) {
    if (this == system)
        return this;
    this->name = system->getName();
    this->value = system->getValue();
    return this;
}
