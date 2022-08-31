#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> graph[1000];
bool visited[1000];
void dfs(int vertex)
{

    visited[vertex] = true;
    for (int child : graph[vertex])
    {
        cout << vertex << " child " << child << endl;
        if (visited[child])
            continue;

        dfs(child);
    }
}
int main()
{
    int vertex, edge;
    cin >> vertex >> edge;

    for (int i = 0; i < edge; i++)
    {
        int v1, v2;

        cin >> v1 >> v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    dfs(1);

    return 0;
}
