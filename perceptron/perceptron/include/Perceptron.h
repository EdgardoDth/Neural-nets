#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include "Matrix.h"

class Perceptron
{
    private:
        Matrix weights;
        Matrix trainingSet;
        Matrix target;
        double lr;
        int epo;
        int tsLen;
        int ptLen;
        double bias;
    public:
        Perceptron(std::vector<std::vector<double>>, std::vector<double>);
        Perceptron(double, int, std::vector<std::vector<double>>, std::vector<double>);

        Matrix getWeights();
        double getBias();
        int pw(std::vector<double>);
        void train();
};

#endif // PERCEPTRON_H
