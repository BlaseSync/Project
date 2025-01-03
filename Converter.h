#pragma once

namespace OPI12 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	public ref class Converter : public System::Windows::Forms::Form
	{
	public:
		Converter(void)
		{
			InitializeComponent();
		}

	protected:
		~Converter()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::TextBox^ decimalInput;
		System::Windows::Forms::Label^ resultLabel;
		System::Windows::Forms::Button^ calculateButton;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->decimalInput = (gcnew System::Windows::Forms::TextBox());
			this->resultLabel = (gcnew System::Windows::Forms::Label());
			this->calculateButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// decimalInput
			// 
			this->decimalInput->Location = System::Drawing::Point(20, 20);
			this->decimalInput->Name = L"decimalInput";
			this->decimalInput->Size = System::Drawing::Size(200, 20);
			this->decimalInput->TabIndex = 0;
			// 
			// resultLabel
			// 
			this->resultLabel->AutoSize = true;
			this->resultLabel->Location = System::Drawing::Point(20, 60);
			this->resultLabel->Name = L"resultLabel";
			this->resultLabel->Size = System::Drawing::Size(62, 13);
			this->resultLabel->TabIndex = 2;
			this->resultLabel->Text = L"Результат:";
			// 
			// calculateButton
			// 
			this->calculateButton->Location = System::Drawing::Point(240, 20);
			this->calculateButton->Name = L"calculateButton";
			this->calculateButton->Size = System::Drawing::Size(75, 23);
			this->calculateButton->TabIndex = 1;
			this->calculateButton->Text = L"Рассчитать";
			this->calculateButton->Click += gcnew System::EventHandler(this, &Converter::CalculateButton_Click);
			// 
			// Converter
			// 
			this->ClientSize = System::Drawing::Size(484, 361);
			this->Controls->Add(this->decimalInput);
			this->Controls->Add(this->calculateButton);
			this->Controls->Add(this->resultLabel);
			this->Name = L"Converter";
			this->Text = L"Bit Calculator";
			this->Load += gcnew System::EventHandler(this, &Converter::Converter_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		void CalculateButton_Click(Object^ sender, EventArgs^ e)
		{
			String^ inputStr = decimalInput->Text;
			int number;

			if (!Int32::TryParse(inputStr, number)) {
				resultLabel->Text = L"Ошибка: введите корректное десятичное число.";
				return;
			}

			String^ octal = ConvertToOctal(number);
			String^ hexadecimal = Convert::ToString(number, 16)->ToUpper();
			String^ binary = ConvertToBinary(number);

			resultLabel->Text = L"Десятичное: " + number + L"\n"
				+ L"Восьмеричное: " + octal + L"\n"
				+ L"Шестнадцатеричное: " + hexadecimal + L"\n"
				+ L"Двоичное: " + binary;
		}

		String^ ConvertToOctal(int number)
		{
			String^ octal = L"";
			while (number > 0) {
				octal = (number % 8).ToString() + octal;
				number /= 8;
			}
			return octal == L"" ? L"0" : octal;
		}

		String^ ConvertToBinary(int number)
		{
			String^ binary = L"";
			while (number > 0) {
				binary = (number % 2).ToString() + binary;
				number /= 2;
			}
			return binary == L"" ? L"0" : binary;
		}
	private: System::Void Converter_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
