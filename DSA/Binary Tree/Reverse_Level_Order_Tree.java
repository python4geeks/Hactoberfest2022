import java.util.*;
class BT{
    static Node root;
    static class Node{
        Node left,right;
        int data;
        Node(int d){
            data = d;
        }
    }

    static ArrayList<Integer> reverseLevelOrder(){
        ArrayList<Integer> arr = new ArrayList<Integer>();
        Stack<Integer> stack = new Stack<Integer>();
        Queue<Node> q = new LinkedList<Node>();
        q.add(root);
        while(!q.isEmpty()){
            Node temp = q.poll();
            stack.push(temp.data);
            if(temp.right!=null){
                q.add(temp.right);
            }
            if(temp.left!=null){
                q.add(temp.left);
            }
        }
        while(!stack.empty()){
            arr.add(stack.pop());
        }
        return arr;
    }

    public static void main(String[] args) {
        root = new Node(1);
        root.left = new Node(5);
        root.right = new Node(4);
        root.left.left = new Node(8);
        root.left.right = new Node(3);
        ArrayList<Integer> arr = new ArrayList<Integer>();
        arr = reverseLevelOrder();
        System.out.println(arr);
    }
}