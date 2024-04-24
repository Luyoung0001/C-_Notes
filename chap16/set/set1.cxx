#include <iostream>
#include <iterator>
#include <set>
using namespace std;
int main() {
    const int N = 6;
    string s1[N] = {"buffoon", "thinkers", "for", "heavy", "can", "for"};
    set<string> A(s1, s1 + N);
    ostream_iterator<string, char> out(cout, " ");
    copy(A.begin(), A.end(), out);
    return 0;
}
