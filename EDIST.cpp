#include <iostream>
#include <string>
#include <limits>
using namespace std;
#define FOR(i,N) for (int i = 0; i < N; i++)

int D[2010][2010];

int DIST(string& s, string& t)
{
/*
    D[i][j] = D[i+1][j+1]  <- if i == j
    D[i][j] = 1 + max(D[i+1][j+1], D[i+1][j], D[i][j+1])
*/
    for (int i = 0; i <= s.length(); i++)
    {
        for (int j = 0; j <= t.length(); j++)
        {
            if (i == 0)
            {
                D[i][j] = j; 
            }
            else if (j == 0)
            {
                D[i][j] = i;
            }
            else if (s[i-1] == t[j-1])
            {
                D[i][j] = D[i-1][j-1];
            }
            else
            {
                D[i][j] = 1 + min(min(D[i-1][j-1], D[i-1][j]), D[i][j-1]);
            }
        }
    }
    return D[s.length()][t.length()];
}

int main() {
	int T;
	cin >> T;
	FOR(i,T)
	{
        string s, t;
        cin >> s >> t;
        cout << DIST(s,t) << endl;
	}
	return 0;
}

