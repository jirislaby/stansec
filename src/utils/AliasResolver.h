#ifndef ALIASRESOLVER_H
#define ALIASRESOLVER_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QMap>
#include <QString>

namespace utils {

class AliasResolver {
public:
    typedef QMap<QString, QString> AliasMap;
    AliasResolver() { }

    void addAliasMapping(const AliasMap &newAliases) {
	aliases.insert(newAliases);
    }

    bool match(const QString &pattern, const QString &name) const {
	return name == pattern ||
		(aliases.contains(name) && aliases[name] == pattern);
    }

private:
    AliasMap aliases;
};

}

#endif
