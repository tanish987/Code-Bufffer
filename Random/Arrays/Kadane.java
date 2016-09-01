/*
 * Largest Sum Contiguous Subarray(Kadane Algo)
 * It will not work for all negative numbers. Firstly, check if all are -ve or not.
 */
package G4G;
import java.io.*;
/**
 *
 * @author Vivek Sharma
 */
public class Kadane {
    public static void main(String[] a) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int len = Integer.parseInt(br.readLine());
        
        int arr[] = new int[len];
        
        int i;
        
        String str[] = br.readLine().split(" ");
        
        for(i = 0; i < len; i++){
            arr[i] = Integer.parseInt(str[i]);
        }
        
        int max, sum;
        max = sum = 0;
        
        int temp, start, end = 0;
        temp = start = 0;
        for(i = 0; i < len; i++){
            sum += arr[i];
            
            if(sum < 0){
                temp = i+1;
                sum = 0;
            }
            else if(sum > max){
                max = sum;
                start = temp;
                end = i;
            }
        }
        
        System.out.println("Max sum: " + max + " start: " + start + " end: " + end);
    }
}
