

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class Task_1433F {

    public static void main(String[] args) {
        FastScanner in = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);

        int i, j, n = in.nextInt(), m = in.nextInt(), k = in.nextInt();

        long[][] a = new long[n+1][m+1];
        for(i = 1; i <= n; i++)
            for(j = 1; j <= m; j++)
                a[i][j] = in.nextLong();

        long[][] dpmods = new long[n+1][k];

        for(long[] x: dpmods)
            Arrays.fill(x, -1);
        dpmods[0][0] = 0;

        for(i = 1; i <= n; i++) {
            long[][] dp = new long[m/2+1][k];
            for(long[] x: dp)
                Arrays.fill(x, -1);
            dp[0][0] = 0;

            for(j = 1; j <= m; j++) {
                for(int z = m/2-1; z >= 0; z--) {
                    for(int mod = 0; mod < k; mod++) {
                        if(dp[z][mod] == -1) continue;
                        dp[z+1][(int)(mod+a[i][j])%k] = Math.max(dp[z+1][(int)(mod+a[i][j])%k], dp[z][mod] + a[i][j]);
                    }
                }
            }

            for(int mod = 0; mod < k; mod++) 
                for(int z = 0; z <= m/2; z++)
                    dp[m/2][mod] = Math.max(dp[m/2][mod], dp[z][mod]);

            for(int mod1 = 0; mod1 < k; mod1++) {
                if(dpmods[i-1][mod1] == -1) continue;
                for(int mod2 = 0; mod2 < k; mod2++) {
                    if(dp[m/2][mod2] > -1) 
                        dpmods[i][(int)(mod1+mod2)%k] = Math.max(dpmods[i][(int)(mod1+mod2)%k], dpmods[i-1][mod1] + dp[m/2][mod2]);
                }
            }
        }
        out.println(dpmods[n][0]);
        out.close();
    }

    // Template copied from @SecondThread because I was too lazy
    // to make my own and I'm probably never going to use Java again
    static void sort(int[] a) {
        ArrayList<Integer> l = new ArrayList<>();
        for(int i : a) l.add(i);
        Collections.sort(l);
        for(int i = 0; i < a.length; i++) a[i] = l.get(i);
    }
    
    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");
        String next() {
            while(!st.hasMoreTokens())
                try { st = new StringTokenizer(br.readLine()); }
                catch(IOException e) { e.printStackTrace(); }
            return st.nextToken();
        }
        
        int nextInt() { return Integer.parseInt(next()); }
        long nextLong() { return Long.parseLong(next()); }

        int[] readArray(int n) {
            int[] a = new int[n];
            for(int i = 0; i < n; i++) a[i] = nextInt();
            return a;
        }
    }
}
/**
    ThN CVz#roagh King sOts in his t$rone
    bith the MiVa$ kouch and a hexrt SB ejone
    An empiEe buil^ xv hQilA and greed
    A bleevine #round foV Shose who Keez

**/