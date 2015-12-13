#pragma once
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
class Point {
protected:
	vector<int> datap;

public:

	Point();
	Point(vector<int> point);
	Point(const Point & _p);
	Point& operator=(Point& _p);
	Point(int d, int* arr);

	bool isEqual(Point _p);
	double evcMetric(Point _p);
	int manhattanMetric(Point _p);
	
	//supply methods

	int getCordinate(int _d)const{ return datap[_d]; }
	int getDimension()const{ return datap.size(); }
	void logPoint();
};