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

	vector<vector<bool>> visited(m, vector<bool>(n, false));
	queue<pii> q;
	// suppose we can start from 0,0
	q.push(make_pair(0, 0));
	while (!q.empty())
	{
		pii aux = q.front();
		q.pop();
		if (visited[aux.f][aux.s])
		{
			continue;
		}
		visited[aux.f][aux.s] = true;
		if (sq.at(aux.f).at(aux.s) == '#')
		{
			c++;
		}
		else
		{
			for (auto move : moves)
			{
				pii npos = make_pair(aux.f + move.f, aux.s + move.s);
				if (!oob(npos, m, n) && !visited.at(npos.f).at(npos.s))
				{
					q.push(npos);
				}
			}
		}
	}

	cout << c << endl;

	exit(0);
}
