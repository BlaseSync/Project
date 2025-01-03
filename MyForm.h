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
            clickCount = 0;  // Инициализируем общий счетчик кликов
            clickRate = 0;   // Инициализируем счетчик кликов в секунду
            timerCount = 0;  // Счетчик времени (для подсчета кликов в секунду)
            timer->Start();  // Запускаем таймер для подсчета кликов в секунду
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
        System::Windows::Forms::Label^ label1;  // Метка для отображения общего количества кликов
        System::Windows::Forms::Label^ label2;  // Метка для отображения кликов в секунду
        System::Windows::Forms::Timer^ timer;   // Таймер для подсчета кликов в секунду

        int clickCount;   // Переменная для хранения общего количества кликов
        int clickRate;    // Переменная для хранения кликов в секунду
        int timerCount;   // Счетчик для отслеживания времени

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
            this->timer->Interval = 1000; // Таймер с интервалом 1 секунда (1000 мс)
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
        clickCount++;  // Увеличиваем общий счетчик кликов
        label1->Text = L"Clicks: " + clickCount.ToString();  // Обновляем метку с общим количеством кликов
        timerCount++;  // Увеличиваем счетчик времени, чтобы отслеживать количество кликов за секунду
    }

    private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
        clickRate = timerCount;  // Сохраняем количество кликов за прошедшую секунду
        label2->Text = L"Clicks per second: " + clickRate.ToString();  // Обновляем метку с кликами в секунду
        timerCount = 0;  // Сбрасываем счетчик кликов за секунду
    }
    };
}
