package uf;

public class WeightedQuickUnion {
    private int[] id;
    private int[] sz;
    private int count_;

    public WeightedQuickUnion(int n) {
        id = new int[n];
        sz = new int[n];
        for (int i = 0; i < n; ++i) {
            id[i] = i;
            sz[i] = i;
        }
        count_ = n;

    }

    public boolean connected(int x, int y) {
        return find(x) == find(y);
    }

    public int count() {
        return count_;
    }

    public int find(int x) {
        while (x != id[x]) x = id[x];
        return x;
    }


    public void union(int x, int y) {
        int i = find(x);
        int j = find(y);
        if (i == j) return;
        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
        } else {
            id[j] = i;
            sz[i] += sz[j];
        }
        --count_;
    }


    public static void main(String[] args) {
        int[] source = {0, 1, 1, 2, 4, 3};
        WeightedQuickUnion wqu = new WeightedQuickUnion(5);
        for (int i = 0, j = 1; j < 6; i += 2, j += 2) {
            if (!wqu.connected(source[i], source[j])) {
                wqu.union(source[i], source[j]);
            }
        }
        System.out.println(wqu.count());//打印连通分量个数
    }
}
