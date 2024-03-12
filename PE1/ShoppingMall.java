// Moses Adewolu
// "I'm an extremely deep thinker"

public class ShoppingMall {

    public static void main(String args[]) {

        int x = 2;
        int y = 5;
        
        while (x != y) {
            x = x*=2;
            if (x > y) {
                x = x - y;
            } else {
                y = y + 1;
            }
            if (x == y) {
                System.out.println("Caught");
            }
        }
        }

    /* 
    public static void main(String[] args) {
        
        int cash  = 100;
        double taxRate = 1.13;
        double subtotal = 58.62;

        String name  = "Moses";

        double change = cash - subtotal * taxRate;

        double changeTrunc = (int) (change * 100) / 100;

        System.out.println(name + " has $" + changeTrunc + " dollars remaining!\n" + name + " started with $" + cash + " dollars!");
    
    }
    */
}