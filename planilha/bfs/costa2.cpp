#include <bits/stdc++.h>

using namespace std;

#define _                         \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define f first
#define s second
#define pb push_back()

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool oob(pii c, int m, int n)
{
	return c.f < 0 || c.f >= m || c.s < 0 || c.s >= n;
}

int main()
{
	_
		vector<pii>
			moves = {make_pair(0, -1), make_pair(0, 1), make_pair(1, 0), make_pair(-1, 0)};
	int m, n;
	cin >> m >> n;
	vector<string> sq(m, "");
	int c = 0;
	while (c < m)
	{
		cin >> sq.at(c);
		c++;
	}

	c = 0;

  for (int i = 0; i < m; i++){
    for (int j = 0; j <n; j++){
      if (sq[i][j] == '#'){
        bool valid = false;
        for (auto move: moves){
          pii npos = {i + move.f, j + move.s};
          if (oob(npos, m, n)){
            valid = true;
          }
          else if (sq[npos.f][npos.s] == '.'){
            valid = true;
          }
        }
        if (valid) c++;
      }
    }
  }

	cout << c << endl;

	exit(0);
}
