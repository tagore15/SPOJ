#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
using namespace std;
typedef long long LL;

#define LEN_STR 1010
#define STEP_MAX 20

std::string str; // string to work upon
int length;     // length of string

int sa[LEN_STR]; // suffix array - indices of suffixes in lexicographical sorting order

/*--------------------------- SUFFIX ARRAY -------------------------------------------*/
// An index of a string
struct node
{
  int idx[2]; // sorting index of first half of suffix
              // sorting index of second half of suffix
  int id;     // original index of suffix
} nd[LEN_STR];

int cmp(node n1, node n2)
{
  return (n1.idx[0] == n2.idx[0]) ? (n1.idx[1] < n2.idx[1] ? 1 : 0) : (n1.idx[0] < n2.idx[0] ? 1 : 0);
}
int P[STEP_MAX][LEN_STR]; // stores index of a position in sorted array
void createSuffixArray()
{
  for (int i = 0; i < length; i++)
    {
      P[0][i] = str[i] - 'A';
      nd[i].id = i;
    }
  // sort the suffixes of length 2^step with indexes of sorted upper and lower halves
  for (int cnt = 1, step = 1; cnt < length ; step++, cnt <<= 1)
    {
      for (int i = 0; i < length; i++)
        {
          nd[i].idx[0] = P[step-1][i];
          nd[i].idx[1] = (i + cnt) < length ? P[step-1][i+cnt] : -10000;
          nd[i].id     = i;
        }
      sort(nd, nd + length, cmp);
      for (int i = 0; i < length; i++)
        {
          P[step][nd[i].id] = (i > 0 && nd[i].idx[0] == nd[i-1].idx[0] && nd[i-1].idx[1] == nd[i].idx[1]) ? P[step][nd[i-1].id] : i;
        }
    }
  for (int i = 0; i < length; i++)
    {
      sa[i] = nd[i].id;
    }
}
void debugSuffixArray()
{
  for (int i = 0; i < length; i++)
    {
      cout << sa[i] << endl;
    }
}

/*--------------------------- LONGEST COMMON PREFIX ARRAY -------------------------------------------*/
int lcp[LEN_STR]; // longest common prefix array
// for a suffix a1a2a3.....an with lcp of k, suffix a2a3....an would have lcp of atleast k-1
void createLcpArray()
{
  int rank[LEN_STR];
  for (int i = 0; i < length; i++)
    {
      rank[sa[i]] = i;
    }
  for (int i = 0, k = 0; i < length; i++, k?k--:0)
    {
      if (rank[i] == length-1)
        {
          lcp[rank[i]] = 0;
          continue;
        }
      int j = sa[rank[i]+1];
      while (str[i+k] == str[j+k] && i+k < length && j+k < length) k++;
      lcp[rank[i]] = k;
    }
}

void debugLcpArray()
{
  cout << "LONGEST COMMON PREFIX ARRAY" << endl;
  for (int i = 0; i < length; i++)
    {
      cout << lcp[i] << endl;
    }
}
/*--------------------------- NUMBER OF DISTINCT SUBSTRINGS -----------------------------------------*/
// count number of distinct strings
// num of distinct substrings are (all possible prefixes of suffixes - lcp to avoid duplicate)
long countDistStrings(std::string& str)
{
  long count = 0;
  for (int i = 0; i < length; i++)
    {
      count += length - sa[i];
      count -= lcp[i];
    }
  return count;
}

int main()
{
  int T;
  cin >> T;
  for (int i = 0; i < T; i++)
    {
      cin >> str;
      length = str.length();
      createSuffixArray();
      //debugSuffixArray();
      createLcpArray();
      //debugLcpArray();
      cout << countDistStrings(str) << endl;
    }
  return 0;
}
