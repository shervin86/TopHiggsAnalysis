// C++ includes
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

// ROOT includes
#include <TROOT.h>
#include <TFile.h>
#include <TTree.h>
#include <TChain.h>

#include "addWeightsToTreetH.hh"

using namespace std;

int main(int argc, char* argv[]) {

  char fileName[500];
  if ( argc < 5 ) {
    std::cout << "Format should be: LatinosAnalyzer filename.root weight_in_pb sampleid channel" << std::endl;
    return 1;
  }
  strcpy(fileName,argv[1]);
  float weight;
  weight = atof(argv[2]);
  int sampleid, channel;
  sampleid=atoi(argv[3]);
  channel=atoi(argv[4]);

  std::cout << "Processing sample " << fileName << ": weight for 1/fb = " << weight
            << "\tsample ID = " << sampleid << "\tchannel = " << channel << std::endl;

  addWeightsToTreetH weighter(fileName,weight,sampleid,channel);
  weighter.addWeights();

  return 0;

}
