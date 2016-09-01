/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package G4G;
import java.io.*;
/**
 *
 * @author Vivek Sharma
 */
public class maxSumSub {
    public static void main(String[] arg) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int len = Integer.parseInt(br.readLine());
        
        int arr[] = new int[len];
        
        String str[] = br.readLine().split(" ");
        
        int i;
        for(i = 0; i < len; i++){
            arr[i] = Integer.parseInt(str[i]);
        }
        
        int max = sumSub(arr, 0, len-1);
        
        System.out.println("Maximum subarray sum: " + max);
    }
    
    static int sumSub(int arr[], int l, int r){
        if(l == r){
            return arr[l];
        }
        else {                  // l > r: this will never happen
            int mid = (l+r)/2;
            int sumL = sumSub(arr, l, mid);
            int sumR = sumSub(arr, mid+1, r);
            
            int sumCr = crossSum(arr, l, mid, r);
            
            int max1 = sumL > sumR?sumL:sumR;
            
            return (max1>sumCr?max1:sumCr);
            
        }
        
    }
    
    static int crossSum(int arr[], int l, int m, int r){
        int i;
        
        int sumL = 0, sumR = 0;
        int maxL, maxR;
        maxL = maxR = Integer.MIN_VALUE;
        
        for(i = m; i >= l; i--){
            sumL += arr[i];
            if(sumL > maxL){
                maxL = sumL;
            }
        }
        
        for(i = m+1; i <= r; i++){
            sumR += arr[i];
            if(sumR > maxR){
                maxR = sumR;
            }
        }
        
        return maxL+maxR;
        
    }
}
