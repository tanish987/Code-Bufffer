

/**
 * Given a number x, print all possible non-increasing sequences with sum equals to x.

    Example: Input: x = 3
             Output: 1 1 1
                     2 1
                     3
 */
package G4G;

/**
 *
 * @author Vivek Sharma
 */
import java.io.*;

public class printDecSeq {
    public static void main(String[] ar) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int x = Integer.parseInt(br.readLine());
        
        int data[] = new int[x];
        
        enumerate(0, 0, x, 0, data);
        
    }
    
    static void enumerate(int last, int count, int sum , int index, int data[]){
        if(sum == 1){
            System.out.println("1");
            return;
        }
        if(count == sum){
            index--;
            while(index >= 0){
                System.out.print(data[index] + " ");
                index--;
            }
            System.out.println();
            return;
        }
        else if(count > sum){
            return;
        }
        
        for(int i = 1; i <= sum; i++){
            
            if(i >= last){
                data[index] = i;
         
                enumerate(i, count+i, sum, index+1, data);
            }
            
        }
    }
}
