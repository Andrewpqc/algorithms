package uf;

public class QuickUnion {
    private int[] id;
    private int count_;

    public QuickUnion(int n) {
        id = new int[n];
        count_ = n;
        for(int i=0;i<n;++i)
            id[i]=i;
    }

    public boolean connected(int x, int y) {
        return find(x) == find(y);
    }

    public int find(int x) {
        while (x != id[x]) x = id[x];
        return x;
    }

    public void union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;
        id[rootX] = rootY;

        --count_;
    }

    public int count() {
        return count_;
    }

    public static void main(String[] args) {
        int[] source = {0, 1, 1, 2, 4, 3};
        QuickUnion qu = new QuickUnion(5);
        for (int i = 0, j = 1; j < 6; i += 2, j += 2) {
            if (!qu.connected(source[i], source[j])) {
                qu.union(source[i], source[j]);
            }
        }
        System.out.println(qu.count());//打印连通分量个数
    }


}
