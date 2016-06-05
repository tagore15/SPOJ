#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
typedef vector<int> VI;

#define FOR(i,N) for(int i = 0 ; i < N; i++)

int D[2002][2002];  // D[i][j] <- LCS of first array ending at i and second array at j

void initD()
{
    FOR(i,2002)
        FOR(j,2002)
            D[i][j] = 0;
}

int LCS(VI& a, VI& b)
{
    int m = a.size();
    int n = b.size();

    for (int i = 1; i <= m ; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i-1] == b[j-1])
            {
                D[i][j] = 1 + D[i-1][j-1];
            }
            D[i][j] = max(D[i][j], max(D[i][j-1], D[i-1][j]));
        }
    }
    return D[m][n];
}

int main()
{
    //int arr1[] = {16,2,77,29,80};
    int d;
    cin >> d;
    FOR(i,d)
    {
        VI a, b;
        int x, res = 0;
        do
        {
            cin >> x;
            if (x == 0) break;
            a.push_back(x);
        } while(1);
        do
        {
            cin >> x;
            if (x == 0) break;
            initD();
            do {
                b.push_back(x);
                cin >> x;
                if (x == 0) break;
            } while(1);
            int ans = LCS(a, b);
            if (ans > res)
            {
                res = ans;
            }
            b.clear();
        } while(1);
        cout << res << endl;
    }

    /*int arr1[] = {16,2,77,29,80};
    vector<int> vec1 (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
    //int arr2[] = {90, 16,3, 29, 80, 77};
    int arr2[] = {90,16,3,29,80,77};
    vector<int> vec2 (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
    FOR
    cout << LCS(vec1, vec2) << endl;*/
    return 0;
}
