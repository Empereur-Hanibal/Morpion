//
// Created by louis on 29/06/2023.
//

#ifndef MORPION_JOUEUR_H
#define MORPION_JOUEUR_H


#include <string>

using namespace std;

class Joueur{

private:
    string nom;
    string symbole;

public:
    Joueur(string nom, string symbole)
    {
        this->nom = nom;
        this->symbole = symbole;
    }

    string getNom()
    {
        return nom;
    }

    string getSymbole()
    {
        return symbole;
    }
};


#endif //MORPION_JOUEUR_H
