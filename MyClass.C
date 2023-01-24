/////////////////////////////MEDIUM->LOOSE
#define MyClass_cxx
#include "MyClass.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include<iostream>
#include <TMath.h>
#include "TStopwatch.h"
#include <TLorentzVector.h>
#include <TRandom2.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

float zero = 0.0;

void MyClass::Loop(string outputfile, int ntotEvent, int nPrintEvent){
  
  TStopwatch sw;
  sw.Start();
  //int N_metFilters = 0 ;
  // int  N_HLTPho = 0;
  
  if (fChain == 0) return;
  
  cout<<"Output file : " << outputfile << endl;
  char *outfilename = const_cast<char*>(outputfile.c_str());
  TFile *fileout = new TFile(outfilename,"RECREATE");

  Long64_t nentries = fChain->GetEntries();
  std::cout << "Total entries: " << nentries << std::endl;
  
  if (ntotEvent >= 0) nentries = ntotEvent;
  Long64_t nbytes = 0, nb = 0;
  
  TH1F *h_EEMass170200               = new TH1F("E-E Invariant Mass170200","E-E Invariant Mass170200",60,60,120);
  TH1F *h_EEMass200220               = new TH1F("E-E Invariant Mass200220","E-E Invariant Mass200220",60,60,120);
  TH1F *h_EEMass220270               = new TH1F("E-E Invariant Mass220270","E-E Invariant Mass220270",60,60,120);
  TH1F *h_EEMass270320               = new TH1F("E-E Invariant Mass270320","E-E Invariant Mass270320",60,60,120);
  TH1F *h_EEMass320                  = new TH1F("E-E Invariant Mass320"   ,"E-E Invariant Mass320"   ,60,60,120);
  
  TH1F *h_EPMass170200               = new TH1F("E-P Invariant Mass170200","E-P Invariant Mass170200",60,60,120);
  TH1F *h_EPMass200220               = new TH1F("E-P Invariant Mass200220","E-P Invariant Mass200220",60,60,120);
  TH1F *h_EPMass220270               = new TH1F("E-P Invariant Mass220270","E-P Invariant Mass220270",60,60,120);
  TH1F *h_EPMass270320               = new TH1F("E-P Invariant Mass270320","E-P Invariant Mass270320",60,60,120);
  TH1F *h_EPMass320                  = new TH1F("E-P Invariant Mass320"   ,"E-P Invariant Mass320"   ,60,60,120);
  
  
  
  TH1F *h_EEMassnv10   = new TH1F("E-E Invariant Massnv10"  ,"E-E Invariant Massnv10"  ,60,60,120);
  TH1F *h_EEMassnv1020 = new TH1F("E-E Invariant Massnv1020","E-E Invariant Massnv1020",60,60,120);
  TH1F *h_EEMassnv2030 = new TH1F("E-E Invariant Massnv2030","E-E Invariant Massnv2030",60,60,120);
  TH1F *h_EEMassnv30   = new TH1F("E-E Invariant Massnv30"  ,"E-E Invariant Massnv30"  ,60,60,120);
  
  TH1F *h_EPMassnv10   = new TH1F("E-P Invariant Massnv10"  ,"E-P Invariant Massnv10"  ,60,60,120);
  TH1F *h_EPMassnv1020 = new TH1F("E-P Invariant Massnv1020","E-P Invariant Massnv1020",60,60,120);
  TH1F *h_EPMassnv2030 = new TH1F("E-P Invariant Massnv2030","E-P Invariant Massnv2030",60,60,120);
  TH1F *h_EPMassnv30   = new TH1F("E-P Invariant Massnv30"  ,"E-P Invariant Massnv30"  ,60,60,120);
  
  
  
  TH1F *h_EEMasseta5      = new TH1F("E-E Invariant Masseta.5"     ,"E-E Invariant Masseta.5"     ,60,60,120);
  TH1F *h_EEMasseta5_10   = new TH1F("E-E Invariant Masseta.5_1"   ,"E-E Invariant Masseta.5_1"   ,60,60,120);
  TH1F *h_EEMasseta10_14  = new TH1F("E-E Invariant Masseta1_1.44" ,"E-E Invariant Masseta1_1.44" ,60,60,120);
  TH1F *h_EEMasseta15_20  = new TH1F("E-E Invariant Masseta1.5_2"  ,"E-E Invariant Masseta1.5_2"  ,60,60,120);
  TH1F *h_EEMasseta20_25  = new TH1F("E-E Invariant Masseta2_2.5"  ,"E-E Invariant Masseta12_2.5" ,60,60,120);
  
  TH1F *h_EPMasseta5      = new TH1F("E-P Invariant Masseta.5"     ,"E-P Invariant Masseta.5"     ,60,60,120);
  TH1F *h_EPMasseta5_10   = new TH1F("E-P Invariant Masseta.5_1"   ,"E-P Invariant Masseta.5_1"   ,60,60,120);
  TH1F *h_EPMasseta10_14  = new TH1F("E-P Invariant Masseta1_1.44" ,"E-P Invariant Masseta1_1.44" ,60,60,120);
  TH1F *h_EPMasseta15_20  = new TH1F("E-P Invariant Masseta1.5_2"  ,"E-P Invariant Masseta1.5_2"  ,60,60,120);
  TH1F *h_EPMasseta20_25  = new TH1F("E-P Invariant Masseta2_2.5"  ,"E-P Invariant Masseta12_2.5" ,60,60,120);
  
  
  TH1F *h_EEMasseta_ne5      = new TH1F("E-E Invariant Masseta_ne.5"     ,"E-E Invariant Masseta_ne.5"      ,60,60,120);
  TH1F *h_EEMasseta_ne5_10   = new TH1F("E-E Invariant Masseta_ne.5_1"   ,"E-E Invariant Masseta_ne.5_1"    ,60,60,120);
  TH1F *h_EEMasseta_ne10_14  = new TH1F("E-E Invariant Masseta_ne1_1.44" ,"E-E Invariant Masseta_ne1_1.44"  ,60,60,120);
  TH1F *h_EEMasseta_ne15_20  = new TH1F("E-E Invariant Masseta_ne1.5_2"  ,"E-E Invariant Masseta_ne1.5_2"   ,60,60,120);
  TH1F *h_EEMasseta_ne20_25  = new TH1F("E-E Invariant Masseta_ne2_2.5"  ,"E-E Invariant Masseta_ne1.2_2.5" ,60,60,120);
  
  TH1F *h_EPMasseta_ne5      = new TH1F("E-P Invariant Masseta_ne.5"     ,"E-P Invariant Masseta_ne.5"     ,60,60,120);
  TH1F *h_EPMasseta_ne5_10   = new TH1F("E-P Invariant Masseta_ne.5_1"   ,"E-P Invariant Masseta_ne.5_1"   ,60,60,120);
  TH1F *h_EPMasseta_ne10_14  = new TH1F("E-P Invariant Masseta_ne1_1.44" ,"E-P Invariant Masseta_ne1_1.44" ,60,60,120);
  TH1F *h_EPMasseta_ne15_20  = new TH1F("E-P Invariant Masseta_ne1.5_2"  ,"E-P Invariant Masseta_ne1.5_2"  ,60,60,120);
  TH1F *h_EPMasseta_ne20_25  = new TH1F("E-P Invariant Masseta_ne2_2.5"  ,"E-P Invariant Masseta_ne12_2.5" ,60,60,120);
  
  
  
  
  TH1F *h_NVtx           = new TH1F("E-P nvtx","E-Pnvtxx",100,0,100);
  
  Int_t                N_metFilters = 0 ;
  Int_t  N_HLTPho =0 ;
  Int_t  n_electron =0 ;
  Int_t  n_photons =0 ;

  
  for (Long64_t jentry=0; jentry<nentries;jentry++)    {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    if (jentry % nPrintEvent == 0) std::cout << "  " << jentry  << "  Events Processed... " << std::endl;
    std::vector<double> pass;
    std::vector<double> fail;
    
    if (!getMetFilter()) continue;
    N_metFilters ++;
      // std::cout<<"passing events metFilters ==0          "<< N_metFilters << std::endl<< std::endl;
    
    if((HLTPho>>11)&1 == 1){          ////////////////Photon trigger
      N_HLTPho ++ ;
      for ( int j=0; j<nEle; j++ ){
	TLorentzVector etag;
	if ( elePt->at(j) > 30 && abs(eleEta->at(j)) < 2.5 && (eleIDbit->at(j)>>2)&1==1){
	  etag.SetPtEtaPhiE(elePt->at(j), eleEta->at(j), elePhi->at(j), eleE->at(j) );
	  // std::cout<< "etag mass with if "<< etag.M()<< std::endl;
	}
	for( int i=0; i<nPho; i++ ){
	  float dR = dRCal(phoEta->at(i),phoSCPhi->at(i), eleSCEta->at(j),eleSCPhi->at(j));
	  if (dR < 0.5) continue;
	  n_electron ++ ;
	  if ( MediumPhoton(i) ){
	    n_photons ++ ;
	    // std::cout<<"passing events photons "<< n_electron << std::endl<< std::endl;
	    TLorentzVector probe;
	    probe.SetPtEtaPhiE(phoEt->at(i), phoEta->at(i), phoPhi->at(i), phoE->at(i) );
	    double InvMass  = ( etag + probe).M();
	    
	    if ((InvMass > 60) && (InvMass < 120)){
	      std::cout<< "invariant mass is  "<< InvMass<< std::endl;
	      std::cout<< "phohasPixelSeed  "<< phohasPixelSeed->at(i) << std::endl;
	      if ( phohasPixelSeed->at(i) == 1 ){
		
		//////==========  w.r.t photon_Pt  ===========///////
		
		if (phoEt->at(i) >= 170 && phoEt->at(i) < 200)		      h_EEMass170200->Fill(InvMass);
		if (phoEt->at(i) >= 200 && phoEt->at(i) < 220)			      h_EEMass200220->Fill(InvMass);
		if ((phoEt->at(i) >= 220) && (phoEt->at(i) < 270))		      h_EEMass220270->Fill(InvMass);
		if (phoEt->at(i) >= 270 && phoEt->at(i) < 320)		      h_EEMass270320->Fill(InvMass);
		if ((phoEt->at(i) >= 320))		      h_EEMass320->Fill(InvMass);
		
		/////// =========   w.r.t No of vertices ======//////
		
		if (nVtx < 10)				h_EEMassnv10->Fill(InvMass);
		
		if ((nVtx>= 10) && (nVtx < 20))					h_EEMassnv1020->Fill(InvMass);
		
		if ((nVtx >= 20) && (nVtx < 30))				h_EEMassnv2030->Fill(InvMass);
		
		if ((nVtx >= 30))				h_EEMassnv30->Fill(InvMass);
		
		
		
		if ((phoEt->at(i) > 225) && fabs(phoEta->at(i)) >= 0.0 && fabs(phoEta->at(i)) < 0.2) h_EEMasseta5->Fill(InvMass);
		
		if ((phoEt->at(i) > 225) && fabs(phoEta->at(i)) >= 0.2 && fabs(phoEta->at(i)) < 0.4)  h_EEMasseta5_10->Fill(InvMass);
		
		if ((phoEt->at(i) > 225) && fabs(phoEta->at(i)) >= 0.4 && fabs(phoEta->at(i)) < 0.8)  h_EEMasseta10_14->Fill(InvMass);
		
		if ((phoEt->at(i) > 225) && fabs(phoEta->at(i)) >= 0.8 && fabs(phoEta->at(i)) < 1.2)  h_EEMasseta15_20->Fill(InvMass);
		
		if ((phoEt->at(i) > 225) && fabs(phoEta->at(i)) >= 1.2 && fabs(phoEta->at(i)) <= 1.4442)  h_EEMasseta20_25->Fill(InvMass);			      		
	      }
	      
	      
	      if ( phohasPixelSeed->at(i) == 0 ){
		
		//////==========  w.r.t photon_Pt  ===========///////
		
		if (phoEt->at(i) >= 170 && phoEt->at(i) < 200)				h_EPMass170200->Fill(InvMass);
		
		if ((phoEt->at(i) >=200) && (phoEt->at(i) < 220))				h_EPMass200220->Fill(InvMass);
		
		if ((phoEt->at(i) >=220) && (phoEt->at(i) < 270))				h_EPMass220270->Fill(InvMass);
		
		if (phoEt->at(i) >= 270 && phoEt->at(i) < 320)				h_EPMass270320->Fill(InvMass);
		
		if ((phoEt->at(i) >= 320))				h_EPMass320->Fill(InvMass);
		
		
		//////=============== w. r. t. number of vertices ==========//////////////
		
		if (nVtx < 10)				h_EPMassnv10->Fill(InvMass);
		
		if ((nVtx >= 10) && (nVtx < 20))				h_EPMassnv1020->Fill(InvMass);
		
		if ((nVtx >= 20) && (nVtx < 30))				h_EPMassnv2030->Fill(InvMass);
		
		if ((nVtx >= 30))				h_EPMassnv30->Fill(InvMass);
		
		
		
		
		/////   =========== w.r.t. Photon +ve eta  =======////////
		
		
		if ((phoEt->at(i) > 225) && fabs(phoEta->at(i)) >= 0.0 && fabs(phoEta->at(i)) < 0.2)  h_EPMasseta5->Fill(InvMass);
		
		if ((phoEt->at(i) > 225) && fabs(phoEta->at(i)) >= 0.2 && fabs(phoEta->at(i)) < 0.4)  h_EPMasseta5_10->Fill(InvMass);
		
		if ((phoEt->at(i) > 225) && fabs(phoEta->at(i)) >= 0.4 && fabs(phoEta->at(i)) < 0.8)  h_EPMasseta10_14->Fill(InvMass);
		
		if ((phoEt->at(i) > 225) && fabs(phoEta->at(i)) >= 0.8 && fabs(phoEta->at(i)) < 1.2)  h_EPMasseta15_20->Fill(InvMass);
		
		if ((phoEt->at(i) > 225) && fabs(phoEta->at(i)) >= 1.2 && fabs(phoEta->at(i)) <= 1.4442) h_EPMasseta20_25->Fill(InvMass);			      
		
		
		
		
		
	      }
	    }
	  }		
	}
      }
    }
  }
  
  
  h_NVtx->Fill(nVtx) ;
  h_NVtx->Write() ;
  
  
  h_EEMass170200->Write();
  h_EEMass200220->Write();
  h_EEMass220270->Write();
  h_EEMass270320->Write();
  h_EEMass320->Write();
  
  h_EPMass170200->Write();
  h_EPMass200220->Write();
  h_EPMass220270->Write();
  h_EPMass270320->Write();
  h_EPMass320->Write();
  
  
  h_EEMassnv10->Write();
  h_EEMassnv1020->Write();
  h_EEMassnv2030->Write();
  h_EEMassnv30->Write();
  
  h_EPMassnv10->Write();
  h_EPMassnv1020->Write();
  h_EPMassnv2030->Write();
  h_EPMassnv30->Write();
  
  h_EEMasseta5->Write();
  h_EEMasseta5_10->Write();
  h_EEMasseta10_14->Write();
  h_EEMasseta15_20->Write();
  h_EEMasseta20_25->Write();
  
  h_EPMasseta5->Write();
  h_EPMasseta5_10->Write();
  h_EPMasseta10_14->Write();
  h_EPMasseta15_20->Write();
  h_EPMasseta20_25->Write();
  
  
  h_EEMasseta_ne5->Write();
  h_EEMasseta_ne5_10->Write();
  h_EEMasseta_ne10_14->Write();
  h_EEMasseta_ne15_20->Write();
  h_EEMasseta_ne20_25->Write();
  
  h_EPMasseta_ne5->Write();
  h_EPMasseta_ne5_10->Write();
  h_EPMasseta_ne10_14->Write();
  h_EPMasseta_ne15_20->Write();
  h_EPMasseta_ne20_25->Write();
  
  

  fileout->Close();

  cout<<outputfile<< " created ...."<<endl;

  sw.Stop();
  std::cout << "RealTime : " << sw.RealTime() / 60.0 << " minutes" << std::endl;
  std::cout << "CPUTime  : " << sw.CpuTime()  / 60.0 << " minutes" << std::endl;
}

bool MyClass::getMetFilter(){
  bool decision = true;
  if(metFilters>>0 & 1) decision = false;
  if(metFilters>>1 & 1) decision = false;
  if(metFilters>>2 & 1) decision = false;
  if(metFilters>>3 & 1) decision = false;
  if(metFilters>>4 & 1) decision = false;
  if(metFilters>>5 & 1) decision = false;
  if(metFilters>>7 & 1) decision = false;
  if(metFilters>>8 & 1) decision = false;
  return decision;
}



float MyClass::dRCal(float etaLead, float phiLead, float etaTrail, float phiTrail){

  float dphi = fabs(phiLead - phiTrail);
  if (dphi > TMath::Pi()) dphi = TMath::Pi()*2. - dphi;
  float deta = fabs(etaLead - etaTrail);
  float dR = sqrt(deta*deta + dphi*dphi);
  return dR;

}

///////////////////////NEW IDS May3
bool MyClass::MediumPhoton(int& i){

    bool isMediumPhoton = false;
    Float_t uncorrectedPhoEt = phoEt->at(i);
    bool kinematic = (fabs(phoSCEta->at(i))< 2.5) ;
    bool photonId = (
		     ( phoHoverE->at(i)                <  0.0230   ) &&
		     ( phoSigmaIEtaIEtaFull5x5->at(i)  <  0.0103 ) &&
		     ( TMath::Max( ( phoPFChWorstIso->at(i)  - rho*EAchargedworst(phoSCEta->at(i)) ), 0.0) < 2.14 )  &&
		     ( TMath::Max( ( phoPFNeuIso->at(i) - rho*EAneutral(phoSCEta->at(i)) ), 0.0) < (7.25 + (9.73714e-03 * uncorrectedPhoEt) + (1.01605e-05 * pow(uncorrectedPhoEt, 2.0))) )  &&
		     ( TMath::Max( ( phoPFPhoIso->at(i) - rho*EAphoton(phoSCEta->at(i))  ), 0.0) < (0.17 + (2.99336e-03 * uncorrectedPhoEt)) )
		     );
    
    bool noncoll = fabs(phoSeedTime->at(i)) < 3.&& phoMIPTotEnergy->at(i) < 4.9; //&&  (*phoSigmaIEtaIEtaFull5x5)[p] > 0.001 && (*phoSigmaIPhiIPhiFull5x5)[p] > 0.001;
    
    if(photonId && kinematic && noncoll)
      isMediumPhoton = true ;
    
    return isMediumPhoton;
}
//end of 2016 Selections



// Effective area to be needed in PF Iso for photon ID                                                                                                                                               

Double_t MyClass::EAchargedworst(Double_t eta){
  Float_t EffectiveArea = 0.0;
  if(fabs(eta) >= 0.0   && fabs(eta) < 0.5   ) EffectiveArea = 0.06118;
  if(fabs(eta) >= 0.5   && fabs(eta) < 1.0   ) EffectiveArea = 0.05545;
  if(fabs(eta) >= 1.0   && fabs(eta) < 1.479 ) EffectiveArea = 0.05000;
  return EffectiveArea;
}

Double_t MyClass::EAneutral(Double_t eta){
  Float_t EffectiveArea = 0.0;
  if(fabs(eta) >= 0.0   && fabs(eta) < 0.5   ) EffectiveArea = 0.03279;
  if(fabs(eta) >= 0.5   && fabs(eta) < 1.0   ) EffectiveArea = 0.05682;
  if(fabs(eta) >= 1.0   && fabs(eta) < 1.479 ) EffectiveArea = 0.07969;
  return EffectiveArea;
}

Double_t MyClass::EAphoton(Double_t eta){
  Float_t EffectiveArea = 0.0;
  if(fabs(eta) >= 0.0   && fabs(eta) < 0.5   ) EffectiveArea = 0.1078;
  if(fabs(eta) >= 0.5   && fabs(eta) < 1.0   ) EffectiveArea = 0.1068;
  if(fabs(eta) >= 1.0   && fabs(eta) < 1.479 ) EffectiveArea = 0.08661;
  return EffectiveArea;
}







