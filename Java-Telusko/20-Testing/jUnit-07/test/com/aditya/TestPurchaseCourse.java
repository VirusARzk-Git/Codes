package com.aditya;

import com.aditya.course.*;
import com.aditya.service.PurchaseCourse;
import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class TestPurchaseCourse {

	@Test
	void testProceedWithCourse() {
		PurchaseCourse pc = new PurchaseCourse();
		boolean status = pc.proceedWithCourse(new JavaCourse());
		assertTrue(status);
	}

}
