#include <iostream>
#include <iomanip>

using namespace std;

struct wezel
{
    int nr;
    wezel *next;
};

void drukuj_liste( wezel * );
void dodaj_wezly( wezel *, int );
void zwolnij_pamiec(wezel *);
int ile_elementow( wezel* );
int suma_co_drugiego( wezel* );

int main()
{
    wezel *head;//deklarujemy glowe
    head = new wezel;//rezerwujemy pamiec dla glowy i przypisujemy adres do zmiennej head
    head-> nr=0;//nadajemy wartosci skladowym wezla glowa
    head -> next=NULL;//glowa jest ogonem

    int k;
    cout<<"\n\n\tPodaj ile wezlow chcesz dodac:\t\t";
    cin>>k;

    dodaj_wezly( head, k );

    cout<<"\n\n\t***********************************\n";
    cout<<"\n\t******** Drukujemy liste **********\n";
    cout<<"\n\t***********************************\n\n";
    cout<<endl;

    drukuj_liste( head );

    cout<<"\t       NULL   \n";
    cout<<endl;

    cout<<"\n\t******************************"<<endl;
    cout<<"\t*  Na liscie jest: "<<ile_elementow(head)<<" wezlow. *"<<endl;
    cout<<"\t******************************"<<endl;
    cout<<"\n\t*****************************************"<<endl;
    cout<<"\t*  Suma co drugiego elementu wynosi: "<<suma_co_drugiego(head)<<". *"<<endl;
    cout<<"\t*****************************************"<<endl;

    // delete head;
    zwolnij_pamiec(head);
    return 0;
}

void drukuj_liste( wezel *n )
{                   //i != 0    i = i+1
    for ( ; n->next != NULL; n = n->next )
    {
        cout<<"\t      "<<n<<endl;
        cout<<"\t--------------------\n";
        cout<<"\t|   nr = "<<setw(3)<< n->nr <<"       |"<<endl;
        cout<<"\t--------------------\n";
        cout<<"\t| next = "<<setw(5)<< n->next <<"  |"<<endl;
        cout<<"\t--------------------\n";
        cout<<"\t         |   \n";
        cout<<"\t         V   \n";
    }
}

void dodaj_wezly( wezel *n, int k )
{
        for( int j = 0; j < k; j++ )//bedzie wykonywal k razy
        {
            wezel *w = new wezel;
            w->nr = (n->nr)+1;//wartosc liczby tylko sie zmienia
            w->next = NULL;//nowy wskazuje na koniec//wezly dodajemy na koncu
            n->next = w;//stary wskazuje na nowy
            n = w;
        }
}

void zwolnij_pamiec(wezel *w){
    while (w) {
        wezel *tmp = w;
        w = w -> next;
        delete tmp;
    }
}

int ile_elementow( wezel *n )
{
    int i=1;
    while( n->next != NULL )
    {
        n = n->next;
        i++;
    }
    return i;
}

int suma_co_drugiego( wezel *n )
{
    int i=1;
    int s=0;
    for ( ; n; n = n->next )
    {
        if( i%2 )
            s = s+n->nr;
        i++;
    }
    return s;
}
