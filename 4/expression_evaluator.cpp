// FIX ME задача на по стилю

/*
 * //Во всех заданиях данной подгруппы предполагается, что исходные строки, определяющие выражения,
 * //не содержат пробелов.При выполнении заданий не следует использовать оператор цикла.
 * //Вывести значение целочисленного выражения, заданного в виде строки S.Выражение
 * //определяется следующим образом(функция M возвращает максимальный из своих параметров,
 * //а функция m — минимальный) :
 * //        <выражение> :: = <цифра> | M(<выражение>, <выражение>) | m(<выражение>, <выражение>)
*/

/*
 * Продолжение задачи №4
 * Во всех заданиях данной подгруппы предполагается, что исходные строки, определяющие выражения,
 * не содержат пробелов.При выполнении заданий не следует использовать оператор цикла.
 * Вывести значение целочисленного выражения, заданного в виде строки S.Выражение
 * определяется следующим образом(функция M возвращает максимальный из своих параметров,
 * а функция m — минимальный) :
 *         <выражение> :: = <цифра> | M(<выражение>, <выражение>) | m(<выражение>, <выражение>)
*/

// FIX ME пробел между кодом
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//FIX ME забыли поднять функцию
int EvaluateExpression(const string& expression);

/**
 * @brief Вычисляет значение элемента выражения (цифра или вложенное выражение)
 * @param expression Строка с выражением для вычисления
 * @return Целочисленное значение элемента
 */
// FIX ME плохой нейминг
// int element(string str) {
int EvaluateElement(string& expression) {
    if (expression[0] == 'M' || expression[0] == 'm') {
        return EvaluateExpression(expression.substr(2, expression.size() - 3));
    }
    return stoi(expression);
}

/**
 * @brief Вычисляет значение целочисленного выражения
 * @param expression Строка с выражением для вычисления
 * @return Результат вычисления выражения
 */
// FIX ME плохой неймиг
// int calc(string str) {
int EvaluateExpression(string& expression) {
    // FIX ME плохой нейминг
    // int i = 0;
    // int level = 0;
    // int pos = -1;

    int current_position = 0;
    int nesting_level = 0;
    int comma_position = -1;

    while (current_position < expression.size()) {
        if (expression[current_position] == '(') {
            ++nesting_level;
        }
        if (expression[current_position] == ')') {
            --nesting_level;
        }
        if (nesting_level == 1 && expression[current_position] == ',') {
            comma_position = current_position;
            break;
        }
        ++current_position;
    }

    if (comma_position == -1) {
        return EvaluateElement(expression);
    }

    const string left_expression = expression.substr(0, comma_position);
    const string right_expression = expression.substr(comma_position + 1);

    if (expression[0] == 'M') {
        return max(EvaluateExpression(left_expression),
                   EvaluateExpression(right_expression));
    } else if (expression[0] == 'm') {
        return min(EvaluateExpression(left_expression),
                   EvaluateExpression(right_expression));
    }

    return 0;
}

int main() {
    setlocale(LC_ALL, "Russian");
    // FIX ME плохой нейминг
    // string str;
    string input_expression;
    cout << "Введите выражение: ";
    getline(cin, input_expression);
    // FIX ME плохой нейминг
    // int r = calc(str);
    int result = EvaluateExpression(input_expression);
    cout << "Ответ: " << result << endl;
    return 0;
}