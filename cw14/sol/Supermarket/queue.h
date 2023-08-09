//queue.h -- interfejs kolejki

#ifndef QUEUE_H_
#define QUEUE_H_

//ta kolejka bedzie przechowywala elementy klasy Customer
class Customer {
    private:
        long arrive; //czas dolaczenia klienta do kolejki
        int processtime; //czas obslugi klienta
    public:
        Customer() { arrive = processtime = 0; }
        void set (long when);
        long when() const { return arrive; }
        int ptime() const { return processtime; }
};

typedef Customer Item;

class Queue {
    private:
        struct Node {
            Item item;
            struct Node* next;
        };
        enum { Q_SIZE = 10 };
        Node *front; //wskaznik czola kolejki
        Node *rear; //wskaznik ogona kolejki
        int items; //biezaca liczba elementow kolejki
        const int qsize; //maksymalna liczba elementow kolejki
        Queue (const Queue &q) : qsize (0) {}
        Queue &operator= (const Queue &q) { return *this; }
    public:
        Queue (int qs = Q_SIZE); //tworzy kolejke o pojemnosci qs
        ~Queue();
        bool isempty() const;
        bool isfull() const;
        int queuecount() const;
        bool enqueue (const Item &item); //dodaje element na koniec kolejki
        bool dequeue (Item &item); //wyciaga element z czola kolejki
};

#endif //QUEUE_H_
