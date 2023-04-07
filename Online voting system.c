#include <stdio.h>
#include <string.h>

#define MAX_VOTERS 3
#define NUM_CANDIDATES 3

int main() {
    char password[20] = "cuk2022";
    char candidate_names[NUM_CANDIDATES][20] = {"Phoebe", "Timo", "Wex"};
    int candidate_votes[NUM_CANDIDATES] = {0};
    char voter_name[50];
    char voter_password[20];
    int i, j, vote;

    printf("Welcome to the Cooperative university voting system!\n");
    printf("____________________________________________________\n");

    for (i = 0; i < MAX_VOTERS; i++) {
        printf("\nVoter %d, please enter one name and ID number in this format Joshua.bssec01/1727/2022: ", i + 1);
        scanf("%s", voter_name);

        printf("Hello %s, please enter the voting password send to your student email: ", voter_name);
        scanf("%s", voter_password);

        if (strcmp(voter_password, password) != 0) {
            printf("Incorrect password. You cannot vote.\n");
            continue;
        }

        printf("Thank you, %s. Here are the candidates:\n", voter_name);
        for (j = 0; j < NUM_CANDIDATES; j++) {
            printf("%d. %s\n", j + 1, candidate_names[j]);
        }

        printf("Enter the number of your choice: ");
        scanf("%d", &vote);

        if (vote < 1 || vote > NUM_CANDIDATES) {
            printf("Invalid choice. You cannot vote.\n");
            continue;
        }

        candidate_votes[vote - 1]++;
        printf("Thank you, %s. Your vote has been recorded.\n", voter_name);
    }

    printf("\nVoting has ended. Here are the results:\n");
    for (i = 0; i < NUM_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidate_names[i], candidate_votes[i]);
    }

    int winner_index = 0;
    for (i = 1; i < NUM_CANDIDATES; i++) {
        if (candidate_votes[i] > candidate_votes[winner_index]) {
            winner_index = i;
        }
    }
    printf("%s wins with %d votes!\n", candidate_names[winner_index], candidate_votes[winner_index]);

    return 0;
}