#include <iostream>
#include <vector>
#include <cstdint>
#include <climits>


using std::vector;
using namespace std;

void initVect(vector<int>& arr, int refArrSize, int def) {
	for (int i = 0; i < refArrSize; i++) {
		arr.push_back(def);
	}
}

const void showVect(const vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << ", ";
	}
	cout << endl;
}

void bellmanFord(const vector<vector<int> > &adj, const vector<vector<int> > &cost, vector<int>& dist, vector<int>& prev) {
	for (int j = 0; j < adj.size(); j++) {
		for (int i = 0; i < adj[j].size(); i++) {
			if (dist[adj[j][i]] > dist[j] + cost[j][i]) {
				dist[adj[j][i]] = dist[j] + cost[j][i];
				prev[adj[j][i]] = j;
			}
		}
	}
}

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  //write your code here
	vector<int> dist;
	vector<int> prev;
	initVect(dist, cost.size(), 99999);
	initVect(prev, adj.size(), -1);
	dist[0] = 0;
	prev[0] = 0;
	// Calculate weight for every edge V-1 times, to get weight from src to reach all vertices
	for (int k = 0; k < adj.size() - 1; k++)
	    bellmanFord(adj, cost, dist, prev);
	//showVect(dist);
	vector<int> finalDist;
	for (int i = 0; i < dist.size(); i++)
		finalDist.push_back(dist[i]);
	// Calculate the all edge weight once more, if same no negative cycle found
	bellmanFord(adj, cost, dist, prev);
	//showVect(dist);
	for (int i = 0; i < dist.size(); i++) {
		if (dist[i] == finalDist[i])
			continue;
		else
			return 1;
	}
  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
  //system("pause");
}
