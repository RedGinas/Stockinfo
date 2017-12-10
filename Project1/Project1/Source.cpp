#include <iostream>
#include <math.h>
#include <string>
#include <Windows.h>
using namespace std;

void Visener() {
	string str = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя",key,keystr="",stext,newtext="";
	cout << "шифруемый текст: ";
	cin >> stext;
	cout << "ключ: ";
	cin >> key;
	for (int i = 0; i < stext.length(); i++) 
		keystr += key[i%key.length()];
	cout << "строка ключа: " << keystr << endl;
	for (int i = 0; i < stext.length(); i++)
		if(str.find(stext[i])!=-1 && str.find(keystr[i])!=-1)
			newtext += str[(str.find(stext[i]) + str.find(keystr[i])) % 33];
		else newtext += stext[i];
	cout << "результат: " << newtext;
}

string not_repitkey(string key) {
	string newkey = "";
	for (int i = 0; i < key.length(); i++)
		if (newkey.find(key[i]) == -1)
			newkey += key[i];
	return newkey;
}

string strmader(string str,string alf) {
	for (int i = 0; i < alf.length(); i++)
		if (str.find(alf[i]) == -1)
			str += alf[i];
	return str;
}

void duobox() {
	string str = "абвгдеёжзийклмнопрстуфхцчшщыьэюя",str1,str2;
	string key1,key2,stext, newtext = "";
	cout << "ключ 1 и ключ 2: ";
	cin >> key1 >> key2;
	cout << "текст: ";
	cin >> stext;
	if (stext.length() % 2 == 1)
		stext += 'а';
	key1 = not_repitkey(key1);
	key2 = not_repitkey(key2);
	str1 = strmader(key1,str);
	str2 = strmader(key2,str);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 4; j++)
			cout << str1[i * 4 + j];
		cout << "     ";
		for (int j = 0; j < 4; j++)
			cout << str2[i * 4 + j];
		cout << endl;
	}

	for (int i = 0; i < stext.length(); i += 2)
	{
		if (str1.find(stext[i]) != -1 && str2.find(stext[i + 1]) != -1) {
			int strind1 = (str1.find(stext[i]) - str1.find(stext[i]) % 4) / 4,strind2=(str2.find(stext[i + 1]) - str2.find(stext[i + 1]) % 4)/4;
			int raz = abs(strind1 - strind2);
			if (strind1 == strind2) {			
				newtext += str2[str1.find(stext[i])];
				newtext += str1[str2.find(stext[i + 1])];
			}
			else if (strind1 > strind2) {
				newtext += str2[str2.find(stext[i + 1]) + 4 * raz];
				newtext += str1[str1.find(stext[i]) - 4 * raz];			
			}
			else {				
				newtext += str2[str2.find(stext[i + 1]) - 4 * raz];
				newtext += str1[str1.find(stext[i]) + 4 * raz];		
			}
		}
		else {
			newtext += stext[i];
			newtext += stext[i + 1];
		}
	}
	
	cout << newtext;
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	duobox();
	int i;
	cin >> i;
}

