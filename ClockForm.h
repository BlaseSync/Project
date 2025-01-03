#pragma once
#include <ctime>
#include <windows.h>
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Diagnostics;

public ref class ClockForm : public Form {
private:
    Label^ lblCurrentTime;
    TextBox^ txtAlarmTime;
    Button^ btnSetAlarm;
    Label^ lblStopwatch;
    Button^ btnStartStopwatch;
    Button^ btnStopStopwatch;
    Button^ btnResetStopwatch;
    Label^ lblTimer;
    TextBox^ txtTimerDuration;
    Button^ btnSetTimer;

    DateTime alarmTime = DateTime::MinValue;
    bool alarmTriggered = false;
    Stopwatch^ stopwatch = gcnew Stopwatch();
    TimeSpan timerDuration = TimeSpan::Zero;
    bool timerRunning = false;
    DateTime timerEndTime = DateTime::MinValue;

public:
    ClockForm() {
        InitializeComponent();
    }

protected:
    ~ClockForm() {}

private:
    void InitializeComponent() {
        this->lblCurrentTime = gcnew Label();
        this->txtAlarmTime = gcnew TextBox();
        this->btnSetAlarm = gcnew Button();
        this->lblStopwatch = gcnew Label();
        this->btnStartStopwatch = gcnew Button();
        this->btnStopStopwatch = gcnew Button();
        this->btnResetStopwatch = gcnew Button();
        this->lblTimer = gcnew Label();
        this->txtTimerDuration = gcnew TextBox();
        this->btnSetTimer = gcnew Button();

        this->Text = "Часы и секундомер";
        this->ClientSize = System::Drawing::Size(400, 300);

        this->lblCurrentTime->Location = System::Drawing::Point(50, 20);
        this->lblCurrentTime->Size = System::Drawing::Size(300, 20);
        this->lblCurrentTime->Text = "Текущее время: ";
        this->Controls->Add(this->lblCurrentTime);

        this->txtAlarmTime->Location = System::Drawing::Point(50, 60);
        this->txtAlarmTime->Size = System::Drawing::Size(100, 20);
        this->Controls->Add(this->txtAlarmTime);

        this->btnSetAlarm->Location = System::Drawing::Point(170, 60);
        this->btnSetAlarm->Size = System::Drawing::Size(150, 30);
        this->btnSetAlarm->Text = "Установить будильник";
        this->btnSetAlarm->Click += gcnew EventHandler(this, &ClockForm::btnSetAlarm_Click);
        this->Controls->Add(this->btnSetAlarm);

        this->lblStopwatch->Location = System::Drawing::Point(50, 120);
        this->lblStopwatch->Size = System::Drawing::Size(300, 20);
        this->lblStopwatch->Text = "Секундомер: 00:00";
        this->Controls->Add(this->lblStopwatch);

        this->btnStartStopwatch->Location = System::Drawing::Point(50, 160);
        this->btnStartStopwatch->Size = System::Drawing::Size(90, 30);
        this->btnStartStopwatch->Text = "Старт";
        this->btnStartStopwatch->Click += gcnew EventHandler(this, &ClockForm::btnStartStopwatch_Click);
        this->Controls->Add(this->btnStartStopwatch);

        this->btnStopStopwatch->Location = System::Drawing::Point(150, 160);
        this->btnStopStopwatch->Size = System::Drawing::Size(90, 30);
        this->btnStopStopwatch->Text = "Стоп";
        this->btnStopStopwatch->Click += gcnew EventHandler(this, &ClockForm::btnStopStopwatch_Click);
        this->Controls->Add(this->btnStopStopwatch);

        this->btnResetStopwatch->Location = System::Drawing::Point(250, 160);
        this->btnResetStopwatch->Size = System::Drawing::Size(90, 30);
        this->btnResetStopwatch->Text = "Сброс";
        this->btnResetStopwatch->Click += gcnew EventHandler(this, &ClockForm::btnResetStopwatch_Click);
        this->Controls->Add(this->btnResetStopwatch);

        this->lblTimer->Location = System::Drawing::Point(50, 200);
        this->lblTimer->Size = System::Drawing::Size(300, 20);
        this->lblTimer->Text = "Таймер: 00:00";
        this->Controls->Add(this->lblTimer);

        this->txtTimerDuration->Location = System::Drawing::Point(50, 240);
        this->txtTimerDuration->Size = System::Drawing::Size(100, 20);
        this->Controls->Add(this->txtTimerDuration);

        this->btnSetTimer->Location = System::Drawing::Point(170, 240);
        this->btnSetTimer->Size = System::Drawing::Size(150, 30);
        this->btnSetTimer->Text = "Установить таймер";
        this->btnSetTimer->Click += gcnew EventHandler(this, &ClockForm::btnSetTimer_Click);
        this->Controls->Add(this->btnSetTimer);

        Timer^ timer = gcnew Timer();
        timer->Interval = 10;
        timer->Tick += gcnew EventHandler(this, &ClockForm::Timer_Tick);
        timer->Start();
    }

    void Timer_Tick(Object^ sender, EventArgs^ e) {
        lblCurrentTime->Text = "Текущее время: " + DateTime::Now.ToString("HH:mm:ss");

        if (alarmTime != DateTime::MinValue && DateTime::Now >= alarmTime && !alarmTriggered) {
            alarmTriggered = true;
            MessageBox::Show("Будильник сработал!", "Будильник");
        }

        if (stopwatch->IsRunning) {
            TimeSpan elapsed = stopwatch->Elapsed;
            lblStopwatch->Text = String::Format("Секундомер: {0:D2}:{1:D2}:{2:D2}", elapsed.Minutes, elapsed.Seconds, elapsed.Milliseconds / 10);
        }

        if (timerRunning) {
            TimeSpan remainingTime = timerEndTime - DateTime::Now;
            if (remainingTime.TotalSeconds <= 0) {
                timerRunning = false;
                lblTimer->Text = "Таймер: 00:00";
                MessageBox::Show("Таймер завершён!", "Таймер");
            }
            else {
                lblTimer->Text = String::Format("Таймер: {0:D2}:{1:D2}", remainingTime.Minutes, remainingTime.Seconds);
            }
        }
    }

    void btnSetAlarm_Click(Object^ sender, EventArgs^ e) {
        String^ input = txtAlarmTime->Text;
        DateTime parsedTime;
        if (DateTime::TryParse(input, parsedTime)) {
            alarmTime = DateTime::Today.AddHours(parsedTime.Hour).AddMinutes(parsedTime.Minute);
            alarmTriggered = false;
            MessageBox::Show("Будильник установлен на " + alarmTime.ToString("HH:mm"));
        }
        else {
            MessageBox::Show("Некорректный формат. Введите время как 'часы:минуты' (например, 20:15).");
        }
    }

    void btnStartStopwatch_Click(Object^ sender, EventArgs^ e) {
        stopwatch->Start();
    }

    void btnStopStopwatch_Click(Object^ sender, EventArgs^ e) {
        stopwatch->Stop();
    }

    void btnResetStopwatch_Click(Object^ sender, EventArgs^ e) {
        stopwatch->Reset();
        lblStopwatch->Text = "Секундомер: 00:00:00";
    }

    void btnSetTimer_Click(Object^ sender, EventArgs^ e) {
        String^ input = txtTimerDuration->Text;
        TimeSpan duration;
        if (TimeSpan::TryParseExact(input, "mm\\:ss", nullptr, duration)) {
            timerDuration = duration;
            timerEndTime = DateTime::Now.Add(timerDuration);
            timerRunning = true;
            MessageBox::Show(String::Format("Таймер установлен на {0:D2}:{1:D2}.", duration.Minutes, duration.Seconds));
        }
        else {
            MessageBox::Show("Некорректный формат. Введите время как 'минуты:секунды' (например, 01:25).");
        }
    }
};

