#include <iostream>
#include <cmath>
using namespace std;
class Telo
{
protected:
    double povrsina;
    double zapremina;
public:
    virtual double Povrsina() = 0;
    virtual double Zapremina() = 0;
    virtual void ispisi()=0;
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
        zapremina = a*b*c;
        return zapremina;
    }
    double Povrsina()
    {
        povrsina = 2*(a*b + a*c + b*c);
        return povrsina;
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
        zapremina = pow(a,2)*sqrt(pow(h,2)-pow(a/2,2))/3;
        return zapremina;
    }
    double Povrsina()
    {
        povrsina = pow(a,2)+4*(a*h/2);
        return povrsina;
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
};
class JSPiramida : public Piramida
{
public:
    JSPiramida(){a = 5; h =(a*sqrt(3))/2;}
    JSPiramida(double stranica, double visina){a = stranica; h = visina;}
    JSPiramida(const JSPiramida &jsp){a = jsp.a; h = jsp.h;}
    ~JSPiramida(){}
};
class specTelo : Telo
{
private:
    Kocka K;
    JSPiramida P;
public:
    specTelo() : K(2.00),P(2.00, 4.00){}
    specTelo(double stranica, double visina) : K(stranica),P(stranica, visina){}
    specTelo(const specTelo &s) : K(s.K),P(s.P){}
    ~specTelo(){}

    double Zapremina()
    {
        zapremina = K.Zapremina() + 2*P.Zapremina();
        return zapremina;
    }
    double Povrsina()
    {
        povrsina = 2*(P.Povrsina() - pow(P.getStranicaA(),2)) + 4*pow(K.getStranicaA(),2);
        return povrsina;
    }
    void ispisi()
    {
        cout<<K.getStranicaA()<<","<<Zapremina()<<","<<Povrsina()<<endl;
    }
};
int main()
{
    Kvadar K;
    Kvadar K1(5.00,6.00,7.00);
    Kvadar K2(K);
    K.ispisi();
    K1.ispisi();
    K2.ispisi();

    Piramida P;
    Piramida P1(7.00,10.00);
    Piramida P2(P);
    P.ispisi();
    P1.ispisi();
    P2.ispisi();

    Kocka O;
    Kocka O1(5.00);
    Kocka O2(O);
    K.ispisi();
    K1.ispisi();
    K2.ispisi();

    JSPiramida S;
    JSPiramida S1(2.00,1.71);
    JSPiramida S2(S);
    S.ispisi();
    S1.ispisi();
    S2.ispisi();

    specTelo T;
    specTelo T1(8.00,6.84);
    specTelo T2(T);
    T.ispisi();
    T1.ispisi();
    T2.ispisi();
    return 0;
}
