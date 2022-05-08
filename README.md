# Recursive_algorithm_constructing_restriction_map
 Mapping based on partial digestion problem

Example of input txt file:

2 3 4 4 5 5 6 6 6 7 7 8 8 9 10 11 11 11 11 12 13 13 14 14 15 15 16 16 17 18 19 19 19 20 20 21 21 22 23 23 25 25 25 26 26 27 27 27 30 30 31 31 32 32 35 35 36 36 38 38 38 40 41 42 42 43 44 46 46 49 51 52 53 57 57 61 63 67

Output:

Wczytano instancje: 
2 3 4 4 5 5 6 6 6 7 7 8 8 9 10 11 11 11 11 12 13 13 14 14 15 15 16 16 17 18 19 19 19 20 20 21 21 22 23 23 25 25 25 26 26 27 27 27 30 30 31 31 32 32 35 35 36 36 38 38 38 40 41 42 42 43 44 46 46 49 51 52 53 57 57 61 63 67

Sprawdzanie zaleznosci liczby ciec od licznosci podanego zbioru...

Multizbior jest prawidlowy

Wyszukana mapa:
4 6 5 8 3 9 5 2 4 7 8 6

Czas wyszukiwania: 4667ms

1. Definicja problemu:

Mapowanie metodą częściowego trawienia. Skonstruowanie mapy restrykcyjnej zgodnej z podanym multizbiorem (zbiorem długości odcinków uzyskanych we wszystkich miejscach cięć przez enzym).

2. Implementacja:

•	Wczytanie z pliku multizbioru

•	Sprawdzenie multizbioru, kolejne punkty są realizowane tylko jeśli istnieje liczba cięć przekładająca się na tę liczność zgodnie z poniższym symbolem Newtona.
 
Sprawdzany warunek w programie: 2|A| = (k+1)(k+2)             
 gdzie k – liczba cięć, A – multizbiór
•	Wyszukiwanie mapy realizowane jest poprzez rekurencyjny algorytm przeszukiwania z nawrotami. Funkcja ‘szukaj’ sprawdza każdy element podanej instancji, sprawdzając za każdym razem czy dodanie danego elementu do rozwiązania, jakim jest mapa, jest zgodne z jej obecną postacią. W tym celu sprawdzamy czy dla badanego miejsca restrykcyjnego obecne są w multizbiorze wszystkie odległości pomiędzy nim i już obecnymi w rozwiązaniu miejscami oraz końcami cząsteczki. Przechodzimy w ten sposób ’’drzewo wywołań’’ funkcji ‘szukaj’ zawracając zawsze gdy ścieżka którą podążamy nie pasuje do rozwiązania. Gdy wyczerpane zostaną wszystkie następniki danego węzła i nie zostało znaleziona możliwa dalsza ścieżka wracamy o dwa ‘poziomy’ wyżej. Procedura kończy się w momencie znalezienia pierwszego pasującego i kompletnego rozwiązania.

•	Na wyjściu wyświetlamy znalezioną mapę lub informację o braku rozwiązania 

3.	Testy: 

•	ns-PDP-11a-asc.txt (całościowy wynik działania programu):
Wczytano instancje: 
2 3 4 4 5 5 6 6 6 7 7 8 8 9 10 11 11 11 11 12 13 13 14 14 15 15 16 16 17 18 19 19 19 20 20 21 21 22 23 23 25 25 25 26 26 27 27 27 30 30 31 31 32 32 35 35 36 36 38 38 38 40 41 42 42 43 44 46 46 49 51 52 53 57 57 61 63 67

Sprawdzanie zaleznosci liczby ciec od licznosci podanego zbioru...

Multizbior jest prawidlowy

Wyszukana mapa:
4 6 5 8 3 9 5 2 4 7 8 6

Czas wyszukiwania: 4667ms

...

4.	Wnioski:

Czas pracy algorytmu zależy w dużym stopniu od długości fragmentów w danej instancji. Przy powtarzających się, krótkich odcinkach wyszukiwanie rozwiązania trwa znacznie dłużej (np. dla ins-PDP-14a-asc.txt algorytm potrzebował aż 21,5 min). Dobrze prezentują to również wyniki dla wygenerowanych własnych instancji (Test 1 i 2). Na wydłużenie działania algorytmu ma też generalnie wpływ większa ilość pozycji w instancji. Przed rozpoczęciem procedury przeszukiwania wektor z elementami instancji jest sortowany, zatem kolejność występowania wartości ma marginalny wpływ na algorytm (widać to na przykładzie instancji ins-PDP-14b-asc.txt oraz ins-PDP-14b-desc.txt, a także ins-PDP-11b-asc.txt oraz ins-PDP-11b-desc.txt).
