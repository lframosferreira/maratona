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

int main(){ _
	int A, V;
	int idx = 1;
	while (true){
		cin >> A >> V;
		if (A == 0 and V == 0) break;
		vector<int> v(A+1);
		int ans=-INF;
		for (int i = 0; i < V; i++){
			int x, y;
			cin >> x >> y;
			v[x]++;v[y]++;
			ans=max({ans, v[x],v[y]});
		}
		cout << "Teste " << idx++ << endl;
		for (int i = 1; i <= A; i++){
			if (v[i] == ans){
				cout << i << " ";	
			}
		}
		cout << endl;
		cout << endl; 
	}

    exit(0);
}
