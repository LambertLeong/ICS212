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
// DESCRIPTION: 	contains the prototypes for llist
//
//****************************************************************/

class llist
{
  private:
    record *    start;
    char        filename[16];
    int         readfile();
    int         writefile();
    record *    reverse(record * );
    void        cleanup();

  public:
    llist();
    llist(char[]);
    llist(const llist &list);
    ~llist();
    int addRecord(int, char[], char[], int);
    int printRecord(int);
    int modifyRecord(int, char[]);
    void printAll();
    int deleteRecord(int);
    void reverse();
    friend ostream & operator<<(ostream &, const llist &);
    
    
    llist & llist::operator=(const llist &list);
};
