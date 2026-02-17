package ChainOfResponsibilityDesignPattern;

import ChainOfResponsibilityDesignPattern.Dispensers.Dispenser;
import ChainOfResponsibilityDesignPattern.Dispensers.DispenseChain;
import java.util.Scanner;

public class ATMDispenser {
	private DispenseChain chain;

	public ATMDispenser() {
		// Set up the chain: 2000 -> 500 -> 200 -> 100
		DispenseChain d2000 = new Dispenser(2000);
		DispenseChain d500 = new Dispenser(500);
		DispenseChain d200 = new Dispenser(200);
		DispenseChain d100 = new Dispenser(100);

		d2000.setNextChain(d500);
		d500.setNextChain(d200);
		d200.setNextChain(d100);

		this.chain = d2000;
	}

	public void requestAmount(int amount) {
		if (amount <= 0 || amount % 100 != 0) {
			System.out.println("Amount must be positive and in multiples of 100.");
			return;
		}
		chain.dispense(new Currency(amount));
	}

	public static void main(String[] args) {
		ATMDispenser atm = new ATMDispenser();
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter amount to withdraw in multiple of 100: ");
		int amount = scanner.nextInt();
		atm.requestAmount(amount);
		scanner.close();
	}
}
