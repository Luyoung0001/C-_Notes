#include <iostream>
#include <string>
using namespace std;
int main() {
    char animal[] = "cat";
    char *ps = new char[strlen(animal) + 1];

    // 复制
    strcpy(ps, animal);
    cout << ps << endl;

    // 这种复制不是安全的复制,会带来:段错误,因为访问到了不应该访问到的内存
    char food[20] = {0};
    // strcpy(food, "hello, this is test!hello, this is test!hello, this is "
    //            "test!hello, this is test!12345");

    strncpy(food, "a panic basket filled with many goodies",19);

    cout << food << endl;

    return 0;
}