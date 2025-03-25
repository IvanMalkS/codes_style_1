//К - ичные числа.Среди чисел в системе счисления с основанием K(2≤K≤10) определить сколько
//имеется чисел из N(1 < N < 20, N + K < 26) разрядов таких, что в их записи не содержится более
//трех подряд идущих нулей.Для того, чтобы избежать переполнения, ответ
//представьте в виде вещественного числа.

#include <iostream>
#include <cmath>
#include <string>
#include <Windows.h>
using namespace std;

bool NoThreeZeros(string &num)
{
    int count = 0;
    for (char ch : num)
    {
        if (ch == '0')
        {
            count++;
            if (count > 3)
                return false;
        }
        else
            count = 0;
    }
    return true;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int k, n;

    while (true)
    {
        cout << "Введите основание системы счисления K(2 <= K <= 10): ";
        cin >> k;
        if (k >= 2 && k <= 10)
        {
            break;
        }
        else
        {
            cout << "Некорректный ввод. Повторите попытку." << endl;
        }
    }

    while (true)
    {
        cout << "Введите кол-во разрядов N(1 < N < 20): ";
        cin >> n;
        if (n > 1 && n < 20 && (n + k) < 26)
        {
            break;
        }
        else
        {
            cout << "Некорректный ввод. Повторите попытку." << endl;
        }
    }

    double total = 0;
    int min_number = pow(k, n - 1);
    int max_number = pow(k, n);
    // FIX ME не рекомендуется использовать методы внутри for
    // for (int i = pow(k, n - 1); i < pow(k, n); i++)
    for (int i = min_number; i < max_number; i++)
    {
        // FIX ME лишняя инициализация пустой строки
        // string num = "";
        string num;
        int temp = i;

        if (k != 10)
        {
            for (int j = 0; j < n; j++)
            {
                num = to_string(temp % k) + num;
                temp = temp / k;
            }
        }

        if (num[0] != '0' && NoThreeZeros(num))
        {
            total++;
        }
    }

    cout << "Количество чисел: " << total << endl;
    return 0;
}