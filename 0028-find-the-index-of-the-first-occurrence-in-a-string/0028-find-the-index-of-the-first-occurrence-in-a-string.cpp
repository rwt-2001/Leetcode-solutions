using ll = long long int;
class Solution {
    ll p = 31, mod = 1e9 + 7;
public:
    
    ll powr(ll a, ll b) {
        ll res = 1;
        while (b) {
            if (b & 1) res = (1ll*res*a)%mod;
            b /= 2;
            a  = (1ll*a*a)%mod;

            a %= mod;
            res %= mod;
        }
        return res;
    }

    ll inv(ll x) {
        return powr(x, mod - 2);
    }

    ll hash(string str){
        ll p_power = 1;
        ll hash_val = 0;
        
        for(ll i = 0;i<str.size();i++){
            ll val = (1LL * (str[i] - 'a' + 1) * p_power)%mod;
            hash_val = (1LL * hash_val + 1ll*val)%mod;
            p_power  = (1LL * p_power * p)%mod;
        }
        
        return hash_val;
    }
    
    int strStr(string text, string pattern) {
        
        ll n = text.size();
        ll m = pattern.size();
        if( m > n) return -1;
        ll pHash = hash(pattern);
        ll tHash = hash(text.substr(0,m));
        
        if(pHash == tHash) return 0;
        
  
        for(ll i = 1;i + m <= n;i++){
            tHash -= (text[i-1] - 'a' + 1);
            
            tHash = (tHash * inv(p)) % mod;
            tHash = (1LL*tHash + (1LL * (text[i + m-1] - 'a' + 1) * powr(p, m - 1))%mod)%mod;
            if(tHash == pHash) return i;
        }
        
        return -1;
        // return hash(haystack);
    }
};