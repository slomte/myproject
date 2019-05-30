#ifndef analysis_stop_topN2_ana_h
#define analysis_stop_topN2_ana_h

#include "SampleAnalyzer/Process/Analyzer/AnalyzerBase.h"

namespace MA5
{
class stop_topN2_ana : public AnalyzerBase
{
  INIT_ANALYSIS(stop_topN2_ana,"stop_topN2_ana")

 public:
  virtual bool Initialize(const MA5::Configuration& cfg, const std::map<std::string,std::string>& parameters);
  virtual void Finalize(const SampleFormat& summary, const std::vector<SampleFormat>& files);
  virtual bool Execute(SampleFormat& sample, const EventFormat& event);

 private:
};
}

#endif