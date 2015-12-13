#include "Cluster.h"


Cluster::Cluster(){
	
}
bool Cluster::updateCurrentMedoid(){// check ?????
	int minCost = 99999; // поменять !
	Point tmp;
	int s = ps.size();
	for (int i = 0; i < ps.size(); i++){
		int cost = 0;

		for (int j = 0; j < ps.size(); j++){
			cost += ps[i].manhattanMetric(ps[j]);
		}

		if (minCost > cost){
			minCost = cost;
			tmp = ps[i];
		}

	}

	if (!curMedoid.isEqual(tmp)){
		setMedoid(tmp);
		//cout << "swapped to: "; tmp.logPoint();
		return true;
	}
	else{
		return false;
	}
}
