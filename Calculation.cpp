#include "Calculation.hpp"
#include <iostream>
#include <limits>
#include <string>

void Calculator::run()
{
    setlocale(0, "");
    std::cout << "Hello my friend!" << std::endl;
    std::cout << "Добро пожаловать в программу калькулятор!" << std::endl;


    while (true)
    {
        get_two_numbers();
        std::cout << "Введенные числа: " << first_number_ << " и " << second_number_ << std::endl;

        const Operation choice = get_operation_choice();
        if (choice == Operation::Invalid)
            break;
        calculate(choice);

        if (!ask_for_another_calculation())
        {
            break;
        }
    }
}

void Calculator::get_two_numbers()
{
    std::cout << "Введите два числа:" << std::endl;
    first_number_ = get_number_from_input("Первое число: ");
    second_number_ = get_number_from_input("Второе число: ");
}

double Calculator::get_number_from_input(const std::string& prompt)
{
    double number;
    while (true)
    {
        std::cout << prompt;
        if (!(std::cin >> number) || std::cin.peek() != '\n')
        {
            std::cout << "Некорректный ввод. Пожалуйста, введите числовое значение." << std::endl;
            clear_input();
        }
        else
        {
            break;
        }
    }
    return number;
}

Operation Calculator::get_operation_choice()
{
    int choice = 0;
    while (true)
    {
        std::cout << "Выберите действие, где:" << std::endl
                  << "1 - сложение" << std::endl
                  << "2 - вычитание" << std::endl
                  << "3 - умножение" << std::endl
                  << "4 - деление" << std::endl
                  << "Для завершения программы введите 'q'." << std::endl;

        std::string input;
        if (!(std::cin >> input))
        {
            std::cout << "Некорректный ввод выбора операции." << std::endl;
            clear_input();
        }
        else if (is_exit_symbol(input))
        {
            return Operation::Invalid;
        }
        else
        {
            if (input.size() == 1 && std::isdigit(input[0]))
            {
                choice = input[0] - '0';
                if (choice >= 1 && choice <= 4)
                    break;
            }
            std::cout << "Некорректный выбор операции. Пожалуйста, выберите операцию от 1 до 4." << std::endl;
        }
    }
    return static_cast<Operation>(choice);
}

void Calculator::calculate(const Operation& choice)
{
    switch (choice)
    {
        case Operation::Addition:
            std::cout << "Результат сложения: " << first_number_ + second_number_ << std::endl;
            break;
        case Operation::Subtraction:
            std::cout << "Результат вычитания: " << first_number_ - second_number_ << std::endl;
            break;
        case Operation::Multiplication:
            std::cout << "Результат умножения: " << first_number_ * second_number_ << std::endl;
            break;
        case Operation::Division:
            if (second_number_ == 0)
            {
                std::cout << "Делить на ноль нельзя!!!" << std::endl;
            }
            else
            {
                std::cout << "Результат деления: " << first_number_ / second_number_ << std::endl;
            }
            break;
        default:
            std::cout << "Некорректное значение." << std::endl;
            break;
    }
}

bool Calculator::ask_for_another_calculation()
{
    char answer;
    std::cout << "Хотите выполнить еще операцию? (y/n): ";
    while (!(std::cin >> answer) || (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N'))
    {
        std::cout << "Некорректный ввод. Пожалуйста, введите 'y' или 'n': ";
        clear_input();
    }
    return (answer == 'y' || answer == 'Y');
}

void Calculator::clear_input()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool Calculator::is_exit_symbol(const std::string& input)
{
    return (input == "q" || input == "Q");
}

