#ifndef COACH_H
#define COACH_H

#include "models.h"

// Register new coach
void registerCoach();

// View all coaches
void viewCoaches();

// Check if nickname already exists
int coachExists(char nickname[]);

#endif
