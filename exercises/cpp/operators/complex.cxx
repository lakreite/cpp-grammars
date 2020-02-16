//KUZNETSOV MAXIM 207 group
#include<iostream>
class Complex{
    double r;
    double i;
public:    
    Complex(){
        r = i = 0.;
    }
    Complex(const double &re, const double& im): r(re), i(im){}
    double re() const{
        return r;
    }
    double im() const{
        return i;
    }
    void out() const{
        std::cout << r << '+' << i << 'i';
    }
    void outln() const{
        std::cout << r << '+' << i << 'i'<< std::endl;
    }
    Complex operator+(const Complex &arg2){
        Complex t(this->re() + arg2.re(), this->im() + arg2.im());
        return t;
    }
    Complex operator+(){//const Complex& arg){
        return *this;
    }
    Complex operator-(){//const Complex& arg){
        return {-this->re(),-this->im()};//Complex(-arg.re(), -arg.im());
    }
    Complex operator-(const Complex &arg2){
        return Complex(this->re() - arg2.re(), this->im() - arg2.im());
    }
    Complex& operator++(){
        r += 1;
        return *this;
    }
    Complex operator++(int){
        Complex t(*this);
        r += 1;
        return t;
    }
    Complex& operator--(){
        r -= 1;
        return *this;
    }
    Complex operator--(int){
        Complex t(*this);
        r -= 1;
        return t;
    }
    const Complex operator+=(const Complex &arg2){
        this->r+=arg2.re();
        this->i+=arg2.im();
        return *this;
    }
    const Complex operator-=(const Complex &arg2){
        this->r-=arg2.re();
        this->i-=arg2.im();
        return *this;
    }
    const bool operator==(const Complex &arg2){
        return ((this->re()==arg2.re())&&(this->im()==arg2.im()))?true:false;
    }
    const bool operator!=(const Complex &arg2){
        return ((this->re()!=arg2.re())||(this->im()!=arg2.im()))?true:false;
    }
    const Complex operator-(double x){
        return {this->r-x,this->i};
    }
    const Complex operator*(double x){
        return {this->r * x, this->i * x};
    }
    Complex& operator=(const Complex& arg){
        this->r = arg.re();
        this->i = arg.im();
        return *this;
    }
};
int main(){
    Complex a(1,1),b(0,0),c(0,1);
    std::cout<<"//a == 1 + i, b == 0, c = i"<<std::endl;
    a = b = c;
    std::cout<<"a = b = c;// a == ";
    a.outln();
    std::cout<<"b == ";
    b.outln();
    std::cout<<"c == ";
    c.outln();
    std::cout<<"//a = 1 + i, b = 0"<<std::endl;
    a = {1, 1},b = {0,0};
    std::cout<<"a+=b;// a == ";
    a+=b;
    a.outln();
    a+=c;
    std::cout<<"a+=c;// a == ";
    a.outln();
    a-=c;
    std::cout<<"a-=c;// a == ";
    a.outln();
    std::cout<<"a = a+ = b; // a == ";
    a = a+= b;
    a.outln();
    a = a -= c;
    std::cout<<"a = a -= c; // a == ";
    a.outln();
    a = a + c;
    std::cout<<"a = a + c; // a == ";
    a.outln();
    std::cout<< "a + b + c == ";
    (a+b+c).outln();
    std::cout<< "a + b + c - 1 == ";
    (a + b + c - 1).outln();
    std::cout<<"a == ";
    a.outln();
    std::cout<<"(before side-effect) ++a == ";
    (++a).outln();
    std::cout<<"(after s-e) a == ";
    a.outln();
    std::cout<<"(before side-effect) a++ == ";
    (a++).outln();
    std::cout<<"(after s-e) a == ";
    a.outln();
    std::cout<<"(bef. s-e) --a == ";
    (--a).outln();
    std::cout<<"(a. s-e) a == ";
    a.outln();
    std::cout<<"(bef. s-e) a-- == ";
    (a--).outln();
    std::cout<<"(a.s-e) a == ";
    a.outln();
    std::cout<<"a == a?: " << (a == a) << std::endl;
    std::cout<<"a == b?: " << (a == b) << std::endl;
    std::cout<<"a != a?: " << (a != a) << std::endl;
    std::cout<<"a != b?: " << (a != b) << std::endl;
    std::cout<<"+a == ";
    (+a).outln();
    std::cout<<"-a == ";
    (-a).outln();
    b = {2,3};
    std::cout<< "b == ";
    b.outln();
    std::cout<<"a - b == ";
    (a-b).outln();
    std::cout<<"a++ + --b == ";
    (a++ + --b).outln();
}
