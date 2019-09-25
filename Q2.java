package algorithm;
import java.util.*;
public class Q2 {
	static int[] sieveOfEratos(int []a) {
		a[1]=0;
		for(int i=2;i<(a.length/2)+1;i++) {
			if(a[i]==0)
				continue;
			for(int j=2;i*j<a.length;j++) {
				a[i*j]=0;
			}
		}
		return a;
	}
	public static void main(String[] args) {
		Scanner scanner=new Scanner(System.in);
		System.out.print("N ют╥б : ");
		int N=scanner.nextInt();
		int []a=new int[N+1];
		for(int i=0;i<a.length;i++)
			a[i]=i;
		a=sieveOfEratos(a);
		for(int i=0;i<a.length;i++)
			System.out.print(a[i]+" ");
		System.out.println();
	}

}
