#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>

using namespace std;

vector<int> collection; // multizbior A
vector<int> map;        // rozwiazanie

int greatest = 0;
int ammount_of_elem = 0;
int check = 0;
bool found = false;
bool *tab;
bool *is_sum;

void read() {                        // wczytanie instancji

	ifstream file;
	int number;

	file.open("set.txt", std::ios::in);
	if (file.good() == false)
		cout << "Blad przy otwieraniu pliku" << endl;
	else {
		while (file.good()) {
			file >> number;
			collection.push_back(number);
		}
		cout << "Wczytano instacje:" << endl;
		file.close();
	}
}

int check_collection() {            //Sprawdzanie zaleznosci liczby ciec od licznosci podanego zbioru
	int k = 1;
	cout<<endl<<endl<< "Sprawdzanie zaleznosci liczby ciec od licznosci podanego zbioru..."<<endl;
	while(ammount_of_elem*2 != k*(k+1)){
		k++;
		if (k*(k + 1) > ammount_of_elem * 2) {
			cout << "Nieprawidlowa wartosc dla podanej instancji" << endl;
			return 0;
		}
	}
	cout<<"Multizbior jest prawidlowy"<<endl;
	return k;
}

bool sum_compatible() {             // sprawdzenie zgodnosci nowego wezla
	int local_sum = 0;
	bool a = 1;
	for (int i = 0; i < ammount_of_elem; i++) {
		is_sum[i] = false;
	}
	for (int i = 0; i < map.size(); i++) {
		local_sum = 0;
		for (int j = i; j < map.size(); j++) {
			a = 0;
			local_sum += map[j];
			if (local_sum > greatest) {
				return 0;
			}
			if (find(collection.begin(), collection.end(), local_sum) == collection.end()) {
				return 0;
			}
			for (int i = 0; i < ammount_of_elem; i++) {
				if (collection[i] == local_sum && is_sum[i] == false) {
					is_sum[i]= true;
					a = 1;
					break;

				}
			}
			if (a == 0)
				return 0;
		}
	}
	return 1;
}

bool SumAll() {
	int sum = 0;
	for (int i = 0; i < map.size(); i++)
		sum += map[i];
	if (sum == greatest)
		return 1;
	else return 0;
}
void search_collection(int dodaj, int *jest, int poziom_zaglebienia) {    // szukaj - procedura reukurencyjna

	vector<int> checked;
	int item;

	map.push_back(dodaj);       // dodanie wezla

	for (int i = 0; i < ammount_of_elem; i++) {
		if (collection[i] == dodaj && tab[i] == 0) {
				tab[i] = true;
				break;                                                    // oznaczenie nieuzytego jeszcze fragmentu
		}
	}

	if (poziom_zaglebienia == 0)
		checked.push_back(dodaj);

	if (sum_compatible()) {
		if (poziom_zaglebienia < check-1) {
			for (int i = 0; i < ammount_of_elem; i++) {
				if(tab[i] == false){
					checked.push_back(collection[i]);
					search_collection(collection[i], jest, (poziom_zaglebienia + 1));
					break;
				}
			}
		}
		else if (SumAll()) {
			*jest = true;
		}
		else {
			for (int i = 0; i < ammount_of_elem; i++) {
				int c = map[map.size() - 1];
				if (collection[i] == c && tab[i] ==true) {
					tab[i] = false; break;
				}
			}
			map.pop_back();
			return;
		}
	}
	else {
		for (int i = 0; i < ammount_of_elem; i++) {
			int c = map[map.size() - 1];
			if (collection[i] == c && tab[i] == true) {
				tab[i] = false; break;
			}
		}
		map.pop_back();
		return;

	}
 	if (*jest == true) {
		return;
	}
	else {
		for (int i = 0; i < ammount_of_elem; i++) {
			item = collection[i];
			if (find(checked.begin(), checked.end(), item) == checked.end() && tab[i] == false) {
				checked.push_back(collection[i]);
				search_collection(collection[i], jest, (poziom_zaglebienia + 1));
				if (*jest == true) return;
			}
		}
		for (int i = 0; i < ammount_of_elem; i++) {
			int c = map[map.size() - 1];
			if (collection[i] == c && tab[i] == true) {
					tab[i] = false; break;
			}
		}
		map.pop_back();
		return;

	}
}
int main(){

	read();

	for (int i = 0; i < collection.size(); i++) {
		cout << collection[i] << " ";
	}

	int is_found = false;
	clock_t start, stop;

	sort(collection.begin(), collection.end());

	greatest = collection[collection.size() - 1];
	ammount_of_elem = collection.size();
	check = check_collection();

	if (check != 0) {
		tab = new bool[ammount_of_elem];
		is_sum = new bool[ammount_of_elem];


		for (int i = 0; i < ammount_of_elem; i++) {
			tab[i] = false;
			is_sum[i] = false;
		}
		cout << endl;
		start = clock();
		for (int i = 0; i < collection.size(); i++) {
			search_collection(collection[i], &is_found, 0);
			if (is_found == true) break;
		}
		stop = clock();
		long time = (long)(stop - start);
		if (is_found == false)
			cout << "Brak rozwiazania" << endl;
		else {
			cout << "Wyszukana mapa: " << endl;
			for (int i = 0; i < map.size(); i++)
				cout << map[i] << " ";
            cout<<endl;
			cout << "Czas wyszukiwania: " << time << "ms" << endl;
		}
	}

}
