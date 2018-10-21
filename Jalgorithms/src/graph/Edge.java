package graph;

public class Edge implements Comparable<Edge> {
    private final int v_;
    private final int w_;
    private final double weight_;

    public Edge(int v, int w, double weight) {
        v_ = v;
        w_ = w;
        weight_ = weight;
    }

    public double weight() {
        return weight_;
    }

    public int either() {
        return v_;
    }

    public int other(int x) {
        if (x == v_) return w_;
        else if (x == w_) return v_;
        else throw new RuntimeException("error in other()");
    }


    @Override
    public int compareTo(Edge that) {
        if (this.weight() < that.weight()) return -1;
        else if (this.weight() > that.weight()) return 1;
        else return 0;
    }


    @Override
    public String toString() {
        return this.v_ + " " + this.w_ + " " + this.weight_;
    }


    public static void main(String[] args) {
        Edge e1 = new Edge(1, 2, 0.12);
        Edge e2 = new Edge(2, 3, 0.15);

        System.out.println(e1.weight());

        int either = e1.either();
        int other = e1.other(either);
        System.out.println(either + " " + other);

        System.out.println(e1.compareTo(e2) < 0);

        System.out.println(e1);

        System.out.println(e2);

    }
}
