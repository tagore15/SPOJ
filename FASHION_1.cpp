#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <algorithm>
using namespace std;
#define FOR(i,N) for (int i = 0; i < N; i++)
int main() {
	int T;
	cin >> T;
	FOR(i,T)
	{
	    int N, t;
	vector<int> A, B;
	    cin >> N;
	    FOR(i,N)
	    {
		cin >> t;
		A.push_back(t);
	    }
	    FOR(i,N)
	    {
		cin >> t;
		B.push_back(t);
	    }
	    sort(A.begin(), A.end());
	    sort(B.begin(), B.end());
	    long sum = 0;
	    FOR(i,N)
	    {
	    sum += (A[i]*B[i]);	        
	    }
	    cout << sum << endl;
	}
	return 0;
}
