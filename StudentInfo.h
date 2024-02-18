#ifndef __DHCP__
#define __DHCP__
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class StudentInfo
{
    private :
        vector<int> index_search;
        vector<StudentInfo> student;
        string grade;
        string numero;
        string nom;
        string mac;
        string mac_eth;
        string serial;
        string marque;
        string etat;
        string total;

    public :

    static int index;
    void set_index(int index);
    void set_numero(string numero);
    void set_nom(string nom);
    void set_mac(string mac);
    void set_mac_eth(string mac_eth);
    void set_serial(string serial);
    void set_marque(string marque);
    void set_etat(string etat);
    void set_total();
    int get_index();
    string get_numero();
    string get_nom();
    string get_mac();
    string get_mac_eth();
    string get_serial();
    string get_marque();
    string get_etat();
    string get_total();
    vector<StudentInfo> get_info();
    vector<int> search(string recherche);
   int nbrLineInscriptionL1();
   void supprimerStudent(int id);
};

#endif //DHCP
