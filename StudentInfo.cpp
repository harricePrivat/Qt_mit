#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "StudentInfo.h"
#include <string.h>
using namespace std;

    int StudentInfo::index=1;
        //fonction setters
    void StudentInfo::set_index(int index){
        this->index=index;
    }
        void StudentInfo::set_numero(string numero)
        {
            this->numero = numero;
        }
        void StudentInfo::set_nom(string nom)
        {
            this->nom = nom;
        }
        void StudentInfo::set_mac(string mac)
        {
            this->mac = mac;
        }
        void StudentInfo::set_mac_eth(string mac_eth)
        {
            this->mac_eth = mac_eth;
        }
        void StudentInfo::set_serial(string serial)
        {
            this->serial = serial;
        }
        void StudentInfo::set_marque(string marque)
        {
            this->marque = marque;
        }
        void StudentInfo::set_etat(string etat)
        {
            this->etat = etat;
        }
        void StudentInfo::set_total()
        {
            total = grade + " " + numero + " " + nom + " " + mac + " " + mac_eth + " " + serial + " " + marque + " " + etat;
        }
        //fonction getters
        int StudentInfo::get_index(){
            return this->index;
        }
        string StudentInfo::get_numero()
        {
            return this->numero;
        }
        string StudentInfo::get_nom()
        {
            return this->nom;
        }
        string StudentInfo::get_mac()
        {
            return this->mac;
        }
        string StudentInfo::get_mac_eth()
        {
            return this->mac_eth;
        }
        string StudentInfo::get_serial()
        {
            return this->serial;
        }
        string StudentInfo::get_marque()
        {
            return this->marque;
        }
        string StudentInfo::get_etat()
        {
            return this->etat;
        }
        string StudentInfo::get_total()
        {
            return this->total;
        }

        //methode d'ajout et de recuperation d'information
        vector<StudentInfo> StudentInfo::get_info()
        {
            int index = 0;
            ifstream file{"/home/brice/dhcpMIT/inscription_L1.csv"};
            string numero,nom ,mac, mac_eth, serial, marque, etat;
            string test; 
            istringstream flux(test);


            if(file.is_open())
            {
                while(getline(file,test))
                {   
                    student.push_back(StudentInfo());
                    istringstream flux(test);
                    //grade
                    student[index].grade = "L1";
                    //numero
                    getline(flux,numero,'\t');
                    student[index].set_numero(numero);
                    //nom
                    getline(flux,nom,'\t');
                    student[index].set_nom(nom);
                    //mac
                    getline(flux,mac,'\t');
                    student[index].set_mac(mac);
                    //mac_eth
                    getline(flux,mac_eth,'\t');
                    student[index].set_mac_eth(mac_eth);
                    //serial
                    getline(flux,serial,'\t');
                    student[index].set_serial(serial);
                    //marque
                    getline(flux,marque,'\t');
                    student[index].set_marque(marque);
                    //etat
                    getline(flux,etat,'\t');
                    if(etat.empty())
                    {
                        etat = "aucun problème";
                    }
                    student[index].set_etat(etat);
                    student[index].set_total();
                    flux.clear();
                    test.erase();
                    index++;
                }

                file.close();   
            }
            return this->student;
        }


        //methode pour la recherche
        vector<int> StudentInfo::search(string recherche)
        {
            for(int i = 0; i < student.size(); i++)
            {
                string t = student[i].get_total();
                if(t.find(recherche) !=string::npos)
                {
                index_search.push_back(i);
                }
            }
            return this->index_search;
        }

        int StudentInfo::nbrLineInscriptionL1(){
            int i=0;
            string line;
            std::ifstream file("/home/brice/dhcpMIT/inscription_L1.csv");
                if(file.is_open()){
                    while(std::getline(file,line))
                        i++;
                }
                file.close();
                return i;
        }

        void StudentInfo::supprimerStudent(int id){
            ifstream old("/home/brice/dhcpMIT/inscription_L1.csv");
            ofstream nouveau("/home/brice/dhcpMIT/tmpL1.csv");
            if(old.is_open() && nouveau.is_open()){
                string line;
                int position;
                while(std::getline(old,line)){
                  position=line.find(',');
                       string token=line.substr(0,position);
                       if(id!=stoi(token)){
                           nouveau << line << endl;
                       }
                }
            }
            std::remove("/home/brice/dhcpMIT/inscription_L1.csv");
            std::rename("/home/brice/dhcpMIT/tmpL1.csv","/home/brice/dhcpMIT/inscription_L1.csv");
            old.close();
            nouveau.close();
        }

