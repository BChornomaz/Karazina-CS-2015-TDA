#include <vector>
#include "Point.h"

using namespace std;
class Cluster{
	vector<Point> ps;
	Point curMedoid;
public:

	bool updateCurrentMedoid();

	Cluster();
	void clear() { ps.clear(); }
	void addPoint(Point _p) { ps.push_back(_p); }
	void setMedoid(Point _p) { 
		curMedoid = _p; 
	}
	int getClustrSize(){ return ps.size(); }
	Point getMedoid() { return curMedoid; }
	Point getCurMedoid() { return curMedoid; }

	void logCluster(){
		for (int i = 0; i < ps.size(); i++)
			ps[i].logPoint();
	}
};