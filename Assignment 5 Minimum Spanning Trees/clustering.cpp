#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cmath>
#include <map> 

using std::vector;
using std::pair;
using namespace std;

double distance(int x1, int x2, int y1, int y2) {
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

int find(int i, const vector<int>& set) {
	while (i != set[i]) {
		i = set[i];
	}
	return i;
}

void unionSet(int i, int j, vector<int>& set, vector<int>& rank) {
	int i_id = find(i, set);
	int j_id = find(j, set);
	if (i_id == j_id)
		return;
	if (rank[i_id] > rank[j_id]) {
		set[j_id] = i_id;
	}
	else {
		set[i_id] = j_id;
		if (rank[i_id] == rank[j_id])
			rank[j_id] = rank[j_id] + 1;
	}
}


double clustering(vector<int> x, vector<int> y, int k) {
  //write your code here
	// Start by treating every vertex as 1 cluster
	double result = -1.;
	vector<int> set;
	vector<int> rank;
	for (int i = 0; i < x.size(); i++) {
		set.push_back(i);
		rank.push_back(0);
	}

	map<vector<int>, double> pointsToWeight;

	//Using ordered map weightToPoints, hence the distance is already sorted
	map<double, vector<vector<int>>> weightToPoints;
	for (int i = 0; i < x.size() - 1; i++) {
		for (int j = i + 1; j < x.size(); j++) {
			vector<int> temp;
			temp.push_back(i);
			temp.push_back(j);
			double cost = distance(x[i], x[j], y[i], y[j]);
			pointsToWeight[temp] = cost;
			weightToPoints[cost].push_back(temp);
		}
	}
	int num = x.size();
	for (auto i = weightToPoints.begin(); i != weightToPoints.end(); i++) {
		for (int j = 0; j < i->second.size(); j++) {
			//Stop when the required number of clusters is reached = k
			if (num < k)
				break;
			if (find(i->second[j][0], set) != find(i->second[j][1], set)) {
				if (pointsToWeight[i->second[j]] > result)
					result = pointsToWeight[i->second[j]];
				unionSet(i->second[j][0], i->second[j][1], set, rank);
				--num;
			}
		}
	}
  return result;
} 

int main() {
  size_t n;
  int k;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cin >> k;
  std::cout << std::setprecision(10) << clustering(x, y, k) << std::endl;
  //system("pause");
}
