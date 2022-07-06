template<class T>
struct Tree {
    static constexpr T unit = INT64_MIN;
    T f(T a, T b) { // (any associative fn)
        return a+b; 
    } 
    vector<T> s; int n;
    Tree(vector<T> &arr, T def = unit) : s(2*arr.size(), def), n(arr.size()) {
        for(int i=0;i<arr.size();i++){
            update(i, arr[i]);
        }
    }
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};