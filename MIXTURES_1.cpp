#include <iostream>
#include <limits>
using namespace std;
typedef long long LL;

#define FOR(i,N) for(int i = 0 ; i < N; i++)
LL DP[101][101][101];// start*end*value  stores amount of smoke generated
int arr[101], N;

void init()
{
    FOR(i,101)
        FOR(j,101)
            FOR(k,101)
                DP[i][j][k] = -1;
}

LL calculate()
{
    for (int i = 0; i <= N; i++)
    {
        DP[i][i][arr[i]] = 0;
    }
    for (int i = 2; i <= N; i++)
    { // subset size
        for (int j = 0; j <= N-i; j++)
        { // starting index of subset
            for (int k = j; k <= i+j-2; k++)
            { // ending index of first component (NOTE: we don't want zero size of second component)
                for (int l = 0; l < 100; l++)
                { // for all possible values of first subset
                    if (DP[j][k][l] != -1)
                    {
                        for (int m = 0; m < 100; m++)
                        // for all possible values of second subset
                        {
                            if (DP[k+1][j+i-1][m] != -1)
                            {
                                LL left = DP[j][k][l];
                                LL right = DP[k+1][j+i-1][m];
                                LL cur = l*m + left + right;
                                if (DP[j][j+i-1][(l+m)%100] == -1 || DP[j][j+i-1][(l+m)%100] > cur)
                                {
                                    DP[j][j+i-1][(l+m)%100] = cur;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    // find minimum
    LL min = numeric_limits<LL>::max();
    for (int i = 0; i < 100; i++)
    {
        if (DP[0][N-1][i] != -1 && DP[0][N-1][i] < min)
        {
            min = DP[0][N-1][i];
        }
    }
    return min;
}

int main()
{
    while (scanf("%d", &N) != EOF)
    {
        init();


        FOR(i,N)
        {
            cin >> arr[i];
        }
        cout << calculate() << endl;
    }
    return 0;
}
