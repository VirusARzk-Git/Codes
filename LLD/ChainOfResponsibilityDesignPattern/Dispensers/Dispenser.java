package ChainOfResponsibilityDesignPattern.Dispensers;

import ChainOfResponsibilityDesignPattern.Currency;

public class Dispenser implements DispenseChain {
    private final int denomination;
    private DispenseChain nextChain;

    public Dispenser(int denomination) {
        this.denomination = denomination;
    }

    @Override
    public void setNextChain(DispenseChain nextChain) {
        this.nextChain = nextChain;
    }

    @Override
    public void dispense(Currency cur) {
        int num = cur.getAmount() / denomination;
        int remainder = cur.getAmount() % denomination;
        if (num > 0) {
            System.out.println("Dispensing " + num + " notes of " + denomination);
        }
        if(remainder > 0)
            nextChain.dispense(new Currency(remainder));
    }
}
