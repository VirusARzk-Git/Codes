package ObserverDesignPattern.Observable;

import ObserverDesignPattern.Observer.NotifyObserver;

public interface StocksObservable {
    public void add(NotifyObserver observer);
    public void remove(NotifyObserver observer);
    public void notifyObservers();
    public void setStockCount(int newStockAdded);
    public int getStockCount();
}
