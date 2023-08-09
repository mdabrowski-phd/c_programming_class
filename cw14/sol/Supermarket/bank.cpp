//bank.cpp -- test interfejsu klasy Queue
//kompilowac z plikiem queue.cpp

#include <iostream>
#include <cstdlib> //funkcje rand() i srand()
#include <ctime> //funkcja time()
#include "queue.h"

using namespace std;

const int MIN_PER_HR = 60;

bool newcustomer (double x); //czy dotarl juz nastepny klient?

int main() {
    //przygotowanie symulacji
    srand(time(NULL)); //inicjalizacja generatora liczb losowych
    cout << "***SYMULACJA KOLEJKI W SUPERMARKECIE***\n\n";

    cout << "Podaj maksymalna dlugosc kolejki: ";
    int qs;
    cin >> qs;
    Queue line (qs); //w kolejce moze stanac maksymalnie qs klientow

    cout << "Podaj symulowany czas (w godzinach): ";
    int hours; //liczba godzin symulacji
    cin >> hours;
    //symulacja z jednominutowa rozdzielczoscia
    long cyclelimit = MIN_PER_HR * hours; //licza cykli

    cout << "Podaj srednia liczbe klientow na godzine: ";
    double perhour; //srednia liczba nowych klientow na godzine
    cin >> perhour;
    double min_per_cust = MIN_PER_HR / perhour; //sredni odstep czasowy pomiedzy klientami

    Item temp; //dane nowego klienta

    long turnaways = 0; //liczba klientow odeslanych z kolejki
    long customers = 0; //liczba klientow przyjetych do kolejki
    long served = 0; //liczba klientow obsluzonych w symulacji
    long sum_line = 0; //laczna liczba oczekujacych
    long wait_time = 0; //czas do zwolnienia bankomatu
    long line_wait = 0; //laczny czas oczekiwania

    //rozpoczecie symulacji
    for (int cycle = 0; cycle < cyclelimit; cycle++) {
        if (newcustomer (min_per_cust)) { //mamy nowego chetnego
            if (line.isfull())
                    turnaways++;
            else {
                customers++;
                temp.set (cycle); //czas przybycia = nr cyklu
                line.enqueue (temp); //dolaczenie klienta do kolejki
            }
        }
        if (wait_time <=0 && !line.isempty()) {
            line.dequeue (temp); //nastepny do obsluzenia
            wait_time = temp.ptime(); //czas obslugi = wait_time
            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += line.queuecount();
    }

    //zestawienie wynikow
    if (customers > 0) {
        cout << "\n\tliczba klientow przyjetych: " << customers << endl;
        cout << "\tliczba klientow obsluzonych: " << served << endl;
        cout << "\tliczba klientow odeslanych: " << turnaways << endl;
        cout << "\n\tsrednia dlugosc kolejki: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout.setf(ios_base::showpoint);
        cout << (double) sum_line / cyclelimit << endl;
        cout << "\tsredni czas oczekiwania: " << (double) line_wait / served << " minut\n";
    }
    else
        cout << "Brak klientow!\n";

    cout << "\n***GOTOWE!***\n";
    return 0;
}

/*x = sredni odstep czasowy (w minutach) pomiedzy potencjalnymi klientami
jesli wartosc zwracana to true, w danej minucie pojawil sie klient*/
bool newcustomer (double x) {
    return ( rand() * x / RAND_MAX < 1 );
}
