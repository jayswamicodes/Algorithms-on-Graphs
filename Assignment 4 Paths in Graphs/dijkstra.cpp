#include <iostream>
#include <vector>
#include <queue>
#include <cstdint>
#include <climits>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
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

void updateQ(vector<int>& Q, int vertex, int cost) {
	Q[vertex] = cost;
}

int getMin(vector<int>& Q) {
	int min = INT_MAX;
	for (int i = 0; i < Q.size(); i++) {
		if (Q[i] < min && Q[i] != -1)
			min = i;
	}
	if (min!=INT_MAX)
		Q[min] = -1;
	return min;
}

void dijkstra(const vector<vector<int> > &adj, const vector<vector<int> > &cost, vector<int>& dist, vector<int>& prev) {
	vector<int> Q;
	for (int i = 0; i < dist.size(); i++) {
		Q.push_back(dist[i]);
	}
	while (!Q.empty()) {
		int min = getMin(Q);
		if (min == INT_MAX)
			break;
		for (int i = 0; i < adj[min].size(); i++) {
			if (dist[adj[min][i]] > dist[min] + cost[min][i]) {
				dist[adj[min][i]] = dist[min] + cost[min][i];
				prev[adj[min][i]] = min;
				updateQ(Q, adj[min][i], dist[adj[min][i]]);
			}
		}
	}
}

int distance(const vector<vector<int> > &adj, const vector<vector<int> > &cost, int s, int t) {
  //write your code her
	vector<int> dist;
	vector<int> prev;
	initVect(dist, cost.size(), INT_MAX);
	initVect(prev, adj.size(), 0);
	dist[s] = 0;
	dijkstra(adj, cost, dist, prev);
	//showVect(dist);
	if (dist[t] != INT_MAX)
		return dist[t];

  return -1;
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
  //system("pause");
}
