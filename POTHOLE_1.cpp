#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;
typedef long long LL;

#define FOR(i,N) for(int i = 0 ; i < N; i++)

int GRAPH[210][210];
int n; // numbers of chambers

bool isVisited[210];
int parent[210];
bool bfs()
{
    FOR(i,n)
    {
        isVisited[i] = false;
        parent[i] = -1;
    }
    queue<int> q;
    q.push(0);
    while (not q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (not isVisited[i] && GRAPH[u][i] > 0)
            {
                parent[i] = u;
                if (i == n-1) return true;
                isVisited[i] = true;
                q.push(i);
            }
        }
    }
    return false;
}
int maxFlow()
{
    int max_flow = 0;
    while(bfs()) // while there is augmented path achievable by BFS
    {
        // traverse along augmented path and check its max flow with updation of residual graph
        int u = n-1;
        int min_flow_arc = numeric_limits<int>::max();
        while (u != 0)
        {
            if (min_flow_arc > GRAPH[parent[u]][u])
                min_flow_arc = GRAPH[parent[u]][u];
            u = parent[u];
        }
        u = n-1;
        while (u != 0)
        {
            GRAPH[parent[u]][u] -= min_flow_arc;
            GRAPH[u][parent[u]] += min_flow_arc;
            u = parent[u];
        }
        max_flow += min_flow_arc;
    }
    return max_flow;
}
void init()
{
    FOR(i,210)
        FOR(j,210)
            {
                GRAPH[i][j] = 0;
            }
}

int main()
{
    int t, m;
    cin >> t;
    FOR(i,t)
    {
        init();
        cin >> n;
        FOR(i, (n-1))
        {
            cin >> m;
            FOR(j, m)
            {
                int k;
                cin >> k;
                GRAPH[i][k-1] = ((i == 0 || k == n)?1:10000);
            }
        }
        cout << maxFlow() << endl;
    }
    return 0;
}
