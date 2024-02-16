// Doubly Circular

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
class DoublyCL
{
    private:
         struct node<T> * first;
         struct node<T> * last;
        int Count;

    public:
        DoublyCL();
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
DoublyCL<T>::DoublyCL()
{
    first = NULL;
    last = NULL;
    Count = 0;
}
template <class T>
void DoublyCL<T>::InsertFirst(T no)
{
    struct node<T> * newn=NULL;
    newn = new struct node<T>;
    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if((first == NULL)&&(last == NULL))
    {
        first=newn;
        last = newn;
    }
    else
    {
        newn->next=first;
        first->prev=newn;
        first=newn;
    }
    last->next=first;
    first->prev=newn;
    Count++;
}

template <class T>
int DoublyCL<T>::CountNode()
{
    return Count;
}

template <class T>
void DoublyCL<T>::Display()
{
     if(first != NULL && last != NULL)
    {
        do
        {
            cout<<"| "<<first->data<<"| <=>";
            first = first->next;
        }while(first != last->next);
    }

}
template <class T>
void DoublyCL<T>::InsertLast(T no)
{
    struct node<T> * newn=NULL;
   // struct node<T> * temp=first;
    newn = new struct node<T>;
    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if((first == NULL)&&(last == NULL))
    {
        first=newn;
        last=newn;
    }
    else
    {
        newn->prev=last;
        last->next=newn;
        last=newn;
    }
    last->next=first;
    first->prev=last;
    Count++;
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if((first == NULL)&&(last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        free(first);
        first=NULL;
        last=NULL;
    }
    else
    {
         first=first->next;
         free(last->next);
         last->next=first;
        first->prev=last;
    }
    Count--;
}


template <class T>
void DoublyCL<T>::DeleteLast()
{
     if(first == NULL)
    {
        return;
    }
    else if(first == last)
    {
        free(first);
        first=NULL;
        last = NULL;
    }
    else
    {
        struct node<T> * temp = first;
        while(temp->next->next != first)
        {
            temp=temp->next;
        }
        last=last->prev;
        free(last->next);
        last->next=first;
        first->prev=last;
    }
    Count--;
}


template <class T>
void DoublyCL<T>::InsertAtPos(T no,int ipos)
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
void DoublyCL<T>::DeleteAtPos(int ipos)
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
    DoublyCL <float>obj;
    int iret=0;

    obj.InsertFirst(51.1);
    obj.InsertFirst(21.2);
    obj.InsertFirst(11.3);

    obj.Display();

    iret=obj.CountNode();
    cout<<"\n Number of nodes are :"<<iret<<"\n";

    obj.InsertLast(101.1);
    obj.InsertLast(111.2);
    obj.InsertLast(121.3);

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

     obj.InsertAtPos(105.3,3);

    obj.Display();

    iret=obj.CountNode();
    cout<<"\n Number of nodes are :"<<iret<<"\n";

     obj.DeleteAtPos(3);

    obj.Display();

    iret=obj.CountNode();
    cout<<"\n Number of nodes are :"<<iret<<"\n";

    return 0;
}