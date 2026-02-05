#ifndef ATTIVITA_H_
#define ATTIVITA_H_

#include "struct_macro.h"



/**
 * @brief Aggiunge una struttura attivita' nel file attivita'.
 * @param file_utenti Puntatore al file utenti.
 * @param file_risorse Puntatore al file risorse.
 * @param file_attivita Puntatore al file attivita'.
 * @param ID_risorsa Variabile contenente l'ID della risorsa appena scaricata.
 * @param ID_creatore Variabile contenente l'ID del creatore della risorsa appena scaricata.
 */
void aggiorna_file_attivita (FILE *file_utenti, FILE *file_risorse, FILE *file_attivita, int ID_risorsa, int ID_creatore);


/**
 * @brief Stampa tutte le attivita' svolte dagli utilizzatori della piattaforma.
 * @param file_attivita Puntatore al file attivita'.
 */
void stampa_attivita_utilizzatori (FILE *file_attivita);




#endif /* ATTIVITA_H_ */
