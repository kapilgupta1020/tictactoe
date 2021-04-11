#include "game-manager.h"
#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter N to have board of NxN: "<<endl;
    cin >> N;

    GameManager gm(N);

    gm.start();
    gm.play();

    return 0;
}
