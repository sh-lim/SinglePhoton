AUTOMAKE_OPTIONS = foreign

INCLUDES = \
  -I$(includedir) \
  -I$(OFFLINE_MAIN)/include \
  -I`root-config --incdir`

libtreemaker_la_LDFLAGS = \
  -nodefaultlibs \
  -L$(libdir) \
  -L$(OFFLINE_MAIN)/lib \
	-L$(HOME)/install/lib \
 `root-config --libs`

lib_LTLIBRARIES = \
	libtreemaker.la
  
include_HEADERS = \
	TreeMaker.h \
	TreeMakerLinkDef.h 

libtreemaker_la_SOURCES = \
	TreeMaker.cc \
	TreeMaker_Dict.C 

libtreemaker_la_LIBADD = \
  -lg4dst \
  -lg4eval \
  -lcalotrigger \
  -lphool\
	-lSinglePhotonAnalysis

BUILT_SOURCES = \
	testexternals.C

noinst_PROGRAMS = \
	testexternals

testexternals_LDADD = \
	libtreemaker.la

testexternals.C:
	echo "//*** this is a generated file. Do not commit, do not edit" > $@
	echo "int main()" >> $@
	echo "{" >> $@
	echo "  return 0;" >> $@
	echo "}" >> $@

##############################################
# please add new classes in alphabetical order
# Rule for generating CINT dictionaries from class headers.
%_Dict.C: %.h %LinkDef.h
	rootcint -f $@ -c $(CINTFLAGS) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $^

clean-local:
	rm -f *Dict* testexternals.C
