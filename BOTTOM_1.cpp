#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <algorithm>
using namespace std;
#define FOR(i,N) for (int i = 0; i < N; i++)

typedef vector<int> VI;
typedef vector<VI> VII;
VII graph, graphT;  // forward and reverse dfs
int comp[5010]; // connected component for vertex
VI sorted; // sorted list of vertices from first dfs
bool visited[5010]; // keep info of visted vertices during dfs
bool sol[5010]; // final results to calculate which connected components satisfy condition in question
// forward DFS
void dfs(int v)
{
    visited[v] = true;
    for (int i = 0; i < graph[v].size(); i++)
    {
        //cout << v << " " << i << endl;
        //cout << graph[v][i] << endl;
        if (not visited[graph[v][i]]) {
            dfs(graph[v][i]);
        }
    }
    sorted.push_back(v);
}
// reverse DFS
void dfsT(int v, int comp_id)
{
    //cout << "DFST" << comp_id << endl;
    visited[v] = true;
    comp[v] = comp_id;
    for (int i = 0; i < graphT[v].size(); i++)
    {
        if (not visited[graphT[v][i]]) {
            dfsT(graphT[v][i], comp_id);
        }
    }
}

void findConnectedComponenets(int v)
{
    FOR(i,v) visited[i] = false;
    FOR(i,v)
    {
        if (not visited[i])
        {
            dfs(i);
        }
    }
    int comp_id = 0;
    FOR(i,v) visited[i] = false;
    for (int i = sorted.size()-1; i >= 0 ; i--)
    {
        if (not visited[sorted[i]])
        {
            dfsT(sorted[i], comp_id++);
        }
    }
}

void printConnectedComponents(int v)
{
    //cout << v << endl;
    FOR(i,v) 
    {
       cout << comp[i] << endl;
    }
}

int main() 
{
    int v, e;
    do {
        //cout << "HERE" << endl;
	    cin >> v;
	    if (v == 0) return 0;
        //cout << "HERE" << v << endl;
	    cin >> e;
	    graph.clear();
	    graph.resize(v);
	    graphT.clear();
	    graphT.resize(v);
	    FOR(i,e)
	    {
	        int s, t;
	        cin >> s >> t;
	        //cout << graph.size() << endl;
	        //cout << s << " " << t << " "  << graph[s-1].size()<<endl;
	        graph[s-1].push_back(t-1);
	        //cout << "HEREdd";
	        graphT[t-1].push_back(s-1);
	    }
	    findConnectedComponenets(v);
	    //printConnectedComponents(v);
	    FOR(i,v) sol[i] = true;
	    FOR(i,v)
	    {
	        if (sol[comp[i]] == false) continue;
	        FOR(j,graph[i].size())
	        {
	            if (comp[i] != comp[graph[i][j]])
	            {
	                sol[comp[i]] = false;
	                break;
	            }
	        }
	    }
	    FOR(i,v)
	    {
	        if (sol[comp[i]]) cout << i+1 << " ";
	    }
	    cout << endl;
    } while(1);
	return 0;
}
