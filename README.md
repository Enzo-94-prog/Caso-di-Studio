
# Simulazione Piattaforma Didattica – Linguaggio C

Progetto sviluppato in linguaggio **C** che simula una piattaforma didattica per la condivisione di risorse educative (giochi, documenti e video), con gestione di utenti, risorse, attività e statistiche.
Il sistema è realizzato come applicazione **console-based** e utilizza **file binari** per la persistenza dei dati.

Progetto realizzato nell’ambito del corso di **Laboratorio di Informatica**.

---

## Descrizione del progetto

L’obiettivo del progetto è simulare le principali funzionalità di una piattaforma per la condivisione di risorse didattiche online, supportando due tipologie di utenti:

- **Creatori**, che possono caricare e gestire risorse  
- **Utilizzatori**, che possono cercare, scaricare e valutare risorse  

Il sistema consente:
- registrazione e autenticazione degli utenti  
- gestione completa delle risorse  
- tracciamento delle attività degli utilizzatori  
- suggerimenti automatici basati sulle interazioni passate  
- visualizzazione di statistiche e classifiche  

Il progetto è stato sviluppato seguendo una struttura modulare, con particolare attenzione alla **progettazione dei dati**, alla **gestione dei file** e alla **validazione degli input**.

---

## Screenshots delle funzionalità principali

### Login e registrazione
<p align="center">
  <img src="screenshots/login.png" alt="Login e registrazione">
</p>

---

### Menu principale – Creatore
<p align="center">
  <img src="screenshots/menu_creatore.png" alt="Menu principale creatore">
</p>

---

### Aggiunta di una risorsa
<p align="center">
  <img src="screenshots/aggiungi_risorsa_1.png" width="45%" alt="Aggiunta risorsa - fase 1">
  <img src="screenshots/aggiungi_risorsa_2.png" width="45%" alt="Aggiunta risorsa - fase 2">
</p>

---

### Menu principale – Utilizzatore
<p align="center">
  <img src="screenshots/menu_utilizzatore.png" alt="Menu principale utilizzatore">
</p>

---

### Ricerca delle risorse
<p align="center">
  <img src="screenshots/ricerca_risorsa.png" alt="Ricerca risorsa">
</p>

---

### Statistiche e classifiche
<p align="center">
  <img src="screenshots/statistiche.png" alt="Statistiche">
</p>

---

### Attività degli utilizzatori
<p align="center">
  <img src="screenshots/attivita_utilizzatori.png" alt="Attività utilizzatori">
</p>


---

## Funzionalità principali

### Gestione utenti
- Registrazione e login  
- Distinzione tra account *creatore* e *utilizzatore*  
- Cancellazione dell’account  
- Disconnessione e ritorno al menu principale  

### Gestione risorse (Creatori)
- Inserimento di nuove risorse  
- Modifica delle risorse caricate  
- Rimozione delle risorse  
- Visualizzazione delle risorse associate al proprio account  

### Ricerca e interazione (Utilizzatori)
- Ricerca delle risorse per **titolo**  
- Ricerca delle risorse per **parola chiave**  
- Download e valutazione delle risorse  
- Suggerimento automatico di contenuti affini  

### Statistiche e classifiche
- Top 5 risorse più scaricate  
- Top 5 creatori più popolari  
- Top 5 utilizzatori più attivi  
- Statistiche sui creatori (numero di risorse per tipologia)  
- Visualizzazione delle attività degli utilizzatori  

---

## Strutture dati principali

Il progetto utilizza strutture dati definite tramite `struct` ed `enum`, tra cui:

- `utente_t` – struttura per la gestione degli utenti  
- `risorsa_t` – struttura per la gestione delle risorse didattiche  
- `attivita_t` – struttura per il tracciamento delle attività  
- `tipo_risorsa_t` – enumerazione delle tipologie di risorsa (Gioco, Documento, Video)  

Sono inoltre presenti **costanti simboliche** utilizzate per migliorare la leggibilità e la manutenibilità del codice.

---

## Persistenza dei dati

La persistenza delle informazioni è gestita tramite **file binari**, utilizzati come archivi strutturati:

- `file_utenti.dat` – utenti registrati  
- `file_risorse.dat` – risorse presenti sulla piattaforma  
- `file_attivita.dat` – attività degli utilizzatori  
- `file_ordinamento.dat` – file di supporto per operazioni di ordinamento  

L’accesso ai dati avviene tramite posizionamento diretto all’interno dei file, utilizzando identificativi calcolati.

---

## Aspetti tecnici rilevanti

- Linguaggio: **C**  
- Programmazione strutturata e modulare  
- Utilizzo di:
  - `struct`, `enum` e puntatori  
  - file binari (`fread`, `fwrite`, `fseek`)  
  - controlli sull’input dell’utente  
- Generazione deterministica degli identificativi  
- Ordinamento dei dati persistenti  
- Tracciamento delle interazioni tra utenti e risorse  

---

## Compilazione ed esecuzione

Compilazione del programma tramite **MinGW** (GCC per Windows):

```bash
gcc main.c -o piattaforma
```

Esecuzione del programma:

```bash
./piattaforma
```

**Nota**: assicurarsi che MinGW sia installato e che la cartella bin di MinGW sia inclusa nel PATH di sistema. Dopo aver clonato la repository, questi comandi permettono di compilare ed eseguire immediatamente il programma.

Il programma utilizza file binari per la persistenza dei dati, che vengono **creati automaticamente alla prima esecuzione** se non presenti nella directory di esecuzione.

**Nota:** nella repository sono già presenti dei file con dati di esempio all'interno della cartella **G14_DataFile**, che permettono di utilizzare immediatamente il programma. Le credenziali di accesso per gli utenti di prova sono indicate nella parte finale della documentazione.

---

## Testing

Il progetto è stato testato seguendo un **piano di test strutturato**, che copre:
- tutte le funzionalità principali  
- input validi e non validi  
- casi limite  

I test hanno confermato il corretto funzionamento del sistema rispetto ai requisiti definiti.

---

## Note finali

Questo progetto rappresenta un **case study completo** che dimostra competenze in:
- progettazione software  
- gestione della memoria e dei file in C  
- analisi dei requisiti  
- sviluppo di applicazioni console strutturate  

Pur essendo nato in ambito accademico, il progetto è stato sviluppato con un approccio vicino a contesti reali di sviluppo software.