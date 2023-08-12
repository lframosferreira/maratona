#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back()

typedef long long ll;
typedef pair<int , int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int t;cin >> t;
    int n, k;
    while (t--){
        int ans = 0;
        cin >> n >> k;
        vector<int> v(n*k);
        for (int i = 0; i < n*k;i++) cin >> v[i];
        int aux;
        if (n%2==0){
            aux= n/2;
        } else {
            aux = n/2;
            aux++;
        }
        if (n == 1){
            for (auto e: v) ans +=e;
        }
        else if (n == 2){
            for (int i = 0; i < n*k;i++){
                if (i % 2 == 0) ans += v[i];
            }
        }else{
            for (int j = 1; j<= k;j++){
                ans += v[n*k - (n-1)*j + (aux - 2)];
            }
        }
        cout << ans << endl;
    }

    exit(0);
}
