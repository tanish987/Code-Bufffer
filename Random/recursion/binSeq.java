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
public class binSeq {
    public static void main(String[] arg) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        
        int len = Integer.parseInt(br.readLine());
        
        int data[] = new int[2*len];
        
        enumerate(0, 2*len, 0, data);
        
    }
    
    static void enumerate(int sum, int len, int index, int data[] ){
        if(index == len && sum == 0 ){
            for(int i = 0; i < index; i++){
                
                System.out.print(data[i] + " ");
            }
            System.out.println();
            return;
        }
        else if(index == len && sum != 0){
            return;
        }
        
        for(int i = 0; i <= 1; i++){
            data[index] = i;
            
            if(index >= len/2){
                enumerate(sum-i, len, index+1, data);
            }
            else{
                enumerate(sum+i, len, index+1, data);
            }
            
        }
        
    }
    
}
