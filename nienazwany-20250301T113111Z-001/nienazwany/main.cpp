#include <iostream>
#include <filesystem>
#include "organizm.h"
#include "ustawienia.h"
#include "generatorlosowy.h"
#include "sasiedztwo.h"
#include "nisza.h"
#include "osobniki.h"
#include <fstream>


using namespace std;




int main()
{

    std::string file {__FILE__};
    std::string directory {file.substr(0, file.rfind("/"))};
    std::string directorysave, directoryload;
    directorysave=directory;
    directoryload=directory;
    directorysave+="//symulacja.txt";
    directory+="//element.jpg";
    directoryload+="//start.txt";




Srodowisko ekoSystem=Srodowisko::czytajZPliku(directoryload);

ofstream plikWynikowy(directorysave);
if(!plikWynikowy.is_open()) return 1;
    string stanSymulacji;

unsigned long i = 0;

do{
    system("clear");
    cout << "Krok symulacji: " << i << endl;
    plikWynikowy << "Krok symulacji: " << i << endl;
    stanSymulacji = ekoSystem.doTekstu();

    cout << endl << stanSymulacji << endl;
    plikWynikowy << stanSymulacji << endl;
    cin.ignore(1);
    ekoSystem++;
    i++;
} while(i < 200 && !ekoSystem && std::filesystem::exists(directory));

if(!std::filesystem::exists(directory)) cout<<"Blad krytyczny: Brakujace pliki"<<endl;
    cout << endl;
    plikWynikowy.close();
    return 0;
}



