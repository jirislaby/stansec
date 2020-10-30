TEMPLATE = subdirs

SUBDIRS = \
	parser \
	core

parser.subdir = src/parser
core.subdir = src/core

core.depends = parser
