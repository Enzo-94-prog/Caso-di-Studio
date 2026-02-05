#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "struct_macro.h"




/**
 * @pre Il file ordinamento deve essere stato redatto con tutte le risorse non vuote presenti nel file risorse.
 * @post Il file ordinamento deve contenere tutte le risorse ordinate in modo decrescente a seconda del numero di volte che sono state scaricate.
 */
void ordina_risorse_piu_scaricate (FILE *file_ordinamento, int primo, int ultimo)
{
	risorsa_t risorsa_i, risorsa_j, risorsa_pivot, temp = {"", "", "", "", "", 0, 0, 0, 0, 0};
	int i = 0;
    int j = 0;
    int pivot = 0;


    /*
     * Ordinamento quicksort.
     */


   if (primo < ultimo) {

      pivot = primo;
      i = primo;
      j = ultimo;

      while (i < j) {

    	  fseek(file_ordinamento, pivot * sizeof(risorsa_t), SEEK_SET);
    	  fread(&risorsa_pivot, sizeof(risorsa_t), 1, file_ordinamento);

    	  fseek(file_ordinamento, i * sizeof(risorsa_t), SEEK_SET);
    	  fread(&risorsa_i, sizeof(risorsa_t), 1, file_ordinamento);


    	  while ( (risorsa_i.numero_download >= risorsa_pivot.numero_download) && (i < ultimo) ) {

    		  i++;

    		  fseek(file_ordinamento, i * sizeof(risorsa_t), SEEK_SET);
    		  fread(&risorsa_i, sizeof(risorsa_t), 1, file_ordinamento);

    	  }


    	  fseek(file_ordinamento, j * sizeof(risorsa_t), SEEK_SET);
    	  fread(&risorsa_j, sizeof(risorsa_t), 1, file_ordinamento);


    	  while ( (risorsa_j.numero_download < risorsa_pivot.numero_download) ) {

    		  j--;

        	  fseek(file_ordinamento, j * sizeof(risorsa_t), SEEK_SET);
        	  fread(&risorsa_j, sizeof(risorsa_t), 1, file_ordinamento);

         }


    	  if (i < j) {

    		  temp = risorsa_i;
    		  risorsa_i = risorsa_j;

    		  fseek(file_ordinamento, i * sizeof(risorsa_t), SEEK_SET);
    		  fwrite(&risorsa_i, sizeof(risorsa_t), 1, file_ordinamento);

    		  risorsa_j = temp;

    		  fseek(file_ordinamento, j * sizeof(risorsa_t), SEEK_SET);
    		  fwrite(&risorsa_j, sizeof(risorsa_t), 1, file_ordinamento);

         }
      }


      temp = risorsa_pivot;
      risorsa_pivot = risorsa_j;


      fseek(file_ordinamento, pivot * sizeof(risorsa_t), SEEK_SET);
      fwrite(&risorsa_pivot, sizeof(risorsa_t), 1, file_ordinamento);

      risorsa_j = temp;

      fseek(file_ordinamento, j * sizeof(risorsa_t), SEEK_SET);
      fwrite(&risorsa_j, sizeof(risorsa_t), 1, file_ordinamento);


      ordina_risorse_piu_scaricate (file_ordinamento, primo, j - 1);
      ordina_risorse_piu_scaricate (file_ordinamento, j + 1, ultimo);

   }
}

/**
 * @pre Il file ordinamento deve essere stato redatto con tutti gli utenti non vuoti presenti nel file utenti.
 * @post Il file ordinamento deve contenere tutti gli utenti (utilizzatori o creatori) ordinati in modo decrescente
 * a seconda del numero di volte in cui hanno scaricato delle risorse/in cui le proprie risorse sono state scaricate.
 */
void ordina_utenti (FILE *file_ordinamento, int primo, int ultimo)
{
	utente_t utente_i, utente_j, utente_pivot, temp = {"", "", "", "", 0, 0, 0, 0};
	int i = 0;
	int j = 0;
	int pivot = 0;


    /*
     * Ordinamento quicksort.
     */


	if (primo < ultimo) {
		pivot = primo;
		i = primo;
		j = ultimo;

		while (i < j) {

			fseek(file_ordinamento, pivot * sizeof(utente_t), SEEK_SET);
			fread(&utente_pivot, sizeof(utente_t), 1, file_ordinamento);

			fseek(file_ordinamento, i * sizeof(utente_t), SEEK_SET);
			fread(&utente_i, sizeof(utente_t), 1, file_ordinamento);


			while ((utente_i.numero_download_totali >= utente_pivot.numero_download_totali ) && (i < ultimo)) {

				i++;

				fseek(file_ordinamento, i * sizeof(utente_t), SEEK_SET);
				fread(&utente_i, sizeof(utente_t), 1, file_ordinamento);

 	  }



 	  fseek(file_ordinamento, j * sizeof(utente_t), SEEK_SET);
 	  fread(&utente_j, sizeof(utente_t), 1, file_ordinamento);



 	  while ((utente_j.numero_download_totali < utente_pivot.numero_download_totali)) {

 		  j--;

     	  fseek(file_ordinamento, j * sizeof(utente_t), SEEK_SET);
     	  fread(&utente_j, sizeof(utente_t), 1, file_ordinamento);

      }


 	  if (i < j) {

 		  temp = utente_i;
 		  utente_i = utente_j;

 		  fseek(file_ordinamento, i * sizeof(utente_t), SEEK_SET);
 		  fwrite(&utente_i, sizeof(utente_t), 1, file_ordinamento);

 		  utente_j = temp;

 		  fseek(file_ordinamento, j * sizeof(utente_t), SEEK_SET);
 		  fwrite(&utente_j, sizeof(utente_t), 1, file_ordinamento);

      }
   }


   temp = utente_pivot;
   utente_pivot = utente_j;


   fseek(file_ordinamento, pivot * sizeof(utente_t), SEEK_SET);
   fwrite(&utente_pivot, sizeof(utente_t), 1, file_ordinamento);

   utente_j = temp;

   fseek(file_ordinamento, j * sizeof(utente_t), SEEK_SET);
   fwrite(&utente_j, sizeof(utente_t), 1, file_ordinamento);


   ordina_utenti (file_ordinamento, primo, j - 1);
   ordina_utenti (file_ordinamento, j + 1, ultimo);

	}

}
