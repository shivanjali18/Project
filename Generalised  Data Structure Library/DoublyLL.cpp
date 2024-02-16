// Doubly Linear

#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};
template <class T>
class DoublyLL
{
    private:
         struct node<T> * first;
        int Count;

    public:
        DoublyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void Display();
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T no,int ipos);
        void DeleteAtPos(int ipos);
};
template <class T>
DoublyLL<T>::DoublyLL()
{
    first = NULL;
    Count = 0;
}
template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
    struct node<T> * newn=NULL;
    newn = new struct node<T>;
    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if(first == NULL)
    {
        first=newn;
    }
    else
    {
        newn->next=first;
        first->prev=newn;
        first=newn;
    }
    Count++;
}
template <class T>
void DoublyLL<T>::InsertLast(T no)
{
    struct node<T> * newn=NULL;
    newn = new struct node<T>;
    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if(first == NULL)
    {
        first=newn;
    }
    else
    {
        struct node<T> * temp = first;
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        newn->prev=temp;
        temp->next=newn;
    }
    Count++;
}
template <class T>
void DoublyLL<T>::Display()
{
    struct node<T> * temp=first;

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"| <=> ";
        temp=temp->next;
    }
    cout<<"NULL\n";

}
template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        free(first);
        first=NULL;
    }
    else
    {
        struct node<T> * temp=first;
        first=first->next;
         first->next->prev=NULL;
         free(temp);
    }
    Count--;
}
template <class T>
void DoublyLL<T>::DeleteLast()
{
     if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        free(first);
        first=NULL;
    }
    else
    {
        struct node<T> * temp = first;
        while(temp->next->next != NULL)
        {
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    }
    Count--;
}
template <class T>
int DoublyLL<T>::CountNode()
{
    return Count;
}
template <class T>
void DoublyLL<T>::InsertAtPos(T no,int ipos)
{
    int size=0,i=0;
    size=CountNode();

    struct node<T> * newn=NULL;
    newn=new struct node<T>;
    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if((ipos < 1)||(ipos > size+1))
    {
        cout<<"Invalid Position\n";
        return;
    }
    else if(ipos ==1)
    {
        InsertFirst(no);
    }
    else if(ipos == size+1)
    {
        InsertLast(no);
    }
    else 
    {
        struct node<T> * temp=first;
        for(i=1;i<ipos-1;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next->prev=newn;
        newn->prev=temp;
        temp->next=newn;
    }
    Count++;
}
template <class T>
void DoublyLL<T>::DeleteAtPos(int ipos)
{
     int size=0,i=0;
    size=CountNode();

    if((ipos < 1)||(ipos > size))
    {
        cout<<"Invalid Position\n";
        return;
    }
    else if(ipos ==1)
    {
        DeleteFirst();
    }
    else if(ipos == size)
    {
        DeleteLast();
    }
    else 
    {
        struct node<T> * temp=first;
        for(i=1;i<ipos-1;i++)
        {
            temp=temp->next;
        }
        struct node<T> * target = temp->next;
        temp->next=temp->next->next;
        free(target);
    }
    Count--;
}

int main()
{
    DoublyLL <float>obj;
    int iret=0;

    obj.InsertFirst(51.1);
    obj.InsertFirst(21.2);
    obj.InsertFirst(11.3);

    obj.Display();

    iret=obj.CountNode();
    cout<<"\n Number of nodes are :"<<iret<<"\n";

     obj.InsertLast(101.1);
    obj.InsertLast(111.4);
    obj.InsertLast(121.5);

    obj.Display();

    iret=obj.CountNode();
    cout<<"\n Number of nodes are :"<<iret<<"\n";

     obj.DeleteFirst();

    obj.Display();

    iret=obj.CountNode();
    cout<<"\n Number of nodes are :"<<iret<<"\n";

    obj.DeleteLast();

    obj.Display();

    iret=obj.CountNode();
    cout<<"\n Number of nodes are :"<<iret<<"\n";

    obj.InsertAtPos(105.6,3);

    obj.Display();

    iret=obj.CountNode();
    cout<<"\n Number of nodes are :"<<iret<<"\n";

     obj.DeleteAtPos(3);

    obj.Display();

    iret=obj.CountNode();
    cout<<"\n Number of nodes are :"<<iret<<"\n";
    return 0;
}