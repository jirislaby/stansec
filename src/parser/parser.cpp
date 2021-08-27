#include <iostream>

#include <clang/Frontend/CompilerInstance.h>
#include <clang/Frontend/FrontendAction.h>
#include <clang/StaticAnalyzer/Core/Checker.h>
#include <clang/StaticAnalyzer/Core/CheckerManager.h>
#include <clang/StaticAnalyzer/Core/PathSensitive/CheckerContext.h>
#include <clang/StaticAnalyzer/Frontend/AnalysisConsumer.h>
#include <clang/StaticAnalyzer/Frontend/CheckerRegistry.h>
#include <clang/Tooling/Tooling.h>

#include "parser.h"

using namespace clang;
using namespace ento;
using namespace parser;

namespace {

class ParserChecker : public Checker<check::ASTCodeBody, check::EndOfTranslationUnit> {
public:
	void checkEndOfTranslationUnit(const TranslationUnitDecl *TU,
				       AnalysisManager &,
				       BugReporter &) const {
		llvm::errs() << __func__ << ":\n";
		TU->dump();
	}

	void checkASTCodeBody(const Decl *D, AnalysisManager& mgr,
			BugReporter &) const {
		llvm::errs() << __func__ << ":\n";

		if (auto ND = dynamic_cast<const NamedDecl *>(D)) {
			llvm::errs() << "decl is NAMED as '" << ND->getName() << "'\n";
		}

		if (CFG *cfg = mgr.getCFG(D)) {
			llvm::errs() << "dumping a CFG:\n";
			cfg->dump(mgr.getLangOpts(), true);
		} else {
			llvm::errs() << "NOT a CFG:\n";
			D->dump();
		}
	}
};

class ParserAction : public ASTFrontendAction {
	std::string Diags;
	llvm::raw_string_ostream DiagsOutput;

	class DiagConsumer : public PathDiagnosticConsumer {
		llvm::raw_ostream &Output;

	public:
		DiagConsumer(llvm::raw_ostream &Output) : Output(Output) {}

		void FlushDiagnosticsImpl(std::vector<const PathDiagnostic *> &Diags,
					  FilesMade *filesMade) override {
			for (const auto *PD : Diags)
				Output << PD->getCheckerName() << ":" << PD->getShortDescription() << '\n';
		}

		StringRef getName() const override { return "Parser"; }
	};

public:
	ParserAction() : DiagsOutput(Diags) {}

	std::unique_ptr<ASTConsumer> CreateASTConsumer(CompilerInstance &Compiler,
						       StringRef File) override {
	    std::unique_ptr<AnalysisASTConsumer> AnalysisConsumer =
		    CreateAnalysisConsumer(Compiler);
	    AnalysisConsumer->AddDiagnosticConsumer(new DiagConsumer(DiagsOutput));
	    Compiler.getAnalyzerOpts()->CheckersAndPackages = {{"stanse.Parser", true}};
	    AnalysisConsumer->AddCheckerRegistrationFn([](CheckerRegistry &Registry) {
		Registry.addChecker<ParserChecker>("stanse.Parser", "Parser for stanseC", "");
	    });
	    return std::move(AnalysisConsumer);
	}
};

}

Parser::Parser()
{
}

Parser::~Parser()
{
}

void Parser::parse(const std::string &code)
{
	tooling::runToolOnCode(std::make_unique<ParserAction>(), code, "input.c");
}

QString Parser::getDot(unsigned int line, int shrink) const
{
	return QString();
}

void runParserOnFile(const std::string &file)
{
	llvm::errs() << "running on " << file << "\n";
	tooling::runToolOnCodeWithArgs(std::make_unique<ParserAction>(),
				       "unused",
				       llvm::vfs::getRealFileSystem(),
				       std::vector<std::string>(), file);
}
