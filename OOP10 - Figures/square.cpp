#include<iostream>
#include"square.h"
using namespace std;

Square::Square(double x, double y, double len) { //���������� �������������
	corner = { x,y };
	length = len;
}

double Square::getArea() { //����� ���������� ������� 
	return length * length;
}
Rectangle_t Square::getFrameRect() { //����� ��������� ��������������� ��������������
	Rectangle_t rec;
	rec.width = rec.height = length;
	rec.pos = {corner.x + length/2, corner.y + length/2};
	return rec;
}
void Square::move(Point_t newPoint1) { //����������� ������ ������ � ������������ �����
	corner = { newPoint1.x - length / 2, newPoint1.y - length / 2 };
}
void Square::move(double moveX, double moveY) { //����������� ������ ������ �������� �������� �� ���� ������� � �������
	corner.x += moveX;
	corner.y += moveY;
}

void Square::scale(double n) { //����� ��������������� ������
	length *= n;
	corner = { this->getFrameRect().pos.x - length / 2, this->getFrameRect().pos.y - length / 2, };
}

void Square::scale(double x, double y, double n) { //����� ����������� ���������������
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
string Square::getName() { //��������� �������� ������
	string name = "SQUARE";
	return name;
}
Shape* Square::clone() { //�������� ����� ������
	return new Square(*this);
}