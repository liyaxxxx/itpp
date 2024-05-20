#include <iostream>
using namespace std;

template<class type>
struct heap {
    type a[1000];
    int n;
    heap() {
        n = 0;
    }

    void _up(int i) {
        while (i > 0 && a[i] > a[(i - 1) / 2]) {
            swap(a[i], a[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void _down(int i) {
        int ma = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && a[l] > a[ma])
            ma = l;

        if (r < n && a[r] > a[ma])
            ma = r;

        if (ma != i) {
            swap(a[i], a[ma]);
            _down(ma);
        }
    }

    void push(type x) {
        a[n++] = x;
        _up(n - 1);
    }

    void pop() {
        if (n == 0) return;
        swap(a[0], a[--n]);
        _down(0);
    }

    void update(int i, type x) {
        a[i] = x;
        _up(i);
        _down(i);
    }

    type top() {
        return a[0];
    }

    int size() {
        return n;
    }

    bool empty() {
        return n == 0;
    }
};

int main() {
    heap<int> hp;
    hp.push(10);
    hp.push(0);
    hp.push(20);
    hp.push(3);
    hp.push(7);
    hp.update(2, 69);

    while (!hp.empty()) {
        cout << hp.top() << ' ';
        hp.pop();
    }
    cout << endl;
    return 0;
}
