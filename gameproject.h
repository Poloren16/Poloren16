#ifndef GAMEPROJECT_H_INCLUDED
#define GAMEPROJECT_H_INCLUDED
#define infoG(G) G->infoG
#define nextGame(G) G->nextGame
#define firstGame(Lg) Lg.firstGame
#define lastGame(Lg) Lg.lastGame
#define infoD(D) D->infoD
#define nextDev(D) D->nextDev
#define firstDevelop(Ld) Ld.firstDevelop
#define Relasi(G) G->firstR //OKE KAK
#define peran(R) R->peran

using namespace std;
typedef struct elmGame *adr_game;
typedef struct elmDev *adr_develop;
typedef struct elmRelasi *adr_relasi;


struct projectGame{
    string kode, namaGame, genre, platform, deadline, server;
};

struct elmGame {
    projectGame infoG;
    adr_game nextGame,Prev;
    adr_relasi firstR;
};

struct listGame {
    adr_game firstGame;
    adr_game lastGame;
};


struct development {
    string nama, ID, peran;
};



struct elmDev {
    development infoD;
    adr_develop nextDev;
};



struct listDev {
    adr_develop firstDevelop;

};

struct elmRelasi { //relasi elemennya peran
    adr_develop peran;
    adr_relasi next;
};



//list game
void createGame(listGame &Lg); //a
adr_game newelm(projectGame data);
void inserLastGame(listGame &Lg, adr_game G); //a
void deleteFirstGame(listGame &Lg); //d
void showGame(listGame &Lg); //j
adr_game findgamebygenre(listGame &Lg, string genre); // g


//list karyawan
void createKaryawan(listDev &Ld); //b
adr_develop newelm(development data);
void insertFirstKaryawan(listDev &Ld, adr_develop D); //b
void deleteLastKaryawan(listDev &Ld, listGame &G); //e
void showKaryawan(listDev &Ld); //k
adr_develop findbyperan (listDev &Ld, string peran); //h


//list relasi
void deleteRelation(adr_game &G, adr_develop &D); //f
void showChildbyParentsGenre(adr_develop D, adr_game G, string genre); //l
void showAllData(listGame lg); //m
void showAllParentswithChild(listGame Lg, listDev Ld); //n
int countRelationAllGame(listGame Lg, string genre); //p
int countRelationSpecial(listGame Lg, listDev Ld, string peran); //q (note : r bisa digabung dengan q dengan catatan memakai if else)
int countNothingRelation(adr_develop D, adr_game G); //r
void editRelation(adr_develop D, adr_game G, adr_relasi R); //s
void showbyperan(listGame &Lg, string peran); //o

int selectMenu();

#endif // GAMEPROJECT_H_INCLUDED
