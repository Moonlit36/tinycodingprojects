package Vigenere;

import java.util.*;
import edu.duke.*;

public class VigenereBreaker {
    public String sliceString(String message, int whichSlice, int totalSlices) {
        /* 
        int whichSlice, indicating 
        the index the slice should start from,
        
        int totalSlices indicating 
        the length of the key.)
        */
        
        String slice = "";
        
        for (int k = whichSlice; k < message.length(); k += totalSlices) {
            slice += message.charAt(k);
        }
        
        return slice;
    }

    public int[] tryKeyLength(String encrypted, int klength, char mostCommon) {
        int[] key = new int[klength];
        CaesarCracker cb = new CaesarCracker(mostCommon);
        
        for (int j = 0; j < klength; j++) {
            String currslice = sliceString(encrypted, j, klength);
            int currkey = cb.getKey(currslice);
            key[j] = currkey;
        }
        
        return key;
    }
    
    public HashSet<String> readDictionary (FileResource fr) {
        /*/
        All the dictionary files, 
        including the English dictionary file, 
        are included in the starter program you download. 
        They are inside the folder called ‘dictionaries’.
        //*/
        HashSet<String> dictionary = new HashSet<String>();
        
        for (String line : fr.lines()) {
            line = line.toLowerCase();
            dictionary.add(line);
        }
        
        return dictionary;
    }
    
    public int countWords(String message, HashSet<String> dictionary) {
        int countWords = 0;
        
        for (String bunch : message.split("\\W+")) {
            bunch = bunch.toLowerCase();
            if (dictionary.contains(bunch)) {
                countWords += 1;
            }
        }
        
        return countWords;
    }
    
    public String breakKnownLength (String encrypted, int klength, char mostCommon) {
        int[] key = tryKeyLength(encrypted, klength, mostCommon);
        VigenereCipher vc = new VigenereCipher(key);
        String decrypted = vc.decrypt(encrypted);
        return decrypted;
    }
    
    public char mostCommonCharIn (HashSet<String> dictionary) {
        //char ch = '';
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();
        
        for (String s : dictionary) {
            for (int c = 0; c < s.length(); c++) {
                char d = s.charAt(c);
                boolean well = Character.isLetter(d);
                if (! map.containsKey(d) && well) {
                    map.put(d, 1);
                }
                else if (map.containsKey(d)) {
                    map.put(d, map.get(d)+1);
                }
            }
        }
        
        char ans = '6';
        for (char x : map.keySet()) {
            if (ans == '6') {
                ans = x;
            }
            if (map.get(x) > map.get(ans)) {
                ans = x;
            }
        }
        
        return ans;
        
    }
    
    public String breakForLanguage (String encrypted, HashSet<String> dictionary) {
        
        char mostCommn = mostCommonCharIn(dictionary);
        
        String output = "";
        int currmax = 0;
        String keystring = "";
        System.out.println("HELP I'VE BEEN INFESTED");
        //encrypted.length() not really
        for (int k = 1; k <= 100; k++) {
            
            System.out.println("YEERK " + k);
            
            int[] key = tryKeyLength(encrypted, k, mostCommn);
            VigenereCipher vc = new VigenereCipher(key);
            String decrypted = vc.decrypt(encrypted);
            
            int wordiness = countWords(decrypted, dictionary);
            
            if (wordiness > currmax) {
                output = decrypted;
                currmax = wordiness;
                
                if ((encrypted.split("\\W+").length - wordiness) < (encrypted.split("\\W+").length/10)) {
                    keystring = printKey(key);
                    System.out.println("NOT SURE the key: " + keystring + "  num valid words: " + currmax);
                    
                }
                
            }
            
            
        }
        System.out.println("d'awwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww security poofs!!!!" + "\n the key: " + keystring + "  num valid words: \n" + currmax);
        
        return output;
    }
    
    public void breakForAllLangs (String encrypted, HashMap<String, HashSet<String>> languages) {
        String output = "";
        int currmax = 0;
        String language = "";
        
        for (String lang : languages.keySet()) {
            System.out.println("Barnes also approves of " + lang);
            String plaintext = breakForLanguage(encrypted, languages.get(lang));
            int wordiness = countWords(plaintext, languages.get(lang));
            
            if (wordiness > currmax) {
                output = plaintext;
                currmax = wordiness;
                language = lang;
            }
        }
        
        System.out.println(language);
        System.out.println(output.substring(0, 300));
        
    }
    
    public void breakVigenere () {
        
        FileResource fr = new FileResource();
        String message = fr.asString();
        
        //English
        
        
        HashMap<String, HashSet<String>> langu = new HashMap<String, HashSet<String>>();
        String[] langnames = {"Danish", "Dutch", "English", "French", "German", "Italian", "Portuguese", "Spanish"};
        
        for (String lang : langnames) {
            System.out.println("Cat Eleanor approves of " + lang);
            FileResource fur = new FileResource("Vigenere/dictionaries/" + lang);
            HashSet<String> dictionary = readDictionary(fur);
            langu.put(lang, dictionary);
        }
        
        breakForAllLangs(message, langu);
        
        
        
    }
    
    public String printKey (int[] key) {
        String securitypoof = "\n" + "{";
        for (int u : key) {
            securitypoof += u + ",";
        }
        securitypoof += "}" + "\n";
        //System.out.print(securitypoof);
        return securitypoof;
    }
}
