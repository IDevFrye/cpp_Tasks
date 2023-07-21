#include<iostream>
#include"square.h"
using namespace std;

Square::Square(double x, double y, double len) { //вычисление характеристик
	corner = { x,y };
	length = len;
}

double Square::getArea() { //метод вычисления площади 
	return length * length;
}
Rectangle_t Square::getFrameRect() { //метод получения ограничивающего прямоугольника
	Rectangle_t rec;
	rec.width = rec.height = length;
	rec.pos = {corner.x + length/2, corner.y + length/2};
	return rec;
}
void Square::move(Point_t newPoint1) { //перемещение центра фигуры в определенную точку
	corner = { newPoint1.x - length / 2, newPoint1.y - length / 2 };
}
void Square::move(double moveX, double moveY) { //перемещение центра фигуры согласно смещению по осяи абсцисс и ординат
	corner.x += moveX;
	corner.y += moveY;
}

void Square::scale(double n) { //метод масштабирования фигуры
	length *= n;
	corner = { this->getFrameRect().pos.x - length / 2, this->getFrameRect().pos.y - length / 2, };
}

void Square::scale(double x, double y, double n) { //метод изотропного масштабирования
	Point_t a1 = { this->getFrameRect().pos.x - length / 2, this->getFrameRect().pos.y - length / 2 };
	this->move({ x, y });
	Point_t a2 = { this->getFrameRect().pos.x - length / 2, this->getFrameRect().pos.y - length / 2 };
	double diffX = a1.x - a2.x;
	double diffY = a1.y - a2.y;
	this->scale(n);
	diffX *= n;
	diffY *= n;
	a2 = { x, y };
	this->move({ x + diffX, y + diffY });
}
string Square::getName() { //получение названия фигуры
	string name = "SQUARE";
	return name;
}
Shape* Square::clone() { //создание копии фигуры
	return new Square(*this);
}