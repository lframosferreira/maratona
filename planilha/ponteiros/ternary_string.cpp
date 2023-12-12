#include <bits/stdc++.h>

using namespace std;

#define _                         \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back()

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main()
{
	_

		int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int l = 0;
		int r = 0;
		int best = INF;
		int v[4] = {0};
		bool is_valid = false;
		while (l < s.length())
		{

			if (v[1] > 0 && v[2] > 0 && v[3] > 0)
			{
				best = min(best, r - l);
				if (best == 3)
					break;
				is_valid = true;
			}

			if (is_valid)
			{
				v[s.at(l) - '0']--;
				l++;
			}
			else
			{
				if (r == s.length())
					break;
				v[s.at(r) - '0']++;
				r++;
			}
			is_valid=false;
		}
		if (best == INF)
		{
			cout << 0 << endl;
		}
		else
		{
			cout << best << endl;
		}
	}
	exit(0);
}
