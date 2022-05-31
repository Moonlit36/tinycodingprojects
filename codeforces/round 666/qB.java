
import java.io.*;
import java.util.*;

import java.lang.Math; 
 
 
public class qB{
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        
        // Start writing your solution here. -------------------------------------
        
        /*
         * int n      = sc.nextInt();        // read input as integer
         * long k     = sc.nextLong();       // read input as long
         * double d   = sc.nextDouble();     // read input as double
         * String str = sc.next();           // read input as String
         * String s   = sc.nextLine();       // read whole line as String
         * 
         * int result = 3*n;
         * out.println(result);                    // print via PrintWriter
           */
        
        int num_nums = sc.nextInt();
        ArrayList<Integer> leest = new ArrayList<Integer>();
        for (int i = 0; i < num_nums; i++) {
            leest.add(sc.nextInt()); //new Integer(sc.nextInt())
        }
        
        Collections.sort(leest);
        
        for (int i = 0; i < num_nums; i++) {
            //
        }
        
        //int yay = (int) Math.round(Math.pow(10, 14));
        //long basenum = 
        
        //for 
        
        
        // Stop writing your solution here. -------------------------------------
        out.close();
    }
    
    public static boolean checkPowers (ArrayList<Integer> arr) {//but how do you decide the base number? answer: n-1th root of the n-1th number, round to whole number????
        for (int u = 0; u < arr.size(); u++) {
            if (Math.pow(arr.get(1), u) != arr.get(u)) {
                return false;
            }
        }    
        return true;
    }

    
    //public String[] mealong;
    //-----------PrintWriter for faster output---------------------------------
    public static PrintWriter out;
      
    //-----------MyScanner class for faster input----------
    public static class MyScanner {
       BufferedReader br;
       StringTokenizer st;
  
       public MyScanner() {
          br = new BufferedReader(new InputStreamReader(System.in));
       }
  
       String next() {
           while (st == null || !st.hasMoreElements()) {
               try {
                   st = new StringTokenizer(br.readLine());
               } catch (IOException e) {
                   e.printStackTrace();
               }
           }
           return st.nextToken();
       }
  
       int nextInt() {
           return Integer.parseInt(next());
       }
  
       long nextLong() {
           return Long.parseLong(next());
       }
  
       double nextDouble() {
           return Double.parseDouble(next());
       }
  
       String nextLine(){
           String str = "";
       try {
          str = br.readLine();
       } catch (IOException e) {
          e.printStackTrace();
       }
       return str;
       }
 
    }
    //--------------------------------------------------------
}
