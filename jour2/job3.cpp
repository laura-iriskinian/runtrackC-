#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

// Classe Aquatique
class Aquatique {
protected:
    double vitesse_nage;

public:
    Aquatique(double v = 1.0) : vitesse_nage(v) {}

    virtual void nage() {
        cout << "Je nage à " << vitesse_nage << " m/s." << endl;
    }
};

// Classe Terrestre
class Terrestre {
protected:
    double vitesse_marche;

public:
    Terrestre(double v = 0.5) : vitesse_marche(v) {}

    virtual void marche() {
        cout << "Je marche à " << vitesse_marche << " m/s." << endl;
    }
};

// Classe Pingouin
class Pingouin : public Aquatique, public Terrestre, public enable_shared_from_this<Pingouin> {
private:
    string nom;
    double vitesse_glisse;

public:
    // Vector statique pour stocker tous les pingouins
    static vector<shared_ptr<Pingouin>> colony;

    // Constructeur normal
    Pingouin(string n, double v_nage, double v_marche, double v_glisse)
        : Aquatique(v_nage), Terrestre(v_marche), nom(n), vitesse_glisse(v_glisse) {
        cout << nom << " est né." << endl;
    }

    // Constructeur de copie
    Pingouin(const Pingouin& autre)
        : Aquatique(autre.vitesse_nage),
          Terrestre(autre.vitesse_marche),
          nom(autre.nom),
          vitesse_glisse(autre.vitesse_glisse) {
        cout << nom << " a été copié." << endl;
    }

    // Destructeur
    ~Pingouin() {
        cout << nom << " est détruit." << endl;
        auto it = remove_if(colony.begin(), colony.end(),
            [this](const shared_ptr<Pingouin>& p) {
                return p.get() == this;
            });
        colony.erase(it, colony.end());
    }

    // Ajouter ce pingouin à la colonie
    void rejoindreColonie() {
        colony.push_back(shared_from_this());
    }

    // Méthodes
    void sePresenter() {
        cout << "Bonjour, je suis " << nom << "." << endl;
    }

    void glisse() {
        cout << "Je glisse à " << vitesse_glisse << " m/s." << endl;
    }

    void setVitesseGlisse(double v) {
        vitesse_glisse = v;
    }

    double getVitesseGlisse() {
        return vitesse_glisse;
    }
};

// Initialisation du vector statique
vector<shared_ptr<Pingouin>> Pingouin::colony;

int main() {
    {
        // Création des pingouins
        auto p1 = make_shared<Pingouin>("Pingo", 2.5, 0.8, 4.2);
        auto p2 = make_shared<Pingouin>("Pinga", 2.0, 0.6, 3.8);

        p1->rejoindreColonie();
        p2->rejoindreColonie();

        // Présentation
        for (auto& p : Pingouin::colony) {
            p->sePresenter();
            p->nage();
            p->marche();
            p->glisse();
            cout << "Vitesse de glisse : " << p->getVitesseGlisse() << " m/s\n\n";
        }
    }  // Fin du bloc → les pingouins sont détruits ici

    cout << "Tous les pingouins ont quitté la colonie." << endl;

    return 0;
}
