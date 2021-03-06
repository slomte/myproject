#include "SampleAnalyzer/User/Analyzer/stop_topN2_HZ_ana.h"
using namespace MA5;
using namespace std;

// -----------------------------------------------------------------------------
// Initialize
// function called one time at the beginning of the analysis
// -----------------------------------------------------------------------------
bool stop_topN2_HZ_ana::Initialize(const MA5::Configuration& cfg, const std::map<std::string,std::string>& parameters)
{
  cout << "BEGIN Initialization" << endl;
  // initialize variables, histos

  // Initializing PhysicsService for MC
  PHYSICS->mcConfig().Reset();

  // definition of the multiparticle "hadronic"
  PHYSICS->mcConfig().AddHadronicId(-5);
  PHYSICS->mcConfig().AddHadronicId(-4);
  PHYSICS->mcConfig().AddHadronicId(-3);
  PHYSICS->mcConfig().AddHadronicId(-2);
  PHYSICS->mcConfig().AddHadronicId(-1);
  PHYSICS->mcConfig().AddHadronicId(1);
  PHYSICS->mcConfig().AddHadronicId(2);
  PHYSICS->mcConfig().AddHadronicId(3);
  PHYSICS->mcConfig().AddHadronicId(4);
  PHYSICS->mcConfig().AddHadronicId(5);
  PHYSICS->mcConfig().AddHadronicId(21);

  // definition of the multiparticle "invisible"
  PHYSICS->mcConfig().AddInvisibleId(-16);
  PHYSICS->mcConfig().AddInvisibleId(-14);
  PHYSICS->mcConfig().AddInvisibleId(-12);
  PHYSICS->mcConfig().AddInvisibleId(12);
  PHYSICS->mcConfig().AddInvisibleId(14);
  PHYSICS->mcConfig().AddInvisibleId(16);
  PHYSICS->mcConfig().AddInvisibleId(1000022);

  // ===== Signal region ===== //
  Manager()->AddRegionSelection("myregion");

  // ===== Selections ===== //

  // ===== Histograms ===== //
  //rec
  Manager()->AddHisto("NJets", 20, 0, 20);
  Manager()->AddHisto("NbJets", 10, 0, 10);
  Manager()->AddHisto("Nleps", 10, 0, 10);
  Manager()->AddHisto("PTJets", 100, 0, 2000);
  Manager()->AddHisto("PTLeps", 100, 0, 1500);

  Manager()->AddHisto("MT2", 100, 0, 1500);
  Manager()->AddHisto("MT_lmet", 100, 0, 1500);
  Manager()->AddHisto("Mlb", 100, 0, 1500);

  Manager()->AddHisto("MET", 100, 0, 2000);
  Manager()->AddHisto("MHT", 100, 0, 2000);
  Manager()->AddHisto("ET", 100, 0, 4000);
  Manager()->AddHisto("HT",100, 0, 4000);
 
  //bbbar pair + ll pair 
  Manager()->AddHisto("bbbar_invM", 100, 0, 1000);
  Manager()->AddHisto("bbbar_invM_H", 35, 90, 160);
  Manager()->AddHisto("Nbpairs_H", 10, 0, 10);
  Manager()->AddHisto("bbbar_invM_H_1", 35, 90, 160);

  Manager()->AddHisto("llpair_invM", 100, 0, 1000);
  Manager()->AddHisto("llpair_invM_Z", 35, 55, 125);
  Manager()->AddHisto("Nllpairs_Z", 10, 0, 10);
  Manager()->AddHisto("llpair_invM_Z_1", 35, 55, 125);


  //bb (H) + ll (Z) + lep + NJ>=2 + NbJ>=1
  Manager()->AddHisto("MET_", 100, 0, 2000);
  Manager()->AddHisto("MT_", 100, 0, 1500);
  Manager()->AddHisto("NJets_", 20, 0, 20);
  Manager()->AddHisto("NbJets_", 10, 0, 10);



  cout << "END   Initialization" << endl;
  return true;
}

// -----------------------------------------------------------------------------
// Finalize
// function called one time at the end of the analysis
// -----------------------------------------------------------------------------
void stop_topN2_HZ_ana::Finalize(const SampleFormat& summary, const std::vector<SampleFormat>& files)
{
  cout << "BEGIN Finalization" << endl;
  // saving histos
  cout << "END   Finalization" << endl;
}

// -----------------------------------------------------------------------------
// Execute
// function called each time one event is read
// -----------------------------------------------------------------------------
bool stop_topN2_HZ_ana::Execute(SampleFormat& sample, const EventFormat& event)
{
  // ***************************************************************************
  // Example of analysis with generated particles
  // Concerned samples : LHE/STDHEP/HEPMC
  // ***************************************************************************
  /*
  if (event.mc()!=0)
  {
    cout << "---------------NEW EVENT-------------------" << endl;

    // Event weight
    double myWeight=1.;
    if (!Configuration().IsNoEventWeight()) myWeight=event.mc()->weight();

    // Initial state
    for (MAuint32 i=0;i<event.mc()->particles().size();i++)
    {
      const MCParticleFormat& part = event.mc()->particles()[i];

      cout << "----------------------------------" << endl;
      cout << "MC particle" << endl;
      cout << "----------------------------------" << endl;

      // display index particle
      cout << "index=" << i+1;

      // display the status code
      cout << "Status Code=" << part.statuscode() << endl;
      if (PHYSICS->Id->IsInitialState(part)) cout << " (Initial state) ";
      else if (PHYSICS->Id->IsFinalState(part)) cout << " (Final state) ";
      else cout << " (Intermediate state) ";
      cout << endl;

      // pdgid
      cout << "pdg id=" << part.pdgid() << endl;
      if (PHYSICS->Id->IsInvisible(part)) cout << " (invisible particle) ";
      else cout << " (visible particle) ";
      cout << endl;

      // display kinematics information
      cout << "px=" << part.px()
                << " py=" << part.py()
                << " pz=" << part.pz()
                << " e="  << part.e()
                << " m="  << part.m() << endl;
      cout << "pt=" << part.pt() 
                << " eta=" << part.eta() 
                << " phi=" << part.phi() << endl;

      // display particle mother id
      if (part.mothers().empty()) 
      {
        cout << "particle with no mother." << endl;
      }
      else
      {
        std::cout << "particle coming from the decay of";
        for(MAuint32 j=0;j<part.mothers().size();j++)
        {
          const MCParticleFormat* mother = part.mothers()[j];
          cout << " " << mother->pdgid();
        }
        std::cout << "." << endl;
      }
    }

    // Transverse missing energy (MET)
    cout << "MET pt=" << event.mc()->MET().pt()
         << " phi=" << event.mc()->MET().phi() << endl;
    cout << endl;

    // Transverse missing hadronic energy (MHT)
    cout << "MHT pt=" << event.mc()->MHT().pt()
              << " phi=" << event.mc()->MHT().phi() << endl;
    cout << endl;

    // Total transverse energy (TET)
    cout << "TET=" << event.mc()->TET() << endl;
    cout << endl;

    // Total transverse hadronic energy (THT)
    cout << "THT=" << event.mc()->THT() << endl; 
   cout << endl;

  return true;
  }
  */


  // ***************************************************************************
  // Example of analysis with reconstructed objects
  // Concerned samples : 
  //   - LHCO samples
  //   - LHE/STDHEP/HEPMC samples after applying jet-clustering algorithm
  // ***************************************************************************
  
  // Event weight
  double myWeight=1.;
  if (!Configuration().IsNoEventWeight() && event.mc()!=0) myWeight=1.0 /*0.0476*150*0.1*/;

  Manager()->InitializeForNewEvent(myWeight);

  if (event.rec()!=0)
  {
    //cout << "---------------NEW EVENT-------------------" << endl;

    const MALorentzVector& MET = event.rec()->MET().momentum();

    vector<const RecLeptonFormat*> reco_leps;
    // Looking through the reconstructed electron collection
    for (MAuint32 i=0;i<event.rec()->electrons().size();i++)
    {
      const RecLeptonFormat& elec = event.rec()->electrons()[i];
      Manager()->FillHisto("MT_lmet", elec.mt_met(MET));
      reco_leps.push_back(&elec);
      Manager()->FillHisto("PTLeps", elec.pt());
    }

    // Looking through the reconstructed muon collection
    for (MAuint32 i=0;i<event.rec()->muons().size();i++)
    {
      const RecLeptonFormat& mu = event.rec()->muons()[i];
      Manager()->FillHisto("MT_lmet", mu.mt_met(MET));
      reco_leps.push_back(&mu);
      Manager()->FillHisto("PTLeps", mu.pt());
    }

    int Nleps = reco_leps.size();
    Manager()->FillHisto("Nleps", Nleps);

    // Looking through the reconstructed hadronic tau collection
    /*for (MAuint32 i=0;i<event.rec()->taus().size();i++)
    {
      const RecTauFormat& tau = event.rec()->taus()[i];
    }*/

    vector<const RecJetFormat*> reco_jets;
    vector<const RecJetFormat*> reco_bjets;
    // Looking through the reconstructed jet collection
    for (MAuint32 i=0;i<event.rec()->jets().size();i++)
    {
      const RecJetFormat& jet = event.rec()->jets()[i];
      reco_jets.push_back(&jet);
      Manager()->FillHisto("PTJets", jet.pt());   
      //b-jet
      if(jet.btag()){reco_bjets.push_back(&jet);}

    }

    SORTER->sort(reco_jets, PTordering);
    SORTER->sort(reco_bjets, PTordering);
    SORTER->sort(reco_leps, PTordering);

    //jets
    int Njets = reco_jets.size();
    int Nbjets = reco_bjets.size();
    Manager()->FillHisto("NbJets", Nbjets);
    Manager()->FillHisto("NJets", Njets);

    //MT
    /*if(reco_leps.size()>0){
      Manager()->FillHisto("MT_lmet", reco_leps[0]->mt_met(MET));
    }*/
    //MT2
    if(reco_jets.size() >= 2){
      MALorentzVector p111 = event.rec()->jets()[0].momentum();
      MALorentzVector p222 = event.rec()->jets()[1].momentum();
      ParticleBaseFormat p11=ParticleBaseFormat(p111);
      ParticleBaseFormat p22=ParticleBaseFormat(p222);
      const ParticleBaseFormat *p1= &(p11);
      const ParticleBaseFormat *p2= &(p22);
      Manager()->FillHisto("MT2", PHYSICS->Transverse->MT2(p1, p2, event.rec()->MET(), 0.));
      //dR_jj
      //float dR_jj = event.rec()->jets()[0].dr(p22);
      //Manager()->FillHisto("dR_jj_MT2", dR_jj);
    }


    //Mlb
    if(reco_leps.size()>0 && reco_bjets.size()>0){
      const ParticleBaseFormat* p_b0 = reco_bjets[0];
      float dR_min = reco_leps[0]->dr(p_b0);
      unsigned int index = 0;
      for(unsigned int i=1; i<reco_bjets.size(); i++){
        const ParticleBaseFormat* p_b = reco_bjets[i];
        float dR = reco_leps[0]->dr(p_b);
        //Manager()->FillHisto("dR_l_bs", dR);
        if(dR<dR_min){
          dR_min = dR;
          index = i;
        }
      }
      float Mlb = (reco_leps[0]->momentum() + reco_bjets[index]->momentum()).M();
      Manager()->FillHisto("Mlb", Mlb);
    }


    //MET
    Manager()->FillHisto("MET", event.rec()->MET().pt());
    Manager()->FillHisto("MHT", event.rec()->MHT().pt());
    Manager()->FillHisto("ET", event.rec()->TET());
    Manager()->FillHisto("HT", event.rec()->THT());

//-------------------------------------------------------------------------------------------//

    //bbbar pair
    MAuint32 Npair=0;
    if(reco_bjets.size()>1){
      MAuint32 m=0;
      MAuint32 N = reco_bjets.size();
      MAuint32 M = (N*(N-1))/(2);
      float bbbar_Mass[M];
      for(MAuint32 k=0; k<reco_bjets.size(); k++){
        for(MAuint32 l=k+1; l<reco_bjets.size(); l++){
          bbbar_Mass[m] = (reco_bjets[k]->momentum() + reco_bjets[l]->momentum()).M();
          m = m+1;
        }
      }

      
      for(MAuint32 j=0; j<M; j++){
        Manager()->FillHisto("bbbar_invM", bbbar_Mass[j]);
        if(bbbar_Mass[j]>100 && bbbar_Mass[j]<150){
          Manager()->FillHisto("bbbar_invM_H", bbbar_Mass[j]);
          Npair=Npair+1;
        }
      }
      Manager()->FillHisto("Nbpairs_H", Npair);

      //array of mass of bb (H)
      float bbbar_invM_H[Npair]; int o=0; 
      for(MAuint32 s=0; s<M; s++){
        if(bbbar_Mass[s]>100 && bbbar_Mass[s]<150){
          bbbar_invM_H[o] = bbbar_Mass[s];
          o=o+1;
        }
      }
      //plot the one closest to H
      if(Npair>0){
        float Mass = bbbar_invM_H[0];
        for(MAuint32 t=1; t<Npair; t++){
          if( fabs(bbbar_invM_H[t]-125.) < fabs(Mass-125.) ){
            Mass = bbbar_invM_H[t];
          }
        }
        Manager()->FillHisto("bbbar_invM_H_1", Mass);
      }

    }

//-------------------------------------------------------------------------------------------//

    //ll pair
    MAuint32 Npair_ll=0;
    if(reco_leps.size()>1){
      MAuint32 p=0;
      MAuint32 P = reco_leps.size();
      MAuint32 Q = (P*(P-1))/(2);
      float llpair_Mass[Q];
      for(MAuint32 k1=0; k1<reco_leps.size(); k1++){
        for(MAuint32 l1=k1+1; l1<reco_leps.size(); l1++){
          llpair_Mass[p] = (reco_leps[k1]->momentum() + reco_leps[l1]->momentum()).M();
          p = p+1;
        }
      }

      
      for(MAuint32 j1=0; j1<Q; j1++){
        Manager()->FillHisto("llpair_invM", llpair_Mass[j1]);
        if(llpair_Mass[j1]>65 && llpair_Mass[j1]<115){
          Manager()->FillHisto("llpair_invM_Z", llpair_Mass[j1]);
          Npair_ll=Npair_ll+1;
        }
      }
      Manager()->FillHisto("Nllpairs_Z", Npair_ll);

      //array of mass of ll (Z)
      float llpair_invM_Z[Npair_ll]; int h=0; 
      for(MAuint32 r=0; r<Q; r++){
        if(llpair_Mass[r]>65 && llpair_Mass[r]<115){
          llpair_invM_Z[h] = llpair_Mass[r];
          h=h+1;
        }
      }
      //plot the one closest to Z
      if(Npair_ll>0){
        float Mass1 = llpair_invM_Z[0];
        for(MAuint32 t1=1; t1<Npair_ll; t1++){
          if( fabs(llpair_invM_Z[t1]-91.) < fabs(Mass1-91.) ){
            Mass1 = llpair_invM_Z[t1];
          }
        }
        Manager()->FillHisto("llpair_invM_Z_1", Mass1);
      }

    }

//-------------------------------------------------------------------------------------------//

    //bb (H) + ll (Z) + lep + met + NJ>=2 + NbJ>=1

    if(Npair>0 && Npair_ll>0 && reco_leps.size()>=3 && reco_jets.size()>=2 && reco_bjets.size()>=3){
      Manager()->FillHisto("MET_",event.rec()->MET().pt());
      Manager()->FillHisto("NJets_", reco_jets.size());
      Manager()->FillHisto("NbJets_", reco_bjets.size());
      for(MAuint32 z=0; z< reco_leps.size(); z++){
        Manager()->FillHisto("MT_", reco_leps[z]->mt_met(MET));
      }
    }



  }
  
  return true;
}

