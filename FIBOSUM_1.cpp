#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;

#define FOR(i,N) for (int i = 0; i < N; i++)
#define MOD 1000000007
// size of matrix
#define N 2 

typedef vector<vector<LL> > matrix;
matrix mul(matrix A, matrix B)
{
    matrix C(N, vector<LL>(N));
    FOR(i,N)
    {
        FOR(j,N)
        {
            FOR(k,N)
            {
                C[i][j] += ((A[i][k]*B[k][j])%MOD);
            }
        }
    }
    return C;
}
// matrix exponentitation by squaring
matrix pow(matrix A, LL p)
{
    if (p == 1)
    {
        return A; 
    }
    if (p == 2)
    {
        return mul(A, A);
    }
    matrix tmp(N, vector<LL>(N));
    tmp = pow(pow(A, p/2), 2);
    if (p%2 == 0)
    {
        return tmp;
    }
    return mul(A, tmp);
}

/* find pth fibonacci number using matrix power
[0 1]^p*[1]
[1 1]   [1]
*/
LL findFib(LL p) 
{
    if (p == 0) return 0;
    if (p == 1 || p == 2)   return 1;
    matrix A(N, vector<LL>(N)), result(N, vector<LL>(N));
    A[0][0] = 0; A[0][1] = 1;
    A[1][0] = 1; A[1][1] = 1;
    result = pow(A, p-2);
    LL ans = 0;
    FOR(i,N)
    {
        ans += result[N-1][i]%MOD;
    }
    return ans;
}

void debug()
{
    FOR(i,10)
    {
        cout << i << "th fibonacci number is " << findFib(i) << endl;
    }
}

int main() {
	int t;
	LL n1, m1;
	cin >> t;
	//debug();
	FOR(i,t)
	{
	    cin >> n1 >> m1;
	    // F(1)+F(2)+F(3)+F(4)+........+F(N) = F(N+2)-1
	    LL res = (findFib(m1+2) - findFib(n1+1))%MOD;
	    if (res < 0)
	    {
	        res += MOD;
	    }
	    cout << res << endl;
	}
	return 0;
}
