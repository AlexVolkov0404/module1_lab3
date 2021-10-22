// module1_lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
double fun(double x) {  //обчислює значення функції
    int p;
    p = pow(x, 3) + x - 5;
    return p;
}
double fun_p1(double x) { //обчислює значення першої похідної функції
    int p;
    p = 3 * pow(x, 2) + 1;
    return p;
}
double fun_p2(double x) { //обчислює значення другої рохідної функції
    int p;
    p = 6 * x;
    return p;
}
int main()
{
    double a, b, e, x0, x1;
    cout << "a=";
    cin >> a;
    cout << "b=";
    cin >> b;
    cout << "e=";
    cin >> e;
    bool k = true;

    if (fun(a) * fun(b) > 0) { //перевірка умов методу
        k = false;
    }
    if (k) {
        if (fun(a) * fun_p2(a) > 0) {
            x0 = a;
            x1 = a - fun(a) / fun_p1(a);
        }
        else {
            if (fun(b) * fun_p2(b) > 0) {
                x0 = b;
                x1 = b - fun(b) / fun_p1(b);
            }
            else k = false;
        }

    }

    if (k) {
        while (abs(x1 - x0) >= e) {//знаходження послідовності х,що збігаються до кореня
            x0 = x1;
            x1 = x1 - fun(x1) / fun_p1(x1);
        }
        cout << "koren: " << x1;
    }
    else cout << "ymova dla metody ne vykonuetsya";
}

