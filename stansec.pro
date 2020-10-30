TEMPLATE = subdirs

SUBDIRS = \
	parser \
	core

parser.subdir = src/parser
core.subdir = src/core

core.depends = parser

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
