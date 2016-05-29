#include <iostream>
using namespace std;
typedef long long LL;

#define FOR(i,N) for(int i = 0 ; i < N; i++)
int DP[15][100];

void populate()
{
    DP[1][0] = 1;
    for(int i = 2; i <= 12; i++)
    {
	// nth number can be inserted at any n-1 position and inversion count would be accordingly
        for(int j = 0; j < i; j++)
        {
            for (int k = j; k <= 98; k++)
            {
                DP[i][k] +=  DP[i-1][k-j];
            }
        }
    }
}

int count(int n, int k)
{
  return DP[n][k];
}

int main()
{
    populate();
    int t;
    cin >> t;
    FOR(i,t)
    {
        int n, k;
        cin >> n >> k;
        cout << count(n, k) << endl;
    }
    return 0;
}
