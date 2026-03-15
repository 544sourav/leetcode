class Fancy {
public:
    vector<long long> f;
    long long add = 0;
    long long mul = 1;
    const int MOD = 1e9+7;

    long long modInverse(long long x){
        long long res = 1, p = MOD-2;
        while(p){
            if(p&1) res = (res*x)%MOD;
            x = (x*x)%MOD;
            p >>= 1;
        }
        return res;
    }

    Fancy() {}

    void append(int val) {
        long long inv = modInverse(mul);
        long long v = ((val - add + MOD) % MOD * inv) % MOD;
        f.push_back(v);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx) {
        if(idx >= f.size()) return -1;
        return (f[idx] * mul % MOD + add) % MOD;
    }
};