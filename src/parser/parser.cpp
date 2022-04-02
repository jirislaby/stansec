/*
 * Copyright (c) 2021-2022 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <iostream>

#include <clang/Analysis/CallGraph.h>
#include <clang/AST/Attr.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Frontend/FrontendAction.h>
#include <clang/StaticAnalyzer/Core/Checker.h>
#include <clang/StaticAnalyzer/Core/CheckerManager.h>
#include <clang/StaticAnalyzer/Core/PathSensitive/CheckerContext.h>
#include <clang/StaticAnalyzer/Frontend/AnalysisConsumer.h>
#include <clang/StaticAnalyzer/Frontend/CheckerRegistry.h>
#include <clang/Tooling/Tooling.h>

#include "../codestructures/LazyInternalStructuresIntra.h"
#include "../codestructures/LazyInternalStructuresInter.h"
#include "../checker/Checker.h"

#include "parser.h"

using namespace clang;
using namespace ento;
using namespace parser;

namespace parser {

class ParserChecker : public Checker<check::ASTCodeBody, check::EndOfTranslationUnit> {
public:
	ParserChecker() {}

	void checkEndOfTranslationUnit(const TranslationUnitDecl *TU,
				       AnalysisManager &mgr,
				       BugReporter &) const {
		llvm::errs() << __func__ << ":\n";

		auto chkMgr = mgr.getCheckerManager();
		auto p = parserMap[&chkMgr->getAnalyzerOptions()];

#ifndef INTER
		codestructs::LazyInternalStructuresIntra LIS(mgr, TU);
#else
		codestructs::LazyInternalStructuresInter LIS(mgr, TU);
#endif

		p->check(LIS);

		//TU->dump();
		//auto &srcMgr = mgr.getSourceManager();
		for (const auto &d : TU->decls())
		    if (auto fd = llvm::dyn_cast<const FunctionDecl>(d)) {
			if (!fd->isThisDeclarationADefinition())
			    continue;
			if (/*auto nd =*/ llvm::dyn_cast<const NamedDecl>(d)) {
#if 0
			    const auto &src = d->getSourceRange();
			    const auto &start = srcMgr.getPresumedLoc(src.getBegin());
			    const auto &end = srcMgr.getPresumedLoc(src.getEnd());
			    llvm::errs() << "named: " << nd->getName() << " (" <<
					    start.getLine() << ':' << start.getColumn() <<
					    "-" << end.getLine() << ':' << end.getColumn() <<
					    ")\n";
#endif
			} else
			    d->dumpColor();
		    } /*else
			d->dumpColor();*/
	}

	void checkASTCodeBody(const Decl *D, AnalysisManager& mgr,
			BugReporter &) const {
#if 0
		llvm::errs() << __func__ << ":\n";
		class CB {
		public:
			CB(const ASTContext &ctx) : ctx(ctx) { }
			void operator()(const Stmt *s) {
			    llvm::errs() << "CB stmt=";
			    s->dumpPretty(ctx);
			    llvm::errs() << '\n';
			}
		private:
			const ASTContext &ctx;
		};


		if (auto ND = dynamic_cast<const NamedDecl *>(D)) {
			llvm::errs() << "decl is NAMED as '" << ND->getName() << "'\n";

			if (auto cfg = mgr.getCFG(D)) {
			    CB cb(D->getASTContext());
			    llvm::errs() << "dumping a CFG:\n";
			    //cfg->dump(mgr.getLangOpts(), true);
			    llvm::errs() << "dumping stmts:\n";
			    cfg->VisitBlockStmts(cb);
			    //parser->addCFG(QString::fromStdString(ND->getName().str()), cfg);
			} else {
			    llvm::errs() << "NOT a CFG:\n";
			    D->dump();
			}
		}
#endif
	}

	typedef QMap<const clang::AnalyzerOptions *, Parser *> ParserMap;
	static ParserMap parserMap;
};

ParserChecker::ParserMap ParserChecker::parserMap;

class ParserAction : public ASTFrontendAction {
private:
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
	ParserAction(Parser *parser) : parser(parser), DiagsOutput(Diags) {}

	std::unique_ptr<ASTConsumer> CreateASTConsumer(CompilerInstance &Compiler,
						       StringRef File) override {
	    std::unique_ptr<AnalysisASTConsumer> AnalysisConsumer =
		    CreateAnalysisConsumer(Compiler);
	    AnalysisConsumer->AddDiagnosticConsumer(new DiagConsumer(DiagsOutput));
	    Compiler.getDiagnostics().setIgnoreAllWarnings(true);
	    Compiler.getAnalyzerOpts()->CheckersAndPackages = {{"stanse.Parser", true}};
	    ParserChecker::parserMap[Compiler.getAnalyzerOpts().get()] = parser;
	    //auto p = parser;
	    auto reg = [](CheckerManager &mgr) {
		    mgr.registerChecker<ParserChecker>();
		};
	    auto shouldReg = [](const CheckerManager &) -> bool { return true; };
	    AnalysisConsumer->AddCheckerRegistrationFn([reg, shouldReg](CheckerRegistry &Registry) {
		Registry.addChecker(reg, shouldReg,
		    "stanse.Parser", "Parser for stanseC", "", false);
	    });
	    return std::move(AnalysisConsumer);
	}

private:
	Parser *parser;
	std::string Diags;
	llvm::raw_string_ostream DiagsOutput;

};

}

Parser::Parser(checker::CheckerProgressMonitor *monitor,
	       checker::CheckerErrorReceiver &errReceiver,
	       const QList<core::CheckerConfiguration> &checkers) :
	checkers(checkers), monitor(monitor), errReceiver(errReceiver)
{
}

Parser::~Parser()
{
}

void Parser::parseAndCheck(const std::string &fileName,
			   const std::string &code)
{
	tooling::runToolOnCode(std::make_unique<ParserAction>(this), code,
			       fileName);
}

void Parser::check(const codestructs::LazyInternalStructures &LIS)
{
	for (auto &ch: checkers)
		ch.getChecker()->check(LIS, errReceiver, *monitor);
}

#if 0
void Parser::addCFG(QString name, const clang::CFG *cfg)
{
	cfgMap.insert(name, cfg);
}
#endif
QString Parser::getDot(unsigned int line, int shrink) const
{
	return QString();
}

#if 0
void runParserOnFile(const std::string &file)
{
	llvm::errs() << "running on " << file << "\n";
	tooling::runToolOnCodeWithArgs(std::make_unique<ParserAction>(),
				       "unused",
				       llvm::vfs::getRealFileSystem(),
				       std::vector<std::string>(), file);
}
#endif
