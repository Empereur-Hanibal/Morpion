//
// Created by louis on 28/06/2023.
//

#ifndef MORPION_GRILLE_H
#define MORPION_GRILLE_H

//
// Created by louis on 28/06/2023.
//

#include "Grille.h"

#include <iostream>
#include <string>

using namespace std;

class Grille {

public:
    static constexpr size_t SIZE = 3;

private:
    string grille[SIZE][SIZE];

public:
    Grille()

    bool Jouer(int x, int y, string joueur)

    string Afficher()

    bool EstPleine()

    bool EstGagnante()



};

#endif //MORPION_GRILLE_H
