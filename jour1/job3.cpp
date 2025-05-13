#include <iostream> 
using namespace std;

int main (){
    int N;

    cout << "Entrez un nombre (0 pour quitter) : ";
    cin >> N; // On demande à l'utilisateur un nombre

    while (N != 0) {
        for (int i = 0; i < N; i++) {
            cout << "Hello World" << endl;
        }
    }
    return 0;
}