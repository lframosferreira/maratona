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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    while (1){
        int M, N; cin >> M >> N;
        if (M == 0 and N == 0) break;
        M *= 100; N *= 100;
        int L; cin >> L;
        int K; cin >> K;
        vector<int> v(K);
        for (int& i: v) cin >> i;
        for (int& i: v) i *= 100;
        int ans1 = -1;
        int ans2 = -1;
        sort(v.begin(), v.end(), greater<int>());
        int l = 0; int r = K-1;
        int cover1 = 0;
        int cover2 = 0;
        if (M % L != 0 and N % L != 0){
            cout << "impossivel" << endl;
            continue;
        }
        if (M % L == 0){ 
            ans1 = 0;
            while (l <= r) {
                if (cover1 == M / L) break;
                if (v[l] > N){
                    l++;
                    continue;
                }
                if (v[l] == N) {
                    ans1++;
                    l++;
                    cover1++;
                    continue;
                }
                int want = N - v[l];
                int found = 0;
                while (v[r] <= want){
                    if (r <= l) break;
                    if (v[r] == want){
                        found = 1;
                        break;
                    }
                    r--;
                }
                if (r < l) break;
                if (!found) {
                    l++;
                    continue;
                }
                ans1+=2;
                cover1++;
                l++;
                r--;
            }
            if (cover1 < M/L) ans1 = -1;
        }

        l = 0; r = K-1;
        if (N % L == 0){
            ans2 = 0;
            while (l <= r) {
                if (cover2 == N / L) break;
                if (v[l] > M){
                    l++;
                    continue;
                }
                if (v[l] == M) {
                    ans2++;
                    l++;
                    cover2++;
                    continue;
                }
                int want = M - v[l];
                int found = 0;
                while (v[r] <= want){
                    if (r <= l) break;
                    if (v[r] == want){
                        found = 1;
                        break;
                    }
                    r--;
                }
                if (r < l) break;
                if (!found) {
                    l++;
                    continue;
                }
                ans2+=2;
                cover2++;
                l++;
                r--;
            }
            if (cover2 < N/L) ans2 = -1;
        }
        if (ans1 == -1 and ans2 == -1) cout << "impossivel" << endl;
        else if (ans1 == -1) cout << ans2 << endl;
        else if (ans2 == -1) cout << ans1 << endl;
        else cout << min(ans1, ans2) << endl;
    }
    exit(0);
}
