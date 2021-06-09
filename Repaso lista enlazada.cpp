#include <iostream>
using namespace std;
//Insertando elementos en una lista enlazada
//pasos
//1.Crear un nuevo nodo
//2.Asignar a nuevo_nodo->dato el elemento que queremos incluir a la lista 
//3.Crear dos nodos auxiliares y asignar lista al primero de ellos
//4.Insertar el elemento a la lista
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

class LinkedList{
    private:
        Node *head;
        int size;
    public:
        LinkedList();
        void insert(int num);
        void remove(int pos);
        void print();
        ~LinkedList();
};
LinkedList::LinkedList(){
    this->head=NULL;

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
LinkedList::~LinkedList(){
    Node *Aux=head;
    Node *Actual;
    while(Aux!=NULL){
        Actual=Aux->getSiguiente();
        delete Aux;
        Aux=Actual;
    }
    head=NULL;
}

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
    Ve->remove(3);
    cout<<"Lista eliminando la posicion 3"<<endl;
    Ve->print();
    return 0;
}
