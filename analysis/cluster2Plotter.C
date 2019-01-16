#include <iostream>
using namespace std;

#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TLegend.h"
#include "math.h"
#include "TH1.h"
#include "TH2.h"
#include "TEfficiency.h"
#include "TLine.h"
#include "TGraphAsymmErrors.h"

TChain* handleFile(string name, string extension, string treename, unsigned int filecount){
  TChain *all = new TChain(treename.c_str());
  string temp;
  for (int i = 0; i < filecount; ++i)
  {

    ostringstream s;
    s<<i;
    temp = name+string(s.str())+extension;
    all->Add(temp.c_str());
  }
  return all;
}

void cluster2Plotter()
{
  double deta[200];
  double dphi[200];
  int    cluster_n;

  string treePath = "/sphenix/user/vassalli/gammasample/fourembededonlineanalysis";
  string treeExtension = ".root";
  unsigned int nFiles=100;
  TChain *ttree = handleFile(treePath,treeExtension,"ttree",nFiles);
  ttree->SetBranchAddress("clus_dphi",    &dphi    );
  ttree->SetBranchAddress("clus_deta",    &deta    );
  ttree->SetBranchAddress("nRpair",    &cluster_n  );

  string outfilename = "2clusplot.root";
  TFile *out = new TFile(outfilename.c_str(),"RECREATE");

  string plotname = "2clusplot";

  TH2F *h_2clusplot = new TH2F("2clusplot","",80,0,.5,80,0,.5); 
	h_2clusplot->SetStats(kFALSE);
    h_2clusplot->GetXaxis()->SetTitle("eta");
    h_2clusplot->GetYaxis()->SetTitle("phi");
  for (int event = 0; event < ttree->GetEntries(); ++event)
  {
    ttree->GetEvent(event);
    for (int i = 0; i < cluster_n; ++i)
    {
    	h_2clusplot->Fill(deta[i],dphi[i]);
    }
  }  
  out->Write();
  out->Close();
  delete ttree;
  delete out;

}