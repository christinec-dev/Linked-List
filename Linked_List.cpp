//Copyright 2021 Christine Coomans

//Necessary libraries for application
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std; 
#define null 0
#define UNDERLINE "\033[4m"
#define CLOSEUNDERLINE "\033[0m"

//Person object creation
class Person {
public:
    //A person has a name, surname, age, and gender
    string name;
    string surname;
    int age;
    string gender;
    //Bind the defined variables to future functions
    Person(string name, string surname, int age, string gender) {
        this->name = name;
        this->surname = surname;
        this->age = age;
        this->gender = gender;
    }
};

//Linked List Node Initialization
class Node {
//singular person pointer to Person Class
public:
    Person* per;
    Node* next;
    Node(Person* per) {
        this->per = per;
        next = null;
    }
};

//Initialize our Ordered Linked List
class OrderedList {

private:
    //node pointers
    Node* head; //first node
    Node* tail; //last node
    int size; //list size

//initial values of pointers
public:
    OrderedList() {
        head = null;
        tail = null;
        size = 0;
    }
    //size refers to our list size of initial array
    int getSize() {
        return size;
    }

    //function to change the text color of our comand line
    void Color(int color)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }

    //function to create existing people array objects to our initial list
    void append(string name, string surname, int age, string gender) {
        //pointer assigns variables to Person object and creates an individual node
        Person* pers = new Person(name, surname, age, gender);
        Node* node = new Node(pers);
        //returns initial empty node values
        if (head == null) {
            head = node;
            tail = node;
        }
        //else creates a new node
        else {
            tail->next = node;
            tail = node;
        }
        //adds node by incrementing list size
        size++;
    }

    //function to add person object to our  list array
    void addPerson(string name, string surname, int age, string gender)
    {
        //pointer assigns variables to Person object and creates an individual node
        Person* pers = new Person(name, surname, age, gender);
        Node* node = new Node(pers);
        //returns initial empty node values
        if (head == null) {
            head = node;
            tail = node;
        }
        //else creates a new node
        else {
            tail->next = node;
            tail = node;
        }
        //adds node by incrementing list size
        size++;
    }

    //function to remove a person object from our list array
    void removePerson(string name) {
        //deletes first item (header) node from array
        if (head != null) {
            Node* current = head;
            //delete the list item equal to the name entered
            if (current->per->name == name) {
                delete current;
            }
            //loops through list array to find name entered
            else {
                while (current != null) {
                    //deletes then breaks out of loop to only delete current item equal to the name entered
                    if (current->next->per->name == name) {
                        current->next = current->next->next;
                        break;
                    }
                    //else loops to next item
                    else {
                        current = current->next;
                    }
                }
            }
            //adds node by decrementing list size
            size--;
        }
    }

    //function to add person to the top of the list
    void prepend(string name, string surname, int age, string gender) {
        Person* pers = new Person(name, surname, age, gender);
        Node* node = new Node(pers);
        if (head == null) {
            head = node;
            tail = node;
        }
        else {
            node->next = head;
            head = node;
        }
        size++;
    }

    //get number of people
    void display() {
        Node* current = head;
        while (current != null) { 
            cout << current->per->name << ", " << current->per->surname << ", "  << current->per->age << ", " << current->per->gender << endl;
            current = current->next;
        }
        Color(2);
        cout << "Total number of people: " << getSize() << endl; 
        cout << endl;
    }

    //main functionality to add/remove/display list items
    void run() {
        //needed for bold styling
        char esc_char = 27; 
        //five people objects for the ordered list
        append("Kevin", "MacLarren", 47, "Male");
        append("Christine", "Coomans", 22, "Female");
        append("Gerhard", "Botha", 24, "Male");
        append("Meghan", "Smith", 33, "Female");
        append("Dylan", "Porter", 16, "Male");

        //List before alteration:
        Color(15);
        cout << esc_char << "[1m" << "----- List before alterations: -----" << esc_char << "[0m" << endl;
        cout << endl;
        cout << UNDERLINE << "Name" << " " << "Surname" << " " << "Age" << " " << "Gender" << CLOSEUNDERLINE << endl;
        display();

        //List after instertion
        Color(15);
        cout << esc_char << "[1m" << "----- List after person addition: -----" << esc_char << "[0m" << endl;
        cout << endl;
        cout << UNDERLINE << "Name" << " " << "Surname" << " " << "Age" << " " << "Gender" << CLOSEUNDERLINE << endl;
        addPerson("Jason", "Brody", 29, "Male");
        display();

        //List after deletion:
        Color(15);
        cout << esc_char << "[1m" "----- List after person removal: -----" << esc_char << "[0m" << endl;
        cout << endl;     
        cout << UNDERLINE << "Name" << " " << "Surname" << " " << "Age" << " " << "Gender" << CLOSEUNDERLINE << endl;
        removePerson("Christine"); 
        display();
    }

    //class deconstructor
    void destroy() {
        Node* current;
        while (head != null) {
            current = head->next;
            delete head;
            head = current;
        }
        head = null;
        tail = null;
        size = 0;
    }
    ~OrderedList() {
        destroy();
    }
};

//Main CPP function
int main() {
    //return the list 
    OrderedList list;
    //runs the list functions
    list.run();
 
    //Exit status for CPP application
    return 0;
}