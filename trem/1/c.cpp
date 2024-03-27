#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
 
#define f first
#define s second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
 
int consegue[110];
int n;
 
int acha_novo(int s){
    int novo=0;
    for (int i = 1; i< s; i++) novo += min(consegue[i], consegue[s-i]);
    return novo/2;
}
 
int main() { _
    int t; cin >> t;
    int ans=-INT_MAX;
    while (t--){
        memset(consegue, 0, sizeof consegue);
        cin >> n;
        for (int i = 0; i < n; i++){
            int aux; cin >> aux;
            consegue[aux]++;
        }
        int ans=-INT_MAX;
        for (int s = 1; s <= 100; s++){
            int novo=acha_novo(s);
            ans=max(ans, novo);
        }
        cout << ans << endl;
    }
 
	exit(0);
}
