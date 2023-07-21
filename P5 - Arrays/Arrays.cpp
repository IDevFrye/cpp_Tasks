#include <iostream>
#include <locale.h>
#include <ctime>
#include <fstream>

int countOfFullDiv(int* arr, int s, int n) {
	int count = 0;
	for (int i = 0; i < s; i++) {
		if (arr[i] % abs(n) == 0)
			count++;
	}
	return count;
}

int main() {
	setlocale(LC_ALL, "RUS");
	const int SIZE = 7;
	int number;
	int arr[SIZE] = {1, 2, 9, 12, 4, 6, 77};
	std::cout << "Cтатический массив: ";
	for (int i = 0; i < SIZE; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Введите число: ";
	std::cin >> number;
	if ((std::cin.peek() != '\n') || (number == 0)) {
		std::cout << "Некорректный ввод числа. Завершение программы.";
		return 0;
	}
	std::cout << "Количество элементов массива, делящихся без остатка на заданное число: " << countOfFullDiv(arr, SIZE, number) << std::endl;
	return 0;

}

int main() {
	setlocale(LC_ALL, "RUS");
	srand(time(0));
	int size = 0;
	int number;
	std::cout << "Введите число: ";
	std::cin >> number;
	if ((std::cin.peek() != '\n') || (number == 0)) {
		std::cout << "Некорректный ввод числа. Завершение программы.";
		return 0;
	}
	std::cout << "Введите количество элементов массива: ";
	std::cin >> size;
	if (std::cin.peek() != '\n') {
		std::cout << "Некорректный ввод количества элементов массива. Размер массива должен быть задан целым числом. Завершение программы.";
		return 0;
	}
	else if (size <= 0) {
		std::cout << "Размер массива должен быть больше нуля. Завершение программы.";
		return 0;
	}
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100;
	}
	std::cout << "Динамический массив из случайных чисел: ";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Количество элементов массива, делящихся без остатка на заданное число: " << countOfFullDiv(arr, size, number) << std::endl;
	delete[] arr;
	return 0;
}

int main()
{
	setlocale(LC_ALL, "ru");
	std::ifstream file;
	file.open("D:/Рабочий стол/file1.txt");
	int size = 0;
	int number;
	std::cout << "Введите число: ";
	std::cin >> number;
	if ((std::cin.peek() != '\n') || (number == 0)) {
		std::cout << "Некорректный ввод числа. Завершение программы.";
		return 0;
	}
	while (!file.eof()) {
		file >> size;
		if (file.fail()) {
			std::cout << "Значение из файла не является целым числом. Завершение программы.";
			return 0;
		}
		else if (size <= 0) {
			std::cout << "Размер массива должен быть больше нуля. Завершение программы.";
			return 0;
		}
		std::cout << "Массив из файла: " << std::endl;
		int* arr = new int[size];
		for (int i = 0; i < size; i++) {
			file >> arr[i];
			if (file.fail()) {
				std::cout << "Элементами массива должны быть целые числа. Завершение программы.";
				return 0;
			}
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "Количество элементов массива, делящихся без остатка на заданное число: " << countOfFullDiv(arr, size, number) << std::endl;
		delete[] arr;
	}
	file.close();
	return 0;
}
