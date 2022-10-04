class BT{
    static Node root;
    static class Node{
        Node left,right;
        int data;
        Node(int d){
            data = d;
        }
    }

    static int diameter(Node root,Height height){
        if(root == null){
            height.h = 0;
            return 0;
        }
        Height lh = new Height();
        Height rh = new Height();
        int ld = diameter(root, lh);
        int rd = diameter(root, rh);
        height.h = Math.max(lh.h,rh.h)+1;
        return Math.max(lh.h+rh.h+1,Math.max(ld,rd));
    }

    public static void main(String[] args) {
        root = new Node(1);
        root.left = new Node(5);
        root.right = new Node(4);
        root.left.left = new Node(8);
        root.left.right = new Node(3);
        Height h = new Height();
        int ans = diameter(root, h);
        System.out.println(ans);
    }
}

class Height{
    int h;
}