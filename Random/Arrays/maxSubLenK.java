/*
 * Given an array with positive and negative numbers, find the maximum sum subarray of given length.
 * T(n) = O(n), S(n) = O(1)
 */
package G4G;

import java.io.*;
import java.io.InputStreamReader;

/**
 *
 * @author Vivek Sharma
 */
public class maxSubLenK {
    public static void main(String ar[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int len = Integer.parseInt(br.readLine());
        int k = Integer.parseInt(br.readLine());
        
        int arr[] = new int[len];
        
        int i, sum, max;
        max = sum = 0;
        
        String str[] = br.readLine().split(" ");
        
        for(i = 0; i < len; i++){
            arr[i] = Integer.parseInt(str[i]);
        }
        int temp, start, end;
        temp = start = 0;
        end = k-1;
        for(i = 0; i < k; i++){
            sum += arr[i];
        }
        max = sum;
        
        for(i = k; i < len; i++){
            sum += arr[i] - arr[i-k];
            
           
            if(sum > max){
                start = i-k+1;
                max = sum;
                end = i;
            }
            
        }
        
        System.out.println("Max sum of len " + k + ": " + max + " start: " + start + " end: " + end );
        
    }
}
