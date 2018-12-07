#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int n;
vector < vector<pair <int, long long>> > adjlist;
vector <int> visited;
vector <int> source;
vector <long long> cost;
priority_queue < pair<long long, int> > pq;
/*
void dfs(int node) {
	visited[node] = 1;

	cout << node << " ";

	for (int i = 0; i < adjlist[node].size(); i++) {
		int child = adjlist[node][i];
		if (visited[child] != 1)
			dfs(child);
	}
}
*/
int main()
{
	int m;
	cin >> n >> m;
	adjlist.resize(n + 1);
	source.resize(n + 1);
	cost.assign(n + 1, 1e8);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		long long w;
		cin >> x >> y >> w;
		adjlist[x].push_back({ y, w });
	}
	source[1] = 1;
	cost[1] = 0;
	pq.push({ 0,1 }); // pair {cost, source}
	while (!pq.empty())
	{
		int node = pq.top().second;
		pq.pop();
		for (int i = 0; i < adjlist[node].size(); i++)
		{
			int child = adjlist[node][i].first;
			int childW = adjlist[node][i].second;
			if (childW + cost[node] < cost[child]) // (child weight + cost of the node ) > cost of the child
			{
				cost[child] = childW + cost[node]; // child weight = weight of the edge
				source[child] = node;
				pq.push({ -1 * cost[child], child });
			}
		}
	}
	stack <int> st;
	st.push(n);
	int x = source[n];
	for (int i = 1; i <= n; i++)
	{
		st.push(x);
		x = source[x];
		if (x == source[x]) 
		{
			st.push(x);
			break;
		}
	}
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	system("pause");
	return 0;
}