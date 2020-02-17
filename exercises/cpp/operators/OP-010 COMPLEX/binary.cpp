#include<iostream>
#include"complex.hpp"
using std::cout;
using std::endl;
int main(){
    Complex a(1,1), b(2, 2), c(4, 4);
    cout<<"a: "<<a<<" b: "<<b<<" c: "<<c<<endl;
    cout<<"b = c: "<<(b=c)<<endl;
    cout<<"b: "<<b<<" c: "<<c<<endl;
    cout<<"(a=b)=c: "<<((a=b)=c)<<endl;
    cout<<"a: "<<a<<endl;
    a = {1,1};
    b = {2,2};
    c = {3,3};
    cout<<"a: "<<a<<" b: "<<b<<" c: "<<c<<endl;
    cout<<"a=b=c"<<(a=b=c)<<endl;
    cout<<"a: "<<a<<" b: "<<b<<" c: "<<c<<endl;
    cout<<"a==b: "<<(a==b)<<endl;
    cout<<"a!=b: "<<(a!=b)<<endl;
    a = {1,1};
    b = {1,-1};
    cout<<"a: "<<a<<" b: "<<b<<endl;
    cout<<"a==b: "<<(a==b)<<endl;
    cout<<"a!=b: "<<(a!=b)<<endl;
    cout<<"2 * a: "<<(2 * a)<<endl;
    cout<<"a * 2: "<<(a * 2)<<endl;
    cout<<"a + 8: "<<(a + 8)<<endl;
    cout<<"8 + a: "<<(8 + a)<<endl;
    cout<<"a += 8: "<<(a+=8)<<endl;
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;
    cout<<"a += b: "<<(a+=b)<<endl;
    cout<<"a: "<<a<<endl;
    cout<<"c: "<<c<<endl;
    cout<<"a = b+= c: "<<(a=b+=c)<<endl;
    cout<<"a: "<<a<<" b: "<<b<<" c: "<<c<<endl;
    a = {1, 1};
    cout<<"a: "<<a<<endl;
    cout<<"a = b-= c: "<<(a=b-=c)<<endl;
    cout<<"a: "<<a<<" b: "<<b<<" c: "<<c<<endl;
}
