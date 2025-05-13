#include <iostream>
using namespace std;

int main() {
    int a, b, somme;

    //Demander deux sommes
    cout << "Entrez le premier nombre : ";
    cin >> a;

    cout << "Entrez le deuxième nombre : ";
    cin >> b;

    // Calcul de la somme
    somme = a + b;

    cout << "La somme est : " << somme << endl;

    return 0;
}