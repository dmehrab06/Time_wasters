    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long

    const ll mx = 1e4 + 1;
    string make_string(ll n) {
        string s;
        char c;
        while(n > 0) {
            c = n % 10 + 48;
            s = c + s;
            n /= 10;
        }
        return s;
    }
    string multiply(string s, ll n) {
        //if(n == 1) return s;
        ll carry, i;
        char c;
        string ret,temp;
        carry = 0;
        for(ll pos = s.size()-1; pos >= 0; pos--) {
            i = s[pos] - 48;
            i *= n;
            i += carry;
            c = i % 10 + 48;
            carry = i / 10;
            ret = c + ret;
        }
        if(carry > 0) {
            temp = make_string(carry);
            ret = temp + ret;
        }
        return ret;
    }
    vector<ll> primes(1,2);
    vector<bool> notPrime(mx,0);
    ll plen;
    void setPrime() {
        notPrime[0] = notPrime[1] = 1;
        ll stop = sqrt(mx);
        for(ll i = 4; i < mx; i += 2) notPrime[i] = 1;
        for(ll i = 3; i <= stop; i += 2) {
            if(!notPrime[i]) {
                primes.push_back(i);
                for(ll j = i * i; j < mx; j += i) {
                    if(!notPrime[j]) notPrime[j] = 1;
                }
            }
        }
        for(ll i = stop + 1; i < mx; i += 2) {
            if(!notPrime[i]) primes.push_back(i);
        }
        plen = primes.size();
        //for(ll i = 0; i < plen; i++) printf("%lld ",primes[i]);
    }

    int main() {
        ios_base::sync_with_stdio(false);
        ll t,a,n,m;
        setPrime();
        scanf("%lld",&t);
        for(ll tc = 1; tc <= t; tc++) {
            scanf("%lld",&n);
            vector<ll> v(plen,0);
            while(n--) {
                scanf("%lld",&a);
                for(ll i = 0; i < plen && a > 1; i++) {
                    m = 1;
                    while(a % primes[i]==0) {
                        m *= primes[i];
                        a /= primes[i];
                    }
                    v[i] = max(v[i],m);
                }
            }
            string ans = "1";
            //for(ll i = 0; i < plen; i++) ans = multiply(ans,v[i]);
            sort(v.begin(),v.end());
            for(ll i = plen - 1; i >= 0; i--) {
                if(v[i] <= 1) break;
                ans = multiply(ans,v[i]);
            }
            cout << "Case " << tc << ": " << ans << endl;
        }
    }

