#pragma once
#include"shape.h"
#include"base-types.h"
#include<string>

class CompositeShape : public Shape { //����������� ����� �� Shape
private: //�������� ������������� ��������� ������
    int maxCount;  //������������ �����
    int factCount; //����������� �����
    Shape** shapes_; //������ ���������� 
public:
    CompositeShape(int);
    CompositeShape(const CompositeShape&); //����������� �����������
    CompositeShape(CompositeShape&&) noexcept; //����������� �����������
    CompositeShape operator=(const CompositeShape&); //����������� ���������� = ��� ����������� � ��� ������������
    CompositeShape operator=(CompositeShape&&) noexcept;
    ~CompositeShape() {};
    int getMaxCount(); //��������� ������������� ����������
    int getFactCount(); //��������� ��������� ����������
    Shape** getShapes(); //��������� �����
    std::string getName() override; //��������� �������� 
    Rectangle_t getFrameRect() override; //����� ��������� ��������������� ��������������
    double getArea() override; //����� ���������� ������� 
    void move(Point_t) override; //����������� ������ ������ � ������������ �����
    void move(double, double) override; //����������� ������ ������ �������� �������� �� ���� ������� � �������
    void scale(double) override; //����� ��������������� ������
    void scale(double, double, double) override; //����� ����������� ���������������
    void add(Shape*); //����� ���������� ������ � ������
    Shape* clone() override;  //�������� ����� ������
};

