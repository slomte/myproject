#define ttbar_1l_1Mevt_cxx
#include "ttbar_1l_1Mevt.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

//*******
#include <TH1.h>
#include <TMath.h>
#include <TLorentzVector.h>
#include <iostream>

void ttbar_1l_1Mevt::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L ttbar_1l_1Mevt.C
//      Root > ttbar_1l_1Mevt t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
//**************
   cout<<"Hello!!"<<endl;

   using namespace std;

   //declare the histograms to use
   TH1::SetDefaultBufferSize();

   histo[0] = new TH1D("t_PT", "PT of top", 100, 0, 2500);
   histo[1] = new TH1D("b_PT", "PT of bottom", 100, 0, 2500);
   histo[2] = new TH1D("W_PT", "PT of W boson", 100, 0, 2500);
   histo[3] = new TH1D("j_PT", "PT of jets", 100, 0, 1500);
   histo[4] = new TH1D("l_PT", "PT of leps", 100, 0, 1500);
   histo[5] = new TH1D("ak4_PT", "PT of AK4Jets", 100, 0, 2000);
   histo[6] = new TH1D("ak8_PT", "PT of AK8Jets", 100, 0, 2000);
   histo[7] = new TH1D("ak12_PT", "PT of AK12Jets", 100, 0, 2000);
   histo[8] = new TH1D("fatj_PT", "PT of FatJets", 100, 0, 2000);

   histo[9] = new TH1D("HT", "HT", 100, 0, 5000);
   histo[12] = new TH1D("MET", "MET", 100, 0, 1500);

   histo[13] = new TH1D("t_N", "N of top", 5, 0, 5);
   histo[14] = new TH1D("b_N", "N of bottom", 5, 0, 5);
   histo[15] = new TH1D("W_N", "N of W boson", 5, 0, 5);
   histo[16] = new TH1D("j_N", "N of jets", 20, 0, 20);
   histo[17] = new TH1D("l_N", "N of leps", 10, 0, 10);
   histo[18] = new TH1D("ak4_N", "N of AK4Jets", 20, 0, 20);
   histo[19] = new TH1D("ak8_N", "N of AK8Jets", 20, 0, 20);
   histo[20] = new TH1D("ak12_N", "N of AK12Jets", 20, 0, 20);
   histo[21] = new TH1D("fatj_N", "N of FatJets", 10, 0, 10);

   histo[22] = new TH1D("j_M", "Mass of jets", 100, 0, 500);
   histo[23] = new TH1D("ak4_M", "Mass of AK4Jets", 100, 0, 500);
   histo[24] = new TH1D("ak8_M", "Mass of AK8Jets", 100, 0, 500);
   histo[25] = new TH1D("ak12_M", "Mass of AK12Jets", 100, 0, 500);
   histo[26] = new TH1D("fatj_M", "Mass of FatJets", 100, 0, 1000);


//---------------------------------------------------------------
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
//--------------------------------------------------------------

      //truthtop.clear();

//-------------------------------------------

//mycode

float Weight = (102.1837*35.9*1000)/(1000000);

//MET
Float_t met = MissingET_MET[0];
histo[12]->Fill(met, Weight);
//HT
Float_t ht = ScalarHT_HT[0];
histo[9]->Fill(ht, Weight);

int N_t=0; int N_b=0; int N_W=0;
//Particles
int NPar=Particle_size;
for(int i=0; i<NPar; i++){
  //top
  if(abs(Particle_PID[i])==6) {
    histo[0]->Fill(Particle_PT[i], Weight);
    N_t=N_t+1;
  }
  //bottom
  if(abs(Particle_PID[i])==5) {
    histo[1]->Fill(Particle_PT[i], Weight);
    N_b=N_b+1;
  }
  //W
  if(abs(Particle_PID[i])==24) {
    histo[2]->Fill(Particle_PT[i], Weight);
    N_W=N_W+1;
  }
}//par loop
histo[13]->Fill(N_t, Weight);
histo[14]->Fill(N_t, Weight);
histo[15]->Fill(N_t, Weight);

//Jets
int Njets=Jet_size;
for(int j=0; j<Njets; j++){

  if(Jet_PT[j]>5 && abs(Jet_Eta[j])<2.4){
    histo[3]->Fill(Jet_PT[j], Weight);
    histo[22]->Fill(Jet_Mass[j], Weight);
  }
} 
histo[16]->Fill(Njets, Weight);
//AK4Jets
int NAK4jets=AK4_Jet_size;
for(int j=0; j<NAK4jets; j++){

  if(AK4_Jet_PT[j]>5 && abs(AK4_Jet_Eta[j])<2.4){
    histo[5]->Fill(AK4_Jet_PT[j], Weight);
    histo[23]->Fill(AK4_Jet_Mass[j], Weight);
  }
} 
histo[18]->Fill(NAK4jets, Weight);
//AK8Jets
int NAK8jets=AK8_Jet_size;
for(int j=0; j<NAK8jets; j++){

  if(AK8_Jet_PT[j]>5 && abs(AK8_Jet_Eta[j])<2.4){
    histo[6]->Fill(AK8_Jet_PT[j], Weight);
    histo[24]->Fill(AK8_Jet_Mass[j], Weight);
  }
} 
histo[19]->Fill(NAK8jets, Weight);
//AK12Jets
int NAK12jets=AK12_Jet_size;
for(int j=0; j<NAK12jets; j++){

  if(AK12_Jet_PT[j]>5 && abs(AK12_Jet_Eta[j])<2.4){
    histo[7]->Fill(AK12_Jet_PT[j], Weight);
    histo[25]->Fill(AK12_Jet_Mass[j], Weight);
  }
} 
histo[20]->Fill(NAK12jets, Weight);
//FatJets
int Nfatjets=FatJet_size;
for(int j=0; j<Nfatjets; j++){

  if(FatJet_PT[j]>5 && abs(FatJet_Eta[j])<2.4){
    histo[8]->Fill(FatJet_PT[j], Weight);
    histo[26]->Fill(FatJet_Mass[j], Weight);
  }
} 
histo[21]->Fill(Nfatjets, Weight);

//Reco Leptons
int NElecs=Electron_size;
for(int k=0; k<NElecs; k++){

  if(Electron_PT[k]>5 && abs(Muon_Eta[k])<2.4){
    histo[4]->Fill(Electron_PT[k], Weight);
  }
} 
int NMus=Muon_size;
for(int k=0; k<NMus; k++){

  if(Muon_PT[k]>5 && abs(Muon_Eta[k])<2.4){
    histo[4]->Fill(Muon_PT[k], Weight);
  }
} 
int Nleps = Electron_size+Muon_size;
histo[17]->Fill(Nleps, Weight);


    }//event loop
   this->Output();
}//void loop
//-------------------------------------------
Int_t ttbar_1l_1Mevt::Output()
{
  TFile *rootfile = new TFile("Hst_ttbar_1l_1Mevt.root", "RECREATE");

  histo[0]->Write();
  histo[1]->Write();
  histo[2]->Write();
  histo[3]->Write();
  histo[4]->Write();
  histo[5]->Write();
  histo[6]->Write();
  histo[7]->Write();
  histo[8]->Write();
  histo[9]->Write();
//  histo[10]->Write();
//  histo[11]->Write();
  histo[12]->Write();
  histo[13]->Write();
  histo[14]->Write();
  histo[15]->Write();
  histo[16]->Write();
  histo[17]->Write();
  histo[18]->Write();
  histo[19]->Write();
  histo[20]->Write();
  histo[21]->Write();
  histo[22]->Write();
  histo[23]->Write();
  histo[24]->Write();
  histo[25]->Write();
  histo[26]->Write();
/*  histo[27]->Write();
  histo[28]->Write();
  histo[29]->Write();
*/

  rootfile->Write();
  rootfile->Close();

  return 0;
}

//---------------------------------------------------
