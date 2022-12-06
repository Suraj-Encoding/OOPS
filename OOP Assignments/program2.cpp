// # Assignment-2 -> Student database system
#include <iostream>
#define max 30  // Macros
using namespace std;

// class
class Student{ 
   private:
     int roll_no;
     string name, address, Class, dob, blood_gp,div;
     long int phone_no; 
    public:
     static int count;  // By default count=0
     // function declaration
     void setdata(int i);
     void getdata(int i);
     inline static void display_count();
     // Constructor declaration -> default constructor
      Student();
     // Destructor declaration -> destructor is only one
      ~Student();
};

// function defination
// setdata
void Student :: setdata(int i){
      cout<<"\nEnter data of student-"<<(i+1)<< " : "<<endl;

      cin.ignore(); // <- Imp step
      cout<<"Enter name: ";
      getline(cin,name); 
    
      cout<<"Enter address: ";
      getline(cin,address); 

      cout<<"Enter class: ";
      getline(cin,Class);

      cout<<"Enter division: ";
      getline(cin,div);

      cout<<"Enter D.O.B: ";
      getline(cin,dob);

      cout<<"Enter blood group: ";
      getline(cin,blood_gp);

      cout<<"Enter Roll No: ";
      cin>>roll_no;

      cout<<"Enter phone no: ";
      cin>>phone_no;
      
      // Increament student count by 1
         count++; 
}

// getdata
void Student :: getdata(int i){
    cout<<"\nStudent-" <<(i+1)<< " Data: "<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Address: "<<address<<endl;
    cout<<"Class: "<<Class<<endl;
    cout<<"Division: "<<div<<endl;
    cout<<"D.O.B: "<<dob<<endl;
    cout<<"Blood Group: "<<blood_gp<<endl;
    cout<<"Roll No: "<<roll_no<<endl;
    cout<<"Phone No: "<<phone_no<<endl;
}

// Constructor
Student :: Student(){
      cout<<"Constructor.."<<endl;
      name = "null";
      address = "null";
      Class = "null";
      div = "null" ;
      dob = "null";
      blood_gp = "null";
      roll_no = 0;
      phone_no = 0; 
}

// Destructor
Student :: ~Student(){
    cout<<"Destroyed.."<<endl;
}

// Static function -> To use static variable
void Student :: display_count(){
     cout<<"\nThe count of students is: "<<count<<endl;
}

// Initialise static variable of class
int Student :: count=0;

// main function
int main()
{  
    cout<<"\n # Student Database System # \n"<<endl;
    int i,n,ch;

    // Enter number of students
    cout<<"Enter number of students: ";
    cin>>n;

    // Array of objects -> Constructor is call -> to construct objects -> to allocate the memory
    Student stud[n]; 
   
    // Menu driven program
    do{
    // Menu
    cout<<"\n#Menu: \n1.Setdata \n2.Getdata \n0.Exit \nEnter your choice:  ";
    cin>>ch;

    // Switch Case
    switch(ch){

        case 1:
            // setdata
            for(i=0;i<n;i++)
            {
                stud[i].setdata(i);
            }
            break;

        case 2: 
            //getdata
            for(i=0;i<n;i++)
            {
                stud[i].getdata(i);
            }
            break;

        case 0:  
            goto end;  // goto statement with label 'end'
            break;

        default: 
            cout<<"Enter correct choice!"<<endl;
            break; 

    }
 } while(1); 
   end: 
   Student :: display_count();
   // Destructor is call -> to destroy objects -> to deallocate or free the memory
   return 0;
}


/*
Concepts Used: classes & objects, constructor, destructor, inline function,
               static function & static variables, array of objects and others.
               others: goto, macros, switch, do-while, for loop.
*/