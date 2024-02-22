// Singly Circular

#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class SinglyCL
{
    private:
        struct node<T> * first;
        struct node<T> * last;
        int Count;

    public:
        SinglyCL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void Display();
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T no,int ipos);
        void DeleteAtPos(int ipos);
         int Addition();
         int Frequency(T no);
        int EvenCount();
        int OddCount();
        int Maximum();
        int Minimum();
};
template <class T>
SinglyCL<T>::SinglyCL()
{
    first = NULL;
    last = NULL;
    Count = 0;
}
template <class T>
void SinglyCL::InsertFirst(T no)
{
 struct node<T> * newn = NULL;

    newn = new struct node<T>;   
    newn->data = no;
    newn->next = NULL;

    if((first == NULL)&&(last == NULL))   // if(Count == 0)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    last->next=first;
    Count++;   
}
template <class T>
void SinglyCL<T>::InsertLast(T no)
{
    struct node<T> * newn = NULL;

    newn = new struct node<T>;   
    newn->data = no;
    newn->next = NULL;

    if((first == NULL)&&(last == NULL))   // if(Count == 0)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next =newn;
        last = newn;
    }
    last->next=first;
    Count++;   
}

template <class T>
void SinglyCL<T>::Display()
{
    struct node<T> * temp = first;
    cout<<"Elements of the linkedlist are :\n";

    if((first != NULL)&&(last != NULL))
    {
        do
        {
            cout<<"| "<<temp->data<<"| <-> ";
            temp=temp->next;
        }while(temp != first);
        cout<<" ";
    }
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if((first == NULL)&&(last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        first=NULL;
        free(last);
        last=NULL;
    }
    else
    {
        first=first->next;
        free((last)->next);
        last->next=first;
    }
    Count--;
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
     if((first == NULL)&&(last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        first=NULL;
        free(last);
        last=NULL;
    }
    else
    {
       struct node<T> * temp = first;
       while(temp->next->next != first)
       {
        temp=temp->next;
       }
       last=temp;
       free(temp->next);
       last->next=first;
    }
    Count--;
}

template <class T>
int SinglyCL<T>::CountNode()
{
    return Count;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T no,int ipos)
{
    int size=0,i=0;
    size=CountNode();

    struct node<T> * newn=NULL;
    newn=new struct node<T>;
    newn->data=no;
    newn->next=NULL;

    struct node<T> * temp=first;

    if((ipos < 1)||(ipos > size+1))
    {
        cout<<"Invalid Parameter\n";
        return;
    }
    else if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == size+1)
    {
        InsertLast(no);
    }
    else
    {
        for(i=1;i<ipos-1;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
    }
    Count++;
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int ipos)
{
    int size=0,i=0;
    size=CountNode();

    struct node<T> * temp=first;

    if((ipos < 1)||(ipos > size))
    {
        cout<<"Invalid Parameter\n";
        return;
    }
    else if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == size)
    {
        DeleteLast();
    }
    else
    {
        for(i=1;i<ipos-1;i++)
        {
            temp=temp->next;
        }
        struct node<T> * target=temp->next;
        temp->next=temp->next->next;
        free(target);
    }
    Count--;
}
template <class T>
int SinglyCL<T>::Addition()
{
    int iSum=0;
    struct node<T> * temp = first;

    if((first != NULL)&&(last != NULL))
    {
        do
        {
            iSum=iSum+temp->data;
            temp=temp->next;
        }while(temp != first);
    }
    return iSum;
}

template <class T>
int SinglyCL<T>::EvenCount()
{
     int iCnt=0;
    struct node<T> * temp = first;

    if((first != NULL)&&(last != NULL))
    {
        do
        {
            if(temp->data % 2 == 0)
            {
                iCnt++;
            }
          
            temp=temp->next;
        }while(temp != first);
    }
    return iCnt;
}


template <class T>
int SinglyCL<T>::OddCount()
{
     int iCnt=0;
    struct node<T> * temp = first;

    if((first != NULL)&&(last != NULL))
    {
        do
        {
            if(temp->data % 2 != 0)
            {
                iCnt++;
            }
          
            temp=temp->next;
        }while(temp != first);
    }
    return iCnt;
}

template <class T>
int SinglyCL<T>::Maximum()
{
    struct node<T> * temp = first;
    int iMax=temp->data;

    if((first != NULL)&&(last != NULL))
    {
        do
        {
            if(iMax < temp->data)
            {
                iMax=temp->data;
            }
          
            temp=temp->next;
        }while(temp != first);
    }
    return iMax;
}

template <class T>
int SinglyCL<T>::Minimum()
{
     struct node<T> * temp = first;
    int iMin=temp->data;
    
    if((first != NULL)&&(last != NULL))
    {
        do
        {
            if(iMin > temp->data)
            {
                iMin=temp->data;
            }
          
            temp=temp->next;
        }while(temp != first);
    }
    return iMin;
}
template <class T>
int SinglyCL<T>::Frequency(T no)
{
     struct node<T> * temp = first;
    int iCnt=0;
    
    if((first != NULL)&&(last != NULL))
    {
        do
        {
            if(temp->data == no)
            {
                iCnt++;
            }
          
            temp=temp->next;
        }while(temp != first);
    }
    return iCnt;
}
int main()
{
   int i;  
    cout<<"SinglyCL of integer type:"<<"\n";
    cout<<"SinglyCL of float type:"<<"\n";
    cout<<"SinglyCL of double type:"<<"\n";
    cout<<"SinglyCL of character type:"<<"\n";

    cout<<"Enter your choise :"<<"\n";
    cin>>i;

    if(i == 1)
    {
    SinglyCL <int>obj;

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
         SinglyCL <float>obj;

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
        SinglyCL <double>obj;

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
    SinglyCL <char>obj;

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
       cout<<"Invalid Choise"<<"\n";
   }
      iRet = obj.Addition();
    cout<<"\nAddition of all nodes are : "<<iRet<<"\n";

    iRet = obj.EvenCount();
    cout<<"Number of Even elements in the linked list are : "<<iRet<<"\n";

    iRet = obj.OddCount();
    cout<<"Number of Odd elements in the linked list are : "<<iRet<<"\n";

    iRet = obj.Maximum();
    cout<<" Maximum element in the linked list are : "<<iRet<<"\n";

    iRet = obj.Minimum();
    cout<<"Minimum elements in the linked list are : "<<iRet<<"\n";

     int ivalue=0;
    cout<<"Enter the number that you want to find frequency:";
    cin>>ivalue;
  
    iRet = obj.Frequency(ivalue);
    cout<<"Frequency of that node are : "<<iRet<<"\n"; 
}
