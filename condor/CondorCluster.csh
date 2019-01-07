#!/bin/csh 
@ p = ( ${1} )
#
#/sphenix/user/vassalli/gammasample/test/fourembededout0.root
set OUT_LOCATION="/sphenix/user/vassalli/gammasample/"
set OUT_FILE=${OUT_LOCATION}fourembededonlineanalysis${p}.root
set IN_FILE=${OUT_LOCATION}fourembededout${p}.root
set PYTHIA_FILE="/sphenix/user/vassalli/gammasample/pythiahep.dat"
#
set SCRATCH_AREA="$_CONDOR_SCRATCH_DIR/fran_photons"                                                                                                              
#
set SOURCE_PHOTONMAKER="/direct/phenix+u/vassalli/sphenix/single/gen/*"
set BURNER="condor/after_embeded.C"
#
source /phenix/u/vassalli/.cshrc
mkdir $SCRATCH_AREA
cp  $SOURCE_PHOTONMAKER $SCRATCH_AREA
cp $BURNER $SCRATCH_AREA
#
cd $SCRATCH_AREA
root -b -q Fun4All_G4_sPHENIX.C\(2,\"$IN_FILE\",\"$PYTHIA_FILE\"\) 
root -b -q cluster_burner.C\(\"$IN_FILE\",\"$OUT_FILE\"\)
#
rm -rf $SCRATCH_AREA
#
exit 0
