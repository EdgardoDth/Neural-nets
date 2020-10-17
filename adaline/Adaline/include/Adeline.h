#ifndef ADELINE_H
#define ADELINE_H

#include "Matrix.h"

class Adeline
{
    private:
        Matrix weights;
        Matrix trainingSet;
        Matrix target;
        double lr;
        double bias;
        int epo;
        int tsLen;
        int ptLen;
    public:
        Adeline(double, int, std::vector<std::vector<double>>, std::vector<double>);

        Matrix getWeights();
        double getBias();

        double pw();
        double activate(double);
        double p_activate(double);
        void train();
};

#endif // ADELINE_H
