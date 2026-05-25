#include <stdio.h>

#include "tennisti.h"

int main() {

    int scelta;

    do {

        printf("\n===== MENU =====\n");

        printf("1. Aggiungi Tennista\n");
        printf("2. Visualizza Tennisti\n");
        printf("3. Cerca Tennista ID\n");
        printf("4. Modifica Tennista\n");
        printf("5. Elimina Tennista\n");
        printf("6. Cerca per nome\n");
        printf("7. Cerca per cognome\n");
        printf("8. Conta tennisti\n");
        printf("9. Genera report\n");
        printf("0. Esci\n");

        printf("Scelta: ");
        scanf("%d", &scelta);

        switch(scelta) {

            case 1:
                aggiungiTennista();
                break;

            case 2:
                visualizzaTennisti();
                break;

            case 3:
                cercaTennista();
                break;

            case 4:
                modificaTennista();
                break;

            case 5:
                eliminaTennista();
                break;

            case 6:
                cercaPerNome();
                break;

            case 7:
                cercaPerCognome();
                break;

            case 8:
                printf("Totale tennisti: %d\n",
                       contaTennisti());
                break;

            case 9:
                generaReportTennisti();
                break;

            case 0:
                printf("Uscita...\n");
                break;

            default:
                printf("Scelta non valida.\n");
        }

    } while(scelta != 0);

    return 0;
}