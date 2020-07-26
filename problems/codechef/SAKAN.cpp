#include <iostream>
#include <memory>
#include <sstream>
#include <unordered_map>
#include <vector>

#include <algorithm>
#include <cstring>

using namespace std;
using l  = long;
using ll = long long;
using ul = unsigned long;

vector<bool> R, C;
int main()
{
  int T;
  cin >> T;

  while (T--)
  {
    R.clear();
    C.clear();
    int n, m, q;
    cin >> n >> m >> q;
    R.resize(n);
    C.resize(m);
    for (int i = 0; i < q; ++i)
    {
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      R[x] = !R[x];
      C[y] = !C[y];
    }

    long long no = 0, ne = 0;
    for (int i = 0; i < m; ++i)
    {
      if (C[i])
        no++;
    }
    ne     = m - no;
    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
      if (R[i])
      {
        ans += ne;
      }
      else
      {
        ans += no;
      }
    }
    cout << ans << endl;
  }

  return 0;
}

/*
constexpr int DIM = 10;
int N[DIM][DIM];

void markall(const int x, const int y)
{
  for (int i = 0; i < DIM; ++i)
  {
    N[x][i]++;
    N[x][i] %= 2;
  }
  for (int i = 0; i < DIM; ++i)
  {
    N[i][y]++;
    N[i][y] %= 2;
  }
}

void printmatrix()
{
  for (int i = 0; i < DIM; ++i)
  {
    for (int j = 0; j < DIM; ++j)
    {
      cout << N[i][j] << " ";
    }
    cout << endl;
  }
}

int main()
{

  while (true)
  {

    int x, y;

    do
    {
      cout << "insert x and y: ";
      cin >> x >> y;
    } while (!(x >= 0 && y >= 0 && x < DIM && y < DIM));

    markall(x, y);

    printmatrix();
  }

  return 0;
}*/