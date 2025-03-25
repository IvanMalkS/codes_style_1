//Во всех заданиях данной подгруппы предполагается, что исходные строки, определяющие выражения,
//не содержат пробелов.При выполнении заданий не следует использовать оператор цикла.
//Вывести значение целочисленного выражения, заданного в виде строки S.Выражение
//определяется следующим образом(функция M возвращает максимальный из своих параметров,
//а функция m — минимальный) :
//        <выражение> :: = <цифра> | M(<выражение>, <выражение>) | m(<выражение>, <выражение>)

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int element(string str) {
    if (str[0] == 'M' || str[0] == 'm') {
        return calc(str.substr(2, str.size() - 3)); // Убираем "M(" и ")"
    }
    return stoi(str);
}

int calc(string str) {
    int i = 0;
    int level = 0;
    int pos = -1;

    while (i < str.size()) {
        if (str[i] == '(') level++;
        if (str[i] == ')') level--;
        if (level == 1 && str[i] == ',') {
            pos = i;
            break;
        }
        i++;
    }

    if (pos == -1) {
        return element(str);
    }

    string left = str.substr(0, pos);
    string right = str.substr(pos + 1);

    if (str[0] == 'M') {
        return max(calc(left), calc(right));
    }
    else if (str[0] == 'm') {
        return min(calc(left), calc(right));
    }

    return 0;
}

int main() {
    setlocale(LC_ALL, "Russian");
    string str;
    cout << "Введите выражение: ";
    getline(cin, str);
    int r = calc(str);
    cout << "Ответ: " << r << endl;
    return 0;
}
