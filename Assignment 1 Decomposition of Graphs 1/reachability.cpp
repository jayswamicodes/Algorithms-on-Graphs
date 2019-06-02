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
	/*for (int j = 0; j < adj[x].size(); j++)
		cout << adj[x][j] << ",";
	cout << endl;*/
	for (int j = 0; j < adj[x].size(); j++)
		if (!nodePresent(visit, adj[x][j]))
			dfs(adj, visit, adj[x][j]);
}

int reach(vector<vector<int> > &adj, int x, int y) {
  //write your code here
	vector<int> visited;
	dfs(adj, visited, x);
	if (nodePresent(visited, x) && nodePresent(visited, y))
		return 1;
  return 0;
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
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
  //system("pause");
}
