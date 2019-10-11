//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Oct  8 14:09:56 2019 by ROOT version 6.10/08
// from TTree PreSelection/PreSelection
// found on file: SkimTTbar_HT_600_800_Nov29_0123.root
//////////////////////////////////////////////////////////

#ifndef SkimTTbar_HT_600_800_Nov29_0123_h
#define SkimTTbar_HT_600_800_Nov29_0123_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

//*******(I added)
#include <TH1.h>
#include <TH2.h>
#include <vector>
#include <TLorentzVector.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"
#include "vector"

class SkimTTbar_HT_600_800_Nov29_0123 {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   UInt_t          RunNum;
   UInt_t          LumiBlockNum;
   ULong64_t       EvtNum;
   Bool_t          BadChargedCandidateFilter;
   Bool_t          BadPFMuonFilter;
   Int_t           BTags;
   Int_t           BTagsMVA;
   Double_t        CrossSection;
   Int_t           CSCTightHaloFilter;
   Double_t        DeltaPhi1;
   Double_t        DeltaPhi2;
   Double_t        DeltaPhi3;
   Double_t        DeltaPhi4;
   Int_t           EcalDeadCellTriggerPrimitiveFilter;
   Int_t           eeBadScFilter;
   vector<TLorentzVector> *Electrons;
   vector<double>  *Electrons_MTW;
   vector<TLorentzVector> *GenElectrons;
   vector<bool>    *GenElectrons_fromTau;
   vector<TLorentzVector> *GenMuons;
   vector<bool>    *GenMuons_fromTau;
   vector<TLorentzVector> *GenTaus;
   vector<bool>    *GenTaus_had;
   Int_t           globalTightHalo2016Filter;
   Int_t           HBHEIsoNoiseFilter;
   Int_t           HBHENoiseFilter;
   Double_t        HT;
   Int_t           isoElectronTracks;
   Int_t           isoMuonTracks;
   Int_t           isoPionTracks;
   vector<TLorentzVector> *Jets;
   vector<double>  *Jets_bDiscriminatorCSV;
   vector<int>     *Jets_hadronFlavor;
   vector<bool>    *Jets_HTMask;
   vector<bool>    *Jets_ID;
   vector<double>  *Jets_muonEnergyFraction;
   Double_t        madHT;
   Double_t        MET;
   Double_t        METPhi;
   Double_t        MHT;
   Double_t        MHTPhi;
   vector<TLorentzVector> *Muons;
   vector<double>  *Muons_MTW;
   Int_t           NJets;
   Int_t           NJetsISR;
   Int_t           NVtx;
   Double_t        PFCaloMETRatio;
   Double_t        puWeight;
   vector<string>  *TriggerNames;
   vector<int>     *TriggerPass;
   Double_t        TrueNumInteractions;
   Double_t        Weight;

   // List of branches
   TBranch        *b_RunNum;   //!
   TBranch        *b_LumiBlockNum;   //!
   TBranch        *b_EvtNum;   //!
   TBranch        *b_BadChargedCandidateFilter;   //!
   TBranch        *b_BadPFMuonFilter;   //!
   TBranch        *b_BTags;   //!
   TBranch        *b_BTagsMVA;   //!
   TBranch        *b_CrossSection;   //!
   TBranch        *b_CSCTightHaloFilter;   //!
   TBranch        *b_DeltaPhi1;   //!
   TBranch        *b_DeltaPhi2;   //!
   TBranch        *b_DeltaPhi3;   //!
   TBranch        *b_DeltaPhi4;   //!
   TBranch        *b_EcalDeadCellTriggerPrimitiveFilter;   //!
   TBranch        *b_eeBadScFilter;   //!
   TBranch        *b_Electrons;   //!
   TBranch        *b_Electrons_MTW;   //!
   TBranch        *b_GenElectrons;   //!
   TBranch        *b_GenElectrons_fromTau;   //!
   TBranch        *b_GenMuons;   //!
   TBranch        *b_GenMuons_fromTau;   //!
   TBranch        *b_GenTaus;   //!
   TBranch        *b_GenTaus_had;   //!
   TBranch        *b_globalTightHalo2016Filter;   //!
   TBranch        *b_HBHEIsoNoiseFilter;   //!
   TBranch        *b_HBHENoiseFilter;   //!
   TBranch        *b_HT;   //!
   TBranch        *b_isoElectronTracks;   //!
   TBranch        *b_isoMuonTracks;   //!
   TBranch        *b_isoPionTracks;   //!
   TBranch        *b_Jets;   //!
   TBranch        *b_Jets_bDiscriminatorCSV;   //!
   TBranch        *b_Jets_hadronFlavor;   //!
   TBranch        *b_Jets_HTMask;   //!
   TBranch        *b_Jets_ID;   //!
   TBranch        *b_Jets_muonEnergyFraction;   //!
   TBranch        *b_madHT;   //!
   TBranch        *b_MET;   //!
   TBranch        *b_METPhi;   //!
   TBranch        *b_MHT;   //!
   TBranch        *b_MHTPhi;   //!
   TBranch        *b_Muons;   //!
   TBranch        *b_Muons_MTW;   //!
   TBranch        *b_NJets;   //!
   TBranch        *b_NJetsISR;   //!
   TBranch        *b_NVtx;   //!
   TBranch        *b_PFCaloMETRatio;   //!
   TBranch        *b_puWeight;   //!
   TBranch        *b_TriggerNames;   //!
   TBranch        *b_TriggerPass;   //!
   TBranch        *b_TrueNumInteractions;   //!
   TBranch        *b_Weight;   //!

   SkimTTbar_HT_600_800_Nov29_0123(TTree *tree=0);
   virtual ~SkimTTbar_HT_600_800_Nov29_0123();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Int_t    Output();//*******
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
//*********
   void BookHistograms();

   private:
   //declare histograms
   TH1D* histo[300];
   //TH2D* hist2[20];

   struct Part {
     TLorentzVector v;
     int id;
     int ind;
     int flavor;
     int Charge;
     int D1;
     int D2;
     int M1;
     int M2;
   };

   vector <TLorentzVector> reco_jets;
   vector <TLorentzVector> reco_bjets;
   vector <TLorentzVector> reco_leps;
   vector <TLorentzVector> reco_RbbJ;
   vector <TLorentzVector> reco_HbbJ;

};

#endif

#ifdef SkimTTbar_HT_600_800_Nov29_0123_cxx
SkimTTbar_HT_600_800_Nov29_0123::SkimTTbar_HT_600_800_Nov29_0123(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("SkimTTbar_HT_600_800_Nov29_0123.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("SkimTTbar_HT_600_800_Nov29_0123.root");
      }
      f->GetObject("PreSelection",tree);

   }
   Init(tree);
}

SkimTTbar_HT_600_800_Nov29_0123::~SkimTTbar_HT_600_800_Nov29_0123()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t SkimTTbar_HT_600_800_Nov29_0123::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t SkimTTbar_HT_600_800_Nov29_0123::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void SkimTTbar_HT_600_800_Nov29_0123::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   Electrons = 0;
   Electrons_MTW = 0;
   GenElectrons = 0;
   GenElectrons_fromTau = 0;
   GenMuons = 0;
   GenMuons_fromTau = 0;
   GenTaus = 0;
   GenTaus_had = 0;
   Jets = 0;
   Jets_bDiscriminatorCSV = 0;
   Jets_hadronFlavor = 0;
   Jets_HTMask = 0;
   Jets_ID = 0;
   Jets_muonEnergyFraction = 0;
   Muons = 0;
   Muons_MTW = 0;
   TriggerNames = 0;
   TriggerPass = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("RunNum", &RunNum, &b_RunNum);
   fChain->SetBranchAddress("LumiBlockNum", &LumiBlockNum, &b_LumiBlockNum);
   fChain->SetBranchAddress("EvtNum", &EvtNum, &b_EvtNum);
   fChain->SetBranchAddress("BadChargedCandidateFilter", &BadChargedCandidateFilter, &b_BadChargedCandidateFilter);
   fChain->SetBranchAddress("BadPFMuonFilter", &BadPFMuonFilter, &b_BadPFMuonFilter);
   fChain->SetBranchAddress("BTags", &BTags, &b_BTags);
   fChain->SetBranchAddress("BTagsMVA", &BTagsMVA, &b_BTagsMVA);
   fChain->SetBranchAddress("CrossSection", &CrossSection, &b_CrossSection);
   fChain->SetBranchAddress("CSCTightHaloFilter", &CSCTightHaloFilter, &b_CSCTightHaloFilter);
   fChain->SetBranchAddress("DeltaPhi1", &DeltaPhi1, &b_DeltaPhi1);
   fChain->SetBranchAddress("DeltaPhi2", &DeltaPhi2, &b_DeltaPhi2);
   fChain->SetBranchAddress("DeltaPhi3", &DeltaPhi3, &b_DeltaPhi3);
   fChain->SetBranchAddress("DeltaPhi4", &DeltaPhi4, &b_DeltaPhi4);
   fChain->SetBranchAddress("EcalDeadCellTriggerPrimitiveFilter", &EcalDeadCellTriggerPrimitiveFilter, &b_EcalDeadCellTriggerPrimitiveFilter);
   fChain->SetBranchAddress("eeBadScFilter", &eeBadScFilter, &b_eeBadScFilter);
   fChain->SetBranchAddress("Electrons", &Electrons, &b_Electrons);
   fChain->SetBranchAddress("Electrons_MTW", &Electrons_MTW, &b_Electrons_MTW);
   fChain->SetBranchAddress("GenElectrons", &GenElectrons, &b_GenElectrons);
   fChain->SetBranchAddress("GenElectrons_fromTau", &GenElectrons_fromTau, &b_GenElectrons_fromTau);
   fChain->SetBranchAddress("GenMuons", &GenMuons, &b_GenMuons);
   fChain->SetBranchAddress("GenMuons_fromTau", &GenMuons_fromTau, &b_GenMuons_fromTau);
   fChain->SetBranchAddress("GenTaus", &GenTaus, &b_GenTaus);
   fChain->SetBranchAddress("GenTaus_had", &GenTaus_had, &b_GenTaus_had);
   fChain->SetBranchAddress("globalTightHalo2016Filter", &globalTightHalo2016Filter, &b_globalTightHalo2016Filter);
   fChain->SetBranchAddress("HBHEIsoNoiseFilter", &HBHEIsoNoiseFilter, &b_HBHEIsoNoiseFilter);
   fChain->SetBranchAddress("HBHENoiseFilter", &HBHENoiseFilter, &b_HBHENoiseFilter);
   fChain->SetBranchAddress("HT", &HT, &b_HT);
   fChain->SetBranchAddress("isoElectronTracks", &isoElectronTracks, &b_isoElectronTracks);
   fChain->SetBranchAddress("isoMuonTracks", &isoMuonTracks, &b_isoMuonTracks);
   fChain->SetBranchAddress("isoPionTracks", &isoPionTracks, &b_isoPionTracks);
   fChain->SetBranchAddress("Jets", &Jets, &b_Jets);
   fChain->SetBranchAddress("Jets_bDiscriminatorCSV", &Jets_bDiscriminatorCSV, &b_Jets_bDiscriminatorCSV);
   fChain->SetBranchAddress("Jets_hadronFlavor", &Jets_hadronFlavor, &b_Jets_hadronFlavor);
   fChain->SetBranchAddress("Jets_HTMask", &Jets_HTMask, &b_Jets_HTMask);
   fChain->SetBranchAddress("Jets_ID", &Jets_ID, &b_Jets_ID);
   fChain->SetBranchAddress("Jets_muonEnergyFraction", &Jets_muonEnergyFraction, &b_Jets_muonEnergyFraction);
   fChain->SetBranchAddress("madHT", &madHT, &b_madHT);
   fChain->SetBranchAddress("MET", &MET, &b_MET);
   fChain->SetBranchAddress("METPhi", &METPhi, &b_METPhi);
   fChain->SetBranchAddress("MHT", &MHT, &b_MHT);
   fChain->SetBranchAddress("MHTPhi", &MHTPhi, &b_MHTPhi);
   fChain->SetBranchAddress("Muons", &Muons, &b_Muons);
   fChain->SetBranchAddress("Muons_MTW", &Muons_MTW, &b_Muons_MTW);
   fChain->SetBranchAddress("NJets", &NJets, &b_NJets);
   fChain->SetBranchAddress("NJetsISR", &NJetsISR, &b_NJetsISR);
   fChain->SetBranchAddress("NVtx", &NVtx, &b_NVtx);
   fChain->SetBranchAddress("PFCaloMETRatio", &PFCaloMETRatio, &b_PFCaloMETRatio);
   fChain->SetBranchAddress("puWeight", &puWeight, &b_puWeight);
   fChain->SetBranchAddress("TriggerNames", &TriggerNames, &b_TriggerNames);
   fChain->SetBranchAddress("TriggerPass", &TriggerPass, &b_TriggerPass);
   fChain->SetBranchAddress("TrueNumInteractions", &TrueNumInteractions, &b_TrueNumInteractions);
   fChain->SetBranchAddress("Weight", &Weight, &b_Weight);
   Notify();
}

Bool_t SkimTTbar_HT_600_800_Nov29_0123::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void SkimTTbar_HT_600_800_Nov29_0123::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t SkimTTbar_HT_600_800_Nov29_0123::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef SkimTTbar_HT_600_800_Nov29_0123_cxx
