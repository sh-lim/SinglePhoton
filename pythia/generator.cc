#include "Pythia8/Pythia.h"
#include "Pythia8Plugins/HepMC2.h" //added plugin for HepMC, think we will need some new library in pythia for this
using namespace Pythia8;
using namespace std;

void generator(std::string filename, long nEvents){
	using namespace HepMC;
	string hepName = filename+".dat";    //filenames
	 HepMC::Pythia8ToHepMC ToHepMC;    // Interface for conversion from Pythia8::Event to HepMC event.
    HepMC::IO_GenEvent ascii_io_direct(hepName, std::ios::out); //file where HepMC events will be stored.

  	/*pythia set up*/
  Pythia pythiaengine;
  pythiaengine.readString("Beams:eCM = 200.");
 	pythiaengine.readString("promptphoton:all = on");
 	pythiaengine.readString("HardQCD:all = on");
 	pythiaengine.readString("PhaseSpace:pTHatMin = 10.");
 	pythiaengine.readString("Random::setSeed = on");
  pythiaengine.readString("Random::seed =0");
  pythiaengine.init();

  for (int iEvent = 0; iEvent < nEvents; ++iEvent)
  	{ 
  		HepMC::GenEvent* hepmcevtfrag = new HepMC::GenEvent(); //create HepMC event
      ToHepMC_frag.fill_next_event( pythiaengine, hepmcevtfrag ); //convert event from pythia to HepMC
      ascii_io_frag << hepmcevtfrag;//write event to file
      delete hepmcevtfrag; //delete event so it can be redeclared next time
  	}

 }

int main(int argc, char const *argv[] )
{
	string fileOut = string(argv[1]);
	long nEvents =strtol(argv[2],NULL,10);  // 5000000;
	makeData(fileOut,nEvents);
	return 0;
}