#include "clicker.h"

using namespace System;
using namespace System::Windows::Forms;

int clicker(array<String^>^ args) {


	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	OPI12::clicker form;
	Application::Run(% form);
	return 0;
}