#define ttbarH_50kevt_1_5_cxx
#include "ttbarH_50kevt_1_5.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

//*******
#include <TH1.h>
#include <TMath.h>
#include <TLorentzVector.h>
#include <iostream>

void ttbarH_50kevt_1_5::Loop()
{
//   In a ROOT session, you can do:
//      root> .L ttbarH_50kevt_1_5.C
//      root> ttbarH_50kevt_1_5 t
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



   //1lep + Nj>3 + Nbj>2 evts
   histo[34] = new TH1D("MET_1", "MET for 1lep + Nj>3 + Nbj>2 ", 100, 0, 2000);
   histo[35] = new TH1D("HT_1", "HT for 1lep + Nj>3 + Nbj>2 ", 100, 0, 5000);
   histo[36] = new TH1D("Nj_1", "NJets for 1lep + Nj>3 + Nbj>2 ", 20, 0, 20);
   histo[37] = new TH1D("Nbj_1", "NbJets for 1lep + Nj>3 + Nbj>2 ", 10, 0, 10);

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
   histo[47] = new TH1D("dPhi_bbH_l_1", "dPhi bet lep and bbjets in H window for 1lep + Nj>3 + Nbj>2", 50, 0, 5);
   histo[52] = new TH1D("dPhi_bbH_met_1", "dPhi bet met and bbjet systems in H window for 1lep + Nj>3 + Nbj>2", 50, 0, 5);





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


//-------------------------------------------

//mycode


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
    histo[0]->Fill(Particle_PT[i]);
    Part par; par.v.SetPtEtaPhiM(Particle_PT[i], Particle_Eta[i], Particle_Phi[i], Particle_Mass[i]);
    par.id=Particle_PID[i]; par.ind=i; par.Charge=Particle_Charge[i]; 
    stops.push_back(par);
  }
  if(Particle_PID[i]==-1000006) {
    histo[1]->Fill(Particle_PT[i]);
    Part par; par.v.SetPtEtaPhiM(Particle_PT[i], Particle_Eta[i], Particle_Phi[i], Particle_Mass[i]);
    par.id=Particle_PID[i]; par.ind=i; par.Charge=Particle_Charge[i]; 
    stops.push_back(par);
  }
  //top
  if(Particle_PID[i]==6 && Particle_PID[Particle_M1[i]]!=6) {
    histo[6]->Fill(Particle_PT[i]);
    Part par; par.v.SetPtEtaPhiM(Particle_PT[i], Particle_Eta[i], Particle_Phi[i], Particle_Mass[i]);
    par.id=Particle_PID[i]; par.ind=i; par.Charge=Particle_Charge[i]; 
    tops.push_back(par);
  }
  if(Particle_PID[i]==-6 && Particle_PID[Particle_M1[i]]!=-6) {
    histo[7]->Fill(Particle_PT[i]);
    Part par; par.v.SetPtEtaPhiM(Particle_PT[i], Particle_Eta[i], Particle_Phi[i], Particle_Mass[i]);
    par.id=Particle_PID[i]; par.ind=i; par.Charge=Particle_Charge[i]; 
    tops.push_back(par);
  }
  //Neu2
  if(Particle_PID[i]==1000023 && Particle_PID[Particle_M1[i]]==1000006) {
    histo[2]->Fill(Particle_PT[i]);
    Part par; par.v.SetPtEtaPhiM(Particle_PT[i], Particle_Eta[i], Particle_Phi[i], Particle_Mass[i]);
    par.id=Particle_PID[i]; par.ind=i; par.Charge=Particle_Charge[i]; 
    Neu2s.push_back(par);
  }
  
  //b from t
  if(Particle_PID[i]==5 && Particle_PID[Particle_M1[i]]==6) {
    histo[8]->Fill(Particle_PT[i]);
    Part par; par.v.SetPtEtaPhiM(Particle_PT[i], Particle_Eta[i], Particle_Phi[i], Particle_Mass[i]);
    par.id=Particle_PID[i]; par.ind=i; par.Charge=Particle_Charge[i]; par.M1=6;
    bquarks_t.push_back(par); 
  }
  if(Particle_PID[i]==-5 && Particle_PID[Particle_M1[i]]==-6 ) {
    histo[9]->Fill(Particle_PT[i]);
    Part par; par.v.SetPtEtaPhiM(Particle_PT[i], Particle_Eta[i], Particle_Phi[i], Particle_Mass[i]);
    par.id=Particle_PID[i]; par.ind=i; par.Charge=Particle_Charge[i]; par.M1=-6;
    bquarks_t.push_back(par); 
  }
  //b from H
  if(Particle_PID[i]==5 && Particle_PID[Particle_M1[i]]==25) {
    histo[14]->Fill(Particle_PT[i]);
    Part par; par.v.SetPtEtaPhiM(Particle_PT[i], Particle_Eta[i], Particle_Phi[i], Particle_Mass[i]);
    par.id=Particle_PID[i]; par.ind=i; par.Charge=Particle_Charge[i]; par.M1=25;
    bquarks_H.push_back(par); 
  }
  if(Particle_PID[i]==-5 && Particle_PID[Particle_M1[i]]==25) {
    histo[15]->Fill(Particle_PT[i]);
    Part par; par.v.SetPtEtaPhiM(Particle_PT[i], Particle_Eta[i], Particle_Phi[i], Particle_Mass[i]);
    par.id=Particle_PID[i]; par.ind=i; par.Charge=Particle_Charge[i]; par.M1=-25;
    bquarks_H.push_back(par); 
  }
  //W
  if(Particle_PID[i]==24 && Particle_PID[Particle_M1[i]]==6) {
    histo[10]->Fill(Particle_PT[i]);
  }
  if(Particle_PID[i]==-24 && Particle_PID[Particle_M1[i]]==-6) {
    histo[11]->Fill(Particle_PT[i]);
  }
  //H
  if(abs(Particle_PID[i])==25 && Particle_PID[Particle_M1[i]]!=25) {
    histo[12]->Fill(Particle_PT[i]);
    Part par; par.v.SetPtEtaPhiM(Particle_PT[i], Particle_Eta[i], Particle_Phi[i], Particle_Mass[i]);
    par.id=Particle_PID[i]; par.ind=i; par.Charge=Particle_Charge[i]; 
    Higgs.push_back(par);
  }
  //Z
  /*if(abs(Particle_PID[i])==23 ) {
    histo[13]->Fill(Particle_PT[i]);
  }*/
  //Neu1
  if(Particle_PID[i]==1000022 && Particle_PID[Particle_M1[i]]==1000023) {
    histo[4]->Fill(Particle_PT[i]);
    Part par; par.v.SetPtEtaPhiM(Particle_PT[i], Particle_Eta[i], Particle_Phi[i], Particle_Mass[i]);
    par.id=Particle_PID[i]; par.ind=i; par.Charge=Particle_Charge[i]; 
    Neu1s.push_back(par);
  }
  if(Particle_PID[i]==1000022 && Particle_PID[Particle_M1[i]]==-1000006) {
    histo[5]->Fill(Particle_PT[i]);
    Part par; par.v.SetPtEtaPhiM(Particle_PT[i], Particle_Eta[i], Particle_Phi[i], Particle_Mass[i]);
    par.id=Particle_PID[i]; par.ind=i; par.Charge=Particle_Charge[i]; 
    Neu1ss.push_back(par);
  }

}//par loop

  //MET HT
  histo[22]->Fill(MissingET_MET[0]);
  histo[23]->Fill(ScalarHT_HT[0]);
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
        histo[21]->Fill(elec.v.Pt());
        Nleps=Nleps+1;
      }
    }
    for(int b=0; b<Muon_size; b++){
      if(Muon_PT[b]>=10 && fabs(Muon_Eta[b])<=2.4){
        Part muon; muon.v.SetPtEtaPhiM(Muon_PT[b], Muon_Eta[b], Muon_Phi[b], 0.105658);
        reco_leps.push_back(muon);
        histo[21]->Fill(Muon_PT[b]);
        Nleps=Nleps+1;
      }
    }
    histo[20]->Fill(reco_leps.size());
  }

  //Jets
  int Njets = Jet_size; int Nbjets=0;
  for(int i=0; i<Njets; i++){
    Part jet; jet.v.SetPtEtaPhiM(Jet_PT[i], Jet_Eta[i], Jet_Phi[i], Jet_Mass[i]);
    if(jet.v.Pt()>=20 && fabs(jet.v.Eta())<3.4){
      reco_jets.push_back(jet);
      histo[18]->Fill(jet.v.Pt());
      if(Jet_BTag[i]==1){
        Nbjets=Nbjets+1;
        Part jet1; jet1.v.SetPtEtaPhiM(Jet_PT[i], Jet_Eta[i], Jet_Phi[i], Jet_Mass[i]);
        if(jet1.v.Pt()>=20 && fabs(jet1.v.Eta())<2.5){
          reco_bjets.push_back(jet1);
          histo[19]->Fill(jet1.v.Pt());
        }
      }
    }
  }
  histo[17]->Fill(reco_bjets.size());
  histo[16]->Fill(reco_jets.size());

  //dPhi bet bb quarks from t
  if(bquarks_t.size()==2){
    float dPhi_bb_t = fabs(bquarks_t.at(0).v.Phi() - bquarks_t.at(1).v.Phi());
    if(dPhi_bb_t>TMath::Pi()) {dPhi_bb_t = 2*TMath::Pi() - dPhi_bb_t;}
    histo[25]->Fill(dPhi_bb_t);
  }
  //dPhi bet bb quarks from H
  if(bquarks_H.size()==2){
    float dPhi_bb_H = fabs(bquarks_H.at(0).v.Phi() - bquarks_H.at(1).v.Phi());
    if(dPhi_bb_H>TMath::Pi()) {dPhi_bb_H = 2*TMath::Pi() - dPhi_bb_H;}
    histo[24]->Fill(dPhi_bb_H);
  }
  //dPhi bet stops
  if(stops.size()==2){
    float dPhi_t1t1 = fabs(stops.at(0).v.Phi() - stops.at(1).v.Phi());
    if(dPhi_t1t1>TMath::Pi()) {dPhi_t1t1 = 2*TMath::Pi() - dPhi_t1t1;}
    histo[26]->Fill(dPhi_t1t1);
  }
  //dPhi bet tops
  if(tops.size()==2){
    float dPhi_tt = fabs(tops.at(0).v.Phi() - tops.at(1).v.Phi());
    if(dPhi_tt>TMath::Pi()) {dPhi_tt = 2*TMath::Pi() - dPhi_tt;}
    histo[27]->Fill(dPhi_tt);
  }
  //dPhi bet t and H
  if(tops.size()==2 && Higgs.size()==1){
    float dPhi_tH = fabs(tops.at(0).v.Phi() - Higgs.at(0).v.Phi());
    if(dPhi_tH>TMath::Pi()) {dPhi_tH = 2*TMath::Pi() - dPhi_tH;}
    histo[49]->Fill(dPhi_tH);
  }
  //dPhi bet t~ and H
  if(tops.size()==2 && Higgs.size()==1){
    float dPhi_tH1 = fabs(tops.at(1).v.Phi() - Higgs.at(0).v.Phi());
    if(dPhi_tH1>TMath::Pi()) {dPhi_tH1 = 2*TMath::Pi() - dPhi_tH1;}
    histo[50]->Fill(dPhi_tH1);
  }
  //dPhi bet N1 N2
  if(Neu2s.size()==1 && Neu1s.size()==1 && Neu1ss.size()==1){
    float dPhi_n1n2 = fabs(Neu2s.at(0).v.Phi() - Neu1s.at(0).v.Phi());
    if(dPhi_n1n2>TMath::Pi()) {dPhi_n1n2 = 2*TMath::Pi() - dPhi_n1n2;}
    histo[30]->Fill(dPhi_n1n2);
    float dPhi_n1n2_ = fabs(Neu2s.at(0).v.Phi() - Neu1ss.at(0).v.Phi());
    if(dPhi_n1n2_>TMath::Pi()) {dPhi_n1n2_ = 2*TMath::Pi() - dPhi_n1n2_;}
    histo[31]->Fill(dPhi_n1n2_);
    float dPhi_n1n1 = fabs(Neu1s.at(0).v.Phi() - Neu1ss.at(0).v.Phi());
    if(dPhi_n1n1>TMath::Pi()) {dPhi_n1n1 = 2*TMath::Pi() - dPhi_n1n1;}
    histo[51]->Fill(dPhi_n1n1);
  }

  //dPhi bet lep and met
  if(reco_leps.size()>0){
    for(int j=0; j<reco_leps.size(); j++){
      float dPhi_l_met = fabs(MissingET_Phi[0] - reco_leps.at(j).v.Phi());
      if(dPhi_l_met>TMath::Pi()) {dPhi_l_met = 2*TMath::Pi() - dPhi_l_met;}
      histo[28]->Fill(dPhi_l_met);
    }
  }
  //dPhi bet lep1 and met
  if(reco_leps.size()==1){
    float dPhi_l1_met = fabs(MissingET_Phi[0] - reco_leps.at(0).v.Phi());
    if(dPhi_l1_met>TMath::Pi()) {dPhi_l1_met = 2*TMath::Pi() - dPhi_l1_met;}
    histo[48]->Fill(dPhi_l1_met);
  }
  //dPhi bet lep and lep+met
  if(reco_leps.size()>0){
    for(int n=0; n<reco_leps.size(); n++){
      float Phi_lmet = (reco_leps.at(n).v + missinget.at(0).v).Phi();
      float dPhi_l_lmet = fabs(Phi_lmet - reco_leps.at(n).v.Phi());
      histo[29]->Fill(dPhi_l_lmet);
    }
  }

  //dPhi bet b-jets
  if(reco_bjets.size()>1){
    for(int k=0; k<reco_bjets.size(); k++){
      for(int l=k+1; l<reco_bjets.size(); l++){
        float dPhi_bbj = fabs(reco_bjets.at(k).v.Phi() - reco_bjets.at(l).v.Phi());
        if(dPhi_bbj>TMath::Pi()) {dPhi_bbj = 2*TMath::Pi() - dPhi_bbj;}
        histo[32]->Fill(dPhi_bbj);
        //dPhi bet b-jets in H window and lep 
        float invM_bbj = (reco_bjets.at(k).v + reco_bjets.at(l).v).M();
        if(reco_leps.size()>0 && invM_bbj<150 && invM_bbj>100){
          float Phi_bbH = (reco_bjets.at(k).v + reco_bjets.at(l).v).Phi();
          for(int m=0; m<reco_leps.size(); m++){
            float dPhi_bbH_l = fabs(Phi_bbH - reco_leps.at(m).v.Phi());
            if(dPhi_bbH_l>TMath::Pi()) {dPhi_bbH_l = 2*TMath::Pi() - dPhi_bbH_l;}
            histo[33]->Fill(dPhi_bbH_l);
          }
        }
      }
    }
  }


  //Event Selection: 1lep + Nj>3 + Nbj>2 
  if(reco_leps.size()==1 && reco_jets.size()>3 && reco_bjets.size()>2){

    histo[34]->Fill(MissingET_MET[0]);
    histo[35]->Fill(ScalarHT_HT[0]);
    histo[36]->Fill(reco_jets.size());
    histo[37]->Fill(reco_bjets.size());

    //dPhi bet bb quarks from t
    if(bquarks_t.size()==2){
      float dPhi_bb_t = fabs(bquarks_t.at(0).v.Phi() - bquarks_t.at(1).v.Phi());
      if(dPhi_bb_t>TMath::Pi()) {dPhi_bb_t = 2*TMath::Pi() - dPhi_bb_t;}
      histo[39]->Fill(dPhi_bb_t);
    }
    //dPhi bet bb quarks from H
    if(bquarks_H.size()==2){
      float dPhi_bb_H = fabs(bquarks_H.at(0).v.Phi() - bquarks_H.at(1).v.Phi());
      if(dPhi_bb_H>TMath::Pi()) {dPhi_bb_H = 2*TMath::Pi() - dPhi_bb_H;}
      histo[38]->Fill(dPhi_bb_H);
    }
    //dPhi bet stops
    if(stops.size()==2){
      float dPhi_t1t1 = fabs(stops.at(0).v.Phi() - stops.at(1).v.Phi());
      if(dPhi_t1t1>TMath::Pi()) {dPhi_t1t1 = 2*TMath::Pi() - dPhi_t1t1;}
      histo[40]->Fill(dPhi_t1t1);
    }
    //dPhi bet tops
    if(tops.size()==2){
      float dPhi_tt = fabs(tops.at(0).v.Phi() - tops.at(1).v.Phi());
      if(dPhi_tt>TMath::Pi()) {dPhi_tt = 2*TMath::Pi() - dPhi_tt;}
      histo[41]->Fill(dPhi_tt);
    }
    //dPhi bet N1 N2
    if(Neu2s.size()==1 && Neu1s.size()==1 && Neu1ss.size()==1){
      float dPhi_n1n2 = fabs(Neu2s.at(0).v.Phi() - Neu1s.at(0).v.Phi());
      if(dPhi_n1n2>TMath::Pi()) {dPhi_n1n2 = 2*TMath::Pi() - dPhi_n1n2;}
      histo[44]->Fill(dPhi_n1n2);
      float dPhi_n1n2_ = fabs(Neu2s.at(0).v.Phi() - Neu1ss.at(0).v.Phi());
      if(dPhi_n1n2_>TMath::Pi()) {dPhi_n1n2_ = 2*TMath::Pi() - dPhi_n1n2_;}
      histo[45]->Fill(dPhi_n1n2_);
    }

    //dPhi bet lep1 and met
    float dPhi_l1_met = fabs(MissingET_Phi[0] - reco_leps.at(0).v.Phi());
    if(dPhi_l1_met>TMath::Pi()) {dPhi_l1_met = 2*TMath::Pi() - dPhi_l1_met;}
    histo[42]->Fill(dPhi_l1_met);
  
    //dPhi bet lep and lep+met
    float Phi_lmet = (reco_leps.at(0).v + missinget.at(0).v).Phi();
    float dPhi_l_lmet = fabs(Phi_lmet - reco_leps.at(0).v.Phi());
    if(dPhi_l_lmet>TMath::Pi()) {dPhi_l_lmet = 2*TMath::Pi() - dPhi_l_lmet;}
    histo[43]->Fill(dPhi_l_lmet);
    //*****
    float Lept_0 = (reco_leps.at(0).v.Pt())*(TMath::Cos(reco_leps.at(0).v.Phi()));
    float Lept_1 = (reco_leps.at(0).v.Pt())*(TMath::Sin(reco_leps.at(0).v.Phi()));
    float Met_Lept_0 = Met_0 + Lept_0;
    float Met_Lept_1 = Met_1 + Lept_1;
    float y_x = (Met_Lept_1)/(Met_Lept_0);
    float Phi = TMath::ATan(y_x);
    float dPhi_l_lmet2D = fabs(reco_leps.at(0).v.Phi() - Phi);
    if(dPhi_l_lmet2D>TMath::Pi()) {dPhi_l_lmet2D = 2*TMath::Pi() - dPhi_l_lmet2D;}
    histo[53]->Fill(dPhi_l_lmet2D);

    //dPhi bet b-jets
    if(reco_bjets.size()>1){
      for(int k=0; k<reco_bjets.size(); k++){
        for(int l=k+1; l<reco_bjets.size(); l++){
          float dPhi_bbj = fabs(reco_bjets.at(k).v.Phi() - reco_bjets.at(l).v.Phi());
          if(dPhi_bbj>TMath::Pi()) {dPhi_bbj = 2*TMath::Pi() - dPhi_bbj;}
          histo[46]->Fill(dPhi_bbj);
          //dPhi bet b-jets in H window and lep 
          float invM_bbj = (reco_bjets.at(k).v + reco_bjets.at(l).v).M();
          if(invM_bbj<150 && invM_bbj>100){
            float Phi_bbH = (reco_bjets.at(k).v + reco_bjets.at(l).v).Phi();
            float dPhi_bbH_l = fabs(Phi_bbH - reco_leps.at(0).v.Phi());
            if(dPhi_bbH_l>TMath::Pi()) {dPhi_bbH_l = 2*TMath::Pi() - dPhi_bbH_l;}
            histo[47]->Fill(dPhi_bbH_l);

            //dPhi bet b-jets in H window and met
            float dPhi_bbH_met = fabs(Phi_bbH - MissingET_Phi[0]);
            if(dPhi_bbH_met>TMath::Pi()) {dPhi_bbH_met = 2*TMath::Pi() - dPhi_bbH_met;}
            histo[52]->Fill(dPhi_bbH_met);


            //
        /*    float bbH_Px = ((reco_bjets.at(k).v + reco_bjets.at(l).v).Pt())*(TMath::Cos((reco_bjets.at(k).v + reco_bjets.at(l).v).Phi()));
            float bbH_Py = ((reco_bjets.at(k).v + reco_bjets.at(l).v).Pt())*(TMath::Sin((reco_bjets.at(k).v + reco_bjets.at(l).v).Phi()));
            float met_bbH_Px = bbH_Px + Met_0;
            float met_bbH_Py = bbH_Py + Met_1;
            float y_x_ = met_bbH_Py/met_bbH_Px;
            float Phi_ = TMath::ATan(y_x_);
            float dPhi_bbHmet_met = fabs(MissingET_Phi[0] - Phi);
            if(dPhi_bbHmet_met>TMath::Pi()) {dPhi_bbHmet_met = 2*TMath::Pi() - dPhi_bbHmet_met;}
            histo[52]->Fill(dPhi_bbHmet_met);*/
            //
            /*float Phi_5 = ((reco_bjets.at(k).v + reco_bjets.at(l).v) + missinget.at(0).v).Phi();
            float dPhi_5 = fabs(Phi_5 - );*/

          }
        }
      }
    }



  }//event selection




   }//event loop
   this->Output();
}//void loop
//-------------------------------------------
Int_t ttbarH_50kevt_1_5::Output()
{
  TFile *rootfile = new TFile("Hst_ttbarH_50kevt_1_5.root", "RECREATE");

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
  histo[47]->Write();
  histo[52]->Write();

  rootfile->Write();
  rootfile->Close();

  return 0;
}

//---------------------------------------------------
