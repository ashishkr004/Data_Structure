import java.util.*;
import java.io.*;


public class sorting{
	static void swap(int a[], int i, int j){
		int t1=a[i];
		int t2=a[j];
		a[i]=t2;
		a[j]=t1;
	}

	static void insertionSort(int a[]){
		int l=a.length;
		int i=0;
		while(i<l){
			int j=i;
			if(i>0){
				while(a[j]<a[j-1]){
					swap(a,j,j-1);
					j--;
					if(j==0){
						break;
					}
				}					
			}
			i++;
		}
	}

	static void selectionSort(int a[]){
		for(int i=0; i<a.length; i++){
			int c=i;
			for(int j=i; j<a.length; j++){
				if(a[c]>a[j]){
					c=j;
				}
			}
			if(c!=i){
				swap(a,i,c);
			}
		}
	}

	static void bubbleSort(int a[]){
		int l=a.length-1;
		while(l>0){
			int i=0;
			while(i<l){
				if(a[i]>a[i+1]){
					swap(a,i,i+1);
				}
				i++;
			}
			l--;
		}
	}


	public static void main(String[] args){
		int[] nums1 = new int[]{33, 11, 44, 22, 55, 66, 99, 77, 88, 10};
		insertionSort(nums1);
		System.out.println("The result of insertion sort on 33, 11, 44, 22, 55, 66, 99, 77, 88, 10 is: ");
		for (int i=0; i<nums1.length; i++){
			System.out.println(nums1[i]);
		}

		int[] nums2 = new int[]{30, 10, 40, 20, 50, 60, 90, 70, 80, 100};
		bubbleSort(nums2);
		System.out.println("The result of insertion sort on 30, 10, 40, 20, 50, 60, 90, 70, 80, 100 is: ");
		for (int i=0; i<nums2.length; i++){
			System.out.println(nums2[i]);
		}

		int[] nums3 = new int[]{35, 15, 45, 25, 55, 65, 95, 75, 85, 5};
		selectionSort(nums3);
		System.out.println("The result of insertion sort on 35, 15, 45, 25, 55, 65, 95, 75, 85, 5 is: ");
		for (int i=0; i<nums3.length; i++){
			System.out.println(nums3[i]);
		}
	}
}