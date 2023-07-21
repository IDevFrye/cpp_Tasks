#include <iostream>
#include <locale.h>
#include <fstream>
const char* ERROR_NOT_NUMBER = "Ошибка: введено не число. Завершение программы.";
const char* ERROR_NOT_POSITIVE_NUMBER = "Ошибка: введено не положительное число в качестве размера матрицы. Завершение программы.";
const char* ERROR_NOT_SQUARE_MATRIX = "Ошибка: заданные размеры не являются размерами квадратной матрицы. Завершение программы.";

int** sozdanie(int size1, int size2) { //выделение динамической памяти под массив
    int** A = new int* [size1];
    for (int i = 0; i < size1; i++) {
        A[i] = new int[size2];
    }
    return A;
}

bool inArray(int** A, int size1, int size2) { //ввод данных массива из файла и их проверка
    std::ifstream in("D:/Рабочий стол/in2.txt");
    while (in.get() != '\n') continue;
    bool flag = true;
    for (int i = 0; i < size1 && flag; i++) {
        for (int j = 0; j < size2 && flag; j++) {
            flag = true;
            in >> A[i][j];
            if (in.fail()) {
                flag = false;
            }
        }
    }
    return flag;
}

int maxOfMainDiagonal(int** A, int size1, int size2) { //функция определяет максимальную сумму из сумм элементов диагоналей, параллельных главной 
    int* ar = new int[2 * size1] {}; //создаём массив для сумм элементов каждой из диагоналей матрицы
    for (int i = 0; i < size1; i++)
        for (int j = 0; j < size2; j++)
            ar[i + j] += A[i][size1 - 1 - j]; //заполняем массив сумм элементов диагоналей
    int maxOfDiagonals = 0;
    for (int i = 1; i < size1 * 2 - 1; i++)
        if (ar[i] > ar[maxOfDiagonals]) //ищем максимальную сумму
            maxOfDiagonals = i;
    return ar[maxOfDiagonals];//возвращаем максимальную сумму элементов диагоналей
    delete[] ar;
}

void outArray(int** A, int s1, int s2) { //выводим массив и результат на консоль, в файл передаём результат
    std::ofstream out("D:/Рабочий стол/out2.txt");
    std::cout << "Введённый динамический массив из файла размером " << s1 << " на " << s2 << ": " << std::endl;
    for (int i = 0; i < s1; i++) {
        for (int j = 0; j < s2; j++) {
            std::cout << A[i][j] << " ";
        }
        std::cout << "\n";
    }
    out << "Максимум среди сумм элементов диагоналей, параллельных главной диагонали матрицы, равен: " << maxOfMainDiagonal(A, s1, s2);
}

int main() {
    setlocale(LC_ALL, "RUS");
    int row; int column;
    std::ifstream in("D:/Рабочий стол/in2.txt");
    try {
        in >> row;
        if (in.fail()) {
            throw ERROR_NOT_NUMBER;
        }
        if (row <= 0) {
            throw ERROR_NOT_POSITIVE_NUMBER;
        }
        in >> column;
        if (in.fail()) {
            throw ERROR_NOT_NUMBER;
        }
        if (column <= 0) {
            throw ERROR_NOT_POSITIVE_NUMBER;
        }
        if (column != row) {
            throw ERROR_NOT_SQUARE_MATRIX;
        }
        int** A;
        A = sozdanie(row, column); //выделяем динамическую память
        if (!inArray(A, row, column)) { //проверяем ввод элементов массива из файла на целочисленность
            throw ERROR_NOT_NUMBER;
        }
        int itog = maxOfMainDiagonal(A, row, column);
        outArray(A, row, column); //выводим массив и результат на консоль, в файл передаём результат
        std::cout << "Максимум среди сумм элементов диагоналей, параллельных главной диагонали матрицы, равен: " << maxOfMainDiagonal(A, row, column);
        for (int i = 0; i < row; i++) {
            delete[] A[i];
        }
        delete[] A;
    }
    catch (const char* error) {
        std::cerr << error << std::endl;
        return -1;
    }
}
