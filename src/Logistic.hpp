//
// Created by Hugo Ziviani on 1/27/23.
//

#ifndef MYVENSIM_LOGISTIC_HPP
#define MYVENSIM_LOGISTIC_HPP

#include "Flow.hpp"

class Logistic: public Flow{
public:
    Logistic()= default;
    Logistic(System* source, System* destination):Flow(source,destination){};

    double run() override{
        return getDestination()->getValue()*0.01*(1-(getDestination()->getValue())/70);
    }
};

#endif //MYVENSIM_LOGISTIC_HPP



