/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Striver;
import java.util.*;
/**
 *
 * @author Nitish Kumar Maurya
 */
public class Graph3_BFS {
    public static ArrayList<Integer> bfsOfGraph(int n,ArrayList<ArrayList<Integer>>adj)
    {
        ArrayList<Integer>bfs=new ArrayList<>();
        boolean []visit=new boolean[n+1];
        for(int i=1;i<=n;i++)
        {
            if(visit[i]==false)
            {
                Queue<Integer>q1=new LinkedList<>();
                q1.add(i);
                visit[i]=true;
                while(!q1.isEmpty())
                {
                    Integer kp=q1.poll();
                    bfs.add(kp);
                    for(Integer it:adj.get(kp))
                    {
                        if(visit[it]==false)
                        {
                            visit[it]=true;
                            q1.add(it);
                        }
                    }
                }
            }
        }
        return bfs;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=7,w=6;
        ArrayList<ArrayList<Integer>>adj=new ArrayList<ArrayList<Integer>>();
        
        for(int i=0;i<=n;i++)
        {
            adj.add(new ArrayList<Integer>());
        }
        for(int i=0;i<w;i++)
        {
            int u=sc.nextInt(),v=sc.nextInt();
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        ArrayList<Integer>bfs=bfsOfGraph(n,adj);
        for(Integer it:bfs)
        {
            System.out.print(it+" ");
        }
    }
}
