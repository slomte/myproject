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

  //First declare the file names
  TString aafile ="zz_1k_400_200.root"; 
  TString bbfile ="ttbar_1l_2Mevt.root";
  TString ccfile ="ttbar_2l_8Mevt.root";

  //Now let us define the plot name 
  TString plotname1 = "MET_NJ_5_9_NbJ_1";
  TString plotname2 = "MET_NJ_5_9_NbJ_1";
  TString plotname3 = "MET_NJ_5_9_NbJ_1";

  //Now let us open the files
  TFile *fileaa = new TFile(aafile);
  TFile *filebb = new TFile(bbfile);
  TFile *filecc = new TFile(ccfile);

  //Now open the respective histograms from the files
  TH1F *haa = (TH1F *)fileaa->Get(plotname1);
  TH1F *hbb = (TH1F *)filebb->Get(plotname2);
  TH1F *hcc = (TH1F *)filecc->Get(plotname3);

  // Now rebin the histograms if needed
  // Group nrebins bins together
  int nrebins = 10;
  haa->Rebin(nrebins); hbb->Rebin(nrebins); hcc->Rebin(nrebins); 


  //Now lets get Bin Content and Bin Error for MC Statistical uncertainty
  double sig_binContent_b1 = haa->GetBinContent(1);
  double sig_binError_b1 = haa->GetBinError(1);
  double sig_StatUncer_b1 = (sig_binError_b1/sig_binContent_b1)+1 ;

  double bg1_binContent_b1 = hbb->GetBinContent(1);
  double bg1_binError_b1 = hbb->GetBinError(1);
  double bg1_StatUncer_b1 = (bg1_binError_b1/bg1_binContent_b1)+1 ;

  double bg2_binContent_b1 = hcc->GetBinContent(1);
  double bg2_binError_b1 = hcc->GetBinError(1);
  double bg2_StatUncer_b1 = (bg2_binError_b1/bg2_binContent_b1)+1 ;


  double sig_binContent_b2 = haa->GetBinContent(2);
  double sig_binError_b2 = haa->GetBinError(2);
  double sig_StatUncer_b2 = (sig_binError_b2/sig_binContent_b2)+1 ;

  double bg1_binContent_b2 = hbb->GetBinContent(2);
  double bg1_binError_b2 = hbb->GetBinError(2);
  double bg1_StatUncer_b2 = (bg1_binError_b2/bg1_binContent_b2)+1 ;

  double bg2_binContent_b2 = hcc->GetBinContent(2);
  double bg2_binError_b2 = hcc->GetBinError(2);
  double bg2_StatUncer_b2 = (bg2_binError_b2/bg2_binContent_b2)+1 ;


  double sig_binContent_b3 = haa->GetBinContent(3);
  double sig_binError_b3 = haa->GetBinError(3);
  double sig_StatUncer_b3 = (sig_binError_b3/sig_binContent_b3)+1 ;

  double bg1_binContent_b3 = hbb->GetBinContent(3);
  double bg1_binError_b3 = hbb->GetBinError(3);
  double bg1_StatUncer_b3 = (bg1_binError_b3/bg1_binContent_b3)+1 ;

  double bg2_binContent_b3 = hcc->GetBinContent(3);
  double bg2_binError_b3 = hcc->GetBinError(3);
  double bg2_StatUncer_b3 = (bg2_binError_b3/bg2_binContent_b3)+1 ;


  double sig_binContent_b4 = haa->GetBinContent(4);
  double sig_binError_b4 = haa->GetBinError(4);
  double sig_StatUncer_b4 = (sig_binError_b4/sig_binContent_b4)+1 ;

  double bg1_binContent_b4 = hbb->GetBinContent(4);
  double bg1_binError_b4 = hbb->GetBinError(4);
  double bg1_StatUncer_b4 = (bg1_binError_b4/bg1_binContent_b4)+1 ;

  double bg2_binContent_b4 = hcc->GetBinContent(4);
  double bg2_binError_b4 = hcc->GetBinError(4);
  double bg2_StatUncer_b4 = (bg2_binError_b4/bg2_binContent_b4)+1 ;


  double sig_binContent_b5 = haa->GetBinContent(5);
  double sig_binError_b5 = haa->GetBinError(5);
  double sig_StatUncer_b5 = (sig_binError_b5/sig_binContent_b5)+1 ;

  double bg1_binContent_b5 = hbb->GetBinContent(5);
  double bg1_binError_b5 = hbb->GetBinError(5);
  double bg1_StatUncer_b5 = (bg1_binError_b5/bg1_binContent_b5)+1 ;

  double bg2_binContent_b5 = hcc->GetBinContent(5);
  double bg2_binError_b5 = hcc->GetBinError(5);
  double bg2_StatUncer_b5 = (bg2_binError_b5/bg2_binContent_b5)+1 ;


  //declare our output datacard txt file

  //bin1
  ofstream myfile;
  myfile.open("dc_MET_NJ_5_9_NbJ_1_bin1.txt");
  myfile<<"# Simple counting experiment for 1 signal and 2 bgs. \n";
  myfile<<"# stop->top N2, N2->Z N1 with mass(stop, N2, N1)=(1000, 400, 200) GeV \n";
  myfile<<"imax 1  number of channels \n";
  myfile<<"jmax 2  number of backgrounds \n";
  myfile<<"kmax 6  number of nuisance parameters (sources of systematical uncertainties) \n";
  myfile<<"-------------------------------------------------------------------------------------- \n";
  myfile<<"# one channel, 0 obs events \n";
  myfile<<"bin bin1 \n";
  myfile<<"observation 0 \n";
  myfile<<"-------------------------------------------------------------------------------------- \n";
  myfile<<"bin                             bin1           bin1            bin1 \n";
  myfile<<"process                         ggt1t1         tt1l            tt2l \n";
  myfile<<"process                         0              1               2 \n";
  myfile<<"rate                            "<<sig_binContent_b1<<"           "<<bg1_binContent_b1<<"         "<<bg2_binContent_b1<<" \n";
  myfile<<"-------------------------------------------------------------------------------------- \n";
  myfile<<"syst_uncert_ggt1t1_bin1   lnN   1.20            -               -             \n";
  myfile<<"syst_uncert_tt1l_bin1     lnN    -             1.20             -             \n";
  myfile<<"syst_uncert_tt2l_bin1     lnN    -              -              1.20           \n";
  myfile<<"stat_uncert_ggt1t1_bin1   lnN   "<<sig_StatUncer_b1<<"          -               -            \n";
  myfile<<"stat_uncert_tt1l_bin1     lnN    -             "<<bg1_StatUncer_b1<<"           -            \n";
  myfile<<"stat_uncert_tt2l_bin1     lnN    -              -              "<<bg2_StatUncer_b1<<"        \n";
  myfile.close();


  //bin2
  ofstream myfile1;
  myfile1.open("dc_MET_NJ_5_9_NbJ_1_bin2.txt");
  myfile1<<"# Simple counting experiment for 1 signal and 2 bgs. \n";
  myfile1<<"# stop->top N2, N2->Z N1 with mass(stop, N2, N1)=(1000, 400, 200) GeV \n";
  myfile1<<"imax 1  number of channels \n";
  myfile1<<"jmax 2  number of backgrounds \n";
  myfile1<<"kmax 6  number of nuisance parameters (sources of systematical uncertainties) \n";
  myfile1<<"-------------------------------------------------------------------------------------- \n";
  myfile1<<"# one channel, 0 obs events \n";
  myfile1<<"bin bin2 \n";
  myfile1<<"observation 0 \n";
  myfile1<<"-------------------------------------------------------------------------------------- \n";
  myfile1<<"bin                             bin2           bin2            bin2 \n";
  myfile1<<"process                         ggt1t1         tt1l            tt2l \n";
  myfile1<<"process                         0              1               2 \n";
  myfile1<<"rate                            "<<sig_binContent_b2<<"           "<<bg1_binContent_b2<<"         "<<bg2_binContent_b2<<" \n";
  myfile1<<"-------------------------------------------------------------------------------------- \n";
  myfile1<<"syst_uncert_ggt1t1_bin2   lnN   1.20            -               -             \n";
  myfile1<<"syst_uncert_tt1l_bin2     lnN    -             1.20             -             \n";
  myfile1<<"syst_uncert_tt2l_bin2     lnN    -              -              1.20           \n";
  myfile1<<"stat_uncert_ggt1t1_bin2   lnN   "<<sig_StatUncer_b2<<"          -               -            \n";
  myfile1<<"stat_uncert_tt1l_bin2     lnN    -             "<<bg1_StatUncer_b2<<"           -            \n";
  myfile1<<"stat_uncert_tt2l_bin2     lnN    -              -              "<<bg2_StatUncer_b2<<"        \n"; 
  myfile1.close();

  //bin3
  ofstream myfile2;
  myfile2.open("dc_MET_NJ_5_9_NbJ_1_bin3.txt");
  myfile2<<"# Simple counting experiment for 1 signal and 2 bgs. \n";
  myfile2<<"# stop->top N2, N2->Z N1 with mass(stop, N2, N1)=(1000, 400, 200) GeV \n";
  myfile2<<"imax 1  number of channels \n";
  myfile2<<"jmax 2  number of backgrounds \n";
  myfile2<<"kmax 6  number of nuisance parameters (sources of systematical uncertainties) \n";
  myfile2<<"-------------------------------------------------------------------------------------- \n";
  myfile2<<"# one channel, 0 obs events \n";
  myfile2<<"bin bin3 \n";
  myfile2<<"observation 0 \n";
  myfile2<<"-------------------------------------------------------------------------------------- \n";
  myfile2<<"bin                             bin3           bin3            bin3 \n";
  myfile2<<"process                         ggt1t1         tt1l            tt2l \n";
  myfile2<<"process                         0              1               2 \n";
  myfile2<<"rate                            "<<sig_binContent_b3<<"           "<<bg1_binContent_b3<<"         "<<bg2_binContent_b3<<" \n";
  myfile2<<"-------------------------------------------------------------------------------------- \n";
  myfile2<<"syst_uncert_ggt1t1_bin3   lnN   1.20            -               -             \n";
  myfile2<<"syst_uncert_tt1l_bin3     lnN    -             1.20             -             \n";
  myfile2<<"syst_uncert_tt2l_bin3     lnN    -              -              1.20           \n";
  myfile2<<"stat_uncert_ggt1t1_bin3   lnN   "<<sig_StatUncer_b3<<"          -               -            \n";
  myfile2<<"stat_uncert_tt1l_bin3     lnN    -             "<<bg1_StatUncer_b3<<"           -            \n";
  myfile2<<"stat_uncert_tt2l_bin3     lnN    -              -              "<<bg2_StatUncer_b3<<"        \n";
  myfile2.close();


  //bin4
  ofstream myfile3;
  myfile3.open("dc_MET_NJ_5_9_NbJ_1_bin4.txt");
  myfile3<<"# Simple counting experiment for 1 signal and 2 bgs. \n";
  myfile3<<"# stop->top N2, N2->Z N1 with mass(stop, N2, N1)=(1000, 400, 200) GeV \n";
  myfile3<<"imax 1  number of channels \n";
  myfile3<<"jmax 2  number of backgrounds \n";
  myfile3<<"kmax 6  number of nuisance parameters (sources of systematical uncertainties) \n";
  myfile3<<"-------------------------------------------------------------------------------------- \n";
  myfile3<<"# one channel, 0 obs events \n";
  myfile3<<"bin bin4 \n";
  myfile3<<"observation 0 \n";
  myfile3<<"-------------------------------------------------------------------------------------- \n";
  myfile3<<"bin                             bin4           bin4            bin4 \n";
  myfile3<<"process                         ggt1t1         tt1l            tt2l \n";
  myfile3<<"process                         0              1               2 \n";
  myfile3<<"rate                            "<<sig_binContent_b4<<"           "<<bg1_binContent_b4<<"         "<<bg2_binContent_b4<<" \n";
  myfile3<<"-------------------------------------------------------------------------------------- \n";
  myfile3<<"syst_uncert_ggt1t1_bin4   lnN   1.20            -               -             \n";
  myfile3<<"syst_uncert_tt1l_bin4     lnN    -             1.20             -             \n";
  myfile3<<"syst_uncert_tt2l_bin4     lnN    -              -              1.20           \n";
  myfile3<<"stat_uncert_ggt1t1_bin4   lnN   "<<sig_StatUncer_b4<<"          -               -            \n";
  myfile3<<"stat_uncert_tt1l_bin4     lnN    -             "<<bg1_StatUncer_b4<<"           -            \n";
  myfile3<<"stat_uncert_tt2l_bin4     lnN    -              -              "<<bg2_StatUncer_b4<<"        \n"; 
  myfile3.close();


  //bin5
  ofstream myfile4;
  myfile4.open("dc_MET_NJ_5_9_NbJ_1_bin5.txt");
  myfile4<<"# Simple counting experiment for 1 signal and 2 bgs. \n";
  myfile4<<"# stop->top N2, N2->Z N1 with mass(stop, N2, N1)=(1000, 400, 200) GeV \n";
  myfile4<<"imax 1  number of channels \n";
  myfile4<<"jmax 2  number of backgrounds \n";
  myfile4<<"kmax 6  number of nuisance parameters (sources of systematical uncertainties) \n";
  myfile4<<"-------------------------------------------------------------------------------------- \n";
  myfile4<<"# one channel, 0 obs events \n";
  myfile4<<"bin bin5 \n";
  myfile4<<"observation 0 \n";
  myfile4<<"-------------------------------------------------------------------------------------- \n";
  myfile4<<"bin                             bin5           bin5            bin5 \n";
  myfile4<<"process                         ggt1t1         tt1l            tt2l \n";
  myfile4<<"process                         0              1               2 \n";
  myfile4<<"rate                            "<<sig_binContent_b5<<"           "<<bg1_binContent_b5<<"         "<<bg2_binContent_b5<<" \n";
  myfile4<<"-------------------------------------------------------------------------------------- \n";
  myfile4<<"syst_uncert_ggt1t1_bin5   lnN   1.20            -               -             \n";
  myfile4<<"syst_uncert_tt1l_bin5     lnN    -             1.20             -             \n";
  myfile4<<"syst_uncert_tt2l_bin5     lnN    -              -              1.20           \n";
  myfile4<<"stat_uncert_ggt1t1_bin5   lnN   "<<sig_StatUncer_b5<<"          -               -            \n";
  myfile4<<"stat_uncert_tt1l_bin5     lnN    -             "<<bg1_StatUncer_b5<<"           -            \n";
  myfile4<<"stat_uncert_tt2l_bin5     lnN    -              -              "<<bg2_StatUncer_b5<<"        \n"; 
  myfile4.close();

  return 0;

}
