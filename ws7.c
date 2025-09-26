#define _CRT_SECURE_NO_WARNINGS
#define MAX_PATH_LENGTH 70

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct PlayerInfo {
    int lives;
    char symbol;
    int treasures_found;
    int past_positions[MAX_PATH_LENGTH];
};
struct GameInfo {
    int max_moves;
    int path_length;
    int bombs_positions[MAX_PATH_LENGTH];
    int treasure_position[MAX_PATH_LENGTH];
};
bool bomb_finder(const int arr[], const int pos) {
  return arr[pos - 1] == 1;
}
bool treasure_finder(const int arr[], const int pos) {
   return arr[pos - 1] == 1;
}

bool repeated_position(const int arr[], const int filled, const int number) {
    for (int r = 0; r < filled; r++) {
        if (arr[r] == number) return true;
    }
    return false;
}
int main(void) {
    struct PlayerInfo player_info;
    struct GameInfo game_info;
    int bomb_pos = 0, j = 0, treasures_pos = 0, k = 0, next_move = 0, t = 0;
    char symbol_history[MAX_PATH_LENGTH] = {0};

    memset(player_info.past_positions, 0, sizeof(player_info.past_positions));
    player_info.treasures_found = 0;

    printf("================================\n");
    printf("        Treasure Hunt!\n");
    printf("================================\n\n");
    printf("PLAYER Configuration\n--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player_info.symbol);
    do {
        printf("Set the number of lives: ");
        scanf("%d", &player_info.lives);
        if (player_info.lives < 1 || player_info.lives > 10) printf("     Must be between 1 and 10!\n");
    } while (player_info.lives < 1 || player_info.lives > 10);

    printf("Player configuration set-up is complete\n\n");
    printf("GAME Configuration\n------------------\n");

    do {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &game_info.path_length);

        if (game_info.path_length < 10 || game_info.path_length > MAX_PATH_LENGTH || game_info.path_length % 5 != 0) {
            printf("Must be a multiple of 5 and between 10-70!!!\n");
        }
    } while (game_info.path_length < 10 || game_info.path_length > MAX_PATH_LENGTH || game_info.path_length % 5 != 0);

    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game_info.max_moves);

        if (game_info.max_moves < player_info.lives || game_info.max_moves > (game_info.path_length * 0.75)) {
            printf("    Value must be between %d and %d\n", player_info.lives,
                (int)(game_info.path_length * 0.75));
        }
    } while (game_info.max_moves < player_info.lives || game_info.max_moves > (game_info.path_length * 0.75));

    printf("\nBOMB Placement\n--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game_info.path_length);

    while (bomb_pos < game_info.path_length) {
        printf("   Positions [%2d-", bomb_pos + 1);
        bomb_pos += 5;
        printf("%2d]: ", bomb_pos);

        for (int i = 0; i < 5; i++) {
            scanf("%d", &game_info.bombs_positions[j]);
            j++;
        }
    }
    printf("BOMB placement set\n\nTREASURE Placement\n------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game_info.path_length);

    while (treasures_pos < game_info.path_length) {
        printf("   Positions [%2d-", treasures_pos + 1);
        treasures_pos += 5;
        printf("%2d]: ", treasures_pos);

        for (int l = 0; l < 5; l++) {
            scanf("%d", &game_info.treasure_position[k]);
            k++;
        }
    }
    printf("TREASURE placement set\n\nGAME configuration set-up is complete...\n\n");
    printf("------------------------------------\nTREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\nPlayer:\n");
    printf("   Symbol     : %c\n", player_info.symbol);
    printf("   Lives      : %d\n", player_info.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\nGame:\n");
    printf("   Path Length: %d\n", game_info.path_length);
    printf("   Bombs      : ");

    for (int m = 0; m < game_info.path_length; m++) {
        printf("%d", game_info.bombs_positions[m]);
    }
    printf("\n   Treasure   : ");

    for (int n = 0; n < game_info.path_length; n++) {
        printf("%d", game_info.treasure_position[n]);
    }
    printf("\n====================================\n~ Get ready to play TREASURE HUNT! ~\n"
           "====================================\n");

    do {

        if (next_move == 0) printf("\n");
        else {
                printf("  ");
                for (int u = 0; u < game_info.path_length; u++) {
                    if (u == next_move - 1) printf("%c", player_info.symbol);
                    else printf(" ");
                }
        }

        printf("\n  ");
        for (int o = 0; o < game_info.path_length; o++) {
            if (symbol_history[o] != 0) printf("%c", symbol_history[o]);
            else printf("-");
        }

        printf("\n  ");
        for (int p = 1; p <= game_info.path_length; p++) {
            if (p % 10 == 0) printf("%d", p / 10);
            else {
                printf("|");
            }
        }
        printf("\n  ");

        for (int q = 1; q <= game_info.path_length; q++) {
            printf("%d", q % 10);
        }
        printf("\n+---------------------------------------------------+\n");
        printf(" Lives: %2d | Treasures: %2d | Moves Remaining: %2d\n", player_info.lives,
            player_info.treasures_found, game_info.max_moves);
        printf("+---------------------------------------------------+\n");

        do {
            printf("Next Move [%2d-%2d]: ", 1, game_info.path_length);
            scanf("%d", &next_move);

            if (next_move < 1 || next_move > game_info.path_length) printf("  Out of Range!!!\n");

        } while (next_move < 1 || next_move > game_info.path_length);

        if (repeated_position(player_info.past_positions, t, next_move)) {
            printf("\n===============> Dope! You've been here before!\n\n");
        }
        else {
            player_info.past_positions[t++] = next_move;
            game_info.max_moves--;

             if (bomb_finder(game_info.bombs_positions, next_move) &&
                treasure_finder(game_info.treasure_position, next_move)) {

                player_info.lives -= 1;
                player_info.treasures_found += 1;
                printf("\n===============> [&] !!! BOOOOOM !!! [&]\n");
                printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
                symbol_history[next_move - 1] = '&';
            }

            else if (bomb_finder(game_info.bombs_positions, next_move)) {

                player_info.lives -= 1;
                printf("\n===============> [!] !!! BOOOOOM !!! [!]\n\n");
                symbol_history[next_move - 1] = '!';
            }
            else if (treasure_finder(game_info.treasure_position, next_move)) {

                player_info.treasures_found += 1;
                printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
                symbol_history[next_move - 1] = '$';
            }
            else {
                printf("\n===============> [.] ...Nothing found here... [.]\n\n");
                symbol_history[next_move - 1] = '.';
            }
        }
    } while (player_info.lives > 0 && game_info.max_moves > 0);

    if (player_info.lives < 1) printf("No more LIVES remaining!\n\n");
    else if (game_info.max_moves < 1) printf("No more MOVES remaining!\n\n");

    printf("  ");
    for (int u = 0; u < game_info.path_length; u++) {
        if (u == next_move - 1) printf("%c", player_info.symbol);
        else printf(" ");
    }

    printf("\n  ");
        for (int w = 0; w < game_info.path_length; w++) {
            if (symbol_history[w] != 0) printf("%c", symbol_history[w]);
            else printf("-");
        }

        printf("\n  ");
        for (int t = 1; t <= game_info.path_length; t++) {
            if (t % 10 == 0) printf("%d", t / 10);
            else {
                printf("|");
            }
        }
        printf("\n  ");

        for (int s = 1; s <= game_info.path_length; s++) {
            printf("%d", s % 10);
        }
    printf("\n+---------------------------------------------------+\n");
    printf(" Lives: %2d | Treasures: %2d | Moves Remaining: %2d\n", player_info.lives,
    player_info.treasures_found, game_info.max_moves);
    printf("+---------------------------------------------------+\n\n");

    printf("##################\n");
    printf("#   Game over!   #\n##################\n\nYou should play again and try to beat your score!\n");

    return 0;
}
