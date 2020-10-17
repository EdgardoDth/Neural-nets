#include "Perceptron.h"
#include <cmath>
#include <ctime>

Perceptron::Perceptron(std::vector<std::vector<double>> ts, std::vector<double> _target): lr(0.5), epo(20) {
    trainingSet = Matrix(ts);
    tsLen = ts.size();
    ptLen = ts[0].size();
    target = Matrix::toMatrix(_target);
    int min = -1;
    int max = 1;
    weights = Matrix(1, ptLen);
    bias = 0.0;

    srand(time(NULL));
    for(unsigned int i = 1; i < ptLen; i++)
        *weights(0, i) = min + (double)rand() * (max - min) / (double)RAND_MAX;
}

Matrix Perceptron::getWeights() {
    return weights;
}

double Perceptron::getBias() {
    return bias;
}

int Perceptron::pw(std::vector<double> pt) {
    double val = 0.0;
    for(int i = 0; i < ptLen; i++)
        val += (*weights(0, i)) * pt[i];

    if (val + bias >= 0)
        return 1;
    return 0;
}

void Perceptron::train() {
    for(int i = 0; i < epo; i++) {
        for(int j = 0; j < tsLen; j++) {
            // y - y'
            double error = (*target(0, j)) - pw(trainingSet(j));
            if (error != 0) {
                weights = Matrix::add(weights,  Matrix::mul(trainingSet(j), lr * error));
                bias += lr * error;
            }
        }
    }
}
