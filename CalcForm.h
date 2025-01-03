#pragma once

namespace OPI12 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для CalcForm
	/// </summary>
	public ref class CalcForm : public System::Windows::Forms::Form
	{
	public:
		CalcForm(void)
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
		~CalcForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ vivod;
	private: System::Windows::Forms::Button^ btn_1;
	private: System::Windows::Forms::Button^ btn_2;
	private: System::Windows::Forms::Button^ btn_3;
	private: System::Windows::Forms::Button^ btn_4;
	private: System::Windows::Forms::Button^ btn_5;
	private: System::Windows::Forms::Button^ btn_6;
	private: System::Windows::Forms::Button^ btn_7;
	private: System::Windows::Forms::Button^ btn_8;
	private: System::Windows::Forms::Button^ btn_9;
	private: System::Windows::Forms::Button^ btn_0;
	private: System::Windows::Forms::Button^ btn_procent;
	private: System::Windows::Forms::Button^ btn_point;
	private: System::Windows::Forms::Button^ btn_plus;
	private: System::Windows::Forms::Button^ btn_minus;
	private: System::Windows::Forms::Button^ btn_ravno;
	private: System::Windows::Forms::Button^ btn_proiz;
	private: System::Windows::Forms::Button^ btn_dele;
	private: System::Windows::Forms::Button^ btn_AC;

	private: float first_num;
	private: char user_action = ' ';











	protected:

	protected:

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
			this->vivod = (gcnew System::Windows::Forms::Label());
			this->btn_1 = (gcnew System::Windows::Forms::Button());
			this->btn_2 = (gcnew System::Windows::Forms::Button());
			this->btn_3 = (gcnew System::Windows::Forms::Button());
			this->btn_4 = (gcnew System::Windows::Forms::Button());
			this->btn_5 = (gcnew System::Windows::Forms::Button());
			this->btn_6 = (gcnew System::Windows::Forms::Button());
			this->btn_7 = (gcnew System::Windows::Forms::Button());
			this->btn_8 = (gcnew System::Windows::Forms::Button());
			this->btn_9 = (gcnew System::Windows::Forms::Button());
			this->btn_0 = (gcnew System::Windows::Forms::Button());
			this->btn_procent = (gcnew System::Windows::Forms::Button());
			this->btn_point = (gcnew System::Windows::Forms::Button());
			this->btn_plus = (gcnew System::Windows::Forms::Button());
			this->btn_minus = (gcnew System::Windows::Forms::Button());
			this->btn_ravno = (gcnew System::Windows::Forms::Button());
			this->btn_proiz = (gcnew System::Windows::Forms::Button());
			this->btn_dele = (gcnew System::Windows::Forms::Button());
			this->btn_AC = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// vivod
			// 
			this->vivod->Location = System::Drawing::Point(21, 9);
			this->vivod->Margin = System::Windows::Forms::Padding(12, 0, 12, 0);
			this->vivod->Name = L"vivod";
			this->vivod->Size = System::Drawing::Size(259, 48);
			this->vivod->TabIndex = 0;
			this->vivod->Text = L"0";
			this->vivod->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// btn_1
			// 
			this->btn_1->Location = System::Drawing::Point(23, 151);
			this->btn_1->Name = L"btn_1";
			this->btn_1->Size = System::Drawing::Size(60, 60);
			this->btn_1->TabIndex = 1;
			this->btn_1->Text = L"1";
			this->btn_1->UseVisualStyleBackColor = true;
			this->btn_1->Click += gcnew System::EventHandler(this, &CalcForm::number_click);
			// 
			// btn_2
			// 
			this->btn_2->Location = System::Drawing::Point(89, 151);
			this->btn_2->Name = L"btn_2";
			this->btn_2->Size = System::Drawing::Size(60, 60);
			this->btn_2->TabIndex = 2;
			this->btn_2->Text = L"2";
			this->btn_2->UseVisualStyleBackColor = true;
			this->btn_2->Click += gcnew System::EventHandler(this, &CalcForm::number_click);
			// 
			// btn_3
			// 
			this->btn_3->Location = System::Drawing::Point(155, 151);
			this->btn_3->Name = L"btn_3";
			this->btn_3->Size = System::Drawing::Size(60, 60);
			this->btn_3->TabIndex = 3;
			this->btn_3->Text = L"3";
			this->btn_3->UseVisualStyleBackColor = true;
			this->btn_3->Click += gcnew System::EventHandler(this, &CalcForm::number_click);
			// 
			// btn_4
			// 
			this->btn_4->Location = System::Drawing::Point(23, 217);
			this->btn_4->Name = L"btn_4";
			this->btn_4->Size = System::Drawing::Size(60, 60);
			this->btn_4->TabIndex = 4;
			this->btn_4->Text = L"4";
			this->btn_4->UseVisualStyleBackColor = true;
			this->btn_4->Click += gcnew System::EventHandler(this, &CalcForm::number_click);
			// 
			// btn_5
			// 
			this->btn_5->Location = System::Drawing::Point(89, 217);
			this->btn_5->Name = L"btn_5";
			this->btn_5->Size = System::Drawing::Size(60, 60);
			this->btn_5->TabIndex = 5;
			this->btn_5->Text = L"5";
			this->btn_5->UseVisualStyleBackColor = true;
			this->btn_5->Click += gcnew System::EventHandler(this, &CalcForm::number_click);
			// 
			// btn_6
			// 
			this->btn_6->Location = System::Drawing::Point(155, 217);
			this->btn_6->Name = L"btn_6";
			this->btn_6->Size = System::Drawing::Size(60, 60);
			this->btn_6->TabIndex = 6;
			this->btn_6->Text = L"6";
			this->btn_6->UseVisualStyleBackColor = true;
			this->btn_6->Click += gcnew System::EventHandler(this, &CalcForm::number_click);
			// 
			// btn_7
			// 
			this->btn_7->Location = System::Drawing::Point(23, 283);
			this->btn_7->Name = L"btn_7";
			this->btn_7->Size = System::Drawing::Size(60, 60);
			this->btn_7->TabIndex = 7;
			this->btn_7->Text = L"7";
			this->btn_7->UseVisualStyleBackColor = true;
			this->btn_7->Click += gcnew System::EventHandler(this, &CalcForm::number_click);
			// 
			// btn_8
			// 
			this->btn_8->Location = System::Drawing::Point(89, 283);
			this->btn_8->Name = L"btn_8";
			this->btn_8->Size = System::Drawing::Size(60, 60);
			this->btn_8->TabIndex = 8;
			this->btn_8->Text = L"8";
			this->btn_8->UseVisualStyleBackColor = true;
			this->btn_8->Click += gcnew System::EventHandler(this, &CalcForm::number_click);
			// 
			// btn_9
			// 
			this->btn_9->Location = System::Drawing::Point(155, 283);
			this->btn_9->Name = L"btn_9";
			this->btn_9->Size = System::Drawing::Size(60, 60);
			this->btn_9->TabIndex = 9;
			this->btn_9->Text = L"9";
			this->btn_9->UseVisualStyleBackColor = true;
			this->btn_9->Click += gcnew System::EventHandler(this, &CalcForm::number_click);
			// 
			// btn_0
			// 
			this->btn_0->Location = System::Drawing::Point(89, 349);
			this->btn_0->Name = L"btn_0";
			this->btn_0->Size = System::Drawing::Size(60, 60);
			this->btn_0->TabIndex = 10;
			this->btn_0->Text = L"0";
			this->btn_0->UseVisualStyleBackColor = true;
			this->btn_0->Click += gcnew System::EventHandler(this, &CalcForm::number_click);
			// 
			// btn_procent
			// 
			this->btn_procent->Location = System::Drawing::Point(23, 349);
			this->btn_procent->Name = L"btn_procent";
			this->btn_procent->Size = System::Drawing::Size(60, 60);
			this->btn_procent->TabIndex = 11;
			this->btn_procent->Text = L"%";
			this->btn_procent->UseVisualStyleBackColor = true;
			this->btn_procent->Click += gcnew System::EventHandler(this, &CalcForm::btn_procent_Click);
			// 
			// btn_point
			// 
			this->btn_point->Location = System::Drawing::Point(155, 349);
			this->btn_point->Name = L"btn_point";
			this->btn_point->Size = System::Drawing::Size(60, 60);
			this->btn_point->TabIndex = 12;
			this->btn_point->Text = L",";
			this->btn_point->UseVisualStyleBackColor = true;
			this->btn_point->Click += gcnew System::EventHandler(this, &CalcForm::btn_point_Click);
			// 
			// btn_plus
			// 
			this->btn_plus->Location = System::Drawing::Point(221, 151);
			this->btn_plus->Name = L"btn_plus";
			this->btn_plus->Size = System::Drawing::Size(60, 60);
			this->btn_plus->TabIndex = 13;
			this->btn_plus->Text = L"+";
			this->btn_plus->UseVisualStyleBackColor = true;
			this->btn_plus->Click += gcnew System::EventHandler(this, &CalcForm::btn_plus_Click);
			// 
			// btn_minus
			// 
			this->btn_minus->Location = System::Drawing::Point(221, 217);
			this->btn_minus->Name = L"btn_minus";
			this->btn_minus->Size = System::Drawing::Size(60, 60);
			this->btn_minus->TabIndex = 14;
			this->btn_minus->Text = L"-";
			this->btn_minus->UseVisualStyleBackColor = true;
			this->btn_minus->Click += gcnew System::EventHandler(this, &CalcForm::btn_minus_Click);
			// 
			// btn_ravno
			// 
			this->btn_ravno->Location = System::Drawing::Point(221, 283);
			this->btn_ravno->Name = L"btn_ravno";
			this->btn_ravno->Size = System::Drawing::Size(60, 126);
			this->btn_ravno->TabIndex = 16;
			this->btn_ravno->Text = L"=";
			this->btn_ravno->UseVisualStyleBackColor = true;
			this->btn_ravno->Click += gcnew System::EventHandler(this, &CalcForm::button4_Click);
			// 
			// btn_proiz
			// 
			this->btn_proiz->Location = System::Drawing::Point(221, 85);
			this->btn_proiz->Name = L"btn_proiz";
			this->btn_proiz->Size = System::Drawing::Size(60, 60);
			this->btn_proiz->TabIndex = 17;
			this->btn_proiz->Text = L"*";
			this->btn_proiz->UseVisualStyleBackColor = true;
			this->btn_proiz->Click += gcnew System::EventHandler(this, &CalcForm::btn_proiz_Click);
			// 
			// btn_dele
			// 
			this->btn_dele->Location = System::Drawing::Point(155, 85);
			this->btn_dele->Name = L"btn_dele";
			this->btn_dele->Size = System::Drawing::Size(60, 60);
			this->btn_dele->TabIndex = 18;
			this->btn_dele->Text = L"/";
			this->btn_dele->UseVisualStyleBackColor = true;
			this->btn_dele->Click += gcnew System::EventHandler(this, &CalcForm::btn_dele_Click);
			// 
			// btn_AC
			// 
			this->btn_AC->Location = System::Drawing::Point(23, 85);
			this->btn_AC->Name = L"btn_AC";
			this->btn_AC->Size = System::Drawing::Size(126, 60);
			this->btn_AC->TabIndex = 19;
			this->btn_AC->Text = L"AC";
			this->btn_AC->UseVisualStyleBackColor = true;
			this->btn_AC->Click += gcnew System::EventHandler(this, &CalcForm::btn_AC_Click);
			// 
			// CalcForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(23, 46);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(301, 439);
			this->Controls->Add(this->btn_AC);
			this->Controls->Add(this->btn_dele);
			this->Controls->Add(this->btn_proiz);
			this->Controls->Add(this->btn_ravno);
			this->Controls->Add(this->btn_minus);
			this->Controls->Add(this->btn_plus);
			this->Controls->Add(this->btn_point);
			this->Controls->Add(this->btn_procent);
			this->Controls->Add(this->btn_0);
			this->Controls->Add(this->btn_9);
			this->Controls->Add(this->btn_8);
			this->Controls->Add(this->btn_7);
			this->Controls->Add(this->btn_6);
			this->Controls->Add(this->btn_5);
			this->Controls->Add(this->btn_4);
			this->Controls->Add(this->btn_3);
			this->Controls->Add(this->btn_2);
			this->Controls->Add(this->btn_1);
			this->Controls->Add(this->vivod);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(12, 11, 12, 11);
			this->Name = L"CalcForm";
			this->Text = L"CalcForm";
			this->Load += gcnew System::EventHandler(this, &CalcForm::CalcForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion



private: System::Void number_click(System::Object^ sender, System::EventArgs^ e) {
	Button^ button = safe_cast<Button^>(sender);
	if (this->vivod->Text == "0")
		this->vivod->Text = button->Text;
	else
		this->vivod->Text += button->Text;
}

private: System::Void btn_proiz_Click(System::Object^ sender, System::EventArgs^ e) {
	math_action('*');
}
private: System::Void btn_dele_Click(System::Object^ sender, System::EventArgs^ e) {
	math_action('/');
}
private: System::Void btn_plus_Click(System::Object^ sender, System::EventArgs^ e) {
	math_action('+');
}
private: System::Void btn_minus_Click(System::Object^ sender, System::EventArgs^ e) {
	math_action('-');
}
	   private: System::Void math_action(char action) {
		   this->first_num = System::Convert::ToDouble(this->vivod->Text);
		   this->user_action = action;
		   this->vivod->Text = "0";
	   }

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		if (user_action == ' ')
			return;

		float second = System::Convert::ToDouble(this->vivod->Text);
		float res;

		switch (this->user_action) {
		case '+': res = this->first_num + second; break;
		case '-': res = this->first_num - second; break;
		case '*': res = this->first_num * second; break;
		case '/':
			if (second != 0)
				res = this->first_num / second;
			else
				MessageBox::Show(this, "На 0 делить нельзя", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			break;
		}
		this->vivod->Text = System::Convert::ToString(res);
	}
private: System::Void btn_AC_Click(System::Object^ sender, System::EventArgs^ e) {
	this->vivod->Text = "0";

	this->first_num = 0;
	this->user_action = ' ';
}
private: System::Void btn_point_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ text = this->vivod->Text;

	if (!text->Contains(",")) //проверка на наличие запятых
		this->vivod->Text = text + ",";
}
private: System::Void btn_procent_Click(System::Object^ sender, System::EventArgs^ e) {
	first_num = System::Convert::ToDouble(vivod->Text);
	first_num /= 100;

	this->vivod->Text = System::Convert::ToString(first_num);
}
private: System::Void CalcForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
