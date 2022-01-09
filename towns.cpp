#include"towns.h"

// Island Functions
Island::Island(){
    vector<Town> towns = {};
}

// Menu Function
void Island::menu(Town aTown){
    int choice;
    string cont;

    cout << "1. Add a town to the island." << endl;
    cout << "2. Remove a town from the island." << endl;
    cout << "3. Edit a town in the island." << endl;
    cout << "4. Show total population of the island." << endl;
    cout << "5. Print all towns of the island." << endl;
    cin >> choice;

    switch(choice){
        case 1:
            addTown(aTown);
            break;
        case 2:
            removeTown(aTown);
            break;
        case 3:
            editTown(aTown);
            break;
        case 4:
            totalPopulation();
            break;
        case 5:
            printTowns();
            break;
    }
}

void Island::addTown(Town aTown){
    towns.push_back(aTown);
}

void Island::removeTown(Town aTown){
    operator==(aTown);
    for(int i = 0;i < towns.size();i++){
        if(towns[i].getName() == aTown.getName()){
            towns.erase(remove(towns.begin(), towns.end(), towns[i]), towns.end());
        }
    }
}

void Island::editTown(Town aTown){
    int choice, newValue;
    string newString;

    cout << "1. Edit the town's name." << endl;
    cout << "2. Edit the town's mayor." << endl;
    cout << "3. Edit the town's population." << endl;
    cout << "4. Edit the town's area." << endl;
    cin >> choice;

    for(int i = 0;i < towns.size();i++){
        if(towns[i].getName() == aTown.getName()){
            if(choice == 1){
                cout << "What is the new name for the town?" << endl;
                cin >> newString;
                towns[i].setName(newString);
            }
            else if(choice == 2){
                cout << "What is the new name for the mayor?" << endl;
                cin >> newString;
                towns[i].setMayor(newString);
            }
            else if(choice == 3){
                cout << "What is the new population of the town?" << endl;
                cin >> newValue;
                towns[i].setPopulation(newValue);
            }
            else if(choice == 4){
                cout << "What is the new area of the town?" << endl;
                cin >> newValue;
                towns[i].setArea(newValue);
            }
            else{
                cout << "That is not a correct option." << endl;
            }
        }
    }
}

void Island::printTowns(){
    for(int i = 0;i < towns.size();i++){
        cout << "Town name: " << towns[i].getName() << endl;
        cout << "Town mayor: " << towns[i].getMayor() << endl;
        cout << "Town population: " << towns[i].getPopulation() << endl;
        cout << "Town area: " << towns[i].getArea() << endl;
        cout << endl;
    }
}

void Island::totalPopulation(){
    int max_population = 0;

    for(int i = 0;i < towns.size();i++){
        max_population += towns[i].getPopulation();
    }
    cout << "The total population of the island is " << max_population << " people." << endl;
}

// Town functions

Town operator +(Town aTown1, Town aTown2){
    Town result;
    result.population = aTown1.population + aTown2.population;
    result.area = aTown1.area + aTown2.area;
    return result;
}

bool Town::operator==(Town aTown){
    return this->name == aTown.name && this->mayor == aTown.mayor && this->population == aTown.population && this->area == aTown.area; 
}

Town::Town(){
    mayor = "none";
    name = "none";
    population = 0;
    area = 0;
}

Town::Town(string aMayor, string aName, int aPopulation, int aArea){
    setMayor(aMayor);
    setName(aName);
    setPopulation(aPopulation);
    setArea(aArea);
}

void Town::setMayor(string aMayor){
    mayor = aMayor;
}

void Town::setName(string aName){
    name = aName;
}

void Town::setPopulation(int aPopulation){
    population = aPopulation;
}

void Town::setArea(int aArea){
    area = aArea;
}

string Town::getMayor(){
    return mayor;
}

string Town::getName(){
    return name;
}

int Town::getPopulation(){
    return population;
}

int Town::getArea(){
    return area;
}