#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define FOR(i,N) for(int i = 0; i < N; i++)

using namespace std;

struct segmentTreeNode
{
    int maxPrefixSum, maxSuffixSum, maxSum, sum;

    void assignLeaf(int value)
    {
        maxPrefixSum = maxSuffixSum = maxSum = sum = value;
    }

    void merge(segmentTreeNode& left, segmentTreeNode &right)
    {
        maxPrefixSum = max(left.maxPrefixSum, left.sum + right.maxPrefixSum);
        maxSuffixSum = max(right.maxSuffixSum, left.maxSuffixSum + right.sum);
        sum = left.sum + right.sum;
        maxSum = max(maxPrefixSum, max(maxSuffixSum, max(sum, max(left.maxSum, max(right.maxSum, left.maxSuffixSum + right.maxPrefixSum)))));
    }
    int getValue()
    {
        return maxSum;
    }
};

template<typename T>
class segmentTree
{
    public:
    segmentTreeNode* st;
    int size;

    segmentTree(T arr[], int n)
    {
        st = new segmentTreeNode[getSize(n)];
        buildTree(arr, 1, 0, n-1);
        size = n;
    }

    ~segmentTree()
    {
        delete[] st;
    }

    T getValue(int low, int high)
    {
        segmentTreeNode stn =  getValue(1, 0, size-1, low, high);
        return stn.getValue();
    }

    void updateValue(int index, int value)
    {
        updateValue(index, 1 /* stIndex */ , value, 0, (size-1));
    }

    private:
    int getSize(int n)
    {
        int sz = 1;
        while (sz < n) sz <<= 1;
        return (sz << 1);
    }
    void buildTree(T arr[], int stIndex, int left, int right)
    {
        if (left == right)
        {
            st[stIndex].assignLeaf(arr[left]);
            return;
        }
        int mid = (left + right)/2;
        buildTree(arr, 2*stIndex, left, mid);
        buildTree(arr, 2*stIndex + 1, mid+1, right);
        st[stIndex].merge(st[2*stIndex], st[2*stIndex+1]);
    }

    segmentTreeNode getValue(int stIndex, int left, int right, int low, int high)
    {
        if (left == low && right == high)
        {
            return st[stIndex];
        }
        int mid = (left + right)/2;
        if (high <= mid)
          {
            return getValue(2*stIndex, left, mid, low, high);
          }
        if (low > mid)
          {
            return getValue(2*stIndex+1, mid+1, right, low, high);
          }
        segmentTreeNode st1 = getValue(2*stIndex, left, mid, low, mid);
        segmentTreeNode st2 = getValue(2*stIndex+1, mid+1, right, mid+1, high);
        segmentTreeNode st3;
        st3.merge(st1, st2);
        return st3;
    }
    void updateValue(int index, int stIndex, int value, int left, int right)
    {
        if (left == right)
          {
            //assert(index == left);
            st[stIndex].assignLeaf(value);
            return;
          }
        if (right < left) return;
        int mid = (left + right)/2;
        if (index <= mid)
          {
            updateValue(index, 2*stIndex, value, left, mid);
          }
        else
          {
            updateValue(index, 2*stIndex+1, value, mid+1, right);
          }
        st[stIndex].merge(st[2*stIndex], st[2*stIndex+1]);
    }
};

int main()
{
    int arr[50100];
    int M, N;
    scanf("%d", &N);

    FOR(i,N)
    {
        scanf("%d", &arr[i]);
    }

    segmentTree<int> st(arr, N);
    cin >> M;
    FOR(i,M)
    {
        int q, x, y;
        cin >> q >> x >> y;
        if (q == 1)
          {
            printf("%d\n", st.getValue(x-1, y-1));
          }
        else
          {
            st.updateValue(x-1, y);
          }
    }
    return 0;
}
