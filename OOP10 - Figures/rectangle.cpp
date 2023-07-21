#include<iostream>
#include"rectangle.h"
using namespace std;

Rectangle::Rectangle(double x1, double y1, double x2, double y2) { //вычисление характеристик
	width = abs(x2 - x1);
	height = abs(y2 - y1);
	point1 = { x1, y1 };
	point2 = { x2, y2 };
}

double Rectangle::getArea() { //метод вычисления площади 
	return width * height;
}
Rectangle_t Rectangle::getFrameRect() { //метод получения ограничивающего прямоугольника
	Point_t pos = { (point1.x + point2.x) / 2, (point1.y + point2.y) / 2 };
	Rectangle_t rect = { width, height, pos };
	return rect;
}
void Rectangle::move(Point_t newPoint1) { //перемещение центра фигуры в определенную точку
	point1 = { newPoint1.x - width / 2, newPoint1.y - height / 2 };
	point2 = { newPoint1.x + width / 2, newPoint1.y + height / 2 };
}
void Rectangle::move(double moveX, double moveY) { //перемещение центра фигуры согласно смещению по осяи абсцисс и ординат
	point1.x += moveX;
	point1.y += moveY;
	point2.x += moveX;
	point2.y += moveY;
}

void Rectangle::scale(double n) { //метод масштабирования фигуры
	width *= n;
	height *= n;
	point1 = { this->getFrameRect().pos.x - width / 2, this->getFrameRect().pos.y - height / 2 };
	point2 = { this->getFrameRect().pos.x + width / 2, this->getFrameRect().pos.y + height / 2 };
}

void Rectangle::scale(double x, double y, double n) { //метод изотропного масштабирования
	Point_t a1 = { this->getFrameRect().pos.x - width / 2, this->getFrameRect().pos.y - height / 2 };
	this->move({ x, y });
	Point_t a2 = { this->getFrameRect().pos.x - width / 2, this->getFrameRect().pos.y - height / 2 };
	double diffX = a1.x - a2.x;
	double diffY = a1.y - a2.y;
	this->scale(n);
	diffX *= n;
	diffY *= n;
	a2 = { x, y };
	this->move({ x + diffX, y + diffY });
}

string Rectangle::getName() { //получение названия фигуры
	string name = "RECTANGLE";
	return name;
}
Shape* Rectangle::clone() { //создание копии фигуры
	return new Rectangle(*this);
}
