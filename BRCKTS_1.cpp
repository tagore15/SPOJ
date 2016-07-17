#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define FOR(i,N) for(int i = 0; i < N; i++)

using namespace std;

struct segmentTreeNode
{
    int unMatchedLeftPar, unMatchedRightPar;
    segmentTreeNode()
    {
        unMatchedLeftPar = 0;
        unMatchedRightPar = 0;
    }

    void assignLeaf(char value)
    {
        if (value == '(')
        {
           unMatchedLeftPar = 1;
           unMatchedRightPar = 0;
        }
        else
        {
           unMatchedLeftPar = 0;
           unMatchedRightPar = 1;
        }
    }

    void merge(segmentTreeNode& left, segmentTreeNode &right)
    {
        int numMatches = std::min(left.unMatchedLeftPar, right.unMatchedRightPar);
        unMatchedLeftPar = left.unMatchedLeftPar + right.unMatchedLeftPar - numMatches;
        unMatchedRightPar = left.unMatchedRightPar + right.unMatchedRightPar - numMatches;
    }
    bool getValue()
    {
        if (unMatchedLeftPar == 0 && unMatchedRightPar == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

template<typename T, typename V>
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

    V getValue(int low, int high)
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
    void updateValue(int index, int stIndex, T value, int left, int right)
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
    char arr[50100];
    int N;
    FOR(T,10)
    {
        cin >> N;
        cin >> arr;

        segmentTree<char, bool> st(arr, N);
        int m;
        scanf("%d", &m);

        printf("Test %d:\n", T+1);
        FOR(i,m)
        {
            int k;
            scanf("%d", &k);

            if (k == 0)
            {
                printf("%s\n", st.getValue(0, N-1)?"YES":"NO");
            }
            else
            {
                arr[k-1] = (arr[k-1] == '(' ? ')' : '(');
                st.updateValue(k-1, arr[k-1]);
            }
        }
    }
    return 0;
}
