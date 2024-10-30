// package com.company;

// import com.sun.source.tree.Tree;

import java.io.*;
import java.util.*;
import java.lang.*;
public class Main {

    public static void main(String[] args) {
        FastScanner fs=new FastScanner();
        int T = 1;
        PrintWriter out=new PrintWriter(System.out);
        BookStack right = new BookStack(), left = new BookStack();
        while(T-- > 0) {
            int N = fs.nextInt(), M=fs.nextInt(), K= fs.nextInt();
            int A[] = new int[N];
            for(int i = 0; i < N; i++)
                A[i]=fs.nextInt();
            int l = 0, r = N - 1;
            while(l < r) {
                int mid = (l + r) / 2;
                if(works(K, M, A, mid)) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }

            out.println(N - l);
        }

        out.close();
    }

    static boolean works(int sizes, int boxes, int A[], int L) {
        int curSizes = 0;
        boxes--;
        for(int i = L; i < A.length; i++) {
            if(curSizes + A[i] > sizes) {
                boxes--;
                curSizes = A[i];
            } else {
                curSizes += A[i];
            }
        }

        return boxes >= 0;
    }
    static class BookStack {
        int added;
        ArrayList<Book> stack;
        // find book by value
        HashMap<Integer, Integer> ids;

        public BookStack() {
            stack=new ArrayList<>();
            ids=new HashMap<>();
            added = 0;
        }
        int size() {
            assert(stack.size() == added);
            return added;
        }
        void add(Book bk) {
            ++added;
            stack.add(bk);
            ids.put(bk.val, added);

        }
        boolean containsBook(Book bk) {
            return ids.containsKey(bk.val);
        }
        int getBook(Book bk) {
            if(!containsBook(bk)) assert(false);
            return added - ids.get(bk.val);
        }
    }
    static class Book {
        int id, val;
        public Book(int id, int val) {
            this.id = val;
            this.val = id;
        }

        public Book() {
            this.id = 0;
            this.val = 0;
        }
    }

    static class RangeMin {
        long logs[], st[][];
        // sparse table?
        int N, K;
        public RangeMin(int n) {
            N=n;
            K = (int)((double) (Math.log10((double)n) /(double) Math.log10((double)2) ));
            st = new long [N+2][K+2];
            logs = new long[N+2];
        }
        void init(ArrayList<Integer> A) {

            for(int i = 0; i < N; i++) {
                Arrays.fill(st[i], (long)1e18);
                st[i][0]=(long)A.get(i);
            }
            // NLOGN
            for(int j = 1; j <= K; j++) {
                for(int i = 0; i + (1<<j) <= N; i++) {
                    st[i][j]=Math.min(st[i][j-1], st[i + (1 << (j-1))][j-1]);
                }
            }
            logs[1]=0;
            for(int i = 2; i <= N; i++) {
                logs[i]=logs[i/2]+1;
            }
        }
        void init(int [] A) {

            for(int i = 0; i < N; i++) {
                Arrays.fill(st[i], (long)1e18);
                st[i][0]=(long)A[i];
            }
            // NLOGN
            for(int j = 1; j <= K; j++) {
                for(int i = 0; i + (1<<j) <= N; i++) {
                    st[i][j]=Math.min(st[i][j-1], st[i + (1 << (j-1))][j-1]);
                }
            }
            logs[1]=0;
            for(int i = 2; i <= N; i++) {
                logs[i]=logs[i/2]+1;
            }
        }

        long query(int L, int R) {
            int j = (int)logs[R-L+1];
            return Math.min(st[L][j], st[R - (1 << j) + 1][j]);
        }
    }

    static class Pair implements Comparable<Pair>{
        long first, second;
        public Pair(long l, long i) {
            first=l;second=i;
        }
        public Pair() {
            first=0;second=0;
        }
        public int compareTo(Pair x) {
            if(this.first<x.first)
                return -1;
            if(this.first==x.first)
                return Long.compare(this.second, x.second);
            return 1;
        }
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
        public int max(int a[]) {
            int mx = Integer.MIN_VALUE;
            for(int i : a)
                mx = Math.max(i, mx);
            return mx;
        }
        public int count(int a[], int val) {
            int ans =0;
            for(int i : a)
                ans += val == i ? 1 : 0;
            return ans;
        }
        public int min(int a[]) {
            int mn = Integer.MAX_VALUE;
            for(int i : a)
                mn = Math.min(i, mn);
            return mn;
        }
        public void randomShuffleSort(int []a) {
            Random r = new Random();
            for(int i =0; i < (a.length)/2; i++) {
                int temp=a[i],p=r.nextInt(a.length);
                a[i]=a[p];
                a[p]=temp;
            }
            Arrays.sort(a);
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