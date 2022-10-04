class BT{
    static Node root;
    static class Node{
        Node left,right;
        int data;
        Node(int d){
            data = d;
        }
    }

    static int height(Node root){
        if(root == null){
            return 0;
        }
        else{
            int lheight = height(root.left);
            int rheight = height(root.right);
            if(lheight > rheight)
                return lheight+=1;
            return rheight+=1;
        }
    }

    public static void main(String[] args) {
        root = new Node(1);
        root.left = new Node(5);
        root.right = new Node(4);
        root.left.left = new Node(8);
        root.left.right = new Node(3);
        int h = height(root);
        System.out.println(h);
    }
}