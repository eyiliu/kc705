#ifndef JADE_JADEDECODE_HH
#define JADE_JADEDECODE_HH

#include "JadeSystem.hh"
#include "JadeDataFrame.hh"

class JadeDecode{
public:
  JadeDecode(const std::string &options);
  virtual ~JadeDecode();
  virtual JadeDataFrameUP Decode(JadeDataFrameUP &&) const;
  
private:
  std::string m_options;

};



#endif