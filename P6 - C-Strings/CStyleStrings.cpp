#include <iostream>
#include <locale.h>
#include <fstream>
#include <cctype>
const int NUMB_OF_LETTERS = 26;
const char* ERROR_NOT_NUMBER = "Ошибка: введено не число. Завершение программы.";
const char* ERROR_NOT_POSITIVE_NUMBER = "Ошибка: введено не положительное число. Завершение программы.";

char* function(char* destination, const char* source) {
	int curr_el = 0;
	int dop_el = 0;
	int alph_n[NUMB_OF_LETTERS] = {0};
	while (source[curr_el] != '\0') {
		if (isalpha(tolower(source[curr_el]))) {
			alph_n[int(tolower(source[curr_el])) - 'a']++;
		}
		curr_el++;
	}
	for (int j = 0; j < NUMB_OF_LETTERS; j++) {
		if (alph_n[j] == 0) {
			destination[dop_el] = char(j + 'a');
			dop_el++;
		}
	}
	return destination;
}

int main() {
	setlocale(LC_ALL, "RUS");
	std::ifstream in("D:/Рабочий стол/in.txt");
	std::ofstream out("D:/Рабочий стол/out.txt");
	int max_length;
	while (!in.eof()) {
		try {
			in >> max_length;
			if (in.fail() || in.peek() != '\n') {
				throw ERROR_NOT_NUMBER;
			}
			if (max_length <= 0) {
				throw ERROR_NOT_POSITIVE_NUMBER;
			}
			std::cout << "Успешный ввод." << std::endl;
		}
		catch (const char* error) {
			std::cerr << error << std::endl;
			return -1;
		}
		while (in.get() != '\n') continue;
		char* first_string = new char[max_length + 1];
		in.getline(first_string, max_length + 1);
		first_string[max_length] = '\0';
		int i = 0;
		std::cout << "Исходная строка: ";
		while (first_string[i] != '\0') {
			std::cout << first_string[i];
			i++;
		}
		std::cout << std::endl;
		int alph[NUMB_OF_LETTERS] = {};
		int count = 0;
		for (int i = 0; first_string[i] != '\0'; i++) {
			if (isalpha(tolower(first_string[i]))) {
				if (alph[int(tolower(first_string[i])) - 'a'] == 0) count++;
				if (isalpha(tolower(first_string[i]))) {
					alph[int(tolower(first_string[i])) - 'a']++;
				}
			}
		}
		char* new_string = new char[NUMB_OF_LETTERS + 1 - count];
		new_string[NUMB_OF_LETTERS - count] = '\0';
		out << function(new_string, first_string) << std::endl;
		std::cout << "Новая строка: " << new_string << std::endl;
		delete[] first_string;
		delete[] new_string;
	}
	return 0;
}





