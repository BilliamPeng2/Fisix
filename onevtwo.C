#define onevtwo_cxx
#include "onevtwo.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void onevtwo::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L onevtwo.C
//      Root > onevtwo t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   TH2F *h2 = new TH2F("h2", "Two Highest Final State Hadron Energies", 100, 0, 300, 100, 0, 300);
   TAxis *xaxis = h2->GetXaxis();
   TAxis *yaxis = h2->GetYaxis();
   xaxis->SetTitle("Highest Hadron Energy (GeV)");
   yaxis->SetTitle("2nd Highest Hadron Energy (GeV)");
   /** Loop over events */
   for (Long64_t jentry=0; jentry<nentries;jentry++)
 {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      // cout << "Event: " << jentry << ", nPart: " << nPart <<  endl;
      set<double> set;
      /** Loop over all particles within this event */
      for ( int i = 0; i < nPart; i++ ){
 // if stable final state particle 
      if ( p_fKS[ i ] == 1 ){
	if ( abs(p_fKF[ i ]) > 100)  { //hadron filter
	    double z = p_fEnergy[i];
	    set.insert(z); /**insert all Energies of hadrons into set*/ }
}
}
  
       if (set.size()!=1){
       float x = *set.rbegin();
       float y = *++set.rbegin();
       h2->Fill(x,y);
       }
}
    TCanvas *myCanvas = new TCanvas();
    h2->Draw("colz");
}
