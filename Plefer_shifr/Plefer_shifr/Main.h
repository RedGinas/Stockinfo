#pragma once
#include "Main.h"
using namespace System;
using namespace System::Collections::Generic;
using namespace System::ComponentModel;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Text;
using namespace System::Threading::Tasks;
using namespace System::IO;
using namespace System::Windows::Forms;
		

namespace Plefer_shifr {
	/// <summary>
	/// Сводка для Main
	/// </summary>
	public ref class Main : public Form
	{
	public:
		int choice=0;
		Char **table = new Char*[5];
		String^ General_Text,^pust,^Key;
		String ^CharTable = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя.,:-!?\"";//строка ограничение вводимых букв
		String ^CharTablError = "QAZWSXEDCRFVTGBNHYUJM<KIOL>;P{}\'qazxswedcvfrtgbnhyujmkiol/p[]1234567890@#$%^&*()+=_№";//строка запрета занесения в базу данных определённых букв
		String ^SecondCharTable = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";//строка ограничение вводимых букв
		int j = 0;
		bool word1 = false, word2 = false, word3 = false, word4 = false, word5 = false;
	private: System::Windows::Forms::RadioButton^  add_Database;
	private: System::Windows::Forms::Label^  Error_text;
	public:
		char *End_Text;
		Main(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}	


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^  Enter_Text;
	private: System::Windows::Forms::RichTextBox^  Matrix;
	private: System::Windows::Forms::Button^  Begining;

	private: System::Windows::Forms::TextBox^  Key_Box;
	private: System::Windows::Forms::Label^  Key_Label;
	private: System::Windows::Forms::RichTextBox^  Out_Text;
	private: System::Windows::Forms::Label^  Info_Out_Lable;
	private: System::Windows::Forms::Label^  Info_In_lable;
	private: System::Windows::Forms::RadioButton^  Choice_shif;
	private: System::Windows::Forms::Panel^  Choice_Function_Box;

	private: System::Windows::Forms::RadioButton^  Choice_deshif_without;
	private: System::Windows::Forms::RadioButton^  Choice_deshif;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Enter_Text = (gcnew System::Windows::Forms::RichTextBox());
			this->Matrix = (gcnew System::Windows::Forms::RichTextBox());
			this->Begining = (gcnew System::Windows::Forms::Button());
			this->Key_Box = (gcnew System::Windows::Forms::TextBox());
			this->Key_Label = (gcnew System::Windows::Forms::Label());
			this->Out_Text = (gcnew System::Windows::Forms::RichTextBox());
			this->Info_Out_Lable = (gcnew System::Windows::Forms::Label());
			this->Info_In_lable = (gcnew System::Windows::Forms::Label());
			this->Choice_shif = (gcnew System::Windows::Forms::RadioButton());
			this->Choice_Function_Box = (gcnew System::Windows::Forms::Panel());
			this->add_Database = (gcnew System::Windows::Forms::RadioButton());
			this->Choice_deshif_without = (gcnew System::Windows::Forms::RadioButton());
			this->Choice_deshif = (gcnew System::Windows::Forms::RadioButton());
			this->Error_text = (gcnew System::Windows::Forms::Label());
			this->Choice_Function_Box->SuspendLayout();
			this->SuspendLayout();
			// 
			// Enter_Text
			// 
			this->Enter_Text->Location = System::Drawing::Point(12, 28);
			this->Enter_Text->Name = L"Enter_Text";
			this->Enter_Text->Size = System::Drawing::Size(384, 147);
			this->Enter_Text->TabIndex = 4;
			this->Enter_Text->Text = L"";
			this->Enter_Text->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Main::Enter_Text_Function);
			// 
			// Matrix
			// 
			this->Matrix->Location = System::Drawing::Point(521, 218);
			this->Matrix->Name = L"Matrix";
			this->Matrix->Size = System::Drawing::Size(138, 120);
			this->Matrix->TabIndex = 6;
			this->Matrix->Text = L"";
			// 
			// Begining
			// 
			this->Begining->Location = System::Drawing::Point(521, 344);
			this->Begining->Name = L"Begining";
			this->Begining->Size = System::Drawing::Size(138, 24);
			this->Begining->TabIndex = 7;
			this->Begining->Text = L"Выполнить";
			this->Begining->UseVisualStyleBackColor = true;
			this->Begining->Click += gcnew System::EventHandler(this, &Main::Begining_Click);
			// 
			// Key_Box
			// 
			this->Key_Box->Location = System::Drawing::Point(118, 181);
			this->Key_Box->Name = L"Key_Box";
			this->Key_Box->Size = System::Drawing::Size(278, 20);
			this->Key_Box->TabIndex = 9;
			this->Key_Box->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Main::Enter_Text_Function);
			// 
			// Key_Label
			// 
			this->Key_Label->AutoSize = true;
			this->Key_Label->Location = System::Drawing::Point(12, 184);
			this->Key_Label->Name = L"Key_Label";
			this->Key_Label->Size = System::Drawing::Size(90, 13);
			this->Key_Label->TabIndex = 10;
			this->Key_Label->Text = L"Ключевое слово";
			// 
			// Out_Text
			// 
			this->Out_Text->Location = System::Drawing::Point(12, 221);
			this->Out_Text->Name = L"Out_Text";
			this->Out_Text->Size = System::Drawing::Size(384, 147);
			this->Out_Text->TabIndex = 11;
			this->Out_Text->Text = L"";
			// 
			// Info_Out_Lable
			// 
			this->Info_Out_Lable->AutoSize = true;
			this->Info_Out_Lable->Location = System::Drawing::Point(12, 205);
			this->Info_Out_Lable->Name = L"Info_Out_Lable";
			this->Info_Out_Lable->Size = System::Drawing::Size(59, 13);
			this->Info_Out_Lable->TabIndex = 12;
			this->Info_Out_Lable->Text = L"Результат";
			// 
			// Info_In_lable
			// 
			this->Info_In_lable->AutoSize = true;
			this->Info_In_lable->Location = System::Drawing::Point(12, 9);
			this->Info_In_lable->Name = L"Info_In_lable";
			this->Info_In_lable->Size = System::Drawing::Size(89, 13);
			this->Info_In_lable->TabIndex = 13;
			this->Info_In_lable->Text = L"Исходный текст";
			// 
			// Choice_shif
			// 
			this->Choice_shif->AutoSize = true;
			this->Choice_shif->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->Choice_shif->Checked = true;
			this->Choice_shif->Location = System::Drawing::Point(3, 7);
			this->Choice_shif->Name = L"Choice_shif";
			this->Choice_shif->Size = System::Drawing::Size(78, 17);
			this->Choice_shif->TabIndex = 14;
			this->Choice_shif->TabStop = true;
			this->Choice_shif->Text = L"Шифрация";
			this->Choice_shif->UseVisualStyleBackColor = true;
			this->Choice_shif->CheckedChanged += gcnew System::EventHandler(this, &Main::Choice_shif_CheckedChanged);
			// 
			// Choice_Function_Box
			// 
			this->Choice_Function_Box->Controls->Add(this->add_Database);
			this->Choice_Function_Box->Controls->Add(this->Choice_deshif_without);
			this->Choice_Function_Box->Controls->Add(this->Choice_deshif);
			this->Choice_Function_Box->Controls->Add(this->Choice_shif);
			this->Choice_Function_Box->Location = System::Drawing::Point(444, 9);
			this->Choice_Function_Box->Name = L"Choice_Function_Box";
			this->Choice_Function_Box->Size = System::Drawing::Size(215, 100);
			this->Choice_Function_Box->TabIndex = 15;
			// 
			// add_Database
			// 
			this->add_Database->AutoSize = true;
			this->add_Database->Location = System::Drawing::Point(3, 76);
			this->add_Database->Name = L"add_Database";
			this->add_Database->Size = System::Drawing::Size(157, 17);
			this->add_Database->TabIndex = 17;
			this->add_Database->Text = L"Дополнение базы данных";
			this->add_Database->UseVisualStyleBackColor = true;
			this->add_Database->CheckedChanged += gcnew System::EventHandler(this, &Main::add_Database_CheckedChanged);
			// 
			// Choice_deshif_without
			// 
			this->Choice_deshif_without->AutoSize = true;
			this->Choice_deshif_without->Location = System::Drawing::Point(3, 53);
			this->Choice_deshif_without->Name = L"Choice_deshif_without";
			this->Choice_deshif_without->Size = System::Drawing::Size(203, 17);
			this->Choice_deshif_without->TabIndex = 16;
			this->Choice_deshif_without->Text = L"Дешифрация без ключевого слова";
			this->Choice_deshif_without->UseVisualStyleBackColor = true;
			this->Choice_deshif_without->CheckedChanged += gcnew System::EventHandler(this, &Main::Choice_deshif_without_CheckedChanged);
			// 
			// Choice_deshif
			// 
			this->Choice_deshif->AutoSize = true;
			this->Choice_deshif->Location = System::Drawing::Point(3, 30);
			this->Choice_deshif->Name = L"Choice_deshif";
			this->Choice_deshif->Size = System::Drawing::Size(92, 17);
			this->Choice_deshif->TabIndex = 15;
			this->Choice_deshif->Text = L"Дешифрация";
			this->Choice_deshif->UseVisualStyleBackColor = true;
			this->Choice_deshif->CheckedChanged += gcnew System::EventHandler(this, &Main::Choice_deshif_CheckedChanged);
			// 
			// Error_text
			// 
			this->Error_text->AutoSize = true;
			this->Error_text->Location = System::Drawing::Point(441, 125);
			this->Error_text->Name = L"Error_text";
			this->Error_text->Size = System::Drawing::Size(0, 13);
			this->Error_text->TabIndex = 16;
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(671, 380);
			this->Controls->Add(this->Error_text);
			this->Controls->Add(this->Choice_Function_Box);
			this->Controls->Add(this->Info_In_lable);
			this->Controls->Add(this->Info_Out_Lable);
			this->Controls->Add(this->Out_Text);
			this->Controls->Add(this->Key_Label);
			this->Controls->Add(this->Key_Box);
			this->Controls->Add(this->Begining);
			this->Controls->Add(this->Matrix);
			this->Controls->Add(this->Enter_Text);
			this->Name = L"Main";
			this->Text = L"Программа для использование шифра Плейфера(шифрация/дешифрация)";
			this->Choice_Function_Box->ResumeLayout(false);
			this->Choice_Function_Box->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void Choice_shif_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void Choice_deshif_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void Choice_deshif_without_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void add_Database_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void Begining_Click(System::Object^  sender, System::EventArgs^  e);
		 System::Void Check_Text();//проверка вводимого текста на нечётность и повторение 2-х букв на идушем подряд чётном индексном месте
		 System::Int32 space_skore(String^ Text);//подсчёт количества пробелов
		 System::String^ Check_Key();//проверка ключа на ноличие повторяюшехся букв
		 System::String^ Pust();//выбор символа пустышки
		 System::Void Mass_Build();//постоение шифрационной матрицы
		 System::String ^Shifr(String ^str);//шифрация
		 System::String^ De_Shifr(String^ str);//дешифрация
		 System::String^ Remove_Space(int *mass,int skore, String ^ text);//удаление пробелов из строки с сохранением их позиций
		 System::String^ Insert_Space(int *mass, int skore, String ^ text);//занесение пробелов в строку по их позициям
		 System::Void Insert_In_Database(String^ add);//дополнение базы данных
		 System::String^ Read_DataBase();//функция сцитывания базы данных
		 System::Boolean Words_Check_of_true(String^ str, String^ base,int Number_word);//Функция проверки дишифрованого слова на правильность
private: System::Void Enter_Text_Function(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);//запрет введение ненужных символов в textbox
};
}