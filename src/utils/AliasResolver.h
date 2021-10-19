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
#if QT_VERSION >= QT_VERSION_CHECK(5, 15, 0)
	aliases.insert(newAliases);
#else
	for (auto it = newAliases.begin(); it != newAliases.end(); ++it)
		aliases.insert(it.key(), it.value());
#endif
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
