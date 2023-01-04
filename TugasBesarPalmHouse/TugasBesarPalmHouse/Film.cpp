#include "Film.h"

// PROCEDURE FILM //
void createListFilm(listFilm &F){
    First(F) = nil;
}
bool isEmptyFilm(listFilm F) {
    return (First(F) == nil);
}
bool onlyOneFilm(listFilm F) {
    return (next(First(F)) == nil);
}
bool isLastFilm(listFilm F, adr_film X) {
    if (isEmptyFilm(F)) {
        return false;
    } else if (onlyOneFilm(F)) {
        return true;
    } else {
        adr_film P = toLastFilm(F);

        if (X == P) {
            return true;
        } else {
            return false;
        }
    }
}
adr_film createNewFilm(string Judul, string Genre, int Durasi, adr_film X){
    X = new elmFilm;

    info(X).Judul = Judul;
    info(X).Genre = Genre;
    info(X).Durasi = Durasi;

    next(X) = nil;
    next_s(X) = nil;
    return X;
}

adr_film toLastFilm(listFilm F){
    adr_film P;

    P = First(F);
    while (next(P) != nil) {
        P = next(P);
    }

    return P;
}
void insertFirstFilm(listFilm &F, adr_film X){
    if (isEmptyFilm(F)) {
        First(F) = X;
    } else {
        next(X) = First(F);
        First(F) = X;
    }
}
void insertLastFilm(listFilm &F, adr_film X){
    if (isEmptyFilm(F)) {
        First(F) = X;
    } else {
        adr_film P = toLastFilm(F);
        next(P) = X;
    }
}
void insertAfterFilm(listFilm &F, adr_film A, adr_film X){
    next(X) = next(A);
    next(A) = X;
}
void deleteFirstFilm(listFilm &F, adr_film &X){
    if (isEmptyFilm(F)) {
        cout << "List Film Kosong" << endl;
    } else if (onlyOneFilm(F)) {
        X = First(F);
        First(F) = nil;
    } else {
        X = First(F);
        First(F) = next(First(F));
        next(X) = nil;
    }
}
void deleteLastFilm(listFilm &F, adr_film &X){
    if (isEmptyFilm(F)) {
        cout << "List Film Kosong" << endl;
    } else if (onlyOneFilm(F)) {
        X = First(F);
        First(F) = nil;
    } else {
        X = toLastFilm(F);
        adr_film A = First(F);
        while (next(A) != X) {
            A = next(A);
        }

        next(A) = nil;
    }
}
void deleteAfterFilm(listFilm &F, adr_film A, adr_film &X){
    X = next(A);
    next(A) = next(X);
    next(X) = nil;
}
adr_film findFilm(listFilm F, string Judul, string Genre, int Durasi){
    adr_film P;
    P = First(F);
    while ((P!=nil) &&  (info(P).Judul != Judul) && (info(P).Genre != Genre) && (info(P).Durasi != Durasi) ) {
        P = next(P);
    }

    return P;
}




// PROCEDURE SUTRADARA //
void createListSutradara(listSutradara &S){
    First(S) = nil;
}
bool isEmptySutradara(listSutradara S) {
    return (First(S) == nil);
}
bool onlyOneSutradara(listSutradara S) {
    return (next(First(S)) == nil);
}
bool isLastSutradara(listSutradara S, adr_sutradara Y) {
    if (isEmptySutradara(S)) {
        return false;
    } else if (onlyOneSutradara(S)) {
        return true;
    } else {
        if (Y == toLastSutradara(S)) {
            return true;
        } else {
            return false;
        }
    }
}
adr_sutradara createNewSutradara(string Nama, adr_sutradara Y){
    Y = new elmSutradara;

    info(Y) = Nama;
    next(Y) = nil;
    return Y;
}
adr_sutradara toLastSutradara(listSutradara S){
    adr_sutradara P;

    P = First(S);
    while (next(P) != nil) {
        P = next(P);
    }

    return P;
}
void insertFirstSutradara(listSutradara &S, adr_sutradara Y){
    if (isEmptySutradara(S)) {
        First(S) = Y;
    } else {
        next(Y) = First(S);
        First(S) = Y;
    }
}
void insertLastSutradara(listSutradara &S, adr_sutradara Y){
    if (isEmptySutradara(S)) {
        First(S) = Y;
    } else {
        adr_sutradara P = toLastSutradara(S);
        next(P) = Y;
    }
}
void insertAfterSutradara(listSutradara &S, adr_sutradara B, adr_sutradara Y){
    next(Y) = next(B);
    next(B) = Y;
}
void deleteFirstSutradara(listSutradara &S, adr_sutradara &Y){
    if (isEmptySutradara(S)) {
        cout << "List Sutradara Kosong" << endl;
    } else if (onlyOneSutradara(S)) {
        Y = First(S);
        First(S) = nil;
    } else {
        Y = First(S);
        First(S) = next(First(S));
        next(Y) = nil;
    }
}
void deleteLastSutradara(listSutradara &S, adr_sutradara &Y){
    if (isEmptySutradara(S)) {
        cout << "List Sutradara Kosong" << endl;
    } else if (onlyOneSutradara(S)) {
        Y = First(S);
        First(S) = nil;
    } else {
        Y = toLastSutradara(S);
        adr_sutradara B = First(S);
        while (next(B) != Y) {
            B = next(B);
        }

        next(B) = nil;
    }
}
void deleteAfterSutradara(listSutradara &S, adr_sutradara B, adr_sutradara &Y){
    Y = next(B);
    next(B) = next(Y);
    next(Y) = nil;
}
adr_sutradara findSutradara(listSutradara S, string Nama) {
    adr_sutradara P = First(S);

    while (P!= nil && info(P) != Nama) {
        P = next(P);
    }

    return P;
}
void printSutradara(listSutradara S){
    adr_sutradara P = First(S);
    if (First(S)== nil){
        cout << "Nama Sutradara Kosong"<< endl;
    }else{
        while (P!= nil){
            cout <<"Nama Sutradara: "<< info(P) << endl;
            P = next(P);
        }
    }
}


// PROCEDURE MLL //
void tambahRelasi(listFilm &F, listSutradara &S, adr_film &X, adr_sutradara &Y){
    next_s(X) = Y;
}
void hapusDataFilm(listFilm &F, listSutradara &S, adr_film &X, adr_sutradara &Y){
        if (X == First(F)) {
            Y = next_s(X);
            next_s(X) = nil;
            deleteFirstFilm(F, X);

            if (Y == First(S)) {
                deleteFirstSutradara(S, Y);
            } else if (isLastSutradara(S, Y)) {
                deleteLastSutradara(S, Y);
            } else {
                adr_sutradara Q = First(S);
                while (next(Q) != Y) {
                    Q = next(Q);
                }
                deleteAfterSutradara(S, Q, Y);
            }
        }

        else if (isLastFilm(F, X)) {
            Y = next_s(X);
            next_s(X) = nil;
            deleteLastFilm(F, X);

            if (Y == First(S)) {
                deleteFirstSutradara(S, Y);
            } else if (isLastSutradara(S, Y)) {
                deleteLastSutradara(S, Y);
            } else {
                adr_sutradara Q = First(S);
                while (next(Q) != Y) {
                    Q = next(Q);
                }
                deleteAfterSutradara(S, Q, Y);
            }
        } else {
            Y = next_s(X);
            next_s(X) = nil;
            adr_film W = First(F);
            while (next(W) != nil) {
                W = next(W);
            }
            deleteAfterFilm(F, W, X);

            if (Y == First(S)) {
                deleteFirstSutradara(S, Y);
            } else if (isLastSutradara(S, Y)) {
                deleteLastSutradara(S, Y);
            } else {
                adr_sutradara Q = First(S);
                while (next(Q) != Y) {
                    Q = next(Q);
                }
                deleteAfterSutradara(S, Q, Y);
            }
        }
}
void printFilm(listFilm F, listSutradara S){
    adr_film P = First(F);


    while (P != nil) {
        if (next_s(P) == nil) {
            cout <<"Judul: "<< info(P).Judul << "\n" <<"Sutradara: "<< "Belum Terhubung" << "\n" <<"Genre: "<< info(P).Genre << "\n" <<"Durasi: " <<info(P).Durasi << " Menit"<<"\n" << endl;\
            P = next(P);
        } else {
            cout <<"Judul: "<< info(P).Judul << "\n" <<"Sutradara: "<< info(next_s(P)) << "\n" <<"Genre: "<< info(P).Genre << "\n" <<"Durasi: " <<info(P).Durasi << " Menit"<<"\n" << endl;\
            P = next(P);
        }
    }
}
int countFilm(listFilm F, listSutradara S){
    adr_film P = First(F);
    int i = 0;

    while (P != nil) {
        i++;
        P = next(P);
    }
    return i;
}
void leastFilm(listFilm F, listSutradara S){
    if ( (isEmptyFilm(F)) || (isEmptySutradara(S)) ) {
        cout << "Salah Satu List Kosong" << endl;
    } else if (onlyOneSutradara(S)) {
        cout << "Sutradara dengan film paling sedikit adalah: " << info(First(S)) << endl;
    } else {
        adr_sutradara adr_min;
        adr_film X;
        adr_sutradara Y;
        int min;
        int count;

        // Inisiasi Sutradara pertama sebagai sutradara dengan film paling sedikit
        adr_min = First(S);
        X = First(F);
        Y = First(S);
        while (X != nil) {
            if (next_s(X) == Y) {
                min++;
            }
            X = next(X);
        }
        Y = next(Y);

        while (Y != nil) {
            count = 0;
            X = First(F);
            while (X != nil) {
                if (next_s(X) == Y) {
                    count++;
                }
                X = next(X);
            }
            if (count < min) {
                adr_min = Y;
                min = count;
            }
            Y = next(Y);
        }

        cout << "Sutradara dengan film paling sedikit adalah: " << info(adr_min) << endl;

    }
}
void mostFilm(listFilm F, listSutradara S){
    if ( (isEmptyFilm(F)) || (isEmptySutradara(S)) ) {
        cout << "Salah Satu List Kosong" << endl;
    } else if (onlyOneSutradara(S)) {
        cout << "Sutradara dengan film paling terbanyak adalah: " << info(First(S)) << endl;
    } else {
        adr_sutradara adr_max;
        adr_film X;
        adr_sutradara Y;
        int max;
        int count;

        // Inisiasi Sutradara pertama sebagai sutradara dengan film paling banyak
        adr_max = First(S);
        X = First(F);
        Y = First(S);
        while (X != nil) {
            if (next_s(X) == Y) {
                max++;
            }
            X = next(X);
        }
        Y = next(Y);

        while (Y != nil) {
            count = 0;
            X = First(F);
            while (X != nil) {
                if (next_s(X) == Y) {
                    count++;
                }
                X = next(X);
            }
            if (count > max) {
                adr_max = Y;
                max = count;
            }
            Y = next(Y);
        }
        cout << "Sutradara dengan film paling sedikit adalah: " << info(adr_max) << endl;
    }
}
