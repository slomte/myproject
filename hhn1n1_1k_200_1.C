#define hhn1n1_1k_200_1_cxx
#include "hhn1n1_1k_200_1.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

//*******
#include <TH1.h>
#include <TMath.h>
#include <TLorentzVector.h>
#include <iostream>

void hhn1n1_1k_200_1::Loop()
{
//   In a ROOT session, you can do:
//      root> .L hhn1n1_1k_200_1.C
//      root> hhn1n1_1k_200_1 t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
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

   histo[0] = new TH1D("st_PT", "PT of stop", 100, 0, 2500);
   histo[1] = new TH1D("t_PT", "PT of top", 100, 0, 2500);
   histo[2] = new TH1D("n2_PT", "PT of Neu2", 100, 0, 2500);
   histo[3] = new TH1D("b_PT", "PT of bottom", 100, 0, 2500);
   histo[4] = new TH1D("W_PT", "PT of W boson", 100, 0, 2500);
   histo[5] = new TH1D("H_PT", "PT of H boson", 100, 0, 2500);
   histo[6] = new TH1D("n1_PT", "PT of Neu1", 100, 0, 2500);

   histo[7] = new TH1D("j_PT", "PT of jet", 100, 0, 1500);
   histo[8] = new TH1D("l_PT", "PT of lepton", 100, 0, 1500);
   histo[9] = new TH1D("MET", "MET", 100, 0, 1500);
   histo[21] = new TH1D("HT", "HT", 100, 0, 5000);

   histo[10] = new TH1D("Nj", "NJets", 20, 0, 20);
   histo[11] = new TH1D("Nl", "NLeps", 10, 0, 10);

   histo[12] = new TH1D("N_ak4j", "NAK4Jets", 20, 0, 20);
   histo[13] = new TH1D("N_ak8j", "NAK8Jets", 20, 0, 20);
   histo[14] = new TH1D("N_fatj", "N Fat Jets", 10, 0, 10);
   histo[15] = new TH1D("PT_ak4j", "pT of AK4Jets", 100, 0, 2000);
   histo[16] = new TH1D("PT_ak8j", "pT of AK8Jets", 100, 0, 2000);
   histo[17] = new TH1D("PT_fatj", "pT of Fat Jets", 100, 0, 2000);
   histo[18] = new TH1D("M_ak4j", "Mass of AK4Jets", 100, 0, 500);
   histo[19] = new TH1D("M_ak8j", "Mass of AK8Jets", 100, 0, 500);
   histo[20] = new TH1D("M_fatj", "Mass of Fat Jets", 100, 0, 1000);




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

     //clear the vectors




//-------------------------------------------

//mycode

float Weight = (0.0476*35.9*1000)/(10000);
//cout<<"new event"<<endl;
//Particles
int NPar=Particle_size;
for(int i=0; i<NPar; i++){

  //stop
  if(abs(Particle_PID[i])==1000006) {
    histo[0]->Fill(Particle_PT[i], Weight);
  }
  //top
  if(abs(Particle_PID[i])==6) {
    histo[1]->Fill(Particle_PT[i], Weight);
  }
  //Neu2
  if(abs(Particle_PID[i])==1000023 && Particle_PID[Particle_M1[i]]!=1000023) {
    histo[2]->Fill(Particle_PT[i], Weight);
  }
  //b
  if(Particle_PID[i]==5 && Particle_PID[Particle_M1[i]]==6) {
    histo[3]->Fill(Particle_PT[i], Weight);
  }
  if(Particle_PID[i]==-5 && Particle_PID[Particle_M1[i]]==-6) {
    histo[3]->Fill(Particle_PT[i], Weight);
  }
  //W
  if(Particle_PID[i]==24 && Particle_PID[Particle_M1[i]]==6) {
    histo[4]->Fill(Particle_PT[i], Weight);
  }
  if(Particle_PID[i]==-24 && Particle_PID[Particle_M1[i]]==-6) {
    histo[4]->Fill(Particle_PT[i], Weight);
  }
  //H
  if(abs(Particle_PID[i])==25 && Particle_PID[Particle_M1[i]]!=25) {
    histo[5]->Fill(Particle_PT[i], Weight);
  }
  //Neu1
  if(abs(Particle_PID[i])==1000022 && Particle_PID[Particle_M1[i]]!=1000022) {
    histo[6]->Fill(Particle_PT[i], Weight);
  }

}//par loop

//Jets
int Njets=Jet_size;
for(int j=0; j<Njets; j++){

  if(Jet_PT[j]>5 && abs(Jet_Eta[j])<2.4){
    histo[7]->Fill(Jet_PT[j], Weight);
  }
} 
histo[10]->Fill(Njets, Weight);
//AK4Jets
int NAK4jets=AK4_Jet_size;
for(int j=0; j<NAK4jets; j++){

  if(AK4_Jet_PT[j]>5 && abs(AK4_Jet_Eta[j])<2.4){
    histo[15]->Fill(AK4_Jet_PT[j], Weight);
    histo[18]->Fill(AK4_Jet_Mass[j], Weight);
  }
} 
histo[12]->Fill(NAK4jets, Weight);
//AK8Jets
int NAK8jets=AK8_Jet_size;
for(int j=0; j<NAK8jets; j++){

  if(AK8_Jet_PT[j]>5 && abs(AK8_Jet_Eta[j])<2.4){
    histo[16]->Fill(AK8_Jet_PT[j], Weight);
    histo[19]->Fill(AK8_Jet_Mass[j], Weight);
  }
} 
histo[13]->Fill(NAK8jets, Weight);
//FatJets
int Nfatjets=FatJet_size;
for(int j=0; j<Nfatjets; j++){

  if(FatJet_PT[j]>5 && abs(FatJet_Eta[j])<2.4){
    histo[17]->Fill(FatJet_PT[j], Weight);
    histo[20]->Fill(FatJet_Mass[j], Weight);
  }
} 
histo[14]->Fill(Nfatjets, Weight);
 
//Reco Leptons
int NElecs=Electron_size;
for(int k=0; k<NElecs; k++){

  if(Electron_PT[k]>5 && abs(Muon_Eta[k])<2.4){
    histo[8]->Fill(Electron_PT[k], Weight);
  }
} 
int NMus=Muon_size;
for(int k=0; k<NMus; k++){

  if(Muon_PT[k]>5 && abs(Muon_Eta[k])<2.4){
    histo[8]->Fill(Muon_PT[k], Weight);
  }
} 
int Nleps = Electron_size+Muon_size;
histo[11]->Fill(Nleps, Weight);
//MET
Float_t met = MissingET_MET[0];
histo[9]->Fill(met, Weight);
//HT
Float_t ht = ScalarHT_HT[0];
histo[21]->Fill(ht, Weight);

   }//event loop
   this->Output();
}
//-------------------------------------------
Int_t hhn1n1_1k_200_1::Output()
{
  TFile *rootfile = new TFile("Hst_hhn1n1_1k_200_1.root", "RECREATE");

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
  histo[21]->Write();
  histo[10]->Write();
  histo[11]->Write();
  histo[12]->Write();
  histo[13]->Write();
  histo[14]->Write();
  histo[15]->Write();
  histo[16]->Write();
  histo[17]->Write();
  histo[18]->Write();
  histo[19]->Write();
  histo[20]->Write();


  rootfile->Write();
  rootfile->Close();

  return 0;
}

//---------------------------------------------------
