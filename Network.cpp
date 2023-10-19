#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

int n, S, k, connected[1001], visited[1001];
vector<int> graph[1001], far_nodes[1001];

void connect_nodes(int u, int f, int d) {
	connected[u] = f;
	int n = graph[u].size();
	if (n == 1 && d > k) 
		far_nodes[d].push_back(u);
	for (int i = 0; i < n; i++) {
		int v = graph[u][i];
		if (v != f) 
			connect_nodes(v, u, d + 1);
	}
}

void Distance_nodes(int u, int f, int d) {
	visited[u] = 1;
	int n = graph[u].size();
	for (int i = 0; i < n; i++) {
		int v = graph[u][i];
		if (v != f && d < k) 
			Distance_nodes(v, u, d + 1);
	}
}

int necessary_replicas() {
	int ans = 0;
	memset(visited, 0, sizeof(visited));
	for (int d = n - 1; d > k; d--) {
		for (int i = 0; i < far_nodes[d].size(); i++) {
			int u = far_nodes[d][i];
			if (visited[u]) 
				continue;

			int v = u;

			for (int j = 0; j < k; j++) 
				v = connected[v];
			Distance_nodes(v, -1, 0);
			ans++;
		}
	}
	return ans;
}

void clear_data() {
	for (int i = 1; i <= n; i++) {
		graph[i].clear();
		far_nodes[i].clear();
	}
}

int main() {
	int T, a, b;
	vector<int> output;

	scanf("%d", &T);

	while (T--) {
		scanf("%d\n%d %d",&n, &S, &k);
		clear_data();
		for (int i = 1;i < n;i++) {
			scanf("%d %d", &a, &b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		connect_nodes(S, 0, 0);
		output.push_back(necessary_replicas());
	}

	for (auto const& i : output) {
		cout << i <<endl;
	}

	return 0;
}
