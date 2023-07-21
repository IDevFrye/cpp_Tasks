#include <iostream>

bool isContained(int numb, int dig) { //функция для поиска цифры в числе
    while (numb > 0) {
        if (numb % 10 == (dig)) //пробегаемся по каждой цифре и ищем совпадение
            return true;
        numb /= 10; //если не нашли, продолжаем искать в следующем разряде числа, если такой имеется
    }
    return false;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int number, digit;
    std::cout << "Введите число: " << std::endl;
    std::cin >> number;
    if (std::cin.peek() != '\n') { // проверка на корректный ввод числа 
        std::cout << "Ошибка: число задано некорректно. Завершение программы.";
        return 0;
    }
    std::cout << "Введите цифру для поиска в числе: " << std::endl;
    std::cin >> digit;
    if (std::cin.peek() != '\n' || digit > 9 || digit < 0) { // проверка на корректный ввод цифры
        std::cout << "Ошибка: цифра введена некорректно. Завершение программы.";
        return 0;
    }
    std::cout << "Результат поиска цифры в числе: " << isContained(number, digit); //выводим результат поиска, осуществлённого функцией
    return 0;
}