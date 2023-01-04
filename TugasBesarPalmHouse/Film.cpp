#include "Film.h"

// PROCEDURE FILM //
void createListFilm(listFilm &F){
/*{ I.S -
    F.S Terbentuk List Film Kosong}*/
    First(F) = nil;
}
bool isEmptyFilm(listFilm F) {
/*{ I.S -
    F.S Mengembalikan nilai true jika list Film kosong}*/
    return (First(F) == nil);
}
bool onlyOneFilm(listFilm F) {
/*{ I.S -
    F.S Mengembalikan nilai true ketika list Film hanya memiliki 1 element}*/
    return (next(First(F)) == nil);
}
bool isLastFilm(listFilm F, adr_film X) {
/*{ I.S -
    F.S Mengembalikan nilai true ketika alamat pada pointer sama dengan alamat terakhir dalam list}*/
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
/*{ I.S Terdefinisi sebuah data film baru
    F.S Element yang berisi data film disimpan dalam alamat pointer}*/
    X = new elmFilm;

    info(X).Judul = Judul;
    info(X).Genre = Genre;
    info(X).Durasi = Durasi;

    next(X) = nil;
    next_s(X) = nil;
    return X;
}
adr_film toLastFilm(listFilm F){
/*{ I.S Terdefinisi List Film yang tidak kosong
    F.S Mengembalikan nilai alamat pointer pada bagian akhir list }*/
    adr_film P;

    P = First(F);
    while (next(P) != nil) {
        P = next(P);
    }

    return P;
}
void insertFirstFilm(listFilm &F, adr_film X){
/*{ I.S Terdefinisi sebuah list film yang mungkin kosong, dan alamat element dari data film
    F.S Data film masuk ke dalam list film di posisi awal}*/
    if (isEmptyFilm(F)) {
        First(F) = X;
    } else {
        next(X) = First(F);
        First(F) = X;
    }
}
void insertLastFilm(listFilm &F, adr_film X){
/*{ I.S Terdefinisi sebuah list film yang mungkin kosong, dan alamat element dari data film
    F.S Data film masuk ke dalam list film di posisi akhir}*/
    if (isEmptyFilm(F)) {
        First(F) = X;
    } else {
        adr_film P = toLastFilm(F);
        next(P) = X;
    }
}
void insertAfterFilm(listFilm &F, adr_film A, adr_film X){
/*{ I.S Terdefinisi list film tidak kosong, dan alamat element dari data film
    F.S Data Film masuk ke dalam list di setelah pointer A}*/
    next(X) = next(A);
    next(A) = X;
}
void deleteFirstFilm(listFilm &F, adr_film &X){
/*{ I.S Terdefinisi sebuah list film yang mungkin kosong,
    F.S Data film yang berada di awal list dilm di hapus dan alamatnya disimpan dalam pointer}*/
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
/*{ I.S Terdefinisi sebuah list film yang mungkin kosong,
    F.S Data film yang berada di akhir list dilm di hapus dan alamatnya disimpan dalam pointer}*/
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
void deleteAfterFilm(listFilm &F, adr_film &A, adr_film &X){
/*{ I.S Terdefinisi list film yang tidak kosong
    F.S Menghapus film setelah pointer A, dan menyimpannya dalam pointer X}*/
    X = next(A);
    next(A) = next(X);
    next_s(X) = nil;
    next(X) = nil;
}
void deleteFindFilm(listFilm &F, string judul, string genre, int durasi){
/*{ I.S Terdefinisi list Film tidak kosong
    F.S Mengapus data Film yang dicari}*/
    adr_film P,PF,PFF;

    if (isEmptyFilm(F)) {
        cout << endl << " List Film Kosong" << endl;
    } else {
        PF = findFilm(F, judul, genre, durasi);

        if (PF == nil) {
            cout << endl << endl << "Data tidak ditemukan" << endl;
        } else {
            if (PF == First(F)) {
                deleteFirstFilm(F, P);
            }else if (PF == toLastFilm(F)) {
                deleteLastFilm(F,P);
            }else {
                PFF = First(F);
                while (next(PFF)!= PF){
                    PFF = next(PFF);
                }
                deleteAfterFilm(F, PFF, P);
            }
        }
    }
    cout << "===================================="<<endl;
    cout << "PENGHAPUSAN BERHASIL !!!";
}
adr_film findFilm(listFilm F, string Judul, string Genre, int Durasi){
/*{ I.S Terdefinisi List Film mungkin kosong
    F.S Mengembalikan alamat dari element yang dicari }*/
    adr_film P;
    P = First(F);
    while ( (P != nil) && ( (info(P).Judul != Judul) || (info(P).Genre != Genre) || (info(P).Durasi != Durasi) ) )  {
        P = next(P);
    }

    return P;
}




// PROCEDURE SUTRADARA //
void createListSutradara(listSutradara &S){
/*{ I.S -
    F.S Terbentuk list Sutradara kosong}*/
    First(S) = nil;
}
bool isEmptySutradara(listSutradara S) {
/*{ I.S -
    F.S Mengembalikan nilai true jika list sutradara kosong}*/
    return (First(S) == nil);
}
bool onlyOneSutradara(listSutradara S) {
/*{ I.S -
    F.S Mengembalikan nilai True jika List Sutradara hanya memiliki 1 element}*/
    return (next(First(S)) == nil);
}
bool isLastSutradara(listSutradara S, adr_sutradara Y) {
/*{ I.S Terdefinisi List Sutradara mungkin kosong
    F.S Mengembalikan nilai true ketika alamat pada pointer sama dengan alamat terakhir dalam list}*/
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
/*{ I.S Terdefinisi sebuah data sutradara baru
    F.S Element yang berisi data sutradara disimpan dalam alamat pointer}*/
    Y = new elmSutradara;

    info(Y) = Nama;
    next(Y) = nil;
    return Y;
}
adr_sutradara toLastSutradara(listSutradara S){
/*{ I.S Terdefinisi List Sutradara yang tidak kosong
    F.S Mengembalikan nilai alamat pointer pada bagian akhir list }*/
    adr_sutradara P;

    P = First(S);
    while (next(P) != nil) {
        P = next(P);
    }

    return P;
}
void insertFirstSutradara(listSutradara &S, adr_sutradara Y){
/*{ I.S Terdefinisi sebuah list Sutradara yang mungkin kosong, dan alamat element dari data Sutradara
    F.S Data Sutradara masuk ke dalam list Sutradara di posisi awal}*/

    if (isEmptySutradara(S)) {
        First(S) = Y;
    } else {
        next(Y) = First(S);
        First(S) = Y;
    }
}
void insertLastSutradara(listSutradara &S, adr_sutradara Y){
/*{ I.S Terdefinisi sebuah list Sutradara yang mungkin kosong, dan alamat element dari data Sutradara
    F.S Data Sutradara masuk ke dalam list Sutradara di posisi akhir}*/
    if (isEmptySutradara(S)) {
        First(S) = Y;
    } else {
        adr_sutradara P = toLastSutradara(S);
        next(P) = Y;
    }
}
void insertAfterSutradara(listSutradara &S, adr_sutradara B, adr_sutradara Y){
/*{ I.S Terdefinisi list sutradara dengan data minimal 2
    F.S Data sutradara masuk ke dalam list sutradara di posisi setelah B}*/
    next(Y) = next(B);
    next(B) = Y;
}
void deleteFirstSutradara(listSutradara &S, adr_sutradara &Y){
/*{ I.S Terdefinisi List Sutradara mungkin kosong
    F.S Menghapus data Sutradara pada posisi awal dan menyimpan pada pointer}*/
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
/*{ I.S Terdefinisi List Sutradara mungkin kosong
    F.S Menghapus data Sutradara pada posisi akhir dan menyimpan pada pointer}*/
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
/*{ I.S Terdefinisi List tidak kosong
    F.S Menghapus element setelah B dan data disimpan dalam variabel Y}*/
    Y = next(B);
    next(B) = next(Y);
    next(Y) = nil;
}
adr_sutradara findSutradara(listSutradara S, string Nama) {
/*{ I.S Terdefinisi List Sutradara mungkin kosong
    F.S Mengembalikan alamat dari elemnt yang dicari}*/
    adr_sutradara P = First(S);

    while (P!= nil && info(P) != Nama) {
        P = next(P);
    }

    return P;
}
void deleteFindSutradara(listFilm &F, listSutradara &S, string Nama){
/*{ I.S Terdefinisi List Sutradara mungkin kosong
    F.S Menghapus Data element yang dicari dan memutus dengan list Film}*/
    adr_sutradara P,PS,PSS;
    PS = findSutradara(S, Nama);

    adr_film Pf = First(F);
    while (Pf != nil) {
        if (next_s(Pf) == PS) {
            next_s(Pf) = nil;
        }
        Pf = next(Pf);
    }

    if (PS == First(S)){
        deleteFirstSutradara(S, P);
    }else if (PS == toLastSutradara(S)) {
        deleteLastSutradara(S,P);
    }else{
        PSS = First(S);
        while (next(PSS)!= PS){
            PSS = next(PSS);
        }
        deleteAfterSutradara(S, PSS, P);
    }
    cout << "======================================"<<endl;
    cout << "PENGHAPUSAN BERHASIL !!!";

}
void printSutradara(listSutradara S){
/*{ I.S terdefinisi List Sutradara mungkin Kosong
    F.S Menampilkan semua data pada List Sutradara}*/
    adr_sutradara P = First(S);
    system("cls");
    cout << "====== List Nama Sutradara ========" << endl << endl;
    if (First(S)== nil){
        cout << "List Sutradara Kosong"<< endl;
    }else{
        while (P!= nil){
            cout <<"Nama Sutradara: "<< info(P) << endl;
            P = next(P);
        }
    }

    cout << endl << "===================================";
}


// PROCEDURE MLL //
void tambahRelasi(listFilm &F, listSutradara &S, adr_film &X, adr_sutradara &Y){
/*{ I.S Terdefinisi List Film & List Sutradara tidak kosong
    F.S Menyambungkan List Film dengan List Sutradara}*/
    next_s(X) = Y;
}
void hapusSemuaData(listFilm &F, listSutradara &S){
/*{ I.S Terdefinisi List Film & List Sutradara Tidak kosong
    F.S Menghapus Semua Data pada List Film dan Sutradara}*/
    while (!isEmptyFilm(F)) {
        adr_film x;
        deleteFirstFilm(F, x);
    }

    while (!isEmptySutradara(S)) {
        adr_sutradara y;
        deleteFirstSutradara(S, y);
    }
}
void printFilm(listFilm F, listSutradara S){
/*{ I.S Terdefinisi List Film & List Sutradara Mungkin kosong
    F.S Menampilkan List Film & Sutradara}*/
    adr_film P = First(F);

    cout << "=========List Film=======" << endl << endl;

    if (P == nil) {
        cout << "List film kosong !!!" << endl << endl;
    } else {
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
    cout << "=========================="<<endl;
}
int countFilm(listFilm F, listSutradara S){
/*{ I.S Terdefinisi list Film Kosong
    F.S Mengembalikan jumlah banyaknya element pada list Film}*/
    adr_film P = First(F);
    int i = 0;

    while (P != nil) {
        i++;
        P = next(P);
    }
    return i;
}
void leastFilm(listFilm F, listSutradara S){
/*{ I.S Terdefinisi MLL yang mungkin kosong
    F.S Menampilkan Nama Sutradara yang paling sedikit menyutradarai Film}*/
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
/*{ I.S Terdefinisi MLL yang mungkin kosong
    F.S Menampilkan Nama Sutradara yang paling banyak menyutradarai Film}*/
    if ( (isEmptyFilm(F)) || (isEmptySutradara(S)) ) {
        cout << "Salah Satu List Kosong" << endl;
    } else if (onlyOneSutradara(S)) {
        cout << "Sutradara dengan film paling banyak adalah: " << info(First(S)) << endl;
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
        cout << "Sutradara dengan film paling banyak adalah: " << info(adr_max) << endl;
    }
}


// PROCEDURE MENU //
void kembaliKeMenu(int &x) {
/* Prosedur yang digunakan untuk user kembali ke menu utama */
    char menuswitch;
    cout << endl << endl << endl << "Kembali ke menu utama? (Y/N): ";
    cin >> menuswitch;
    while ( (menuswitch != 'Y') && (menuswitch != 'N') &&  (menuswitch != 'y') && (menuswitch != 'n') ) {
            cout << "Input tidak sesuai, silahkan input ulang (Y/N): ";
            cin >> menuswitch;
    }
    if ( (menuswitch == 'Y') || (menuswitch == 'y') ){
        x = 1;
    } else {
        x = 0;
    }
    system("cls");
}
