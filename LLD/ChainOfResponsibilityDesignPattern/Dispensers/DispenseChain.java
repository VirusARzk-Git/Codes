package ChainOfResponsibilityDesignPattern.Dispensers;

import ChainOfResponsibilityDesignPattern.Currency;

public interface DispenseChain {
    public void setNextChain(DispenseChain nextChain);
    public void dispense(Currency cur);
}