/*
 * Продолжение задачи №4
 * Заголовочные файлы
 * Во всех заданиях данной подгруппы предполагается, что исходные строки, определяющие выражения,
 * не содержат пробелов.При выполнении заданий не следует использовать оператор цикла.
 * Вывести значение целочисленного выражения, заданного в виде строки S.Выражение
 * определяется следующим образом(функция M возвращает максимальный из своих параметров,
 * а функция m — минимальный) :
 *         <выражение> :: = <цифра> | M(<выражение>, <выражение>) | m(<выражение>, <выражение>)
*/


#ifndef EXPRESSION_EVALUATOR_H_
#define EXPRESSION_EVALUATOR_H_

#include <string>

/**
 * @file expression_evaluator.h
 * @brief Вычисление специальных выражений с функциями M (максимум) и m (минимум)
 */

/**
 * @brief Вычисляет значение элемента выражения (цифра или вложенное выражение)
 * @param expression Строка с выражением (может быть модифицирована)
 * @return Целочисленное значение элемента
 * @note Функция является частью взаимно-рекурсивной пары с EvaluateExpression
 */
int EvaluateElement(std::string& expression);

/**
 * @brief Вычисляет значение целочисленного выражения
 * @param expression Строка с выражением (может быть модифицирована)
 * @return Результат вычисления выражения
 * @note Функция является частью взаимно-рекурсивной пары с EvaluateElement
 * @details Поддерживает выражения вида:
 *          - Цифры (например "5")
 *          - M(expr1, expr2) - возвращает максимум
 *          - m(expr1, expr2) - возвращает минимум
 */
int EvaluateExpression(std::string& expression);

#endif  // EXPRESSION_EVALUATOR_H_