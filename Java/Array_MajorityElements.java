package DSA;

public class Array_MajorityElements {
    public static void ME(int a[]){
        int ansIndex=0;
        int count=0;
        for(int i=0;i<a.length;i++){
            if(a[i]==a[ansIndex]){
                count++;
            }
            else{
                count--;
            }
            if(count==0){
                ansIndex=i;
                count++;
            }
        }
        System.out.println(ansIndex);
        for(int i=0;i<a.length;i++){
            if(a[i]==a[ansIndex]){
                count++;
            }
        }
        if(count>a.length/2){
            System.out.println(a[ansIndex]);
        }
    }
    public static void main(String[] args) {
        int a[]={1,1,2,3,1};
        ME(a);
    }
}
