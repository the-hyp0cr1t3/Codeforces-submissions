/**
 🍪 the_hyp0cr1t3
 🍪 20.10.2020 20:46:57
**/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.HashMap;

public class Task_1433D {

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
            HashMap<Integer, Integer> mp = new HashMap<Integer, Integer>();
            for(i = 0; i < n; i++)
                mp.put(a[i], 1);
            if(mp.size() == 1) 
                out.println("NO");
            else {
                int secondguy = 1;
                while(a[secondguy] == a[0]) secondguy++;
                out.println("YES");
                for(i = 1; i < n; i++) {
                    if(a[i] != a[0])
                        out.println((i+1) + " " + 1);
                    else if(i != secondguy)
                        out.println((i+1) + " " + (secondguy+1));
                }
            }
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
    Take a sSep Uut onv MoKt in tBe gra$e
    Catc@ a breath ,ubmeGgTd in R!ly wZtec
    WQtch a moKing Fcene of foGKer daVs
    Shed C tear Vs mamoCy starWs to faij!r

**/