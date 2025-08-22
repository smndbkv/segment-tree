#include <iostream>

template <class T>
class seg_tree
{
private:
    T *t = nullptr;

public:
    seg_tree(T a[], int n)
    {
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
};
