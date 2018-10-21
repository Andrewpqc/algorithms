package graph;

public class DepthFirstOrder {
    private boolean [] marked;
    private Queue<Integer> pre;//前序
    private Queue<Integer> post;//后序
    private Stack<Integer> reversePost;//逆后序

    public DepthFirstOrder(Digraph dg){
        marked = new boolean[dg.V()];
        pre = new Queue<>();
        post = new Queue<>();
        reversePost = new Stack<>();

        for(int i=0;i<dg.V();++i)
            if(!marked[i]) dfs(dg,i);
    }

    private void dfs(Digraph dg, int s){
        pre.enqueue(s);

        marked[s]=true;
        for(int i : dg.adj(s)){
            if(!marked[i]) dfs(dg,i);
        }

        post.enqueue(s);
        reversePost.push(s);
    }

    public Iterable<Integer> pre(){
        return pre;
    }

    public Iterable<Integer> post(){
        return post;
    }

    public Iterable<Integer> reversePost(){
        return reversePost;
    }


    public static void main(String[] args) {
        Digraph dg = new Digraph(8);
        dg.addEdge(0, 1);
        dg.addEdge(1, 2);
        dg.addEdge(2, 3);
        dg.addEdge(3, 4);
        dg.addEdge(5, 6);
        dg.addEdge(6, 7);

        DepthFirstOrder dfo = new DepthFirstOrder(dg);

        System.out.println("pre:");
        for(int i : dfo.pre()){
            System.out.print(i+" ");
        }
        System.out.println();

        System.out.println("post:");
        for(int i : dfo.post()){
            System.out.print(i+" ");
        }
        System.out.println();

        System.out.println("reversePost:");
        for(int i : dfo.reversePost()){
            System.out.print(i+" ");
        }
        System.out.println();
    }
}
