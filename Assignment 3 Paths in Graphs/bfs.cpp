#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using namespace std;

void bfs(vector<vector<int> > &adj, int s, vector<int>& distance) {
	// Implementation of BFS
	queue<int> vertex;
	vertex.push(s);
	distance[s] = 0;
	while (!vertex.empty()) {
		int node = vertex.front();
		vertex.pop();
		for (int j = 0; j < adj[node].size(); j++) {
			if (distance[adj[node][j]] == -1) {
				vertex.push(adj[node][j]);
				distance[adj[node][j]] = distance[node] + 1;
			}
		}
	}
}

int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here
	vector<int> distance;
	for (int i = 0; i < adj.size(); i++) {
		distance.push_back(-1);
	}
	bfs(adj, s, distance);
    return distance[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
