#pragma once
#include<iostream>
#include"base-types.h"
#include<string>
using namespace std;

class Shape {
public:
	friend ostream& operator<<(ostream& out, Shape& shape) { //перегрузка оператора вывода в необходимом для нас формате
		Rectangle_t rec = shape.getFrameRect();
		double x1 = rec.pos.x - rec.width / 2;
		double x2 = rec.pos.x + rec.width / 2;
		double y1 = rec.pos.y - rec.height / 2;
		double y2 = rec.pos.y + rec.height / 2;
		return out << shape.getName() << " " << round((shape.getArea()) * 10) / 10 << " (" << round(x1 * 10) / 10 << ";" << round(y1 * 10) / 10 <<
			") (" << round(x2 * 10) / 10 << ";" << round(y2 * 10) / 10 << ") ";
	}
	bool operator<(Shape& shape) { //перегрузка одного из операторов сравнения площадей фигур с булевым значением
		if (this->getArea() < shape.getArea()) {
			return true;
		}
		else {
			return false;
		}
	}
	virtual double getArea() = 0; //метод вычисления площади 
	virtual Rectangle_t getFrameRect() = 0; //метод получения ограничивающего прямоугольника
	virtual void move(Point_t) = 0; //перемещение центра фигуры в определенную точку
	virtual void move(double, double) = 0; //перемещение центра фигуры согласно смещению по осяи абсцисс и ординат
	virtual void scale(double) = 0; //метод масштабирования фигуры
	virtual void scale(double, double, double) = 0; //метод изотропного масштабирования
	virtual string getName() = 0; //получение названия фигуры
	virtual Shape* clone() = 0; //создание копии фигуры
};
