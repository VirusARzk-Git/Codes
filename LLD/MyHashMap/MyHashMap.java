package MyHashMap;

public class MyHashMap<K, V> {

  private static final int DEFAULT_CAPACITY = 1 << 4; // 16
  private static final int MAXIMUM_CAPACITY = 1 << 30;

  public Entry[] hashTable;

  public MyHashMap() {
    this.hashTable = new MyHashMap.Entry[DEFAULT_CAPACITY];
  }

  public MyHashMap(int capacity) {
    if (capacity < 0) {
      throw new IllegalArgumentException("Capacity must be non-negative");
    }
    if (capacity > MAXIMUM_CAPACITY) {
      capacity = MAXIMUM_CAPACITY;
    }
    this.hashTable = new MyHashMap.Entry[tableSizeFor(capacity)];
  }

  private static int tableSizeFor(int capacity) {
    int x = log2(capacity - 1) + 1;
    return 1 << x;
  }

  private static int log2(int n) {
    int log = 0;
    while (n > 1) {
      n >>= 1;
      log++;
    }
    return log;
  }

  class Entry {

    public K key;
    public V value;
    public Entry next;

    public Entry(K key, V value) {
      this.key = key;
      this.value = value;
      this.next = null;
    }
  }

  public void put(K key, V value) {
    int hashCode = key.hashCode() % hashTable.length;
    Entry node = hashTable[hashCode];

    if (node == null) {
      hashTable[hashCode] = new Entry(key, value);
      return;
    } else {
      Entry prev = null;
      while (node != null) {
        if (node.key.equals(key)) {
          node.value = value;
          return;
        }
        prev = node;
        node = node.next;
      }
      prev.next = new Entry(key, value);
    }
  }

  public V get(K key) {
    int hashCode = key.hashCode() % hashTable.length;
    Entry current = hashTable[hashCode];

    while (current != null) {
      if (current.key.equals(key)) {
        return current.value;
      }
      current = current.next;
    }
    return null;
  }

  public static void main(String[] args) {
    MyHashMap<Integer, String> map = new MyHashMap<>();
    map.put(1, "One");
    map.put(2, "Two");
    map.put(3, "Three");
    System.out.println(map.get(2));
    System.out.println(map.get(3));

    map.put(2, "Two Updated");
    System.out.println(map.get(2));
  }
}
