#include "Adeline.h"
#include <cmath>
#include <ctime>

Adeline::Adeline(double lr, int epo, std::vector<std::vector<double>> _ts,
     std::vector<double> _target)
{
    //ctor
    tsLen = _ts.size();
    ptLen = ts[0].size();
    lr = lr;
    epo = epo;
    bias = 0.0;
    weights = Matrix(1, ptLen);
    trainingSet = Matrix(_ts);
    target = Matrix::toMatrix(_target);
    int max = 1;
    int min = -1;

    srand(time(NULL));
    for(unsigned int i = 1; i < ptLen; i++)
        *weights(0, i) = min + (double)rand() * (max - min) / (double)RAND_MAX;
}

Matrix Adeline::getWeights() {
    return weights;
}

double Adeline::getBias() {
    return bias;
}

double Adeline::pw() {

}

double Adeline::activate(double) {

}

//derivate of sigmoid
double Adeline::p_activate(double) {

}

void Adeline::train() {

}
