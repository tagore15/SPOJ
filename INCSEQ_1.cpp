#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define FOR(i,N) for(int i = 0 ; i < N; i++)
typedef vector<int> VI;
VI ARR, BRR;

#define MOD 5000000
#define MAX 100000
int mx = 1;

// binary index tree of different sizes(first index) ending with last element <= second index
int BIT[51][MAX];
int N, K;

// x & -x would return last set bit and all other bits are zero
int query(int *b, int idx)
{
    int val = 0;
    while (idx > 0)
    {
        val += b[idx];
        if (val >= MOD) val -= MOD;
        idx -= (idx & -idx);
    }
    return val;
}
void update(int *b, int idx, int val)
{
    while (idx <= mx)
    {
        b[idx] += val;
        if (b[idx] >= MOD) b[idx] -= MOD;
        idx += (idx & -idx);
    }
}


int main()
{
    scanf("%d %d", &N, &K);
    int t;
    FOR(i,N)
    {
        scanf("%d", &t);
        ARR.push_back(t);
        BRR.push_back(t);
    }
    // normalize the array for efficiency
    map<int,int> norm_map;
    sort(BRR.begin(), BRR.end());
    //mx = BRR[0];
    norm_map[BRR[0]] = mx;

    for(int i = 1; i < BRR.size() ; i++)
    {
        if (BRR[i] != BRR[i-1])
        {
            mx++;
            norm_map[BRR[i]] = mx;
        }
    }
    FOR(i,N)
    {
        ARR[i] = norm_map[ARR[i]];
    }

    FOR(i,N)
    {
        update(BIT[1], ARR[i], 1);
        for (int k = 1; k <= K; k++)
        {
            update(BIT[k], ARR[i], query(BIT[k-1], ARR[i]-1));
        }
    }
    printf("%d\n",query(BIT[K], mx));
    return 0;
}
