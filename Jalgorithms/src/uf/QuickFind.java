//union-find算法之quick find
package uf;

public class QuickFind {
    private int[] id;
    private int count_;

    public QuickFind(int n) {
        id = new int[n];
        count_ = n;
        for (int i = 0; i < n; ++i)
            id[i] = i;
    }

    public int find(int x) {
        return id[x];
    }

    public boolean connected(int x, int y) {
        return find(x) == find(y);
    }

    public void union(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;

        for (int i = 0; i < id.length; ++i) {
            if (id[i] == px) id[i] = py;
        }
        --count_;
    }

    public int count() {
        return count_;
    }


    public static void main(String[] args) {
        int[] source = {0, 1, 1, 2, 4, 3};
        QuickFind qf = new QuickFind(5);
        for (int i = 0, j = 1; j < 6; i += 2, j += 2) {
            if (!qf.connected(source[i], source[j])) {
                qf.union(source[i], source[j]);
            }
        }

        System.out.println(qf.count());//打印联通分量个数

    }
}
