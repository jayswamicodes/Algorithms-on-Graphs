#include <iostream>
#include <vector>

using std::vector;
using std::pair;
using namespace std;

bool nodePresent(vector<int>& visited, int node) {
	for (int i = 0; i < visited.size(); i++)
		if (visited[i] == node)
			return 1;
	return 0;
}

void dfs(const vector<vector<int> > &adj, vector<int>& visit, int x) {
	visit.push_back(x);
	for (int j = 0; j < adj[x].size(); j++)
		if (!nodePresent(visit, adj[x][j]))
			dfs(adj, visit, adj[x][j]);
}

int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  //write your code here
  vector<int> vertex;
  for (int i = 0; i < adj.size(); i++) {
	  vertex.push_back(i);
  }
  vector<int> visited;
  for (int j = 0; j < vertex.size(); j++) {
	  if (!nodePresent(visited, vertex[j])) {
		  dfs(adj, visited, vertex[j]);
		  res++;
	  }
  }
  return res;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj);
  //system("pause");
}
