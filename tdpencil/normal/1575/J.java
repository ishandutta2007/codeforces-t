

import java.util.*;
import java.io.*;
import java.math.*;
public class A {
	
    public static void main(String[] args) {
    	PrintWriter out=new PrintWriter(System.out);
        FastScanner fs=new FastScanner();
        int te=1;
        for (int test=0; test<te; test++) {
        	int n = fs.nextInt();
        	int m = fs.nextInt();
        	int k = fs.nextInt();
        	int jmp[][] = new int[n][m];
        	for(int i = 0; i < n; i++) {
        		for(int j = 0; j < m; j++) {
        			jmp[i][j]=fs.nextInt();
        		}
        	}
        	int p = 0;
        	while(k-- > 0) {
        		
        		int i = 0, j = fs.nextInt()-1;
        		while(!(i==n-1&&jmp[i][j]==2)) {
        			if(jmp[i][j]==1) {
        				jmp[i][j]=2;
        				j++;
        			} else if(jmp[i][j]==2) {
        				i++;
        			} else {
        				jmp[i][j]=2;
        				j--;
        			}
        		}
        		out.print((j+1) + " ");
        	}
        }
        out.close();
    }
    
   
    static class TreeGraph {
    	boolean visited[];
    	int graph[][];
    	ArrayDeque<Integer> dq;
    	int depth[];
    	int frequency[];
    	int n;
    	public TreeGraph(int n) {
    		visited = new boolean[n];
    		graph = new int[n][];
    		dq=new ArrayDeque<>();
    		depth=new int[n];
    		frequency = new int[n];
    		this.n=n;
    	}
    	
    	public void addEdge(int u, int v) {
    		++frequency[u];
    		++frequency[v];
    		dq.add(u);
    		dq.add(v);
    	}
    	public void init() {
    		for(int i=0; i < n; i++)
    			graph[i]=new int[frequency[i]];
    		while(dq.size()>0) {
    			int u=dq.pollFirst(),v=dq.pollFirst();
    			graph[u][--frequency[u]] = v;
    			graph[v][--frequency[v]] = u;
    		}
    	}
    	public void dfs(int u, int d, int par) {
    		depth[u]=d;
    		for(int e : graph[u]) {
    			if(e != par) {
    				dfs(e, d + 1, u);
    			}
    		}
    	}
    }
    static class prefix_sum_2d {
        int p[][];
        int n;
        prefix_sum_2d(int s, int q, int g[][]) {
            n = 2 * Math.max(s, q) + 1;
            p = new int[n+1][n+1];
            for(int i = 0; i < s; ++i)
                for(int j = 0; j < n; ++j)
                    if(j<q)
                        p[i][j+1]=p[i][j]+g[i][j];
                    else
                        p[i][j+1]=p[i][j];
            for(int i = 0; i < n; ++i)
                for(int j = 0; j <= n; ++j)
                    p[i+1][j]+=p[i][j];
            int pp[][]=new int[n+2][n+1];
            for(int i =0 ; i <= n; ++i)
                for(int j = 0; j <= n; ++j)
                    pp[i+1][j]=p[i][j];
            p=pp;

        }

        public int query(int x1, int y1, int x2, int y2) {

            x1++;
            x2++;
            y1++;
            y2++;
            return p[x1-1][y1-1]+p[x2][y2]-p[x2][y1-1]-p[x1-1][y2];
        }
    }

    static class HopcroftKarp {
        int[] match;
        int[] dist;
        ArrayList<Integer>[] graph;
        int N;
        int M;
        int T;
        int INF = 1000000000;

        HopcroftKarp(int N, int M) {
            this.N=N;
            this.M=M;
            T = N+M+1;
            match = new int[T];
            dist = new int[T];
            graph = new ArrayList[T];
            for (int i = 0; i < T; i++)
                graph[i] = new ArrayList<Integer>();
        }


        void addEdge(int u, int v) {
            graph[u].add(v);
            graph[v].add(u);
        }

        boolean BFS() {
            ArrayDeque<Integer> q = new ArrayDeque<Integer>();
            for (int u = 1; u <= N; u++) {
                if (match[u]==0) {
                    dist[u] = 0;
                    q.add(u);
                } else {
                    dist[u] = INF;
                }
            }
            dist[0] = INF;
            while (!q.isEmpty()) {
                int u = q.pollFirst();
                if (dist[u]<dist[0]) {
                    for (int v: graph[u]) {
                        if (dist[match[v]] == INF) {
                            dist[match[v]] = dist[u]+1;
                            q.push(match[v]);
                        }
                    }
                }
            }
            return dist[0]<INF;
        }

        boolean DFS(int u) {
            if (u > 0) {
                for (int v: graph[u]) {
                    if (dist[match[v]]==dist[u]+1 && DFS(match[v])) {
                        match[v] = u;
                        match[u] = v;
                        return true;
                    }
                }
                dist[u] = INF;
                return false;
            }
            return true;
        }

        ArrayList<int[]> run() {
            int m = 0;
            while (BFS()) {
                for (int u = 1; u <= N; u++) {
                    if (match[u]==0 && DFS(u)) m++;
                }
            }
            ArrayList<int[]> ans = new ArrayList<>();
            for (int v = N+1; v <= N+M; v++) {
                if (match[v]>0)
                    ans.add(new int[]{match[v],v});
            }
            return ans;
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
        int ni() {
            return nextInt();
        }
        int nextInt()
        {
            return Integer.parseInt(next());
        }
        long nl() {
            return nextLong();
        }
        long nextLong()
        {
            return Long.parseLong(next());
        }
        double nd()
        {
            return nextDouble();
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
/*
when stuck:
    dp, see as ranges, greedy
    maybe intuition? ad-hoc?
    bs? bs with bitmasks?
    go backwards?
    solve for complement
    do stuff / write down
    draw? perhaps DAG or two pointers in disguise?
    template wrong?
    STOP PLAYING VALORANT
    STOP WATCHING TWITCH BOZO
WA:
    input right?
    N, M or N, K?
    list[0] when doesn't exist?
    is right DS for problem?
    998244353 or 1000000007?
    overflow
TLE:
    high constant factor? (switch to cpp bozo)
    while loop / for loop?
RTE:
    divide 0 ? overflow? maybe empty ds
    forgot to remove com.company


*/