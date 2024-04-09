#ifndef ARRAYTP_H_
#define ARRAYTP_H_
#include <cstdlib>
#include <iostream>
template <class Type, int n>
class ArrayTP {
    private:
        Type arr[n];
    public:
        ArrayTP(){};
        explicit ArrayTP(const Type & v); // 初始化函数,将值全部初始化为 v

        // 这里重写,主要就是为了处理边界问题
        virtual Type & operator[](int i);
        virtual Type operator[](int i) const;

};

template <class Type, int n>
ArrayTP<Type, n>::ArrayTP(const Type & v){
    for(int i = 0; i < n; i++){
        arr[i] = v;
    }
}

template <class Type, int n>
Type& ArrayTP<Type, n>::operator[](int i){
    if(i < 0 || i >= n){
        std::cerr << "Error in array limits: " << i << " is out of range.\n";
        std::exit(EXIT_FAILURE);
    }
    return arr[i];
}

template <class Type, int n>
Type ArrayTP<Type, n>::operator[](int i)const{
    if(i < 0 || i >= n){
        std::cerr << "Error in array limits: " << i << " is out of range.\n";
        std::exit(EXIT_FAILURE);
    }
    return arr[i];

}

#endif