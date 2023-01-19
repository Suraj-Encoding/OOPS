#include<iostream>
using namespace std;
class complex{
    int real;
    int img;
    public:
        complex(){
            real=0;
            img=0;
        }
        void display_complex(){
            if(img > 0){
                cout<<"Complex number : "<<real<<"+"<<img<<"i"<<endl;
            }else{
                cout<<"Complex number : "<<real<<img<<"i"<<endl; 
            }
        }
        friend complex operator +(complex a ,complex c);
        friend complex operator *(complex a ,complex c);
        void operator <<(complex a){
            if(img >= 0){
                cout<<"Complex number : "<<a.real<<"+"<<a.img<<"i"<<endl;
            }else{
                cout<<"Complex number : "<<a.real<<a.img<<"i"<<endl; 
            }
        }
        complex operator >>(complex a){
            cout<<"real : ";
            cin>>a.real;
            cout<<"img : ";
            cin>>a.img;
            return a;
            
        }
};
        complex operator +(complex a ,complex c){
            complex b;
            b.real= c.real + a.real;
            b.img= c.img + a.img;
            return b;
        }
        complex operator *(complex a ,complex c){
            complex b;
            b.real= c.real*a.real - a.img*c.img;
            b.img= c.real*a.img +c.img*a.real;
            return b;
        }
int main(){
    complex a,b,c;
    cout<<"-----------------------------------"<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<"First number :"<<endl;
    a=a>>(a);
    cout<<"-----------------------------------"<<endl;
    cout<<"Second number :"<<endl;
    b=b>>(b);
    cout<<"-----------------------------------"<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<"Addition : "<<endl;
    c=a+b;
    c<<(c);
    cout<<"-----------------------------------"<<endl;
    cout<<"Multiplication"<<endl;
    c=a*b;
    c<<(c);
    cout<<"-----------------------------------"<<endl;
    cout<<"-----------------------------------"<<endl;
    return 0;
}