#include "tabtenn0.h"
#include <iostream>
int main() {
    using std::cout;
    TableTennisPlayer player1("Chunk", "Blizzard", true);
    TableTennisPlayer player2("Tara", "Boomdea", false);

    player1.Name();
    if (player1.HasTable()) {
        cout << ": has a table.\n";
    } else {
        cout << ": have not a table.\n";
    }

    player2.Name();
    if (player2.HasTable()) {
        cout << ": has a table.\n";
    } else {
        cout << ": have not a table.\n";
    }

    TableTennisPlayer player3;
    player3.Name();
    if (player3.HasTable()) {
        cout << ": has a table.\n";
    } else {
        cout << ": have not a table.\n";
    }


    return 0;
}