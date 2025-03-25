// FIX ME задача не шаблону
/*
 * //Археолог нашел N артефактов.Известны веса(сi) и ценности(di) артефактов.Нужно
 * //выбрать такое подмножество найденных вещей, чтобы суммарный их вес не превысил Z кг, а их
 * //общая ценность оказалась максимальной.Известно, что решение единственно.Укажите поряд
 * //ковые номера вещей, которые нужно взять.Исходный данные находятся в текстовом файле, в
 * //первой строке указаны N и Z, а во второй строке значения весов(в кг), в третьей - ценность
 * //находок.Вывести так же суммарный вес и общую ценность результата.
*/

/*
 * Продолжение задания №1
 * Археолог нашел N артефактов. Известны веса (сi) и ценности (di) артефактов.
 * Нужно выбрать такое подмножество найденных вещей, чтобы суммарный их вес не превысил Z кг,
 * а их общая ценность оказалась максимальной. Известно, что решение единственно.
 * Укажите порядковые номера вещей, которые нужно взять. Исходные данные находятся в текстовом файле,
 * в первой строке указаны N и Z, а во второй строке значения весов (в кг), в третьей - ценность находок.
 * Вывести так же суммарный вес и общую ценность результата.
*/

# include "knapsack.h"
# include <iostream>
# include <ctime>
# include <fstream>
# include <vector>

// FIX ME не нужные импорты
// # include <windows.h>

using namespace std;

/**
 * Рекурсивная функция для поиска выбранных артефактов.
 *
 * @param dp_table - матрица динамического программирования.
 * @param current_index - текущий индекс артефакта.
 * @param current_weight - текущий вес.
 * @param weights - вектор весов артефактов.
 * @param total_weight - суммарный вес выбранных артефактов.
*/
// FIX ME не по неймину
// void find(const vector<vector<int>>& a, int k, int s, const vector<int>& w, double& weight)
void FindSelectedItems(const std::vector<std::vector<int>>& dp_table, int current_index, int current_weight, const std::vector<int>& weights, double& total_weight)
{  // FIX ME: Фигурная скобка должна быть на новой строке (строка 24, 31, 35, 70, 76, 84, 86, 88, 92).
    // FIX ME: Однострочные блоки запрещены. Нужно использовать фигурные скобки.
    // if (k == 0 || s == 0) return;
    if (current_index == 0 || current_weight == 0)
    {
        return;
    }


    if (dp_table[current_index][current_weight] == dp_table[current_index - 1][current_weight])  // Если коробка не была выбрана
    {
        FindSelectedItems(dp_table, current_index - 1, current_weight, weights, total_weight);
    }
    else  // Если коробка была выбрана
    {
        cout << current_index << " ";  // Выводим номер коробки
        total_weight += weights[current_index];
        FindSelectedItems(dp_table, current_index - 1, current_weight - weights[current_index], weights, total_weight);  // Ищем оставшиеся коробки
    }
}

/**
 * Функция для чтения данных из файла.
 *
 * @param filename - имя файла.
 * @param num_items - количество артефактов.
 * @param max_capacity - максимальный вес.
 * @param weights - вектор весов артефактов.
 * @param values - вектор ценностей артефактов.
 */
void ReadFromFile(const string& filename, int& num_items, int& max_capacity, vector<int>& weights, vector<int>& values)
{
    fstream input_file(filename);
    if (!input_file.is_open())
    {
        cerr << "Ошибка открытия файла!" << endl;
        exit(1);
    }

    input_file >> num_items >> max_capacity;
    weights.resize(num_items + 1);
    values.resize(num_items + 1);

    for (int i = 1; i <= num_items; i++)
    {
        input_file >> weights[i];
    }

    for (int i = 1; i <= num_items; i++)
    {
        input_file >> values[i];
    }

    input_file.close();
}


/**
 * Решение задачи о рюкзаке с использованием динамического программирования.
 *
 * @param num_items - количество предметов.
 * @param max_capacity - максимальный вес рюкзака.
 * @param weights - вектор весов предметов.
 * @param values - вектор ценностей предметов.
 * @return Матрица динамического программирования.
 */
vector<vector<int>> SolveKnapsackProblem(int num_items, int max_capacity, const vector<int>& weights, const vector<int>& values)
{
    vector<vector<int>> dp_table(num_items + 1, vector<int>(max_capacity + 1, 0));

    for (int k = 1; k <= num_items; k++)
    {
        for (int s = 1; s <= max_capacity; s++)
        {
            if (s >= weights[k])
            {
                dp_table[k][s] = max(dp_table[k - 1][s], dp_table[k - 1][s - weights[k]] + values[k]);
            }
            else
            {
                dp_table[k][s] = dp_table[k - 1][s];
            }
        }
    }

    return dp_table;
}

/**
 * Запись результата в файл.
 *
 * @param filename - имя файла.
 * @param max_value - максимальная ценность рюкзака.
 * @param total_weight - суммарный вес выбранных предметов.
 */
void WriteResultToFile(const string& filename, int max_value, double total_weight)
{
    fstream output_file(filename, ios::app);  // Открываем файл в режиме добавления
    if (!output_file.is_open())
    {
        cerr << "Ошибка открытия файла для записи результата!" << endl;
        exit(1);
    }

    output_file << max_value << " " << total_weight << endl;  // Записываем результат
    output_file.close();
}

/**
 * Генерация случайных данных для тестирования и запись их в файл.
 *
 * @param filename - имя файла.
 * @param num_items - количество артефактов.
 * @param max_capacity - максимальный вес.
 */
void GenerateRandomData(const string& filename, int num_items, int max_capacity)
{
    fstream output_file(filename);
    if (!output_file.is_open())
    {
        cerr << "Ошибка открытия файла для записи данных!" << endl;
        exit(1);
    }

    srand(time(0));

    output_file << num_items << " " << max_capacity << endl;

    for (int i = 1; i <= num_items; i++)
    {
        output_file << rand() % 50 + 1 << " ";
    }
    output_file << endl;

    for (int i = 1; i <= num_items; i++)
    {
        output_file << rand() % 101 << " ";
    }
    output_file << endl;

    output_file.close();
}


int main()
{
    // FIX ME: Использование Windows.h не рекомендуется для кроссплатформенного кода.
    //  SetConsoleCP(1251);
    //  SetConsoleOutputCP(1251);

    // FIX ME: лучше перенести отдельно к функции с рандомом
    // srand(time(0));

    cout << "Добро пожаловать! Перед вами задача о неделимом рюкзаке. В чем её суть?" << endl;
    cout << "Археолог нашел N артефактов. Известны веса (сi) и ценности (di) артефактов." << endl;
    cout << "Нужно выбрать такое подмножество найденных вещей, чтобы суммарный их вес не превысил Z кг," << endl;
    cout << "а их общая ценность оказалась максимальной." << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << "Вам необходимо будет ввести два числа: N - количество артефактов;" << endl;
    cout << "Z - суммарный вес, который нельзя превышать." << endl;
    cout << "После чего мы подсчитаем суммарный вес и максимальную ценность, а также выведем товары, которые были взяты." << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << endl;
    cout << endl;

    // FIX ME не по неймингу
    // int n;
    int num_items;
    cout << "Введите число N - количество артефактов: ";
    cin >> num_items;

    // FIX ME не по неймингу
    // int z;
    int max_capacity;
    cout << "Введите число Z - вес, который нельзя превышать: ";
    cin >> max_capacity;

    // FIX ME: Чтение из файла и генерация рандомных данных вынесено в отдельную функцию для оптимизации
    /*
    fstream f1("a.txt");
    f1 << n << " " << z;
    f1 << endl;


    for (int i = 1; i <= n; i++)
    {
        w[i] = rand() % 50 + 1;
        f1 << w[i] << " ";
    }
    f1 << endl;

    for (int i = 1; i <= n; i++)
    {
        p[i] = rand() % 101;
        f1 << p[i] << " ";
    }
    f1 << endl;
    */

    GenerateRandomData("a.txt", num_items, max_capacity);

    // FIX ME не по неймингу
    // vector<int> p(num_items + 1, 0);  // Цены (индексы от 1 до n)
    vector<int> values(num_items + 1, 0);

    // FIX ME не по неймингу
    // vector<int> w(num_items + 1, 0);  // Веса (индексы от 1 до n)
    vector<int> weights(num_items + 1, 0);

    ReadFromFile("a.txt", num_items, max_capacity, weights, values);

    // FIX ME Выенесено в отдельный метод для оптимизации
    /*
    for (int k = 1; k <= n; k++)
  {
    for (int s = 1; s <= z; s++)
    {
      if (s >= w[k])
      {
        a[k][s] = max(a[k - 1][s], a[k - 1][s - w[k]] + p[k]);
      }
      else
      {
        a[k][s] = a[k - 1][s];
      }
    }
  }
    */

    // FIX ME не по неймнингу
    // vector<vector<int>> a = solveKnapsack(num_items, max_capacity, weights, values);
    vector<vector<int>> dp_table = SolveKnapsackProblem(num_items, max_capacity, weights, values);

    // FIX ME плохой нейминг
    // double weight = 0;
    double total_weight = 0;

    cout << "Максимальный вес рюкзака: " << total_weight << endl;
    cout << "Максимальная ценность рюкзака: " << dp_table[num_items][max_capacity] << endl;
    FindSelectedItems(dp_table, num_items, max_capacity, weights, total_weight);
    cout << endl;

    // FIX ME сохранение вынесено в отдельный файл
    /*
    f1 << a[n][z] << " " << weight << endl;
  f1.close();
    */

    // Запись результата в файл
    WriteResultToFile("a.txt", dp_table[num_items][max_capacity], total_weight);

    return 0;
}
