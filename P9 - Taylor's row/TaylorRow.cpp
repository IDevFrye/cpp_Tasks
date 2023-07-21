#include <iostream>
#include <cmath>
#include <iomanip>

//const double LEFT = -1.0;
//const double RIGHT = 1.0;

double tailor(double absError, int numberMax, double x, double xl, double xr) {
    if (x >= xr || x <= xl) {
        throw std::exception ("Значение x находится вне заданного интервала");
    }
    int step = 1;
    double res = 1;
    double curEl = 1;
    double denominator = step;
    bool isMinus = true;
    while (std::abs(curEl) > absError) {
        step++;
        if (step > numberMax)
            throw std::exception ("Точность не достигнута");
        curEl = (curEl * x * x) / denominator;
        if (isMinus) res -= curEl;
        else res += curEl;
        denominator = step;
        isMinus = !isMinus;
    }
    return res;
}

int main() {
    setlocale(LC_ALL, "Russian");
    double xl;
    std::cout << "Введите левую границу интервала: ";
    std::cin >> xl;
    if (std::cin.fail()) {
        std::cout << "Неверно введено число. Завершение программы.";
        return -1;
    }
    if (xl < -1 || xl > 1) {
        std::cout << "Граница должна быть больше -1 и меньше 1. Завершение программы.";
        return 1;
    }
    double xr;
    std::cout << "Введите правую границу интервала: ";
    std::cin >> xr;
    if (!std::cin) {
        std::cout << "Неверно введено число. Завершение программы.";
        return -1;
    }
    if (xr < -1 || xr > 1) {
        std::cout << "Граница должна быть больше -1 и меньше 1. Завершение программы.";
        return 1;
    }
    double step;
    std::cout << "Введите шаг интервала: ";
    std::cin >> step;
    if (!std::cin || step <= 0) {
        std::cout << "Шаг должен быть положительным числом. Завершение программы.";
        return -1;
    }
    double absError = 0;
    std::cout << "Введите абсолютную погрешность: ";
    std::cin >> absError;
    if (!std::cin || absError <= 0) {
        std::cout << "Абсолютная погрешность должна быть положительным числом. Завершение программы.";
        return -1;
    }
    int numberMax = 0;
    std::cout << "Введите максимальное число слагаемых: ";
    std::cin >> numberMax;
    if (!std::cin || numberMax <= 0) {
        std::cout << "Максимальное число слагаемых должно быть целым положительным числом. Завершение программы.";
        return -1;
    }
    
    std::cout << std::setw(6) << "x" << '|' << std::setw(15) << "С++ result" << '|' << std::setw(15) << "Taylor Series" << std::endl;
    std::cout << std::setw(39) << "---------------------------------------" << std::endl;
    for (double x = xl + step; x <= xr/* - step*/; x += step) {
        if (std::abs(x) <= 1e-15) x = 0;
        double calcResult = exp(-(x*x));
        try {
            double tailorResult = tailor(absError, numberMax, x, xl, xr);
            /*if (abs(x - 1) < 1e-15) {
                std::cout << "Значение x находится вне заданного интервала, x = 1";
                break;
            }*/
            if ((x > -1) && (x < 1)) 
                std::cout << std::setw(6) << x << '|' << std::setw(15) << calcResult << '|' << std::setw(15) << tailorResult << std::endl;
        }
        catch (std::exception& msg)
        {
            std::cout << msg.what() << ", x = " << x << std::endl;
        }
    }
}
