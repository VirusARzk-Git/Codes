package com.aditya.course;

public class SpringBootCourse implements Course {
	@Override
	public boolean coursePurchased() {
		System.out.print("SpringBoot Course Purchased");
		return true;
	}
}
