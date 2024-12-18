#include <iostream>
#include <string>
#include "gameproject.h"

using namespace std;

int main()
{
    listGame Lg;
    listDev Ld;
    adr_game G;
    adr_develop D;
    projectGame game;
    development dev;
    string peran;
//    adr_game game;
//    adr_develop karyawan;
    int i;
    int n;
    int pilih;
    bool status;
    string kode, nama ,genre, platform, deadline, server;
    createGame(Lg);
    createKaryawan(Ld);


    cout <<"|---------------Data Project Game---------------|"<< endl;
    cout <<"|             Relation with Developer           |"<< endl;
    cout <<"|                     by:                       |"<< endl;
    cout <<"|Florensius Hutagalung & Anom Ayu Radhaswasti   |"<< endl;
    pilih = selectMenu();
    while (pilih != 0) {
        switch(pilih){
            //Ini maunya 4 data udah langsung ada, jadi tinggal lanjutin 4 data tersebut
            case 1:
                cout << "|-------------------- TAMBAHKAN DATA --------------------|" << endl;
                cout << "|1.Tambah Data Game                                      |" << endl;
                cout << "|2.Tambah Data Karyawan                                  |" << endl;
                cout << "|3.Exit                                                  |" << endl;
                cout << "|--------------------------------------------------------|" << endl;
                cout << "Masukan pilihan: ";
                cin >> i;
                    if(i == 1){
                        cout << "|--------------------------------------------------------|" << endl;
                        for(int z = 0; z<=6;z++){
                        cout << "| Kode : ", z ;
                        cin >> game.kode ;
                        cout << "| Nama Game : ", z ;
                        cin >> game.namaGame ;
                        cout << "| Genre  : ", z ;
                        cin >> game.genre  ;
                        cout << "| Platform : ", z ;
                        cin >> game.platform ;
                        cout << "| Deadline: ", z ;
                        cin >> game.deadline ;
                        cout << "| Server  : ", z ;
                        cin >> game.server  ;
                        G =  newelm(game);
                        inserLastGame(Lg, G);
                        }
                        cout << "|--------------------------------------------------------|" << endl;
                        cout << "|                 Data Berhasil Di Tambahkan             |" << endl;
                    }else if( i == 2){
                        cout << "|--------------------------------------------------------|" << endl;
                        for(int z = 0; z<=6;z++){
                        cout << "| Nama karyawan : ", z ;
                        cin >> dev.nama ;
                        cout << "| ID karyawan : ", z ;
                        cin >> dev.ID ;
                        cout << "| Peran karyawan  : ", z ;
                        cin >> dev.peran ;
                        D =  newelm(dev);
                        insertFirstKaryawan(Ld,D);
                        }
                        cout << "|--------------------------------------------------------|" << endl;
                        cout << "|                 Data Berhasil Di Tambahkan             |" << endl;
                    }
                break;

            case 2:
                cout << "|---------------------- TAMPILKAN DATA -------------------------------|" << endl;
                cout << "|1.Tampilkan Data Game                                                |"<< endl;
                cout << "|2.Tampilkan Data Karyawan                                            |"<< endl;
                cout << "|3.Tampilkan Data Karyawan dengan proyeknya berdasarkan relasi genre  |" << endl;
                cout << "|4.Tampilkan Data Karyawan yang berelasi dengan Proyek                |"<< endl;
                cout << "|5.Tampilkan Data Proyek yang berelasi dengan Karyawann               |" << endl;
                cout << "|6.Tampilkan Data Proyek dengan Karyawan berdasarkan relasi peran     |" << endl;
                cout << "|7.Exit" << endl;
                cout << "|--------------------------------------------------------------------|" << endl;
                cout << "Masukan pilihan: ";
                cin >> i;
                if(i == 1){
                cout << "|-------------------- Tampilkan Data Game--------------------------------|" << endl;
                    showGame(Lg);
                cout << "|--------------------------------------------------------------------|" << endl;

                }else if (i == 2){
                cout << "|-------------------- Tampilkan Data Karyawan   -----------------------------|" << endl;
                    showKaryawan(Ld);
                cout << "|--------------------------------------------------------------------|" << endl;
                }else if(i == 3) {
                cout << "|-------------------- Tampilkan Data Karyawan dengan proyeknya berdasarkan relasi genre----------------|" << endl;
                    showChildbyParentsGenre(D,G,genre);
                cout << "|--------------------------------------------------------------------------------------------------|" << endl;
                }else if(i == 4){
                cout << "|-------------------- Tampilkan Data Karyawan yang berelasi dengan Proyek ----------------|" << endl;
                    showAllData(Lg);
                cout << "|-------------------------------------------------------------------------------------|" << endl;
                }else if(i==5){
                cout << "|-------------------- Tampilkan Data Proyek yang berelasi dengan Karyawann ----------------|"<<endl;
                    showAllParentswithChild(Lg,Ld);
                cout << "|--------------------------------------------------------------------------------------|" << endl;
                }else if(i == 6){
                cout << "|-------------------- Tampilkan Data Proyek dengan Karyawan berdasarkan relasi peran ----------------|" <<endl;
                    showbyperan(Lg,peran);
                cout << "|-------------------------------------------------------------------------------------|" << endl;
                }
                break;
            case 3:
                cout << "|---------------------- HAPUS DATA ----------------------|" << endl;
                cout << "|1.Hapus Game                                            |" << endl;
                cout << "|2.Hapus Karyawan                                        |" << endl;
                cout << "|3.Hapus Relasi                                          |" << endl;
                cout << "|4.Exit                                                  |" << endl;
                cout << "|--------------------------------------------------------|" << endl;
                cout << "Masukan pilihan: ";
                cin >> i;
                if(i == 1){
                    cout << "|--------------------- Hapus  Data Game ---------------------------------|" << endl;
                    deleteFirstGame(Lg);
                    cout << "|--------------------------------------------------------------------|" << endl;
                }else if(i == 2){
                    cout << "|-------------------- Hapus Data Karyawan--------------------------------|" << endl;
                    deleteLastKaryawan(Ld, Lg);
                    cout << "|--------------------------------------------------------------------|" << endl;
                }else if(i==3){
                    cout << "|-------------------- Hapus Data Relasi ---------------------------------|" << endl;
                    deleteRelation(G,D);
                    cout << "|--------------------------------------------------------------------|" << endl;
                }
                break;
            case 4:
                //edit
                break;
            case 5:
                cout << "|---------------------- COUNT DATA ----------------------|" << endl;
                cout << "|1.Count dari element project game                       |" << endl;
                cout << "|2.Count dari element karyawan                           |" << endl;
                cout << "|3.Count yang tidak memiliki relasi                      |" << endl;
                cout << "|4.Exit                                                  |" << endl;
                cout << "|--------------------------------------------------------|" << endl;
                cout << "Masukan pilihan: ";
                cin >> i;
                    if(i == 1){
                        cout << "|------------------Count data game------------------------|" << endl;
                        cout << "Count dari element project adalah: ";
                        countRelationAllGame(Lg,genre);
                        cout << "|---------------------------------------------------------|" << endl;
                    }else if(i==2){
                        cout << "|------------------Count data karyawan --------------------------|" << endl;
                        cout << "Count dari element karyawan adalah: ";
                        countRelationSpecial(Lg,Ld, peran);
                        cout << "|-----------------------------------------------------------------|" << endl;
                    }else if(i==3){
                        cout << "|------------------Count data yang tidak memiliki relasi  ------------------------|" << endl;
                        cout << "Count dari element project adalah: ";
                        countNothingRelation(D,G);
                        cout << "|---------------------------------------------------------------------------------|" << endl;
                    }
                    break;
        }
    }
}
