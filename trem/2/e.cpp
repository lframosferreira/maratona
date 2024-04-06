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
typedef vector<vi> vvi;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int t; cin >> t;
    while (t--){
        int n;cin>>n;
        string txt;cin >> txt;
        bool alice=1;
        while (1){
            if (txt.size()==1){
                cout << (alice ? "Alice" : "Bob" ) <<endl; 
                break;
            }
            if (txt.front()=='L' or txt.back()=='R'){
                cout << (alice ? "Alice" : "Bob" ) <<endl; 
                break;
            } 
            bool ok1=false;
            int idx1,idx2;
            for (int i = 0; i <txt.size()-1; i++){
                if (txt[i]==txt[i+1]){
                   ok1=true;
                   idx1=i;
                   break;
                }
            }
            for (int i = txt.size()-1; i >0; i--){
                if (txt[i]==txt[i-1]){
                   idx2=i-1;
                   break;
                }
            }
            if (!ok1){
                if (!alice) cout << "Alice" << endl;
                else cout << "Bob" << endl;
                break;
           }else {
                if (txt[idx1]=='L'){
                    cout << (alice ? "Alice" :"Bob")<< endl;
                    break;
                }
                else if (txt[idx2]=='R'){
                    cout << (alice ? "Alice" :"Bob")<< endl;
                    break;
                }
                else {
                    txt=txt.substr(idx1+1, string::npos);
                    alice=!alice;
                }
            }
        }
    }    
    exit(0);
}
