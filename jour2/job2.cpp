#include <iostream>
#include <string>
using namespace std;

class Aquatique {
    protected:
        double vitesse_nage;
    
    public:
        Aquatique (double v = 1.0) {
            vitesse_nage = v;
        }

        virtual void nage() {
            cout << "Je nage à " << vitesse_nage << "m/s." << endl;
        }
};

class Terrestre {
    protected : 
        double vitesse_marche;

    public :
        Terrestre(double v = 0.5) {
            vitesse_marche = v;
        }

        virtual void marche() {
            cout << "Je marche à " << vitesse_marche << "m/s." << endl;
        }
};

class Pingouin : public Aquatique, public Terrestre {
    private:
        string nom;
        double vitesse_glisse;
    
    public : 
        //Constructeur normal
        Pingouin(string n, double v_nage, double v_marche, double v_glisse) :
            Aquatique(v_nage), Terrestre(v_marche), nom(n), vitesse_glisse(v_glisse) {}

        //Constructeur de copie
        Pingouin(const Pingouin& autre) :
            Aquatique(autre.vitesse_nage),
            Terrestre(autre.vitesse_marche),
            nom(autre.nom),
            vitesse_glisse(autre.vitesse_glisse) {}
        
        void sePresenter() {
            cout << "Bonjour, je suis" << nom << "." << endl;
        }

        void glisse() {
            cout << "Je glisse à " << "m/s." << endl;
        }
        
        void setVitesseGlisse(double v) {
            vitesse_glisse = v;
        }

        double getVitesseGlisse() {
            return vitesse_glisse;
        }
};

int main() {
    Pingouin p1("Pingo", 2.0, 0.6, 4.0);
    p1.sePresenter();
    p1.nage();
    p1.marche();
    
    cout << "On crée une copie du Pingouin...\n";
    Pingouin p2 = p1; // Appel au constructeur de copie
    p2.sePresenter();
    p2.glisse();

    return 0;
}