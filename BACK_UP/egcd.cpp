#include <iostream>
#include <cmath>
using namespace std;
#define FOR(i,N) for (int i = 0; i < N; i++)

// ax + by = g
void egcd(int a, int b, int &x, int &y, int &g)
{
    int s = 1, s1 = 0, t = 0, t1 = 1, c;
    while (b != 0)
    {
        g = b;
        c = s1;
        s1 = s - (a/b)*s1;
        s = c;
        c = t1;
        t1 = t - (a/b)*t1;
        t = c;
        c = b;
        b = a%b;
        a = c;
        //cout << s << " " << t << endl;
        //cout << a << " " << b << endl;
    } 
    x = s;
    y = t;
} 

int main() {
	// your code goes here
	int t;
	cin >> t;
	FOR(i,t)
	{
	    int a, b, c;
	    cin >> a >> b >> c;
	    if ( c > a && c > b)
	    {
	        cout << -1 << endl;
	        continue;
	    }
	    
    	int x, y, g;
    	egcd(max(a,b), min(a,b), x, y, g);
	    cout << x << " " << y << " " << g << endl;
    	if (c%g != 0)
    	{
    	    cout << -1;
    	}
    	else
    	{
            cout << abs(x) + abs(y) << endl;
    	}
	}
	return 0;
}
