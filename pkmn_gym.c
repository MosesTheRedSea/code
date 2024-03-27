/**
 * @file pkmn_gym.c
 * @author Moses Adewolu
 *
 * @date 2024-03-25
 */

// DO NOT MODIFY THE INCLUDE(S) LIST
#include "pkmn_gym.h"

// DO NOT MODIFY THE GLOBAL VARIABLE(S) LIST
struct Gym gym;

// ALWAYS check the validity of the passed in arguments
// (i.e. not NULL, in the correct range, not too long)

// If any of the parameters are invalid, the function should
// do nothing and return FAILURE.


/** register_trainer
 * @brief Add a new trainer to the gym with the provided parameters.
 * @param name the name of the trainer
 * @return FAILURE if parameters invalid or the gym is full, SUCCESS otherwise
*/
int register_trainer(const char *name) {
    UNUSED_PARAM(name);

    if (name == NULL || *name == '\0') {
        return FAILURE;
    }

    // Check if gym is full
    if (gym.num_trainers >= MAX_TRAINER_LENGTH) {
        return FAILURE;
    }

    // Check if name is too long
    size_t n =  my_strlen(name);

    if (n >= MAX_NAME_LENGTH) {
        return FAILURE; // Name too long
    }

    my_strncpy(gym.trainers[gym.num_trainers].name, name, n);
    gym.trainers[gym.num_trainers].name[n] = '\0'; 
    gym.trainers[gym.num_trainers].party_size = 0;
    gym.trainers[gym.num_trainers].num_wins = 0;
     gym.num_trainers++;

    return SUCCESS;
}

/** unregister_trainer
 * @brief Removes a trainer from the gym.
 * @param name the name of the trainer
 * @return FAILURE if parameters invalid or the trainer is not found, SUCCESS otherwise
*/
int unregister_trainer(const char *name) {
    UNUSED_PARAM(name);

    
    if (name == NULL || *name == '\0') {
        return FAILURE;
    }

    // Check if name is too long
    size_t n =  my_strlen(name);
    int found = -1;

    if (n >= MAX_NAME_LENGTH) {
        return FAILURE; // Name too long
    }

    for (int i = 0; i < gym.num_trainers; ++i) {
        if (my_strncmp(gym.trainers[i].name, name, MAX_NAME_LENGTH) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        return FAILURE;
    }

    for (int i = found; i < gym.num_trainers - 1; ++i) {
        gym.trainers[i] = gym.trainers[i + 1];
    }

    gym.num_trainers--;

    return SUCCESS;
}

/** catch_pokemon
 * @brief Creates a new Pokémon and adds it to
 * the trainer's party.
 * @param trainer pointer to the trainer who caught this Pokémon
 * @param species the species of the Pokémon caught
 * @param level the level of the Pokémon caught
 * @return FAILURE if parameters invalid or the trainer's party is full, SUCCESS otherwise
*/
int catch_pokemon(struct Trainer *trainer, const char *species, int level) {
    UNUSED_PARAM(trainer);
    UNUSED_PARAM(species);
    UNUSED_PARAM(level);

    if (species == NULL || trainer == NULL || trainer->party_size >= MAX_PARTY_LENGTH || my_strlen(species) >= MAX_NAME_LENGTH) {
        return FAILURE;
    }

    if (level < 1 || level > 100) {
        return FAILURE;
    }

    struct Pokemon my_pokemon;
    my_strncpy(my_pokemon.species, species, my_strlen(species));
    my_pokemon.level = level;

    trainer->party[trainer->party_size] = my_pokemon;
    trainer->party_size++;

    return SUCCESS; 
}

/** release_pokemon
 * @brief Removes a Pokémon from a trainer's party.
 * @param trainer pointer to the trainer who is releasing a Pokémon
 * @param species the species of the Pokémon to release
 * @return FAILURE if parameters invalid or the Pokémon is not found in the trainer's party, SUCCESS otherwise
*/
int release_pokemon(struct Trainer *trainer, const char *species) {
    UNUSED_PARAM(trainer);
    UNUSED_PARAM(species);

    int found = -1;

    if (species == NULL || trainer == NULL) {
        return FAILURE;
    }
 
    // Check if empty
    if (trainer->party_size == 0) {
        return FAILURE;
    }  

    for (int i = 0; i < trainer->party_size; ++i) {
        if (my_strncmp(trainer->party[i].species, species, MAX_NAME_LENGTH) == 0) {
            found = i;
            break;
        }
    }
    
    if (found == -1) {
        return FAILURE;
    }

    for (int i = found; i < trainer->party_size - 1; ++i) {
        trainer->party[i] = trainer->party[i + 1];
    }
    trainer->party_size--;

    return SUCCESS;
}

/** count_species
 * @brief Count the total number of Pokémon of a given species
 * out of the parties of every trainer in this gym.
 * @param species the name of the species to search for
 * @return FAILURE if parameters invalid, otherwise the number of Pokémon in the gym of the given species
*/
int count_species(const char *species) {
    UNUSED_PARAM(species);

    if (species == NULL || my_strlen(species) >= MAX_NAME_LENGTH) {
        return FAILURE;
    }

    int totalPokemon = 0;

    for (int i = 0; i < gym.num_trainers; ++i) {
        for (int j = 0; j < gym.trainers[i].party_size; ++j) {
            if (my_strncmp(gym.trainers[i].party[j].species, species, MAX_NAME_LENGTH) == 0) {
                totalPokemon++;
            }
        }
    }
    return totalPokemon;
}

/** trade_pokemon
 * @brief Trade two Pokémon between two trainers,
 * swapping their positions in their parties.
 * @param t0 pointer to the first trainer in the trade
 * @param party_index_0 the index of the Pokémon to trade in the first trainer's party
 * @param t1 pointer to the second trainer in the trade
 * @param party_index_1 the index of the Pokémon to trade in the second trainer's party
 * @return FAILURE if 
 *                  parameters invalid,
 *                  both Trainers are the same,
 *                  party_index_0 or party_index_1 do not point to pokemon,
 *         SUCCESS otherwise
*/
int trade_pokemon(struct Trainer *t0, int party_index_0, struct Trainer *t1, int party_index_1) {
    UNUSED_PARAM(t0);
    UNUSED_PARAM(party_index_0);
    UNUSED_PARAM(t1);
    UNUSED_PARAM(party_index_1);

    // Check if Trainer's are Null
     if (t0 == NULL || t1 == NULL || party_index_0 < 0 || party_index_1 < 0) {
        return FAILURE;
    }

     if (t0 == t1) {
        return FAILURE;
    }

    if (party_index_0 >= t0->party_size || party_index_1 >= t1->party_size) {
        return FAILURE;
    }

    struct Pokemon holder = t0->party[party_index_0];
    t0->party[party_index_0] = t1->party[party_index_1];
    t1->party[party_index_1] = holder;

    return SUCCESS;
}

/** battle_trainer
 * @brief Start a battle between two trainers.
 * 
 * The num_wins variable of the winner of this battle should
 * also be incremented to reflect the trainer's win.
 * 
 * @param challenger pointer to the trainer who initiated the battle
 * @param opponent pointer to the trainer who was initiated by the challenger
 * @return FAILURE if parameters invalid, 0 if the challenger wins, 1 if the opponent wins
*/
int battle_trainer(struct Trainer *challenger, struct Trainer *opponent) {
    UNUSED_PARAM(challenger);
    UNUSED_PARAM(opponent);

    if (challenger == NULL || opponent == NULL) {
        return FAILURE;
    }

    int challenger_wins = 0;
    int opponent_wins = 0;

    int num_matches = (challenger->party_size < opponent->party_size) ? challenger->party_size : opponent->party_size;

     for (int i = 0; i < num_matches; i++) {
        // Create the 2 Poke on that are fighting

        // Challenger Pokemon
        struct Pokemon *challenger_pokemon = &challenger->party[i];

        // Opponet Pokemon
        struct Pokemon *opponent_pokemon = &opponent->party[i];

        if (challenger_pokemon->level > opponent_pokemon->level) {
            challenger_wins++;
        } else if (opponent_pokemon->level > challenger_pokemon->level) {
            opponent_wins++;
        }
    }

    // Automatically award wins to the trainer with more Pokémon
    if (challenger->party_size > opponent->party_size) {
        challenger_wins += (challenger->party_size - num_matches);
    } else if (opponent->party_size > challenger->party_size) {
        opponent_wins += (opponent->party_size - num_matches);
    }

    // Determine the winner based on the number of wins
    if (challenger_wins > opponent_wins) {
        challenger->num_wins++;
        return 0;
    } else if (opponent_wins > challenger_wins) {
        opponent->num_wins++;
        return 1;
    } else {
        // Tie - opponent wins
        opponent->num_wins++;
        return 1;
    }
}

/** find_champion
 * @brief Find the CHAMPION!!! (i.e., the trainer in this gym with the most wins.)
 * If several trainers have the maximum number of wins, pick the first in the gym trainer array with
 *  the maximum wins.
 * @return a pointer to the Trainer with the most wins, NULL is the gym has no Trainers in it
*/
struct Trainer *find_champion(void) {
    if (gym.num_trainers == 0) {
        return NULL;
    }

    struct Trainer *champion = &gym.trainers[0];

    for (int i = 1; i < gym.num_trainers; i++) {
        champion = (gym.trainers[i].num_wins > champion->num_wins) ? &gym.trainers[i] : champion;
    }

    return champion;
}