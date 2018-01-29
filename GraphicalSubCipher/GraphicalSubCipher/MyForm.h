#pragma once

namespace GraphicalSubCipher {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1402, 564);
			this->label1->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(90, 37);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AccessibleName = L"lblType";
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 58);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(676, 37);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Would you like to encrypt a phrase or decrypt a phrase\?";
			// 
			// button1
			// 
			this->button1->AccessibleName = L"btnEncrypt";
			this->button1->Location = System::Drawing::Point(12, 240);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(157, 74);
			this->button1->TabIndex = 2;
			this->button1->Text = L"&Encrypt";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->AccessibleName = L"btnDecrypt";
			this->button2->Location = System::Drawing::Point(270, 240);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(157, 74);
			this->button2->TabIndex = 3;
			this->button2->Text = L"&Decrypt";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->AccessibleName = L"btnExit";
			this->button3->Location = System::Drawing::Point(524, 240);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(157, 74);
			this->button3->TabIndex = 4;
			this->button3->Text = L"E&xit";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::btnExit);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(15, 37);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(693, 326);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(8, 9, 8, 9);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnExit(System::Object^  sender, System::EventArgs^  e) {
		return;
	}
};
}


