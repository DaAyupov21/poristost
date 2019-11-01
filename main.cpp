#include <iostream>
#include <vector>
#include "Svertka.h"
using namespace std;
int main() {
    vector<vector<int>> m = {{8,8,6,3,2,1,0,9}, {0,1,2,2,5,1,1,0},{1,0,6,1,2,9,0,1},{0,9,1,1,0,0,9,3}, {0,1,8,1,1,7,0,1}, {1,0,1,11,6,1,2,1}, {1,1,0,9,6,5,1,1}, {3,2,6,9,1,6,1,0}};
    vector<vector<int>> k {{1,0,0}, {0,1,0}, {0,0,1}};
    Svertka svertka {m, k};
    svertka.PrintResult();
    return 0;
}