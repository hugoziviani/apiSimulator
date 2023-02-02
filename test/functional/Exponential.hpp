//
// Created by Hugo Ziviani on 1/27/23.
//

#ifndef MYVENSIM_EXPONENTIAL_HPP
#define MYVENSIM_EXPONENTIAL_HPP

#include "../../src/Flow.hpp"

class Exponential: public Flow{
public:
    Exponential()= default;
    Exponential(System* source, System* destination):Flow(source,destination){};
    double run() override{
        return getSource()->getValue()*0.01;
    }
};

#endif //MYVENSIM_EXPONENTIAL_HPP
