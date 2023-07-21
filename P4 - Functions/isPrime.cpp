#include <iostream>
bool isPrime(int numb) { //функция для проверки на то, является ли число простым 
    if (numb == 1) //числа, меньшие или равные единице не являются простыми
        return false;
    for (int i = 2; i <= sqrt(numb); i++)//проходим по делителям от 2 до корня из числа
        if (numb % i == 0)
            return false;
    return true;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int number;
    std::cout << "Введите число: " << std::endl;
    std::cin >> number;
    if (std::cin.peek() != '\n' || number < 1) { // проверка на корректный ввод числа 
        std::cout << "Ошибка: введено некорректное число. Завершение программы.";
        return 0;
    }
    std::cout << "Результат проверки на простоту числа: " << isPrime(number);
    return 0;
}
