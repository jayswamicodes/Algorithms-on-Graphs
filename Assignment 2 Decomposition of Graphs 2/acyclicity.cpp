#include <iostream>
#include <vector>
#include <map>

using std::vector;
using std::pair;
using std::map;
using namespace std;

bool dfs(const vector<vector<int> > &adj, vector<string>& vertex, int x) {
	if (vertex[x] == "green") {
		vertex[x] = "blue";
		for (int i = 0; i < adj[x].size(); i++) {
			if (dfs(adj, vertex, adj[x][i]))
				return true;
		}
		vertex[x] = "red";
		return false;
	}
	else if (vertex[x] == "blue") {
		return true;
	}
	else if (vertex[x] == "red") {
		return false;
	}
}

int acyclic(vector<vector<int> > &adj) {
  //write your code here
	vector<string> vertex;
	for (int i = 0; i < adj.size(); i++) {
		vertex.push_back("green");
		/*cout << adj[i].size() << ": ";
		for (int j = 0; j < adj[i].size(); j++)
			cout << adj[i][j] << ", ";
		cout << endl;*/
	}
	
	for (int j = 0; j < vertex.size(); j++) {
		if (vertex[j] == "green") {
			if (dfs(adj, vertex, j))
				return 1;
		}
	}
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
  }
  std::cout << acyclic(adj);
  //system("pause");
}
