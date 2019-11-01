//
// Created by damir on 01.11.2019.
//

#include "Svertka.h"
#include <iomanip>

Svertka::Svertka(vector<vector<int>> m, vector<vector<int>> k) {
    matrix = m;
    kernel = k;
    result.resize(matrix.size()-kernel.size()+1);
    for(auto & i : result){
        i.resize(matrix.size()-kernel.size() + 1, 0); //создаем размерность матрицы после свертки
    }
cout << endl;
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            for(int ik = 0; ik < kernel.size(); ik++) {
                for (int jk = 0; jk < kernel[ik].size(); jk++) {
                    if (i + ik > matrix.size() || j + jk > matrix[i].size()) {
                        continue;
                    }
                    result[i][j] += matrix[i + ik][j + jk] * kernel[ik][jk];
                }
            }
        }
        cout << endl;
    }

}
void Svertka::PrintResult() {
    for(int i = 0; i < result.size(); i++){
        for (int j = 0; j < result[i].size(); j++){
            cout << setw(5) << result[i][j];
        }
        cout << endl;
    }
}
void Svertka::PrintMatrix() {
    for(int i = 0; i < matrix.size(); i++){
        for (int j = 0; j < matrix[i].size(); j++){
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}
