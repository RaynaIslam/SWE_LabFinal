#include "pch.h"
#include <iostream>
using namespace std;
class Shape {
public:
	virtual double area() = 0;
};
class Circle :public Shape {
private:
	double radius;
public:
	Circle(double r):radius(r){}
	double area() override {
		return (3.14) * (3.14) * radius;
	}
};

class Square :public Shape {
private:
	double side;
public:
	Square(double a) :side(a) {}
	double area() override {
		return side*side;
	}

};

class Rectangle :public Shape {
private:
	double a,b;
public:
	Rectangle(double x,double y) {
		a = x;
		b = y;
	}
	double area() override {
		return a*b;
	}

};
class ShapeFactory{
public:
	static Shape* getCircle(double r) {
		return new Circle(r);
	}
	static Shape* getSquare(double r) {
		return new Square(r);
	}
	static Shape* getRectangle(double a,double b) {
		return new Rectangle(a,b);
	}

};

TEST(TestingShape, TestCircle) {
	Shape* s1 =  ShapeFactory::getCircle(3.0);

  EXPECT_EQ(s1->area(),29.5788);
 
}
TEST(TestingShape, TestSquare) {
	Shape* s2 =ShapeFactory::getSquare(2);
	EXPECT_EQ(s2->area(), 4);
}
TEST(TestingShape, TestRectangle) {
	Shape* s3 = ShapeFactory::getRectangle(3, 5);
	EXPECT_EQ(s3->area(), 15.0);
}