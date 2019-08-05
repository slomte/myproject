#define stopstop_topN2_topN1_600300_cxx
#include "stopstop_topN2_topN1_600300.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

//*******
#include <TH1.h>
#include <TMath.h>
#include <TLorentzVector.h>
#include <iostream>

void stopstop_topN2_topN1_600300::Loop()
{
//   In a ROOT session, you can do:
//      root> .L stopstop_topN2_topN1_600300.C
//      root> stopstop_topN2_topN1_600300 t
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
   histo[1] = new TH1D("st~_PT", "PT of stop~", 100, 0, 2500);
   histo[2] = new TH1D("n2_PT", "PT of Neu2", 100, 0, 2000);
   //histo[3] = new TH1D("n2~_PT", "PT of Neu2~", 100, 0, 2000);
   histo[4] = new TH1D("n1_PT", "PT of Neu1", 100, 0, 1500);
   histo[5] = new TH1D("n1~_PT", "PT of Neu1~", 100, 0, 1500);

   histo[6] = new TH1D("t_PT", "PT of top", 100, 0, 2500);
   histo[7] = new TH1D("t~_PT", "PT of antitop", 100, 0, 2500);
   histo[8] = new TH1D("b_t_PT", "PT of b from t", 100, 0, 2500);
   histo[9] = new TH1D("b~_t_PT", "PT of b~ from t~", 100, 0, 2500);
   histo[10] = new TH1D("W_PT", "PT of W+", 100, 0, 2500);
   histo[11] = new TH1D("W~_PT", "PT of W-", 100, 0, 2500);
   histo[12] = new TH1D("H_PT", "PT of H boson", 100, 0, 1000);
   //histo[13] = new TH1D("Z_PT", "PT of Z boson", 100, 0, 1000);
   histo[14] = new TH1D("b_H_PT", "PT of b from H", 100, 0, 2500);
   histo[15] = new TH1D("b~_H_PT", "PT of b~ from H", 100, 0, 2500);


   histo[16] = new TH1D("Nj", "NJets", 20, 0, 20);
   histo[17] = new TH1D("Nbj", "NbJets", 10, 0, 10);
   histo[18] = new TH1D("PT_Jets", "PT of Jets", 100, 0, 2000);
   histo[19] = new TH1D("PT_bJets", "PT of b Jets", 100, 0, 2000);
   histo[20] = new TH1D("Nleps", "NLeps", 10, 0, 10);
   histo[21] = new TH1D("PT_Leps", "PT of Leps", 100, 0, 1500);

   histo[22] = new TH1D("MET", "MET", 100, 0, 2000);
   histo[23] = new TH1D("HT", "HT", 100, 0, 5000);
   histo[56] = new TH1D("MT", "MT", 100, 0, 2000);

   histo[24] = new TH1D("dPhi_bbq_H", "dPhi bet bb quarks (from H)", 50, 0, 5);
   histo[25] = new TH1D("dPhi_bbq_t", "dPhi bet bb quarks (from t)", 50, 0, 5);
   histo[26] = new TH1D("dPhi_t1t1", "dPhi bet stops", 50, 0, 5);
   histo[27] = new TH1D("dPhi_tt", "dPhi bet tops", 50, 0, 5);
   histo[49] = new TH1D("dPhi_t_H", "dPhi bet t and H", 50, 0, 5);
   histo[50] = new TH1D("dPhi_t~_H", "dPhi bet t~ and H", 50, 0, 5);



   histo[28] = new TH1D("dPhi_leps_met", "dPhi bet leps and met", 50, 0, 5);
   histo[48] = new TH1D("dPhi_lep1_met", "dPhi bet leading lep and met", 50, 0, 5);
   histo[29] = new TH1D("dPhi_l_l+met", "dPhi bet lep and lep+met", 50, 0, 5);
   histo[30] = new TH1D("dPhi_N1_N2", "dPhi bet N1 and N2", 50, 0, 5);
   histo[31] = new TH1D("dPhi_N1~_N2", "dPhi bet N1~ and N2", 50, 0, 5);
   histo[51] = new TH1D("dPhi_N1_N1~", "dPhi bet N1 and N1~", 50, 0, 5);
   histo[32] = new TH1D("dPhi_bbjs", "dPhi bet b-jets", 50, 0, 5);
   histo[33] = new TH1D("dPhi_bbH_leps", "dPhi bet leps and bbjet systems in H window", 50, 0, 5);



   //1lep + Nj>3 + Nbj>2 evts + met>100 + mt>120
   histo[34] = new TH1D("MET_1", "MET for 1lep + Nj>3 + Nbj>2 ", 100, 0, 2000);
   histo[35] = new TH1D("HT_1", "HT for 1lep + Nj>3 + Nbj>2 ", 100, 0, 5000);
   histo[36] = new TH1D("Nj_1", "NJets for 1lep + Nj>3 + Nbj>2 ", 20, 0, 20);
   histo[37] = new TH1D("Nbj_1", "NbJets for 1lep + Nj>3 + Nbj>2 ", 10, 0, 10);
   histo[54] = new TH1D("MT_1", "MT for 1lep + Nj>3 + Nbj>2 ", 100, 0, 2000);

   histo[38] = new TH1D("dPhi_bbq_H_1", "dPhi bet bb quarks (from H) for 1lep + Nj>3 + Nbj>2", 50, 0, 5);
   histo[39] = new TH1D("dPhi_bbq_t_1", "dPhi bet bb quarks (from t) for 1lep + Nj>3 + Nbj>2", 50, 0, 5);
   histo[40] = new TH1D("dPhi_t1t1_1", "dPhi bet stops for 1lep + Nj>3 + Nbj>2", 50, 0, 5);
   histo[41] = new TH1D("dPhi_tt_1", "dPhi bet tops for 1lep + Nj>3 + Nbj>2", 50, 0, 5);
   histo[42] = new TH1D("dPhi_l_met_1", "dPhi bet lep and met for 1lep + Nj>3 + Nbj>2", 50, 0, 5);
   histo[43] = new TH1D("dPhi_l_l+met_1", "dPhi bet lep and lep+met for 1lep + Nj>3 + Nbj>2", 50, 0, 5);
   histo[53] = new TH1D("dPhi_l_l+met2D_1", "dPhi bet lep and lep+met(2D) for 1lep + Nj>3 + Nbj>2", 50, 0, 5);
   histo[44] = new TH1D("dPhi_N1_N2_1", "dPhi bet N1 and N2 for 1lep + Nj>3 + Nbj>2", 50, 0, 5);
   histo[45] = new TH1D("dPhi_N1~_N2_1", "dPhi bet N1~ and N2 for 1lep + Nj>3 + Nbj>2", 50, 0, 5);
   histo[46] = new TH1D("dPhi_bbjs_1", "dPhi bet b-jets for 1lep + Nj>3 + Nbj>2", 50, 0, 5);
   histo[55] = new TH1D("dPhi_bbjs_H_1", "dPhi bet b-jets in H window for 1lep + Nj>3 + Nbj>2", 50, 0, 5);

   histo[57] = new TH1D("PT_bbjH", "PT of bbjets in H window", 100, 0, 1500);
   histo[58] = new TH1D("InvM_bbjH", "Invariant Mass of bbjets in H window", 140, 90, 160);

   histo[47] = new TH1D("dPhi_bbH_l_1", "dPhi bet lep and bbjets in H window for 1lep + Nj>3 + Nbj>2", 50, 0, 5);
   histo[52] = new TH1D("dPhi_bbH_met_1", "dPhi bet met and bbjet systems in H window for 1lep + Nj>3 + Nbj>2", 50, 0, 5);
   histo[59] = new TH1D("dPhi_bbHmet_met_1", "dPhi bet met and bbjet+met system in H window for 1lep + Nj>3 + Nbj>2", 50, 0, 5);
   histo[60] = new TH1D("dPhi_bbHlep_lep_1", "dPhi bet lep and bbjet+lep systems in H window for 1lep + Nj>3 + Nbj>2", 50, 0, 5);

   //dPhi(l,W)>0.5
   histo[61] = new TH1D("MET_2", "MET after BS and dPhi(l,W)>0.5 ", 100, 0, 2000);
   histo[70] = new TH1D("MT_2", "MT after BS and dPhi(l,W)>0.5 ", 100, 0, 2000);
   histo[62] = new TH1D("Nj_2", "NJets after BS and dPhi(l,W)>0.5 ", 20, 0, 20);
   histo[63] = new TH1D("Nbj_2", "NbJets after BS and dPhi(l,W)>0.5 ", 10, 0, 10);
   histo[64] = new TH1D("dPhi_l_l+met2D_2", "dPhi bet lep and lep+met(2D) after BS and dPhi(l,W)>0.5", 50, 0, 5);

   histo[65] = new TH1D("Nfatj_1", "N Fat Jets for 1lep + Nj>3 + Nbj>2 ", 5, 0, 5);
   histo[66] = new TH1D("PT_fatj", "PT of Fat Jets for 1lep + Nj>3 + Nbj>2", 100, 0, 1500);
   histo[67] = new TH1D("M_fatj", "Mass of Fat Jets for 1lep + Nj>3 + Nbj>2", 100, 0, 1000);
   histo[68] = new TH1D("Tau21", "Tau[1]/Tau[0] for Fat Jets", 100, 0, 1);
   histo[69] = new TH1D("Tau32", "Tau[2]/Tau[1] for Fat Jets", 100, 0, 1);

   // + NFatJet>0 
   histo[76] = new TH1D("MET_4", "MET for 1lep + Nj>3 + Nbj>2 ", 100, 0, 2000);
   histo[77] = new TH1D("MT_4", "MT for 1lep + Nj>3 + Nbj>2 ", 100, 0, 2000);
   histo[78] = new TH1D("Nj_4", "NJets for 1lep + Nj>3 + Nbj>2 ", 20, 0, 20);
   histo[79] = new TH1D("Nbj_4", "NbJets for 1lep + Nj>3 + Nbj>2 ", 10, 0, 10);
   histo[80] = new TH1D("dPhi_l_l+met2D_4", "MT for 1lep + Nj>3 + Nbj>2 ", 50, 0, 5);

   //1lep + Nj>3 + Nbj>2 evts + met>120 + mt>150
   histo[71] = new TH1D("MET_3", "MET for 1lep + Nj>3 + Nbj>2 ", 100, 0, 2000);
   histo[72] = new TH1D("HT_3", "HT for 1lep + Nj>3 + Nbj>2 ", 100, 0, 5000);
   histo[73] = new TH1D("Nj_3", "NJets for 1lep + Nj>3 + Nbj>2 ", 20, 0, 20);
   histo[74] = new TH1D("Nbj_3", "NbJets for 1lep + Nj>3 + Nbj>2 ", 10, 0, 10);
   histo[75] = new TH1D("MT_3", "MT for 1lep + Nj>3 + Nbj>2 ", 100, 0, 2000);

   // + NFatJet>0 
   histo[81] = new TH1D("MET_5", "MET for 1lep + Nj>3 + Nbj>2 ", 100, 0, 2000);
   histo[82] = new TH1D("MT_5", "MT for 1lep + Nj>3 + Nbj>2 ", 100, 0, 2000);
   histo[83] = new TH1D("Nj_5", "NJets for 1lep + Nj>3 + Nbj>2 ", 20, 0, 20);
   histo[84] = new TH1D("Nbj_5", "NbJets for 1lep + Nj>3 + Nbj>2 ", 10, 0, 10);
   histo[85] = new TH1D("dPhi_l_l+met2D_5", "dPhi bet lep and lep+met(2D) for 1lep + Nj>3 + Nbj>2", 50, 0, 5);


   //Optimisation
   histo[86] = new TH1D("MET_NJ4_7_NbJ3_4", "MET with NJ:[4-7] and NbJ:[3-4]", 100, 0, 1500);
   histo[87] = new TH1D("MET_NJ4_7_NbJ5", "MET with NJ:[4-7] and NbJ:[>=5]", 100, 0, 1500);
   histo[88] = new TH1D("MET_NJ8_NbJ3_4", "MET with NJ:[>=8] and NbJ:[3-4]", 100, 0, 1500);
   histo[89] = new TH1D("MET_NJ8_NbJ5", "MET with NJ:[>=8] and NbJ:[>=5]", 100, 0, 1500);

   histo[94] = new TH1D("MET_fj_NJ4_7_NbJ3_4", "MET with NJ:[4-7] and NbJ:[3-4] after NFatJet>0", 100, 0, 1500);
   histo[95] = new TH1D("MET_fj_NJ4_7_NbJ5", "MET with NJ:[4-7] and NbJ:[>=5] after NFatJet>0", 100, 0, 1500);
   histo[96] = new TH1D("MET_fj_NJ8_NbJ3_4", "MET with NJ:[>=8] and NbJ:[3-4] after NFatJet>0", 100, 0, 1500);
   histo[97] = new TH1D("MET_fj_NJ8_NbJ5", "MET with NJ:[>=8] and NbJ:[>=5] after NFatJet>0", 100, 0, 1500);

   histo[90] = new TH1D("MT_NJ4_7_NbJ3_4", "MT with NJ:[4-7] and NbJ:[3-4]", 100, 0, 1500);
   histo[91] = new TH1D("MT_NJ4_7_NbJ5", "MT with NJ:[4-7] and NbJ:[>=5]", 100, 0, 1500);
   histo[92] = new TH1D("MT_NJ8_NbJ3_4", "MT with NJ:[>=8] and NbJ:[3-4]", 100, 0, 1500);
   histo[93] = new TH1D("MT_NJ8_NbJ5", "MT with NJ:[>=8] and NbJ:[>=5]", 100, 0, 1500);

   histo[98] = new TH1D("MT_fj_NJ4_7_NbJ3_4", "MT with NJ:[4-7] and NbJ:[3-4] after NFatJet>0", 100, 0, 1500);
   histo[99] = new TH1D("MT_fj_NJ4_7_NbJ5", "MT with NJ:[4-7] and NbJ:[>=5] after NFatJet>0", 100, 0, 1500);
   histo[100] = new TH1D("MT_fj_NJ8_NbJ3_4", "MT with NJ:[>=8] and NbJ:[3-4] after NFatJet>0", 100, 0, 1500);
   histo[101] = new TH1D("MT_fj_NJ8_NbJ5", "MT with NJ:[>=8] and NbJ:[>=5] after NFatJet>0", 100, 0, 1500);

//---------------------------------------------------------------
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      if(ientry%10000==0)cout<<"Processed "<<ientry<<" event..."<<endl;
//--------------------------------------------------------------

      bquarks_H.clear();
      bquarks_t.clear();
      stops.clear();      
      tops.clear();
      Higgs.clear();
      Neu2s.clear();
      Neu1s.clear();
      Neu1ss.clear();
      missinget.clear();
      

      reco_leps.clear();
      reco_jets.clear();
      reco_bjets.clear();
      reco_fatjets.clear();


//-------------------------------------------

//mycode

float weight = (0.0476*1.3*150*1000)/(50000);

//Particles

//cout<<"index "<<"  Status "<<"  PID "<<"  M1 "<<"  M2 "<<"  D1 "<<"  D2 "<<"  PT "<<endl;

//cout<<"event"<<endl;
int NPar=Particle_size;
for(int i=0; i<NPar; i++){

//cout<<i<<"   "<<Particle_Status[i]<<"   "<<Particle_PID[i]<<"   "<<Particle_M1[i]<<"   "<<Particle_M2[i]<<"   "<<Particle_D1[i]<<"   "<<Particle_D2[i]<<"   "<<Particle_PT[i]<<endl;

/*if(Particle_PID[i]==5 && Particle_PID[Particle_M1[i]]!=5){
cout<<"b M1= "<<Particle_PID[Particle_M1[i]]<<endl;
}

if(Particle_PID[i]==6 && Particle_PID[Particle_D2[i]]!=5 && Particle_PID[Particle_D2[i]]!=6){
cout<<"D2 of t when not b =  "<<Particle_PID[Particle_D2[i]]<<endl;
} */


  //stop
  if(Particle_PID[i]==1000006) {
    histo[0]->Fill(Particle_PT[i], weight);
    Part par; par.v.SetPtEtaPhiM(Particle_PT[i], Particle_Eta[i], Particle_Phi[i], Particle_Mass[i]);
    par.id=Particle_PID[i]; par.ind=i; par.Charge=Particle_Charge[i]; 
    stops.push_back(par);
  }
  if(Particle_PID[i]==-1000006) {
    histo[1]->Fill(Particle_PT[i], weight);
    Part par; par.v.SetPtEtaPhiM(Particle_PT[i], Particle_Eta[i], Particle_Phi[i], Particle_Mass[i]);
    par.id=Particle_PID[i]; par.ind=i; par.Charge=Particle_Charge[i]; 
    stops.push_back(par);
  }
  //top
  if(Particle_PID[i]==6 && Particle_PID[Particle_M1[i]]!=6) {
    histo[6]->Fill(Particle_PT[i], weight);
    Part par; par.v.SetPtEtaPhiM(Particle_PT[i], Particle_Eta[i], Particle_Phi[i], Particle_Mass[i]);
    par.id=Particle_PID[i]; par.ind=i; par.Charge=Particle_Charge[i]; 
    tops.push_back(par);
  }
  if(Particle_PID[i]==-6 && Particle_PID[Particle_M1[i]]!=-6) {
    histo[7]->Fill(Particle_PT[i], weight);
    Part par; par.v.SetPtEtaPhiM(Particle_PT[i], Particle_Eta[i], Particle_Phi[i], Particle_Mass[i]);
    par.id=Particle_PID[i]; par.ind=i; par.Charge=Particle_Charge[i]; 
    tops.push_back(par);
  }
  //Neu2
  if(Particle_PID[i]==1000023 && Particle_PID[Particle_M1[i]]==1000006) {
    histo[2]->Fill(Particle_PT[i], weight);
    Part par; par.v.SetPtEtaPhiM(Particle_PT[i], Particle_Eta[i], Particle_Phi[i], Particle_Mass[i]);
    par.id=Particle_PID[i]; par.ind=i; par.Charge=Particle_Charge[i]; 
    Neu2s.push_back(par);
  }
  
  //b from t
  if(Particle_PID[i]==5 && Particle_PID[Particle_M1[i]]==6) {
    histo[8]->Fill(Particle_PT[i], weight);
    Part par; par.v.SetPtEtaPhiM(Particle_PT[i], Particle_Eta[i], Particle_Phi[i], Particle_Mass[i]);
    par.id=Particle_PID[i]; par.ind=i; par.Charge=Particle_Charge[i]; par.M1=6;
    bquarks_t.push_back(par); 
  }
  if(Particle_PID[i]==-5 && Particle_PID[Particle_M1[i]]==-6 ) {
    histo[9]->Fill(Particle_PT[i], weight);
    Part par; par.v.SetPtEtaPhiM(Particle_PT[i], Particle_Eta[i], Particle_Phi[i], Particle_Mass[i]);
    par.id=Particle_PID[i]; par.ind=i; par.Charge=Particle_Charge[i]; par.M1=-6;
    bquarks_t.push_back(par); 
  }
  //b from H
  if(Particle_PID[i]==5 && Particle_PID[Particle_M1[i]]==25) {
    histo[14]->Fill(Particle_PT[i], weight);
    Part par; par.v.SetPtEtaPhiM(Particle_PT[i], Particle_Eta[i], Particle_Phi[i], Particle_Mass[i]);
    par.id=Particle_PID[i]; par.ind=i; par.Charge=Particle_Charge[i]; par.M1=25;
    bquarks_H.push_back(par); 
  }
  if(Particle_PID[i]==-5 && Particle_PID[Particle_M1[i]]==25) {
    histo[15]->Fill(Particle_PT[i], weight);
    Part par; par.v.SetPtEtaPhiM(Particle_PT[i], Particle_Eta[i], Particle_Phi[i], Particle_Mass[i]);
    par.id=Particle_PID[i]; par.ind=i; par.Charge=Particle_Charge[i]; par.M1=-25;
    bquarks_H.push_back(par); 
  }
  //W
  if(Particle_PID[i]==24 && Particle_PID[Particle_M1[i]]==6) {
    histo[10]->Fill(Particle_PT[i], weight);
  }
  if(Particle_PID[i]==-24 && Particle_PID[Particle_M1[i]]==-6) {
    histo[11]->Fill(Particle_PT[i], weight);
  }
  //H
  if(abs(Particle_PID[i])==25 && Particle_PID[Particle_M1[i]]!=25) {
    histo[12]->Fill(Particle_PT[i], weight);
    Part par; par.v.SetPtEtaPhiM(Particle_PT[i], Particle_Eta[i], Particle_Phi[i], Particle_Mass[i]);
    par.id=Particle_PID[i]; par.ind=i; par.Charge=Particle_Charge[i]; 
    Higgs.push_back(par);
  }
  //Z
  /*if(abs(Particle_PID[i])==23 ) {
    histo[13]->Fill(Particle_PT[i], weight);
  }*/
  //Neu1
  if(Particle_PID[i]==1000022 && Particle_PID[Particle_M1[i]]==1000023) {
    histo[4]->Fill(Particle_PT[i], weight);
    Part par; par.v.SetPtEtaPhiM(Particle_PT[i], Particle_Eta[i], Particle_Phi[i], Particle_Mass[i]);
    par.id=Particle_PID[i]; par.ind=i; par.Charge=Particle_Charge[i]; 
    Neu1s.push_back(par);
  }
  if(Particle_PID[i]==1000022 && Particle_PID[Particle_M1[i]]==-1000006) {
    histo[5]->Fill(Particle_PT[i], weight);
    Part par; par.v.SetPtEtaPhiM(Particle_PT[i], Particle_Eta[i], Particle_Phi[i], Particle_Mass[i]);
    par.id=Particle_PID[i]; par.ind=i; par.Charge=Particle_Charge[i]; 
    Neu1ss.push_back(par);
  }

}//par loop

  //MET HT
  histo[22]->Fill(MissingET_MET[0], weight);
  histo[23]->Fill(ScalarHT_HT[0], weight);
  Part met; met.v.SetPtEtaPhiM(MissingET_MET[0], MissingET_Eta[0], MissingET_Phi[0], 0);
  missinget.push_back(met);
  //2D met
  float Met_0 = (MissingET_MET[0])*(TMath::Cos(MissingET_Phi[0]));
  float Met_1 = (MissingET_MET[0])*(TMath::Sin(MissingET_Phi[0]));

  //Leptons
  int Nl = Electron_size + Muon_size; int Nleps=0;
  if(Nl>0){
    for(int a=0; a<Electron_size; a++){
      if(Electron_PT[a]>=10 && fabs(Electron_Eta[a])<=2.5){
        Part elec; elec.v.SetPtEtaPhiM(Electron_PT[a], Electron_Eta[a], Electron_Phi[a], 0.000511);
        reco_leps.push_back(elec);
        histo[21]->Fill(elec.v.Pt(), weight);
        Nleps=Nleps+1;
      }
    }
    for(int b=0; b<Muon_size; b++){
      if(Muon_PT[b]>=10 && fabs(Muon_Eta[b])<=2.4){
        Part muon; muon.v.SetPtEtaPhiM(Muon_PT[b], Muon_Eta[b], Muon_Phi[b], 0.105658);
        reco_leps.push_back(muon);
        histo[21]->Fill(Muon_PT[b], weight);
        Nleps=Nleps+1;
      }
    }
    histo[20]->Fill(reco_leps.size(), weight);
  }

  //mt
  float mt_;
  for(int k=0; k<reco_leps.size(); k++){
    float dp_lmet = fabs(MissingET_Phi[0] - reco_leps.at(k).v.Phi());
    if(dp_lmet>TMath::Pi()) {dp_lmet = 2*TMath::Pi() - dp_lmet;}
    float mt_ = sqrt(2*reco_leps.at(k).v.Pt()*MissingET_MET[0]*(1-TMath::Cos(dp_lmet)));
    histo[56]->Fill(mt_, weight);
  }
  //Jets
  int Njets = Jet_size; int Nbjets=0;
  for(int i=0; i<Njets; i++){
    Part jet; jet.v.SetPtEtaPhiM(Jet_PT[i], Jet_Eta[i], Jet_Phi[i], Jet_Mass[i]);
    if(jet.v.Pt()>=20 && fabs(jet.v.Eta())<2.4){
      /*for(int m=0; m<reco_leps.size(); m++){
        float dP_jetlep = fabs(jet.v.Phi() - reco_leps.at(m).v.Phi());
        if(dP_jetlep>TMath::Pi()) {dP_jetlep = 2*TMath::Pi() - dP_jetlep;}
        float dE_jetlep = fabs(jet.v.Eta() - reco_leps.at(m).v.Eta());
        float dR_jetlep = sqrt(pow(dP_jetlep,2) + pow(dE_jetlep,2));
        if(dR_jetlep>=0.5){*/

          reco_jets.push_back(jet);
          histo[18]->Fill(jet.v.Pt(), weight);
          if(Jet_BTag[i]==1){
            Nbjets=Nbjets+1;
            Part jet1; jet1.v.SetPtEtaPhiM(Jet_PT[i], Jet_Eta[i], Jet_Phi[i], Jet_Mass[i]);
            if(jet1.v.Pt()>=20 && fabs(jet1.v.Eta())<2.4){
              reco_bjets.push_back(jet1);
              histo[19]->Fill(jet1.v.Pt(), weight);
            }
          }
        //}
      //}
    }
  }
  histo[17]->Fill(reco_bjets.size(), weight);
  histo[16]->Fill(reco_jets.size(), weight);

  //dPhi bet bb quarks from t
  if(bquarks_t.size()==2){
    float dPhi_bb_t = fabs(bquarks_t.at(0).v.Phi() - bquarks_t.at(1).v.Phi());
    if(dPhi_bb_t>TMath::Pi()) {dPhi_bb_t = 2*TMath::Pi() - dPhi_bb_t;}
    histo[25]->Fill(dPhi_bb_t, weight);
  }
  //dPhi bet bb quarks from H
  if(bquarks_H.size()==2){
    float dPhi_bb_H = fabs(bquarks_H.at(0).v.Phi() - bquarks_H.at(1).v.Phi());
    if(dPhi_bb_H>TMath::Pi()) {dPhi_bb_H = 2*TMath::Pi() - dPhi_bb_H;}
    histo[24]->Fill(dPhi_bb_H, weight);
  }
  //dPhi bet stops
  if(stops.size()==2){
    float dPhi_t1t1 = fabs(stops.at(0).v.Phi() - stops.at(1).v.Phi());
    if(dPhi_t1t1>TMath::Pi()) {dPhi_t1t1 = 2*TMath::Pi() - dPhi_t1t1;}
    histo[26]->Fill(dPhi_t1t1, weight);
  }
  //dPhi bet tops
  if(tops.size()==2){
    float dPhi_tt = fabs(tops.at(0).v.Phi() - tops.at(1).v.Phi());
    if(dPhi_tt>TMath::Pi()) {dPhi_tt = 2*TMath::Pi() - dPhi_tt;}
    histo[27]->Fill(dPhi_tt, weight);
  }
  //dPhi bet t and H
  if(tops.size()==2 && Higgs.size()==1){
    float dPhi_tH = fabs(tops.at(0).v.Phi() - Higgs.at(0).v.Phi());
    if(dPhi_tH>TMath::Pi()) {dPhi_tH = 2*TMath::Pi() - dPhi_tH;}
    histo[49]->Fill(dPhi_tH, weight);
  }
  //dPhi bet t~ and H
  if(tops.size()==2 && Higgs.size()==1){
    float dPhi_tH1 = fabs(tops.at(1).v.Phi() - Higgs.at(0).v.Phi());
    if(dPhi_tH1>TMath::Pi()) {dPhi_tH1 = 2*TMath::Pi() - dPhi_tH1;}
    histo[50]->Fill(dPhi_tH1, weight);
  }
  //dPhi bet N1 N2
  if(Neu2s.size()==1 && Neu1s.size()==1 && Neu1ss.size()==1){
    float dPhi_n1n2 = fabs(Neu2s.at(0).v.Phi() - Neu1s.at(0).v.Phi());
    if(dPhi_n1n2>TMath::Pi()) {dPhi_n1n2 = 2*TMath::Pi() - dPhi_n1n2;}
    histo[30]->Fill(dPhi_n1n2, weight);
    float dPhi_n1n2_ = fabs(Neu2s.at(0).v.Phi() - Neu1ss.at(0).v.Phi());
    if(dPhi_n1n2_>TMath::Pi()) {dPhi_n1n2_ = 2*TMath::Pi() - dPhi_n1n2_;}
    histo[31]->Fill(dPhi_n1n2_, weight);
    float dPhi_n1n1 = fabs(Neu1s.at(0).v.Phi() - Neu1ss.at(0).v.Phi());
    if(dPhi_n1n1>TMath::Pi()) {dPhi_n1n1 = 2*TMath::Pi() - dPhi_n1n1;}
    histo[51]->Fill(dPhi_n1n1, weight);
  }

  //dPhi bet lep and met
  if(reco_leps.size()>0){
    for(int j=0; j<reco_leps.size(); j++){
      float dPhi_l_met = fabs(MissingET_Phi[0] - reco_leps.at(j).v.Phi());
      if(dPhi_l_met>TMath::Pi()) {dPhi_l_met = 2*TMath::Pi() - dPhi_l_met;}
      histo[28]->Fill(dPhi_l_met, weight);
    }
  }
  //dPhi bet lep1 and met
  if(reco_leps.size()==1){
    float dPhi_l1_met = fabs(MissingET_Phi[0] - reco_leps.at(0).v.Phi());
    if(dPhi_l1_met>TMath::Pi()) {dPhi_l1_met = 2*TMath::Pi() - dPhi_l1_met;}
    histo[48]->Fill(dPhi_l1_met, weight);
  }
  //dPhi bet lep and lep+met
  if(reco_leps.size()>0){
    for(int n=0; n<reco_leps.size(); n++){
      float Phi_lmet = (reco_leps.at(n).v + missinget.at(0).v).Phi();
      float dPhi_l_lmet = fabs(Phi_lmet - reco_leps.at(n).v.Phi());
      histo[29]->Fill(dPhi_l_lmet, weight);
    }
  }

  //dPhi bet b-jets
  if(reco_bjets.size()>1){
    for(int k=0; k<reco_bjets.size(); k++){
      for(int l=k+1; l<reco_bjets.size(); l++){
        float dPhi_bbj = fabs(reco_bjets.at(k).v.Phi() - reco_bjets.at(l).v.Phi());
        if(dPhi_bbj>TMath::Pi()) {dPhi_bbj = 2*TMath::Pi() - dPhi_bbj;}
        histo[32]->Fill(dPhi_bbj, weight);
        //dPhi bet b-jets in H window and lep 
        float invM_bbj = (reco_bjets.at(k).v + reco_bjets.at(l).v).M();
        if(reco_leps.size()>0 && invM_bbj<150 && invM_bbj>100){
          float Phi_bbH = (reco_bjets.at(k).v + reco_bjets.at(l).v).Phi();
          for(int m=0; m<reco_leps.size(); m++){
            float dPhi_bbH_l = fabs(Phi_bbH - reco_leps.at(m).v.Phi());
            if(dPhi_bbH_l>TMath::Pi()) {dPhi_bbH_l = 2*TMath::Pi() - dPhi_bbH_l;}
            histo[33]->Fill(dPhi_bbH_l, weight);
          }
        }
      }
    }
  }


  //Event Selection: 1lep + Nj>3 + Nbj>2 + met>100 + mt>120
  if(reco_leps.size()==1 && reco_jets.size()>3 && reco_bjets.size()>2 && MissingET_MET[0]>100){

    //mt
    float dP_lmet = fabs(MissingET_Phi[0] - reco_leps.at(0).v.Phi());
    if(dP_lmet>TMath::Pi()) {dP_lmet = 2*TMath::Pi() - dP_lmet;}
    float mt = sqrt(2*reco_leps.at(0).v.Pt()*MissingET_MET[0]*(1-TMath::Cos(dP_lmet)));

    if(MissingET_MET[0]>120 && mt>150){
      histo[71]->Fill(MissingET_MET[0], weight);
      histo[72]->Fill(ScalarHT_HT[0], weight);
      histo[73]->Fill(reco_jets.size(), weight);
      histo[74]->Fill(reco_bjets.size(), weight);
      histo[75]->Fill(mt, weight);

      //optimisation
      //MET
      if(reco_jets.size()>3 && reco_jets.size()<8){
        if(reco_bjets.size()>2 && reco_bjets.size()<5){
          histo[86]->Fill(MissingET_MET[0], weight);
        }
        if(reco_bjets.size()>4){
          histo[87]->Fill(MissingET_MET[0], weight);
        }
      }
      if(reco_jets.size()>7){
        if(reco_bjets.size()>2 && reco_bjets.size()<5){
          histo[88]->Fill(MissingET_MET[0], weight);
        }
        if(reco_bjets.size()>4){
          histo[89]->Fill(MissingET_MET[0], weight);
        }
      }
      //MT
      if(reco_jets.size()>3 && reco_jets.size()<8){
        if(reco_bjets.size()>2 && reco_bjets.size()<5){
          histo[90]->Fill(mt, weight);
        }
        if(reco_bjets.size()>4){
          histo[91]->Fill(mt, weight);
        }
      }
      if(reco_jets.size()>7){
        if(reco_bjets.size()>2 && reco_bjets.size()<5){
          histo[92]->Fill(mt, weight);
        }
        if(reco_bjets.size()>4){
          histo[93]->Fill(mt, weight);
        }
      }
    }//mt150 met120

    if(mt>120){
    histo[34]->Fill(MissingET_MET[0], weight);
    histo[35]->Fill(ScalarHT_HT[0], weight);
    histo[36]->Fill(reco_jets.size(), weight);
    histo[37]->Fill(reco_bjets.size(), weight);
    histo[54]->Fill(mt, weight);

    //dPhi bet bb quarks from t
    if(bquarks_t.size()==2){
      float dPhi_bb_t = fabs(bquarks_t.at(0).v.Phi() - bquarks_t.at(1).v.Phi());
      if(dPhi_bb_t>TMath::Pi()) {dPhi_bb_t = 2*TMath::Pi() - dPhi_bb_t;}
      histo[39]->Fill(dPhi_bb_t, weight);
    }
    //dPhi bet bb quarks from H
    if(bquarks_H.size()==2){
      float dPhi_bb_H = fabs(bquarks_H.at(0).v.Phi() - bquarks_H.at(1).v.Phi());
      if(dPhi_bb_H>TMath::Pi()) {dPhi_bb_H = 2*TMath::Pi() - dPhi_bb_H;}
      histo[38]->Fill(dPhi_bb_H, weight);
    }
    //dPhi bet stops
    if(stops.size()==2){
      float dPhi_t1t1 = fabs(stops.at(0).v.Phi() - stops.at(1).v.Phi());
      if(dPhi_t1t1>TMath::Pi()) {dPhi_t1t1 = 2*TMath::Pi() - dPhi_t1t1;}
      histo[40]->Fill(dPhi_t1t1, weight);
    }
    //dPhi bet tops
    if(tops.size()==2){
      float dPhi_tt = fabs(tops.at(0).v.Phi() - tops.at(1).v.Phi());
      if(dPhi_tt>TMath::Pi()) {dPhi_tt = 2*TMath::Pi() - dPhi_tt;}
      histo[41]->Fill(dPhi_tt, weight);
    }
    //dPhi bet N1 N2
    if(Neu2s.size()==1 && Neu1s.size()==1 && Neu1ss.size()==1){
      float dPhi_n1n2 = fabs(Neu2s.at(0).v.Phi() - Neu1s.at(0).v.Phi());
      if(dPhi_n1n2>TMath::Pi()) {dPhi_n1n2 = 2*TMath::Pi() - dPhi_n1n2;}
      histo[44]->Fill(dPhi_n1n2, weight);
      float dPhi_n1n2_ = fabs(Neu2s.at(0).v.Phi() - Neu1ss.at(0).v.Phi());
      if(dPhi_n1n2_>TMath::Pi()) {dPhi_n1n2_ = 2*TMath::Pi() - dPhi_n1n2_;}
      histo[45]->Fill(dPhi_n1n2_, weight);
    }

    //dPhi bet lep1 and met
    float dPhi_l1_met = fabs(MissingET_Phi[0] - reco_leps.at(0).v.Phi());
    if(dPhi_l1_met>TMath::Pi()) {dPhi_l1_met = 2*TMath::Pi() - dPhi_l1_met;}
    histo[42]->Fill(dPhi_l1_met, weight);
  
    //dPhi bet lep and lep+met
    float Phi_lmet = (reco_leps.at(0).v + missinget.at(0).v).Phi();
    float dPhi_l_lmet = fabs(Phi_lmet - reco_leps.at(0).v.Phi());
    if(dPhi_l_lmet>TMath::Pi()) {dPhi_l_lmet = 2*TMath::Pi() - dPhi_l_lmet;}
    histo[43]->Fill(dPhi_l_lmet, weight);
    //*****
    float Lept_0 = (reco_leps.at(0).v.Pt())*(TMath::Cos(reco_leps.at(0).v.Phi()));
    float Lept_1 = (reco_leps.at(0).v.Pt())*(TMath::Sin(reco_leps.at(0).v.Phi()));
    float Met_x = MissingET_MET[0]*TMath::Cos(MissingET_Phi[0]);
    float Met_y = MissingET_MET[0]*TMath::Sin(MissingET_Phi[0]);
    float Met_Lept_0 = Met_x + Lept_0;
    float Met_Lept_1 = Met_y + Lept_1;
    float y_x = fabs(Met_Lept_1)/fabs(Met_Lept_0);
    float Phi_g = TMath::ATan(y_x);
    float Phi_nn;
    if(Met_Lept_0>=0 && Met_Lept_1>=0){Phi_nn = Phi_g;}
    if(Met_Lept_0<0 && Met_Lept_1<0){Phi_nn = TMath::Pi() + Phi_g;}
    if(Met_Lept_0>0 && Met_Lept_1<0){Phi_nn = 2*TMath::Pi() - Phi_g;}
    if(Met_Lept_0<0 && Met_Lept_1>0){Phi_nn = TMath::Pi() - Phi_g;}

    float dPhi_l_lmet2D = fabs(reco_leps.at(0).v.Phi() - Phi_nn);
    if(dPhi_l_lmet2D>TMath::Pi()) {dPhi_l_lmet2D = 2*TMath::Pi() - dPhi_l_lmet2D;}
    histo[53]->Fill(dPhi_l_lmet2D, weight);
    //if dPhi(l,W)>0.5 select evt
    if(dPhi_l_lmet2D>=0.5){
      histo[61]->Fill(MissingET_MET[0], weight);
      histo[70]->Fill(mt, weight);
      histo[62]->Fill(reco_jets.size(), weight);
      histo[63]->Fill(reco_bjets.size(), weight);
      histo[64]->Fill(dPhi_l_lmet2D, weight);
    }

    //dPhi bet b-jets
    if(reco_bjets.size()>1){
      for(int k=0; k<reco_bjets.size(); k++){
        for(int l=k+1; l<reco_bjets.size(); l++){
          float dPhi_bbj = fabs(reco_bjets.at(k).v.Phi() - reco_bjets.at(l).v.Phi());
          if(dPhi_bbj>TMath::Pi()) {dPhi_bbj = 2*TMath::Pi() - dPhi_bbj;}
          histo[46]->Fill(dPhi_bbj, weight);
          //dPhi bet b-jets in H window and lep 
          float invM_bbj = (reco_bjets.at(k).v + reco_bjets.at(l).v).M();
          if(invM_bbj<150 && invM_bbj>100){
            histo[55]->Fill(dPhi_bbj, weight);
            float PT_bbH = (reco_bjets.at(k).v + reco_bjets.at(l).v).Pt();
            histo[57]->Fill(PT_bbH, weight);
            histo[58]->Fill(invM_bbj, weight);
            float Phi_bbH = (reco_bjets.at(k).v + reco_bjets.at(l).v).Phi();
            float dPhi_bbH_l = fabs(Phi_bbH - reco_leps.at(0).v.Phi());
            if(dPhi_bbH_l>TMath::Pi()) {dPhi_bbH_l = 2*TMath::Pi() - dPhi_bbH_l;}
            histo[47]->Fill(dPhi_bbH_l, weight);

            //dPhi bet b-jets in H window and met
            float dPhi_bbH_met = fabs(Phi_bbH - MissingET_Phi[0]);
            if(dPhi_bbH_met>TMath::Pi()) {dPhi_bbH_met = 2*TMath::Pi() - dPhi_bbH_met;}
            histo[52]->Fill(dPhi_bbH_met, weight);


            //bbH + met
            float bbH_Px = ((reco_bjets.at(k).v + reco_bjets.at(l).v).Pt())*(TMath::Cos((reco_bjets.at(k).v + reco_bjets.at(l).v).Phi()));
            float bbH_Py = ((reco_bjets.at(k).v + reco_bjets.at(l).v).Pt())*(TMath::Sin((reco_bjets.at(k).v + reco_bjets.at(l).v).Phi()));
            float met_bbH_Px = bbH_Px + Met_0;
            float met_bbH_Py = bbH_Py + Met_1;
            float y_x_ = fabs(met_bbH_Py)/fabs(met_bbH_Px);
            float Phi_4 = TMath::ATan(y_x_);
            float Phi_44;
            if(met_bbH_Px>=0 && met_bbH_Py>=0){Phi_44 = Phi_4;}
            if(met_bbH_Px<0 && met_bbH_Py<0){Phi_44 = TMath::Pi() + Phi_4;}
            if(met_bbH_Px>0 && met_bbH_Py<0){Phi_44 = 2*TMath::Pi() - Phi_4;}
            if(met_bbH_Px<0 && met_bbH_Py>0){Phi_44 = TMath::Pi() - Phi_4;}
            float dPhi_bbHmet_met = fabs(MissingET_Phi[0] - Phi_44);
            if(dPhi_bbHmet_met>TMath::Pi()) {dPhi_bbHmet_met = 2*TMath::Pi() - dPhi_bbHmet_met;}
            histo[59]->Fill(dPhi_bbHmet_met, weight);

            //bbH + lep
            float Lept_0 = (reco_leps.at(0).v.Pt())*(TMath::Cos(reco_leps.at(0).v.Phi()));
            float Lept_1 = (reco_leps.at(0).v.Pt())*(TMath::Sin(reco_leps.at(0).v.Phi()));
            float lep_bbH_Px = bbH_Px + Lept_0;
            float lep_bbH_Py = bbH_Py + Lept_1;
            float y_x_1 = fabs(lep_bbH_Py)/fabs(lep_bbH_Px);
            float Phi_7 = TMath::ATan(y_x_1);
            float Phi_77;
            if(lep_bbH_Px>=0 && lep_bbH_Py>=0){Phi_77 = Phi_7;}
            if(lep_bbH_Px<0 && lep_bbH_Py<0){Phi_77 = TMath::Pi() + Phi_7;}
            if(lep_bbH_Px>0 && lep_bbH_Py<0){Phi_77 = 2*TMath::Pi() - Phi_7;}
            if(lep_bbH_Px<0 && lep_bbH_Py>0){Phi_77 = TMath::Pi() - Phi_7;}
            float dPhi_bbHlep_lep = fabs(MissingET_Phi[0] - Phi_77);
            if(dPhi_bbHlep_lep>TMath::Pi()) {dPhi_bbHlep_lep = 2*TMath::Pi() - dPhi_bbHlep_lep;}
            histo[60]->Fill(dPhi_bbHlep_lep, weight);

          }
        }
      }
    }

    //Fat jets (AK8) and pT>300
    for(int q=0; q<FatJet_size; q++){
      if(FatJet_PT[q]>300 && fabs(FatJet_Eta[q])<2.4 && FatJet_Mass[q]<150 && FatJet_Mass[q]>100){
        Part jet2; jet2.v.SetPtEtaPhiM(FatJet_PT[q], FatJet_Eta[q], FatJet_Phi[q], FatJet_Mass[q]);
        reco_fatjets.push_back(jet2);
        histo[66]->Fill(FatJet_PT[q] ,weight);
        histo[67]->Fill(FatJet_Mass[q] ,weight);

        float tau21 = FatJet_Tau[q][1]/FatJet_Tau[q][0];
        float tau32 = FatJet_Tau[q][2]/FatJet_Tau[q][1];
        histo[68]->Fill(tau21 ,weight);
        histo[69]->Fill(tau32 ,weight);

      }
    }
    histo[65]->Fill(reco_fatjets.size() ,weight);
    if(reco_fatjets.size()>0){      
      histo[76]->Fill(MissingET_MET[0], weight);
      histo[77]->Fill(mt, weight);
      histo[78]->Fill(reco_jets.size(), weight);
      histo[79]->Fill(reco_bjets.size(), weight);
      histo[80]->Fill(dPhi_l_lmet2D, weight);

      if(MissingET_MET[0]>120 && mt>150){
        histo[81]->Fill(MissingET_MET[0], weight);
        histo[82]->Fill(mt, weight);
        histo[83]->Fill(reco_jets.size(), weight);
        histo[84]->Fill(reco_bjets.size(), weight);
        histo[85]->Fill(dPhi_l_lmet2D, weight);

        //optimisation
        //MET
        if(reco_jets.size()>3 && reco_jets.size()<8){
          if(reco_bjets.size()>2 && reco_bjets.size()<5){
            histo[94]->Fill(MissingET_MET[0], weight);
          }
          if(reco_bjets.size()>4){
            histo[95]->Fill(MissingET_MET[0], weight);
          }
        }
        if(reco_jets.size()>7){
          if(reco_bjets.size()>2 && reco_bjets.size()<5){
            histo[96]->Fill(MissingET_MET[0], weight);
          }
          if(reco_bjets.size()>4){
            histo[97]->Fill(MissingET_MET[0], weight);
          }
        }
        //MT
        if(reco_jets.size()>3 && reco_jets.size()<8){
          if(reco_bjets.size()>2 && reco_bjets.size()<5){
            histo[98]->Fill(mt, weight);
          }
          if(reco_bjets.size()>4){
            histo[99]->Fill(mt, weight);
          }
        }
        if(reco_jets.size()>7){
          if(reco_bjets.size()>2 && reco_bjets.size()<5){
            histo[100]->Fill(mt, weight);
          }
          if(reco_bjets.size()>4){
            histo[101]->Fill(mt, weight);
          }
        }

      }//met120 mt150

    }

    }//mt cut


  }//event selection




   }//event loop
   this->Output();
}//void loop
//-------------------------------------------
Int_t stopstop_topN2_topN1_600300::Output()
{
  TFile *rootfile = new TFile("Hst_stopstop_topN2_topN1_600300.root", "RECREATE");

  histo[0]->Write();
  histo[1]->Write();
  histo[2]->Write();
  //histo[3]->Write();
  histo[4]->Write();
  histo[5]->Write();
  histo[6]->Write();
  histo[7]->Write();
  histo[8]->Write();
  histo[9]->Write();
  histo[10]->Write();
  histo[11]->Write();
  histo[12]->Write();
  //histo[13]->Write();
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
  histo[56]->Write();
  histo[24]->Write();
  histo[25]->Write();
  histo[26]->Write();
  histo[27]->Write();
  histo[49]->Write();
  histo[50]->Write();
  histo[28]->Write();
  histo[48]->Write();
  histo[29]->Write();
  histo[30]->Write();
  histo[31]->Write();
  histo[51]->Write();
  histo[32]->Write();
  histo[33]->Write();
  histo[34]->Write();
  histo[35]->Write();
  histo[36]->Write();
  histo[37]->Write();
  histo[54]->Write();
  histo[38]->Write();
  histo[39]->Write();
  histo[40]->Write();
  histo[41]->Write();
  histo[42]->Write();
  histo[43]->Write();
  histo[53]->Write();
  histo[44]->Write();
  histo[45]->Write();
  histo[46]->Write();
  histo[55]->Write();
  histo[57]->Write();
  histo[58]->Write();
  histo[47]->Write();
  histo[52]->Write();
  histo[59]->Write();
  histo[60]->Write();
  histo[61]->Write();
  histo[70]->Write();
  histo[62]->Write();
  histo[63]->Write();
  histo[64]->Write();
  histo[65]->Write();
  histo[66]->Write();
  histo[67]->Write();
  histo[68]->Write();
  histo[69]->Write();
  histo[71]->Write();
  histo[72]->Write();
  histo[73]->Write();
  histo[74]->Write();
  histo[75]->Write();
  histo[76]->Write();
  histo[77]->Write();
  histo[78]->Write();
  histo[79]->Write();
  histo[80]->Write();
  histo[81]->Write();
  histo[82]->Write();
  histo[83]->Write();
  histo[84]->Write();
  histo[85]->Write();
  histo[86]->Write();
  histo[87]->Write();
  histo[88]->Write();
  histo[89]->Write();
  histo[90]->Write();
  histo[91]->Write();
  histo[92]->Write();
  histo[93]->Write();
  histo[94]->Write();
  histo[95]->Write();
  histo[96]->Write();
  histo[97]->Write();
  histo[98]->Write();
  histo[99]->Write();
  histo[100]->Write();
  histo[101]->Write();


  rootfile->Write();
  rootfile->Close();

  return 0;
}

//---------------------------------------------------
