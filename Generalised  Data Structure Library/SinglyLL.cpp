#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class SinglyLL
{
    private:
        struct node<T> * first;
        int Count;

    public:
        SinglyLL();
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
SinglyLL<T>::SinglyLL()
{
    cout<<"Inside constructor\n";
    first = NULL;
    Count = 0;
}

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
    struct node<T> *newn = NULL;

    newn = new struct node<T>;   
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)   // if(Count == 0)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    Count++;
}

template <class T>
void SinglyLL<T>::InsertLast(T no)
{
    struct node<T> * newn = NULL;
    struct node<T> * temp = first;

    newn = new struct node<T>;   
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)   // if(Count == 0)
    {
        first = newn;
    }
    else
    {
        while(temp -> next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    Count++;
}

template <class T>
void SinglyLL<T>::Display()
{
    struct node<T> * temp = first;

    cout<<"Elements of the linked list are : \n";
    
    while(temp != NULL) // Type 1
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp ->next;
    }
    cout<<"NULL \n";
}

template <class T>
int SinglyLL<T>::CountNode()
{
    return Count;
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        struct node<T> * temp = first;

        first = first->next;
        delete temp;
    }
    Count--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        struct node<T> * temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    Count--;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T no,int ipos)
{
    if((ipos < 1) || (ipos > Count+1))
    {
        return;
    }
     
    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == Count+1)
    {
        InsertLast(no);
    }
    else
    {
        struct node<T> * newn = new struct node<T>;
        newn->data = no;
        newn->next = NULL;

        struct node<T> * temp = first;
        int i = 0;

        for(i = 1; i < ipos-1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp->next = newn;

        Count++;
    }
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int ipos)
{
    if((ipos < 1) || (ipos > Count))
    {
        return;
    }
     
    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == Count)
    {
        DeleteLast();
    }
    else
    {
        struct node<T> * temp = first;
        int i = 0;

        for(i = 1; i < ipos-1; i++)
        {
            temp = temp -> next;
        }

        struct node<T> * targatednode = temp->next;
        temp->next = temp->next->next;
        delete targatednode;

        Count--;
    }
}

int main()
{
    int i;  
    cout<<"SinglyLL of integer type:"<<"\n";
    cout<<"SinglyLL of float type:"<<"\n";
    cout<<"SinglyLL of double type:"<<"\n";
    cout<<"SinglyLL of character type:"<<"\n";

    cout<<"Enter your choise :"<<"\n";
    cin>>i;

    if(i == 1)
    {
    SinglyLL <int>obj;

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
         SinglyLL <float>obj;

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
        SinglyLL <double>obj;

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
    SinglyLL <char>obj;

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
    else
   {
       cout<<"invalid Choise<<"\n";
   }
    return 0;
}
