#ifndef SNOWMAN_SNOWTOOLS_COVERAGE_H__
#define SNOWMAN_SNOWTOOLS_COVERAGE_H__

#include <memory>
#include <unordered_map>
#include <vector>
#include <cstdint>
#include <vector>
#include <cassert> 
#include <iostream>
#include <memory>

#include "htslib/hts.h"
#include "htslib/sam.h"
#include "htslib/bgzf.h"
#include "htslib/kstring.h"

#include "SnowTools/BamRead.h"
#include "SnowTools/GenomicRegion.h"

typedef std::shared_ptr<std::vector<uint16_t>> uint16_sp;

namespace SnowTools {

/*! Class to hold base-pair or binned coverage across the genome
 */
class STCoverage {
  
 private:

  GenomicRegion m_gr;
  uint16_sp v;

 public:

  /** Add a read to this coverage track */
  void addRead(const BamRead &r);

  /** Make a new coverage object at interval gr */
  STCoverage(const GenomicRegion& gr);

  /** Make an empty coverage */
  STCoverage() {}

  /*! Add to coverage objects together to get total coverge 
   * 
   * @param cov Coverage object to add to current object
   */
  //void combineCoverage(Coverage &cov);

  /** Return a short summary string of this coverage object */
  void ToBedgraph(ogzstream * o, const bam_hdr_t * h) const;
  
  /** Print the entire data */
  friend std::ostream& operator<<(std::ostream &out, const STCoverage &c);

  /** Return the coverage count at a position */
  uint16_t getCoverageAtPosition(size_t pos) const;
  
};

}
#endif
