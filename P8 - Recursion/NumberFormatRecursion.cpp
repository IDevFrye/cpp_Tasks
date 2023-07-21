#include <iostream>
#include <ctype.h>

bool isDigit(const char chr) {
    return ((chr >= '0') && (chr <= '9'));
}

bool isSign(const char chr) {
    return ((chr == '-') || (chr == '+'));
}

int isUnsignedInt(const char* str, int i) {
    if (str[i] == '.') {
        return i;
    }
    else if ((str[i + 1] == '.') || (str[i + 1] == 'E') || (str[i + 1] == 'e') || (str[i + 1] == '\0')) {
        return (i + 1);
    } 
    else if (!isDigit(str[i])) {
        return -1;
    }
    isUnsignedInt(str, ++i);
}

int isMantissa(const char* str, int i) {
    int dots = 0;
    int isUnsignedIntResult = isUnsignedInt(str, i);
    if (str[isUnsignedIntResult] == '.') dots++;
    if ((isUnsignedIntResult == -1) || (str[isUnsignedIntResult] == '\0')) {
        return -1;
    }
    else if ((str[isUnsignedIntResult] == 'E') || (str[isUnsignedIntResult] == 'e')) {
        if (dots == 1) return isUnsignedIntResult;
        return -1;
    }
    return(isUnsignedInt(str, isUnsignedIntResult + 1));
}

bool isOrder(const char* str, int i) {
    int isUnsignedIntResult = -1;
    if (str[i] == 'E') isUnsignedIntResult = isUnsignedInt(str, i + 2);
    else isUnsignedIntResult = isUnsignedInt(str, i + 1);
    if (isUnsignedIntResult == -1) return false;
    return (((str[i] == 'E') && (isSign(str[i + 1])) && (str[isUnsignedInt(str, i + 2)] == '\0')) || ((str[i] == 'e') && (!isSign(str[i + 1])) && (str[isUnsignedInt(str, i + 1)] == '\0')));
}

bool isReal(const char* str) {
    int isMantissaResult = isMantissa(str, 0);
    if (isMantissaResult == -1) return false;
    return(isOrder(str, isMantissaResult));
}

int main() {
    setlocale(LC_ALL, "RUS");
    const char* testTrue[7] = { "55.3453E-5", ".53e3", ".3E+12", "99.3e126", "12.345E-12", ".897e45", "1.1e2"};
    const char* testFalse[11] = { "5.4.1E-5", "53e3", ".3E12", "3.1e+12", ".3E-12.1", ".E-12", "1.2.56E-1", ".e24", "12.31e-6", ".45E2", "435345E+4"};
    for (int i = 0; i < 7; i++) {
        std::cout << "Вещественное число: " << testTrue[i] << "  " << "Соответствие: " << isReal(testTrue[i]) << std::endl;
    }
    for (int i = 0; i < 11; i++) {
        std::cout << "Вещественное число: " << testFalse[i] << "  " << "Соответствие: " << isReal(testFalse[i]) << std::endl;
    }
    return 0;
}