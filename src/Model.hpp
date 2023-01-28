//
// Created by Hugo Ziviani on 1/27/23.
//

#ifndef MYVENSIM_MODEL_HPP
#define MYVENSIM_MODEL_HPP

#include "Flow.hpp"
#include <cstring>
#include <vector>

class Model{
private:
    Model* operator=(Model*);

protected:
    vector<Flow*> flows;
    vector<System*> systems;

public:
    Model();
    virtual ~Model();
    double run(int,int);
    void add(System*);
    void add(Flow*);
};


#endif //MYVENSIM_MODEL_HPP
