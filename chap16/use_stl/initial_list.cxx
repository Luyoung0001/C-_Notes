#include <iostream>

class Position {
  private:
    int x;
    int y;
    int z;

  public:
    // 构造函数
    Position(int xx = 0, int yy = 0, int zz = 0) : x(xx), y(yy), z(zz) {}

    // 显示位置信息
    void display() const {
        std::cout << "Position: (" << x << ", " << y << ", " << z << ")"
                  << std::endl;
    }
};

// 我们使用了初始化列表 {20, -3} 来创建一个Position对象A，
// 实际上这会调用Position(int, int,
// int)构造函数，并将x坐标设置为20，y坐标设置为-3， 而z坐标将使用默认值0
int main() {
    Position A = {20, -3}; // 使用 Position(int, int, int)
    A.display();

    return 0;
}
