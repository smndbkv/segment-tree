#include <iostream>

template <class T>
class seg_tree
{
private:
    T *t = nullptr;
    int n = 0;

public:
    seg_tree(T *a, int n)
    {
        this->n = n;
        t = new T[2 * n - 1];
        build(a, 0, 0, n);
    }
    ~seg_tree()
    {
        delete[] t;
    }

    void build(T *a, int v, int tl, int tr)
    {
        if (tr - tl == 1)
        {
            t[v] = a[tl];
            return;
        }
        int tm = (tr + tl) / 2;
        build(a, v + 1, tl, tm);
        build(a, v + 2 * (tm - tl), tm, tr);
        t[v] = t[v + 1] + t[v + 2 * (tm - tl)];
    }
    T get_sum(int ql, int qr)
    {
        ql--;
        return get_sum_subtree(0, 0, n, ql, qr);
    }
    T get_sum_subtree(int v, int tl, int tr, int ql, int qr)
    {
        if (ql <= tl && tr <= qr)
        {
            return t[v];
        }
        int tm = (tr + tl) / 2;
        if (tm <= ql || qr <= tl)
        {
            return get_sum_subtree(v + 2 * (tm - tl), tm, tr, ql, qr);
        }
        if (tr <= ql || qr <= tm)
        {
            return get_sum_subtree(v + 1, tl, tm, ql, qr);
        }

        return get_sum_subtree(v + 1, tl, tm, ql, qr) + get_sum_subtree(v + 2 * (tm - tl), tm, tr, ql, qr);
    }
};
