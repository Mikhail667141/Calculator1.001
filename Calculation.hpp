#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <string>

enum class Operation {
    Addition = 1,
    Subtraction,
    Multiplication,
    Division,
    Invalid
};

class Calculator {
public:
    void run(); // Главная функция программы, запускающая весь процесс вычислений.

private:
    double first_number_;
    double second_number_;

    void get_two_numbers(); // Запрашивает у пользователя ввод двух чисел.
    Operation get_operation_choice(); // Запрашивает у пользователя выбор операции.
    void calculate(const Operation& choice); // Выполняет вычисление в зависимости от выбранной операции.
    bool ask_for_another_calculation(); // Спрашивает у пользователя, хочет ли он выполнить еще одну операцию.
    void clear_input(); // Очищает буфер ввода.
    bool is_exit_symbol(const std::string& input); // Проверяет, является ли введенный символ выходным символом для завершения программы.
    double get_number_from_input(const std::string& prompt); // Запрашивает у пользователя ввод числа и возвращает его.
};

#endif  // CALCULATOR_HPP
