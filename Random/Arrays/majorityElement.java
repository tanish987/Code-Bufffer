/**
 * Write a function which takes an array and emits the majority element (>=n/2), otherwise prints NONE as follows:

       I/P : 3 3 4 2 4 4 2 4 4
       O/P : 4 

       I/P : 3 3 4 2 4 4 2 4
       O/P : NONE
 */
package G4G;
import java.io.*;
/**
 *
 * @author Vivek Sharma
 */
public class majorityElement {
    public static void main(String[] arg) throws IOException{
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int len = Integer.parseInt(br.readLine());
        int i;
        
        int arr[] = new int[len];
        
        String[] str = br.readLine().split(" ");
        for(i = 0; i < len; i++){
            arr[i] = Integer.parseInt(str[i]);
        }
        
        int candidate = findCandidate(arr, len);
        int count = 0;
        
        for(i = 0; i < len; i++){
            if(candidate == arr[i]){
                count++;
            }
        }
        
        if(count >= len/2 + 1){
            System.out.println("Majority Element: " + candidate);
        }
        else{
            System.out.println("NONE");
        }
        
    }
    
    static int findCandidate(int arr[], int len){
        
        int max_index = 0, count = 0, i;
        
        for(i = 1; i < len; i++){
            if(arr[max_index] == arr[i]){
                count++;
            }
            else{
                count--;
            }
            if(count == 0){
                max_index = i;
                count = 1;
            }
        }
        
        return arr[max_index];
    }
}
