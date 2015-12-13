#include <iostream>
#include <vector>
#include "cProcc.h"
#include "Point.h"
using namespace std;

int main(){
	//hey
	vector<Point> data;
	int *pr = new int[2];
	pr[0] = 1; pr[1] = 2;
	int *z = new int[2];
	z[0] = 0; z[1] = 3;
	Point p1(2, pr); Point p2(2, z);
	data.push_back(p1); data.push_back(p2);
	cProcc p (1,data);
	p.start();
	system("pause");
	return 0;
}