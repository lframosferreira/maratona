// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int , int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int n; cin >> n;
    int fact[9] = {0};
    fact[0] = 1;
    for (int i = 1; i <=8 ; i++){
        fact[i] = i * fact[i-1];
    }    
    int ans = 0;
    int aux = 0;
    int ptr = 8;
    while (aux != n){
        if (n-aux < fact[ptr]){
            ptr--;
            continue;
        } 
        ans++;
        aux += fact[ptr];
    }
    cout << ans << endl;
    exit(0);
}
