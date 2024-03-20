#include "stock00.h"
#include <iostream>
int main() {
    // 如果你自己定义了构造函数，编译器默认会认为你知道如何初始化对象，因此不再生成默认构造函数。
    // {
    //     Stock cat; // 这里会报错，因为没有默认构造函数可用
    //     cat.acquire("Cats", 20, 1);
    //     cat.show();
    //     cat.buy(20, 1);
    //     cat.show();
    //     cat.sell(39, 2);
    //     cat.show();
    //     cat.buy(39, 1);
    //     cat.show();
    //     // 使用构造函数,多种方式
    //     Stock dog = {"Doge", 200, 200};
    //     dog.show();
    //     Stock sheep{"Sheep", 100, 80};
    //     sheep.show();
    //     Stock *tiger = new Stock("Tiger", 200, 300);
    //     tiger->show();
    //     delete tiger;

    //     // 创建一个临时对象,然后舍弃它,因此这里仍然会调用析构函数
    //     sheep = Stock("Sheep_new", 20, 300);
    //     sheep.show();

    //     // const 对象
    //     const Stock Elephant = Stock("Elephant", 200, 300);
    //     // Elephant.show();  这里会报错,因为 show()的行为不确定,它不能保证
    //     // show()方法不会对 Elephant 进行修改
    //     // 要想调用这个函数,必须得在函数原型中,定义中进行承诺
    //     Elephant.show();
    // };

    // 初始化数组对象
    {
        const int Num = 10;
        // 由于该声明只初始化了数组的部分元素，因此余下的7个元素将使用默认构造函数进行初始化,
        // 这种初始化依然会采用创建临时变量的
        Stock animals[Num] = {Stock("Monkey1", 20, 20),
                              Stock("Monkey2", 30, 20),
                              Stock()};
        // 初始化对象数组的方案是，首先使用默认构造函数创建数组元素，
        // 然后花括号中的构造函数将创建临时对象，然后将临时对象的内容复制到相应的元素中。
        // 这里会直接将 2 个临时对象析构掉

        // 但是,数组中的对象什么时候释放?答案是代码块运行完后,自动析构
        // 但是打印区的析构次数不对,只析构了 10 次,应该是 12次
        animals[0].show();
        animals[1].show();
    };
    return 0;
}