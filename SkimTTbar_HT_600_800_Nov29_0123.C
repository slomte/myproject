#define SkimTTbar_HT_600_800_Nov29_0123_cxx
#include "SkimTTbar_HT_600_800_Nov29_0123.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

//*******
#include <TH1.h>
#include <TMath.h>
#include <TLorentzVector.h>
#include <iostream>

void SkimTTbar_HT_600_800_Nov29_0123::Loop()
{
//   In a ROOT session, you can do:
//      root> .L SkimTTbar_HT_600_800_Nov29_0123.C
//      root> SkimTTbar_HT_600_800_Nov29_0123 t
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

   histo[0] = new TH1D("MET", "MET", 100, 0, 5000);
   histo[1] = new TH1D("MHT", "MHT", 100, 0, 5000);
   histo[2] = new TH1D("HT", "HT", 100, 0, 10000);
   histo[3] = new TH1D("Nj", "NJets", 30, 0, 30);
   histo[4] = new TH1D("Nbj", "NbJets", 20, 0, 20);
   histo[5] = new TH1D("Nl", "Nleps", 5, 0, 5);

   //event selections: 0l + met>100 + NJ>=2 + NbJ>=2 
   //0l
   histo[6] = new TH1D("MET_0l", "MET [0l]", 100, 0, 5000);
   histo[7] = new TH1D("MHT_0l", "MHT [0l]", 100, 0, 5000);
   histo[8] = new TH1D("HT_0l", "HT [0l]", 100, 0, 10000);
   histo[9] = new TH1D("Nj_0l", "NJets [0l]", 30, 0, 30);
   histo[10] = new TH1D("Nbj_0l", "NbJets [0l]", 20, 0, 20);   
   //0l + met>100
   histo[11] = new TH1D("MHT_0lmet100", "MHT [0l+met>100]", 100, 0, 5000);
   histo[12] = new TH1D("HT_0lmet100", "HT [0l+met>100]", 100, 0, 10000);
   histo[13] = new TH1D("Nj_0lmet100", "NJets [0l+met>100]", 30, 0, 30);
   histo[14] = new TH1D("Nbj_0lmet100", "NbJets [0l+met>100]", 20, 0, 20);   
   //0l + Nj>=2
   histo[15] = new TH1D("MET_0lNJ2", "MET [0l+Nj>=2]", 100, 0, 5000);
   histo[16] = new TH1D("MHT_0lNJ2", "MHT [0l+Nj>=2]", 100, 0, 5000);
   histo[17] = new TH1D("HT_0lNJ2", "HT [0l+Nj>=2]", 100, 0, 10000);
   histo[18] = new TH1D("Nbj_0lNJ2", "NbJets [0l+Nj>=2]", 20, 0, 20);   
   //0l + Nj>=2
   histo[19] = new TH1D("MET_0lNbJ2", "MET [0l+Nbj>=2]", 100, 0, 5000);
   histo[20] = new TH1D("MHT_0lNbJ2", "MHT [0l+Nbj>=2]", 100, 0, 5000);
   histo[21] = new TH1D("HT_0lNbJ2", "HT [0l+Nbj>=2]", 100, 0, 10000);
   histo[22] = new TH1D("Nj_0lNbJ2", "NJets [0l+Nbj>=2]", 30, 0, 30);   
   //N-1 selections
   histo[23] = new TH1D("MET_0lNJ2NbJ2", "MET [0l+Nj>=2+Nbj>=2]", 100, 0, 5000);
   histo[24] = new TH1D("Nj_0lmet100NbJ2", "NJets [0l+met>100+Nbj>=2]", 30, 0, 30);   
   histo[25] = new TH1D("Nbj_0lmet100NJ2", "NbJets [0l+met>100+Nj>=2]", 20, 0, 20);   
   histo[26] = new TH1D("MHT_0lmet100NJ2NbJ2", "MHT [0l+met>100+Nj>=2+Nbj>=2]", 100, 0, 5000);
   histo[27] = new TH1D("HT_0lmet100NJ2NbJ2", "HT [0l+met>100+Nj>=2+Nbj>=2]", 100, 0, 10000);


   //RA2b Selections: 0l + NJ>=4 + NbJ>=2 + HT>300 + MET>300 + dPhi(J12, met)>0.5
   histo[28] = new TH1D("MET_BS", "MET [0l+NJ4+NbJ2+HT300+MET300+dP0.5]", 100, 0, 5000);
   histo[29] = new TH1D("MHT_BS", "MHT [0l+NJ4+NbJ2+HT300+MET300+dP0.5]", 100, 0, 5000);
   histo[30] = new TH1D("HT_BS", "HT [0l+NJ4+NbJ2+HT300+MET300+dP0.5]", 100, 0, 10000);
   histo[31] = new TH1D("Nj_BS", "NJets [0l+NJ4+NbJ2+HT300+MET300+dP0.5]", 30, 0, 30);
   histo[32] = new TH1D("Nbj_BS", "NbJets [0l+NJ4+NbJ2+HT300+MET300+dP0.5]", 20, 0, 20);   

   //Search bins
   histo[33] = new TH1D("MET_NJ45_NbJ2_1", "MET BS + NJ45 + NbJ2 + @1", 100, 0, 5000);
   histo[34] = new TH1D("MET_NJ45_NbJ2_2", "MET BS + NJ45 + NbJ2 + @2", 100, 0, 5000);
   histo[35] = new TH1D("MET_NJ45_NbJ2_3", "MET BS + NJ45 + NbJ2 + @3", 100, 0, 5000);
   histo[36] = new TH1D("MET_NJ45_NbJ2_4", "MET BS + NJ45 + NbJ2 + @4", 100, 0, 5000);
   histo[37] = new TH1D("MET_NJ45_NbJ2_5", "MET BS + NJ45 + NbJ2 + @5", 100, 0, 5000);
   histo[38] = new TH1D("MET_NJ45_NbJ2_6", "MET BS + NJ45 + NbJ2 + @6", 100, 0, 5000);
   histo[39] = new TH1D("MET_NJ45_NbJ2_7", "MET BS + NJ45 + NbJ2 + @7", 100, 0, 5000);
   histo[40] = new TH1D("MET_NJ45_NbJ2_8", "MET BS + NJ45 + NbJ2 + @8", 100, 0, 5000);
   histo[41] = new TH1D("MET_NJ45_NbJ2_9", "MET BS + NJ45 + NbJ2 + @9", 100, 0, 5000);
   histo[42] = new TH1D("MET_NJ45_NbJ2_10", "MET BS + NJ45 + NbJ2 + @10", 100, 0, 5000);

   histo[43] = new TH1D("MET_NJ67_NbJ2_1", "MET BS + NJ67 + NbJ2 + @1", 100, 0, 5000);
   histo[44] = new TH1D("MET_NJ67_NbJ2_2", "MET BS + NJ67 + NbJ2 + @2", 100, 0, 5000);
   histo[45] = new TH1D("MET_NJ67_NbJ2_3", "MET BS + NJ67 + NbJ2 + @3", 100, 0, 5000);
   histo[46] = new TH1D("MET_NJ67_NbJ2_4", "MET BS + NJ67 + NbJ2 + @4", 100, 0, 5000);
   histo[47] = new TH1D("MET_NJ67_NbJ2_5", "MET BS + NJ67 + NbJ2 + @5", 100, 0, 5000);
   histo[48] = new TH1D("MET_NJ67_NbJ2_6", "MET BS + NJ67 + NbJ2 + @6", 100, 0, 5000);
   histo[49] = new TH1D("MET_NJ67_NbJ2_7", "MET BS + NJ67 + NbJ2 + @7", 100, 0, 5000);
   histo[50] = new TH1D("MET_NJ67_NbJ2_8", "MET BS + NJ67 + NbJ2 + @8", 100, 0, 5000);
   histo[51] = new TH1D("MET_NJ67_NbJ2_9", "MET BS + NJ67 + NbJ2 + @9", 100, 0, 5000);
   histo[52] = new TH1D("MET_NJ67_NbJ2_10", "MET BS + NJ67 + NbJ2 + @10", 100, 0, 5000);

   histo[53] = new TH1D("MET_NJ89_NbJ2_1", "MET BS + NJ89 + NbJ2 + @1", 100, 0, 5000);
   histo[54] = new TH1D("MET_NJ89_NbJ2_2", "MET BS + NJ89 + NbJ2 + @2", 100, 0, 5000);
   histo[55] = new TH1D("MET_NJ89_NbJ2_3", "MET BS + NJ89 + NbJ2 + @3", 100, 0, 5000);
   histo[56] = new TH1D("MET_NJ89_NbJ2_4", "MET BS + NJ89 + NbJ2 + @4", 100, 0, 5000);
   histo[57] = new TH1D("MET_NJ89_NbJ2_5", "MET BS + NJ89 + NbJ2 + @5", 100, 0, 5000);
   histo[58] = new TH1D("MET_NJ89_NbJ2_6", "MET BS + NJ89 + NbJ2 + @6", 100, 0, 5000);
   histo[59] = new TH1D("MET_NJ89_NbJ2_7", "MET BS + NJ89 + NbJ2 + @7", 100, 0, 5000);
   histo[60] = new TH1D("MET_NJ89_NbJ2_8", "MET BS + NJ89 + NbJ2 + @8", 100, 0, 5000);
   histo[61] = new TH1D("MET_NJ89_NbJ2_9", "MET BS + NJ89 + NbJ2 + @9", 100, 0, 5000);
   histo[62] = new TH1D("MET_NJ89_NbJ2_10", "MET BS + NJ89 + NbJ2 + @10", 100, 0, 5000);

   histo[63] = new TH1D("MET_NJ10_NbJ2_1", "MET BS + NJ10 + NbJ2 + @1", 100, 0, 5000);
   histo[64] = new TH1D("MET_NJ10_NbJ2_2", "MET BS + NJ10 + NbJ2 + @2", 100, 0, 5000);
   histo[65] = new TH1D("MET_NJ10_NbJ2_3", "MET BS + NJ10 + NbJ2 + @3", 100, 0, 5000);
   histo[66] = new TH1D("MET_NJ10_NbJ2_4", "MET BS + NJ10 + NbJ2 + @4", 100, 0, 5000);
   histo[67] = new TH1D("MET_NJ10_NbJ2_5", "MET BS + NJ10 + NbJ2 + @5", 100, 0, 5000);
   histo[68] = new TH1D("MET_NJ10_NbJ2_6", "MET BS + NJ10 + NbJ2 + @6", 100, 0, 5000);
   histo[69] = new TH1D("MET_NJ10_NbJ2_7", "MET BS + NJ10 + NbJ2 + @7", 100, 0, 5000);
   histo[70] = new TH1D("MET_NJ10_NbJ2_8", "MET BS + NJ10 + NbJ2 + @8", 100, 0, 5000);
   histo[71] = new TH1D("MET_NJ10_NbJ2_9", "MET BS + NJ10 + NbJ2 + @9", 100, 0, 5000);
   histo[72] = new TH1D("MET_NJ10_NbJ2_10", "MET BS + NJ10 + NbJ2 + @10", 100, 0, 5000);

   histo[73] = new TH1D("MET_NJ45_NbJ3_1", "MET BS + NJ45 + NbJ3 + @1", 100, 0, 5000);
   histo[74] = new TH1D("MET_NJ45_NbJ3_2", "MET BS + NJ45 + NbJ3 + @2", 100, 0, 5000);
   histo[75] = new TH1D("MET_NJ45_NbJ3_3", "MET BS + NJ45 + NbJ3 + @3", 100, 0, 5000);
   histo[76] = new TH1D("MET_NJ45_NbJ3_4", "MET BS + NJ45 + NbJ3 + @4", 100, 0, 5000);
   histo[77] = new TH1D("MET_NJ45_NbJ3_5", "MET BS + NJ45 + NbJ3 + @5", 100, 0, 5000);
   histo[78] = new TH1D("MET_NJ45_NbJ3_6", "MET BS + NJ45 + NbJ3 + @6", 100, 0, 5000);
   histo[79] = new TH1D("MET_NJ45_NbJ3_7", "MET BS + NJ45 + NbJ3 + @7", 100, 0, 5000);
   histo[80] = new TH1D("MET_NJ45_NbJ3_8", "MET BS + NJ45 + NbJ3 + @8", 100, 0, 5000);
   histo[81] = new TH1D("MET_NJ45_NbJ3_9", "MET BS + NJ45 + NbJ3 + @9", 100, 0, 5000);
   histo[82] = new TH1D("MET_NJ45_NbJ3_10", "MET BS + NJ45 + NbJ3 + @10", 100, 0, 5000);

   histo[83] = new TH1D("MET_NJ67_NbJ3_1", "MET BS + NJ67 + NbJ3 + @1", 100, 0, 5000);
   histo[84] = new TH1D("MET_NJ67_NbJ3_2", "MET BS + NJ67 + NbJ3 + @2", 100, 0, 5000);
   histo[85] = new TH1D("MET_NJ67_NbJ3_3", "MET BS + NJ67 + NbJ3 + @3", 100, 0, 5000);
   histo[86] = new TH1D("MET_NJ67_NbJ3_4", "MET BS + NJ67 + NbJ3 + @4", 100, 0, 5000);
   histo[87] = new TH1D("MET_NJ67_NbJ3_5", "MET BS + NJ67 + NbJ3 + @5", 100, 0, 5000);
   histo[88] = new TH1D("MET_NJ67_NbJ3_6", "MET BS + NJ67 + NbJ3 + @6", 100, 0, 5000);
   histo[89] = new TH1D("MET_NJ67_NbJ3_7", "MET BS + NJ67 + NbJ3 + @7", 100, 0, 5000);
   histo[90] = new TH1D("MET_NJ67_NbJ3_8", "MET BS + NJ67 + NbJ3 + @8", 100, 0, 5000);
   histo[91] = new TH1D("MET_NJ67_NbJ3_9", "MET BS + NJ67 + NbJ3 + @9", 100, 0, 5000);
   histo[92] = new TH1D("MET_NJ67_NbJ3_10", "MET BS + NJ67 + NbJ3 + @10", 100, 0, 5000);

   histo[93] = new TH1D("MET_NJ89_NbJ3_1", "MET BS + NJ89 + NbJ3 + @1", 100, 0, 5000);
   histo[94] = new TH1D("MET_NJ89_NbJ3_2", "MET BS + NJ89 + NbJ3 + @2", 100, 0, 5000);
   histo[95] = new TH1D("MET_NJ89_NbJ3_3", "MET BS + NJ89 + NbJ3 + @3", 100, 0, 5000);
   histo[96] = new TH1D("MET_NJ89_NbJ3_4", "MET BS + NJ89 + NbJ3 + @4", 100, 0, 5000);
   histo[97] = new TH1D("MET_NJ89_NbJ3_5", "MET BS + NJ89 + NbJ3 + @5", 100, 0, 5000);
   histo[98] = new TH1D("MET_NJ89_NbJ3_6", "MET BS + NJ89 + NbJ3 + @6", 100, 0, 5000);
   histo[99] = new TH1D("MET_NJ89_NbJ3_7", "MET BS + NJ89 + NbJ3 + @7", 100, 0, 5000);
   histo[100] = new TH1D("MET_NJ89_NbJ3_8", "MET BS + NJ89 + NbJ3 + @8", 100, 0, 5000);
   histo[101] = new TH1D("MET_NJ89_NbJ3_9", "MET BS + NJ89 + NbJ3 + @9", 100, 0, 5000);
   histo[102] = new TH1D("MET_NJ89_NbJ3_10", "MET BS + NJ89 + NbJ3 + @10", 100, 0, 5000);

   histo[103] = new TH1D("MET_NJ10_NbJ3_1", "MET BS + NJ10 + NbJ3 + @1", 100, 0, 5000);
   histo[104] = new TH1D("MET_NJ10_NbJ3_2", "MET BS + NJ10 + NbJ3 + @2", 100, 0, 5000);
   histo[105] = new TH1D("MET_NJ10_NbJ3_3", "MET BS + NJ10 + NbJ3 + @3", 100, 0, 5000);
   histo[106] = new TH1D("MET_NJ10_NbJ3_4", "MET BS + NJ10 + NbJ3 + @4", 100, 0, 5000);
   histo[107] = new TH1D("MET_NJ10_NbJ3_5", "MET BS + NJ10 + NbJ3 + @5", 100, 0, 5000);
   histo[108] = new TH1D("MET_NJ10_NbJ3_6", "MET BS + NJ10 + NbJ3 + @6", 100, 0, 5000);
   histo[109] = new TH1D("MET_NJ10_NbJ3_7", "MET BS + NJ10 + NbJ3 + @7", 100, 0, 5000);
   histo[110] = new TH1D("MET_NJ10_NbJ3_8", "MET BS + NJ10 + NbJ3 + @8", 100, 0, 5000);
   histo[111] = new TH1D("MET_NJ10_NbJ3_9", "MET BS + NJ10 + NbJ3 + @9", 100, 0, 5000);
   histo[112] = new TH1D("MET_NJ10_NbJ3_10", "MET BS + NJ10 + NbJ3 + @10", 100, 0, 5000);

   //RbbJ and HbbJ
   histo[113] = new TH1D("NRbbJ_BS", "NRbbJ after BS", 10, 0, 10);
   histo[114] = new TH1D("PT_RbbJ_BS", "p_{T} of RbbJ after BS", 100, 0, 2000);
   histo[115] = new TH1D("M_RbbJ_BS", "M of RbbJ after BS", 100, 0, 1000);
   histo[116] = new TH1D("NHbbJ_BS", "NHbbJ after BS", 10, 0, 10);
   histo[117] = new TH1D("PT_HbbJ_BS", "p_{T} of HbbJ after BS", 100, 0, 2000);
   histo[118] = new TH1D("M_HbbJ_BS", "M of HbbJ after BS", 100, 0, 1000);


   //BS + NHbbJ>0
   histo[119] = new TH1D("MET_H_NJ45_NbJ2_1", "MET BS + NJ45 + NbJ2 + @1 + NHbbJ>0", 100, 0, 5000);
   histo[120] = new TH1D("MET_H_NJ45_NbJ2_2", "MET BS + NJ45 + NbJ2 + @2 + NHbbJ>0", 100, 0, 5000);
   histo[121] = new TH1D("MET_H_NJ45_NbJ2_3", "MET BS + NJ45 + NbJ2 + @3 + NHbbJ>0", 100, 0, 5000);
   histo[122] = new TH1D("MET_H_NJ45_NbJ2_4", "MET BS + NJ45 + NbJ2 + @4 + NHbbJ>0", 100, 0, 5000);
   histo[123] = new TH1D("MET_H_NJ45_NbJ2_5", "MET BS + NJ45 + NbJ2 + @5 + NHbbJ>0", 100, 0, 5000);
   histo[124] = new TH1D("MET_H_NJ45_NbJ2_6", "MET BS + NJ45 + NbJ2 + @6 + NHbbJ>0", 100, 0, 5000);
   histo[125] = new TH1D("MET_H_NJ45_NbJ2_7", "MET BS + NJ45 + NbJ2 + @7 + NHbbJ>0", 100, 0, 5000);
   histo[126] = new TH1D("MET_H_NJ45_NbJ2_8", "MET BS + NJ45 + NbJ2 + @8 + NHbbJ>0", 100, 0, 5000);
   histo[127] = new TH1D("MET_H_NJ45_NbJ2_9", "MET BS + NJ45 + NbJ2 + @9 + NHbbJ>0", 100, 0, 5000);
   histo[128] = new TH1D("MET_H_NJ45_NbJ2_10", "MET BS + NJ45 + NbJ2 + @10 + NHbbJ>0", 100, 0, 5000);

   histo[129] = new TH1D("MET_H_NJ67_NbJ2_1", "MET BS + NJ67 + NbJ2 + @1 + NHbbJ>0", 100, 0, 5000);
   histo[130] = new TH1D("MET_H_NJ67_NbJ2_2", "MET BS + NJ67 + NbJ2 + @2 + NHbbJ>0", 100, 0, 5000);
   histo[131] = new TH1D("MET_H_NJ67_NbJ2_3", "MET BS + NJ67 + NbJ2 + @3 + NHbbJ>0", 100, 0, 5000);
   histo[132] = new TH1D("MET_H_NJ67_NbJ2_4", "MET BS + NJ67 + NbJ2 + @4 + NHbbJ>0", 100, 0, 5000);
   histo[133] = new TH1D("MET_H_NJ67_NbJ2_5", "MET BS + NJ67 + NbJ2 + @5 + NHbbJ>0", 100, 0, 5000);
   histo[134] = new TH1D("MET_H_NJ67_NbJ2_6", "MET BS + NJ67 + NbJ2 + @6 + NHbbJ>0", 100, 0, 5000);
   histo[135] = new TH1D("MET_H_NJ67_NbJ2_7", "MET BS + NJ67 + NbJ2 + @7 + NHbbJ>0", 100, 0, 5000);
   histo[136] = new TH1D("MET_H_NJ67_NbJ2_8", "MET BS + NJ67 + NbJ2 + @8 + NHbbJ>0", 100, 0, 5000);
   histo[137] = new TH1D("MET_H_NJ67_NbJ2_9", "MET BS + NJ67 + NbJ2 + @9 + NHbbJ>0", 100, 0, 5000);
   histo[138] = new TH1D("MET_H_NJ67_NbJ2_10", "MET BS + NJ67 + NbJ2 + @10 + NHbbJ>0", 100, 0, 5000);

   histo[139] = new TH1D("MET_H_NJ89_NbJ2_1", "MET BS + NJ89 + NbJ2 + @1 + NHbbJ>0", 100, 0, 5000);
   histo[140] = new TH1D("MET_H_NJ89_NbJ2_2", "MET BS + NJ89 + NbJ2 + @2 + NHbbJ>0", 100, 0, 5000);
   histo[141] = new TH1D("MET_H_NJ89_NbJ2_3", "MET BS + NJ89 + NbJ2 + @3 + NHbbJ>0", 100, 0, 5000);
   histo[142] = new TH1D("MET_H_NJ89_NbJ2_4", "MET BS + NJ89 + NbJ2 + @4 + NHbbJ>0", 100, 0, 5000);
   histo[143] = new TH1D("MET_H_NJ89_NbJ2_5", "MET BS + NJ89 + NbJ2 + @5 + NHbbJ>0", 100, 0, 5000);
   histo[144] = new TH1D("MET_H_NJ89_NbJ2_6", "MET BS + NJ89 + NbJ2 + @6 + NHbbJ>0", 100, 0, 5000);
   histo[145] = new TH1D("MET_H_NJ89_NbJ2_7", "MET BS + NJ89 + NbJ2 + @7 + NHbbJ>0", 100, 0, 5000);
   histo[146] = new TH1D("MET_H_NJ89_NbJ2_8", "MET BS + NJ89 + NbJ2 + @8 + NHbbJ>0", 100, 0, 5000);
   histo[147] = new TH1D("MET_H_NJ89_NbJ2_9", "MET BS + NJ89 + NbJ2 + @9 + NHbbJ>0", 100, 0, 5000);
   histo[148] = new TH1D("MET_H_NJ89_NbJ2_10", "MET BS + NJ89 + NbJ2 + @10 + NHbbJ>0", 100, 0, 5000);

   histo[149] = new TH1D("MET_H_NJ10_NbJ2_1", "MET BS + NJ10 + NbJ2 + @1 + NHbbJ>0", 100, 0, 5000);
   histo[150] = new TH1D("MET_H_NJ10_NbJ2_2", "MET BS + NJ10 + NbJ2 + @2 + NHbbJ>0", 100, 0, 5000);
   histo[151] = new TH1D("MET_H_NJ10_NbJ2_3", "MET BS + NJ10 + NbJ2 + @3 + NHbbJ>0", 100, 0, 5000);
   histo[152] = new TH1D("MET_H_NJ10_NbJ2_4", "MET BS + NJ10 + NbJ2 + @4 + NHbbJ>0", 100, 0, 5000);
   histo[153] = new TH1D("MET_H_NJ10_NbJ2_5", "MET BS + NJ10 + NbJ2 + @5 + NHbbJ>0", 100, 0, 5000);
   histo[154] = new TH1D("MET_H_NJ10_NbJ2_6", "MET BS + NJ10 + NbJ2 + @6 + NHbbJ>0", 100, 0, 5000);
   histo[155] = new TH1D("MET_H_NJ10_NbJ2_7", "MET BS + NJ10 + NbJ2 + @7 + NHbbJ>0", 100, 0, 5000);
   histo[156] = new TH1D("MET_H_NJ10_NbJ2_8", "MET BS + NJ10 + NbJ2 + @8 + NHbbJ>0", 100, 0, 5000);
   histo[157] = new TH1D("MET_H_NJ10_NbJ2_9", "MET BS + NJ10 + NbJ2 + @9 + NHbbJ>0", 100, 0, 5000);
   histo[158] = new TH1D("MET_H_NJ10_NbJ2_10", "MET BS + NJ10 + NbJ2 + @10 + NHbbJ>0", 100, 0, 5000);

   histo[159] = new TH1D("MET_H_NJ45_NbJ3_1", "MET BS + NJ45 + NbJ3 + @1 + NHbbJ>0", 100, 0, 5000);
   histo[160] = new TH1D("MET_H_NJ45_NbJ3_2", "MET BS + NJ45 + NbJ3 + @2 + NHbbJ>0", 100, 0, 5000);
   histo[161] = new TH1D("MET_H_NJ45_NbJ3_3", "MET BS + NJ45 + NbJ3 + @3 + NHbbJ>0", 100, 0, 5000);
   histo[162] = new TH1D("MET_H_NJ45_NbJ3_4", "MET BS + NJ45 + NbJ3 + @4 + NHbbJ>0", 100, 0, 5000);
   histo[163] = new TH1D("MET_H_NJ45_NbJ3_5", "MET BS + NJ45 + NbJ3 + @5 + NHbbJ>0", 100, 0, 5000);
   histo[164] = new TH1D("MET_H_NJ45_NbJ3_6", "MET BS + NJ45 + NbJ3 + @6 + NHbbJ>0", 100, 0, 5000);
   histo[165] = new TH1D("MET_H_NJ45_NbJ3_7", "MET BS + NJ45 + NbJ3 + @7 + NHbbJ>0", 100, 0, 5000);
   histo[166] = new TH1D("MET_H_NJ45_NbJ3_8", "MET BS + NJ45 + NbJ3 + @8 + NHbbJ>0", 100, 0, 5000);
   histo[167] = new TH1D("MET_H_NJ45_NbJ3_9", "MET BS + NJ45 + NbJ3 + @9 + NHbbJ>0", 100, 0, 5000);
   histo[168] = new TH1D("MET_H_NJ45_NbJ3_10", "MET BS + NJ45 + NbJ3 + @10 + NHbbJ>0", 100, 0, 5000);

   histo[169] = new TH1D("MET_H_NJ67_NbJ3_1", "MET BS + NJ67 + NbJ3 + @1 + NHbbJ>0", 100, 0, 5000);
   histo[170] = new TH1D("MET_H_NJ67_NbJ3_2", "MET BS + NJ67 + NbJ3 + @2 + NHbbJ>0", 100, 0, 5000);
   histo[171] = new TH1D("MET_H_NJ67_NbJ3_3", "MET BS + NJ67 + NbJ3 + @3 + NHbbJ>0", 100, 0, 5000);
   histo[172] = new TH1D("MET_H_NJ67_NbJ3_4", "MET BS + NJ67 + NbJ3 + @4 + NHbbJ>0", 100, 0, 5000);
   histo[173] = new TH1D("MET_H_NJ67_NbJ3_5", "MET BS + NJ67 + NbJ3 + @5 + NHbbJ>0", 100, 0, 5000);
   histo[174] = new TH1D("MET_H_NJ67_NbJ3_6", "MET BS + NJ67 + NbJ3 + @6 + NHbbJ>0", 100, 0, 5000);
   histo[175] = new TH1D("MET_H_NJ67_NbJ3_7", "MET BS + NJ67 + NbJ3 + @7 + NHbbJ>0", 100, 0, 5000);
   histo[176] = new TH1D("MET_H_NJ67_NbJ3_8", "MET BS + NJ67 + NbJ3 + @8 + NHbbJ>0", 100, 0, 5000);
   histo[177] = new TH1D("MET_H_NJ67_NbJ3_9", "MET BS + NJ67 + NbJ3 + @9 + NHbbJ>0", 100, 0, 5000);
   histo[178] = new TH1D("MET_H_NJ67_NbJ3_10", "MET BS + NJ67 + NbJ3 + @10 + NHbbJ>0", 100, 0, 5000);

   histo[179] = new TH1D("MET_H_NJ89_NbJ3_1", "MET BS + NJ89 + NbJ3 + @1 + NHbbJ>0", 100, 0, 5000);
   histo[180] = new TH1D("MET_H_NJ89_NbJ3_2", "MET BS + NJ89 + NbJ3 + @2 + NHbbJ>0", 100, 0, 5000);
   histo[181] = new TH1D("MET_H_NJ89_NbJ3_3", "MET BS + NJ89 + NbJ3 + @3 + NHbbJ>0", 100, 0, 5000);
   histo[182] = new TH1D("MET_H_NJ89_NbJ3_4", "MET BS + NJ89 + NbJ3 + @4 + NHbbJ>0", 100, 0, 5000);
   histo[183] = new TH1D("MET_H_NJ89_NbJ3_5", "MET BS + NJ89 + NbJ3 + @5 + NHbbJ>0", 100, 0, 5000);
   histo[184] = new TH1D("MET_H_NJ89_NbJ3_6", "MET BS + NJ89 + NbJ3 + @6 + NHbbJ>0", 100, 0, 5000);
   histo[185] = new TH1D("MET_H_NJ89_NbJ3_7", "MET BS + NJ89 + NbJ3 + @7 + NHbbJ>0", 100, 0, 5000);
   histo[186] = new TH1D("MET_H_NJ89_NbJ3_8", "MET BS + NJ89 + NbJ3 + @8 + NHbbJ>0", 100, 0, 5000);
   histo[187] = new TH1D("MET_H_NJ89_NbJ3_9", "MET BS + NJ89 + NbJ3 + @9 + NHbbJ>0", 100, 0, 5000);
   histo[188] = new TH1D("MET_H_NJ89_NbJ3_10", "MET BS + NJ89 + NbJ3 + @10 + NHbbJ>0", 100, 0, 5000);

   histo[189] = new TH1D("MET_H_NJ10_NbJ3_1", "MET BS + NJ10 + NbJ3 + @1 + NHbbJ>0", 100, 0, 5000);
   histo[190] = new TH1D("MET_H_NJ10_NbJ3_2", "MET BS + NJ10 + NbJ3 + @2 + NHbbJ>0", 100, 0, 5000);
   histo[191] = new TH1D("MET_H_NJ10_NbJ3_3", "MET BS + NJ10 + NbJ3 + @3 + NHbbJ>0", 100, 0, 5000);
   histo[192] = new TH1D("MET_H_NJ10_NbJ3_4", "MET BS + NJ10 + NbJ3 + @4 + NHbbJ>0", 100, 0, 5000);
   histo[193] = new TH1D("MET_H_NJ10_NbJ3_5", "MET BS + NJ10 + NbJ3 + @5 + NHbbJ>0", 100, 0, 5000);
   histo[194] = new TH1D("MET_H_NJ10_NbJ3_6", "MET BS + NJ10 + NbJ3 + @6 + NHbbJ>0", 100, 0, 5000);
   histo[195] = new TH1D("MET_H_NJ10_NbJ3_7", "MET BS + NJ10 + NbJ3 + @7 + NHbbJ>0", 100, 0, 5000);
   histo[196] = new TH1D("MET_H_NJ10_NbJ3_8", "MET BS + NJ10 + NbJ3 + @8 + NHbbJ>0", 100, 0, 5000);
   histo[197] = new TH1D("MET_H_NJ10_NbJ3_9", "MET BS + NJ10 + NbJ3 + @9 + NHbbJ>0", 100, 0, 5000);
   histo[198] = new TH1D("MET_H_NJ10_NbJ3_10", "MET BS + NJ10 + NbJ3 + @10 + NHbbJ>0", 100, 0, 5000);

//---------------------------------------------------------------
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      if(ientry%100000==0)cout<<"Processed "<<ientry<<" event..."<<endl;
//--------------------------------------------------------------      

      reco_jets.clear();
      reco_bjets.clear();
      reco_leps.clear();
      reco_RbbJ.clear();
      reco_HbbJ.clear();
//-------------------------------------------

  //mycode
  //cout<<"evt"<<endl;
  float Wt = (CrossSection*150000)/nentries;
  
  //MET
  histo[0]->Fill(MET, Wt);
  histo[1]->Fill(MHT, Wt);
  histo[2]->Fill(HT, Wt);

  
  //Jets
  int Njets = Jets->size();
  for(int i=0; i<Njets; i++){
    if( Jets->at(i).Pt()>30 && abs(Jets->at(i).Eta())<2.4 ){
      reco_jets.push_back(Jets->at(i));
      
      //b-jets
      if( Jets_bDiscriminatorCSV->at(i) > 0.8484 ){
        reco_bjets.push_back(Jets->at(i));
      }
      //
    }
  }
  
  int NJ = reco_jets.size();
  histo[3]->Fill(NJ, Wt);
  int NbJ = reco_bjets.size();
  histo[4]->Fill(NbJ, Wt);
  
  
  //Lepton
  int Nlep = Electrons->size() + Muons->size();
  int Nelec = Electrons->size(); int Nmuon = Muons->size();
  for( int i=0; i<Nelec; i++ ){
    if( Electrons->at(i).Pt()>10 && abs(Electrons->at(i).Eta())<2.5 ){
      reco_leps.push_back(Electrons->at(i));
    }
  }

  for( int i=0; i<Nmuon; i++ ){
    if( Muons->at(i).Pt()>10 && abs(Muons->at(i).Eta())<2.4 ){
      reco_leps.push_back(Muons->at(i));
    }
  }

  int Nl = reco_leps.size();
  histo[5]->Fill(Nl, Wt);


  //event selections: 0l + met>100 + Nj>=2 + NbJ>=2
  if(Nl==0){
    histo[6]->Fill(MET, Wt);
    histo[7]->Fill(MHT, Wt);
    histo[8]->Fill(HT, Wt);
    histo[9]->Fill(NJ, Wt);
    histo[10]->Fill(NbJ, Wt);
    //met>100
    if(MET>100){
      histo[11]->Fill(MHT, Wt);
      histo[12]->Fill(HT, Wt);
      histo[13]->Fill(NJ, Wt);
      histo[14]->Fill(NbJ, Wt);
    }
    //NJ>=2
    if(NJ>=2){
      histo[15]->Fill(MET, Wt);
      histo[16]->Fill(MHT, Wt);
      histo[17]->Fill(HT, Wt);
      histo[18]->Fill(NbJ, Wt);
    }
    //NbJ>=2
    if(NbJ>=2){
      histo[19]->Fill(MET, Wt);
      histo[20]->Fill(MHT, Wt);
      histo[21]->Fill(HT, Wt);
      histo[22]->Fill(NJ, Wt);
    }
  }

  //n-1 selections
  if(Nl==0 && NJ>=2 && NbJ>=2){
    histo[23]->Fill(MET, Wt);
  }
  if(Nl==0 && MET>100 && NbJ>=2){
    histo[24]->Fill(NJ, Wt);
  }
  if(Nl==0 && NJ>=2 && MET>100){
    histo[25]->Fill(NbJ, Wt);
  }
  if(Nl==0 && NJ>=2 && NbJ>=2 && MET>100){
    histo[26]->Fill(MHT, Wt);
    histo[27]->Fill(HT, Wt);
  }
  
  //------------------------------------------
  //RA2b Selections: 0l + NJ>=4 + NbJ>=2 + HT>300 + MET>300 + dPhi(J12, met)>0.5
  if(Nl==0 && NJ>=4 && NbJ>=2 && HT>=300 && MET>=300){
    float dP1 = abs( reco_jets.at(0).Phi() - METPhi );
    if(dP1>TMath::Pi()) {dP1 = 2*TMath::Pi() - dP1;}
    float dP2 = abs( reco_jets.at(1).Phi() - METPhi );
    if(dP2>TMath::Pi()) {dP2 = 2*TMath::Pi() - dP2;}
    //    
    if(dP1>0.5 && dP2>0.5){
      histo[28]->Fill(MET, Wt);
      histo[29]->Fill(MHT, Wt);
      histo[30]->Fill(HT, Wt);
      histo[31]->Fill(NJ, Wt);
      histo[32]->Fill(NbJ, Wt);
      
      //Rbb jet
      for(int j=0; j<NbJ; j++){
	for(int k=j+1; k<NbJ; k++){
	  TLorentzVector RbbJ = (reco_bjets.at(j) + reco_bjets.at(k));
	  float RbbJ_PT = RbbJ.Pt();
	  float RbbJ_M = RbbJ.M(); 
          histo[114]->Fill(RbbJ_PT, Wt);
          histo[115]->Fill(RbbJ_M, Wt);
          reco_RbbJ.push_back(RbbJ);
	}
      }
      int NRbbJ = reco_RbbJ.size();
      histo[113]->Fill(NRbbJ, Wt);
      
      //HbbJ
      if(NRbbJ>0){
	for(int h=0; h<NRbbJ; h++){
	  if(reco_RbbJ.at(h).M()>100 && reco_RbbJ.at(h).M()<150){
	    float HbbJ_PT = reco_RbbJ.at(h).Pt();
	    float HbbJ_M = reco_RbbJ.at(h).M(); 	    
            histo[117]->Fill(HbbJ_PT, Wt);
            histo[118]->Fill(HbbJ_M, Wt);
	    reco_HbbJ.push_back(reco_RbbJ.at(h));	     
	  }
	}
      }
      int NHbbJ = reco_HbbJ.size();
      histo[116]->Fill(NHbbJ, Wt);

      //Search bins*****
      //NJ45 NbJ2
      if((NJ==4 || NJ==5) && (NbJ==2)){
	if(HT>300 && HT<600 && MET>300 && MET<350){
	  histo[33]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[119]->Fill(MET, Wt);}
	}
	if(HT>600 && HT<1200 && MET>300 && MET<350){
	  histo[34]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[120]->Fill(MET, Wt);}
	}
	if(HT>1200 && MET>300 && MET<350){
	  histo[35]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[121]->Fill(MET, Wt);}
	}
	if(HT>350 && HT<600 && MET>350 && MET<600){
	  histo[36]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[122]->Fill(MET, Wt);}
	}
	if(HT>600 && HT<1200 && MET>350 && MET<600){
	  histo[37]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[123]->Fill(MET, Wt);}
	}
	if(HT>1200 && MET>350 && MET<600){
	  histo[38]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[124]->Fill(MET, Wt);}
	}
	if(HT>600 && HT<1200 && MET>600 && MET<850){
	  histo[39]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[125]->Fill(MET, Wt);}
	}
	if(HT>1200 && MET>600 && MET<850){
	  histo[40]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[126]->Fill(MET, Wt);}
	}
	if(HT>850 && HT<1700 && MET>850){
	  histo[41]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[127]->Fill(MET, Wt);}
	}				
	if(HT>1700 && MET>850){
	  histo[42]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[128]->Fill(MET, Wt);}
	}
      }//NJ45 NbJ2

      //NJ45 NbJ3
      if((NJ==4 || NJ==5) && (NbJ>=3)){
	if(HT>300 && HT<600 && MET>300 && MET<350){
	  histo[43]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[129]->Fill(MET, Wt);}
	}
	if(HT>600 && HT<1200 && MET>300 && MET<350){
	  histo[44]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[130]->Fill(MET, Wt);}
	}
	if(HT>1200 && MET>300 && MET<350){
	  histo[45]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[131]->Fill(MET, Wt);}
	}
	if(HT>350 && HT<600 && MET>350 && MET<600){
	  histo[46]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[132]->Fill(MET, Wt);}
	}
	if(HT>600 && HT<1200 && MET>350 && MET<600){
	  histo[47]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[133]->Fill(MET, Wt);}
	}
	if(HT>1200 && MET>350 && MET<600){
	  histo[48]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[134]->Fill(MET, Wt);}
	}
	if(HT>600 && HT<1200 && MET>600 && MET<850){
	  histo[49]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[135]->Fill(MET, Wt);}
	}
	if(HT>1200 && MET>600 && MET<850){
	  histo[50]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[136]->Fill(MET, Wt);}
	}
	if(HT>850 && HT<1700 && MET>850){
	  histo[51]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[137]->Fill(MET, Wt);}
	}				
	if(HT>1700 && MET>850){
	  histo[52]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[138]->Fill(MET, Wt);}
	}
      }//NJ45 NbJ3

      //NJ67 NbJ2
      if((NJ==6 || NJ==7) && (NbJ==2)){
	if(HT>300 && HT<600 && MET>300 && MET<350){
	  histo[53]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[139]->Fill(MET, Wt);}
	}
	if(HT>600 && HT<1200 && MET>300 && MET<350){
	  histo[54]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[140]->Fill(MET, Wt);}
	}
	if(HT>1200 && MET>300 && MET<350){
	  histo[55]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[141]->Fill(MET, Wt);}
	}
	if(HT>350 && HT<600 && MET>350 && MET<600){
	  histo[56]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[142]->Fill(MET, Wt);}
	}
	if(HT>600 && HT<1200 && MET>350 && MET<600){
	  histo[57]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[143]->Fill(MET, Wt);}
	}
	if(HT>1200 && MET>350 && MET<600){
	  histo[58]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[144]->Fill(MET, Wt);}
	}
	if(HT>600 && HT<1200 && MET>600 && MET<850){
	  histo[59]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[145]->Fill(MET, Wt);}
	}
	if(HT>1200 && MET>600 && MET<850){
	  histo[60]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[146]->Fill(MET, Wt);}
	}
	if(HT>850 && HT<1700 && MET>850){
	  histo[61]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[147]->Fill(MET, Wt);}
	}				
	if(HT>1700 && MET>850){
	  histo[62]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[148]->Fill(MET, Wt);}
	}
      }//NJ67 NbJ2

      //NJ67 NbJ3
      if((NJ==6 || NJ==7) && (NbJ>=3)){
	if(HT>300 && HT<600 && MET>300 && MET<350){
	  histo[63]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[149]->Fill(MET, Wt);}
	}
	if(HT>600 && HT<1200 && MET>300 && MET<350){
	  histo[64]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[150]->Fill(MET, Wt);}
	}
	if(HT>1200 && MET>300 && MET<350){
	  histo[65]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[151]->Fill(MET, Wt);}
	}
	if(HT>350 && HT<600 && MET>350 && MET<600){
	  histo[66]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[152]->Fill(MET, Wt);}
	}
	if(HT>600 && HT<1200 && MET>350 && MET<600){
	  histo[67]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[153]->Fill(MET, Wt);}
	}
	if(HT>1200 && MET>350 && MET<600){
	  histo[68]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[154]->Fill(MET, Wt);}
	}
	if(HT>600 && HT<1200 && MET>600 && MET<850){
	  histo[69]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[155]->Fill(MET, Wt);}
	}
	if(HT>1200 && MET>600 && MET<850){
	  histo[70]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[156]->Fill(MET, Wt);}
	}
	if(HT>850 && HT<1700 && MET>850){
	  histo[71]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[157]->Fill(MET, Wt);}
	}				
	if(HT>1700 && MET>850){
	  histo[72]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[158]->Fill(MET, Wt);}
	}
      }//NJ67 NbJ3

      //NJ89 NbJ2
      if((NJ==8 || NJ==9) && (NbJ==2)){
	if(HT>300 && HT<600 && MET>300 && MET<350){
	  histo[73]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[159]->Fill(MET, Wt);}
	}
	if(HT>600 && HT<1200 && MET>300 && MET<350){
	  histo[74]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[160]->Fill(MET, Wt);}
	}
	if(HT>1200 && MET>300 && MET<350){
	  histo[75]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[161]->Fill(MET, Wt);}
	}
	if(HT>350 && HT<600 && MET>350 && MET<600){
	  histo[76]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[162]->Fill(MET, Wt);}
	}
	if(HT>600 && HT<1200 && MET>350 && MET<600){
	  histo[77]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[163]->Fill(MET, Wt);}
	}
	if(HT>1200 && MET>350 && MET<600){
	  histo[78]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[164]->Fill(MET, Wt);}
	}
	if(HT>600 && HT<1200 && MET>600 && MET<850){
	  histo[79]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[165]->Fill(MET, Wt);}
	}
	if(HT>1200 && MET>600 && MET<850){
	  histo[80]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[166]->Fill(MET, Wt);}
	}
	if(HT>850 && HT<1700 && MET>850){
	  histo[81]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[167]->Fill(MET, Wt);}
	}				
	if(HT>1700 && MET>850){
	  histo[82]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[168]->Fill(MET, Wt);}
	}
      }//NJ89 NbJ2

      //NJ89 NbJ3
      if((NJ==8 || NJ==9) && (NbJ>=3)){
	if(HT>300 && HT<600 && MET>300 && MET<350){
	  histo[83]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[169]->Fill(MET, Wt);}
	}
	if(HT>600 && HT<1200 && MET>300 && MET<350){
	  histo[84]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[170]->Fill(MET, Wt);}
	}
	if(HT>1200 && MET>300 && MET<350){
	  histo[85]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[171]->Fill(MET, Wt);}
	}
	if(HT>350 && HT<600 && MET>350 && MET<600){
	  histo[86]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[172]->Fill(MET, Wt);}
	}
	if(HT>600 && HT<1200 && MET>350 && MET<600){
	  histo[87]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[173]->Fill(MET, Wt);}
	}
	if(HT>1200 && MET>350 && MET<600){
	  histo[88]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[174]->Fill(MET, Wt);}
	}
	if(HT>600 && HT<1200 && MET>600 && MET<850){
	  histo[89]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[175]->Fill(MET, Wt);}
	}
	if(HT>1200 && MET>600 && MET<850){
	  histo[90]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[176]->Fill(MET, Wt);}
	}
	if(HT>850 && HT<1700 && MET>850){
	  histo[91]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[177]->Fill(MET, Wt);}
	}				
	if(HT>1700 && MET>850){
	  histo[92]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[178]->Fill(MET, Wt);}
	}
      }//NJ89 NbJ3

      //NJ10 NbJ2
      if(NJ==10 && NbJ==2){
	if(HT>300 && HT<600 && MET>300 && MET<350){
	  histo[93]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[179]->Fill(MET, Wt);}
	}
	if(HT>600 && HT<1200 && MET>300 && MET<350){
	  histo[94]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[180]->Fill(MET, Wt);}
	}
	if(HT>1200 && MET>300 && MET<350){
	  histo[95]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[181]->Fill(MET, Wt);}
	}
	if(HT>350 && HT<600 && MET>350 && MET<600){
	  histo[96]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[182]->Fill(MET, Wt);}
	}
	if(HT>600 && HT<1200 && MET>350 && MET<600){
	  histo[97]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[183]->Fill(MET, Wt);}
	}
	if(HT>1200 && MET>350 && MET<600){
	  histo[98]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[184]->Fill(MET, Wt);}
	}
	if(HT>600 && HT<1200 && MET>600 && MET<850){
	  histo[99]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[185]->Fill(MET, Wt);}
	}
	if(HT>1200 && MET>600 && MET<850){
	  histo[100]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[186]->Fill(MET, Wt);}
	}
	if(HT>850 && HT<1700 && MET>850){
	  histo[101]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[187]->Fill(MET, Wt);}
	}				
	if(HT>1700 && MET>850){
	  histo[102]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[188]->Fill(MET, Wt);}
	}
      }//NJ10 NbJ2

      //NJ10 NbJ3
      if(NJ==10 && NbJ>=3){
	if(HT>300 && HT<600 && MET>300 && MET<350){
	  histo[103]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[189]->Fill(MET, Wt);}
	}
	if(HT>600 && HT<1200 && MET>300 && MET<350){
	  histo[104]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[190]->Fill(MET, Wt);}
	}
	if(HT>1200 && MET>300 && MET<350){
	  histo[105]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[191]->Fill(MET, Wt);}
	}
	if(HT>350 && HT<600 && MET>350 && MET<600){
	  histo[106]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[192]->Fill(MET, Wt);}
	}
	if(HT>600 && HT<1200 && MET>350 && MET<600){
	  histo[107]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[193]->Fill(MET, Wt);}
	}
	if(HT>1200 && MET>350 && MET<600){
	  histo[108]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[194]->Fill(MET, Wt);}
	}
	if(HT>600 && HT<1200 && MET>600 && MET<850){
	  histo[109]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[195]->Fill(MET, Wt);}
	}
	if(HT>1200 && MET>600 && MET<850){
	  histo[110]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[196]->Fill(MET, Wt);}
	}
	if(HT>850 && HT<1700 && MET>850){
	  histo[111]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[197]->Fill(MET, Wt);}
	}				
	if(HT>1700 && MET>850){
	  histo[112]->Fill(MET, Wt);
	  if(NHbbJ>0){histo[198]->Fill(MET, Wt);}
	}
      }//NJ10 NbJ3



    }//dP()>0.5
  }//RA2b selec
  
	 
   }//event loop
   this->Output();
}//void loop
//-------------------------------------------
Int_t SkimTTbar_HT_600_800_Nov29_0123::Output()
{
  TFile *rootfile = new TFile("Hst_SkimTTbar_HT_600_800_Nov29_0123_opt.root", "RECREATE");

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
  histo[102]->Write();
  histo[103]->Write();
  histo[104]->Write();
  histo[105]->Write();
  histo[106]->Write();
  histo[107]->Write();
  histo[108]->Write();
  histo[109]->Write();
  histo[110]->Write();
  histo[111]->Write();
  histo[112]->Write();
  histo[113]->Write();
  histo[114]->Write();
  histo[115]->Write();
  histo[116]->Write();
  histo[117]->Write();
  histo[118]->Write();
  histo[119]->Write();
  histo[120]->Write();
  histo[121]->Write();
  histo[122]->Write();
  histo[123]->Write();
  histo[124]->Write();
  histo[125]->Write();
  histo[126]->Write();
  histo[127]->Write();
  histo[128]->Write();
  histo[129]->Write();
  histo[130]->Write();
  histo[131]->Write();
  histo[132]->Write();
  histo[133]->Write();
  histo[134]->Write();
  histo[135]->Write();
  histo[136]->Write();
  histo[137]->Write();
  histo[138]->Write();
  histo[139]->Write();
  histo[140]->Write();
  histo[141]->Write();
  histo[142]->Write();
  histo[143]->Write();
  histo[144]->Write();
  histo[145]->Write();
  histo[146]->Write();
  histo[147]->Write();
  histo[148]->Write();
  histo[149]->Write();
  histo[150]->Write();
  histo[151]->Write();
  histo[152]->Write();
  histo[153]->Write();
  histo[154]->Write();
  histo[155]->Write();
  histo[156]->Write();
  histo[157]->Write();
  histo[158]->Write();
  histo[159]->Write();
  histo[160]->Write();
  histo[161]->Write();
  histo[162]->Write();
  histo[163]->Write();
  histo[164]->Write();
  histo[165]->Write();
  histo[166]->Write();
  histo[167]->Write();
  histo[168]->Write();
  histo[169]->Write();
  histo[170]->Write();
  histo[171]->Write();
  histo[172]->Write();
  histo[173]->Write();
  histo[174]->Write();
  histo[175]->Write();
  histo[176]->Write();
  histo[177]->Write();
  histo[178]->Write();
  histo[179]->Write();
  histo[180]->Write();
  histo[181]->Write();
  histo[182]->Write();
  histo[183]->Write();
  histo[184]->Write();
  histo[185]->Write();
  histo[186]->Write();
  histo[187]->Write();
  histo[188]->Write();
  histo[189]->Write();
  histo[190]->Write();
  histo[191]->Write();
  histo[192]->Write();
  histo[193]->Write();
  histo[194]->Write();
  histo[195]->Write();
  histo[196]->Write();
  histo[197]->Write();
  histo[198]->Write();




  rootfile->Write();
  rootfile->Close();

  return 0;
}

//---------------------------------------------------
