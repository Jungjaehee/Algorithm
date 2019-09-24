package algorithm;

import java.util.*;
public class Q1 {
	static int binarySearch(int []a, int key, int left, int right) {
		int mid;
		if(left <= right) {
			mid=(left+right)/2;
			if(key==a[mid])
				return mid;
			else if(key<a[mid])
				return binarySearch(a,key,left,mid-1);
			else
				return binarySearch(a,key,mid+1,right);
		}
        return -1;
	}
	static int[] sorting(int []a) {
		int tmp;
		for(int i=0;i<a.length;i++) {
			for(int j=i+1;j<a.length;j++) {
				if(a[i]>a[j]) {
					tmp=a[i]; a[i]=a[j]; a[j]=tmp;
				}
			}
		}
		return a;
	}
	public static void main(String[] args) {
		Scanner scanner= new Scanner(System.in);
		Random random=new Random();
		int []a=new int[10];
		int key;
		for(int i=0;i<a.length;i++) 
			a[i]=random.nextInt(100);
		sorting(a);
		int left=0;
		int right=a.length-1;
		System.out.println("찾을 숫자를 입력하시오 : ");
		key=scanner.nextInt();
		System.out.println(binarySearch(a,key,left,right));
	}

}

