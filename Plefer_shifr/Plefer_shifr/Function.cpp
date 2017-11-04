#include <iomanip>
#include "Main.h"


using namespace Plefer_shifr;
using namespace System;
using namespace System::IO;

//проверка вводимого текста на нечётность и повторение 2-х букв на идушем подряд чётном индексном месте
Void Main::Check_Text() {

	String^ pust = Pust();
	if (General_Text->Length % 2 == 1)
		General_Text += pust;
	for (int i = 0; i < General_Text->Length; i += 2)
		if (General_Text[i] == General_Text[i + 1] && General_Text[i] != ' ') {
			General_Text = General_Text->String::Insert(i + 1, pust);
			General_Text = General_Text->String::Insert(i + 3, pust);
			i += 2;
		}
	String^ space = " ";
	for (int i = 0; i < General_Text->Length - 1; i++) {
		if (General_Text[i] == ' ' && General_Text[i + 1] == ' ')
		{
			General_Text = General_Text->Remove(i, 2);
			General_Text = General_Text->String::Insert(i, space);
			i--;
		}
	}
	General_Text = General_Text->ToLower();
}

//подсчёт количества пробелов
Int32 Main::space_skore(String^ Text) {
	int skore = 0;
	for (int i = 0; i < Text->Length - 1; i++) {
		if (Text[i] == ' ')
			skore++;
	}
	return skore;
}

//проверка ключа на ноличие повторяюшехся букв
String^ Main::Check_Key() {
	int skore = 0;
	String^ NewKey;
	NewKey = Convert::ToString(Key[0]);
	for (int forj = 0; forj < Key->Length; forj++) {
		skore = 0;
		for (int fori = 0; fori < NewKey->Length; fori++)
			if (Key[forj] == Key[fori])fori = Key->Length;//если в новом ключе уже есть данный элемент
			else skore++;
			if (skore == NewKey->Length && Key[forj] != 32)NewKey += Convert::ToString(Key[forj]);//если прошли до конца нового ключа и нет повторений элемент добавляется в ключ
	}
	NewKey = NewKey->ToLower();
	return NewKey;
}

//выбор символа пустышки
String^ Main::Pust()
{
	srand(time(NULL));
	int puste = 0 + rand() % 40;
	String^ r = Convert::ToString(CharTable[puste]);
	return r;
}

//постоение шифрационной матрицы
Void Main::Mass_Build() {
	String ^NewKey = Key;
	Matrix->Text = "";
	String ^str = "";
	for (int i = 0; i < CharTable->Length; i++)
		if (NewKey->IndexOf(CharTable[i]) == (-1)) NewKey += CharTable[i];
	int skore = 0;
	for (int i = 0; i < 5; i++) {
		str = "";
		for (int j = 0; j < 8; j++) {
			table[i][j] = (NewKey[skore]);
			str += NewKey[skore] + " ";
			skore++;


		}
		Matrix->Text += str;
		Matrix->Text += "\n";
	}
}

//шифрация
String^ Main::Shifr(String ^str) {
	int i, j, stri1, strj1, stri2, strj2;
	String^ zamena1, ^zamena2;
	for (int strl = 0; strl < str->Length - 1; strl += 2) {
		zamena1 = "";
		zamena2 = "";
		for (i = 0; i < 5; i++) {
			for (j = 0; j < 8; j++)
			{
				if (table[i][j] == str[strl])
				{
					stri1 = i;
					strj1 = j;
				}
				if (table[i][j] == str[strl + 1])
				{
					stri2 = i;
					strj2 = j;
				}
			}
		}
		if (stri1 == stri2 || strj1 == strj2) {
			if (strj1 == strj2) {
				if (stri1 != 4)
					zamena1 += table[stri1+1][strj1];
				else zamena1 += table[0][strj1];
				if (stri2 != 4)
					zamena2 += table[stri2+1][strj2];
				else zamena2 += table[0][strj2];
			}
			if (stri1 == stri2) {
				if (strj1 != 7)
					zamena1 += table[stri1][strj1+1];
				else zamena1 += table[stri1][0];
				if (strj2 != 7)
					zamena2 += table[stri2][strj2 + 1];
				else zamena2 += table[stri2][0];
			}
		}
		else {
			zamena1 += table[stri2][strj1];
			zamena2 += table[stri1][strj2];
		}
		str = str->Remove(strl, 1);
		str = str->Insert(strl, zamena1);
		str = str->Remove(strl + 1, 1);
		str = str->Insert(strl + 1, zamena2);
	}
	return str;
}

//дешифрация
String^ Main::De_Shifr(String ^str) {
	int i, j, stri1, strj1, stri2, strj2;
	String^ zamena1, ^zamena2;
	for (int strl = 0; strl < str->Length - 1; strl += 2) {
		zamena1 = "";
		zamena2 = "";
		for (i = 0; i < 5; i++) {
			for (j = 0; j < 8; j++)
			{
				if (table[i][j] == str[strl])
				{
					stri1 = i;
					strj1 = j;
				}
				if (table[i][j] == str[strl + 1])
				{
					stri2 = i;
					strj2 = j;
				}
			}
		}
		if (stri1 == stri2 || strj1 == strj2) {
			if (strj1 == strj2) {
				if (stri1 != 0)
					zamena1 += table[stri1 - 1][strj1];
				else zamena1 += table[4][strj1];
				if (stri2 != 0)
					zamena2 += table[stri2 - 1][strj2];
				else zamena2 += table[4][strj2];
			}
			if (stri1 == stri2) {
				if (strj1 != 0)
					zamena1 += table[stri1][strj1 - 1];
				else zamena1 += table[stri1][7];
				if (strj2 != 0)
					zamena2 += table[stri2][strj2 - 1];
				else zamena2 += table[stri2][7];
			}
		}
		else {
			zamena1 += table[stri2][strj1];
			zamena2 += table[stri1][strj2];
		}
		str = str->Remove(strl, 1);
		str = str->Insert(strl, zamena1);
		str = str->Remove(strl + 1, 1);
		str = str->Insert(strl + 1, zamena2);
	}
	return str;
}

//удаление пробелов из строки с сохранением их позиций
String ^ Main::Remove_Space(int *mass, int skore, String ^ text) {
	text = text->Remove(mass[skore], 1);
	return text;
}

//занесение пробелов в строку по их позициям
String ^ Main::Insert_Space(int *mass, int skore, String ^ text) {
	String ^space = " ";
	text = text->Insert(mass[skore], space);
	return text;
}

//дополнение базы данных
Void Main::Insert_In_Database(String^ add) {
	add += " ";
	bool go = false;
	String^ word;
		for (int i = 0; i < add->Length;)
		{
			go = false;
			StreamReader ^streamReader = gcnew StreamReader("wordbase.txt", Encoding::GetEncoding(1251)); //Открываем файл для чтения
			String ^str = ""; //Объявляем переменную, в которую будем записывать текст из файла
				str = streamReader->ReadToEnd();//В переменную str по строчно записываем содержимое файла
				str=str->ToLower();
			word = "";
			while (add[i] != ' ' && i < add->Length - 1 && add[i]!='\n') {
				word += add[i];
				i++;
			}
			for (int j = 0; j < CharTablError->Length && !go; j++) {
				if (word->IndexOf(CharTablError[j]) != -1)go = true;
			}
			if (i < add->Length)i++;
			int pos = str->IndexOf(word);
			if (pos == -1 && !go) {
				streamReader->Close();
				StreamWriter^ write_text = gcnew StreamWriter("wordbase.txt",true);  //Класс для записи в файл
				write_text->WriteLine(word); //Записываем в файл текст из текстового поля
				write_text->Close(); // Закрываем файл
			}
			else streamReader->Close();
		}
}

//функция сцитывания базы данных
String^ Main::Read_DataBase() {
	StreamReader ^streamReader = gcnew StreamReader("wordbase.txt", Encoding::GetEncoding(1251)); //Открываем файл для чтения
	String ^str = ""; //Объявляем переменную, в которую будем записывать текст из файла
	str = streamReader->ReadToEnd();//В переменную str заносится содержимое всего файла
	str = str->ToLower();
	return str;
}

//Функция проверки дишифрованого слова на правильность
Boolean Main::Words_Check_of_true(String^ str,String^ base,int Number_word) {
	String^ word;
	int i = 0;
	str += " ";
	for (int j = 0; j < Number_word; j++) {
		word = "";
		while (i < str->Length - 1 && str[i] != ' ') {
			word += str[i];
			i++;
		}
	}
	int temp = base->IndexOf(word);
	if (temp == -1)return false;
	else return true;
}

//запрет введение ненужных символов в textbox
Void Main::Enter_Text_Function(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	bool rus = false;
	for (int fori = 0; fori < 40 && !rus; fori++)
		if (e->KeyChar == CharTable[fori])rus = true;
	for (int fori = 0; fori < 33 && !rus; fori++)
		if (e->KeyChar == SecondCharTable[fori])rus = true;
	if (!rus && e->KeyChar != 32 && e->KeyChar != 8) e->Handled = true;
}