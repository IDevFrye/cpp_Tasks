#include <iostream>
bool isPalindrom(int numb) { //функция для проверки на то, является ли число палиндромом
    long long binNumb = 0; //двоичная запись числа
    long long d = 1; //число разряда
    int leng = 0; //длина двоичной записи
    while (numb > 0) {
        binNumb += (numb % 2) * d; //добавлем остаток от деления на два, перемноженный на текущий разряд
        leng++;
        numb = numb / 2; //понижаем разряд числа
        d = d * 10; //повышаем разряд для двоичной записи
    }
    long long binNumb_temp = binNumb;
    int revBinNumb = 0; //Число перевернутое
    while (binNumb_temp != 0) {
        revBinNumb = revBinNumb * 10 + binNumb_temp % 10; //Переворачиваем число по цифрам
        binNumb_temp /= 10; //Отбрасываем последнюю цифру
    }
    return (binNumb == revBinNumb); //возвращаем истинность выражения
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
    std::cout << "Результат проверки на палиндром: " << isPalindrom(number);
    return 0;
}
