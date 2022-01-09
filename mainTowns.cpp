#include"towns.h"

int main(){

    Town town1("Carlos Mendez", "Aguadilla", 15000, 22000), town2("Charlie Delgado", "Isabela", 12000, 23000), town3;

    Island island;

    island.menu(town1); 
    island.menu(town2); 
    island.menu(town1); 
    island.menu(town1); 
    island.menu(town2); 

    return 0;
}