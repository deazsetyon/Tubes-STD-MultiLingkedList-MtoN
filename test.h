#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include <iostream>
using namespace std;

#define info(P) (P)->info
#define child(P) (P)->child
#define lastChild(P) (P)->lastChild
#define prev(P) (P)->prev
#define next(P) (P)->next
#define first(L) ((L).first)
#define last(L) ((L).last)

typedef struct elmAktor *adrAktor;
typedef struct elmChild *adrChild;
typedef struct elmFilm *adrFilm;

struct aktor{
    string nama,asal,tanggal;
    int umur;
};
struct film{
    string judul,sutradara,genre,durasi;
    int tahun;
};
struct elmAktor{
    aktor info;
    adrChild child;
    adrChild lastChild;
    adrAktor prev,next;
};
struct elmChild{
    adrFilm info;
    adrChild prev,next;
};
struct elmFilm{
    film info;
    adrFilm prev,next;
};
struct listAktor{
    adrAktor first,last;
};
struct listFilm{
    adrFilm first,last;
};

int showMenu();
void createAktor(listAktor &LA);
void createFilm(listFilm &LF);

adrAktor createElmAktor(aktor x);
adrChild createElmChild(adrFilm P);
adrFilm createElmFilm(film x);

void insertFilm(listFilm &LF,adrFilm P);

void deleteFirstAktor(listAktor &LA,adrAktor &P);
void deleteFirstChild(adrAktor P,adrChild &Q);
void deleteFirstFilm(listFilm &LF,adrFilm &P);
void deleteLastAktor(listAktor &LA,adrAktor &P);
void deleteLastChild(adrAktor P,adrChild &Q);
void deleteLastFilm(listFilm &LF,adrFilm &P);
void deleteAfterAktor(adrAktor prec,adrAktor &P);
void deleteAfterChild(adrChild prec,adrChild &Q);
void deleteAfterFilm(adrFilm prec,adrFilm &P);

void deleteAktor(listAktor &LA,string nama,adrAktor &P);
void deleteChild(adrAktor &P,adrChild Q,adrChild &R);
void deleteFilm(listFilm &LF,string judul,adrFilm &P);

//pembantu
void connecting(adrAktor P,adrChild Q);
adrFilm searchFilm(listFilm LF,string judul);
void showFilmInAktor(listAktor LA);
void deleteFilmTertentu(listAktor &LA,listFilm &LF,string judul);
adrAktor cekAktor(listAktor LA,string nama,string asal,string tgl,int umur);
adrFilm cekFilm(listFilm LF,string judul,string genre,string sutradara,string durasi,int tahun);

//fungsi ditugas besar
void insertAktor(listAktor &LA,adrAktor P);
void printAktor(listAktor LA,string nama);
void deleteAktorTertentu(listAktor &LA,string nama);
adrAktor searchAktor(listAktor LA,string nama);
void insertFilmOlehAktor(listAktor &LA,listFilm &LF);
void deleteFilmDariAktor(listAktor &LA,listFilm &LF,string nama,string judul);
void showFilmDariAktor(listAktor LA,string nama);
adrChild searchFilmDariAktor(listAktor LA,listFilm LF,string judul);
void AddRelation(listAktor LA,listFilm LF,string nama,string judul);
void DeleteRelation(listAktor LA,listFilm LF,string nama,string judul);
void AktorPopuler(listAktor LA,listFilm LF);
void showAktorDariFilm(listAktor LA,string judul);
#endif // TEST_H_INCLUDED
