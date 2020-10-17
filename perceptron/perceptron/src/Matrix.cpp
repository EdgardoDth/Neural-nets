#include "Matrix.h"
#include <iostream>
Matrix::Matrix(): rows(0), columns(0) {}

Matrix::Matrix(const Matrix & other) {
    rows = other.rows;
    columns = other.columns;
    data = other.data;
}

Matrix::Matrix(int _rows, int _columns)
{
    //ctor
    rows = _rows;
    columns = _columns;
    data.resize(_rows, std::vector<double>(_columns, 0));
}

Matrix::Matrix(std::vector<std::vector<double>> ts)
{
    data = ts;
    rows = ts.size();
    columns = ts[0].size();
}

double* Matrix::operator()(const int row, const int column) {
    return &data[row][column];
}

std::vector<double> Matrix::operator()(const int row) {
    return data[row];
}

int Matrix::getRows() {
    return rows;
}

int Matrix::getColumms() {
    return columns;
}

Matrix Matrix::add(Matrix a, Matrix b) {
    Matrix result(a.getRows(), a.getColumms());
    for(int i = 0; i < a.getRows(); i++)
        for(int j = 0; j < a.getColumms(); j++)
            *result(i, j) = (*a(i,j)) + (*b(i,j));
    return result;
}

Matrix Matrix::add(std::vector<double> v, double e) {
    Matrix result(1, v.size());
    for(int i = 0; i < v.size(); i++)
        *result(1, i) = v[i] + e;
    return result;
}

Matrix Matrix::transpose(Matrix a) {
    Matrix result(a.getColumms(), a.getRows());
    for(int i = 0; i < a.getRows(); i++)
        for(int j = 0; j < a.getColumms(); j++)
            *result(j, i) = *a(i, j);
    return result;
}

Matrix Matrix::sub(Matrix a, Matrix b) {
    Matrix result(a.getRows(), a.getColumms());
    for(int i = 0; i < a.getRows(); i++)
        for(int j = 0; j < a.getColumms(); j++)
            *result(i, j) = (*a(i,j)) - (*b(i,j));
    return result;
}

Matrix Matrix::mul(Matrix a, Matrix b) {
    Matrix result(a.getRows(), b.getRows());
    if(a.getColumms() == b.getRows())
        for(int i = 0; i < a.getRows(); i++)
            for(int j = 0; j < a.getColumms(); j++)
                for (int k = 0; k < a.getColumms(); k++)
                    *result(i, j) += (*a(i, k)) * (*b(k, j));
    return result;
}

Matrix Matrix::mul(std::vector<double> v, double e) {
    Matrix result(1, v.size());
    for(int i = 0; i < v.size(); i++)
        *result(0, i) = v[i] * e;
    return result;
}

double Matrix::dot(Matrix a, Matrix b) {
    double sum = 0.0;
    for(int i = 0; i < a.getColumms(); i++)
        sum += (*a(0,i)) * (*b(0, i));
    return sum;
}

//Matrix column
Matrix Matrix::toMatrix(std::vector<double> v) {
    Matrix aux(1, v.size());
    for(int i = 0; i < v.size(); i++)
        *aux(0, i) = v.at(i);
    return aux;
}

void Matrix::printAll(Matrix a)
{
    for(int i = 0; i < a.getRows(); i++)
        for(int j = 0; j < a.getColumms(); j++)
            std::cout << (*a(i, j)) << std::endl;
}

void Matrix::add(double n)
{
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < columns; j++)
            data[i][j] += n;
}

void Matrix::mul(double n)
{
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < columns; j++)
            data[i][j] *= n;
}
