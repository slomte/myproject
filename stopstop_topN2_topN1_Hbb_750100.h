//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Jul 16 10:32:57 2019 by ROOT version 6.08/06
// from TTree Delphes/Analysis tree
// found on file: stopstop_topN2_topN1_Hbb_750100.root
//////////////////////////////////////////////////////////

#ifndef stopstop_topN2_topN1_Hbb_750100_h
#define stopstop_topN2_topN1_Hbb_750100_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

//*******(I added)
#include <TH1.h>
#include <TH2.h>
#include <vector>

// Header file for the classes stored in the TTree if any.
#include "TClonesArray.h"
#include "TObject.h"

// Fixed size dimensions of array or collections stored in the TTree if any.
   const Int_t kMaxEvent = 1;
   const Int_t kMaxParticle = 1648;
   const Int_t kMaxGenJet = 20;
   const Int_t kMaxGenMissingET = 1;
   const Int_t kMaxJet = 16;
   const Int_t kMaxAK4_Jet = 18;
   const Int_t kMaxAK8_Jet = 14;
   const Int_t kMaxAK12_Jet = 12;
   const Int_t kMaxElectron = 2;
   const Int_t kMaxPhoton = 2;
   const Int_t kMaxMuon = 3;
   const Int_t kMaxFatJet = 6;
   const Int_t kMaxMissingET = 1;
   const Int_t kMaxScalarHT = 1;

class stopstop_topN2_topN1_Hbb_750100 {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           Event_;
   UInt_t          Event_fUniqueID[kMaxEvent];   //[Event_]
   UInt_t          Event_fBits[kMaxEvent];   //[Event_]
   Long64_t        Event_Number[kMaxEvent];   //[Event_]
   Float_t         Event_ReadTime[kMaxEvent];   //[Event_]
   Float_t         Event_ProcTime[kMaxEvent];   //[Event_]
   Int_t           Event_ProcessID[kMaxEvent];   //[Event_]
   Float_t         Event_Weight[kMaxEvent];   //[Event_]
   Float_t         Event_ScalePDF[kMaxEvent];   //[Event_]
   Float_t         Event_AlphaQED[kMaxEvent];   //[Event_]
   Float_t         Event_AlphaQCD[kMaxEvent];   //[Event_]
   Int_t           Event_size;
   Int_t           Particle_;
   UInt_t          Particle_fUniqueID[kMaxParticle];   //[Particle_]
   UInt_t          Particle_fBits[kMaxParticle];   //[Particle_]
   Int_t           Particle_PID[kMaxParticle];   //[Particle_]
   Int_t           Particle_Status[kMaxParticle];   //[Particle_]
   Int_t           Particle_IsPU[kMaxParticle];   //[Particle_]
   Int_t           Particle_M1[kMaxParticle];   //[Particle_]
   Int_t           Particle_M2[kMaxParticle];   //[Particle_]
   Int_t           Particle_D1[kMaxParticle];   //[Particle_]
   Int_t           Particle_D2[kMaxParticle];   //[Particle_]
   Int_t           Particle_Charge[kMaxParticle];   //[Particle_]
   Float_t         Particle_Mass[kMaxParticle];   //[Particle_]
   Float_t         Particle_E[kMaxParticle];   //[Particle_]
   Float_t         Particle_Px[kMaxParticle];   //[Particle_]
   Float_t         Particle_Py[kMaxParticle];   //[Particle_]
   Float_t         Particle_Pz[kMaxParticle];   //[Particle_]
   Float_t         Particle_P[kMaxParticle];   //[Particle_]
   Float_t         Particle_PT[kMaxParticle];   //[Particle_]
   Float_t         Particle_Eta[kMaxParticle];   //[Particle_]
   Float_t         Particle_Phi[kMaxParticle];   //[Particle_]
   Float_t         Particle_Rapidity[kMaxParticle];   //[Particle_]
   Float_t         Particle_CtgTheta[kMaxParticle];   //[Particle_]
   Float_t         Particle_D0[kMaxParticle];   //[Particle_]
   Float_t         Particle_DZ[kMaxParticle];   //[Particle_]
   Float_t         Particle_T[kMaxParticle];   //[Particle_]
   Float_t         Particle_X[kMaxParticle];   //[Particle_]
   Float_t         Particle_Y[kMaxParticle];   //[Particle_]
   Float_t         Particle_Z[kMaxParticle];   //[Particle_]
   Int_t           Particle_size;
   Int_t           GenJet_;
   UInt_t          GenJet_fUniqueID[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_fBits[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_PT[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_Eta[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_Phi[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_T[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_Mass[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_DeltaEta[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_DeltaPhi[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_Flavor[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_FlavorAlgo[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_FlavorPhys[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_BTag[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_BTagAlgo[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_BTagPhys[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_TauTag[kMaxGenJet];   //[GenJet_]
   Int_t           GenJet_Charge[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_EhadOverEem[kMaxGenJet];   //[GenJet_]
   Int_t           GenJet_NCharged[kMaxGenJet];   //[GenJet_]
   Int_t           GenJet_NNeutrals[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_Beta[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_BetaStar[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_MeanSqDeltaR[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_PTD[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_FracPt[kMaxGenJet][5];   //[GenJet_]
   Float_t         GenJet_Tau[kMaxGenJet][5];   //[GenJet_]
   TLorentzVector  GenJet_TrimmedP4[5][kMaxGenJet];
   TLorentzVector  GenJet_PrunedP4[5][kMaxGenJet];
   TLorentzVector  GenJet_SoftDroppedP4[5][kMaxGenJet];
   Int_t           GenJet_NSubJetsTrimmed[kMaxGenJet];   //[GenJet_]
   Int_t           GenJet_NSubJetsPruned[kMaxGenJet];   //[GenJet_]
   Int_t           GenJet_NSubJetsSoftDropped[kMaxGenJet];   //[GenJet_]
   TRefArray       GenJet_Constituents[kMaxGenJet];
   TRefArray       GenJet_Particles[kMaxGenJet];
   TLorentzVector  GenJet_Area[kMaxGenJet];
   Int_t           GenJet_size;
   Int_t           GenMissingET_;
   UInt_t          GenMissingET_fUniqueID[kMaxGenMissingET];   //[GenMissingET_]
   UInt_t          GenMissingET_fBits[kMaxGenMissingET];   //[GenMissingET_]
   Float_t         GenMissingET_MET[kMaxGenMissingET];   //[GenMissingET_]
   Float_t         GenMissingET_Eta[kMaxGenMissingET];   //[GenMissingET_]
   Float_t         GenMissingET_Phi[kMaxGenMissingET];   //[GenMissingET_]
   Int_t           GenMissingET_size;
   Int_t           Jet_;
   UInt_t          Jet_fUniqueID[kMaxJet];   //[Jet_]
   UInt_t          Jet_fBits[kMaxJet];   //[Jet_]
   Float_t         Jet_PT[kMaxJet];   //[Jet_]
   Float_t         Jet_Eta[kMaxJet];   //[Jet_]
   Float_t         Jet_Phi[kMaxJet];   //[Jet_]
   Float_t         Jet_T[kMaxJet];   //[Jet_]
   Float_t         Jet_Mass[kMaxJet];   //[Jet_]
   Float_t         Jet_DeltaEta[kMaxJet];   //[Jet_]
   Float_t         Jet_DeltaPhi[kMaxJet];   //[Jet_]
   UInt_t          Jet_Flavor[kMaxJet];   //[Jet_]
   UInt_t          Jet_FlavorAlgo[kMaxJet];   //[Jet_]
   UInt_t          Jet_FlavorPhys[kMaxJet];   //[Jet_]
   UInt_t          Jet_BTag[kMaxJet];   //[Jet_]
   UInt_t          Jet_BTagAlgo[kMaxJet];   //[Jet_]
   UInt_t          Jet_BTagPhys[kMaxJet];   //[Jet_]
   UInt_t          Jet_TauTag[kMaxJet];   //[Jet_]
   Int_t           Jet_Charge[kMaxJet];   //[Jet_]
   Float_t         Jet_EhadOverEem[kMaxJet];   //[Jet_]
   Int_t           Jet_NCharged[kMaxJet];   //[Jet_]
   Int_t           Jet_NNeutrals[kMaxJet];   //[Jet_]
   Float_t         Jet_Beta[kMaxJet];   //[Jet_]
   Float_t         Jet_BetaStar[kMaxJet];   //[Jet_]
   Float_t         Jet_MeanSqDeltaR[kMaxJet];   //[Jet_]
   Float_t         Jet_PTD[kMaxJet];   //[Jet_]
   Float_t         Jet_FracPt[kMaxJet][5];   //[Jet_]
   Float_t         Jet_Tau[kMaxJet][5];   //[Jet_]
   TLorentzVector  Jet_TrimmedP4[5][kMaxJet];
   TLorentzVector  Jet_PrunedP4[5][kMaxJet];
   TLorentzVector  Jet_SoftDroppedP4[5][kMaxJet];
   Int_t           Jet_NSubJetsTrimmed[kMaxJet];   //[Jet_]
   Int_t           Jet_NSubJetsPruned[kMaxJet];   //[Jet_]
   Int_t           Jet_NSubJetsSoftDropped[kMaxJet];   //[Jet_]
   TRefArray       Jet_Constituents[kMaxJet];
   TRefArray       Jet_Particles[kMaxJet];
   TLorentzVector  Jet_Area[kMaxJet];
   Int_t           Jet_size;
   Int_t           AK4_Jet_;
   UInt_t          AK4_Jet_fUniqueID[kMaxAK4_Jet];   //[AK4_Jet_]
   UInt_t          AK4_Jet_fBits[kMaxAK4_Jet];   //[AK4_Jet_]
   Float_t         AK4_Jet_PT[kMaxAK4_Jet];   //[AK4_Jet_]
   Float_t         AK4_Jet_Eta[kMaxAK4_Jet];   //[AK4_Jet_]
   Float_t         AK4_Jet_Phi[kMaxAK4_Jet];   //[AK4_Jet_]
   Float_t         AK4_Jet_T[kMaxAK4_Jet];   //[AK4_Jet_]
   Float_t         AK4_Jet_Mass[kMaxAK4_Jet];   //[AK4_Jet_]
   Float_t         AK4_Jet_DeltaEta[kMaxAK4_Jet];   //[AK4_Jet_]
   Float_t         AK4_Jet_DeltaPhi[kMaxAK4_Jet];   //[AK4_Jet_]
   UInt_t          AK4_Jet_Flavor[kMaxAK4_Jet];   //[AK4_Jet_]
   UInt_t          AK4_Jet_FlavorAlgo[kMaxAK4_Jet];   //[AK4_Jet_]
   UInt_t          AK4_Jet_FlavorPhys[kMaxAK4_Jet];   //[AK4_Jet_]
   UInt_t          AK4_Jet_BTag[kMaxAK4_Jet];   //[AK4_Jet_]
   UInt_t          AK4_Jet_BTagAlgo[kMaxAK4_Jet];   //[AK4_Jet_]
   UInt_t          AK4_Jet_BTagPhys[kMaxAK4_Jet];   //[AK4_Jet_]
   UInt_t          AK4_Jet_TauTag[kMaxAK4_Jet];   //[AK4_Jet_]
   Int_t           AK4_Jet_Charge[kMaxAK4_Jet];   //[AK4_Jet_]
   Float_t         AK4_Jet_EhadOverEem[kMaxAK4_Jet];   //[AK4_Jet_]
   Int_t           AK4_Jet_NCharged[kMaxAK4_Jet];   //[AK4_Jet_]
   Int_t           AK4_Jet_NNeutrals[kMaxAK4_Jet];   //[AK4_Jet_]
   Float_t         AK4_Jet_Beta[kMaxAK4_Jet];   //[AK4_Jet_]
   Float_t         AK4_Jet_BetaStar[kMaxAK4_Jet];   //[AK4_Jet_]
   Float_t         AK4_Jet_MeanSqDeltaR[kMaxAK4_Jet];   //[AK4_Jet_]
   Float_t         AK4_Jet_PTD[kMaxAK4_Jet];   //[AK4_Jet_]
   Float_t         AK4_Jet_FracPt[kMaxAK4_Jet][5];   //[AK4_Jet_]
   Float_t         AK4_Jet_Tau[kMaxAK4_Jet][5];   //[AK4_Jet_]
   TLorentzVector  AK4_Jet_TrimmedP4[5][kMaxAK4_Jet];
   TLorentzVector  AK4_Jet_PrunedP4[5][kMaxAK4_Jet];
   TLorentzVector  AK4_Jet_SoftDroppedP4[5][kMaxAK4_Jet];
   Int_t           AK4_Jet_NSubJetsTrimmed[kMaxAK4_Jet];   //[AK4_Jet_]
   Int_t           AK4_Jet_NSubJetsPruned[kMaxAK4_Jet];   //[AK4_Jet_]
   Int_t           AK4_Jet_NSubJetsSoftDropped[kMaxAK4_Jet];   //[AK4_Jet_]
   TRefArray       AK4_Jet_Constituents[kMaxAK4_Jet];
   TRefArray       AK4_Jet_Particles[kMaxAK4_Jet];
   TLorentzVector  AK4_Jet_Area[kMaxAK4_Jet];
   Int_t           AK4_Jet_size;
   Int_t           AK8_Jet_;
   UInt_t          AK8_Jet_fUniqueID[kMaxAK8_Jet];   //[AK8_Jet_]
   UInt_t          AK8_Jet_fBits[kMaxAK8_Jet];   //[AK8_Jet_]
   Float_t         AK8_Jet_PT[kMaxAK8_Jet];   //[AK8_Jet_]
   Float_t         AK8_Jet_Eta[kMaxAK8_Jet];   //[AK8_Jet_]
   Float_t         AK8_Jet_Phi[kMaxAK8_Jet];   //[AK8_Jet_]
   Float_t         AK8_Jet_T[kMaxAK8_Jet];   //[AK8_Jet_]
   Float_t         AK8_Jet_Mass[kMaxAK8_Jet];   //[AK8_Jet_]
   Float_t         AK8_Jet_DeltaEta[kMaxAK8_Jet];   //[AK8_Jet_]
   Float_t         AK8_Jet_DeltaPhi[kMaxAK8_Jet];   //[AK8_Jet_]
   UInt_t          AK8_Jet_Flavor[kMaxAK8_Jet];   //[AK8_Jet_]
   UInt_t          AK8_Jet_FlavorAlgo[kMaxAK8_Jet];   //[AK8_Jet_]
   UInt_t          AK8_Jet_FlavorPhys[kMaxAK8_Jet];   //[AK8_Jet_]
   UInt_t          AK8_Jet_BTag[kMaxAK8_Jet];   //[AK8_Jet_]
   UInt_t          AK8_Jet_BTagAlgo[kMaxAK8_Jet];   //[AK8_Jet_]
   UInt_t          AK8_Jet_BTagPhys[kMaxAK8_Jet];   //[AK8_Jet_]
   UInt_t          AK8_Jet_TauTag[kMaxAK8_Jet];   //[AK8_Jet_]
   Int_t           AK8_Jet_Charge[kMaxAK8_Jet];   //[AK8_Jet_]
   Float_t         AK8_Jet_EhadOverEem[kMaxAK8_Jet];   //[AK8_Jet_]
   Int_t           AK8_Jet_NCharged[kMaxAK8_Jet];   //[AK8_Jet_]
   Int_t           AK8_Jet_NNeutrals[kMaxAK8_Jet];   //[AK8_Jet_]
   Float_t         AK8_Jet_Beta[kMaxAK8_Jet];   //[AK8_Jet_]
   Float_t         AK8_Jet_BetaStar[kMaxAK8_Jet];   //[AK8_Jet_]
   Float_t         AK8_Jet_MeanSqDeltaR[kMaxAK8_Jet];   //[AK8_Jet_]
   Float_t         AK8_Jet_PTD[kMaxAK8_Jet];   //[AK8_Jet_]
   Float_t         AK8_Jet_FracPt[kMaxAK8_Jet][5];   //[AK8_Jet_]
   Float_t         AK8_Jet_Tau[kMaxAK8_Jet][5];   //[AK8_Jet_]
   TLorentzVector  AK8_Jet_TrimmedP4[5][kMaxAK8_Jet];
   TLorentzVector  AK8_Jet_PrunedP4[5][kMaxAK8_Jet];
   TLorentzVector  AK8_Jet_SoftDroppedP4[5][kMaxAK8_Jet];
   Int_t           AK8_Jet_NSubJetsTrimmed[kMaxAK8_Jet];   //[AK8_Jet_]
   Int_t           AK8_Jet_NSubJetsPruned[kMaxAK8_Jet];   //[AK8_Jet_]
   Int_t           AK8_Jet_NSubJetsSoftDropped[kMaxAK8_Jet];   //[AK8_Jet_]
   TRefArray       AK8_Jet_Constituents[kMaxAK8_Jet];
   TRefArray       AK8_Jet_Particles[kMaxAK8_Jet];
   TLorentzVector  AK8_Jet_Area[kMaxAK8_Jet];
   Int_t           AK8_Jet_size;
   Int_t           AK12_Jet_;
   UInt_t          AK12_Jet_fUniqueID[kMaxAK12_Jet];   //[AK12_Jet_]
   UInt_t          AK12_Jet_fBits[kMaxAK12_Jet];   //[AK12_Jet_]
   Float_t         AK12_Jet_PT[kMaxAK12_Jet];   //[AK12_Jet_]
   Float_t         AK12_Jet_Eta[kMaxAK12_Jet];   //[AK12_Jet_]
   Float_t         AK12_Jet_Phi[kMaxAK12_Jet];   //[AK12_Jet_]
   Float_t         AK12_Jet_T[kMaxAK12_Jet];   //[AK12_Jet_]
   Float_t         AK12_Jet_Mass[kMaxAK12_Jet];   //[AK12_Jet_]
   Float_t         AK12_Jet_DeltaEta[kMaxAK12_Jet];   //[AK12_Jet_]
   Float_t         AK12_Jet_DeltaPhi[kMaxAK12_Jet];   //[AK12_Jet_]
   UInt_t          AK12_Jet_Flavor[kMaxAK12_Jet];   //[AK12_Jet_]
   UInt_t          AK12_Jet_FlavorAlgo[kMaxAK12_Jet];   //[AK12_Jet_]
   UInt_t          AK12_Jet_FlavorPhys[kMaxAK12_Jet];   //[AK12_Jet_]
   UInt_t          AK12_Jet_BTag[kMaxAK12_Jet];   //[AK12_Jet_]
   UInt_t          AK12_Jet_BTagAlgo[kMaxAK12_Jet];   //[AK12_Jet_]
   UInt_t          AK12_Jet_BTagPhys[kMaxAK12_Jet];   //[AK12_Jet_]
   UInt_t          AK12_Jet_TauTag[kMaxAK12_Jet];   //[AK12_Jet_]
   Int_t           AK12_Jet_Charge[kMaxAK12_Jet];   //[AK12_Jet_]
   Float_t         AK12_Jet_EhadOverEem[kMaxAK12_Jet];   //[AK12_Jet_]
   Int_t           AK12_Jet_NCharged[kMaxAK12_Jet];   //[AK12_Jet_]
   Int_t           AK12_Jet_NNeutrals[kMaxAK12_Jet];   //[AK12_Jet_]
   Float_t         AK12_Jet_Beta[kMaxAK12_Jet];   //[AK12_Jet_]
   Float_t         AK12_Jet_BetaStar[kMaxAK12_Jet];   //[AK12_Jet_]
   Float_t         AK12_Jet_MeanSqDeltaR[kMaxAK12_Jet];   //[AK12_Jet_]
   Float_t         AK12_Jet_PTD[kMaxAK12_Jet];   //[AK12_Jet_]
   Float_t         AK12_Jet_FracPt[kMaxAK12_Jet][5];   //[AK12_Jet_]
   Float_t         AK12_Jet_Tau[kMaxAK12_Jet][5];   //[AK12_Jet_]
   TLorentzVector  AK12_Jet_TrimmedP4[5][kMaxAK12_Jet];
   TLorentzVector  AK12_Jet_PrunedP4[5][kMaxAK12_Jet];
   TLorentzVector  AK12_Jet_SoftDroppedP4[5][kMaxAK12_Jet];
   Int_t           AK12_Jet_NSubJetsTrimmed[kMaxAK12_Jet];   //[AK12_Jet_]
   Int_t           AK12_Jet_NSubJetsPruned[kMaxAK12_Jet];   //[AK12_Jet_]
   Int_t           AK12_Jet_NSubJetsSoftDropped[kMaxAK12_Jet];   //[AK12_Jet_]
   TRefArray       AK12_Jet_Constituents[kMaxAK12_Jet];
   TRefArray       AK12_Jet_Particles[kMaxAK12_Jet];
   TLorentzVector  AK12_Jet_Area[kMaxAK12_Jet];
   Int_t           AK12_Jet_size;
   Int_t           Electron_;
   UInt_t          Electron_fUniqueID[kMaxElectron];   //[Electron_]
   UInt_t          Electron_fBits[kMaxElectron];   //[Electron_]
   Float_t         Electron_PT[kMaxElectron];   //[Electron_]
   Float_t         Electron_Eta[kMaxElectron];   //[Electron_]
   Float_t         Electron_Phi[kMaxElectron];   //[Electron_]
   Float_t         Electron_T[kMaxElectron];   //[Electron_]
   Int_t           Electron_Charge[kMaxElectron];   //[Electron_]
   Float_t         Electron_EhadOverEem[kMaxElectron];   //[Electron_]
   TRef            Electron_Particle[kMaxElectron];
   Float_t         Electron_IsolationVar[kMaxElectron];   //[Electron_]
   Float_t         Electron_IsolationVarRhoCorr[kMaxElectron];   //[Electron_]
   Float_t         Electron_SumPtCharged[kMaxElectron];   //[Electron_]
   Float_t         Electron_SumPtNeutral[kMaxElectron];   //[Electron_]
   Float_t         Electron_SumPtChargedPU[kMaxElectron];   //[Electron_]
   Float_t         Electron_SumPt[kMaxElectron];   //[Electron_]
   Int_t           Electron_size;
   Int_t           Photon_;
   UInt_t          Photon_fUniqueID[kMaxPhoton];   //[Photon_]
   UInt_t          Photon_fBits[kMaxPhoton];   //[Photon_]
   Float_t         Photon_PT[kMaxPhoton];   //[Photon_]
   Float_t         Photon_Eta[kMaxPhoton];   //[Photon_]
   Float_t         Photon_Phi[kMaxPhoton];   //[Photon_]
   Float_t         Photon_E[kMaxPhoton];   //[Photon_]
   Float_t         Photon_T[kMaxPhoton];   //[Photon_]
   Float_t         Photon_EhadOverEem[kMaxPhoton];   //[Photon_]
   TRefArray       Photon_Particles[kMaxPhoton];
   Float_t         Photon_IsolationVar[kMaxPhoton];   //[Photon_]
   Float_t         Photon_IsolationVarRhoCorr[kMaxPhoton];   //[Photon_]
   Float_t         Photon_SumPtCharged[kMaxPhoton];   //[Photon_]
   Float_t         Photon_SumPtNeutral[kMaxPhoton];   //[Photon_]
   Float_t         Photon_SumPtChargedPU[kMaxPhoton];   //[Photon_]
   Float_t         Photon_SumPt[kMaxPhoton];   //[Photon_]
   Int_t           Photon_size;
   Int_t           Muon_;
   UInt_t          Muon_fUniqueID[kMaxMuon];   //[Muon_]
   UInt_t          Muon_fBits[kMaxMuon];   //[Muon_]
   Float_t         Muon_PT[kMaxMuon];   //[Muon_]
   Float_t         Muon_Eta[kMaxMuon];   //[Muon_]
   Float_t         Muon_Phi[kMaxMuon];   //[Muon_]
   Float_t         Muon_T[kMaxMuon];   //[Muon_]
   Int_t           Muon_Charge[kMaxMuon];   //[Muon_]
   TRef            Muon_Particle[kMaxMuon];
   Float_t         Muon_IsolationVar[kMaxMuon];   //[Muon_]
   Float_t         Muon_IsolationVarRhoCorr[kMaxMuon];   //[Muon_]
   Float_t         Muon_SumPtCharged[kMaxMuon];   //[Muon_]
   Float_t         Muon_SumPtNeutral[kMaxMuon];   //[Muon_]
   Float_t         Muon_SumPtChargedPU[kMaxMuon];   //[Muon_]
   Float_t         Muon_SumPt[kMaxMuon];   //[Muon_]
   Int_t           Muon_size;
   Int_t           FatJet_;
   UInt_t          FatJet_fUniqueID[kMaxFatJet];   //[FatJet_]
   UInt_t          FatJet_fBits[kMaxFatJet];   //[FatJet_]
   Float_t         FatJet_PT[kMaxFatJet];   //[FatJet_]
   Float_t         FatJet_Eta[kMaxFatJet];   //[FatJet_]
   Float_t         FatJet_Phi[kMaxFatJet];   //[FatJet_]
   Float_t         FatJet_T[kMaxFatJet];   //[FatJet_]
   Float_t         FatJet_Mass[kMaxFatJet];   //[FatJet_]
   Float_t         FatJet_DeltaEta[kMaxFatJet];   //[FatJet_]
   Float_t         FatJet_DeltaPhi[kMaxFatJet];   //[FatJet_]
   UInt_t          FatJet_Flavor[kMaxFatJet];   //[FatJet_]
   UInt_t          FatJet_FlavorAlgo[kMaxFatJet];   //[FatJet_]
   UInt_t          FatJet_FlavorPhys[kMaxFatJet];   //[FatJet_]
   UInt_t          FatJet_BTag[kMaxFatJet];   //[FatJet_]
   UInt_t          FatJet_BTagAlgo[kMaxFatJet];   //[FatJet_]
   UInt_t          FatJet_BTagPhys[kMaxFatJet];   //[FatJet_]
   UInt_t          FatJet_TauTag[kMaxFatJet];   //[FatJet_]
   Int_t           FatJet_Charge[kMaxFatJet];   //[FatJet_]
   Float_t         FatJet_EhadOverEem[kMaxFatJet];   //[FatJet_]
   Int_t           FatJet_NCharged[kMaxFatJet];   //[FatJet_]
   Int_t           FatJet_NNeutrals[kMaxFatJet];   //[FatJet_]
   Float_t         FatJet_Beta[kMaxFatJet];   //[FatJet_]
   Float_t         FatJet_BetaStar[kMaxFatJet];   //[FatJet_]
   Float_t         FatJet_MeanSqDeltaR[kMaxFatJet];   //[FatJet_]
   Float_t         FatJet_PTD[kMaxFatJet];   //[FatJet_]
   Float_t         FatJet_FracPt[kMaxFatJet][5];   //[FatJet_]
   Float_t         FatJet_Tau[kMaxFatJet][5];   //[FatJet_]
   TLorentzVector  FatJet_TrimmedP4[5][kMaxFatJet];
   TLorentzVector  FatJet_PrunedP4[5][kMaxFatJet];
   TLorentzVector  FatJet_SoftDroppedP4[5][kMaxFatJet];
   Int_t           FatJet_NSubJetsTrimmed[kMaxFatJet];   //[FatJet_]
   Int_t           FatJet_NSubJetsPruned[kMaxFatJet];   //[FatJet_]
   Int_t           FatJet_NSubJetsSoftDropped[kMaxFatJet];   //[FatJet_]
   TRefArray       FatJet_Constituents[kMaxFatJet];
   TRefArray       FatJet_Particles[kMaxFatJet];
   TLorentzVector  FatJet_Area[kMaxFatJet];
   Int_t           FatJet_size;
   Int_t           MissingET_;
   UInt_t          MissingET_fUniqueID[kMaxMissingET];   //[MissingET_]
   UInt_t          MissingET_fBits[kMaxMissingET];   //[MissingET_]
   Float_t         MissingET_MET[kMaxMissingET];   //[MissingET_]
   Float_t         MissingET_Eta[kMaxMissingET];   //[MissingET_]
   Float_t         MissingET_Phi[kMaxMissingET];   //[MissingET_]
   Int_t           MissingET_size;
   Int_t           ScalarHT_;
   UInt_t          ScalarHT_fUniqueID[kMaxScalarHT];   //[ScalarHT_]
   UInt_t          ScalarHT_fBits[kMaxScalarHT];   //[ScalarHT_]
   Float_t         ScalarHT_HT[kMaxScalarHT];   //[ScalarHT_]
   Int_t           ScalarHT_size;

   // List of branches
   TBranch        *b_Event_;   //!
   TBranch        *b_Event_fUniqueID;   //!
   TBranch        *b_Event_fBits;   //!
   TBranch        *b_Event_Number;   //!
   TBranch        *b_Event_ReadTime;   //!
   TBranch        *b_Event_ProcTime;   //!
   TBranch        *b_Event_ProcessID;   //!
   TBranch        *b_Event_Weight;   //!
   TBranch        *b_Event_ScalePDF;   //!
   TBranch        *b_Event_AlphaQED;   //!
   TBranch        *b_Event_AlphaQCD;   //!
   TBranch        *b_Event_size;   //!
   TBranch        *b_Particle_;   //!
   TBranch        *b_Particle_fUniqueID;   //!
   TBranch        *b_Particle_fBits;   //!
   TBranch        *b_Particle_PID;   //!
   TBranch        *b_Particle_Status;   //!
   TBranch        *b_Particle_IsPU;   //!
   TBranch        *b_Particle_M1;   //!
   TBranch        *b_Particle_M2;   //!
   TBranch        *b_Particle_D1;   //!
   TBranch        *b_Particle_D2;   //!
   TBranch        *b_Particle_Charge;   //!
   TBranch        *b_Particle_Mass;   //!
   TBranch        *b_Particle_E;   //!
   TBranch        *b_Particle_Px;   //!
   TBranch        *b_Particle_Py;   //!
   TBranch        *b_Particle_Pz;   //!
   TBranch        *b_Particle_P;   //!
   TBranch        *b_Particle_PT;   //!
   TBranch        *b_Particle_Eta;   //!
   TBranch        *b_Particle_Phi;   //!
   TBranch        *b_Particle_Rapidity;   //!
   TBranch        *b_Particle_CtgTheta;   //!
   TBranch        *b_Particle_D0;   //!
   TBranch        *b_Particle_DZ;   //!
   TBranch        *b_Particle_T;   //!
   TBranch        *b_Particle_X;   //!
   TBranch        *b_Particle_Y;   //!
   TBranch        *b_Particle_Z;   //!
   TBranch        *b_Particle_size;   //!
   TBranch        *b_GenJet_;   //!
   TBranch        *b_GenJet_fUniqueID;   //!
   TBranch        *b_GenJet_fBits;   //!
   TBranch        *b_GenJet_PT;   //!
   TBranch        *b_GenJet_Eta;   //!
   TBranch        *b_GenJet_Phi;   //!
   TBranch        *b_GenJet_T;   //!
   TBranch        *b_GenJet_Mass;   //!
   TBranch        *b_GenJet_DeltaEta;   //!
   TBranch        *b_GenJet_DeltaPhi;   //!
   TBranch        *b_GenJet_Flavor;   //!
   TBranch        *b_GenJet_FlavorAlgo;   //!
   TBranch        *b_GenJet_FlavorPhys;   //!
   TBranch        *b_GenJet_BTag;   //!
   TBranch        *b_GenJet_BTagAlgo;   //!
   TBranch        *b_GenJet_BTagPhys;   //!
   TBranch        *b_GenJet_TauTag;   //!
   TBranch        *b_GenJet_Charge;   //!
   TBranch        *b_GenJet_EhadOverEem;   //!
   TBranch        *b_GenJet_NCharged;   //!
   TBranch        *b_GenJet_NNeutrals;   //!
   TBranch        *b_GenJet_Beta;   //!
   TBranch        *b_GenJet_BetaStar;   //!
   TBranch        *b_GenJet_MeanSqDeltaR;   //!
   TBranch        *b_GenJet_PTD;   //!
   TBranch        *b_GenJet_FracPt;   //!
   TBranch        *b_GenJet_Tau;   //!
   TBranch        *b_GenJet_TrimmedP4;   //!
   TBranch        *b_GenJet_PrunedP4;   //!
   TBranch        *b_GenJet_SoftDroppedP4;   //!
   TBranch        *b_GenJet_NSubJetsTrimmed;   //!
   TBranch        *b_GenJet_NSubJetsPruned;   //!
   TBranch        *b_GenJet_NSubJetsSoftDropped;   //!
   TBranch        *b_GenJet_Constituents;   //!
   TBranch        *b_GenJet_Particles;   //!
   TBranch        *b_GenJet_Area;   //!
   TBranch        *b_GenJet_size;   //!
   TBranch        *b_GenMissingET_;   //!
   TBranch        *b_GenMissingET_fUniqueID;   //!
   TBranch        *b_GenMissingET_fBits;   //!
   TBranch        *b_GenMissingET_MET;   //!
   TBranch        *b_GenMissingET_Eta;   //!
   TBranch        *b_GenMissingET_Phi;   //!
   TBranch        *b_GenMissingET_size;   //!
   TBranch        *b_Jet_;   //!
   TBranch        *b_Jet_fUniqueID;   //!
   TBranch        *b_Jet_fBits;   //!
   TBranch        *b_Jet_PT;   //!
   TBranch        *b_Jet_Eta;   //!
   TBranch        *b_Jet_Phi;   //!
   TBranch        *b_Jet_T;   //!
   TBranch        *b_Jet_Mass;   //!
   TBranch        *b_Jet_DeltaEta;   //!
   TBranch        *b_Jet_DeltaPhi;   //!
   TBranch        *b_Jet_Flavor;   //!
   TBranch        *b_Jet_FlavorAlgo;   //!
   TBranch        *b_Jet_FlavorPhys;   //!
   TBranch        *b_Jet_BTag;   //!
   TBranch        *b_Jet_BTagAlgo;   //!
   TBranch        *b_Jet_BTagPhys;   //!
   TBranch        *b_Jet_TauTag;   //!
   TBranch        *b_Jet_Charge;   //!
   TBranch        *b_Jet_EhadOverEem;   //!
   TBranch        *b_Jet_NCharged;   //!
   TBranch        *b_Jet_NNeutrals;   //!
   TBranch        *b_Jet_Beta;   //!
   TBranch        *b_Jet_BetaStar;   //!
   TBranch        *b_Jet_MeanSqDeltaR;   //!
   TBranch        *b_Jet_PTD;   //!
   TBranch        *b_Jet_FracPt;   //!
   TBranch        *b_Jet_Tau;   //!
   TBranch        *b_Jet_TrimmedP4;   //!
   TBranch        *b_Jet_PrunedP4;   //!
   TBranch        *b_Jet_SoftDroppedP4;   //!
   TBranch        *b_Jet_NSubJetsTrimmed;   //!
   TBranch        *b_Jet_NSubJetsPruned;   //!
   TBranch        *b_Jet_NSubJetsSoftDropped;   //!
   TBranch        *b_Jet_Constituents;   //!
   TBranch        *b_Jet_Particles;   //!
   TBranch        *b_Jet_Area;   //!
   TBranch        *b_Jet_size;   //!
   TBranch        *b_AK4_Jet_;   //!
   TBranch        *b_AK4_Jet_fUniqueID;   //!
   TBranch        *b_AK4_Jet_fBits;   //!
   TBranch        *b_AK4_Jet_PT;   //!
   TBranch        *b_AK4_Jet_Eta;   //!
   TBranch        *b_AK4_Jet_Phi;   //!
   TBranch        *b_AK4_Jet_T;   //!
   TBranch        *b_AK4_Jet_Mass;   //!
   TBranch        *b_AK4_Jet_DeltaEta;   //!
   TBranch        *b_AK4_Jet_DeltaPhi;   //!
   TBranch        *b_AK4_Jet_Flavor;   //!
   TBranch        *b_AK4_Jet_FlavorAlgo;   //!
   TBranch        *b_AK4_Jet_FlavorPhys;   //!
   TBranch        *b_AK4_Jet_BTag;   //!
   TBranch        *b_AK4_Jet_BTagAlgo;   //!
   TBranch        *b_AK4_Jet_BTagPhys;   //!
   TBranch        *b_AK4_Jet_TauTag;   //!
   TBranch        *b_AK4_Jet_Charge;   //!
   TBranch        *b_AK4_Jet_EhadOverEem;   //!
   TBranch        *b_AK4_Jet_NCharged;   //!
   TBranch        *b_AK4_Jet_NNeutrals;   //!
   TBranch        *b_AK4_Jet_Beta;   //!
   TBranch        *b_AK4_Jet_BetaStar;   //!
   TBranch        *b_AK4_Jet_MeanSqDeltaR;   //!
   TBranch        *b_AK4_Jet_PTD;   //!
   TBranch        *b_AK4_Jet_FracPt;   //!
   TBranch        *b_AK4_Jet_Tau;   //!
   TBranch        *b_AK4_Jet_TrimmedP4;   //!
   TBranch        *b_AK4_Jet_PrunedP4;   //!
   TBranch        *b_AK4_Jet_SoftDroppedP4;   //!
   TBranch        *b_AK4_Jet_NSubJetsTrimmed;   //!
   TBranch        *b_AK4_Jet_NSubJetsPruned;   //!
   TBranch        *b_AK4_Jet_NSubJetsSoftDropped;   //!
   TBranch        *b_AK4_Jet_Constituents;   //!
   TBranch        *b_AK4_Jet_Particles;   //!
   TBranch        *b_AK4_Jet_Area;   //!
   TBranch        *b_AK4_Jet_size;   //!
   TBranch        *b_AK8_Jet_;   //!
   TBranch        *b_AK8_Jet_fUniqueID;   //!
   TBranch        *b_AK8_Jet_fBits;   //!
   TBranch        *b_AK8_Jet_PT;   //!
   TBranch        *b_AK8_Jet_Eta;   //!
   TBranch        *b_AK8_Jet_Phi;   //!
   TBranch        *b_AK8_Jet_T;   //!
   TBranch        *b_AK8_Jet_Mass;   //!
   TBranch        *b_AK8_Jet_DeltaEta;   //!
   TBranch        *b_AK8_Jet_DeltaPhi;   //!
   TBranch        *b_AK8_Jet_Flavor;   //!
   TBranch        *b_AK8_Jet_FlavorAlgo;   //!
   TBranch        *b_AK8_Jet_FlavorPhys;   //!
   TBranch        *b_AK8_Jet_BTag;   //!
   TBranch        *b_AK8_Jet_BTagAlgo;   //!
   TBranch        *b_AK8_Jet_BTagPhys;   //!
   TBranch        *b_AK8_Jet_TauTag;   //!
   TBranch        *b_AK8_Jet_Charge;   //!
   TBranch        *b_AK8_Jet_EhadOverEem;   //!
   TBranch        *b_AK8_Jet_NCharged;   //!
   TBranch        *b_AK8_Jet_NNeutrals;   //!
   TBranch        *b_AK8_Jet_Beta;   //!
   TBranch        *b_AK8_Jet_BetaStar;   //!
   TBranch        *b_AK8_Jet_MeanSqDeltaR;   //!
   TBranch        *b_AK8_Jet_PTD;   //!
   TBranch        *b_AK8_Jet_FracPt;   //!
   TBranch        *b_AK8_Jet_Tau;   //!
   TBranch        *b_AK8_Jet_TrimmedP4;   //!
   TBranch        *b_AK8_Jet_PrunedP4;   //!
   TBranch        *b_AK8_Jet_SoftDroppedP4;   //!
   TBranch        *b_AK8_Jet_NSubJetsTrimmed;   //!
   TBranch        *b_AK8_Jet_NSubJetsPruned;   //!
   TBranch        *b_AK8_Jet_NSubJetsSoftDropped;   //!
   TBranch        *b_AK8_Jet_Constituents;   //!
   TBranch        *b_AK8_Jet_Particles;   //!
   TBranch        *b_AK8_Jet_Area;   //!
   TBranch        *b_AK8_Jet_size;   //!
   TBranch        *b_AK12_Jet_;   //!
   TBranch        *b_AK12_Jet_fUniqueID;   //!
   TBranch        *b_AK12_Jet_fBits;   //!
   TBranch        *b_AK12_Jet_PT;   //!
   TBranch        *b_AK12_Jet_Eta;   //!
   TBranch        *b_AK12_Jet_Phi;   //!
   TBranch        *b_AK12_Jet_T;   //!
   TBranch        *b_AK12_Jet_Mass;   //!
   TBranch        *b_AK12_Jet_DeltaEta;   //!
   TBranch        *b_AK12_Jet_DeltaPhi;   //!
   TBranch        *b_AK12_Jet_Flavor;   //!
   TBranch        *b_AK12_Jet_FlavorAlgo;   //!
   TBranch        *b_AK12_Jet_FlavorPhys;   //!
   TBranch        *b_AK12_Jet_BTag;   //!
   TBranch        *b_AK12_Jet_BTagAlgo;   //!
   TBranch        *b_AK12_Jet_BTagPhys;   //!
   TBranch        *b_AK12_Jet_TauTag;   //!
   TBranch        *b_AK12_Jet_Charge;   //!
   TBranch        *b_AK12_Jet_EhadOverEem;   //!
   TBranch        *b_AK12_Jet_NCharged;   //!
   TBranch        *b_AK12_Jet_NNeutrals;   //!
   TBranch        *b_AK12_Jet_Beta;   //!
   TBranch        *b_AK12_Jet_BetaStar;   //!
   TBranch        *b_AK12_Jet_MeanSqDeltaR;   //!
   TBranch        *b_AK12_Jet_PTD;   //!
   TBranch        *b_AK12_Jet_FracPt;   //!
   TBranch        *b_AK12_Jet_Tau;   //!
   TBranch        *b_AK12_Jet_TrimmedP4;   //!
   TBranch        *b_AK12_Jet_PrunedP4;   //!
   TBranch        *b_AK12_Jet_SoftDroppedP4;   //!
   TBranch        *b_AK12_Jet_NSubJetsTrimmed;   //!
   TBranch        *b_AK12_Jet_NSubJetsPruned;   //!
   TBranch        *b_AK12_Jet_NSubJetsSoftDropped;   //!
   TBranch        *b_AK12_Jet_Constituents;   //!
   TBranch        *b_AK12_Jet_Particles;   //!
   TBranch        *b_AK12_Jet_Area;   //!
   TBranch        *b_AK12_Jet_size;   //!
   TBranch        *b_Electron_;   //!
   TBranch        *b_Electron_fUniqueID;   //!
   TBranch        *b_Electron_fBits;   //!
   TBranch        *b_Electron_PT;   //!
   TBranch        *b_Electron_Eta;   //!
   TBranch        *b_Electron_Phi;   //!
   TBranch        *b_Electron_T;   //!
   TBranch        *b_Electron_Charge;   //!
   TBranch        *b_Electron_EhadOverEem;   //!
   TBranch        *b_Electron_Particle;   //!
   TBranch        *b_Electron_IsolationVar;   //!
   TBranch        *b_Electron_IsolationVarRhoCorr;   //!
   TBranch        *b_Electron_SumPtCharged;   //!
   TBranch        *b_Electron_SumPtNeutral;   //!
   TBranch        *b_Electron_SumPtChargedPU;   //!
   TBranch        *b_Electron_SumPt;   //!
   TBranch        *b_Electron_size;   //!
   TBranch        *b_Photon_;   //!
   TBranch        *b_Photon_fUniqueID;   //!
   TBranch        *b_Photon_fBits;   //!
   TBranch        *b_Photon_PT;   //!
   TBranch        *b_Photon_Eta;   //!
   TBranch        *b_Photon_Phi;   //!
   TBranch        *b_Photon_E;   //!
   TBranch        *b_Photon_T;   //!
   TBranch        *b_Photon_EhadOverEem;   //!
   TBranch        *b_Photon_Particles;   //!
   TBranch        *b_Photon_IsolationVar;   //!
   TBranch        *b_Photon_IsolationVarRhoCorr;   //!
   TBranch        *b_Photon_SumPtCharged;   //!
   TBranch        *b_Photon_SumPtNeutral;   //!
   TBranch        *b_Photon_SumPtChargedPU;   //!
   TBranch        *b_Photon_SumPt;   //!
   TBranch        *b_Photon_size;   //!
   TBranch        *b_Muon_;   //!
   TBranch        *b_Muon_fUniqueID;   //!
   TBranch        *b_Muon_fBits;   //!
   TBranch        *b_Muon_PT;   //!
   TBranch        *b_Muon_Eta;   //!
   TBranch        *b_Muon_Phi;   //!
   TBranch        *b_Muon_T;   //!
   TBranch        *b_Muon_Charge;   //!
   TBranch        *b_Muon_Particle;   //!
   TBranch        *b_Muon_IsolationVar;   //!
   TBranch        *b_Muon_IsolationVarRhoCorr;   //!
   TBranch        *b_Muon_SumPtCharged;   //!
   TBranch        *b_Muon_SumPtNeutral;   //!
   TBranch        *b_Muon_SumPtChargedPU;   //!
   TBranch        *b_Muon_SumPt;   //!
   TBranch        *b_Muon_size;   //!
   TBranch        *b_FatJet_;   //!
   TBranch        *b_FatJet_fUniqueID;   //!
   TBranch        *b_FatJet_fBits;   //!
   TBranch        *b_FatJet_PT;   //!
   TBranch        *b_FatJet_Eta;   //!
   TBranch        *b_FatJet_Phi;   //!
   TBranch        *b_FatJet_T;   //!
   TBranch        *b_FatJet_Mass;   //!
   TBranch        *b_FatJet_DeltaEta;   //!
   TBranch        *b_FatJet_DeltaPhi;   //!
   TBranch        *b_FatJet_Flavor;   //!
   TBranch        *b_FatJet_FlavorAlgo;   //!
   TBranch        *b_FatJet_FlavorPhys;   //!
   TBranch        *b_FatJet_BTag;   //!
   TBranch        *b_FatJet_BTagAlgo;   //!
   TBranch        *b_FatJet_BTagPhys;   //!
   TBranch        *b_FatJet_TauTag;   //!
   TBranch        *b_FatJet_Charge;   //!
   TBranch        *b_FatJet_EhadOverEem;   //!
   TBranch        *b_FatJet_NCharged;   //!
   TBranch        *b_FatJet_NNeutrals;   //!
   TBranch        *b_FatJet_Beta;   //!
   TBranch        *b_FatJet_BetaStar;   //!
   TBranch        *b_FatJet_MeanSqDeltaR;   //!
   TBranch        *b_FatJet_PTD;   //!
   TBranch        *b_FatJet_FracPt;   //!
   TBranch        *b_FatJet_Tau;   //!
   TBranch        *b_FatJet_TrimmedP4;   //!
   TBranch        *b_FatJet_PrunedP4;   //!
   TBranch        *b_FatJet_SoftDroppedP4;   //!
   TBranch        *b_FatJet_NSubJetsTrimmed;   //!
   TBranch        *b_FatJet_NSubJetsPruned;   //!
   TBranch        *b_FatJet_NSubJetsSoftDropped;   //!
   TBranch        *b_FatJet_Constituents;   //!
   TBranch        *b_FatJet_Particles;   //!
   TBranch        *b_FatJet_Area;   //!
   TBranch        *b_FatJet_size;   //!
   TBranch        *b_MissingET_;   //!
   TBranch        *b_MissingET_fUniqueID;   //!
   TBranch        *b_MissingET_fBits;   //!
   TBranch        *b_MissingET_MET;   //!
   TBranch        *b_MissingET_Eta;   //!
   TBranch        *b_MissingET_Phi;   //!
   TBranch        *b_MissingET_size;   //!
   TBranch        *b_ScalarHT_;   //!
   TBranch        *b_ScalarHT_fUniqueID;   //!
   TBranch        *b_ScalarHT_fBits;   //!
   TBranch        *b_ScalarHT_HT;   //!
   TBranch        *b_ScalarHT_size;   //!

   stopstop_topN2_topN1_Hbb_750100(TTree *tree=0);
   virtual ~stopstop_topN2_topN1_Hbb_750100();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Int_t    Output();//*******
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
//*********
   void BookHistograms();

   private:
   //declare histograms
   TH1D* histo[100];
   TH2D* hist[10];

   struct Part {
     TLorentzVector v;
     int id;
     int ind;
     int flavor;
     int Charge;
     int D1;
     int D2;
     int M1;
     int M2;

   };

   vector <Part> Higgs;
   vector <Part> bquark_H;
   vector <Part> bquark_t;
   vector <Part> bantiquark_H;
   vector <Part> bantiquark_t;
   vector <Part> reco_bjets;
   vector <Part> reco_jets;
   vector <Part> b_quarks;
   vector <Part> b_quarks_H;
   vector <Part> match_bjets;
   vector <Part> matched_mindP_jets;
   vector <Part> match_bjets_Hmass;
   vector <Part> matched_bquarks;

   vector <float> invM_bbj_Hmass;
   vector <float> invM_bbj_Hmass_diff;
   vector <float> array_dPhi;
   vector <float> array_dR;
   vector <float> array_dR_b;
   vector <float> dPhi_bquarks;
};

#endif

#ifdef stopstop_topN2_topN1_Hbb_750100_cxx
stopstop_topN2_topN1_Hbb_750100::stopstop_topN2_topN1_Hbb_750100(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("stopstop_topN2_topN1_Hbb_750100.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("stopstop_topN2_topN1_Hbb_750100.root");
      }
      f->GetObject("Delphes",tree);

   }
   Init(tree);
}

stopstop_topN2_topN1_Hbb_750100::~stopstop_topN2_topN1_Hbb_750100()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t stopstop_topN2_topN1_Hbb_750100::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t stopstop_topN2_topN1_Hbb_750100::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void stopstop_topN2_topN1_Hbb_750100::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Event", &Event_, &b_Event_);
   fChain->SetBranchAddress("Event.fUniqueID", Event_fUniqueID, &b_Event_fUniqueID);
   fChain->SetBranchAddress("Event.fBits", Event_fBits, &b_Event_fBits);
   fChain->SetBranchAddress("Event.Number", Event_Number, &b_Event_Number);
   fChain->SetBranchAddress("Event.ReadTime", Event_ReadTime, &b_Event_ReadTime);
   fChain->SetBranchAddress("Event.ProcTime", Event_ProcTime, &b_Event_ProcTime);
   fChain->SetBranchAddress("Event.ProcessID", Event_ProcessID, &b_Event_ProcessID);
   fChain->SetBranchAddress("Event.Weight", Event_Weight, &b_Event_Weight);
   fChain->SetBranchAddress("Event.ScalePDF", Event_ScalePDF, &b_Event_ScalePDF);
   fChain->SetBranchAddress("Event.AlphaQED", Event_AlphaQED, &b_Event_AlphaQED);
   fChain->SetBranchAddress("Event.AlphaQCD", Event_AlphaQCD, &b_Event_AlphaQCD);
   fChain->SetBranchAddress("Event_size", &Event_size, &b_Event_size);
   fChain->SetBranchAddress("Particle", &Particle_, &b_Particle_);
   fChain->SetBranchAddress("Particle.fUniqueID", Particle_fUniqueID, &b_Particle_fUniqueID);
   fChain->SetBranchAddress("Particle.fBits", Particle_fBits, &b_Particle_fBits);
   fChain->SetBranchAddress("Particle.PID", Particle_PID, &b_Particle_PID);
   fChain->SetBranchAddress("Particle.Status", Particle_Status, &b_Particle_Status);
   fChain->SetBranchAddress("Particle.IsPU", Particle_IsPU, &b_Particle_IsPU);
   fChain->SetBranchAddress("Particle.M1", Particle_M1, &b_Particle_M1);
   fChain->SetBranchAddress("Particle.M2", Particle_M2, &b_Particle_M2);
   fChain->SetBranchAddress("Particle.D1", Particle_D1, &b_Particle_D1);
   fChain->SetBranchAddress("Particle.D2", Particle_D2, &b_Particle_D2);
   fChain->SetBranchAddress("Particle.Charge", Particle_Charge, &b_Particle_Charge);
   fChain->SetBranchAddress("Particle.Mass", Particle_Mass, &b_Particle_Mass);
   fChain->SetBranchAddress("Particle.E", Particle_E, &b_Particle_E);
   fChain->SetBranchAddress("Particle.Px", Particle_Px, &b_Particle_Px);
   fChain->SetBranchAddress("Particle.Py", Particle_Py, &b_Particle_Py);
   fChain->SetBranchAddress("Particle.Pz", Particle_Pz, &b_Particle_Pz);
   fChain->SetBranchAddress("Particle.P", Particle_P, &b_Particle_P);
   fChain->SetBranchAddress("Particle.PT", Particle_PT, &b_Particle_PT);
   fChain->SetBranchAddress("Particle.Eta", Particle_Eta, &b_Particle_Eta);
   fChain->SetBranchAddress("Particle.Phi", Particle_Phi, &b_Particle_Phi);
   fChain->SetBranchAddress("Particle.Rapidity", Particle_Rapidity, &b_Particle_Rapidity);
   fChain->SetBranchAddress("Particle.CtgTheta", Particle_CtgTheta, &b_Particle_CtgTheta);
   fChain->SetBranchAddress("Particle.D0", Particle_D0, &b_Particle_D0);
   fChain->SetBranchAddress("Particle.DZ", Particle_DZ, &b_Particle_DZ);
   fChain->SetBranchAddress("Particle.T", Particle_T, &b_Particle_T);
   fChain->SetBranchAddress("Particle.X", Particle_X, &b_Particle_X);
   fChain->SetBranchAddress("Particle.Y", Particle_Y, &b_Particle_Y);
   fChain->SetBranchAddress("Particle.Z", Particle_Z, &b_Particle_Z);
   fChain->SetBranchAddress("Particle_size", &Particle_size, &b_Particle_size);
   fChain->SetBranchAddress("GenJet", &GenJet_, &b_GenJet_);
   fChain->SetBranchAddress("GenJet.fUniqueID", GenJet_fUniqueID, &b_GenJet_fUniqueID);
   fChain->SetBranchAddress("GenJet.fBits", GenJet_fBits, &b_GenJet_fBits);
   fChain->SetBranchAddress("GenJet.PT", GenJet_PT, &b_GenJet_PT);
   fChain->SetBranchAddress("GenJet.Eta", GenJet_Eta, &b_GenJet_Eta);
   fChain->SetBranchAddress("GenJet.Phi", GenJet_Phi, &b_GenJet_Phi);
   fChain->SetBranchAddress("GenJet.T", GenJet_T, &b_GenJet_T);
   fChain->SetBranchAddress("GenJet.Mass", GenJet_Mass, &b_GenJet_Mass);
   fChain->SetBranchAddress("GenJet.DeltaEta", GenJet_DeltaEta, &b_GenJet_DeltaEta);
   fChain->SetBranchAddress("GenJet.DeltaPhi", GenJet_DeltaPhi, &b_GenJet_DeltaPhi);
   fChain->SetBranchAddress("GenJet.Flavor", GenJet_Flavor, &b_GenJet_Flavor);
   fChain->SetBranchAddress("GenJet.FlavorAlgo", GenJet_FlavorAlgo, &b_GenJet_FlavorAlgo);
   fChain->SetBranchAddress("GenJet.FlavorPhys", GenJet_FlavorPhys, &b_GenJet_FlavorPhys);
   fChain->SetBranchAddress("GenJet.BTag", GenJet_BTag, &b_GenJet_BTag);
   fChain->SetBranchAddress("GenJet.BTagAlgo", GenJet_BTagAlgo, &b_GenJet_BTagAlgo);
   fChain->SetBranchAddress("GenJet.BTagPhys", GenJet_BTagPhys, &b_GenJet_BTagPhys);
   fChain->SetBranchAddress("GenJet.TauTag", GenJet_TauTag, &b_GenJet_TauTag);
   fChain->SetBranchAddress("GenJet.Charge", GenJet_Charge, &b_GenJet_Charge);
   fChain->SetBranchAddress("GenJet.EhadOverEem", GenJet_EhadOverEem, &b_GenJet_EhadOverEem);
   fChain->SetBranchAddress("GenJet.NCharged", GenJet_NCharged, &b_GenJet_NCharged);
   fChain->SetBranchAddress("GenJet.NNeutrals", GenJet_NNeutrals, &b_GenJet_NNeutrals);
   fChain->SetBranchAddress("GenJet.Beta", GenJet_Beta, &b_GenJet_Beta);
   fChain->SetBranchAddress("GenJet.BetaStar", GenJet_BetaStar, &b_GenJet_BetaStar);
   fChain->SetBranchAddress("GenJet.MeanSqDeltaR", GenJet_MeanSqDeltaR, &b_GenJet_MeanSqDeltaR);
   fChain->SetBranchAddress("GenJet.PTD", GenJet_PTD, &b_GenJet_PTD);
   fChain->SetBranchAddress("GenJet.FracPt[5]", GenJet_FracPt, &b_GenJet_FracPt);
   fChain->SetBranchAddress("GenJet.Tau[5]", GenJet_Tau, &b_GenJet_Tau);
   fChain->SetBranchAddress("GenJet.TrimmedP4[5]", GenJet_TrimmedP4, &b_GenJet_TrimmedP4);
   fChain->SetBranchAddress("GenJet.PrunedP4[5]", GenJet_PrunedP4, &b_GenJet_PrunedP4);
   fChain->SetBranchAddress("GenJet.SoftDroppedP4[5]", GenJet_SoftDroppedP4, &b_GenJet_SoftDroppedP4);
   fChain->SetBranchAddress("GenJet.NSubJetsTrimmed", GenJet_NSubJetsTrimmed, &b_GenJet_NSubJetsTrimmed);
   fChain->SetBranchAddress("GenJet.NSubJetsPruned", GenJet_NSubJetsPruned, &b_GenJet_NSubJetsPruned);
   fChain->SetBranchAddress("GenJet.NSubJetsSoftDropped", GenJet_NSubJetsSoftDropped, &b_GenJet_NSubJetsSoftDropped);
   fChain->SetBranchAddress("GenJet.Constituents", GenJet_Constituents, &b_GenJet_Constituents);
   fChain->SetBranchAddress("GenJet.Particles", GenJet_Particles, &b_GenJet_Particles);
   fChain->SetBranchAddress("GenJet.Area", GenJet_Area, &b_GenJet_Area);
   fChain->SetBranchAddress("GenJet_size", &GenJet_size, &b_GenJet_size);
   fChain->SetBranchAddress("GenMissingET", &GenMissingET_, &b_GenMissingET_);
   fChain->SetBranchAddress("GenMissingET.fUniqueID", GenMissingET_fUniqueID, &b_GenMissingET_fUniqueID);
   fChain->SetBranchAddress("GenMissingET.fBits", GenMissingET_fBits, &b_GenMissingET_fBits);
   fChain->SetBranchAddress("GenMissingET.MET", GenMissingET_MET, &b_GenMissingET_MET);
   fChain->SetBranchAddress("GenMissingET.Eta", GenMissingET_Eta, &b_GenMissingET_Eta);
   fChain->SetBranchAddress("GenMissingET.Phi", GenMissingET_Phi, &b_GenMissingET_Phi);
   fChain->SetBranchAddress("GenMissingET_size", &GenMissingET_size, &b_GenMissingET_size);
   fChain->SetBranchAddress("Jet", &Jet_, &b_Jet_);
   fChain->SetBranchAddress("Jet.fUniqueID", Jet_fUniqueID, &b_Jet_fUniqueID);
   fChain->SetBranchAddress("Jet.fBits", Jet_fBits, &b_Jet_fBits);
   fChain->SetBranchAddress("Jet.PT", Jet_PT, &b_Jet_PT);
   fChain->SetBranchAddress("Jet.Eta", Jet_Eta, &b_Jet_Eta);
   fChain->SetBranchAddress("Jet.Phi", Jet_Phi, &b_Jet_Phi);
   fChain->SetBranchAddress("Jet.T", Jet_T, &b_Jet_T);
   fChain->SetBranchAddress("Jet.Mass", Jet_Mass, &b_Jet_Mass);
   fChain->SetBranchAddress("Jet.DeltaEta", Jet_DeltaEta, &b_Jet_DeltaEta);
   fChain->SetBranchAddress("Jet.DeltaPhi", Jet_DeltaPhi, &b_Jet_DeltaPhi);
   fChain->SetBranchAddress("Jet.Flavor", Jet_Flavor, &b_Jet_Flavor);
   fChain->SetBranchAddress("Jet.FlavorAlgo", Jet_FlavorAlgo, &b_Jet_FlavorAlgo);
   fChain->SetBranchAddress("Jet.FlavorPhys", Jet_FlavorPhys, &b_Jet_FlavorPhys);
   fChain->SetBranchAddress("Jet.BTag", Jet_BTag, &b_Jet_BTag);
   fChain->SetBranchAddress("Jet.BTagAlgo", Jet_BTagAlgo, &b_Jet_BTagAlgo);
   fChain->SetBranchAddress("Jet.BTagPhys", Jet_BTagPhys, &b_Jet_BTagPhys);
   fChain->SetBranchAddress("Jet.TauTag", Jet_TauTag, &b_Jet_TauTag);
   fChain->SetBranchAddress("Jet.Charge", Jet_Charge, &b_Jet_Charge);
   fChain->SetBranchAddress("Jet.EhadOverEem", Jet_EhadOverEem, &b_Jet_EhadOverEem);
   fChain->SetBranchAddress("Jet.NCharged", Jet_NCharged, &b_Jet_NCharged);
   fChain->SetBranchAddress("Jet.NNeutrals", Jet_NNeutrals, &b_Jet_NNeutrals);
   fChain->SetBranchAddress("Jet.Beta", Jet_Beta, &b_Jet_Beta);
   fChain->SetBranchAddress("Jet.BetaStar", Jet_BetaStar, &b_Jet_BetaStar);
   fChain->SetBranchAddress("Jet.MeanSqDeltaR", Jet_MeanSqDeltaR, &b_Jet_MeanSqDeltaR);
   fChain->SetBranchAddress("Jet.PTD", Jet_PTD, &b_Jet_PTD);
   fChain->SetBranchAddress("Jet.FracPt[5]", Jet_FracPt, &b_Jet_FracPt);
   fChain->SetBranchAddress("Jet.Tau[5]", Jet_Tau, &b_Jet_Tau);
   fChain->SetBranchAddress("Jet.TrimmedP4[5]", Jet_TrimmedP4, &b_Jet_TrimmedP4);
   fChain->SetBranchAddress("Jet.PrunedP4[5]", Jet_PrunedP4, &b_Jet_PrunedP4);
   fChain->SetBranchAddress("Jet.SoftDroppedP4[5]", Jet_SoftDroppedP4, &b_Jet_SoftDroppedP4);
   fChain->SetBranchAddress("Jet.NSubJetsTrimmed", Jet_NSubJetsTrimmed, &b_Jet_NSubJetsTrimmed);
   fChain->SetBranchAddress("Jet.NSubJetsPruned", Jet_NSubJetsPruned, &b_Jet_NSubJetsPruned);
   fChain->SetBranchAddress("Jet.NSubJetsSoftDropped", Jet_NSubJetsSoftDropped, &b_Jet_NSubJetsSoftDropped);
   fChain->SetBranchAddress("Jet.Constituents", Jet_Constituents, &b_Jet_Constituents);
   fChain->SetBranchAddress("Jet.Particles", Jet_Particles, &b_Jet_Particles);
   fChain->SetBranchAddress("Jet.Area", Jet_Area, &b_Jet_Area);
   fChain->SetBranchAddress("Jet_size", &Jet_size, &b_Jet_size);
   fChain->SetBranchAddress("AK4_Jet", &AK4_Jet_, &b_AK4_Jet_);
   fChain->SetBranchAddress("AK4_Jet.fUniqueID", AK4_Jet_fUniqueID, &b_AK4_Jet_fUniqueID);
   fChain->SetBranchAddress("AK4_Jet.fBits", AK4_Jet_fBits, &b_AK4_Jet_fBits);
   fChain->SetBranchAddress("AK4_Jet.PT", AK4_Jet_PT, &b_AK4_Jet_PT);
   fChain->SetBranchAddress("AK4_Jet.Eta", AK4_Jet_Eta, &b_AK4_Jet_Eta);
   fChain->SetBranchAddress("AK4_Jet.Phi", AK4_Jet_Phi, &b_AK4_Jet_Phi);
   fChain->SetBranchAddress("AK4_Jet.T", AK4_Jet_T, &b_AK4_Jet_T);
   fChain->SetBranchAddress("AK4_Jet.Mass", AK4_Jet_Mass, &b_AK4_Jet_Mass);
   fChain->SetBranchAddress("AK4_Jet.DeltaEta", AK4_Jet_DeltaEta, &b_AK4_Jet_DeltaEta);
   fChain->SetBranchAddress("AK4_Jet.DeltaPhi", AK4_Jet_DeltaPhi, &b_AK4_Jet_DeltaPhi);
   fChain->SetBranchAddress("AK4_Jet.Flavor", AK4_Jet_Flavor, &b_AK4_Jet_Flavor);
   fChain->SetBranchAddress("AK4_Jet.FlavorAlgo", AK4_Jet_FlavorAlgo, &b_AK4_Jet_FlavorAlgo);
   fChain->SetBranchAddress("AK4_Jet.FlavorPhys", AK4_Jet_FlavorPhys, &b_AK4_Jet_FlavorPhys);
   fChain->SetBranchAddress("AK4_Jet.BTag", AK4_Jet_BTag, &b_AK4_Jet_BTag);
   fChain->SetBranchAddress("AK4_Jet.BTagAlgo", AK4_Jet_BTagAlgo, &b_AK4_Jet_BTagAlgo);
   fChain->SetBranchAddress("AK4_Jet.BTagPhys", AK4_Jet_BTagPhys, &b_AK4_Jet_BTagPhys);
   fChain->SetBranchAddress("AK4_Jet.TauTag", AK4_Jet_TauTag, &b_AK4_Jet_TauTag);
   fChain->SetBranchAddress("AK4_Jet.Charge", AK4_Jet_Charge, &b_AK4_Jet_Charge);
   fChain->SetBranchAddress("AK4_Jet.EhadOverEem", AK4_Jet_EhadOverEem, &b_AK4_Jet_EhadOverEem);
   fChain->SetBranchAddress("AK4_Jet.NCharged", AK4_Jet_NCharged, &b_AK4_Jet_NCharged);
   fChain->SetBranchAddress("AK4_Jet.NNeutrals", AK4_Jet_NNeutrals, &b_AK4_Jet_NNeutrals);
   fChain->SetBranchAddress("AK4_Jet.Beta", AK4_Jet_Beta, &b_AK4_Jet_Beta);
   fChain->SetBranchAddress("AK4_Jet.BetaStar", AK4_Jet_BetaStar, &b_AK4_Jet_BetaStar);
   fChain->SetBranchAddress("AK4_Jet.MeanSqDeltaR", AK4_Jet_MeanSqDeltaR, &b_AK4_Jet_MeanSqDeltaR);
   fChain->SetBranchAddress("AK4_Jet.PTD", AK4_Jet_PTD, &b_AK4_Jet_PTD);
   fChain->SetBranchAddress("AK4_Jet.FracPt[5]", AK4_Jet_FracPt, &b_AK4_Jet_FracPt);
   fChain->SetBranchAddress("AK4_Jet.Tau[5]", AK4_Jet_Tau, &b_AK4_Jet_Tau);
   fChain->SetBranchAddress("AK4_Jet.TrimmedP4[5]", AK4_Jet_TrimmedP4, &b_AK4_Jet_TrimmedP4);
   fChain->SetBranchAddress("AK4_Jet.PrunedP4[5]", AK4_Jet_PrunedP4, &b_AK4_Jet_PrunedP4);
   fChain->SetBranchAddress("AK4_Jet.SoftDroppedP4[5]", AK4_Jet_SoftDroppedP4, &b_AK4_Jet_SoftDroppedP4);
   fChain->SetBranchAddress("AK4_Jet.NSubJetsTrimmed", AK4_Jet_NSubJetsTrimmed, &b_AK4_Jet_NSubJetsTrimmed);
   fChain->SetBranchAddress("AK4_Jet.NSubJetsPruned", AK4_Jet_NSubJetsPruned, &b_AK4_Jet_NSubJetsPruned);
   fChain->SetBranchAddress("AK4_Jet.NSubJetsSoftDropped", AK4_Jet_NSubJetsSoftDropped, &b_AK4_Jet_NSubJetsSoftDropped);
   fChain->SetBranchAddress("AK4_Jet.Constituents", AK4_Jet_Constituents, &b_AK4_Jet_Constituents);
   fChain->SetBranchAddress("AK4_Jet.Particles", AK4_Jet_Particles, &b_AK4_Jet_Particles);
   fChain->SetBranchAddress("AK4_Jet.Area", AK4_Jet_Area, &b_AK4_Jet_Area);
   fChain->SetBranchAddress("AK4_Jet_size", &AK4_Jet_size, &b_AK4_Jet_size);
   fChain->SetBranchAddress("AK8_Jet", &AK8_Jet_, &b_AK8_Jet_);
   fChain->SetBranchAddress("AK8_Jet.fUniqueID", AK8_Jet_fUniqueID, &b_AK8_Jet_fUniqueID);
   fChain->SetBranchAddress("AK8_Jet.fBits", AK8_Jet_fBits, &b_AK8_Jet_fBits);
   fChain->SetBranchAddress("AK8_Jet.PT", AK8_Jet_PT, &b_AK8_Jet_PT);
   fChain->SetBranchAddress("AK8_Jet.Eta", AK8_Jet_Eta, &b_AK8_Jet_Eta);
   fChain->SetBranchAddress("AK8_Jet.Phi", AK8_Jet_Phi, &b_AK8_Jet_Phi);
   fChain->SetBranchAddress("AK8_Jet.T", AK8_Jet_T, &b_AK8_Jet_T);
   fChain->SetBranchAddress("AK8_Jet.Mass", AK8_Jet_Mass, &b_AK8_Jet_Mass);
   fChain->SetBranchAddress("AK8_Jet.DeltaEta", AK8_Jet_DeltaEta, &b_AK8_Jet_DeltaEta);
   fChain->SetBranchAddress("AK8_Jet.DeltaPhi", AK8_Jet_DeltaPhi, &b_AK8_Jet_DeltaPhi);
   fChain->SetBranchAddress("AK8_Jet.Flavor", AK8_Jet_Flavor, &b_AK8_Jet_Flavor);
   fChain->SetBranchAddress("AK8_Jet.FlavorAlgo", AK8_Jet_FlavorAlgo, &b_AK8_Jet_FlavorAlgo);
   fChain->SetBranchAddress("AK8_Jet.FlavorPhys", AK8_Jet_FlavorPhys, &b_AK8_Jet_FlavorPhys);
   fChain->SetBranchAddress("AK8_Jet.BTag", AK8_Jet_BTag, &b_AK8_Jet_BTag);
   fChain->SetBranchAddress("AK8_Jet.BTagAlgo", AK8_Jet_BTagAlgo, &b_AK8_Jet_BTagAlgo);
   fChain->SetBranchAddress("AK8_Jet.BTagPhys", AK8_Jet_BTagPhys, &b_AK8_Jet_BTagPhys);
   fChain->SetBranchAddress("AK8_Jet.TauTag", AK8_Jet_TauTag, &b_AK8_Jet_TauTag);
   fChain->SetBranchAddress("AK8_Jet.Charge", AK8_Jet_Charge, &b_AK8_Jet_Charge);
   fChain->SetBranchAddress("AK8_Jet.EhadOverEem", AK8_Jet_EhadOverEem, &b_AK8_Jet_EhadOverEem);
   fChain->SetBranchAddress("AK8_Jet.NCharged", AK8_Jet_NCharged, &b_AK8_Jet_NCharged);
   fChain->SetBranchAddress("AK8_Jet.NNeutrals", AK8_Jet_NNeutrals, &b_AK8_Jet_NNeutrals);
   fChain->SetBranchAddress("AK8_Jet.Beta", AK8_Jet_Beta, &b_AK8_Jet_Beta);
   fChain->SetBranchAddress("AK8_Jet.BetaStar", AK8_Jet_BetaStar, &b_AK8_Jet_BetaStar);
   fChain->SetBranchAddress("AK8_Jet.MeanSqDeltaR", AK8_Jet_MeanSqDeltaR, &b_AK8_Jet_MeanSqDeltaR);
   fChain->SetBranchAddress("AK8_Jet.PTD", AK8_Jet_PTD, &b_AK8_Jet_PTD);
   fChain->SetBranchAddress("AK8_Jet.FracPt[5]", AK8_Jet_FracPt, &b_AK8_Jet_FracPt);
   fChain->SetBranchAddress("AK8_Jet.Tau[5]", AK8_Jet_Tau, &b_AK8_Jet_Tau);
   fChain->SetBranchAddress("AK8_Jet.TrimmedP4[5]", AK8_Jet_TrimmedP4, &b_AK8_Jet_TrimmedP4);
   fChain->SetBranchAddress("AK8_Jet.PrunedP4[5]", AK8_Jet_PrunedP4, &b_AK8_Jet_PrunedP4);
   fChain->SetBranchAddress("AK8_Jet.SoftDroppedP4[5]", AK8_Jet_SoftDroppedP4, &b_AK8_Jet_SoftDroppedP4);
   fChain->SetBranchAddress("AK8_Jet.NSubJetsTrimmed", AK8_Jet_NSubJetsTrimmed, &b_AK8_Jet_NSubJetsTrimmed);
   fChain->SetBranchAddress("AK8_Jet.NSubJetsPruned", AK8_Jet_NSubJetsPruned, &b_AK8_Jet_NSubJetsPruned);
   fChain->SetBranchAddress("AK8_Jet.NSubJetsSoftDropped", AK8_Jet_NSubJetsSoftDropped, &b_AK8_Jet_NSubJetsSoftDropped);
   fChain->SetBranchAddress("AK8_Jet.Constituents", AK8_Jet_Constituents, &b_AK8_Jet_Constituents);
   fChain->SetBranchAddress("AK8_Jet.Particles", AK8_Jet_Particles, &b_AK8_Jet_Particles);
   fChain->SetBranchAddress("AK8_Jet.Area", AK8_Jet_Area, &b_AK8_Jet_Area);
   fChain->SetBranchAddress("AK8_Jet_size", &AK8_Jet_size, &b_AK8_Jet_size);
   fChain->SetBranchAddress("AK12_Jet", &AK12_Jet_, &b_AK12_Jet_);
   fChain->SetBranchAddress("AK12_Jet.fUniqueID", AK12_Jet_fUniqueID, &b_AK12_Jet_fUniqueID);
   fChain->SetBranchAddress("AK12_Jet.fBits", AK12_Jet_fBits, &b_AK12_Jet_fBits);
   fChain->SetBranchAddress("AK12_Jet.PT", AK12_Jet_PT, &b_AK12_Jet_PT);
   fChain->SetBranchAddress("AK12_Jet.Eta", AK12_Jet_Eta, &b_AK12_Jet_Eta);
   fChain->SetBranchAddress("AK12_Jet.Phi", AK12_Jet_Phi, &b_AK12_Jet_Phi);
   fChain->SetBranchAddress("AK12_Jet.T", AK12_Jet_T, &b_AK12_Jet_T);
   fChain->SetBranchAddress("AK12_Jet.Mass", AK12_Jet_Mass, &b_AK12_Jet_Mass);
   fChain->SetBranchAddress("AK12_Jet.DeltaEta", AK12_Jet_DeltaEta, &b_AK12_Jet_DeltaEta);
   fChain->SetBranchAddress("AK12_Jet.DeltaPhi", AK12_Jet_DeltaPhi, &b_AK12_Jet_DeltaPhi);
   fChain->SetBranchAddress("AK12_Jet.Flavor", AK12_Jet_Flavor, &b_AK12_Jet_Flavor);
   fChain->SetBranchAddress("AK12_Jet.FlavorAlgo", AK12_Jet_FlavorAlgo, &b_AK12_Jet_FlavorAlgo);
   fChain->SetBranchAddress("AK12_Jet.FlavorPhys", AK12_Jet_FlavorPhys, &b_AK12_Jet_FlavorPhys);
   fChain->SetBranchAddress("AK12_Jet.BTag", AK12_Jet_BTag, &b_AK12_Jet_BTag);
   fChain->SetBranchAddress("AK12_Jet.BTagAlgo", AK12_Jet_BTagAlgo, &b_AK12_Jet_BTagAlgo);
   fChain->SetBranchAddress("AK12_Jet.BTagPhys", AK12_Jet_BTagPhys, &b_AK12_Jet_BTagPhys);
   fChain->SetBranchAddress("AK12_Jet.TauTag", AK12_Jet_TauTag, &b_AK12_Jet_TauTag);
   fChain->SetBranchAddress("AK12_Jet.Charge", AK12_Jet_Charge, &b_AK12_Jet_Charge);
   fChain->SetBranchAddress("AK12_Jet.EhadOverEem", AK12_Jet_EhadOverEem, &b_AK12_Jet_EhadOverEem);
   fChain->SetBranchAddress("AK12_Jet.NCharged", AK12_Jet_NCharged, &b_AK12_Jet_NCharged);
   fChain->SetBranchAddress("AK12_Jet.NNeutrals", AK12_Jet_NNeutrals, &b_AK12_Jet_NNeutrals);
   fChain->SetBranchAddress("AK12_Jet.Beta", AK12_Jet_Beta, &b_AK12_Jet_Beta);
   fChain->SetBranchAddress("AK12_Jet.BetaStar", AK12_Jet_BetaStar, &b_AK12_Jet_BetaStar);
   fChain->SetBranchAddress("AK12_Jet.MeanSqDeltaR", AK12_Jet_MeanSqDeltaR, &b_AK12_Jet_MeanSqDeltaR);
   fChain->SetBranchAddress("AK12_Jet.PTD", AK12_Jet_PTD, &b_AK12_Jet_PTD);
   fChain->SetBranchAddress("AK12_Jet.FracPt[5]", AK12_Jet_FracPt, &b_AK12_Jet_FracPt);
   fChain->SetBranchAddress("AK12_Jet.Tau[5]", AK12_Jet_Tau, &b_AK12_Jet_Tau);
   fChain->SetBranchAddress("AK12_Jet.TrimmedP4[5]", AK12_Jet_TrimmedP4, &b_AK12_Jet_TrimmedP4);
   fChain->SetBranchAddress("AK12_Jet.PrunedP4[5]", AK12_Jet_PrunedP4, &b_AK12_Jet_PrunedP4);
   fChain->SetBranchAddress("AK12_Jet.SoftDroppedP4[5]", AK12_Jet_SoftDroppedP4, &b_AK12_Jet_SoftDroppedP4);
   fChain->SetBranchAddress("AK12_Jet.NSubJetsTrimmed", AK12_Jet_NSubJetsTrimmed, &b_AK12_Jet_NSubJetsTrimmed);
   fChain->SetBranchAddress("AK12_Jet.NSubJetsPruned", AK12_Jet_NSubJetsPruned, &b_AK12_Jet_NSubJetsPruned);
   fChain->SetBranchAddress("AK12_Jet.NSubJetsSoftDropped", AK12_Jet_NSubJetsSoftDropped, &b_AK12_Jet_NSubJetsSoftDropped);
   fChain->SetBranchAddress("AK12_Jet.Constituents", AK12_Jet_Constituents, &b_AK12_Jet_Constituents);
   fChain->SetBranchAddress("AK12_Jet.Particles", AK12_Jet_Particles, &b_AK12_Jet_Particles);
   fChain->SetBranchAddress("AK12_Jet.Area", AK12_Jet_Area, &b_AK12_Jet_Area);
   fChain->SetBranchAddress("AK12_Jet_size", &AK12_Jet_size, &b_AK12_Jet_size);
   fChain->SetBranchAddress("Electron", &Electron_, &b_Electron_);
   fChain->SetBranchAddress("Electron.fUniqueID", Electron_fUniqueID, &b_Electron_fUniqueID);
   fChain->SetBranchAddress("Electron.fBits", Electron_fBits, &b_Electron_fBits);
   fChain->SetBranchAddress("Electron.PT", Electron_PT, &b_Electron_PT);
   fChain->SetBranchAddress("Electron.Eta", Electron_Eta, &b_Electron_Eta);
   fChain->SetBranchAddress("Electron.Phi", Electron_Phi, &b_Electron_Phi);
   fChain->SetBranchAddress("Electron.T", Electron_T, &b_Electron_T);
   fChain->SetBranchAddress("Electron.Charge", Electron_Charge, &b_Electron_Charge);
   fChain->SetBranchAddress("Electron.EhadOverEem", Electron_EhadOverEem, &b_Electron_EhadOverEem);
   fChain->SetBranchAddress("Electron.Particle", Electron_Particle, &b_Electron_Particle);
   fChain->SetBranchAddress("Electron.IsolationVar", Electron_IsolationVar, &b_Electron_IsolationVar);
   fChain->SetBranchAddress("Electron.IsolationVarRhoCorr", Electron_IsolationVarRhoCorr, &b_Electron_IsolationVarRhoCorr);
   fChain->SetBranchAddress("Electron.SumPtCharged", Electron_SumPtCharged, &b_Electron_SumPtCharged);
   fChain->SetBranchAddress("Electron.SumPtNeutral", Electron_SumPtNeutral, &b_Electron_SumPtNeutral);
   fChain->SetBranchAddress("Electron.SumPtChargedPU", Electron_SumPtChargedPU, &b_Electron_SumPtChargedPU);
   fChain->SetBranchAddress("Electron.SumPt", Electron_SumPt, &b_Electron_SumPt);
   fChain->SetBranchAddress("Electron_size", &Electron_size, &b_Electron_size);
   fChain->SetBranchAddress("Photon", &Photon_, &b_Photon_);
   fChain->SetBranchAddress("Photon.fUniqueID", Photon_fUniqueID, &b_Photon_fUniqueID);
   fChain->SetBranchAddress("Photon.fBits", Photon_fBits, &b_Photon_fBits);
   fChain->SetBranchAddress("Photon.PT", Photon_PT, &b_Photon_PT);
   fChain->SetBranchAddress("Photon.Eta", Photon_Eta, &b_Photon_Eta);
   fChain->SetBranchAddress("Photon.Phi", Photon_Phi, &b_Photon_Phi);
   fChain->SetBranchAddress("Photon.E", Photon_E, &b_Photon_E);
   fChain->SetBranchAddress("Photon.T", Photon_T, &b_Photon_T);
   fChain->SetBranchAddress("Photon.EhadOverEem", Photon_EhadOverEem, &b_Photon_EhadOverEem);
   fChain->SetBranchAddress("Photon.Particles", Photon_Particles, &b_Photon_Particles);
   fChain->SetBranchAddress("Photon.IsolationVar", Photon_IsolationVar, &b_Photon_IsolationVar);
   fChain->SetBranchAddress("Photon.IsolationVarRhoCorr", Photon_IsolationVarRhoCorr, &b_Photon_IsolationVarRhoCorr);
   fChain->SetBranchAddress("Photon.SumPtCharged", Photon_SumPtCharged, &b_Photon_SumPtCharged);
   fChain->SetBranchAddress("Photon.SumPtNeutral", Photon_SumPtNeutral, &b_Photon_SumPtNeutral);
   fChain->SetBranchAddress("Photon.SumPtChargedPU", Photon_SumPtChargedPU, &b_Photon_SumPtChargedPU);
   fChain->SetBranchAddress("Photon.SumPt", Photon_SumPt, &b_Photon_SumPt);
   fChain->SetBranchAddress("Photon_size", &Photon_size, &b_Photon_size);
   fChain->SetBranchAddress("Muon", &Muon_, &b_Muon_);
   fChain->SetBranchAddress("Muon.fUniqueID", Muon_fUniqueID, &b_Muon_fUniqueID);
   fChain->SetBranchAddress("Muon.fBits", Muon_fBits, &b_Muon_fBits);
   fChain->SetBranchAddress("Muon.PT", Muon_PT, &b_Muon_PT);
   fChain->SetBranchAddress("Muon.Eta", Muon_Eta, &b_Muon_Eta);
   fChain->SetBranchAddress("Muon.Phi", Muon_Phi, &b_Muon_Phi);
   fChain->SetBranchAddress("Muon.T", Muon_T, &b_Muon_T);
   fChain->SetBranchAddress("Muon.Charge", Muon_Charge, &b_Muon_Charge);
   fChain->SetBranchAddress("Muon.Particle", Muon_Particle, &b_Muon_Particle);
   fChain->SetBranchAddress("Muon.IsolationVar", Muon_IsolationVar, &b_Muon_IsolationVar);
   fChain->SetBranchAddress("Muon.IsolationVarRhoCorr", Muon_IsolationVarRhoCorr, &b_Muon_IsolationVarRhoCorr);
   fChain->SetBranchAddress("Muon.SumPtCharged", Muon_SumPtCharged, &b_Muon_SumPtCharged);
   fChain->SetBranchAddress("Muon.SumPtNeutral", Muon_SumPtNeutral, &b_Muon_SumPtNeutral);
   fChain->SetBranchAddress("Muon.SumPtChargedPU", Muon_SumPtChargedPU, &b_Muon_SumPtChargedPU);
   fChain->SetBranchAddress("Muon.SumPt", Muon_SumPt, &b_Muon_SumPt);
   fChain->SetBranchAddress("Muon_size", &Muon_size, &b_Muon_size);
   fChain->SetBranchAddress("FatJet", &FatJet_, &b_FatJet_);
   fChain->SetBranchAddress("FatJet.fUniqueID", FatJet_fUniqueID, &b_FatJet_fUniqueID);
   fChain->SetBranchAddress("FatJet.fBits", FatJet_fBits, &b_FatJet_fBits);
   fChain->SetBranchAddress("FatJet.PT", FatJet_PT, &b_FatJet_PT);
   fChain->SetBranchAddress("FatJet.Eta", FatJet_Eta, &b_FatJet_Eta);
   fChain->SetBranchAddress("FatJet.Phi", FatJet_Phi, &b_FatJet_Phi);
   fChain->SetBranchAddress("FatJet.T", FatJet_T, &b_FatJet_T);
   fChain->SetBranchAddress("FatJet.Mass", FatJet_Mass, &b_FatJet_Mass);
   fChain->SetBranchAddress("FatJet.DeltaEta", FatJet_DeltaEta, &b_FatJet_DeltaEta);
   fChain->SetBranchAddress("FatJet.DeltaPhi", FatJet_DeltaPhi, &b_FatJet_DeltaPhi);
   fChain->SetBranchAddress("FatJet.Flavor", FatJet_Flavor, &b_FatJet_Flavor);
   fChain->SetBranchAddress("FatJet.FlavorAlgo", FatJet_FlavorAlgo, &b_FatJet_FlavorAlgo);
   fChain->SetBranchAddress("FatJet.FlavorPhys", FatJet_FlavorPhys, &b_FatJet_FlavorPhys);
   fChain->SetBranchAddress("FatJet.BTag", FatJet_BTag, &b_FatJet_BTag);
   fChain->SetBranchAddress("FatJet.BTagAlgo", FatJet_BTagAlgo, &b_FatJet_BTagAlgo);
   fChain->SetBranchAddress("FatJet.BTagPhys", FatJet_BTagPhys, &b_FatJet_BTagPhys);
   fChain->SetBranchAddress("FatJet.TauTag", FatJet_TauTag, &b_FatJet_TauTag);
   fChain->SetBranchAddress("FatJet.Charge", FatJet_Charge, &b_FatJet_Charge);
   fChain->SetBranchAddress("FatJet.EhadOverEem", FatJet_EhadOverEem, &b_FatJet_EhadOverEem);
   fChain->SetBranchAddress("FatJet.NCharged", FatJet_NCharged, &b_FatJet_NCharged);
   fChain->SetBranchAddress("FatJet.NNeutrals", FatJet_NNeutrals, &b_FatJet_NNeutrals);
   fChain->SetBranchAddress("FatJet.Beta", FatJet_Beta, &b_FatJet_Beta);
   fChain->SetBranchAddress("FatJet.BetaStar", FatJet_BetaStar, &b_FatJet_BetaStar);
   fChain->SetBranchAddress("FatJet.MeanSqDeltaR", FatJet_MeanSqDeltaR, &b_FatJet_MeanSqDeltaR);
   fChain->SetBranchAddress("FatJet.PTD", FatJet_PTD, &b_FatJet_PTD);
   fChain->SetBranchAddress("FatJet.FracPt[5]", FatJet_FracPt, &b_FatJet_FracPt);
   fChain->SetBranchAddress("FatJet.Tau[5]", FatJet_Tau, &b_FatJet_Tau);
   fChain->SetBranchAddress("FatJet.TrimmedP4[5]", FatJet_TrimmedP4, &b_FatJet_TrimmedP4);
   fChain->SetBranchAddress("FatJet.PrunedP4[5]", FatJet_PrunedP4, &b_FatJet_PrunedP4);
   fChain->SetBranchAddress("FatJet.SoftDroppedP4[5]", FatJet_SoftDroppedP4, &b_FatJet_SoftDroppedP4);
   fChain->SetBranchAddress("FatJet.NSubJetsTrimmed", FatJet_NSubJetsTrimmed, &b_FatJet_NSubJetsTrimmed);
   fChain->SetBranchAddress("FatJet.NSubJetsPruned", FatJet_NSubJetsPruned, &b_FatJet_NSubJetsPruned);
   fChain->SetBranchAddress("FatJet.NSubJetsSoftDropped", FatJet_NSubJetsSoftDropped, &b_FatJet_NSubJetsSoftDropped);
   fChain->SetBranchAddress("FatJet.Constituents", FatJet_Constituents, &b_FatJet_Constituents);
   fChain->SetBranchAddress("FatJet.Particles", FatJet_Particles, &b_FatJet_Particles);
   fChain->SetBranchAddress("FatJet.Area", FatJet_Area, &b_FatJet_Area);
   fChain->SetBranchAddress("FatJet_size", &FatJet_size, &b_FatJet_size);
   fChain->SetBranchAddress("MissingET", &MissingET_, &b_MissingET_);
   fChain->SetBranchAddress("MissingET.fUniqueID", MissingET_fUniqueID, &b_MissingET_fUniqueID);
   fChain->SetBranchAddress("MissingET.fBits", MissingET_fBits, &b_MissingET_fBits);
   fChain->SetBranchAddress("MissingET.MET", MissingET_MET, &b_MissingET_MET);
   fChain->SetBranchAddress("MissingET.Eta", MissingET_Eta, &b_MissingET_Eta);
   fChain->SetBranchAddress("MissingET.Phi", MissingET_Phi, &b_MissingET_Phi);
   fChain->SetBranchAddress("MissingET_size", &MissingET_size, &b_MissingET_size);
   fChain->SetBranchAddress("ScalarHT", &ScalarHT_, &b_ScalarHT_);
   fChain->SetBranchAddress("ScalarHT.fUniqueID", ScalarHT_fUniqueID, &b_ScalarHT_fUniqueID);
   fChain->SetBranchAddress("ScalarHT.fBits", ScalarHT_fBits, &b_ScalarHT_fBits);
   fChain->SetBranchAddress("ScalarHT.HT", ScalarHT_HT, &b_ScalarHT_HT);
   fChain->SetBranchAddress("ScalarHT_size", &ScalarHT_size, &b_ScalarHT_size);
   Notify();
}

Bool_t stopstop_topN2_topN1_Hbb_750100::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void stopstop_topN2_topN1_Hbb_750100::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t stopstop_topN2_topN1_Hbb_750100::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef stopstop_topN2_topN1_Hbb_750100_cxx
