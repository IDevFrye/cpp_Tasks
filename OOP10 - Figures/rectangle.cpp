#include<iostream>
#include"rectangle.h"
using namespace std;

Rectangle::Rectangle(double x1, double y1, double x2, double y2) { //���������� �������������
	width = abs(x2 - x1);
	height = abs(y2 - y1);
	point1 = { x1, y1 };
	point2 = { x2, y2 };
}

double Rectangle::getArea() { //����� ���������� ������� 
	return width * height;
}
Rectangle_t Rectangle::getFrameRect() { //����� ��������� ��������������� ��������������
	Point_t pos = { (point1.x + point2.x) / 2, (point1.y + point2.y) / 2 };
	Rectangle_t rect = { width, height, pos };
	return rect;
}
void Rectangle::move(Point_t newPoint1) { //����������� ������ ������ � ������������ �����
	point1 = { newPoint1.x - width / 2, newPoint1.y - height / 2 };
	point2 = { newPoint1.x + width / 2, newPoint1.y + height / 2 };
}
void Rectangle::move(double moveX, double moveY) { //����������� ������ ������ �������� �������� �� ���� ������� � �������
	point1.x += moveX;
	point1.y += moveY;
	point2.x += moveX;
	point2.y += moveY;
}

void Rectangle::scale(double n) { //����� ��������������� ������
	width *= n;
	height *= n;
	point1 = { this->getFrameRect().pos.x - width / 2, this->getFrameRect().pos.y - height / 2 };
	point2 = { this->getFrameRect().pos.x + width / 2, this->getFrameRect().pos.y + height / 2 };
}

void Rectangle::scale(double x, double y, double n) { //����� ����������� ���������������
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

string Rectangle::getName() { //��������� �������� ������
	string name = "RECTANGLE";
	return name;
}
Shape* Rectangle::clone() { //�������� ����� ������
	return new Rectangle(*this);
}
