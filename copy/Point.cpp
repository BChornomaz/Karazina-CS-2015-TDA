#include "Point.h"

Point::Point(){
	datap;
}
Point::Point(vector<int> _dim){
	datap = _dim;
}

Point::Point(int d, int* arr){
	for (int i = 0; i < d; i++)
		datap.push_back(arr[i]);
}
Point::Point(const Point & _p) {
	datap.resize(_p.getDimension());
	for (int i = 0; i < datap.size(); i++)
		datap[i] = _p.getCordinate(i);
}

bool Point::isEqual(Point _p){// сравнение 2х точек
	for (int i = 0; i < datap.size(); i++)
		if (datap[i] != _p.getCordinate(i))
			return false;
	return true;
}
double Point::evcMetric(Point _p){
	int sum = 0;
	for (int i = 0; i < datap.size(); i++)
		sum += pow(datap[i] - _p.getCordinate(i), 2);
	return sqrt(sum);
};
int Point::manhattanMetric(Point _p){
	int sum = 0;
	for (int i = 0; i < datap.size(); i++)
		sum += abs(datap[i] - _p.getCordinate(i));
	return sum;
}
Point& Point::operator=(Point& _p){
	datap.resize(_p.getDimension());
	for (int i = 0; i < _p.getDimension(); i++)
		datap[i] = _p.getCordinate(i);
	return *this;

}

//supply methods
void Point::logPoint(){
	for (int i = 0; i < datap.size(); i++)
		cout << datap[i] << " ";
	cout << endl;
}
