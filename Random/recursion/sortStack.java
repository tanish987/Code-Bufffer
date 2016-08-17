/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package G4G;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

/**
 *
 * @author Vivek Sharma
 */
public class sortStack {
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
			st.push(inpt[i]);
		}
		
		sort(st);
		
		for(i = 0; i < size; i++){
			System.out.println(st.pop());
		}
		
	}
	
	static void sort(Stack st){
		int k;
		if(!st.empty()){
			k = (Integer)st.pop();
			sort(st);
			insertAtLast(st, k);
		}
	}
	
	static void insertAtLast(Stack st, int k){
		int n;
		if(!st.empty() && (Integer)st.peek() > k){
			n = (Integer)st.pop();
			insertAtLast(st, k);
                        st.push(n);
		}
                else if(st.empty() || (!st.empty() && (Integer)st.peek() <= k)){
			st.push(k);
			return;
		}
	//	st.push(n);
	}
}
