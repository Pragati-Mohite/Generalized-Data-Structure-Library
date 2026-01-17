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

    return 0;
}