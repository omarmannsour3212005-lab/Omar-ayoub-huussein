#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "models.h"
#include "config.h"
#include "squadra.h"

void createTeam() {

    FILE *fpPlayers;
    FILE *fpTeams;

    Tennista player;
    Squadra team;

    int selectedId;
    int found;
    int duplicate;
    int i;
    int totalCredits = 0;

    printf("\n===== CREATE TEAM =====\n");

    // Coach nickname
    printf("Coach nickname: ");
    scanf("%49s", team.coachNickname);

    // Tournament ID
    printf("Tournament ID: ");
    scanf("%d", &team.torneoId);

    // Open players file
    fpPlayers = fopen("players.dat", "rb");

    if(fpPlayers == NULL) {
        printf("Error opening players file.\n");
        return;
    }

    // Show available players
    printf("\n===== AVAILABLE PLAYERS =====\n");

    while(fread(&player, sizeof(Tennista), 1, fpPlayers)) {

        if(player.disponibile == 1) {

            printf("ID: %d | %s %s | Ranking: %d | Credits: %d\n",
                   player.id,
                   player.nome,
                   player.cognome,
                   player.ranking,
                   player.crediti);
        }
    }

    // Select 6 players
    for(i = 0; i < MAX_PLAYERS; i++) {

        duplicate = 0;
        found = 0;

        printf("\nSelect player %d ID: ", i + 1);
        scanf("%d", &selectedId);

        // Check duplicates
        for(int j = 0; j < i; j++) {

            if(team.playerIds[j] == selectedId) {
                duplicate = 1;
                break;
            }
        }

        if(duplicate) {
            printf("Player already selected.\n");
            i--;
            continue;
        }

        rewind(fpPlayers);

        // Search player in file
        while(fread(&player, sizeof(Tennista), 1, fpPlayers)) {

            if(player.id == selectedId &&
               player.disponibile == 1) {

                found = 1;

                // Budget check
                if(totalCredits + player.crediti > MAX_BUDGET) {

                    printf("Budget exceeded.\n");
                    found = 0;
                    break;
                }

                team.playerIds[i] = player.id;

                totalCredits += player.crediti;

                printf("Added: %s %s\n",
                       player.nome,
                       player.cognome);

                printf("Current credits: %d/%d\n",
                       totalCredits,
                       MAX_BUDGET);

                break;
            }
        }

        if(!found) {
            printf("Invalid player.\n");
            i--;
        }
    }

    fclose(fpPlayers);

    team.totalCredits = totalCredits;
    team.totalPoints = 0;

    // Save team
    fpTeams = fopen("squadre.dat", "ab");

    if(fpTeams == NULL) {
        printf("Error opening squadre file.\n");
        return;
    }

    fwrite(&team, sizeof(Squadra), 1, fpTeams);

    fclose(fpTeams);

    printf("\nTeam created successfully!\n");
}

void viewTeams() {

    FILE *fp;

    Squadra team;

    int i;

    fp = fopen("squadre.dat", "rb");

    if(fp == NULL) {
        printf("No teams found.\n");
        return;
    }

    printf("\n===== TEAMS =====\n");

    while(fread(&team, sizeof(Squadra), 1, fp)) {

        printf("\nCoach: %s\n", team.coachNickname);

        printf("Tournament ID: %d\n",
               team.torneoId);

        printf("Players IDs: ");

        for(i = 0; i < MAX_PLAYERS; i++) {

            printf("%d ",
                   team.playerIds[i]);
        }

        printf("\nTotal Credits: %d\n",
               team.totalCredits);

        printf("Total Points: %d\n",
               team.totalPoints);
    }

    fclose(fp);
}

void modifyTeam() {

    printf("\nModify Team not implemented yet.\n");
}
