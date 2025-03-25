// FIX ME задача на по стилю

/*
 * //К - ичные числа.Среди чисел в системе счисления с основанием K(2≤K≤10) определить сколько
 * //имеется чисел из N(1 < N < 20, N + K < 26) разрядов таких, что в их записи не содержится более
 * //трех подряд идущих нулей.Для того, чтобы избежать переполнения, ответ
 * //представьте в виде вещественного числа.
*/

/*
 * Продолжение задачи №3
 * К - ичные числа.Среди чисел в системе счисления с основанием K(2≤K≤10) определить сколько
 * имеется чисел из N(1 < N < 20, N + K < 26) разрядов таких, что в их записи не содержится более
 * трех подряд идущих нулей.Для того, чтобы избежать переполнения, ответ
 * представьте в виде вещественного числа.
*/

#include "k_numbers.h"

#include <iostream>
#include <cmath>
#include <string>

// FIX ME Использование Windows.h не рекомендуется для кроссплатформенного кода.
// #include <Windows.h>

using namespace std;

/**
 * @brief Проверяет, содержит ли число более трех подряд идущих нулей
 * @param num Строковое представление числа для проверки
 * @return true если число содержит не более трех подряд идущих нулей, false в противном случае
 * @details Функция проходит по всем символам строки и подсчитывает последовательные нули.
 *          Если встречается последовательность из более чем трех нулей, возвращает false.
 */
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

/**
 * @brief Подсчитывает количество чисел в заданной системе счисления, удовлетворяющих условиям задачи
 *
 * @param k Основание системы счисления (2 ≤ k ≤ 10)
 * @param n Количество разрядов в числе (1 < n < 20)
 * @return int Количество n-разрядных чисел в системе счисления k, которые:
 *             - Не начинаются с нуля
 *             - Не содержат более трех подряд идущих нулей
 */
int CalculateCount(int k, int n)
{
    int count = 0;
    int min_number = pow(k, n - 1);
    int max_number = pow(k, n);

    for (int i = min_number; i < max_number; i++)
    {
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
            count++;
        }
    }
    return  count;
}

int main()
{
    // FIX ME: Использование Windows.h не рекомендуется для кроссплатформенного кода.
    //  SetConsoleCP(1251);
    //  SetConsoleOutputCP(1251);

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

    // FIX ME лучше вынести в отдельную функцию
    /*
     *   // FIX ME не правильный тип данных и не лучший нейминг
     *   // double total = 0;
     *   int count = 0;
     *   int min_number = pow(k, n - 1);
     *   int max_number = pow(k, n);
     *   // FIX ME не рекомендуется использовать методы внутри for
     *   // for (int i = pow(k, n - 1); i < pow(k, n); i++)
     *
     *   for (int i = min_number; i < max_number; i++)
     *   {
     *       // FIX ME лишняя инициализация пустой строки
     *       // string num = "";
     *       string num;
     *       int temp = i;
     *
     *       if (k != 10)
     *       {
     *           for (int j = 0; j < n; j++)
     *           {
     *               num = to_string(temp % k) + num;
     *               temp = temp / k;
     *           }
     *       }
     *
     *       if (num[0] != '0' && NoThreeZeros(num))
     *       {
     *           count++;
     *       }
     *   }
    */

    int count = CalculateCount(k, n);

    cout << "Количество чисел: " << count << endl;
    return 0;
}