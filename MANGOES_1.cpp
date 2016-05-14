#include <iostream>
using namespace std;
#define FOR(i,N) for (int i = 0; i < N; i++)

int main() {
	// sum of (1+3+...+ (n-2))
	int T;
	cin >> T;
	FOR(i,T)
	{
	    long long n;
	    cin >> n;
	    long long terms;
	    if (n%2 == 0)
	    {
	        terms = (n-1)/2;
	    }
	    else
	    {
	        terms = n/2;
	    }
	    
	    long long first = 1;
	    long long last = (2*terms-1);
	    long long sum = ((first + last)/2)%n;
	
	    cout << (terms*sum)%n << endl;
	}
	return 0;
}
