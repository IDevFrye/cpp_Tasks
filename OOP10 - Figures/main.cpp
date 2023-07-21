#include<iostream>
#include<fstream>
#include"shape.h"
#include"rectangle.h"
#include"square.h"
#include"base-types.h"
#include"CompositeShape.h"
#include<string>
using namespace std;

void sortShapes(Shape** figures, int size) { //сортировка фигур
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (*figures[j + 1] < *figures[j]) {
				swap(figures[j], figures[j + 1]);
			}
		}
	}
}

void printShapes(Shape** shapes, int size) { //вывод фигур
	for (int i = 0; i < size; i++) {
		cout << *shapes[i] << endl;
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	ifstream in("D:/Рабочий стол/in.txt");
	if (in.is_open()) {
		int countOfStrings = 0;
		char* str = new char[1024];
		while (!in.eof()) {
			in.getline(str, 1024, '\n');
			if (!(string(str).empty())) {
				countOfStrings++;
			}
		}
		delete[] str;
		in.clear();
		in.seekg(0, ios::beg);
		Shape** figures = new Shape * [countOfStrings];
		string nameOfShape;
		bool firstCommand = true;
		int n = 0;
		while (!in.eof()) {
			in >> nameOfShape;
			if (nameOfShape == "RECTANGLE") { //обработка прямоугольника
				double x1, y1, x2, y2;
				in >> x1;
				in >> y1;
				in >> x2;
				in >> y2;
				Rectangle rect(x1, y1, x2, y2);
				figures[n] = rect.clone();
				n++;
			}
			else if (nameOfShape == "SQUARE") { //обработка квадрата
				double x1, y1, len;
				in >> x1;
				in >> y1;
				in >> len;
				if (len > 0) {
					Square sq(x1, y1, len);
					figures[n] = sq.clone();
					n++;
				}
				else {
					cout << "Длина стороны квадрата должна быть положительной." << endl;
				}
			}
			else if (nameOfShape == "COMPLEX") { //обработка составной фигуры
				int maxN, realN;
				in >> maxN;
				if (maxN <= 0) {
					cout << "Максимальное кол-во фигур в составной фигуре должно быть положительным." << endl;
					while (nameOfShape != "COMPLEXEND") {
						in >> nameOfShape;
					}
				}
				else {
					realN = 0;
					CompositeShape cs(maxN);
					while (true) {
						in >> nameOfShape;
						if (nameOfShape == "RECTANGLE") {
							double x1, y1, x2, y2;
							in >> x1;
							in >> y1;
							in >> x2;
							in >> y2;
							Rectangle rect(x1, y1, x2, y2);
							cs.add(rect.clone());
							realN++;
						}
						else if (nameOfShape == "SQUARE") {
							double x1, y1, len;
							in >> x1;
							in >> y1;
							in >> len;
							if (len > 0) {
								Square sq(x1, y1, len);
								cs.add(sq.clone());
								realN++;
							}
							else {
								cout << "Длина стороны квадрата должна быть положительной." << endl;
							}
						}
						else if (nameOfShape == "COMPLEXEND") {
							break;
						}
						if (realN == maxN) {
							in >> nameOfShape;
							if (nameOfShape == "COMPLEXEND") {
								break;
							}
							else {
								cout << "Достигнуто максимальное количество фигур составной фигуры, остальные значения не будут записаны." << endl;
								while (nameOfShape != "COMPLEXEND") {
									in >> nameOfShape;
								}
								break;
							}
						}
					}
					figures[n] = cs.clone();
					n++;
				}
			}
			else if (nameOfShape == "MOVE") { //обработка команды MOVE
				if (firstCommand) {
					sortShapes(figures, n);
					cout << endl << "Отсортированные фигуры до комманд:" << endl;
					printShapes(figures, n);
					cout << endl;
					firstCommand = false;
				}
				double x, y;
				in >> x;
				in >> y;
				for (int j = 0; j < n; j++) {
					figures[j]->move(x, y);
				}
				cout << endl << "Отсортированные фигуры после комманды MOVE (" << x << ", " << y << "): " << endl;
				sortShapes(figures, n);
				printShapes(figures, n);
			}
			else if (nameOfShape == "SCALE") { //обработка команды SCALE
				if (firstCommand) {
					sortShapes(figures, n);
					cout << endl << "Отсортированные фигуры до комманд:" << endl;
					printShapes(figures, n);
					firstCommand = false;
				}
				double x, y, k;
				in >> x;
				in >> y;
				in >> k;
				if (k > 0) {
					for (int j = 0; j < n; j++) {
						figures[j]->scale(x, y, k);
					}
				} 
				else {
					cout << endl << "Коэффициент масштабирования должен быть задан положительным числом." << endl;
				}
				cout << endl << "Отсортированные фигуры после комманды SCALE (" << x << ", " << y << ", " << k << "): " << endl;
				sortShapes(figures, n);
				printShapes(figures, n);
			}
			else {
				while (in.get() != '\n') continue;
			}
		}
	}
	else {
	cout << "Файл не был открыт. Первая часть программы не была завершена успешно." << endl;
	}

	cout << endl << "----------------------" << endl << "COMPOSITE SHAPE TEST |" << endl << "----------------------" << endl;
	CompositeShape testShape(3); // тест 
	Rectangle r1(1, 2, 3, 4);
	Rectangle r2(5, 6, 7, 8);
	Square s1(-2, -3, 3);
	testShape.add(r1.clone());
	testShape.add(r2.clone());
	testShape.add(s1.clone());
	cout << "testShape: " << testShape << " состоит из:" << endl;
	printShapes(testShape.getShapes(), 3);
	cout << "Максимальное значение = " << testShape.getMaxCount() << endl << "Фактическое значение = " << testShape.getFactCount() << endl;
	cout << "testShape.getShapes() = " << testShape.getShapes() << endl;
	cout << endl;

	cout << "-------------------------" << endl << "Конструктор копирования |" << endl << "-------------------------" << endl;
	CompositeShape testShapeCopy(testShape);
	cout << "testShapeCopy: " << testShapeCopy << " включает в себя:" << endl;
	printShapes(testShapeCopy.getShapes(), 3);
	cout << "Максимальное значение = " << testShape.getMaxCount() << endl << "Фактическое значение = " << testShape.getFactCount() << endl;
	cout << "testShapeCopy.getShapes() = " << testShapeCopy.getShapes() << endl;
	cout << endl;

	cout << "-------------------------" << endl << "Конструктор перемещения |" << endl << "-------------------------" << endl;
	CompositeShape testShapeNew((CompositeShape&&)testShape);
	cout << "testShapeNew: " << testShapeNew << " включает в себя:" << endl;
	printShapes(testShapeNew.getShapes(), 3);
	cout << "Максимальное значение = " << testShapeNew.getMaxCount() << endl << "Фактическое значение = " << testShapeNew.getFactCount() << endl;
	cout << "testShapeNew.getShapes() = " << testShapeNew.getShapes() << endl;
	cout << endl;

	cout << "-------------------------------" << endl << "Проверка на очистку testShape |" << endl << "-------------------------------" << endl;
	cout << "Максимальное значение = " << testShape.getMaxCount() << endl << "Фактическое значение = " << testShape.getFactCount() << endl;
	cout << "testShape.getShapes() = " << testShape.getShapes() << endl;
	cout << endl;

	cout << endl << "------------------------" << endl << "COMPOSITE SHAPE TEST 2 |" << endl << "------------------------" << endl;
	CompositeShape testShape2(3);
	Rectangle r11(9, 8, 7, 6);
	Square s11(5, 4, 3);
	Square s21(2, 1, 4);
	testShape2.add(r11.clone());
	testShape2.add(s11.clone());
	testShape2.add(s21.clone());
	cout << "testShape2: " << testShape2 << " включает в себя:" << endl;
	printShapes(testShape2.getShapes(), 3);
	cout << "Максимальное значение = " << testShape2.getMaxCount() << endl << "Фактическое значение = " << testShape2.getFactCount() << endl;
	cout << "testShape2.getShapes() = " << testShape2.getShapes() << endl;
	cout << endl;

	cout << "----------------------" << endl << "Оператор копирования |" << endl << "----------------------" << endl;
	CompositeShape testShape2Copy = testShape2;
	cout << "testShape2: " << testShape2Copy << " включает в себя:" << endl;
	printShapes(testShape2Copy.getShapes(), 3);
	cout << "Максимальное значение = " << testShape2.getMaxCount() << endl << "Фактическое значение = " << testShape2.getFactCount() << endl;
	cout << "testShape2Copy.getShapes() = " << testShape2Copy.getShapes() << endl;
	cout << endl;

	cout << "----------------------" << endl << "Оператор перемещения |" << endl << "----------------------" << endl;
	CompositeShape testShape2New = (CompositeShape&&)testShape2;
	cout << "testShape2New: " << testShape2New << " включает в себя:" << endl;
	printShapes(testShape2New.getShapes(), 3);
	cout << "Максимальное значение = " << testShape2New.getMaxCount() << endl << "Фактическое значение = " << testShape2New.getFactCount() << endl;
	cout << "testShape2New.getShapes() = " << testShape2New.getShapes() << endl;
	cout << endl;

	cout << "--------------------------------" << endl << "Проверка на очистку testShape2 |" << endl << "-------------------------------" << endl;
	cout << "Максимальное значение = " << testShape2.getMaxCount() << endl << "Фактическое значение = " << testShape2.getFactCount() << endl;
	cout << "testShape2.getShapes() = " << testShape2.getShapes() << endl;
	cout << endl;

	return 0;
}

