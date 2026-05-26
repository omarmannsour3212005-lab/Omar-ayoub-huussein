#ifndef TENNISTI_H
#define TENNISTI_H

#define FILE_PLAYERS "players.dat"

typedef struct {

    int id;
    char nome[50];
    char cognome[50];
    int ranking;
    float crediti;
    int disponibile;

} Tennista;

/* CRUD */
void aggiungiTennista();
void visualizzaTennisti();
void cercaTennista();
void modificaTennista();
void eliminaTennista();

/* Extra */
float calcolaCrediti(int ranking);

void cercaPerNome();
void cercaPerCognome();

int contaTennisti();
int caricaTennisti(Tennista arr[]);

void generaReportTennisti();

#endif
