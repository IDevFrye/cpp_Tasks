#include"CompositeShape.h"
#include<string>
#include<limits>

CompositeShape::CompositeShape(int maxN) {
    maxCount = maxN; 
    factCount = 0;
    shapes_ = new Shape * [maxN];
}

CompositeShape::CompositeShape(const CompositeShape& shape) { //конструктор копирования
    maxCount = shape.maxCount;
    factCount = shape.factCount;
    shapes_ = shape.shapes_;
}

CompositeShape::CompositeShape(CompositeShape&& shape) noexcept { //конструктор перемещения
    maxCount = shape.maxCount;
    factCount = shape.factCount;
    shapes_ = shape.shapes_;
    shape.shapes_ = nullptr;
    shape.maxCount = shape.factCount = 0;
}

CompositeShape CompositeShape::operator=(const CompositeShape& shape) { //определение операторов = для копирования и для перпемещения
    CompositeShape cs(shape);
    return cs;
}

CompositeShape CompositeShape::operator=(CompositeShape&& shape) noexcept {
    CompositeShape cs((CompositeShape&&)shape);
    return cs;
}

int CompositeShape::getMaxCount() { //получение максимального количества
    return maxCount;
}

int CompositeShape::getFactCount() { //получение реального количества
    return factCount;
}

std::string CompositeShape::getName() { //получение названия 
    return "COMPOSITE SHAPE";
}

Rectangle_t CompositeShape::getFrameRect() { //метод получения ограничивающего прямоугольника
    Rectangle_t rec;
    double leftDownX = std::numeric_limits<double>::max(); 
    double leftDownY = std::numeric_limits<double>::max();
    double rightUpX = std::numeric_limits<double>::min();
    double rightUpY = std::numeric_limits<double>::min();
    double x1, y1, x2, y2;
    for (int i = 0; i < factCount; i++) {
        x1 = shapes_[i]->getFrameRect().pos.x - shapes_[i]->getFrameRect().width / 2; //нахождение углов относительно центра фигуры
        y1 = shapes_[i]->getFrameRect().pos.y - shapes_[i]->getFrameRect().height / 2;
        x2 = shapes_[i]->getFrameRect().pos.x + shapes_[i]->getFrameRect().width / 2;
        y2 = shapes_[i]->getFrameRect().pos.y + shapes_[i]->getFrameRect().height / 2;
        if (x1 < leftDownX) { //поиск точек с намиеньшей абсциссой и ординатой и с наибольшей соответственно
            leftDownX = x1;
        }
        if (y1 < leftDownY) {
            leftDownY = y1;
        }
        if (x2 > rightUpX) {
            rightUpX = x2;
        }
        if (y2 > rightUpY) {
            rightUpY = y2;
        }
    }
    rec.width = abs(rightUpX - leftDownX); //вычисление параметров составной фигуры
    rec.height = abs(rightUpY - leftDownY);
    rec.pos = { leftDownX + rec.width / 2, leftDownY + rec.height / 2 };
    return rec;
}

double CompositeShape::getArea() { //метод вычисления площади 
    double summ = 0;
    for (int i = 0; i < factCount; i++) {
        summ += shapes_[i]->getArea();
    }
    return summ;
}

void CompositeShape::move(Point_t point) { //перемещение центра фигуры в определенную точку
    double defPosX = this->getFrameRect().pos.x;
    double defPosY = this->getFrameRect().pos.y;
    for (int i = 0; i < factCount; i++) {
        shapes_[i]->move({ shapes_[i]->getFrameRect().pos.x - defPosX + point.x, shapes_[i]->getFrameRect().pos.y - defPosY + point.y });
    }
}

void CompositeShape::move(double moveX, double moveY) { //перемещение центра фигуры согласно смещению по осяи абсцисс и ординат
    for (int i = 0; i < factCount; i++) {
        shapes_[i]->move(moveX, moveY);
    }
}

void CompositeShape::scale(double n) { //метод масштабирования фигуры
    double defPosX = this->getFrameRect().pos.x;
    double defPosY = this->getFrameRect().pos.y;
    for (int i = 0; i < factCount; i++) {
        shapes_[i]->scale(defPosX,defPosY, n);
    }
}

void CompositeShape::scale(double x, double y, double k) {//метод изотропного масштабирования
    Point_t a1 = { this->getFrameRect().pos.x - this->getFrameRect().width / 2,
                  this->getFrameRect().pos.y - this->getFrameRect().height / 2 };
    this->move({ x, y });
    Point_t a2 = { this->getFrameRect().pos.x - this->getFrameRect().width / 2,
                  this->getFrameRect().pos.y - this->getFrameRect().height / 2 };
    double diffX = a1.x - a2.x;
    double diffY = a1.y - a2.y;
    this->scale(k);
    double deltaX = diffX * k;
    double deltaY = diffY * k;
    this->move({ x + deltaX, y + deltaY });
}

void CompositeShape::add(Shape* shape) { //метод добавления фигуры в массив
    if (factCount < maxCount) {
        shapes_[factCount] = shape->clone();
        factCount++;
    }
}

Shape* CompositeShape::clone() { //создание копии фигуры
    return new CompositeShape(*this);
}

Shape** CompositeShape::getShapes() { //получение фигур
    return shapes_;
}