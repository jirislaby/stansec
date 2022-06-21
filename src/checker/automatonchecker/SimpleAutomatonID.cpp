#include <clang/AST/ASTDumper.h>
#include <clang/AST/Expr.h>
#include <clang/Basic/LangOptions.h>

#include <QDebug>

#include "../../codestructures/PassingSolver.h"
#include "../../utils/xmlpatterns/XMLPatternVariablesAssignment.h"

#include "SimpleAutomatonID.h"

using namespace checker;

SimpleAutomatonID::SimpleAutomatonID(const utils::XMLPatternVariablesAssignment &assignment,
				     const bool isGlobal) :
	varsAssignment(assignment.getVarsNodeMap().values()),
	_isGlobal(isGlobal)
{
}

QString SimpleAutomatonID::toString(const clang::LangOptions &LO) const
{
	QString result;
	result.append(isGlobal() ? 'G' : 'L').append('(');
	QStringList vars;
	for (const auto &a : getVarsAssignment()) {
		auto decast = a->IgnoreParenCasts();
		std::string str;
		llvm::raw_string_ostream out(str);
		clang::PrintingPolicy policy(LO);
		decast->printPretty(out, nullptr, policy);
		vars << QString::fromStdString(str);
	}
	result.append(vars.join(',')).append(')');
	return result;
}

QDebug checker::operator<<(QDebug d, const SimpleAutomatonID &item)
{
	if (item.isGlobal())
		d << 'G';
	else
		d << 'L';
	d << item.getVarsAssignment();
	return d;
}

bool checker::operator==(const SimpleAutomatonID &lhs,
			 const SimpleAutomatonID &rhs)
{
	if (lhs.isGlobal() != rhs.isGlobal())
		return false;

	const auto &ll = lhs.getVarsAssignment();
	const auto &rl = rhs.getVarsAssignment();
	auto i1 = ll.constBegin();
	auto i2 = rl.constBegin();
	const auto &e1 = ll.constEnd();
	const auto &e2 = rl.constEnd();
	for (; i1 != e1 && i2 != e2; ++i1, ++i2)
		if (!codestructs::PassingSolver::isSameExpr(*i1, *i2))
			return false;

	return i1 == e1 && i2 == e2;
}
