#include <iostream>
using namespace std;
typedef long long LL;

#define FOR(i,N) for (int i = 0; i < N; i++)

LL solve(LL n, LL k)
{
    /* n stars, (n-1) possiblites to place (k-1) bars for k different type of objects
    (n-1)C(k-1) = (n-1)!/(k-1)!(n-k)!
                = (n-1)(n-2)...(n-k+1)/1.2.3....k-1 */
    LL result = 1;
    for (int i = n-k+1, j = 1; i <= n-1; i++, j++)
        result = (result*i)/j;
    return result;
    
}
int main() {
	// your code goes here
	int t;
	LL n, k;
	cin >> t;
	FOR(i,t)
	{
	    cin >> n >> k;
	    cout << solve(n, k) << endl;
	}
	return 0;
}
