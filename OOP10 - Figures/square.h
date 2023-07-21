#pragma once
#include"shape.h"
#include"base-types.h"
class Square : public Shape { //���������� ����� �� Shape
private: //�������������� ��������
	Point_t corner;
	double length;
public:
	Square(double, double, double); 
	~Square() {};
	double getArea() override; //����� ���������� ������� 
	Rectangle_t getFrameRect() override; //����� ��������� ��������������� ��������������
	void move(Point_t) override; //����������� ������ ������ � ������������ �����
	void move(double, double) override; //����������� ������ ������ �������� �������� �� ���� ������� � �������
	void scale(double) override; //����� ��������������� ������
	void scale(double, double, double) override; //����� ����������� ���������������
	std::string getName() override; //��������� �������� ������
	Shape* clone(); //�������� ����� ������
};