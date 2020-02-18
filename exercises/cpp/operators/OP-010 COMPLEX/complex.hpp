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
    //void out() const{
    //    std::cout << r << '+' << i << 'i';
    //}
    //void outln() const{
    //    std::cout << r << '+' << i << 'i'<< std::endl;
    //}
    //a + b; Complex a, b;
    friend Complex operator+(const Complex &arg1, const Complex &arg2){
        return {arg1.re()+arg2.re(),arg1.im()+arg2.im()};
    }
    //+a; Complex a;
    Complex operator+(){
        return *this;
    }
    //-a; Complex a;
    Complex operator-(){
        return {-this->re(),-this->im()};
    }
    //a - b; Complex a,b;
    friend const Complex operator-(const Complex &arg1, const Complex &arg2){
        return {arg1.re()-arg2.re(),arg1.im()-arg2.im()};
    }
    //++a; Complex a;
    Complex& operator++(){
        r += 1;
        return *this;
    }
    //a++; Complex a; 
    const Complex operator++(int){
        Complex t(*this);
        r += 1;
        return t;
    }
    //--a; Complex a;
    Complex& operator--(){
        r -= 1;
        return *this;
    }
    //a--; Complex a;
    const Complex operator--(int){
        Complex t(*this);
        r -= 1;
        return t;
    }
    //a+=b; Complex a, b;
    const Complex operator+=(const Complex &arg2){
        this->r+=arg2.re();
        this->i+=arg2.im();
        return *this;
    }
    //a-=b; Complex a, b;
    const Complex operator-=(const Complex &arg2){
        this->r-=arg2.re();
        this->i-=arg2.im();
        return *this;
    }
    //a==b; Complex a, b;
    friend const bool operator==(const Complex &arg1, const Complex &arg2){
        return ((arg1.re()==arg2.re())&&(arg1.im()==arg2.im()))?true:false;
    }
    //a!=b; Complex a, b;
    friend const bool operator!=(const Complex &arg1, const Complex &arg2){
        return ((arg1.re()!=arg2.re())||(arg1.im()!=arg2.im()))?true:false;
    }
    //a + b; Complex a; double b;
    const Complex operator+(double x){
        return {this->r+x,this->i};
    }
    //a + b; double a; Complex b;
    friend const Complex operator+(double x, const Complex& arg){
        return {arg.re()+x,arg.im()};
    }
    //a - b; Complex a; double b;
    const Complex operator-(double x){
        return {this->r-x,this->i};
    }
    //a - b; double a; Complex b;
    friend const Complex operator-(double x, const Complex& arg){
        return{-arg.re()+x, -arg.im()};
    }
    //a * b; Complex a; double b;
    const Complex operator*(double x){
        return {this->r * x, this->i * x};
    }
    //a * b; double a; Complex b;
    friend const Complex operator*(double x, const Complex& arg){
        return{arg.re()*x,arg.im()*x};
    }
    //a = b; Complex a, b;
    Complex& operator=(const Complex& arg){
        this->r = arg.re();
        this->i = arg.im();
        return *this;
    }
    //out<<a; std::ostream out; Complex a;
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
    //double(Complex);
    explicit operator double() const{
        return this->r;
    }
    friend const Complex operator*(const Complex &arg1, const Complex &arg2){
        return {arg1.re()*arg2.re()-arg1.im()*arg2.im(),
            arg1.re()*arg2.im() + arg1.im()*arg2.re()};
    }
    friend const Complex operator/(const Complex &arg1,const Complex &arg2){
        double temp = arg2.im();
        temp *= temp;
        temp += arg2.re()*arg2.re();
        //if (temp==0)
        //    return {};
        return {(arg1.re()*arg2.re()+arg1.im()*arg2.im())/temp, (arg2.re()*arg1.im() - arg1.re()*arg2.im())/temp};
    }
    friend const Complex operator/(const Complex &arg, const double x){
        //if (x == 0)
        //    return {};
        return {arg.re()/x,arg.im()/x};
    }
    friend const Complex operator/(const double x, const Complex &arg){
        //if ((arg.im()==0)&&(arg.re()==0))
        //    return {};
        return Complex(x,0) / arg;
    } 
};
