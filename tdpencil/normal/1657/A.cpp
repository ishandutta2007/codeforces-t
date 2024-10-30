#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ld long double
#define ar array

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;

//template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define V vector
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)

template<class T> bool umin(T& a, const T& b) {
    return b<a?a=b, 1:0;
}
template<class T> bool umax(T& a, const T& b) { 
    return a<b?a=b, 1:0;
} 

ll FIRSTTRUE(function<bool(ll)> f, ll lb, ll rb) {
    while(lb<rb) {
        ll mb=(lb+rb)/2;
        f(mb)?rb=mb:lb=mb+1; 
    } 
    return lb;
}
ll LASTTRUE(function<bool(ll)> f, ll lb, ll rb) {
    while(lb<rb) {
        ll mb=(lb+rb+1)/2;
        f(mb)?lb=mb:rb=mb-1; 
    } 
    return lb;
}

template<class A> void read(vt<A>& v);
template<class A, size_t S> void read(ar<A, S>& a);
template<class T> void read(T& x) {
    cin >> x;
}
void read(double& d) {
    string t;
    read(t);
    d=stod(t);
}
void read(long double& d) {
    string t;
    read(t);
    d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
    read(h);
    read(t...);
}
template<class A> void read(vt<A>& x) {
    EACH(a, x)
        read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
    EACH(a, x)
        read(a);
}

string to_string(char c) {
    return string(1, c);
}
string to_string(bool b) {
    return b?"true":"false";
}
string to_string(const char* s) {
    return string(s);
}
string to_string(string s) {
    return s;
}
string to_string(vt<bool> v) {
    string res;
    FOR(sz(v))
        res+=char('0'+v[i]);
    return res;
}

template<size_t S> string to_string(bitset<S> b) {
    string res;
    FOR(S)
        res+=char('0'+b[i]);
    return res;
}
template<class T> string to_string(T v) {
    bool f=1;
    string res;
    EACH(x, v) {
        if(!f)
            res+=' ';
        f=0;
        res+=to_string(x);
    }
    return res;
}

template<class A> void write(A x) {
    cout << to_string(x);
}
template<class H, class... T> void write(const H& h, const T&... t) { 
    write(h);
    write(t...);
}
void print() {
    write("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) { 
    write(h);
    if(sizeof...(t))
        write(' ');
    print(t...);
}

void DBG() {
    cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
    cerr << to_string(h);
    if(sizeof...(t))
        cerr << ", ";
    DBG(t...);
}
#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

template<class T> void offset(ll o, T& x) {
    x+=o;
}
template<class T> void offset(ll o, vt<T>& x) {
    EACH(a, x)
        offset(o, a);
}
template<class T, size_t S> void offset(ll o, ar<T, S>& x) {
    EACH(a, x)
        offset(o, a);
}

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b) {
    return uniform_int_distribution<ll>(a, b)(mt_rng);
}

template<class T, class U> void vti(vt<T> &v, U x, size_t n) {
    v=vt<T>(n, x);
}
template<class T, class U> void vti(vt<T> &v, U x, size_t n, size_t m...) {
    v=vt<T>(n);
    EACH(a, v)
        vti(a, x, m);
}

const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};


template <typename T, int NDIMS> struct tensor_view {
    static_assert(NDIMS >= 0, "NDIMS must be nonnegative");

    protected:
    std::array<int, NDIMS> shape;
    std::array<int, NDIMS> strides;
    T* data;

    tensor_view(std::array<int, NDIMS> shape_, std::array<int, NDIMS> strides_, T* data_) : shape(shape_), strides(strides_), data(data_) {}

    public:
    tensor_view() : shape{0}, strides{0}, data(nullptr) {}

    protected:
    int flatten_index(std::array<int, NDIMS> idx) const {
        int res = 0;
        for (int i = 0; i < NDIMS; i++) { res += idx[i] * strides[i]; }
        return res;
    }
    int flatten_index_checked(std::array<int, NDIMS> idx) const {
        int res = 0;
        for (int i = 0; i < NDIMS; i++) {
            assert(0 <= idx[i] && idx[i] < shape[i]);
            res += idx[i] * strides[i];
        }
        return res;
    }

    public:
    T& operator[] (std::array<int, NDIMS> idx) const {
        return data[flatten_index(idx)];
    }
    T& at(std::array<int, NDIMS> idx) const {
        return data[flatten_index_checked(idx)];
    }

    template <int D = NDIMS>
        typename std::enable_if<(0 < D), tensor_view<T, NDIMS-1>>::type operator[] (int idx) const {
            std::array<int, NDIMS-1> nshape; std::copy(shape.begin()+1, shape.end(), nshape.begin());
            std::array<int, NDIMS-1> nstrides; std::copy(strides.begin()+1, strides.end(), nstrides.begin());
            T* ndata = data + (strides[0] * idx);
            return tensor_view<T, NDIMS-1>(nshape, nstrides, ndata);
        }
    template <int D = NDIMS>
        typename std::enable_if<(0 < D), tensor_view<T, NDIMS-1>>::type at(int idx) const {
            assert(0 <= idx && idx < shape[0]);
            return operator[](idx);
        }

    template <int D = NDIMS>
        typename std::enable_if<(0 == D), T&>::type operator * () const {
            return *data;
        }

    template <typename U, int D> friend struct tensor_view;
    template <typename U, int D> friend struct tensor;
};

template <typename T, int NDIMS> struct tensor {
    static_assert(NDIMS >= 0, "NDIMS must be nonnegative");

    protected:
    std::array<int, NDIMS> shape;
    std::array<int, NDIMS> strides;
    int len;
    T* data;

    public:
    tensor() : shape{0}, strides{0}, len(0), data(nullptr) {}

    explicit tensor(std::array<int, NDIMS> shape_, const T& t = T()) {
        shape = shape_;
        strides[NDIMS-1] = 1;
        for (int i = NDIMS-1; i > 0; i--) {
            strides[i-1] = strides[i] * shape[i];
        }
        len = strides[0] * shape[0];
        data = new T[len];
        std::fill(data, data + len, t);
    }

    tensor(const tensor& o) : shape(o.shape), strides(o.strides), len(o.len), data(new T[len]) {
        for (int i = 0; i < len; i++) {
            data[i] = o.data[i];
        }
    }

    tensor& operator=(tensor&& o) noexcept {
        using std::swap;
        swap(shape, o.shape);
        swap(strides, o.strides);
        swap(len, o.len);
        swap(data, o.data);
        return *this;
    }
    tensor(tensor&& o) : tensor() {
        *this = std::move(o);
    }
    tensor& operator=(const tensor& o) {
        return *this = tensor(o);
    }
    ~tensor() { delete[] data; }

    using view_t = tensor_view<T, NDIMS>;
    view_t view() {
        return tensor_view<T, NDIMS>(shape, strides, data);
    }
    operator view_t() {
        return view();
    }

    using const_view_t = tensor_view<const T, NDIMS>;
    const_view_t view() const {
        return tensor_view<const T, NDIMS>(shape, strides, data);
    }
    operator const_view_t() const {
        return view();
    }

    T& operator[] (std::array<int, NDIMS> idx) { return view()[idx]; }
    T& at(std::array<int, NDIMS> idx) { return view().at(idx); }
    const T& operator[] (std::array<int, NDIMS> idx) const { return view()[idx]; }
    const T& at(std::array<int, NDIMS> idx) const { return view().at(idx); }

    template <int D = NDIMS>
        typename std::enable_if<(0 < D), tensor_view<T, NDIMS-1>>::type operator[] (int idx) {
            return view()[idx];
        }
    template <int D = NDIMS>
        typename std::enable_if<(0 < D), tensor_view<T, NDIMS-1>>::type at(int idx) {
            return view().at(idx);
        }

    template <int D = NDIMS>
        typename std::enable_if<(0 < D), tensor_view<const T, NDIMS-1>>::type operator[] (int idx) const {
            return view()[idx];
        }
    template <int D = NDIMS>
        typename std::enable_if<(0 < D), tensor_view<const T, NDIMS-1>>::type at(int idx) const {
            return view().at(idx);
        }

    template <int D = NDIMS>
        typename std::enable_if<(0 == D), T&>::type operator * () {
            return *view();
        }
    template <int D = NDIMS>
        typename std::enable_if<(0 == D), const T&>::type operator * () const {
            return *view();
        }
};


template <typename T> T mod_inv_in_range(T a, T m) {
	// assert(0 <= a && a < m);
	T x = a, y = m;
	T vx = 1, vy = 0;
	while (x) {
		T k = y / x;
		y %= x;
		vy -= k * vx;
		std::swap(x, y);
		std::swap(vx, vy);
	}
	assert(y == 1);
	return vy < 0 ? m + vy : vy;
}

template <typename T> T mod_inv(T a, T m) {
	a %= m;
	a = a < 0 ? a + m : a;
	return mod_inv_in_range(a, m);
}

template <int MOD_> struct modnum {
	static constexpr int MOD = MOD_;
	static_assert(MOD_ > 0, "MOD must be positive");
private:
	int v;
public:
	modnum() : v(0) {}
	modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
	explicit operator int() const { return v; }
	friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
	friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }

	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

	modnum inv() const {
		modnum res;
		res.v = mod_inv_in_range(v, MOD);
		return res;
	}
	friend modnum inv(const modnum& m) { return m.inv(); }
	modnum neg() const {
		modnum res;
		res.v = v ? MOD-v : 0;
		return res;
	}
	friend modnum neg(const modnum& m) { return m.neg(); }

	modnum operator- () const {
		return neg();
	}
	modnum operator+ () const {
		return modnum(*this);
	}

	modnum& operator ++ () {
		v ++;
		if (v == MOD) v = 0;
		return *this;
	}
	modnum& operator -- () {
		if (v == 0) v = MOD;
		v --;
		return *this;
	}
	modnum& operator += (const modnum& o) {
		v -= MOD-o.v;
		v = (v < 0) ? v + MOD : v;
		return *this;
	}
	modnum& operator -= (const modnum& o) {
		v -= o.v;
		v = (v < 0) ? v + MOD : v;
		return *this;
	}
	modnum& operator *= (const modnum& o) {
		v = int(ll(v) * ll(o.v) % MOD);
		return *this;
	}
	modnum& operator /= (const modnum& o) {
		return *this *= o.inv();
	}

	friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
	friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

bool psquare(int x) {
	int v = sqrt(x);
	if(v * v == x)
		return true;
	if((v+1) * (v+1) == x)
		return true;
	return false;
}
void solve() {
    int a, b;
    cin >> a >> b;
	if(a == 0 && b == 0) {
		print(0);
	} else if(psquare(a*a+b*b)) {
		print(1);
	} else {
		print(2);
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t=1;
    read(t);
    FOR(t) {
        //write("Case #", i+1, ": ");
        solve();
    }
}