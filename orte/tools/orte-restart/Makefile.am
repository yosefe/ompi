#
# Copyright (c) 2004-2007 The Trustees of Indiana University and Indiana
#                         University Research and Technology
#                         Corporation.  All rights reserved.
# Copyright (c) 2004-2005 The University of Tennessee and The University
#                         of Tennessee Research Foundation.  All rights
#                         reserved.
# Copyright (c) 2004-2009 High Performance Computing Center Stuttgart, 
#                         University of Stuttgart.  All rights reserved.
# Copyright (c) 2004-2005 The Regents of the University of California.
#                         All rights reserved.
# Copyright (c) 2008-2014 Cisco Systems, Inc.  All rights reserved.
# Copyright (c) 2008      Sun Microsystems, Inc.  All rights reserved.
# Copyright (c) 2010-2011 Oak Ridge National Labs.  All rights reserved.
# $COPYRIGHT$
# 
# Additional copyrights may follow
# 
# $HEADER$
#

include $(top_srcdir)/Makefile.ompi-rules

man_pages = orte-restart.1
EXTRA_DIST = orte-restart.1in

if WANT_FT_CR
if OPAL_INSTALL_BINARIES

bin_PROGRAMS = orte-restart

nodist_man_MANS = $(man_pages)

# Ensure that the man pages are rebuilt if the opal_config.h file
# changes; a "good enough" way to know if configure was run again (and
# therefore the release date or version may have changed)
$(nodist_man_MANS): $(top_builddir)/opal/include/opal_config.h

dist_ortedata_DATA = help-orte-restart.txt

endif # OPAL_INSTALL_BINARIES

orte_restart_SOURCES = orte-restart.c
orte_restart_LDADD = $(top_builddir)/orte/lib@ORTE_LIB@.la $(top_builddir)/opal/lib@OPAL_LIB@.la

endif # WANT_FT_CR

distclean-local:
	rm -f $(man_pages)
