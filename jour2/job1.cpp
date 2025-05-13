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
    
    public : 
        Pingouin(string n, double v_nage, double v_marche) :
            Aquatique(v_nage), Terrestre(v_marche), nom(n) {}

        void sePresenter() {
            cout << "Bonjour, je suis" << nom << "." << endl;
        }
};

int main() {
    Pingouin p("Pingo", 2.0, 0.6);
    p.sePresenter();
    p.nage();
    p.marche();
    return 0;
}