#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////
//
//  Datastructure Name: Singly Linear LinkedList
//  Description: Generic Singly Linear LinkedList
//  Input: Generic Variables
//  Output: Singly Linear LinkedList
//  Author: Ajinkya Deshmane
//  Date: 05 - 07 - 2024
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
struct nodeSL
{
    T data;
    struct nodeSL *next;
};

template<class T>
class SinglyLL
{
    private:
        struct nodeSL<T>* First;
        T iCount;
    public:
        SinglyLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template<class T>
SinglyLL<T>::SinglyLL()
{
    cout<<"Inside Constructor\n";
    First = NULL;
    iCount = 0;
}

template<class T>
void SinglyLL<T>::Display()
{
    struct nodeSL<T>* temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<"|-> ";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

template<class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template<class T>
void SinglyLL<T>::InsertFirst(
                                T No
                                )
{
    struct nodeSL<T>* newn = NULL;

    newn = new nodeSL<T>;    // malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template<class T>
void SinglyLL<T>::InsertLast(
                                T No
                                )
{
    struct nodeSL<T>* newn = NULL;
    struct nodeSL<T>* temp = First;

    newn = new nodeSL<T>;    // malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    iCount++;
}

template<class T>
void SinglyLL<T>::InsertAtPos(
                                T No,
                                int iPos
                                )
{
    struct nodeSL<T>* newn = NULL;
    int i = 0;
    struct nodeSL<T>* temp;

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else 
    {
        temp = First;
        
        newn = new struct nodeSL<T>;
        newn->data = No;
        newn->next = NULL;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp -> next = newn;
        iCount++;
    }
}

template<class T>
void SinglyLL<T>::DeleteFirst()
{
    struct nodeSL<T>* temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First -> next;
        delete temp;
    }
    iCount--;
}

template<class T>
void SinglyLL<T>::DeleteLast()
{
    struct nodeSL<T>* temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp ->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template<class T>
void SinglyLL<T>::DeleteAtPos(
                                int iPos
                                )
{
    int i = 0;
    struct nodeSL<T>* temp1;
    struct nodeSL<T>* temp2;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else 
    {
        temp1 = First;

        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }    
}

/////////////////////////////////////////////////////////////////////////////
//
//  Datastructure Name: Doubly Linear LinkedList
//  Description: Generic Doubly Linear LinkedList
//  Input: Generic Variables
//  Output: Doubly Linear LinkedList
//  Author: Ajinkya Deshmane
//  Date: 05 - 07 - 2024
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
struct nodeDL
{
    T iData;
    struct nodeDL *Next;
    struct nodeDL *Prev;
};

template <class T>
class DoublyLL
{
    private:
        int iCount;
        nodeDL<T> *First;
        nodeDL<T> *Last;

    public:

        DoublyLL();

        void Display();
        int Count();

        void InsertFirst(T iNo);
        void InsertLast(T iNo);
        void InsertAtPos(T iNo, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template<class T>
DoublyLL<T> :: DoublyLL()
{
    iCount = 0;
    First = NULL;
    Last = NULL;
}

template <class T>
void DoublyLL<T> :: Display()
{
    nodeDL<T> *temp = First;

    cout<<"<=> ";
    while(temp != NULL)
    {
        cout<<"| "<<temp->iData<<" | <=> ";
        temp = temp->Next;
    }
    cout<<endl;
}

template <class T>
int DoublyLL<T> :: Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T> :: InsertFirst(
                                T iNo
                                )
{
    nodeDL<T> *newn = new nodeDL<T>();

    newn->iData = iNo;
    newn->Next = NULL;
    newn->Prev = NULL;

    if(First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->Next = First;
        First->Prev = newn;
        First = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T> :: InsertLast(
                                T iNo
                                )
{
    nodeDL<T> *newn = new nodeDL<T>();

    newn->iData = iNo;
    newn->Next = NULL;
    newn->Prev = NULL;

    if(First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->Prev = Last;
        Last->Next = newn;
        Last = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T> :: InsertAtPos(
                                T iNo,
                                int iPos
                                )
{
    nodeDL<T> *newn = NULL;
    nodeDL<T> *temp = NULL;
    int i = 0;
    
    if(iPos < 1 || iPos > iCount + 1)
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        newn = new nodeDL<T>();

        newn->iData = iNo;
        newn->Next = NULL;
        newn->Prev = NULL;

        temp = First;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->Next;
        }

        newn->Next = temp->Next;
        newn->Prev = temp;
        newn->Next->Prev = newn;
        temp->Next = newn;

        iCount++;
    }
}

template <class T>
void DoublyLL<T> :: DeleteFirst()
{
    nodeDL<T> *temp = NULL;

    if(First == NULL && Last == NULL)
    {
        cout<<"LinkedList is empty"<<endl;
        return;
    }
    else if(First == Last)
    {
        free(First);
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->Next;
        free(First->Prev);
        First->Prev = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T> :: DeleteLast()
{
    nodeDL<T> *temp = NULL;

    if(First == NULL && Last == NULL)
    {
        cout<<"LinkedList is empty"<<endl;
        return;
    }
    else if(First == Last)
    {
        free(First);
        First = NULL;
        Last = NULL;
    }
    else
    {
        Last = Last->Prev;
        free(Last->Next);
        Last->Next = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T> :: DeleteAtPos(
                                int iPos
                                )
{
    nodeDL<T> *temp = NULL;
    int i = 0;
   
    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->Next;
        }

        temp->Next = temp->Next->Next;
        free(temp->Next->Prev);
        temp->Next->Prev = temp;

        iCount--;
    }
}

/////////////////////////////////////////////////////////////////////////////
//
//  Datastructure Name: Singly Circular LinkedList
//  Description: Generic Singly Circular LinkedList
//  Input: Generic Variables
//  Output: Singly Circular LinkedList
//  Author: Ajinkya Deshmane
//  Date: 05 - 07 - 2024
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
struct nodeSC
{
    T iData;
    class nodeSC *Next;
};

template <class T>
class SinglyCL
{
    private:
        int iCount;
        class nodeSC<T> *First;

    public:

        SinglyCL();
        
        void Display();
        int Count();
        
        void InserFirst(T iNo);
        void InsertLast(T iNo);
        void InsertAtPos(T iNo, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
SinglyCL<T> :: SinglyCL()
{
    iCount = 0;
    First = NULL;
}

template <class T>
void SinglyCL<T> :: Display()
{
    nodeSC<T> *temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->iData<<" | -> ";
        temp = temp->Next;
    }
    cout<<"NULL"<<endl;
}

template <class T>
int SinglyCL<T> :: Count()
{
    return iCount;
}

template <class T>
void SinglyCL<T> :: InserFirst(
                                T iNo
                                )
{
    nodeSC<T> *newn = NULL;

    newn = (nodeSC<T> *)malloc(sizeof(nodeSC<T>));

    newn->iData = iNo;
    newn->Next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->Next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
void SinglyCL<T> :: InsertLast(
                                T iNo
                                )
{
    nodeSC<T> *newn = NULL;
    nodeSC<T> *temp = NULL;

    newn = (nodeSC<T> *)malloc(sizeof(nodeSC<T>));

    newn->iData = iNo;
    newn->Next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;

        while(temp->Next != NULL)
        {
            temp = temp->Next;
        }

        temp->Next = newn;
    }
    iCount++;
}

template <class T>
void SinglyCL<T> :: InsertAtPos(
                                T iNo,
                                int iPos
                                )
{
    nodeSC<T> *newn = NULL;
    nodeSC<T> *temp = NULL;
    int i = 0;

    if(iPos < 1 || iPos > iCount + 1)
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(iPos == 1)
    {
        InserFirst(iNo);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        temp = First;
        newn = (nodeSC<T> *)malloc(sizeof(nodeSC<T>));

        newn->iData = iNo;
        newn->Next = NULL;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->Next;
        }

        newn->Next = temp->Next;
        temp->Next = newn;

        iCount++;
    }
}

template <class T>
void SinglyCL<T> :: DeleteFirst()
{   
    nodeSC<T> *temp = NULL;

    if(First == NULL)
    {
        cout<<"LinkedList is empty"<<endl;
        return;
    }
    else if(First->Next == NULL)
    {
        free(First);
        First = NULL;
    }
    else
    {
        temp = First->Next;
        free(First);
        First = temp;
    }
    iCount--;
}

template <class T>
void SinglyCL<T> :: DeleteLast()
{   
    nodeSC<T> *temp = NULL;

    if(First == NULL)
    {
        cout<<"LinkedList is empty"<<endl;
        return;
    }
    else if(First->Next == NULL)
    {
        free(First);
        First = NULL;
    }
    else
    {
        temp = First;

        while(temp->Next->Next != NULL)
        {
            temp = temp->Next;
        }

        free(temp->Next);
        temp->Next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyCL<T> :: DeleteAtPos(
                                int iPos
                                )
{
    nodeSC<T> *temp1 = NULL;
    nodeSC<T> *temp2 = NULL;
    int i = 0;

    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;

        for(i = 1; i < iPos - 1; i++)
        {
            temp1 = temp1->Next;
        }

        temp2 = temp1->Next;
        temp1->Next = temp1->Next->Next;

        iCount--;
    }
}

/////////////////////////////////////////////////////////////////////////////
//
//  Datastructure Name: Doubly Circular LinkedList
//  Description: Generic Doubly Circular LinkedList
//  Input: Generic Variables
//  Output: Doubly Circular LinkedList
//  Author: Ajinkya Deshmane
//  Date: 05 - 07 - 2024
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
struct nodeDC
{
    T Data;
    struct nodeDC *next;
    struct nodeDC *prev;
};

template <class T>
class DoublyCL
{
    private:
        struct nodeDC<T> * First;
        struct nodeDC<T> * Last;
        int iCount;

    public:
        DoublyCL();

        void Display();
        int Count();

        void InsertFirst(T iNo);
        void InsertLast(T iNo);
        void InsertAtPos(T iNo,  int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
DoublyCL<T> :: DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T> :: Display()
{
    if(First == NULL && Last == NULL)
    {
        cout<<"LinkedList Is Empty"<<endl;
        return;
    }

    cout<<"<=> ";
    do
    {
        cout<<"| "<<First->Data<<" | <=> ";
        First = First->next;
    } while (First != Last->next);

    cout<<endl;
}

template <class T>
int DoublyCL<T> :: Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T> :: InsertFirst(
                                T iNo
                                )
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn->Data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    iCount++;
    Last->next = First;
    First->prev = Last;
}

template <class T>
void DoublyCL<T> :: InsertLast(
                                T iNo
                                )
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn->Data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        newn->prev = Last;
        Last = newn;
    }
    iCount++;
    Last->next = First;
    First->prev = Last;
}

template <class T>
void DoublyCL<T> :: InsertAtPos(
                                T iNo,
                                int iPos
                                )
{
    struct nodeDC<T> * temp = NULL;
    struct nodeDC <T>*  newn = NULL;
    int i = 0;

    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        newn = new nodeDC<T>;
        newn->Data = iNo;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->next->prev = newn;

        newn->prev = temp;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void DoublyCL<T> :: DeleteFirst()
{
    if(First == NULL && Last == NULL)   
    {
        return;
    }
    else if(First == Last)              
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else                                
    {
        First = First->next;
        delete Last->next;

        First->prev = Last;
        Last->next = First;
    }
    iCount--;
}

template <class T>
void DoublyCL<T> :: DeleteLast()
{
    if(First == NULL && Last == NULL)   
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        Last = Last->prev;
        delete First->prev;
        Last->next = First;
        First->prev = Last;
    }
    iCount--;
}

template <class T>
void DoublyCL<T> :: DeleteAtPos(
                                int iPos
                                )
{
    struct nodeDC<T> * temp = NULL;
    int i = 0;

    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

/////////////////////////////////////////////////////////////////////////////
//
//  Datastructure Name: Stack
//  Description: Implementation Of Generic Stack
//  Input: Generic Variables
//  Output: Stack
//  Author: Ajinkya Deshmane
//  Date: 05 - 07 - 2024
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
struct nodeST
{
    T iData;
    struct nodeST<T>* Next;
};

template <class T>
class Stack
{
    private:
        int iCount;
        nodeST<T> *First;

    public:
        
        Stack();

        void Display();
        int Count();

        void Push(T iNo);
        T Pop();
};

template <class T>
Stack<T> :: Stack()
{
    iCount = 0;
    First = NULL;
}

template <class T>
void Stack<T> :: Display()
{
    struct nodeST<T> *temp = NULL;

    temp = First;

    while(temp != NULL)
    {
        cout<<temp->iData<<endl;
        temp = temp->Next;
    }
} 

template <class T>
int Stack<T> :: Count()
{
    return iCount;
}

template <class T>
void Stack<T> :: Push(
                        T iNo
                        )
{
    struct nodeST<T> *newn = NULL;

    newn = (nodeST<T> *)malloc(sizeof(nodeST<T>));

    newn->iData = iNo;
    newn->Next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->Next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
T Stack<T> :: Pop()
{
    nodeST<T> *temp = NULL;
    T iReturn = 0;

    if(First == NULL)
    {
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    else if(First->Next == NULL)
    {
        iReturn = First->iData;
        free(First);
        First = NULL;
    }
    else
    {
        temp = First->Next;
        iReturn = First->iData;
        free(First);
        First = temp;
    }
    iCount--;

    return iReturn;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Datastructure Name: Queue
//  Description: Implemetation Of Generic Queue
//  Input: Generic Variables
//  Output: Generic Queue
//  Author: Ajinkya Deshmane
//  Date: 05 - 07 - 2024
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
struct nodeQU
{
    T iData;
    nodeQU<T> *Next;
};

template <class T>
class Queue
{
    private:
        int iCount;
        nodeQU<T> *First;
    
    public:

        Queue();

        void Display();
        int Count();

        void EnQueue(T iNo);
        T DeQueue();
};

template <class T>
Queue<T> :: Queue()
{
    iCount = 0;
    First = NULL;
}

template <class T>
void Queue<T> :: Display()
{
    struct nodeQU<T> *temp = NULL;

    temp = First;

    while(temp != NULL)
    {
        cout<<temp->iData<<"\t";
        temp = temp->Next;
    }
    cout<<endl;
}

template <class T>
int Queue<T> :: Count()
{
    return iCount;
}

template <class T>
void Queue<T> :: EnQueue(
                            T iNo
                            )
{
    nodeQU<T> *newn = NULL;
    nodeQU<T> *temp = NULL;

    newn = (nodeQU<T> *)malloc(sizeof(nodeQU<T>));

    newn->iData = iNo;
    newn->Next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;

        while(temp->Next != NULL)
        {
            temp = temp->Next;
        }

        temp->Next = newn;
    }
    iCount++;
}

template <class T>
T Queue<T> :: DeQueue()
{
    nodeQU<T> *temp = NULL;
    T iReturn = 0;

    if(First == NULL)
    {
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    else if(First->Next == NULL)
    {
        iReturn = First->iData;
        free(First);
        First = NULL;
    }
    else
    {
        temp = First->Next;
        iReturn = First->iData;
        free(First);
        First = temp;
    }
    iCount--;

    return iReturn;
}

/////////////////////////////////////////////////////////////////////////////
//
//  MAIN FUNCTION
//  Author: Ajinkya Deshmane
//  Date: 05 - 07 - 2024
//
/////////////////////////////////////////////////////////////////////////////

int main()
{
    
    return 0;
}