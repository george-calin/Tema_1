#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
ifstream f("date.in");
struct eveniment
{
    int t,p,index; // t = timp
    // p = profit
};
vector <eveniment> v; //vectorul de evenimente
vector <eveniment>::iterator it;
stack <int> afisare;
int n;
bool compara(eveniment a,eveniment b)
{
    return a.t>b.t;
}
void citire()
{
    f>>n;
    v.resize(n);
    eveniment aux;
    for(int i=0; i<n; i++)
    {
        f>>aux.p>>aux.t;
        aux.index=i+1;
        v.push_back(aux);
    }
    f.close();
    sort(v.begin(),v.end(),compara); //ordonare descrescatoare  a evenimentelor dupa timp
}
void algoritm()
{
    eveniment max_cur; //max_cur = evenimentul cu cel mai bun profit pana la pasul curent
    int max_it; // indexul evenimentului max_cur
    int timp=v[0].t,n; // timpul initial este cel maxim , adica v[0].t
    while(timp!=0)
    {

        if(v[0].t>=timp)
        {
            max_it=0;
            max_cur=v[0];
            for(int j=1; v[j].t>=timp; j++) //parcurgem vectorul cat timp evenimentele se incadreaza in timpul curent
                // , alegem evenimentul cu profitul cel mai bun , il punem in stiva de afisare
                // si il stergem din vector
            {
                if(v[j].p>max_cur.p)
                {
                    max_cur=v[j];
                    max_it=j;
                }
            }
            v.erase(v.begin()+max_it);
            afisare.push(max_cur.index);
            --n;
        }
        --timp;
    }
}

int main()
{
    citire();
    algoritm();
    while(!afisare.empty()) //afisarea indexurilor evenimentelor in ordinea corecta
    {
        cout<<afisare.top()<<" ";
        afisare.pop();
    }
}
