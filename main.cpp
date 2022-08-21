//Задача "Ходы ферзя" сириус курсы
/*
 На шахматной доске стоит ферзь. Отметьте положение ферзя на доске и все клетки,
 которые бьёт ферзь. Клетку, где стоит ферзь, отметьте буквой «Q», клетки, которые бьёт ферзь,
 отметьте символами «*», остальные клетки заполните точками.

Входные данные

В двух строках входного файла заданы два числа — координаты нахождения ферзя.
 Числа во входном файле натуральные, не превосходящие 8 по значению.

Выходные данные

Выведите на экран изображение доски так, как это показано в примере.
 Обратите внимание, что символы в одной строке разделены пробелом.

 ВВОД:
 4
 2
 ВЫВОД:
. * . . * . . .
. * . * . . . .
* * * . . . . .
* Q * * * * * *
* * * . . . . .
. * . * . . . .
. * . . * . . .
. * . . . * . .

 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, k;
    n = 8;
    m = 8;
    k = 1;
    vector<vector<int> > t(n + 14, vector<int> (m + 14, 0));
    for (int i = 0; i < k; ++i){
        int mi, mj;
        cin >> mi >> mj;
        t[mi+6][mj+6] = -1;
    }

    vector<int> di = {-1, -1, -1,  0, 0,  1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, -1, -2, -3, -4, -5, -6, -7,
    2, 3, 4, 5, 6, 7,  2, 3, 4, 5, 6, 7,  -2, -3, -4, -5, -6, -7,  -2, -3, -4, -5, -6, -7};
    vector<int> dj = {-1,  0,  1, -1, 1, -1, 0, 1, 1, 2, 3, 4, 5, 6, 7, -1, -2, -3, -4, -5, -6, -7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      2, 3, 4, 5, 6, 7,   -2, -3, -4, -5, -6, -7,   2, 3, 4, 5, 6, 7,  -2, -3, -4, -5, -6, -7};
    for (int i = 7; i < t.size() - 7; ++i){
        for (int j = 7; j < t[i].size() - 7; ++j){
            if (t[i][j] == -1){
                for (int k = 0; k < di.size(); ++k){
                    int ni = i + di[k];
                    //cout << di[k] << " ";
                    int nj = j + dj[k];
                    //cout << dj[k] << " "<< endl;
                    if (t[ni][nj] != -1)
                        ++t[ni][nj];
                }
            }
        }
    }
    for (int i = 7; i < t.size() - 7; ++i){
        for (int j = 7; j < t[i].size() - 7; ++j){
            if (t[i][j] == -1){
                cout << "Q"<< ' ';
            }
            else if (t[i][j] == 0){
                cout << "."<< ' ';
            }
            else{
                cout << '*'<< ' ';
            }
        }
        cout << endl;
    }
    return 0;
}
