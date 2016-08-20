/**
 * Given two sorted arrays A and B, generate all possible arrays such that first element is taken from A then from B then from A and so on in increasing order till the arrays exhausted. The generated arrays should end with an element from B.

    For Example 
    A = {10, 15, 25}
    B = {1, 5, 20, 30}

    The resulting arrays are:
    10 20
    10 20 25 30
    10 30
    15 20
    15 20 25 30
    15 30
    25 30
 */


package G4G;
import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class sortedArMs
{
	public static void main (String[] args) throws java.lang.Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int na, nb, i;
		
		na = Integer.parseInt(br.readLine());
		nb = Integer.parseInt(br.readLine());
		
		int A[] = new int[na];
		int B[] = new int[nb];
		int data[] = new int[na+nb+10];
		
		String str[] = br.readLine().split(" ");
	
		for(i = 0 ; i < na; i++){
			A[i] =  Integer.parseInt(str[i]);
		}
		
		String str1[] = br.readLine().split(" ");
		
		for(i = 0 ; i < nb; i++){
			B[i] =  Integer.parseInt(str1[i]);
		}
		
		data[0] = 0;
		
		rec(A, B, 0, na, nb, 1, data);
		
	}
	static void rec(int A[], int B[], int op, int na, int nb, int index, int data[] )
	{
		
		int list[] = (op == 0)?A:B;
		int end = (op == 0)?na-1:nb-1;
		
		int k = Arrays.binarySearch(list, 0, end+1, data[index-1]);
             //   System.out.println("k: " + k);
                k = (-1)*k -1;
                
		for(int i = k; i <= end; i++){
                 
			data[index] = list[i];
			if(op == 1){
				for(int j = 1; j <= index; j++){
					System.out.print(data[j] + " ");
				}
				System.out.println();
                     
			}
			
				rec(A, B, (op == 0)? 1:0, na, nb, index+1, data);
			
		}
	}
}