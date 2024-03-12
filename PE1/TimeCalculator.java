// Moses Adewolu
//  

public class TimeCalculator {
    
    public static void main(String[] args) {

        double homeworkTIme = 3.99;

        double lectureTIme = 1.25;

        int numLectures = 4;

        double breakTIme = 0.53;

        double travelAdjustment = 0.08;

        double timeTotal = 0.0;

        timeTotal += homeworkTIme / 2;
        timeTotal += lectureTIme * numLectures;
        timeTotal -= breakTIme * 3;
        timeTotal *= (1 + travelAdjustment);

        double timeTotalTrunc = (int) (timeTotal * 100) / 100.0;

        System.out.println("You're busy for " + timeTotalTrunc + " hours.");

        int totalHours = 24;

        totalHours -= timeTotalTrunc;

        System.out.println("You hjave " + totalHours + " hours remaining in the day.");

    }

}
