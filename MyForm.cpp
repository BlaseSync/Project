#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

int MyForm(array<String^>^ args) {


	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	clicker::MyForm form;
	Application::Run(% form);
	return 0;
}