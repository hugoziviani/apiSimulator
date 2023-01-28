//
// Created by Hugo Ziviani on 1/27/23.
//

#ifndef MYVENSIM_SYSTEM_HPP
#define MYVENSIM_SYSTEM_HPP

#include <iostream>
#include <cstdlib>

using namespace std;

class System {

protected:
    string name;
    double value;

public:
    System();
    System(string="default", double=0.0);

    virtual ~System();
    void setName(string);
    void setValue(double);
    double getValue();
    string getName();
    System* operator=(System*);
};


#endif //MYVENSIM_SYSTEM_HPP
