#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef vector<LL> VLL;

#define FOR(i,N) for(int i = 0 ; i < N; i++)
LL N, C;
VLL ARR;

// possible to select >= C
bool select(LL d)
{
    LL sel = 1;
    LL last_pos = ARR[0];
    for (int i = 1 ; i < N; i++)
    {
        if (ARR[i] - last_pos >= d)
        {
            sel++;
            last_pos = ARR[i];
        }
    }
    if (sel >= C) return true;
    return false;
}

LL solve()
{
    LL lower =  0, upper = ARR[N-1];
    while (lower <= upper) {
        LL mid = (lower + upper)>>1;
        if (select(mid))
        {
            lower = mid+1;
        }
        else
        {
            upper = mid-1;
        }
    }
    return lower-1;
}
int main()
{
    int t;
    cin >> t;
    FOR(i,t)
    {
        ARR.clear();
        cin >> N >> C;
        FOR(i,N)
        {
            LL k;
            cin >> k;
            ARR.push_back(k);
        }
        sort(ARR.begin(), ARR.end());
        cout << solve() << endl;
    }
    return 0;
}
