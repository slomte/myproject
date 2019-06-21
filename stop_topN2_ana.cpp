#include "SampleAnalyzer/User/Analyzer/stop_topN2_ana.h"
using namespace MA5;
using namespace std;

// -----------------------------------------------------------------------------
// Initialize
// function called one time at the beginning of the analysis
// -----------------------------------------------------------------------------
bool stop_topN2_ana::Initialize(const MA5::Configuration& cfg, const std::map<std::string,std::string>& parameters)
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
  
  //single lep
  Manager()->AddHisto("NJets_1levt", 20, 0, 20);
  Manager()->AddHisto("NbJets_1levt", 10, 0, 10);
  Manager()->AddHisto("MT2_1levt", 100, 0, 1500);
  Manager()->AddHisto("MT_lmet_1levt", 100, 0, 1500);
  Manager()->AddHisto("Mlb_1levt", 100, 0, 1500);
  Manager()->AddHisto("MET_1levt", 100, 0, 2000);
  Manager()->AddHisto("MHT_1levt", 100, 0, 2000);
  Manager()->AddHisto("ET_1levt", 100, 0, 4000);
  Manager()->AddHisto("HT_1levt",100, 0, 4000);

  //single lep and mt>100
  Manager()->AddHisto("NJets_1levtmt100", 20, 0, 20);
  Manager()->AddHisto("NbJets_1levtmt100", 10, 0, 10);
  Manager()->AddHisto("MT2_1levtmt100", 100, 0, 1500);
  Manager()->AddHisto("MT_lmet_1levtmt100", 100, 0, 1500);
  Manager()->AddHisto("Mlb_1levtmt100", 100, 0, 1500);
  Manager()->AddHisto("MET_1levtmt100", 100, 0, 2000);
  Manager()->AddHisto("MHT_1levtmt100", 100, 0, 2000);
  Manager()->AddHisto("ET_1levtmt100", 100, 0, 4000);
  Manager()->AddHisto("HT_1levtmt100",100, 0, 4000);
  
  //single lep and met>100
  Manager()->AddHisto("NJets_1levtmet100", 20, 0, 20);
  Manager()->AddHisto("NbJets_1levtmet100", 10, 0, 10);
  Manager()->AddHisto("MT2_1levtmet100", 100, 0, 1500);
  Manager()->AddHisto("MT_lmet_1levtmet100", 100, 0, 1500);
  Manager()->AddHisto("Mlb_1levtmet100", 100, 0, 1500);
  Manager()->AddHisto("MET_1levtmet100", 100, 0, 2000);
  Manager()->AddHisto("MHT_1levtmet100", 100, 0, 2000);
  Manager()->AddHisto("ET_1levtmet100", 100, 0, 4000);
  Manager()->AddHisto("HT_1levtmet100",100, 0, 4000);

  //single lep and met>100 and mt>100
  Manager()->AddHisto("NJets_1levtmet100mt100", 20, 0, 20);
  Manager()->AddHisto("NbJets_1levtmet100mt100", 10, 0, 10);
  Manager()->AddHisto("MT2_1levtmet100mt100", 100, 0, 1500);
  Manager()->AddHisto("MT_lmet_1levtmet100mt100", 100, 0, 1500);
  Manager()->AddHisto("Mlb_1levtmet100mt100", 100, 0, 1500);
  Manager()->AddHisto("MET_1levtmet100mt100", 100, 0, 2000);
  Manager()->AddHisto("MHT_1levtmet100mt100", 100, 0, 2000);
  Manager()->AddHisto("ET_1levtmet100mt100", 100, 0, 4000);
  Manager()->AddHisto("HT_1levtmet100mt100",100, 0, 4000);

  //single lep and met>100 and mt>100 and bjet>0
  Manager()->AddHisto("NJets_1levtmet100mt100bjet", 20, 0, 20);
  Manager()->AddHisto("NbJets_1levtmet100mt100bjet", 10, 0, 10);
  Manager()->AddHisto("MT2_1levtmet100mt100bjet", 100, 0, 1500);
  Manager()->AddHisto("MT_lmet_1levtmet100mt100bjet", 100, 0, 1500);
  Manager()->AddHisto("Mlb_1levtmet100mt100bjet", 100, 0, 1500);
  Manager()->AddHisto("MET_1levtmet100mt100bjet", 100, 0, 2000);
  Manager()->AddHisto("MHT_1levtmet100mt100bjet", 100, 0, 2000);
  Manager()->AddHisto("ET_1levtmet100mt100bjet", 100, 0, 4000);
  Manager()->AddHisto("HT_1levtmet100mt100bjet",100, 0, 4000);

  //Binning in MET and MT (in addition to _1levtmet100mt100 cuts)
  Manager()->AddHisto("MET_NJ_0_4_NbJ_0", 100, 0, 2000);
  Manager()->AddHisto("MET_NJ_5_9_NbJ_0", 100, 0, 2000);
  Manager()->AddHisto("MET_NJ_10_14_NbJ_0", 100, 0, 2000);
  Manager()->AddHisto("MET_NJ_15_inf_NbJ_0", 100, 0, 2000);
  Manager()->AddHisto("MET_NJ_0_4_NbJ_1", 100, 0, 2000);
  Manager()->AddHisto("MET_NJ_5_9_NbJ_1", 100, 0, 2000);
  Manager()->AddHisto("MET_NJ_10_14_NbJ_1", 100, 0, 2000);
  Manager()->AddHisto("MET_NJ_15_inf_NbJ_1", 100, 0, 2000);
  Manager()->AddHisto("MET_NJ_0_4_NbJ_2onw", 100, 0, 2000);
  Manager()->AddHisto("MET_NJ_5_9_NbJ_2onw", 100, 0, 2000);
  Manager()->AddHisto("MET_NJ_10_14_NbJ_2onw", 100, 0, 2000);
  Manager()->AddHisto("MET_NJ_15_inf_NbJ_2onw", 100, 0, 2000);

  Manager()->AddHisto("MT_NJ_0_4_NbJ_0", 100, 0, 1500);
  Manager()->AddHisto("MT_NJ_5_9_NbJ_0", 100, 0, 1500);
  Manager()->AddHisto("MT_NJ_10_14_NbJ_0", 100, 0, 1500);
  Manager()->AddHisto("MT_NJ_15_inf_NbJ_0", 100, 0, 1500);
  Manager()->AddHisto("MT_NJ_0_4_NbJ_1", 100, 0, 1500);
  Manager()->AddHisto("MT_NJ_5_9_NbJ_1", 100, 0, 1500);
  Manager()->AddHisto("MT_NJ_10_14_NbJ_1", 100, 0, 1500);
  Manager()->AddHisto("MT_NJ_15_inf_NbJ_1", 100, 0, 1500);
  Manager()->AddHisto("MT_NJ_0_4_NbJ_2onw", 100, 0, 1500);
  Manager()->AddHisto("MT_NJ_5_9_NbJ_2onw", 100, 0, 1500);
  Manager()->AddHisto("MT_NJ_10_14_NbJ_2onw", 100, 0, 1500);
  Manager()->AddHisto("MT_NJ_15_inf_NbJ_2onw", 100, 0, 1500);



  cout << "END   Initialization" << endl;
  return true;
}

// -----------------------------------------------------------------------------
// Finalize
// function called one time at the end of the analysis
// -----------------------------------------------------------------------------
void stop_topN2_ana::Finalize(const SampleFormat& summary, const std::vector<SampleFormat>& files)
{
  cout << "BEGIN Finalization" << endl;
  // saving histos
  cout << "END   Finalization" << endl;
}

// -----------------------------------------------------------------------------
// Execute
// function called each time one event is read
// -----------------------------------------------------------------------------
bool stop_topN2_ana::Execute(SampleFormat& sample, const EventFormat& event)
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
  if (!Configuration().IsNoEventWeight() && event.mc()!=0) myWeight=87.31*150*0.0005;

  //modified**
  //myWeight=0.0476*150*0.1 for signal stop 1TeV
  //myWeight=364.36*150*0.0005 for ttbar_1lep 
  //myWeight=87.31*150* for ttbar_2lep 
  Manager()->InitializeForNewEvent(myWeight);

  //const RecEventFormat* Event = event.rec();

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

    }//jets

    SORTER->sort(reco_jets, PTordering);
    SORTER->sort(reco_bjets, PTordering);
    SORTER->sort(reco_leps, PTordering);

    //jets
    int Njets = reco_jets.size();
    int Nbjets = reco_bjets.size();
    Manager()->FillHisto("NbJets", Nbjets);
    Manager()->FillHisto("NJets", Njets);

    //MT
    if(reco_leps.size()>0){
      Manager()->FillHisto("MT_lmet", reco_leps[0]->mt_met(MET));
    }
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


    //--------------------------//-------------------------//
    //Single lep events
    if(reco_leps.size()==1){
      //jets
      int Njets = reco_jets.size();
      int Nbjets = reco_bjets.size();
      Manager()->FillHisto("NbJets_1levt", Nbjets);
      Manager()->FillHisto("NJets_1levt", Njets);
    }
    //MT
    if(reco_leps.size()==1){
      Manager()->FillHisto("MT_lmet_1levt", reco_leps[0]->mt_met(MET));
    }
    //MT2
    if(reco_jets.size() >= 2 && reco_leps.size()==1){
      MALorentzVector p111 = event.rec()->jets()[0].momentum();
      MALorentzVector p222 = event.rec()->jets()[1].momentum();
      ParticleBaseFormat p11=ParticleBaseFormat(p111);
      ParticleBaseFormat p22=ParticleBaseFormat(p222);
      const ParticleBaseFormat *p1= &(p11);
      const ParticleBaseFormat *p2= &(p22);
      Manager()->FillHisto("MT2_1levt", PHYSICS->Transverse->MT2(p1, p2, event.rec()->MET(), 0.));
    }
    //Mlb
    if(reco_leps.size()==1 && reco_bjets.size()>0){
      const ParticleBaseFormat* p_b0 = reco_bjets[0];
      float dR_min = reco_leps[0]->dr(p_b0);
      unsigned int index = 0;
      for(unsigned int i=1; i<reco_bjets.size(); i++){
        const ParticleBaseFormat* p_b = reco_bjets[i];
        float dR = reco_leps[0]->dr(p_b);
        if(dR<dR_min){
          dR_min = dR;
          index = i;
        }
      }
      float Mlb = (reco_leps[0]->momentum() + reco_bjets[index]->momentum()).M();
      Manager()->FillHisto("Mlb_1levt", Mlb);
    }
    //MET
    if(reco_leps.size()==1){
      Manager()->FillHisto("MET_1levt", event.rec()->MET().pt());
      Manager()->FillHisto("MHT_1levt", event.rec()->MHT().pt());
      Manager()->FillHisto("ET_1levt", event.rec()->TET());
      Manager()->FillHisto("HT_1levt", event.rec()->THT());
    }
    //--------------------------//-------------------------//
    //Single lep evt and MT>100
    if(reco_leps.size()==1 && reco_leps[0]->mt_met(MET)>100){
      //jets
      int Njets = reco_jets.size();
      int Nbjets = reco_bjets.size();
      Manager()->FillHisto("NbJets_1levtmt100", Nbjets);
      Manager()->FillHisto("NJets_1levtmt100", Njets);
    }
    //MT
    if(reco_leps.size()==1 && reco_leps[0]->mt_met(MET)>100){
      Manager()->FillHisto("MT_lmet_1levtmt100", reco_leps[0]->mt_met(MET));
    }
    //MT2
    if(reco_jets.size() >= 2 && reco_leps.size()==1 && reco_leps[0]->mt_met(MET)>100){
      MALorentzVector p111 = event.rec()->jets()[0].momentum();
      MALorentzVector p222 = event.rec()->jets()[1].momentum();
      ParticleBaseFormat p11=ParticleBaseFormat(p111);
      ParticleBaseFormat p22=ParticleBaseFormat(p222);
      const ParticleBaseFormat *p1= &(p11);
      const ParticleBaseFormat *p2= &(p22);
      Manager()->FillHisto("MT2_1levtmt100", PHYSICS->Transverse->MT2(p1, p2, event.rec()->MET(), 0.));
    }
    //Mlb
    if(reco_leps.size()==1 && reco_bjets.size()>0 && reco_leps[0]->mt_met(MET)>100){
      const ParticleBaseFormat* p_b0 = reco_bjets[0];
      float dR_min = reco_leps[0]->dr(p_b0);
      unsigned int index = 0;
      for(unsigned int i=1; i<reco_bjets.size(); i++){
        const ParticleBaseFormat* p_b = reco_bjets[i];
        float dR = reco_leps[0]->dr(p_b);
        if(dR<dR_min){
          dR_min = dR;
          index = i;
        }
      }
      float Mlb = (reco_leps[0]->momentum() + reco_bjets[index]->momentum()).M();
      Manager()->FillHisto("Mlb_1levtmt100", Mlb);
    }
    //MET
    if(reco_leps.size()==1 && reco_leps[0]->mt_met(MET)>100){
      Manager()->FillHisto("MET_1levtmt100", event.rec()->MET().pt());
      Manager()->FillHisto("MHT_1levtmt100", event.rec()->MHT().pt());
      Manager()->FillHisto("ET_1levtmt100", event.rec()->TET());
      Manager()->FillHisto("HT_1levtmt100", event.rec()->THT());
    }
    //--------------------------//-------------------------//
    //Single lep evt and met>100
    if(reco_leps.size()==1 && event.rec()->MET().pt()>100){
      //jets
      int Njets = reco_jets.size();
      int Nbjets = reco_bjets.size();
      Manager()->FillHisto("NbJets_1levtmet100", Nbjets);
      Manager()->FillHisto("NJets_1levtmet100", Njets);
    }
    //MT
    if(reco_leps.size()==1 && event.rec()->MET().pt()>100){
      Manager()->FillHisto("MT_lmet_1levtmet100", reco_leps[0]->mt_met(MET));
    }
    //MT2
    if(reco_jets.size() >= 2 && reco_leps.size()==1 && event.rec()->MET().pt()>100){
      MALorentzVector p111 = event.rec()->jets()[0].momentum();
      MALorentzVector p222 = event.rec()->jets()[1].momentum();
      ParticleBaseFormat p11=ParticleBaseFormat(p111);
      ParticleBaseFormat p22=ParticleBaseFormat(p222);
      const ParticleBaseFormat *p1= &(p11);
      const ParticleBaseFormat *p2= &(p22);
      Manager()->FillHisto("MT2_1levtmet100", PHYSICS->Transverse->MT2(p1, p2, event.rec()->MET(), 0.));
    }
    //Mlb
    if(reco_leps.size()==1 && reco_bjets.size()>0 && event.rec()->MET().pt()>100){
      const ParticleBaseFormat* p_b0 = reco_bjets[0];
      float dR_min = reco_leps[0]->dr(p_b0);
      unsigned int index = 0;
      for(unsigned int i=1; i<reco_bjets.size(); i++){
        const ParticleBaseFormat* p_b = reco_bjets[i];
        float dR = reco_leps[0]->dr(p_b);
        if(dR<dR_min){
          dR_min = dR;
          index = i;
        }
      }
      float Mlb = (reco_leps[0]->momentum() + reco_bjets[index]->momentum()).M();
      Manager()->FillHisto("Mlb_1levtmet100", Mlb);
    }
    //MET
    if(reco_leps.size()==1 && event.rec()->MET().pt()>100){
      Manager()->FillHisto("MET_1levtmet100", event.rec()->MET().pt());
      Manager()->FillHisto("MHT_1levtmet100", event.rec()->MHT().pt());
      Manager()->FillHisto("ET_1levtmet100", event.rec()->TET());
      Manager()->FillHisto("HT_1levtmet100", event.rec()->THT());
    }
    //--------------------------//-------------------------//
    //Single lep evt and met>100 and mt>100
    if(reco_leps.size()==1 && event.rec()->MET().pt()>100 && reco_leps[0]->mt_met(MET)>100){
      //jets
      int Njets = reco_jets.size();
      int Nbjets = reco_bjets.size();
      Manager()->FillHisto("NbJets_1levtmet100mt100", Nbjets);
      Manager()->FillHisto("NJets_1levtmet100mt100", Njets);
    }
    //MT
    if(reco_leps.size()==1 && event.rec()->MET().pt()>100 && reco_leps[0]->mt_met(MET)>100){
      Manager()->FillHisto("MT_lmet_1levtmet100mt100", reco_leps[0]->mt_met(MET));
    }
    //MT2
    if(reco_jets.size() >= 2 && reco_leps.size()==1 && event.rec()->MET().pt()>100 && reco_leps[0]->mt_met(MET)>100){
      MALorentzVector p111 = event.rec()->jets()[0].momentum();
      MALorentzVector p222 = event.rec()->jets()[1].momentum();
      ParticleBaseFormat p11=ParticleBaseFormat(p111);
      ParticleBaseFormat p22=ParticleBaseFormat(p222);
      const ParticleBaseFormat *p1= &(p11);
      const ParticleBaseFormat *p2= &(p22);
      Manager()->FillHisto("MT2_1levtmet100mt100", PHYSICS->Transverse->MT2(p1, p2, event.rec()->MET(), 0.));
    }
    //Mlb
    if(reco_leps.size()==1 && reco_bjets.size()>0 && event.rec()->MET().pt()>100 && reco_leps[0]->mt_met(MET)>100){
      const ParticleBaseFormat* p_b0 = reco_bjets[0];
      float dR_min = reco_leps[0]->dr(p_b0);
      unsigned int index = 0;
      for(unsigned int i=1; i<reco_bjets.size(); i++){
        const ParticleBaseFormat* p_b = reco_bjets[i];
        float dR = reco_leps[0]->dr(p_b);
        if(dR<dR_min){
          dR_min = dR;
          index = i;
        }
      }
      float Mlb = (reco_leps[0]->momentum() + reco_bjets[index]->momentum()).M();
      Manager()->FillHisto("Mlb_1levtmet100mt100", Mlb);
    }
    //MET
    if(reco_leps.size()==1 && event.rec()->MET().pt()>100 && reco_leps[0]->mt_met(MET)>100){
      Manager()->FillHisto("MET_1levtmet100mt100", event.rec()->MET().pt());
      Manager()->FillHisto("MHT_1levtmet100mt100", event.rec()->MHT().pt());
      Manager()->FillHisto("ET_1levtmet100mt100", event.rec()->TET());
      Manager()->FillHisto("HT_1levtmet100mt100", event.rec()->THT());
    }
    //--------------------------//-------------------------//

    //Single lep evt and met>100 and mt>100 and Nbjet>0
    if(reco_leps.size()==1 && event.rec()->MET().pt()>100 && reco_leps[0]->mt_met(MET)>100 && reco_bjets.size()>0){
      //jets
      int Njets = reco_jets.size();
      int Nbjets = reco_bjets.size();
      Manager()->FillHisto("NbJets_1levtmet100mt100bjet", Nbjets);
      Manager()->FillHisto("NJets_1levtmet100mt100bjet", Njets);
    }
    //MT
    if(reco_leps.size()==1 && event.rec()->MET().pt()>100 && reco_leps[0]->mt_met(MET)>100 && reco_bjets.size()>0){
      Manager()->FillHisto("MT_lmet_1levtmet100mt100bjet", reco_leps[0]->mt_met(MET));
    }
    //MT2
    if(reco_jets.size() >= 2 && reco_leps.size()==1 && event.rec()->MET().pt()>100 && reco_leps[0]->mt_met(MET)>100 && reco_bjets.size()>0){
      MALorentzVector p111 = event.rec()->jets()[0].momentum();
      MALorentzVector p222 = event.rec()->jets()[1].momentum();
      ParticleBaseFormat p11=ParticleBaseFormat(p111);
      ParticleBaseFormat p22=ParticleBaseFormat(p222);
      const ParticleBaseFormat *p1= &(p11);
      const ParticleBaseFormat *p2= &(p22);
      Manager()->FillHisto("MT2_1levtmet100mt100bjet", PHYSICS->Transverse->MT2(p1, p2, event.rec()->MET(), 0.));
    }
    //Mlb
    if(reco_leps.size()==1 && reco_bjets.size()>0 && event.rec()->MET().pt()>100 && reco_leps[0]->mt_met(MET)>100 && reco_bjets.size()>0){
      const ParticleBaseFormat* p_b0 = reco_bjets[0];
      float dR_min = reco_leps[0]->dr(p_b0);
      unsigned int index = 0;
      for(unsigned int i=1; i<reco_bjets.size(); i++){
        const ParticleBaseFormat* p_b = reco_bjets[i];
        float dR = reco_leps[0]->dr(p_b);
        if(dR<dR_min){
          dR_min = dR;
          index = i;
        }
      }
      float Mlb = (reco_leps[0]->momentum() + reco_bjets[index]->momentum()).M();
      Manager()->FillHisto("Mlb_1levtmet100mt100bjet", Mlb);
    }
    //MET
    if(reco_leps.size()==1 && event.rec()->MET().pt()>100 && reco_leps[0]->mt_met(MET)>100 && reco_bjets.size()>0){
      Manager()->FillHisto("MET_1levtmet100mt100bjet", event.rec()->MET().pt());
      Manager()->FillHisto("MHT_1levtmet100mt100bjet", event.rec()->MHT().pt());
      Manager()->FillHisto("ET_1levtmet100mt100bjet", event.rec()->TET());
      Manager()->FillHisto("HT_1levtmet100mt100bjet", event.rec()->THT());
    }
    //--------------------------//-------------------------//
    //Binning and Optimisation

    //single lep, mt>100, met>100
    


    //MET
    if(reco_leps.size()==1 && event.rec()->MET().pt()>100 && reco_leps[0]->mt_met(MET)>100){
      //bj=0
      if(reco_bjets.size()==0){
        if(reco_jets.size()<5){Manager()->FillHisto("MET_NJ_0_4_NbJ_0", event.rec()->MET().pt());}
        if(reco_jets.size()>4 && reco_jets.size()<10){Manager()->FillHisto("MET_NJ_5_9_NbJ_0", event.rec()->MET().pt());}
        if(reco_jets.size()>9 && reco_jets.size()<15){Manager()->FillHisto("MET_NJ_10_14_NbJ_0", event.rec()->MET().pt());}
        if(reco_jets.size()>14 ){Manager()->FillHisto("MET_NJ_15_inf_NbJ_0", event.rec()->MET().pt());}
      }//bj=0
      //bj=1
      if(reco_bjets.size()==1){
        if(reco_jets.size()<5){Manager()->FillHisto("MET_NJ_0_4_NbJ_1", event.rec()->MET().pt());}
        if(reco_jets.size()>4 && reco_jets.size()<10){Manager()->FillHisto("MET_NJ_5_9_NbJ_1", event.rec()->MET().pt());}
        if(reco_jets.size()>9 && reco_jets.size()<15){Manager()->FillHisto("MET_NJ_10_14_NbJ_1", event.rec()->MET().pt());}
        if(reco_jets.size()>14 ){Manager()->FillHisto("MET_NJ_15_inf_NbJ_1", event.rec()->MET().pt());}
      }//bj=1
      //bj>=2
      if(reco_bjets.size()>=2){
        if(reco_jets.size()<5){Manager()->FillHisto("MET_NJ_0_4_NbJ_2onw", event.rec()->MET().pt());}
        if(reco_jets.size()>4 && reco_jets.size()<10){Manager()->FillHisto("MET_NJ_5_9_NbJ_2onw", event.rec()->MET().pt());}
        if(reco_jets.size()>9 && reco_jets.size()<15){Manager()->FillHisto("MET_NJ_10_14_NbJ_2onw", event.rec()->MET().pt());}
        if(reco_jets.size()>14 ){Manager()->FillHisto("MET_NJ_15_inf_NbJ_2onw", event.rec()->MET().pt());}
      }//bj>=2
    }//MET


    //MT
    if(reco_leps.size()==1 && event.rec()->MET().pt()>100 && reco_leps[0]->mt_met(MET)>100){
      //bj=0
      if(reco_bjets.size()==0){
        if(reco_jets.size()<5){Manager()->FillHisto("MT_NJ_0_4_NbJ_0", reco_leps[0]->mt_met(MET));}
        if(reco_jets.size()>4 && reco_jets.size()<10){Manager()->FillHisto("MT_NJ_5_9_NbJ_0", reco_leps[0]->mt_met(MET));}
        if(reco_jets.size()>9 && reco_jets.size()<15){Manager()->FillHisto("MT_NJ_10_14_NbJ_0", reco_leps[0]->mt_met(MET));}
        if(reco_jets.size()>14 ){Manager()->FillHisto("MT_NJ_15_inf_NbJ_0", reco_leps[0]->mt_met(MET));}
      }//bj=0
      //bj=1
      if(reco_bjets.size()==1){
        if(reco_jets.size()<5){Manager()->FillHisto("MT_NJ_0_4_NbJ_1", reco_leps[0]->mt_met(MET));}
        if(reco_jets.size()>4 && reco_jets.size()<10){Manager()->FillHisto("MT_NJ_5_9_NbJ_1", reco_leps[0]->mt_met(MET));}
        if(reco_jets.size()>9 && reco_jets.size()<15){Manager()->FillHisto("MT_NJ_10_14_NbJ_1", reco_leps[0]->mt_met(MET));}
        if(reco_jets.size()>14 ){Manager()->FillHisto("MT_NJ_15_inf_NbJ_1", reco_leps[0]->mt_met(MET));}
      }//bj=1
      //bj>=2
      if(reco_bjets.size()>=2){
        if(reco_jets.size()<5){Manager()->FillHisto("MT_NJ_0_4_NbJ_2onw", reco_leps[0]->mt_met(MET));}
        if(reco_jets.size()>4 && reco_jets.size()<10){Manager()->FillHisto("MT_NJ_5_9_NbJ_2onw", reco_leps[0]->mt_met(MET));}
        if(reco_jets.size()>9 && reco_jets.size()<15){Manager()->FillHisto("MT_NJ_10_14_NbJ_2onw", reco_leps[0]->mt_met(MET));}
        if(reco_jets.size()>14 ){Manager()->FillHisto("MT_NJ_15_inf_NbJ_2onw", reco_leps[0]->mt_met(MET));}
      }//bj>=2
    }//MT



 
  }//rec evt




  return true;
}

