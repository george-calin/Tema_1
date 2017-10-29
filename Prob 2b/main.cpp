#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
ifstream f("date.in");
vector <int> text,index;
vector<stack<int> > stiva; // vector de p stive care sa retina textele lungi
vector<vector <int> > lista;// vector de p listele ce contin solutia finala
vector <int>::iterator it;
int n,p;
bool compara(int a,int b)
{
    return text[b]>text[a];
}
void citire()
{
    int aux;
    f>>n>>p;
    lista.resize(p);
    stiva.resize(p);
    for(int i=0; i<n; i++)
    {
        f>>aux;
        text.push_back(aux);
        index.push_back(i);
    }
    f.close();
    sort(index.begin(),index.end(),compara); //ordonare crescatoare dupa lungime
    for(int i = 0; i<n; i++)
        cout<<text[index[i]]<<" ";
    cout<<endl;
}
void algoritm_1()
{


    int i,_n=n-n%p,counter=0; // in cazul in care n%p!=0 , cele n%p elemente de la mijloc le tratam separat
    for(i=0; i<_n/2; i++)   // mergem pana la aproximativ mijlocul vectorului si adaugam elemente in p liste
    {
        lista[i%p].push_back(text[index[i]]);
        stiva[i%p].push(text[index[n-i-1]]);    // retinem in stiva[i%p] elemente ce urmeaza sa fie puse
        // in lista[i%p]
    }

    while(counter!=n%p) //adaugarea elementelor din mijloc care nu au fost adaugate in pasul anterior
    {
        lista[counter].push_back(text[index[i]]);
        ++counter;
        ++i;
    }

    for(i=0; i<_n/2; i++) // adaugarea elementelor retinute in stiva
    {
        lista[i%p].push_back(stiva[i%p].top());
        stiva[i%p].pop();
    }

}
void algoritm_2() //Pentru acest caz putem sa adaugam direct elemente din vectorul ordonat crescator
// de texte , in p liste
{
    for(int i=0; i<n; i++)
        lista[i%p].push_back(text[index[i]]);
}
int main()
{
    citire();
    if(n>p*2)
        algoritm_1();
    else algoritm_2();
    for(int i=0; i<p; i++) // Afisarea
    {
        for(it=lista[i].begin(); it<lista[i].end(); it++)
            cout<<*it<<" ";
        cout<<endl;
    }
    return 0;
}
