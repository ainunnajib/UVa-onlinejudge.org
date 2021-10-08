#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
using namespace std;
typedef long long ll;

int t, n, m, x[100005];

bool check(int d){
    int cur, idx=0;
    for(int i=0;i<n;i++){
        cur = x[idx] + d;
        idx = upper_bound(x, x+m, cur+d) - x;
        if(idx>=m) return true;
    }
    return false;
}

int main(){
    cout << setprecision(1) << fixed;
    cin >> t;
    while(t--){
        cin >> n >> m;
        memset(x, 0, sizeof(int));
        for(int i=0;i<m;i++) { 
            cin >> x[i];
            x[i] *= 20;
        }
        if(n>=m) {
            cout << "0.0" << endl;
            continue;
        }

        sort(x, x+m);
        int lo=0, hi=x[m-1], mid;
        while(lo<hi-1){
            mid = lo + (hi-lo)/2;
            if(check(mid)) hi = mid;
            else lo = mid;
        }
        if(hi%2 == 0) cout << 1.0*hi/20 << endl;
        else cout << 1.0*(hi/2+1)/10 << endl;
    }
}