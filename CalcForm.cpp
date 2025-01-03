#include "CalcForm.h"
using namespace System;
using namespace System::Windows::Forms;

int CalcForm(array<String^>^ args) {


    Application::SetCompatibleTextRenderingDefault(false);
    Application::EnableVisualStyles();
    OPI12::CalcForm form;
    Application::Run(% form);
    return 0;
}
