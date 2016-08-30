/*
* The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate span of stock’s price for all n days. 
* The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days
* just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
* Example: 
* if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, 
* then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}
 */
package G4G;

/**
 *
 * @author Vivek Sharma
 */
import java.io. *;
import java.util.*;

public class stockSpan {
    public static void main(String[] arg) throws IOException{
        int N, i;
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        N = Integer.parseInt(br.readLine());
        
        String str[] = br.readLine().split(" ");
        
        int stock[] = new int[N+1];
        int span[] = new int[N+1];
        
        for(i = 1; i <= N; i++){
     
            stock[i] = Integer.parseInt(str[i-1]);
        }
  ///   1st method: T(n) = O(n), S(n) = O(n)
        Stack st = new Stack();
        
        st.push(0);
        span[0] = 1;
        
        for(i = 1; i < N; i++){
            while(!st.empty() && stock[(Integer)st.peek()] <= stock[i]){
                st.pop();
            }
            
            span[i] = st.empty()?i+1:i-(Integer)st.peek();
            st.push(i);
        }
        for(i = 0; i < N; i++){
            System.out.print(span[i] + " ");
        }
   ///
   
  /* 2nd Method: T(n) = O(n), S(n) = O(n)
       int last[] = new int[N+1];
       int j;
       
       span[1] = 1;
       last[1] = 0;
       
       for(i = 2; i <= N; i++){
           if(stock[i] < stock[i-1]){
               span[i] = 1;
               last[i] = i-1;
           }
           else{
               span[i] = 1 + span[i-1];
               j = last[i-1];
               
               while(stock[j] <= stock[i] && j >= 1){
                   span[i]++;
                   j--;
               }
               last[i] = j;
           }
       }
       
       for(i = 1; i <= N; i++){
           System.out.print(span[i] + " ");
       }
       System.out.println();
       for(i = 1; i <= N; i++){
           System.out.print(last[i] + " ");
       }
      */  
    }
}
