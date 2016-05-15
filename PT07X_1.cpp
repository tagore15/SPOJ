#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <algorithm>
using namespace std;
#define FOR(i,N) for (int i = 0; i < N; i++)

// set-disjoint data structure
int parent[10010];
// initialize for given number of nodes
void init(int N)
{
   FOR(i,N) parent[i]=i;
}

// finds parent of a node
int FIND(int u)
{
    while (u != parent[u])
    {
        u = parent[u];
    }
    return u;
}
// joins 2 nodes
void JOIN(int u, int v)
{
    parent[FIND(u)] = FIND(v);
}

// checks if 2 sets are disjoints
bool DISJOINT(int u, int v)
{
    if (FIND(u) == FIND(v))
    {
        return false;
    }
    return true;
}
int main() 
{
    int N, M;
    cin >> N >> M;
    if (M != N-1)
    {
        cout << "NO";
        return 0;
    }
    init(N);
    int u, v;
    FOR(i,M)
    {
        cin >> u >> v;
        if (not DISJOINT(u, v))
        {
            cout << "NO";
            return 0;
        }
        JOIN(u, v);
    }
    cout << "YES";
	return 0;
}
