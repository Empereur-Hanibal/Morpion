//
// Created by louis on 29/06/2023.
//

#include "Controleur.h"
#include "../ihm/Grille.h"
#include "../metier/Joueur.h"

#include <iostream>
#include <string>

using namespace std;

class Controleur {

    private:
        Grille grille;
        Joueur joueur1;
        Joueur joueur2;

        string joueurActuel;

    public:
        Controleur()
        {
            grille = Grille();
            joueur1 = Joueur("Joueur 1", "X");
            joueur2 = Joueur("Joueur 2", "O");
            Demarrer();
        }



    private:
        void AfficherGrille()
        {
            cout << grille.Afficher() << endl;
        }

        void DemanderCoordonnees()
        {
            int x, y;

            cout << "Entrez les coordonnées de la case à jouer (x, y) : ";
            cin >> x >> y;

            if (x < 0 || x > 2 || y < 0 || y > 2)
            {
                cout << "Coordonnées invalides !" << endl;
                DemanderCoordonnees();
            }
            else
            {
                if (!grille.Jouer(x, y, joueur1.getSymbole()))
                {
                    cout << "La case est déjà prise !" << endl;
                    DemanderCoordonnees();
                }
            }
        }

        bool VerifierVictoire()
        {
            return grille.estGagnant() || grille.estPlein();
        }

        void Demarrer()
        {
            joueurActuel = joueur1.getNom();

            while(VerifierVictoire() == false)
            {
                AfficherGrille();
                DemanderCoordonnees();

                if (joueurActuel == joueur1.getNom())
                    joueurActuel = joueur2.getNom();
                else
                    joueurActuel = joueur1.getNom();
            }

            cout << "Partie terminée !" << endl;
            cout << "Le gagnant est " << joueurActuel << endl;
        }
};

int main()
{
    Controleur();
    return 0;
}
