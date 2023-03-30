#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;
//структура ТОВАР
struct TOVAR
{

	string NAME;
	string TYPE;
	string SORT;
	int QUANTITY;
	float COST;
};
//функція вводу даних в масив структур
void take_data(TOVAR& tovar)
{
	cout << "Iм'я:  ";
	cin >> tovar.NAME;
	char change = 1;
	cout << "Натисніть:\n 1 - Поштучно\n  2 - Кілограмах" << endl;
	while (true) {
		change = _getch();

		if (change == '1') {
			tovar.TYPE = "ШТ.";
			break;
		}
		else if (change == '2') {
			tovar.TYPE = "Кг";
			break;
		}
	}
	cout << "Сорт:  ";
	cin >> tovar.SORT;
	if (tovar.TYPE == "ШТ.")cout << "Кiлькiсть:  "; else if (tovar.TYPE == "Кг")cout << "Вага Кг.:  ";

	cin >> tovar.QUANTITY;
	cout << "Вартiсть грн:  ";
	cin >> tovar.COST;
}
//функція В=виводу елементів масиву струтур
void Print(TOVAR& tovar)
{

	if (tovar.TYPE == "ШТ.")
	{

		cout << tovar.NAME << "\t\t" << tovar.SORT << "\t\t" << tovar.QUANTITY << "\t\t\t-\t\t\t" << tovar.COST << endl;
	}
	else if (tovar.TYPE == "Кг")
	{
		cout << tovar.NAME << "\t\t" << tovar.SORT << "\t\t-\t\t\t" << tovar.QUANTITY << "\t\t\t" << tovar.COST << endl;
	}

}

//Добавить товар
void addTovar(TOVAR*& people, int& length, const TOVAR& newPerson) {

	TOVAR* newPeople = new TOVAR[length + 1];
	for (int i = 0; i < length; i++) {
		newPeople[i] = people[i];
	}
	newPeople[length] = newPerson;
	delete[] people;
	people = newPeople;
	length++;
}
//Видалити товар
void removeElement(TOVAR tovar[], int& length, int index) {
	if (index < 0 || index >= length) {
		cout << "\nЕлемент з таким номером не знайдено!" << endl;
		return;
	}

cout << "\nВидалено елемент №" << index+1 << endl;
Print(tovar[index]);
	// зсуваємо елементи вліво починаючи з наступного елементу
	for (int i = index+1 ; i < length; i++) {
		tovar[i - 1] = tovar[i];
	}
	
	// зменшуємо розмір масиву
	length--;
}




int main()
{
	SetConsoleCP(1251); // встановлення кодування Windows-1251 в  потік введення
	SetConsoleOutputCP(1251); // встановлення кодування Windows-1251 в  потік виведення 
	//для коректним виведення в консоль тільки так))
	int i = 0;
	float sum = 0;
	char change;
	TOVAR tovar1;
	TOVAR *tovar = new TOVAR[0];
	int len = sizeof(tovar) / sizeof(tovar[0]);
	while (true) {
	cout << "\n1 - Добавить товар\n2 - Показати список\n3 - видалити товар\n";
	//вибір дії
	while (true)
		{
			change = _getch();
			if (change == 1||2||3 ) break;
		}

		//Якщо 1 (ввід)
		if (change == '1') {
			system("cls");
			addTovar(tovar, len, tovar1);

			while (i < len) {
				system("cls");
				cout << "# " << i + 1 << endl;
				take_data(tovar[i]);
				++i;
			}
	
		}

		//Якщо 2 (Вивід)
		if (change == '2') {
			system("cls");

			cout << "\n\n#\tІм'я \t\tСорт\t\tКількість ШТ.\t\tВага в Кг.\t\tВартість грн" << endl;
			if (len == 0)
			{
				cout << "-\n";

			}
			sum = 0;
			for (int i = 0; i < len; i++)
			{
				sum += tovar[i].COST;
				cout << "________________________________________________________________________________________________________________" << endl;
				cout << i + 1 << "\t";
				Print(tovar[i]);
			}
			cout << "________________________________________________________________________________________________________________" << endl;
			cout << "\nЗагальна вартість:\t" << sum << endl;;


		}
		//якщо 3 (видалення з виводом по номеру)
		if (change == '3')
		{
			--i;
			int n = 0;
			system("cls");

			cout << "\n\n#\tІм'я \t\tСорт\t\tКількість ШТ.\t\tВага в Кг.\t\tВартість грн" << endl;
			if (len == 0)
			{
				cout << "-\n";

			}
			for (int i = 0; i < len; i++)
			{
				cout << "________________________________________________________________________________________________________________" << endl;
				cout << i + 1 << "\t";
				Print(tovar[i]);
			}
			cout << "________________________________________________________________________________________________________________" << endl;
			cout << "\nНомер елемента для видалення: \t" << endl;
			cin >> n;
			removeElement(tovar, len, n-1);
		}
		//вихід
		if (change == 'x')break;
	}
	delete[] &tovar;
	return 0;
}