#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "models.h"
#include "tornei.h"

// ==================== ADD TORNEO ====================

void addTorneo()
{
    FILE *fp;

    Torneo t;

    fp = fopen("tornei.dat", "ab");

    if(fp == NULL)
    {
        printf("Errore apertura file!\n");
        return;
    }

    printf("\n===== AGGIUNGI TORNEO =====\n");

    printf("Inserisci ID torneo: ");
    scanf("%d", &t.id);

    printf("Inserisci nome torneo: ");
    scanf("%s", t.nome);

    t.winnerId = -1;

    fwrite(&t, sizeof(Torneo), 1, fp);

    fclose(fp);

    printf("Torneo salvato correttamente!\n");
}

// ==================== VIEW TORNEI ====================

void viewTornei()
{
    FILE *fp;

    Torneo t;

    fp = fopen("tornei.dat", "rb");

    if(fp == NULL)
    {
        printf("Nessun torneo trovato!\n");
        return;
    }

    printf("\n===== LISTA TORNEI =====\n");

    while(fread(&t, sizeof(Torneo), 1, fp))
    {
        printf("\nID: %d\n", t.id);
        printf("Nome: %s\n", t.nome);
        printf("Winner ID: %d\n", t.winnerId);
    }

    fclose(fp);
}

// ==================== DELETE TORNEO ====================

void deleteTorneo()
{
    FILE *fp;
    FILE *temp;

    Torneo t;

    int id;
    int found = 0;

    fp = fopen("tornei.dat", "rb");

    if(fp == NULL)
    {
        printf("Errore apertura file!\n");
        return;
    }

    temp = fopen("temp.dat", "wb");

    printf("Inserisci ID torneo da eliminare: ");
    scanf("%d", &id);

    while(fread(&t, sizeof(Torneo), 1, fp))
    {
        if(t.id == id)
        {
            found = 1;
        }
        else
        {
            fwrite(&t, sizeof(Torneo), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("tornei.dat");
    rename("temp.dat", "tornei.dat");

    if(found)
    {
        printf("Torneo eliminato correttamente!\n");
    }
    else
    {
        printf("Torneo non trovato!\n");
    }
} 

void addMatch()
{
    FILE *fp;

    Match match;

    fp = fopen("matches.dat", "ab");

    if(fp == NULL)
    {
        printf("Errore apertura file!\n");
        return;
    }

    printf("\n===== ADD MATCH =====\n");

    printf("Inserisci Match ID: ");
    scanf("%d", &match.id);

    printf("Player 1 ID: ");
    scanf("%d", &match.player1Id);

    printf("Player 2 ID: ");
    scanf("%d", &match.player2Id);

    printf("Ace Player 1: ");
    scanf("%d", &match.ace1);

    printf("Ace Player 2: ");
    scanf("%d", &match.ace2);

    printf("Break Player 1: ");
    scanf("%d", &match.break1);

    printf("Break Player 2: ");
    scanf("%d", &match.break2);

    printf("Doppi Falli Player 1: ");
    scanf("%d", &match.doppiFalli1);

    printf("Doppi Falli Player 2: ");
    scanf("%d", &match.doppiFalli2);

    printf("Winner ID: ");
    scanf("%d", &match.winnerId);

    fwrite(&match, sizeof(Match), 1, fp);

    fclose(fp);

    printf("Match salvato correttamente!\n");
}
