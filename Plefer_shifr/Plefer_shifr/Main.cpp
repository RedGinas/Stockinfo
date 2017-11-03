#include "Main.h"
using namespace Plefer_shifr;
using namespace System;
using namespace System::Collections::Generic;
using namespace System::ComponentModel;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Text;
using namespace System::Threading::Tasks;
using namespace System::Windows::Forms;



Void Main::Choice_shif_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	choice = 0;//0-Шифрация
	this->Matrix->Size = System::Drawing::Size(120, 120);
	// 
	this->Key_Box->Size = System::Drawing::Size(278, 20);
	//
	this->Key_Label->Text = L"Ключевое слово";
	// 
	this->Out_Text->Size = System::Drawing::Size(384, 147);
	// 
	this->Info_Out_Lable->Text = L"Результат";
	// 
	this->Info_In_lable->Text = L"Исходный текст";
	this->Out_Text->Text = "";
}

Void Main::Choice_deshif_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	choice = 1;//1-Дешифрация
	this->Matrix->Size = System::Drawing::Size(120, 120);
	// 
	this->Key_Box->Size = System::Drawing::Size(278, 20);
	//
	this->Key_Label->Text = L"Ключевое слово";
	// 
	this->Out_Text->Size = System::Drawing::Size(384, 147);
	// 
	this->Info_Out_Lable->Text = L"Результат";
	// 
	this->Info_In_lable->Text = L"Исходный текст";
	this->Out_Text->Text = "";
}

Void Main::Choice_deshif_without_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	choice = 2;//2-Дешифрация без ключа
	this->Matrix->Size = System::Drawing::Size(120, 120);
	// 
	this->Key_Box->Size = System::Drawing::Size(0, 0);
	//
	this->Key_Label->Text = L"Ключевое слово : ";
	// 
	this->Out_Text->Size = System::Drawing::Size(384, 147);
	// 
	this->Info_Out_Lable->Text = L"Результат";
	// 
	this->Info_In_lable->Text = L"Исходный текст";
	this->Out_Text->Text = "";

}

Void Main::add_Database_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	choice = 3;//3-дополнение базы данных
	this->Matrix->Size = System::Drawing::Size(0, 0);
	// 
	this->Key_Box->Size = System::Drawing::Size(0, 0);
	//
	this->Key_Label->Text = L"";
	// 
	this->Out_Text->Size = System::Drawing::Size(0, 0);
	// 
	this->Info_Out_Lable->Text = L"";
	// 
	this->Info_In_lable->Text = L"Текст для дополнения";
	this->Out_Text->Text = "";
}

Void Main::Begining_Click(System::Object^  sender, System::EventArgs^  e)
{
	Error_text->Text = "";
	General_Text = Convert::ToString(Enter_Text->Text);
	int skore=0;
	int *space_mass;
	for (int fori = 0; fori < 5; fori++)
		table[fori] = new Char[8];
	if (space_skore(General_Text) >= 4 || choice==3) {
		String^ base = Read_DataBase();
		switch (choice)
		{
		case 0:
			Key = Convert::ToString(Key_Box->Text);

			for (int sk = 0; sk < 8; sk++)Key = Check_Key();
			Check_Text();
			Mass_Build();
			skore = space_skore(General_Text);
			space_mass = new int[skore];
			for (int i = 0; i < skore; i++) {
				space_mass[i] = General_Text->LastIndexOf(' ');
				General_Text = Remove_Space(space_mass, i, General_Text);
			}

			if (General_Text->Length % 2 == 1)
				General_Text = General_Text->Remove(General_Text->Length - 1, 1);

			General_Text = Shifr(General_Text);
			for (int i = skore - 1; i >= 0; i--) {
				General_Text = Insert_Space(space_mass, i, General_Text);
			}
			Out_Text->Text = General_Text;
			break;




		case 1:

			Key = Convert::ToString(Key_Box->Text);

			for (int sk = 0; sk < 8; sk++)Key = Check_Key();
			Check_Text();
			Mass_Build();
			skore = space_skore(General_Text);
			space_mass = new int[skore];
			for (int i = 0; i < skore; i++) {
				space_mass[i] = General_Text->LastIndexOf(' ');
				General_Text = Remove_Space(space_mass, i, General_Text);
			}

			if (General_Text->Length % 2 == 1)
				General_Text = General_Text->Remove(General_Text->Length - 1, 1);

			General_Text = De_Shifr(General_Text);
			for (int i = skore - 1; i >= 0; i--) {
				General_Text = Insert_Space(space_mass, i, General_Text);
			}
			Out_Text->Text = General_Text;

			break;





		case 2:
			base += " ";
			while ((!word1 || !word2 || !word3 || !word4 || !word5)&&j<base->Length) {
				General_Text = Convert::ToString(Enter_Text->Text);
				Key = "";
				while (base[j] != '\n' && base[j]!='\r' && j<base->Length-1){
					Key += base[j];
					j++;
				}if (j < base->Length)j+=2;
				if(Key!="")for (int sk = 0; sk < 8; sk++)Key = Check_Key();
				Mass_Build();
				skore = space_skore(General_Text);
				space_mass = new int[skore];
				for (int i = 0; i < skore; i++) {
					space_mass[i] = General_Text->LastIndexOf(' ');
					General_Text = Remove_Space(space_mass, i, General_Text);
				}
				if (General_Text->Length % 2 == 1)
					General_Text = General_Text->Remove(General_Text->Length - 1, 1);
				General_Text = De_Shifr(General_Text);
				for (int i = skore - 1; i >= 0; i--) {
					General_Text = Insert_Space(space_mass, i, General_Text);
				}
				word1 = Words_Check_of_true(General_Text, base, 1);
				word2 = Words_Check_of_true(General_Text, base, 2);
				word3 = Words_Check_of_true(General_Text, base, 3);
				word4 = Words_Check_of_true(General_Text, base, 4);
				word5 = Words_Check_of_true(General_Text, base, 5);
			}
			if (j >= base->Length) {
				Error_text->Text = "Не удалось найти слово\nдля дешифрации";
			}
			else {
				Key_Label->Text += Convert::ToString(Key);
				Out_Text->Text = General_Text;
			}
			break;





		case 3:
			Insert_In_Database(General_Text);
			break;
		default:
			break;
		}
	}
	else Error_text->Text = "Шифруймый/дешифруймый текст\nдолжен содержать\nминимум 5 слов";
}


[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew Main());
	return 0;
}
