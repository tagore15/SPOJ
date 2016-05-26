#include <iostream>
using namespace std;
typedef long long LL;

#define FOR(i,N) for(int i = 0 ; i < N; i++)

int n, m;
double P[101][101];

void initPath()
{
    FOR(i,n+1)
        FOR(j,n+1)
            P[i][j] = 0;
}

void allPairShortestPath()
{
	for (int k = 1; k <= n ; k++)
    	for (int i = 1; i <= n; i++)
        	for (int j = 1; j <= n; j++)
                    P[i][j] = max(P[i][j], P[i][k]*P[k][j]);
}
int main()
{
    do {
        cin >> n;
        if (n == 0) return 0;
        initPath();
        cin >> m;
        int a, b, p;
        FOR(i,m)
        {
            cin >> a >> b >> p;
            P[a][b] = P[b][a] = ((double)p)/100;
        }
        allPairShortestPath();
        printf("%.6lf percent\n", P[1][n]*100);
    } while(1);
    return 0;
}
