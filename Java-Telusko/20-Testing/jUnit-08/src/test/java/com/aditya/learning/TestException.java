package com.aditya.learning;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class TestException {
	SortingArray order = new SortingArray();
	
	@Test
	void testSortingArrayException() {
//		try {
//			int unsorted[] = null;
//			int sorted[] = order.sortingArray(unsorted);
//			System.out.println("Statements below Exception");
//			fail();
//		}
//		catch(NullPointerException e){
//			System.out.println("Exception generated");
//		}
		int unsorted[] = null;
		assertThrows(NullPointerException.class, ()-> order.sortingArray(unsorted));
	}

}
