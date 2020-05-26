#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <locale.h>

using namespace std;

struct diag{
    int length = 0, summa = 0, maxValue = 0;
    int number;
};

bool comp(diag a, diag b)
{
    return ((a.length < b.length) || (a.length == b.length && a.summa < b.summa) || (a.length == b.length && a.summa == b.summa && a.maxValue < b.maxValue));
}

int main()
{
    setlocale(0, "Russian");
    vector < vector <int> > M;
    ifstream input;
    input.open("input.txt");
    int n, m;
    input >> n >> m;
    M.resize(n);
    for (vector < vector <int> > :: iterator it = M.begin(); it != M.end(); it++)
    {
        it -> resize(m);
        for (vector < int > :: iterator iter = it -> begin(); iter != it -> end(); iter++)
        {
            input >> *iter;
        }
    }
    //Вывод матрицы на экран:
    /*for (vector < vector < int > > :: iterator it = M.begin(); it != M.end(); it++)
    {
        for (vector < int > :: iterator  iter = it -> begin(); iter != it -> end(); cout << *iter << " ", iter++);
        cout << "\n";
    }
    */
    vector < diag > D;
    D.resize(n + m - 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            D[i + j].number = i + j + 1;
            D[i + j].length++;
            D[i + j].summa += M[i][j];
            if (D[i + j].maxValue < M[i][j]) D[i + j].maxValue = M[i][j];
        }
    sort(D.begin(), D.end(), comp);
    for (int i = 0; i < n + m - 1; i++)
    {
        cout << "Диагональ " << D[i].number << ": " << "- длина - " << D[i].length << ", сумма - " << D[i].summa << ", максимум - " << D[i].maxValue << "\n";
    }
    return 0;
}
