/*
 * Продолжение задания №1
 * Заголовочный файл для задачи о рюкзаке.
 * Описание задачи:
 * Археолог нашел N артефактов. Известны веса (сi) и ценности (di) артефактов.
 * Нужно выбрать такое подмножество найденных вещей, чтобы суммарный их вес не превысил Z кг,
 * а их общая ценность оказалась максимальной. Известно, что решение единственно.
 * Укажите порядковые номера вещей, которые нужно взять. Исходные данные находятся в текстовом файле,
 * в первой строке указаны N и Z, а во второй строке значения весов (в кг), в третьей - ценность находок.
 * Вывести так же суммарный вес и общую ценность результата.
 */

#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <vector>
#include <fstream>

/**
 * Рекурсивная функция для поиска выбранных артефактов.
 *
 * @param dp_table - матрица динамического программирования.
 * @param current_index - текущий индекс артефакта.
 * @param current_weight - текущий вес.
 * @param weights - вектор весов артефактов.
 * @param total_weight - суммарный вес выбранных артефактов.
 */
void FindSelectedItems(const std::vector<std::vector<int>>& dp_table, int current_index, int current_weight, const std::vector<int>& weights, double& total_weight);

/**
 * Функция для чтения данных из файла.
 *
 * @param filename - имя файла.
 * @param num_items - количество артефактов.
 * @param max_capacity - максимальный вес.
 * @param weights - вектор весов артефактов.
 * @param values - вектор ценностей артефактов.
 */
void ReadFromFile(const std::string& filename, int& num_items, int& max_capacity, std::vector<int>& weights, std::vector<int>& values);

/**
 * Решение задачи о рюкзаке с использованием динамического программирования.
 *
 * @param num_items - количество предметов.
 * @param max_capacity - максимальный вес рюкзака.
 * @param weights - вектор весов предметов.
 * @param values - вектор ценностей предметов.
 * @return Матрица динамического программирования.
 */
std::vector<std::vector<int>> SolveKnapsackProblem(int num_items, int max_capacity, const std::vector<int>& weights, const std::vector<int>& values);

/**
 * Запись результата в файл.
 *
 * @param filename - имя файла.
 * @param max_value - максимальная ценность рюкзака.
 * @param total_weight - суммарный вес выбранных предметов.
 */
void WriteResultToFile(const std::string& filename, int max_value, double total_weight);

/**
 * Генерация случайных данных для тестирования и запись их в файл.
 *
 * @param filename - имя файла.
 * @param num_items - количество артефактов.
 * @param max_capacity - максимальный вес.
 */
void GenerateRandomData(const std::string& filename, int num_items, int max_capacity);

/**
 * Основная функция для решения задачи о рюкзаке.
 *
 * @return 0 в случае успешного завершения.
 */
int main();

#endif // KNAPSACK_H
