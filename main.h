#pragma once
#include "CalcForm.h"
#include "clicker.h"
#include "Converter.h"
#include "ClockForm.h"

namespace OPI12 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для main
	/// </summary>
	public ref class main : public System::Windows::Forms::Form
	{
	public:
		main(void)
		{
			InitializeComponent();
			//
			// Применяем закругление кнопок
			//
			RoundButton(this->button1, 50);
			RoundButton(this->button2, 50);
			RoundButton(this->button3, 50);
			RoundButton(this->button4, 50);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~main()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

		// Метод для закругления кнопок
		void RoundButton(Button^ button, int radius)
		{
			System::Drawing::Drawing2D::GraphicsPath^ path = gcnew System::Drawing::Drawing2D::GraphicsPath();

			int diameter = radius * 2;
			System::Drawing::Rectangle arcRect = System::Drawing::Rectangle(0, 0, diameter, diameter);

			// Верхний левый угол
			path->AddArc(arcRect, 180, 90);

			// Верхний правый угол
			arcRect.X = button->Width - diameter;
			path->AddArc(arcRect, 270, 90);

			// Нижний правый угол
			arcRect.Y = button->Height - diameter;
			path->AddArc(arcRect, 0, 90);

			// Нижний левый угол
			arcRect.X = 0;
			path->AddArc(arcRect, 90, 90);

			path->CloseFigure();
			button->Region = gcnew System::Drawing::Region(path);
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(main::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			resources->ApplyResources(this->button1, L"button1");
			this->button1->Name = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &main::toCalc_Click);
			// 
			// button2
			// 
			resources->ApplyResources(this->button2, L"button2");
			this->button2->Name = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &main::button2_Click);
			// 
			// button3
			// 
			resources->ApplyResources(this->button3, L"button3");
			this->button3->Name = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &main::button3_Click);
			// 
			// button4
			// 
			resources->ApplyResources(this->button4, L"button4");
			this->button4->Name = L"button4";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &main::Button4_Click);
			// 
			// main
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Navy;
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"main";
			this->Load += gcnew System::EventHandler(this, &main::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void toCalc_Click(System::Object^ sender, System::EventArgs^ e) {
		CalcForm^ calcForm = gcnew CalcForm();
		calcForm->Show();
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		clicker^ meteoricForm = gcnew clicker();
		meteoricForm->Show();
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		Converter^ dateForm = gcnew Converter();
		dateForm->Show();
	}

	private: System::Void Button4_Click(System::Object^ sender, System::EventArgs^ e) {
		ClockForm^ clockForm = gcnew ClockForm();
		clockForm->Show();
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
