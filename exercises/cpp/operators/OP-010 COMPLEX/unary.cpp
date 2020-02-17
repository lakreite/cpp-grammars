#include<iostream>
#include"complex.hpp"
int main(){
    Complex a(1, 1);
    std::cout<<"a: "<<a<<std::endl;
    std::cout<<"--a: "<<(--a)<<std::endl;
    std::cout<<"a: "<<a<<std::endl;
    std::cout<<"a--: "<<(a--)<<std::endl;
    std::cout<<"a: "<<a<<std::endl;
    std::cout<<"++a: "<<(++a)<<std::endl;
    std::cout<<"a: "<<a<<std::endl;
    std::cout<<"a++: "<<(a++)<<std::endl;
    std::cout<<"a: "<<a<<std::endl;
    std::cout<<"+a: "<<(+a)<<std::endl;
    std::cout<<"a: "<<a<<std::endl;
    std::cout<<"-a: "<<(-a)<<std::endl;
    std::cout<<"a: "<<a<<std::endl;
    std::cout<<"double(a): "<<static_cast<double>(a)<<std::endl;
    Complex b(0, 1);
    std::cout<<"b: "<<b<<std::endl;
    std::cout<<"double(b): "<<static_cast<double>(b)<<std::endl;
    Complex c(1, 0);
    std::cout<<"c: "<<c<<std::endl;
    std::cout<<"double(c): "<<static_cast<double>(c)<<std::endl;

}
