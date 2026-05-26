#ifndef MODELS_H
#define MODELS_H

#include "config.h"

// ==================== TENNISTA ====================

typedef struct {

    int id;

    char nome[MAX_NAME];
    char cognome[MAX_NAME];

    int ranking;
    int crediti;

    int disponibile;

} Tennista;


// ==================== MATCH ====================

typedef struct {

    int id;

    int player1Id;
    int player2Id;

    int ace1;
    int ace2;

    int doppiFalli1;
    int doppiFalli2;

    int break1;
    int break2;

    int winnerId;

} Match;


// ==================== TORNEO ====================

typedef struct {

    int id;

    char nome[MAX_NAME];

    int winnerId;

} Torneo;


// ==================== COACH ====================

typedef struct {

    char nickname[MAX_NAME];

} Coach;


// ==================== SQUADRA ====================

typedef struct {

    int id;

    char coachNickname[MAX_NAME];

    int torneoId;

    int playerIds[MAX_PLAYERS];

    int totalCredits;

    int totalPoints;

} Squadra;

#endif
