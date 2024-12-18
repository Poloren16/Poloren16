#include <iostream>
#include "gameproject.h"



void createGame(listGame &Lg){
    firstGame(Lg) = NULL;
    lastGame(Lg) = NULL;
//    adr_game G = new elmGame;
//    infoG(G).kode = kode;
//    infoG(G).namaGame = namaGame;
//    infoG(G).genre = genre;
//    infoG(G).platform = platform;
//    infoG(G).deadline = deadline;
//    infoG(G).server = server;
//    nextGame(G) = NULL;
//    return G;
}

adr_game newelm(projectGame data){
    adr_game g = new elmGame;
    infoG(g) = data;
    nextGame(g) = NULL;
    g->prevGame = NULL;
    firstR(g) = NULL;
    return g;
}

void inserLastGame(listGame &Lg, adr_game G) {
    if (firstGame(Lg) == NULL) {
        firstGame(Lg) = G;
        Lg.lastGame = G;
     } else {
        nextGame(Lg.lastGame) = G;
        G->prevGame = Lg.lastGame;
         nextGame(G) = NULL;
        Lg.lastGame = G;
    }
}

//void addRelation(adr_game G, adr_develop D) {
//    if (Relasi(G) == NULL) {
//        Relasi(G) = D;
//    } else {
//        nextDev(D) = Relasi(G);
//        Relasi(G) = D;
//    }
//    cout << "Relasi dibuat di game: " << infoG(G).namaGame << endl;
//    cout << "Karyawan: " << infoD(D).nama << endl;
//}

void deleteFirstGame(listGame &Lg) {
    adr_game G;
    adr_relasi R;

    if (firstGame(Lg) == NULL) {
        cout << "List game kosong" << endl;
        return;
    }

    G = firstGame(Lg);

    // Hapus semua relasi terkait game
    while (G->firstR != NULL) {
        R = G->firstR; // Ambil relasi pertama
        G->firstR = R->next; // Pindah ke relasi berikutnya
        delete R; // Hapus relasi
    }

    // Update elemen pertama game
    if (firstGame(Lg) == Lg.lastGame) {
        firstGame(Lg) = NULL;
        Lg.lastGame = NULL;
    } else {
        firstGame(Lg) = nextGame(firstGame(Lg));
    }

    delete G; // Hapus node game
    cout << "Game berhasil dihapus" << endl;
}

void showGame(listGame &Lg) {
    if (firstGame(Lg) == NULL) {
      cout << "List Game Kosong" << endl;
 }
    adr_game G = firstGame(Lg);
    while (G != NULL) {
        inserLastGame(Lg, G);
        cout << "Kode : " << infoG(G).kode << endl;
        cout << "Nama Game : " << infoG(G).namaGame << endl;
        cout << "Genre : " << infoG(G).genre << endl;
        cout << "Platform : " << infoG(G).platform << endl;
        cout << "Deadline : " << infoG(G).deadline << endl;
        cout << "Server : " << infoG(G).server << endl;
        cout <<" ============================================================" << endl;
        G = nextGame(G);
    }
}

adr_game findgamebygenre(listGame &Lg, string genre){
    adr_game P = firstGame(Lg);
    while(P != NULL){
        if(infoG(P).genre == genre){
            return P;
        }
        P = nextGame(P);
    }
    return NULL;
}

void createKaryawan(listDev &Ld){
    firstDevelop(Ld) = NULL;
}

adr_develop newelm(development data){
    adr_develop d = new elmDev;
    infoD(d) = data;
    nextDev(d) = NULL;
    return d;
}

void insertFirstKaryawan(listDev &Ld, adr_develop D){
    if (firstDevelop(Ld) == NULL) {
        firstDevelop(Ld) = D;
    } else {
        nextDev(D) = firstDevelop(Ld);
        firstDevelop(Ld) = D;
    }
}

void deleteLastKaryawan(listDev &Ld, listGame &Lg){
    //deleteLastKaryawanAndRelation(LChild,Lg)// {
    if (Ld.firstDevelop == NULL) {
        cout << "List Karyawan kosong" << endl;

    }
    if (nextDev(Ld.firstDevelop) == NULL) {

        adr_game G = firstGame(Lg);
        while (G != NULL) {
            if (Relasi(G) == Ld.firstDevelop) {
                Relasi(G) = NULL;
            } else {
                adr_develop D = Relasi(G);
                while (D != NULL) {
                    if (nextDev(D) == Ld.firstDevelop) {
                        nextDev(D) = NULL;
                        break;
                    }
                    D = nextDev(D);
                }
            }
            G = nextGame(G);
        }


        delete Ld.firstDevelop;
        Ld.firstDevelop = NULL;
        cout << "Elemen terakhir dari List Child beserta relasinya berhasil dihapus." << endl;
        return;
    }


    adr_develop P = Ld.firstDevelop;
    adr_develop R = NULL;

    while (nextDev(P) != NULL) {
        adr_develop D = P;
        adr_develop P = nextDev(P);
    }
    adr_game G = firstGame(Lg);

    while (G != NULL) {
        if (Relasi(G) == P) {
            Relasi(G) = NULL;
        } else {
            adr_develop temp = Relasi(G);
            while (temp != NULL) {
                if (nextDev(temp) == P) {
                    nextDev(temp) = NULL;
                    break;
                }
                temp = nextDev(temp);
            }
        }
        G = nextGame(G);
    }

    adr_develop Q = Ld.firstDevelop;
     adr_develop D = Relasi(G);
    if (Q != NULL) {
        nextDev(D) = NULL;
    } else {

        Ld.firstDevelop = NULL;
    }


    delete P;
    cout << "List Karyawan dan Relasi dihapus" << endl;
}


void showKaryawan(listDev &Ld) {
    if (firstDevelop(Ld) == NULL) {
        cout << "List Karyawan Kosong" << endl;
    }
    adr_develop D = firstDevelop(Ld);
    while (D != NULL) {
        cout << "Data Karyawan: "<<endl;

        cout << "Nama : " << infoD(D).nama << endl;
        cout << "ID : " << infoD(D).ID << endl;
        cout << "Peran : " << infoD(D).peran << endl;
         cout <<" ============================================================" << endl;
        D = nextDev(D);
    }
}



adr_develop findbyperan (listDev &Ld, string peran){
    adr_develop D = firstDevelop(Ld);
    while (D != NULL){
        if(infoD(D).peran == peran){
            return D;
        }
        D = nextDev(D);
    }
    return NULL;
}

void deleteRelation(adr_game &G, adr_develop &D) {
    if (G == NULL || D == NULL) {
        cout << "Tidak ada relasi yang dihapus" << endl;
    }

    if(Relasi(G) == D) {
        Relasi(G) = nextDev(D);
    } else {
        adr_develop temp = Relasi(G);
        while (temp != NULL && nextDev(temp) != D) {
            temp = nextDev(temp);
        }
        if (temp != NULL) {
            nextDev(temp) = nextDev(D);
        }
    }
    cout << "Game : " << infoG(G).namaGame << endl;
    cout << "Karyawan : " << D->infoD.nama << endl;
}



void showChildbyParentsGenre(listDev Ld, listGame Lg,string genre){
    adr_game p = firstGame(Lg);
    bool ketemu = false;

    while(p != NULL){
        if(infoG(p).genre == genre ) {
            ketemu = true;
            cout << "Kode Game: " << infoG(p).kode << endl;
            cout << "Proyek Game: " << infoG(p).namaGame << endl;
            cout << "Genre: " <<infoG(p).genre << endl;
            cout << "Platform: " <<infoG(p).platform << endl;
            cout << "Deadline: " << infoG(p).deadline << endl;
            cout << "Server: " << infoG(p).server << endl;
            cout << "Karyawan yang terlibat:" << endl;

            adr_relasi r = Relasi(p);
            if(r == NULL){
                cout << "Tidak ada karyawan yang bekerja pada proyek tersebut." << endl;
            }else {
                while (r !=NULL){
                    adr_develop d = peran(r);
                    cout <<"Nama: " << infoD(d).nama <<endl;
                    cout <<"Id: " << infoD(d).ID <<endl;
                    cout << "Peran: " << infoD(d).peran <<endl;
                }
            }
            cout << endl;
        }
        p = nextGame(p);
    }

    if(!ketemu){
         cout << "Tidak ada proyek game dengan genre \"" << genre << "\" yang ditemukan." << endl;
    }
}

void showAllData(listGame lg){
    adr_game g = firstGame(lg);

    if (g == NULL){
        cout << "Tidak ada proyek game yang tersedia." << endl;
        return;
    }

      cout << "Daftar Proyek Game dan Karyawan yang Terlibat:" << endl;
      cout << "-------------------------------------------------" << endl;

      while (g != NULL){
        cout << "Kode Proyek: " << infoG(g).kode << endl;
        cout << "Nama Game  : " << infoG(g).namaGame << endl;
        cout << "Genre      : " << infoG(g).genre << endl;
        cout << "Platform   : " << infoG(g).platform << endl;
        cout << "Deadline   : " << infoG(g).deadline << endl;
        cout << "Server     : " << infoG(g).server << endl;
          adr_relasi r = Relasi(r);
          if(r == NULL){
            cout << "  - Tidak ada karyawan yang terlibat." << endl;
          }else {
              cout << "Karyawan yang terlibat adalah: " << endl;
              while(r !=NULL){
                adr_develop d = peran(r);
                cout << " -Nama : "<< infoD(d).nama <<endl;
                cout << "  ID : "<< infoD(d).ID<<endl;
                cout << "  Peran : "<< infoD(d).peran <<endl;

                r = next(r);
              }
          }

          cout << "-------------------------------------------------" << endl;
          g = nextGame(g);
      }
}


void showbyperan(listGame &Lg, string peran){
    adr_game g = firstGame(Lg);
    bool ketemu = false;

    if(g == NULL){
        cout << "Tidak ada proyek game yang tersedia." << endl;
        return;
    }

    cout << "Daftar Proyek Game Berdasarkan Peran \"" << peran << "\":" << endl;
    cout << "-------------------------------------------------" << endl;

    while ( g != NULL){
        bool role = false;

        adr_relasi r = Relasi(g);
        while (r != NULL){
            adr_develop d = peran(r);

            if(infoD(d).peran == peran){
                role = true;
                break;
            }

            r = next(r);
        }
          if (role) {
            ketemu = true;
            cout << "Kode Proyek: " << infoG(g).kode << endl;
            cout << "Nama Game  : " << infoG(g).namaGame << endl;
            cout << "Genre      : " << infoG(g).genre << endl;
            cout << "Platform   : " << infoG(g).platform << endl;
            cout << "Deadline   : " << infoG(g).deadline << endl;
            cout << "Server     : " << infoG(g).server << endl;
            cout << "-------------------------------------------------" << endl;
        }
        g = nextGame(g);
    }

    if(!role){
        cout << "Tidak ada proyek game yang memiliki karyawan dengan peran \"" << peran << "\"." << endl;

    }
}

int countRelationAllGame(listGame Lg, string genre) {
    adr_game g = findgamebygenre(Lg, genre);
    if (g != NULL){
        int count = 0;
        adr_relasi r = Relasi(g);
        while (r != NULL){
            count++;
            r = next(r);
        }
        return count;
    }
    return -1;
}


int countRelationSpecial(listGame Lg, listDev Ld, string peran){
    adr_develop d = findbyperan(Ld,peran);

    if(d == NULL){
        return -1;
    }

    int count = 0;

    adr_game g = firstGame(Lg);
    while(g !=NULL){
        adr_relasi r = Relasi(g);
        while (r != NULL){
            if(peran(r) == d) {
                count ++;
                break;
            }
            r = next(r);
        }
        g = nextGame(g);
    }
    return count;
}


int selectMenu(){
    int pilih;
    cout <<"=============== Menu =============="<< endl;
    cout <<"|1.Tambahkan Data                      |"<< endl;
    cout <<"|2.Tampilan data                       |"<< endl;
    cout <<"|3.Hapus data                          |"<< endl;
    cout <<"|4.Edit Data                           |"<< endl;
    cout <<"|5.Count                               |"<< endl;
    cout <<"|7.Exit                                |"<< endl;
    cout <<"Masukkan pilihan anda 1/2/3/4/5/6/7: ";
        cin >> pilih;
       return pilih;
}



















