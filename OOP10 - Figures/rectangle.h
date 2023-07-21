#pragma once
#include"shape.h"
#include"base-types.h"

class Rectangle : public Shape { //����������� ����� �� Shape
private: //�������������� ��������������
	double width;
	double height;
	Point_t point1;
	Point_t point2;
public:
	Rectangle(double, double, double, double);
	~Rectangle() {};
	double getArea() override; //����� ���������� ������� 
	Rectangle_t getFrameRect() override; //����� ��������� ��������������� ��������������
	void move(Point_t) override; //����������� ������ ������ � ������������ �����
	void move(double, double) override; //����������� ������ ������ �������� �������� �� ���� ������� � �������
	void scale(double) override; //����� ��������������� ������
	void scale(double, double, double) override; //����� ����������� ���������������
	std::string getName() override; //��������� �������� ������
	Shape* clone() override; //�������� ����� ������
};