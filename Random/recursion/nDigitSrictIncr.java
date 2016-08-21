
/**
 * Given number of digits n in a number, print all n-digit numbers whose digits are strictly increasing from left to right.
 * Input:  n = 2
    Output:  
    01 02 03 04 05 06 07 08 09 12 13 14 15 16 17 18 19 23 24 25 26 27 28 
    29 34 35 36 37 38 39 45 46 47 48 49 56 57 58 59 67 68 69 78 79 89 
 */
package G4G;

import java.io.*;

/**
 *
 * @author Vivek Sharma
 */
public class nDigitSrictIncr {
    public static void main(String[] ar) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int noDigit = Integer.parseInt(br.readLine());
        int data[] = new int[noDigit];
        enumerate(0, noDigit, 0, data); 
        
    }
    static void enumerate(int start, int noDigit, int index, int data[]){
        if(index == noDigit){
           
           for(int x = 0; x < index; x++){
               System.out.print(data[x] + " ");
           }
           System.out.println();
           return;
        }
        
        for(int i = start; i <= 9 && 9-i+1 >= noDigit-index; i++){
        //    System.out.println(" index " + index);
            data[index] = i;
            enumerate(i+1, noDigit, index+1, data);
        }
    }
}
