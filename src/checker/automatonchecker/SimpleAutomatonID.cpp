#include "../../codestructures/PassingSolver.h"

#include "SimpleAutomatonID.h"

using namespace checker;

SimpleAutomatonID::SimpleAutomatonID(const utils::XMLPatternVariablesAssignment &assignment,
				     const bool isGlobal) :
	varsAssignment(buildVarsCollection(assignment)), _isGlobal(isGlobal)
{
}

QString SimpleAutomatonID::toString() const {
	QString result;
	if (isGlobal())
		result.append('G');
	result.append(getVarsAssignment().join(','));
	return result;
}

QStringList SimpleAutomatonID::buildVarsCollection(const utils::XMLPatternVariablesAssignment &varsAssignment) {
	return codestructs::PassingSolver::makeArgumentList(varsAssignment);
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
