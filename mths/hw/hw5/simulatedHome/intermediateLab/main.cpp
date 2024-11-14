#include <iostream>
#include <fstream>
#include <vector>
#include "animal.h"

using namespace std;

void writeAnimals(vector<Animal> &animals, string filename);
void addAnimal(vector<Animal> &animals);
void removeAnimal(vector<Animal> &animals);
void displayAnimals(vector<Animal> &animals);

int main()
{
    string filename;
    ifstream infile;
    vector<Animal> animals;

    cout << "Welcome to the vet management system." << endl;
    cout << "Please enter a file to read patients from: ";
    cin >> filename;

    infile.open(filename);

    while(!infile.is_open())
    {
        cout << endl << "That file doesn't exist. Try again." << endl;
        cout << "Please enter a file to read patients from: ";
        cin >> filename;

        infile.open(filename);
    }

    cout << endl << "File opening..." << endl;

    string name, type;
    int age;
    float weight;

    while(infile >> name >> type >> age >> weight)
    {
        Animal temp(name, type, age, weight);

        animals.push_back(temp);
    }

    cout << "File read. Closing the file from read mode." << endl;
    infile.close();

    // menu handling
    while(1)
    {
        string option;

        cout << endl << "Menu:" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Display animals" << endl;
        cout << "2. Add animal" << endl;
        cout << "3. Remove animal" << endl;
        cout << "4. Write to file" << endl;
        cout << "Enter your option: ";
        cin >> option;

        cout << endl;

        // exit
        if(option == "0")
        {
            cout << "Good-bye!" << endl;
            break;
        }

        // display
        else if(option == "1")
        {
            displayAnimals(animals);
        }

        // add
        else if(option == "2")
        {
            addAnimal(animals);
        }

        // remove
        else if(option == "3")
        {
            displayAnimals(animals);
            removeAnimal(animals);
        }

        // write
        else if(option == "4")
        {
            writeAnimals(animals, filename);
            cout << "Animals saved." << endl;
        }

        // wrong option
        else
        {
            cout << "That wasn't an option. Please try again." << endl;
        }
    }

    return 0;
}

void writeAnimals(vector<Animal> &animals, string filename)
{
    ofstream outfile;
    outfile.open(filename);

    for(int i = 0; i < animals.size(); i++)
    {
        outfile << animals[i].getName() << " " << animals[i].getType() << " ";
        outfile << animals[i].getAge() << " " << animals[i].getWeight() << endl;
    }

    outfile.close();
}

void addAnimal(vector<Animal> &animals)
{
    string name, type;
    int age;
    float weight;

    cout << "Enter in the animal name (no spaces!): ";
    cin >> name;

    cout << "Enter in the animal type (species): ";
    cin >> type;

    cout << "Enter in the animal age: ";
    cin >> age;

    cout << "Enter in the animal weight: ";
    cin >> weight;

    Animal temp(name, type, age, weight);
    animals.push_back(temp);
}

void removeAnimal(vector<Animal> &animals)
{
    int option;

    cout << "Which animal would you like to remove? ";
    cin >> option;
    option--;

    animals.erase(animals.begin()+option);
}

void displayAnimals(vector<Animal> &animals)
{
    for(int i = 0; i < animals.size(); i++)
    {
        cout << "Animal " << i + 1 << ": " << endl;
        cout << "Name: " << animals[i].getName() << endl;
        cout << "Type: " << animals[i].getType() << endl;
        cout << "Age: " << animals[i].getAge() << endl;
        cout << "Weight: " << animals[i].getWeight() << endl;
        cout << endl;
    }
}
