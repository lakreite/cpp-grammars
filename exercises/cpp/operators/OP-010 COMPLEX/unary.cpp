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

}
