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
