#ifndef MATRIX_H
#define MATRIX_H
#include <vector>

class Matrix
{
    private:
        int rows;
        int columns;
        std::vector<std::vector<double>> data;
    public:
        Matrix();
        Matrix(int, int);
        Matrix(const Matrix&);
        Matrix(std::vector<std::vector<double>>);
        double* operator()(const int, const int);
        std::vector<double> operator()(const int);
        int getRows();
        int getColumms();

        void add(double);
        void mul(double);
        //static Matrix
        static Matrix add(Matrix, Matrix);
        static Matrix add(std::vector<double>, double);
        static Matrix transpose(Matrix);
        static Matrix sub(Matrix, Matrix);
        static Matrix mul(Matrix, Matrix);
        static Matrix mul(std::vector<double>, double);
        static double dot(Matrix, Matrix);
        static Matrix toMatrix(std::vector<double>);
        static void printAll(Matrix);
};

#endif // MATRIX_H
