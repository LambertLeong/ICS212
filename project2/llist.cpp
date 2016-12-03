/*****************************************************************
//
// NAME: 			Lambert Leong
//
// HOMEWORK:		project1
//
// CLASS: 			ICS 212
//
// INSTRUCTOR: 		Ravi Narayan
//
// DATE: 			JULY 30, 2016
//
// FILE: 			llist.h
//
// DESCRIPTION: 	contains llist functions
//
//****************************************************************/

#include "project2header.h"

/*****************************************************************
//
// Function name: readfile
//
// DESCRIPTION: reads records from a .txt file and stores them in 
//              an array of accounts.  Function assumes that record format
//              is as follows:
                    acount number
                    name
                    address!
                    year of birth
//
//              the '!' after address is used to indicate the end of 
//              the address input.  Function also assumes records are complete
// Parameters: void
//
// Return values: void
//
//****************************************************************/

int llist::readfile()
{
    ifstream file;
    
    int anum, year, i, accountfield, check1, check2, amount, sucess;
    char accounum [20], name [25], address [80], birth[5], c, birth2[4];

    i = 0;
    accountfield = 0;
    check1 = 0;
    check2 = 0;
    c = 0;
	amount = 0;
    sucess = 0;
    
    birth[0]='\0';
	accounum[0] = '\0';
    
	#ifdef debug
        cout<<"\n********DEBUG MODE********\n";
        cout<<"DEBUG: calling function readFile"<<endl;
        cout<<"***************************\n\n";
	#endif
    file.open(filename);
    if(file == NULL)
    {
        cout<<"File does not exists to read "<<endl;
    }
    else
    {
        while(!file.eof())
        {
            file.get(c);
            if(accountfield == 0)
            {
                
                if(c < '0' || c > '9'|| c=='\n')
                {
                    accounum[i] = '\0';
                    anum = atoi(accounum);
                    accountfield = 1;
                    i = 0;
                    
                } 
                else
                {
                    accounum[i] = c;
                    i++;
                }
            }
            else if(accountfield == 1)
            {
               if(c == '\n' || i > 23)
                {
                    name[i]='\0';
                    accountfield = 2;
                    i = 0;
                } 
                else
                {
                    name[i]=c;
                    i++;
                } 
            }
            else if(accountfield == 2)
            {
                if(c == '!' || i > 78)
                {
                    address[i]='\0';
                    accountfield = 3;
                    check1=1;
                    i = 0;
                    
                } 
                else
                {
                    address[i] = c;
                    i++;
                } 
            }
            else if(accountfield == 3)
            {
                if(i > 4)
                {
                    year = atoi(birth);
                    amount = addRecord(anum, name, address, year);
                    accountfield = 0;
                    i = 0;
                    accounum[0] = '\0';
                    check2 = 1;
                    sucess =1;
                } 
                else
                {
                    birth[i] = c;
                    i++;
                } 
            }
        }
    }
	birth[0]='\0';
    file.close();
    return sucess;
}

/*****************************************************************
//
// Function name: writefile
//
// DESCRIPTION: writes records to a .txt file from accounts.  It writes them
//              in the order in which they were input(FIFP).
//              Output format is as follows:
                    acount number
                    name
                    address!
                    year of birth
//              the '!' after address is used to indicate the end of 
//              the address input.
// Parameters: void
//
// Return values: void
//
//****************************************************************/

int llist:: writefile( )
{
    ofstream outfile;
    
    struct record *current;
    outfile.open("input.txt" );
    /*outfile.open("output.txt" );*/
    current=start;
    
    #ifdef debug
        cout<<"\n********DEBUG MODE********\n";
        cout<<"DEBUG: calling function writefile"<<endl;
        cout<<"***************************\n\n";
	#endif
    
    while(current != NULL)
    {
        outfile<<current->accountno<<endl<<current->name<<endl<<current->address<<'!'<<endl<<current->yearofbirth<<endl;
        current=current->next;
    }
    
    outfile.close();
}

/***********************************************************************
//
// Function name:   reverse
//
// DESCRIPTION:     reverse the order of the data using recursion
//
// Parameters:      current(*): start pointer
//
// Return values:   rturn(*):   new start pointer   
//
//*********************************************************************/

record * llist::reverse(record * current)
{
    struct record *temp,*next, *rturn;
    
    if (start != NULL)
    {
        rturn = current;
        temp = rturn->next;
        if(current->next == NULL)
        {
            rturn = current;
        }
        else 
        {
            temp = current->next;
            current->next=NULL;
            next = reverse(temp);
            temp->next=current;
            rturn = next;
        }
    }
    else
    {
            rturn = start;
            cout<<"List is empty\n Nothing to reverse\n";
    }
    return rturn;
}

/***********************************************************************
//
// Function name:   cleanup
//
// DESCRIPTION:     frees up all memory from heap that was malloc(ed)
//                  
//
// Parameters:      void
//
// Return values:   void
//
//*********************************************************************/

void llist::cleanup()
{
    struct record *previous, *current, *purge;
    current = start;
    previous = NULL;
	
    #ifdef debug
        cout<<"\n********DEBUG MODE********\n";
        cout<<"Function called: cleanup\n";
        cout<<"***************************\n\n";
    #endif

/*list is empty*/

    if (start == NULL)
    {
        cout<<"List contains no records to clean\n"<<endl;
    }
    else
    {
        while(current != NULL)
        {
            purge = current;
            previous = current;
            current=previous->next;
            delete(purge);
        }
    }
}

/***********************************************************************
//
// Function name:   llist
//
// DESCRIPTION:     llist constructor
//
// Parameters:      void
//
// Return values:   void
//
//*********************************************************************/

llist::llist()
{
    #ifdef debug
        cout<<"\n********DEBUG MODE********\n";
        cout<<"Function called: Default Constructor \n";
        cout<<"***************************\n\n";
    #endif
    start = NULL;
    strcpy(filename, "input.txt");
    readfile();
}

/***********************************************************************
//
// Function name:   llist
//
// DESCRIPTION:     llist constructor
//
// Parameters:      filename(char): name of .txt file      
//
// Return values:   void
//
//*********************************************************************/

llist::llist(char fileName[])
{
    #ifdef debug
        cout<<"\n********DEBUG MODE********\n";
        cout<<"Function called: Constructor(fileName) \n";
        cout<<"***************************\n\n";
    #endif
    start = NULL;
    strcpy(filename, fileName);
    readfile();
}

/***********************************************************************
//
// Function name:   llist
//
// DESCRIPTION:     llist copy constructor
//
// Parameters:      Reference of llist called list     
//
// Return values:   void
//
//*********************************************************************/

llist::llist(const llist &list)
{
    struct record *current;
    start = NULL;
    current = list.start;
    
	
    #ifdef debug
        cout<<"\n********DEBUG MODE********\n";
        cout<<"Function called: Copy Constructor \n";
        cout<<"***************************\n\n";
    #endif

    if (current == NULL)
    {
        cout<<"List contains no records to copy\n"<<endl;
    }
    else
    {
        while(current != NULL)
        {
            addRecord (current->accountno, current->name, current->address, current->yearofbirth);
            current = current->next;
        }
    }
}

/***********************************************************************
//
// Function name:   ~llist
//
// DESCRIPTION:     llist destructor
//
// Parameters:      void
//
// Return values:   void   
//
//*********************************************************************/

llist::~llist()
{
    #ifdef debug
        cout<<"\n********DEBUG MODE********\n";
        cout<<"Function called: Destructor \n";
        cout<<"***************************\n\n";
    #endif
    writefile();
    cleanup();
}

/*****************************************************************
//
// Function name:   addRecord
//
// DESCRIPTION:     adds a record
//
// Parameters:  accountno (int):    account number
//              name (char []):     name
//              addres (char []):   address w/ multi lines
//              birthday (int);     birth year
//
// Return values: int
//
//****************************************************************/

int llist:: addRecord (int accountnum, char name[], char address[], int yearofbirth)
{
    struct record *previous, *current, *newrecord;
    int sucess;
    
    newrecord = new record;
    sucess = 0;
    newrecord->accountno = accountnum;
    strcpy(newrecord->name, name);
    strcpy(newrecord->address, address);
    newrecord->yearofbirth = yearofbirth;
    current = start;
    previous = NULL;

	#ifdef debug
        cout<<"\n********DEBUG MODE********\n";
        cout<<"Called function addRecord\nParameters passed:\naccount number is "<<accountnum<<"\nname is "<<name<<"\naddress is "<<address<<"\nbirth year is "<<yearofbirth<<endl;
        cout<<"***************************\n\n";
	#endif
/*add to an empty list*/
    if(start == NULL)
    {
        newrecord->next = NULL;
        start=newrecord;
        sucess = 1;
    }
    else
    {
        while(current != NULL && sucess == 0)
        {
            if(newrecord->accountno <= current->accountno)
            {
                newrecord->next = current;
/*add to begining*/
                if(previous == NULL)
                {
                    start=newrecord;
                    sucess = 1;
                }
/*add to in front of*/               
                else
                {
                    previous->next = newrecord;
                    sucess = 1;
                }
            }
            else if(current->next == NULL)
            {
/*insert between two record or to the end if next field is NULL*/
                newrecord->next = current->next;
                current->next = newrecord;
                sucess = 1;
            }
/*step or point previous and current to the next node*/  
			else
			{
				previous = current;
				current=previous->next;
			}
        }
    }
    return sucess;
}

/*****************************************************************
//
// Function name:   printRecord 
//
// DESCRIPTION:     prints a record
//
// Parameters:      accountno (int):    account number
//                  
//
// Return values: int
//
//****************************************************************/

int llist:: printRecord (int accountno)
{
    int sucess, printaccount;
    struct record *previous, *current;
    sucess = 0;
    printaccount = accountno;
    current = start;
    previous = NULL;
	
    #ifdef debug
        cout<<"\n********DEBUG MODE********\n";
        cout<<"Function called: printRecord\nParameters passed:\naccountno is "<<accountno<<endl;
        cout<<"***************************\n\n";
    #endif

/*list is empty*/

    if (start == NULL)
    {
        cout<<"List contains no records\n"<<endl;
    }

    while(current != NULL)
    {
        if(current->accountno == printaccount)
        {
			cout<<"Printing records matching account number"<<endl;
            cout<<"account number:\n"<<current->accountno<<endl;
            cout<<"name:\n"<<current->name<<endl;
            cout<<"adress:\n"<<current->address<<endl;
            cout<<"birth day:\n"<<current->yearofbirth<<endl;
            previous = current;
			current=previous->next;
            sucess = 1;
        }
        else
        {
            previous = current;
			current=previous->next;
        } 
    }
    return sucess;
}

/*****************************************************************
//
// Function name:   modifyRecord
//
// DESCRIPTION:     modifies a record
//
// Parameters:      accountno (int):    account number
//                  name (char []):     New name on the account
//
// Return values: void
//
//****************************************************************/

int llist:: modifyRecord (int accountno, char address[ ])
{
    int sucess, modifyaccount;
    struct record *previous, *current;
    sucess = 0;
    modifyaccount = accountno;
    current = start;
    previous = NULL;
	
    #ifdef debug
        cout<<"\n********DEBUG MODE********\n";
        cout<<"Function called: modifyRecord\nParameters passed:\naccountno is "<<accountno<<"\naddress is "<<address<<endl;
        cout<<"***************************\n\n";
    #endif

/*list is empty*/

    if (start == NULL)
    {
        cout<<"List contains no records\n"<<endl;
    }

    while(current != NULL)
    {
        if(current->accountno == modifyaccount)
        {
            strcpy(current->address, address);
            previous = current;
			current=previous->next;
            sucess = 1;
        }
        else
        {
            previous = current;
			current=previous->next;
        } 
    }
    return sucess;
}

/*****************************************************************
//
// Function name:   printAllRecords 
//
// DESCRIPTION:     prints records
//
// Parameters:      *start (record):    start location in heap of database
//
// Return values: void
//
//****************************************************************/

void llist:: printAll()
{
    struct record *previous, *current;
    current = start;
    previous = NULL;
	
    #ifdef debug
        cout<<"\n********DEBUG MODE********\n";
        cout<<"Function called: printAllRecords\n";
        cout<<"***************************\n\n";
    #endif

/*list is empty*/

    if (start == NULL)
    {
        cout<<"List contains no records to print at all\n"<<endl;
    }
    else
    {
        cout<<"Printing all records\n"<<endl;
        while(current != NULL)
        {
            cout<<current->accountno<<endl;
            cout<<current->name<<endl;
            cout<<current->address<<endl;
            cout<<current->yearofbirth<<endl;
            previous = current;
            current=previous->next;
        }
    }
}

/*****************************************************************
//
// Function name:   deleteRecord 
//
// DESCRIPTION:     deletes records
//
// Parameters:      accountno (int):    account number
//
// Return values: void
//
//****************************************************************/

int llist:: deleteRecord(int accountnum)
{
    struct record *previous, *current, *del;
    int deleteaccount, sucess;
    
    sucess = 0;
    deleteaccount = accountnum;
    current = start;
    previous = NULL;
    
    #ifdef debug
        cout<<"\n********DEBUG MODE********\n";
        cout<<"Function called: deletRecord\naccountno is "<<accountnum<<endl;
        cout<<"***************************\n\n";
    #endif

/*list is empty*/

    if (start == NULL)
    {
        cout<<"List contains no records\n"<<endl;
    }
    else
    {
        while(current != NULL)
        {
            if(current->accountno == deleteaccount)
            {
/*delete only node*/
                if(previous == NULL && current->next == NULL)
                {
                    delete(current);
                    current = NULL;
                    start = NULL;
                    sucess = 1;
                }
/*delete first node*/
                else if(previous == NULL && current->next != NULL)
                {
                    del = current;
                    start = current->next;
                    current = current->next;
                    delete(del);
                    sucess = 1;
                }
/*delete a node in the middle*/
                else if(previous != NULL)
                {
                    previous->next = current->next;
                    del = current;
                    current = current->next;
                    delete(del);
                    sucess = 1;
                }
            }
            else
            {
/*step previous and current to the next node if not nodes were deleted*/
                previous = current;
                current=previous->next;
            } 
        }
    }
    return sucess;
}

/***********************************************************************
//
// Function name:   reverse
//
// DESCRIPTION:     calls the private reverse method
//
// Parameters:      void
//
// Return values:  void 
//
//*********************************************************************/

void llist::reverse()
{
    start = reverse(start);
}

/***********************************************************************
//
// Function name:   overloaded operator<<
//
// DESCRIPTION:     Allows the whole list to be printed with the '<<' operator
//                  can be used in place of the printAll function     
//
// Parameters:      stream(ostream ref variable):       reference to stream
//                  slist(const llist ref variable):   reference to list
//
// Return values:   ostream
//
//*********************************************************************/

ostream & operator<<(ostream &stream, const llist &list)
{
    struct record *previous, *current;
    current = list.start;
    previous = NULL;
	
    #ifdef debug
        cout<<"\n********DEBUG MODE********\n";
        cout<<"Function called: Overloaded '<<' Operator\n";
        cout<<"***************************\n\n";
    #endif

/*list is empty*/

    if (list.start == NULL)
    {
        cout<<"List contains no records to print at all\n"<<endl;
    }
    else
    {
        cout<<"Printing all records\n"<<endl;
        while(current != NULL)
        {
            stream<<current->accountno<<endl;
            stream<<current->name<<endl;
            stream<<current->address<<endl;
            stream<<current->yearofbirth<<endl;
            previous = current;
            current=previous->next;
        }
    }
    return stream;
}

/***********************************************************************
//
// Function name:   overloded '=' operator
//
// DESCRIPTION:     
//
// Parameters:      
//
// Return values:   
//
//*********************************************************************/

llist & llist::operator=(const llist &list)
{
    struct record *previous, *current;
    current = list.start;
    previous = NULL;
	
    #ifdef debug
        cout<<"\n********DEBUG MODE********\n";
        cout<<"Function called: Overloaded '=' \n";
        cout<<"***************************\n\n";
    #endif

/*list is empty*/

    if (current == NULL)
    {
        cout<<"List contains no records to copy\n"<<endl;
    }
    else
    {
        cout<<"copying all records\n"<<endl;
        while(current != NULL)
        {
            addRecord (current->accountno, current->name, current->address, current->yearofbirth);
            current = current->next;
        }
    }
    return *this;
}
