//queue.cpp -- implementacje metod klas Queue i Customer

#include "queue.h"
#include <cstdlib>

//metody klasy Queue

Queue::Queue (int qs) : qsize (qs) {
    front = rear = NULL;
    items = 0;
}

Queue::~Queue() {
    Node *temp;
    while (front != NULL) { //do wyczerpania kolejki
        temp = front; //zachowanie adresu elementu biezacego
        front = front->next; //przesuniecie wskaznika do elementu nastepnego
        delete temp; //zwolnienie elementu spod zapamietanego adresu
    }
}

bool Queue::isempty() const {
    return items == 0;
}

bool Queue::isfull() const {
    return items == qsize;
}

int Queue::queuecount() const {
    return items;
}

//dodaje element do kolejki
bool Queue::enqueue (const Item &item) {
    if (isfull())
            return false;
    Node *add = new Node; //utworzenie wezla
    if (add == NULL)
            return false; //brak mozliwosci przydzialu elementu
    add->item = item; //ustawienie wskaznikow wezlow
    add->next = NULL;
    items++;
    if (front == NULL) //jesli kolejka jest pusta
            front = add; //umiesc element na czele listy
    else
        rear->next = add; //w przeciwnym przypadku dolacz do konca
    rear = add; //rear wskazuje teraz nowy wezel
    return true;
}

//kopiuje element czolowy kolejki do argumentu wywolania i usuwa go z kolejki
bool Queue::dequeue (Item &item) {
    if (front == NULL)
            return false;
    item = front->item; //skopiowanie do item pierwszego elementu kolejki
    items--;
    Node *temp = front; //zachowanie polozenia pierwszego elementu
    front = front->next; //przestawienie wskaznika front na nastepny element
    delete temp; //usuniecie dotychczasowego pierwszego elementu
    if (items == 0)
            rear = NULL;
    return true;
}

//metody klasy Customer

/*kiedy klient trafia do kolejki, zapamietywany jest biezacy czas systemowy,
losowany jest tez czas obslugi klienta (z zakresu od 1 do 3)*/
void Customer::set (long when) {
    processtime = std::rand() % 3 + 1;
    arrive = when;
}
