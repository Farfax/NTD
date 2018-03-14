#include<iostream>

template<class T>
class List{
                struct Node{ // "węzeł" przechowuję wartość oraz wskaźniki na następny/poprzedni
                        Node* next=nullptr;
                        Node* previous=nullptr;
                        T value;
                };

        Node* last=nullptr; // ostatni element
        Node* first=nullptr; // pierwszy element w liście
        int size=0;
public:
        ~List(){
                Node* node=first;

                while(node){ // zwalniamy pamięć
                        Node* temp=node->next;
                        delete node;
                        node=temp;
                }
        }

        void add(const T& value){
                Node* newNode= new Node; // tworzymy nowy węzęł i ustawiamy wartość
                newNode->value=value;

                if(!first)
                        first=newNode; // ustawiamy węzeł na pierwszym miejscu
                else{
                        newNode->previous=last; // wklejamy nowy węzeł za ostatnim
                        last->next=newNode;
                }

                size++;
                last=newNode; // aktualizujemy ostatni element
        }

        void print() const { // wypisuje wszystkie elementy
                Node* node=first;

                        while(node){
                                std::cout<<node->value<<std::endl;
                                node=node->next;
                        }
        }

        void remove(const T& value){ // usuwa pierwszy węzęł z daną wartością
                Node* node=first;

                while(node && node->value!=value) // szukamy węzła z daną wartością
                        node=node->next;

                if(!node) // jeśli nie znaleziono wychodzimy z metody
                        return;

                node->previous->next=node->next; // usuwamy węzeł ze struktury listy i zwalniamy pamięć
                node->next->previous=node->previous;

                delete node;
        }

        void removeAll(const T& value){ // usuwa wszystkie węzły z daną wartością
                int oldSize;

                do{
                        oldSize=size;
                        remove(value);
                }
                while(size!=oldSize);  // jeśli po wykonaniu remove lista nie zmieniejszy rozmiaru, nie ma już więcej elementów do usunięcia
        }
};

int main(){
        List<int> lista;
        int  numbers[]= { 3,1,2,4,5,3,5,6,3};

        for(auto num: numbers)
        lista.add(num);

        lista.print();
        lista.removeAll(3);
        lista.print();
        return 0;
}
