package Vigenere;


import java.util.*;
import edu.duke.*;


public class Testing {
    public String p(String s) {
        System.out.println(s);
        return s;
    }
    
    public void testChar (char a, int b) {
        CaesarCipher cd = new CaesarCipher(b);
        p(cd.decryptLetter( p(cd.encryptLetter(a)+"").charAt(0) )+"");
        
    }
    
    public void test () {
        CaesarCipher cc = new CaesarCipher(3);
        /*/
        String x = p(cc.encrypt("1776. New York City. Pardon me, are you Aaron Burr, sir?"));
        p(cc.decrypt(x));
        testChar('e', 6);
        //*/
        /*/
        String a = "oslusiadas_key17.txt";
        FileResource z = new FileResource("Vigenere/smolmessages/" + a);
        CaesarCracker cb = new CaesarCracker('a');
        p(cb.decrypt(z.asString()));
        //*/
        
        
        /*/
        int[] key = {17, 14, 12, 4};
        VigenereCipher ab = new VigenereCipher(key);
        
        
        p(ab.decrypt("Tcmp-pxety mj nikhqv htee mrfhtii tyv"));
        
        p( ab.decrypt( p( ab.encrypt( z.asString() ) ) ) );
        //*/
        
        
        /*/
        VigenereBreaker vb = new VigenereBreaker();
        
        String a = "athens_keyflute" + ".txt";
        FileResource z = new FileResource("Vigenere/smolmessages/" + a);
        
        
        String y = p(z.asString());
        int[] yarrr = vb.tryKeyLength(y, 5, 'e');
        
        System.out.println();
        
        for (int u : yarrr) {
            p(u+"");
        }
        //*/
        
        
        /*/
        
        VigenereBreaker ab = new VigenereBreaker();
        
        p(ab.sliceString("abcdefghijklm", 0, 3) + " " + "adgjm");
        
        p(ab.sliceString("abcdefghijklm", 1, 3) + " " + "behk");
        
        p(ab.sliceString("abcdefghijklm", 2, 3) + " " + "cfil");
        
        p(ab.sliceString("abcdefghijklm", 0, 4) + " " + "aeim");
        
        p(ab.sliceString("abcdefghijklm", 1, 4) + " " + "bfj");
        
        p(ab.sliceString("abcdefghijklm", 2, 4) + " " + "cgk");
        
        p(ab.sliceString("abcdefghijklm", 3, 4) + " " + "dhl");
        
        p(ab.sliceString("abcdefghijklm", 0, 5) + " " + "afk");
        
        p(ab.sliceString("abcdefghijklm", 1, 5) + " " + "bgl");
        
        p(ab.sliceString("abcdefghijklm", 2, 5) + " " + "chm");
        
        p(ab.sliceString("abcdefghijklm", 3, 5) + " " + "di");
        
        p(ab.sliceString("abcdefghijklm", 4, 5) + " " + "ej");
        //*/
        
        
        
        
        String s = "19,13,10,11,13,14,5,6,25,20,18,20,12,15,9,19,0,13,15,4,15,20,15,19,0,25,17,15,17,8,16,24,19,11,9,13,6,20,8,8,21,14,23,16,6,23,21,4,3,12,16,16,22,6,10,21,20";
        System.out.println(s.split(",").length);
        
        
        
        
        
        
        
    }

}
