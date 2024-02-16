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
   int i;  
    cout<<"DoublyLL of integer type:"<<"\n";
    cout<<"DoublyLL of float type:"<<"\n";
    cout<<"DoublyLL of double type:"<<"\n";
    cout<<"DoublyLL of character type:"<<"\n";

    cout<<"Enter your choise :"<<"\n";
    cin>>i;

    if(i == 1)
    {
    DoublyCL <int>obj;

    int iRet = 0;

    obj.InsertFirst(11);
    obj.InsertFirst(21);
    obj.InsertFirst(51);
    obj.InsertFirst(101);
    obj.InsertFirst(111);
    
    obj.InsertLast(121);
    obj.InsertLast(151);
    obj.InsertLast(201);
    
    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.InsertAtPos(105, 5);

    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.DeleteAtPos(5);

    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.DeleteFirst();
    

    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.DeleteLast();

    
    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";
    }
    else if(i == 2)
    {
         DoublyCL <float>obj;

    int iRet = 0;

    obj.InsertFirst(11.11);
    obj.InsertFirst(21.2);
    obj.InsertFirst(51.3);
    obj.InsertFirst(101.4);
    obj.InsertFirst(111.5);
    
    obj.InsertLast(121.6);
    obj.InsertLast(151.2);
    obj.InsertLast(201.3);
    
    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.InsertAtPos(105.8, 5);

    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.DeleteAtPos(5);

    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.DeleteFirst();
    

    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.DeleteLast();

    
    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";
    }
    else if(i == 3)
    {
        DoublyCL <double>obj;

    int iRet = 0;

    obj.InsertFirst(11.1111);
    obj.InsertFirst(21.3234);
    obj.InsertFirst(51.789);
    obj.InsertFirst(101.098);
    obj.InsertFirst(111.567);
    
    obj.InsertLast(121.432);
    obj.InsertLast(151.429);
    obj.InsertLast(201.320);
    
    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.InsertAtPos(105.526, 5);

    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.DeleteAtPos(5);

    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.DeleteFirst();
    

    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.DeleteLast();

    
    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";
    }
   else if (i == 4)
{
    DoublyCL <char>obj;

    int iRet = 0;

    obj.InsertFirst('E');
    obj.InsertFirst('D');
    obj.InsertFirst('C');
    obj.InsertFirst('B');
    obj.InsertFirst('A');
    
    obj.InsertLast('X');
    obj.InsertLast('Y');
    obj.InsertLast('Z');
    
    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.InsertAtPos('S', 5);

    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.DeleteAtPos(5);

    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.DeleteFirst();
    

    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.DeleteLast();

    
    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";
}
}
