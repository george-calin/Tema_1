#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
ifstream f("date.in.txt");
struct cub
{
    int col,l,index; // col = color , l = latura cubului , index = indexul initial al cubului
};
bool compare(cub a, cub b)
{
    return a.l > b.l;
}
void citire(vector <cub> &c,int &n,int &p)
{
    f>>n>>p;
    cub aux;
    c.resize(n);
    for(int i=0; i<n; i++)
    {
        f>>aux.l>>aux.col;
        aux.index=i+1;
        c.push_back(aux);
    }
    f.close();
    sort(c.begin(),c.end(),compare); //ordonare descrescatoare dupa latura
}
void algoritm(vector <cub> &c,int n)
{
    int inaltime_turn=c[0].l, culoarea_curenta=c[0].col;
    cout<<c[0].index<<' ';
    for(int i=1; i<n; i++)  //parcurgem vectorul descrescator , cand culorile a doua cuburi consecutive sunt diferite,
        //afisam cel de-al doilea cub si actualizam culoarea curenta
    {
        if(c[i].col!=culoarea_curenta)
        {
            cout<<c[i].index<<' ';
            culoarea_curenta=c[i].col;
            inaltime_turn+=c[i].l;
        }
    }
    cout<<endl<<inaltime_turn;
}
int main()
{
    vector <cub> c;
    int n,p;
    citire(c,n,p);
    algoritm(c,n);

}
/* In cazul in care lungimile laturilor pot fi si egale , algoritmul de mai sus nu functioneaza de fiecare data
deoarece e posibil ca ordonarea descrescatoare dupa lungime sa puna 2 cuburi de aceeasi culoare unu dupa altul fiind
posibila si o alta pozitionare.
EX 10 1
    9 1
    9 2
algoritmul rezulta: inaltimea turnului = 10+9 = 19 , cuburile:1 3
 iar solutia optima = 10+9+9 = 28 , cuburile:1 3 2
 */

