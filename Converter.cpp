#include "Converter.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Converter(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    OPI12::Converter^ mainForm = gcnew OPI12::Converter();
    Application::Run(mainForm);
}
