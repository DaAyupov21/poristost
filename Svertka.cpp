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
    }

}
void Svertka::PrintResult() {
    for(auto & i : result){
        for (int j : i){
            cout << setw(5) << j;
        }
        cout << endl;
    }
}
void Svertka::PrintMatrix() {
    cout << "Matrix:\n";
    for(auto & i : matrix){
        for (int j : i){
            cout << setw(5) << j;
        }
        cout << endl;
    }
}
void Svertka::stridingMatrix() {
    int newSize = matrix.size()-kernel.size()-2;
    stridingResult.resize(newSize);
    for(auto & i :stridingResult){
        i.resize(newSize, 0);
    }
    for(int i = 0; i < stridingResult.size(); i++){
        for(int j = 0; j < stridingResult[i].size(); j++) {
            for (int ik = 0; ik < kernel.size(); ik ++) {
                for (int jk = 0; jk < kernel[ik].size(); jk ++) {
                    if (i + ik > matrix.size() || j + jk > matrix[i].size()) {
                        continue;
                    }
                    if(i == 0 && j ==0){
                        stridingResult[i][j] += matrix[i + ik][j + jk] * kernel[ik][jk];
                    } if (i + ik > matrix.size() || j + jk > matrix[i].size()) {
                        continue;
                    }
                    else if(i == 0){
                        stridingResult[i][j] += matrix[i + ik][j + jk + 1] * kernel[ik][jk];
                    }
                    else if(j == 0){
                        stridingResult[i][j] += matrix[i + ik + 1][j + jk] * kernel[ik][jk];
                    }
                    else{
                        stridingResult[i][j] += matrix[i + ik + 1][j + jk + 1] * kernel[ik][jk];
                    }

                }
            }
        }
    }
    PrintMatrix();
    cout << "Striding\n";
    for(auto & i :stridingResult){
        for(auto j : i){
            cout << setw(5)<<j;
        }
        cout << endl;
    }


}
