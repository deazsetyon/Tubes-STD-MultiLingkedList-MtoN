#include "test.h"

int main(){
    listAktor LA;
    listFilm LF;
    aktor newAktor;
    adrAktor P;
    int pilihan;
    string lanjut;

    createAktor(LA);
    createFilm(LF);
    pilihan=showMenu();

    while (pilihan!=0){
        if (pilihan==1){
            cout<<"Nama : ";cin>>newAktor.nama;
            cout<<"Asal : ";cin>>newAktor.asal;
            cout<<"Tanggal lahir : ";cin>>newAktor.tanggal;
            cout<<"Umur :";cin>>newAktor.umur;
            if (cekAktor(LA,newAktor.nama,newAktor.asal,newAktor.tanggal,newAktor.umur)==NULL){
                P=createElmAktor(newAktor);
                insertAktor(LA,P);
                cout<<"Aktor "<<newAktor.nama<<" berhasil ditambahkan ke List"<<endl;
            }else{
                cout<<"Aktor tersebut sudah ada di list"<<endl;
            }

        }else if(pilihan==2){
            string nama;
            cout<<"Nama aktor yang dicari : ";cin>>nama;
            printAktor(LA,nama);
        }else if(pilihan==3){
            string nama;
            cout<<"Nama aktor yang akan dihapus : ";cin>>nama;
            deleteAktorTertentu(LA,nama);
            cout<<"Aktor "<<nama<<" berhasil dihapus"<<endl;
        }else if(pilihan==4){
            insertFilmOlehAktor(LA,LF);
        }else if(pilihan==5){
            string nama,judul;
            cout<<"Nama aktor : ";cin>>nama;
            cout<<"Judul Film : ";cin>>judul;
            deleteFilmDariAktor(LA,LF,nama,judul);
            cout<<"Film "<<judul<<" berhasil dihapus dari aktor "<<nama<<endl;
        }else if(pilihan==6){
            string nama;
            cout<<"Nama aktor : ";cin>>nama;
            showFilmDariAktor(LA,nama);
        }else if(pilihan==7){
            string nama,judul;
            cout<<"Nama aktor : ";cin>>nama;
            cout<<"Judul Film : ";cin>>judul;
            AddRelation(LA,LF,nama,judul);
        }else if(pilihan==8){
            string nama,judul;
            cout<<"Nama aktor : ";cin>>nama;
            cout<<"Judul Film : ";cin>>judul;
            DeleteRelation(LA,LF,nama,judul);
            cout<<"Film "<<judul<<" berhasil dihapus dari aktor "<<nama<<endl;
        }else if(pilihan==9){
            AktorPopuler(LA,LF);
        }else if(pilihan==10){
            string judul;
            cout<<"Judul : ";cin>>judul;
            showAktorDariFilm(LA,judul);
        }else if (pilihan==11){
            film newFilm;
            cout<<"judul : ";cin>>newFilm.judul;
            cout<<"genre : ";cin>>newFilm.genre;
            cout<<"sutradara : ";cin>>newFilm.sutradara;
            cout<<"Durasi : ";cin>>newFilm.durasi;
            cout<<"tahun tayang : ";cin>>newFilm.tahun;
            if (cekFilm(LF,newFilm.judul,newFilm.genre,newFilm.sutradara,newFilm.durasi,newFilm.tahun)==NULL){
                adrFilm P=createElmFilm(newFilm);
                insertFilm(LF,P);
                cout<<"Film "<<newFilm.judul<<" berhasil ditambahkan ke list"<<endl;
            }else{
                cout<<"Film tersebut sudah ada di list"<<endl;
            }

        }else if(pilihan==12){
            string judul;
            cout<<"Film yang akan dihapus : ";cin>>judul;
            deleteFilmTertentu(LA,LF,judul);
            cout<<"Film "<<judul<<" berhasil dihapus dari list"<<endl;
        }else if(pilihan==100){
            cout<<endl;
            cout<<"============================================"<<endl;
            cout<<"Hanya untuk mengecek relasi nya saja"<<endl;
            showFilmInAktor(LA);
            cout<<endl;
            cout<<"============================================"<<endl;
        }
        cout<<endl;
        cout<<"Kembali ke menu utama (Y/N) : ";cin>>lanjut;
        if (lanjut=="Y" || lanjut=="y"){
            pilihan=showMenu();
        }else{
            pilihan=0;
        }
    }
    return 0;
}
