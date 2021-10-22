// task15.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
double fun_lag(double nn, double* XX, double* YY, double xk) { //побудова многочлена Лагранжа
    double yk = 0;
    for (int i = 0; i < nn; i++) {
        double p = 1;
        for (int j = 0; j < nn; j++) {
            if (j != i) {
                p = p * (xk - XX[j]) / (XX[i] - XX[j]);
            }

        }
        yk = yk + p * YY[i];
    }
    return yk;
}
int main()
{
    int n;
    double x, y;
    cout << "vvesty kilkist vusliv: ";
    cin >> n;

    double* X = new double[n]; //масив абсцис вузлів інтерполяції
    double* Y = new double[n]; //масив ординат вузлів інтерполяції
    cout << "vvesty koordynaty vusliv: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << ": ";
        cin >> X[i];
        cout << "y" << i + 1 << ": ";
        cin >> Y[i];
    }
    cout << "x: ";
    cin >> x;
    y = fun_lag(n, X, Y, x); //обчислення значення многочлена лагранжа для проміжку х
    cout << "y: " << y;

}

