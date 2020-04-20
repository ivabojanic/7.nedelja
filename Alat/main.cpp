#include <iostream>

using namespace std;

class DinString
{
private:
        int duzina;
        char *text;
public:
        DinString(){duzina = 0; text = NULL;}
        DinString(const char ulaz[])
        {
            duzina = 0;
            while (ulaz[duzina] != '\0')
            {
                duzina++;
            }
            text = new char [duzina + 1];
            for(int i = 0; i < duzina; i++)
            {
                text[i] = ulaz[i];
            }
            text[duzina] = '\0';
        }
        DinString(const DinString &ds)
        {
            duzina = ds.duzina;
            text = new char [duzina + 1];
            for(int i = 0; i < duzina; i++)
            {
                text[i] = ds.text[i];
            }
            text[duzina] = '\0';
        }
        ~DinString(){ delete[] text;}

        int length() const {return duzina;}
        char& operator[] (int i){return text[i];}
        char operator[] (int i) const {return text[i];}

        DinString& operator=(const DinString &ds)
        {
            if(this != &ds) {
            delete[] text;
            duzina = ds.duzina;
            text = new char[duzina + 1];
            for (int i = 0; i < duzina; i++)
            {
                text[i] = ds.text[i];
            }
            text[duzina] = '\0';
        }
            return *this;
        }
        DinString& operator+=(const DinString &ds)
        {
            int i;
            char *tempText = new char[duzina + ds.duzina + 1];
            for (i = 0; i < duzina; i++)
            {
                 tempText[i] = text[i];
            }
            for (i = 0; i < ds.duzina; i++)
            {
                tempText[duzina + i] = ds.text[i];
            }
            tempText[duzina + ds.duzina] = '\0';
            duzina += ds.duzina;
            delete[] text;
            text = tempText;

            return *this;
        }

        friend bool operator==(const DinString &ds1, const DinString &ds2)
        {
            if(ds1.duzina != ds2.duzina)
            {
                return false;
            }
            for(int i = 1; i < ds1.duzina; i++)
            {
                if(ds1.text[i] != ds2.text[i])
                {
                    return false;
                }
            }
        }
        friend bool operator!=(const DinString &ds1 , const DinString &ds2)
        {
            if(ds1.duzina != ds2.duzina)
            {
                return true;
            }
            for(int i = 1; i < ds1.duzina; i++)
            {
                if(ds1.text[i] != ds2.text[i])
                {
                    return true;
                }
            }
        }
        friend DinString operator+(const DinString &ds1, const DinString &ds2)
        {
            DinString temp;
            temp.duzina = ds1.duzina + ds2.duzina;
            temp.text = new char[temp.duzina + 1];
            int i;
            for(i = 0; i < ds1.duzina; i++)
            {
                temp.text[i] = ds1.text[i];
            }
            for(i = 0; i < ds2.duzina; i++)
            {
                temp.text[ds1.duzina + i] = ds2.text[i];
            }
            temp.text[temp.duzina] = '\0';
            return temp;
        }

        friend ostream& operator<<(ostream &out, const DinString &ds)
        {
            if(ds.duzina > 0)
            {
                cout<<ds.text;
            }
            return out;
        }
};
class Alat
{
protected:
    DinString proizvodjac;
    DinString serijskiBroj;
public:
    void Ispis()
    {
        cout<<proizvodjac<<","<<serijskiBroj<<endl;
    }
};
class Cekic : public Alat
{
private:
    double tezina;
    int upotrebljivost;
public:
    Cekic(){ tezina = 100.00; upotrebljivost = 10; proizvodjac = "Cekicara"; serijskiBroj = "2003456";}
    Cekic(double t,int u, DinString p, DinString sb)
    {
        tezina = t;
        if( u > 0)
        {
            upotrebljivost = u;
        }
        proizvodjac = p;
        serijskiBroj = sb;
    }
    Cekic(const Cekic &c){tezina = c.tezina; upotrebljivost = c.upotrebljivost; proizvodjac = c.proizvodjac; serijskiBroj = c.serijskiBroj;}
    ~Cekic(){}

    void ispisi()
    {
        cout<<tezina<<","<<upotrebljivost;
        Alat::Ispis();
    }
    bool Upotrebi()
    {
        if(upotrebljivost > 0)
        {
            upotrebljivost--;
            return true;
        }else
            return false;
    }
};
class Testera : public Alat
{
private:
    double otupljenost;
public:
    Testera(){ otupljenost = 0.01; proizvodjac = "Teterara"; serijskiBroj = "007856";}
    Testera(double o, DinString p, DinString sb)
    {
        if( o > 0 && o < 1)
        {
            otupljenost = o;
        }
        proizvodjac = p;
        serijskiBroj = sb;
    }
    Testera(const Testera &t){otupljenost = t.otupljenost; proizvodjac = t.proizvodjac; serijskiBroj = t.serijskiBroj;}
    void ispisi()
    {
        cout<<otupljenost;
        Alat::Ispis();
    }
    bool Upotrebi()
    {
        if(otupljenost > 0)
        {
            otupljenost = otupljenost + 0.05;
            return true;
        }else
            return false;
    }
    bool naostri()
    {
        if(otupljenost < 1)
        {
            otupljenost = otupljenost - 0.05;
            return true;
        }else
            return false;
    }
};
int main()
{
    Cekic C;
    Cekic C1(300,9,"Cekicara Pezos","00569");
    Cekic C2(C);
    C.ispisi();
    C1.ispisi();
    C2.ispisi();
    C1.Upotrebi();
    C1.ispisi();

    Testera T;
    Testera T1(0.5,"Testerara Pezos","999856");
    Testera T2(T);
    T.ispisi();
    T1.ispisi();
    T2.ispisi();
    T1.Upotrebi();
    T1.ispisi();
    T1.naostri();
    T1.naostri();
    T1.ispisi();
    return 0;
    return 0;
}
