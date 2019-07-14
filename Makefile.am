lib_LIBRARIES = libjsgf_kit.a

libjsgf_kit_a_SOURCES = src/grammar.cpp src/expansion.cpp src/rule.cpp\
			src/matchinfo.cpp src/matchresult.cpp src/tag.cpp\
			src/unparsedsection.cpp src/kleenestar.cpp src/plusoperator.cpp\
			src/optionalgrouping.cpp src/requiredgrouping.cpp src/sequence.cpp\
			src/alternativeset.cpp src/token.cpp src/rulereference.cpp

jsgfkitincludedir = $(includedir)/jsgfkit

jsgfkitinclude_HEADERS = include/rule.h include/expansion.h include/grammar.h\
		  include/unparsedsection.h include/kleenestar.h \
		  include/alternativeset.h include/token.h include/tag.h include/matchinfo.h\
	 	  include/matchresult.h include/sequence.h include/plusoperator.h include/requiredgrouping.h\
		  include/optionalgrouping.h include/rulereference.h

libjsgf_kit_a_CPPFLAGS = -I include/

ACLOCAL_AMFLAGS = -I m4
pkgconfig_DATA = jsgfkit.pc
