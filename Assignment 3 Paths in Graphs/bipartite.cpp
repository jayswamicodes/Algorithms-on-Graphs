#include <iostream>
#include <vector>
#include <queue>
#include <string>

using std::vector;
using std::queue;
using namespace std;

void bfs(vector<vector<int> > &adj, vector<int>& distance, vector<string>& color) {
	// Implementation of BFS
	queue<int> vertex;
	vertex.push(0);
	distance[0] = 0;
	while (!vertex.empty()) {
		int node = vertex.front();
		vertex.pop();
		for (int j = 0; j < adj[node].size(); j++) {
			if (distance[adj[node][j]] == -1) {
				vertex.push(adj[node][j]);
				distance[adj[node][j]] = distance[node] + 1;
				// For even distance assign white / for odd distance assign black
				if (distance[adj[node][j]] % 2 != 0)
					color[adj[node][j]] = "black";
			}
		}
	}
}

bool verifyBipartite(vector<vector<int> > &adj, vector<int>& distance, vector<string>& color) {
	// for index in adj graph, verify for even distance, its edges should be black and vice versa for graph to be Bipartite
	for (int i = 0; i < adj.size(); i++) {
		if (distance[i] % 2 == 0) {
			for (int j = 0; j < adj[i].size(); j++) {
				if (color[adj[i][j]] == "black")
					continue;
				else
					return 0;
			}
		}
		else {
			for (int j = 0; j < adj[i].size(); j++) {
				if (color[adj[i][j]] == "white")
					continue;
				else
					return 0;
			}
		}
	}
	return 1;
}

int bipartite(vector<vector<int> > &adj) {
  //write your code here
	vector<int> distance;
	vector<string> color;
	for (int i = 0; i < adj.size(); i++) {
		distance.push_back(-1);
		color.push_back("white");
	}
	bfs(adj, distance, color);
	return verifyBipartite(adj, distance, color);
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
  std::cout << bipartite(adj);
  //system("pause");
}
