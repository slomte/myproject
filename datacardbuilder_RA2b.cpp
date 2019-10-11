#include "TFile.h"
#include "TH1.h"
#include "TCanvas.h"
//#include "TLegend.h"
//#include "THStack.h"
#include "TF1.h"
#include "TString.h"
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
//using std::cout;
//using std::endl;

int dcBuilder() 
{

  TString aafile ="Hst_t1t1_tN1_tN1_1200400_100k_opt.root"; 
  TString plotname1 = "MET_H_NJ45_NbJ2_1";
  TFile *file_1 = new TFile(aafile);
  TH1F *h_1 = (TH1F *)file_1->Get(plotname1);

  Double_t xbins[6] = {0.0, 300.0, 350.0, 600.0, 850.0, 5000};

  h_1->Rebin(5, "newh_1", xbins);
  TString plotname11 = "newh_1";
  TH1F *newh_1 = (TH1F *)file_1->Get(plotname11);
  double sig_binContent_b1 = newh_1->GetBinContent(2);
  double sig_binError_b1 = newh_1->GetBinError(2);
  double sig_StatUncer_b1 = (sig_binError_b1/sig_binContent_b1)+1 ;

  TString plotname2 = "MET_H_NJ45_NbJ2_2";
  TFile *file_2 = new TFile(aafile);
  TH1F *h_2 = (TH1F *)file_2->Get(plotname2);
  h_2->Rebin(5, "newh_2", xbins);
  TString plotname21 = "newh_2";
  TH1F *newh_2 = (TH1F *)file_2->Get(plotname21);
  double sig_binContent_b2 = newh_2->GetBinContent(2);
  double sig_binError_b2 = newh_2->GetBinError(2);
  double sig_StatUncer_b2 = (sig_binError_b2/sig_binContent_b2)+1 ;

  TString plotname3 = "MET_H_NJ45_NbJ2_3";
  TFile *file_3 = new TFile(aafile);
  TH1F *h_3 = (TH1F *)file_3->Get(plotname3);
  h_3->Rebin(5, "newh_3", xbins);
  TString plotname31 = "newh_3";
  TH1F *newh_3 = (TH1F *)file_3->Get(plotname31);
  double sig_binContent_b3 = newh_3->GetBinContent(2);
  double sig_binError_b3 = newh_3->GetBinError(2);
  double sig_StatUncer_b3 = (sig_binError_b3/sig_binContent_b3)+1 ;

  TString plotname4 = "MET_H_NJ45_NbJ2_4";
  TFile *file_4 = new TFile(aafile);
  TH1F *h_4 = (TH1F *)file_4->Get(plotname4);
  h_4->Rebin(5, "newh_4", xbins);
  TString plotname41 = "newh_4";
  TH1F *newh_4 = (TH1F *)file_4->Get(plotname41);
  double sig_binContent_b4 = newh_4->GetBinContent(3);
  double sig_binError_b4 = newh_4->GetBinError(3);
  double sig_StatUncer_b4 = (sig_binError_b4/sig_binContent_b4)+1 ;

  TString plotname5 = "MET_H_NJ45_NbJ2_5";
  TFile *file_5 = new TFile(aafile);
  TH1F *h_5 = (TH1F *)file_5->Get(plotname5);
  h_5->Rebin(5, "newh_5", xbins);
  TString plotname51 = "newh_5";
  TH1F *newh_5 = (TH1F *)file_5->Get(plotname51);
  double sig_binContent_b5 = newh_5->GetBinContent(3);
  double sig_binError_b5 = newh_5->GetBinError(3);
  double sig_StatUncer_b5 = (sig_binError_b5/sig_binContent_b5)+1 ;

  TString plotname6 = "MET_H_NJ45_NbJ2_6";
  TFile *file_6 = new TFile(aafile);
  TH1F *h_6 = (TH1F *)file_6->Get(plotname6);
  h_6->Rebin(5, "newh_6", xbins);
  TString plotname61 = "newh_6";
  TH1F *newh_6 = (TH1F *)file_6->Get(plotname61);
  double sig_binContent_b6 = newh_6->GetBinContent(3);
  double sig_binError_b6 = newh_6->GetBinError(3);
  double sig_StatUncer_b6 = (sig_binError_b6/sig_binContent_b6)+1 ;

  TString plotname7 = "MET_H_NJ45_NbJ2_7";
  TFile *file_7 = new TFile(aafile);
  TH1F *h_7 = (TH1F *)file_7->Get(plotname7);
  h_7->Rebin(5, "newh_7", xbins);
  TString plotname71 = "newh_7";
  TH1F *newh_7 = (TH1F *)file_7->Get(plotname71);
  double sig_binContent_b7 = newh_7->GetBinContent(4);
  double sig_binError_b7 = newh_7->GetBinError(4);
  double sig_StatUncer_b7 = (sig_binError_b7/sig_binContent_b7)+1 ;

  TString plotname8 = "MET_H_NJ45_NbJ2_8";
  TFile *file_8 = new TFile(aafile);
  TH1F *h_8 = (TH1F *)file_8->Get(plotname8);
  h_8->Rebin(5, "newh_8", xbins);
  TString plotname81 = "newh_8";
  TH1F *newh_8 = (TH1F *)file_8->Get(plotname81);
  double sig_binContent_b8 = newh_8->GetBinContent(4);
  double sig_binError_b8 = newh_8->GetBinError(4);
  double sig_StatUncer_b8 = (sig_binError_b8/sig_binContent_b8)+1 ;

  TString plotname9 = "MET_H_NJ45_NbJ2_9";
  TFile *file_9 = new TFile(aafile);
  TH1F *h_9 = (TH1F *)file_9->Get(plotname9);
  h_9->Rebin(5, "newh_9", xbins);
  TString plotname91 = "newh_9";
  TH1F *newh_9 = (TH1F *)file_9->Get(plotname91);
  double sig_binContent_b9 = newh_9->GetBinContent(5);
  double sig_binError_b9 = newh_9->GetBinError(5);
  double sig_StatUncer_b9 = (sig_binError_b9/sig_binContent_b9)+1 ;

  TString plotname10 = "MET_H_NJ45_NbJ2_10";
  TFile *file_10 = new TFile(aafile);
  TH1F *h_10 = (TH1F *)file_10->Get(plotname10);
  h_10->Rebin(5, "newh_10", xbins);
  TString plotname101 = "newh_10";
  TH1F *newh_10 = (TH1F *)file_10->Get(plotname101);
  double sig_binContent_b10 = newh_10->GetBinContent(5);
  double sig_binError_b10 = newh_10->GetBinError(5);
  double sig_StatUncer_b10 = (sig_binError_b10/sig_binContent_b10)+1 ;
///////////////////////////////////////////////////////////////////////
  //ttbar
  TString bbfile ="Hst_SkimTTbar_HT_600_Inf_opt.root";
  TString plotnameb1 = "MET_H_NJ45_NbJ2_1";
  TFile *file_bb1 = new TFile(bbfile);
  TH1F *hbb_1 = (TH1F *)file_bb1->Get(plotnameb1);
  hbb_1->Rebin(5, "newhbb_1", xbins);
  TString plotnameb11 = "newhbb_1";
  TH1F *newhbb_1 = (TH1F *)file_bb1->Get(plotnameb11);
  double bg1_binContent_b1 = newhbb_1->GetBinContent(2);
  double bg1_binError_b1 = newhbb_1->GetBinError(2);
  double bg1_StatUncer_b1 = (bg1_binError_b1/bg1_binContent_b1)+1 ;

  TString plotnameb2 = "MET_H_NJ45_NbJ2_2";
  TFile *file_bb2 = new TFile(bbfile);
  TH1F *hbb_2 = (TH1F *)file_bb2->Get(plotnameb2);
  hbb_2->Rebin(5, "newhbb_2", xbins);
  TString plotnameb21 = "newhbb_2";
  TH1F *newhbb_2 = (TH1F *)file_bb2->Get(plotnameb21);
  double bg1_binContent_b2 = newhbb_2->GetBinContent(2);
  double bg1_binError_b2 = newhbb_2->GetBinError(2);
  double bg1_StatUncer_b2 = (bg1_binError_b2/bg1_binContent_b2)+1 ;

  TString plotnameb3 = "MET_H_NJ45_NbJ2_3";
  TFile *file_bb3 = new TFile(bbfile);
  TH1F *hbb_3 = (TH1F *)file_bb3->Get(plotnameb3);
  hbb_3->Rebin(5, "newhbb_3", xbins);
  TString plotnameb31 = "newhbb_3";
  TH1F *newhbb_3 = (TH1F *)file_bb3->Get(plotnameb31);
  double bg1_binContent_b3 = newhbb_3->GetBinContent(2);
  double bg1_binError_b3 = newhbb_3->GetBinError(2);
  double bg1_StatUncer_b3 = (bg1_binError_b3/bg1_binContent_b3)+1 ;

  TString plotnameb4 = "MET_H_NJ45_NbJ2_4";
  TFile *file_bb4 = new TFile(bbfile);
  TH1F *hbb_4 = (TH1F *)file_bb4->Get(plotnameb4);
  hbb_4->Rebin(5, "newhbb_4", xbins);
  TString plotnameb41 = "newhbb_4";
  TH1F *newhbb_4 = (TH1F *)file_bb4->Get(plotnameb41);
  double bg1_binContent_b4 = newhbb_4->GetBinContent(3);
  double bg1_binError_b4 = newhbb_4->GetBinError(3);
  double bg1_StatUncer_b4 = (bg1_binError_b4/bg1_binContent_b4)+1 ;

  TString plotnameb5 = "MET_H_NJ45_NbJ2_5";
  TFile *file_bb5 = new TFile(bbfile);
  TH1F *hbb_5 = (TH1F *)file_bb5->Get(plotnameb5);
  hbb_5->Rebin(5, "newhbb_5", xbins);
  TString plotnameb51 = "newhbb_5";
  TH1F *newhbb_5 = (TH1F *)file_bb5->Get(plotnameb51);
  double bg1_binContent_b5 = newhbb_5->GetBinContent(3);
  double bg1_binError_b5 = newhbb_5->GetBinError(3);
  double bg1_StatUncer_b5 = (bg1_binError_b5/bg1_binContent_b5)+1 ;

  TString plotnameb6 = "MET_H_NJ45_NbJ2_6";
  TFile *file_bb6 = new TFile(bbfile);
  TH1F *hbb_6 = (TH1F *)file_bb6->Get(plotnameb6);
  hbb_6->Rebin(5, "newhbb_6", xbins);
  TString plotnameb61 = "newhbb_6";
  TH1F *newhbb_6 = (TH1F *)file_bb6->Get(plotnameb61);
  double bg1_binContent_b6 = newhbb_6->GetBinContent(3);
  double bg1_binError_b6 = newhbb_6->GetBinError(3);
  double bg1_StatUncer_b6 = (bg1_binError_b6/bg1_binContent_b6)+1 ;

  TString plotnameb7 = "MET_H_NJ45_NbJ2_7";
  TFile *file_bb7 = new TFile(bbfile);
  TH1F *hbb_7 = (TH1F *)file_bb7->Get(plotnameb7);
  hbb_7->Rebin(5, "newhbb_7", xbins);
  TString plotnameb71 = "newhbb_7";
  TH1F *newhbb_7 = (TH1F *)file_bb7->Get(plotnameb71);
  double bg1_binContent_b7 = newhbb_7->GetBinContent(4);
  double bg1_binError_b7 = newhbb_7->GetBinError(4);
  double bg1_StatUncer_b7 = (bg1_binError_b7/bg1_binContent_b7)+1 ;

  TString plotnameb8 = "MET_H_NJ45_NbJ2_8";
  TFile *file_bb8 = new TFile(bbfile);
  TH1F *hbb_8 = (TH1F *)file_bb8->Get(plotnameb8);
  hbb_8->Rebin(5, "newhbb_8", xbins);
  TString plotnameb81 = "newhbb_8";
  TH1F *newhbb_8 = (TH1F *)file_bb8->Get(plotnameb81);
  double bg1_binContent_b8 = newhbb_8->GetBinContent(4);
  double bg1_binError_b8 = newhbb_8->GetBinError(4);
  double bg1_StatUncer_b8 = (bg1_binError_b8/bg1_binContent_b8)+1 ;

  TString plotnameb9 = "MET_H_NJ45_NbJ2_9";
  TFile *file_bb9 = new TFile(bbfile);
  TH1F *hbb_9 = (TH1F *)file_bb9->Get(plotnameb9);
  hbb_9->Rebin(5, "newhbb_9", xbins);
  TString plotnameb91 = "newhbb_9";
  TH1F *newhbb_9 = (TH1F *)file_bb9->Get(plotnameb91);
  double bg1_binContent_b9 = newhbb_9->GetBinContent(5);
  double bg1_binError_b9 = newhbb_9->GetBinError(5);
  double bg1_StatUncer_b9 = (bg1_binError_b9/bg1_binContent_b9)+1 ;

  TString plotnameb10 = "MET_H_NJ45_NbJ2_10";
  TFile *file_bb10 = new TFile(bbfile);
  TH1F *hbb_10 = (TH1F *)file_bb10->Get(plotnameb10);
  hbb_10->Rebin(5, "newhbb_10", xbins);
  TString plotnameb101 = "newhbb_10";
  TH1F *newhbb_10 = (TH1F *)file_bb10->Get(plotnameb101);
  double bg1_binContent_b10 = newhbb_10->GetBinContent(5);
  double bg1_binError_b10 = newhbb_10->GetBinError(5);
  double bg1_StatUncer_b10 = (bg1_binError_b10/bg1_binContent_b10)+1 ;
//////////////////////////////////////////////////////////////////
  //Z+Jets
  TString ccfile ="Hst_SkimZJet_HT_100_Inf_opt.root";
  TString plotnamec1 = "MET_H_NJ45_NbJ2_1";
  TFile *file_cc1 = new TFile(ccfile);
  TH1F *hcc_1 = (TH1F *)file_cc1->Get(plotnamec1);
  hcc_1->Rebin(5, "newhcc_1", xbins);
  TString plotnamec11 = "newhcc_1";
  TH1F *newhcc_1 = (TH1F *)file_cc1->Get(plotnamec11);
  double bg2_binContent_b1 = newhcc_1->GetBinContent(2);
  double bg2_binError_b1 = newhcc_1->GetBinError(2);
  double bg2_StatUncer_b1 = (bg2_binError_b1/bg2_binContent_b1)+1 ;

  TString plotnamec2 = "MET_H_NJ45_NbJ2_2";
  TFile *file_cc2 = new TFile(ccfile);
  TH1F *hcc_2 = (TH1F *)file_cc2->Get(plotnamec2);
  hcc_2->Rebin(5, "newhcc_2", xbins);
  TString plotnamec21 = "newhcc_2";
  TH1F *newhcc_2 = (TH1F *)file_cc2->Get(plotnamec21);
  double bg2_binContent_b2 = newhcc_2->GetBinContent(2);
  double bg2_binError_b2 = newhcc_2->GetBinError(2);
  double bg2_StatUncer_b2 = (bg2_binError_b2/bg2_binContent_b2)+1 ;

  TString plotnamec3 = "MET_H_NJ45_NbJ2_3";
  TFile *file_cc3 = new TFile(ccfile);
  TH1F *hcc_3 = (TH1F *)file_cc3->Get(plotnamec3);
  hcc_3->Rebin(5, "newhcc_3", xbins);
  TString plotnamec31 = "newhcc_3";
  TH1F *newhcc_3 = (TH1F *)file_cc3->Get(plotnamec31);
  double bg2_binContent_b3 = newhcc_3->GetBinContent(2);
  double bg2_binError_b3 = newhcc_3->GetBinError(2);
  double bg2_StatUncer_b3 = (bg2_binError_b3/bg2_binContent_b3)+1 ;

  TString plotnamec4 = "MET_H_NJ45_NbJ2_4";
  TFile *file_cc4 = new TFile(ccfile);
  TH1F *hcc_4 = (TH1F *)file_cc4->Get(plotnamec4);
  hcc_4->Rebin(5, "newhcc_4", xbins);
  TString plotnamec41 = "newhcc_4";
  TH1F *newhcc_4 = (TH1F *)file_cc4->Get(plotnamec41);
  double bg2_binContent_b4 = newhcc_4->GetBinContent(3);
  double bg2_binError_b4 = newhcc_4->GetBinError(3);
  double bg2_StatUncer_b4 = (bg2_binError_b4/bg2_binContent_b4)+1 ;

  TString plotnamec5 = "MET_H_NJ45_NbJ2_5";
  TFile *file_cc5 = new TFile(ccfile);
  TH1F *hcc_5 = (TH1F *)file_cc5->Get(plotnamec5);
  hcc_5->Rebin(5, "newhcc_5", xbins);
  TString plotnamec51 = "newhcc_5";
  TH1F *newhcc_5 = (TH1F *)file_cc5->Get(plotnamec51);
  double bg2_binContent_b5 = newhcc_5->GetBinContent(3);
  double bg2_binError_b5 = newhcc_5->GetBinError(3);
  double bg2_StatUncer_b5 = (bg2_binError_b5/bg2_binContent_b5)+1 ;

  TString plotnamec6 = "MET_H_NJ45_NbJ2_6";
  TFile *file_cc6 = new TFile(ccfile);
  TH1F *hcc_6 = (TH1F *)file_cc6->Get(plotnamec6);
  hcc_6->Rebin(5, "newhcc_6", xbins);
  TString plotnamec61 = "newhcc_6";
  TH1F *newhcc_6 = (TH1F *)file_cc6->Get(plotnamec61);
  double bg2_binContent_b6 = newhcc_6->GetBinContent(3);
  double bg2_binError_b6 = newhcc_6->GetBinError(3);
  double bg2_StatUncer_b6 = (bg2_binError_b6/bg2_binContent_b6)+1 ;

  TString plotnamec7 = "MET_H_NJ45_NbJ2_7";
  TFile *file_cc7 = new TFile(ccfile);
  TH1F *hcc_7 = (TH1F *)file_cc7->Get(plotnamec7);
  hcc_7->Rebin(5, "newhcc_7", xbins);
  TString plotnamec71 = "newhcc_7";
  TH1F *newhcc_7 = (TH1F *)file_cc7->Get(plotnamec71);
  double bg2_binContent_b7 = newhcc_7->GetBinContent(4);
  double bg2_binError_b7 = newhcc_7->GetBinError(4);
  double bg2_StatUncer_b7 = (bg2_binError_b7/bg2_binContent_b7)+1 ;

  TString plotnamec8 = "MET_H_NJ45_NbJ2_8";
  TFile *file_cc8 = new TFile(ccfile);
  TH1F *hcc_8 = (TH1F *)file_cc8->Get(plotnamec8);
  hcc_8->Rebin(5, "newhcc_8", xbins);
  TString plotnamec81 = "newhcc_8";
  TH1F *newhcc_8 = (TH1F *)file_cc8->Get(plotnamec81);
  double bg2_binContent_b8 = newhcc_8->GetBinContent(4);
  double bg2_binError_b8 = newhcc_8->GetBinError(4);
  double bg2_StatUncer_b8 = (bg2_binError_b8/bg2_binContent_b8)+1 ;

  TString plotnamec9 = "MET_H_NJ45_NbJ2_9";
  TFile *file_cc9 = new TFile(ccfile);
  TH1F *hcc_9 = (TH1F *)file_cc9->Get(plotnamec9);
  hcc_9->Rebin(5, "newhcc_9", xbins);
  TString plotnamec91 = "newhcc_9";
  TH1F *newhcc_9 = (TH1F *)file_cc9->Get(plotnamec91);
  double bg2_binContent_b9 = newhcc_9->GetBinContent(5);
  double bg2_binError_b9 = newhcc_9->GetBinError(5);
  double bg2_StatUncer_b9 = (bg2_binError_b9/bg2_binContent_b9)+1 ;

  TString plotnamec10 = "MET_H_NJ45_NbJ2_10";
  TFile *file_cc10 = new TFile(ccfile);
  TH1F *hcc_10 = (TH1F *)file_cc10->Get(plotnamec10);
  hcc_10->Rebin(5, "newhcc_10", xbins);
  TString plotnamec101 = "newhcc_10";
  TH1F *newhcc_10 = (TH1F *)file_cc10->Get(plotnamec101);
  double bg2_binContent_b10 = newhcc_10->GetBinContent(5);
  double bg2_binError_b10 = newhcc_10->GetBinError(5);
  double bg2_StatUncer_b10 = (bg2_binError_b10/bg2_binContent_b10)+1 ;
///////////////////////////////////////////////////////////////////////
  //W+Jets
  TString ddfile ="Hst_SkimWJet_100_Inf_opt.root";
  TString plotnamed1 = "MET_H_NJ45_NbJ2_1";
  TFile *file_dd1 = new TFile(ddfile);
  TH1F *hdd_1 = (TH1F *)file_dd1->Get(plotnamed1);
  hdd_1->Rebin(5, "newhdd_1", xbins);
  TString plotnamed11 = "newhdd_1";
  TH1F *newhdd_1 = (TH1F *)file_dd1->Get(plotnamed11);
  double bg3_binContent_b1 = newhdd_1->GetBinContent(2);
  double bg3_binError_b1 = newhdd_1->GetBinError(2);
  double bg3_StatUncer_b1 = (bg3_binError_b1/bg3_binContent_b1)+1 ;

  TString plotnamed2 = "MET_H_NJ45_NbJ2_2";
  TFile *file_dd2 = new TFile(ddfile);
  TH1F *hdd_2 = (TH1F *)file_dd2->Get(plotnamed2);
  hdd_2->Rebin(5, "newhdd_2", xbins);
  TString plotnamed21 = "newhdd_2";
  TH1F *newhdd_2 = (TH1F *)file_dd2->Get(plotnamed21);
  double bg3_binContent_b2 = newhdd_2->GetBinContent(2);
  double bg3_binError_b2 = newhdd_2->GetBinError(2);
  double bg3_StatUncer_b2 = (bg3_binError_b2/bg3_binContent_b2)+1 ;

  TString plotnamed3 = "MET_H_NJ45_NbJ2_3";
  TFile *file_dd3 = new TFile(ddfile);
  TH1F *hdd_3 = (TH1F *)file_dd3->Get(plotnamed3);
  hdd_3->Rebin(5, "newhdd_3", xbins);
  TString plotnamed31 = "newhdd_3";
  TH1F *newhdd_3 = (TH1F *)file_dd3->Get(plotnamed31);
  double bg3_binContent_b3 = newhdd_3->GetBinContent(2);
  double bg3_binError_b3 = newhdd_3->GetBinError(2);
  double bg3_StatUncer_b3 = (bg3_binError_b3/bg3_binContent_b3)+1 ;

  TString plotnamed4 = "MET_H_NJ45_NbJ2_4";
  TFile *file_dd4 = new TFile(ddfile);
  TH1F *hdd_4 = (TH1F *)file_dd4->Get(plotnamed4);
  hdd_4->Rebin(5, "newhdd_4", xbins);
  TString plotnamed41 = "newhdd_4";
  TH1F *newhdd_4 = (TH1F *)file_dd4->Get(plotnamed41);
  double bg3_binContent_b4 = newhdd_4->GetBinContent(3);
  double bg3_binError_b4 = newhdd_4->GetBinError(3);
  double bg3_StatUncer_b4 = (bg3_binError_b4/bg3_binContent_b4)+1 ;

  TString plotnamed5 = "MET_H_NJ45_NbJ2_5";
  TFile *file_dd5 = new TFile(ddfile);
  TH1F *hdd_5 = (TH1F *)file_dd5->Get(plotnamed5);
  hdd_5->Rebin(5, "newhdd_5", xbins);
  TString plotnamed51 = "newhdd_5";
  TH1F *newhdd_5 = (TH1F *)file_dd5->Get(plotnamed51);
  double bg3_binContent_b5 = newhdd_5->GetBinContent(3);
  double bg3_binError_b5 = newhdd_5->GetBinError(3);
  double bg3_StatUncer_b5 = (bg3_binError_b5/bg3_binContent_b5)+1 ;

  TString plotnamed6 = "MET_H_NJ45_NbJ2_6";
  TFile *file_dd6 = new TFile(ddfile);
  TH1F *hdd_6 = (TH1F *)file_dd6->Get(plotnamed6);
  hdd_6->Rebin(5, "newhdd_6", xbins);
  TString plotnamed61 = "newhdd_6";
  TH1F *newhdd_6 = (TH1F *)file_dd6->Get(plotnamed61);
  double bg3_binContent_b6 = newhdd_6->GetBinContent(3);
  double bg3_binError_b6 = newhdd_6->GetBinError(3);
  double bg3_StatUncer_b6 = (bg3_binError_b6/bg3_binContent_b6)+1 ;

  TString plotnamed7 = "MET_H_NJ45_NbJ2_7";
  TFile *file_dd7 = new TFile(ddfile);
  TH1F *hdd_7 = (TH1F *)file_dd7->Get(plotnamed7);
  hdd_7->Rebin(5, "newhdd_7", xbins);
  TString plotnamed71 = "newhdd_7";
  TH1F *newhdd_7 = (TH1F *)file_dd7->Get(plotnamed71);
  double bg3_binContent_b7 = newhdd_7->GetBinContent(4);
  double bg3_binError_b7 = newhdd_7->GetBinError(4);
  double bg3_StatUncer_b7 = (bg3_binError_b7/bg3_binContent_b7)+1 ;

  TString plotnamed8 = "MET_H_NJ45_NbJ2_8";
  TFile *file_dd8 = new TFile(ddfile);
  TH1F *hdd_8 = (TH1F *)file_dd8->Get(plotnamed8);
  hdd_8->Rebin(5, "newhdd_8", xbins);
  TString plotnamed81 = "newhdd_8";
  TH1F *newhdd_8 = (TH1F *)file_dd8->Get(plotnamed81);
  double bg3_binContent_b8 = newhdd_8->GetBinContent(4);
  double bg3_binError_b8 = newhdd_8->GetBinError(4);
  double bg3_StatUncer_b8 = (bg3_binError_b8/bg3_binContent_b8)+1 ;

  TString plotnamed9 = "MET_H_NJ45_NbJ2_9";
  TFile *file_dd9 = new TFile(ddfile);
  TH1F *hdd_9 = (TH1F *)file_dd9->Get(plotnamed9);
  hdd_9->Rebin(5, "newhdd_9", xbins);
  TString plotnamed91 = "newhdd_9";
  TH1F *newhdd_9 = (TH1F *)file_dd9->Get(plotnamed91);
  double bg3_binContent_b9 = newhdd_9->GetBinContent(5);
  double bg3_binError_b9 = newhdd_9->GetBinError(5);
  double bg3_StatUncer_b9 = (bg3_binError_b9/bg3_binContent_b9)+1 ;

  TString plotnamed10 = "MET_H_NJ45_NbJ2_10";
  TFile *file_dd10 = new TFile(ddfile);
  TH1F *hdd_10 = (TH1F *)file_dd10->Get(plotnamed10);
  hdd_10->Rebin(5, "newhdd_10", xbins);
  TString plotnamed101 = "newhdd_10";
  TH1F *newhdd_10 = (TH1F *)file_dd10->Get(plotnamed101);
  double bg3_binContent_b10 = newhdd_10->GetBinContent(5);
  double bg3_binError_b10 = newhdd_10->GetBinError(5);
  double bg3_StatUncer_b10 = (bg3_binError_b10/bg3_binContent_b10)+1 ;
///////////////////////////////////////////////////////////////////////
  //QCD
  TString eefile ="Hst_SkimQCD_HT_200_Inf_opt.root";
  TString plotnamee1 = "MET_H_NJ45_NbJ2_1";
  TFile *file_ee1 = new TFile(eefile);
  TH1F *hee_1 = (TH1F *)file_ee1->Get(plotnamee1);
  hee_1->Rebin(5, "newhee_1", xbins);
  TString plotnamee11 = "newhee_1";
  TH1F *newhee_1 = (TH1F *)file_ee1->Get(plotnamee11);
  double bg4_binContent_b1 = newhee_1->GetBinContent(2);
  double bg4_binError_b1 = newhee_1->GetBinError(2);
  double bg4_StatUncer_b1 = (bg4_binError_b1/bg4_binContent_b1)+1 ;

  TString plotnamee2 = "MET_H_NJ45_NbJ2_2";
  TFile *file_ee2 = new TFile(eefile);
  TH1F *hee_2 = (TH1F *)file_ee2->Get(plotnamee2);
  hee_2->Rebin(5, "newhee_2", xbins);
  TString plotnamee21 = "newhee_2";
  TH1F *newhee_2 = (TH1F *)file_ee2->Get(plotnamee21);
  double bg4_binContent_b2 = newhee_2->GetBinContent(2);
  double bg4_binError_b2 = newhee_2->GetBinError(2);
  double bg4_StatUncer_b2 = (bg4_binError_b2/bg4_binContent_b2)+1 ;

  TString plotnamee3 = "MET_H_NJ45_NbJ2_3";
  TFile *file_ee3 = new TFile(eefile);
  TH1F *hee_3 = (TH1F *)file_ee3->Get(plotnamee3);
  hee_3->Rebin(5, "newhee_3", xbins);
  TString plotnamee31 = "newhee_3";
  TH1F *newhee_3 = (TH1F *)file_ee3->Get(plotnamee31);
  double bg4_binContent_b3 = newhee_3->GetBinContent(2);
  double bg4_binError_b3 = newh_3->GetBinError(2);
  double bg4_StatUncer_b3 = (bg4_binError_b3/bg4_binContent_b3)+1 ;

  TString plotnamee4 = "MET_H_NJ45_NbJ2_4";
  TFile *file_ee4 = new TFile(eefile);
  TH1F *hee_4 = (TH1F *)file_ee4->Get(plotnamee4);
  hee_4->Rebin(5, "newhee_4", xbins);
  TString plotnamee41 = "newhee_4";
  TH1F *newhee_4 = (TH1F *)file_ee4->Get(plotnamee41);
  double bg4_binContent_b4 = newhee_4->GetBinContent(3);
  double bg4_binError_b4 = newhee_4->GetBinError(3);
  double bg4_StatUncer_b4 = (bg4_binError_b4/bg4_binContent_b4)+1 ;

  TString plotnamee5 = "MET_H_NJ45_NbJ2_5";
  TFile *file_ee5 = new TFile(eefile);
  TH1F *hee_5 = (TH1F *)file_ee5->Get(plotnamee5);
  hee_5->Rebin(5, "newhee_5", xbins);
  TString plotnamee51 = "newhee_5";
  TH1F *newhee_5 = (TH1F *)file_ee5->Get(plotnamee51);
  double bg4_binContent_b5 = newhee_5->GetBinContent(3);
  double bg4_binError_b5 = newhee_5->GetBinError(3);
  double bg4_StatUncer_b5 = (bg4_binError_b5/bg4_binContent_b5)+1 ;

  TString plotnamee6 = "MET_H_NJ45_NbJ2_6";
  TFile *file_ee6 = new TFile(eefile);
  TH1F *hee_6 = (TH1F *)file_ee6->Get(plotnamee6);
  hee_6->Rebin(5, "newhee_6", xbins);
  TString plotnamee61 = "newhee_6";
  TH1F *newhee_6 = (TH1F *)file_ee6->Get(plotnamee61);
  double bg4_binContent_b6 = newhee_6->GetBinContent(3);
  double bg4_binError_b6 = newhee_6->GetBinError(3);
  double bg4_StatUncer_b6 = (bg4_binError_b6/bg4_binContent_b6)+1 ;

  TString plotnamee7 = "MET_H_NJ45_NbJ2_7";
  TFile *file_ee7 = new TFile(eefile);
  TH1F *hee_7 = (TH1F *)file_ee7->Get(plotnamee7);
  hee_7->Rebin(5, "newhee_7", xbins);
  TString plotnamee71 = "newhee_7";
  TH1F *newhee_7 = (TH1F *)file_ee7->Get(plotnamee71);
  double bg4_binContent_b7 = newhee_7->GetBinContent(4);
  double bg4_binError_b7 = newhee_7->GetBinError(4);
  double bg4_StatUncer_b7 = (bg4_binError_b7/bg4_binContent_b7)+1 ;

  TString plotnamee8 = "MET_H_NJ45_NbJ2_8";
  TFile *file_ee8 = new TFile(eefile);
  TH1F *hee_8 = (TH1F *)file_ee8->Get(plotnamee8);
  hee_8->Rebin(5, "newhee_8", xbins);
  TString plotnamee81 = "newhee_8";
  TH1F *newhee_8 = (TH1F *)file_ee8->Get(plotnamee81);
  double bg4_binContent_b8 = newhee_8->GetBinContent(4);
  double bg4_binError_b8 = newhee_8->GetBinError(4);
  double bg4_StatUncer_b8 = (bg4_binError_b8/bg4_binContent_b8)+1 ;

  TString plotnamee9 = "MET_H_NJ45_NbJ2_9";
  TFile *file_ee9 = new TFile(eefile);
  TH1F *hee_9 = (TH1F *)file_ee9->Get(plotnamee9);
  hee_9->Rebin(5, "newhee_9", xbins);
  TString plotnamee91 = "newhee_9";
  TH1F *newhee_9 = (TH1F *)file_ee9->Get(plotnamee91);
  double bg4_binContent_b9 = newhee_9->GetBinContent(5);
  double bg4_binError_b9 = newhee_9->GetBinError(5);
  double bg4_StatUncer_b9 = (bg4_binError_b9/bg4_binContent_b9)+1 ;

  TString plotnamee10 = "MET_H_NJ45_NbJ2_10";
  TFile *file_ee10 = new TFile(eefile);
  TH1F *hee_10 = (TH1F *)file_ee10->Get(plotnamee10);
  hee_10->Rebin(5, "newhee_10", xbins);
  TString plotnamee101 = "newhee_10";
  TH1F *newhee_10 = (TH1F *)file_ee10->Get(plotnamee101);
  double bg4_binContent_b10 = newhee_10->GetBinContent(5);
  double bg4_binError_b10 = newhee_10->GetBinError(5);
  double bg4_StatUncer_b10 = (bg4_binError_b10/bg4_binContent_b10)+1 ;
///////////////////////////////////////////////////////////////////////




  //declare our output datacard txt file
  //bin1
  ofstream myfile1;
  myfile1.open("dc_MET_H_NJ45_NbJ2_bin1.txt");
  myfile1<<"# Simple counting experiment for 1 signal and 4 bgs. \n";
  myfile1<<"# stop->top N2, N2->H N1 and stop->top N1 with mass(stop, N2, N1)=(1200, 600, 300) GeV \n";
  myfile1<<"imax 1  number of channels \n";
  myfile1<<"jmax 4  number of backgrounds \n";
  myfile1<<"kmax 10  number of nuisance parameters (sources of systematical uncertainties) \n";
  myfile1<<"-------------------------------------------------------------------------------------- \n";
  myfile1<<"# one channel, 0 obs events \n";
  myfile1<<"bin bin1 \n";
  myfile1<<"observation 0 \n";
  myfile1<<"-------------------------------------------------------------------------------------- \n";
  myfile1<<"bin                             bin1           bin1            bin1            bin1            bin1            \n";
  myfile1<<"process                         ggt1t1         ttbar           ZJ              WJ              QCD             \n";
  myfile1<<"process                         0              1               2               3               4               \n";
  myfile1<<"rate                            "<<sig_binContent_b1<<"           "<<bg1_binContent_b1<<"         "<<bg2_binContent_b1<<"         "<<bg3_binContent_b1<<"         "<<bg4_binContent_b1<<" \n";
  myfile1<<"-------------------------------------------------------------------------------------- \n";
  myfile1<<"syst_uncert_ggt1t1_bin1   lnN   1.20            -               -               -               -               \n";
  myfile1<<"syst_uncert_ttbar_bin1    lnN    -             1.20             -               -               -               \n";
  myfile1<<"syst_uncert_ZJ_bin1       lnN    -              -              1.20             -               -               \n";
  myfile1<<"syst_uncert_WJ_bin1       lnN    -              -               -              1.20             -               \n";
  myfile1<<"syst_uncert_QCD_bin1      lnN    -              -               -               -              1.20             \n";

  myfile1<<"stat_uncert_ggt1t1_bin1   lnN   "<<sig_StatUncer_b1<<"          -               -               -               -         \n";
  myfile1<<"stat_uncert_ttbar_bin1    lnN    -             "<<bg1_StatUncer_b1<<"           -               -               -         \n";
  myfile1<<"stat_uncert_ZJ_bin1       lnN    -              -              "<<bg2_StatUncer_b1<<"           -               -         \n"; 
  myfile1<<"stat_uncert_WJ_bin1       lnN    -              -               -              "<<bg3_StatUncer_b1<<"           -         \n"; 
  myfile1<<"stat_uncert_QCD_bin1      lnN    -              -               -               -              "<<bg4_StatUncer_b1<<"     \n"; 
  myfile1.close();
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //bin2
  ofstream myfile2;
  myfile2.open("dc_MET_H_NJ45_NbJ2_bin2.txt");
  myfile2<<"# Simple counting experiment for 1 signal and 4 bgs. \n";
  myfile2<<"# stop->top N2, N2->H N1 and stop->top N1 with mass(stop, N2, N1)=(1200, 600, 300) GeV \n";
  myfile2<<"imax 1  number of channels \n";
  myfile2<<"jmax 4  number of backgrounds \n";
  myfile2<<"kmax 10  number of nuisance parameters (sources of systematical uncertainties) \n";
  myfile2<<"-------------------------------------------------------------------------------------- \n";
  myfile2<<"# one channel, 0 obs events \n";
  myfile2<<"bin bin2 \n";
  myfile2<<"observation 0 \n";
  myfile2<<"-------------------------------------------------------------------------------------- \n";
  myfile2<<"bin                             bin2           bin2            bin2            bin2            bin2            \n";
  myfile2<<"process                         ggt1t1         ttbar           ZJ              WJ              QCD             \n";
  myfile2<<"process                         0              1               2               3               4               \n";
  myfile2<<"rate                            "<<sig_binContent_b2<<"           "<<bg1_binContent_b2<<"         "<<bg2_binContent_b2<<"         "<<bg3_binContent_b2<<"         "<<bg4_binContent_b2<<" \n";
  myfile2<<"-------------------------------------------------------------------------------------- \n";
  myfile2<<"syst_uncert_ggt1t1_bin2   lnN   1.20            -               -               -               -               \n";
  myfile2<<"syst_uncert_ttbar_bin2    lnN    -             1.20             -               -               -               \n";
  myfile2<<"syst_uncert_ZJ_bin2       lnN    -              -              1.20             -               -               \n";
  myfile2<<"syst_uncert_WJ_bin2       lnN    -              -               -              1.20             -               \n";
  myfile2<<"syst_uncert_QCD_bin2      lnN    -              -               -               -              1.20             \n";

  myfile2<<"stat_uncert_ggt1t1_bin2   lnN   "<<sig_StatUncer_b2<<"          -               -               -               -         \n";
  myfile2<<"stat_uncert_ttbar_bin2    lnN    -             "<<bg1_StatUncer_b2<<"           -               -               -         \n";
  myfile2<<"stat_uncert_ZJ_bin2       lnN    -              -              "<<bg2_StatUncer_b2<<"           -               -         \n"; 
  myfile2<<"stat_uncert_WJ_bin2       lnN    -              -               -              "<<bg3_StatUncer_b2<<"           -         \n"; 
  myfile2<<"stat_uncert_QCD_bin2      lnN    -              -               -               -              "<<bg4_StatUncer_b2<<"     \n"; 
  myfile2.close();
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //bin3
  ofstream myfile3;
  myfile3.open("dc_MET_H_NJ45_NbJ2_bin3.txt");
  myfile3<<"# Simple counting experiment for 1 signal and 4 bgs. \n";
  myfile3<<"# stop->top N2, N2->H N1 and stop->top N1 with mass(stop, N2, N1)=(1200, 600, 300) GeV \n";
  myfile3<<"imax 1  number of channels \n";
  myfile3<<"jmax 4  number of backgrounds \n";
  myfile3<<"kmax 10  number of nuisance parameters (sources of systematical uncertainties) \n";
  myfile3<<"-------------------------------------------------------------------------------------- \n";
  myfile3<<"# one channel, 0 obs events \n";
  myfile3<<"bin bin3 \n";
  myfile3<<"observation 0 \n";
  myfile3<<"-------------------------------------------------------------------------------------- \n";
  myfile3<<"bin                             bin3           bin3            bin3            bin3            bin3            \n";
  myfile3<<"process                         ggt1t1         ttbar           ZJ              WJ              QCD             \n";
  myfile3<<"process                         0              1               2               3               4               \n";
  myfile3<<"rate                            "<<sig_binContent_b3<<"           "<<bg1_binContent_b3<<"         "<<bg2_binContent_b3<<"         "<<bg3_binContent_b3<<"         "<<bg4_binContent_b3<<" \n";
  myfile3<<"-------------------------------------------------------------------------------------- \n";
  myfile3<<"syst_uncert_ggt1t1_bin3   lnN   1.20            -               -               -               -               \n";
  myfile3<<"syst_uncert_ttbar_bin3    lnN    -             1.20             -               -               -               \n";
  myfile3<<"syst_uncert_ZJ_bin3       lnN    -              -              1.20             -               -               \n";
  myfile3<<"syst_uncert_WJ_bin3       lnN    -              -               -              1.20             -               \n";
  myfile3<<"syst_uncert_QCD_bin3      lnN    -              -               -               -              1.20             \n";

  myfile3<<"stat_uncert_ggt1t1_bin3   lnN   "<<sig_StatUncer_b3<<"          -               -               -               -         \n";
  myfile3<<"stat_uncert_ttbar_bin3    lnN    -             "<<bg1_StatUncer_b3<<"           -               -               -         \n";
  myfile3<<"stat_uncert_ZJ_bin3       lnN    -              -              "<<bg2_StatUncer_b3<<"           -               -         \n"; 
  myfile3<<"stat_uncert_WJ_bin3       lnN    -              -               -              "<<bg3_StatUncer_b3<<"           -         \n"; 
  myfile3<<"stat_uncert_QCD_bin3      lnN    -              -               -               -              "<<bg4_StatUncer_b3<<"     \n"; 
  myfile3.close();
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //bin4
  ofstream myfile4;
  myfile4.open("dc_MET_H_NJ45_NbJ2_bin4.txt");
  myfile4<<"# Simple counting experiment for 1 signal and 4 bgs. \n";
  myfile4<<"# stop->top N2, N2->H N1 and stop->top N1 with mass(stop, N2, N1)=(1200, 600, 300) GeV \n";
  myfile4<<"imax 1  number of channels \n";
  myfile4<<"jmax 4  number of backgrounds \n";
  myfile4<<"kmax 10  number of nuisance parameters (sources of systematical uncertainties) \n";
  myfile4<<"-------------------------------------------------------------------------------------- \n";
  myfile4<<"# one channel, 0 obs events \n";
  myfile4<<"bin bin4 \n";
  myfile4<<"observation 0 \n";
  myfile4<<"-------------------------------------------------------------------------------------- \n";
  myfile4<<"bin                             bin4           bin4            bin4            bin4            bin4            \n";
  myfile4<<"process                         ggt1t1         ttbar           ZJ              WJ              QCD             \n";
  myfile4<<"process                         0              1               2               3               4               \n";
  myfile4<<"rate                            "<<sig_binContent_b4<<"           "<<bg1_binContent_b4<<"         "<<bg2_binContent_b4<<"         "<<bg3_binContent_b4<<"         "<<bg4_binContent_b4<<" \n";
  myfile4<<"-------------------------------------------------------------------------------------- \n";
  myfile4<<"syst_uncert_ggt1t1_bin4   lnN   1.20            -               -               -               -               \n";
  myfile4<<"syst_uncert_ttbar_bin4    lnN    -             1.20             -               -               -               \n";
  myfile4<<"syst_uncert_ZJ_bin4       lnN    -              -              1.20             -               -               \n";
  myfile4<<"syst_uncert_WJ_bin4       lnN    -              -               -              1.20             -               \n";
  myfile4<<"syst_uncert_QCD_bin4      lnN    -              -               -               -              1.20             \n";

  myfile4<<"stat_uncert_ggt1t1_bin4   lnN   "<<sig_StatUncer_b4<<"          -               -               -               -         \n";
  myfile4<<"stat_uncert_ttbar_bin4    lnN    -             "<<bg1_StatUncer_b4<<"           -               -               -         \n";
  myfile4<<"stat_uncert_ZJ_bin4       lnN    -              -              "<<bg2_StatUncer_b4<<"           -               -         \n"; 
  myfile4<<"stat_uncert_WJ_bin4       lnN    -              -               -              "<<bg3_StatUncer_b4<<"           -         \n"; 
  myfile4<<"stat_uncert_QCD_bin4      lnN    -              -               -               -              "<<bg4_StatUncer_b4<<"     \n"; 
  myfile4.close();
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //bin5
  ofstream myfile5;
  myfile5.open("dc_MET_H_NJ45_NbJ2_bin5.txt");
  myfile5<<"# Simple counting experiment for 1 signal and 4 bgs. \n";
  myfile5<<"# stop->top N2, N2->H N1 and stop->top N1 with mass(stop, N2, N1)=(1200, 600, 300) GeV \n";
  myfile5<<"imax 1  number of channels \n";
  myfile5<<"jmax 4  number of backgrounds \n";
  myfile5<<"kmax 10  number of nuisance parameters (sources of systematical uncertainties) \n";
  myfile5<<"-------------------------------------------------------------------------------------- \n";
  myfile5<<"# one channel, 0 obs events \n";
  myfile5<<"bin bin5 \n";
  myfile5<<"observation 0 \n";
  myfile5<<"-------------------------------------------------------------------------------------- \n";
  myfile5<<"bin                             bin5           bin5            bin5            bin5            bin5            \n";
  myfile5<<"process                         ggt1t1         ttbar           ZJ              WJ              QCD             \n";
  myfile5<<"process                         0              1               2               3               4               \n";
  myfile5<<"rate                            "<<sig_binContent_b5<<"           "<<bg1_binContent_b5<<"         "<<bg2_binContent_b5<<"         "<<bg3_binContent_b5<<"         "<<bg4_binContent_b5<<" \n";
  myfile5<<"-------------------------------------------------------------------------------------- \n";
  myfile5<<"syst_uncert_ggt1t1_bin5   lnN   1.20            -               -               -               -               \n";
  myfile5<<"syst_uncert_ttbar_bin5    lnN    -             1.20             -               -               -               \n";
  myfile5<<"syst_uncert_ZJ_bin5       lnN    -              -              1.20             -               -               \n";
  myfile5<<"syst_uncert_WJ_bin5       lnN    -              -               -              1.20             -               \n";
  myfile5<<"syst_uncert_QCD_bin5      lnN    -              -               -               -              1.20             \n";

  myfile5<<"stat_uncert_ggt1t1_bin5   lnN   "<<sig_StatUncer_b5<<"          -               -               -               -         \n";
  myfile5<<"stat_uncert_ttbar_bin5    lnN    -             "<<bg1_StatUncer_b5<<"           -               -               -         \n";
  myfile5<<"stat_uncert_ZJ_bin5       lnN    -              -              "<<bg2_StatUncer_b5<<"           -               -         \n"; 
  myfile5<<"stat_uncert_WJ_bin5       lnN    -              -               -              "<<bg3_StatUncer_b5<<"           -         \n"; 
  myfile5<<"stat_uncert_QCD_bin5      lnN    -              -               -               -              "<<bg4_StatUncer_b5<<"     \n"; 
  myfile5.close();
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //bin6
  ofstream myfile6;
  myfile6.open("dc_MET_H_NJ45_NbJ2_bin6.txt");
  myfile6<<"# Simple counting experiment for 1 signal and 4 bgs. \n";
  myfile6<<"# stop->top N2, N2->H N1 and stop->top N1 with mass(stop, N2, N1)=(1200, 600, 300) GeV \n";
  myfile6<<"imax 1  number of channels \n";
  myfile6<<"jmax 4  number of backgrounds \n";
  myfile6<<"kmax 10  number of nuisance parameters (sources of systematical uncertainties) \n";
  myfile6<<"-------------------------------------------------------------------------------------- \n";
  myfile6<<"# one channel, 0 obs events \n";
  myfile6<<"bin bin6 \n";
  myfile6<<"observation 0 \n";
  myfile6<<"-------------------------------------------------------------------------------------- \n";
  myfile6<<"bin                             bin6           bin6            bin6            bin6            bin6            \n";
  myfile6<<"process                         ggt1t1         ttbar           ZJ              WJ              QCD             \n";
  myfile6<<"process                         0              1               2               3               4               \n";
  myfile6<<"rate                            "<<sig_binContent_b6<<"           "<<bg1_binContent_b6<<"         "<<bg2_binContent_b6<<"         "<<bg3_binContent_b6<<"         "<<bg4_binContent_b6<<" \n";
  myfile6<<"-------------------------------------------------------------------------------------- \n";
  myfile6<<"syst_uncert_ggt1t1_bin6   lnN   1.20            -               -               -               -               \n";
  myfile6<<"syst_uncert_ttbar_bin6    lnN    -             1.20             -               -               -               \n";
  myfile6<<"syst_uncert_ZJ_bin6       lnN    -              -              1.20             -               -               \n";
  myfile6<<"syst_uncert_WJ_bin6       lnN    -              -               -              1.20             -               \n";
  myfile6<<"syst_uncert_QCD_bin6      lnN    -              -               -               -              1.20             \n";

  myfile6<<"stat_uncert_ggt1t1_bin6   lnN   "<<sig_StatUncer_b6<<"          -               -               -               -         \n";
  myfile6<<"stat_uncert_ttbar_bin6    lnN    -             "<<bg1_StatUncer_b6<<"           -               -               -         \n";
  myfile6<<"stat_uncert_ZJ_bin6       lnN    -              -              "<<bg2_StatUncer_b6<<"           -               -         \n"; 
  myfile6<<"stat_uncert_WJ_bin6       lnN    -              -               -              "<<bg3_StatUncer_b6<<"           -         \n"; 
  myfile6<<"stat_uncert_QCD_bin6      lnN    -              -               -               -              "<<bg4_StatUncer_b6<<"     \n"; 
  myfile6.close();
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //bin7
  ofstream myfile7;
  myfile7.open("dc_MET_H_NJ45_NbJ2_bin7.txt");
  myfile7<<"# Simple counting experiment for 1 signal and 4 bgs. \n";
  myfile7<<"# stop->top N2, N2->H N1 and stop->top N1 with mass(stop, N2, N1)=(1200, 600, 300) GeV \n";
  myfile7<<"imax 1  number of channels \n";
  myfile7<<"jmax 4  number of backgrounds \n";
  myfile7<<"kmax 10  number of nuisance parameters (sources of systematical uncertainties) \n";
  myfile7<<"-------------------------------------------------------------------------------------- \n";
  myfile7<<"# one channel, 0 obs events \n";
  myfile7<<"bin bin7 \n";
  myfile7<<"observation 0 \n";
  myfile7<<"-------------------------------------------------------------------------------------- \n";
  myfile7<<"bin                             bin7           bin7            bin7            bin7            bin7            \n";
  myfile7<<"process                         ggt1t1         ttbar           ZJ              WJ              QCD             \n";
  myfile7<<"process                         0              1               2               3               4               \n";
  myfile7<<"rate                            "<<sig_binContent_b7<<"           "<<bg1_binContent_b7<<"         "<<bg2_binContent_b7<<"         "<<bg3_binContent_b7<<"         "<<bg4_binContent_b7<<" \n";
  myfile7<<"-------------------------------------------------------------------------------------- \n";
  myfile7<<"syst_uncert_ggt1t1_bin7   lnN   1.20            -               -               -               -               \n";
  myfile7<<"syst_uncert_ttbar_bin7    lnN    -             1.20             -               -               -               \n";
  myfile7<<"syst_uncert_ZJ_bin7       lnN    -              -              1.20             -               -               \n";
  myfile7<<"syst_uncert_WJ_bin7       lnN    -              -               -              1.20             -               \n";
  myfile7<<"syst_uncert_QCD_bin7      lnN    -              -               -               -              1.20             \n";

  myfile7<<"stat_uncert_ggt1t1_bin7   lnN   "<<sig_StatUncer_b7<<"          -               -               -               -         \n";
  myfile7<<"stat_uncert_ttbar_bin7    lnN    -             "<<bg1_StatUncer_b7<<"           -               -               -         \n";
  myfile7<<"stat_uncert_ZJ_bin7       lnN    -              -              "<<bg2_StatUncer_b7<<"           -               -         \n"; 
  myfile7<<"stat_uncert_WJ_bin7       lnN    -              -               -              "<<bg3_StatUncer_b7<<"           -         \n"; 
  myfile7<<"stat_uncert_QCD_bin7      lnN    -              -               -               -              "<<bg4_StatUncer_b7<<"     \n"; 
  myfile7.close();
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //bin8
  ofstream myfile8;
  myfile8.open("dc_MET_H_NJ45_NbJ2_bin8.txt");
  myfile8<<"# Simple counting experiment for 1 signal and 4 bgs. \n";
  myfile8<<"# stop->top N2, N2->H N1 and stop->top N1 with mass(stop, N2, N1)=(1200, 600, 300) GeV \n";
  myfile8<<"imax 1  number of channels \n";
  myfile8<<"jmax 4  number of backgrounds \n";
  myfile8<<"kmax 10  number of nuisance parameters (sources of systematical uncertainties) \n";
  myfile8<<"-------------------------------------------------------------------------------------- \n";
  myfile8<<"# one channel, 0 obs events \n";
  myfile8<<"bin bin8 \n";
  myfile8<<"observation 0 \n";
  myfile8<<"-------------------------------------------------------------------------------------- \n";
  myfile8<<"bin                             bin8           bin8            bin8            bin8            bin8            \n";
  myfile8<<"process                         ggt1t1         ttbar           ZJ              WJ              QCD             \n";
  myfile8<<"process                         0              1               2               3               4               \n";
  myfile8<<"rate                            "<<sig_binContent_b8<<"           "<<bg1_binContent_b8<<"         "<<bg2_binContent_b8<<"         "<<bg3_binContent_b8<<"         "<<bg4_binContent_b8<<" \n";
  myfile8<<"-------------------------------------------------------------------------------------- \n";
  myfile8<<"syst_uncert_ggt1t1_bin8   lnN   1.20            -               -               -               -               \n";
  myfile8<<"syst_uncert_ttbar_bin8    lnN    -             1.20             -               -               -               \n";
  myfile8<<"syst_uncert_ZJ_bin8       lnN    -              -              1.20             -               -               \n";
  myfile8<<"syst_uncert_WJ_bin8       lnN    -              -               -              1.20             -               \n";
  myfile8<<"syst_uncert_QCD_bin8      lnN    -              -               -               -              1.20             \n";

  myfile8<<"stat_uncert_ggt1t1_bin8   lnN   "<<sig_StatUncer_b8<<"          -               -               -               -         \n";
  myfile8<<"stat_uncert_ttbar_bin8    lnN    -             "<<bg1_StatUncer_b8<<"           -               -               -         \n";
  myfile8<<"stat_uncert_ZJ_bin8       lnN    -              -              "<<bg2_StatUncer_b8<<"           -               -         \n"; 
  myfile8<<"stat_uncert_WJ_bin8       lnN    -              -               -              "<<bg3_StatUncer_b8<<"           -         \n"; 
  myfile8<<"stat_uncert_QCD_bin8      lnN    -              -               -               -              "<<bg4_StatUncer_b8<<"     \n"; 
  myfile8.close();
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //bin9
  ofstream myfile9;
  myfile9.open("dc_MET_H_NJ45_NbJ2_bin9.txt");
  myfile9<<"# Simple counting experiment for 1 signal and 4 bgs. \n";
  myfile9<<"# stop->top N2, N2->H N1 and stop->top N1 with mass(stop, N2, N1)=(1200, 600, 300) GeV \n";
  myfile9<<"imax 1  number of channels \n";
  myfile9<<"jmax 4  number of backgrounds \n";
  myfile9<<"kmax 10  number of nuisance parameters (sources of systematical uncertainties) \n";
  myfile9<<"-------------------------------------------------------------------------------------- \n";
  myfile9<<"# one channel, 0 obs events \n";
  myfile9<<"bin bin9 \n";
  myfile9<<"observation 0 \n";
  myfile9<<"-------------------------------------------------------------------------------------- \n";
  myfile9<<"bin                             bin9           bin9            bin9            bin9            bin9            \n";
  myfile9<<"process                         ggt1t1         ttbar           ZJ              WJ              QCD             \n";
  myfile9<<"process                         0              1               2               3               4               \n";
  myfile9<<"rate                            "<<sig_binContent_b9<<"           "<<bg1_binContent_b9<<"         "<<bg2_binContent_b9<<"         "<<bg3_binContent_b9<<"         "<<bg4_binContent_b9<<" \n";
  myfile9<<"-------------------------------------------------------------------------------------- \n";
  myfile9<<"syst_uncert_ggt1t1_bin9   lnN   1.20            -               -               -               -               \n";
  myfile9<<"syst_uncert_ttbar_bin9    lnN    -             1.20             -               -               -               \n";
  myfile9<<"syst_uncert_ZJ_bin9       lnN    -              -              1.20             -               -               \n";
  myfile9<<"syst_uncert_WJ_bin9       lnN    -              -               -              1.20             -               \n";
  myfile9<<"syst_uncert_QCD_bin9      lnN    -              -               -               -              1.20             \n";

  myfile9<<"stat_uncert_ggt1t1_bin9   lnN   "<<sig_StatUncer_b9<<"          -               -               -               -         \n";
  myfile9<<"stat_uncert_ttbar_bin9    lnN    -             "<<bg1_StatUncer_b9<<"           -               -               -         \n";
  myfile9<<"stat_uncert_ZJ_bin9       lnN    -              -              "<<bg2_StatUncer_b9<<"           -               -         \n"; 
  myfile9<<"stat_uncert_WJ_bin9       lnN    -              -               -              "<<bg3_StatUncer_b9<<"           -         \n"; 
  myfile9<<"stat_uncert_QCD_bin9      lnN    -              -               -               -              "<<bg4_StatUncer_b9<<"     \n"; 
  myfile9.close();
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //bin10
  ofstream myfile10;
  myfile10.open("dc_MET_H_NJ45_NbJ2_bin10.txt");
  myfile10<<"# Simple counting experiment for 1 signal and 4 bgs. \n";
  myfile10<<"# stop->top N2, N2->H N1 and stop->top N1 with mass(stop, N2, N1)=(1200, 600, 300) GeV \n";
  myfile10<<"imax 1  number of channels \n";
  myfile10<<"jmax 4  number of backgrounds \n";
  myfile10<<"kmax 10  number of nuisance parameters (sources of systematical uncertainties) \n";
  myfile10<<"-------------------------------------------------------------------------------------- \n";
  myfile10<<"# one channel, 0 obs events \n";
  myfile10<<"bin bin10 \n";
  myfile10<<"observation 0 \n";
  myfile10<<"-------------------------------------------------------------------------------------- \n";
  myfile10<<"bin                             bin10           bin10            bin10            bin10            bin10            \n";
  myfile10<<"process                         ggt1t1         ttbar           ZJ              WJ              QCD             \n";
  myfile10<<"process                         0              1               2               3               4               \n";
  myfile10<<"rate                            "<<sig_binContent_b10<<"           "<<bg1_binContent_b10<<"         "<<bg2_binContent_b10<<"         "<<bg3_binContent_b10<<"         "<<bg4_binContent_b10<<" \n";
  myfile10<<"-------------------------------------------------------------------------------------- \n";
  myfile10<<"syst_uncert_ggt1t1_bin10   lnN   1.20            -               -               -               -               \n";
  myfile10<<"syst_uncert_ttbar_bin10    lnN    -             1.20             -               -               -               \n";
  myfile10<<"syst_uncert_ZJ_bin10       lnN    -              -              1.20             -               -               \n";
  myfile10<<"syst_uncert_WJ_bin10       lnN    -              -               -              1.20             -               \n";
  myfile10<<"syst_uncert_QCD_bin10      lnN    -              -               -               -              1.20             \n";

  myfile10<<"stat_uncert_ggt1t1_bin10   lnN   "<<sig_StatUncer_b10<<"          -               -               -               -         \n";
  myfile10<<"stat_uncert_ttbar_bin10    lnN    -             "<<bg1_StatUncer_b10<<"           -               -               -         \n";
  myfile10<<"stat_uncert_ZJ_bin10       lnN    -              -              "<<bg2_StatUncer_b10<<"           -               -         \n"; 
  myfile10<<"stat_uncert_WJ_bin10       lnN    -              -               -              "<<bg3_StatUncer_b10<<"           -         \n"; 
  myfile10<<"stat_uncert_QCD_bin10      lnN    -              -               -               -              "<<bg4_StatUncer_b10<<"     \n"; 
  myfile10.close();
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


  return 0;

}
