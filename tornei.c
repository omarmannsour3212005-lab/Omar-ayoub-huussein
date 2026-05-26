#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tornei.h"

#define TOURNAMENT_FILE "tornei.dat"

// ==========================================
// ADD TOURNAMENT
// ==========================================

void addTorneo() {

    FILE *fp;

    Torneo torneo;

    fp = fopen(TOURNAMENT_FILE, "ab");

    if(fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\n=== ADD TOURNAMENT ===\n");

    printf("Insert tournament ID: ");
    scanf("%d", &torneo.id);

    if(torneoExists(torneo.id)) {
        printf("Tournament already exists!\n");
        fclose(fp);
        return;
    }

    printf("Insert tournament name: ");
    scanf(" %[^\n]", torneo.nome);

    torneo.winnerId = -1;

    fwrite(&torneo, sizeof(Torneo), 1, fp);

    fclose(fp);

    printf("Tournament added successfully!\n");
}


// ==========================================
// VIEW TOURNAMENTS
// ==========================================

void viewTornei() {

    FILE *fp;

    Torneo torneo;

    fp = fopen(TOURNAMENT_FILE, "rb");

    if(fp == NULL) {
        printf("No tournaments found.\n");
        return;
    }

    printf("\n=== TOURNAMENT LIST ===\n");

    while(fread(&torneo, sizeof(Torneo), 1, fp)) {

        printf("\n----------------------\n");

        printf("ID: %d\n", torneo.id);
        printf("Name: %s\n", torneo.nome);

        if(torneo.winnerId == -1)
            printf("Winner: Not decided\n");
        else
            printf("Winner ID: %d\n", torneo.winnerId);
    }

    fclose(fp);
}


// ==========================================
// SEARCH TOURNAMENT
// ==========================================

void searchTorneo() {

    FILE *fp;

    Torneo torneo;

    int id;
    int found = 0;

    fp = fopen(TOURNAMENT_FILE, "rb");

    if(fp == NULL) {
        printf("No tournaments file found.\n");
        return;
    }

    printf("\nInsert tournament ID to search: ");
    scanf("%d", &id);

    while(fread(&torneo, sizeof(Torneo), 1, fp)) {

        if(torneo.id == id) {

            found = 1;

            printf("\n=== TOURNAMENT FOUND ===\n");

            printf("ID: %d\n", torneo.id);
            printf("Name: %s\n", torneo.nome);

            if(torneo.winnerId == -1)
                printf("Winner: Not decided\n");
            else
                printf("Winner ID: %d\n", torneo.winnerId);

            break;
        }
    }

    fclose(fp);

    if(!found) {
        printf("Tournament not found.\n");
    }
}


// ==========================================
// DELETE TOURNAMENT
// ==========================================

void deleteTorneo() {

    FILE *fp;
    FILE *temp;

    Torneo torneo;

    int id;
    int found = 0;

    fp = fopen(TOURNAMENT_FILE, "rb");

    if(fp == NULL) {
        printf("File not found.\n");
        return;
    }

    temp = fopen("temp.dat", "wb");

    if(temp == NULL) {
        printf("Error creating temp file.\n");
        fclose(fp);
        return;
    }

    printf("\nInsert tournament ID to delete: ");
    scanf("%d", &id);

    while(fread(&torneo, sizeof(Torneo), 1, fp)) {

        if(torneo.id == id) {
            found = 1;
        } else {
            fwrite(&torneo, sizeof(Torneo), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove(TOURNAMENT_FILE);
    rename("temp.dat", TOURNAMENT_FILE);

    if(found)
        printf("Tournament deleted successfully.\n");
    else
        printf("Tournament not found.\n");
}


// ==========================================
// CHECK IF TOURNAMENT EXISTS
// ==========================================

int torneoExists(int id) {

    FILE *fp;

    Torneo torneo;

    fp = fopen(TOURNAMENT_FILE, "rb");

    if(fp == NULL) {
        return 0;
    }

    while(fread(&torneo, sizeof(Torneo), 1, fp)) {

        if(torneo.id == id) {

            fclose(fp);
            return 1;
        }
    }

    fclose(fp);

    return 0;
}
