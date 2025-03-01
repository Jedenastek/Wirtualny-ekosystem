# Wirtualny Ekosystem

## Opis projektu
Wirtualny Ekosystem to prosty symulator biocybernetyczny, w którym rozwija się ekosystem składający się z trzech gatunków wirtualnych organizmów:

- **Glony (`*`)** – zdobywają pożywienie poprzez fotosyntezę.
- **Grzyby (`#`)** – odżywiają się martwymi organizmami.
- **Bakterie (`@`)** – polują na glony oraz inne bakterie.

Środowisko ekosystemu to prostokątna tablica komórek (nisz), w której organizmy żyją, zdobywają pożywienie, rozmnażają się i starzeją. Aplikacja wykonana jest w języku **C++** i posiada **interfejs konsolowy**, który wyświetla animację rozwoju ekosystemu.

## Zasady symulacji
1. **Starzenie się** – każdy organizm ma określoną długość życia.
2. **Zdobywanie pożywienia** – organizmy szukają jedzenia w swoim sąsiedztwie.
3. **Rozmnażanie** – organizmy mogą tworzyć potomstwo, jeśli znajdą wolne miejsce.
4. **Ruch** – grzyby i bakterie mogą zmieniać położenie, jeśli nie jedzą ani się nie rozmnażają.

## Struktura kodu
Projekt składa się z następujących klas:

### 1. **Klasa Organizm**
- Obejmuje wspólne cechy i funkcjonalności trzech gatunków.
- Stan licznika posiłków i życia.
- Zmniejszanie licznika życia.
- Sprawdzanie głodu organizmu.
- Możliwość rozmnażania.

### 2. **Klasa UstawieniaSymulacji**
- Singleton przechowujący globalne ustawienia symulacji.
- Definiuje symbole organizmów, limity żywieniowe i koszty rozmnażania.
- Metody zwracające symbole niszy i separatory niszy.

### 3. **Klasa GeneratorLosowy**
- Generuje pseudolosowe liczby w zadanych zakresach.
- Metoda `indeksyLosowe` losuje położenia w tablicy ekosystemu.

### 4. **Klasa Mieszkaniec i ZamiarMieszkanca**
- `ZamiarMieszkanca` przechowuje decyzje organizmów wynikające z otoczenia.
- `Mieszkaniec` to klasa abstrakcyjna, zawierająca metody interakcji organizmu ze środowiskiem.
- Metody:
  - Zwracanie symbolu mieszkańca.
  - Określanie typu organizmu (glon, grzyb, bakteria).
  - Podejmowanie akcji (ruch, jedzenie, rozmnażanie).

### 5. **Klasa Sasiedztwo**
- Przechowuje informacje o sąsiednich niszach wokół organizmu.
- Posiada tablicę `sasiad` 3x3, gdzie środkowa komórka oznacza aktualną niszę.
- Metody:
  - Zwracanie wskaźnika na sąsiednie komórki.
  - Losowe wybieranie położenia w zapisie literowym.
  - Umieszczanie informacji o sąsiednich organizmach.

### 6. **Klasa Osobniki**
- Zawiera klasy **Glon**, **Grzyb** i **Bakteria**, będące potomkami **Organizmu** i **Mieszkańca**.
- Implementuje metody wirtualne dla każdego gatunku.

### 7. **Klasa Nisza**
- Pojedyncza komórka wirtualnego ekosystemu.
- Zawiera wskaźnik `lokator`, który wskazuje na organizm.
- Metody:
  - Sprawdzanie stanu lokatora.
  - Sprawdzanie zamiaru lokatora.
  - Przeprowadzanie akcji symulacyjnych.

### 8. **Klasa Srodowisko**
- Reprezentuje planszę symulacji jako dynamiczną tablicę obiektów **Nisza**.
- Metody:
  - Określenie sąsiedztwa danej niszy.
  - Sprawdzenie, czy na planszy są żywe organizmy.
  - Losowa zmiana niszy na inną (dla grzybów i bakterii).
  - Wykonywanie cyklu życia organizmu.
  - Generowanie tekstowej reprezentacji ekosystemu.

## Jak uruchomić projekt?
1. **Sklonuj repozytorium:**
   ```sh
   git clone https://github.com/user/wirtualny-ekosystem.git
   ```
2. **Przejdź do katalogu projektu:**
   ```sh
   cd wirtualny-ekosystem
   ```
3. **Skompiluj kod:**
   ```sh
   g++ -o ekosystem main.cpp -std=c++11
   ```
4. **Uruchom symulację:**
   ```sh
   ./ekosystem
   ```

## Autorzy
- **Piotr Chrabąszcz**
- **Dominik Długołencki**
