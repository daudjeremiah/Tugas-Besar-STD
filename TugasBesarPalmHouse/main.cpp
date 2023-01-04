#include "Film.h"

int main()
{
    char menuswitch;
    listFilm Lf;
    adr_film Pf, Pff;
    listSutradara Ls;
    adr_sutradara Ps, Pss;
    infotype F;
    string nameS;
    int x,durasi,y,z;
    string Fjudul, Fgenre;
    int Fdurasi;

    // KAMUS CASE 8 //

    adr_film FF, FFF, FFFF;

    x = 100;
    createListFilm(Lf);
    createListSutradara(Ls);
    while (x!=0){
        cout << "------------ Tugas Besar ------------" << endl;
        cout << "------------ Palm House ------------" << endl;
        cout << "Anggota Kelompok :" << endl;
        cout << "Daud Jeremiah Oscar Simanjuntak - 1301213404" << endl;
        cout << "Dio Irsaputra Siregar - 1301213012" << endl << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "1. Memasukan Data Film"<<endl;
        cout << "2. Memasukan Nama Sutradara"<<endl;
        cout << "3. Menampilkan Sutradara"<< endl;
        cout << "4. Menyambungkan Sutradara " <<endl;
        cout << "5. Menampilkan Sutradara yang Paling Banyak & Sedikit Menyutradarai Film "<< endl;
        cout << "6. Menampilkan Semua Data Film"<<endl;
        cout << "7. Menghapus Data Film"<<endl;
        cout << "8. Menghapus Data Sutradara"<<endl;
        cout << "9. Menghapus Semua Data Film"<<endl;
        cout << "0. Keluar"<<endl;
        cout << "Pilihan Anda: ";
        cin >> x;
        cout << endl;
        switch(x){
        case 1:
            system("cls");
            cout << "==========Masukkan Film========"<<endl;
            cout << "Masukkan Banyak Film yang ingin Dimasukkan: ";
            cin >> z;
            cout << endl << endl << "==========Input Film===========" << endl << "==============================="<<endl;
            for (int i=0;i<z;i++){
                cout << "Judul: ";
                getline(cin, F.Judul);
                getline(cin, F.Judul);
                //cin >> F.Judul;
                cout << "Genre: ";
                getline(cin, F.Genre);
                //cin >> F.Genre;
                cout << "Durasi: ";
                cin >> F.Durasi;
                Pff = findFilm(Lf, F.Judul, F.Genre, F.Durasi);
                if (Pff != nil){
                    cout << endl << "===============================" << endl;
                    cout << "DATA FILM DUPLIKAT !!!";
                    cout << endl << endl << endl;
                }else{
                    Pf = createNewFilm(F.Judul,F.Genre,F.Durasi,Pf);
                    insertLastFilm(Lf,Pf);
                    cout << "===============================" << endl;
                    cout << "INPUT FILM BERHASIL !!!";
                    cout<< endl << endl << endl;
                    }
            }
            kembaliKeMenu(x);
            break;
        case 2:
            system("cls");
            cout << "========Masukan Nama Sutradara========="<< endl;
            cout << "Nama Sutradara: ";
            getline(cin, nameS);
            getline(cin, nameS);
            //cin >> nameS;
            Pss = findSutradara(Ls, nameS);
            if (Pss != nil) {
                cout << endl << "=======================================" << endl << endl;
                cout << "NAMA SUTRADARA DUPLIKAT !!!";
            } else {
                Ps = createNewSutradara(nameS,Ps);
                insertLastSutradara(Ls,Ps);
                cout << "=======================================" << endl << endl;
                cout << "INPUT SUTRADARA BERHASIL !!!";
            }
            kembaliKeMenu(x);
            break;
        case 3:
            system("cls");
            cout << "====== List Nama Sutradara ========"<< endl;
            printSutradara(Ls);
            cout << endl;
            kembaliKeMenu(x);
            break ;
        case 4:
            system("cls");
            cout << "========Menyambungkan Sutradara========="<< endl;
            cout << "========Mencari Film========="<< endl;
            cout << "Judul: ";
            getline(cin, Fjudul);
            getline(cin, Fjudul);
            //cin >> Fjudul;
            cout << "Genre: ";
            getline(cin, Fgenre);
            //cin >> Fgenre;
            cout << "Durasi: ";
            cin >> Fdurasi;
            Pf = findFilm(Lf,Fjudul, Fgenre, Fdurasi);
            if (Pf == nil){
                cout << "============================="<< endl << endl;
                cout << "Data Film Tidak Ditemukan"<<endl;
                kembaliKeMenu(x);
                break;
            }

            cout << "============================="<< endl << endl;
            cout << "========Mencari Sutradara======="<< endl;
            cout << "Nama Sutradara: ";
            getline(cin, nameS);
            getline(cin, nameS);
            //cin >> nameS;
            Ps = findSutradara(Ls, nameS);
            if (Ps == nil){
                cout << "============================="<< endl << endl;
                cout << "Nama Sutradara Tidak Ditemukan"<< endl;
                kembaliKeMenu(x);
                break;
            }
            tambahRelasi(Lf, Ls,Pf,Ps);
            cout << "================================"<< endl << endl;
            cout << "RELASI BERHASIL !!!";
            kembaliKeMenu(x);
            break;

        case 5:
            system("cls");
            cout << "=======Menampilkan Sutradara yang Paling Banyak & Sedikit Menyutradarai Film========="<<endl << endl;
            mostFilm(Lf,Ls);
            leastFilm(Lf,Ls);
            cout << endl << "===========================================================================";
            kembaliKeMenu(x);
            break;
        case 6:
            system("cls");
            printFilm(Lf,Ls);
            cout << endl << "Total Film: " << countFilm(Lf,Ls);
            kembaliKeMenu(x);
            break;
        case 7:
            system("cls");
            if (isEmptyFilm(Lf)) {
                cout << "=========Menghapus Data Film========"<<endl << endl;
                cout << "LIST FILM KOSONG !!!" << endl << endl;
                cout << "====================================";
            } else {
                cout << "=========Menghapus Data Film========"<<endl;
                cout << "===================================="<<endl;
                cout << "Mencari Film yang Ingin Dihapus"<<endl;
                cout << "Judul: ";
                getline(cin, F.Judul);
                getline(cin, F.Judul);
                cout << "Genre: ";
                getline(cin, F.Genre);
                cout << "Durasi: ";
                cin >> F.Durasi;
                deleteFindFilm(Lf,Fjudul, Fgenre,Fdurasi);
            }
            kembaliKeMenu(x);
            break;
        case 8:
            system("cls");
            if (isEmptySutradara(Ls)) {
                cout << "=========Menghapus Data Sutradara========"<<endl << endl;
                cout << "LIST SUTRADARA KOSONG !!!" << endl << endl;
                cout << "=========================================";
            } else {
                cout << "========Menghapus Data Sutradara======"<<endl;
                cout << "Mencari Data Sutradara"<<endl;
                cout << "Nama: ";
                cin >> nameS;
                deleteFindSutradara(Lf,Ls,nameS);
            }

            kembaliKeMenu(x);
            break;
        case 9:
            system("cls");
            if (isEmptyFilm(Lf) && isEmptySutradara(Ls)){
                cout << "=========Menghapus Data Sutradara========"<<endl << endl;
                cout << "LIST DATA KOSONG !!!" << endl << endl;
                cout << "=========================================";
            }else{
                hapusSemuaData(Lf, Ls);
                cout << "SEMUA DATA TELAH DIHAPUS !!!"<<endl;
            }
            kembaliKeMenu(x);
            break;
        }

    }
    cout << "Anda berhasil keluar dari Program... "<<endl;

    return 0;
}
