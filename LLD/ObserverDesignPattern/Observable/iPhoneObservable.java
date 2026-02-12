package ObserverDesignPattern.Observable;

import java.util.List;

import ObserverDesignPattern.Observer.NotifyObserver;

public class iPhoneObservable implements StocksObservable {

  public List<NotifyObserver> observers = new java.util.ArrayList<>();
  public int stockCount = 0;

  @Override
  public void add(NotifyObserver observer) {
    observers.add(observer);
  }

  @Override
  public void remove(NotifyObserver observer) {
    observers.remove(observer);
  }

  @Override
  public void notifyObservers() {
    for (NotifyObserver observer : observers) {
      observer.update();
    }
  }

  @Override
  public void setStockCount(int newStockAdded) {
    if (stockCount == 0 && newStockAdded > 0) {
      notifyObservers();
    }
    this.stockCount += newStockAdded;
  }

  @Override
  public int getStockCount() {
    return this.stockCount;
  }
}
