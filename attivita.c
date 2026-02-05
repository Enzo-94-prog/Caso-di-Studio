#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "struct_macro.h"

/**
 * @pre L'utilizzatore deve aver scaricato una risorsa.
 * @post L'attivita' dell'utilizzatore viene salvata nel file attivita' sotto forma di struttura.
 */

void aggiorna_file_attivita (FILE *file_utenti, FILE *file_risorse, FILE *file_attivita, int ID_risorsa, int ID_creatore)
{
	incrementa_contatore_download (file_risorse, ID_risorsa);
	salva_attivita_utilizzatore (file_utenti, file_risorse, file_attivita, ID_risorsa);
	aggiorna_valutazione_media_risorsa (file_risorse, file_attivita, ID_risorsa);
	incrementa_numero_download_totali_utenti (file_utenti, ID_creatore);
}

/**
 * @pre L'utilizzatore deve aver selezionato l'opzione di visualizzazione delle attivita' degli utilizzatori.
 * @post Viene stampato a schermo un elenco di attivita' degli utilizzatori.
 */

void stampa_attivita_utilizzatori (FILE *file_attivita)
{
	attivita_t attivita = {"", "", "", "", 0};
	int attivita_trovata = 0;
	int numero_attivita = 0;




	rewind(file_attivita);
	fread(&attivita, sizeof(attivita_t), 1, file_attivita);

	if (strlen(attivita.username_utilizzatore) >= LUNGHEZZA_MIN_STRINGA)
		attivita_trovata = 1;


	if (attivita_trovata == 1) {

		rewind(file_attivita);
		fread(&attivita, sizeof(attivita_t), 1, file_attivita);

		while (!feof(file_attivita)) {

			printf("\n\n\t\t\t\t                       Attivita' #%d", numero_attivita + 1);

			puts ("\n\t\t\t\t+---------------------------------------------------------+");

			printf("\n\t\t\t\t\t         Titolo risorsa: << %s >>", attivita.titolo_risorsa);

			printf("\n\n\t\t\t\t\t         Di disciplina: %s", attivita.disciplina);

			printf("\n\n\t\t\t\t\t         Creata da: %s", attivita.username_creatore);

			printf("\n\n\t\t\t\t\t         Scaricata da: %s", attivita.username_utilizzatore);

			printf("\n\n\t\t\t\t\t         Valutata : %d/%d stelle", attivita.valutazione, N_MASSIMO_STELLE_VALUTAZIONE);

			puts ("\n\n\t\t\t\t+---------------------------------------------------------+\n\n");

			fread(&attivita, sizeof(attivita_t), 1, file_attivita);

			numero_attivita++;
		}

		printf("\n\n\t\t\t\t\t    Sono state trovate %d attivita'", numero_attivita);

	}

	else
		puts("\n\n\t\t\t  ** Non e' stata trovata alcuna attivita' svolta da utilizzatori. **");

	puts("\n\n\n\n\t\t\t       ** L'utente verra' reindirizzato al menu utilizzatore. **\n\n");
	printf("\t\t\t\t\t  ");
	system("pause");

}
