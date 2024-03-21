/*

    █▀▄▀█ █▀▀█ █▀▀ █▀▀ █▀▀ ─█▀▀█ █▀▀▄ █▀▀ █───█ █▀▀█ █── █──█ 
    █░█░█ █──█ ▀▀█ █▀▀ ▀▀█ ░█▄▄█ █──█ █▀▀ █▄█▄█ █──█ █── █──█ 
    █──░█ ▀▀▀▀ ▀▀▀ ▀▀▀ ▀▀▀ ░█─░█ ▀▀▀─ ▀▀▀ ─▀─▀─ ▀▀▀▀ ▀▀▀ ─▀▀▀

*/

import java.util.Scanner;
import java.util.Random;

// Pokemon Battle is the Main implementation of this class 

public class PokemonBattle {

    public static void main(String[] args) {

        Random rand = new Random();

        Scanner scan = new Scanner(System.in);

        String pokemonName, rivalPokemonName  = "";

        double rivalPokemonHealth = (rand.nextDouble() * 20.0) + 40.0;

        int totalTurns = 0;

        System.out.println("Enter your Pokemon's name: ");
        pokemonName = scan.nextLine();
        System.out.println("Enter your rival Pokemon's nickname: ");
        rivalPokemonName = scan.nextLine();

        System.out.println(String.format("Your rival has chosen %s to fight, which has %f health.", rivalPokemonName, rivalPokemonHealth));

        do {

            // Select a Random Attack Type
            AttackType attack = AttackType.values()[rand.nextInt(AttackType.values().length)];

            int attackDamage = 0;

            double totalDamage = 0;

            switch(attack) {
                case SCRATCH:
                    totalDamage = ((rand.nextDouble() * 5.0) + 1.0) * (rand.nextInt(3) + 1);
                    break;

                case TACKLE:
                    totalDamage = (rand.nextDouble() * 7.0) + 2.0;
                    break;
                
                case SURF:
                totalDamage = (rand.nextDouble() * 2.0) + 7.0;
                    break;
            }

            rivalPokemonHealth -= totalDamage;

            totalTurns++;

            System.out.println(String.format("%s used %s and did %f damage. Your rival has %f health remaining.", pokemonName, attack.toString(), totalDamage, rivalPokemonHealth < 0 ? 0 : rivalPokemonHealth));
                
        } while (rivalPokemonHealth <= 0);

        System.out.println(String.format("%s fainted after %d turns!", rivalPokemonName, totalTurns));

        System.out.printf("You have earned $%f!", (rand.nextDouble() * 1200.0) * -1 + 2400.0);

    }

}
