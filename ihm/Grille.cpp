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

        bool EstPleine()
        {
            for(int i=0; i<SIZE; i++)
            {
                for(int j=0; j<SIZE; j++)
                {
                    if (grille[i][j] == " ")
                        return false;
                }
            }

            return true;
        }

        bool EstGagnante()
        {
            for(int i=0; i<SIZE; i++)
            {
                if (grille[i][0] == grille[i][1] && grille[i][1] == grille[i][2] && grille[i][0] != " ")
                    return true;
            }

            for(int i=0; i<SIZE; i++)
            {
                if (grille[0][i] == grille[1][i] && grille[1][i] == grille[2][i] && grille[0][i] != " ")
                    return true;
            }

            if (grille[0][0] == grille[1][1] && grille[1][1] == grille[2][2] && grille[0][0] != " ")
                return true;

            if (grille[0][2] == grille[1][1] && grille[1][1] == grille[2][0] && grille[0][2] != " ")
                return true;

            return false;
        }


};

int main()
{
    Grille grille;


    cout << grille.Afficher() << std::endl;

    return 0;
}

