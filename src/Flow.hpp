//
// Created by Hugo Ziviani on 1/27/23.
//

#ifndef MYVENSIM_FLOW_HPP
#define MYVENSIM_FLOW_HPP

#include "System.hpp"

class Flow {

protected:
    System* source;
    System* destination;

public:
    Flow();
    Flow(System*, System*);
    virtual ~Flow();
    void setSource(System*);
    void setDestination(System*);
    System* getSource();
    System* getDestination();
    virtual double run() = 0;
    Flow* operator=(Flow*);

};


#endif //MYVENSIM_FLOW_HPP
