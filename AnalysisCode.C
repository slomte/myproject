/*
Simple macro showing how to access branches from the delphes output root file,
loop over events, and plot simple quantities such as the jet pt and the di-electron invariant
mass.

root -l examples/Example1.C'("delphes_output.root")'
*/

#ifdef __CLING__
R__LOAD_LIBRARY(libDelphes)
#include "/home/work/slomte/Work/EventGeneration/MG5_aMC_v2_6_3_2/Delphes/external/ExRootAnalysis/ExRootTreeReader.h"
#include "/home/work/slomte/Work/EventGeneration/MG5_aMC_v2_6_3_2/Delphes/classes/DelphesClasses.h"
class ExRootTreeReader;
#endif

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TMath.h>
#include <vector>
#include <TLorentzVector.h>
#include <iostream>
#include "TVector.h"
#include "TVector2.h"
#include "TVector3.h"
//------------------------------------------------------------------------------

class ExRootTreeReader;
using namespace std;


void Example1(const char *inputFile)
{
  gSystem->Load("libDelphes");

  // Create chain of root trees
  TChain chain("Delphes");
  chain.Add(inputFile);

  // Create object of class ExRootTreeReader
  ExRootTreeReader *treeReader = new ExRootTreeReader(&chain);
  Long64_t numberOfEntries = treeReader->GetEntries();

  // Get pointers to branches used in this analysis
  TClonesArray *branchJet = treeReader->UseBranch("Jet");
  TClonesArray *branchElectron = treeReader->UseBranch("Electron");
  TClonesArray *branchMuon = treeReader->UseBranch("Muon");
  TClonesArray *branchFatJet = treeReader->UseBranch("FatJet");
  TClonesArray *branchMissingET = treeReader->UseBranch("MissingET");
  TClonesArray *branchScalarHT = treeReader->UseBranch("ScalarHT");
  TClonesArray *branchPar = treeReader->UseBranch("Particle");


  vector <TLorentzVector> leptons;
  vector <TLorentzVector> jets;
  vector <TLorentzVector> bjets;
  vector <TLorentzVector> fatjet_candi;
  vector <TLorentzVector> fatjet_Htag;
  vector <TLorentzVector> fatjet_SD_candi;
  vector <TLorentzVector> fatjet_SD_Htag;
  vector <TLorentzVector> fatjet_SD_Hmatch;
  vector <TLorentzVector> fatjet_SD_Hmatch_Htag;
  vector <TLorentzVector> fatjet_SD_Wmatch;
  vector <TLorentzVector> fatjet_SD_Wmatch_Wtag;
  vector <TLorentzVector> fatjet_SD_tmatch;
  vector <TLorentzVector> fatjet_SD_tmatch_ttag;
  vector <TLorentzVector> fatjet_SD_nomatch;

  vector <TLorentzVector> fatjat_SD_sj12matchbq;
  vector <TLorentzVector> fatjat_SD_sj12matchbq_Htag;
  vector <TLorentzVector> bquarksH;
  vector <TLorentzVector> Higgs;
  vector <TLorentzVector> genW;
  vector <TLorentzVector> gentop;
  vector <TLorentzVector> res_bbjets;
  vector <TLorentzVector> res_bbjets_Htag;
  vector <TLorentzVector> res_bbjets_Hmatch;
  vector <TLorentzVector> res_bbjets_Hmatch_Htag;

  vector <float> dM_FJ_H;
  vector <float> dM_RJ_H;



  float delta_phi(float phi1, float phi2);
  float delta_eta(float eta1, float eta2);
  Double_t delR(TLorentzVector v1,  TLorentzVector v2);


  // Book histograms

  double Wt = (6.83*150)/numberOfEntries;
  TFile f("Hst_t1t1_tN2_tN1_1000720200_1_opt.root","RECREATE");


  TH1F hist_t1_Pt("PT_t1", "p_{T} of ~t1", 100, 0, 2000);
  TH1F hist_t_Pt("PT_t", "p_{T} of t", 100, 0, 2000);
  TH1F hist_N2_t_Pt("PT_N2", "p_{T} of N2", 100, 0, 2000);
  TH1F hist_N1_t1_Pt("PT_N1_t1", "p_{T} of N1 from ~t1", 100, 0, 2000);
  TH1F hist_N1_N2_Pt("PT_N1_N2", "p_{T} of N1 from N2", 100, 0, 2000);
  TH1F hist_H_N2_Pt("PT_H_N2", "p_{T} of H from N2", 100, 0, 2000);
  TH1F hist_b_t_Pt("PT_b_t", "p_{T} of b from t", 100, 0, 2000);
  TH1F hist_W_t_Pt("PT_W_t", "p_{T} of W from t", 100, 0, 2000);
  TH1F hist_b_H_Pt("PT_b_H", "p_{T} of b from H", 100, 0, 2000);

  TH1F Nlep("Nleps", "Nleps", 10, 0, 10);
  TH1F NJet("Njets", "NJets", 20, 0, 20);
  TH1F NbJet("Nbjets", "NbJets", 10, 0, 10);
  TH1F h_FJ_C_Pt("PT_FJ_Candi", "p_{T} of Candidate FJ", 100, 0, 2000);
  TH1F h_FJ_C_M("M_FJ_Candi", "M of Candidate FJ", 200, 0, 1000);
  TH1F h_FJ_Htag_Pt("PT_FJ_Htag", "p_{T} of FJ Htag", 100, 0, 2000);
  TH1F h_FJ_Htag_M("M_FJ_Htag", "M of FJ Htag", 40, 0, 200);
  TH1F h_FJSD_C_Pt("PT_FJC_SD", "p_{T} of FJ SD", 100, 0, 2000);
  TH1F h_FJSD_C_M("M_FJC_SD", "M of FJ SD", 200, 0, 1000);
  TH1F h_FJSD_Htag_Pt("PT_FJ_SD_Htag", "p_{T} of FJ SD and Htag", 100, 0, 2000);
  TH1F h_FJSD_Htag_M("M_FJ_SD_Htag", "M of FJ SD and Htag", 40, 0, 200);
  TH1F h_FJSD_Hmatch_Pt("PT_FJ_SD_Hmatch", "p_{T} of FJ SD and Hmatch", 100, 0, 2000);
  TH1F h_FJSD_Hmatch_M("M_FJ_SD_Hmatch", "M of FJ SD and Hmatch", 200, 0, 1000);
  TH1F h_FJSD_Hmatch_Htag_Pt("PT_FJ_SD_Hmatch_Htag", "p_{T} of FJ SD and Hmatch and Htag", 100, 0, 2000);
  TH1F h_FJSD_Hmatch_Htag_M("M_FJ_SD_Hmatch_Htag", "M of FJ SD and Hmatch and Htag", 40, 0, 200);
  TH1F h_FJSD_Wmatch_Pt("PT_FJ_SD_Wmatch", "p_{T} of FJ SD and Wmatch", 100, 0, 2000);
  TH1F h_FJSD_Wmatch_M("M_FJ_SD_Wmatch", "M of FJ SD and Wmatch", 200, 0, 1000);
  TH1F h_FJSD_Wmatch_Wtag_Pt("PT_FJ_SD_Wmatch_Wtag", "p_{T} of FJ SD and Wmatch and Wtag", 100, 0, 2000);
  TH1F h_FJSD_Wmatch_Wtag_M("M_FJ_SD_Wmatch_Wtag", "M of FJ SD and Wmatch and Wtag", 40, 0, 200);
  TH1F h_FJSD_tmatch_Pt("PT_FJ_SD_tmatch", "p_{T} of FJ SD and tmatch", 100, 0, 2000);
  TH1F h_FJSD_tmatch_M("M_FJ_SD_tmatch", "M of FJ SD and tmatch", 200, 0, 1000);
  TH1F h_FJSD_tmatch_ttag_Pt("PT_FJ_SD_tmatch_ttag", "p_{T} of FJ SD and tmatch and ttag", 100, 0, 2000);
  TH1F h_FJSD_tmatch_ttag_M("M_FJ_SD_tmatch_ttag", "M of FJ SD and tmatch and ttag", 80, 0, 400);

  TH1F h_FJSD_Nsubjets("Nsj_FDSD", "N subjets of SD FJ", 5, 0, 5);
  TH1F h_FJSD_sj1_Pt("PT_sj1_FJ_SD", "p_{T} of sj1 of FJ SD", 100, 0, 2000);
  TH1F h_FJSD_sj1_M("M_sj1_FJ_SD", "M of sj1 of FJ SD", 100, 0, 500);
  TH1F h_FJSD_sj2_Pt("PT_sj2_FJ_SD", "p_{T} of sj2 of FJ SD", 100, 0, 2000);
  TH1F h_FJSD_sj2_M("M_sj2_FJ_SD", "M of sj2 of FJ SD", 100, 0, 500);
  TH1F h_FJSD_sj12_matchbq_sj1_Pt("PT_sj1_FJSD_matchsj12", "p_{T} of sj1 when 2sjs matched to bjs", 100, 0, 2000);
  TH1F h_FJSD_sj12_matchbq_sj1_M("M_sj1_FJSD_matchsj12", "M of sj1 when 2sjs matched to bjs", 100, 0, 500);
  TH1F h_FJSD_sj12_matchbq_sj2_Pt("PT_sj2_FJSD_matchsj12", "p_{T} of sj2 when 2sjs matched to bjs", 100, 0, 2000);
  TH1F h_FJSD_sj12_matchbq_sj2_M("M_sj2_FJSD_matchsj12", "p_{T} of sj2 when 2sjs matched to bjs", 100, 0, 500);
  TH1F h_FJSD_sj12_matchbq_Pt("PT_FJSD_matchsj2", "p_{T} of FJ SD after matching sj12", 100, 0, 2000);
  TH1F h_FJSD_sj12_matchbq_M("M_FJSD_matchsj2", "M of FJ SD after matching sj12", 200, 0, 1000);
  TH1F h_FJSD_sj12_matchbq_Htag_Pt("PT_FJSD_matchsj2_Htag", "p_{T} of FJ SD after matching sj12 and Htag", 100, 0, 2000);
  TH1F h_FJSD_sj12_matchbq_Htag_M("M_FJSD_matchsj2_Htag", "M of FJ SD after matching sj12 and Htag", 40, 0, 200);
  TH1F NbquarksH("N_bquarksH", "N b-quarks from H", 20, 0, 20);
  TH1F NHiggs("N_Higgs", "N Higgs", 4, 0, 4);
  TH1F h_bquarkH_Pt("PT_bquarksH", "p_{T} of b-quarks from H", 100, 0, 2000);
  TH1F h_Higgs_Pt("PT_genH", "p_{T} of gen Higgs", 100, 0, 2000);
  TH1F h_genW_Pt("PT_genW", "p_{T} of gen W", 100, 0, 2000);
  TH1F h_gentop_Pt("PT_gentop", "p_{T} of gen top", 100, 0, 2000);

  TH1F h_NRJ_c("NRJ_candi", "N RJ candi", 30, 0, 30);
  TH1F h_NRJ_Htag("NRJ_Htag", "N RJ Htag", 30, 0, 30);
  TH1F h_NRJ_Hmatch("NRJ_Hmatch", "N RJ Hmatch", 30, 0, 30);
  TH1F h_NRJ_Hmatch_Htag("NRJ_Hmatch_Htag", "N RJ Hmatch Htag", 30, 0, 30);
  TH1F h_NFJ_c("NFJ_candi", "N FJ candi", 10, 0, 10);
  TH1F h_NFJ_Htag("NFJ_Htag", "N FJ Htag", 10, 0, 10);
  TH1F h_NFJ_SD("NFJ_SD", "N FJ SD", 10, 0, 10);
  TH1F h_NFJ_SD_Htag("NFJ_SD_Htag", "N FJ SD Htag", 10, 0, 10);
  TH1F h_NFJ_SD_Hmatch("NFJ_SD_Hmatch", "N FJ SD Htag", 10, 0, 10);
  TH1F h_NFJ_SD_Hmatch_Htag("NFJ_SD_Hmatch_Htag", "N FJ SD Htag", 10, 0, 10);
  TH1F h_NFJ_SD_sj12matchbq("NFJ_SD_sj12matchbq", "N FJ SD sj12matchbq", 10, 0, 10);
  TH1F h_NFJ_SD_sj12matchbq_Htag("NFJ_SD_sj12matchbq_Htag", "N FJ SD sj12matchbq and Htag", 10, 0, 10);
  TH1F h_RJ_c_Pt("PT_RJ_candi", "p_{T} of candidate Res bb Jet", 100, 0, 2000);
  TH1F h_RJ_c_M("M_RJ_candi", "M of candidate Res bb Jet", 400, 0, 2000);
  TH1F h_RJ_Htag_Pt("PT_RJ_Htag", "p_{T} of Res bb Jet Htag", 100, 0, 2000);
  TH1F h_RJ_Htag_M("M_RJ_Htag", "M of Res bb Jet Htag", 40, 0, 200);
  TH1F h_RJ_Hmatch_Pt("PT_RJ_matchH", "p_{T} of Res bb Jet matched to genH", 100, 0, 2000);
  TH1F h_RJ_Hmatch_M("M_RJ_matchH", "M of Res bb Jet matched to genH", 200, 0, 1000);
  TH1F h_RJ_Hmatch_Htag_Pt("PT_RJ_matchH_Htag", "p_{T} of Res bb Jet matched to genH and Htag", 100, 0, 2000);
  TH1F h_RJ_Hmatch_Htag_M("M_RJ_matchH_Htag", "M of Res bb Jet matched to genH and Htag", 40, 0, 200);
  //BS
  TH1F h_BS_MET("MET_BS", "MET after BS", 100, 0, 2000); 
  TH1F h_BS_MT("MT_BS", "MT after BS", 100, 0, 2000); 
  TH1F h_BS_HT("HT_BS", "HT after BS", 100, 0, 5000); 
  TH1F h_BS_NJ("NJ_BS", "NJ after BS", 20, 0, 20); 
  TH1F h_BS_NbJ("NbJ_BS", "NbJ after BS", 10, 0, 10); 
  TH1F h_BSNbJ2_MET("MET_BSNbJ2", "MET after BSNbJ=2", 100, 0, 2000);
  TH1F h_BSNbJ3_MET("MET_BSNbJ3", "MET after BSNbJ>=3", 100, 0, 2000);
  TH1F h_genH_PT("PT_genH_BS", "p_{T} of genH after BS", 50, 0, 1000);
  TH1F h_BS_NFJ("NFJ_BS", "N FJ candi after BS", 10, 0, 10);
  TH1F h_BS_NFJ_Htag("NFJ_Htag_BS", "N FJ Htag after BS", 10, 0, 10);
  TH1F h_BS_NFJ_SD("NFJ_SD_BS", "N FJ SD after BS", 10, 0, 10);
  TH1F h_BS_NFJ_SD_Htag("NFJ_SD_Htag_BS", "N FJ SD Htag after BS", 10, 0, 10);
  TH1F h_BS_NFJ_SD_Hmatch("NFJ_SD_Hmatch_BS", "N FJ SD Hmatch after BS", 10, 0, 10);
  TH1F h_BS_NFJ_SD_Hmatch_Htag("NFJ_SD_Hmatch_Htag_BS", "N FJ SD Hmatch Htag after BS", 10, 0, 10);
  TH1F h_BS_NFJ_SD_Wmatch("NFJ_SD_Wmatch_BS", "N FJ SD Wmatch after BS", 10, 0, 10);
  TH1F h_BS_NFJ_SD_Wmatch_Wtag("NFJ_SD_Wmatch_Wtag_BS", "N FJ SD Wmatch Wtag after BS", 10, 0, 10);
  TH1F h_BS_NFJ_SD_tmatch("NFJ_SD_tmatch_BS", "N FJ SD tmatch after BS", 10, 0, 10);
  TH1F h_BS_NFJ_SD_tmatch_ttag("NFJ_SD_tmatch_ttag_BS", "N FJ SD tmatch ttag after BS", 10, 0, 10);

  TH1F h_BS_NFJ_SD_sj12matchbq("NFJ_SD_sj12matchbq_BS", "N FJ SD sj12matchbq after BS", 10, 0, 10);
  TH1F h_BS_NFJ_SD_sj12matchbq_Htag("NFJ_SD_sj12matchbq_Htag_BS", "N FJ SD sj12matchbq and Htag after BS", 10, 0, 10);

  TH1F h_BS_FJ_Pt("PT_FJ_BS", "p_{T} of FJ after BS", 100, 0, 2000);
  TH1F h_BS_FJ_M("M_FJ_BS", "M of FJ after BS", 400, 0, 2000);
  TH1F h_BS_FJ_Htag_Pt("PT_FJ_Htag_BS", "p_{T} of FJ Htag after BS", 100, 0, 2000);
  TH1F h_BS_FJ_Htag_M("M_FJ_Htag_BS", "M of FJ Htag after BS", 40, 0, 200);
  TH1F h_BS_FJ_SD_Pt("PT_FJ_SD_BS", "p_{T} of FJ SD after BS", 100, 0, 2000);
  TH1F h_BS_FJ_SD_M("M_FJ_SD_BS", "M of FJ SD after BS", 200, 0, 1000);
  TH1F h_BS_FJ_SD_Htag_Pt("PT_FJ_SD_Htag_BS", "p_{T} of FJ SD Htag after BS", 100, 0, 2000);
  TH1F h_BS_FJ_SD_Htag_M("M_FJ_SD_Htag_BS", "M of FJ SD Htag after BS", 40, 0, 200);
  TH1F h_BS_FJ_SD_Hmatch_Pt("PT_FJ_SD_Hmatch_BS", "p_{T} of FJ SD Hmatch after BS", 100, 0, 2000);
  TH1F h_BS_FJ_SD_Hmatch_M("M_FJ_SD_Hmatch_BS", "M of FJ SD Hmatch after BS", 120, 0, 600);
  TH1F h_BS_FJ_SD_Hmatch_Htag_Pt("PT_FJ_SD_HmatchHtag_BS", "p_{T} of FJ SD Hmatch Htag after BS", 100, 0, 2000);
  TH1F h_BS_FJ_SD_Hmatch_Htag_M("M_FJ_SD_HmatchHtag_BS", "M of FJ SD Hmatch Htag after BS", 40, 0, 200);
  TH1F h_BS_FJ_SD_Wmatch_Pt("PT_FJ_SD_Wmatch_BS", "p_{T} of FJ SD Wmatch after BS", 100, 0, 2000);
  TH1F h_BS_FJ_SD_Wmatch_M("M_FJ_SD_Wmatch_BS", "M of FJ SD Wmatch after BS", 120, 0, 600);
  TH1F h_BS_FJ_SD_Wmatch_Wtag_Pt("PT_FJ_SD_WmatchWtag_BS", "p_{T} of FJ SD Wmatch Wtag after BS", 100, 0, 2000);
  TH1F h_BS_FJ_SD_Wmatch_Wtag_M("M_FJ_SD_WmatchWtag_BS", "M of FJ SD Wmatch Wtag after BS", 40, 0, 200);
  TH1F h_BS_FJ_SD_tmatch_Pt("PT_FJ_SD_tmatch_BS", "p_{T} of FJ SD tmatch after BS", 100, 0, 2000);
  TH1F h_BS_FJ_SD_tmatch_M("M_FJ_SD_tmatch_BS", "M of FJ SD tmatch after BS", 120, 0, 600);
  TH1F h_BS_FJ_SD_tmatch_ttag_Pt("PT_FJ_SD_tmatchttag_BS", "p_{T} of FJ SD tmatch ttag after BS", 100, 0, 2000);
  TH1F h_BS_FJ_SD_tmatch_ttag_M("M_FJ_SD_tmatchttag_BS", "M of FJ SD tmatch ttag after BS", 80, 0, 400);
  TH1F h_BS_FJ_SD_nomatch_Pt("PT_FJ_SD_nomatch_BS", "p_{T} of FJ SD no match after BS", 100, 0, 2000);
  TH1F h_BS_FJ_SD_nomatch_M("M_FJ_SD_nomatch_BS", "M of FJ SD no match after BS", 80, 0, 400);
  TH1F h_min_dM_fj_H("min_dM_fjsdHtag_H", "min dM(fjsdHtag, 125)", 200, 0, 200);
  TH1F h_BS_FJSD_Htag_closest_Pt("PT_FJ_SD_Htag_closestHmass_BS", "p_{T} of FJ SD Htag closest to Hmass after BS", 100, 0, 2000);
  TH1F h_BS_FJSD_Htag_closest_M("M_FJ_SD_Htag_closestHmass_BS", "M of FJ SD Htag closest to Hmass after BS", 40, 0, 200);
  TH1F h_BS_FJ_SD_sj12matchbq_Pt("PT_FJ_SD_sj12matchbq_BS", "p_{T} of FJ SD sj12 match bq after BS", 100, 0, 2000);
  TH1F h_BS_FJ_SD_sj12matchbq_M("M_FJ_SD_sj12matchbq_BS", "M of FJ SD sj12 match bq after BS", 200, 0, 1000);
  TH1F h_BS_FJ_SD_sj12matchbq_Htag_Pt("PT_FJ_SD_sj12matchbq_Htag_BS", "p_{T} of FJ SD sj12 match bq and Htag after BS", 100, 0, 2000);
  TH1F h_BS_FJ_SD_sj12matchbq_Htag_M("M_FJ_SD_sj12matchbq_Htag_BS", "M of FJ SD sj12 match bq and Htag after BS", 40, 0, 200);

  TH1F h_BS_NRJ("NRJ_BS", "N RJ candi after BS", 20, 0, 20);
  TH1F h_BS_NRJ_Htag("NRJ_Htag_BS", "N RJ Htag after BS", 20, 0, 20);
  TH1F h_BS_NRJ_Hmatch("NRJ_Hmatch_BS", "N RJ match genH after BS", 20, 0, 20);
  TH1F h_BS_NRJ_Hmatch_Htag("NRJ_Hmatch_Htag_BS", "N RJ match genH and Htag after BS", 20, 0, 20);
  TH1F h_BS_RJ_Pt("PT_RJ_BS", "p_{T} of RJ after BS", 100, 0, 2000);
  TH1F h_BS_RJ_M("M_RJ_BS", "M of RJ after BS", 400, 0, 2000);
  TH1F h_BS_RJ_Htag_Pt("PT_RJ_Htag_BS", "p_{T} of RJ Htag after BS", 100, 0, 2000);
  TH1F h_BS_RJ_Htag_M("M_RJ_Htag_BS", "M of RJ Htag after BS", 40, 0, 200);
  TH1F h_BS_RJ_Hmatch_Pt("PT_RJ_Hmatch_BS", "p_{T} of RJ match genH after BS", 100, 0, 2000);
  TH1F h_BS_RJ_Hmatch_M("M_RJ_Hmatch_BS", "p_{T} of RJ match genH after BS", 200, 0, 1000);
  TH1F h_BS_RJ_Hmatch_Htag_Pt("PT_RJ_Hmatch_Htag_BS", "p_{T} of RJ match genH and Htag after BS", 100, 0, 2000);
  TH1F h_BS_RJ_Hmatch_Htag_M("M_RJ_Hmatch_Htag_BS", "M of RJ match genH and Htag after BS", 40, 0, 200);
  TH1F h_min_dM_rj_H("min_dM_rjHtag_H", "min dM(rjHtag, 125)", 200, 0, 200);
  TH1F h_BS_RJ_Htag_closest_Pt("PT_RJ_Htag_closestHmass_BS", "p_{T} of RJ Htag closest to Hmass after BS", 100, 0, 2000);
  TH1F h_BS_RJ_Htag_closest_M("M_RJ_Htag_closestHmass_BS", "M of RJ Htag closest to Hmass after BS", 40, 0, 200);

  //H requi - FJ
  TH1F h_BS_NFJHtag1_MET("MET_BS_NFJHtag1", "MET after BS+NFJ(Htag)>=1", 100, 0, 2000);
  TH1F h_BS_NFJHtag1_MT("MT_BS_NFJHtag1", "MT after BS+NFJ(Htag)>=1", 100, 0, 2000);
  TH1F h_BS_NFJHtag1_HT("HT_BS_NFJHtag1", "HT after BS+NFJ(Htag)>=1", 100, 0, 5000);
  TH1F h_BS_NFJHtag1_NJ("NJ_BS_NFJHtag1", "NJets after BS+NFJ(Htag)>=1", 20, 0, 20);
  TH1F h_BS_NFJHtag1_NbJ("NbJ_BS_NFJHtag1", "NbJets after BS+NFJ(Htag)>=1", 10, 0, 10);
  TH1F h_BSNbJ2_NFJHtag1_MET("MET_BSNbJ2_NFJHtag1", "MET after BSNbJ=2 + NFJ(Htag)>=1", 100, 0, 2000);
  TH1F h_BSNbJ3_NFJHtag1_MET("MET_BSNbJ3_NFJHtag1", "MET after BSNbJ>=3 + NFJ(Htag)>=1", 100, 0, 2000);
  TH1F h_BSNFJHtag1_genHPt("PT_genH_BS_NFJHtag1", "p_{T} of genH after BS+NFJ(Htag)>=1", 100, 0, 2000);
  TH1F h_BSNFJHtag1_Pt("PT_FJHtag_BS_NFJHtag1", "p_{T} of FJ Htag after BS + NFJ(Htag)>=1", 100, 0, 2000);
  TH1F h_BSNFJHtag1_M("M_FJHtag_BS_NFJHtag1", "M of FJ Htag after BS + NFJ(Htag)>=1", 40, 0, 200);

  TH1F h_BS_NFJSDHtag1_MET("MET_BS_NFJSDHtag1", "MET after BS+NFJSD(Htag)>=1", 100, 0, 2000);
  TH1F h_BS_NFJSDHtag1_MT("MT_BS_NFJSDHtag1", "MT after BS+NFJSD(Htag)>=1", 100, 0, 2000);
  TH1F h_BS_NFJSDHtag1_HT("HT_BS_NFJSDHtag1", "HT after BS+NFJSD(Htag)>=1", 100, 0, 5000);
  TH1F h_BS_NFJSDHtag1_NJ("NJ_BS_NFJSDHtag1", "NJets after BS+NFJSD(Htag)>=1", 20, 0, 20);
  TH1F h_BS_NFJSDHtag1_NbJ("NbJ_BS_NFJSDHtag1", "NbJets after BS+NFJSD(Htag)>=1", 10, 0, 10);
  TH1F h_BSNbJ2_NFJSDHtag1_MET("MET_BSNbJ2_NFJSDHtag1", "MET after BSNbJ=2 + NFJSD(Htag)>=1", 100, 0, 2000);
  TH1F h_BSNbJ3_NFJSDHtag1_MET("MET_BSNbJ3_NFJSDHtag1", "MET after BSNbJ>=3 + NFJSD(Htag)>=1", 100, 0, 2000);
  TH1F h_BSNFJSDHtag1_genHPt("PT_genH_BS_NFJSDHtag1", "p_{T} of genH after BS+NFJSD(Htag)>=1", 100, 0, 2000);
  TH1F h_BSNFJSDHtag1_Pt("PT_FJSDHtag_BS_NFJSDHtag1", "p_{T} of FJ Htag after BS + NFJSD(Htag)>=1", 100, 0, 2000);
  TH1F h_BSNFJSDHtag1_M("M_FJSDHtag_BS_NFJSDHtag1", "M of FJ Htag after BS + NFJSD(Htag)>=1", 40, 0, 200);

  TH1F h_BS_NFJSDHmatchHtag1_MET("MET_BS_NFJSDHmatchHtag1", "MET after BS+NFJSD(HmatchHtag)>=1", 100, 0, 2000);
  TH1F h_BS_NFJSDHmatchHtag1_MT("MT_BS_NFJSDHmatchHtag1", "MT after BS+NFJSD(HmatchHtag)>=1", 100, 0, 2000);
  TH1F h_BS_NFJSDHmatchHtag1_HT("HT_BS_NFJSDHmatchHtag1", "HT after BS+NFJSD(HmatchHtag)>=1", 100, 0, 5000);
  TH1F h_BS_NFJSDHmatchHtag1_NJ("NJ_BS_NFJSDHmatchHtag1", "NJets after BS+NFJSD(HmatchHtag)>=1", 20, 0, 20);
  TH1F h_BS_NFJSDHmatchHtag1_NbJ("NbJ_BS_NFJSDHmatchHtag1", "NbJets after BS+NFJSD(HmatchHtag)>=1", 10, 0, 10);
  TH1F h_BSNbJ2_NFJSDHmatchHtag1_MET("MET_BSNbJ2_NFJSDHmatchHtag1", "MET after BSNbJ=2 + NFJSD(HmatchHtag)>=1", 100, 0, 2000);
  TH1F h_BSNbJ3_NFJSDHmatchHtag1_MET("MET_BSNbJ3_NFJSDHmatchHtag1", "MET after BSNbJ>=3 + NFJSD(HmatchHtag)>=1", 100, 0, 2000);
  TH1F h_BSNFJSDHmatchHtag1_genHPt("PT_genH_BS_NFJSDHmatchHtag1", "p_{T} of genH after BS+NFJSD(HmatchHtag)>=1", 100, 0, 2000);
  TH1F h_BSNFJSDHmatchHtag1_Pt("PT_FJSDHmatchHtag_BS_NFJSDHmatchHtag1", "p_{T} of FJ HmatchHtag after BS + NFJSD(HmatchHtag)>=1", 100, 0, 2000);
  TH1F h_BSNFJSDHmatchHtag1_M("M_FJSDHmatchHtag_BS_NFJSDHmatchHtag1", "M of FJ HmatchHtag after BS + NFJSD(HmatchHtag)>=1", 40, 0, 200);


  TH1F h_BS_NFJSDmatchbqHtag1_MET("MET_BS_NFJSDmatchbqHtag1", "MET after BS+NFJSDmatchbq(Htag)>=1", 100, 0, 2000);
  TH1F h_BS_NFJSDmatchbqHtag1_MT("MT_BS_NFJSDmatchbqHtag1", "MT after BS+NFJSDmatchbq(Htag)>=1", 100, 0, 2000);
  TH1F h_BS_NFJSDmatchbqHtag1_HT("HT_BS_NFJSDmatchbqHtag1", "HT after BS+NFJSDmatchbq(Htag)>=1", 100, 0, 5000);
  TH1F h_BS_NFJSDmatchbqHtag1_NJ("NJ_BS_NFJSDmatchbqHtag1", "NJets after BS+NFJSDmatchbq(Htag)>=1", 20, 0, 20);
  TH1F h_BS_NFJSDmatchbqHtag1_NbJ("NbJ_BS_NFJSDmatchbqHtag1", "NbJets after BS+NFJSDmatchbq(Htag)>=1", 10, 0, 10);
  TH1F h_BSNbJ2_NFJSDmatchbqHtag1_MET("MET_BSNbJ2_NFJSDmatchbqHtag1", "MET after BSNbJ=2 + NFJSDmatchbq(Htag)>=1", 100, 0, 2000);
  TH1F h_BSNbJ3_NFJSDmatchbqHtag1_MET("MET_BSNbJ3_NFJSDmatchbqHtag1", "MET after BSNbJ>=3 + NFJSDmatchbq(Htag)>=1", 100, 0, 2000);
  TH1F h_BSNFJSDmatchbqHtag1_genHPt("PT_genH_BS_NFJSDmatchbqHtag1", "p_{T} of genH after BS+NFJSDmatchbq(Htag)>=1", 100, 0, 2000);
  TH1F h_BSNFJSDmatchbqHtag1_Pt("PT_FJSDmatchbqHtag_BS_NFJSDmatchbqHtag1", "p_{T} of FJ Htag after BS + NFJSDmatchbq(Htag)>=1", 100, 0, 2000);
  TH1F h_BSNFJSDmatchbqHtag1_M("M_FJSDmatchbqHtag_BS_NFJSDmatchbqHtag1", "M of FJ Htag after BS + NFJSDmatchbq(Htag)>=1", 40, 0, 200);

  //H requi - RJ when FJ=0
  TH1F h_BS_NFJSDHtag0NRJHtag1_MET("MET_BS_NFJSDHtag0NRJHtag1", "MET after BS + NFJSD(Htag)=0 + NRJ(Htag)>0", 100, 0, 2000);
  TH1F h_BS_NFJSDHtag0NRJHtag1_MT("MT_BS_NFJSDHtag0NRJHtag1", "MT after BS + NFJSD(Htag)=0 + NRJ(Htag)>0", 100, 0, 2000);
  TH1F h_BS_NFJSDHtag0NRJHtag1_HT("HT_BS_NFJSDHtag0NRJHtag1", "HT after BS + NFJSD(Htag)=0 + NRJ(Htag)>0", 100, 0, 5000);
  TH1F h_BS_NFJSDHtag0NRJHtag1_NJ("NJ_BS_NFJSDHtag0NRJHtag1", "NJets after BS + NFJSD(Htag)=0 + NRJ(Htag)>0", 20, 0, 20);
  TH1F h_BS_NFJSDHtag0NRJHtag1_NbJ("NbJ_BS_NFJSDHtag0NRJHtag1", "NbJets after BS + NFJSD(Htag)=0 + NRJ(Htag)>0", 10, 0, 10);
  TH1F h_BSNbJ2_NFJSDHtag0NRJHtag1_MET("MET_BSNbJ2_NFJSDHtag0NRJHtag1", "MET after BSNbJ2 + NFJSD(Htag)=0 + NRJ(Htag)>0", 100, 0, 2000);
  TH1F h_BSNbJ3_NFJSDHtag0NRJHtag1_MET("MET_BSNbJ3_NFJSDHtag0NRJHtag1", "MET after BSNbJ3 + NFJSD(Htag)=0 + NRJ(Htag)>0", 100, 0, 2000);
  TH1F h_BSNFJSDHtag0NRJHtag1_genHPt("PT_genH_BS_NFJSDHtag0NRJHtag1", "p_{T} of genH after BS + NFJSD(Htag)=0 + NRJ(Htag)>0", 100, 0, 2000);
  TH1F h_BSNFJSDHtag0NRJHtag1_Pt("PT_RJHtag_BS_NFJSDHtag0NRJHtag1", "p_{T} of RJ Htag after BS + NFJSD(Htag)=0 + NRJ(Htag)>0", 100, 0, 2000);
  TH1F h_BSNFJSDHtag0NRJHtag1_M("M_RJHtag_BS_NFJSDHtag0NRJHtag1", "M of RJ Htag after BS + NFJSD(Htag)=0 + NRJ(Htag)>0", 40, 0, 200);



  //H requi - RJ
  TH1F h_BS_NRJHtag1_MET("MET_BS_NRJHtag1", "MET after BS+NRJ(Htag)>=1", 100, 0, 2000);
  TH1F h_BS_NRJHtag1_MT("MT_BS_NRJHtag1", "MT after BS+NRJ(Htag)>=1", 100, 0, 2000);
  TH1F h_BS_NRJHtag1_HT("HT_BS_NRJHtag1", "HT after BS+NRJ(Htag)>=1", 100, 0, 5000);
  TH1F h_BS_NRJHtag1_NJ("NJ_BS_NRJHtag1", "NJets after BS+NRJ(Htag)>=1", 20, 0, 20);
  TH1F h_BS_NRJHtag1_NbJ("NbJ_BS_NRJHtag1", "NbJets after BS+NRJ(Htag)>=1", 10, 0, 10);
  TH1F h_BSNbJ2_NRJHtag1_MET("MET_BSNbJ2_NRJHtag1", "MET after BSNbJ=2 + NRJ(Htag)>=1", 100, 0, 2000);
  TH1F h_BSNbJ3_NRJHtag1_MET("MET_BSNbJ3_NRJHtag1", "MET after BSNbJ>=3 + NRJ(Htag)>=1", 100, 0, 2000);
  TH1F h_BSNRJHtag1_genHPt("PT_genH_BS_NRJHtag1", "p_{T} of genH after BS+NRJ(Htag)>=1", 100, 0, 2000);
  TH1F h_BSNRJHtag1_Pt("PT_RJHtag_BS_NRJHtag1", "p_{T} of RJ Htag after BS + NRJ(Htag)>=1", 100, 0, 2000);
  TH1F h_BSNRJHtag1_M("M_RJHtag_BS_NRJHtag1", "M of RJ Htag after BS + NRJ(Htag)>=1", 40, 0, 200);
  TH1F h_BS_NRJHmatch_Htag1_MET("MET_BS_NRJHmatchHtag1", "MET after BS+NRJ(HmatchHtag)>=1", 100, 0, 2000);
  TH1F h_BS_NRJHmatch_Htag1_MT("MT_BS_NRJHmatch_Htag1", "MT after BS+NRJ(Hmatch_Htag)>=1", 100, 0, 2000);
  TH1F h_BS_NRJHmatch_Htag1_HT("HT_BS_NRJHmatch_Htag1", "HT after BS+NRJ(Hmatch_Htag)>=1", 100, 0, 5000);
  TH1F h_BS_NRJHmatch_Htag1_NJ("NJ_BS_NRJHmatch_Htag1", "NJets after BS+NRJ(Hmatch_Htag)>=1", 20, 0, 20);
  TH1F h_BS_NRJHmatch_Htag1_NbJ("NbJ_BS_NRJHmatch_Htag1", "NbJets after BS+NRJ(Hmatch_Htag)>=1", 10, 0, 10);
  TH1F h_BSNbJ2_NRJHmatch_Htag1_MET("MET_BSNbJ2_NRJHmatch_Htag1", "MET after BSNbJ=2 + NRJ(Hmatch_Htag)>=1", 100, 0, 2000);
  TH1F h_BSNbJ3_NRJHmatch_Htag1_MET("MET_BSNbJ3_NRJHmatch_Htag1", "MET after BSNbJ>=3 + NRJ(Hmatch_Htag)>=1", 100, 0, 2000);
  TH1F h_BSNRJHmatch_Htag1_genHPt("PT_genH_BS_NRJHmatch_Htag1", "p_{T} of genH after BS+NRJ(Hmatch_Htag)>=1", 100, 0, 2000);
  TH1F h_BSNRJHmatch_Htag1_Pt("PT_RJHmatch_Htag_BS_NRJHmatch_Htag1", "p_{T} of RJ Hmatch_Htag after BS + NRJ(Hmatch_Htag)>=1", 100, 0, 2000);
  TH1F h_BSNRJHmatch_Htag1_M("M_RJHmatch_Htag_BS_NRJHmatch_Htag1", "M of RJ Hmatch_Htag after BS + NRJ(Hmatch_Htag)>=1", 40, 0, 200);





  int nEvtTotal=0;
  // Loop over all events
  for(Int_t entry = 0; entry < numberOfEntries; ++entry)
  {
    // Load selected branches with data from specified event
    treeReader->ReadEntry(entry);
    nEvtTotal++;
    if(nEvtTotal%1000==0)cout<<"Processed "<<nEvtTotal<<" event..."<<endl;   

//-------------------

  leptons.clear();
  jets.clear();
  bjets.clear();
  fatjet_candi.clear();
  fatjet_Htag.clear();
  fatjet_SD_candi.clear();
  fatjet_SD_Htag.clear();
  fatjet_SD_Hmatch.clear();
  fatjet_SD_Hmatch_Htag.clear();
  fatjet_SD_Wmatch.clear();
  fatjet_SD_Wmatch_Wtag.clear();
  fatjet_SD_tmatch.clear();
  fatjet_SD_tmatch_ttag.clear();
  fatjat_SD_sj12matchbq.clear();
  fatjat_SD_sj12matchbq_Htag.clear();
  fatjet_SD_nomatch.clear();
  bquarksH.clear();
  Higgs.clear();
  genW.clear();
  gentop.clear();

  res_bbjets.clear();
  res_bbjets_Htag.clear();
  res_bbjets_Hmatch.clear();
  res_bbjets_Hmatch_Htag.clear();

  dM_FJ_H.clear();
  dM_RJ_H.clear();

//-------------------
    //MET
    MissingET *met = (MissingET*)branchMissingET->At(0);
    double MET = met->MET;
    double MET_Phi = met->Phi;

    ScalarHT *ht = (ScalarHT*)branchScalarHT->At(0);
    double HT = ht->HT;


//-------------------
    //Lepton
    if(branchElectron->GetEntries() > 0){
      for(int i=0; i<branchElectron->GetEntries(); i++){
        Electron *el = (Electron *) branchElectron->At(i);
        if((el->PT > 20) && (fabs(el->Eta) < 2.5)){
          leptons.push_back(el->P4());
        }
      }
    }    
    if(branchMuon->GetEntries() > 0){
      for(int i=0; i<branchMuon->GetEntries(); i++){
        Muon *mu = (Muon *) branchMuon->At(i);
        if((mu->PT > 20) && (fabs(mu->Eta) < 2.4)){
          leptons.push_back(mu->P4());
        }
      }
    }    
    Nlep.Fill(leptons.size(), Wt);
//-------------------
    //MT
    double MT;
    if(leptons.size()>0){
      double l1_et = leptons.at(0).Pt();
      double dPhi = delta_phi(leptons.at(0).Phi(), MET_Phi);
      MT = sqrt( 2*MET*l1_et*( 1 - cos(dPhi) ) );
    }
//-------------------

    if(branchPar->GetEntries() > 0){
      for(int i=0; i<branchPar->GetEntries(); i++){
        GenParticle *par = (GenParticle*) branchPar->At(i);

        //b-quark from H
        if( abs(par->PID) == 5 ){
          GenParticle *mpar = (GenParticle*) branchPar->At(par->M1);
          int pid_mpar = mpar->PID;
          if(pid_mpar==25){
            bquarksH.push_back(par->P4());
            h_bquarkH_Pt.Fill(par->PT, Wt);
          } //        
        }
        //Higgs
        if( abs(par->PID) == 25 && (par->M1) != i ){
          Higgs.push_back(par->P4());
          h_Higgs_Pt.Fill(par->PT, Wt);
        }
        //gen W
        if( abs(par->PID) == 24 && (par->M1) != i ){
          GenParticle *mpar1 = (GenParticle*) branchPar->At(par->M1);
          int pid_mpar1 = mpar1->PID;
          if(abs(pid_mpar1)==6){            
            genW.push_back(par->P4());
            h_genW_Pt.Fill(par->PT, Wt);
          }
        }
        //gen top
	if( abs(par->PID) == 6 && par->D1>0 && par->D2>0){
          GenParticle *dpar1 = (GenParticle*) branchPar->At(par->D1);
          int pid_dpar1 = dpar1->PID;
          GenParticle *dpar2 = (GenParticle*) branchPar->At(par->D2);
          int pid_dpar2 = dpar2->PID;
          if(abs(pid_dpar1)!=6 && abs(pid_dpar2)!=6){
            gentop.push_back(par->P4());
            h_gentop_Pt.Fill(par->PT, Wt);
          }
        }//

        ///////////////
        //~t1
	if(abs(par->PID) == 1000006 && par->D1>0 && par->D2>0 ){
          GenParticle *dpar1 = (GenParticle*) branchPar->At(par->D1);
          int pid_dpar1 = dpar1->PID;
          GenParticle *dpar2 = (GenParticle*) branchPar->At(par->D2);
          int pid_dpar2 = dpar2->PID;
          if(abs(pid_dpar1)!=1000006 && abs(pid_dpar2)!=1000006){
            hist_t1_Pt.Fill(par->PT, Wt);
          }
        }
        //t
	if(abs(par->PID) == 6 && par->D1>0 && par->D2>0){
          GenParticle *dpar1 = (GenParticle*) branchPar->At(par->D1);
          int pid_dpar1 = dpar1->PID;
          GenParticle *dpar2 = (GenParticle*) branchPar->At(par->D2);
          int pid_dpar2 = dpar2->PID;
          if(abs(pid_dpar1)!=6 && abs(pid_dpar2)!=6){
            hist_t_Pt.Fill(par->PT, Wt);
          }
        }
        //N2
	if(par->PID == 1000023 && par->M1>0 ){
          GenParticle *mpar1 = (GenParticle*) branchPar->At(par->M1);
          int pid_mpar1 = mpar1->PID;
          if(abs(pid_mpar1)==1000006){            
            hist_N2_t_Pt.Fill(par->PT, Wt);

          }
        }
        //N1 from N2
	if(par->PID == 1000022  && par->M1>0 ){
          GenParticle *mpar1 = (GenParticle*) branchPar->At(par->M1);
          int pid_mpar1 = mpar1->PID;
          if(pid_mpar1==1000023){
            hist_N1_N2_Pt.Fill(par->PT, Wt);
          }
        }
        //N1 from ~t1
	if(par->PID == 1000022  && par->M1>0 ){
          GenParticle *mpar1 = (GenParticle*) branchPar->At(par->M1);
          int pid_mpar1 = mpar1->PID;
          if(abs(pid_mpar1)==1000006){
            hist_N1_t1_Pt.Fill(par->PT, Wt);

          }
        }
        //H from N2
        if(par->PID==25 && par->M1>0){
          GenParticle *mpar1 = (GenParticle*) branchPar->At(par->M1);
          int pid_mpar1 = mpar1->PID;
          if(pid_mpar1==1000023){            
            hist_H_N2_Pt.Fill(par->PT, Wt);
          }
        }
        //b from t
        if(abs(par->PID)==5 && par->M1>0){
          GenParticle *mpar1 = (GenParticle*) branchPar->At(par->M1);
          int pid_mpar1 = mpar1->PID;
          if(abs(pid_mpar1)==6){            
            hist_b_t_Pt.Fill(par->PT, Wt);
          }
        }
        //W from t
        if(abs(par->PID)==24 && par->M1>0){
          GenParticle *mpar1 = (GenParticle*) branchPar->At(par->M1);
          int pid_mpar1 = mpar1->PID;
          if(abs(pid_mpar1)==6){            
            hist_W_t_Pt.Fill(par->PT, Wt);
          }
        }
        //b from H
        if(abs(par->PID)==5 && par->M1>0){
          GenParticle *mpar1 = (GenParticle*) branchPar->At(par->M1);
          int pid_mpar1 = mpar1->PID;
          if(abs(pid_mpar1)==25){            
            hist_b_H_Pt.Fill(par->PT, Wt);
          }
        }
        //////////

      }
    }
    NbquarksH.Fill(bquarksH.size(), Wt);
    NHiggs.Fill(Higgs.size(), Wt);
    
    

//-------------------

    //Jet
    if(branchJet->GetEntries() > 0)
    {
      for(int i=0; i<branchJet->GetEntries(); i++){
        Jet *jet = (Jet*) branchJet->At(i);
        if( (jet->PT > 30) && (fabs(jet->Eta) < 2.4) ){
          jets.push_back(jet->P4());
          if(jet->BTag==1){
            bjets.push_back(jet->P4());
          }
        }
      }
    }//jets

    NJet.Fill(jets.size(), Wt);
    NbJet.Fill(bjets.size(), Wt);


//---------------------
    //FatJet
    if(branchFatJet->GetEntries() > 0)
    {
      for(int i=0; i<branchFatJet->GetEntries(); i++){

        Jet *fatjet = (Jet*) branchFatJet->At(i);

        //candi fj
        fatjet_candi.push_back(fatjet->P4());
        h_FJ_C_Pt.Fill(fatjet->PT, Wt);
        h_FJ_C_M.Fill(fatjet->Mass, Wt);

        //fj Htag
        if( ((fatjet->PT)>300) && (fabs(fatjet->Eta)<2.4) && ((fatjet->Mass)>100) && ((fatjet->Mass)<150) ){
          fatjet_Htag.push_back(fatjet->P4());
          h_FJ_Htag_Pt.Fill(fatjet->PT, Wt);
          h_FJ_Htag_M.Fill(fatjet->Mass, Wt);
        }

        //fj SD candi
        TLorentzVector fj_sd_p4 = fatjet->SoftDroppedP4[0];
        fatjet_SD_candi.push_back(fj_sd_p4);
        h_FJSD_C_M.Fill(fj_sd_p4.M(), Wt);
        h_FJSD_C_Pt.Fill(fj_sd_p4.Pt(), Wt);
    
        //fj SD Htag
        if( (fj_sd_p4.Pt() > 300) && (fabs(fj_sd_p4.Eta()) < 2.4) &&  (fj_sd_p4.M() > 100) && (fj_sd_p4.M()<150) ){
          fatjet_SD_Htag.push_back(fj_sd_p4);
          h_FJSD_Htag_M.Fill(fj_sd_p4.M(), Wt);
          h_FJSD_Htag_Pt.Fill(fj_sd_p4.Pt(), Wt);
        }

        int matchWfound=0; int matchHfound=0; int matchtopfound=0;          
        //check if match to genW
        if(genW.size()>0){
          double dR_fjsd_W1 = delR(genW.at(0), fj_sd_p4);
          double dR_fjsd_W2 = delR(genW.at(1), fj_sd_p4);
          if(dR_fjsd_W1<=0.4 || dR_fjsd_W2<=0.4){
            matchWfound++;
            fatjet_SD_Wmatch.push_back(fj_sd_p4);
            h_FJSD_Wmatch_M.Fill(fj_sd_p4.M(), Wt);
            h_FJSD_Wmatch_Pt.Fill(fj_sd_p4.Pt(), Wt);
            if(fj_sd_p4.Pt()>200 && fabs(fj_sd_p4.Eta())<2.4 && (fj_sd_p4.M()>60) && (fj_sd_p4.M()<100) ){
              fatjet_SD_Wmatch_Wtag.push_back(fj_sd_p4);
              h_FJSD_Wmatch_Wtag_M.Fill(fj_sd_p4.M(), Wt);
              h_FJSD_Wmatch_Wtag_Pt.Fill(fj_sd_p4.Pt(), Wt);
            }
          }
        }

        //check if match to gen top
        if(gentop.size()>0){
          double dR_fjsd_top1 = delR(gentop.at(0), fj_sd_p4);
          double dR_fjsd_top2 = delR(gentop.at(1), fj_sd_p4);
          if(dR_fjsd_top1<=0.4 || dR_fjsd_top2<=0.4){
            matchtopfound++;
            fatjet_SD_tmatch.push_back(fj_sd_p4);
            h_FJSD_tmatch_M.Fill(fj_sd_p4.M(), Wt);
            h_FJSD_tmatch_Pt.Fill(fj_sd_p4.Pt(), Wt);
            if(fj_sd_p4.Pt()>400 && fabs(fj_sd_p4.Eta())<2.4 && (fj_sd_p4.M()>150) && (fj_sd_p4.M()<200) ){
              fatjet_SD_tmatch_ttag.push_back(fj_sd_p4);
              h_FJSD_tmatch_ttag_M.Fill(fj_sd_p4.M(), Wt);
              h_FJSD_tmatch_ttag_Pt.Fill(fj_sd_p4.Pt(), Wt);
            }
          }
        }

        //check if match to genH and also Htag
        if(Higgs.size()>0){
          double dR_fjsd_H1 = delR(Higgs.at(0), fj_sd_p4);
          if(dR_fjsd_H1<=0.4){
            matchHfound++;
            fatjet_SD_Hmatch.push_back(fj_sd_p4);
            h_FJSD_Hmatch_M.Fill(fj_sd_p4.M(), Wt);
            h_FJSD_Hmatch_Pt.Fill(fj_sd_p4.Pt(), Wt);
            if( fj_sd_p4.Pt()>300 && fabs(fj_sd_p4.Eta())<2.4 && (fj_sd_p4.M()>100) && (fj_sd_p4.M()<150) ){
              fatjet_SD_Hmatch_Htag.push_back(fj_sd_p4);
              h_FJSD_Hmatch_Htag_M.Fill(fj_sd_p4.M(), Wt);
              h_FJSD_Hmatch_Htag_Pt.Fill(fj_sd_p4.Pt(), Wt);
            }
          }
          if(dR_fjsd_H1>0.4 && Higgs.size()==2){
            double dR_fjsd_H2 = delR(Higgs.at(1), fj_sd_p4);
            if(dR_fjsd_H2<=0.4){
              fatjet_SD_Hmatch.push_back(fj_sd_p4);
              h_FJSD_Hmatch_M.Fill(fj_sd_p4.M(), Wt);
              h_FJSD_Hmatch_Pt.Fill(fj_sd_p4.Pt(), Wt);
              if( fj_sd_p4.Pt()>300 && fabs(fj_sd_p4.Eta())<2.4 && (fj_sd_p4.M() > 100) && (fj_sd_p4.M()<150) ){
                fatjet_SD_Hmatch_Htag.push_back(fj_sd_p4);
                h_FJSD_Hmatch_Htag_M.Fill(fj_sd_p4.M(), Wt);
                h_FJSD_Hmatch_Htag_Pt.Fill(fj_sd_p4.Pt(), Wt);
              }
            }
          }
        }//

        //if fjsd not matched to H or W or top
        if(matchHfound==0 && matchWfound==0 && matchtopfound==0){
          fatjet_SD_nomatch.push_back(fj_sd_p4);
        }


        //check if 2 subjets
        h_FJSD_Nsubjets.Fill(fatjet->NSubJetsSoftDropped, Wt);
        if(fatjet->NSubJetsSoftDropped == 2){

          //fj SD match 2sj to 2bq
          TLorentzVector fj_sd_sj1_p4 = fatjet->SoftDroppedP4[1];
          TLorentzVector fj_sd_sj2_p4 = fatjet->SoftDroppedP4[2];
          h_FJSD_sj1_Pt.Fill(fj_sd_sj1_p4.Pt(), Wt);
          h_FJSD_sj1_M.Fill(fj_sd_sj1_p4.M(), Wt);
          h_FJSD_sj2_Pt.Fill(fj_sd_sj2_p4.Pt(), Wt);
          h_FJSD_sj2_M.Fill(fj_sd_sj2_p4.M(), Wt);
        
          //match sj1 to a b-quark
          double dR_sj1_bq[bquarksH.size()]; int found_bqmatch_sj1=0; int j1;
          for(int j=0; j<bquarksH.size(); j++){
            dR_sj1_bq[j] = delR(fj_sd_sj1_p4, bquarksH.at(j));
            if( dR_sj1_bq[j] < 0.4 ){
              found_bqmatch_sj1++;
              j1=j;
            }
          }

          if(found_bqmatch_sj1>0){

            double dR_sj2_bq[bjets.size()]; int found_bqmatch_sj2=0; int k1;
            for(int k=0; k<bquarksH.size(); k++){
              dR_sj2_bq[k] = delR(fj_sd_sj2_p4, bquarksH.at(k));
              if( dR_sj2_bq[k] < 0.4 ){
                found_bqmatch_sj2++;
                k1=k;
              }
            }
            if(found_bqmatch_sj2>0 /*&& j1!=k1*/){
     
              h_FJSD_sj12_matchbq_sj1_Pt.Fill(fj_sd_sj1_p4.Pt(), Wt);
              h_FJSD_sj12_matchbq_sj1_M.Fill(fj_sd_sj1_p4.M(), Wt);
              h_FJSD_sj12_matchbq_sj2_Pt.Fill(fj_sd_sj2_p4.Pt(), Wt);
              h_FJSD_sj12_matchbq_sj2_M.Fill(fj_sd_sj2_p4.M(), Wt);
           
              h_FJSD_sj12_matchbq_Pt.Fill(fj_sd_p4.Pt(), Wt);
              h_FJSD_sj12_matchbq_M.Fill(fj_sd_p4.M(), Wt);
              fatjat_SD_sj12matchbq.push_back(fj_sd_p4);

              //Htag
              if( (fj_sd_p4.Pt()>300 )&& (fabs(fj_sd_p4.Eta())<2.4) && (fj_sd_p4.M()>100) && (fj_sd_p4.M()<150) ){
                fatjat_SD_sj12matchbq_Htag.push_back(fj_sd_p4);
                h_FJSD_sj12_matchbq_Htag_Pt.Fill(fj_sd_p4.Pt(), Wt);
                h_FJSD_sj12_matchbq_Htag_M.Fill(fj_sd_p4.M(), Wt);
              }

            }//match sj12 to bj
          
          }//match sj1 to bj

        }//2 subjets

      }//fj loop

    }//fj>0

    h_NFJ_c.Fill(fatjet_candi.size(), Wt);
    h_NFJ_Htag.Fill(fatjet_Htag.size(), Wt);
    h_NFJ_SD.Fill(fatjet_SD_candi.size(), Wt);
    h_NFJ_SD_Htag.Fill(fatjet_SD_Htag.size(), Wt);
    h_NFJ_SD_Hmatch.Fill(fatjet_SD_Hmatch.size(), Wt);
    h_NFJ_SD_Hmatch_Htag.Fill(fatjet_SD_Hmatch_Htag.size(), Wt);
    h_NFJ_SD_sj12matchbq.Fill(fatjat_SD_sj12matchbq.size(), Wt);
    h_NFJ_SD_sj12matchbq_Htag.Fill(fatjat_SD_sj12matchbq_Htag.size(), Wt);


    //keep only the FJ closest to Hmass
    int index1 = 0;
    if(fatjet_SD_Htag.size()==1){
      float dM_fj_H = abs(fatjet_SD_Htag.at(0).M() - 125);
      dM_FJ_H.push_back(dM_fj_H);
    }
    if(fatjet_SD_Htag.size()>1){
      for(int l=0; l<fatjet_SD_Htag.size(); l++){
        float dM_fj_H = abs(fatjet_SD_Htag.at(l).M() - 125);
        dM_FJ_H.push_back(dM_fj_H);
      }
      //find minima
      float min1 = dM_FJ_H.at(0);// index1=0;
      for(int k=1; k<dM_FJ_H.size(); k++){
        if(dM_FJ_H.at(k) < min1 ){
          min1 = dM_FJ_H.at(k);
          index1 = k;
        }
      }
      //the FJ closest to Hmass is fatjet_SD_Htag.at(index)
    }//


//---------------------

    //Resolved H->bb Jets
    if(bjets.size()>1){
      for(int l=0; l<bjets.size(); l++){
        for(int m=l+1; m<bjets.size(); m++){
          TLorentzVector res_bbJ_p4 = (bjets.at(l) + bjets.at(m));
            res_bbjets.push_back(res_bbJ_p4);
            h_RJ_c_Pt.Fill(res_bbJ_p4.Pt(), Wt);
            h_RJ_c_M.Fill(res_bbJ_p4.M(), Wt);
            if(res_bbJ_p4.M()>100 && res_bbJ_p4.M()<150){
              res_bbjets_Htag.push_back(res_bbJ_p4);
              h_RJ_Htag_Pt.Fill(res_bbJ_p4.Pt(), Wt);
              h_RJ_Htag_M.Fill(res_bbJ_p4.M(), Wt);
            }

            //check if match to genH
            if(Higgs.size()>0){
              double dR_RJ_H1 = delR(res_bbJ_p4, Higgs.at(0));
              if(dR_RJ_H1<=0.4){
                res_bbjets_Hmatch.push_back(res_bbJ_p4);
                h_RJ_Hmatch_Pt.Fill(res_bbJ_p4.Pt(), Wt);
                h_RJ_Hmatch_M.Fill(res_bbJ_p4.M(), Wt);
                if(res_bbJ_p4.M()>100 && res_bbJ_p4.M()<150){
                  res_bbjets_Hmatch_Htag.push_back(res_bbJ_p4);
                  h_RJ_Hmatch_Htag_Pt.Fill(res_bbJ_p4.Pt(), Wt);
                  h_RJ_Hmatch_Htag_M.Fill(res_bbJ_p4.M(), Wt);

                }
              }//match to H1 in dR0.4
              if(dR_RJ_H1>0.4 && Higgs.size()==2){
                double dR_RJ_H2 = delR(res_bbJ_p4, Higgs.at(1));
                if(dR_RJ_H2<=0.4){
                  res_bbjets_Hmatch.push_back(res_bbJ_p4);
                  h_RJ_Hmatch_Pt.Fill(res_bbJ_p4.Pt(), Wt);
                  h_RJ_Hmatch_M.Fill(res_bbJ_p4.M(), Wt);
                  if(res_bbJ_p4.M()>100 && res_bbJ_p4.M()<150){
                    res_bbjets_Hmatch_Htag.push_back(res_bbJ_p4);
                    h_RJ_Hmatch_Htag_Pt.Fill(res_bbJ_p4.Pt(), Wt);
                    h_RJ_Hmatch_Htag_M.Fill(res_bbJ_p4.M(), Wt);
                  }
                }
              }//match to H2 in dR0.4        
            }
        }//
      }//
    }//bjets loop


    h_NRJ_c.Fill(res_bbjets.size(), Wt);
    h_NRJ_Htag.Fill(res_bbjets_Htag.size(), Wt);
    h_NRJ_Hmatch.Fill(res_bbjets_Hmatch.size(), Wt);
    h_NRJ_Hmatch_Htag.Fill(res_bbjets_Hmatch_Htag.size(), Wt);

    //keep only the RJ closest to Hmass
    int index = 0;
    if(res_bbjets_Htag.size()==1){
      float dM_rj_H = abs(res_bbjets_Htag.at(0).M() - 125);
      dM_RJ_H.push_back(dM_rj_H);
    }
    if(res_bbjets_Htag.size()>1){
      for(int l=0; l<res_bbjets_Htag.size(); l++){
        float dM_rj_H = abs(res_bbjets_Htag.at(l).M() - 125);
        dM_RJ_H.push_back(dM_rj_H);
      }
      //find minima
      float min = dM_RJ_H.at(0);// index=0;
      for(int k=1; k<dM_RJ_H.size(); k++){
        if(dM_RJ_H.at(k) < min ){
          min = dM_RJ_H.at(k);
          index = k;
        }
      }
      //the RJ closest to Hmass is res_bbjets_Htag.at(index)
    }//



//-----------------------------------
    //BS: 1l+met>120+mt>150+ht>500+dP(j12,met)>0.8+NJ5+NbJ2
    int Nl = leptons.size();
    int NJ = jets.size();
    int NbJ = bjets.size();
    bool dPhi_j12_met_08 = false;
    if(jets.size()>1){
      double dPhi_j1_met = delta_phi(MET_Phi, jets.at(0).Phi());
      double dPhi_j2_met = delta_phi(MET_Phi, jets.at(1).Phi());
      if(dPhi_j1_met>0.8 && dPhi_j2_met>0.8){
        dPhi_j12_met_08 = true;
      }
    }


    //BS
    if( (Nl==1) && (MET>120)  && (HT>500) && (NJ>4) && (NbJ>1) ){
      if(dPhi_j12_met_08==true && (MT>150)){

      h_BS_MET.Fill(MET, Wt);
      h_BS_MT.Fill(MT, Wt);
      h_BS_HT.Fill(HT, Wt);
      h_BS_NJ.Fill(NJ, Wt);
      h_BS_NbJ.Fill(NbJ, Wt);

      //Search bins: NbJ=2 ,NbJ>=3
      if(NbJ==2){
        h_BSNbJ2_MET.Fill(MET, Wt);
      }
      if(NbJ>=3){
        h_BSNbJ3_MET.Fill(MET, Wt);
      }//


      if(Higgs.size()>0){
        h_genH_PT.Fill(Higgs.at(0).Pt(), Wt);
        if(Higgs.size()==2){
          h_genH_PT.Fill(Higgs.at(1).Pt(), Wt);
        }
      }//


      //FJ
      h_BS_NFJ.Fill(fatjet_candi.size(), Wt);
      h_BS_NFJ_Htag.Fill(fatjet_Htag.size(), Wt);
      h_BS_NFJ_SD.Fill(fatjet_SD_candi.size(), Wt);
      h_BS_NFJ_SD_Htag.Fill(fatjet_SD_Htag.size(), Wt);
      h_BS_NFJ_SD_Hmatch.Fill(fatjet_SD_Hmatch.size(), Wt);
      h_BS_NFJ_SD_Hmatch_Htag.Fill(fatjet_SD_Hmatch_Htag.size(), Wt);
      h_BS_NFJ_SD_Wmatch.Fill(fatjet_SD_Wmatch.size(), Wt);
      h_BS_NFJ_SD_Wmatch_Wtag.Fill(fatjet_SD_Wmatch_Wtag.size(), Wt);
      h_BS_NFJ_SD_tmatch.Fill(fatjet_SD_tmatch.size(), Wt);
      h_BS_NFJ_SD_tmatch_ttag.Fill(fatjet_SD_tmatch_ttag.size(), Wt);
      h_BS_NFJ_SD_sj12matchbq.Fill(fatjat_SD_sj12matchbq.size(), Wt);
      h_BS_NFJ_SD_sj12matchbq_Htag.Fill(fatjat_SD_sj12matchbq_Htag.size(), Wt);

      for(int a=0; a<fatjet_candi.size(); a++){
        h_BS_FJ_Pt.Fill(fatjet_candi.at(a).Pt(), Wt);
        h_BS_FJ_M.Fill(fatjet_candi.at(a).M(), Wt);
      }
      for(int a=0; a<fatjet_Htag.size(); a++){
        h_BS_FJ_Htag_Pt.Fill(fatjet_Htag.at(a).Pt(), Wt);
        h_BS_FJ_Htag_M.Fill(fatjet_Htag.at(a).M(), Wt);
      }
      for(int a=0; a<fatjet_SD_candi.size(); a++){
        h_BS_FJ_SD_Pt.Fill(fatjet_SD_candi.at(a).Pt(), Wt);
        h_BS_FJ_SD_M.Fill(fatjet_SD_candi.at(a).M(), Wt);
      }
      for(int a=0; a<fatjet_SD_Htag.size(); a++){
        h_BS_FJ_SD_Htag_Pt.Fill(fatjet_SD_Htag.at(a).Pt(), Wt);
        h_BS_FJ_SD_Htag_M.Fill(fatjet_SD_Htag.at(a).M(), Wt);
      }
      for(int a=0; a<fatjet_SD_Hmatch.size(); a++){
        h_BS_FJ_SD_Hmatch_Pt.Fill(fatjet_SD_Hmatch.at(a).Pt(), Wt);
        h_BS_FJ_SD_Hmatch_M.Fill(fatjet_SD_Hmatch.at(a).M(), Wt);
      }
      for(int a=0; a<fatjet_SD_Hmatch_Htag.size(); a++){
        h_BS_FJ_SD_Hmatch_Htag_Pt.Fill(fatjet_SD_Hmatch_Htag.at(a).Pt(), Wt);
        h_BS_FJ_SD_Hmatch_Htag_M.Fill(fatjet_SD_Hmatch_Htag.at(a).M(), Wt);
      }
      for(int a=0; a<fatjet_SD_Wmatch.size(); a++){
        h_BS_FJ_SD_Wmatch_Pt.Fill(fatjet_SD_Wmatch.at(a).Pt(), Wt);
        h_BS_FJ_SD_Wmatch_M.Fill(fatjet_SD_Wmatch.at(a).M(), Wt);
      }
      for(int a=0; a<fatjet_SD_Wmatch_Wtag.size(); a++){
        h_BS_FJ_SD_Wmatch_Wtag_Pt.Fill(fatjet_SD_Wmatch_Wtag.at(a).Pt(), Wt);
        h_BS_FJ_SD_Wmatch_Wtag_M.Fill(fatjet_SD_Wmatch_Wtag.at(a).M(), Wt);
      }
      for(int a=0; a<fatjet_SD_tmatch.size(); a++){
        h_BS_FJ_SD_tmatch_Pt.Fill(fatjet_SD_tmatch.at(a).Pt(), Wt);
        h_BS_FJ_SD_tmatch_M.Fill(fatjet_SD_tmatch.at(a).M(), Wt);
      }
      for(int a=0; a<fatjet_SD_tmatch_ttag.size(); a++){
        h_BS_FJ_SD_tmatch_ttag_Pt.Fill(fatjet_SD_tmatch_ttag.at(a).Pt(), Wt);
        h_BS_FJ_SD_tmatch_ttag_M.Fill(fatjet_SD_tmatch_ttag.at(a).M(), Wt);
      }
      for(int a=0; a<fatjat_SD_sj12matchbq.size(); a++){
        h_BS_FJ_SD_sj12matchbq_Pt.Fill(fatjat_SD_sj12matchbq.at(a).Pt(), Wt);
        h_BS_FJ_SD_sj12matchbq_M.Fill(fatjat_SD_sj12matchbq.at(a).M(), Wt);
      }
      for(int a=0; a<fatjat_SD_sj12matchbq_Htag.size(); a++){
        h_BS_FJ_SD_sj12matchbq_Htag_Pt.Fill(fatjat_SD_sj12matchbq_Htag.at(a).Pt(), Wt);
        h_BS_FJ_SD_sj12matchbq_Htag_M.Fill(fatjat_SD_sj12matchbq_Htag.at(a).M(), Wt);
      }

      for(int a=0; a<fatjet_SD_nomatch.size(); a++){
        h_BS_FJ_SD_nomatch_Pt.Fill(fatjet_SD_nomatch.at(a).Pt(), Wt);
        h_BS_FJ_SD_nomatch_M.Fill(fatjet_SD_nomatch.at(a).M(), Wt);
      }
      if(fatjet_SD_Htag.size()>0){
        h_BS_FJSD_Htag_closest_Pt.Fill(fatjet_SD_Htag.at(index1).Pt(), Wt);
        h_BS_FJSD_Htag_closest_M.Fill(fatjet_SD_Htag.at(index1).M(), Wt);
        h_min_dM_fj_H.Fill(dM_FJ_H.at(index1), Wt);
      }



      //RJ
      h_BS_NRJ.Fill(res_bbjets.size(), Wt);
      h_BS_NRJ_Htag.Fill(res_bbjets_Htag.size(), Wt);
      h_BS_NRJ_Hmatch.Fill(res_bbjets_Hmatch.size(), Wt);
      h_BS_NRJ_Hmatch_Htag.Fill(res_bbjets_Hmatch_Htag.size(), Wt);
      for(int a=0; a<res_bbjets.size(); a++){
        h_BS_RJ_Pt.Fill(res_bbjets.at(a).Pt(), Wt);
        h_BS_RJ_M.Fill(res_bbjets.at(a).M(), Wt);
      }
      for(int a=0; a<res_bbjets_Htag.size(); a++){
        h_BS_RJ_Htag_Pt.Fill(res_bbjets_Htag.at(a).Pt(), Wt);
        h_BS_RJ_Htag_M.Fill(res_bbjets_Htag.at(a).M(), Wt);
      }
      for(int a=0; a<res_bbjets_Hmatch.size(); a++){
        h_BS_RJ_Hmatch_Pt.Fill(res_bbjets_Hmatch.at(a).Pt(), Wt);
        h_BS_RJ_Hmatch_M.Fill(res_bbjets_Hmatch.at(a).M(), Wt);
      }
      for(int a=0; a<res_bbjets_Hmatch_Htag.size(); a++){
        h_BS_RJ_Hmatch_Htag_Pt.Fill(res_bbjets_Hmatch_Htag.at(a).Pt(), Wt);
        h_BS_RJ_Hmatch_Htag_M.Fill(res_bbjets_Hmatch_Htag.at(a).M(), Wt);
      }
      //RJ closest to Hmass
      if(res_bbjets_Htag.size()>0){
        h_BS_RJ_Htag_closest_Pt.Fill(res_bbjets_Htag.at(index).Pt(), Wt);
        h_BS_RJ_Htag_closest_M.Fill(res_bbjets_Htag.at(index).M(), Wt);
        h_min_dM_rj_H.Fill(dM_RJ_H.at(index), Wt);
      }
//---------******--------------******--------------*****----------
//---------******--------------******--------------*****----------
      //Requiring H in event criteria:

      //fj Htag
      if(fatjet_Htag.size()>0){
        h_BS_NFJHtag1_MET.Fill(MET, Wt);
        h_BS_NFJHtag1_MT.Fill(MT, Wt);
        h_BS_NFJHtag1_HT.Fill(HT, Wt);
        h_BS_NFJHtag1_NJ.Fill(NJ, Wt);
        h_BS_NFJHtag1_NbJ.Fill(NbJ, Wt);

        //Search bins: NbJ=2 ,NbJ>=3
        if(NbJ==2){
          h_BSNbJ2_NFJHtag1_MET.Fill(MET, Wt);
        }
        if(NbJ>=3){
          h_BSNbJ3_NFJHtag1_MET.Fill(MET, Wt);
        }//

        if(Higgs.size()>0){
          for(int b=0; b<Higgs.size(); b++){
            h_BSNFJHtag1_genHPt.Fill(Higgs.at(b).Pt(), Wt);
          }
        }

        for(int s=0; s<fatjet_Htag.size(); s++){
          h_BSNFJHtag1_Pt.Fill(fatjet_Htag.at(s).Pt(), Wt);
          h_BSNFJHtag1_M.Fill(fatjet_Htag.at(s).M(), Wt);
        
        }
      }//fj Htag


      //fj sd Htag
      if(fatjet_SD_Htag.size()>0){
        h_BS_NFJSDHtag1_MET.Fill(MET, Wt);
        h_BS_NFJSDHtag1_MT.Fill(MT, Wt);
        h_BS_NFJSDHtag1_HT.Fill(HT, Wt);
        h_BS_NFJSDHtag1_NJ.Fill(NJ, Wt);
        h_BS_NFJSDHtag1_NbJ.Fill(NbJ, Wt);

        //Search bins: NbJ=2 ,NbJ>=3
        if(NbJ==2){
          h_BSNbJ2_NFJSDHtag1_MET.Fill(MET, Wt);
        }
        if(NbJ>=3){
          h_BSNbJ3_NFJSDHtag1_MET.Fill(MET, Wt);
        }//

        if(Higgs.size()>0){
          for(int b=0; b<Higgs.size(); b++){
            h_BSNFJSDHtag1_genHPt.Fill(Higgs.at(b).Pt(), Wt);
          }
        }

        for(int s=0; s<fatjet_SD_Htag.size(); s++){
          h_BSNFJSDHtag1_Pt.Fill(fatjet_SD_Htag.at(s).Pt(), Wt);
          h_BSNFJSDHtag1_M.Fill(fatjet_SD_Htag.at(s).M(), Wt);
        
        }
      }//fj sd Htag

      //fj sd Hmatch Htag
      if(fatjet_SD_Hmatch_Htag.size()>0){
        h_BS_NFJSDHmatchHtag1_MET.Fill(MET, Wt);
        h_BS_NFJSDHmatchHtag1_MT.Fill(MT, Wt);
        h_BS_NFJSDHmatchHtag1_HT.Fill(HT, Wt);
        h_BS_NFJSDHmatchHtag1_NJ.Fill(NJ, Wt);
        h_BS_NFJSDHmatchHtag1_NbJ.Fill(NbJ, Wt);

        //Search bins: NbJ=2 ,NbJ>=3
        if(NbJ==2){
          h_BSNbJ2_NFJSDHmatchHtag1_MET.Fill(MET, Wt);
        }
        if(NbJ>=3){
          h_BSNbJ3_NFJSDHmatchHtag1_MET.Fill(MET, Wt);
        }//

        if(Higgs.size()>0){
          for(int b=0; b<Higgs.size(); b++){
            h_BSNFJSDHmatchHtag1_genHPt.Fill(Higgs.at(b).Pt(), Wt);
          }
        }

        for(int s=0; s<fatjet_SD_Hmatch_Htag.size(); s++){
          h_BSNFJSDHmatchHtag1_Pt.Fill(fatjet_SD_Hmatch_Htag.at(s).Pt(), Wt);
          h_BSNFJSDHmatchHtag1_M.Fill(fatjet_SD_Hmatch_Htag.at(s).M(), Wt);
        
        }
      }//fj sd Hmatch Htag






      //fj sd matchedbq Htag
      if(fatjat_SD_sj12matchbq_Htag.size()>0){
        h_BS_NFJSDmatchbqHtag1_MET.Fill(MET, Wt);
        h_BS_NFJSDmatchbqHtag1_MT.Fill(MT, Wt);
        h_BS_NFJSDmatchbqHtag1_HT.Fill(HT, Wt);
        h_BS_NFJSDmatchbqHtag1_NJ.Fill(NJ, Wt);
        h_BS_NFJSDmatchbqHtag1_NbJ.Fill(NbJ, Wt);

        //Search bins: NbJ=2 ,NbJ>=3
        if(NbJ==2){
          h_BSNbJ2_NFJSDmatchbqHtag1_MET.Fill(MET, Wt);
        }
        if(NbJ>=3){
          h_BSNbJ3_NFJSDmatchbqHtag1_MET.Fill(MET, Wt);
        }//

        if(Higgs.size()>0){
          for(int b=0; b<Higgs.size(); b++){
            h_BSNFJSDmatchbqHtag1_genHPt.Fill(Higgs.at(b).Pt(), Wt);
          }
        }

        for(int s=0; s<fatjat_SD_sj12matchbq_Htag.size(); s++){
          h_BSNFJSDmatchbqHtag1_Pt.Fill(fatjat_SD_sj12matchbq_Htag.at(s).Pt(), Wt);
          h_BSNFJSDmatchbqHtag1_M.Fill(fatjat_SD_sj12matchbq_Htag.at(s).M(), Wt);
        
        }
      }//fj sd matchedbq Htag


      //fj_sd_Htag=0 rj>0
      if(fatjet_SD_Htag.size()==0 && res_bbjets_Htag.size()>0 ){
        h_BS_NFJSDHtag0NRJHtag1_MET.Fill(MET, Wt);
        h_BS_NFJSDHtag0NRJHtag1_MT.Fill(MT, Wt);
        h_BS_NFJSDHtag0NRJHtag1_HT.Fill(HT, Wt);
        h_BS_NFJSDHtag0NRJHtag1_NJ.Fill(NJ, Wt);
        h_BS_NFJSDHtag0NRJHtag1_NbJ.Fill(NbJ, Wt);

        //Search bins: NbJ=2 ,NbJ>=3
        if(NbJ==2){
          h_BSNbJ2_NFJSDHtag0NRJHtag1_MET.Fill(MET, Wt);
        }
        if(NbJ>=3){
          h_BSNbJ3_NFJSDHtag0NRJHtag1_MET.Fill(MET, Wt);
        }//

        if(Higgs.size()>0){
          for(int b=0; b<Higgs.size(); b++){
            h_BSNFJSDHtag0NRJHtag1_genHPt.Fill(Higgs.at(b).Pt(), Wt);
          }
        }

        for(int s=0; s<res_bbjets_Htag.size(); s++){
          h_BSNFJSDHtag0NRJHtag1_Pt.Fill(res_bbjets_Htag.at(s).Pt(), Wt);
          h_BSNFJSDHtag0NRJHtag1_M.Fill(res_bbjets_Htag.at(s).M(), Wt);
        
        }
      }//fj_sd_Htag=0 rj>0



      //RJ Htag
      if(res_bbjets_Htag.size()>0){
        h_BS_NRJHtag1_MET.Fill(MET, Wt);
        h_BS_NRJHtag1_MT.Fill(MT, Wt);
        h_BS_NRJHtag1_HT.Fill(HT, Wt);
        h_BS_NRJHtag1_NJ.Fill(NJ, Wt);
        h_BS_NRJHtag1_NbJ.Fill(NbJ, Wt);

        //Search bins: NbJ=2 ,NbJ>=3
        if(NbJ==2){
          h_BSNbJ2_NRJHtag1_MET.Fill(MET, Wt);
        }
        if(NbJ>=3){
          h_BSNbJ3_NRJHtag1_MET.Fill(MET, Wt);
        }//

        if(Higgs.size()>0){
          for(int b=0; b<Higgs.size(); b++){
            h_BSNRJHtag1_genHPt.Fill(Higgs.at(b).Pt(), Wt);
          }
        }

        for(int s=0; s<res_bbjets_Htag.size(); s++){
          h_BSNRJHtag1_Pt.Fill(res_bbjets_Htag.at(s).Pt(), Wt);
          h_BSNRJHtag1_M.Fill(res_bbjets_Htag.at(s).M(), Wt);
        
        }
      }//RJ Htag

      //RJ Hmatch Htag
      if(res_bbjets_Hmatch_Htag.size()>0){
        h_BS_NRJHmatch_Htag1_MET.Fill(MET, Wt);
        h_BS_NRJHmatch_Htag1_MT.Fill(MT, Wt);
        h_BS_NRJHmatch_Htag1_HT.Fill(HT, Wt);
        h_BS_NRJHmatch_Htag1_NJ.Fill(NJ, Wt);
        h_BS_NRJHmatch_Htag1_NbJ.Fill(NbJ, Wt);

        //Search bins: NbJ=2 ,NbJ>=3
        if(NbJ==2){
          h_BSNbJ2_NRJHmatch_Htag1_MET.Fill(MET, Wt);
        }
        if(NbJ>=3){
          h_BSNbJ3_NRJHmatch_Htag1_MET.Fill(MET, Wt);
        }//

        if(Higgs.size()>0){
          for(int b=0; b<Higgs.size(); b++){
            h_BSNRJHmatch_Htag1_genHPt.Fill(Higgs.at(b).Pt(), Wt);
          }
        }

        for(int s=0; s<res_bbjets_Htag.size(); s++){
          h_BSNRJHmatch_Htag1_Pt.Fill(res_bbjets_Htag.at(s).Pt(), Wt);
          h_BSNRJHmatch_Htag1_M.Fill(res_bbjets_Htag.at(s).M(), Wt);
        
        }
      }//RJ Hmatch Htag





    }//dPhi(j12,met)
    }//bs






  }
//evt loop


  //histogram output
  hist_t1_Pt.Write();
  hist_t_Pt.Write();
  hist_N2_t_Pt.Write();
  hist_N1_t1_Pt.Write();
  hist_N1_N2_Pt.Write();
  hist_H_N2_Pt.Write();
  hist_b_t_Pt.Write();
  hist_W_t_Pt.Write();
  hist_b_H_Pt.Write();
  Nlep.Write();
  NJet.Write();
  NbJet.Write();
  h_FJ_C_Pt.Write();
  h_FJ_C_M.Write();
  h_FJ_Htag_Pt.Write();
  h_FJ_Htag_M.Write();
  h_FJSD_C_Pt.Write();
  h_FJSD_C_M.Write();
  h_FJSD_Htag_Pt.Write();
  h_FJSD_Htag_M.Write();
  h_FJSD_Hmatch_Pt.Write();
  h_FJSD_Hmatch_M.Write();
  h_FJSD_Hmatch_Htag_Pt.Write();
  h_FJSD_Hmatch_Htag_M.Write();
  h_FJSD_Wmatch_Pt.Write();
  h_FJSD_Wmatch_M.Write();
  h_FJSD_Wmatch_Wtag_Pt.Write();
  h_FJSD_Wmatch_Wtag_M.Write();
  h_FJSD_tmatch_Pt.Write();
  h_FJSD_tmatch_M.Write();
  h_FJSD_tmatch_ttag_Pt.Write();
  h_FJSD_tmatch_ttag_M.Write();

  h_FJSD_Nsubjets.Write();
  h_FJSD_sj1_Pt.Write();
  h_FJSD_sj1_M.Write();
  h_FJSD_sj2_Pt.Write();
  h_FJSD_sj2_M.Write();
  h_FJSD_sj12_matchbq_sj1_Pt.Write();
  h_FJSD_sj12_matchbq_sj1_M.Write();
  h_FJSD_sj12_matchbq_sj2_Pt.Write();
  h_FJSD_sj12_matchbq_sj2_M.Write();
  h_FJSD_sj12_matchbq_Pt.Write();
  h_FJSD_sj12_matchbq_M.Write();
  h_FJSD_sj12_matchbq_Htag_Pt.Write();
  h_FJSD_sj12_matchbq_Htag_M.Write();
  NbquarksH.Write();
  NHiggs.Write();
  h_bquarkH_Pt.Write();
  h_Higgs_Pt.Write();
  h_genW_Pt.Write();
  h_gentop_Pt.Write();
  h_NRJ_c.Write();
  h_NRJ_Htag.Write();
  h_NRJ_Hmatch.Write();
  h_NRJ_Hmatch_Htag.Write();
  h_NFJ_c.Write();
  h_NFJ_Htag.Write();
  h_NFJ_SD.Write();
  h_NFJ_SD_Htag.Write();
  h_NFJ_SD_Hmatch.Write();
  h_NFJ_SD_Hmatch_Htag.Write();
  h_NFJ_SD_sj12matchbq.Write();
  h_NFJ_SD_sj12matchbq_Htag.Write();
  h_RJ_c_Pt.Write();
  h_RJ_c_M.Write();
  h_RJ_Htag_Pt.Write();
  h_RJ_Htag_M.Write();
  h_RJ_Hmatch_Pt.Write();
  h_RJ_Hmatch_M.Write();
  h_RJ_Hmatch_Htag_Pt.Write();
  h_RJ_Hmatch_Htag_M.Write();
  //BS
  h_BS_MET.Write();
  h_BS_MT.Write();
  h_BS_HT.Write();
  h_BS_NJ.Write();
  h_BS_NbJ.Write();
  h_BSNbJ2_MET.Write();
  h_BSNbJ3_MET.Write();
  h_genH_PT.Write();
  h_BS_NFJ.Write();
  h_BS_NFJ_Htag.Write();
  h_BS_NFJ_SD.Write();
  h_BS_NFJ_SD_Htag.Write();
  h_BS_NFJ_SD_Hmatch.Write();
  h_BS_NFJ_SD_Hmatch_Htag.Write();
  h_BS_NFJ_SD_Wmatch.Write();
  h_BS_NFJ_SD_Wmatch_Wtag.Write();
  h_BS_NFJ_SD_tmatch.Write();
  h_BS_NFJ_SD_tmatch_ttag.Write();

  h_BS_NFJ_SD_sj12matchbq.Write();
  h_BS_NFJ_SD_sj12matchbq_Htag.Write();
  h_BS_FJ_Pt.Write();
  h_BS_FJ_M.Write();
  h_BS_FJ_Htag_Pt.Write();
  h_BS_FJ_Htag_M.Write();
  h_BS_FJ_SD_Pt.Write();
  h_BS_FJ_SD_M.Write();
  h_BS_FJ_SD_Htag_Pt.Write();
  h_BS_FJ_SD_Htag_M.Write();
  h_BS_FJ_SD_Hmatch_Pt.Write();
  h_BS_FJ_SD_Hmatch_M.Write();
  h_BS_FJ_SD_Hmatch_Htag_Pt.Write();
  h_BS_FJ_SD_Hmatch_Htag_M.Write();
  h_BS_FJ_SD_Wmatch_Pt.Write();
  h_BS_FJ_SD_Wmatch_M.Write();
  h_BS_FJ_SD_Wmatch_Wtag_Pt.Write();
  h_BS_FJ_SD_Wmatch_Wtag_M.Write();
  h_BS_FJ_SD_tmatch_Pt.Write();
  h_BS_FJ_SD_tmatch_M.Write();
  h_BS_FJ_SD_tmatch_ttag_Pt.Write();
  h_BS_FJ_SD_tmatch_ttag_M.Write();
  h_BS_FJ_SD_nomatch_Pt.Write();
  h_BS_FJ_SD_nomatch_M.Write();
  h_min_dM_fj_H.Write();
  h_BS_FJSD_Htag_closest_Pt.Write();
  h_BS_FJSD_Htag_closest_M.Write();
  h_BS_FJ_SD_sj12matchbq_Pt.Write();
  h_BS_FJ_SD_sj12matchbq_M.Write();
  h_BS_FJ_SD_sj12matchbq_Htag_Pt.Write();
  h_BS_FJ_SD_sj12matchbq_Htag_M.Write();

  h_BS_NRJ.Write();
  h_BS_NRJ_Htag.Write();
  h_BS_NRJ_Hmatch.Write();
  h_BS_NRJ_Hmatch_Htag.Write();
  h_BS_RJ_Pt.Write();
  h_BS_RJ_M.Write();
  h_BS_RJ_Htag_Pt.Write();
  h_BS_RJ_Htag_M.Write();
  h_BS_RJ_Hmatch_Pt.Write();
  h_BS_RJ_Hmatch_M.Write();
  h_BS_RJ_Hmatch_Htag_Pt.Write();
  h_BS_RJ_Hmatch_Htag_M.Write();
  h_min_dM_rj_H.Write();
  h_BS_RJ_Htag_closest_Pt.Write();
  h_BS_RJ_Htag_closest_M.Write();

  h_BS_NFJHtag1_MET.Write();
  h_BS_NFJHtag1_MT.Write();
  h_BS_NFJHtag1_HT.Write();
  h_BS_NFJHtag1_NJ.Write();
  h_BS_NFJHtag1_NbJ.Write();
  h_BSNbJ2_NFJHtag1_MET.Write();
  h_BSNbJ3_NFJHtag1_MET.Write();
  h_BSNFJHtag1_genHPt.Write();
  h_BSNFJHtag1_Pt.Write();
  h_BSNFJHtag1_M.Write();

  h_BS_NFJSDHtag1_MET.Write();
  h_BS_NFJSDHtag1_MT.Write();
  h_BS_NFJSDHtag1_HT.Write();
  h_BS_NFJSDHtag1_NJ.Write();
  h_BS_NFJSDHtag1_NbJ.Write();
  h_BSNbJ2_NFJSDHtag1_MET.Write();
  h_BSNbJ3_NFJSDHtag1_MET.Write();
  h_BSNFJSDHtag1_genHPt.Write();
  h_BSNFJSDHtag1_Pt.Write();
  h_BSNFJSDHtag1_M.Write();

  h_BS_NFJSDHmatchHtag1_MET.Write();
  h_BS_NFJSDHmatchHtag1_MT.Write();
  h_BS_NFJSDHmatchHtag1_HT.Write();
  h_BS_NFJSDHmatchHtag1_NJ.Write();
  h_BS_NFJSDHmatchHtag1_NbJ.Write();
  h_BSNbJ2_NFJSDHmatchHtag1_MET.Write();
  h_BSNbJ3_NFJSDHmatchHtag1_MET.Write();
  h_BSNFJSDHmatchHtag1_genHPt.Write();
  h_BSNFJSDHmatchHtag1_Pt.Write();
  h_BSNFJSDHmatchHtag1_M.Write();


  h_BS_NFJSDmatchbqHtag1_MET.Write();
  h_BS_NFJSDmatchbqHtag1_MT.Write();
  h_BS_NFJSDmatchbqHtag1_HT.Write();
  h_BS_NFJSDmatchbqHtag1_NJ.Write();
  h_BS_NFJSDmatchbqHtag1_NbJ.Write();
  h_BSNbJ2_NFJSDmatchbqHtag1_MET.Write();
  h_BSNbJ3_NFJSDmatchbqHtag1_MET.Write();
  h_BSNFJSDmatchbqHtag1_genHPt.Write();
  h_BSNFJSDmatchbqHtag1_Pt.Write();
  h_BSNFJSDmatchbqHtag1_M.Write();

  h_BS_NFJSDHtag0NRJHtag1_MET.Write();
  h_BS_NFJSDHtag0NRJHtag1_MT.Write();
  h_BS_NFJSDHtag0NRJHtag1_HT.Write();
  h_BS_NFJSDHtag0NRJHtag1_NJ.Write();
  h_BS_NFJSDHtag0NRJHtag1_NbJ.Write();
  h_BSNbJ2_NFJSDHtag0NRJHtag1_MET.Write();
  h_BSNbJ3_NFJSDHtag0NRJHtag1_MET.Write();
  h_BSNFJSDHtag0NRJHtag1_genHPt.Write();
  h_BSNFJSDHtag0NRJHtag1_Pt.Write();
  h_BSNFJSDHtag0NRJHtag1_M.Write();

  h_BS_NRJHtag1_MET.Write();
  h_BS_NRJHtag1_MT.Write();
  h_BS_NRJHtag1_HT.Write();
  h_BS_NRJHtag1_NJ.Write();
  h_BS_NRJHtag1_NbJ.Write();
  h_BSNbJ2_NRJHtag1_MET.Write();
  h_BSNbJ3_NRJHtag1_MET.Write();
  h_BSNRJHtag1_genHPt.Write();
  h_BSNRJHtag1_Pt.Write();
  h_BSNRJHtag1_M.Write();

  h_BS_NRJHmatch_Htag1_MET.Write();
  h_BS_NRJHmatch_Htag1_MT.Write();
  h_BS_NRJHmatch_Htag1_HT.Write();
  h_BS_NRJHmatch_Htag1_NJ.Write();
  h_BS_NRJHmatch_Htag1_NbJ.Write();
  h_BSNbJ2_NRJHmatch_Htag1_MET.Write();
  h_BSNbJ3_NRJHmatch_Htag1_MET.Write();
  h_BSNRJHmatch_Htag1_genHPt.Write();
  h_BSNRJHmatch_Htag1_Pt.Write();
  h_BSNRJHmatch_Htag1_M.Write();


}
//----------------------************----------------

float delta_phi(float phi1, float phi2)
 {
   float dphi = fabs(phi1 - phi2);
   if(dphi>TMath::Pi()) dphi = 2*TMath::Pi() - dphi;
   return dphi;
 }

float delta_eta(float eta1, float eta2)
 {
   float deta = fabs(eta1 - eta2);
   return deta;
 }

Double_t delR(TLorentzVector v1,  TLorentzVector v2)
 { 
   return sqrt( pow(delta_eta(v1.Eta(),v2.Eta()),2) + pow(delta_phi(v1.Phi(),v2.Phi()),2) );
 }

