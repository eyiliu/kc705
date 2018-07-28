#ifndef JADE_JADEFILTER_HH
#define JADE_JADEFILTER_HH

#include "JadeSystem.hh"
#include "JadeFactory.hh"
#include "JadeOption.hh"
#include "JadePost.hh"
#include "JadeDataFrame.hh"

class JadeFilter;
using JadeFilterSP = JadeFactory<JadeFilter>::SP;
using JadeFilterUP = JadeFactory<JadeFilter>::UP;

#ifndef JADE_DLL_EXPORT
extern template class DLLEXPORT JadeFactory<JadeFilter>;
extern template DLLEXPORT
std::unordered_map<std::type_index, typename JadeFactory<JadeFilter>::UP (*)(const JadeOption&)>&
JadeFactory<JadeFilter>::Instance<const JadeOption&>();
#endif


class DLLEXPORT JadeFilter: public JadePost{
public:
  JadeFilter(const JadeOption &opt);
  virtual ~JadeFilter();
  static JadeFilterSP Make(const std::string& name, const JadeOption& opt);
  virtual void Reset();
  virtual JadeDataFrameSP Filter(JadeDataFrameSP df);
  JadeOption Post(const std::string &url, const JadeOption &opt) override;
 private:
  JadeOption m_opt;
};

#endif
