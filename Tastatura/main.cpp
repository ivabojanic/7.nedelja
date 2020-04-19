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
class Tastatura
{
protected:
    DinString proizvodjac;
    int brojTastera;
public:
    void ispisi()
    {
        cout<<proizvodjac<<","<<brojTastera;
    }

};
class GejmerskaTastatura : public Tastatura
{
private:
    int brojPritisaka;
public:
    GejmerskaTastatura(){brojPritisaka = 0; proizvodjac = "Samsung"; brojTastera = 100;}
    GejmerskaTastatura(int b, DinString p, int t){brojPritisaka = b; proizvodjac = p; brojTastera = t;}
    GejmerskaTastatura(const GejmerskaTastatura &g){brojPritisaka = g.brojPritisaka; proizvodjac = g.proizvodjac; brojTastera = g.brojTastera;}
    ~GejmerskaTastatura(){}

    void ispis()
    {
        Tastatura::ispisi();
        cout<<brojPritisaka;
    }
    void pritisniTaster()
    {
        brojPritisaka++;
    }
    void drziTaster(int sec)
    {
        brojPritisaka += sec;
    }

};
class NumerickaTastatura : public Tastatura
{
private:
    int brojPritisakaBrojeva;
public:
    NumerickaTastatura(){brojPritisakaBrojeva = 0; proizvodjac = "Lenovo"; brojTastera = 100;}
    NumerickaTastatura(int b, DinString p, int t){brojPritisakaBrojeva = b; proizvodjac = p; brojTastera = t;}
    NumerickaTastatura(const NumerickaTastatura &n){brojPritisakaBrojeva = n.brojPritisakaBrojeva; proizvodjac = n.proizvodjac; brojTastera = n.brojTastera;}
    ~NumerickaTastatura(){}

    void ispis()
    {
        Tastatura::ispisi();
        cout<<brojPritisakaBrojeva;
    }

    void pritisniTaster(bool PritisniBroj)
    {
        if(PritisniBroj == true)
        {
            brojPritisakaBrojeva++;
        }
    }
    void drziTaster(int sec,bool PritisnutBroj)
    {
        if(PritisnutBroj == true)
        {
            brojPritisakaBrojeva += sec;
        }
    }
};
int main()
{
    GejmerskaTastatura G;
    GejmerskaTastatura G1(10,"Samsung",100);
    GejmerskaTastatura G2(G);
    G.ispis();
    G1.ispis();
    G2.ispis();

    G1.drziTaster(10);
    G2.pritisniTaster();
    G2.ispis();
    G2.ispis();

    NumerickaTastatura N;
    NumerickaTastatura N1(10,"Lenovo",100);
    NumerickaTastatura N2(N);
    N.ispis();
    N1.ispis();
    N2.ispis();

    N1.pritisniTaster(true);
    N2.drziTaster(10,true);
    N1.ispis();
    N2.ispis();

    return 0;
}
