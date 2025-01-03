#include "main.h"
#include "CalcForm.h"

using namespace System;
using namespace System::Windows::Forms;

int main(array<String^>^ args) {


	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	OPI12::main form;
	Application::Run(% form);
	return 0;
}



