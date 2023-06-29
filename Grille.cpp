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
        {
            for(int i=0; i<SIZE; i++)
            {
                for(int j=0; j<SIZE; j++)
                {
                    grille[i][j] = " ";
                }
            }
        }

        bool Jouer(int x, int y, string joueur)
        {
            if (grille[x][y] != " " || grille[x][y] != "X" || grille[x][y] != "O") // Si la case est déjà prise ou que le joueur n'est pas "X" ou "O"
                return false;

            grille[x][y] = joueur;
        }

        string Afficher()
        {
            string str = "+";

            for (int i = 0; i < SIZE; i++)
            {
                str += "---+";
            }

            str += "\n";

            for(int i=0; i<SIZE; i++)
            {
                str += "|";

                for (int j = 0; j<SIZE ; j++)
                {
                    str += " " + grille[i][j] + " |";
                }

                str += "\n+";

                for (int j = 0; j<SIZE; j++)
                {
                    str += "---+";
                }

                str += "\n";
            }

            return str;
        }
};

int main()
{
    Grille grille;


    out << grille.Afficher() << std::endl;

    return 0;
}

