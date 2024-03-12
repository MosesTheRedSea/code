/*

    █▀▄▀█ █▀▀█ █▀▀ █▀▀ █▀▀ ─█▀▀█ █▀▀▄ █▀▀ █───█ █▀▀█ █── █──█ 
    █░█░█ █──█ ▀▀█ █▀▀ ▀▀█ ░█▄▄█ █──█ █▀▀ █▄█▄█ █──█ █── █──█ 
    █──░█ ▀▀▀▀ ▀▀▀ ▀▀▀ ▀▀▀ ░█─░█ ▀▀▀─ ▀▀▀ ─▀─▀─ ▀▀▀▀ ▀▀▀ ─▀▀▀

*/

public class Quinary {

    public static void main(String[] args) {
        
        int initialNum = 535;
        String answer = "";
        int zeroCount = 0;
        int oneCount = 0;
        int twoCount = 0;
        int threeCount = 0;
        int fourCount = 0;
        int currentNum = initialNum;

        while(currentNum != 0) {
            int digit = currentNum % 5;

            if (digit == 0) {
                zeroCount++;
            } else if (digit == 1) {
                oneCount++;
            } else if (digit == 2) {
                twoCount++;
            } else if (digit == 3) {
                threeCount++;
            } else if (digit == 4) {
                fourCount++;
            }
            answer = digit + answer;
            currentNum = currentNum / 5;
        }

        System.out.printf("Decimal Representation: %d \n", initialNum);

        System.out.printf("Quinary Representation: %s \n", answer);

        System.out.printf("%d zero(s), %d one(S), %d two(s), %d three(s), %d four(s)\n", zeroCount, oneCount, twoCount, threeCount, fourCount);

        int digitSum = (0 * zeroCount) + (1 * oneCount) + (2 * twoCount) + (3 * threeCount) + (4 * fourCount);

        switch(digitSum % 5) {
            case (0):
                System.out.println("The Quinary digits sum to a multiple of 5!");
                break;
            case (1):
                System.out.println("The Quinary digits almost summed to a multiple 5!");
                break;
            case (4):
                System.out.println("So close!");
                break;
            default:
                System.out.println("Nope!");
        }

       
        System.out.printf((zeroCount > oneCount && zeroCount > twoCount && zeroCount > threeCount && zeroCount > fourCount) ? "Zero is the most used digit" : "Zero is not the most used digit");
      
    }
}