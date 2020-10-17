#include <iostream>
#include <vector>
#include "Matrix.h"
#include "Perceptron.h"
#include <fstream>

void writeInFile(Perceptron & p, std::vector<std::vector<double>> _ts, std::vector<double> _target) {
    std::ofstream file("output.txt");
    int sizeW = p.getWeights().getColumms();

    if (file.is_open()) {
        file << sizeW << std::endl;
        for(int i = 0; i < sizeW; i++) {
            file << *p.getWeights()(0, i) << std::endl;
        }

        file << p.getBias() << std::endl;
        //target size
        file << _target.size() << std::endl;
        //target vector
        for(int i = 0; i < _target.size(); i++) {
            file << _target.at(i) << std::endl;
        }
        //training set row
        file << _ts.size() << std::endl;
        //training set column
        file << _ts[0].size() << std::endl;
        //training set
        for(int j = 0; j < _ts[0].size(); j++) {
            for(int i = 0; i < _ts.size(); i++) {
                file << _ts[i][j] << std::endl;
            }
        }

    }
    file.close();
}

std::vector<std::vector<double> > td {{1.0, 1.0},
                                      {0.0, 0.0},
                                      {1.0, 0.0},
                                      {0.0, 1.0}
                                     };

std::vector<double> target {1,
                            0,
                            1,
                            1};

int main()
{
    Matrix x = Matrix(td);
    Perceptron p = Perceptron(td, target);
    p.train();

    writeInFile(p, td, target);

    return 0;
}
