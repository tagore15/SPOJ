#include <iostream>
#include <queue>
using namespace std;
#define FOR(i,N) for (int i = 0; i < N; i++)

int main()
{
    int C;
    cin >> C;
    FOR(i,C)
    {
        long long N, P, A, T, wait = 0;
        priority_queue<long long, vector<long long>, greater<long long> > pq;
        cin >> N >> P;
        FOR(j,P)
        {
          cin >> A >> T;
          long long processTime = T+5;
          wait += processTime;
          if (pq.size() < N)
            {
              pq.push(A+processTime);
            }
          else
            {
              long long f = pq.top();
              pq.pop();
              if (f < A) f = A;
              wait += (f-A);
              pq.push(f+processTime);
            }
        }
        cout << wait << endl;
    }
    return 0;
}
