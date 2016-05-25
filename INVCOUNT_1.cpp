#include <iostream>
using namespace std;
typedef long long LL;

#define FOR(i,N) for(int i = 0 ; i < N; i++)
int n;
LL A[200010];

LL merge(int left, int mid, int right)
{
    //cout << left << " " << mid << " " << right << endl;
    int temp[200010];
    int li = left, ri = mid + 1, tmpIndex = 0;
    LL invCount = 0;
    while (li <= mid && ri <= right)
    {
       while (A[li] <= A[ri] && li <= mid)
       {
            temp[tmpIndex++] = A[li++];
       }
       while (A[li] > A[ri] && ri <= right)
       {
            temp[tmpIndex++] = A[ri++];
            invCount += (mid - li + 1);
       }
    }
    //cout << left << " " << mid << " " << right << endl;
    while (li <= mid)
    {
        temp[tmpIndex++] = A[li++];
    }
    while (ri <= right)
    {
        temp[tmpIndex++] = A[ri++];
    }

    // copy back sorted temp to array A
    FOR(i,tmpIndex)
    {
        A[i+left] = temp[i];
    }
    return invCount;
}

LL mergeSort(int left, int right)
{
    //cout << left << " " << right << endl;
    if (left >= right)
    {
        return 0;
    }
    int mid = (left+right)/2;
    LL invCount = 0;
    invCount += mergeSort(left, mid);
    invCount += mergeSort(mid+1, right);
    invCount += merge(left, mid, right);
    return invCount;
}

LL countInverse()
{
    return mergeSort(0, n-1);
}

int main()
{
    int t;
    cin >> t;
    FOR(i,t)
    {
        cin >> n;
        FOR(j,n)
        {
            cin >> A[j];
        }
        cout << countInverse() << endl;
    }
    return 0;
}
