package com.aditya.learning;

import static org.junit.jupiter.api.Assertions.*;

import java.time.Duration;

import org.junit.jupiter.api.Test;

class PerformanceTest {

	@Test
	void testSortingMethodPerformance() {
		SortingArray order = new SortingArray();
		int unsorted[] = {};
		assertTimeout(Duration.ofMillis(25),() -> order.sortingArray(unsorted));
	}

}
