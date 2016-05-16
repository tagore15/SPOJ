#include <iostream>
using namespace std;
#define FOR(i,N) for (int i = 0; i < N; i++)

int GCD(int a, int b)
{
    if (b == 0) return a;
    return GCD(b,a%b);
}

int main() {
    // your code goes here
    int T;
    cin >> T;
    FOR(i,T)
    {
        int A;
        string B;
        cin >> A;
        cin >> B;

        if (A == 0)
        {
        	cout << B << endl;
        	continue;
        }
        int b1 = 0;
        FOR(j,B.length())
        {
          b1 *= 10;
          b1 += (B[j] - '0');
          b1 %= A;
        }
        cout << GCD(A, b1) << endl;
    }
    return 0;
}
