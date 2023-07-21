﻿#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    int x1, x2, y1, y2;
    std::cout << "Введите координату x1: " << std::endl;
    std::cin >> x1; // вводим координату x1
    if (std::cin.fail()) { // проверка на то, что x1 является числом
        std::cout << "Координаты должны быть заданы числами, завершение программы." << std::endl;
        return 0;
    }
    if (not(x1 > 0)) { // проверка на ввод x1
        std::cout << "Координаты должны быть заданы положительными числами, завершение программы." << std::endl;
        return 0;
    }
    if (x1 > 8) { // проверка на соответствие размерам доски
        std::cout << "Координаты должны быть заданы числами от 1 до 8 (размерность шахматной доски), завершение программы." << std::endl;
        return 0;
    }
    std::cout << "Введите координату y1: " << std::endl;
    std::cin >> y1; // вводим координату y1
    if (std::cin.fail()) { // проверка на то, что y1 является числом
        std::cout << "Координаты должны быть заданы числами, завершение программы." << std::endl;
        return 0;
    }
    if (not(y1 > 0)) { // проверка на ввод y1
        std::cout << "Координаты должны быть заданы положительными числами, завершение программы." << std::endl;
        return 0;
    }
    if (y1 > 8) { // проверка на соответствие размерам доски
        std::cout << "Координаты должны быть заданы числами от 1 до 8 (размерность шахматной доски), завершение программы." << std::endl;
        return 0;
    }
    std::cout << "Введите координату x2: " << std::endl;
    std::cin >> x2; // вводим координату x2
    if (std::cin.fail()) { // проверка на то, что x2 является числом
        std::cout << "Координаты должны быть заданы числами, завершение программы." << std::endl;
        return 0;
    }
    if (not(x2 > 0)) { // проверка на ввод x2
        std::cout << "Координаты должны быть заданы положительными числами, завершение программы." << std::endl;
        return 0;
    }
    if (x2 > 8) { // проверка на соответствие размерам доски
        std::cout << "Координаты должны быть заданы числами от 1 до 8 (размерность шахматной доски), завершение программы." << std::endl;
        return 0;
    }
    std::cout << "Введите координату y2: " << std::endl;
    std::cin >> y2; // вводим координату y2
    if (std::cin.fail()) { // проверка на то, что y2 является числом
        std::cout << "Координаты должны быть заданы числами, завершение программы." << std::endl;
        return 0;
    }
    if (not(y2 > 0)) { // проверка на ввод y2
        std::cout << "Координаты должны быть заданы положительными числами, завершение программы." << std::endl;
        return 0;
    }
    if (y2 > 8) { // проверка на соответствие размерам доски
        std::cout << "Координаты должны быть заданы числами от 1 до 8 (размерность шахматной доски), завершение программы." << std::endl;
        return 0;
    }
    if ((x1 == x2) && (y1 == y2)) { // проверка на различность клеток
        std::cout << "Координаты клеток должны быть различными, завершение программы." << std::endl;
        return 0;
    }
    if (((abs(x1 - x2) == 1) && (abs(y1 - y2) == 2)) || ((abs(x1 - x2) == 2) && (abs(y1 - y2) == 1))) { // исключаем случаи с одинаковом столбцом или строчкой
        std::cout << "Истина. Конь способен переместиться заданным образом и побить фигуру, стоящую там, завершение программы." << std::endl;
        return 0;
    }
    else {
        std::cout << "Ложь. Конь не способен переместиться заданным образом, завершение программы." << std::endl;
        return 0;
    }
}
