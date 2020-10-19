import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Task_4A {

    public static void main(String[] args) {
        FastScanner in = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);

        int i, n = in.nextInt();
        out.println(n%2 == 0 && n > 2? "YES" : "NO");

        out.close();
    }

    // Template copied from @SecondThread
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