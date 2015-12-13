#include "cProcc.h"

cProcc::cProcc(int _numOfClusters, vector<Point> _data) : pset(_data), numOfClusters(_numOfClusters){
	clusters = new Cluster*[_numOfClusters];
	for (int i = 0; i < _numOfClusters; i++)
		clusters[i] = new Cluster;
	RandSetMedoids();
}
void cProcc::RandSetMedoids(){
	int k = pset.size() / numOfClusters;
	for (int i = 0; i < numOfClusters; i++){
		clusters[i]->setMedoid(pset[k*i]);//выбираем рандомные точки из множества как метроиды	
	}
}

void cProcc::start(){
	bool status = true;
	while (status){
		status = false;
		assignCorrectMedoid();
		for (int i = 0; i < numOfClusters; i++){
			//cout << "Cluster : " << i << " with medoid";
			//clusters[i]->getMedoid().logPoint();
			//clusters[i]->logCluster();
			status |= clusters[i]->updateCurrentMedoid();//если хотя бы одна функция центрирования вернула положительный результат повторяем цикл снова
			//clusters[i]->getMedoid().show();
		}
		cout << endl;
	}
}
void cProcc::assignCorrectMedoid(){
	for (int i = 0; i < numOfClusters; i++)
		clusters[i]->clear();
	for (auto it = pset.begin(); it != pset.end(); it++){
		int min = 9999;//поменять!!!
		int currClusterId = 0;
		for (int j = 0; j < numOfClusters; j++){
			int dis = it->manhattanMetric(clusters[j]->getCurMedoid());//сравниваем координаты с центром
			if (min > dis){
				min = dis;
				currClusterId = j;
			}
		}
		clusters[currClusterId]->addPoint(*it);
	}
	//for (int i = 0; i < numOfClusters; i++)
	//	cout << clusters[i]->getClustrSize() << " ";
	//cout << endl;
}

void cProcc::logCurMedoids(){
	for (int i = 0; i < numOfClusters; i++)
		clusters[i]->getMedoid().logPoint();
}