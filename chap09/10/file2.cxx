#include <iostream>
using namespace std;
extern int cats;
extern int dogs;
extern int fleas;
int main() {
    cout << "cats from file1: cats=" << cats << endl;
    cout << "dogs from file1: dogs=" << dogs << endl;
    cout << "fleas from file1: fleas=" << fleas << endl;
    return 0;
}