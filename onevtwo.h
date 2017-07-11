//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Jun 30 15:22:52 2017 by ROOT version 5.34/36
// from TTree tree/Pythia 6 tree
// found on file: pythia6.ep.dis.e10xp250.1000.root
//////////////////////////////////////////////////////////

#ifndef onevtwo_h
#define onevtwo_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <TClonesArray.h>
#include <TObject.h>
#include <TAttLine.h>
//#include <TMCParticle.h>

// Fixed size dimensions of array or collections stored in the TTree if any.
   const Int_t kMaxp = 200;

class onevtwo {

public :

  TH1F* htest;

   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           p_;
   UInt_t          p_fUniqueID[kMaxp];   //[p_]
   UInt_t          p_fBits[kMaxp];   //[p_]
   Short_t         p_fLineColor[kMaxp];   //[p_]
   Short_t         p_fLineStyle[kMaxp];   //[p_]
   Short_t         p_fLineWidth[kMaxp];   //[p_]
   Int_t           p_fKS[kMaxp];   //[p_]
   Int_t           p_fKF[kMaxp];   //[p_]
   Int_t           p_fParent[kMaxp];   //[p_]
   Int_t           p_fFirstChild[kMaxp];   //[p_]
   Int_t           p_fLastChild[kMaxp];   //[p_]
   Float_t         p_fPx[kMaxp];   //[p_]
   Float_t         p_fPy[kMaxp];   //[p_]
   Float_t         p_fPz[kMaxp];   //[p_]
   Float_t         p_fEnergy[kMaxp];   //[p_]
   Float_t         p_fMass[kMaxp];   //[p_]
   Float_t         p_fVx[kMaxp];   //[p_]
   Float_t         p_fVy[kMaxp];   //[p_]
   Float_t         p_fVz[kMaxp];   //[p_]
   Float_t         p_fTime[kMaxp];   //[p_]
   Float_t         p_fLifetime[kMaxp];   //[p_]
   Int_t           nPart;
   Double_t        Q2;
   Double_t        y;
   Double_t        x;

   // List of branches
   TBranch        *b_p_;   //!
   TBranch        *b_p_fUniqueID;   //!
   TBranch        *b_p_fBits;   //!
   TBranch        *b_p_fLineColor;   //!
   TBranch        *b_p_fLineStyle;   //!
   TBranch        *b_p_fLineWidth;   //!
   TBranch        *b_p_fKS;   //!
   TBranch        *b_p_fKF;   //!
   TBranch        *b_p_fParent;   //!
   TBranch        *b_p_fFirstChild;   //!
   TBranch        *b_p_fLastChild;   //!
   TBranch        *b_p_fPx;   //!
   TBranch        *b_p_fPy;   //!
   TBranch        *b_p_fPz;   //!
   TBranch        *b_p_fEnergy;   //!
   TBranch        *b_p_fMass;   //!
   TBranch        *b_p_fVx;   //!
   TBranch        *b_p_fVy;   //!
   TBranch        *b_p_fVz;   //!
   TBranch        *b_p_fTime;   //!
   TBranch        *b_p_fLifetime;   //!
   TBranch        *b_nPart;   //!
   TBranch        *b_Q2;   //!
   TBranch        *b_y;   //!
   TBranch        *b_x;   //!

   onevtwo(TTree *tree=0);
   virtual ~onevtwo();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef onevtwo_cxx
onevtwo::onevtwo(TTree *tree) : fChain(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("pythia6.ep.dis.e10xp250.1000000.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("pythia6.ep.dis.e10xp250.1000000.root");
      }
      f->GetObject("tree",tree);

   }
   Init(tree);
}

onevtwo::~onevtwo()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t onevtwo::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t onevtwo::LoadTree(Long64_t entry)
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

void onevtwo::Init(TTree *tree)
{
  /** Define histogram */
  htest = new TH1F("htest",";x-axis;y-axis", 600, -300, 300);

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

   fChain->SetBranchAddress("p", &p_, &b_p_);
   fChain->SetBranchAddress("p.fUniqueID", p_fUniqueID, &b_p_fUniqueID);
   fChain->SetBranchAddress("p.fBits", p_fBits, &b_p_fBits);
   fChain->SetBranchAddress("p.fLineColor", p_fLineColor, &b_p_fLineColor);
   fChain->SetBranchAddress("p.fLineStyle", p_fLineStyle, &b_p_fLineStyle);
   fChain->SetBranchAddress("p.fLineWidth", p_fLineWidth, &b_p_fLineWidth);
   fChain->SetBranchAddress("p.fKS", p_fKS, &b_p_fKS);
   fChain->SetBranchAddress("p.fKF", p_fKF, &b_p_fKF);
   fChain->SetBranchAddress("p.fParent", p_fParent, &b_p_fParent);
   fChain->SetBranchAddress("p.fFirstChild", p_fFirstChild, &b_p_fFirstChild);
   fChain->SetBranchAddress("p.fLastChild", p_fLastChild, &b_p_fLastChild);
   fChain->SetBranchAddress("p.fPx", p_fPx, &b_p_fPx);
   fChain->SetBranchAddress("p.fPy", p_fPy, &b_p_fPy);
   fChain->SetBranchAddress("p.fPz", p_fPz, &b_p_fPz);
   fChain->SetBranchAddress("p.fEnergy", p_fEnergy, &b_p_fEnergy);
   fChain->SetBranchAddress("p.fMass", p_fMass, &b_p_fMass);
   fChain->SetBranchAddress("p.fVx", p_fVx, &b_p_fVx);
   fChain->SetBranchAddress("p.fVy", p_fVy, &b_p_fVy);
   fChain->SetBranchAddress("p.fVz", p_fVz, &b_p_fVz);
   fChain->SetBranchAddress("p.fTime", p_fTime, &b_p_fTime);
   fChain->SetBranchAddress("p.fLifetime", p_fLifetime, &b_p_fLifetime);
   fChain->SetBranchAddress("nPart", &nPart, &b_nPart);
   fChain->SetBranchAddress("Q2", &Q2, &b_Q2);
   fChain->SetBranchAddress("y", &y, &b_y);
   fChain->SetBranchAddress("x", &x, &b_x);
   Notify();
}

Bool_t onevtwo::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void onevtwo::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t onevtwo::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef onevtwo_cxx
