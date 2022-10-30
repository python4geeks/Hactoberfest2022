import java.util.*;

public class BitwiseBlend {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0){
            int n = sc.nextInt();
            int arr[] = new int[n];

            for (int i = 0; i < arr.length; i++) {
                arr[i] = sc.nextInt();
            }

            boolean oddPresent = false;
            boolean odd = false;
            boolean even = false;

            for(int i = 0;i<n;i++){
                if((arr[i]&1) == 1){
                    oddPresent = true;
                    if((i&1) == 0)
                        even = true;
                    else odd = true;
                }
            }

            if(!oddPresent){
                System.out.println(-1);
                continue;
            }

            ArrayList<Integer> oddarr = new ArrayList<>();
            ArrayList<Integer> evenarr = new ArrayList<>();

            int oddPos = -1;
            int evenPos = -1;

            if(odd){

                for(int i = 0; i < n; i++){

                    if((arr[i]&1) == 1 && (i&1) == 1){
                         oddPos = i; 
                         break;
                    }
                      

                }

                for(int i = 0; i < n;i++){
                    if( (i&1) == 1 &&  (arr[i]&1) == 0){
                        oddarr.add(i+1);
                        oddarr.add(oddPos+1);
                    }
                    else if((i&1) == 0 && (arr[i] &1) == 1 && i!=oddPos){
                        oddarr.add(i+1);
                        oddarr.add(oddPos+1);
                    }

                }
            
        }
            if(even){

                for(int i = 0; i < n; i++){

                    if((arr[i]&1) == 1 && (i&1) == 0){
                         evenPos = i; 
                         break;
                    }
                      

                }

                for(int i = 0; i < n;i++){
                    if((arr[i]&1) == 0 && (i&1) == 0){
                        evenarr.add(i+1);
                        evenarr.add(evenPos+1);
                    }
                    else if((arr[i]&1) == 1 && (i&1) == 1 && i!=evenPos){
                    evenarr.add(i+1);
                    evenarr.add(evenPos+1);
                    }
                }
            
        }
        System.out.println(evenarr);
        System.out.println(oddarr);

        if(oddarr.isEmpty()){
            
                System.out.println(evenarr.size()/2);
                for(int i = 0; i<evenarr.size()-1;i=i+2){
                    System.out.print(evenarr.get(i)+" "+ evenarr.get(i+1));
                }
        }
            if(evenarr.isEmpty()){

                System.out.println(oddarr.size()/2);
                for(int i = 0; i<oddarr.size()-1;i=i+2){
                    System.out.print(oddarr.get(i)+" "+ oddarr.get(i+1));
                }

            }

        if(!evenarr.isEmpty() && !oddarr.isEmpty()){
            if(evenarr.size()<=oddarr.size()){
                System.out.println(evenarr.size()/2);
                for(int i = 0; i<evenarr.size()-1;i=i+2){
                    System.out.print(evenarr.get(i)+" "+ evenarr.get(i+1));
                }
            }

            else{

                System.out.println(oddarr.size()/2);
                for(int i = 0; i<oddarr.size()-1;i=i+2){
                    System.out.print(oddarr.get(i)+" "+ oddarr.get(i+1));
                }

            }
        }

            


            
            

        }
    }
}
    
