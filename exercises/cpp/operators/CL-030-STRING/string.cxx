//KUZNETSOV MAXIM 207
#include<iostream>
#include<cassert>
class String{
    char * value; //value don't include last zero
    int len; //length
public:    
    String(){
        value = nullptr;
        len = 0; 
    }
    String(const char * s){
        if ((s == nullptr) || (s[0] == 0)){
            value = nullptr;
            len = 0;
            return;
        }
        int k = 0;
        for (; s[k] != 0; ++k){}
        len = k;
        value = new char[len];
        for (int i = 0; s[i] != 0; ++i){
            value[i] = s[i];
        }
    }
    std::size_t length() const{
        return len;
    }
    char &at(std::size_t index){
        return value[index - 1]; // numeration since one
    }
    void append(const char *s){
        if ((s == nullptr) || (s[0] == 0)){
            return;
        }
        int size_s = 0;
        for (;s[size_s] != 0; ++size_s){}
        char * new_value = new char[len + size_s];
        for (int i = 0; i < len; ++i)
            new_value[i] = value[i];
        for (int i = len; i < len + size_s; ++i)
            new_value[i] = s[i - len];
        delete[] value;
        value = new_value;
        len += size_s;
    }
    const char *raw(){
        return value;
    }
    void out(){
        char * temp = new char[len + 1];
        for (int i = 0; i < len; ++i)
            temp[i] = value[i];
        temp[len] = 0;
        std::cout<<temp;
        delete[] temp;
    }
    ~String(){
        delete[] value;
    }
};
int main(){
    String k("abcde");
    k.out();
    std::cout<<std::endl<<k.length()
             <<std::endl;
    k.append("Tfgh");
    k.out();
    std::cout<<std::endl<<k.length()
             <<std::endl;
    k.at(4) = '4';
    k.out();
    std::cout<<std::endl<<k.length()
             <<std::endl;
    k.append(nullptr);
    k.out();
    std::cout<<std::endl<<k.length()
             <<std::endl;
    
    
    std::cout<<std::endl<<(k.raw())[3]
             <<std::endl;
    {
        String k;
        k.out();
        std::cout<<std::endl<<k.length()
             <<std::endl;
        String t;
        t.append("12345");
        t.out();
        std::cout<<std::endl<<t.length()
             <<std::endl;
    }
}
