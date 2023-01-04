#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include <iostream>
using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define next_s(P) (P)->next_s
#define First(D) ((D).First)
#define nil NULL

struct Film {
    string Judul;
    string Genre;
    int Durasi;
    // Menit
};

typedef Film infotype;

typedef struct elmFilm *adr_film;
typedef struct elmSutradara *adr_sutradara;

struct elmFilm{
    infotype info;
    adr_film next;
    adr_sutradara next_s;
};

struct elmSutradara{
    string info;
    adr_sutradara next;
};

struct listFilm {
    adr_film First;
};

struct listSutradara {
    adr_sutradara First;
};


// PROCEDURE FILM //
void createListFilm(listFilm &F);
bool isEmptyFilm(listFilm F);
bool onlyOneFilm(listFilm F);
bool isLastFilm(listFilm F, adr_film X);
adr_film createNewFilm(string Judul, string Genre, int Durasi, adr_film X);
adr_film toLastFilm(listFilm F);
void insertFirstFilm(listFilm &F, adr_film X);
void insertLastFilm(listFilm &F, adr_film X);
void insertAfterFilm(listSutradara &S, adr_sutradara B, adr_sutradara Y);
void deleteFirstFilm(listFilm &F, adr_film &X);
void deleteLastFilm(listFilm &F, adr_film &X);
void deleteAfterFilm(listSutradara &S, adr_sutradara B, adr_sutradara &Y);
adr_film findFilm(listFilm F, string Judul, string Genre, int Durasi);


// PROCEDURE SUTRADARA //
void createListSutradara(listSutradara &S);
bool isEmptySutradara(listSutradara S);
bool onlyOneSutradara(listSutradara S);
bool isLastSutradara(listSutradara S, adr_sutradara Y);
adr_sutradara createNewSutradara(string Nama, adr_sutradara Y);
adr_sutradara toLastSutradara(listSutradara S);
void insertFirstSutradara(listSutradara &S, adr_sutradara Y);
void insertLastSutradara(listSutradara &S, adr_sutradara Y);
void insertAfterSutradara(listSutradara &S, adr_sutradara B, adr_sutradara Y);
void deleteFirstSutradara(listSutradara &S, adr_sutradara &Y);
void deleteLastSutradara(listSutradara &S, adr_sutradara &Y);
void deleteAfterSutradara(listSutradara &S, adr_sutradara B, adr_sutradara &Y);
adr_sutradara findSutradara(listSutradara S, string Nama);
void printSutradara(listSutradara S);

// PROCEDURE MLL //
void tambahRelasi(listFilm &F, listSutradara &S, adr_film &X, adr_sutradara &Y);
void hapusDataFilm(listFilm &F, listSutradara &S, adr_film &X, adr_sutradara &Y);
void printFilm(listFilm F, listSutradara S);
int countFilm(listFilm F, listSutradara S);
void leastFilm(listFilm F, listSutradara S);
void mostFilm(listFilm F, listSutradara S);



#endif // FLIGHT_H_INCLUDED
