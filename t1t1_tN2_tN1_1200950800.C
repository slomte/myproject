#define t1t1_tN2_tN1_1200950800_cxx
#include "t1t1_tN2_tN1_1200950800.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

//*******
#include <TH1.h>
#include <TMath.h>
#include <TLorentzVector.h>
#include <iostream>

void t1t1_tN2_tN1_1200950800::Loop()
{
//   In a ROOT session, you can do:
//      root> .L t1t1_tN2_tN1_1200950800.C
//      root> t1t1_tN2_tN1_1200950800 t
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
   histo[174] = new TH1D("PT_H", "PT of Higgs", 100, 0, 2000);

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

   //dPhi(J12, met)>0.8
   //Event Selections: 1l + met>100 + mt>100
   histo[77] = new TH1D("MET_1l", "MET after 1lep", 100, 0, 2000);
   histo[78] = new TH1D("MET_1lmt100", "MET after 1lep + MT>100GeV", 100, 0, 2000);
   histo[79] = new TH1D("MET_1lmt100met100", "MET after 1lep + MT>100GeV + MET>100GeV", 100, 0, 2000);
   histo[80] = new TH1D("MT_1l", "MT after 1lep", 100, 0, 2000);
   histo[81] = new TH1D("MT_1lmet100", "MT after 1lep + MET>100GeV", 100, 0, 2000);
   histo[82] = new TH1D("MT_1lmet100mt100", "MT after 1lep + MET>100GeV + MT>100GeV", 100, 0, 2000);
   histo[83] = new TH1D("Nj_1l", "NJets after 1lep", 20, 0, 20);
   histo[84] = new TH1D("Nj_1lmet100", "NJets after 1lep + MET>100GeV", 20, 0, 20);
   histo[85] = new TH1D("Nj_1lmt100", "NJets after 1lep + MT>100GeV", 20, 0, 20);
   histo[86] = new TH1D("Nj_1lmet100mt100", "NJets after 1lep + MET>100GeV + MT>100GeV", 20, 0, 20);
   histo[87] = new TH1D("Nbj_1l", "NbJets after 1lep", 10, 0, 10);
   histo[88] = new TH1D("Nbj_1lmet100", "NbJets after 1lep + MET>100GeV", 10, 0, 10);
   histo[89] = new TH1D("Nbj_1lmt100", "NbJets after 1lep + MT>100GeV", 10, 0, 10);
   histo[90] = new TH1D("Nbj_1lmet100mt100", "NbJets after 1lep + MET>100GeV + MT>100GeV", 10, 0, 10);
   // + NJ>=4 + NbJ>=2/3
   histo[91] = new TH1D("MET_1lmet100mt100NJ4", "MET after 1l + mt>100 + met>100 + NJ>=4", 100, 0, 2000);
   histo[92] = new TH1D("MET_1lmet100mt100NJ4NbJ2", "MET after 1l + mt>100 + met>100 + NJ>=4 + NbJ>=2", 100, 0, 2000);
   histo[93] = new TH1D("MET_1lmet100mt100NJ4NbJ3", "MET after 1l + mt>100 + met>100 + NJ>=4 + NbJ>=3", 100, 0, 2000);
   histo[94] = new TH1D("MT_1lmet100mt100NJ4", "MT after 1l + mt>100 + met>100 + NJ>=4", 100, 0, 2000);
   histo[95] = new TH1D("MT_1lmet100mt100NJ4NbJ2", "MT after 1l + mt>100 + met>100 + NJ>=4 + NbJ>=2", 100, 0, 2000);
   histo[96] = new TH1D("MT_1lmet100mt100NJ4NbJ3", "MT after 1l + mt>100 + met>100 + NJ>=4 + NbJ>=3", 100, 0, 2000);
   histo[97] = new TH1D("Nj_1lmet100mt100NbJ2", "NJets after 1lep + MET>100GeV + MT>100GeV + NbJ>=2", 20, 0, 20);
   histo[98] = new TH1D("Nj_1lmet100mt100NJ4NbJ2", "NJets after 1lep + MET>100GeV + MT>100GeV + NJ>=4 + NbJ>=2", 20, 0, 20);
   histo[99] = new TH1D("Nj_1lmet100mt100NbJ3", "NJets after 1lep + MET>100GeV + MT>100GeV + NbJ>=3", 20, 0, 20);
   histo[100] = new TH1D("Nj_1lmet100mt100NJ4NbJ3", "NJets after 1lep + MET>100GeV + MT>100GeV + NJ>=4 + NbJ>=3", 20, 0, 20);
   histo[101] = new TH1D("Nbj_1lmet100mt100NJ4", "NJets after 1lep + MET>100GeV + MT>100GeV + NJ>=4", 10, 0, 10);
   histo[102] = new TH1D("Nbj_1lmet100mt100NJ4NbJ2", "NJets after 1lep + MET>100GeV + MT>100GeV + NJ>=4 + NbJ>=2", 10, 0, 10);
   histo[103] = new TH1D("Nbj_1lmet100mt100NJ4NbJ3", "NJets after 1lep + MET>100GeV + MT>100GeV + NJ>=4 + NbJ>=3", 10, 0, 10);
   // + NJ>=5 + NbJ>=2/3
   histo[104] = new TH1D("MET_1lmet100mt100NJ5", "MET after 1l + mt>100 + met>100 + NJ>=5", 100, 0, 2000);
   histo[105] = new TH1D("MET_1lmet100mt100NJ5NbJ2", "MET after 1l + mt>100 + met>100 + NJ>=5 + NbJ>=2", 100, 0, 2000);
   histo[106] = new TH1D("MET_1lmet100mt100NJ5NbJ3", "MET after 1l + mt>100 + met>100 + NJ>=5 + NbJ>=3", 100, 0, 2000);
   histo[107] = new TH1D("MT_1lmet100mt100NJ5", "MT after 1l + mt>100 + met>100 + NJ>=5", 100, 0, 2000);
   histo[108] = new TH1D("MT_1lmet100mt100NJ5NbJ2", "MT after 1l + mt>100 + met>100 + NJ>=5 + NbJ>=2", 100, 0, 2000);
   histo[109] = new TH1D("MT_1lmet100mt100NJ5NbJ3", "MT after 1l + mt>100 + met>100 + NJ>=5 + NbJ>=3", 100, 0, 2000);
   //histo[110] = new TH1D("Nj_1lmet100mt100NbJ2", "NJets after 1lep + MET>100GeV + MT>100GeV + NbJ>=2", 20, 0, 20);
   histo[111] = new TH1D("Nj_1lmet100mt100NJ5NbJ2", "NJets after 1lep + MET>100GeV + MT>100GeV + NJ>=5 + NbJ>=2", 20, 0, 20);
   //histo[112] = new TH1D("Nj_1lmet100mt100NbJ3", "NJets after 1lep + MET>100GeV + MT>100GeV + NbJ>=3", 20, 0, 20);
   histo[113] = new TH1D("Nj_1lmet100mt100NJ5NbJ3", "NJets after 1lep + MET>100GeV + MT>100GeV + NJ>=5 + NbJ>=3", 20, 0, 20);
   histo[114] = new TH1D("Nbj_1lmet100mt100NJ5", "NJets after 1lep + MET>100GeV + MT>100GeV + NJ>=5", 10, 0, 10);
   histo[115] = new TH1D("Nbj_1lmet100mt100NJ5NbJ2", "NJets after 1lep + MET>100GeV + MT>100GeV + NJ>=5 + NbJ>=2", 10, 0, 10);
   histo[116] = new TH1D("Nbj_1lmet100mt100NJ5NbJ3", "NJets after 1lep + MET>100GeV + MT>100GeV + NJ>=5 + NbJ>=3", 10, 0, 10);



   //For compressed spectra:
   //1lep + Nj>3 + Nbj>1 evts + met>120 + mt>100
   histo[13] = new TH1D("MET_1", "MET for 1lep + Nj>3 + Nbj>1 ", 100, 0, 2000);
   histo[14] = new TH1D("MT_1", "MT for 1lep + Nj>3 + Nbj>1 ", 100, 0, 2000);
   histo[15] = new TH1D("Nj_1", "NJets for 1lep + Nj>3 + Nbj>1 ", 20, 0, 20);
   histo[16] = new TH1D("Nbj_1", "NbJets for 1lep + Nj>3 + Nbj>1 ", 10, 0, 10);
   // + NFatJet>0 
   histo[17] = new TH1D("MET_fj_1", "MET for 1lep + Nj>3 + Nbj>1 ", 100, 0, 2000);
   histo[18] = new TH1D("MT_fj_1", "MT for 1lep + Nj>3 + Nbj>1 ", 100, 0, 2000);
   histo[19] = new TH1D("Nj_fj_1", "NJets for 1lep + Nj>3 + Nbj>1 ", 20, 0, 20);
   histo[20] = new TH1D("Nbj_fj_1", "NbJets for 1lep + Nj>3 + Nbj>1 ", 10, 0, 10);

   //1lep + Nj>4 + Nbj>1 evts + met>120 + mt>100
   histo[21] = new TH1D("MET_2", "MET for 1lep + Nj>4 + Nbj>1 ", 100, 0, 2000);
   histo[22] = new TH1D("MT_2", "MT for 1lep + Nj>4 + Nbj>1 ", 100, 0, 2000);
   histo[23] = new TH1D("Nj_2", "NJets for 1lep + Nj>4 + Nbj>1 ", 20, 0, 20);
   histo[24] = new TH1D("Nbj_2", "NbJets for 1lep + Nj>4 + Nbj>1 ", 10, 0, 10);
   // + NFatJet>0 
   histo[25] = new TH1D("MET_fj_2", "MET for 1lep + Nj>4 + Nbj>1 ", 100, 0, 2000);
   histo[26] = new TH1D("MT_fj_2", "MT for 1lep + Nj>4 + Nbj>1 ", 100, 0, 2000);
   histo[27] = new TH1D("Nj_fj_2", "NJets for 1lep + Nj>4 + Nbj>1 ", 20, 0, 20);
   histo[28] = new TH1D("Nbj_fj_2", "NbJets for 1lep + Nj>4 + Nbj>1 ", 10, 0, 10);

   //1lep + Nj>3 + Nbj>2 evts + met>120 + mt>100
   histo[29] = new TH1D("MET_3", "MET for 1lep + Nj>3 + Nbj>2 ", 100, 0, 2000);
   histo[30] = new TH1D("MT_3", "MT for 1lep + Nj>3 + Nbj>2 ", 100, 0, 2000);
   histo[31] = new TH1D("Nj_3", "NJets for 1lep + Nj>3 + Nbj>2 ", 20, 0, 20);
   histo[32] = new TH1D("Nbj_3", "NbJets for 1lep + Nj>3 + Nbj>2 ", 10, 0, 10);
   // + NFatJet>0 
   histo[33] = new TH1D("MET_fj_3", "MET for 1lep + Nj>3 + Nbj>2 ", 100, 0, 2000);
   histo[34] = new TH1D("MT_fj_3", "MT for 1lep + Nj>3 + Nbj>2 ", 100, 0, 2000);
   histo[35] = new TH1D("Nj_fj_3", "NJets for 1lep + Nj>3 + Nbj>2 ", 20, 0, 20);
   histo[36] = new TH1D("Nbj_fj_3", "NbJets for 1lep + Nj>3 + Nbj>2 ", 10, 0, 10);

   //1lep + Nj>4 + Nbj>2 evts + met>120 + mt>100
   histo[37] = new TH1D("MET_4", "MET for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[38] = new TH1D("MT_4", "MT for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[39] = new TH1D("Nj_4", "NJets for 1lep + Nj>4 + Nbj>2 ", 20, 0, 20);
   histo[40] = new TH1D("Nbj_4", "NbJets for 1lep + Nj>4 + Nbj>2 ", 10, 0, 10);
   // + NFatJet>0 
   histo[41] = new TH1D("MET_fj_4", "MET for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[42] = new TH1D("MT_fj_4", "MT for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[43] = new TH1D("Nj_fj_4", "NJets for 1lep + Nj>4 + Nbj>2 ", 20, 0, 20);
   histo[44] = new TH1D("Nbj_fj_4", "NbJets for 1lep + Nj>4 + Nbj>2 ", 10, 0, 10);

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


   //Tighter selections
   //1lep + Nj>4 + Nbj>2 evts + met>200 + mt>150
   histo[117] = new TH1D("MET_9", "MET for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[118] = new TH1D("MT_9", "MT for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[119] = new TH1D("Nj_9", "NJets for 1lep + Nj>4 + Nbj>2 ", 20, 0, 20);
   histo[120] = new TH1D("Nbj_9", "NbJets for 1lep + Nj>4 + Nbj>2 ", 10, 0, 10);
   histo[166] = new TH1D("Nfj_9", "NFatJets for 1lep + Nj>4 + Nbj>2 ", 10, 0, 10);
   histo[167] = new TH1D("Nresbbj_9", "NResbbJets for 1lep + Nj>4 + Nbj>2 ", 15, 0, 15);
   histo[168] = new TH1D("PT_fj_9", "p_{T} of FatJets for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[169] = new TH1D("PT_resbbj_9", "p_{T} of ResbbJets for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   // + NFatJet>0 
   histo[121] = new TH1D("MET_fj_9", "MET for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[122] = new TH1D("MT_fj_9", "MT for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[123] = new TH1D("Nj_fj_9", "NJets for 1lep + Nj>4 + Nbj>2 ", 20, 0, 20);
   histo[124] = new TH1D("Nbj_fj_9", "NbJets for 1lep + Nj>4 + Nbj>2 ", 10, 0, 10);
   // + Nresbbjet>0 (when Nfj=0)
   histo[137] = new TH1D("MET_resbbj_9", "MET for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[138] = new TH1D("MT_resbbj_9", "MT for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[139] = new TH1D("Nj_resbbj_9", "NJets for 1lep + Nj>4 + Nbj>2 ", 20, 0, 20);
   histo[140] = new TH1D("Nbj_resbbj_9", "NbJets for 1lep + Nj>4 + Nbj>2 ", 10, 0, 10);
   histo[209] = new TH1D("MET_resbbj_pt200_9", "MET for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[210] = new TH1D("MT_resbbj_pt200_9", "MT for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[211] = new TH1D("Nj_resbbj_pt200_9", "NJets for 1lep + Nj>4 + Nbj>2 ", 20, 0, 20);
   histo[212] = new TH1D("Nbj_resbbj_pt200_9", "NbJets for 1lep + Nj>4 + Nbj>2 ", 10, 0, 10);
   // + NFJ>0 or NFJ=0&NRbbJ>0
   histo[154] = new TH1D("MET_fj_resbbj_9", "MET for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[155] = new TH1D("MT_fj_resbbj_9", "MT for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[156] = new TH1D("Nj_fj_resbbj_9", "NJets for 1lep + Nj>4 + Nbj>2 ", 20, 0, 20);
   histo[157] = new TH1D("Nbj_fj_resbbj_9", "NbJets for 1lep + Nj>4 + Nbj>2 ", 10, 0, 10);
   //NResbbJ>0
   histo[184] = new TH1D("MET_resbbj1_9", "MET for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[185] = new TH1D("MT_resbbj1_9", "MT for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[186] = new TH1D("Nj_resbbj1_9", "NJets for 1lep + Nj>4 + Nbj>2 ", 20, 0, 20);
   histo[187] = new TH1D("Nbj_resbbj1_9", "NbJets for 1lep + Nj>4 + Nbj>2 ", 10, 0, 10);
   histo[205] = new TH1D("MET_resbbj1_pt200_9", "MET for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[206] = new TH1D("MT_resbbj1_pt200_9", "MT for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[207] = new TH1D("Nj_resbbj1_pt200_9", "NJets for 1lep + Nj>4 + Nbj>2 ", 20, 0, 20);
   histo[208] = new TH1D("Nbj_resbbj1_pt200_9", "NbJets for 1lep + Nj>4 + Nbj>2 ", 10, 0, 10);


   //1lep + Nj>4 + Nbj>2 evts + met>250 + mt>150
   histo[125] = new TH1D("MET_10", "MET for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[126] = new TH1D("MT_10", "MT for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[127] = new TH1D("Nj_10", "NJets for 1lep + Nj>4 + Nbj>2 ", 20, 0, 20);
   histo[128] = new TH1D("Nbj_10", "NbJets for 1lep + Nj>4 + Nbj>2 ", 10, 0, 10);
   histo[170] = new TH1D("Nfj_10", "NFatJets for 1lep + Nj>4 + Nbj>2 ", 10, 0, 10);
   histo[171] = new TH1D("Nresbbj_10", "NResbbJets for 1lep + Nj>4 + Nbj>2 ", 15, 0, 15);
   histo[172] = new TH1D("PT_fj_10", "p_{T} of FatJets for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[173] = new TH1D("PT_resbbj_10", "p_{T} of ResbbJets for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   // + NFatJet>0 
   histo[129] = new TH1D("MET_fj_10", "MET for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[130] = new TH1D("MT_fj_10", "MT for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[131] = new TH1D("Nj_fj_10", "NJets for 1lep + Nj>4 + Nbj>2 ", 20, 0, 20);
   histo[132] = new TH1D("Nbj_fj_10", "NbJets for 1lep + Nj>4 + Nbj>2 ", 10, 0, 10);
   // + Nresbbjet>0 (when Nfj=0)
   histo[141] = new TH1D("MET_resbbj_10", "MET for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[142] = new TH1D("MT_resbbj_10", "MT for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[143] = new TH1D("Nj_resbbj_10", "NJets for 1lep + Nj>4 + Nbj>2 ", 20, 0, 20);
   histo[144] = new TH1D("Nbj_resbbj_10", "NbJets for 1lep + Nj>4 + Nbj>2 ", 10, 0, 10);
   histo[217] = new TH1D("MET_resbbj_pt200_10", "MET for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[218] = new TH1D("MT_resbbj_pt200_10", "MT for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[219] = new TH1D("Nj_resbbj_pt200_10", "NJets for 1lep + Nj>4 + Nbj>2 ", 20, 0, 20);
   histo[220] = new TH1D("Nbj_resbbj_pt200_10", "NbJets for 1lep + Nj>4 + Nbj>2 ", 10, 0, 10);

   // + NFJ>0 or NFJ=0&NRbbJ>0
   histo[158] = new TH1D("MET_fj_resbbj_10", "MET for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[159] = new TH1D("MT_fj_resbbj_10", "MT for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[160] = new TH1D("Nj_fj_resbbj_10", "NJets for 1lep + Nj>4 + Nbj>2 ", 20, 0, 20);
   histo[161] = new TH1D("Nbj_fj_resbbj_10", "NbJets for 1lep + Nj>4 + Nbj>2 ", 10, 0, 10);
   //NResbbJ>0
   histo[188] = new TH1D("MET_resbbj1_10", "MET for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[189] = new TH1D("MT_resbbj1_10", "MT for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[190] = new TH1D("Nj_resbbj1_10", "NJets for 1lep + Nj>4 + Nbj>2 ", 20, 0, 20);
   histo[191] = new TH1D("Nbj_resbbj1_10", "NbJets for 1lep + Nj>4 + Nbj>2 ", 10, 0, 10);
   histo[213] = new TH1D("MET_resbbj1_pt200_10", "MET for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[214] = new TH1D("MT_resbbj1_pt200_10", "MT for 1lep + Nj>4 + Nbj>2 ", 100, 0, 2000);
   histo[215] = new TH1D("Nj_resbbj1_pt200_10", "NJets for 1lep + Nj>4 + Nbj>2 ", 20, 0, 20);
   histo[216] = new TH1D("Nbj_resbbj1_pt200_10", "NbJets for 1lep + Nj>4 + Nbj>2 ", 10, 0, 10);


   //HT>500
   histo[221] = new TH1D("MET_ht", "MET after HT>500 GeV ", 100, 0, 2000);
   histo[222] = new TH1D("MET_ht_1l", "MET for 1lep ", 100, 0, 2000);
   histo[223] = new TH1D("MET_ht_1lmet120mt100", "MET for 1lep + mt>100 + met>120 ", 100, 0, 2000);
   histo[224] = new TH1D("MET_ht_1lmet120mt150", "MET for 1lep + mt>150 + met>120", 100, 0, 2000);
   histo[225] = new TH1D("MET_ht_1lmet120mt100NJ4NbJ2", "MET for 1lep + mt>100 + met>120 + Nj>=4 + Nbj>=2 ", 100, 0, 2000);
   histo[226] = new TH1D("MET_ht_1lmet120mt150NJ4NbJ2", "MET for 1lep + mt>150 + met>120 + Nj>=4 + Nbj>=2 ", 100, 0, 2000);
   histo[227] = new TH1D("MET_ht_1lmet120mt100NJ5NbJ2", "MET for 1lep + mt>100 + met>120 + Nj>=5 + Nbj>=2 ", 100, 0, 2000);
   histo[228] = new TH1D("MET_ht_1lmet120mt150NJ5NbJ2", "MET for 1lep + mt>150 + met>120 + Nj>=5 + Nbj>=2 ", 100, 0, 2000);
   histo[229] = new TH1D("MET_ht_1lmet120mt100NJ4NbJ3", "MET for 1lep + mt>100 + met>120 + Nj>=4 + Nbj>=3 ", 100, 0, 2000);
   histo[230] = new TH1D("MET_ht_1lmet120mt150NJ4NbJ3", "MET for 1lep + mt>150 + met>120 + Nj>=4 + Nbj>=3 ", 100, 0, 2000);
   histo[231] = new TH1D("MET_ht_1lmet120mt100NJ5NbJ3", "MET for 1lep + mt>100 + met>120 + Nj>=5 + Nbj>=3 ", 100, 0, 2000);
   histo[232] = new TH1D("MET_ht_1lmet120mt150NJ5NbJ3", "MET for 1lep + mt>150 + met>120 + Nj>=5 + Nbj>=3 ", 100, 0, 2000);
   histo[266] = new TH1D("MET_ht_1lmet120mt100NJ4NbJ=2", "MET for 1lep + mt>100 + met>120 + Nj>=4 + Nbj=2 ", 100, 0, 2000);
   histo[267] = new TH1D("MET_ht_1lmet120mt150NJ4NbJ=2", "MET for 1lep + mt>150 + met>120 + Nj>=4 + Nbj=2 ", 100, 0, 2000);
   histo[268] = new TH1D("MET_ht_1lmet120mt100NJ5NbJ=2", "MET for 1lep + mt>100 + met>120 + Nj>=5 + Nbj=2 ", 100, 0, 2000);
   histo[269] = new TH1D("MET_ht_1lmet120mt150NJ5NbJ=2", "MET for 1lep + mt>150 + met>120 + Nj>=5 + Nbj=2 ", 100, 0, 2000);


   // + NRbbJ>0 or NFJ>0 or NFJ0=+NRbbJ>0
   histo[233] = new TH1D("MET_ht_1lmet120mt100NJ4NbJ2NRbbJ1", "MET for 1lep + mt>100 + met>120 + Nj>=4 + Nbj=2 + NRbbJ>0", 100, 0, 2000);
   histo[234] = new TH1D("MET_ht_1lmet120mt100NJ4NbJ2NRbbJ1pt200", "MET for 1lep + mt>100 + met>120 + Nj>=4 + Nbj=2 + NRbbJ>0 with pt>200", 100, 0, 2000);
   histo[235] = new TH1D("MET_ht_1lmet120mt100NJ4NbJ2NFJ1", "MET for 1lep + mt>100 + met>120 + Nj>=4 + Nbj=2 + NFJ>0", 100, 0, 2000);
   histo[236] = new TH1D("MET_ht_1lmet120mt100NJ4NbJ2NFJ0NRbbJ1", "MET for 1lep + mt>100 + met>120 + Nj>=4 + Nbj=2 + NFJ=0 + NRbbJ>0", 100, 0, 2000);

   histo[237] = new TH1D("MET_ht_1lmet120mt100NJ5NbJ2NRbbJ1", "MET for 1lep + mt>100 + met>120 + Nj>=5 + Nbj=2 + NRbbJ>0", 100, 0, 2000);
   histo[238] = new TH1D("MET_ht_1lmet120mt100NJ5NbJ2NRbbJ1pt200", "MET for 1lep + mt>100 + met>120 + Nj>=5 + Nbj=2 + NRbbJ>0 with pt>200", 100, 0, 2000);
   histo[239] = new TH1D("MET_ht_1lmet120mt100NJ5NbJ2NFJ1", "MET for 1lep + mt>100 + met>120 + Nj>=5 + Nbj=2 + NFJ>0", 100, 0, 2000);
   histo[240] = new TH1D("MET_ht_1lmet120mt100NJ5NbJ2NFJ0NRbbJ1", "MET for 1lep + mt>100 + met>120 + Nj>=5 + Nbj=2 + NFJ=0 + NRbbJ>0", 100, 0, 2000);

   histo[241] = new TH1D("MET_ht_1lmet120mt100NJ4NbJ3NRbbJ1", "MET for 1lep + mt>100 + met>120 + Nj>=4 + Nbj>=3 + NRbbJ>0", 100, 0, 2000);
   histo[242] = new TH1D("MET_ht_1lmet120mt100NJ4NbJ3NRbbJ1pt200", "MET for 1lep + mt>100 + met>120 + Nj>=4 + Nbj>=3 + NRbbJ>0 with pt>200", 100, 0, 2000);
   histo[243] = new TH1D("MET_ht_1lmet120mt100NJ4NbJ3NFJ1", "MET for 1lep + mt>100 + met>120 + Nj>=4 + Nbj>=3 + NFJ>0", 100, 0, 2000);
   histo[244] = new TH1D("MET_ht_1lmet120mt100NJ4NbJ3NFJ0NRbbJ1", "MET for 1lep + mt>100 + met>120 + Nj>=4 + Nbj>=3 + NFJ=0 + NRbbJ>0", 100, 0, 2000);

   histo[245] = new TH1D("MET_ht_1lmet120mt100NJ5NbJ3NRbbJ1", "MET for 1lep + mt>100 + met>120 + Nj>=5 + Nbj>=3 + NRbbJ>0", 100, 0, 2000);
   histo[246] = new TH1D("MET_ht_1lmet120mt100NJ5NbJ3NRbbJ1pt200", "MET for 1lep + mt>100 + met>120 + Nj>=5 + Nbj>=3 + NRbbJ>0 with pt>200", 100, 0, 2000);
   histo[247] = new TH1D("MET_ht_1lmet120mt100NJ5NbJ3NFJ1", "MET for 1lep + mt>100 + met>120 + Nj>=5 + Nbj>=3 + NFJ>0", 100, 0, 2000);
   histo[248] = new TH1D("MET_ht_1lmet120mt100NJ5NbJ3NFJ0NRbbJ1", "MET for 1lep + mt>100 + met>120 + Nj>=5 + Nbj>=3 + NFJ=0 + NRbbJ>0", 100, 0, 2000);

   //
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

//-------------------------------------------

  //mycode

  float weight = (1.70*150)/(50000);


  //Particles
  int NPar=Particle_size;
  for(int i=0; i<NPar; i++){
    //H
    if(abs(Particle_PID[i])==25 && Particle_PID[Particle_M1[i]]!=25) {
      histo[174]->Fill(Particle_PT[i], weight);
      Part par; par.v.SetPtEtaPhiM(Particle_PT[i], Particle_Eta[i], Particle_Phi[i], Particle_Mass[i]);
      par.id=Particle_PID[i]; par.ind=i; par.Charge=Particle_Charge[i]; 
    }
  }


  //MET HT
  histo[10]->Fill(MissingET_MET[0], weight);
  histo[11]->Fill(ScalarHT_HT[0], weight);

  if(ScalarHT_HT[0]>500){
    histo[221]->Fill(MissingET_MET[0], weight);
  }

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

  //Event Selections: 1l + met>100 + mt>100 + NJ>=4/5 + NbJ>=2/3

  if(reco_leps.size()==1){
    histo[77]->Fill(MissingET_MET[0], weight);
    histo[83]->Fill(reco_jets.size(), weight);
    histo[87]->Fill(reco_bjets.size(), weight);

    //ht>500
    if(ScalarHT_HT[0]>500){
      histo[222]->Fill(MissingET_MET[0], weight);
    }

    //mt
    float dP_lmet = fabs(MissingET_Phi[0] - reco_leps.at(0).v.Phi());
    if(dP_lmet>TMath::Pi()) {dP_lmet = 2*TMath::Pi() - dP_lmet;}
    float mt = sqrt(2*reco_leps.at(0).v.Pt()*MissingET_MET[0]*(1-TMath::Cos(dP_lmet)));
    histo[80]->Fill(mt, weight);

    if(MissingET_MET[0]>100){
      histo[81]->Fill(mt, weight);
      histo[84]->Fill(reco_jets.size(), weight);
      histo[88]->Fill(reco_bjets.size(), weight);
    }
    if(mt>100){
      histo[78]->Fill(MissingET_MET[0], weight);
      histo[85]->Fill(reco_jets.size(), weight);
      histo[89]->Fill(reco_bjets.size(), weight);
      if(MissingET_MET[0]>100){
        histo[79]->Fill(MissingET_MET[0], weight);
        histo[82]->Fill(mt, weight);
        histo[86]->Fill(reco_jets.size(), weight);
        histo[90]->Fill(reco_bjets.size(), weight);

        // + NJ>=4 + NbJ>=2/3
        if(reco_jets.size()>3){
          histo[91]->Fill(MissingET_MET[0], weight);
          histo[94]->Fill(mt, weight);
          histo[101]->Fill(reco_bjets.size(), weight);
          if(reco_bjets.size()>1){
            histo[92]->Fill(MissingET_MET[0], weight);
            histo[95]->Fill(mt, weight);
            histo[98]->Fill(reco_jets.size(), weight);
            histo[102]->Fill(reco_bjets.size(), weight);
          }
          if(reco_bjets.size()>2){
            histo[93]->Fill(MissingET_MET[0], weight);
            histo[96]->Fill(mt, weight);
            histo[100]->Fill(reco_jets.size(), weight);
            histo[103]->Fill(reco_bjets.size(), weight);
          }
        }
        if(reco_bjets.size()>1){
          histo[97]->Fill(reco_jets.size(), weight);
        }
        if(reco_bjets.size()>2){
          histo[99]->Fill(reco_jets.size(), weight);
        }
        // + NJ>=5 + NbJ>=2/3
        if(reco_jets.size()>4){
          histo[104]->Fill(MissingET_MET[0], weight);
          histo[107]->Fill(mt, weight);
          histo[114]->Fill(reco_bjets.size(), weight);
          if(reco_bjets.size()>1){
            histo[105]->Fill(MissingET_MET[0], weight);
            histo[108]->Fill(mt, weight);
            histo[111]->Fill(reco_jets.size(), weight);
            histo[115]->Fill(reco_bjets.size(), weight);
          }
          if(reco_bjets.size()>2){
            histo[106]->Fill(MissingET_MET[0], weight);
            histo[109]->Fill(mt, weight);
            histo[113]->Fill(reco_jets.size(), weight);
            histo[116]->Fill(reco_bjets.size(), weight);
          }
        }//
      }//met100
    }//mt100
  }//1lep

  //--------------------------------******---------------------------//
  //Event Selection: 1lep + Nj>3 + Nbj>1 + met>120 + mt>100
  if(reco_leps.size()==1 && reco_jets.size()>3 && reco_bjets.size()>1 && MissingET_MET[0]>120){

    //mt
    float dP_lmet = fabs(MissingET_Phi[0] - reco_leps.at(0).v.Phi());
    if(dP_lmet>TMath::Pi()) {dP_lmet = 2*TMath::Pi() - dP_lmet;}
    float mt = sqrt(2*reco_leps.at(0).v.Pt()*MissingET_MET[0]*(1-TMath::Cos(dP_lmet)));

    if(mt>100){
      histo[13]->Fill(MissingET_MET[0], weight);
      histo[14]->Fill(mt, weight);
      histo[15]->Fill(reco_jets.size(), weight);
      histo[16]->Fill(reco_bjets.size(), weight);
      //ht>500
      if(ScalarHT_HT[0]>500){
        histo[225]->Fill(MissingET_MET[0], weight);
        if(reco_bjets.size()==2){
          histo[266]->Fill(MissingET_MET[0], weight);
        }
        if(reco_resbbjets.size()>0 && reco_bjets.size()==2){
          histo[233]->Fill(MissingET_MET[0], weight);
          for(int s=0; s<reco_resbbjets.size(); s++){
            if(reco_resbbjets.at(s).v.Pt()>200){
              histo[234]->Fill(MissingET_MET[0], weight);
            }
          }
        }
      }
      if(reco_fatjetsmatch.size()>0){
        histo[17]->Fill(MissingET_MET[0], weight);
        histo[18]->Fill(mt, weight);
        histo[19]->Fill(reco_jets.size(), weight);
        histo[20]->Fill(reco_bjets.size(), weight);
        if(ScalarHT_HT[0]>500 && reco_bjets.size()==2){
          histo[235]->Fill(MissingET_MET[0], weight);
        }
      }
      if(reco_fatjetsmatch.size()==0 && reco_resbbjets.size()>0 && ScalarHT_HT[0]>500 && reco_bjets.size()==2){
        histo[236]->Fill(MissingET_MET[0], weight);
      }
      //
      if(reco_jets.size()>4){
        histo[21]->Fill(MissingET_MET[0], weight);
        histo[22]->Fill(mt, weight);
        histo[23]->Fill(reco_jets.size(), weight);
        histo[24]->Fill(reco_bjets.size(), weight);
        if(ScalarHT_HT[0]>500){
          histo[227]->Fill(MissingET_MET[0], weight);
          if(reco_bjets.size()==2){
            histo[268]->Fill(MissingET_MET[0], weight);
          }
          if(reco_resbbjets.size()>0 && reco_bjets.size()==2){
            histo[237]->Fill(MissingET_MET[0], weight);
            for(int s=0; s<reco_resbbjets.size(); s++){
              if(reco_resbbjets.at(s).v.Pt()>200){
                histo[238]->Fill(MissingET_MET[0], weight);
              }
            }
          }
        }
        if(reco_fatjetsmatch.size()>0){
          histo[25]->Fill(MissingET_MET[0], weight);
          histo[26]->Fill(mt, weight);
          histo[27]->Fill(reco_jets.size(), weight);
          histo[28]->Fill(reco_bjets.size(), weight);
          if(ScalarHT_HT[0]>500 && reco_bjets.size()==2){
            histo[239]->Fill(MissingET_MET[0], weight);
          }
        }
        if(reco_fatjetsmatch.size()==0 && reco_resbbjets.size()>0 && ScalarHT_HT[0]>500 && reco_bjets.size()==2){
          histo[240]->Fill(MissingET_MET[0], weight);
        }
      }//

      //NbJ>2
        if(reco_bjets.size()>2){
        histo[29]->Fill(MissingET_MET[0], weight);
        histo[30]->Fill(mt, weight);
        histo[31]->Fill(reco_jets.size(), weight);
        histo[32]->Fill(reco_bjets.size(), weight);
        if(ScalarHT_HT[0]>500){
          histo[229]->Fill(MissingET_MET[0], weight);
          if(reco_resbbjets.size()>0){
            histo[241]->Fill(MissingET_MET[0], weight);
            for(int s=0; s<reco_resbbjets.size(); s++){
              if(reco_resbbjets.at(s).v.Pt()>200){
                histo[242]->Fill(MissingET_MET[0], weight);
              }
            }
          }
        }
        if(reco_fatjetsmatch.size()>0){
          histo[33]->Fill(MissingET_MET[0], weight);
          histo[34]->Fill(mt, weight);
          histo[35]->Fill(reco_jets.size(), weight);
          histo[36]->Fill(reco_bjets.size(), weight);
          if(ScalarHT_HT[0]>500){
            histo[243]->Fill(MissingET_MET[0], weight);
          }
        }
        if(reco_fatjetsmatch.size()==0 && reco_resbbjets.size()>0 && ScalarHT_HT[0]>500){
          histo[244]->Fill(MissingET_MET[0], weight);
        }

        //
        if(reco_jets.size()>4){
          histo[37]->Fill(MissingET_MET[0], weight);
          histo[38]->Fill(mt, weight);
          histo[39]->Fill(reco_jets.size(), weight);
          histo[40]->Fill(reco_bjets.size(), weight);
          if(ScalarHT_HT[0]>500){
            histo[231]->Fill(MissingET_MET[0], weight);
            if(reco_resbbjets.size()>0){
              histo[245]->Fill(MissingET_MET[0], weight);
              for(int s=0; s<reco_resbbjets.size(); s++){
                if(reco_resbbjets.at(s).v.Pt()>200){
                  histo[246]->Fill(MissingET_MET[0], weight);
                }
              }
            }
          }
          if(reco_fatjetsmatch.size()>0){
            histo[41]->Fill(MissingET_MET[0], weight);
            histo[42]->Fill(mt, weight);
            histo[43]->Fill(reco_jets.size(), weight);
            histo[44]->Fill(reco_bjets.size(), weight);
            if(ScalarHT_HT[0]>500){
              histo[247]->Fill(MissingET_MET[0], weight);
            }
          }
          if(reco_fatjetsmatch.size()==0 && reco_resbbjets.size()>0 && ScalarHT_HT[0]>500){
            histo[248]->Fill(MissingET_MET[0], weight);
          }

        }//
      }//nbj>2

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

        //
        if(reco_jets.size()>4){
          histo[53]->Fill(MissingET_MET[0], weight);
          histo[54]->Fill(mt, weight);
          histo[55]->Fill(reco_jets.size(), weight);
          histo[56]->Fill(reco_bjets.size(), weight);
          if(ScalarHT_HT[0]>500){
            histo[228]->Fill(MissingET_MET[0], weight);
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
            }
            if(reco_resbbjets.size()>0 && reco_bjets.size()==2){
              histo[253]->Fill(MissingET_MET[0], weight);
              for(int s=0; s<reco_resbbjets.size(); s++){
                if(reco_resbbjets.at(s).v.Pt()>200){
                  histo[254]->Fill(MissingET_MET[0], weight);
                }
              }
            }
          }
          if(reco_fatjetsmatch.size()>0){
            histo[57]->Fill(MissingET_MET[0], weight);
            histo[58]->Fill(mt, weight);
            histo[59]->Fill(reco_jets.size(), weight);
            histo[60]->Fill(reco_bjets.size(), weight);
            if(ScalarHT_HT[0]>500 && reco_bjets.size()==2){
              histo[255]->Fill(MissingET_MET[0], weight);
            }
          }
          if(reco_fatjetsmatch.size()==0 && reco_resbbjets.size()>0 && ScalarHT_HT[0]>500 && reco_bjets.size()==2){
            histo[256]->Fill(MissingET_MET[0], weight);
            int NNRbbJpt200=0;
            for(int g=0; g<reco_resbbjets.size(); g++){
              if(reco_resbbjets.at(g).v.Pt()>200){
                NNRbbJpt200 = NNRbbJpt200+1; 
              }
            }
            if(NNRbbJpt200>0){
              histo[272]->Fill(MissingET_MET[0], weight);
            }
          }

        }//

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
          //+++++++++++++++++++++++//
          if(reco_jets.size()>4){
            histo[69]->Fill(MissingET_MET[0], weight);
            histo[70]->Fill(mt, weight);
            histo[71]->Fill(reco_jets.size(), weight);
            histo[72]->Fill(reco_bjets.size(), weight);
            histo[162]->Fill(reco_fatjetsmatch.size(), weight);
            histo[163]->Fill(reco_resbbjets.size(), weight);
            if(ScalarHT_HT[0]>500){
              histo[232]->Fill(MissingET_MET[0], weight);
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
                for(int s=0; s<reco_resbbjets.size(); s++){
                  if(reco_resbbjets.at(s).v.Pt()>200){
                    histo[262]->Fill(MissingET_MET[0], weight);
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
                int NRbbJpt200=0;
                for(int g=0; g<reco_resbbjets.size(); g++){
                  if(reco_resbbjets.at(g).v.Pt()>200){
                    NRbbJpt200 = NRbbJpt200+1; 
                  }
                }
                if(NRbbJpt200>0){
                  histo[271]->Fill(MissingET_MET[0], weight);
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

            //met>200
            if(MissingET_MET[0]>200){
              histo[117]->Fill(MissingET_MET[0], weight);
              histo[118]->Fill(mt, weight);
              histo[119]->Fill(reco_jets.size(), weight);
              histo[120]->Fill(reco_bjets.size(), weight);
              histo[166]->Fill(reco_fatjetsmatch.size(), weight);
              histo[167]->Fill(reco_resbbjets.size(), weight);
              for(int d=0; d<reco_fatjetsmatch.size(); d++){
                histo[168]->Fill(reco_fatjetsmatch.at(d).v.Pt(), weight);
              }
              for(int c=0; c<reco_resbbjets.size(); c++){
                histo[169]->Fill(reco_resbbjets.at(c).v.Pt(), weight);
              }

              if(reco_fatjetsmatch.size()>0){
                histo[121]->Fill(MissingET_MET[0], weight);
                histo[122]->Fill(mt, weight);
                histo[123]->Fill(reco_jets.size(), weight);
                histo[124]->Fill(reco_bjets.size(), weight);
                histo[154]->Fill(MissingET_MET[0], weight);
                histo[155]->Fill(mt, weight);
                histo[156]->Fill(reco_jets.size(), weight);
                histo[157]->Fill(reco_bjets.size(), weight);
              }
              if(reco_fatjetsmatch.size()==0 && reco_resbbjets.size()>0){
                histo[137]->Fill(MissingET_MET[0], weight);
                histo[138]->Fill(mt, weight);
                histo[139]->Fill(reco_jets.size(), weight);
                histo[140]->Fill(reco_bjets.size(), weight);   
                histo[154]->Fill(MissingET_MET[0], weight);
                histo[155]->Fill(mt, weight);
                histo[156]->Fill(reco_jets.size(), weight);
                histo[157]->Fill(reco_bjets.size(), weight);     
                for(int x=0; x<reco_resbbjets.size(); x++){
                  if(reco_resbbjets.at(x).v.Pt()>200){
                    histo[209]->Fill(MissingET_MET[0], weight);
                    histo[210]->Fill(mt, weight);
                    histo[211]->Fill(reco_jets.size(), weight);
                    histo[212]->Fill(reco_bjets.size(), weight);
                  }
                }       
              }
              if(reco_resbbjets.size()>0){
                histo[184]->Fill(MissingET_MET[0], weight);
                histo[185]->Fill(mt, weight);
                histo[186]->Fill(reco_jets.size(), weight);
                histo[187]->Fill(reco_bjets.size(), weight);  
                for(int x=0; x<reco_resbbjets.size(); x++){
                  if(reco_resbbjets.at(x).v.Pt()>200){
                    histo[205]->Fill(MissingET_MET[0], weight);
                    histo[206]->Fill(mt, weight);
                    histo[207]->Fill(reco_jets.size(), weight);
                    histo[208]->Fill(reco_bjets.size(), weight);
                  }
                } 
              }
            }//met200
            //met>250
            if(MissingET_MET[0]>250){
              histo[125]->Fill(MissingET_MET[0], weight);
              histo[126]->Fill(mt, weight);
              histo[127]->Fill(reco_jets.size(), weight);
              histo[128]->Fill(reco_bjets.size(), weight);
              histo[170]->Fill(reco_fatjetsmatch.size(), weight);
              histo[171]->Fill(reco_resbbjets.size(), weight);
              for(int d=0; d<reco_fatjetsmatch.size(); d++){
                histo[172]->Fill(reco_fatjetsmatch.at(d).v.Pt(), weight);
              }
              for(int c=0; c<reco_resbbjets.size(); c++){
                histo[173]->Fill(reco_resbbjets.at(c).v.Pt(), weight);
              }

              if(reco_fatjetsmatch.size()>0){
                histo[129]->Fill(MissingET_MET[0], weight);
                histo[130]->Fill(mt, weight);
                histo[131]->Fill(reco_jets.size(), weight);
                histo[132]->Fill(reco_bjets.size(), weight);
                histo[158]->Fill(MissingET_MET[0], weight);
                histo[159]->Fill(mt, weight);
                histo[160]->Fill(reco_jets.size(), weight);
                histo[161]->Fill(reco_bjets.size(), weight);
              }
              if(reco_fatjetsmatch.size()==0 && reco_resbbjets.size()>0){
                histo[141]->Fill(MissingET_MET[0], weight);
                histo[142]->Fill(mt, weight);
                histo[143]->Fill(reco_jets.size(), weight);
                histo[144]->Fill(reco_bjets.size(), weight);    
                histo[158]->Fill(MissingET_MET[0], weight);
                histo[159]->Fill(mt, weight);
                histo[160]->Fill(reco_jets.size(), weight);
                histo[161]->Fill(reco_bjets.size(), weight);      
                for(int x=0; x<reco_resbbjets.size(); x++){
                  if(reco_resbbjets.at(x).v.Pt()>200){
                    histo[217]->Fill(MissingET_MET[0], weight);
                    histo[218]->Fill(mt, weight);
                    histo[219]->Fill(reco_jets.size(), weight);
                    histo[220]->Fill(reco_bjets.size(), weight);
                  }
                }     
              }
              if(reco_resbbjets.size()>0){
                histo[188]->Fill(MissingET_MET[0], weight);
                histo[189]->Fill(mt, weight);
                histo[190]->Fill(reco_jets.size(), weight);
                histo[191]->Fill(reco_bjets.size(), weight);  
                for(int x=0; x<reco_resbbjets.size(); x++){
                  if(reco_resbbjets.at(x).v.Pt()>200){
                    histo[213]->Fill(MissingET_MET[0], weight);
                    histo[214]->Fill(mt, weight);
                    histo[215]->Fill(reco_jets.size(), weight);
                    histo[216]->Fill(reco_bjets.size(), weight);
                  }
                } 
              }
            }//met250
          }//nj>4
        }//nbj>2

      }//mt>150
    }//mt>100


  }//event selection

    }//0.8
  }



   }//event loop
   this->Output();
}//void loop
//-------------------------------------------
Int_t t1t1_tN2_tN1_1200950800::Output()
{
  TFile *rootfile = new TFile("Hst_t1t1_tN2_tN1_1200950800_opt.root", "RECREATE");

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
  histo[102]->Write();
  histo[103]->Write();
  histo[104]->Write();
  histo[105]->Write();
  histo[106]->Write();
  histo[107]->Write();
  histo[108]->Write();
  histo[109]->Write();
  //histo[110]->Write();
  histo[111]->Write();
  //histo[112]->Write();
  histo[113]->Write();
  histo[114]->Write();
  histo[115]->Write();
  histo[116]->Write();
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
  histo[27]->Write();
  histo[28]->Write();
  histo[29]->Write();
  histo[30]->Write();
  histo[31]->Write();
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
  histo[44]->Write();
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
  histo[117]->Write();
  histo[118]->Write();
  histo[119]->Write();
  histo[120]->Write();
  histo[166]->Write();
  histo[167]->Write();
  histo[168]->Write();
  histo[169]->Write();
  histo[121]->Write();
  histo[122]->Write();
  histo[123]->Write();
  histo[124]->Write();
  histo[137]->Write();
  histo[138]->Write();
  histo[139]->Write();
  histo[140]->Write();
  histo[209]->Write();
  histo[210]->Write();
  histo[211]->Write();
  histo[212]->Write();
  histo[154]->Write();
  histo[155]->Write();
  histo[156]->Write();
  histo[157]->Write();
  histo[184]->Write();
  histo[185]->Write();
  histo[186]->Write();
  histo[187]->Write();
  histo[205]->Write();
  histo[206]->Write();
  histo[207]->Write();
  histo[208]->Write();
  histo[125]->Write();
  histo[126]->Write();
  histo[127]->Write();
  histo[128]->Write();
  histo[170]->Write();
  histo[171]->Write();
  histo[172]->Write();
  histo[173]->Write();
  histo[129]->Write();
  histo[130]->Write();
  histo[131]->Write();
  histo[132]->Write();
  histo[141]->Write();
  histo[142]->Write();
  histo[143]->Write();
  histo[144]->Write();
  histo[217]->Write();
  histo[218]->Write();
  histo[219]->Write();
  histo[220]->Write();
  histo[158]->Write();
  histo[159]->Write();
  histo[160]->Write();
  histo[161]->Write();
  histo[188]->Write();
  histo[189]->Write();
  histo[190]->Write();
  histo[191]->Write();
  histo[213]->Write();
  histo[214]->Write();
  histo[215]->Write();
  histo[216]->Write();

  histo[221]->Write();
  histo[222]->Write();
  histo[223]->Write();
  histo[224]->Write();
  histo[225]->Write();
  histo[226]->Write();
  histo[227]->Write();
  histo[228]->Write();
  histo[229]->Write();
  histo[230]->Write();
  histo[231]->Write();
  histo[232]->Write();
  histo[266]->Write();
  histo[267]->Write();
  histo[268]->Write();
  histo[269]->Write();

  histo[233]->Write();
  histo[234]->Write();
  histo[235]->Write();
  histo[236]->Write();
  histo[237]->Write();
  histo[238]->Write();
  histo[239]->Write();
  histo[240]->Write();
  histo[241]->Write();
  histo[242]->Write();
  histo[243]->Write();
  histo[244]->Write();
  histo[245]->Write();
  histo[246]->Write();
  histo[247]->Write();
  histo[248]->Write();
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



  rootfile->Write();
  rootfile->Close();

  return 0;
}

//---------------------------------------------------
