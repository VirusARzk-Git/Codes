class BIT
{
    int n;
    vector<int> bit;

public:
    BIT(int n)
    {
        this->n = n;
        bit.assign(n, 0);
    }

    BIT(vector<int> &a)
    {
        n = a.size();
        bit.assign(n, 0);
        for (int i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r)
    {
        int s = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            s += bit[r];
        return s;
    }

    int sum(int l, int r) { return sum(r) - sum(l - 1); }

    void add(int idx, int delta)
    {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};