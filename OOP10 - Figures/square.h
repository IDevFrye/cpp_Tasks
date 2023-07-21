#pragma once
#include"shape.h"
#include"base-types.h"
class Square : public Shape { //прозводный класс от Shape
private: //характеристики квадрата
	Point_t corner;
	double length;
public:
	Square(double, double, double); 
	~Square() {};
	double getArea() override; //метод вычисления площади 
	Rectangle_t getFrameRect() override; //метод получения ограничивающего прямоугольника
	void move(Point_t) override; //перемещение центра фигуры в определенную точку
	void move(double, double) override; //перемещение центра фигуры согласно смещению по осяи абсцисс и ординат
	void scale(double) override; //метод масштабирования фигуры
	void scale(double, double, double) override; //метод изотропного масштабирования
	std::string getName() override; //получение названия фигуры
	Shape* clone(); //создание копии фигуры
};