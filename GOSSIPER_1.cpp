#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <map>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;
#define FOR(i,N) for (int i = 0; i < N; i++)

int main()
{
  string s, s1, s2;
  int N, M;
  bool share[2100][2100];
  while (true)
    {
      scanf ("%d %d", &N, &M);
      if (N==0 && M==0)
        break;
      FOR(i,N)
        FOR(j,N)
          share[i][j] = false;
      map<string, int> ns;
      FOR(i,N)
        {
          cin >> s;
          ns.insert(make_pair(s, i));
        }
      FOR(i,M)
        {
          string s1, s2;
          cin >> s1 >> s2;
          int idx1 = ns[s1];
          int idx2 = ns[s2];
          share[idx1][idx2] = true;
          share[idx2][idx1] = true;
          FOR(j,N)
            {
              if (share[idx1][j])
                {
                  share[idx2][j] = true;
                  //share[j][idx2] = true;
                }
              if (share[idx2][j])
                {
                  share[idx1][j] = true;
                  //share[j][idx1] = true;
                }
            }
        }
      bool ans = true;
      FOR(i,N)
        {
          FOR(j,N)
            {
              if (i!=j && not share[i][j])
                {
                  ans = false;
                  break;
                }
            }
        }
      if (ans)
        printf("YES\n");
      else
        printf("NO\n");
    }
}

