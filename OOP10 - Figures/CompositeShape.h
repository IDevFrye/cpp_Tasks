#pragma once
#include"shape.h"
#include"base-types.h"
#include<string>

class CompositeShape : public Shape { //производный класс от Shape
private: //описание характеристик составной фигуры
    int maxCount;  //максимальное число
    int factCount; //фактическое число
    Shape** shapes_; //массив указателей 
public:
    CompositeShape(int);
    CompositeShape(const CompositeShape&); //конструктор копирования
    CompositeShape(CompositeShape&&) noexcept; //конструктор перемещения
    CompositeShape operator=(const CompositeShape&); //определение операторов = для копирования и для перпемещения
    CompositeShape operator=(CompositeShape&&) noexcept;
    ~CompositeShape() {};
    int getMaxCount(); //получение максимального количества
    int getFactCount(); //получение реального количества
    Shape** getShapes(); //получение фигур
    std::string getName() override; //получение названия 
    Rectangle_t getFrameRect() override; //метод получения ограничивающего прямоугольника
    double getArea() override; //метод вычисления площади 
    void move(Point_t) override; //перемещение центра фигуры в определенную точку
    void move(double, double) override; //перемещение центра фигуры согласно смещению по осяи абсцисс и ординат
    void scale(double) override; //метод масштабирования фигуры
    void scale(double, double, double) override; //метод изотропного масштабирования
    void add(Shape*); //метод добавления фигуры в массив
    Shape* clone() override;  //создание копии фигуры
};

