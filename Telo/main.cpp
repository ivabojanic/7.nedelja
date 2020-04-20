#include <iostream>
#include <cmath>
using namespace std;
class Telo
{
public:
    virtual double Povrsina() = 0;
    virtual double Zapremina() = 0;
    virtual void ispisi()= 0;
};
class Kvadar : public Telo
{
protected:
    double a;
    double b;
    double c;
public:
    Kvadar(){a = 2; b = 3; c = 4;}
    Kvadar(double A, double B, double C){a = A; b = B; c = C;}
    Kvadar(const Kvadar &k){a = k.a; b = k.b; c = k.c;}
    ~Kvadar(){}

    double getStranicaA()const{return a;}
    double getStranicaB()const{return b;}
    double getStranicaC()const{return c;}

    double Zapremina()
    {
        double Z = a*b*c;
        return Z;
    }
    double Povrsina()
    {
        double P = 2*(a*b + a*c + b*c);
        return P;
    }
    void ispisi()
    {
        cout<<getStranicaA()<<","<<getStranicaB()<<" "<<getStranicaC()<<" "<<Zapremina()<<" "<<Povrsina()<<endl;
    }
};
class Piramida : public Telo
{
protected:
    double a;
    double h;
public:
    Piramida(){a = 2; h = 3;}
    Piramida(double A, double H){a = A; h = H;}
    Piramida(const Piramida &p){a = p.a; h = p.h;}
    ~Piramida(){}

    double getStranicaA()const{return a;}
    double getVisinu()const{return h;}

    double Zapremina()
    {
        double Z = pow(a,2)*sqrt(pow(h,2)-pow(a/2,2))/3;
        return Z;
    }
    double Povrsina()
    {
        double P = pow(a,2)+4*(a*h/2);
        return P;
    }
    void ispisi()
    {
        cout<<getStranicaA()<<","<<getVisinu()<<","<<Zapremina()<<","<<Povrsina()<<endl;
    }
};
class Kocka : public Kvadar
{
public:
    Kocka(){a = 10.00; b = 10.00; c = 10.00;}
    Kocka(double stranica){a = stranica; b = stranica; c = stranica;}
    Kocka(const Kocka &K){a = K.a; b = K.b; c = K.c;}
    ~Kocka(){}
    double getStranicaA()const{return a;}

    double Zapremina()
    {
        double Z = pow(a,3);
        return Z;
    }
    double Povrsina()
    {
        double P = pow(a,2)*6;
        return P;
    }
    void ispisi()
    {
        cout<<getStranicaA()<<","<<Zapremina()<<","<<Povrsina()<<endl;
    }
};
class JSPiramida : public Piramida
{
public:
    JSPiramida(){a = 5; h =(a*sqrt(3))/2;}
    JSPiramida(double stranica, double visina){a = stranica; h = visina;}
    JSPiramida(const JSPiramida &jsp){a = jsp.a; h = jsp.h;}
    ~JSPiramida(){}
    double getStranicaA()const{return a;}
    double getVisinu()const{return h;}
    double Zapremina()
    {
        double Z = pow(a,2)*sqrt(pow(h,2)-pow(a/2,2))/3;
        return Z;
    }
    double Povrsina()
    {
        double P = pow(a,2)+4*(a*h/2);
        return P;
    }
    void ispisi()
    {
        cout<<getStranicaA()<<","<<getVisinu()<<","<<Zapremina()<<","<<Povrsina()<<endl;
    }
};
class specTelo
{
private:
    Kocka K;
    JSPiramida P;
public:
    specTelo() : K(2.00),P(2.00){}
    specTelo(double stranica) : K(stranica),P(stranica){}
    specTelo(const specTelo &s) : K(s.K),P(s.P){}
    ~specTelo(){}

    double Zapremina()
    {
        double Z = K.Zapremina() + 2*P.Zapremina();
        return Z;
    }
    double Povrsina()
    {
        double P = (2*(P.Povrsina() - pow(P.getStranicaA(),2)) + 4*pow(K.getStranicaA(),2);
        return P;
    }
    void ispisi()
    {
        cout<<K.getStranicaA()<<","<<Zapremina()<<","<<Povrsina()<<endl;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
