#include <stdio.h>
#include <string.h>

#include "tennisti.h"
#include "files.h"

float calcolaCrediti(int ranking) {

    if(ranking <= 10)
        return 30;

    if(ranking <= 20)
        return 25;

    if(ranking <= 50)
        return 20;

    if(ranking <= 100)
        return 15;

    return 10;
}

void aggiungiTennista() {

    Tennista t;

    printf("ID: ");
    scanf("%d", &t.id);

    if(t.id <= 0) {

        printf("ID non valido.\n");
        return;
    }

    if(esisteID(t.id)) {

        printf("ID gia esistente!\n");
        return;
    }

    printf("Nome: ");
    scanf("%s", t.nome);

    printf("Cognome: ");
    scanf("%s", t.cognome);

    printf("Ranking: ");
    scanf("%d", &t.ranking);

    if(t.ranking <= 0) {

        printf("Ranking non valido.\n");
        return;
    }

    t.crediti = calcolaCrediti(t.ranking);

    t.disponibile = 1;

    salvaTennista(t);
}

void visualizzaTennisti() {

    leggiTennisti();
}

void cercaTennista() {

    int id;

    Tennista t;

    printf("Inserisci ID: ");
    scanf("%d", &id);

    if(trovaTennistaByID(id, &t)) {

        printf("\nTrovato!\n");

        printf("Nome: %s\n", t.nome);
        printf("Cognome: %s\n", t.cognome);
        printf("Ranking: %d\n", t.ranking);
        printf("Crediti: %.2f\n", t.crediti);

    } else {

        printf("Tennista non trovato.\n");
    }
}

void modificaTennista() {

    int id;

    Tennista t;

    printf("Inserisci ID da modificare: ");
    scanf("%d", &id);

    if(trovaTennistaByID(id, &t)) {

        printf("Nuovo nome: ");
        scanf("%s", t.nome);

        printf("Nuovo cognome: ");
        scanf("%s", t.cognome);

        printf("Nuovo ranking: ");
        scanf("%d", &t.ranking);

        t.crediti = calcolaCrediti(t.ranking);

        printf("Disponibile? (1/0): ");
        scanf("%d", &t.disponibile);

        aggiornaTennista(t);

    } else {

        printf("Tennista non trovato.\n");
    }
}

void eliminaTennista() {

    int id;

    printf("Inserisci ID da eliminare: ");
    scanf("%d", &id);

    eliminaTennistaFile(id);
}

void cercaPerNome() {

    FILE *fp = fopen(FILE_PLAYERS, "rb");

    Tennista t;

    char nome[50];

    int trovato = 0;

    if(fp == NULL) {

        printf("File non trovato.\n");
        return;
    }

    printf("Inserisci nome: ");
    scanf("%s", nome);

    while(fread(&t, sizeof(Tennista), 1, fp)) {

        if(strcmp(t.nome, nome) == 0) {

            printf("\nID: %d\n", t.id);
            printf("Nome: %s\n", t.nome);
            printf("Cognome: %s\n", t.cognome);
            printf("Ranking: %d\n", t.ranking);

            trovato = 1;
        }
    }

    if(!trovato)
        printf("Nessun tennista trovato.\n");

    fclose(fp);
}

void cercaPerCognome() {

    FILE *fp = fopen(FILE_PLAYERS, "rb");

    Tennista t;

    char cognome[50];

    int trovato = 0;

    if(fp == NULL) {

        printf("File non trovato.\n");
        return;
    }

    printf("Inserisci cognome: ");
    scanf("%s", cognome);

    while(fread(&t, sizeof(Tennista), 1, fp)) {

        if(strcmp(t.cognome, cognome) == 0) {

            printf("\nID: %d\n", t.id);
            printf("Nome: %s\n", t.nome);
            printf("Cognome: %s\n", t.cognome);
            printf("Ranking: %d\n", t.ranking);

            trovato = 1;
        }
    }

    if(!trovato)
        printf("Nessun tennista trovato.\n");

    fclose(fp);
}

int contaTennisti() {

    FILE *fp = fopen(FILE_PLAYERS, "rb");

    Tennista t;

    int count = 0;

    if(fp == NULL)
        return 0;

    while(fread(&t, sizeof(Tennista), 1, fp))
        count++;

    fclose(fp);

    return count;
}

int caricaTennisti(Tennista arr[]) {

    FILE *fp = fopen(FILE_PLAYERS, "rb");

    int i = 0;

    if(fp == NULL)
        return 0;

    while(fread(&arr[i], sizeof(Tennista), 1, fp))
        i++;

    fclose(fp);

    return i;
}

void generaReportTennisti() {

    FILE *fp = fopen(FILE_PLAYERS, "rb");
    FILE *report = fopen("report_tennisti.txt", "w");

    Tennista t;

    if(fp == NULL || report == NULL) {

        printf("Errore file.\n");
        return;
    }

    fprintf(report, "===== REPORT TENNISTI =====\n\n");

    while(fread(&t, sizeof(Tennista), 1, fp)) {

        fprintf(report, "ID: %d\n", t.id);
        fprintf(report, "Nome: %s\n", t.nome);
        fprintf(report, "Cognome: %s\n", t.cognome);
        fprintf(report, "Ranking: %d\n", t.ranking);
        fprintf(report, "Crediti: %.2f\n", t.crediti);

        fprintf(report,
                "Disponibile: %s\n\n",
                t.disponibile ? "SI" : "NO");
    }

    fclose(fp);
    fclose(report);

    printf("Report generato!\n");
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
