package ObserverDesignPattern;

import ObserverDesignPattern.Observable.*;
import ObserverDesignPattern.Observer.*;
public class Store {
    public static void main(String[] args) {
        StocksObservable iPhoneStockObservable = new iPhoneObservable();
        NotifyObserver observer1 = new EmailObserver("xyz@example.com", iPhoneStockObservable);
        NotifyObserver observer2 = new EmailObserver("abc@example.com", iPhoneStockObservable);
        NotifyObserver observer3 = new MobileObserver("1234567890", iPhoneStockObservable);

        iPhoneStockObservable.add(observer1);
        iPhoneStockObservable.add(observer2);
        iPhoneStockObservable.add(observer3);
        
        iPhoneStockObservable.setStockCount(10);
        iPhoneStockObservable.setStockCount(5);
        iPhoneStockObservable.remove(observer2);
        iPhoneStockObservable.setStockCount(20);

        
    }
}
