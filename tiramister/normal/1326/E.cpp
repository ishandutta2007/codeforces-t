#include <iostream>
#include <vector>
#include <functional>

template <class T>
struct SegmentTree {
    using Merger = std::function<T(T, T)>;

    int length;
    std::vector<T> dat;
    T unit;
    Merger merge;

    explicit SegmentTree(int n, T unit, Merger merge)
        : length(1), unit(unit), merge(merge) {
        while (length < n) length <<= 1;
        dat.assign(length * 2, unit);
    }

    T query(int ql, int qr) {
        ql = std::max(ql, 0);
        qr = std::min(qr, length);
        ql += length, qr += length;

        T lacc = unit, racc = unit;
        while (ql < qr) {
            if (ql & 1) {
                lacc = merge(lacc, dat[ql]);
                ++ql;
            }
            if (qr & 1) {
                --qr;
                racc = merge(dat[qr], racc);
            }
            ql >>= 1, qr >>= 1;
        }
        return merge(lacc, racc);
    }

    void update(int nidx, int elem) {
        nidx += length;
        dat[nidx].first += elem;

        while (nidx > 0) {
            nidx >>= 1;
            T vl = dat[nidx * 2 + 0];
            T vr = dat[nidx * 2 + 1];
            dat[nidx] = merge(vl, vr);
        }
    }
};

using lint = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        pos[--x] = i;
    }

    SegmentTree<std::pair<lint, lint>>
        seg(n, std::make_pair(0, 0),
            [](auto a, auto b) {
                return std::make_pair(a.first + b.first,
                                      std::max(a.second + b.first, b.second));
            });

    int ans = n;
    for (int i = 0; i < n; ++i) {
        while (true) {
            auto f = seg.query(0, n);
            if (std::max(f.first, f.second) > 0) break;

            --ans;
            seg.update(pos[ans], 1);
        }
        std::cout << ans + 1 << " ";

        int x;
        std::cin >> x;
        --x;
        seg.update(x, -1);
    }
    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}