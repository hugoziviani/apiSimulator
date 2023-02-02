//
// Created by Hugo Ziviani on 1/27/23.
//

#include "FunctionalTest.hpp"

bool nearlyEqual(float a, float b, float epsilon){
    // https://www.boost.org/doc/libs/1_78_0/libs/math/doc/html/math_toolkit/float_comparison.html
    float absA = fabs(a);
    float absB = fabs(b);
    float diff = fabs(a - b);
    if(a == b){
        return true;
    } else if(a == 0 or b == 0 or diff < std::numeric_limits<float>::min()){
        // a or b is zero or both are extremely close to it
        // relative error is less meaningful here
        return diff < (epsilon * std::numeric_limits<float>::min());
    } else { // use relative error
        return diff/(absA + absB) < epsilon;
    }
}
void exponentialFuncionalTest(){

    Model* Modelexponential = new Model();
    System* pop1 = new System("pop1", 100.0);
    System* pop2 = new System("pop2", 0.0);

    Exponential* f = new Exponential(pop1,pop2);
    Modelexponential->add(f);
    Modelexponential->add(pop1);
    Modelexponential->add(pop2);
    Modelexponential->run(0, 100);

    assert(nearlyEqual(pop1->getValue(), 36.6032, 0.0001));
    cout << "pop1 passed on Exponential test - Ok" << endl;
    assert(nearlyEqual(pop2->getValue(), 63.3968, 0.0001));
    cout << "pop2 passed on Exponential test - Ok" << endl;

}
void logisticalFuncionalTest () {

    Model* ModelLogistic = new Model();

    System* p1= new System("p1", 100.0);
    System* p2 = new System("p2", 10.0);
    Logistic* l = new Logistic(p1,p2);

    ModelLogistic->add(l);
    ModelLogistic->add(p1);
    ModelLogistic->add(p2);

    ModelLogistic->run(0, 100);

    assert(fabs(p1->getValue() - 88.2167) < 0.0001);
    cout << "p1 passed on Logistical test - Ok" << endl;
    assert(fabs(p2->getValue() - 21.7834) < 0.0001);
    cout << "p2 passed on Logistical test - Ok" << endl;
}
void complexFuncionalTest () {

    System* Q1 = new System("Q1", 100.0);
    System* Q2 = new System("Q2", 0.0);
    System* Q3 = new System("Q3", 100.0);
    System* Q4 = new System("Q4", 0.0);
    System* Q5 = new System("Q5", 0.0);

    Flow* f = new Exponential(Q1, Q2);
    Flow* g = new Exponential(Q1, Q3);
    Flow* r = new Exponential(Q2, Q5);
    Flow* t = new Exponential(Q2, Q3);
    Flow* u = new Exponential(Q3, Q4);
    Flow* v = new Exponential(Q4, Q1);

    Model* model = new Model();

    model->add(Q1);
    model->add(Q2);
    model->add(Q3);
    model->add(Q4);
    model->add(Q5);

    model->add(f);
    model->add(g);
    model->add(r);
    model->add(t);
    model->add(u);
    model->add(v);

    model->run(0, 100);

//    assert(fabs(Q1->getValue() - 31.8513) < 0.0001);
    assert(nearlyEqual(Q1->getValue(), 31.8513, 0.0001));
    cout << "Q1 passed on Complex test - Ok" << endl;
    assert(nearlyEqual(Q2->getValue(), 18.4003, 0.0001));
    cout << "Q2 passed on Complex test - Ok" << endl;
    assert(nearlyEqual(Q3->getValue(), 77.1143, 0.0001));
    cout << "Q3 passed on Complex test - Ok" << endl;
    assert(nearlyEqual(Q4->getValue(), 56.1728, 0.0001));
    cout << "Q4 passed on Complex test - Ok" << endl;
    assert(nearlyEqual(Q5->getValue(), 16.4612, 0.0001));
    cout << "Q5 passed on Complex test - Ok" << endl;
}
