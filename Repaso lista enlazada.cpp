#include <iostream>
using namespace std;
//Clase nodo
class Node{
    private:
        int num;
        Node *Sig;
    public:
        Node();
        Node(int num,Node *Sig);
        Node(const Node &copiar);
        void setNumero(int num);
        void setSiguiente(Node *Sig);
        int getNumero();
        Node *getSiguiente();
        ~Node();
};
Node::Node(){
    this->num=0;
    this->Sig=NULL;
}
Node::Node(int num,Node *Sig){
    this->num=num;
    this->Sig=Sig;
}
Node::Node(const Node &copiar){
    this->num=copiar.num;
    this->Sig=copiar.Sig;
}
void Node::setNumero(int num){
    this->num=num;
}
void Node::setSiguiente(Node*Sig){
    this->Sig=Sig;
}
int Node::getNumero(){
    return this->num;
}
Node *Node::getSiguiente(){
    return this->Sig;
}
Node::~Node(){}
//Clase lista enlazada
class LinkedList{
    private:
        Node *head;
        int size;
    public:
        LinkedList();
        int getSize();
        void insert(int num);
        void remove(int pos);
        void print();
        friend ostream& operator << (ostream &o, const LinkedList&DA);
        ~LinkedList();
};
LinkedList::LinkedList(){
    this->head=NULL;

}
int LinkedList::getSize(){
    Node *Aux=this->head;
    int count=0;
    while(Aux!=NULL){
        cout<<Aux->getNumero()<<endl;
        Aux=Aux->getSiguiente();
        count+=1;
    }
    return count;
}
void LinkedList::insert(int num){
    //creacion del primer nodo
    this->head=new Node(num,this->head);
    Node *Aux=head;
    Node *aux=NULL;
    int numAux;
    while (Aux->getSiguiente()!=NULL)
    {
        aux=Aux->getSiguiente();
        while(aux!=NULL){
            if(Aux->getNumero()>aux->getNumero()){
                numAux=aux->getNumero();
                aux->setNumero(Aux->getNumero());
                Aux->setNumero(numAux);
            }
            aux=aux->getSiguiente();
        }
        Aux=Aux->getSiguiente();

    }

}
void LinkedList::remove(int pos){
    Node *Aux=this->head;
    Node *Aux2;
    int numPos=1;
    if(Aux!=NULL){
        if(pos==1){
            head=Aux->getSiguiente();
        }
        else{
            while(numPos<pos && Aux->getSiguiente()!=NULL){
                Aux2=Aux;
                Aux=Aux->getSiguiente();
                numPos++;
            }
            Aux2->setSiguiente(Aux->getSiguiente());//esto con el fin de eliminar el nodo aux
        }
        delete Aux;
    }
}
void LinkedList::print(){
    Node *Aux=this->head;
    while(Aux!=NULL){
        cout<<Aux->getNumero()<<endl;
        Aux=Aux->getSiguiente();
    }
}
ostream& operator << (ostream &o, const LinkedList&DA){
    Node *Aux=DA.head;
    while(Aux!=NULL){
        o<<Aux->getNumero()<<" ";
        Aux=Aux->getSiguiente();    
    } 
    return o;
}
LinkedList::~LinkedList(){//elimina todos los nodos
    Node *Aux=head;
    Node *Actual;
    while(Aux!=NULL){
        Actual=Aux->getSiguiente();
        delete Aux;
        Aux=Actual;
    }
    head=NULL;
}
//Insertando elementos en una lista enlazada
//pasos
//1.Crear un nuevo nodo
//2.Asignar a nuevo_nodo->dato el elemento que queremos incluir a la lista 
//3.Crear dos nodos auxiliares y asignar lista al primero de ellos
//4.Insertar el elemento a la lista
int main(){ 
    LinkedList *Ve=new LinkedList;
    cout<<"Lista inicial"<<endl;
    Ve->insert(300);
    Ve->insert(127);
    Ve->insert(200);
    Ve->insert(880);
    Ve->insert(790);
    Ve->insert(123);
    Ve->print();
    cout<<"El tamano es "<<Ve->getSize()<<endl;
    //cout<<Ve;
    Ve->remove(3);
    cout<<"Lista eliminando la posicion 3"<<endl;
    //cout<<Ve;
    Ve->print();
    cout<<"El tamano es "<<Ve->getSize()<<endl;
    return 0;
}
