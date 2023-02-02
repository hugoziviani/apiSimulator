//
// Created by Hugo Ziviani on 1/27/23.
//

#include "Model.hpp"

Model::Model()= default;
Model::Model(Model *model){
    for (auto & system : systems){
        delete system;
    }
    this->systems.clear();

    for(auto & flow : flows){
        delete flow;
    }
    this->flows.clear();

    for (int i = 0; i < flows.size(); i++){
        auto aux = model->flows.at(i);
        this->flows.push_back(aux);
    }

    for (auto aux : model->systems){
        this->systems.push_back(aux);
    }
}
Model::~Model(){
    for (auto & flow : flows) {
        delete flow;
    }
    for (auto & system : systems){
        delete system;
    }
    this->flows.clear();
    this->systems.clear();
}
double Model::run(int start, int finish){
    vector<double> values;
    System* source;
    System* destination;
    for (int i = start; i < finish; i++){

        for(auto & flow : flows) {
            values.push_back(flow->run());
        }

        for(int k = 0; k < flows.size(); k++){
            source = flows.at(k)->getSource();
            source->setValue(source->getValue() - values.at(k));
            destination = flows.at(k)->getDestination();
            destination->setValue(destination->getValue() + values.at(k));
        }
        values.clear();
    }
    return values[finish];
}
void Model::add(System* system){
    this->systems.push_back(system);
}
void Model::add(Flow* flow){
    this->flows.push_back(flow);
}
Model* Model::operator=(Model* model) {
    if(this == model)
        return this;

    for (auto & system : systems){
        delete system;
    }

    this->systems.clear();

    for(auto & flow : flows){
        delete flow;
    }

    this->flows.clear();

    for (int i = 0; i < flows.size(); i++){
        auto aux = model->flows.at(i);
        this->flows.push_back(aux);
    }

    for (auto aux : model->systems){
        this->systems.push_back(aux);
    }
    return this;
}
