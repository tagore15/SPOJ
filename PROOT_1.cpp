#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define FOR(i,N) for(int i = 0; i < N; i++)

using namespace std;

// modular exponentiation using binary i.e. (a^b)%mod
long long powm(long long a, int b, int mod)
{
  long long res = 1;
  while (b)
    {
      if (b & 1)
        {
          res = (res*a)%mod;
        }
      a = (a*a)%mod;
      b >>= 1;
    }
  return res;
}

// check if r is primitive root of p
bool checkPRoot(int r, int p)
{
  if (r == 1 && p == 2) return true;
  if (r <= 1) return false;
  int aux = (p-1);
  // check for all prime factors of n
  for (int i = 2; i*i <= aux; i++)
    {
      // as a^(p-1)%mod = 1 so it is possible only for divisors of p to have mod power 1 otherwise all are different
      if (aux%i == 0)
        {
          if (powm(r, (p-1)/i, p) == 1)
            {
              return false;
            }
          while (aux %i == 0)
            {
            	aux /= i;
            }
        }
    }
  if (aux != 1)
    {
      if (powm(r, (p-1)/aux, p) == 1)
        {
          return false;
        }
    }
  return true;
}

int main()
{
  int p, n;
  cin >> p >> n;
  do
    {
      if (p == 0 && n == 0)
        {
          return 0;
        }
      FOR(i,n)
        {
          int r;
          cin >> r;
          if (checkPRoot(r, p))
            {
              printf("YES\n");
            }
          else
            {
              printf("NO\n");
            }
        }
      cin >> p >> n;
    } while (1);
  return 0;
}
