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

struct Team{
    int id;
    int q_ans;
    int penalty;

    bool operator < (const Team &other){
        if (q_ans==other.q_ans){
            if (penalty==other.penalty) return id < other.id;
            else return penalty < other.penalty;
        }
        return q_ans > other.q_ans;
    };

    bool operator == (const Team &other){
        return q_ans==other.q_ans and penalty==other.penalty;           
    };

    bool operator != (const Team &other){
        return q_ans!=other.q_ans or penalty!=other.penalty;           
    };
};

void pt(const Team &t){
    cout << "id=" << t.id << " , q_ans=" << t.q_ans << " , penalty=" << t.penalty << endl;
}

int EP;
vector<Team> standings;

void get_standings(){
	standings.clear();
	for (int i = 1; i <= T; i++){
        int q_ans=0, penalty=0;
		for (int j = 1; j<= P; j++){
			if (v[i][j].s == 0) continue;
			q_ans += 1;
		    penalty += v[i][j].s + EP * v[i][j].f;
		}	
        standings.pb({i, q_ans, penalty});
    }
    sort(standings.begin(), standings.end());
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
		vector<Team> original_standings(standings);	
        set<pii> original_tied;
        for (int i = 0; i < T - 1; i++){
            auto aux1 = original_standings[i];
            auto aux2 = original_standings[i+1];
            if (aux1==aux2) original_tied.insert({i, i+1});
        }
        
		int l = 1, r=20; // tirei da bunda

        cout << "original"<< endl;
        for (auto t: original_standings) pt(t);

		// acha menor
		int mn=EP;
		while (l<r){
			int m=(l+r)/2;
			EP=m;
			get_standings();
            set<pii> tied;
            for (int i = 0; i < T - 1; i++){
                auto aux1 = standings[i];
                auto aux2 = standings[i+1];
                if (aux1==aux2) tied.insert({i, i+1});
            }
			bool eq=true;
			for (int i = 0; i < T; i++){
				if (original_standings[i].id != standings[i].id){
					eq=false;
					break;
				}
			}
            if (eq){
                for (pii p: original_tied){
                    if (standings[p.f] != standings[p.s]){
                        eq=false;
                        break;
                    }
                }
            }
            if (eq){
                for (pii p: tied){
                    if (original_tied.find(p) == original_tied.end()){
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
            set<pii> tied;
            for (int i = 0; i < T - 1; i++){
                auto aux1 = standings[i];
                auto aux2 = standings[i+1];
                if (aux1==aux2) tied.insert({i, i+1});
            }
			bool eq=true;
			for (int i = 0; i < T; i++){
				if (original_standings[i].id != standings[i].id){
					eq=false;
					break;
				}
			}
            if (eq){
                for (pii p: original_tied){
                    if (standings[p.f] != standings[p.s]){
                        eq=false;
                        break;
                    }
                }
            }
            if (eq){
                for (pii p: tied){
                    if (original_tied.find(p) == original_tied.end()){
                        eq=false;
                        break;
                    }
                }
            }
			if (eq){
				mx=max(mx, EP);
                cout << "curr" << endl;
                cout << "l=" << l << " r=" << r <<endl;
                cout << "EP=" << mx << endl;
                for (auto t: standings) pt(t);
				l=m+1;
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
