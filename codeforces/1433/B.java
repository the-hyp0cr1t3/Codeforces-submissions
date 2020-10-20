/**
 🍪 the_hyp0cr1t3
 🍪 20.10.2020 20:33:14
**/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Task_1433B {

    public static void main(String[] args) {
        FastScanner in = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        int q = in.nextInt();
        for(int tc = 1; tc <= q; tc++)
            new solve(tc, in, out);
        out.close();
    }

    static class solve {
        FastScanner in; PrintWriter out;
        
        solve(int testnumber, FastScanner in, PrintWriter out) {
            this.in = in; this.out = out;
            int i, n = in.nextInt();
            int[] a = in.readArray(n);
            int z = 0;
            for(i = 0; i < n; i++)
                if(a[i] == 0) z++;
            for(i = 0; i < n; i++) {
                if(a[i] == 1) break;
                z--;
            }
            for(i = n-1; i >= 0; i--) {
                if(a[i] == 1) break;
                z--;
            }
            out.println(z);
        }
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
    WQen py nane bkcoseS tomurrowhs news
    Tn top of OhE mountaKn I cannot Ce movZK
    I scaPS the awmmit liqe an uBstoppabls uorce
    With iron witgs I wilO $rowe my worRu NF you akl

**/