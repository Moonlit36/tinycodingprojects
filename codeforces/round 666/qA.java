

import java.io.*;
import java.util.*;
 
 
public class qA{
    /** 
     * this thing was for codeforces qa round 666
     */
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
         
         //first number - number of "times" you get to check the chunks of alphabet soup for whehter they're equaliseable
         int num_iterations = sc.nextInt();
         for(int i = 0; i < num_iterations; i++) {
             int num_lines = sc.nextInt(); //huw many alphabet soup lines there will be
             //String[] mealong = new String[num_lines];
             //List<String> mealong = new ArrayList<String>();
             boolean toggle = true; //have I outputted a response to this chunk?
             Hashtable<String, Integer> mealong = new Hashtable<String, Integer>();//how many times each character appears overall - this is sort of a dictionary, keys are strings, values are integers
             for(int j = 0; j < num_lines; j++) {
                 String s = sc.nextLine();
                 //scan line as string, add to mealong char by char
                 for (int v = 0; v < s.length(); v++){
                     char c = s.charAt(v);
                     if (mealong.containsKey(Character.toString(c))) {
                         mealong.put(Character.toString(c), mealong.get(Character.toString(c))+1); //if char in mealong, increment value
                        }
                     else {
                         mealong.put(Character.toString(c), 1);//if char not in mealong, add it with a value of one
                        }
                     
                 }
             }
             //if any of the values are not divisible by the number of lines, it don't work, so out you put the NO; otherwise YES
             //basically if there are like 3 lines but 5 characters of a certain type, there is no way to evenly share the chars across the lines
             for (int r : mealong.values()) {
                 if ((r % num_lines != 0) && toggle == true) {
                     toggle = false;
                     out.println("NO");
                 }
             }
             if (toggle == true) {
                 out.println("YES");
             }
            }
      
      
      
         // Stop writing your solution here. -------------------------------------
         out.close();
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




















/*
 * Write a description of class qA here.
 *
 * @author (your name)
 * @version (a version number or a date)
 
public class qA
{
    // instance variables - replace the example below with your own
    private int x;

     /*
     * Constructor for objects of class qA
     * /
    public qA()
    {
        // initialise instance variables
        x = 0;
    }

    /**
     * An example of a method - replace this comment with your own
     *
     * @param  y  a sample parameter for a method
     * @return    the sum of x and y
     * /
    public int sampleMethod(int y)
    {
        // put your code here
        return x + y;
    }
}
*/
