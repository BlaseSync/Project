#pragma once

namespace clicker {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
            clickCount = 0;  // �������������� ����� ������� ������
            clickRate = 0;   // �������������� ������� ������ � �������
            timerCount = 0;  // ������� ������� (��� �������� ������ � �������)
            timer->Start();  // ��������� ������ ��� �������� ������ � �������
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Button^ button1;
        System::Windows::Forms::Label^ label1;  // ����� ��� ����������� ������ ���������� ������
        System::Windows::Forms::Label^ label2;  // ����� ��� ����������� ������ � �������
        System::Windows::Forms::Timer^ timer;   // ������ ��� �������� ������ � �������

        int clickCount;   // ���������� ��� �������� ������ ���������� ������
        int clickRate;    // ���������� ��� �������� ������ � �������
        int timerCount;   // ������� ��� ������������ �������

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->timer = (gcnew System::Windows::Forms::Timer());
            this->SuspendLayout();

            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(116, 123);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(75, 23);
            this->button1->TabIndex = 0;
            this->button1->Text = L"Click Me!";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);

            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(116, 70);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(103, 17);
            this->label1->TabIndex = 1;
            this->label1->Text = L"Clicks: 0";

            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(116, 160);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(120, 17);
            this->label2->TabIndex = 2;
            this->label2->Text = L"Clicks per second: 0";

            // 
            // timer
            // 
            this->timer->Interval = 1000; // ������ � ���������� 1 ������� (1000 ��)
            this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);

            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(282, 253);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->button1);
            this->Name = L"MyForm";
            this->Text = L"Clicker";
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        clickCount++;  // ����������� ����� ������� ������
        label1->Text = L"Clicks: " + clickCount.ToString();  // ��������� ����� � ����� ����������� ������
        timerCount++;  // ����������� ������� �������, ����� ����������� ���������� ������ �� �������
    }

    private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
        clickRate = timerCount;  // ��������� ���������� ������ �� ��������� �������
        label2->Text = L"Clicks per second: " + clickRate.ToString();  // ��������� ����� � ������� � �������
        timerCount = 0;  // ���������� ������� ������ �� �������
    }
    };
}
