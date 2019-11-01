//
// Created by damir on 01.11.2019.
//

#ifndef SVERTKA_SVERTKA_H
#define SVERTKA_SVERTKA_H

#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

class Svertka {
private:
    vector<vector<int>> matrix;
    vector<vector<int>> kernel;
    vector<vector<int>> result;
public:
    Svertka(vector<vector<int>> m, vector<vector<int>> k);
    void PrintResult();

};


#endif //SVERTKA_SVERTKA_H
