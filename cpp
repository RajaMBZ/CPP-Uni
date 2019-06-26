#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

//to create the linked list with single string of data
class node{
public:
    string data;
    node* next;
};

//creating linked list of single string of data
class linkedList{
public:

    linkedList(){}

    node *first = NULL;
    node *last = NULL;

//checking if linked list is empty

bool isEmpty(){
	return first==NULL;
}

//to add a string to the linked list
void addNode(string n){
    node *tmp = new node;
    tmp->data = n;
    tmp->next = NULL;

    if(isEmpty())
    {
        first = tmp;
        last = tmp;
    }
    else
    {
        last->next = tmp;
        last = last->next;
    }
}

//to count the total nodes of the linked list
int countNodes(){

    int counterOfNodes = 0;

    node* current = first;
    while (current != NULL)
    {
        counterOfNodes++;
        current = current->next;
    }
    return counterOfNodes;
}

//to get the boolean result of search of a specific string
bool searching(string x)
{

    node* current = new node();
    current = first;

    while (current != NULL)
    {
        if (current->data == x)
            return true;
        current = current->next;
    }
    return false;
}

int searchingTwo(string x)
{
    int number = 1;

    node* current = new node();

    current = first;

    while (current != NULL)
    {
        if (current->data == x)
            return number;
        current = current->next;
        ++number;
    }
}

//printer function to test the run
void printer () {

    node* current = new node();
    current = first;
    cout<<endl;
    while (current != NULL)
    {
        cout<<current->data<<endl;
        current = current->next;
    }

}

//end of linkedList class with single strings
};

//start of linkedListTwo class with double integers

class nodetwo{
public:
    int data1[2];
    nodetwo *next;
};

class linkedListTwo{
public:
    nodetwo *head = NULL;
    nodetwo *tail = NULL;

    void NewNode(int value1, int value2){

        nodetwo *temp = new nodetwo();
        temp->data1[0] = value1;
        temp->data1[1] = value2;
        temp->next=NULL;
        if (head == NULL){
            head = temp;
            tail = temp;
        }
        else
      {
        tail->next=temp;
        tail=tail->next;
      }
    }


int counter(){
    int count = 0;
    nodetwo *current=new nodetwo;
    current = head;

    while(current!=NULL){
        count++;
        current = current->next;
    }

    return count;
}

void Print(){

    nodetwo *current = new nodetwo();

    current = head;

        while(current!=NULL){
            cout<<current->data1[0]<<" co-authors in publication of the year of ";
            if(current->data1[1]!=0)cout<<current->data1[1]<<endl;
            else cout<<"<unknown>"<<endl;
            current = current->next;
        }
        cout<<"\n";
    }

void PrintforPublicationsPerYear(){

    nodetwo *current = new nodetwo();

    current = head;

        while(current!=NULL){
            cout<<current->data1[0]<<" publications published in the year of ";
            if(current->data1[1]!=0)cout<<current->data1[1]<<endl;
            else cout<<"<unknown>"<<endl;
            current = current->next;
        }
        cout<<"\n";
}

void PrintforPosition(){

    nodetwo *current = new nodetwo();

    current = head;

        while(current!=NULL){
            cout<<current->data1[0]<<" publications in the position of ";
            cout<<current->data1[1]<<endl;
            current = current->next;
        }

        cout<<"\n";
}

void sorting () {

    nodetwo * temphead = head;
    nodetwo * tempnode = NULL;

    for (nodetwo *index = head; index->next != nullptr; index = index->next) {
        for (nodetwo *selection = index->next; selection != nullptr; selection = selection->next) {
            if (index->data1[1] > selection->data1[1]) {
                swap(index->data1, selection->data1);
            }
        }
    }
}

//to get the boolean result of search
bool searchingInt(int x)
{
    nodetwo* current = new nodetwo();
    current = head;

    while (current != NULL)
    {
        if (current->data1[1] == x)
            return true;
        current = current->next;
    }
    return false;
}

};

class nodethree{
public:
    string sdata;
    int idata;
    nodethree *next;
};

class linkedListThree{
public:
    nodethree *head = NULL;
    nodethree *tail = NULL;

void NewNode(string value1, int value2){

    nodethree *temp = new nodethree();
    temp->sdata = value1;
    temp->idata = value2;
    temp->next=NULL;
    if (head == NULL){
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next=temp;
        tail=tail->next;
    }
}

void Print(){

    nodethree *current = new nodethree();

    current = head;

    while(current!=NULL){
        cout<<current->sdata<<" in the year of ";
        if(current->idata!=0)cout<<current->idata<<endl;
        else cout<<"<unknown>"<<endl;
        current = current->next;
    }

    cout<<"\n";
}

void sorting () {

    nodethree * temphead = head;
    nodethree * tempnode = NULL;

    for (nodethree *index = head; index->next != nullptr; index = index->next) {
        for (nodethree *selection = index->next; selection != nullptr; selection = selection->next) {
            if (index->idata > selection->idata) {
                swap(index->idata, selection->idata);
            }
        }
    }
}

};

//creation of author class
class Author{
public:

    Author(){}

    string name;

    linkedListTwo* coauthorsAndYears = new linkedListTwo();

    linkedListTwo* publicationsPerYearByX = new linkedListTwo();

    linkedListTwo* paperByPosition = new linkedListTwo();

    linkedListThree* journalNameAndYear = new linkedListThree();

    int countTotalArticles = 0;

    string total[2];

void enter(int x, int y){

    coauthorsAndYears->NewNode(x,y);

}

void enterTwo(int y){

    nodetwo* current = new nodetwo();

    int x = 1;

    if ((publicationsPerYearByX->searchingInt(y)) ==  false) {

        publicationsPerYearByX->NewNode(x, y);

    } else {

    current = publicationsPerYearByX->head;

    while (current != NULL)
    {
        if (current->data1[1] == y)
            current->data1[0] = current->data1[0]+1;
        current = current->next;
    }
}

}

void enterThree (int pos) {

    nodetwo* current = new nodetwo();

    int x = 1;

    if ((paperByPosition->searchingInt(pos)) ==  false) {

        paperByPosition->NewNode(x, pos);

    } else {

    current = paperByPosition->head;

        while (current != NULL)
        {
            if (current->data1[1] == pos){
                current->data1[0] = current->data1[0]+1;
            }
            current = current->next;
        }
    }

}

void enterFour (string s, int y)    {

    journalNameAndYear->NewNode(s,y);

}

};

class Article{
public:

    string identifier, title, journal, month, year, publisher;

    linkedList* authorList = new linkedList();


void printAll() {

    linkedList* current = authorList;

    // Initialize current
    current = authorList;

    while (current->first != NULL) {
        cout<<current->first->data<<endl;
        current->first = current->first->next;
    }
}

//Adding an author to the linkedList of authors of this publication
void addAuthor(string s1, string s2)   {

    string s3 = s1+s2;

    s3.erase(s3.begin());
    s3.pop_back();

    if(s3[0] == ' '){
            s3.erase(0, 1);
    }

    if(s3[s3.length()-1] == ' '){
            s3.erase(s3.length()-1, s3.length());
    }

    authorList->addNode(s3);

}

void setIdentifier(string s)  {

    identifier = s;

}

void setTitle(string s)  {

    s.erase(s.begin());
    s.erase(s.begin());
    s.erase(s.begin());
    s.pop_back();
    s.pop_back();
    s.pop_back();
    s.pop_back();
    s.pop_back();
    s.pop_back();
    title = s;

}

void setJournal(string s)  {

    s.pop_back();
    s.pop_back();
    s.pop_back();
    s.pop_back();
    journal = s;

}

void setMonth(string s)  {

    s.erase(s.begin());
    s.pop_back();

    month = s;

}

void setYear(string s)  {

    s.erase(s.begin());
    s.pop_back();
    year = s;
}

void setPublisher(string s) {

    publisher = s;

}

};

int getNumberOfArticlesByAuthor(Author* au, int totalNumber)   {

    cout<<"Enter the name of the author without any initial spaces (but do include the space between middle/last name and the first name) and commas (such as Guizani Mohsen):"<<endl;

    string st;

    cin.ignore();

    getline(cin, st);

    for(int x = 0; x<totalNumber; ++x){

        if (au[x].name == st){
            return au[x].countTotalArticles;
        }
    }
    return 0;
}

void searchByIdentifier(Article *a, string ID){

    for(int row = 1; row<=50; ++row){
        if(a[row-1].identifier==ID){
            cout<<"----------------------------------------"<<endl;
            cout<<"Found it! "<<endl;
            cout<<"Published in the month: "<<a[row-1].month<<endl;
            cout<<"In the journal: "<<a[row-1].journal<<endl;
            cout<<"In the year: "<<a[row-1].year<<endl;
            cout<<"With the title: "<<a[row-1].title<<endl;
            cout<<"It has the authors:\n\n";
            a[row-1].printAll();
            cout<<"----------------------------------------"<<endl;
        }
    }
}

void viewAllAuthors (Article *a){
    for(int row = 1; row<=50; ++row){
        cout<<endl<<"Article No: "<<row<<endl;
        a[row-1].printAll();
    }
}

bool searchAlreadyIn (int y, Author *a, string x) {

    for(int row = 0; row<y; ++row){

        if (a[row].name == x)   {
                return true;
        }
    }
    return false;
}

int countTotalAuthors (Article *a)  {

    linkedList* l = new linkedList(); //used to get all the authors within all fifty publications

    linkedList* m = new linkedList();

    node* n = new node();

    for(int row = 1; row<=50; ++row){

        n = a[row-1].authorList->first;

        m = a[row-1].authorList;

        while (m->first != NULL)

        {
            if ((l->searching(m->first->data)) == false)   {
                l->addNode(m->first->data);
            }

            m->first = m->first->next;
        }

        a[row-1].authorList->first = n;
    }

    int counter = 0;
    node* current = l->first; // Initialize current
    while (current != NULL)
    {
        counter++;
        current = current->next;
    }
    return counter;
}

linkedList* getAllAuthors (Article *a)  {

    linkedList* l = new linkedList();
    linkedList* m = new linkedList();
    node* n = new node();

    for(int row = 1; row<=50; ++row){

        n = a[row-1].authorList->first;

        m = a[row-1].authorList;

        while (m->first != NULL){

            if ((l->searching(m->first->data)) == false)   {
                l->addNode(m->first->data);
            }
            m->first = m->first->next;
        }
        a[row-1].authorList->first = n;
    }
    return l;
}

int convertToInteger(string s){

    if (s.size()==4){return (std::stoi(s));}
    else if (s=="NULL" || s==""){return 0;}
    else if (s.size()>4){
        while (s.size()>4){
            s.pop_back();
        }
        return (std::stoi(s));
    }
    else return 0;

}

void publicationsPerYear(Author* a, int totalNumber){

    cout<<"Enter the name of the author without any initial spaces (but do include the space between middle/last name and the first name) and commas (such as Guizani Mohsen):"<<endl;

    string st;

    cin.ignore();

    getline(cin, st);

    for(int x = 0; x<totalNumber; ++x){

        if (a[x].name == st){

            a[x].coauthorsAndYears->sorting();
            a[x].coauthorsAndYears->Print();

        }
    }
}

void actualPublicationsPerYear(Author* a, int totalNumber){

    cout<<"Enter the name of the author without any initial spaces (but do include the space between middle/last name and the first name) and commas (such as Guizani Mohsen):"<<endl;

    string st;

    cin.ignore();

    getline(cin, st);

    for(int x = 0; x<totalNumber; ++x){

        if (a[x].name == st){

            a[x].publicationsPerYearByX->sorting();
            a[x].publicationsPerYearByX->PrintforPublicationsPerYear();

        }
    }
}

void positionOfPublications(Author* a, int totalNumber){

    cout<<"Enter the name of the author without any initial spaces (but do include the space between middle/last name and the first name) and commas (such as Guizani Mohsen):"<<endl;

    string st;

    cin.ignore();

    getline(cin, st);

    for(int x = 0; x<totalNumber; ++x){

        if (a[x].name == st){

            a[x].paperByPosition->sorting();
            a[x].paperByPosition->PrintforPosition();

        }
    }
}

void journalOfAuthor(Author* a, int totalNumber){

    cout<<"Enter the name of the author without any initial spaces (but do include the space between middle/last name and the first name) and commas (such as Guizani Mohsen):"<<endl;

    string st;

    cin.ignore();

    getline(cin, st);

    for(int x = 0; x<totalNumber; ++x){

        if (a[x].name == st){

            a[x].journalNameAndYear->sorting();
            a[x].journalNameAndYear->Print();
        }
    }
}

int main () {
while(true){
    linkedList* l = new linkedList();

    string line, fileName, forTitle;

    cout<<"Enter the directory of the BibtexFileCSV file: (like C:\\Users\\Raja\\Downloads\\BibtexFileCSV.csv)\n\n";

    //std::getline(std::cin, fileName);

    //cin>>fileName;

    fileName = "C:\\Users\\Raja\\Downloads\\BibtexFileCSV.csv";

    ifstream myfile (fileName);

    Article *article = new Article[50];

    int row = 0;

    string authorLine1, authorLine2;

    getline(myfile, line);

    for(int row = 1; row<=50; ++row){

        for (int column = 1; column<=26; ++column)   {

            getline(myfile, line,',');

            if (line=="" && column<=6){

                line = "NULL";

            }

            else if (line=="" && column>6)  {

                //line = "NULL";

                //authorLine1 = line;

                //authorLine2 = line;

                column=27;

                getline(myfile, line);

            }

            if (column==1) {

                article[row-1].setIdentifier(line);

            }

            else if (column==2) {

                forTitle = line;

                getline(myfile, line,'{');

                line = forTitle + line;

                article[row-1].setTitle(line);

            }

            else if (column==3) {

                article[row-1].setJournal(line);

            }

            else if (column==4) {

                article[row-1].setMonth(line);

            }

            else if (column==5) {

                article[row-1].setYear(line);

            }

            else if (column==6) {

                article[row-1].setPublisher(line);

            }

            //  Replaced the condition: else if (column==7 || column==9 || column==11 || column==13 || column==15 || column==17 || column==19 || column==21 || column==23)
            //  With the following one:

            else if ((column>=7 && column<=23) && (column%2!=0)) {

                if (line!="NULL")   {
                    authorLine1 = line;
                    getline(myfile, line,',');
                    authorLine2 = line;
                    ++column;
                }
                article[row-1].addAuthor(authorLine1, authorLine2);
            }

            else if (column==25)   {
                authorLine1 = line;
                string str;
                getline(myfile, str);
                authorLine2 = str;
                article[row-1].addAuthor(authorLine1, authorLine2);
                column=27;
            }
        }
    }

    int totalAuthors = countTotalAuthors(article);

    Author *auth = new Author[totalAuthors];

    linkedList* getAuthors = new linkedList();

    getAuthors = getAllAuthors(article);

    node* authorListTwo = getAuthors->first;

    int anotherCounter = 0;

    int position;

    while (authorListTwo != NULL){

        auth[anotherCounter].name = authorListTwo->data;
        for(int row = 0; row<50; ++row){

            if (article[row].authorList->searching(authorListTwo->data))
            {
                ++auth[anotherCounter].countTotalArticles;

                auth[anotherCounter].enter(article[row].authorList->countNodes()-1,convertToInteger(article[row].year));

                auth[anotherCounter].enterTwo(convertToInteger(article[row].year));

                position = article[row].authorList->searchingTwo(authorListTwo->data);

                auth[anotherCounter].enterThree(position);

                auth[anotherCounter].enterFour(article[row].publisher ,convertToInteger(article[row].year));
            }
        }
        ++anotherCounter;
        authorListTwo = authorListTwo->next;
    }

    int ch;

    cout<<"\n------------------DATA STRUCTURES PROJECT------------------\n\nWhich task would you like to run? Enter number!\n\n1. Calculate the total number of articles published by an author x.\n2. Calculates the number of publications of an author x per year\n3. Calculates the number of co-authors of an author x per publication sorted timewise.\n4. Counts the numbers of papers published by an author x for each author position.\n5. Sorted timewise, prints the name of the journal in which an author x has published his research work.\n\n------------------ADDITIONAL FUNCTIONS------------------\n\n6. View authors of each article.\n7. Search for an article by its identifier.\n8. Count total number of authors in all 50 publications.\n\n";

    cin>>ch;

    //closing the file as its work is done after everything is stored in objects and lists

    myfile.close();

 //   while(true){

    if (ch==1)  {

        int totalByAuthor = getNumberOfArticlesByAuthor(auth, totalAuthors);

        cout<<endl<<"Total no. of publications by the entered author = "<<totalByAuthor<<endl;

    } else if (ch == 2) {

        actualPublicationsPerYear(auth, totalAuthors);

    } else if (ch == 3) {

        publicationsPerYear(auth, totalAuthors);

    } else if (ch == 4) {

        positionOfPublications(auth, totalAuthors);

    } else if (ch == 5) {

        journalOfAuthor(auth, totalAuthors);

    } else if (ch == 6) {

        viewAllAuthors(article);

    } else if (ch == 7) {

        string input;

        cout<<"Enter the identifier:";

        cin>>input;

        searchByIdentifier(article, input);

    } else if (ch == 8) {

        cout<<"Total number of authors in all fifty publications: "<<totalAuthors;

    }

    else {

    cout<<"Wrong choice entered! Terminating the program...";

    }
    }
    return 0;
}
