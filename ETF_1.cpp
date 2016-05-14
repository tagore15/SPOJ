#include <iostream>
using namespace std;
#define FOR(i,N) for (int i = 0; i < N; i++)

// find euler's totient function i.e. number of coprimes(GCD=1) less than N
int PHI(int N)
{
    int result = N; // we keep subtracting divisors of prime factors from result
    // iterate over possible prime factors
    for (int p = 2; p*p <= N; p++)
    {
        if (N%p == 0) // find remaining number after removing affect of a prime factor
        {
            while (N%p == 0)
            {
                N /= p;
            }
            result -=  result/p;
        }
    }
    // we can have only 1 prime factor greater than sqrt(n)
    if (N > 1)
    {
        result -= result/N;
    }
    return result;
}

int main() {
	// your code goes here
	int T;
	cin >> T;
	FOR(i,T)
	{
	    int n;
	    cin >> n;
	    cout << PHI(n) << endl;
	}
	return 0;
}
