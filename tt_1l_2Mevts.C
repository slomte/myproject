#define tt_1l_2Mevts_cxx
#include "tt_1l_2Mevts.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

//*******
#include <TH1.h>
#include <TMath.h>
#include <TLorentzVector.h>
#include <iostream>

void tt_1l_2Mevts::Loop()
{
//   In a ROOT session, you can do:
//      root> .L tt_1l_2Mevts.C
//      root> tt_1l_2Mevts t
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

   histo[0] = new TH1D("Nj", "NJets", 20, 0, 20);
   histo[1] = new TH1D("Nbj", "NbJets", 10, 0, 10);
   histo[2] = new TH1D("PT_Jets", "PT of Jets", 100, 0, 2000);
   histo[3] = new TH1D("PT_bJets", "PT of b Jets", 100, 0, 2000);
   histo[4] = new TH1D("Nleps", "NLeps", 10, 0, 10);
   histo[5] = new TH1D("PT_Leps", "PT of Leps", 100, 0, 1500);
   histo[6] = new TH1D("Nfatj", "N Fat Jets", 8, 0, 8);
   histo[265] = new TH1D("Nfatj_match_1b", "N Fat Jets matched to atleast one b-jet", 8, 0, 8);
   histo[7] = new TH1D("PT_fatj", "p_{T} of Fat Jets", 100, 0, 2000);
   histo[8] = new TH1D("Tau21", "Tau[1]/Tau[0] for Fat Jets", 100, 0, 1);
   histo[9] = new TH1D("Tau32", "Tau[2]/Tau[1] for Fat Jets", 100, 0, 1);
   histo[174] = new TH1D("PT_H1", "PT of Higgs", 100, 0, 2000);
   histo[43] = new TH1D("PT_H2", "PT of Higgs", 100, 0, 2000);

   histo[192] = new TH1D("N_fatj_cand", "N of Candidate fatjets", 10, 0, 10);
   histo[175] = new TH1D("PT_fatj_cand", "PT of Candidate fatjets", 100, 0, 2000);
   histo[176] = new TH1D("M_fatj_cand", "Mass of Candidate fatjets", 100, 0, 800);
   histo[193] = new TH1D("N_resbbj_cand", "N of Candidate resolved bb jets", 30, 0, 30);
   histo[177] = new TH1D("PT_resbbj_cand", "PT of Candidate resolved bb jets", 100, 0, 2000);
   histo[178] = new TH1D("M_resbbj_cand", "Mass of Candidate resolved bb jets", 100, 0, 5000);

   histo[145] = new TH1D("Nresbbj", "N resolved bb Jets in H window", 15, 0, 15);
   histo[146] = new TH1D("PT_resbbj", "p_{T} of resolved bb Jets in H window", 100, 0, 2000);
   histo[179] = new TH1D("M_resbbj", "Mass of resolved bb Jets in H window", 100, 0, 2000);
   histo[147] = new TH1D("PT_1resbbj_H", "p_{T} of resolved bb Jet", 100, 0, 2000);

   histo[196] = new TH1D("Nresbbj_pt200", "N resolved bb Jets in H window with pT>200", 15, 0, 15);
   histo[194] = new TH1D("PT_resbbj_pt200", "p_{T} of resolved bb Jets in H window with pT>200", 100, 0, 2000);
   histo[195] = new TH1D("M_resbbj_pt200", "Mass of resolved bb Jets in H window with pT>200", 100, 0, 2000);

   histo[148] = new TH1D("Nresbbj_0fatj", "N resolved bb Jets when NFatJet=0", 15, 0, 15);
   histo[149] = new TH1D("PT_resbbj_0fatj", "p_{T} of resolved bb Jets when NFatJet=0", 100, 0, 2000);
   histo[270] = new TH1D("Nresbbj_0fatj_pT200", "N resolved bb Jets when NFatJet=0 and pT(RbbJ)>200", 15, 0, 15);

   histo[10] = new TH1D("MET", "MET", 100, 0, 2000);
   histo[11] = new TH1D("HT", "HT", 100, 0, 5000);
   histo[12] = new TH1D("MT", "MT", 100, 0, 2000);

   //-------------------------------------------------------------------------
   //Boosted H:
   //1lep + Nj>3 + Nbj>1 evts + met>120 + mt>150 
   histo[45] = new TH1D("MET_5", "MET for 1lep + Nj>3 + Nbj>1 ", 100, 0, 2000);
   histo[46] = new TH1D("MT_5", "MT for 1lep + Nj>3 + Nbj>1 ", 100, 0, 2000);
   histo[47] = new TH1D("Nj_5", "NJets for 1lep + Nj>3 + Nbj>1 ", 20, 0, 20);
   histo[48] = new TH1D("Nbj_5", "NbJets for 1lep + Nj>3 + Nbj>1 ", 10, 0, 10);
   // + NFatJet>0 
   histo[49] = new TH1D("MET_fj_5", "MET for 1lep + Nj>3 + Nbj>1 ", 100, 0, 2000);
   histo[50] = new TH1D("MT_fj_5", "MT for 1lep + Nj>3 + Nbj>1 ", 100, 0, 2000);
   histo[51] = new TH1D("Nj_fj_5", "NJets for 1lep + Nj>3 + Nbj>1 ", 20, 0, 20);
   histo[52] = new TH1D("Nbj_fj_5", "NbJets for 1lep + Nj>3 + Nbj>1 ", 10, 0, 10);

   //1lep + Nj>4 + Nbj>1 evts + met>120 + mt>150
   histo[53] = new TH1D("MET_6", "MET for 1lep + Nj>4 + Nbj>1 ", 100, 0, 2000);
   histo[54] = new TH1D("MT_6", "MT for 1lep + Nj>4 + Nbj>1 ", 100, 0, 2000);
   histo[55] = new TH1D("Nj_6", "NJets for 1lep + Nj>4 + Nbj>1 ", 20, 0, 20);
   histo[56] = new TH1D("Nbj_6", "NbJets for 1lep + Nj>4 + Nbj>1 ", 10, 0, 10);
   // + NFatJet>0 
   histo[57] = new TH1D("MET_fj_6", "MET for 1lep + Nj>4 + Nbj>1 ", 100, 0, 2000);
   histo[58] = new TH1D("MT_fj_6", "MT for 1lep + Nj>4 + Nbj>1 ", 100, 0, 2000);
   histo[59] = new TH1D("Nj_fj_6", "NJets for 1lep + Nj>4 + Nbj>1 ", 20, 0, 20);
   histo[60] = new TH1D("Nbj_fj_6", "NbJets for 1lep + Nj>4 + Nbj>1 ", 10, 0, 10);


   //1lep + Nj>3 + Nbj>2 evts + met>120 + mt>150
   histo[61] = new TH1D("MET_7", "MET for 1lep + Nj>3 + Nbj>2 ", 100, 0, 2000);
   histo[62] = new TH1D("MT_7", "MT for 1lep + Nj>3 + Nbj>2 ", 100, 0, 2000);
   histo[63] = new TH1D("Nj_7", "NJets for 1lep + Nj>3 + Nbj>2 ", 20, 0, 20);
   histo[64] = new TH1D("Nbj_7", "NbJets for 1lep + Nj>3 + Nbj>2 ", 10, 0, 10);
   // + NFatJet>0 
   histo[65] = new TH1D("MET_fj_7", "MET for 1lep + Nj>3 + Nbj>2 ", 100, 0, 2000);
   histo[66] = new TH1D("MT_fj_7", "MT for 1lep + Nj>3 + Nbj>2 ", 100, 0, 2000);
   histo[67] = new TH1D("Nj_fj_7", "NJets for 1lep + Nj>3 + Nbj>2 ", 20, 0, 20);
   histo[68] = new TH1D("Nbj_fj_7", "NbJets for 1lep + Nj>3 + Nbj>2 ", 10, 0, 10);

   //-----------------------------------------------------------------------------
   //1lep + Nj>4 + Nbj>2 evts + met>120 + mt>150
   histo[69] = new TH1D("MET_8", "MET for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[70] = new TH1D("MT_8", "MT for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[71] = new TH1D("Nj_8", "NJets for 1lep + Nj>4 + Nbj>2 ", 20, 0, 20);
   histo[72] = new TH1D("Nbj_8", "NbJets for 1lep + Nj>4 + Nbj>2 ", 10, 0, 10);
   histo[162] = new TH1D("Nfj_8", "NFatJets for 1lep + Nj>4 + Nbj>2 ", 10, 0, 10);
   histo[163] = new TH1D("Nresbbj_8", "NResbbJets for 1lep + Nj>4 + Nbj>2 ", 15, 0, 15);
   histo[164] = new TH1D("PT_fj_8", "p_{T} of FatJets for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[165] = new TH1D("PT_resbbj_8", "p_{T} of ResbbJets for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   // + NFatJet>0 
   histo[73] = new TH1D("MET_fj_8", "MET for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[74] = new TH1D("MT_fj_8", "MT for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[75] = new TH1D("Nj_fj_8", "NJets for 1lep + Nj>4 + Nbj>2 ", 20, 0, 20);
   histo[76] = new TH1D("Nbj_fj_8", "NbJets for 1lep + Nj>4 + Nbj>2 ", 10, 0, 10);
   // + Nresbbjet>0 (when Nfj=0)
   histo[133] = new TH1D("MET_resbbj_8", "MET for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[134] = new TH1D("MT_resbbj_8", "MT for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[135] = new TH1D("Nj_resbbj_8", "NJets for 1lep + Nj>4 + Nbj>2 ", 20, 0, 20);
   histo[136] = new TH1D("Nbj_resbbj_8", "NbJets for 1lep + Nj>4 + Nbj>2 ", 10, 0, 10);
   histo[201] = new TH1D("MET_resbbj_pt200_8", "MET for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[202] = new TH1D("MT_resbbj_pt200_8", "MT for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[203] = new TH1D("Nj_resbbj_pt200_8", "NJets for 1lep + Nj>4 + Nbj>2 ", 20, 0, 20);
   histo[204] = new TH1D("Nbj_resbbj_pt200_8", "NbJets for 1lep + Nj>4 + Nbj>2 ", 10, 0, 10);
   // + NFJ>0 or NFJ=0&NRbbJ>0
   histo[150] = new TH1D("MET_fj_resbbj_8", "MET for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[151] = new TH1D("MT_fj_resbbj_8", "MT for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[152] = new TH1D("Nj_fj_resbbj_8", "NJets for 1lep + Nj>4 + Nbj>2 ", 20, 0, 20);
   histo[153] = new TH1D("Nbj_fj_resbbj_8", "NbJets for 1lep + Nj>4 + Nbj>2 ", 10, 0, 10);
   //NResbbJ>0
   histo[180] = new TH1D("MET_resbbj1_8", "MET for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[181] = new TH1D("MT_resbbj1_8", "MT for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[182] = new TH1D("Nj_resbbj1_8", "NJets for 1lep + Nj>4 + Nbj>2 ", 20, 0, 20);
   histo[183] = new TH1D("Nbj_resbbj1_8", "NbJets for 1lep + Nj>4 + Nbj>2 ", 10, 0, 10);
   histo[197] = new TH1D("MET_resbbj1_pt200_8", "MET for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[198] = new TH1D("MT_resbbj1_pt200_8", "MT for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[199] = new TH1D("Nj_resbbj1_pt200_8", "NJets for 1lep + Nj>4 + Nbj>2 ", 20, 0, 20);
   histo[200] = new TH1D("Nbj_resbbj1_pt200_8", "NbJets for 1lep + Nj>4 + Nbj>2 ", 10, 0, 10);


   //HT>500
   histo[226] = new TH1D("MET_ht_1lmet120mt150NJ4NbJ2", "MET for 1lep + mt>150 + met>120 + Nj>=4 + Nbj>=2 ", 100, 0, 2000);
   histo[228] = new TH1D("MET_ht_1lmet120mt150NJ5NbJ2", "MET for 1lep + mt>150 + met>120 + Nj>=5 + Nbj>=2 ", 100, 0, 2000);
   histo[230] = new TH1D("MET_ht_1lmet120mt150NJ4NbJ3", "MET for 1lep + mt>150 + met>120 + Nj>=4 + Nbj>=3 ", 100, 0, 2000);
   histo[232] = new TH1D("MET_ht_1lmet120mt150NJ5NbJ3", "MET for 1lep + mt>150 + met>120 + Nj>=5 + Nbj>=3 ", 100, 0, 2000);
   histo[267] = new TH1D("MET_ht_1lmet120mt150NJ4NbJ=2", "MET for 1lep + mt>150 + met>120 + Nj>=4 + Nbj=2 ", 100, 0, 2000);
   histo[269] = new TH1D("MET_ht_1lmet120mt150NJ5NbJ=2", "MET for 1lep + mt>150 + met>120 + Nj>=5 + Nbj=2 ", 100, 0, 2000);

   histo[283] = new TH1D("MT_ht_1lmet120mt150NJ5NbJ2", "MT for 1lep + mt>150 + met>120 + Nj>=5 + Nbj>=2 ", 100, 0, 2000);
   histo[284] = new TH1D("MT_ht_1lmet120mt150NJ5NbJ3", "MT for 1lep + mt>150 + met>120 + Nj>=5 + Nbj>=3 ", 100, 0, 2000);
   histo[285] = new TH1D("HT_ht_1lmet120mt150NJ5NbJ2", "HT for 1lep + mt>150 + met>120 + Nj>=5 + Nbj>=2 ", 100, 0, 5000);
   histo[286] = new TH1D("HT_ht_1lmet120mt150NJ5NbJ3", "HT for 1lep + mt>150 + met>120 + Nj>=5 + Nbj>=3 ", 100, 0, 5000);
   histo[287] = new TH1D("Nj_ht_1lmet120mt150NJ5NbJ2", "NJets for 1lep + mt>150 + met>120 + Nj>=5 + Nbj>=2 ", 20, 0, 20);
   histo[288] = new TH1D("Nj_ht_1lmet120mt150NJ5NbJ3", "NJets for 1lep + mt>150 + met>120 + Nj>=5 + Nbj>=3 ", 20, 0, 20);
   histo[289] = new TH1D("Nbj_ht_1lmet120mt150NJ5NbJ2", "NbJets for 1lep + mt>150 + met>120 + Nj>=5 + Nbj>=2 ", 10, 0, 10);
   histo[290] = new TH1D("Nbj_ht_1lmet120mt150NJ5NbJ3", "NbJets for 1lep + mt>150 + met>120 + Nj>=5 + Nbj>=3 ", 10, 0, 10);

   histo[291] = new TH1D("PT_H1_1lmet120mt150ht500NJ5NbJ2", "PT of Higgs after BS NbJ>=2", 100, 0, 2000);
   histo[80] = new TH1D("PT_H2_1lmet120mt150ht500NJ5NbJ2", "PT of Higgs after BS NbJ>=2", 100, 0, 2000);
   histo[292] = new TH1D("PT_H1_1lmet120mt150ht500NJ5NbJ3", "PT of Higgs after BS NbJ>=3", 100, 0, 2000);
   histo[86] = new TH1D("PT_H2_1lmet120mt150ht500NJ5NbJ3", "PT of Higgs after BS NbJ>=3", 100, 0, 2000);


   // + NRbbJ>0 or NFJ>0 or NFJ0=+NRbbJ>0
   histo[249] = new TH1D("MET_ht_1lmet120mt150NJ4NbJ2NRbbJ1", "MET for 1lep + mt>150 + met>120 + Nj>=4 + Nbj=2 + NRbbJ>0", 100, 0, 2000);
   histo[250] = new TH1D("MET_ht_1lmet120mt150NJ4NbJ2NRbbJ1pt200", "MET for 1lep + mt>150 + met>120 + Nj>=4 + Nbj=2 + NRbbJ>0 with pt>200", 100, 0, 2000);
   histo[251] = new TH1D("MET_ht_1lmet120mt150NJ4NbJ2NFJ1", "MET for 1lep + mt>150 + met>120 + Nj>=4 + Nbj=2 + NFJ>0", 100, 0, 2000);
   histo[252] = new TH1D("MET_ht_1lmet120mt150NJ4NbJ2NFJ0NRbbJ1", "MET for 1lep + mt>150 + met>120 + Nj>=4 + Nbj=2 + NFJ=0 + NRbbJ>0", 100, 0, 2000);

   histo[253] = new TH1D("MET_ht_1lmet120mt150NJ5NbJ2NRbbJ1", "MET for 1lep + mt>150 + met>120 + Nj>=5 + Nbj=2 + NRbbJ>0", 100, 0, 2000);
   histo[254] = new TH1D("MET_ht_1lmet120mt150NJ5NbJ2NRbbJ1pt200", "MET for 1lep + mt>150 + met>120 + Nj>=5 + Nbj=2 + NRbbJ>0 with pt>200", 100, 0, 2000);
   histo[255] = new TH1D("MET_ht_1lmet120mt150NJ5NbJ2NFJ1", "MET for 1lep + mt>150 + met>120 + Nj>=5 + Nbj=2 + NFJ>0", 100, 0, 2000);
   histo[256] = new TH1D("MET_ht_1lmet120mt150NJ5NbJ2NFJ0NRbbJ1", "MET for 1lep + mt>150 + met>120 + Nj>=5 + Nbj=2 + NFJ=0 + NRbbJ>0", 100, 0, 2000);
   histo[272] = new TH1D("MET_ht_1lmet120mt150NJ5NbJ2NFJ0NRbbJ1pt200", "MET for 1lep + mt>150 + met>120 + Nj>=5 + Nbj=2 + NFJ=0 + NRbbJ>0 with pT>200", 100, 0, 2000);

   histo[257] = new TH1D("MET_ht_1lmet120mt150NJ4NbJ3NRbbJ1", "MET for 1lep + mt>150 + met>120 + Nj>=4 + Nbj>=3 + NRbbJ>0", 100, 0, 2000);
   histo[258] = new TH1D("MET_ht_1lmet120mt150NJ4NbJ3NRbbJ1pt200", "MET for 1lep + mt>150 + met>120 + Nj>=4 + Nbj>=3 + NRbbJ>0 with pt>200", 100, 0, 2000);
   histo[259] = new TH1D("MET_ht_1lmet120mt150NJ4NbJ3NFJ1", "MET for 1lep + mt>150 + met>120 + Nj>=4 + Nbj>=3 + NFJ>0", 100, 0, 2000);
   histo[260] = new TH1D("MET_ht_1lmet120mt150NJ4NbJ3NFJ0NRbbJ1", "MET for 1lep + mt>150 + met>120 + Nj>=4 + Nbj>=3 + NFJ=0 + NRbbJ>0", 100, 0, 2000);

   histo[261] = new TH1D("MET_ht_1lmet120mt150NJ5NbJ3NRbbJ1", "MET for 1lep + mt>150 + met>120 + Nj>=5 + Nbj>=3 + NRbbJ>0", 100, 0, 2000);
   histo[262] = new TH1D("MET_ht_1lmet120mt150NJ5NbJ3NRbbJ1pt200", "MET for 1lep + mt>150 + met>120 + Nj>=5 + Nbj>=3 + NRbbJ>0 with pt>200", 100, 0, 2000);
   histo[263] = new TH1D("MET_ht_1lmet120mt150NJ5NbJ3NFJ1", "MET for 1lep + mt>150 + met>120 + Nj>=5 + Nbj>=3 + NFJ>0", 100, 0, 2000);
   histo[264] = new TH1D("MET_ht_1lmet120mt150NJ5NbJ3NFJ0NRbbJ1", "MET for 1lep + mt>150 + met>120 + Nj>=5 + Nbj>=3 + NFJ=0 + NRbbJ>0", 100, 0, 2000);
   histo[271] = new TH1D("MET_ht_1lmet120mt150NJ5NbJ3NFJ0NRbbJ1pt200", "MET for 1lep + mt>150 + met>120 + Nj>=5 + Nbj>=3 + NFJ=0 + NRbbJ>0 with pT>200", 100, 0, 2000);

   histo[293] = new TH1D("PT_H1_1lmet120mt150ht500NJ5NbJ2NRbbJ1 ", "PT of Higgs after BS NbJ>=2 + NRbbJ>0", 100, 0, 2000);
   histo[81] = new TH1D("PT_H2_1lmet120mt150ht500NJ5NbJ2NRbbJ1 ", "PT of Higgs after BS NbJ>=2 + NRbbJ>0", 100, 0, 2000);
   histo[13] = new TH1D("MT_1lmet120mt150ht500NJ5NbJ2NRbbJ1", "MT after BS Nbj>=2 + NRbbJ>0", 100, 0, 2000);
   histo[28] = new TH1D("HT_1lmet120mt150ht500NJ5NbJ2NRbbJ1", "HT after BS Nbj>=2 + NRbbJ>0", 100, 0, 5000);
   histo[14] = new TH1D("Nj_1lmet120mt150ht500NJ5NbJ2NRbbJ1", "NJets after BS Nbj>=2 + NRbbJ>0", 20, 0, 20);
   histo[15] = new TH1D("Nbj_1lmet120mt150ht500NJ5NbJ2NRbbJ1", "NbJets after BS Nbj>=2 + NRbbJ>0", 10, 0, 10);

   histo[294] = new TH1D("PT_H1_1lmet120mt150ht500NJ5NbJ2NRbbJ1pt200 ", "PT of Higgs after BS NbJ>=2 + NRbbJ>0 with pt>200", 100, 0, 2000);
   histo[82] = new TH1D("PT_H2_1lmet120mt150ht500NJ5NbJ2NRbbJ1pt200 ", "PT of Higgs after BS NbJ>=2 + NRbbJ>0 with pt>200", 100, 0, 2000);
   histo[16] = new TH1D("MT_1lmet120mt150ht500NJ5NbJ2NRbbJ1pt200", "MT after BS Nbj>=2 + NRbbJ>0 with pt>200", 100, 0, 2000);
   histo[29] = new TH1D("HT_1lmet120mt150ht500NJ5NbJ2NRbbJ1pt200", "HT after BS Nbj>=2 + NRbbJ>0 with pt>200", 100, 0, 5000);
   histo[17] = new TH1D("Nj_1lmet120mt150ht500NJ5NbJ2NRbbJ1pt200", "NJets after BS Nbj>=2 + NRbbJ>0 with pt>200", 20, 0, 20);
   histo[18] = new TH1D("Nbj_1lmet120mt150ht500NJ5NbJ2NRbbJ1pt200", "NbJets after BS Nbj>=2 + NRbbJ>0 with pt>200", 10, 0, 10);

   histo[295] = new TH1D("PT_H1_1lmet120mt150ht500NJ5NbJ2NFJ1 ", "PT of Higgs after BS NbJ>=2 + NFJ>0", 100, 0, 2000);
   histo[83] = new TH1D("PT_H2_1lmet120mt150ht500NJ5NbJ2NFJ1 ", "PT of Higgs after BS NbJ>=2 + NFJ>0", 100, 0, 2000);
   histo[19] = new TH1D("MT_1lmet120mt150ht500NJ5NbJ2NFJ1", "MT after BS Nbj>=2 + NFJ>0", 100, 0, 2000);
   histo[30] = new TH1D("HT_1lmet120mt150ht500NJ5NbJ2NFJ1", "HT after BS Nbj>=2 + NFJ>0", 100, 0, 5000);
   histo[20] = new TH1D("Nj_1lmet120mt150ht500NJ5NbJ2NFJ1", "NJets after BS Nbj>=2 + NFJ>0", 20, 0, 20);
   histo[21] = new TH1D("Nbj_1lmet120mt150ht500NJ5NbJ2NFJ1", "NbJets after BS Nbj>=2 + NFJ>0", 10, 0, 10);

   histo[296] = new TH1D("PT_H1_1lmet120mt150ht500NJ5NbJ2NFJ0NRbbJ1 ", "PT of Higgs after BS NbJ>=2 + NFJ=0 + NRbbJ>0", 100, 0, 2000);
   histo[84] = new TH1D("PT_H2_1lmet120mt150ht500NJ5NbJ2NFJ0NRbbJ1 ", "PT of Higgs after BS NbJ>=2 + NFJ=0 + NRbbJ>0", 100, 0, 2000);
   histo[22] = new TH1D("MT_1lmet120mt150ht500NJ5NbJ2NFJ0NRbbJ1", "MT after BS Nbj>=2 + NFJ=0 + NRbbJ>0", 100, 0, 2000);
   histo[31] = new TH1D("HT_1lmet120mt150ht500NJ5NbJ2NFJ0NRbbJ1", "HT after BS Nbj>=2 + NFJ=0 + NRbbJ>0", 100, 0, 5000);
   histo[23] = new TH1D("Nj_1lmet120mt150ht500NJ5NbJ2NFJ0NRbbJ1", "NJets after BS Nbj>=2 + NFJ=0 + NRbbJ>0", 20, 0, 20);
   histo[24] = new TH1D("Nbj_1lmet120mt150ht500NJ5NbJ2NFJ0NRbbJ1", "NbJets after BS Nbj>=2 + NFJ=0 + NRbbJ>0", 10, 0, 10);

   histo[297] = new TH1D("PT_H1_1lmet120mt150ht500NJ5NbJ2NFJ0NRbbJ1pt200 ", "PT of Higgs after BS NbJ>=2 + NFJ=0 + NRbbJ>0 with pT>200", 100, 0, 2000);
   histo[85] = new TH1D("PT_H2_1lmet120mt150ht500NJ5NbJ2NFJ0NRbbJ1pt200 ", "PT of Higgs after BS NbJ>=2 + NFJ=0 + NRbbJ>0 with pT>200", 100, 0, 2000);
   histo[25] = new TH1D("MT_1lmet120mt150ht500NJ5NbJ2NFJ0NRbbJ1pt200", "MT after BS Nbj>=2 + NFJ=0 + NRbbJ>0 with pT>200", 100, 0, 2000);
   histo[32] = new TH1D("HT_1lmet120mt150ht500NJ5NbJ2NFJ0NRbbJ1pt200", "HT after BS Nbj>=2 + NFJ=0 + NRbbJ>0 with pT>200", 100, 0, 5000);
   histo[26] = new TH1D("Nj_1lmet120mt150ht500NJ5NbJ2NFJ0NRbbJ1pt200", "NJets after BS Nbj>=2 + NFJ=0 + NRbbJ>0 with pT>200", 20, 0, 20);
   histo[27] = new TH1D("Nbj_1lmet120mt150ht500NJ5NbJ2NFJ0NRbbJ1pt200", "NbJets after BS Nbj>=2 + NFJ=0 + NRbbJ>0 with pT>200", 10, 0, 10);


   histo[298] = new TH1D("PT_H1_1lmet120mt150ht500NJ5NbJ3NRbbJ1 ", "PT of Higgs after BS NbJ>=3 + NRbbJ>0", 100, 0, 2000);
   histo[87] = new TH1D("PT_H2_1lmet120mt150ht500NJ5NbJ3NRbbJ1 ", "PT of Higgs after BS NbJ>=3 + NRbbJ>0", 100, 0, 2000);
   histo[299] = new TH1D("PT_H1_1lmet120mt150ht500NJ5NbJ3NRbbJ1pt200 ", "PT of Higgs after BS NbJ>=3 + NRbbJ>0 with pt>200", 100, 0, 2000);
   histo[88] = new TH1D("PT_H2_1lmet120mt150ht500NJ5NbJ3NRbbJ1pt200 ", "PT of Higgs after BS NbJ>=3 + NRbbJ>0 with pt>200", 100, 0, 2000);
   histo[77] = new TH1D("PT_H1_1lmet120mt150ht500NJ5NbJ3NFJ1 ", "PT of Higgs after BS NbJ>=3 + NFJ>0", 100, 0, 2000);
   histo[89] = new TH1D("PT_H2_1lmet120mt150ht500NJ5NbJ3NFJ1 ", "PT of Higgs after BS NbJ>=3 + NFJ>0", 100, 0, 2000);
   histo[78] = new TH1D("PT_H1_1lmet120mt150ht500NJ5NbJ3NFJ0NRbbJ1 ", "PT of Higgs after BS NbJ>=3 + NFJ=0 + NRbbJ>0", 100, 0, 2000);
   histo[90] = new TH1D("PT_H2_1lmet120mt150ht500NJ5NbJ3NFJ0NRbbJ1 ", "PT of Higgs after BS NbJ>=3 + NFJ=0 + NRbbJ>0", 100, 0, 2000);
   histo[79] = new TH1D("PT_H1_1lmet120mt150ht500NJ5NbJ3NFJ0NRbbJ1pt200 ", "PT of Higgs after BS NbJ>=3 + NFJ=0 + NRbbJ>0 with pT>200", 100, 0, 2000);
   histo[91] = new TH1D("PT_H2_1lmet120mt150ht500NJ5NbJ3NFJ0NRbbJ1pt200 ", "PT of Higgs after BS NbJ>=3 + NFJ=0 + NRbbJ>0 with pT>200", 100, 0, 2000);

   //
   histo[273] = new TH1D("NFJ_BS_NbJ3", "NFatJets for 1lep + mt>150 + met>120 + HT>500 + Nj>=5 + Nbj>=3", 10, 0, 10);
   histo[274] = new TH1D("NFJ_BS_NbJ2", "NFatJets for 1lep + mt>150 + met>120 + HT>500 + Nj>=5 + Nbj=2", 10, 0, 10);
   histo[275] = new TH1D("NRbbJ_BS_NbJ3", "NRbbJets for 1lep + mt>150 + met>120 + HT>500 + Nj>=5 + Nbj>=3", 20, 0, 20);
   histo[276] = new TH1D("NRbbJ_BS_NbJ2", "NRbbJets for 1lep + mt>150 + met>120 + HT>500 + Nj>=5 + Nbj=2", 20, 0, 20);
   histo[277] = new TH1D("NRbbJpt200_BS_NbJ3", "NRbbJets (pt200) for 1lep + mt>150 + met>120 + HT>500 + Nj>=5 + Nbj>=3", 20, 0, 20);
   histo[278] = new TH1D("NRbbJpt200_BS_NbJ2", "NRbbJets (pt200) for 1lep + mt>150 + met>120 + HT>500 + Nj>=5 + Nbj=2", 20, 0, 20);
   histo[279] = new TH1D("NRbbJ_NFJ0_BS_NbJ3", "NRbbJets (NFJ0) for 1lep + mt>150 + met>120 + HT>500 + Nj>=5 + Nbj>=3", 20, 0, 20);
   histo[280] = new TH1D("NRbbJ_NFJ0_BS_NbJ2", "NRbbJets (NFJ0) for 1lep + mt>150 + met>120 + HT>500 + Nj>=5 + Nbj=2", 20, 0, 20);
   histo[281] = new TH1D("NRbbJpt200_NFJ0_BS_NbJ3", "NRbbJets (pt200) (NFJ0) for 1lep + mt>150 + met>120 + HT>500 + Nj>=5 + Nbj>=3", 20, 0, 20);
   histo[282] = new TH1D("NRbbJpt200_NFJ0_BS_NbJ2", "NRbbJets (pt200) (NFJ0) for 1lep + mt>150 + met>120 + HT>500 + Nj>=5 + Nbj=2", 20, 0, 20);


   //0Hbb 
   histo[33] = new TH1D("MET_1lmet120ht500mt150NJ5NbJ2NRbbJ_0", "MET for 1lep + mt>150 + met>120 + ht>500 + Nj>=5 + Nbj=2 + NRbbJ=0", 100, 0, 2000);
   histo[34] = new TH1D("MET_1lmet120ht500mt150NJ5NbJ3NRbbJ_0", "MET for 1lep + mt>150 + met>120 + ht>500 + Nj>=5 + Nbj>=3 + NRbbJ=0", 100, 0, 2000);

   //1Hbb
   histo[35] = new TH1D("MET_1lmet120ht500mt150NJ5NbJ2NRbbJ_1", "MET for 1lep + mt>150 + met>120 + ht>500 + Nj>=5 + Nbj=2 + NRbbJ=1", 100, 0, 2000);
   histo[36] = new TH1D("MET_1lmet120ht500mt150NJ5NbJ3NRbbJ_1", "MET for 1lep + mt>150 + met>120 + ht>500 + Nj>=5 + Nbj>=3 + NRbbJ=1", 100, 0, 2000);
   histo[37] = new TH1D("MET_1lmet120ht500mt150NJ5NbJ2NRbbJpt200_1", "MET for 1lep + mt>150 + met>120 + ht>500 + Nj>=5 + Nbj=2 + NRbbJ=1 with pT>200", 100, 0, 2000);
   histo[38] = new TH1D("MET_1lmet120ht500mt150NJ5NbJ3NRbbJpt200_1", "MET for 1lep + mt>150 + met>120 + ht>500 + Nj>=5 + Nbj>=3 + NRbbJ=1 with pT>200", 100, 0, 2000);


   //>=2Hbb
   histo[39] = new TH1D("MET_1lmet120ht500mt150NJ5NbJ2NRbbJ_2", "MET for 1lep + mt>150 + met>120 + ht>500 + Nj>=5 + Nbj=2 + NRbbJ>=2", 100, 0, 2000);
   histo[40] = new TH1D("MET_1lmet120ht500mt150NJ5NbJ3NRbbJ_2", "MET for 1lep + mt>150 + met>120 + ht>500 + Nj>=5 + Nbj>=3 + NRbbJ>=2", 100, 0, 2000);
   histo[41] = new TH1D("MET_1lmet120ht500mt150NJ5NbJ2NRbbJpt200_2", "MET for 1lep + mt>150 + met>120 + ht>500 + Nj>=5 + Nbj=2 + NRbbJ>=2 with pT>200", 100, 0, 2000);
   histo[42] = new TH1D("MET_1lmet120ht500mt150NJ5NbJ3NRbbJpt200_2", "MET for 1lep + mt>150 + met>120 + ht>500 + Nj>=5 + Nbj>=3 + NRbbJ>=2 with pT>200", 100, 0, 2000);


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

      reco_leps.clear();
      reco_jets.clear();
      reco_bjets.clear();
      reco_fatjets.clear();
      reco_fatjetsmatch.clear();
      reco_resbbjets.clear();
      diffMass.clear();
      Higgs.clear();

//-------------------------------------------

  //mycode

  float weight = (364.36*150*1000)/(2000000);


  //Particles
  int NPar=Particle_size;
  for(int i=0; i<NPar; i++){
    //H
    if(abs(Particle_PID[i])==25 && Particle_PID[Particle_M1[i]]!=25) {
      //histo[174]->Fill(Particle_PT[i], weight);
      Part par; par.v.SetPtEtaPhiM(Particle_PT[i], Particle_Eta[i], Particle_Phi[i], Particle_Mass[i]);
      par.id=Particle_PID[i]; par.ind=i; par.Charge=Particle_Charge[i]; 
      Higgs.push_back(par);
    }
  }

  if(Higgs.size()>0){
    histo[174]->Fill(Higgs.at(0).v.Pt(), weight);
  }
  if(Higgs.size()>1){
    histo[43]->Fill(Higgs.at(1).v.Pt(), weight);
  }

  //MET HT
  histo[10]->Fill(MissingET_MET[0], weight);
  histo[11]->Fill(ScalarHT_HT[0], weight);


  //Leptons
  int Nl = Electron_size + Muon_size; int Nleps=0;
  if(Nl>0){
    for(int a=0; a<Electron_size; a++){
      if(Electron_PT[a]>=20 && fabs(Electron_Eta[a])<=2.5){
        Part elec; elec.v.SetPtEtaPhiM(Electron_PT[a], Electron_Eta[a], Electron_Phi[a], 0.000511);
        reco_leps.push_back(elec);
        histo[5]->Fill(elec.v.Pt(), weight);
        Nleps=Nleps+1;
      }
    }
    for(int b=0; b<Muon_size; b++){
      if(Muon_PT[b]>=20 && fabs(Muon_Eta[b])<=2.4){
        Part muon; muon.v.SetPtEtaPhiM(Muon_PT[b], Muon_Eta[b], Muon_Phi[b], 0.105658);
        reco_leps.push_back(muon);
        histo[5]->Fill(Muon_PT[b], weight);
        Nleps=Nleps+1;
      }
    }
    histo[4]->Fill(reco_leps.size(), weight);
  }

  //mt
  float mt_;
  for(int k=0; k<reco_leps.size(); k++){
    float dp_lmet = fabs(MissingET_Phi[0] - reco_leps.at(k).v.Phi());
    if(dp_lmet>TMath::Pi()) {dp_lmet = 2*TMath::Pi() - dp_lmet;}
    float mt_ = sqrt(2*reco_leps.at(k).v.Pt()*MissingET_MET[0]*(1-TMath::Cos(dp_lmet)));
    histo[12]->Fill(mt_, weight);
  }

  //Jets
  int Njets = Jet_size; int Nbjets=0;
  for(int i=0; i<Njets; i++){
    Part jet; jet.v.SetPtEtaPhiM(Jet_PT[i], Jet_Eta[i], Jet_Phi[i], Jet_Mass[i]);
    if(jet.v.Pt()>=30 && fabs(jet.v.Eta())<2.4){
      reco_jets.push_back(jet);
      histo[2]->Fill(jet.v.Pt(), weight);
      if(Jet_BTag[i]==1){
        Nbjets=Nbjets+1;
        Part jet1; jet1.v.SetPtEtaPhiM(Jet_PT[i], Jet_Eta[i], Jet_Phi[i], Jet_Mass[i]);
        if(jet1.v.Pt()>=30 && fabs(jet1.v.Eta())<2.4){
          reco_bjets.push_back(jet1);
          histo[3]->Fill(jet1.v.Pt(), weight);
        }
      }
    }
  }
  histo[0]->Fill(reco_jets.size(), weight);
  histo[1]->Fill(reco_bjets.size(), weight);


  //Fat jets (AK8) and pT>300
  for(int q=0; q<FatJet_size; q++){
    histo[175]->Fill(FatJet_PT[q], weight);
    histo[176]->Fill(FatJet_Mass[q], weight);
    if(FatJet_PT[q]>300 && fabs(FatJet_Eta[q])<2.4 && FatJet_Mass[q]<150 && FatJet_Mass[q]>100){
      Part jet2; jet2.v.SetPtEtaPhiM(FatJet_PT[q], FatJet_Eta[q], FatJet_Phi[q], FatJet_Mass[q]);
      reco_fatjets.push_back(jet2);
      histo[7]->Fill(FatJet_PT[q] ,weight);

      float tau21 = FatJet_Tau[q][1]/FatJet_Tau[q][0];
      float tau32 = FatJet_Tau[q][2]/FatJet_Tau[q][1];
      histo[8]->Fill(tau21 ,weight);
      histo[9]->Fill(tau32 ,weight);

      //check if FJ matched with atleast 1 b-jet
      int Nfjmatch=0;
      if(reco_bjets.size()>0){
        for(int i=0; i<reco_bjets.size(); i++){
          float dPhi = fabs(reco_bjets.at(i).v.Phi() - FatJet_Phi[q]);
          if(dPhi>TMath::Pi()) {dPhi = 2*TMath::Pi() - dPhi;}
          float dEta = fabs(reco_bjets.at(i).v.Eta() - FatJet_Eta[q]);
          float dR = sqrt(pow(dPhi,2) + pow(dEta,2));
          if(dR<0.8){
            Nfjmatch = Nfjmatch + 1;
          }
        }
      }
      if(Nfjmatch>0){
        reco_fatjetsmatch.push_back(jet2);
      }
    }
  }
  histo[6]->Fill(reco_fatjets.size() ,weight);
  histo[265]->Fill(reco_fatjetsmatch.size() ,weight);
  histo[192]->Fill(FatJet_size, weight);
  //look for invM(bjets) from bjet combinations
  int N_cand_RbbJ=0; int N_RbbJ_pt200=0;
  if(reco_bjets.size()>1){
    for(int i=0; i<reco_bjets.size(); i++){
      for(int j=i+1; j<reco_bjets.size(); j++){
        float invM = (reco_bjets.at(i).v + reco_bjets.at(j).v).M();
        histo[178]->Fill(invM, weight);
        float bb_pt = (reco_bjets.at(i).v + reco_bjets.at(j).v).Pt();
        histo[177]->Fill(bb_pt, weight);
        N_cand_RbbJ = N_cand_RbbJ + 1;
        if(invM>100 && invM<150){
          float bb_PT = (reco_bjets.at(i).v + reco_bjets.at(j).v).Pt();
          float bb_Eta = (reco_bjets.at(i).v + reco_bjets.at(j).v).Eta();
          float bb_Phi = (reco_bjets.at(i).v + reco_bjets.at(j).v).Phi();
          Part res_bb_jet; res_bb_jet.v.SetPtEtaPhiM(bb_PT, bb_Eta, bb_Phi, invM);
          reco_resbbjets.push_back(res_bb_jet);
          histo[146]->Fill(bb_PT, weight);
          histo[179]->Fill(invM, weight);
          if(bb_PT>200){
            histo[194]->Fill(bb_PT, weight);
            histo[195]->Fill(invM, weight);
            N_RbbJ_pt200 = N_RbbJ_pt200 + 1;
          }
        }
      }
    }
    histo[145]->Fill(reco_resbbjets.size(), weight);
    histo[193]->Fill(N_cand_RbbJ, weight);
    histo[196]->Fill(N_RbbJ_pt200, weight);
    if(reco_resbbjets.size()==1){
      histo[147]->Fill(reco_resbbjets.at(0).v.Pt(), weight);
    }
    //choose bbjet closest to H mass
    if(reco_resbbjets.size()>1){
      for(int k=0; k<reco_resbbjets.size(); k++){
        float diffM = fabs(reco_resbbjets.at(k).v.M() - 125.0);
        diffMass.push_back(diffM);
      }
      //find min of this array
      float min_diffM = diffMass.at(0); int index=0;
      for(int l=1; l<diffMass.size(); l++){
        if(diffMass.at(l)<min_diffM){
          min_diffM = diffMass.at(l);
          index = l;
        }
      }
      //Thus, reco_resbbjets.at(index) is the resolved jet with invM closest to H mass 
      histo[147]->Fill(reco_resbbjets.at(index).v.Pt(), weight);

    }//resjet>1

    //No Fat Jet in evt
    if(reco_fatjetsmatch.size()==0 && reco_resbbjets.size()>0){
      histo[148]->Fill(reco_resbbjets.size(), weight);
      int NRbbJ_pt200=0;
      for(int h=0; h<reco_resbbjets.size(); h++){
        histo[149]->Fill(reco_resbbjets.at(h).v.Pt(), weight);
        if(reco_resbbjets.at(h).v.Pt() > 200){
          NRbbJ_pt200 = NRbbJ_pt200+1;
        }
      }
      histo[270]->Fill(NRbbJ_pt200, weight);
    }//

  }

//------------------------------------------------------------------------------------

  //check min dPhi(J12, met)>0.8
  if(reco_jets.size()>1){
    float dPhi1 = fabs(reco_jets.at(0).v.Phi() - MissingET_Phi[0]);
    if(dPhi1>TMath::Pi()) {dPhi1 = 2*TMath::Pi() - dPhi1;}
    float dPhi2 = fabs(reco_jets.at(1).v.Phi() - MissingET_Phi[0]);
    if(dPhi2>TMath::Pi()) {dPhi2 = 2*TMath::Pi() - dPhi2;}
    if(dPhi1>0.8 && dPhi2 >0.8){
      //


  //--------------------------------******---------------------------//
  //Event Selection: 1lep + Nj>3 + Nbj>1 + met>120 + mt>100
  if(reco_leps.size()==1 && reco_jets.size()>3 && reco_bjets.size()>1 && MissingET_MET[0]>120){

    //mt
    float dP_lmet = fabs(MissingET_Phi[0] - reco_leps.at(0).v.Phi());
    if(dP_lmet>TMath::Pi()) {dP_lmet = 2*TMath::Pi() - dP_lmet;}
    float mt = sqrt(2*reco_leps.at(0).v.Pt()*MissingET_MET[0]*(1-TMath::Cos(dP_lmet)));


      //Boosted H
      if(mt>150){
        histo[45]->Fill(MissingET_MET[0], weight);
        histo[46]->Fill(mt, weight);
        histo[47]->Fill(reco_jets.size(), weight);
        histo[48]->Fill(reco_bjets.size(), weight);
        //ht>500
        if(ScalarHT_HT[0]>500){
          histo[226]->Fill(MissingET_MET[0], weight);

          if(reco_bjets.size()==2){
            histo[267]->Fill(MissingET_MET[0], weight);



          }
          if(reco_resbbjets.size()>0 && reco_bjets.size()==2){
            histo[249]->Fill(MissingET_MET[0], weight);
            for(int s=0; s<reco_resbbjets.size(); s++){
              if(reco_resbbjets.at(s).v.Pt()>200){
                histo[250]->Fill(MissingET_MET[0], weight);
              }
            }
          }
        }
        if(reco_fatjetsmatch.size()>0){
          histo[49]->Fill(MissingET_MET[0], weight);
          histo[50]->Fill(mt, weight);
          histo[51]->Fill(reco_jets.size(), weight);
          histo[52]->Fill(reco_bjets.size(), weight);
          if(ScalarHT_HT[0]>500 && reco_bjets.size()==2){
            histo[251]->Fill(MissingET_MET[0], weight);
          }
        }
        if(reco_fatjetsmatch.size()==0 && reco_resbbjets.size()>0 && ScalarHT_HT[0]>500 && reco_bjets.size()==2){
          histo[252]->Fill(MissingET_MET[0], weight);
        }





        //NJ5
        if(reco_jets.size()>4){
          histo[53]->Fill(MissingET_MET[0], weight);
          histo[54]->Fill(mt, weight);
          histo[55]->Fill(reco_jets.size(), weight);
          histo[56]->Fill(reco_bjets.size(), weight);
          if(ScalarHT_HT[0]>500){
            histo[228]->Fill(MissingET_MET[0], weight);
            histo[283]->Fill(mt, weight);
            histo[285]->Fill(ScalarHT_HT[0], weight);
            histo[287]->Fill(reco_jets.size(), weight);
            histo[289]->Fill(reco_bjets.size(), weight);
            if(Higgs.size()>0){
              float ptH = Higgs.at(0).v.Pt();
              histo[291]->Fill(ptH, weight);
            }
            if(Higgs.size()>1){
              float ptH1 = Higgs.at(1).v.Pt();
              histo[80]->Fill(ptH1, weight);
            }            
            if(reco_bjets.size()==2){
              histo[269]->Fill(MissingET_MET[0], weight);
              if(reco_fatjetsmatch.size()>0){
                histo[274]->Fill(reco_fatjetsmatch.size(), weight);
              }
              if(reco_resbbjets.size()>0){
                histo[276]->Fill(reco_resbbjets.size(), weight);
                int NRRbbJ200=0;
                for(int h=0; h<reco_resbbjets.size(); h++){
                  if(reco_resbbjets.at(h).v.Pt()>200){
                    NRRbbJ200=NRRbbJ200+1;
                  }
                }
                if(NRRbbJ200>0){
                  histo[278]->Fill(reco_resbbjets.size(), weight);
                  if(reco_fatjetsmatch.size()==0){
                    histo[282]->Fill(reco_resbbjets.size(), weight);
                  }
                }
                if(reco_fatjetsmatch.size()==0){
                  histo[280]->Fill(reco_resbbjets.size(), weight);
                }
              }
            }//NbJ=2
            if(reco_resbbjets.size()>0){
              if(Higgs.size()>0){
                histo[293]->Fill(Higgs.at(0).v.Pt(), weight);
                histo[13]->Fill(mt, weight);
                histo[28]->Fill(ScalarHT_HT[0], weight);
                histo[14]->Fill(reco_jets.size(), weight);
                histo[15]->Fill(reco_bjets.size(), weight);
              }
              if(Higgs.size()>1){
                histo[81]->Fill(Higgs.at(1).v.Pt(), weight);
              }
              if(reco_bjets.size()==2){
                histo[253]->Fill(MissingET_MET[0], weight);
              }

              for(int s=0; s<reco_resbbjets.size(); s++){
                if(reco_resbbjets.at(s).v.Pt()>200){
                  if(reco_bjets.size()==2){
                    histo[254]->Fill(MissingET_MET[0], weight);
                  }
                  if(Higgs.size()>0){
                    histo[294]->Fill(Higgs.at(0).v.Pt(), weight);
                    histo[16]->Fill(mt, weight);
                    histo[29]->Fill(ScalarHT_HT[0], weight);
                    histo[17]->Fill(reco_jets.size(), weight);
                    histo[18]->Fill(reco_bjets.size(), weight);
                  }
                  if(Higgs.size()>1){
                    histo[82]->Fill(Higgs.at(1).v.Pt(), weight);
                  }
                }
              }
            }//
            //0Hbb
            if(reco_resbbjets.size()==0){
              if(reco_bjets.size()==2){
                histo[33]->Fill(MissingET_MET[0], weight);
              }    
              if(reco_bjets.size()>2){
                histo[34]->Fill(MissingET_MET[0], weight);
              }    
            }//0Hbb
            //1Hbb
            if(reco_resbbjets.size()==1){
              if(reco_bjets.size()==2){
                histo[35]->Fill(MissingET_MET[0], weight);
              }    
              if(reco_bjets.size()>2){
                histo[36]->Fill(MissingET_MET[0], weight);
              } 
              //pt200
              if(reco_resbbjets.at(0).v.Pt()>200){
                if(reco_bjets.size()==2){
                  histo[37]->Fill(MissingET_MET[0], weight);
                }    
                if(reco_bjets.size()>2){
                  histo[38]->Fill(MissingET_MET[0], weight);
                } 
              }
            }//1Hbb
            //>=2Hbb
            if(reco_resbbjets.size()>1){
              if(reco_bjets.size()==2){
                histo[39]->Fill(MissingET_MET[0], weight);
              }    
              if(reco_bjets.size()>2){
                histo[40]->Fill(MissingET_MET[0], weight);
              } 
              //pt200
              int pt200N=0;
              for(int j=0; j<reco_resbbjets.size(); j++){
                if(reco_resbbjets.at(j).v.Pt()>200){
                  pt200N=pt200N+1;
                }
              }
              if(pt200N>1 && reco_bjets.size()==2){
                histo[41]->Fill(MissingET_MET[0], weight);
              }
              if(pt200N>1 && reco_bjets.size()>2){
                histo[42]->Fill(MissingET_MET[0], weight);
              }
            }//>=2Hbb

          }//ht500
          if(reco_fatjetsmatch.size()>0){
            histo[57]->Fill(MissingET_MET[0], weight);
            histo[58]->Fill(mt, weight);
            histo[59]->Fill(reco_jets.size(), weight);
            histo[60]->Fill(reco_bjets.size(), weight);
            if(ScalarHT_HT[0]>500){
              if(Higgs.size()>0){
                histo[295]->Fill(Higgs.at(0).v.Pt(), weight);
                histo[19]->Fill(mt, weight);
                histo[30]->Fill(ScalarHT_HT[0], weight);
                histo[20]->Fill(reco_jets.size(), weight);
                histo[21]->Fill(reco_bjets.size(), weight);
              }
              if(Higgs.size()>1){
                histo[83]->Fill(Higgs.at(1).v.Pt(), weight);
              }
              if(reco_bjets.size()==2){
                histo[255]->Fill(MissingET_MET[0], weight);
              }
            }
          }
          if(reco_fatjetsmatch.size()==0 && reco_resbbjets.size()>0 && ScalarHT_HT[0]>500){
            if(Higgs.size()>0){
              histo[296]->Fill(Higgs.at(0).v.Pt(), weight);
                histo[22]->Fill(mt, weight);
                histo[31]->Fill(ScalarHT_HT[0], weight);
                histo[23]->Fill(reco_jets.size(), weight);
                histo[24]->Fill(reco_bjets.size(), weight);

            }
            if(Higgs.size()>1){
              histo[84]->Fill(Higgs.at(1).v.Pt(), weight);
            }
            if(reco_bjets.size()==2){
              histo[256]->Fill(MissingET_MET[0], weight);
            }
            int NNRbbJpt200=0;
            for(int g=0; g<reco_resbbjets.size(); g++){
              if(reco_resbbjets.at(g).v.Pt()>200){
                NNRbbJpt200 = NNRbbJpt200+1; 
              }
            }
            if(NNRbbJpt200>0){
              if(Higgs.size()>0){
                histo[297]->Fill(Higgs.at(0).v.Pt(), weight);
                histo[25]->Fill(mt, weight);
                histo[32]->Fill(ScalarHT_HT[0], weight);
                histo[26]->Fill(reco_jets.size(), weight);
                histo[27]->Fill(reco_bjets.size(), weight);
              }
              if(Higgs.size()>1){
                histo[85]->Fill(Higgs.at(1).v.Pt(), weight);
              }
              if(reco_bjets.size()==2){
                histo[272]->Fill(MissingET_MET[0], weight);
              }
            }
          }

        }//NJ5

        //NbJ>2
        if(reco_bjets.size()>2){
          histo[61]->Fill(MissingET_MET[0], weight);
          histo[62]->Fill(mt, weight);
          histo[63]->Fill(reco_jets.size(), weight);
          histo[64]->Fill(reco_bjets.size(), weight);
          if(ScalarHT_HT[0]>500){
            histo[230]->Fill(MissingET_MET[0], weight);
            if(reco_resbbjets.size()>0){
              histo[257]->Fill(MissingET_MET[0], weight);
              for(int s=0; s<reco_resbbjets.size(); s++){
                if(reco_resbbjets.at(s).v.Pt()>200){
                  histo[258]->Fill(MissingET_MET[0], weight);
                }
              }
            }
          }
          if(reco_fatjetsmatch.size()>0){
            histo[65]->Fill(MissingET_MET[0], weight);
            histo[66]->Fill(mt, weight);
            histo[67]->Fill(reco_jets.size(), weight);
            histo[68]->Fill(reco_bjets.size(), weight);
            if(ScalarHT_HT[0]>500){
              histo[259]->Fill(MissingET_MET[0], weight);
            }
          }
          if(reco_fatjetsmatch.size()==0 && reco_resbbjets.size()>0 && ScalarHT_HT[0]>500){
            histo[260]->Fill(MissingET_MET[0], weight);
          }
          //NJ5
          if(reco_jets.size()>4){
            histo[69]->Fill(MissingET_MET[0], weight);
            histo[70]->Fill(mt, weight);
            histo[71]->Fill(reco_jets.size(), weight);
            histo[72]->Fill(reco_bjets.size(), weight);
            histo[162]->Fill(reco_fatjetsmatch.size(), weight);
            histo[163]->Fill(reco_resbbjets.size(), weight);
            if(ScalarHT_HT[0]>500){
              histo[232]->Fill(MissingET_MET[0], weight);
              histo[284]->Fill(mt, weight);
              histo[286]->Fill(ScalarHT_HT[0], weight);
              histo[288]->Fill(reco_jets.size(), weight);
              histo[290]->Fill(reco_bjets.size(), weight);
              if(Higgs.size()>0){
                float ptH = Higgs.at(0).v.Pt();
                histo[292]->Fill(ptH, weight);
              }
              if(Higgs.size()>1){
                float ptH1 = Higgs.at(1).v.Pt();
                histo[86]->Fill(ptH1, weight);
              }
              if(reco_fatjetsmatch.size()>0){
                histo[273]->Fill(reco_fatjetsmatch.size(), weight);
              }
              if(reco_resbbjets.size()>0){
                histo[275]->Fill(reco_resbbjets.size(), weight);
                int NRbbJ200=0;
                for(int h=0; h<reco_resbbjets.size(); h++){
                  if(reco_resbbjets.at(h).v.Pt()>200){
                    NRbbJ200=NRbbJ200+1;
                  }
                }
                if(NRbbJ200>0){
                  histo[277]->Fill(reco_resbbjets.size(), weight);
                  if(reco_fatjetsmatch.size()==0){
                    histo[281]->Fill(reco_resbbjets.size(), weight);
                  }
                }
                if(reco_fatjetsmatch.size()==0){
                  histo[279]->Fill(reco_resbbjets.size(), weight);
                }
              }

              if(reco_resbbjets.size()>0){
                histo[261]->Fill(MissingET_MET[0], weight);
                if(Higgs.size()>0){
                  histo[298]->Fill(Higgs.at(0).v.Pt(), weight);
                }
                if(Higgs.size()>1){
                  histo[87]->Fill(Higgs.at(1).v.Pt(), weight);
                }
                for(int s=0; s<reco_resbbjets.size(); s++){
                  if(reco_resbbjets.at(s).v.Pt()>200){
                    histo[262]->Fill(MissingET_MET[0], weight);
                    if(Higgs.size()>0){
                      histo[299]->Fill(Higgs.at(0).v.Pt(), weight);
                    }
                    if(Higgs.size()>1){
                      histo[88]->Fill(Higgs.at(1).v.Pt(), weight);
                    }
                  }
                }
              }
            }
            for(int d=0; d<reco_fatjetsmatch.size(); d++){
              histo[164]->Fill(reco_fatjetsmatch.at(d).v.Pt(), weight);
            }
            for(int c=0; c<reco_resbbjets.size(); c++){
              histo[165]->Fill(reco_resbbjets.at(c).v.Pt(), weight);
            }

            if(reco_fatjetsmatch.size()>0){
              histo[73]->Fill(MissingET_MET[0], weight);
              histo[74]->Fill(mt, weight);
              histo[75]->Fill(reco_jets.size(), weight);
              histo[76]->Fill(reco_bjets.size(), weight);
              histo[150]->Fill(MissingET_MET[0], weight);
              histo[151]->Fill(mt, weight);
              histo[152]->Fill(reco_jets.size(), weight);
              histo[153]->Fill(reco_bjets.size(), weight);
              if(ScalarHT_HT[0]>500){
                histo[263]->Fill(MissingET_MET[0], weight);
                if(Higgs.size()>0){
                  histo[77]->Fill(Higgs.at(0).v.Pt(), weight);
                }
                if(Higgs.size()>1){
                  histo[89]->Fill(Higgs.at(1).v.Pt(), weight);
                }
              }
            }
            if(reco_fatjetsmatch.size()==0 && reco_resbbjets.size()>0){
              histo[133]->Fill(MissingET_MET[0], weight);
              histo[134]->Fill(mt, weight);
              histo[135]->Fill(reco_jets.size(), weight);
              histo[136]->Fill(reco_bjets.size(), weight);  
              histo[150]->Fill(MissingET_MET[0], weight);
              histo[151]->Fill(mt, weight);
              histo[152]->Fill(reco_jets.size(), weight);
              histo[153]->Fill(reco_bjets.size(), weight);   
              for(int x=0; x<reco_resbbjets.size(); x++){
                if(reco_resbbjets.at(x).v.Pt()>200){
                  histo[201]->Fill(MissingET_MET[0], weight);
                  histo[202]->Fill(mt, weight);
                  histo[203]->Fill(reco_jets.size(), weight);
                  histo[204]->Fill(reco_bjets.size(), weight);
                }
              }
              if(ScalarHT_HT[0]>500){
                histo[264]->Fill(MissingET_MET[0], weight);
                if(Higgs.size()>0){
                  histo[78]->Fill(Higgs.at(0).v.Pt(), weight);
                }
                if(Higgs.size()>1){
                  histo[90]->Fill(Higgs.at(1).v.Pt(), weight);
                }
                int NRbbJpt200=0;
                for(int g=0; g<reco_resbbjets.size(); g++){
                  if(reco_resbbjets.at(g).v.Pt()>200){
                    NRbbJpt200 = NRbbJpt200+1; 
                  }
                }
                if(NRbbJpt200>0){
                  histo[271]->Fill(MissingET_MET[0], weight);
                  if(Higgs.size()>0){
                    histo[79]->Fill(Higgs.at(0).v.Pt(), weight);
                  }
                  if(Higgs.size()>1){
                    histo[91]->Fill(Higgs.at(1).v.Pt(), weight);
                  }
                }
              }          
            }
            if(reco_resbbjets.size()>0){
              histo[180]->Fill(MissingET_MET[0], weight);
              histo[181]->Fill(mt, weight);
              histo[182]->Fill(reco_jets.size(), weight);
              histo[183]->Fill(reco_bjets.size(), weight);
              for(int x=0; x<reco_resbbjets.size(); x++){
                if(reco_resbbjets.at(x).v.Pt()>200){
                  histo[197]->Fill(MissingET_MET[0], weight);
                  histo[198]->Fill(mt, weight);
                  histo[199]->Fill(reco_jets.size(), weight);
                  histo[200]->Fill(reco_bjets.size(), weight);
                }
              }  
            }

          }//nj>4
        }//nbj>2

      }//mt>150


  }//event selection

    }//0.8
  }



   }//event loop
   this->Output();
}//void loop
//-------------------------------------------
Int_t tt_1l_2Mevts::Output()
{
  TFile *rootfile = new TFile("Hst_tt_1l_2Mevts_opt.root", "RECREATE");

  histo[0]->Write();
  histo[1]->Write();
  histo[2]->Write();
  histo[3]->Write();
  histo[4]->Write();
  histo[5]->Write();
  histo[6]->Write();
  histo[265]->Write();
  histo[7]->Write();
  histo[8]->Write();
  histo[9]->Write();
  histo[174]->Write();
  histo[43]->Write();
  histo[192]->Write();
  histo[175]->Write();
  histo[176]->Write();
  histo[193]->Write();
  histo[177]->Write();
  histo[178]->Write();
  histo[145]->Write();
  histo[146]->Write();
  histo[179]->Write();
  histo[147]->Write();
  histo[196]->Write();
  histo[194]->Write();
  histo[195]->Write();
  histo[148]->Write();
  histo[149]->Write();
  histo[270]->Write();
  histo[10]->Write();
  histo[11]->Write();
  histo[12]->Write();

  histo[45]->Write();
  histo[46]->Write();
  histo[47]->Write();
  histo[48]->Write();
  histo[49]->Write();
  histo[50]->Write();
  histo[51]->Write();
  histo[52]->Write();
  histo[53]->Write();
  histo[54]->Write();
  histo[55]->Write();
  histo[56]->Write();
  histo[57]->Write();
  histo[58]->Write();
  histo[59]->Write();
  histo[60]->Write();
  histo[61]->Write();
  histo[62]->Write();
  histo[63]->Write();
  histo[64]->Write();
  histo[65]->Write();
  histo[66]->Write();
  histo[67]->Write();
  histo[68]->Write();
  histo[69]->Write();
  histo[70]->Write();
  histo[71]->Write();
  histo[72]->Write();
  histo[162]->Write();
  histo[163]->Write();
  histo[164]->Write();
  histo[165]->Write();
  histo[73]->Write();
  histo[74]->Write();
  histo[75]->Write();
  histo[76]->Write();
  histo[133]->Write();
  histo[134]->Write();
  histo[135]->Write();
  histo[136]->Write();
  histo[201]->Write();
  histo[202]->Write();
  histo[203]->Write();
  histo[204]->Write();
  histo[150]->Write();
  histo[151]->Write();
  histo[152]->Write();
  histo[153]->Write();
  histo[180]->Write();
  histo[181]->Write();
  histo[182]->Write();
  histo[183]->Write();
  histo[197]->Write();
  histo[198]->Write();
  histo[199]->Write();
  histo[200]->Write();

  histo[226]->Write();
  histo[228]->Write();
  histo[230]->Write();
  histo[232]->Write();
  histo[267]->Write();
  histo[269]->Write();

  histo[283]->Write();
  histo[284]->Write();
  histo[285]->Write();
  histo[286]->Write();
  histo[287]->Write();
  histo[288]->Write();
  histo[289]->Write();
  histo[290]->Write();
  histo[291]->Write();
  histo[80]->Write();
  histo[292]->Write();
  histo[86]->Write();


  histo[249]->Write();
  histo[250]->Write();
  histo[251]->Write();
  histo[252]->Write();
  histo[253]->Write();
  histo[254]->Write();
  histo[255]->Write();
  histo[256]->Write();
  histo[272]->Write();
  histo[257]->Write();
  histo[258]->Write();
  histo[259]->Write();
  histo[260]->Write();
  histo[261]->Write();
  histo[262]->Write();
  histo[263]->Write();
  histo[264]->Write();
  histo[271]->Write();
  histo[293]->Write();
  histo[81]->Write();
  histo[13]->Write();
  histo[28]->Write();
  histo[14]->Write();
  histo[15]->Write();
  histo[294]->Write();
  histo[82]->Write();
  histo[16]->Write();
  histo[29]->Write();
  histo[17]->Write();
  histo[18]->Write();
  histo[295]->Write();
  histo[83]->Write();
  histo[19]->Write();
  histo[30]->Write();
  histo[20]->Write();
  histo[21]->Write();
  histo[296]->Write();
  histo[84]->Write();
  histo[22]->Write();
  histo[31]->Write();
  histo[23]->Write();
  histo[24]->Write();
  histo[297]->Write();
  histo[85]->Write();
  histo[25]->Write();
  histo[32]->Write();
  histo[26]->Write();
  histo[27]->Write();
  histo[298]->Write();
  histo[87]->Write();
  histo[299]->Write();
  histo[88]->Write();
  histo[77]->Write();
  histo[89]->Write();
  histo[78]->Write();
  histo[90]->Write();
  histo[79]->Write();
  histo[91]->Write();
  histo[273]->Write();
  histo[274]->Write();
  histo[275]->Write();
  histo[276]->Write();
  histo[277]->Write();
  histo[278]->Write();
  histo[279]->Write();
  histo[280]->Write();
  histo[281]->Write();
  histo[282]->Write();

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


  rootfile->Write();
  rootfile->Close();

  return 0;
}

//---------------------------------------------------
