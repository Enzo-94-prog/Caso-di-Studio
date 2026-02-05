#ifndef UTENTI_H_
#define UTENTI_H_

#include "struct_macro.h"


/**
 * @brief Avvia la procedura di accesso alla piattaforma.
 * @param file_utenti Puntatore al file utenti.
 * @param file_risorse Puntatore al file risorse.
 * @param file_attivita Puntatore al file attivita'.
 */
void accedi (FILE *file_utenti, FILE *file_risorse, FILE *file_attivita);


/**
 * @brief Reindirizza l'utente al menu creatore.
 * @param file_utenti Puntatore al file utenti.
 * @param file_risorse Puntatore al file risorse.
 */
void apri_menu_creatore (FILE *file_utenti, FILE *file_risorse);


/**
 * @brief Reindirizza l'utente al menu utilizzatore.
 * @param file_utenti Puntatore al file utenti.
 * @param file_risorse Puntatore al file risorse.
 * @param file_attivita Puntatore al file attivita'.
 */
void apri_menu_utilizzatore (FILE *file_utenti, FILE *file_risorse, FILE *file_attivita);


/**
 * @brief Incrementa il numero di download effettuati dall'utilizzatore o il numero di volte che un creatore
 * ha visto scaricare le proprie risorse.
 * @param file_utenti Puntatore al file utenti.
 * @param ID_creatore Codice identificativo univoco associato al creatore della risorsa appena scaricata.
 */
void incrementa_numero_download_totali_utenti (FILE *file_utenti, int ID_creatore);


/**
 * @brief Avvia la procedura di registrazione alla piattaforma.
 * @param file_utenti Puntatore al file utenti.
 */
void registra_utente (FILE *file_utenti);


/**
 * @brief Salva l'attivita' appena svolta dall'utilizzatore all'interno del file attivita'.
 * @param file_utenti Puntatore al file utenti.
 * @param file_risorse Puntatore al file risorse.
 * @param file_attivita Puntatore al file attivita'.
 * @param ID_risorsa Codice identificativo univoco associato alla risorsa appena scaricata.
 */
void salva_attivita_utilizzatore (FILE *file_utenti, FILE *file_risorse, FILE *file_attivita, int ID_risorsa);


/**
 * @brief Visualizza nel dettaglio i dati di un utente.
 * @param utente Puntatore alla risorsa contenente i dati dell'utente da visualizzare.
 */
void stampa_utente_singolo (utente_t *utente);


/**
 * @brief Visualizza le statistiche di tutti creatori.
 * @param file_utenti Puntatore al file utenti.
 * @param file_risorse Puntatore al file risorse.
 */
void visualizza_statistiche_creatori (FILE *file_utenti, FILE *file_risorse);


/**
 * @brief Visualizza i primi 5 utenti piu' popolari della piattaforma.
 * @param file_utenti Puntatore al file utenti.
 * @param tipo_account Variabile indicante il tipo di utenti di cui si vuole visualizzare una lista ordinata
 * in base ai loro download.
 */
void visualizza_utenti_piu_popolari (FILE *file_utenti, int tipo_account);


/**
 * @brief Cancella l'account dell'utente correntemente connesso.
 * @param file_utenti Puntatore al file utenti.
 * @return Ritorna 1 se l'account e' stato cancellato, 0 altrimenti.
 */
int cancella_account (FILE *file_utenti);





#endif /* UTENTI_H_ */
