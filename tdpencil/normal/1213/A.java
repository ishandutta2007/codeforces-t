//package cf;

import java.util.*;
import java.io.*;
import java.lang.*;

public class A {
	public static void main(String args[]) {
		FastScanner fs = new FastScanner();
		int n = fs.nextInt();
		int c = 0;
		ArrayList<Integer> q = new ArrayList<>();
		for(int i=0; i < n; i++)
			q.add(fs.nextInt());
		for(int i: q) c += 1 & i;
		System.out.println(Math.min(n-c, c));
	}
    static class FastScanner 
    { 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastScanner() 
        { 
            br = new BufferedReader(new
                     InputStreamReader(System.in)); 
        } 
  
        String next() 
        { 
            while (st == null || !st.hasMoreElements()) 
            { 
                try
                { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e) 
                { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
  
        int nextInt() 
        { 
            return Integer.parseInt(next()); 
        } 
  
        long nextLong() 
        { 
            return Long.parseLong(next()); 
        } 
  
        double nextDouble() 
        { 
            return Double.parseDouble(next()); 
        } 
  
        String nextLine() 
        { 
            String str = ""; 
            try
            { 
                str = br.readLine(); 
            } 
            catch (IOException e) 
            { 
                e.printStackTrace(); 
            } 
            return str; 
        }
        public int[] nextArray(int n) {
            int a[] = new int[n];
            for(int i =0; i < n; i++) a[i]=this.nextInt();
            return a;
        }
        public void randomShuffleSort(int []a) {
            for(int i =0; i < (a.length)/2; i++) {
                int temp=a[i];
                a[i]=a[(a.length)-1-i];
                a[(a.length)-1-i]=temp;
            }
            this.fine_sort(a);
        }
        public void fine_sort(int a[]) {
            ArrayList<Integer> A = new ArrayList<>();
            for(int i : a) A.add(i);
            Collections.sort(A);
            for(int i=0; i < a.length; i++) {
                a[i]=A.get(i);
            }
        } 
    }
   
}