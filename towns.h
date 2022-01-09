#ifndef TOWNS_H
#define TOWNS_H
#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::vector;
using std::cin;
using std::endl;
using std::string;


class Town{

    public:
        // Constructors
        Town();
        Town(string aMayor, string aName, int aPopulation, int aArea);

        // Setters & Getters
        void setMayor(string aMayor);
        void setName(string aName);
        void setPopulation(int aPopulation);
        void setArea(int aArea);

        string getMayor();
        string getName();
        int getPopulation();
        int getArea();

        // Friend function
        Town friend operator +(Town aTown1, Town aTown2);

        // Other functions
        bool operator==(Town aTown);

    private:
        string mayor, name;
        int population, area;
};

class Island: public Town
{
    public:
        // Constructor
        Island();

        // Other functions
        void addTown(Town aTown);
        void removeTown(Town aTown);
        void editTown(Town aTown);
        void printTowns();
        void totalPopulation();
        

        // Menu options
        void menu(Town aTown);


    private:
        vector<Town> towns;
};


#endif