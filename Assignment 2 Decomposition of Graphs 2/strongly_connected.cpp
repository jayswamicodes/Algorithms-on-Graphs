#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;
using namespace std;

void reverseGraph(vector<vector<int> >& adj, vector<vector<int> >& rev_adj) {
	for (int i = 0; i < adj.size(); i++) {
		for (int j = 0; j < adj[i].size(); j++)
			rev_adj[adj[i][j]].push_back(i);
	}

	/*for (int i = 0; i < rev_adj.size(); i++) {
		for (int j = 0; j < rev_adj[i].size(); j++) {
			cout << rev_adj[i][j] << ",";
		}
		cout << endl;
	}*/
}

void reverseOrder(vector<int> &order) {
	for (int i = 0; i < order.size() / 2; i++) {
		int temp = order[order.size() - i - 1];
		order[order.size() - i - 1] = order[i];
		order[i] = temp;
	}
}

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

void dfs2(vector<vector<int> > &adj, vector<string> &vertex, int x) {
	//write your code here
	if (vertex[x] == "green") {
		vertex[x] = "blue";
		for (int i = 0; i < adj[x].size(); i++) {
			dfs2(adj, vertex, adj[x][i]);
		}
		vertex[x] = "red";
	}
	else if (vertex[x] == "blue") {
		//return true;
	}
	else if (vertex[x] == "red") {
		//return false;
	}
}

void computeDfs(vector<vector<int> >& rev_adj, vector<int>& order) {
	vector<string> vertex;
	for (int i = 0; i < rev_adj.size(); i++) {
		vertex.push_back("green");
	}

	for (int j = 0; j < vertex.size(); j++) {
		if (vertex[j] == "green") {
			dfs(rev_adj, vertex, order, j);
		}
	}
}

int number_of_strongly_connected_components(vector<vector<int> >& adj) {
  int result = 0;
  //write your code here
  //reverse the graph
  vector<vector<int> > rev_adj(adj.size());
  reverseGraph(adj, rev_adj);

  // compute topo order on reverse graph
  vector<int> order;
  computeDfs(rev_adj, order);
  reverseOrder(order);
  vector<string> vertex;
  for (int i = 0; i < rev_adj.size(); i++) {
	  vertex.push_back("green");
  }
  for (int i = 0; i < order.size(); i++) {
	  if (vertex[order[i]] == "green") {
		  dfs2(adj, vertex, order[i]);
		  ++result;
	  }
  }
  return result;
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
  std::cout << number_of_strongly_connected_components(adj);
  system("pause");
}
