#include <iostream>   // Umozliwia wyswietlanie wynikow w konsoli
#include <vector>     // Udostepnia kontener vector
#include <list>       // Udostepnia liste list
#include <algorithm>  // Udostepnia funkcje sort()
#include <chrono>     // Umozliwia mierzenie czasu
#include <cstdlib>    // Udostepnia funkcje rand()

using namespace std;
using namespace chrono;

int main() {

    // Liczba elementow, ktore bedziemy przechowywac
    const int N = 100000;


    // 1. TABLICA  [------==++==------]

    // Tworzymy tablice o rozmiarze 100001.
    // Jeden dodatkowy element pozwoli nam wstawic liczbe.
    int t[100001];

    // Wypelniamy tablice losowymi liczbami od 0 do 999.
    // Petla wykona sie 100000 razy.
    for (int i = 0; i < N; i++) {
        t[i] = rand() % 1000;
    }

    // ---------- WSTAWIANIE ----------

    // Zapisujemy czas rozpoczecia pomiaru.
    auto start = steady_clock::now();

    // Przesuwamy elementy w prawo, aby zrobic miejsce
    // na nowa liczbe w srodku tablicy.
    for (int i = N; i > N / 2; i--) {
        t[i] = t[i - 1];
    }

    // Wstawiamy liczbe 500 na srodku tablicy.
    t[N / 2] = 500;

    // Zapisujemy czas zakonczenia pomiaru.
    auto stop = steady_clock::now();

    // Odejmujemy czas poczatkowy od koncowego.
    // Wynik zamieniamy na mikrosekundy i wyswietlamy.
    cout << "Tablica - wstawianie: "
         << duration_cast<microseconds>(stop - start).count()
         << " Mikrosekund " << endl;


    // ---------- SORTOWANIE ----------

    // Rozpoczynamy nowy pomiar czasu.
    start = steady_clock::now();

    // Sortujemy wszystkie 100001 elementow tablicy.
    // sort() ustawia liczby od najmniejszej do najwiekszej.
    sort(t, t + N + 1);

    // Konczymy pomiar sortowania.
    stop = steady_clock::now();

    // Wyswietlamy czas sortowania w mikrosekundach.
    cout << "Tablica - sortowanie: "
         << duration_cast<microseconds>(stop - start).count()
         << " Mikrosekund" << endl;


    // ---------- USUWANIE ----------

    // Rozpoczynamy pomiar usuwania.
    start = steady_clock::now();

    // Przesuwamy elementy w lewo.
    // W ten sposob nadpisujemy element ze srodka.
    // Tablica ma staly rozmiar, wiec nie mozemy
    // fizycznie zmniejszyc jej rozmiaru.
    for (int i = N / 2; i < N; i++) {
        t[i] = t[i + 1];
    }

    // Konczymy pomiar usuwania.
    stop = steady_clock::now();

    // Wyswietlamy czas usuwania.
    cout << "Tablica - usuwanie: "
         << duration_cast<microseconds>(stop - start).count()
         << " Mikrosekund" << endl;




    // 2. VECTOR [------==++==------]

    // Tworzymy vector, ktory przechowuje liczby typu int.
    vector<int> v(N);

    // Wypelniamy vector 100000 losowymi liczbami.
    for (int i = 0; i < N; i++) {
        v[i] = rand() % 1000;
    }


    // ---------- WSTAWIANIE ----------

    // Zapisujemy czas rozpoczecia.
    start = steady_clock::now();

    // begin() wskazuje poczatek vectora.
    // Dodajemy N / 2, aby wskazac jego srodek.
    // insert() wstawia liczbe 500 w tym miejscu.
    v.insert(v.begin() + N / 2, 500);

    // Zapisujemy czas zakonczenia.
    stop = steady_clock::now();

    // Wyswietlamy czas wstawiania.
    cout << "\nVector - wstawianie: "
         << duration_cast<microseconds>(stop - start).count()
         << " Mikrosekund" << endl;


    // ---------- SORTOWANIE ----------

    // Rozpoczynamy pomiar sortowania.
    start = steady_clock::now();

    // Sortujemy wszystkie elementy vectora.
    // begin() oznacza pierwszy element,
    // a end() wskazuje pozycje za ostatnim elementem.
    sort(v.begin(), v.end());

    // Konczymy pomiar sortowania.
    stop = steady_clock::now();

    // Wyswietlamy czas sortowania.
    cout << "Vector - sortowanie: "
         << duration_cast<microseconds>(stop - start).count()
         << " Mikrosekund" << endl;


    // ---------- USUWANIE ----------

    // Rozpoczynamy pomiar usuwania.
    start = steady_clock::now();

    // Obliczamy srodek vectora.
    // erase() usuwa element znajdujacy sie w tym miejscu.
    v.erase(v.begin() + v.size() / 2);

    // Konczymy pomiar usuwania.
    stop = steady_clock::now();

    // Wyswietlamy czas usuwania.
    cout << "Vector - usuwanie: "
         << duration_cast<microseconds>(stop - start).count()
         << " Mikrosekund" << endl;



    // 3. LISTA [------==++==------]


    // Tworzymy pusta liste liczb calkowitych.
    list<int> l;

    // Dodajemy do listy 100000 losowych liczb.
    // push_back() dodaje element na koncu listy.
    for (int i = 0; i < N; i++) {
        l.push_back(rand() % 1000);
    }


    // ---------- WSTAWIANIE ----------

    // Rozpoczynamy pomiar czasu.
    start = steady_clock::now();

    // begin() wskazuje pierwszy element listy.
    auto it = l.begin();

    // advance() przesuwa iterator o N / 2 pozycji.
    // W ten sposob dochodzimy do srodka listy.
    advance(it, N / 2);

    // Wstawiamy liczbe 500 w miejscu wskazanym przez iterator.
    l.insert(it, 500);

    // Konczymy pomiar wstawiania.
    stop = steady_clock::now();

    // Wyswietlamy czas wstawiania.
    // Pomiar obejmuje rowniez szukanie srodka listy.
    cout << "\nLista - wstawianie: "
         << duration_cast<microseconds>(stop - start).count()
         << " Mikrosekund" << endl;


    // ---------- SORTOWANIE ----------

    // Rozpoczynamy pomiar sortowania.
    start = steady_clock::now();

    // Lista posiada wlasna funkcje sort().
    // Sortujemy liczby od najmniejszej do najwiekszej.
    l.sort();

    // Konczymy pomiar sortowania.
    stop = steady_clock::now();

    // Wyswietlamy czas sortowania.
    cout << "Lista - sortowanie: "
         << duration_cast<microseconds>(stop - start).count()
         << " Mikrosekund" << endl;


    // ---------- USUWANIE ----------

    // Rozpoczynamy pomiar usuwania.
    start = steady_clock::now();

    // Wracamy do poczatku listy.
    it = l.begin();

    // Ponownie przechodzimy do srodka listy.
    advance(it, l.size() / 2);

    // Usuwamy element wskazywany przez iterator.
    l.erase(it);

    // Konczymy pomiar usuwania.
    stop = steady_clock::now();

    // Wyswietlamy czas usuwania.
    // Pomiar obejmuje tez przejscie do srodka.
    cout << "Lista - usuwanie: "
         << duration_cast<microseconds>(stop - start).count()
         << " Mikrosekund" << endl;


    // Zwracamy 0, co oznacza poprawne zakonczenie programu.
    return 0;
}
