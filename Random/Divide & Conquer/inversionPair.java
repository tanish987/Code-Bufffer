/**
 * Inversion Count for an array indicates – how far (or close) the array is from being sorted.
 * If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum. 
   Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j
 */
package G4G;
import java.io.*;
/**
 *
 * @author Vivek Sharma
 */
public class inversionPair {
    
    public static void main(String[] args) throws IOException{
        
        int i;
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int len = Integer.parseInt(br.readLine());
        
        int arr[] = new int[len];
        
        String[] str = br.readLine().split(" ");
        
        for(i = 0; i < len; i++){
            arr[i] = Integer.parseInt(str[i]);
        }
        
        int n_ip = inverseUsingMS(arr, 0, len-1);
        
        System.out.println("Inversion Pairs: " + n_ip);
    }
    
   static int inverseUsingMS(int arr[], int l, int r){
        if(l < r){
            int mid = (l+r)/2;
            int c1 = inverseUsingMS(arr, l, mid);
            c1 += inverseUsingMS(arr, mid+1, r);
            c1 += countInverse(arr, l, mid, r);
            return c1;
        }
        else{
            return 0;
        }
    }
    
    static int countInverse(int arr[], int l, int p, int r){
        int L[] = new int[p-l+2];
        int R[] = new int[r-p+1];
        int i;
        
        for(i = 0; i < p-l+1; i++){
            L[i] = arr[i+l];
  //          System.out.print(L[i] + " ");
        }
        L[i] = Integer.MAX_VALUE;
 //       System.out.println();
        
        for(i = 0; i < r-p; i++){
            R[i] = arr[i+p+1];
   //         System.out.print(R[i] + " ");
        }
        R[i] = Integer.MAX_VALUE;
 //       System.out.println();
//        System.out.println("l: " + l + " p: " + p + " r: " + r );
        
        int k, count = 0;
        int j;
        i = j = 0;
        
        for(k = l; k <= r; k++){
            if(L[i] <= R[j]){
                arr[k++] = L[i++];
            }
            else{
                arr[k++] = R[j++];
                count += p - (i+l) + 1;
            }
        }
   //     System.out.println("count: " + count);
        return count;
        
    }
}
