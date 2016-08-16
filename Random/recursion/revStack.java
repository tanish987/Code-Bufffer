/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package G4G;

import java.io.*;
import java.util.Stack;

/**
 *
 * @author Vivek Sharma
 */
public class revStack {
    public static void main (String[] args) throws java.lang.Exception
	{
		Stack st = new Stack();
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int size = Integer.parseInt(br.readLine());
		int inpt[] = new int[size];
	
		int i;
		
		String[] input = br.readLine().split(" ");
		
		for(i = 0; i < size; i++){
			inpt[i] = Integer.parseInt(input[i]);
			st.push(input[i]);
		}
		
		reverse(st);
		
		for(i = 0; i < size; i++){
			System.out.println(st.pop());
		}
		
	}
	
	static void reverse(Stack st){
		Object k;
		if(!st.empty()){
			k = st.pop();
			reverse(st);
			insertAtLast(st, k);
		}
	}
	
	static void insertAtLast(Stack st, Object k){
		Object n;
		if(!st.empty()){
			n = st.pop();
			insertAtLast(st, k);
		}
		else{
			st.push(k);
			return;
		}
		st.push(n);
	}
}
