// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int , int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int T, P;
pii v[110][20];
vector<pair<int, pii>> standings;

int EP;

void get_standings(){
	standings.clear();
	standings.resize(T+1);
	for (int i = 1; i <= T; i++) standings[i]={i, {0, 0}};
	for (int i = 1; i <= T; i++){
		for (int j = 1; j<= P; j++){
			if (v[i][j].s == 0) continue;
			standings[i].s.f += 1;
			standings[i].s.s += v[i][j].s + EP * v[i][j].f;
		}	
    }
    sort(standings.begin(), standings.end(), [](pair<int, pii> a, pair<int, pii> b){
        if (a.s.f==b.s.f) {
            if(a.s.s==b.s.s) return a.f < b.f;
            else return a.s.s < b.s.s;	
        }

        return a.s.f > b.s.f;
    });
}

int main(){ _
	while (1){
		EP=20;
		cin >> T >> P;
		if (T==0 and P==0) break;
		memset(v, 0, sizeof v);
		for (int i = 1; i <= T; i++){
			string prob;
			for (int j = 1; j <= P; j++){
				cin >> prob;
				v[i][j].f = stoi(prob.substr(0, prob.find('/')));
				string aux =  prob.substr(prob.find('/')+1, string::npos);	
				v[i][j].s = aux == "-" ? 0 : stoi(aux);
			}
		}
		get_standings();
		
		vector<pair<int, pii>> original_standings(standings);	
        set<pii> tied;
        for (int i = 0; i < T - 1; i++){
            auto [id1, aux1] = original_standings[i];
            auto [id2, aux2] = original_standings[i+1];
            if (aux1==aux2) tied.insert({i, i+1});
        }
        
		//for (auto [id, p]: original_standings){
		//	if (id==0) continue;
		//	auto [completed, penalty] = p;
		//	cout << "id :" << id << "   " << completed << "," << penalty << endl; 
		//}
		//cout << "------------------------" << endl;

		int l = 1, r=20; // tirei da bunda

		// acha menor
		int mn=EP;
		while (l<r){
			int m=(l+r)/2;
			EP=m;
			get_standings();
			bool eq=true;
			for (int i = 1; i <= T; i++){
				if (original_standings[i].f != standings[i].f){
					eq=false;
					break;
				}
			}
            if (eq){
                for (pii p: tied){
                    if (standings[p.f].s != standings[p.s].s){
                        eq=false;
                        break;
                    }
                }
            }
			if (eq){
				r=m;	
				mn=min(mn, EP);
			}else {
				l=m+1;
			}
		}

		l=20;r=1e5 + 10;
		// acha maior
		EP=20;
		int mx=EP;
		while (l<r){
			int m=(l+r)/2;
			EP=m;
			get_standings();
			bool eq=true;
			for (int i = 1; i <= T; i++){
				if (original_standings[i].f != standings[i].f){
					eq=false;
					break;
				}
			}
            if (eq){
                for (pii p: tied){
                    if (standings[p.f].s != standings[p.s].s){
                        eq=false;
                        break;
                    }
                }
            }
			if (eq){
				l=m+1;
				mx=max(mx, EP);
			}else {
				r=m;	
			}
		}
		cout << mn << " ";
	   	if (mx > (int)1e5) cout << '*' << endl;
		else cout << mx	<< endl;
	}
    exit(0);
}
