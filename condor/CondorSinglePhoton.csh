#!/bin/csh 
@ p = ( ${1} + 100 )
#
set OUT_LOCATION="/sphenix/user/vassalli/singlesamples/Photon5/test"
set OUT_FILE=${OUT_LOCATION}onlineanalysis${p}.root
set IN_FILE="/sphenix/user/vassalli/singlesamples/Photon5/test/out${p}.root"
#
set SCRATCH_AREA="$_CONDOR_SCRATCH_DIR"                                                                                                              
#
set SOURCE_PHOTONMAKER="/direct/phenix+u/vassalli/sphenix/single/gen/*"
set BURNER="condor/after_DST.C"
#
source /phenix/u/vassalli/.cshrc
mkdir $SCRATCH_AREA/fran_single_photons
cp  $SOURCE_PHOTONMAKER $SCRATCH_AREA/fran_single_photons/
cp $BURNER $SCRATCH_AREA/fran_single_photons/
#
cd $SCRATCH_AREA/fran_single_photons
root -b -q Fun4All_G4_sPHENIX.C\(\"$IN_FILE\"\) 
root -b -q after_DST.C\(\"$IN_FILE\",\"$OUT_FILE\"\)
#
rm -r $SCRATCH_AREA/fran_single_photons
#
exit 0
