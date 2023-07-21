#include <iostream>
int numberOfOnes(int numb) { //функция для подсчёта единиц в двоичной записи
    int count = 0; //счётчик единиц
    while (numb > 0) {
        if (numb % 2 == 1) //если очередной разряд двоичной записи даёт в остатке единицу, то счётчик увеличивается на 1
            count++;
        numb = numb / 2; //понижаем двоичный разряд
    }
    return count;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int number;
    std::cout << "Введите число: " << std::endl;
    std::cin >> number;
    if (std::cin.peek() != '\n' || number < 0) { // проверка на корректный ввод числа 
        std::cout << "Ошибка: введено некорректное число. Завершение программы.";
        return 0;
    }
    std::cout << "В двоичной записи числа содержится " << numberOfOnes(number) << " единиц(а/ы).";
    return 0;
}