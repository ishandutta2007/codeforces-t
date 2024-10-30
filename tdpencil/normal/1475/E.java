import java.util.*;
import java.io.*;
import java.lang.Math;


public class A {
	
	static int INF = -2_000_000_000;
	static long fac[]=new long[20000];
	static long MOD = 1_000_000_007;
	public static void main(String args[]) {
		FastScanner fs = new FastScanner();
		precalc();
		int t = fs.nextInt();
		long dp[][] = new long[1001][1001];
		for(int i = 0; i <= 1000; i++) {
			dp[i][0]=dp[i][i]=1;
		}
		
		for(int i = 1; i <= 1000; i++) {
			for(int j=1; j <=i; j++) {
				dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%MOD;
			}
		}
		for (int test_case = 1; test_case <= t; test_case++) {
			int n=fs.nextInt(),k=fs.nextInt();
			
			int a[]=new int[n];
			for (int i = 0; i<n; i++)
				a[i]=fs.nextInt();
			
			Arrays.sort(a);
			for (int i = 0; i < n / 2; i++) {
				int temp=a[i];
				a[i]=a[n-1-i];
				a[n-1-i]=temp;
			}
			int cnt2[] = new int[n+1];
			for (int i : a)
				++cnt2[i];
			int cnt[] = new int[n+1];
			ArrayList<Integer> c=new ArrayList<>();
			for (int i = 0; i < k; i++) {
				c.add(a[i]);
			}
			
			for (int i : c)
				++cnt[i];
			
			TreeSet<Integer> ts=new TreeSet<>();
			for (int i : c)
				ts.add(i);
			
			long ans=1;
			for (int i : ts) {
				//cnt is the frequency in the array
				//cnt2 is the frequency that we use
				// choose(n, k) = n!/k!(n-k)!
				int n1=cnt2[i];
				int k1=cnt[i];
				ans *= dp[n1][k1];

				ans %= MOD;
			}
			System.out.println(ans);
		}
	}
	static long choose(int n, int k) {
		return (fac[n]/((fac[k]*fac[n-k])))%MOD;
	}
	
	static void precalc() {
		fac[0]=1;
		for(long i = 1; i < 20000; i++)
			fac[(int)i]=(fac[(int)i-1]*i)%MOD;
	}
	
	
	
	static class Pair implements Comparable<Pair>{
		int first, second;
		public Pair(int x, int y) {
			first=x;second=y;
		}
		public int compareTo(Pair x) {
			if(this.first<x.first)
				return -1;
			if(this.first==x.first)
				return this.second<x.second?-1:(this.second==x.second?0:1);
			return 1;
		}
	}
	
	
	
	
	static class RangeMin {
		long logs[], st[][];
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

		long query(int L, int R) {
			int j = (int)logs[R-L+1];
			return Math.min(st[L][j], st[R - (1 << j) + 1][j]);
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
	
	static class SegmentTree {
    	int leftmost, rightmost;
    	SegmentTree lChild, rChild;
    	int sum;
    	long lz_val;
    	
    	public SegmentTree(int l, int r, int a[]) {
    		leftmost = l;
    		rightmost = r;
    		lz_val=0;
    		if(l == r)
    			sum = a[l];
    		else {
    			int mid = (l + r) / 2;
    			lChild = new SegmentTree(l, mid, a);
    			rChild = new SegmentTree(mid+1, r, a);
    			update();
    		}
    	}
    	public void update() {
    		sum = lChild.sum + rChild.sum + (int)lChild.lz_val + (int)rChild.lz_val;
    	}
    	public void pointUpdate(int pos, int val) {
    		if(leftmost == rightmost) {
    			sum = val;
    		} else {
    			int mid = (leftmost + rightmost) / 2;
    			if(pos <= lChild.rightmost) lChild.pointUpdate(pos, val);
    			else rChild.pointUpdate(pos, val);
    			update();
    		}
    	}
    	public void rangeUpdate(int l, int r, int val) {
    		// first check if it's within the range
    		if(l <= leftmost && r >= rightmost) {
    			lz_val += val;
    		} else {
    			// its not within the range so lets update the left if we have to and update the right if we have to
    			if(lChild.rightmost >= l) lChild.rangeUpdate(l, r, val);
    			if(rChild.leftmost <= r) rChild.rangeUpdate(l, r, val);
    			update();
    		}
    	}
    	public long query(int l, int r) {
    		if(l > rightmost || r < leftmost) return 0;
    		else if(l <= leftmost && r >= rightmost) return sum + lz_val;
    		
    		return (long) lChild.query(l, r) + (long) rChild.query(l, r);
    	}
    }
}