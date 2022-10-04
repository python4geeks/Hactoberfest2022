import java.util.*;
class BT{
    static Node root;
    static class Node{
        Node left,right;
        int data;
        Node(int d){
            data = d;
            left = null;
            right = null;
        }
    }

    static void inorder(Node temp){
        if(temp == null){
            return;
        }
        inorder(temp.left);
        System.out.println(temp.data+" ");
        inorder(temp.right);
    }
    
    static Node insertion(Node temp,int item){
        if(temp == null){
            temp = new Node(item);
            System.out.println(item+" Inserted");
            return temp;
        }
        else if(item < temp.data){
            temp.left = insertion(temp.left,item);
        }
        else if(item > temp.data){
            temp.right = insertion(temp.right,item);
        }
        return temp;
    }
    public static void main(String[] args) {
        root = insertion(root,1);
        insertion(root,2);
        insertion(root,3);
        insertion(root,4);
        insertion(root,5);
        insertion(root,6);
        insertion(root,7);
        System.out.println("Traversing.............");
        inorder(root);

        

    }
}