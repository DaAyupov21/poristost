//
// Created by damir on 01.11.2019.
//

#include "Svertka.h"
#include <iomanip>
Svertka::Svertka(vector<vector<int>> m, vector<vector<int>> k) {
    int res = 0;
    matrix = m;
    kernel = k;
    result.resize(matrix.size()-kernel.size()+1);
    for(auto & i : result){
        i.resize(matrix.size()-kernel.size() + 1, 0); //создаем размерность матрицы после свертки
    }
    PrintResult();
    cout << result[3].size()<<endl<<endl;
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); i++){
            res = 0;
            for(int ik = 0; ik < kernel.size(); ik++){
                for(int jk = 0; jk < kernel[i].size(); jk++){
                    res += matrix[ik+i][jk+j]*kernel[i][j];

                }
            }
            result[i][j] = res;
            cout << res << endl;
        }
    }

}
void Svertka::PrintResult() {
    for(int i = 0; i < result.size(); i++){
        for (int j = 0; j < result[i].size(); i++){
            cout << setw(5) << result[i][j];
        }
        cout << endl;
    }
}
