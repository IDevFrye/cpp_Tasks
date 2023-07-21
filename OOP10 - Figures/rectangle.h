#pragma once
#include"shape.h"
#include"base-types.h"

class Rectangle : public Shape { //производный класс от Shape
private: //характеристики прямоугольника
	double width;
	double height;
	Point_t point1;
	Point_t point2;
public:
	Rectangle(double, double, double, double);
	~Rectangle() {};
	double getArea() override; //метод вычисления площади 
	Rectangle_t getFrameRect() override; //метод получения ограничивающего прямоугольника
	void move(Point_t) override; //перемещение центра фигуры в определенную точку
	void move(double, double) override; //перемещение центра фигуры согласно смещению по осяи абсцисс и ординат
	void scale(double) override; //метод масштабирования фигуры
	void scale(double, double, double) override; //метод изотропного масштабирования
	std::string getName() override; //получение названия фигуры
	Shape* clone() override; //создание копии фигуры
};