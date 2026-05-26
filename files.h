#ifndef FILES_H
#define FILES_H

#include "tennisti.h"

void salvaTennista(Tennista t);

void leggiTennisti();

int trovaTennistaByID(int id, Tennista *t);

void aggiornaTennista(Tennista t);

void eliminaTennistaFile(int id);

int esisteID(int id);

#endif
