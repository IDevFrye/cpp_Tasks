#include <iostream>
#include <locale.h>
#include <fstream>
const int ROW = 3;
const int COLUMN = 3;
const char* ERROR_NOT_NUMBER = "Ошибка: введено не число. Завершение программы.";

bool inArray(int A[ROW][COLUMN]) { //ввод данных массива из входного файла и их проверка
    std::ifstream in("D:/Рабочий стол/in1.txt");
    bool flag = true;
    for (int i = 0; i < ROW && flag; i++) {
        for (int j = 0; j < COLUMN && flag; j++) {
            flag = true;
            in >> A[i][j];
            if (in.fail()) {
                flag = false;
            }
        }
    }
    return flag;
}

int numberOfRowsOrdered(const int A[ROW][COLUMN], const int size1, const int size2) { //функция, определяющая количество строк с возрастающим рядом
    bool flag = true;
    int count = 0;
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2-1; j++) {
            if (A[i][j] > A[i][j + 1]) flag = false;
        }
        if (flag) count++;
        flag = true;
    }
    return count; //возвращаем количество строк, удовлетворяющих условию
}

void outArray(int A[ROW][COLUMN]) { //выводим массив и результат на консоль, в файл передаём результат
    std::cout << "Полученный встроенный массив: " << std::endl;
    std::ofstream out("D:/Рабочий стол/out1.txt");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            std::cout << A[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    out << "Количество строк, элементы которых упорядочены по возрастанию элементов, равно: " << numberOfRowsOrdered(A, ROW, COLUMN);
}

int main() {
    try {
        setlocale(LC_ALL, "RUS");
        int A[ROW][COLUMN]; //встроенный массив с константной размерностью (в данном случае 3*3)
        if (!inArray(A)) { //проверяем ввод элементов массива на целочисленность
            throw ERROR_NOT_NUMBER;
        }
        outArray(A); //выводим массив и результат на консоль, в файл передаём результат
        std::cout << "Количество строк, элементы которых упорядочены по возрастанию элементов, равно: " << numberOfRowsOrdered(A, ROW, COLUMN);
    }
    catch (const char* error) {
        std::cerr << error << std::endl;
        return -1;
    }
}
