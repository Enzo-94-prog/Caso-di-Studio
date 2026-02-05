#ifndef ORDINAMENTO_H_
#define ORDINAMENTO_H_

#include "struct_macro.h"


/**
 * @brief Esegue un ordinamento con algoritmo Quicksort delle strutture risorsa contenute nel file risorse.
 * @param file_ordinamento Puntatore al file ordinamento.
 * @param primo Variabile corrispondente alla posizione della prima risorsa nel file ordinamento.
 * @param ultimo Variabile corrispondente alla posizione dell'ultima risorsa nel file ordinamento.
 */
void ordina_risorse_piu_scaricate (FILE *file_ordinamento, int primo, int ultimo);


/**
 * @brief Esegue un ordinamento con algoritmo Quicksort delle strutture utente contenute nel file utenti.
 * @param file_ordinamento Puntatore al file ordinamento.
 * @param primo Variabile corrispondente alla posizione del primo utente nel file ordinamento.
 * @param ultimo Variabile corrispondente alla posizione dell'ultimo utente nel file ordinamento.
 */
void ordina_utenti (FILE *file_ordinamento, int primo, int ultimo);




#endif /* ORDINAMENTO_H_ */
