#include <iostream>
using namespace std;
typedef long long LL;

#define FOR(i,N) for(int i = 0 ; i < N; i++)
#define MOD 1000000007

LL D[1000002];

// !n = (n-1)*(!(n-1) + !(n-2))
void populateDerange()
{
    D[0] = 0;
    D[1] = 0;
    D[2] = 1;
    for (int i = 3; i < 1000002; i++)
    {
        D[i] = ((i-1)*((D[i-1] + D[i-2])%MOD))%MOD;
    }
}

int main()
{
    int t, n;
    cin >> t;
    populateDerange();
    FOR(i,t)
    {
        cin >> n;
        cout << D[n] << endl;
    }
    return 0;
}
