// FIX ME задача не шаблону
/*
 * //Хромой король.На квадратной доске расставлены монеты, достоинством от 1 до
 * //100. Хромой король, находящийся в правом нижнем углу, мечтает попасть в левый верхний.
 * //При этом он может передвигаться только в клетку слева или сверху и хочет, чтобы сумма всех
 * //монет, оказавшихся у него на пути, была бы максимальной.Определить эту сумму и путь, каким
 * //образом должен двигаться король, чтобы ее собрать.Ввод и вывод организовать при помощи
 * //текстовых файлов.Формат входных данных : в первой строке входного файла записано число
 * //N - размер доски(1 < N < 80).Далее следует N строк, каждая из которых содержит N целых чисел,
 * //представляющих доску.В первую строку выходного файл нужно вывести единственное число :
 * //максимальную сумму, а во второй строке вывести путь в виде строки символов, обозначив
 * //символом L движение влево, а символом U - движение вверх.
*/

/*
 * Продолжение задачи №2
 * Хромой король.На квадратной доске расставлены монеты, достоинством от 1 до
 * 100. Хромой король, находящийся в правом нижнем углу, мечтает попасть в левый верхний.
 * При этом он может передвигаться только в клетку слева или сверху и хочет, чтобы сумма всех
 * монет, оказавшихся у него на пути, была бы максимальной.Определить эту сумму и путь, каким
 * образом должен двигаться король, чтобы ее собрать.Ввод и вывод организовать при помощи
 * текстовых файлов.Формат входных данных : в первой строке входного файла записано число
 * N - размер доски(1 < N < 80).Далее следует N строк, каждая из которых содержит N целых чисел,
 * представляющих доску.В первую строку выходного файл нужно вывести единственное число :
 * максимальную сумму, а во второй строке вывести путь в виде строки символов, обозначив
 * символом L движение влево, а символом U - движение вверх.
*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// FIX ME пропущен импорт
#include <algorithm>

using namespace  std;

/**
 * @brief Чтение входных данных из файла
 * @param input_filename Имя входного файла
 * @param coin_board Ссылка на двумерный вектор для хранения значений монет
 * @return Размер доски или -1 в случае ошибки
 */
int ReadInput(const string& input_filename, vector<vector<int>>& coin_board)
{
    ifstream input_file(input_filename);
    if (!input_file.is_open())
    {
        cerr << "Failed to open input file: " << input_filename << endl;
        return -1;
    }

    int board_size;
    input_file >> board_size;

    coin_board.resize(board_size, vector<int>(board_size));
    for (int row = 0; row < board_size; ++row)
    {
        for (int col = 0; col < board_size; ++col)
        {
            input_file >> coin_board[row][col];
        }
    }

    input_file.close();
    return board_size;
}

/**
 * @brief Запись результатов в файл
 * @param output_filename Имя выходного файла
 * @param max_coins Максимальное количество собранных монет
 * @param path_string Строка с путем короля
 * @return true если запись успешна, false в случае ошибки
 */
bool WriteOutput(const string& output_filename, int max_coins,
                 const string& path_string)
                 {
    ofstream output_file(output_filename);
    if (!output_file.is_open())
    {
        cerr << "Failed to open output file: " << output_filename << endl;
        return false;
    }

    output_file << max_coins << endl;
    output_file << path_string << endl;

    output_file.close();
    return true;
}

/**
 * @brief Вычисление максимального количества монет на пути короля
 * @param coin_board Доска с монетами
 * @param dp_matrix Матрица для динамического программирования
 * @param board_size Размер доски
 */
// FIX ME плохой нейминг
// void Solve(const vector<vector<int>>& board, vector<vector<int>>& board2, int n) {
void CalculateMaxCoins(const vector<vector<int>>& coin_board,
                       vector<vector<int>>& dp_matrix, int board_size)
{ // FIX ME Фигурная скобка должна быть на новой строке (строка 19, 22, 25, 29, 30, 31, 34, 41, 45, 46, 47, 51, 56, 60).

    // FIX ME ранняя инициализация и плохой нейминг
    // int i, j;

    dp_matrix[board_size - 1][board_size - 1] =
            coin_board[board_size - 1][board_size - 1];

    for (int row = board_size - 2; row >= 0; --row)
    {
        dp_matrix[row][board_size - 1] =
                dp_matrix[row + 1][board_size - 1] + coin_board[row][board_size - 1];
    }

    for (int col = board_size - 2; col >= 0; --col)
    {
        dp_matrix[board_size - 1][col] =
                dp_matrix[board_size - 1][col + 1] + coin_board[board_size - 1][col];
    }

    for (int row = board_size - 2; row >= 0; --row)
    {
        for (int col = board_size - 2; col >= 0; --col)
        {
            dp_matrix[row][col] =
                    max(dp_matrix[row + 1][col], dp_matrix[row][col + 1]) +
                    coin_board[row][col];
        }
    }
}

/**
 * @brief Восстановление пути короля
 * @param dp_matrix Матрица динамического программирования
 * @param board_size Размер доски
 * @return Строка с путем (U - вверх, L - влево)
 */
// FIX ME не самый хороший нейминг
// string Path(const vector<vector<int>>& board2, int n)
string ReconstructPath(const vector<vector<int>>& dp_matrix, int board_size) {
    // FIX ME плохой нейминг и лишняя инициализация пустой строки
    // string s = "";
    string path;

    // FIX ME Плохой нейминг
    // int i = 0, j = 0;
    int current_row = 0;
    int current_col = 0;

    while (current_row < board_size - 1 || current_col < board_size - 1) {
        if (current_row < board_size - 1 && current_col < board_size - 1) {
            if (dp_matrix[current_row + 1][current_col] >
                dp_matrix[current_row][current_col + 1]) {
                path += "U";
                ++current_row;
            } else {
                path += "L";
                ++current_col;
            }
        } else if (current_row < board_size - 1) {
            path += "U";
            ++current_row;
        } else {
            path += "L";
            ++current_col;
        }
    }

    reverse(path.begin(), path.end());
    return path;
}

int main() {
    setlocale(0, "");

    // FIX ME разнесено по функциям
    /*
     * fstream f1("f1.txt");
     * if (!f1.is_open()) {
     *         cout << "Не удалось открыть файл f1.txt(" << endl;
     *         return 1;
     *  }
     * fstream f2("f2.txt");
     * if (!f2.is_open()) {
     *     cout << "Не удалось открыть файл f2.txt(" << endl;
     *     return 1;
     * }
     *
    */

    // FIX ME плохой нейминг
    // vector<vector<int>> board(n, vector<int>(n));
    vector<vector<int>> coin_board;
    string input_filename = "f1.txt";
    int board_size = ReadInput(input_filename, coin_board);
    if (board_size == -1) {
        return 1;
    }

    // FIX ME плохой неймнг
    // vector<vector<int>> board2(n, vector<int>(n, 0));
    vector<vector<int>> dp_matrix(board_size, vector<int>(board_size, 0));
    CalculateMaxCoins(coin_board, dp_matrix, board_size);

    string path = ReconstructPath(dp_matrix, board_size);
    string output_filename = "f2.txt";

    if (!WriteOutput(output_filename, dp_matrix[0][0], path)) {
        return 1;
    }

    return 0;
}