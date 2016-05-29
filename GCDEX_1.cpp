#include <iostream>
using namespace std;
typedef long long LL;

#define FOR(i,N) for(int i = 0 ; i < N; i++)

#define TOTAL 1000001
int PHI[TOTAL+10];
LL GD[TOTAL+10];

/* calculate ETF of first N numbers
    using euler' product formula
    phi(n)=n(1−1/p)(1-1/q)..... where p,q are all prime divisors of n
    Imagine the integers 0,1,...n−1. These are the candidates of the prime divisors of n. Now choose some prime number p, which eliminates 1/p of these candidates. Then you have n(1−1/p) of these candidates left. Then choose a different prime q which cancels out 1/q of the remaining candidates to give n(1−1/p)(1−1/q), and so on
*/
void calcPHI()
{
    PHI[1] = 1;
    for (int i = 2; i < TOTAL; i++)
    {
        if (not PHI[i])
        { // this is a prime
            PHI[i] = i-1;
            for (int j = i<<1; j <= TOTAL; j+=i)
            {// if i is multiple of j, then i would be gcd of numbers of coprimes relative to j/i i.e. phi[j/i]
                if (not PHI[j]) PHI[j] = j;
                PHI[j] = PHI[j]/i*(i-1);
            }
        }
    }
}

// for debugging
void displayPHI()
{
    for (int i = 1; i < TOTAL; i++)
    {
        cout << PHI[i] << endl;
    }
}
void GCD_AllPairs()
{
    LL ans = 0;
    for (int i = 1; i <= TOTAL; i++)
    {
        for (int j = i<<1 ; j <= TOTAL; j+=i)
        {
            GD[j] += i*PHI[j/i];
        }
    }
    LL result = 0;
    for (int i = 1; i <= TOTAL ; i++)
    {
        result += GD[i];
        GD[i] = result;
    }
}

int main()
{
    int n;
    calcPHI();
    GCD_AllPairs();
//    displayPHI();
    do {
        scanf("%d",&n);
        if (n == 0) break;
        printf("%lld\n", GD[n]);
    } while(1);
    return 0;
}

