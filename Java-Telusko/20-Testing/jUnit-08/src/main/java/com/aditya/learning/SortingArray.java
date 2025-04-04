package com.aditya.learning;

import java.util.Arrays;

public class SortingArray {
	public int[] sortingArray(int []arr)
	{
		for(int i = 0; i < 10000000; i++)
			Arrays.sort(arr);
		return arr;
	}
}
