#include "test.h"

int showMenu(){
    int pil;
    cout<<"===============MENU==============="<<endl;
    cout<<"1. Menambahkan aktor baru"<<endl;
    cout<<"2. Menampilkan data aktor X" <<endl;
    cout<<"3. Menghapus aktor tertentu"<<endl;
    cout<<"4. Menambahkan film Y oleh aktor X"<<endl;
    cout<<"5. Menghapus film Y dari aktor X"<<endl;
    cout<<"6. Menampilkan seluruh film oleh aktor X"<<endl;
    cout<<"7. Membuat relasi antara aktor X dan film Y"<<endl;
    cout<<"8. Menghapus relasi antara aktor X dan film Y"<<endl;
    cout<<"9. Menampilkan aktor yang memiliki jumlah jumlah film paling banyak dan menampilkan judul filmnya"<<endl;
    cout<<"10. Menampilkan aktor-aktor dari judul Y "<<endl;
    cout<<"11. Menambah film baru"<<endl;
    cout<<"12. Menghapus film tertentu"<<endl;
    cout<<"100. Hanya pengecekan relasi "<<endl;
    cout<<"0. EXIT"<<endl;
    cout<<endl;
    cout<<"Masukkan menu : ";cin>>pil;

    return pil;
}
void createAktor(listAktor &LA){
    first(LA)=NULL;
    last(LA)=NULL;
}
void createFilm(listFilm &LF){
    first(LF)=NULL;
    last(LF)=NULL;
}

adrAktor createElmAktor(aktor x){
    adrAktor P =new elmAktor;
    info(P)=x;
    child(P)=NULL;
    lastChild(P)=NULL;
    next(P)=NULL;
    prev(P)=NULL;

    return P;
}
adrChild createElmChild(adrFilm P){
    adrChild Q=new elmChild;
    info(Q)=P;
    next(Q)=NULL;
    prev(Q)=NULL;

    return Q;
}
adrFilm createElmFilm(film x){
    adrFilm P =new elmFilm;
    info(P)=x;
    next(P)=NULL;
    prev(P)=NULL;
    return P;
}

void insertFilm(listFilm &LF,adrFilm P){
    //insert last DLL
    if (first(LF)==NULL && last(LF)==NULL){
        first(LF)=P;
        last(LF)=P;
    }else{
        prev(P)=last(LF);
        next(last(LF))=P;
        last(LF)=P;
    }
}

void deleteFirstAktor(listAktor &LA,adrAktor &P){
    if (first(LA)==NULL && last(LA)==NULL){
        cout<<"List Kosong"<<endl;
    }else if(next(first(LA))== first(LA)){
        P=first(LA);
        first(LA)=NULL;
        last(LA)=NULL;
    }else{
        P=first(LA);
        first(LA)=next(first(LA));
        next(last(LA))=first(LA);
        prev(first(LA))=last(LA);
        next(P)=NULL;
        prev(P)=NULL;
    }
}
void deleteFirstChild(adrAktor P,adrChild &Q){
    if (child(P)==NULL && lastChild(P)==NULL){
        cout<<"Tidak ada film yang diperankan"<<endl;
    }else{
        Q=child(P);
        if(child(P)==lastChild(P)){
            child(P)=NULL;
            lastChild(P)=NULL;
        }else{
            child(P)=next(Q);
            next(Q)=NULL;
            prev(child(P))=NULL;
        }
    }
}
void deleteFirstFilm(listFilm &LF,adrFilm &P){
    if (first(LF)==NULL && last(LF)==NULL){
        cout<<"List Kosong"<<endl;
    }else{
        P=first(LF);
        if (first(LF)==last(LF)){
            first(LF)==NULL;
            last(LF)==NULL;
        }else{
            first(LF)=next(P);
            next(P)=NULL;
            prev(first(LF))=NULL;
        }
    }
}
void deleteLastAktor(listAktor &LA,adrAktor &P){
    if (first(LA)==NULL && last(LA)==NULL){
        cout<<"List Kosong"<<endl;
    }else if (next(first(LA))==first(LA)){
        P=first(LA);
        first(LA)=NULL;
        last(LA)=NULL;
    }else{
        P=last(LA);
        last(LA)=prev(last(LA));
        prev(first(LA))=last(LA);
        next(last(LA))=first(LA);
        next(P)=NULL;
        prev(P)=NULL;
    }
}
void deleteLastChild(adrAktor P,adrChild &Q){
    if (child(P)==NULL && lastChild(P)==NULL){
        cout<<"Tidak ada film yang diperankan"<<endl;
    }else{
        Q=lastChild(P);
        if (child(P)==lastChild(P)){
            child(P)=NULL;
            lastChild(P)=NULL;
        }else{
            lastChild(P)=prev(lastChild(P));
            prev(Q)=NULL;
            next(lastChild(P))=NULL;
        }
    }
}
void deleteLastFilm(listFilm &LF,adrFilm &P){
    if (first(LF)==NULL && last(LF)==NULL){
        cout<<"List Kosong"<<endl;
    }else{
        P=last(LF);
        if (first(LF)==last(LF)){
            first(LF)=NULL;
            last(LF)=NULL;
        }else{
            last(LF)=prev(last(LF));
            prev(P)=NULL;
            next(last(LF))=NULL;
        }
    }
}
void deleteAfterAktor(adrAktor prec,adrAktor &P){
    P=next(prec);
    next(prec)=next(P);
    prev(next(P))=prec;
    prev(P)=NULL;
    next(P)=NULL;
}
void deleteAfterChild(adrChild prec,adrChild &Q){
    Q=next(prec);
    next(prec)=next(Q);
    prev(next(Q))=prec;
    prev(Q)=NULL;
    next(Q)=NULL;
}
void deleteAfterFilm(adrFilm prec,adrFilm &P){
    P=next(prec);
    next(prec)=next(P);
    prev(next(P))=prec;
    prev(P)=NULL;
    next(P)=NULL;
}

void deleteAktor(listAktor &LA,string nama,adrAktor &P){
    adrAktor cari = searchAktor(LA,nama);
    if (cari!=NULL){
        if (cari==first(LA)){
            deleteFirstAktor(LA,P);
        }else if (cari==last(LA) && next(cari)==first(LA)){
            deleteLastAktor(LA,P);
        }else{
            deleteAfterAktor(prev(cari),P);
        }
    }else{
        cout<<"Nama aktor tidak ditemukan"<<endl;
    }
}
void deleteChild(adrAktor &P,adrChild Q,adrChild &R){
    if (Q!=NULL){
        if (Q==child(P)){
            deleteFirstChild(P,R);
        }else if(Q==lastChild(P)){
            deleteLastChild(P,R);
        }else{
            deleteAfterChild(prev(Q),R);
        }
    }else{
        cout<<"film yang dicari tidak ada"<<endl;
    }
}
void deleteFilm(listFilm &LF,string judul,adrFilm &P){
    adrFilm cari=searchFilm(LF,judul);
    if (cari!=NULL){
        if (cari==first(LF)){
            deleteFirstFilm(LF,P);
        }else if (cari==last(LF)){
            deleteLastFilm(LF,P);
        }else{
            deleteAfterFilm(prev(cari),P);
        }
    }else{
        cout<<"Film tidak ditemukan"<<endl;
    }
}

//PEMBANTU
void connecting(adrAktor P,adrChild Q){
    if (child(P)==NULL && lastChild(P)==NULL){
        child(P)=Q;
        lastChild(P)=Q;
    }else{
        prev(Q)=lastChild(P);
        next(lastChild(P))=Q;
        lastChild(P)=Q;
    }
}
adrFilm searchFilm(listFilm LF,string judul){
    adrFilm found=NULL;
    adrFilm P=first(LF);
    if (first(LF)==NULL){
        return NULL;
    }else{
        while (P!=NULL && found==NULL){
            if (info(P).judul==judul){
                found=P;
            }
            P=next(P);
        }
    }
    return found;

}
void showFilmInAktor(listAktor LA){
    adrAktor P=first(LA);
    if (first(LA)==NULL){
        cout<<"List Kosong"<<endl;
    }else{
        while (next(P)!=first(LA)){
            cout<<info(P).nama<<" -> ";
            adrChild Q = child(P);
            while (Q!=NULL){
                cout<<info(info(Q)).judul<<" ";
                Q=next(Q);
            }
            P=next(P);
            cout<<endl;
        }
        cout<<info(P).nama<<" -> ";
        adrChild Q = child(P);
        while (Q!=NULL){
            cout<<info(info(Q)).judul<<" ";
            Q=next(Q);
        }

    }
}
void deleteFilmTertentu(listAktor &LA,listFilm &LF,string judul){
    adrAktor P =first(LA);
    adrFilm S;
    if (first(LA)==NULL){
        cout<<"List Kosong"<<endl;
    }else{
        adrChild R;
        while (next(P)!=first(LA)){
            adrChild Q=child(P);
            while (Q!=NULL){
                if (info(info(Q)).judul==judul){
                    deleteChild(P,Q,R);
                }
                Q=next(Q);
            }
            P=next(P);
        }
        adrChild Q=child(P);
        while (Q!=NULL){
            if (info(info(Q)).judul==judul){
                deleteChild(P,Q,R);
            }
            Q=next(Q);
        }
        deleteFilm(LF,judul,S);
    }
}
adrAktor cekAktor(listAktor LA,string nama,string asal,string tgl,int umur){
    adrAktor P = first(LA);
    if (first(LA)==NULL){
        return NULL;
    }else{
        while (next(P)!=first(LA)){
            if (info(P).nama==nama && info(P).asal==asal && info(P).tanggal==tgl && info(P).umur==umur){
                return P;
            }
            P=next(P);
        }
        if (info(P).nama==nama && info(P).asal==asal && info(P).tanggal==tgl && info(P).umur==umur){
            return P;
        }
        return NULL;
    }
}
adrFilm cekFilm(listFilm LF,string judul,string genre,string sutradara,string durasi,int tahun){
    adrFilm P=first(LF);
    if (first(LF)==NULL){
        return NULL;
    }else{
        while (P!=NULL){
            if (info(P).judul==judul && info(P).sutradara==sutradara && info(P).genre==genre &&
                info(P).durasi==durasi && info(P).tahun==tahun){
                return P;
            }
            P=next(P);
        }
        return NULL;
    }
}



//Tubes
void insertAktor(listAktor &LA,adrAktor P){
    //inser last => CDLL
    if (first(LA)==NULL && last(LA)==NULL){
        first(LA)=P;
        last(LA)=P;
        next(P)=first(LA);
        prev(P)=last(LA);
    }else{
        next(P)=first(LA);
        prev(P)=last(LA);
        next(last(LA))=P;
        last(LA)=P;
        prev(first(LA))=last(LA);
    }
}
void printAktor(listAktor LA,string nama){
    adrAktor P =searchAktor(LA,nama);
    if (P!=NULL){
        cout<<"Nama Aktor : "<<info(P).nama<<endl;
        cout<<"Asal Aktor : "<<info(P).asal<<endl;
        cout<<"Tanggal Lahir : "<<info(P).tanggal<<endl;
        cout<<"Umur : "<<info(P).umur<<endl;
    }else{
        cout<<"Nama aktor tidak ditemukan"<<endl;
    }
}
void deleteAktorTertentu(listAktor &LA,string nama){
    adrAktor P =searchAktor(LA,nama);
    if (P!=NULL){
        adrChild Q = child(P),R;
        if (Q==NULL){
            deleteAktor(LA,nama,P);
        }else{
            while (Q!=NULL){
                deleteChild(P,Q,R);
                Q=next(Q);
            }
            deleteAktor(LA,nama,P);
        }
    }else{
        cout<<"Aktor yang dimaksud tidak ada di list"<<endl;
    }
}
adrAktor searchAktor(listAktor LA,string nama){
    adrAktor found=NULL;
    adrAktor P=first(LA);
    if (first(LA)==NULL){
        return NULL;
    }else{
        while (next(P)!=first(LA) && found==NULL){
            if (info(P).nama==nama){
                found=P;
            }
            P=next(P);
        }
        if (info(P).nama==nama){
            found=P;
        }
    }
    return found;
}
void insertFilmOlehAktor(listAktor &LA,listFilm &LF){
    film newFilm;
    string nama;
    cout<<"Nama aktor : ";cin>>nama;
    cout<<endl;
    cout<<"judul : ";cin>>newFilm.judul;
    cout<<"genre : ";cin>>newFilm.genre;
    cout<<"sutradara : ";cin>>newFilm.sutradara;
    cout<<"Durasi : ";cin>>newFilm.durasi;
    cout<<"tahun tayang : ";cin>>newFilm.tahun;
    //asumsikan film yang akan ditambahkan belum ada di list
    adrFilm P=createElmFilm(newFilm);
    insertFilm(LF,P);

    adrAktor T=searchAktor(LA,nama);
    if (T!=NULL){
        adrFilm R=searchFilm(LF,newFilm.judul);
        if (R!=NULL){
            adrChild S=createElmChild(R);
            connecting(T,S);
            cout<<"Aktor "<<info(T).nama<<" berhasil direlasikan ke film "<<newFilm.judul<<endl;
        }
    }else{
        cout<<"Aktor tidak ditemukan"<<endl;
    }
}
void deleteFilmDariAktor(listAktor &LA,listFilm &LF,string nama,string judul){
    DeleteRelation(LA,LF,nama,judul);
}
void showFilmDariAktor(listAktor LA,string nama){
    adrAktor cari = searchAktor(LA,nama);
    if (cari!=NULL){
        adrChild Q=child(cari);
        while (Q!=NULL){
            cout<<"Judul : "<<info(info(Q)).judul<<endl;
            cout<<"Sutradara : "<<info(info(Q)).sutradara<<endl;
            cout<<"Genre : "<<info(info(Q)).genre<<endl;
            cout<<"Durasi : "<<info((info(Q))).durasi<<endl;
            cout<<"Tahun tayang : "<<info(info(Q)).tahun<<endl;
            cout<<endl;
            Q=next(Q);
        }
    }
}
adrChild searchFilmDariAktor(listAktor LA,listFilm LF,string nama,string judul){
    adrAktor P = searchAktor(LA,nama);
    if (P!=NULL){
        adrChild Q=child(P);
        while (Q!=NULL){
            if (info(info(Q)).judul==judul){
                return Q;
            }
            Q=next(Q);
        }
        return NULL;
    }else{
        cout<<"Aktor tidak ditemukan"<<endl;
    }
}
void AddRelation(listAktor LA,listFilm LF,string nama,string judul){
    adrAktor T = searchAktor(LA,nama);
    if(T != NULL){
        adrFilm R = searchFilm(LF,judul);
        if(R != NULL){
            if (searchFilmDariAktor(LA,LF,nama,judul)==NULL){
                adrChild S = createElmChild(R);
                connecting(T,S);
                cout<<"Aktor "<<nama<<" berhasil direlasikan ke film "<<judul<<endl;
            }else{
                cout<<"Aktor dan film tersebut sudah direlasikan"<<endl;
            }

        }else{
           cout << "film tidak ditemukan"<<endl;
        }
    }else{
        cout << "aktor tidak ditemukan"<<endl;
    }
}
void DeleteRelation(listAktor LA,listFilm LF,string nama,string judul){
    adrAktor T = searchAktor(LA,nama);
    if(T != NULL){
        adrChild Q=searchFilmDariAktor(LA,LF,nama,judul);
        if (Q!=NULL){
            adrChild S = child(T),R;
            while (S!=NULL){
                if (info(info(S)).judul==judul){
                    deleteChild(T,S,R);
                }
                S=next(S);
            }
        }else{
            cout<<"Judul film yang dimaksud tidak ditemukan di aktor"<<endl;
        }
    }else{
        cout<<"Aktor yang dimaksud tidak ditemukan"<<endl;
    }
}
void AktorPopuler(listAktor LA,listFilm LF){
    if(first(LA) != NULL){
        adrAktor N = last(LA);
        adrAktor populer;
        adrChild E;
        int jumlah;
        int temp = 0;
        while(N != first(LA)){
            E = child(N);
            jumlah = 0;
            while(E != NULL){
                jumlah += 1;
                E = next(E);
            }
            if(jumlah > temp){
                temp = jumlah;
                populer = N;
            }
            N = prev(N);
        }
        E = child(N);
        jumlah = 0;
        while(E != NULL){
            jumlah += 1;
            E = next(E);
        }
        if(jumlah > temp){
            temp = jumlah;
            populer = N;
        }
        printAktor(LA,info(populer).nama);
        cout<<endl;
        showFilmDariAktor(LA,info(populer).nama);
    }else{
        cout << "tidak ada aktor yang memiliki relasi"<<endl;
    }
}
void showAktorDariFilm(listAktor LA,string judul){
    adrAktor P =first(LA);
    if (first(LA)==NULL){
        cout<<"List Kosong"<<endl;
    }else{
        while (next(P)!=first(LA)){
            adrChild Q=child(P);
            while (Q!=NULL){
                if (info(info(Q)).judul==judul){
                    cout<<info(P).nama<<endl;
                }
                Q=next(Q);
            }
            P=next(P);
        }
        adrChild Q=child(P);
        while (Q!=NULL){
            if (info(info(Q)).judul==judul){
                cout<<info(P).nama<<endl;
            }
            Q=next(Q);
        }

    }
}
