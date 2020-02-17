//KUZNETSOV MAXIM 207 group
#include<iostream>
class Complex{
    double r;
    double i;
public:    
    Complex(){
        r = i = 0.;
    }
    Complex(const double &re): r(re){}
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
        Complex t(this->re() + arg2.re(), this->im() + 			arg2.im());
        return t;
    }
    Complex operator+(){
        return *this;
    }
    Complex operator-(){
        return {-this->re(),-this->im()};
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
    const Complex operator+(double x){
        return {this->r+x,this->i};
    }
    friend const Complex operator+(double x, const Complex& arg){
        return {arg.re()+x,arg.im()};
    }
    const Complex operator-(double x){
        return {this->r-x,this->i};
    }
    const Complex operator*(double x){
        return {this->r * x, this->i * x};
    }
    friend const Complex operator*(double x, const Complex& arg){
        return{arg.re()*x,arg.im()*x};
    }
    Complex& operator=(const Complex& arg){
        this->r = arg.re();
        this->i = arg.im();
        return *this;
    }
    friend std::ostream& operator<<(std::ostream &out, const Complex &arg){
        if (arg.re() != 0)
            if (arg.im() > 0)
                out << arg.re() << '+' << arg.im() << 'i';
            else if (arg.im() < 0)
                out << arg.re() << arg.im() << 'i';
            else
                out << arg.re();
        else if (arg.im() != 0)
            out <<arg.im() << 'i';
        else
            out << '0';
        return out;
    }
};
