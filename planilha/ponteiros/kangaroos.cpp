// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int , int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ 
	int n; cin >> n;
	vector<int> v(n);
	for (int &i: v) cin >> i;
	sort(v.rbegin(), v.rend());
	int ans = 0;
	int l = (n-1)/2;
	int r = n - 1;
	while (l>=0 && r>(n-1)/2){ _
		if (v[l] >= 2*v[r]){
			ans++;
			l--;
			r--;
		} else {
			l--;
		}
	}
	cout << n - ans << endl;
	exit(0);
}
