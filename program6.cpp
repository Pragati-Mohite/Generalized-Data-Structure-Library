///////////////////////////////////////////////////////////////
//          Generlised Data Structure Liabrary
///////////////////////////////////////////////////////////////

/*
-------------------------------------------------------------------------------------------
    Type                Name of class for node          Name of class for Functionality
-------------------------------------------------------------------------------------------
    Singly Linear       SinglyLLLnode                   SinglyLLL

    Singly Circular     SinglyCLLnode                   SinglyCLL

    Doubly Linear       DoublyLLLnode                   DoublyLLL

    Doubly Circular     DoublyCLLnode                   DoublyCLL
-------------------------------------------------------------------------------------------

*/

#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////
//      Singly linear linkedlist using generic approach
///////////////////////////////////////////////////////////////

#pragma pack(1)

template <class T>
class SinglyLLLnode
{
    public:
        T data;
        SinglyLLLnode<T> *next;

        SinglyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class SinglyLLL
{
    private:             
        SinglyLLLnode<T> * first;
        int iCount;

    public:
        SinglyLLL();

        void InsertFirst(T);     
        void InsertLast(T);
        
        void DeleteFirst();
        void DeleteLast();

        void Display();
        int Count();
                
        void InsertAtPos(T ,int );
        void DeleteAtPos(int );
};

template <class T>
SinglyLLL<T> :: SinglyLLL()
{
    cout<<"Object of singly LLL gets created..\n";
    this->first = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Function Name :  InsertFirst
//  Input         :  Data of node
//  Output        :  Nothing
//  Description   :  Used to insert node at first position
//  Author        :  Pragati Dattatray Mohite
//  Date          :  06/01/2026
//
//////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: InsertFirst(T no)     
{
    SinglyLLLnode<T> * newn = NULL;
    newn = new SinglyLLLnode<T>(no);

    newn -> next = this->first;
    this->first = newn;
    
    this->iCount++;
}

//////////////////////////////////////////////////////////////////////
//
//  Function Name :  InsertLast
//  Input         :  Data of node
//  Output        :  Nothing
//  Description   :  Used to insert node at Last position
//  Author        :  Pragati Dattatray Mohite
//  Date          :  06/01/2026
//
//////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: InsertLast(T no)
{
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * newn = NULL;
    newn = new SinglyLLLnode<T> (no);

    if(this->iCount == 0)           
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    this->iCount++;
}

//////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteFirst
//  Input         :  Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at first position
//  Author        :  Pragati Dattatray Mohite
//  Date          :  06/01/2026
//
//////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: DeleteFirst()
{
    SinglyLLLnode<T> * temp = NULL;
    if(this->first == NULL)
    {
        return;
    }
    else if(this->first -> next == NULL)        
    {
        delete(this->first);
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        this->first = this->first -> next;
        delete(temp);
    }
    this->iCount--;
}

//////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Pragati Dattatray Mohite
//  Date          :  06/01/2026
//
//////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: DeleteLast()
{
    SinglyLLLnode<T> * temp = NULL;
    if(this->first == NULL)
    {
        return;
    }
    else if(this->first -> next == NULL)        
    {
        delete(this->first);
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        delete(temp -> next);
        temp -> next = NULL;
    }
    this->iCount--;
}

//////////////////////////////////////////////////////////////////////
//
//  Function Name :  Display
//  Input         :  Data of node
//  Output        :  Nothing
//  Description   :  Used to nodes in Linked List
//  Author        :  Pragati Dattatray Mohite
//  Date          :  06/01/2026
//
//////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: Display()
{
    SinglyLLLnode<T> * temp = NULL;
    int iCnt = 0;

    temp = this->first;
    for(iCnt = 1 ; iCnt <= this->iCount ; iCnt++)           
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

//////////////////////////////////////////////////////////////////////
//
//  Function Name :  Count
//  Input         :  Data of node
//  Output        :  Nothing
//  Description   :  Used to count the nodes in Linked List
//  Author        :  Pragati Dattatray Mohite
//  Date          :  06/01/2026
//
//////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLLL<T> :: Count()
{
    return this->iCount;
}

//////////////////////////////////////////////////////////////////////
//
//  Function Name :  InsertAtPos
//  Input         :  Data of node
//  Output        :  Nothing
//  Description   :  Used to Insert node at specified position
//  Author        :  Pragati Dattatray Mohite
//  Date          :  06/01/2026
//
//////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: InsertAtPos(T no ,int pos)
{
    SinglyLLLnode<T> * temp = NULL;
    int iCnt = 0;

    SinglyLLLnode<T> * newn = NULL;

    if(pos< 1 || pos > this->iCount+1)
    {
        cout<<"Invalid Position\n";
        return;
    }
    if(pos==1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyLLLnode<T>(no);

        temp = this->first;
        for(iCnt = 1;iCnt < pos -1 ; iCnt++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn;
        
        this->iCount++;
    }
}

//////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteAtPos
//  Input         :  Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at specified position
//  Author        :  Pragati Dattatray Mohite
//  Date          :  06/01/2026
//
//////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: DeleteAtPos(int pos)
{
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * target = NULL;
    int iCnt = 0;

    if(pos< 1 || pos > this->iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }
    if(pos==1)
    {
        this->DeleteFirst();
    }
    else if(pos == iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
        for(iCnt = 1; iCnt < pos-1 ;iCnt++)
        {
            temp = temp -> next;
        }
        target = temp -> next;
        temp -> next = target -> next;
        delete(target);
        
        this->iCount--;
    }
}

///////////////////////////////////////////////////////////////
//      Doubly linear linkedlist using generic approach
///////////////////////////////////////////////////////////////

#pragma pack(1)

template <class T>
class DoublyLLLnode
{
    public:
        T data;
        DoublyLLLnode<T> *next;
        DoublyLLLnode<T> *prev;

        DoublyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template <class T>
class DoublyLLL
{
    private:
        DoublyLLLnode<T> * first;
        int iCount;

    public:
        DoublyLLL();

        void InsertFirst(T);
        void InsertLast(T);

        void DeleteFirst();
        void DeleteLast();

        void InsertAtPos(T,int);
        void DeleteAtPos(int);

        void Display();
        int Count();
};

template <class T>
DoublyLLL<T>::DoublyLLL()
{
    cout<<"Object of Doubly LLL gets created..\n";
    this->first = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Function Name :  InsertFirst
//  Input         :  Data of node
//  Output        :  Nothing
//  Description   :  Used to insert node at first position
//  Author        :  Pragati Dattatray Mohite
//  Date          :  06/01/2026
//
//////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T>:: InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    this->iCount++;
}

//////////////////////////////////////////////////////////////////////
//
//  Function Name :  InsertLast
//  Input         :  Data of node
//  Output        :  Nothing
//  Description   :  Used to insert node at Last position
//  Author        :  Pragati Dattatray Mohite
//  Date          :  06/01/2026
//
//////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T>:: InsertLast(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        DoublyLLLnode<T> * temp = NULL;

        temp = this->first;
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp->next = newn;
        newn -> prev = temp;
    }
    this->iCount++;

}

//////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteFirst
//  Input         :  Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at first position
//  Author        :  Pragati Dattatray Mohite
//  Date          :  06/01/2026
//
//////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T>:: DeleteFirst()
{
    if(this->first == NULL)              
    {
        return;
    }
    else if(this->first->next == NULL)  
    {
        delete(this->first);
        this->first = NULL;
    }
    else                                
    {
        this->first = this->first->next;
        delete(this->first->prev);
        this->first->prev = NULL;
    }
    this->iCount--;
}

//////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Pragati Dattatray Mohite
//  Date          :  06/01/2026
//
//////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: DeleteLast()
{
    if(this->first == NULL)              
    {
        return;
    }
    else if(this->first->next == NULL)  
    {
        delete(this->first);
        this->first = NULL;
    }
    else                                
    {
        DoublyLLLnode<T> * temp = NULL;
        temp = this -> first;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }
        delete(temp->next);
        temp->next = NULL;
    }
    this->iCount--;
}

//////////////////////////////////////////////////////////////////////
//
//  Function Name :  InsertAtPos
//  Input         :  Data of node
//  Output        :  Nothing
//  Description   :  Used to Insert node at specified position
//  Author        :  Pragati Dattatray Mohite
//  Date          :  06/01/2026
//
//////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: InsertAtPos(T no,int pos)
{
    DoublyLLLnode<T> * temp = NULL;
    DoublyLLLnode<T> * newn = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount+1)
    {
        cout<<"Invalid Position\n";
        return;
    }
    if(pos==1)
    {
        InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1 ; iCnt< pos-1 ; iCnt++)
        {
            temp = temp ->next;
        }
        newn -> next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}

//////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteAtPos
//  Input         :  Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at specified position
//  Author        :  Pragati Dattatray Mohite
//  Date          :  06/01/2026
//
//////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: DeleteAtPos(int pos)
{
    DoublyLLLnode<T> * temp = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }
    if(pos==1)
    {
        DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1 ; iCnt< pos-1 ; iCnt++)
        {
            temp = temp ->next;
        }
        temp->next = temp->next-> next;
        delete(temp->next->prev);
        temp->next->prev = temp;

        this->iCount--;
    }
}

//////////////////////////////////////////////////////////////////////
//
//  Function Name :  Display
//  Input         :  Data of node
//  Output        :  Nothing
//  Description   :  Used to nodes in Linked List
//  Author        :  Pragati Dattatray Mohite
//  Date          :  06/01/2026
//
//////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: Display()
{
    DoublyLLLnode<T> * temp = NULL;
    temp = this->first;

    cout<<"NULL<=>";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

//////////////////////////////////////////////////////////////////////
//
//  Function Name :  Count
//  Input         :  Data of node
//  Output        :  Nothing
//  Description   :  Used to count the nodes in Linked List
//  Author        :  Pragati Dattatray Mohite
//  Date          :  06/01/2026
//
//////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLLL<T> :: Count()
{
    return this->iCount;
}

///////////////////////////////////////////////////////////////
//      Singly Circular linkedlist using generic approach
///////////////////////////////////////////////////////////////

#pragma pack(1)

template <class T>
class SinglyCLLnode
{
    public:
        T data;
        SinglyCLLnode<T> *next;

        SinglyCLLnode(T no)
        {
            data = no;
            next = NULL;
        }
};

template <class T>
class SinglyCLL
{
    private:
        SinglyCLLnode<T> * first;
        SinglyCLLnode<T> * last;
        int iCount;

    public:
        SinglyCLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void DeleteAtPos(int pos);
        void InsertAtPos(T no, int pos);
};

template <class T>
SinglyCLL<T>::SinglyCLL()
{
    cout<<"Object of Singly CLL gets created..\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Function Name :  InsertFirst
//  Input         :  Data of node
//  Output        :  Nothing
//  Description   :  Used to insert node at first position
//  Author        :  Pragati Dattatray Mohite
//  Date          :  07/01/2026
//
//////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    SinglyCLLnode<T> * newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if(first == NULL && last == NULL)   
    {
        first = newn;
        last = newn;

        last->next = first;
    }
    else
    {
        newn->next = first;
        first = newn;

        last->next = first;
    }

    iCount++;
}

//////////////////////////////////////////////////////////////////////
//
//  Function Name :  InsertLast
//  Input         :  Data of node
//  Output        :  Nothing
//  Description   :  Used to insert node at Last position
//  Author        :  Pragati Dattatray Mohite
//  Date          :  07/01/2026
//
//////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
    SinglyCLLnode<T> * newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if(first == NULL && last == NULL)   
    {
        first = newn;
        last = newn;

        last->next = first;
    }
    else
    {
        last->next = newn;
        last = newn;

        last->next = first;
    }

    iCount++;
}

//////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteFirst
//  Input         :  Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at first position
//  Author        :  Pragati Dattatray Mohite
//  Date          :  07/01/2026
//
//////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;

        first = NULL;
        last = NULL;
    }
    else
    {
        first = first -> next;
        delete last->next;

        last->next = first;
    }
    iCount--;
}

//////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Pragati Dattatray Mohite
//  Date          :  07/01/2026
//
//////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DeleteLast()
{
    SinglyCLLnode<T> * temp = NULL;

    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;

        first = NULL;
        last = NULL;
    }
    else
    {
        temp = first;

        while(temp -> next != last)
        {
            temp = temp -> next;
        }

        delete last;
        last = temp;

        last->next = first;
    }
    iCount--;
}

//////////////////////////////////////////////////////////////////////
//
//  Function Name :  Display
//  Input         :  Data of node
//  Output        :  Nothing
//  Description   :  Used to nodes in Linked List
//  Author        :  Pragati Dattatray Mohite
//  Date          :  07/01/2026
//
//////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::Display()
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    else
    {
        SinglyCLLnode<T> * temp = first;
        do
        {
            cout<<"| "<<temp->data<<" | -> ";
            temp = temp -> next;
        } while (temp != last ->next);
    }    
    cout<<"\n";
}

//////////////////////////////////////////////////////////////////////
//
//  Function Name :  Count
//  Input         :  Data of node
//  Output        :  Nothing
//  Description   :  Used to count the nodes in Linked List
//  Author        :  Pragati Dattatray Mohite
//  Date          :  07/01/2026
//
//////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCLL<T>::Count()
{
    return iCount;
}


/////////////////////////////////////// End of Liabrary ///////////////////////////////////////
int main()
{
    SinglyLLL<int> *Obj = new SinglyLLL<int>;
    int iRet = 0;

    Obj->InsertFirst(51);
    Obj->InsertFirst(21);
    Obj->InsertFirst(11);

    Obj->Display();
    iRet = Obj->Count();
    cout<<"Number of Nodes are : "<<iRet<<" \n";

    Obj->InsertLast(101);
    Obj->InsertLast(111);
    Obj->InsertLast(121);
    
    Obj->Display();
    iRet = Obj->Count();
    cout<<"Number of Nodes are : "<<iRet<<" \n";

    Obj->DeleteFirst();

    Obj->Display();       

    iRet = Obj->Count();
    cout<<"Number of Nodes are : "<<iRet<<" \n";

    Obj->DeleteLast();

    Obj->Display();
    iRet = Obj->Count();
    cout<<"Number of Nodes are : "<<iRet<<" \n";

    Obj->InsertAtPos(105 ,4);
    Obj->Display();
    iRet = Obj->Count();
    cout<<"Number of Nodes are : "<<iRet<<" \n";

    Obj->DeleteAtPos(4);
    Obj->Display();
    iRet = Obj->Count();
    cout<<"Number of Nodes are : "<<iRet<<" \n";

    delete Obj;

////////////////////////////////////////////////////////////////////////////////////
    DoublyLLL<char> *dobj = new DoublyLLL<char>();

    dobj->InsertFirst('A');
    dobj->InsertFirst('B');
    dobj->InsertFirst('C');

    dobj->Display();
    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    dobj->InsertLast('X');
    dobj->InsertLast('Y');
    dobj->InsertLast('Z');

    dobj->Display();
    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteFirst();
    dobj->Display();
    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteLast();
    dobj->Display();
    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    dobj->InsertAtPos('$',4);

    dobj->Display();
    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteAtPos(4);

    dobj->Display();
    cout<<"Number of elements are : "<<dobj->Count()<<"\n";
    delete dobj;

////////////////////////////////////////////////////////////////////////////

    SinglyCLL<int> *sobj = new SinglyCLL<int>();

    sobj->InsertFirst(51);
    sobj->InsertFirst(21);
    sobj->InsertFirst(11);

    sobj->Display();    
    iRet = sobj->Count();
    cout<<"Number of elements are : "<<iRet<<"\n";
    
    sobj->InsertLast(101);
    sobj->InsertLast(111);
    sobj->InsertLast(121);

    sobj->Display();    
    iRet = sobj->Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    sobj->DeleteFirst();

    sobj->Display();    
    iRet = sobj->Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    sobj->DeleteLast();

    sobj->Display();    
    iRet = sobj->Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    delete sobj;
    return 0;
}