#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using std::vector;
using std::pair;
using namespace std;

void dfs(vector<vector<int> > &adj, vector<string> &vertex, vector<int> &order, int x) {
  //write your code here
	if (vertex[x] == "green") {
		vertex[x] = "blue";
		for (int i = 0; i < adj[x].size(); i++) {
			dfs(adj, vertex, order, adj[x][i]);
		}
		vertex[x] = "red";
		order.push_back(x);
	}
	else if (vertex[x] == "blue") {
		//return true;
	}
	else if (vertex[x] == "red") {
		//return false;
	}
}     

void reverseOrder(vector<int> &order) {
	for (int i = 0; i < order.size()/2; i++) {
		int temp = order[order.size() - i - 1];
		order[order.size() - i - 1] = order[i];
		order[i] = temp;
	}
}

vector<int> toposort(vector<vector<int> > adj) {
  //vector<int> used(adj.size(), 0);
  vector<int> order;
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
		  dfs(adj, vertex, order, j);
	  }
  }
  reverseOrder(order);
  return order;
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
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
  //system("pause");
}
