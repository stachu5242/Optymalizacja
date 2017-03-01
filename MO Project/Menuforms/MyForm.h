#pragma once
#include "optimalizationAlgorithms.h"
#include "ParticleSwarmOptimalization.h"
#include "Flocking.h"
#include "GenerateFucntionTexture.h"
#include "SimulatedAneaning.h"
#include "PSO.h"
#include "FireflyAlgorithm.h"
#include "GlowwormSwarmAlgorith.h"
#include "ChargedSystemSearch.h"
#include "GrawitationalSearchAlgorithm.h"
#include "functions.h"
#include "BatAlgorithm.h"
#include "RiverFormationDynamic.h"
#include <SDL\SDL_ttf.h>
#include "UniformRandomNumbers.h"
#include "CauchyRandomNumbers.h"
#include "GaussRandomNumbers.h"
#include "LevyRandomNumbers.h"
#include "IntelligentWaterDrops.h"
#include "DrawFourGenerators.h"
#include "DifferentialEvolution.h"
#include "CuckooSearch.h"
#include "BlackHolesAlgorithm.h"

namespace Menuforms {

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
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  fROSENBROCK;
	private: System::Windows::Forms::Button^  fRASTIGIN;
	private: System::Windows::Forms::Button^  fPARABOLOID;
	private: System::Windows::Forms::Button^  fFOURPICKINVERSE;
	private: System::Windows::Forms::Button^  fFOURPEAKSINVERSSE;
	private: System::Windows::Forms::Button^  fBEALE;
	private: System::Windows::Forms::Button^  fGOLDSTEINPRICE;
	private: System::Windows::Forms::Button^  fBOOTH;
	private: System::Windows::Forms::Button^  fBUKIN;
	private: System::Windows::Forms::Button^  fMATYAS;
	private: System::Windows::Forms::Button^  fACKLEY;
	private: System::Windows::Forms::Button^  fLEVI;
	private: System::Windows::Forms::Button^  fTREEHUMPCAMMEL;
	private: System::Windows::Forms::Button^  fEASOM;
	private: System::Windows::Forms::Button^  fCROSSTRAY;
	private: System::Windows::Forms::Button^  fEGGHOLDER;
	private: System::Windows::Forms::Button^  fHOLDERTABLE;
	private: System::Windows::Forms::Button^  fMCCORMICK;
	private: System::Windows::Forms::Button^  fSHAFFERN2;
	private: System::Windows::Forms::Button^  fSHAFFERN4;
	private: System::Windows::Forms::Button^  fSTYBINSKITANG;
	private: System::Windows::Forms::Button^  AlgorithmsOf;
	private: System::Windows::Forms::Button^  aSimulatedAneaning;
	private: System::Windows::Forms::Button^  aFireflyAlg;
	private: System::Windows::Forms::Button^  aGlowworm;
	private: System::Windows::Forms::Button^  aParticleSwarm;
	private: System::Windows::Forms::Button^  aChargedSystem;
	private: System::Windows::Forms::Button^  aGrawitional;
	private: System::Windows::Forms::Button^  aDifferential;
	private: System::Windows::Forms::Button^  aCucko;
	private: System::Windows::Forms::Button^  aBlackHoles;
	private: System::Windows::Forms::Button^  aBat;
	private: System::Windows::Forms::Button^  shortestPath;
	private: System::Windows::Forms::Button^  sRiver;
	private: System::Windows::Forms::Button^  sInteligent;
	private: System::Windows::Forms::Button^  pseudo;
	private: System::Windows::Forms::Button^  pUniform;
	private: System::Windows::Forms::Button^  pCauchy;
	private: System::Windows::Forms::Button^  pGauss;
	private: System::Windows::Forms::Button^  pLevy;
	private: System::Windows::Forms::Button^  extraAlgorithms;
	private: System::Windows::Forms::Button^  eFreeFocking;






























































private: System::Windows::Forms::Button^  ePSO;
private: System::Windows::Forms::Button^  eWanderer;
private: System::Windows::Forms::Button^  eMouse;
private: System::Windows::Forms::Button^  eMouseWanderer;





	protected:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->fROSENBROCK = (gcnew System::Windows::Forms::Button());
			this->fRASTIGIN = (gcnew System::Windows::Forms::Button());
			this->fPARABOLOID = (gcnew System::Windows::Forms::Button());
			this->fFOURPICKINVERSE = (gcnew System::Windows::Forms::Button());
			this->fFOURPEAKSINVERSSE = (gcnew System::Windows::Forms::Button());
			this->fBEALE = (gcnew System::Windows::Forms::Button());
			this->fGOLDSTEINPRICE = (gcnew System::Windows::Forms::Button());
			this->fBOOTH = (gcnew System::Windows::Forms::Button());
			this->fBUKIN = (gcnew System::Windows::Forms::Button());
			this->fMATYAS = (gcnew System::Windows::Forms::Button());
			this->fACKLEY = (gcnew System::Windows::Forms::Button());
			this->fLEVI = (gcnew System::Windows::Forms::Button());
			this->fTREEHUMPCAMMEL = (gcnew System::Windows::Forms::Button());
			this->fEASOM = (gcnew System::Windows::Forms::Button());
			this->fCROSSTRAY = (gcnew System::Windows::Forms::Button());
			this->fEGGHOLDER = (gcnew System::Windows::Forms::Button());
			this->fHOLDERTABLE = (gcnew System::Windows::Forms::Button());
			this->fMCCORMICK = (gcnew System::Windows::Forms::Button());
			this->fSHAFFERN2 = (gcnew System::Windows::Forms::Button());
			this->fSHAFFERN4 = (gcnew System::Windows::Forms::Button());
			this->fSTYBINSKITANG = (gcnew System::Windows::Forms::Button());
			this->AlgorithmsOf = (gcnew System::Windows::Forms::Button());
			this->aSimulatedAneaning = (gcnew System::Windows::Forms::Button());
			this->aFireflyAlg = (gcnew System::Windows::Forms::Button());
			this->aGlowworm = (gcnew System::Windows::Forms::Button());
			this->aParticleSwarm = (gcnew System::Windows::Forms::Button());
			this->aChargedSystem = (gcnew System::Windows::Forms::Button());
			this->aGrawitional = (gcnew System::Windows::Forms::Button());
			this->aDifferential = (gcnew System::Windows::Forms::Button());
			this->aCucko = (gcnew System::Windows::Forms::Button());
			this->aBlackHoles = (gcnew System::Windows::Forms::Button());
			this->aBat = (gcnew System::Windows::Forms::Button());
			this->shortestPath = (gcnew System::Windows::Forms::Button());
			this->sRiver = (gcnew System::Windows::Forms::Button());
			this->sInteligent = (gcnew System::Windows::Forms::Button());
			this->pseudo = (gcnew System::Windows::Forms::Button());
			this->pUniform = (gcnew System::Windows::Forms::Button());
			this->pCauchy = (gcnew System::Windows::Forms::Button());
			this->pGauss = (gcnew System::Windows::Forms::Button());
			this->pLevy = (gcnew System::Windows::Forms::Button());
			this->extraAlgorithms = (gcnew System::Windows::Forms::Button());
			this->eFreeFocking = (gcnew System::Windows::Forms::Button());
			this->ePSO = (gcnew System::Windows::Forms::Button());
			this->eWanderer = (gcnew System::Windows::Forms::Button());
			this->eMouse = (gcnew System::Windows::Forms::Button());
			this->eMouseWanderer = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button1->Location = System::Drawing::Point(913, 453);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Exit";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe Script", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->label1->Location = System::Drawing::Point(22, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(157, 80);
			this->label1->TabIndex = 1;
			this->label1->Text = L"#MO";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->label2->Location = System::Drawing::Point(23, 89);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(66, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Functions:";
			// 
			// fROSENBROCK
			// 
			this->fROSENBROCK->Cursor = System::Windows::Forms::Cursors::Hand;
			this->fROSENBROCK->Enabled = false;
			this->fROSENBROCK->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->fROSENBROCK->Location = System::Drawing::Point(26, 105);
			this->fROSENBROCK->Name = L"fROSENBROCK";
			this->fROSENBROCK->Size = System::Drawing::Size(236, 23);
			this->fROSENBROCK->TabIndex = 3;
			this->fROSENBROCK->Text = L"ROSENBROCK";
			this->fROSENBROCK->UseVisualStyleBackColor = true;
			this->fROSENBROCK->Click += gcnew System::EventHandler(this, &MyForm::fROSENBROCK_Click);
			// 
			// fRASTIGIN
			// 
			this->fRASTIGIN->Cursor = System::Windows::Forms::Cursors::Hand;
			this->fRASTIGIN->Enabled = false;
			this->fRASTIGIN->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->fRASTIGIN->Location = System::Drawing::Point(26, 134);
			this->fRASTIGIN->Name = L"fRASTIGIN";
			this->fRASTIGIN->Size = System::Drawing::Size(236, 23);
			this->fRASTIGIN->TabIndex = 4;
			this->fRASTIGIN->Text = L"RASTIGIN";
			this->fRASTIGIN->UseVisualStyleBackColor = true;
			this->fRASTIGIN->Click += gcnew System::EventHandler(this, &MyForm::fRASTIGIN_Click);
			// 
			// fPARABOLOID
			// 
			this->fPARABOLOID->Cursor = System::Windows::Forms::Cursors::Hand;
			this->fPARABOLOID->Enabled = false;
			this->fPARABOLOID->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->fPARABOLOID->Location = System::Drawing::Point(26, 163);
			this->fPARABOLOID->Name = L"fPARABOLOID";
			this->fPARABOLOID->Size = System::Drawing::Size(236, 23);
			this->fPARABOLOID->TabIndex = 5;
			this->fPARABOLOID->Text = L"PARABOLOID";
			this->fPARABOLOID->UseVisualStyleBackColor = true;
			this->fPARABOLOID->Click += gcnew System::EventHandler(this, &MyForm::fPARABOLOID_Click);
			// 
			// fFOURPICKINVERSE
			// 
			this->fFOURPICKINVERSE->Cursor = System::Windows::Forms::Cursors::Hand;
			this->fFOURPICKINVERSE->Enabled = false;
			this->fFOURPICKINVERSE->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->fFOURPICKINVERSE->Location = System::Drawing::Point(26, 192);
			this->fFOURPICKINVERSE->Name = L"fFOURPICKINVERSE";
			this->fFOURPICKINVERSE->Size = System::Drawing::Size(236, 23);
			this->fFOURPICKINVERSE->TabIndex = 6;
			this->fFOURPICKINVERSE->Text = L"FOUR PICK INVERSE";
			this->fFOURPICKINVERSE->UseVisualStyleBackColor = true;
			this->fFOURPICKINVERSE->Click += gcnew System::EventHandler(this, &MyForm::fFOURPICKINVERSE_Click);
			// 
			// fFOURPEAKSINVERSSE
			// 
			this->fFOURPEAKSINVERSSE->Cursor = System::Windows::Forms::Cursors::Hand;
			this->fFOURPEAKSINVERSSE->Enabled = false;
			this->fFOURPEAKSINVERSSE->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->fFOURPEAKSINVERSSE->Location = System::Drawing::Point(26, 221);
			this->fFOURPEAKSINVERSSE->Name = L"fFOURPEAKSINVERSSE";
			this->fFOURPEAKSINVERSSE->Size = System::Drawing::Size(236, 23);
			this->fFOURPEAKSINVERSSE->TabIndex = 7;
			this->fFOURPEAKSINVERSSE->Text = L"FOUR PEAKS INVERSE";
			this->fFOURPEAKSINVERSSE->UseVisualStyleBackColor = true;
			this->fFOURPEAKSINVERSSE->Click += gcnew System::EventHandler(this, &MyForm::fFOURPEAKSINVERSSE_Click);
			// 
			// fBEALE
			// 
			this->fBEALE->Cursor = System::Windows::Forms::Cursors::Hand;
			this->fBEALE->Enabled = false;
			this->fBEALE->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->fBEALE->Location = System::Drawing::Point(26, 250);
			this->fBEALE->Name = L"fBEALE";
			this->fBEALE->Size = System::Drawing::Size(236, 23);
			this->fBEALE->TabIndex = 8;
			this->fBEALE->Text = L"BAEALE";
			this->fBEALE->UseVisualStyleBackColor = true;
			this->fBEALE->Click += gcnew System::EventHandler(this, &MyForm::fBEALE_Click);
			// 
			// fGOLDSTEINPRICE
			// 
			this->fGOLDSTEINPRICE->Cursor = System::Windows::Forms::Cursors::Hand;
			this->fGOLDSTEINPRICE->Enabled = false;
			this->fGOLDSTEINPRICE->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->fGOLDSTEINPRICE->Location = System::Drawing::Point(26, 279);
			this->fGOLDSTEINPRICE->Name = L"fGOLDSTEINPRICE";
			this->fGOLDSTEINPRICE->Size = System::Drawing::Size(236, 23);
			this->fGOLDSTEINPRICE->TabIndex = 9;
			this->fGOLDSTEINPRICE->Text = L"GOLDSTEIN PRICE";
			this->fGOLDSTEINPRICE->UseVisualStyleBackColor = true;
			this->fGOLDSTEINPRICE->Click += gcnew System::EventHandler(this, &MyForm::fGOLDSTEINPRICE_Click);
			// 
			// fBOOTH
			// 
			this->fBOOTH->Cursor = System::Windows::Forms::Cursors::Hand;
			this->fBOOTH->Enabled = false;
			this->fBOOTH->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->fBOOTH->Location = System::Drawing::Point(26, 308);
			this->fBOOTH->Name = L"fBOOTH";
			this->fBOOTH->Size = System::Drawing::Size(236, 23);
			this->fBOOTH->TabIndex = 10;
			this->fBOOTH->Text = L"BOOTH";
			this->fBOOTH->UseVisualStyleBackColor = true;
			this->fBOOTH->Click += gcnew System::EventHandler(this, &MyForm::fBOOTH_Click);
			// 
			// fBUKIN
			// 
			this->fBUKIN->Cursor = System::Windows::Forms::Cursors::Hand;
			this->fBUKIN->Enabled = false;
			this->fBUKIN->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->fBUKIN->Location = System::Drawing::Point(26, 337);
			this->fBUKIN->Name = L"fBUKIN";
			this->fBUKIN->Size = System::Drawing::Size(236, 23);
			this->fBUKIN->TabIndex = 11;
			this->fBUKIN->Text = L"BUKIN";
			this->fBUKIN->UseVisualStyleBackColor = true;
			this->fBUKIN->Click += gcnew System::EventHandler(this, &MyForm::fBUKIN_Click);
			// 
			// fMATYAS
			// 
			this->fMATYAS->Cursor = System::Windows::Forms::Cursors::Hand;
			this->fMATYAS->Enabled = false;
			this->fMATYAS->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->fMATYAS->Location = System::Drawing::Point(26, 366);
			this->fMATYAS->Name = L"fMATYAS";
			this->fMATYAS->Size = System::Drawing::Size(236, 23);
			this->fMATYAS->TabIndex = 12;
			this->fMATYAS->Text = L"MATYAS";
			this->fMATYAS->UseVisualStyleBackColor = true;
			this->fMATYAS->Click += gcnew System::EventHandler(this, &MyForm::fMATYAS_Click);
			// 
			// fACKLEY
			// 
			this->fACKLEY->Cursor = System::Windows::Forms::Cursors::Hand;
			this->fACKLEY->Enabled = false;
			this->fACKLEY->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->fACKLEY->Location = System::Drawing::Point(26, 395);
			this->fACKLEY->Name = L"fACKLEY";
			this->fACKLEY->Size = System::Drawing::Size(236, 23);
			this->fACKLEY->TabIndex = 13;
			this->fACKLEY->Text = L"ACKLEY";
			this->fACKLEY->UseVisualStyleBackColor = true;
			this->fACKLEY->Click += gcnew System::EventHandler(this, &MyForm::fACKLEY_Click);
			// 
			// fLEVI
			// 
			this->fLEVI->Cursor = System::Windows::Forms::Cursors::Hand;
			this->fLEVI->Enabled = false;
			this->fLEVI->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->fLEVI->Location = System::Drawing::Point(26, 424);
			this->fLEVI->Name = L"fLEVI";
			this->fLEVI->Size = System::Drawing::Size(236, 23);
			this->fLEVI->TabIndex = 14;
			this->fLEVI->Text = L"LEVI";
			this->fLEVI->UseVisualStyleBackColor = true;
			this->fLEVI->Click += gcnew System::EventHandler(this, &MyForm::fLEVI_Click);
			// 
			// fTREEHUMPCAMMEL
			// 
			this->fTREEHUMPCAMMEL->Cursor = System::Windows::Forms::Cursors::Hand;
			this->fTREEHUMPCAMMEL->Enabled = false;
			this->fTREEHUMPCAMMEL->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->fTREEHUMPCAMMEL->Location = System::Drawing::Point(26, 453);
			this->fTREEHUMPCAMMEL->Name = L"fTREEHUMPCAMMEL";
			this->fTREEHUMPCAMMEL->Size = System::Drawing::Size(236, 23);
			this->fTREEHUMPCAMMEL->TabIndex = 15;
			this->fTREEHUMPCAMMEL->Text = L"TREE HUMP CAMMEL";
			this->fTREEHUMPCAMMEL->UseVisualStyleBackColor = true;
			this->fTREEHUMPCAMMEL->Click += gcnew System::EventHandler(this, &MyForm::fTREEHUMPCAMMEL_Click);
			// 
			// fEASOM
			// 
			this->fEASOM->Cursor = System::Windows::Forms::Cursors::Hand;
			this->fEASOM->Enabled = false;
			this->fEASOM->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->fEASOM->Location = System::Drawing::Point(268, 105);
			this->fEASOM->Name = L"fEASOM";
			this->fEASOM->Size = System::Drawing::Size(236, 23);
			this->fEASOM->TabIndex = 16;
			this->fEASOM->Text = L"EASOM";
			this->fEASOM->UseVisualStyleBackColor = true;
			this->fEASOM->Click += gcnew System::EventHandler(this, &MyForm::fEASOM_Click);
			// 
			// fCROSSTRAY
			// 
			this->fCROSSTRAY->Cursor = System::Windows::Forms::Cursors::Hand;
			this->fCROSSTRAY->Enabled = false;
			this->fCROSSTRAY->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->fCROSSTRAY->Location = System::Drawing::Point(268, 134);
			this->fCROSSTRAY->Name = L"fCROSSTRAY";
			this->fCROSSTRAY->Size = System::Drawing::Size(236, 23);
			this->fCROSSTRAY->TabIndex = 17;
			this->fCROSSTRAY->Text = L"CROSS TRAY";
			this->fCROSSTRAY->UseVisualStyleBackColor = true;
			this->fCROSSTRAY->Click += gcnew System::EventHandler(this, &MyForm::fCROSSTRAY_Click);
			// 
			// fEGGHOLDER
			// 
			this->fEGGHOLDER->Cursor = System::Windows::Forms::Cursors::Hand;
			this->fEGGHOLDER->Enabled = false;
			this->fEGGHOLDER->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->fEGGHOLDER->Location = System::Drawing::Point(268, 163);
			this->fEGGHOLDER->Name = L"fEGGHOLDER";
			this->fEGGHOLDER->Size = System::Drawing::Size(236, 23);
			this->fEGGHOLDER->TabIndex = 18;
			this->fEGGHOLDER->Text = L"EGGHOLDER";
			this->fEGGHOLDER->UseVisualStyleBackColor = true;
			this->fEGGHOLDER->Click += gcnew System::EventHandler(this, &MyForm::fEGGHOLDER_Click);
			// 
			// fHOLDERTABLE
			// 
			this->fHOLDERTABLE->Cursor = System::Windows::Forms::Cursors::Hand;
			this->fHOLDERTABLE->Enabled = false;
			this->fHOLDERTABLE->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->fHOLDERTABLE->Location = System::Drawing::Point(268, 192);
			this->fHOLDERTABLE->Name = L"fHOLDERTABLE";
			this->fHOLDERTABLE->Size = System::Drawing::Size(236, 23);
			this->fHOLDERTABLE->TabIndex = 19;
			this->fHOLDERTABLE->Text = L"HOLDER TABLE";
			this->fHOLDERTABLE->UseVisualStyleBackColor = true;
			this->fHOLDERTABLE->Click += gcnew System::EventHandler(this, &MyForm::fHOLDERTABLE_Click);
			// 
			// fMCCORMICK
			// 
			this->fMCCORMICK->Cursor = System::Windows::Forms::Cursors::Hand;
			this->fMCCORMICK->Enabled = false;
			this->fMCCORMICK->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->fMCCORMICK->Location = System::Drawing::Point(268, 221);
			this->fMCCORMICK->Name = L"fMCCORMICK";
			this->fMCCORMICK->Size = System::Drawing::Size(236, 23);
			this->fMCCORMICK->TabIndex = 20;
			this->fMCCORMICK->Text = L"MC CORMICK";
			this->fMCCORMICK->UseVisualStyleBackColor = true;
			this->fMCCORMICK->Click += gcnew System::EventHandler(this, &MyForm::fMCCORMICK_Click);
			// 
			// fSHAFFERN2
			// 
			this->fSHAFFERN2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->fSHAFFERN2->Enabled = false;
			this->fSHAFFERN2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->fSHAFFERN2->Location = System::Drawing::Point(268, 250);
			this->fSHAFFERN2->Name = L"fSHAFFERN2";
			this->fSHAFFERN2->Size = System::Drawing::Size(236, 23);
			this->fSHAFFERN2->TabIndex = 21;
			this->fSHAFFERN2->Text = L"SHAFFER N2";
			this->fSHAFFERN2->UseVisualStyleBackColor = true;
			this->fSHAFFERN2->Click += gcnew System::EventHandler(this, &MyForm::fSHAFFERN2_Click);
			// 
			// fSHAFFERN4
			// 
			this->fSHAFFERN4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->fSHAFFERN4->Enabled = false;
			this->fSHAFFERN4->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->fSHAFFERN4->Location = System::Drawing::Point(268, 279);
			this->fSHAFFERN4->Name = L"fSHAFFERN4";
			this->fSHAFFERN4->Size = System::Drawing::Size(236, 23);
			this->fSHAFFERN4->TabIndex = 22;
			this->fSHAFFERN4->Text = L"SHAFFER N4";
			this->fSHAFFERN4->UseVisualStyleBackColor = true;
			this->fSHAFFERN4->Click += gcnew System::EventHandler(this, &MyForm::fSHAFFERN4_Click);
			// 
			// fSTYBINSKITANG
			// 
			this->fSTYBINSKITANG->Cursor = System::Windows::Forms::Cursors::Hand;
			this->fSTYBINSKITANG->Enabled = false;
			this->fSTYBINSKITANG->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->fSTYBINSKITANG->Location = System::Drawing::Point(268, 308);
			this->fSTYBINSKITANG->Name = L"fSTYBINSKITANG";
			this->fSTYBINSKITANG->Size = System::Drawing::Size(236, 23);
			this->fSTYBINSKITANG->TabIndex = 23;
			this->fSTYBINSKITANG->Text = L"STYBINSKI TANG";
			this->fSTYBINSKITANG->UseVisualStyleBackColor = true;
			this->fSTYBINSKITANG->Click += gcnew System::EventHandler(this, &MyForm::fSTYBINSKITANG_Click);
			// 
			// AlgorithmsOf
			// 
			this->AlgorithmsOf->Cursor = System::Windows::Forms::Cursors::Hand;
			this->AlgorithmsOf->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->AlgorithmsOf->Location = System::Drawing::Point(268, 337);
			this->AlgorithmsOf->Name = L"AlgorithmsOf";
			this->AlgorithmsOf->Size = System::Drawing::Size(236, 23);
			this->AlgorithmsOf->TabIndex = 24;
			this->AlgorithmsOf->Text = L"Algorithms of searching zeros of a function";
			this->AlgorithmsOf->UseVisualStyleBackColor = true;
			this->AlgorithmsOf->Click += gcnew System::EventHandler(this, &MyForm::AlgorithmsOf_Click);
			// 
			// aSimulatedAneaning
			// 
			this->aSimulatedAneaning->Cursor = System::Windows::Forms::Cursors::Hand;
			this->aSimulatedAneaning->Enabled = false;
			this->aSimulatedAneaning->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->aSimulatedAneaning->Location = System::Drawing::Point(268, 366);
			this->aSimulatedAneaning->Name = L"aSimulatedAneaning";
			this->aSimulatedAneaning->Size = System::Drawing::Size(236, 23);
			this->aSimulatedAneaning->TabIndex = 25;
			this->aSimulatedAneaning->Text = L"Simulated aneaning";
			this->aSimulatedAneaning->UseVisualStyleBackColor = true;
			this->aSimulatedAneaning->Click += gcnew System::EventHandler(this, &MyForm::aSimulatedAneaning_Click);
			// 
			// aFireflyAlg
			// 
			this->aFireflyAlg->Cursor = System::Windows::Forms::Cursors::Hand;
			this->aFireflyAlg->Enabled = false;
			this->aFireflyAlg->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->aFireflyAlg->Location = System::Drawing::Point(268, 395);
			this->aFireflyAlg->Name = L"aFireflyAlg";
			this->aFireflyAlg->Size = System::Drawing::Size(236, 23);
			this->aFireflyAlg->TabIndex = 26;
			this->aFireflyAlg->Text = L"Firefly algorithm";
			this->aFireflyAlg->UseVisualStyleBackColor = true;
			this->aFireflyAlg->Click += gcnew System::EventHandler(this, &MyForm::aFireflyAlg_Click);
			// 
			// aGlowworm
			// 
			this->aGlowworm->Cursor = System::Windows::Forms::Cursors::Hand;
			this->aGlowworm->Enabled = false;
			this->aGlowworm->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->aGlowworm->Location = System::Drawing::Point(268, 424);
			this->aGlowworm->Name = L"aGlowworm";
			this->aGlowworm->Size = System::Drawing::Size(236, 23);
			this->aGlowworm->TabIndex = 27;
			this->aGlowworm->Text = L"Glowworm swarm algorithm";
			this->aGlowworm->UseVisualStyleBackColor = true;
			this->aGlowworm->Click += gcnew System::EventHandler(this, &MyForm::aGlowworm_Click);
			// 
			// aParticleSwarm
			// 
			this->aParticleSwarm->Cursor = System::Windows::Forms::Cursors::Hand;
			this->aParticleSwarm->Enabled = false;
			this->aParticleSwarm->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->aParticleSwarm->Location = System::Drawing::Point(268, 453);
			this->aParticleSwarm->Name = L"aParticleSwarm";
			this->aParticleSwarm->Size = System::Drawing::Size(236, 23);
			this->aParticleSwarm->TabIndex = 28;
			this->aParticleSwarm->Text = L"Particle Swarm Optimaliation";
			this->aParticleSwarm->UseVisualStyleBackColor = true;
			this->aParticleSwarm->Click += gcnew System::EventHandler(this, &MyForm::aParticleSwarm_Click);
			// 
			// aChargedSystem
			// 
			this->aChargedSystem->Cursor = System::Windows::Forms::Cursors::Hand;
			this->aChargedSystem->Enabled = false;
			this->aChargedSystem->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->aChargedSystem->Location = System::Drawing::Point(510, 105);
			this->aChargedSystem->Name = L"aChargedSystem";
			this->aChargedSystem->Size = System::Drawing::Size(236, 23);
			this->aChargedSystem->TabIndex = 29;
			this->aChargedSystem->Text = L"Charged system search";
			this->aChargedSystem->UseVisualStyleBackColor = true;
			this->aChargedSystem->Click += gcnew System::EventHandler(this, &MyForm::aChargedSystem_Click);
			// 
			// aGrawitional
			// 
			this->aGrawitional->Cursor = System::Windows::Forms::Cursors::Hand;
			this->aGrawitional->Enabled = false;
			this->aGrawitional->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->aGrawitional->Location = System::Drawing::Point(510, 134);
			this->aGrawitional->Name = L"aGrawitional";
			this->aGrawitional->Size = System::Drawing::Size(236, 23);
			this->aGrawitional->TabIndex = 30;
			this->aGrawitional->Text = L"Grawitational search algorithm";
			this->aGrawitional->UseVisualStyleBackColor = true;
			this->aGrawitional->Click += gcnew System::EventHandler(this, &MyForm::aGrawitional_Click);
			// 
			// aDifferential
			// 
			this->aDifferential->Cursor = System::Windows::Forms::Cursors::Hand;
			this->aDifferential->Enabled = false;
			this->aDifferential->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->aDifferential->Location = System::Drawing::Point(510, 163);
			this->aDifferential->Name = L"aDifferential";
			this->aDifferential->Size = System::Drawing::Size(236, 23);
			this->aDifferential->TabIndex = 31;
			this->aDifferential->Text = L"Differential evolution";
			this->aDifferential->UseVisualStyleBackColor = true;
			this->aDifferential->Click += gcnew System::EventHandler(this, &MyForm::aDifferential_Click);
			// 
			// aCucko
			// 
			this->aCucko->Cursor = System::Windows::Forms::Cursors::Hand;
			this->aCucko->Enabled = false;
			this->aCucko->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->aCucko->Location = System::Drawing::Point(510, 192);
			this->aCucko->Name = L"aCucko";
			this->aCucko->Size = System::Drawing::Size(236, 23);
			this->aCucko->TabIndex = 32;
			this->aCucko->Text = L"Cuckoo search";
			this->aCucko->UseVisualStyleBackColor = true;
			this->aCucko->Click += gcnew System::EventHandler(this, &MyForm::aCucko_Click);
			// 
			// aBlackHoles
			// 
			this->aBlackHoles->Cursor = System::Windows::Forms::Cursors::Hand;
			this->aBlackHoles->Enabled = false;
			this->aBlackHoles->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->aBlackHoles->Location = System::Drawing::Point(510, 221);
			this->aBlackHoles->Name = L"aBlackHoles";
			this->aBlackHoles->Size = System::Drawing::Size(236, 23);
			this->aBlackHoles->TabIndex = 33;
			this->aBlackHoles->Text = L"Black holes Algorithm";
			this->aBlackHoles->UseVisualStyleBackColor = true;
			this->aBlackHoles->Click += gcnew System::EventHandler(this, &MyForm::aBlackHoles_Click);
			// 
			// aBat
			// 
			this->aBat->Cursor = System::Windows::Forms::Cursors::Hand;
			this->aBat->Enabled = false;
			this->aBat->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->aBat->Location = System::Drawing::Point(510, 250);
			this->aBat->Name = L"aBat";
			this->aBat->Size = System::Drawing::Size(236, 23);
			this->aBat->TabIndex = 34;
			this->aBat->Text = L"Bat algorithm";
			this->aBat->UseVisualStyleBackColor = true;
			this->aBat->Click += gcnew System::EventHandler(this, &MyForm::aBat_Click);
			// 
			// shortestPath
			// 
			this->shortestPath->Cursor = System::Windows::Forms::Cursors::Hand;
			this->shortestPath->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->shortestPath->Location = System::Drawing::Point(510, 279);
			this->shortestPath->Name = L"shortestPath";
			this->shortestPath->Size = System::Drawing::Size(236, 23);
			this->shortestPath->TabIndex = 35;
			this->shortestPath->Text = L"Algorithm of searching shortest path";
			this->shortestPath->UseVisualStyleBackColor = true;
			this->shortestPath->Click += gcnew System::EventHandler(this, &MyForm::shortestPath_Click);
			// 
			// sRiver
			// 
			this->sRiver->Cursor = System::Windows::Forms::Cursors::Hand;
			this->sRiver->Enabled = false;
			this->sRiver->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->sRiver->Location = System::Drawing::Point(510, 308);
			this->sRiver->Name = L"sRiver";
			this->sRiver->Size = System::Drawing::Size(236, 23);
			this->sRiver->TabIndex = 36;
			this->sRiver->Text = L"River formation dynamic";
			this->sRiver->UseVisualStyleBackColor = true;
			this->sRiver->Click += gcnew System::EventHandler(this, &MyForm::sRiver_Click);
			// 
			// sInteligent
			// 
			this->sInteligent->Cursor = System::Windows::Forms::Cursors::Hand;
			this->sInteligent->Enabled = false;
			this->sInteligent->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->sInteligent->Location = System::Drawing::Point(510, 337);
			this->sInteligent->Name = L"sInteligent";
			this->sInteligent->Size = System::Drawing::Size(236, 23);
			this->sInteligent->TabIndex = 37;
			this->sInteligent->Text = L"Intelligent water drops";
			this->sInteligent->UseVisualStyleBackColor = true;
			this->sInteligent->Click += gcnew System::EventHandler(this, &MyForm::sInteligent_Click);
			// 
			// pseudo
			// 
			this->pseudo->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pseudo->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->pseudo->Location = System::Drawing::Point(510, 366);
			this->pseudo->Name = L"pseudo";
			this->pseudo->Size = System::Drawing::Size(236, 23);
			this->pseudo->TabIndex = 38;
			this->pseudo->Text = L"Pseudo-random number generator";
			this->pseudo->UseVisualStyleBackColor = true;
			this->pseudo->Click += gcnew System::EventHandler(this, &MyForm::pseudo_Click);
			// 
			// pUniform
			// 
			this->pUniform->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pUniform->Enabled = false;
			this->pUniform->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->pUniform->Location = System::Drawing::Point(510, 395);
			this->pUniform->Name = L"pUniform";
			this->pUniform->Size = System::Drawing::Size(236, 23);
			this->pUniform->TabIndex = 39;
			this->pUniform->Text = L"Uniform random numbers";
			this->pUniform->UseVisualStyleBackColor = true;
			this->pUniform->Click += gcnew System::EventHandler(this, &MyForm::pUniform_Click);
			// 
			// pCauchy
			// 
			this->pCauchy->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pCauchy->Enabled = false;
			this->pCauchy->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->pCauchy->Location = System::Drawing::Point(510, 424);
			this->pCauchy->Name = L"pCauchy";
			this->pCauchy->Size = System::Drawing::Size(236, 23);
			this->pCauchy->TabIndex = 40;
			this->pCauchy->Text = L"Cauchy random numbers";
			this->pCauchy->UseVisualStyleBackColor = true;
			this->pCauchy->Click += gcnew System::EventHandler(this, &MyForm::pCauchy_Click);
			// 
			// pGauss
			// 
			this->pGauss->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pGauss->Enabled = false;
			this->pGauss->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->pGauss->Location = System::Drawing::Point(510, 453);
			this->pGauss->Name = L"pGauss";
			this->pGauss->Size = System::Drawing::Size(236, 23);
			this->pGauss->TabIndex = 41;
			this->pGauss->Text = L"Gauss random nambers";
			this->pGauss->UseVisualStyleBackColor = true;
			this->pGauss->Click += gcnew System::EventHandler(this, &MyForm::pGauss_Click);
			// 
			// pLevy
			// 
			this->pLevy->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pLevy->Enabled = false;
			this->pLevy->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->pLevy->Location = System::Drawing::Point(752, 105);
			this->pLevy->Name = L"pLevy";
			this->pLevy->Size = System::Drawing::Size(236, 23);
			this->pLevy->TabIndex = 42;
			this->pLevy->Text = L"Levy random nambers";
			this->pLevy->UseVisualStyleBackColor = true;
			this->pLevy->Click += gcnew System::EventHandler(this, &MyForm::pLevy_Click);
			// 
			// extraAlgorithms
			// 
			this->extraAlgorithms->Cursor = System::Windows::Forms::Cursors::Hand;
			this->extraAlgorithms->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->extraAlgorithms->Location = System::Drawing::Point(752, 134);
			this->extraAlgorithms->Name = L"extraAlgorithms";
			this->extraAlgorithms->Size = System::Drawing::Size(236, 23);
			this->extraAlgorithms->TabIndex = 43;
			this->extraAlgorithms->Text = L"Extra algorithms";
			this->extraAlgorithms->UseVisualStyleBackColor = true;
			this->extraAlgorithms->Click += gcnew System::EventHandler(this, &MyForm::extraAlgorithms_Click);
			// 
			// eFreeFocking
			// 
			this->eFreeFocking->Cursor = System::Windows::Forms::Cursors::Hand;
			this->eFreeFocking->Enabled = false;
			this->eFreeFocking->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->eFreeFocking->Location = System::Drawing::Point(752, 163);
			this->eFreeFocking->Name = L"eFreeFocking";
			this->eFreeFocking->Size = System::Drawing::Size(236, 23);
			this->eFreeFocking->TabIndex = 44;
			this->eFreeFocking->Text = L"Free Flocking";
			this->eFreeFocking->UseVisualStyleBackColor = true;
			this->eFreeFocking->Click += gcnew System::EventHandler(this, &MyForm::eFreeFocking_Click);
			// 
			// ePSO
			// 
			this->ePSO->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ePSO->Enabled = false;
			this->ePSO->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->ePSO->Location = System::Drawing::Point(752, 279);
			this->ePSO->Name = L"ePSO";
			this->ePSO->Size = System::Drawing::Size(236, 23);
			this->ePSO->TabIndex = 45;
			this->ePSO->Text = L"Particle swarm optimalization";
			this->ePSO->UseVisualStyleBackColor = true;
			this->ePSO->Click += gcnew System::EventHandler(this, &MyForm::ePSO_Click);
			// 
			// eWanderer
			// 
			this->eWanderer->Cursor = System::Windows::Forms::Cursors::Hand;
			this->eWanderer->Enabled = false;
			this->eWanderer->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->eWanderer->Location = System::Drawing::Point(752, 192);
			this->eWanderer->Name = L"eWanderer";
			this->eWanderer->Size = System::Drawing::Size(236, 23);
			this->eWanderer->TabIndex = 44;
			this->eWanderer->Text = L"Flocking With Wanderer";
			this->eWanderer->UseVisualStyleBackColor = true;
			this->eWanderer->Click += gcnew System::EventHandler(this, &MyForm::eWanderer_Click);
			// 
			// eMouse
			// 
			this->eMouse->Cursor = System::Windows::Forms::Cursors::Hand;
			this->eMouse->Enabled = false;
			this->eMouse->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->eMouse->Location = System::Drawing::Point(752, 221);
			this->eMouse->Name = L"eMouse";
			this->eMouse->Size = System::Drawing::Size(236, 23);
			this->eMouse->TabIndex = 44;
			this->eMouse->Text = L"Flocking with mouse";
			this->eMouse->UseVisualStyleBackColor = true;
			this->eMouse->Click += gcnew System::EventHandler(this, &MyForm::eMouse_Click);
			// 
			// eMouseWanderer
			// 
			this->eMouseWanderer->Cursor = System::Windows::Forms::Cursors::Hand;
			this->eMouseWanderer->Enabled = false;
			this->eMouseWanderer->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->eMouseWanderer->Location = System::Drawing::Point(752, 250);
			this->eMouseWanderer->Name = L"eMouseWanderer";
			this->eMouseWanderer->Size = System::Drawing::Size(236, 23);
			this->eMouseWanderer->TabIndex = 44;
			this->eMouseWanderer->Text = L"Flocking - Mouse and wanderer";
			this->eMouseWanderer->UseVisualStyleBackColor = true;
			this->eMouseWanderer->Click += gcnew System::EventHandler(this, &MyForm::eMouseWanderer_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::SystemColors::HighlightText;
			this->ClientSize = System::Drawing::Size(1011, 481);
			this->Controls->Add(this->ePSO);
			this->Controls->Add(this->eMouseWanderer);
			this->Controls->Add(this->eMouse);
			this->Controls->Add(this->eWanderer);
			this->Controls->Add(this->eFreeFocking);
			this->Controls->Add(this->extraAlgorithms);
			this->Controls->Add(this->pLevy);
			this->Controls->Add(this->pGauss);
			this->Controls->Add(this->pCauchy);
			this->Controls->Add(this->pUniform);
			this->Controls->Add(this->pseudo);
			this->Controls->Add(this->sInteligent);
			this->Controls->Add(this->sRiver);
			this->Controls->Add(this->shortestPath);
			this->Controls->Add(this->aBat);
			this->Controls->Add(this->aBlackHoles);
			this->Controls->Add(this->aCucko);
			this->Controls->Add(this->aDifferential);
			this->Controls->Add(this->aGrawitional);
			this->Controls->Add(this->aChargedSystem);
			this->Controls->Add(this->aParticleSwarm);
			this->Controls->Add(this->aGlowworm);
			this->Controls->Add(this->aFireflyAlg);
			this->Controls->Add(this->aSimulatedAneaning);
			this->Controls->Add(this->AlgorithmsOf);
			this->Controls->Add(this->fSTYBINSKITANG);
			this->Controls->Add(this->fSHAFFERN4);
			this->Controls->Add(this->fSHAFFERN2);
			this->Controls->Add(this->fMCCORMICK);
			this->Controls->Add(this->fHOLDERTABLE);
			this->Controls->Add(this->fEGGHOLDER);
			this->Controls->Add(this->fCROSSTRAY);
			this->Controls->Add(this->fEASOM);
			this->Controls->Add(this->fTREEHUMPCAMMEL);
			this->Controls->Add(this->fLEVI);
			this->Controls->Add(this->fACKLEY);
			this->Controls->Add(this->fMATYAS);
			this->Controls->Add(this->fBUKIN);
			this->Controls->Add(this->fBOOTH);
			this->Controls->Add(this->fGOLDSTEINPRICE);
			this->Controls->Add(this->fBEALE);
			this->Controls->Add(this->fFOURPEAKSINVERSSE);
			this->Controls->Add(this->fFOURPICKINVERSE);
			this->Controls->Add(this->fPARABOLOID);
			this->Controls->Add(this->fRASTIGIN);
			this->Controls->Add(this->fROSENBROCK);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L" #MO";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: 
			Functions funtion;
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
	
private: System::Void AlgorithmsOf_Click(System::Object^  sender, System::EventArgs^  e) {
	for (int i = 25; i <= 45; ++i)
		this->Controls[i]->Enabled = true;

	for (int i = 0; i <= 4; ++i)
		this->Controls[i]->Enabled = false;
	for (int i = 14; i <= 23; ++i)
		this->Controls[i]->Enabled = false;
	for (int i = 6; i < 10; ++i)
		this->Controls[i]->Enabled = false;
	for (int i = 11; i <= 12; ++i)
		this->Controls[i]->Enabled = false;
	
}
private: System::Void fROSENBROCK_Click(System::Object^  sender, System::EventArgs^  e) {
	funtion = Functions::ROSENBROCK;
	for (int i = 25; i <= 45; ++i)
		this->Controls[i]->Enabled = false;
	for (int i = 14; i <= 23; ++i)
		this->Controls[i]->Enabled = true;
}
private: System::Void fRASTIGIN_Click(System::Object^  sender, System::EventArgs^  e) {
	funtion = Functions::RASTIGIN;
	for (int i = 25; i <= 45; ++i)
		this->Controls[i]->Enabled = false;
	for (int i = 14; i <= 23; ++i)
		this->Controls[i]->Enabled = true;
}
private: System::Void fPARABOLOID_Click(System::Object^  sender, System::EventArgs^  e) {
	funtion = Functions::PARABOLOID;
	for (int i = 25; i <= 45; ++i)
		this->Controls[i]->Enabled = false;
	for (int i = 14; i <= 23; ++i)
		this->Controls[i]->Enabled = true;
}
private: System::Void fFOURPICKINVERSE_Click(System::Object^  sender, System::EventArgs^  e) {
	funtion = Functions::FOUR_PICK_INVERSE;
	for (int i = 25; i <= 45; ++i)
		this->Controls[i]->Enabled = false;
	for (int i = 14; i <= 23; ++i)
		this->Controls[i]->Enabled = true;
}
private: System::Void fFOURPEAKSINVERSSE_Click(System::Object^  sender, System::EventArgs^  e) {
	funtion = Functions::FOUR_PEAKS_INVERSE;
	for (int i = 25; i <= 45; ++i)
		this->Controls[i]->Enabled = false;
	for (int i = 14; i <= 23; ++i)
		this->Controls[i]->Enabled = true;
}
private: System::Void fBEALE_Click(System::Object^  sender, System::EventArgs^  e) {
	funtion = Functions::BAEALE;
	for (int i = 25; i <= 45; ++i)
		this->Controls[i]->Enabled = false;
	for (int i = 14; i <= 23; ++i)
		this->Controls[i]->Enabled = true;
}
private: System::Void fGOLDSTEINPRICE_Click(System::Object^  sender, System::EventArgs^  e) {
	funtion = Functions::GOLDSTEIN_PRICE;
	for (int i = 25; i <= 45; ++i)
		this->Controls[i]->Enabled = false;
	for (int i = 14; i <= 23; ++i)
		this->Controls[i]->Enabled = true;
}
private: System::Void fBOOTH_Click(System::Object^  sender, System::EventArgs^  e) {
	funtion = Functions::BOOTH;
	for (int i = 25; i <= 45; ++i)
		this->Controls[i]->Enabled = false;
	for (int i = 14; i <= 23; ++i)
		this->Controls[i]->Enabled = true;
}
private: System::Void fBUKIN_Click(System::Object^  sender, System::EventArgs^  e) {
	funtion = Functions::BUKIN;
	for (int i = 25; i <= 45; ++i)
		this->Controls[i]->Enabled = false;
	for (int i = 14; i <= 23; ++i)
		this->Controls[i]->Enabled = true;
}
private: System::Void fMATYAS_Click(System::Object^  sender, System::EventArgs^  e) {
	funtion = Functions::MATYAS;
	for (int i = 25; i <= 45; ++i)
		this->Controls[i]->Enabled = false;
	for (int i = 14; i <= 23; ++i)
		this->Controls[i]->Enabled = true;
}
private: System::Void fACKLEY_Click(System::Object^  sender, System::EventArgs^  e) {
	funtion = Functions::ACKLEY;
	for (int i = 25; i <= 45; ++i)
		this->Controls[i]->Enabled = false;
	for (int i = 14; i <= 23; ++i)
		this->Controls[i]->Enabled = true;
}
private: System::Void fLEVI_Click(System::Object^  sender, System::EventArgs^  e) {
	funtion = Functions::LEVI;
	for (int i = 25; i <= 45; ++i)
		this->Controls[i]->Enabled = false;
	for (int i = 14; i <= 23; ++i)
		this->Controls[i]->Enabled = true;
}
private: System::Void fTREEHUMPCAMMEL_Click(System::Object^  sender, System::EventArgs^  e) {
	funtion = Functions::TREE_HUMP_CAMMEL;
	for (int i = 25; i <= 45; ++i)
		this->Controls[i]->Enabled = false;
	for (int i = 14; i <= 23; ++i)
		this->Controls[i]->Enabled = true;
}
private: System::Void fEASOM_Click(System::Object^  sender, System::EventArgs^  e) {
	funtion = Functions::EASOM;
	for (int i = 25; i <= 45; ++i)
		this->Controls[i]->Enabled = false;
	for (int i = 14; i <= 23; ++i)
		this->Controls[i]->Enabled = true;
}
private: System::Void fCROSSTRAY_Click(System::Object^  sender, System::EventArgs^  e) {
	funtion = Functions::CROSS_TRAY;
	for (int i = 25; i <= 45; ++i)
		this->Controls[i]->Enabled = false;
	for (int i = 14; i <= 23; ++i)
		this->Controls[i]->Enabled = true;
}
private: System::Void fEGGHOLDER_Click(System::Object^  sender, System::EventArgs^  e) {
	funtion = Functions::EGGHOLDER;
	for (int i = 25; i <= 45; ++i)
		this->Controls[i]->Enabled = false;
	for (int i = 14; i <= 23; ++i)
		this->Controls[i]->Enabled = true;
}
private: System::Void fHOLDERTABLE_Click(System::Object^  sender, System::EventArgs^  e) {
	funtion = Functions::HOLDER_TABLE;
	for (int i = 25; i <= 45; ++i)
		this->Controls[i]->Enabled = false;
	for (int i = 14; i <= 23; ++i)
		this->Controls[i]->Enabled = true;
}
private: System::Void fMCCORMICK_Click(System::Object^  sender, System::EventArgs^  e) {
	funtion = Functions::MC_CORMICK;
	for (int i = 25; i <= 45; ++i)
		this->Controls[i]->Enabled = false;
	for (int i = 14; i <= 23; ++i)
		this->Controls[i]->Enabled = true;
}
private: System::Void fSHAFFERN2_Click(System::Object^  sender, System::EventArgs^  e) {
	funtion = Functions::SHAFFER_N2;
	for (int i = 25; i <= 45; ++i)
		this->Controls[i]->Enabled = false;
	for (int i = 14; i <= 23; ++i)
		this->Controls[i]->Enabled = true;
}
private: System::Void fSHAFFERN4_Click(System::Object^  sender, System::EventArgs^  e) {
	funtion = Functions::SHAFFER_N4;
	for (int i = 25; i <= 45; ++i)
		this->Controls[i]->Enabled = false;
	for (int i = 14; i <= 23; ++i)
		this->Controls[i]->Enabled = true;
}
private: System::Void fSTYBINSKITANG_Click(System::Object^  sender, System::EventArgs^  e) {
	funtion = Functions::STYBINSKI_TANG;
	for (int i = 25; i <= 45; ++i)
		this->Controls[i]->Enabled = false;
	for (int i = 14; i <= 23; ++i)
		this->Controls[i]->Enabled = true;
}
private: System::Void aSimulatedAneaning_Click(System::Object^  sender, System::EventArgs^  e) {
	auto fun = getFunction(funtion);
	fun = getFunction(funtion);
	SilumatedAneaning sim(std::get<0>(fun), std::get<1>(fun), std::get<2>(fun));
	sim.run();
}
private: System::Void aFireflyAlg_Click(System::Object^  sender, System::EventArgs^  e) {
	auto fun = getFunction(funtion);
	fun = getFunction(funtion);
	FireflyAlgorithm firefly(std::get<0>(fun), std::get<1>(fun), std::get<2>(fun), 20);
	firefly.run(50);
}
private: System::Void aGlowworm_Click(System::Object^  sender, System::EventArgs^  e) {
	auto fun = getFunction(funtion);
	fun = getFunction(funtion);
	GlowwarmSwarmAlgorithm glow(std::get<0>(fun), std::get<1>(fun), std::get<2>(fun), 200);
	glow.run(50);
}
private: System::Void aParticleSwarm_Click(System::Object^  sender, System::EventArgs^  e) {
	auto fun = getFunction(funtion);
	fun = getFunction(funtion);
	Pso pso(std::get<0>(fun), std::get<1>(fun), std::get<2>(fun), 25);
	pso.run(50);
}
private: System::Void aChargedSystem_Click(System::Object^  sender, System::EventArgs^  e) {
	auto fun = getFunction(funtion);
	fun = getFunction(funtion);
	ChargedSystemSearch chargetSystemSearch(std::get<0>(fun), std::get<1>(fun), std::get<2>(fun), 40);
	chargetSystemSearch.run(50);
}
private: System::Void aGrawitional_Click(System::Object^  sender, System::EventArgs^  e) {
	auto fun = getFunction(funtion);
	fun = getFunction(funtion);
	GrawitationalSearchAlgorithm grawitationalSearchAlgorithm(std::get<0>(fun), std::get<1>(fun), std::get<2>(fun), 40);
	grawitationalSearchAlgorithm.run(50);
}
private: System::Void aDifferential_Click(System::Object^  sender, System::EventArgs^  e) {
	auto fun = getFunction(funtion);
	fun = getFunction(funtion);
	DifferentialEvolution differentialEvolution(std::get<0>(fun), std::get<1>(fun), std::get<2>(fun), 10, 0.1);
	differentialEvolution.run();
}
private: System::Void aCucko_Click(System::Object^  sender, System::EventArgs^  e) {
	auto fun = getFunction(funtion);
	fun = getFunction(funtion);
	CuckooSearch cuckooSearch(std::get<0>(fun), std::get<1>(fun), std::get<2>(fun));
	cuckooSearch.run(50);
}
private: System::Void aBlackHoles_Click(System::Object^  sender, System::EventArgs^  e) {
	auto fun = getFunction(funtion);
	fun = getFunction(funtion);
	BlackHolesAlgorithm bh(std::get<0>(fun), std::get<1>(fun), std::get<2>(fun));
	bh.run(50);
}
private: System::Void aBat_Click(System::Object^  sender, System::EventArgs^  e) {
	auto fun = getFunction(funtion);
	fun = getFunction(funtion);
	BatAlgorithm batAlgorithm(std::get<0>(fun), std::get<1>(fun), std::get<2>(fun));
	batAlgorithm.run(50);
}
private: System::Void shortestPath_Click(System::Object^  sender, System::EventArgs^  e) {
	for (int i = 25; i <= 45; ++i)
		this->Controls[i]->Enabled = false;

	for (int i = 0; i <= 4; ++i)
		this->Controls[i]->Enabled = false;
	for (int i = 14; i <= 23; ++i)
		this->Controls[i]->Enabled = false;
	for (int i = 6; i < 10; ++i)
		this->Controls[i]->Enabled = false;
	for (int i = 11; i <= 12; ++i)
		this->Controls[i]->Enabled = true;
}
private: System::Void sRiver_Click(System::Object^  sender, System::EventArgs^  e) {
	RiverFormationDynamic riverFormationDynamics("./graph.txt");
	riverFormationDynamics.run();
}
private: System::Void sInteligent_Click(System::Object^  sender, System::EventArgs^  e) {
	IntelligentWaterDrops inteligentWaterDrops("./graph.txt");
	inteligentWaterDrops.run();
}
private: System::Void pseudo_Click(System::Object^  sender, System::EventArgs^  e) {
	for (int i = 25; i <= 45; ++i)
		this->Controls[i]->Enabled = false;

	for (int i = 0; i <= 4; ++i)
		this->Controls[i]->Enabled = false;
	for (int i = 14; i <= 23; ++i)
		this->Controls[i]->Enabled = false;
	for (int i = 6; i < 10; ++i)
		this->Controls[i]->Enabled = true;
	for (int i = 11; i <= 12; ++i)
		this->Controls[i]->Enabled = false;
}
private: System::Void pUniform_Click(System::Object^  sender, System::EventArgs^  e) {
	UniformRandomNumbers uniformRandomNumbers;
	uniformRandomNumbers.run();
}
private: System::Void pCauchy_Click(System::Object^  sender, System::EventArgs^  e) {
	CauchyRandomNumbers cauchyRandomNumbers;
	cauchyRandomNumbers.run();
}
private: System::Void pGauss_Click(System::Object^  sender, System::EventArgs^  e) {
	GaussRandomNumbers gaussRandomNumbers;
	gaussRandomNumbers.run();
}
private: System::Void pLevy_Click(System::Object^  sender, System::EventArgs^  e) {

	LevyRandomNumbers levyRandomNumbers;
	levyRandomNumbers.run();
}
private: System::Void extraAlgorithms_Click(System::Object^  sender, System::EventArgs^  e) {
	for (int i = 25; i <= 45; ++i)
		this->Controls[i]->Enabled = false;

	for (int i = 0; i <= 4; ++i)
		this->Controls[i]->Enabled = true;
	for (int i = 14; i <= 23; ++i)
		this->Controls[i]->Enabled = false;
	for (int i = 6; i < 10; ++i)
		this->Controls[i]->Enabled = false;
	for (int i = 11; i <= 12; ++i)
		this->Controls[i]->Enabled = false;
}
private: System::Void eFreeFocking_Click(System::Object^  sender, System::EventArgs^  e) {
	Flocking flocking(50, 600, 600);
	flocking.freeFlocking();
}
private: System::Void eWanderer_Click(System::Object^  sender, System::EventArgs^  e) {
	Flocking flocking(50, 600, 600);
	flocking.wandererFlocking();
}
private: System::Void eMouse_Click(System::Object^  sender, System::EventArgs^  e) {
	Flocking flocking(50, 600, 600);
	flocking.flockingMouse();
}
private: System::Void eMouseWanderer_Click(System::Object^  sender, System::EventArgs^  e) {
	Flocking flocking(50, 600, 600);
	flocking.wandererMouseFlocking();
}
private: System::Void ePSO_Click(System::Object^  sender, System::EventArgs^  e) {
	ParticleSwarmOptimalization ps(glm::vec2(800), glm::vec2(-5, -5), glm::vec2(5, 5));
	ps.run();
}
};
}
