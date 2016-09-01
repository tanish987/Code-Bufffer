/*
 * Maximum sum subarray of len atleast K.
 * T(n) = O(n), S(n) = O(1).
 */
package G4G;
import java.io.*;
/**
 *
 * @author Vivek Sharma
 */
public class maxSubSum_V2 {
    public static void main(String[] arg)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int len = Integer.parseInt(br.readLine());
        int k = Integer.parseInt(br.readLine());
        int i;
        
        String str[] = br.readLine().split(" ");
        int arr[] = new int[len];
        
        for(i = 0; i < len; i++){
            arr[i] = Integer.parseInt(str[i]);
        }
        int sum, max;
        int tempStart, tempEnd, start, end;
        sum = 0;
        for(i = 0; i < k; i++){
            sum += arr[i];
        }
        max = sum;
        
        tempStart = start = 0;
        tempEnd = end = k-1;
        
        for(i = k; i < len; i++){
            if(sum+arr[i] > sum + arr[i] - arr[tempStart]){
                sum += arr[i];
                tempEnd = i;
            }
            else{
                sum += arr[i] - arr[tempStart];
                tempEnd = i;
                tempStart++;
            }
            if(max < sum){
                max = sum;
                start = tempStart;
                end = tempEnd;
            }
        }
        
        System.out.println("Maximum Sum: " + max + " start: " + start + " end: " + end);
        
    }
}
