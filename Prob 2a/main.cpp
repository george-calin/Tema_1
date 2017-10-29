#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream f("date.in");
int n;
struct text
{
    float ratie; // raportul dintre frecventa si lungime
    int index; // pentru a retine pozitia initiala in lista a unui text;
};
vector <text> v;
bool compara(text a,text b)
{
    return a.ratie>b.ratie;
}
void citire()
{
    text aux;
    float aux1,aux2;
    f>>n;
    for(int i=0;i<n;i++)
    {
    f>>aux1>>aux2;
    aux.ratie=aux2/aux1;
    aux.index=i+1;
    v.push_back(aux);
    }
    f.close();
    sort(v.begin(),v.end(),compara); // ordonare descrescatoare dupa ratie
    for(int i=0;i<n;i++)
        cout<<v[i].index<<" ";


}
int main()
{
    citire();
    return 0;
}
