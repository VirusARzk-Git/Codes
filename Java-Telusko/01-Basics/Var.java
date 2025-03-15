class Var {

  public static void main(String[] args) {
    double price = 10.5;
    float tax = 0.01f;
    int quantity = 10;
    System.out.println("Total cost: " + price * quantity * (1 + tax));

    byte b = 127;
    short s = 32767;
    int i = 2147483647;
    long l = 9223372036854775807L;
    System.out.println("Byte: " + b);
    System.out.println("Short: " + s);
    System.out.println("Int: " + i);
    System.out.println("Long: " + l);

    char c = 'A';

    System.out.println("Char: " + c);
    c++;
    System.out.println("Increment Char: " + c);

    boolean flag = true;
    System.out.println("Boolean: " + flag);

    int num1 = 0xf;
    System.out.println("Hexadecimal: " + num1);

    double num2 = 3e307;
    System.out.println("Scientific: " + num2);

    byte by = 127;
    
    int by_to_int = by;
    System.out.println("Byte to Int: " + by_to_int);


    // casting
    int a = 250;
    // byte a_to_byte = a;
    byte a_to_byte = (byte) a;
    System.out.println("Int to Byte: " + a_to_byte);

    // range of byte is -128 to 127 = 256 = 2^8
    // range of short is -32768 to 32767 = 65536 = 2^16
    // range of int is -2147483648 to 2147483647 = 4294967296 = 2^32
    // range of long is -9223372036854775808 to 9223372036854775807 = 18446744073709551616 = 2^64

    
  }
}
