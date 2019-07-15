#define stop_topN2_HZ_300150_cxx
#include "stop_topN2_HZ_300150.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

//*******
#include <TH1.h>
#include <TMath.h>
#include <TLorentzVector.h>
#include <iostream>

void stop_topN2_HZ_300150::Loop()
{
//   In a ROOT session, you can do:
//      root> .L stop_topN2_HZ_300150.C
//      root> stop_topN2_HZ_300150 t
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
   histo[43] = new TH1D("st~_PT", "PT of stopbar", 100, 0, 2500);
   histo[1] = new TH1D("t_PT", "PT of top", 100, 0, 1500);
   histo[44] = new TH1D("t~_PT", "PT of antitop", 100, 0, 1500);
   histo[2] = new TH1D("n2_PT", "PT of Neu2 from ~t1", 100, 0, 2000);
   histo[45] = new TH1D("n2~_PT", "PT of Neu2 from ~t1bar", 100, 0, 2000);
   histo[3] = new TH1D("b_t_PT", "PT of b from t", 100, 0, 1000);
   histo[4] = new TH1D("b~_t_PT", "PT of b~ from t~", 100, 0, 1000);
   histo[18] = new TH1D("b_H_PT", "PT of b from H", 100, 0, 1000);
   histo[19] = new TH1D("b~_H_PT", "PT of b~ from H", 100, 0, 1000);

   histo[5] = new TH1D("W_PT", "PT of W+ boson", 100, 0, 1000);
   histo[46] = new TH1D("W~_PT", "PT of W- boson", 100, 0, 1000);
   histo[6] = new TH1D("H_PT", "PT of H boson", 100, 0, 1000);
   histo[7] = new TH1D("Z_PT", "PT of Z boson", 100, 0, 1000);
   histo[8] = new TH1D("n1_PT", "PT of Neu1 from ~t1", 100, 0, 1500);
   histo[47] = new TH1D("n1~_PT", "PT of Neu1 from ~t1bar", 100, 0, 1500);

   //dPhi_bb
   histo[9] = new TH1D("dPhi_bb_H", "dPhi bet bb (from H)", 50, 0, 5);
   histo[10] = new TH1D("dPhi_bb_t", "dPhi bet bb (from t)", 50, 0, 5);
   histo[15] = new TH1D("dPhi_bb_Ht_tt", "dPhi bet bb (from other than H)", 50, 0, 5);
   histo[16] = new TH1D("dR_bb_H", "dR bet bb (from H)", 50, 0, 5);
   histo[17] = new TH1D("dR_bb_Ht_tt", "dR bet bb (from other than H)", 50, 0, 5);

   histo[11] = new TH1D("Mass_bb_H", "Invar M of bb from H", 100, 0, 1000);
   histo[12] = new TH1D("Mass_bb_t", "Invar M of bb from t", 100, 0, 1000);
   histo[13] = new TH1D("PT_bb_H", "PT of bb from H", 100, 0, 1000);
   histo[14] = new TH1D("PT_bb_t", "PT of bb from t", 100, 0, 1000);

   histo[20] = new TH1D("Nj", "NJets", 20, 0, 20);
   histo[21] = new TH1D("Nbj", "NbJets", 10, 0, 10);
   histo[22] = new TH1D("PT_Jets", "PT of Jets", 100, 0, 1000);
   histo[23] = new TH1D("PT_bJets", "PT of b Jets", 100, 0, 1000);

   histo[24] = new TH1D("dPhi_bb", "dPhi bet bb", 50, 0, 5);
   histo[25] = new TH1D("dR_bb", "dR bet bb", 50, 0, 5);

   histo[26] = new TH1D("min_dPhi", "min dPhi", 50, 0, 5);
   histo[36] = new TH1D("min_dR", "min dR", 50, 0, 5);

   histo[28] = new TH1D("Nleps", "NLeps", 5, 0, 5);
   histo[29] = new TH1D("PT_Leps", "PT of Leps", 100, 0, 1000);

   histo[30] = new TH1D("MET", "MET", 100, 0, 1500);
   histo[31] = new TH1D("HT", "HT", 100, 0, 3000);

   histo[32] = new TH1D("inv_M_min_dP", "invariant Mass of bb with min dPhi", 100, 0, 1000);
   histo[33] = new TH1D("inv_M_1.0", "invariant Mass of bb with dPhi<=1.0", 100, 0, 1000);
   histo[34] = new TH1D("N_bjets_min", "N bJet pair with min dPhi", 10, 0, 10);
   histo[35] = new TH1D("N_bjets_cut_dP1.0", "N bJet pair with dPhi<=1.0", 10, 0, 10);
   histo[37] = new TH1D("inv_M_min_dR", "invariant Mass of bb with min dR", 100, 0, 1000);
   histo[38] = new TH1D("inv_M_cut_dR1.5", "invariant Mass of bb with dR<=1.5", 100, 0, 1000);

   histo[39] = new TH1D("N_match_bjets", "N of matched b-jets in dR 0.3", 10, 0, 10);
   histo[40] = new TH1D("dR_bj_bq", "dR bet b-quark and matched b-jet", 50, 0, 0.5);
   histo[41] = new TH1D("dPhi_bb_match", "dPhi bet matched bb", 50, 0, 5);
   histo[42] = new TH1D("inv_M_match_b", "invariant Mass of bb matched with b-quarks in dR 0.3", 100, 0, 1000);

   histo[48] = new TH1D("inv_M_ll", "invariant Mass of ossf leps", 100, 0, 1000);


   histo[49] = new TH1D("N_bbj_match_mindP", "N bbjets with min dPhi and also matched to b-quarks from H in dR 0.3", 10, 0, 10);
   histo[50] = new TH1D("inv_M_match_mindP_bb", "invariant Mass of bb with min dPhi and also matched with b-quarks in dR 0.3", 100, 0, 1000);
   histo[51] = new TH1D("dPhi_bb_match_mindP", "dPhi bet min dPhi bb and also matched to b-quarks from H in dR 0.3", 50, 0, 5);

   histo[57] = new TH1D("min_dPhi_bq", "min dPhi bet bquarks", 50, 0, 5);
   histo[58] = new TH1D("N_bbq_match_mindP", "N bbquarks with min dPhi and also matched to b-quarks from H in dR 0.3", 10, 0, 10);


   //2D plots
   hist[0] = new TH2D("PT_H_dPhi_bb_quarks", "PT of H vs dPhi bet bb quarks from H", 50, 0, 5, 100, 0, 1000);  
   hist[1] = new TH2D("PT_H_dPhi_bbj_mindPhi", "PT of H vs dPhi bet bb jets with min dPhi", 50, 0, 5, 100, 0, 1000);
   hist[2] = new TH2D("PT_H_dPhi_bbj_matched", "PT of H vs dPhi bet bb jets matched with b-quarks", 50, 0, 5, 100, 0, 1000);


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

      Higgs.clear();
      bquark_H.clear();
      bquark_t.clear();
      bantiquark_H.clear();
      bantiquark_t.clear();
      b_quarks_H.clear();
      b_quarks.clear();
      match_bjets.clear();
      matched_bquarks.clear();

      matched_mindP_jets.clear();


      reco_bjets.clear();
      reco_jets.clear();
      array_dPhi.clear();
      array_dR.clear();
      dPhi_bquarks.clear();

      Elec.clear();
      Muon.clear();
      Leptons.clear();

//-------------------------------------------

//mycode

//float Weight = 1.0 /*0.0476*150*0.1*/;
//cout<<"new event"<<endl;
//Particles

//cout<<"index "<<"  Status "<<"  PID "<<"  M1 "<<"  M2 "<<"  D1 "<<"  D2 "<<"  PT "<<endl;

int NPar=Particle_size;
for(int i=0; i<NPar; i++){

//cout<<i<<"   "<<Particle_Status[i]<<"   "<<Particle_PID[i]<<"   "<<Particle_M1[i]<<"   "<<Particle_M2[i]<<"   "<<Particle_D1[i]<<"   "<<Particle_D2[i]<<"   "<<Particle_PT[i]<<endl;

  //stop
  if(Particle_PID[i]==1000006) {
    histo[0]->Fill(Particle_PT[i]);
  }
  if(Particle_PID[i]==-1000006) {
    histo[43]->Fill(Particle_PT[i]);
  }
  //top
  if(Particle_PID[i]==6) {
    histo[1]->Fill(Particle_PT[i]);
  }
  if(Particle_PID[i]==-6) {
    histo[44]->Fill(Particle_PT[i]);
  }
  //Neu2
  if(Particle_PID[i]==1000023 && Particle_PID[Particle_M1[i]]==1000006) {
    histo[2]->Fill(Particle_PT[i]);
  }
  if(Particle_PID[i]==1000023 && Particle_PID[Particle_M1[i]]==-1000006) {
    histo[45]->Fill(Particle_PT[i]);
  }
  //b from t
  if(Particle_PID[i]==5 && Particle_PID[Particle_M1[i]]==6 && Particle_Status[i]==3) {
    histo[3]->Fill(Particle_PT[i]);
    Part par; par.v.SetPtEtaPhiM(Particle_PT[i], Particle_Eta[i], Particle_Phi[i], Particle_Mass[i]);
    par.id=Particle_PID[i]; par.ind=i; par.Charge=Particle_Charge[i];
    bquark_t.push_back(par); b_quarks.push_back(par);
  }
  if(Particle_PID[i]==-5 && Particle_PID[Particle_M1[i]]==-6 && Particle_Status[i]==3) {
    histo[4]->Fill(Particle_PT[i]);
    Part par; par.v.SetPtEtaPhiM(Particle_PT[i], Particle_Eta[i], Particle_Phi[i], Particle_Mass[i]);
    par.id=Particle_PID[i]; par.ind=i; par.Charge=Particle_Charge[i];
    bantiquark_t.push_back(par); b_quarks.push_back(par);
  }
  //b from H
  if(Particle_PID[i]==5 && Particle_PID[Particle_M1[i]]==25) {
    histo[18]->Fill(Particle_PT[i]);
    Part par; par.v.SetPtEtaPhiM(Particle_PT[i], Particle_Eta[i], Particle_Phi[i], Particle_Mass[i]);
    par.id=Particle_PID[i]; par.ind=i; par.Charge=Particle_Charge[i];
    bquark_H.push_back(par);b_quarks_H.push_back(par); b_quarks.push_back(par);
  }
  if(Particle_PID[i]==-5 && Particle_PID[Particle_M1[i]]==25) {
    histo[19]->Fill(Particle_PT[i]);
    Part par; par.v.SetPtEtaPhiM(Particle_PT[i], Particle_Eta[i], Particle_Phi[i], Particle_Mass[i]);
    par.id=Particle_PID[i]; par.ind=i; par.Charge=Particle_Charge[i];
    bantiquark_H.push_back(par);b_quarks_H.push_back(par); b_quarks.push_back(par);
  }
  //W
  if(Particle_PID[i]==24 && Particle_PID[Particle_M1[i]]==6) {
    histo[5]->Fill(Particle_PT[i]);
  }
  if(Particle_PID[i]==-24 && Particle_PID[Particle_M1[i]]==-6) {
    histo[46]->Fill(Particle_PT[i]);
  }
  //H
  if(abs(Particle_PID[i])==25 && Particle_PID[Particle_M1[i]]==1000023) {
    Part par; par.v.SetPtEtaPhiM(Particle_PT[i], Particle_Eta[i], Particle_Phi[i], Particle_Mass[i]);
    Higgs.push_back(par);
    histo[6]->Fill(Particle_PT[i]);
  }
  //Z
  if(abs(Particle_PID[i])==23 && Particle_PID[Particle_M1[i]]==1000023) {
    histo[7]->Fill(Particle_PT[i]);
  }
  //Neu1
  if(Particle_PID[i]==1000022 && Particle_PID[Particle_M1[Particle_M1[i]]]==1000006) {
    histo[8]->Fill(Particle_PT[i]);
  }
  if(Particle_PID[i]==1000022 && Particle_PID[Particle_M1[Particle_M1[i]]]==-1000006) {
    histo[47]->Fill(Particle_PT[i]);
  }

}//par loop


  //MET HT
  histo[30]->Fill(MissingET_MET[0]);
  histo[31]->Fill(ScalarHT_HT[0]);


  //dPhi bet b-quarks from H
  if(bquark_H.size()>0 && bantiquark_H.size()>0){
    float dPhi_bb_H = fabs(bquark_H.at(0).v.Phi() - bantiquark_H.at(0).v.Phi());
    if(dPhi_bb_H>TMath::Pi()) {dPhi_bb_H = 2*TMath::Pi() - dPhi_bb_H;}
    histo[9]->Fill(dPhi_bb_H);
    hist[0]->Fill(dPhi_bb_H, Higgs.at(0).v.Pt());

    //dR
    float dEta_bb_H = fabs(bquark_H.at(0).v.Eta() - bantiquark_H.at(0).v.Eta());
    float dR_bb_H = sqrt(pow(dPhi_bb_H,2) + pow(dEta_bb_H,2));
    histo[16]->Fill(dR_bb_H);

    float Mass_bb_H = (bquark_H.at(0).v + bantiquark_H.at(0).v).M();
    float PT_bb_H = (bquark_H.at(0).v + bantiquark_H.at(0).v).Pt();
    histo[11]->Fill(Mass_bb_H);
    histo[13]->Fill(PT_bb_H);
  }

  //dPhi bet b-quarks from t
  if(bquark_t.size()>0 && bantiquark_t.size()>0){
    float dPhi_bb_t = fabs(bquark_t.at(0).v.Phi() - bantiquark_t.at(0).v.Phi());
    if(dPhi_bb_t>TMath::Pi()) {dPhi_bb_t = 2*TMath::Pi() - dPhi_bb_t;}
    histo[10]->Fill(dPhi_bb_t);

    float Mass_bb_t = (bquark_t.at(0).v + bantiquark_t.at(0).v).M();
    float PT_bb_t = (bquark_t.at(0).v + bantiquark_t.at(0).v).Pt();
    histo[12]->Fill(Mass_bb_t);
    histo[14]->Fill(PT_bb_t);
  }


  if(bquark_H.size()>0 && bantiquark_H.size()>0 && bquark_t.size()>0 && bantiquark_t.size()>0){
    //dPhi
    float dPhi00 = fabs(bquark_H.at(0).v.Phi() - bquark_t.at(0).v.Phi());
    if(dPhi00>TMath::Pi()) {dPhi00 = 2*TMath::Pi() - dPhi00;}
    histo[15]->Fill(dPhi00, 0.2);
    float dPhi01 = fabs(bquark_H.at(0).v.Phi() - bantiquark_t.at(0).v.Phi());
    if(dPhi01>TMath::Pi()) {dPhi01 = 2*TMath::Pi() - dPhi01;}
    histo[15]->Fill(dPhi01, 0.2);
    float dPhi10 = fabs(bantiquark_H.at(0).v.Phi() - bquark_t.at(0).v.Phi());
    if(dPhi10>TMath::Pi()) {dPhi10 = 2*TMath::Pi() - dPhi10;}
    histo[15]->Fill(dPhi10, 0.2);
    float dPhi11 = fabs(bantiquark_H.at(0).v.Phi() - bantiquark_t.at(0).v.Phi());
    if(dPhi11>TMath::Pi()) {dPhi11 = 2*TMath::Pi() - dPhi11;}
    histo[15]->Fill(dPhi11, 0.2);
    float dPhi22 = fabs(bquark_t.at(0).v.Phi() - bantiquark_t.at(0).v.Phi());
    if(dPhi22>TMath::Pi()) {dPhi22 = 2*TMath::Pi() - dPhi22;}
    histo[15]->Fill(dPhi22, 0.2);

    //dR
    float dEta00 = fabs(bquark_H.at(0).v.Eta() - bquark_t.at(0).v.Eta());
    float dR00 = sqrt(pow(dPhi00,2) + pow(dEta00,2));
    histo[17]->Fill(dR00, 0.2);
    float dEta01 = fabs(bquark_H.at(0).v.Eta() - bantiquark_t.at(0).v.Eta());
    float dR01 = sqrt(pow(dPhi01,2) + pow(dEta01,2));
    histo[17]->Fill(dR01, 0.2);
    float dEta10 = fabs(bantiquark_H.at(0).v.Eta() - bquark_t.at(0).v.Eta());
    float dR10 = sqrt(pow(dPhi10,2) + pow(dEta10,2));
    histo[17]->Fill(dR10, 0.2);
    float dEta11 = fabs(bantiquark_H.at(0).v.Eta() - bantiquark_t.at(0).v.Eta());
    float dR11 = sqrt(pow(dPhi11,2) + pow(dEta11,2));
    histo[17]->Fill(dR11, 0.2);
    float dEta22 = fabs(bquark_t.at(0).v.Eta() - bantiquark_t.at(0).v.Eta());
    float dR22 = sqrt(pow(dPhi22,2) + pow(dEta22,2));
    histo[17]->Fill(dR22, 0.2);

  }

  //min dPhi at gen level bet b-quarks from H and t
  if(b_quarks.size()>1){
    for(int i=0; i<b_quarks.size(); i++){
      for(int j=i+1; j<b_quarks.size(); j++){
        float dP = fabs(b_quarks.at(i).v.Phi() - b_quarks.at(j).v.Phi());
        if(dP>TMath::Pi()) {dP = 2*TMath::Pi() - dP;}
        dPhi_bquarks.push_back(dP);
      }
    }
    //find min dPhi
    float min_dP_bquarks = dPhi_bquarks.at(0);
    for(int k=0; k<dPhi_bquarks.size(); k++){
      if(dPhi_bquarks.at(k) < min_dP_bquarks){
        min_dP_bquarks = dPhi_bquarks.at(k);
      }
    }
    for(int l=0; l<b_quarks.size(); l++){
      for(int m=l+1; m<b_quarks.size(); m++){
        float dP_ = fabs(b_quarks.at(l).v.Phi() - b_quarks.at(m).v.Phi());
        if(dP_>TMath::Pi()) {dP_ = 2*TMath::Pi() - dP_;}
        if(dP_ == min_dP_bquarks){
          histo[57]->Fill(min_dP_bquarks);
          //check if these match with b-quarks from H in dR 0.3
          if(b_quarks_H.size()>1){
            float dP11 = fabs(b_quarks.at(l).v.Phi() - b_quarks_H.at(0).v.Phi());
            if(dP11>TMath::Pi()) {dP11 = 2*TMath::Pi() - dP11;}
            float dE11 = fabs(b_quarks.at(l).v.Eta() - b_quarks_H.at(0).v.Eta());
            float dR11 = sqrt(pow(dP11,2) + pow(dE11,2));

            float dP12 = fabs(b_quarks.at(l).v.Phi() - b_quarks_H.at(1).v.Phi());
            if(dP12>TMath::Pi()) {dP12 = 2*TMath::Pi() - dP12;}
            float dE12 = fabs(b_quarks.at(l).v.Eta() - b_quarks_H.at(1).v.Eta());
            float dR12 = sqrt(pow(dP12,2) + pow(dE12,2));

            float dP21 = fabs(b_quarks.at(m).v.Phi() - b_quarks_H.at(0).v.Phi());
            if(dP21>TMath::Pi()) {dP21 = 2*TMath::Pi() - dP21;}
            float dE21 = fabs(b_quarks.at(m).v.Eta() - b_quarks_H.at(0).v.Eta());
            float dR21 = sqrt(pow(dP21,2) + pow(dE21,2));

            float dP22 = fabs(b_quarks.at(m).v.Phi() - b_quarks_H.at(1).v.Phi());
            if(dP22>TMath::Pi()) {dP22 = 2*TMath::Pi() - dP22;}
            float dE22 = fabs(b_quarks.at(m).v.Eta() - b_quarks_H.at(1).v.Eta());
            float dR22 = sqrt(pow(dP22,2) + pow(dE22,2));

            if(dR11<=0.3 || dR12<=0.3){
              matched_bquarks.push_back(b_quarks.at(l));
            }
            if(dR21<=0.3 || dR22<=0.3){
              matched_bquarks.push_back(b_quarks.at(m));
            }
          }
        }
      }
    }
    histo[58]->Fill(matched_bquarks.size());
  }

  //b-jets
  int Njets = Jet_size; int Nbjets=0;
  for(int i=0; i<Njets; i++){
    Part jet; jet.v.SetPtEtaPhiM(Jet_PT[i], Jet_Eta[i], Jet_Phi[i], Jet_Mass[i]);
    reco_jets.push_back(jet);
    histo[22]->Fill(jet.v.Pt());
    if(Jet_BTag[i]==1){
      Nbjets=Nbjets+1;
      Part jet1; jet1.v.SetPtEtaPhiM(Jet_PT[i], Jet_Eta[i], Jet_Phi[i], Jet_Mass[i]);
      reco_bjets.push_back(jet1);
      histo[23]->Fill(jet1.v.Pt());
    }
  }
  histo[21]->Fill(reco_bjets.size());
  histo[20]->Fill(reco_jets.size());
  //dPhi bet b-jets
  for(int j=0; j<reco_bjets.size(); j++){
    for(int k=j+1; k<reco_bjets.size(); k++){
      float dPhi = fabs(reco_bjets.at(j).v.Phi() - reco_bjets.at(k).v.Phi());
      if(dPhi>TMath::Pi()) {dPhi = 2*TMath::Pi() - dPhi;}
      float dEta = fabs(reco_bjets.at(j).v.Eta() - reco_bjets.at(k).v.Eta());
      float dR = sqrt( pow(dPhi,2) + pow(dEta,2) );
      array_dPhi.push_back(dPhi);
      array_dR.push_back(dR);
      histo[24]->Fill(dPhi);
      histo[25]->Fill(dR);
    }
  }
  if(array_dPhi.size()>0){
    float min_dPhi=array_dPhi.at(0); int index=0;
    for(int l=1; l<array_dPhi.size(); l++){
      if(array_dPhi.at(l) < min_dPhi){
        min_dPhi = array_dPhi.at(l);
        index = l;
      }
    }
    histo[26]->Fill(min_dPhi);
    hist[1]->Fill(min_dPhi, Higgs.at(0).v.Pt());
    //histo[27]->Fill(array_dPhi.at(index));
  
    //Inv M with min_dPhi
    if(reco_bjets.size()>1){
      int N_bjets_mindPhi=0;
      for(int b=0; b<reco_bjets.size(); b++){
        for(int c=b+1; c<reco_bjets.size(); c++){
          float dP = fabs(reco_bjets.at(b).v.Phi() - reco_bjets.at(c).v.Phi());
          if(dP>TMath::Pi()) {dP = 2*TMath::Pi() - dP;}
          if(dP==min_dPhi){
            float inv_M = (reco_bjets.at(b).v + reco_bjets.at(c).v).M();
            histo[32]->Fill(inv_M);
            N_bjets_mindPhi=N_bjets_mindPhi+1;
            //check if these b-jets are matched to b-quarks from H in dR 0.3
            if(b_quarks_H.size()>1){
              float dP_bjbq11 = fabs(reco_bjets.at(b).v.Phi() - b_quarks_H.at(0).v.Phi());
              if(dP_bjbq11>TMath::Pi()) {dP_bjbq11 = 2*TMath::Pi() - dP_bjbq11;}
              float dE_bjbq11 = fabs(reco_bjets.at(b).v.Eta() - b_quarks_H.at(0).v.Eta());
              float dR_bjbq11 = sqrt(pow(dP_bjbq11,2) + pow(dE_bjbq11,2));

              float dP_bjbq12 = fabs(reco_bjets.at(b).v.Phi() - b_quarks_H.at(1).v.Phi());
              if(dP_bjbq12>TMath::Pi()) {dP_bjbq12 = 2*TMath::Pi() - dP_bjbq12;}
              float dE_bjbq12 = fabs(reco_bjets.at(b).v.Eta() - b_quarks_H.at(1).v.Eta());
              float dR_bjbq12 = sqrt(pow(dP_bjbq12,2) + pow(dE_bjbq12,2));

              float dP_bjbq21 = fabs(reco_bjets.at(c).v.Phi() - b_quarks_H.at(0).v.Phi());
              if(dP_bjbq21>TMath::Pi()) {dP_bjbq21 = 2*TMath::Pi() - dP_bjbq21;}
              float dE_bjbq21 = fabs(reco_bjets.at(c).v.Eta() - b_quarks_H.at(0).v.Eta());
              float dR_bjbq21 = sqrt(pow(dP_bjbq21,2) + pow(dE_bjbq21,2));

              float dP_bjbq22 = fabs(reco_bjets.at(c).v.Phi() - b_quarks_H.at(1).v.Phi());
              if(dP_bjbq22>TMath::Pi()) {dP_bjbq22 = 2*TMath::Pi() - dP_bjbq22;}
              float dE_bjbq22 = fabs(reco_bjets.at(c).v.Eta() - b_quarks_H.at(1).v.Eta());
              float dR_bjbq22 = sqrt(pow(dP_bjbq22,2) + pow(dE_bjbq22,2));

              if(dR_bjbq11<=0.3 || dR_bjbq12<=0.3){
                matched_mindP_jets.push_back(reco_bjets.at(b));
              }
              if(dR_bjbq21<=0.3 || dR_bjbq22<=0.3){
                matched_mindP_jets.push_back(reco_bjets.at(c));
              }

            }//
          }
        }   
      }
      histo[34]->Fill(N_bjets_mindPhi);
      histo[49]->Fill(matched_mindP_jets.size());
      if(matched_mindP_jets.size()>1){
        for(int i=0; i<matched_mindP_jets.size(); i++){
          for(int j=i+1; j<matched_mindP_jets.size(); j++){
            float invM_match_mindP = (matched_mindP_jets.at(i).v + matched_mindP_jets.at(j).v).M(); 
            histo[50]->Fill(invM_match_mindP);
            float dPhi_match_mindP = fabs(matched_mindP_jets.at(i).v.Phi() - matched_mindP_jets.at(j).v.Phi());
            if(dPhi_match_mindP>TMath::Pi()) {dPhi_match_mindP = 2*TMath::Pi() - dPhi_match_mindP;}
            histo[51]->Fill(dPhi_match_mindP);
          }
        }
      }
    }
    //Inv M with cut dP<=1.0
    if(reco_bjets.size()>1){
     int N_bjets_cut_1=0;
      for(int b=0; b<reco_bjets.size(); b++){
        for(int c=b+1; c<reco_bjets.size(); c++){
          float dP = fabs(reco_bjets.at(b).v.Phi() - reco_bjets.at(c).v.Phi());
          if(dP>TMath::Pi()) {dP = 2*TMath::Pi() - dP;}
          if(dP<=1.0){
            float inv_M_1 = (reco_bjets.at(b).v + reco_bjets.at(c).v).M();
            histo[33]->Fill(inv_M_1);
            N_bjets_cut_1=N_bjets_cut_1+1;
          }
        }   
      }
      histo[35]->Fill(N_bjets_cut_1);
    }
  }//
  //
  if(array_dR.size()>0){
    float min_dR=array_dR.at(0); 
    for(int l1=1; l1<array_dR.size(); l1++){
      if(array_dR.at(l1) < min_dR){
        min_dR = array_dR.at(l1);
      }
    }
    histo[36]->Fill(min_dR);

    //Inv M with min_dR
    if(reco_bjets.size()>1){
      for(int b1=0; b1<reco_bjets.size(); b1++){
        for(int c1=b1+1; c1<reco_bjets.size(); c1++){
          float dP1 = fabs(reco_bjets.at(b1).v.Phi() - reco_bjets.at(c1).v.Phi());
          if(dP1>TMath::Pi()) {dP1 = 2*TMath::Pi() - dP1;}
          float dE1 = fabs(reco_bjets.at(b1).v.Eta() - reco_bjets.at(c1).v.Eta());
          float dR1 = sqrt(pow(dP1,2) + pow(dE1,2));
          if(dR1==min_dR){
            float inv_M_dR = (reco_bjets.at(b1).v + reco_bjets.at(c1).v).M();
            histo[37]->Fill(inv_M_dR);
          }
        }   
      }
    }
    //Inv M with cut dR<=1.5
    if(reco_bjets.size()>1){
      for(int b1=0; b1<reco_bjets.size(); b1++){
        for(int c1=b1+1; c1<reco_bjets.size(); c1++){
          float dP = fabs(reco_bjets.at(b1).v.Phi() - reco_bjets.at(c1).v.Phi());
          if(dP>TMath::Pi()) {dP = 2*TMath::Pi() - dP;}
          float dE = fabs(reco_bjets.at(b1).v.Eta() - reco_bjets.at(c1).v.Eta());
          float dR = sqrt(pow(dP,2) + pow(dE,2));
          if(dR<=1.5){
            float inv_M_15 = (reco_bjets.at(b1).v + reco_bjets.at(c1).v).M();
            histo[38]->Fill(inv_M_15);
          }
        }   
      }
    }
  }//


  //matching b-jets with b-quarks
  if(reco_bjets.size()>0 && b_quarks_H.size()>0){
    for(int s=0; s<reco_bjets.size(); s++){
      array_dR_b.clear();
      for(int r=0; r<b_quarks_H.size(); r++){
        float dP = fabs(reco_bjets.at(s).v.Phi() - b_quarks_H.at(r).v.Phi());
        if(dP>TMath::Pi()) {dP = 2*TMath::Pi() - dP;}
        float dE = fabs(reco_bjets.at(s).v.Eta() - b_quarks_H.at(r).v.Eta());
        float dR = sqrt(pow(dP,2) + pow(dE,2));
        if(dR<=0.3){
          array_dR_b.push_back(dR);
        }
      }
      //
      if(array_dR_b.size()==1){
        match_bjets.push_back(reco_bjets.at(s));
        histo[40]->Fill(array_dR_b.at(0));
      }
      if(array_dR_b.size()>1){
        float dR_mini=array_dR_b.at(0);
        for(int h=1; h<array_dR_b.size(); h++){
          if(array_dR_b.at(h)<dR_mini){
            dR_mini = array_dR_b.at(h);
          }
        }
        for(int r=0; r<b_quarks_H.size(); r++){
          float dP = fabs(reco_bjets.at(s).v.Phi() - b_quarks_H.at(r).v.Phi());
          if(dP>TMath::Pi()) {dP = 2*TMath::Pi() - dP;}
          float dE = fabs(reco_bjets.at(s).v.Eta() - b_quarks_H.at(r).v.Eta());
          float dR = sqrt(pow(dP,2) + pow(dE,2));
          if(dR==dR_mini){
            match_bjets.push_back(reco_bjets.at(s));
            histo[40]->Fill(dR);
          }
        }
      }
    }//bjet loop
    histo[39]->Fill(match_bjets.size());
    if(match_bjets.size()>0){
      for(int m=0; m<match_bjets.size(); m++){
        for(int m1=m+1; m1<match_bjets.size(); m1++){
          float dP_m = fabs(match_bjets.at(m).v.Phi() - match_bjets.at(m1).v.Phi());
          if(dP_m>TMath::Pi()) {dP_m = 2*TMath::Pi() - dP_m;}
          histo[41]->Fill(dP_m);
          hist[2]->Fill(dP_m, Higgs.at(0).v.Pt());
        }
      }    
    }
    if(match_bjets.size()==2){
      float invM = (match_bjets.at(0).v + match_bjets.at(1).v).M();
      histo[42]->Fill(invM);
    }
  }


  //Leptons
  int Nleps = Electron_size + Muon_size;
  histo[28]->Fill(Nleps);
  if(Nleps>0){
    for(int a=0; a<Nleps; a++){
      histo[29]->Fill(Electron_PT[a]);
      histo[29]->Fill(Muon_PT[a]);
    }
  }

  int N_elec = Electron_size;
  int N_muon = Muon_size;
    for(int b=0; b<N_elec; b++){
      Part lep; lep.v.SetPtEtaPhiM(Electron_PT[b], Electron_Eta[b], Electron_Phi[b], 0.000511);
      lep.Charge=Electron_Charge[b]; lep.flavor=11;
      Elec.push_back(lep);
      Leptons.push_back(lep);
    }
    for(int b=0; b<N_muon; b++){
      Part lep; lep.v.SetPtEtaPhiM(Muon_PT[b], Muon_Eta[b], Muon_Phi[b], 0.105658);
      lep.Charge=Muon_Charge[b]; lep.flavor=13;
      Muon.push_back(lep);
      Leptons.push_back(lep);
    }


  //Tagging Z using l+ l-
  if(Leptons.size()>2){
    for(int i=0; i<Leptons.size(); i++){
      for(int j=i+1; j<Leptons.size(); j++){
        if( (Leptons.at(i).flavor==Leptons.at(j).flavor) && (Leptons.at(i).Charge!=Leptons.at(j).Charge) ){
          float Inv_M_ll = (Leptons.at(i).v + Leptons.at(j).v).M();
          histo[48]->Fill(Inv_M_ll);
        }
      }

    }
  
  }





   }//event loop
   this->Output();
}//void loop
//-------------------------------------------
Int_t stop_topN2_HZ_300150::Output()
{
  TFile *rootfile = new TFile("Hst_stop_topN2_HZ_300150.root", "RECREATE");

  histo[0]->Write();
  histo[43]->Write();
  histo[1]->Write();
  histo[44]->Write();
  histo[2]->Write();
  histo[45]->Write();
  histo[3]->Write();
  histo[4]->Write();
  histo[18]->Write();
  histo[19]->Write();
  histo[5]->Write();
  histo[46]->Write();
  histo[6]->Write();
  histo[7]->Write();
  histo[8]->Write();
  histo[47]->Write();
  histo[9]->Write();
  histo[10]->Write();
  histo[15]->Write();
  histo[16]->Write();
  histo[17]->Write();
  histo[11]->Write();
  histo[12]->Write();
  histo[13]->Write();
  histo[14]->Write();
  histo[20]->Write();
  histo[21]->Write();
  histo[22]->Write();
  histo[23]->Write();
  histo[24]->Write();
  histo[25]->Write();
  histo[26]->Write();
  histo[36]->Write();
  histo[28]->Write();
  histo[29]->Write();
  histo[30]->Write();
  histo[31]->Write();
  histo[32]->Write();
  histo[33]->Write();
  histo[34]->Write();
  histo[35]->Write();
  histo[37]->Write();
  histo[38]->Write();
  histo[39]->Write();
  histo[40]->Write();
  histo[41]->Write();
  histo[42]->Write();
  histo[48]->Write();
  histo[49]->Write();
  histo[50]->Write();
  histo[51]->Write();
  histo[57]->Write();
  histo[58]->Write();


  hist[0]->Write();
  hist[1]->Write();
  hist[2]->Write();


  rootfile->Write();
  rootfile->Close();

  return 0;
}

//---------------------------------------------------
