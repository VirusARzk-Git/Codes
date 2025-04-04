package com.aditya.course;

public class JavaCourse implements Course {

	@Override
	public boolean coursePurchased() {
		System.out.print("Java Course Purchased");
		return true;
	}
	
}
