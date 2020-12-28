
// Generated from C.g4 by ANTLR 4.8


#include "CListener.h"
#include "CVisitor.h"

#include "CParser.h"


using namespace antlrcpp;
using namespace antlr4;

CParser::CParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

CParser::~CParser() {
  delete _interpreter;
}

std::string CParser::getGrammarFileName() const {
  return "C.g4";
}

const std::vector<std::string>& CParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& CParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- PrimaryExpressionContext ------------------------------------------------------------------

CParser::PrimaryExpressionContext::PrimaryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::PrimaryExpressionContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}

tree::TerminalNode* CParser::PrimaryExpressionContext::Constant() {
  return getToken(CParser::Constant, 0);
}

std::vector<tree::TerminalNode *> CParser::PrimaryExpressionContext::StringLiteral() {
  return getTokens(CParser::StringLiteral);
}

tree::TerminalNode* CParser::PrimaryExpressionContext::StringLiteral(size_t i) {
  return getToken(CParser::StringLiteral, i);
}

tree::TerminalNode* CParser::PrimaryExpressionContext::LeftParen() {
  return getToken(CParser::LeftParen, 0);
}

CParser::ExpressionContext* CParser::PrimaryExpressionContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}

tree::TerminalNode* CParser::PrimaryExpressionContext::RightParen() {
  return getToken(CParser::RightParen, 0);
}

CParser::GenericSelectionContext* CParser::PrimaryExpressionContext::genericSelection() {
  return getRuleContext<CParser::GenericSelectionContext>(0);
}

CParser::CompoundStatementContext* CParser::PrimaryExpressionContext::compoundStatement() {
  return getRuleContext<CParser::CompoundStatementContext>(0);
}

CParser::UnaryExpressionContext* CParser::PrimaryExpressionContext::unaryExpression() {
  return getRuleContext<CParser::UnaryExpressionContext>(0);
}

tree::TerminalNode* CParser::PrimaryExpressionContext::Comma() {
  return getToken(CParser::Comma, 0);
}

CParser::TypeNameContext* CParser::PrimaryExpressionContext::typeName() {
  return getRuleContext<CParser::TypeNameContext>(0);
}


size_t CParser::PrimaryExpressionContext::getRuleIndex() const {
  return CParser::RulePrimaryExpression;
}

void CParser::PrimaryExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryExpression(this);
}

void CParser::PrimaryExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryExpression(this);
}


antlrcpp::Any CParser::PrimaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitPrimaryExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::PrimaryExpressionContext* CParser::primaryExpression() {
  PrimaryExpressionContext *_localctx = _tracker.createInstance<PrimaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 0, CParser::RulePrimaryExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(225);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(192);
      match(CParser::Identifier);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(193);
      match(CParser::Constant);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(195); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(194);
                match(CParser::StringLiteral);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(197); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(199);
      match(CParser::LeftParen);
      setState(200);
      expression(0);
      setState(201);
      match(CParser::RightParen);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(203);
      genericSelection();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(205);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::T__0) {
        setState(204);
        match(CParser::T__0);
      }
      setState(207);
      match(CParser::LeftParen);
      setState(208);
      compoundStatement();
      setState(209);
      match(CParser::RightParen);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(211);
      match(CParser::T__1);
      setState(212);
      match(CParser::LeftParen);
      setState(213);
      unaryExpression();
      setState(214);
      match(CParser::Comma);
      setState(215);
      typeName();
      setState(216);
      match(CParser::RightParen);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(218);
      match(CParser::T__2);
      setState(219);
      match(CParser::LeftParen);
      setState(220);
      typeName();
      setState(221);
      match(CParser::Comma);
      setState(222);
      unaryExpression();
      setState(223);
      match(CParser::RightParen);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GenericSelectionContext ------------------------------------------------------------------

CParser::GenericSelectionContext::GenericSelectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::GenericSelectionContext::Generic() {
  return getToken(CParser::Generic, 0);
}

tree::TerminalNode* CParser::GenericSelectionContext::LeftParen() {
  return getToken(CParser::LeftParen, 0);
}

CParser::AssignmentExpressionContext* CParser::GenericSelectionContext::assignmentExpression() {
  return getRuleContext<CParser::AssignmentExpressionContext>(0);
}

tree::TerminalNode* CParser::GenericSelectionContext::Comma() {
  return getToken(CParser::Comma, 0);
}

CParser::GenericAssocListContext* CParser::GenericSelectionContext::genericAssocList() {
  return getRuleContext<CParser::GenericAssocListContext>(0);
}

tree::TerminalNode* CParser::GenericSelectionContext::RightParen() {
  return getToken(CParser::RightParen, 0);
}


size_t CParser::GenericSelectionContext::getRuleIndex() const {
  return CParser::RuleGenericSelection;
}

void CParser::GenericSelectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGenericSelection(this);
}

void CParser::GenericSelectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGenericSelection(this);
}


antlrcpp::Any CParser::GenericSelectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitGenericSelection(this);
  else
    return visitor->visitChildren(this);
}

CParser::GenericSelectionContext* CParser::genericSelection() {
  GenericSelectionContext *_localctx = _tracker.createInstance<GenericSelectionContext>(_ctx, getState());
  enterRule(_localctx, 2, CParser::RuleGenericSelection);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(227);
    match(CParser::Generic);
    setState(228);
    match(CParser::LeftParen);
    setState(229);
    assignmentExpression();
    setState(230);
    match(CParser::Comma);
    setState(231);
    genericAssocList(0);
    setState(232);
    match(CParser::RightParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GenericAssocListContext ------------------------------------------------------------------

CParser::GenericAssocListContext::GenericAssocListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::GenericAssociationContext* CParser::GenericAssocListContext::genericAssociation() {
  return getRuleContext<CParser::GenericAssociationContext>(0);
}

CParser::GenericAssocListContext* CParser::GenericAssocListContext::genericAssocList() {
  return getRuleContext<CParser::GenericAssocListContext>(0);
}

tree::TerminalNode* CParser::GenericAssocListContext::Comma() {
  return getToken(CParser::Comma, 0);
}


size_t CParser::GenericAssocListContext::getRuleIndex() const {
  return CParser::RuleGenericAssocList;
}

void CParser::GenericAssocListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGenericAssocList(this);
}

void CParser::GenericAssocListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGenericAssocList(this);
}


antlrcpp::Any CParser::GenericAssocListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitGenericAssocList(this);
  else
    return visitor->visitChildren(this);
}


CParser::GenericAssocListContext* CParser::genericAssocList() {
   return genericAssocList(0);
}

CParser::GenericAssocListContext* CParser::genericAssocList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::GenericAssocListContext *_localctx = _tracker.createInstance<GenericAssocListContext>(_ctx, parentState);
  CParser::GenericAssocListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, CParser::RuleGenericAssocList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(235);
    genericAssociation();
    _ctx->stop = _input->LT(-1);
    setState(242);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<GenericAssocListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleGenericAssocList);
        setState(237);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(238);
        match(CParser::Comma);
        setState(239);
        genericAssociation(); 
      }
      setState(244);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- GenericAssociationContext ------------------------------------------------------------------

CParser::GenericAssociationContext::GenericAssociationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::TypeNameContext* CParser::GenericAssociationContext::typeName() {
  return getRuleContext<CParser::TypeNameContext>(0);
}

tree::TerminalNode* CParser::GenericAssociationContext::Colon() {
  return getToken(CParser::Colon, 0);
}

CParser::AssignmentExpressionContext* CParser::GenericAssociationContext::assignmentExpression() {
  return getRuleContext<CParser::AssignmentExpressionContext>(0);
}

tree::TerminalNode* CParser::GenericAssociationContext::Default() {
  return getToken(CParser::Default, 0);
}


size_t CParser::GenericAssociationContext::getRuleIndex() const {
  return CParser::RuleGenericAssociation;
}

void CParser::GenericAssociationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGenericAssociation(this);
}

void CParser::GenericAssociationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGenericAssociation(this);
}


antlrcpp::Any CParser::GenericAssociationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitGenericAssociation(this);
  else
    return visitor->visitChildren(this);
}

CParser::GenericAssociationContext* CParser::genericAssociation() {
  GenericAssociationContext *_localctx = _tracker.createInstance<GenericAssociationContext>(_ctx, getState());
  enterRule(_localctx, 6, CParser::RuleGenericAssociation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(252);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::T__0:
      case CParser::T__4:
      case CParser::T__5:
      case CParser::T__6:
      case CParser::T__7:
      case CParser::T__8:
      case CParser::T__9:
      case CParser::Char:
      case CParser::Const:
      case CParser::Double:
      case CParser::Enum:
      case CParser::Float:
      case CParser::Int:
      case CParser::Long:
      case CParser::Restrict:
      case CParser::Short:
      case CParser::Signed:
      case CParser::Struct:
      case CParser::Typeof:
      case CParser::Union:
      case CParser::Unsigned:
      case CParser::Void:
      case CParser::Volatile:
      case CParser::Atomic:
      case CParser::Bool:
      case CParser::Complex:
      case CParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(245);
        typeName();
        setState(246);
        match(CParser::Colon);
        setState(247);
        assignmentExpression();
        break;
      }

      case CParser::Default: {
        enterOuterAlt(_localctx, 2);
        setState(249);
        match(CParser::Default);
        setState(250);
        match(CParser::Colon);
        setState(251);
        assignmentExpression();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PostfixExpressionContext ------------------------------------------------------------------

CParser::PostfixExpressionContext::PostfixExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::PrimaryExpressionContext* CParser::PostfixExpressionContext::primaryExpression() {
  return getRuleContext<CParser::PrimaryExpressionContext>(0);
}

tree::TerminalNode* CParser::PostfixExpressionContext::LeftParen() {
  return getToken(CParser::LeftParen, 0);
}

CParser::TypeNameContext* CParser::PostfixExpressionContext::typeName() {
  return getRuleContext<CParser::TypeNameContext>(0);
}

tree::TerminalNode* CParser::PostfixExpressionContext::RightParen() {
  return getToken(CParser::RightParen, 0);
}

tree::TerminalNode* CParser::PostfixExpressionContext::LeftBrace() {
  return getToken(CParser::LeftBrace, 0);
}

CParser::InitializerListContext* CParser::PostfixExpressionContext::initializerList() {
  return getRuleContext<CParser::InitializerListContext>(0);
}

tree::TerminalNode* CParser::PostfixExpressionContext::RightBrace() {
  return getToken(CParser::RightBrace, 0);
}

tree::TerminalNode* CParser::PostfixExpressionContext::Comma() {
  return getToken(CParser::Comma, 0);
}

CParser::PostfixExpressionContext* CParser::PostfixExpressionContext::postfixExpression() {
  return getRuleContext<CParser::PostfixExpressionContext>(0);
}

tree::TerminalNode* CParser::PostfixExpressionContext::LeftBracket() {
  return getToken(CParser::LeftBracket, 0);
}

CParser::ExpressionContext* CParser::PostfixExpressionContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}

tree::TerminalNode* CParser::PostfixExpressionContext::RightBracket() {
  return getToken(CParser::RightBracket, 0);
}

CParser::ArgumentExpressionListContext* CParser::PostfixExpressionContext::argumentExpressionList() {
  return getRuleContext<CParser::ArgumentExpressionListContext>(0);
}

tree::TerminalNode* CParser::PostfixExpressionContext::Dot() {
  return getToken(CParser::Dot, 0);
}

tree::TerminalNode* CParser::PostfixExpressionContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}

tree::TerminalNode* CParser::PostfixExpressionContext::Arrow() {
  return getToken(CParser::Arrow, 0);
}

tree::TerminalNode* CParser::PostfixExpressionContext::PlusPlus() {
  return getToken(CParser::PlusPlus, 0);
}

tree::TerminalNode* CParser::PostfixExpressionContext::MinusMinus() {
  return getToken(CParser::MinusMinus, 0);
}


size_t CParser::PostfixExpressionContext::getRuleIndex() const {
  return CParser::RulePostfixExpression;
}

void CParser::PostfixExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPostfixExpression(this);
}

void CParser::PostfixExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPostfixExpression(this);
}


antlrcpp::Any CParser::PostfixExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitPostfixExpression(this);
  else
    return visitor->visitChildren(this);
}


CParser::PostfixExpressionContext* CParser::postfixExpression() {
   return postfixExpression(0);
}

CParser::PostfixExpressionContext* CParser::postfixExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::PostfixExpressionContext *_localctx = _tracker.createInstance<PostfixExpressionContext>(_ctx, parentState);
  CParser::PostfixExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 8;
  enterRecursionRule(_localctx, 8, CParser::RulePostfixExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(288);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      setState(255);
      primaryExpression();
      break;
    }

    case 2: {
      setState(256);
      match(CParser::LeftParen);
      setState(257);
      typeName();
      setState(258);
      match(CParser::RightParen);
      setState(259);
      match(CParser::LeftBrace);
      setState(260);
      initializerList(0);
      setState(261);
      match(CParser::RightBrace);
      break;
    }

    case 3: {
      setState(263);
      match(CParser::LeftParen);
      setState(264);
      typeName();
      setState(265);
      match(CParser::RightParen);
      setState(266);
      match(CParser::LeftBrace);
      setState(267);
      initializerList(0);
      setState(268);
      match(CParser::Comma);
      setState(269);
      match(CParser::RightBrace);
      break;
    }

    case 4: {
      setState(271);
      match(CParser::T__0);
      setState(272);
      match(CParser::LeftParen);
      setState(273);
      typeName();
      setState(274);
      match(CParser::RightParen);
      setState(275);
      match(CParser::LeftBrace);
      setState(276);
      initializerList(0);
      setState(277);
      match(CParser::RightBrace);
      break;
    }

    case 5: {
      setState(279);
      match(CParser::T__0);
      setState(280);
      match(CParser::LeftParen);
      setState(281);
      typeName();
      setState(282);
      match(CParser::RightParen);
      setState(283);
      match(CParser::LeftBrace);
      setState(284);
      initializerList(0);
      setState(285);
      match(CParser::Comma);
      setState(286);
      match(CParser::RightBrace);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(313);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(311);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(290);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(291);
          match(CParser::LeftBracket);
          setState(292);
          expression(0);
          setState(293);
          match(CParser::RightBracket);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(295);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(296);
          match(CParser::LeftParen);
          setState(298);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CParser::T__0)
            | (1ULL << CParser::T__1)
            | (1ULL << CParser::T__2)
            | (1ULL << CParser::T__3)
            | (1ULL << CParser::Sizeof)
            | (1ULL << CParser::Alignof)
            | (1ULL << CParser::Generic)
            | (1ULL << CParser::LeftParen))) != 0) || ((((_la - 75) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 75)) & ((1ULL << (CParser::Plus - 75))
            | (1ULL << (CParser::PlusPlus - 75))
            | (1ULL << (CParser::Minus - 75))
            | (1ULL << (CParser::MinusMinus - 75))
            | (1ULL << (CParser::Star - 75))
            | (1ULL << (CParser::And - 75))
            | (1ULL << (CParser::AndAnd - 75))
            | (1ULL << (CParser::Not - 75))
            | (1ULL << (CParser::Tilde - 75))
            | (1ULL << (CParser::Identifier - 75))
            | (1ULL << (CParser::Constant - 75))
            | (1ULL << (CParser::DigitSequence - 75))
            | (1ULL << (CParser::StringLiteral - 75)))) != 0)) {
            setState(297);
            argumentExpressionList(0);
          }
          setState(300);
          match(CParser::RightParen);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(301);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(302);
          match(CParser::Dot);
          setState(303);
          match(CParser::Identifier);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(304);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(305);
          match(CParser::Arrow);
          setState(306);
          match(CParser::Identifier);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(307);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(308);
          match(CParser::PlusPlus);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(309);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(310);
          match(CParser::MinusMinus);
          break;
        }

        } 
      }
      setState(315);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ArgumentExpressionListContext ------------------------------------------------------------------

CParser::ArgumentExpressionListContext::ArgumentExpressionListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::AssignmentExpressionContext* CParser::ArgumentExpressionListContext::assignmentExpression() {
  return getRuleContext<CParser::AssignmentExpressionContext>(0);
}

CParser::ArgumentExpressionListContext* CParser::ArgumentExpressionListContext::argumentExpressionList() {
  return getRuleContext<CParser::ArgumentExpressionListContext>(0);
}

tree::TerminalNode* CParser::ArgumentExpressionListContext::Comma() {
  return getToken(CParser::Comma, 0);
}


size_t CParser::ArgumentExpressionListContext::getRuleIndex() const {
  return CParser::RuleArgumentExpressionList;
}

void CParser::ArgumentExpressionListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgumentExpressionList(this);
}

void CParser::ArgumentExpressionListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgumentExpressionList(this);
}


antlrcpp::Any CParser::ArgumentExpressionListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitArgumentExpressionList(this);
  else
    return visitor->visitChildren(this);
}


CParser::ArgumentExpressionListContext* CParser::argumentExpressionList() {
   return argumentExpressionList(0);
}

CParser::ArgumentExpressionListContext* CParser::argumentExpressionList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::ArgumentExpressionListContext *_localctx = _tracker.createInstance<ArgumentExpressionListContext>(_ctx, parentState);
  CParser::ArgumentExpressionListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, CParser::RuleArgumentExpressionList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(317);
    assignmentExpression();
    _ctx->stop = _input->LT(-1);
    setState(324);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ArgumentExpressionListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleArgumentExpressionList);
        setState(319);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(320);
        match(CParser::Comma);
        setState(321);
        assignmentExpression(); 
      }
      setState(326);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnaryExpressionContext ------------------------------------------------------------------

CParser::UnaryExpressionContext::UnaryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::PostfixExpressionContext* CParser::UnaryExpressionContext::postfixExpression() {
  return getRuleContext<CParser::PostfixExpressionContext>(0);
}

tree::TerminalNode* CParser::UnaryExpressionContext::PlusPlus() {
  return getToken(CParser::PlusPlus, 0);
}

CParser::UnaryExpressionContext* CParser::UnaryExpressionContext::unaryExpression() {
  return getRuleContext<CParser::UnaryExpressionContext>(0);
}

tree::TerminalNode* CParser::UnaryExpressionContext::MinusMinus() {
  return getToken(CParser::MinusMinus, 0);
}

CParser::UnaryOperatorContext* CParser::UnaryExpressionContext::unaryOperator() {
  return getRuleContext<CParser::UnaryOperatorContext>(0);
}

CParser::CastExpressionContext* CParser::UnaryExpressionContext::castExpression() {
  return getRuleContext<CParser::CastExpressionContext>(0);
}

tree::TerminalNode* CParser::UnaryExpressionContext::Sizeof() {
  return getToken(CParser::Sizeof, 0);
}

tree::TerminalNode* CParser::UnaryExpressionContext::LeftParen() {
  return getToken(CParser::LeftParen, 0);
}

CParser::TypeNameContext* CParser::UnaryExpressionContext::typeName() {
  return getRuleContext<CParser::TypeNameContext>(0);
}

tree::TerminalNode* CParser::UnaryExpressionContext::RightParen() {
  return getToken(CParser::RightParen, 0);
}

tree::TerminalNode* CParser::UnaryExpressionContext::Alignof() {
  return getToken(CParser::Alignof, 0);
}

tree::TerminalNode* CParser::UnaryExpressionContext::AndAnd() {
  return getToken(CParser::AndAnd, 0);
}

tree::TerminalNode* CParser::UnaryExpressionContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}


size_t CParser::UnaryExpressionContext::getRuleIndex() const {
  return CParser::RuleUnaryExpression;
}

void CParser::UnaryExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryExpression(this);
}

void CParser::UnaryExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryExpression(this);
}


antlrcpp::Any CParser::UnaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitUnaryExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::UnaryExpressionContext* CParser::unaryExpression() {
  UnaryExpressionContext *_localctx = _tracker.createInstance<UnaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 12, CParser::RuleUnaryExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(349);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(327);
      postfixExpression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(328);
      match(CParser::PlusPlus);
      setState(329);
      unaryExpression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(330);
      match(CParser::MinusMinus);
      setState(331);
      unaryExpression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(332);
      unaryOperator();
      setState(333);
      castExpression();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(335);
      match(CParser::Sizeof);
      setState(336);
      unaryExpression();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(337);
      match(CParser::Sizeof);
      setState(338);
      match(CParser::LeftParen);
      setState(339);
      typeName();
      setState(340);
      match(CParser::RightParen);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(342);
      _la = _input->LA(1);
      if (!(_la == CParser::T__3

      || _la == CParser::Alignof)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(343);
      match(CParser::LeftParen);
      setState(344);
      typeName();
      setState(345);
      match(CParser::RightParen);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(347);
      match(CParser::AndAnd);
      setState(348);
      match(CParser::Identifier);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryOperatorContext ------------------------------------------------------------------

CParser::UnaryOperatorContext::UnaryOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::UnaryOperatorContext::And() {
  return getToken(CParser::And, 0);
}

tree::TerminalNode* CParser::UnaryOperatorContext::Star() {
  return getToken(CParser::Star, 0);
}

tree::TerminalNode* CParser::UnaryOperatorContext::Plus() {
  return getToken(CParser::Plus, 0);
}

tree::TerminalNode* CParser::UnaryOperatorContext::Minus() {
  return getToken(CParser::Minus, 0);
}

tree::TerminalNode* CParser::UnaryOperatorContext::Tilde() {
  return getToken(CParser::Tilde, 0);
}

tree::TerminalNode* CParser::UnaryOperatorContext::Not() {
  return getToken(CParser::Not, 0);
}


size_t CParser::UnaryOperatorContext::getRuleIndex() const {
  return CParser::RuleUnaryOperator;
}

void CParser::UnaryOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryOperator(this);
}

void CParser::UnaryOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryOperator(this);
}


antlrcpp::Any CParser::UnaryOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitUnaryOperator(this);
  else
    return visitor->visitChildren(this);
}

CParser::UnaryOperatorContext* CParser::unaryOperator() {
  UnaryOperatorContext *_localctx = _tracker.createInstance<UnaryOperatorContext>(_ctx, getState());
  enterRule(_localctx, 14, CParser::RuleUnaryOperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(351);
    _la = _input->LA(1);
    if (!(((((_la - 75) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 75)) & ((1ULL << (CParser::Plus - 75))
      | (1ULL << (CParser::Minus - 75))
      | (1ULL << (CParser::Star - 75))
      | (1ULL << (CParser::And - 75))
      | (1ULL << (CParser::Not - 75))
      | (1ULL << (CParser::Tilde - 75)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CastExpressionContext ------------------------------------------------------------------

CParser::CastExpressionContext::CastExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::CastExpressionContext::LeftParen() {
  return getToken(CParser::LeftParen, 0);
}

CParser::TypeNameContext* CParser::CastExpressionContext::typeName() {
  return getRuleContext<CParser::TypeNameContext>(0);
}

tree::TerminalNode* CParser::CastExpressionContext::RightParen() {
  return getToken(CParser::RightParen, 0);
}

CParser::CastExpressionContext* CParser::CastExpressionContext::castExpression() {
  return getRuleContext<CParser::CastExpressionContext>(0);
}

CParser::UnaryExpressionContext* CParser::CastExpressionContext::unaryExpression() {
  return getRuleContext<CParser::UnaryExpressionContext>(0);
}

tree::TerminalNode* CParser::CastExpressionContext::DigitSequence() {
  return getToken(CParser::DigitSequence, 0);
}


size_t CParser::CastExpressionContext::getRuleIndex() const {
  return CParser::RuleCastExpression;
}

void CParser::CastExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCastExpression(this);
}

void CParser::CastExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCastExpression(this);
}


antlrcpp::Any CParser::CastExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitCastExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::CastExpressionContext* CParser::castExpression() {
  CastExpressionContext *_localctx = _tracker.createInstance<CastExpressionContext>(_ctx, getState());
  enterRule(_localctx, 16, CParser::RuleCastExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(366);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(353);
      match(CParser::LeftParen);
      setState(354);
      typeName();
      setState(355);
      match(CParser::RightParen);
      setState(356);
      castExpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(358);
      match(CParser::T__0);
      setState(359);
      match(CParser::LeftParen);
      setState(360);
      typeName();
      setState(361);
      match(CParser::RightParen);
      setState(362);
      castExpression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(364);
      unaryExpression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(365);
      match(CParser::DigitSequence);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MultiplicativeExpressionContext ------------------------------------------------------------------

CParser::MultiplicativeExpressionContext::MultiplicativeExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::CastExpressionContext* CParser::MultiplicativeExpressionContext::castExpression() {
  return getRuleContext<CParser::CastExpressionContext>(0);
}

CParser::MultiplicativeExpressionContext* CParser::MultiplicativeExpressionContext::multiplicativeExpression() {
  return getRuleContext<CParser::MultiplicativeExpressionContext>(0);
}

tree::TerminalNode* CParser::MultiplicativeExpressionContext::Star() {
  return getToken(CParser::Star, 0);
}

tree::TerminalNode* CParser::MultiplicativeExpressionContext::Div() {
  return getToken(CParser::Div, 0);
}

tree::TerminalNode* CParser::MultiplicativeExpressionContext::Mod() {
  return getToken(CParser::Mod, 0);
}


size_t CParser::MultiplicativeExpressionContext::getRuleIndex() const {
  return CParser::RuleMultiplicativeExpression;
}

void CParser::MultiplicativeExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiplicativeExpression(this);
}

void CParser::MultiplicativeExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiplicativeExpression(this);
}


antlrcpp::Any CParser::MultiplicativeExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitMultiplicativeExpression(this);
  else
    return visitor->visitChildren(this);
}


CParser::MultiplicativeExpressionContext* CParser::multiplicativeExpression() {
   return multiplicativeExpression(0);
}

CParser::MultiplicativeExpressionContext* CParser::multiplicativeExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::MultiplicativeExpressionContext *_localctx = _tracker.createInstance<MultiplicativeExpressionContext>(_ctx, parentState);
  CParser::MultiplicativeExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 18;
  enterRecursionRule(_localctx, 18, CParser::RuleMultiplicativeExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(369);
    castExpression();
    _ctx->stop = _input->LT(-1);
    setState(382);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(380);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<MultiplicativeExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleMultiplicativeExpression);
          setState(371);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(372);
          match(CParser::Star);
          setState(373);
          castExpression();
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<MultiplicativeExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleMultiplicativeExpression);
          setState(374);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(375);
          match(CParser::Div);
          setState(376);
          castExpression();
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<MultiplicativeExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleMultiplicativeExpression);
          setState(377);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(378);
          match(CParser::Mod);
          setState(379);
          castExpression();
          break;
        }

        } 
      }
      setState(384);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AdditiveExpressionContext ------------------------------------------------------------------

CParser::AdditiveExpressionContext::AdditiveExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::MultiplicativeExpressionContext* CParser::AdditiveExpressionContext::multiplicativeExpression() {
  return getRuleContext<CParser::MultiplicativeExpressionContext>(0);
}

CParser::AdditiveExpressionContext* CParser::AdditiveExpressionContext::additiveExpression() {
  return getRuleContext<CParser::AdditiveExpressionContext>(0);
}

tree::TerminalNode* CParser::AdditiveExpressionContext::Plus() {
  return getToken(CParser::Plus, 0);
}

tree::TerminalNode* CParser::AdditiveExpressionContext::Minus() {
  return getToken(CParser::Minus, 0);
}


size_t CParser::AdditiveExpressionContext::getRuleIndex() const {
  return CParser::RuleAdditiveExpression;
}

void CParser::AdditiveExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdditiveExpression(this);
}

void CParser::AdditiveExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdditiveExpression(this);
}


antlrcpp::Any CParser::AdditiveExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitAdditiveExpression(this);
  else
    return visitor->visitChildren(this);
}


CParser::AdditiveExpressionContext* CParser::additiveExpression() {
   return additiveExpression(0);
}

CParser::AdditiveExpressionContext* CParser::additiveExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::AdditiveExpressionContext *_localctx = _tracker.createInstance<AdditiveExpressionContext>(_ctx, parentState);
  CParser::AdditiveExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, CParser::RuleAdditiveExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(386);
    multiplicativeExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(396);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(394);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<AdditiveExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleAdditiveExpression);
          setState(388);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(389);
          match(CParser::Plus);
          setState(390);
          multiplicativeExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<AdditiveExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleAdditiveExpression);
          setState(391);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(392);
          match(CParser::Minus);
          setState(393);
          multiplicativeExpression(0);
          break;
        }

        } 
      }
      setState(398);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ShiftExpressionContext ------------------------------------------------------------------

CParser::ShiftExpressionContext::ShiftExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::AdditiveExpressionContext* CParser::ShiftExpressionContext::additiveExpression() {
  return getRuleContext<CParser::AdditiveExpressionContext>(0);
}

CParser::ShiftExpressionContext* CParser::ShiftExpressionContext::shiftExpression() {
  return getRuleContext<CParser::ShiftExpressionContext>(0);
}

tree::TerminalNode* CParser::ShiftExpressionContext::LeftShift() {
  return getToken(CParser::LeftShift, 0);
}

tree::TerminalNode* CParser::ShiftExpressionContext::RightShift() {
  return getToken(CParser::RightShift, 0);
}


size_t CParser::ShiftExpressionContext::getRuleIndex() const {
  return CParser::RuleShiftExpression;
}

void CParser::ShiftExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShiftExpression(this);
}

void CParser::ShiftExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShiftExpression(this);
}


antlrcpp::Any CParser::ShiftExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitShiftExpression(this);
  else
    return visitor->visitChildren(this);
}


CParser::ShiftExpressionContext* CParser::shiftExpression() {
   return shiftExpression(0);
}

CParser::ShiftExpressionContext* CParser::shiftExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::ShiftExpressionContext *_localctx = _tracker.createInstance<ShiftExpressionContext>(_ctx, parentState);
  CParser::ShiftExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, CParser::RuleShiftExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(400);
    additiveExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(410);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(408);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ShiftExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleShiftExpression);
          setState(402);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(403);
          match(CParser::LeftShift);
          setState(404);
          additiveExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ShiftExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleShiftExpression);
          setState(405);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(406);
          match(CParser::RightShift);
          setState(407);
          additiveExpression(0);
          break;
        }

        } 
      }
      setState(412);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- RelationalExpressionContext ------------------------------------------------------------------

CParser::RelationalExpressionContext::RelationalExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ShiftExpressionContext* CParser::RelationalExpressionContext::shiftExpression() {
  return getRuleContext<CParser::ShiftExpressionContext>(0);
}

CParser::RelationalExpressionContext* CParser::RelationalExpressionContext::relationalExpression() {
  return getRuleContext<CParser::RelationalExpressionContext>(0);
}

tree::TerminalNode* CParser::RelationalExpressionContext::Less() {
  return getToken(CParser::Less, 0);
}

tree::TerminalNode* CParser::RelationalExpressionContext::Greater() {
  return getToken(CParser::Greater, 0);
}

tree::TerminalNode* CParser::RelationalExpressionContext::LessEqual() {
  return getToken(CParser::LessEqual, 0);
}

tree::TerminalNode* CParser::RelationalExpressionContext::GreaterEqual() {
  return getToken(CParser::GreaterEqual, 0);
}


size_t CParser::RelationalExpressionContext::getRuleIndex() const {
  return CParser::RuleRelationalExpression;
}

void CParser::RelationalExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationalExpression(this);
}

void CParser::RelationalExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationalExpression(this);
}


antlrcpp::Any CParser::RelationalExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitRelationalExpression(this);
  else
    return visitor->visitChildren(this);
}


CParser::RelationalExpressionContext* CParser::relationalExpression() {
   return relationalExpression(0);
}

CParser::RelationalExpressionContext* CParser::relationalExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::RelationalExpressionContext *_localctx = _tracker.createInstance<RelationalExpressionContext>(_ctx, parentState);
  CParser::RelationalExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 24;
  enterRecursionRule(_localctx, 24, CParser::RuleRelationalExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(414);
    shiftExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(430);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(428);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelationalExpression);
          setState(416);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(417);
          match(CParser::Less);
          setState(418);
          shiftExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelationalExpression);
          setState(419);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(420);
          match(CParser::Greater);
          setState(421);
          shiftExpression(0);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelationalExpression);
          setState(422);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(423);
          match(CParser::LessEqual);
          setState(424);
          shiftExpression(0);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelationalExpression);
          setState(425);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(426);
          match(CParser::GreaterEqual);
          setState(427);
          shiftExpression(0);
          break;
        }

        } 
      }
      setState(432);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- EqualityExpressionContext ------------------------------------------------------------------

CParser::EqualityExpressionContext::EqualityExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::RelationalExpressionContext* CParser::EqualityExpressionContext::relationalExpression() {
  return getRuleContext<CParser::RelationalExpressionContext>(0);
}

CParser::EqualityExpressionContext* CParser::EqualityExpressionContext::equalityExpression() {
  return getRuleContext<CParser::EqualityExpressionContext>(0);
}

tree::TerminalNode* CParser::EqualityExpressionContext::Equal() {
  return getToken(CParser::Equal, 0);
}

tree::TerminalNode* CParser::EqualityExpressionContext::NotEqual() {
  return getToken(CParser::NotEqual, 0);
}


size_t CParser::EqualityExpressionContext::getRuleIndex() const {
  return CParser::RuleEqualityExpression;
}

void CParser::EqualityExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqualityExpression(this);
}

void CParser::EqualityExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqualityExpression(this);
}


antlrcpp::Any CParser::EqualityExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitEqualityExpression(this);
  else
    return visitor->visitChildren(this);
}


CParser::EqualityExpressionContext* CParser::equalityExpression() {
   return equalityExpression(0);
}

CParser::EqualityExpressionContext* CParser::equalityExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::EqualityExpressionContext *_localctx = _tracker.createInstance<EqualityExpressionContext>(_ctx, parentState);
  CParser::EqualityExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 26;
  enterRecursionRule(_localctx, 26, CParser::RuleEqualityExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(434);
    relationalExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(444);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(442);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<EqualityExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleEqualityExpression);
          setState(436);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(437);
          match(CParser::Equal);
          setState(438);
          relationalExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<EqualityExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleEqualityExpression);
          setState(439);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(440);
          match(CParser::NotEqual);
          setState(441);
          relationalExpression(0);
          break;
        }

        } 
      }
      setState(446);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AndExpressionContext ------------------------------------------------------------------

CParser::AndExpressionContext::AndExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::EqualityExpressionContext* CParser::AndExpressionContext::equalityExpression() {
  return getRuleContext<CParser::EqualityExpressionContext>(0);
}

CParser::AndExpressionContext* CParser::AndExpressionContext::andExpression() {
  return getRuleContext<CParser::AndExpressionContext>(0);
}

tree::TerminalNode* CParser::AndExpressionContext::And() {
  return getToken(CParser::And, 0);
}


size_t CParser::AndExpressionContext::getRuleIndex() const {
  return CParser::RuleAndExpression;
}

void CParser::AndExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAndExpression(this);
}

void CParser::AndExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAndExpression(this);
}


antlrcpp::Any CParser::AndExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitAndExpression(this);
  else
    return visitor->visitChildren(this);
}


CParser::AndExpressionContext* CParser::andExpression() {
   return andExpression(0);
}

CParser::AndExpressionContext* CParser::andExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::AndExpressionContext *_localctx = _tracker.createInstance<AndExpressionContext>(_ctx, parentState);
  CParser::AndExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 28;
  enterRecursionRule(_localctx, 28, CParser::RuleAndExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(448);
    equalityExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(455);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<AndExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleAndExpression);
        setState(450);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(451);
        match(CParser::And);
        setState(452);
        equalityExpression(0); 
      }
      setState(457);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ExclusiveOrExpressionContext ------------------------------------------------------------------

CParser::ExclusiveOrExpressionContext::ExclusiveOrExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::AndExpressionContext* CParser::ExclusiveOrExpressionContext::andExpression() {
  return getRuleContext<CParser::AndExpressionContext>(0);
}

CParser::ExclusiveOrExpressionContext* CParser::ExclusiveOrExpressionContext::exclusiveOrExpression() {
  return getRuleContext<CParser::ExclusiveOrExpressionContext>(0);
}

tree::TerminalNode* CParser::ExclusiveOrExpressionContext::Caret() {
  return getToken(CParser::Caret, 0);
}


size_t CParser::ExclusiveOrExpressionContext::getRuleIndex() const {
  return CParser::RuleExclusiveOrExpression;
}

void CParser::ExclusiveOrExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExclusiveOrExpression(this);
}

void CParser::ExclusiveOrExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExclusiveOrExpression(this);
}


antlrcpp::Any CParser::ExclusiveOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitExclusiveOrExpression(this);
  else
    return visitor->visitChildren(this);
}


CParser::ExclusiveOrExpressionContext* CParser::exclusiveOrExpression() {
   return exclusiveOrExpression(0);
}

CParser::ExclusiveOrExpressionContext* CParser::exclusiveOrExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::ExclusiveOrExpressionContext *_localctx = _tracker.createInstance<ExclusiveOrExpressionContext>(_ctx, parentState);
  CParser::ExclusiveOrExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 30;
  enterRecursionRule(_localctx, 30, CParser::RuleExclusiveOrExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(459);
    andExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(466);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExclusiveOrExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExclusiveOrExpression);
        setState(461);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(462);
        match(CParser::Caret);
        setState(463);
        andExpression(0); 
      }
      setState(468);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- InclusiveOrExpressionContext ------------------------------------------------------------------

CParser::InclusiveOrExpressionContext::InclusiveOrExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ExclusiveOrExpressionContext* CParser::InclusiveOrExpressionContext::exclusiveOrExpression() {
  return getRuleContext<CParser::ExclusiveOrExpressionContext>(0);
}

CParser::InclusiveOrExpressionContext* CParser::InclusiveOrExpressionContext::inclusiveOrExpression() {
  return getRuleContext<CParser::InclusiveOrExpressionContext>(0);
}

tree::TerminalNode* CParser::InclusiveOrExpressionContext::Or() {
  return getToken(CParser::Or, 0);
}


size_t CParser::InclusiveOrExpressionContext::getRuleIndex() const {
  return CParser::RuleInclusiveOrExpression;
}

void CParser::InclusiveOrExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInclusiveOrExpression(this);
}

void CParser::InclusiveOrExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInclusiveOrExpression(this);
}


antlrcpp::Any CParser::InclusiveOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitInclusiveOrExpression(this);
  else
    return visitor->visitChildren(this);
}


CParser::InclusiveOrExpressionContext* CParser::inclusiveOrExpression() {
   return inclusiveOrExpression(0);
}

CParser::InclusiveOrExpressionContext* CParser::inclusiveOrExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::InclusiveOrExpressionContext *_localctx = _tracker.createInstance<InclusiveOrExpressionContext>(_ctx, parentState);
  CParser::InclusiveOrExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 32;
  enterRecursionRule(_localctx, 32, CParser::RuleInclusiveOrExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(470);
    exclusiveOrExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(477);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<InclusiveOrExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleInclusiveOrExpression);
        setState(472);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(473);
        match(CParser::Or);
        setState(474);
        exclusiveOrExpression(0); 
      }
      setState(479);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LogicalAndExpressionContext ------------------------------------------------------------------

CParser::LogicalAndExpressionContext::LogicalAndExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::InclusiveOrExpressionContext* CParser::LogicalAndExpressionContext::inclusiveOrExpression() {
  return getRuleContext<CParser::InclusiveOrExpressionContext>(0);
}

CParser::LogicalAndExpressionContext* CParser::LogicalAndExpressionContext::logicalAndExpression() {
  return getRuleContext<CParser::LogicalAndExpressionContext>(0);
}

tree::TerminalNode* CParser::LogicalAndExpressionContext::AndAnd() {
  return getToken(CParser::AndAnd, 0);
}


size_t CParser::LogicalAndExpressionContext::getRuleIndex() const {
  return CParser::RuleLogicalAndExpression;
}

void CParser::LogicalAndExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalAndExpression(this);
}

void CParser::LogicalAndExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalAndExpression(this);
}


antlrcpp::Any CParser::LogicalAndExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitLogicalAndExpression(this);
  else
    return visitor->visitChildren(this);
}


CParser::LogicalAndExpressionContext* CParser::logicalAndExpression() {
   return logicalAndExpression(0);
}

CParser::LogicalAndExpressionContext* CParser::logicalAndExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::LogicalAndExpressionContext *_localctx = _tracker.createInstance<LogicalAndExpressionContext>(_ctx, parentState);
  CParser::LogicalAndExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, CParser::RuleLogicalAndExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(481);
    inclusiveOrExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(488);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LogicalAndExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogicalAndExpression);
        setState(483);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(484);
        match(CParser::AndAnd);
        setState(485);
        inclusiveOrExpression(0); 
      }
      setState(490);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LogicalOrExpressionContext ------------------------------------------------------------------

CParser::LogicalOrExpressionContext::LogicalOrExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::LogicalAndExpressionContext* CParser::LogicalOrExpressionContext::logicalAndExpression() {
  return getRuleContext<CParser::LogicalAndExpressionContext>(0);
}

CParser::LogicalOrExpressionContext* CParser::LogicalOrExpressionContext::logicalOrExpression() {
  return getRuleContext<CParser::LogicalOrExpressionContext>(0);
}

tree::TerminalNode* CParser::LogicalOrExpressionContext::OrOr() {
  return getToken(CParser::OrOr, 0);
}


size_t CParser::LogicalOrExpressionContext::getRuleIndex() const {
  return CParser::RuleLogicalOrExpression;
}

void CParser::LogicalOrExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalOrExpression(this);
}

void CParser::LogicalOrExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalOrExpression(this);
}


antlrcpp::Any CParser::LogicalOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitLogicalOrExpression(this);
  else
    return visitor->visitChildren(this);
}


CParser::LogicalOrExpressionContext* CParser::logicalOrExpression() {
   return logicalOrExpression(0);
}

CParser::LogicalOrExpressionContext* CParser::logicalOrExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::LogicalOrExpressionContext *_localctx = _tracker.createInstance<LogicalOrExpressionContext>(_ctx, parentState);
  CParser::LogicalOrExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, CParser::RuleLogicalOrExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(492);
    logicalAndExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(499);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LogicalOrExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogicalOrExpression);
        setState(494);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(495);
        match(CParser::OrOr);
        setState(496);
        logicalAndExpression(0); 
      }
      setState(501);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ConditionalExpressionContext ------------------------------------------------------------------

CParser::ConditionalExpressionContext::ConditionalExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::LogicalOrExpressionContext* CParser::ConditionalExpressionContext::logicalOrExpression() {
  return getRuleContext<CParser::LogicalOrExpressionContext>(0);
}

tree::TerminalNode* CParser::ConditionalExpressionContext::Question() {
  return getToken(CParser::Question, 0);
}

CParser::ExpressionContext* CParser::ConditionalExpressionContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}

tree::TerminalNode* CParser::ConditionalExpressionContext::Colon() {
  return getToken(CParser::Colon, 0);
}

CParser::ConditionalExpressionContext* CParser::ConditionalExpressionContext::conditionalExpression() {
  return getRuleContext<CParser::ConditionalExpressionContext>(0);
}


size_t CParser::ConditionalExpressionContext::getRuleIndex() const {
  return CParser::RuleConditionalExpression;
}

void CParser::ConditionalExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditionalExpression(this);
}

void CParser::ConditionalExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditionalExpression(this);
}


antlrcpp::Any CParser::ConditionalExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitConditionalExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::ConditionalExpressionContext* CParser::conditionalExpression() {
  ConditionalExpressionContext *_localctx = _tracker.createInstance<ConditionalExpressionContext>(_ctx, getState());
  enterRule(_localctx, 38, CParser::RuleConditionalExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(502);
    logicalOrExpression(0);
    setState(508);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      setState(503);
      match(CParser::Question);
      setState(504);
      expression(0);
      setState(505);
      match(CParser::Colon);
      setState(506);
      conditionalExpression();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentExpressionContext ------------------------------------------------------------------

CParser::AssignmentExpressionContext::AssignmentExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ConditionalExpressionContext* CParser::AssignmentExpressionContext::conditionalExpression() {
  return getRuleContext<CParser::ConditionalExpressionContext>(0);
}

CParser::UnaryExpressionContext* CParser::AssignmentExpressionContext::unaryExpression() {
  return getRuleContext<CParser::UnaryExpressionContext>(0);
}

CParser::AssignmentOperatorContext* CParser::AssignmentExpressionContext::assignmentOperator() {
  return getRuleContext<CParser::AssignmentOperatorContext>(0);
}

CParser::AssignmentExpressionContext* CParser::AssignmentExpressionContext::assignmentExpression() {
  return getRuleContext<CParser::AssignmentExpressionContext>(0);
}

tree::TerminalNode* CParser::AssignmentExpressionContext::DigitSequence() {
  return getToken(CParser::DigitSequence, 0);
}


size_t CParser::AssignmentExpressionContext::getRuleIndex() const {
  return CParser::RuleAssignmentExpression;
}

void CParser::AssignmentExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentExpression(this);
}

void CParser::AssignmentExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentExpression(this);
}


antlrcpp::Any CParser::AssignmentExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitAssignmentExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::AssignmentExpressionContext* CParser::assignmentExpression() {
  AssignmentExpressionContext *_localctx = _tracker.createInstance<AssignmentExpressionContext>(_ctx, getState());
  enterRule(_localctx, 40, CParser::RuleAssignmentExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(516);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(510);
      conditionalExpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(511);
      unaryExpression();
      setState(512);
      assignmentOperator();
      setState(513);
      assignmentExpression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(515);
      match(CParser::DigitSequence);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentOperatorContext ------------------------------------------------------------------

CParser::AssignmentOperatorContext::AssignmentOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::AssignmentOperatorContext::Assign() {
  return getToken(CParser::Assign, 0);
}

tree::TerminalNode* CParser::AssignmentOperatorContext::StarAssign() {
  return getToken(CParser::StarAssign, 0);
}

tree::TerminalNode* CParser::AssignmentOperatorContext::DivAssign() {
  return getToken(CParser::DivAssign, 0);
}

tree::TerminalNode* CParser::AssignmentOperatorContext::ModAssign() {
  return getToken(CParser::ModAssign, 0);
}

tree::TerminalNode* CParser::AssignmentOperatorContext::PlusAssign() {
  return getToken(CParser::PlusAssign, 0);
}

tree::TerminalNode* CParser::AssignmentOperatorContext::MinusAssign() {
  return getToken(CParser::MinusAssign, 0);
}

tree::TerminalNode* CParser::AssignmentOperatorContext::LeftShiftAssign() {
  return getToken(CParser::LeftShiftAssign, 0);
}

tree::TerminalNode* CParser::AssignmentOperatorContext::RightShiftAssign() {
  return getToken(CParser::RightShiftAssign, 0);
}

tree::TerminalNode* CParser::AssignmentOperatorContext::AndAssign() {
  return getToken(CParser::AndAssign, 0);
}

tree::TerminalNode* CParser::AssignmentOperatorContext::XorAssign() {
  return getToken(CParser::XorAssign, 0);
}

tree::TerminalNode* CParser::AssignmentOperatorContext::OrAssign() {
  return getToken(CParser::OrAssign, 0);
}


size_t CParser::AssignmentOperatorContext::getRuleIndex() const {
  return CParser::RuleAssignmentOperator;
}

void CParser::AssignmentOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentOperator(this);
}

void CParser::AssignmentOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentOperator(this);
}


antlrcpp::Any CParser::AssignmentOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitAssignmentOperator(this);
  else
    return visitor->visitChildren(this);
}

CParser::AssignmentOperatorContext* CParser::assignmentOperator() {
  AssignmentOperatorContext *_localctx = _tracker.createInstance<AssignmentOperatorContext>(_ctx, getState());
  enterRule(_localctx, 42, CParser::RuleAssignmentOperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(518);
    _la = _input->LA(1);
    if (!(((((_la - 93) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 93)) & ((1ULL << (CParser::Assign - 93))
      | (1ULL << (CParser::StarAssign - 93))
      | (1ULL << (CParser::DivAssign - 93))
      | (1ULL << (CParser::ModAssign - 93))
      | (1ULL << (CParser::PlusAssign - 93))
      | (1ULL << (CParser::MinusAssign - 93))
      | (1ULL << (CParser::LeftShiftAssign - 93))
      | (1ULL << (CParser::RightShiftAssign - 93))
      | (1ULL << (CParser::AndAssign - 93))
      | (1ULL << (CParser::XorAssign - 93))
      | (1ULL << (CParser::OrAssign - 93)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

CParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::AssignmentExpressionContext* CParser::ExpressionContext::assignmentExpression() {
  return getRuleContext<CParser::AssignmentExpressionContext>(0);
}

CParser::ExpressionContext* CParser::ExpressionContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}

tree::TerminalNode* CParser::ExpressionContext::Comma() {
  return getToken(CParser::Comma, 0);
}


size_t CParser::ExpressionContext::getRuleIndex() const {
  return CParser::RuleExpression;
}

void CParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void CParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


antlrcpp::Any CParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}


CParser::ExpressionContext* CParser::expression() {
   return expression(0);
}

CParser::ExpressionContext* CParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  CParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 44;
  enterRecursionRule(_localctx, 44, CParser::RuleExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(521);
    assignmentExpression();
    _ctx->stop = _input->LT(-1);
    setState(528);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpression);
        setState(523);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(524);
        match(CParser::Comma);
        setState(525);
        assignmentExpression(); 
      }
      setState(530);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ConstantExpressionContext ------------------------------------------------------------------

CParser::ConstantExpressionContext::ConstantExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ConditionalExpressionContext* CParser::ConstantExpressionContext::conditionalExpression() {
  return getRuleContext<CParser::ConditionalExpressionContext>(0);
}


size_t CParser::ConstantExpressionContext::getRuleIndex() const {
  return CParser::RuleConstantExpression;
}

void CParser::ConstantExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstantExpression(this);
}

void CParser::ConstantExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstantExpression(this);
}


antlrcpp::Any CParser::ConstantExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitConstantExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::ConstantExpressionContext* CParser::constantExpression() {
  ConstantExpressionContext *_localctx = _tracker.createInstance<ConstantExpressionContext>(_ctx, getState());
  enterRule(_localctx, 46, CParser::RuleConstantExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(531);
    conditionalExpression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

CParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DeclarationSpecifiersContext* CParser::DeclarationContext::declarationSpecifiers() {
  return getRuleContext<CParser::DeclarationSpecifiersContext>(0);
}

CParser::InitDeclaratorListContext* CParser::DeclarationContext::initDeclaratorList() {
  return getRuleContext<CParser::InitDeclaratorListContext>(0);
}

tree::TerminalNode* CParser::DeclarationContext::Semi() {
  return getToken(CParser::Semi, 0);
}

CParser::StaticAssertDeclarationContext* CParser::DeclarationContext::staticAssertDeclaration() {
  return getRuleContext<CParser::StaticAssertDeclarationContext>(0);
}


size_t CParser::DeclarationContext::getRuleIndex() const {
  return CParser::RuleDeclaration;
}

void CParser::DeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration(this);
}

void CParser::DeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration(this);
}


antlrcpp::Any CParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

CParser::DeclarationContext* CParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 48, CParser::RuleDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(541);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(533);
      declarationSpecifiers();
      setState(534);
      initDeclaratorList(0);
      setState(535);
      match(CParser::Semi);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(537);
      declarationSpecifiers();
      setState(538);
      match(CParser::Semi);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(540);
      staticAssertDeclaration();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationSpecifiersContext ------------------------------------------------------------------

CParser::DeclarationSpecifiersContext::DeclarationSpecifiersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::DeclarationSpecifierContext *> CParser::DeclarationSpecifiersContext::declarationSpecifier() {
  return getRuleContexts<CParser::DeclarationSpecifierContext>();
}

CParser::DeclarationSpecifierContext* CParser::DeclarationSpecifiersContext::declarationSpecifier(size_t i) {
  return getRuleContext<CParser::DeclarationSpecifierContext>(i);
}


size_t CParser::DeclarationSpecifiersContext::getRuleIndex() const {
  return CParser::RuleDeclarationSpecifiers;
}

void CParser::DeclarationSpecifiersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarationSpecifiers(this);
}

void CParser::DeclarationSpecifiersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarationSpecifiers(this);
}


antlrcpp::Any CParser::DeclarationSpecifiersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDeclarationSpecifiers(this);
  else
    return visitor->visitChildren(this);
}

CParser::DeclarationSpecifiersContext* CParser::declarationSpecifiers() {
  DeclarationSpecifiersContext *_localctx = _tracker.createInstance<DeclarationSpecifiersContext>(_ctx, getState());
  enterRule(_localctx, 50, CParser::RuleDeclarationSpecifiers);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(544); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(543);
              declarationSpecifier();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(546); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationSpecifiers2Context ------------------------------------------------------------------

CParser::DeclarationSpecifiers2Context::DeclarationSpecifiers2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::DeclarationSpecifierContext *> CParser::DeclarationSpecifiers2Context::declarationSpecifier() {
  return getRuleContexts<CParser::DeclarationSpecifierContext>();
}

CParser::DeclarationSpecifierContext* CParser::DeclarationSpecifiers2Context::declarationSpecifier(size_t i) {
  return getRuleContext<CParser::DeclarationSpecifierContext>(i);
}


size_t CParser::DeclarationSpecifiers2Context::getRuleIndex() const {
  return CParser::RuleDeclarationSpecifiers2;
}

void CParser::DeclarationSpecifiers2Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarationSpecifiers2(this);
}

void CParser::DeclarationSpecifiers2Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarationSpecifiers2(this);
}


antlrcpp::Any CParser::DeclarationSpecifiers2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDeclarationSpecifiers2(this);
  else
    return visitor->visitChildren(this);
}

CParser::DeclarationSpecifiers2Context* CParser::declarationSpecifiers2() {
  DeclarationSpecifiers2Context *_localctx = _tracker.createInstance<DeclarationSpecifiers2Context>(_ctx, getState());
  enterRule(_localctx, 52, CParser::RuleDeclarationSpecifiers2);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(549); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(548);
              declarationSpecifier();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(551); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationSpecifierContext ------------------------------------------------------------------

CParser::DeclarationSpecifierContext::DeclarationSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::StorageClassSpecifierContext* CParser::DeclarationSpecifierContext::storageClassSpecifier() {
  return getRuleContext<CParser::StorageClassSpecifierContext>(0);
}

CParser::TypeSpecifierContext* CParser::DeclarationSpecifierContext::typeSpecifier() {
  return getRuleContext<CParser::TypeSpecifierContext>(0);
}

CParser::TypeQualifierContext* CParser::DeclarationSpecifierContext::typeQualifier() {
  return getRuleContext<CParser::TypeQualifierContext>(0);
}

CParser::FunctionSpecifierContext* CParser::DeclarationSpecifierContext::functionSpecifier() {
  return getRuleContext<CParser::FunctionSpecifierContext>(0);
}

CParser::AlignmentSpecifierContext* CParser::DeclarationSpecifierContext::alignmentSpecifier() {
  return getRuleContext<CParser::AlignmentSpecifierContext>(0);
}


size_t CParser::DeclarationSpecifierContext::getRuleIndex() const {
  return CParser::RuleDeclarationSpecifier;
}

void CParser::DeclarationSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarationSpecifier(this);
}

void CParser::DeclarationSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarationSpecifier(this);
}


antlrcpp::Any CParser::DeclarationSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDeclarationSpecifier(this);
  else
    return visitor->visitChildren(this);
}

CParser::DeclarationSpecifierContext* CParser::declarationSpecifier() {
  DeclarationSpecifierContext *_localctx = _tracker.createInstance<DeclarationSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 54, CParser::RuleDeclarationSpecifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(558);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(553);
      storageClassSpecifier();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(554);
      typeSpecifier(0);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(555);
      typeQualifier();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(556);
      functionSpecifier();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(557);
      alignmentSpecifier();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitDeclaratorListContext ------------------------------------------------------------------

CParser::InitDeclaratorListContext::InitDeclaratorListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::InitDeclaratorContext* CParser::InitDeclaratorListContext::initDeclarator() {
  return getRuleContext<CParser::InitDeclaratorContext>(0);
}

CParser::InitDeclaratorListContext* CParser::InitDeclaratorListContext::initDeclaratorList() {
  return getRuleContext<CParser::InitDeclaratorListContext>(0);
}

tree::TerminalNode* CParser::InitDeclaratorListContext::Comma() {
  return getToken(CParser::Comma, 0);
}


size_t CParser::InitDeclaratorListContext::getRuleIndex() const {
  return CParser::RuleInitDeclaratorList;
}

void CParser::InitDeclaratorListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitDeclaratorList(this);
}

void CParser::InitDeclaratorListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitDeclaratorList(this);
}


antlrcpp::Any CParser::InitDeclaratorListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitInitDeclaratorList(this);
  else
    return visitor->visitChildren(this);
}


CParser::InitDeclaratorListContext* CParser::initDeclaratorList() {
   return initDeclaratorList(0);
}

CParser::InitDeclaratorListContext* CParser::initDeclaratorList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::InitDeclaratorListContext *_localctx = _tracker.createInstance<InitDeclaratorListContext>(_ctx, parentState);
  CParser::InitDeclaratorListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 56;
  enterRecursionRule(_localctx, 56, CParser::RuleInitDeclaratorList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(561);
    initDeclarator();
    _ctx->stop = _input->LT(-1);
    setState(568);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<InitDeclaratorListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleInitDeclaratorList);
        setState(563);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(564);
        match(CParser::Comma);
        setState(565);
        initDeclarator(); 
      }
      setState(570);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- InitDeclaratorContext ------------------------------------------------------------------

CParser::InitDeclaratorContext::InitDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DeclaratorContext* CParser::InitDeclaratorContext::declarator() {
  return getRuleContext<CParser::DeclaratorContext>(0);
}

tree::TerminalNode* CParser::InitDeclaratorContext::Assign() {
  return getToken(CParser::Assign, 0);
}

CParser::InitializerContext* CParser::InitDeclaratorContext::initializer() {
  return getRuleContext<CParser::InitializerContext>(0);
}


size_t CParser::InitDeclaratorContext::getRuleIndex() const {
  return CParser::RuleInitDeclarator;
}

void CParser::InitDeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitDeclarator(this);
}

void CParser::InitDeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitDeclarator(this);
}


antlrcpp::Any CParser::InitDeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitInitDeclarator(this);
  else
    return visitor->visitChildren(this);
}

CParser::InitDeclaratorContext* CParser::initDeclarator() {
  InitDeclaratorContext *_localctx = _tracker.createInstance<InitDeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 58, CParser::RuleInitDeclarator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(576);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(571);
      declarator();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(572);
      declarator();
      setState(573);
      match(CParser::Assign);
      setState(574);
      initializer();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StorageClassSpecifierContext ------------------------------------------------------------------

CParser::StorageClassSpecifierContext::StorageClassSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::StorageClassSpecifierContext::Typedef() {
  return getToken(CParser::Typedef, 0);
}

tree::TerminalNode* CParser::StorageClassSpecifierContext::Extern() {
  return getToken(CParser::Extern, 0);
}

tree::TerminalNode* CParser::StorageClassSpecifierContext::Static() {
  return getToken(CParser::Static, 0);
}

tree::TerminalNode* CParser::StorageClassSpecifierContext::ThreadLocal() {
  return getToken(CParser::ThreadLocal, 0);
}

tree::TerminalNode* CParser::StorageClassSpecifierContext::Auto() {
  return getToken(CParser::Auto, 0);
}

tree::TerminalNode* CParser::StorageClassSpecifierContext::Register() {
  return getToken(CParser::Register, 0);
}


size_t CParser::StorageClassSpecifierContext::getRuleIndex() const {
  return CParser::RuleStorageClassSpecifier;
}

void CParser::StorageClassSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStorageClassSpecifier(this);
}

void CParser::StorageClassSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStorageClassSpecifier(this);
}


antlrcpp::Any CParser::StorageClassSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitStorageClassSpecifier(this);
  else
    return visitor->visitChildren(this);
}

CParser::StorageClassSpecifierContext* CParser::storageClassSpecifier() {
  StorageClassSpecifierContext *_localctx = _tracker.createInstance<StorageClassSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 60, CParser::RuleStorageClassSpecifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(587);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::T__0:
      case CParser::Typedef: {
        enterOuterAlt(_localctx, 1);
        setState(579);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CParser::T__0) {
          setState(578);
          match(CParser::T__0);
        }
        setState(581);
        match(CParser::Typedef);
        break;
      }

      case CParser::Extern: {
        enterOuterAlt(_localctx, 2);
        setState(582);
        match(CParser::Extern);
        break;
      }

      case CParser::Static: {
        enterOuterAlt(_localctx, 3);
        setState(583);
        match(CParser::Static);
        break;
      }

      case CParser::ThreadLocal: {
        enterOuterAlt(_localctx, 4);
        setState(584);
        match(CParser::ThreadLocal);
        break;
      }

      case CParser::Auto: {
        enterOuterAlt(_localctx, 5);
        setState(585);
        match(CParser::Auto);
        break;
      }

      case CParser::Register: {
        enterOuterAlt(_localctx, 6);
        setState(586);
        match(CParser::Register);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeSpecifierContext ------------------------------------------------------------------

CParser::TypeSpecifierContext::TypeSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::TypeSpecifierContext::Void() {
  return getToken(CParser::Void, 0);
}

tree::TerminalNode* CParser::TypeSpecifierContext::Char() {
  return getToken(CParser::Char, 0);
}

tree::TerminalNode* CParser::TypeSpecifierContext::Short() {
  return getToken(CParser::Short, 0);
}

tree::TerminalNode* CParser::TypeSpecifierContext::Int() {
  return getToken(CParser::Int, 0);
}

tree::TerminalNode* CParser::TypeSpecifierContext::Long() {
  return getToken(CParser::Long, 0);
}

tree::TerminalNode* CParser::TypeSpecifierContext::Float() {
  return getToken(CParser::Float, 0);
}

tree::TerminalNode* CParser::TypeSpecifierContext::Double() {
  return getToken(CParser::Double, 0);
}

tree::TerminalNode* CParser::TypeSpecifierContext::Signed() {
  return getToken(CParser::Signed, 0);
}

tree::TerminalNode* CParser::TypeSpecifierContext::Unsigned() {
  return getToken(CParser::Unsigned, 0);
}

tree::TerminalNode* CParser::TypeSpecifierContext::Bool() {
  return getToken(CParser::Bool, 0);
}

tree::TerminalNode* CParser::TypeSpecifierContext::Complex() {
  return getToken(CParser::Complex, 0);
}

tree::TerminalNode* CParser::TypeSpecifierContext::LeftParen() {
  return getToken(CParser::LeftParen, 0);
}

tree::TerminalNode* CParser::TypeSpecifierContext::RightParen() {
  return getToken(CParser::RightParen, 0);
}

CParser::AtomicTypeSpecifierContext* CParser::TypeSpecifierContext::atomicTypeSpecifier() {
  return getRuleContext<CParser::AtomicTypeSpecifierContext>(0);
}

CParser::StructOrUnionSpecifierContext* CParser::TypeSpecifierContext::structOrUnionSpecifier() {
  return getRuleContext<CParser::StructOrUnionSpecifierContext>(0);
}

CParser::EnumSpecifierContext* CParser::TypeSpecifierContext::enumSpecifier() {
  return getRuleContext<CParser::EnumSpecifierContext>(0);
}

CParser::TypedefNameContext* CParser::TypeSpecifierContext::typedefName() {
  return getRuleContext<CParser::TypedefNameContext>(0);
}

CParser::ConstantExpressionContext* CParser::TypeSpecifierContext::constantExpression() {
  return getRuleContext<CParser::ConstantExpressionContext>(0);
}

tree::TerminalNode* CParser::TypeSpecifierContext::Typeof() {
  return getToken(CParser::Typeof, 0);
}

CParser::TypeSpecifierContext* CParser::TypeSpecifierContext::typeSpecifier() {
  return getRuleContext<CParser::TypeSpecifierContext>(0);
}

CParser::PointerContext* CParser::TypeSpecifierContext::pointer() {
  return getRuleContext<CParser::PointerContext>(0);
}


size_t CParser::TypeSpecifierContext::getRuleIndex() const {
  return CParser::RuleTypeSpecifier;
}

void CParser::TypeSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeSpecifier(this);
}

void CParser::TypeSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeSpecifier(this);
}


antlrcpp::Any CParser::TypeSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitTypeSpecifier(this);
  else
    return visitor->visitChildren(this);
}


CParser::TypeSpecifierContext* CParser::typeSpecifier() {
   return typeSpecifier(0);
}

CParser::TypeSpecifierContext* CParser::typeSpecifier(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::TypeSpecifierContext *_localctx = _tracker.createInstance<TypeSpecifierContext>(_ctx, parentState);
  CParser::TypeSpecifierContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 62;
  enterRecursionRule(_localctx, 62, CParser::RuleTypeSpecifier, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(604);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::T__4:
      case CParser::T__5:
      case CParser::T__6:
      case CParser::Char:
      case CParser::Double:
      case CParser::Float:
      case CParser::Int:
      case CParser::Long:
      case CParser::Short:
      case CParser::Signed:
      case CParser::Unsigned:
      case CParser::Void:
      case CParser::Bool:
      case CParser::Complex: {
        setState(590);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CParser::T__4)
          | (1ULL << CParser::T__5)
          | (1ULL << CParser::T__6)
          | (1ULL << CParser::Char)
          | (1ULL << CParser::Double)
          | (1ULL << CParser::Float)
          | (1ULL << CParser::Int)
          | (1ULL << CParser::Long)
          | (1ULL << CParser::Short)
          | (1ULL << CParser::Signed)
          | (1ULL << CParser::Unsigned)
          | (1ULL << CParser::Void)
          | (1ULL << CParser::Bool)
          | (1ULL << CParser::Complex))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

      case CParser::T__0: {
        setState(591);
        match(CParser::T__0);
        setState(592);
        match(CParser::LeftParen);
        setState(593);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CParser::T__4)
          | (1ULL << CParser::T__5)
          | (1ULL << CParser::T__6))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(594);
        match(CParser::RightParen);
        break;
      }

      case CParser::Atomic: {
        setState(595);
        atomicTypeSpecifier();
        break;
      }

      case CParser::Struct:
      case CParser::Union: {
        setState(596);
        structOrUnionSpecifier();
        break;
      }

      case CParser::Enum: {
        setState(597);
        enumSpecifier();
        break;
      }

      case CParser::Identifier: {
        setState(598);
        typedefName();
        break;
      }

      case CParser::T__7:
      case CParser::Typeof: {
        setState(599);
        _la = _input->LA(1);
        if (!(_la == CParser::T__7

        || _la == CParser::Typeof)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(600);
        match(CParser::LeftParen);
        setState(601);
        constantExpression();
        setState(602);
        match(CParser::RightParen);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(610);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TypeSpecifierContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTypeSpecifier);
        setState(606);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(607);
        pointer(); 
      }
      setState(612);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StructOrUnionSpecifierContext ------------------------------------------------------------------

CParser::StructOrUnionSpecifierContext::StructOrUnionSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::StructOrUnionContext* CParser::StructOrUnionSpecifierContext::structOrUnion() {
  return getRuleContext<CParser::StructOrUnionContext>(0);
}

tree::TerminalNode* CParser::StructOrUnionSpecifierContext::LeftBrace() {
  return getToken(CParser::LeftBrace, 0);
}

tree::TerminalNode* CParser::StructOrUnionSpecifierContext::RightBrace() {
  return getToken(CParser::RightBrace, 0);
}

tree::TerminalNode* CParser::StructOrUnionSpecifierContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}

CParser::StructDeclarationListContext* CParser::StructOrUnionSpecifierContext::structDeclarationList() {
  return getRuleContext<CParser::StructDeclarationListContext>(0);
}


size_t CParser::StructOrUnionSpecifierContext::getRuleIndex() const {
  return CParser::RuleStructOrUnionSpecifier;
}

void CParser::StructOrUnionSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructOrUnionSpecifier(this);
}

void CParser::StructOrUnionSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructOrUnionSpecifier(this);
}


antlrcpp::Any CParser::StructOrUnionSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitStructOrUnionSpecifier(this);
  else
    return visitor->visitChildren(this);
}

CParser::StructOrUnionSpecifierContext* CParser::structOrUnionSpecifier() {
  StructOrUnionSpecifierContext *_localctx = _tracker.createInstance<StructOrUnionSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 64, CParser::RuleStructOrUnionSpecifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(626);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(613);
      structOrUnion();
      setState(615);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::Identifier) {
        setState(614);
        match(CParser::Identifier);
      }
      setState(617);
      match(CParser::LeftBrace);
      setState(619);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__0)
        | (1ULL << CParser::T__4)
        | (1ULL << CParser::T__5)
        | (1ULL << CParser::T__6)
        | (1ULL << CParser::T__7)
        | (1ULL << CParser::T__8)
        | (1ULL << CParser::T__9)
        | (1ULL << CParser::Char)
        | (1ULL << CParser::Const)
        | (1ULL << CParser::Double)
        | (1ULL << CParser::Enum)
        | (1ULL << CParser::Float)
        | (1ULL << CParser::Int)
        | (1ULL << CParser::Long)
        | (1ULL << CParser::Restrict)
        | (1ULL << CParser::Short)
        | (1ULL << CParser::Signed)
        | (1ULL << CParser::Struct)
        | (1ULL << CParser::Typeof)
        | (1ULL << CParser::Union)
        | (1ULL << CParser::Unsigned)
        | (1ULL << CParser::Void)
        | (1ULL << CParser::Volatile)
        | (1ULL << CParser::Atomic)
        | (1ULL << CParser::Bool)
        | (1ULL << CParser::Complex)
        | (1ULL << CParser::StaticAssert))) != 0) || _la == CParser::Identifier) {
        setState(618);
        structDeclarationList(0);
      }
      setState(621);
      match(CParser::RightBrace);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(623);
      structOrUnion();
      setState(624);
      match(CParser::Identifier);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructOrUnionContext ------------------------------------------------------------------

CParser::StructOrUnionContext::StructOrUnionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::StructOrUnionContext::Struct() {
  return getToken(CParser::Struct, 0);
}

tree::TerminalNode* CParser::StructOrUnionContext::Union() {
  return getToken(CParser::Union, 0);
}


size_t CParser::StructOrUnionContext::getRuleIndex() const {
  return CParser::RuleStructOrUnion;
}

void CParser::StructOrUnionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructOrUnion(this);
}

void CParser::StructOrUnionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructOrUnion(this);
}


antlrcpp::Any CParser::StructOrUnionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitStructOrUnion(this);
  else
    return visitor->visitChildren(this);
}

CParser::StructOrUnionContext* CParser::structOrUnion() {
  StructOrUnionContext *_localctx = _tracker.createInstance<StructOrUnionContext>(_ctx, getState());
  enterRule(_localctx, 66, CParser::RuleStructOrUnion);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(628);
    _la = _input->LA(1);
    if (!(_la == CParser::Struct

    || _la == CParser::Union)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructDeclarationListContext ------------------------------------------------------------------

CParser::StructDeclarationListContext::StructDeclarationListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::StructDeclarationContext* CParser::StructDeclarationListContext::structDeclaration() {
  return getRuleContext<CParser::StructDeclarationContext>(0);
}

CParser::StructDeclarationListContext* CParser::StructDeclarationListContext::structDeclarationList() {
  return getRuleContext<CParser::StructDeclarationListContext>(0);
}


size_t CParser::StructDeclarationListContext::getRuleIndex() const {
  return CParser::RuleStructDeclarationList;
}

void CParser::StructDeclarationListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructDeclarationList(this);
}

void CParser::StructDeclarationListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructDeclarationList(this);
}


antlrcpp::Any CParser::StructDeclarationListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitStructDeclarationList(this);
  else
    return visitor->visitChildren(this);
}


CParser::StructDeclarationListContext* CParser::structDeclarationList() {
   return structDeclarationList(0);
}

CParser::StructDeclarationListContext* CParser::structDeclarationList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::StructDeclarationListContext *_localctx = _tracker.createInstance<StructDeclarationListContext>(_ctx, parentState);
  CParser::StructDeclarationListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 68;
  enterRecursionRule(_localctx, 68, CParser::RuleStructDeclarationList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(631);
    structDeclaration();
    _ctx->stop = _input->LT(-1);
    setState(637);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<StructDeclarationListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleStructDeclarationList);
        setState(633);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(634);
        structDeclaration(); 
      }
      setState(639);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StructDeclarationContext ------------------------------------------------------------------

CParser::StructDeclarationContext::StructDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::SpecifierQualifierListContext* CParser::StructDeclarationContext::specifierQualifierList() {
  return getRuleContext<CParser::SpecifierQualifierListContext>(0);
}

tree::TerminalNode* CParser::StructDeclarationContext::Semi() {
  return getToken(CParser::Semi, 0);
}

CParser::StructDeclaratorListContext* CParser::StructDeclarationContext::structDeclaratorList() {
  return getRuleContext<CParser::StructDeclaratorListContext>(0);
}

CParser::StaticAssertDeclarationContext* CParser::StructDeclarationContext::staticAssertDeclaration() {
  return getRuleContext<CParser::StaticAssertDeclarationContext>(0);
}


size_t CParser::StructDeclarationContext::getRuleIndex() const {
  return CParser::RuleStructDeclaration;
}

void CParser::StructDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructDeclaration(this);
}

void CParser::StructDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructDeclaration(this);
}


antlrcpp::Any CParser::StructDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitStructDeclaration(this);
  else
    return visitor->visitChildren(this);
}

CParser::StructDeclarationContext* CParser::structDeclaration() {
  StructDeclarationContext *_localctx = _tracker.createInstance<StructDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 70, CParser::RuleStructDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(647);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::T__0:
      case CParser::T__4:
      case CParser::T__5:
      case CParser::T__6:
      case CParser::T__7:
      case CParser::T__8:
      case CParser::T__9:
      case CParser::Char:
      case CParser::Const:
      case CParser::Double:
      case CParser::Enum:
      case CParser::Float:
      case CParser::Int:
      case CParser::Long:
      case CParser::Restrict:
      case CParser::Short:
      case CParser::Signed:
      case CParser::Struct:
      case CParser::Typeof:
      case CParser::Union:
      case CParser::Unsigned:
      case CParser::Void:
      case CParser::Volatile:
      case CParser::Atomic:
      case CParser::Bool:
      case CParser::Complex:
      case CParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(640);
        specifierQualifierList();
        setState(642);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (((((_la - 63) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 63)) & ((1ULL << (CParser::LeftParen - 63))
          | (1ULL << (CParser::Star - 63))
          | (1ULL << (CParser::Caret - 63))
          | (1ULL << (CParser::Colon - 63))
          | (1ULL << (CParser::Identifier - 63)))) != 0)) {
          setState(641);
          structDeclaratorList(0);
        }
        setState(644);
        match(CParser::Semi);
        break;
      }

      case CParser::StaticAssert: {
        enterOuterAlt(_localctx, 2);
        setState(646);
        staticAssertDeclaration();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SpecifierQualifierListContext ------------------------------------------------------------------

CParser::SpecifierQualifierListContext::SpecifierQualifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::TypeSpecifierContext* CParser::SpecifierQualifierListContext::typeSpecifier() {
  return getRuleContext<CParser::TypeSpecifierContext>(0);
}

CParser::SpecifierQualifierListContext* CParser::SpecifierQualifierListContext::specifierQualifierList() {
  return getRuleContext<CParser::SpecifierQualifierListContext>(0);
}

CParser::TypeQualifierContext* CParser::SpecifierQualifierListContext::typeQualifier() {
  return getRuleContext<CParser::TypeQualifierContext>(0);
}


size_t CParser::SpecifierQualifierListContext::getRuleIndex() const {
  return CParser::RuleSpecifierQualifierList;
}

void CParser::SpecifierQualifierListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSpecifierQualifierList(this);
}

void CParser::SpecifierQualifierListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSpecifierQualifierList(this);
}


antlrcpp::Any CParser::SpecifierQualifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitSpecifierQualifierList(this);
  else
    return visitor->visitChildren(this);
}

CParser::SpecifierQualifierListContext* CParser::specifierQualifierList() {
  SpecifierQualifierListContext *_localctx = _tracker.createInstance<SpecifierQualifierListContext>(_ctx, getState());
  enterRule(_localctx, 72, CParser::RuleSpecifierQualifierList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(657);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(649);
      typeSpecifier(0);
      setState(651);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx)) {
      case 1: {
        setState(650);
        specifierQualifierList();
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(653);
      typeQualifier();
      setState(655);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx)) {
      case 1: {
        setState(654);
        specifierQualifierList();
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructDeclaratorListContext ------------------------------------------------------------------

CParser::StructDeclaratorListContext::StructDeclaratorListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::StructDeclaratorContext* CParser::StructDeclaratorListContext::structDeclarator() {
  return getRuleContext<CParser::StructDeclaratorContext>(0);
}

CParser::StructDeclaratorListContext* CParser::StructDeclaratorListContext::structDeclaratorList() {
  return getRuleContext<CParser::StructDeclaratorListContext>(0);
}

tree::TerminalNode* CParser::StructDeclaratorListContext::Comma() {
  return getToken(CParser::Comma, 0);
}


size_t CParser::StructDeclaratorListContext::getRuleIndex() const {
  return CParser::RuleStructDeclaratorList;
}

void CParser::StructDeclaratorListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructDeclaratorList(this);
}

void CParser::StructDeclaratorListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructDeclaratorList(this);
}


antlrcpp::Any CParser::StructDeclaratorListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitStructDeclaratorList(this);
  else
    return visitor->visitChildren(this);
}


CParser::StructDeclaratorListContext* CParser::structDeclaratorList() {
   return structDeclaratorList(0);
}

CParser::StructDeclaratorListContext* CParser::structDeclaratorList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::StructDeclaratorListContext *_localctx = _tracker.createInstance<StructDeclaratorListContext>(_ctx, parentState);
  CParser::StructDeclaratorListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 74;
  enterRecursionRule(_localctx, 74, CParser::RuleStructDeclaratorList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(660);
    structDeclarator();
    _ctx->stop = _input->LT(-1);
    setState(667);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<StructDeclaratorListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleStructDeclaratorList);
        setState(662);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(663);
        match(CParser::Comma);
        setState(664);
        structDeclarator(); 
      }
      setState(669);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StructDeclaratorContext ------------------------------------------------------------------

CParser::StructDeclaratorContext::StructDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DeclaratorContext* CParser::StructDeclaratorContext::declarator() {
  return getRuleContext<CParser::DeclaratorContext>(0);
}

tree::TerminalNode* CParser::StructDeclaratorContext::Colon() {
  return getToken(CParser::Colon, 0);
}

CParser::ConstantExpressionContext* CParser::StructDeclaratorContext::constantExpression() {
  return getRuleContext<CParser::ConstantExpressionContext>(0);
}


size_t CParser::StructDeclaratorContext::getRuleIndex() const {
  return CParser::RuleStructDeclarator;
}

void CParser::StructDeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructDeclarator(this);
}

void CParser::StructDeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructDeclarator(this);
}


antlrcpp::Any CParser::StructDeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitStructDeclarator(this);
  else
    return visitor->visitChildren(this);
}

CParser::StructDeclaratorContext* CParser::structDeclarator() {
  StructDeclaratorContext *_localctx = _tracker.createInstance<StructDeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 76, CParser::RuleStructDeclarator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(676);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(670);
      declarator();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(672);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 63) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 63)) & ((1ULL << (CParser::LeftParen - 63))
        | (1ULL << (CParser::Star - 63))
        | (1ULL << (CParser::Caret - 63))
        | (1ULL << (CParser::Identifier - 63)))) != 0)) {
        setState(671);
        declarator();
      }
      setState(674);
      match(CParser::Colon);
      setState(675);
      constantExpression();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumSpecifierContext ------------------------------------------------------------------

CParser::EnumSpecifierContext::EnumSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::EnumSpecifierContext::Enum() {
  return getToken(CParser::Enum, 0);
}

tree::TerminalNode* CParser::EnumSpecifierContext::LeftBrace() {
  return getToken(CParser::LeftBrace, 0);
}

CParser::EnumeratorListContext* CParser::EnumSpecifierContext::enumeratorList() {
  return getRuleContext<CParser::EnumeratorListContext>(0);
}

tree::TerminalNode* CParser::EnumSpecifierContext::RightBrace() {
  return getToken(CParser::RightBrace, 0);
}

tree::TerminalNode* CParser::EnumSpecifierContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}

tree::TerminalNode* CParser::EnumSpecifierContext::Comma() {
  return getToken(CParser::Comma, 0);
}


size_t CParser::EnumSpecifierContext::getRuleIndex() const {
  return CParser::RuleEnumSpecifier;
}

void CParser::EnumSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumSpecifier(this);
}

void CParser::EnumSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumSpecifier(this);
}


antlrcpp::Any CParser::EnumSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitEnumSpecifier(this);
  else
    return visitor->visitChildren(this);
}

CParser::EnumSpecifierContext* CParser::enumSpecifier() {
  EnumSpecifierContext *_localctx = _tracker.createInstance<EnumSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 78, CParser::RuleEnumSpecifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(697);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(678);
      match(CParser::Enum);
      setState(680);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::Identifier) {
        setState(679);
        match(CParser::Identifier);
      }
      setState(682);
      match(CParser::LeftBrace);
      setState(683);
      enumeratorList(0);
      setState(684);
      match(CParser::RightBrace);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(686);
      match(CParser::Enum);
      setState(688);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::Identifier) {
        setState(687);
        match(CParser::Identifier);
      }
      setState(690);
      match(CParser::LeftBrace);
      setState(691);
      enumeratorList(0);
      setState(692);
      match(CParser::Comma);
      setState(693);
      match(CParser::RightBrace);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(695);
      match(CParser::Enum);
      setState(696);
      match(CParser::Identifier);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumeratorListContext ------------------------------------------------------------------

CParser::EnumeratorListContext::EnumeratorListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::EnumeratorContext* CParser::EnumeratorListContext::enumerator() {
  return getRuleContext<CParser::EnumeratorContext>(0);
}

CParser::EnumeratorListContext* CParser::EnumeratorListContext::enumeratorList() {
  return getRuleContext<CParser::EnumeratorListContext>(0);
}

tree::TerminalNode* CParser::EnumeratorListContext::Comma() {
  return getToken(CParser::Comma, 0);
}


size_t CParser::EnumeratorListContext::getRuleIndex() const {
  return CParser::RuleEnumeratorList;
}

void CParser::EnumeratorListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumeratorList(this);
}

void CParser::EnumeratorListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumeratorList(this);
}


antlrcpp::Any CParser::EnumeratorListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitEnumeratorList(this);
  else
    return visitor->visitChildren(this);
}


CParser::EnumeratorListContext* CParser::enumeratorList() {
   return enumeratorList(0);
}

CParser::EnumeratorListContext* CParser::enumeratorList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::EnumeratorListContext *_localctx = _tracker.createInstance<EnumeratorListContext>(_ctx, parentState);
  CParser::EnumeratorListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 80;
  enterRecursionRule(_localctx, 80, CParser::RuleEnumeratorList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(700);
    enumerator();
    _ctx->stop = _input->LT(-1);
    setState(707);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<EnumeratorListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleEnumeratorList);
        setState(702);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(703);
        match(CParser::Comma);
        setState(704);
        enumerator(); 
      }
      setState(709);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- EnumeratorContext ------------------------------------------------------------------

CParser::EnumeratorContext::EnumeratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::EnumerationConstantContext* CParser::EnumeratorContext::enumerationConstant() {
  return getRuleContext<CParser::EnumerationConstantContext>(0);
}

tree::TerminalNode* CParser::EnumeratorContext::Assign() {
  return getToken(CParser::Assign, 0);
}

CParser::ConstantExpressionContext* CParser::EnumeratorContext::constantExpression() {
  return getRuleContext<CParser::ConstantExpressionContext>(0);
}


size_t CParser::EnumeratorContext::getRuleIndex() const {
  return CParser::RuleEnumerator;
}

void CParser::EnumeratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumerator(this);
}

void CParser::EnumeratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumerator(this);
}


antlrcpp::Any CParser::EnumeratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitEnumerator(this);
  else
    return visitor->visitChildren(this);
}

CParser::EnumeratorContext* CParser::enumerator() {
  EnumeratorContext *_localctx = _tracker.createInstance<EnumeratorContext>(_ctx, getState());
  enterRule(_localctx, 82, CParser::RuleEnumerator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(715);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(710);
      enumerationConstant();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(711);
      enumerationConstant();
      setState(712);
      match(CParser::Assign);
      setState(713);
      constantExpression();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumerationConstantContext ------------------------------------------------------------------

CParser::EnumerationConstantContext::EnumerationConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::EnumerationConstantContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}


size_t CParser::EnumerationConstantContext::getRuleIndex() const {
  return CParser::RuleEnumerationConstant;
}

void CParser::EnumerationConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumerationConstant(this);
}

void CParser::EnumerationConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumerationConstant(this);
}


antlrcpp::Any CParser::EnumerationConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitEnumerationConstant(this);
  else
    return visitor->visitChildren(this);
}

CParser::EnumerationConstantContext* CParser::enumerationConstant() {
  EnumerationConstantContext *_localctx = _tracker.createInstance<EnumerationConstantContext>(_ctx, getState());
  enterRule(_localctx, 84, CParser::RuleEnumerationConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(717);
    match(CParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AtomicTypeSpecifierContext ------------------------------------------------------------------

CParser::AtomicTypeSpecifierContext::AtomicTypeSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::AtomicTypeSpecifierContext::Atomic() {
  return getToken(CParser::Atomic, 0);
}

tree::TerminalNode* CParser::AtomicTypeSpecifierContext::LeftParen() {
  return getToken(CParser::LeftParen, 0);
}

CParser::TypeNameContext* CParser::AtomicTypeSpecifierContext::typeName() {
  return getRuleContext<CParser::TypeNameContext>(0);
}

tree::TerminalNode* CParser::AtomicTypeSpecifierContext::RightParen() {
  return getToken(CParser::RightParen, 0);
}


size_t CParser::AtomicTypeSpecifierContext::getRuleIndex() const {
  return CParser::RuleAtomicTypeSpecifier;
}

void CParser::AtomicTypeSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtomicTypeSpecifier(this);
}

void CParser::AtomicTypeSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtomicTypeSpecifier(this);
}


antlrcpp::Any CParser::AtomicTypeSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitAtomicTypeSpecifier(this);
  else
    return visitor->visitChildren(this);
}

CParser::AtomicTypeSpecifierContext* CParser::atomicTypeSpecifier() {
  AtomicTypeSpecifierContext *_localctx = _tracker.createInstance<AtomicTypeSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 86, CParser::RuleAtomicTypeSpecifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(719);
    match(CParser::Atomic);
    setState(720);
    match(CParser::LeftParen);
    setState(721);
    typeName();
    setState(722);
    match(CParser::RightParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeQualifierContext ------------------------------------------------------------------

CParser::TypeQualifierContext::TypeQualifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::TypeQualifierContext::Const() {
  return getToken(CParser::Const, 0);
}

tree::TerminalNode* CParser::TypeQualifierContext::Restrict() {
  return getToken(CParser::Restrict, 0);
}

tree::TerminalNode* CParser::TypeQualifierContext::Volatile() {
  return getToken(CParser::Volatile, 0);
}

tree::TerminalNode* CParser::TypeQualifierContext::Atomic() {
  return getToken(CParser::Atomic, 0);
}


size_t CParser::TypeQualifierContext::getRuleIndex() const {
  return CParser::RuleTypeQualifier;
}

void CParser::TypeQualifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeQualifier(this);
}

void CParser::TypeQualifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeQualifier(this);
}


antlrcpp::Any CParser::TypeQualifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitTypeQualifier(this);
  else
    return visitor->visitChildren(this);
}

CParser::TypeQualifierContext* CParser::typeQualifier() {
  TypeQualifierContext *_localctx = _tracker.createInstance<TypeQualifierContext>(_ctx, getState());
  enterRule(_localctx, 88, CParser::RuleTypeQualifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(724);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__8)
      | (1ULL << CParser::T__9)
      | (1ULL << CParser::Const)
      | (1ULL << CParser::Restrict)
      | (1ULL << CParser::Volatile)
      | (1ULL << CParser::Atomic))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionSpecifierContext ------------------------------------------------------------------

CParser::FunctionSpecifierContext::FunctionSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::FunctionSpecifierContext::Inline() {
  return getToken(CParser::Inline, 0);
}

tree::TerminalNode* CParser::FunctionSpecifierContext::Noreturn() {
  return getToken(CParser::Noreturn, 0);
}

CParser::GccAttributeSpecifierContext* CParser::FunctionSpecifierContext::gccAttributeSpecifier() {
  return getRuleContext<CParser::GccAttributeSpecifierContext>(0);
}

tree::TerminalNode* CParser::FunctionSpecifierContext::LeftParen() {
  return getToken(CParser::LeftParen, 0);
}

tree::TerminalNode* CParser::FunctionSpecifierContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}

tree::TerminalNode* CParser::FunctionSpecifierContext::RightParen() {
  return getToken(CParser::RightParen, 0);
}


size_t CParser::FunctionSpecifierContext::getRuleIndex() const {
  return CParser::RuleFunctionSpecifier;
}

void CParser::FunctionSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionSpecifier(this);
}

void CParser::FunctionSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionSpecifier(this);
}


antlrcpp::Any CParser::FunctionSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitFunctionSpecifier(this);
  else
    return visitor->visitChildren(this);
}

CParser::FunctionSpecifierContext* CParser::functionSpecifier() {
  FunctionSpecifierContext *_localctx = _tracker.createInstance<FunctionSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 90, CParser::RuleFunctionSpecifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(732);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::T__10:
      case CParser::T__11:
      case CParser::Inline:
      case CParser::Noreturn: {
        enterOuterAlt(_localctx, 1);
        setState(726);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CParser::T__10)
          | (1ULL << CParser::T__11)
          | (1ULL << CParser::Inline)
          | (1ULL << CParser::Noreturn))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

      case CParser::T__15: {
        enterOuterAlt(_localctx, 2);
        setState(727);
        gccAttributeSpecifier();
        break;
      }

      case CParser::T__12: {
        enterOuterAlt(_localctx, 3);
        setState(728);
        match(CParser::T__12);
        setState(729);
        match(CParser::LeftParen);
        setState(730);
        match(CParser::Identifier);
        setState(731);
        match(CParser::RightParen);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AlignmentSpecifierContext ------------------------------------------------------------------

CParser::AlignmentSpecifierContext::AlignmentSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::AlignmentSpecifierContext::Alignas() {
  return getToken(CParser::Alignas, 0);
}

tree::TerminalNode* CParser::AlignmentSpecifierContext::LeftParen() {
  return getToken(CParser::LeftParen, 0);
}

CParser::TypeNameContext* CParser::AlignmentSpecifierContext::typeName() {
  return getRuleContext<CParser::TypeNameContext>(0);
}

tree::TerminalNode* CParser::AlignmentSpecifierContext::RightParen() {
  return getToken(CParser::RightParen, 0);
}

CParser::ConstantExpressionContext* CParser::AlignmentSpecifierContext::constantExpression() {
  return getRuleContext<CParser::ConstantExpressionContext>(0);
}


size_t CParser::AlignmentSpecifierContext::getRuleIndex() const {
  return CParser::RuleAlignmentSpecifier;
}

void CParser::AlignmentSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAlignmentSpecifier(this);
}

void CParser::AlignmentSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAlignmentSpecifier(this);
}


antlrcpp::Any CParser::AlignmentSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitAlignmentSpecifier(this);
  else
    return visitor->visitChildren(this);
}

CParser::AlignmentSpecifierContext* CParser::alignmentSpecifier() {
  AlignmentSpecifierContext *_localctx = _tracker.createInstance<AlignmentSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 92, CParser::RuleAlignmentSpecifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(744);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(734);
      match(CParser::Alignas);
      setState(735);
      match(CParser::LeftParen);
      setState(736);
      typeName();
      setState(737);
      match(CParser::RightParen);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(739);
      match(CParser::Alignas);
      setState(740);
      match(CParser::LeftParen);
      setState(741);
      constantExpression();
      setState(742);
      match(CParser::RightParen);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclaratorContext ------------------------------------------------------------------

CParser::DeclaratorContext::DeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DirectDeclaratorContext* CParser::DeclaratorContext::directDeclarator() {
  return getRuleContext<CParser::DirectDeclaratorContext>(0);
}

CParser::PointerContext* CParser::DeclaratorContext::pointer() {
  return getRuleContext<CParser::PointerContext>(0);
}

std::vector<CParser::GccDeclaratorExtensionContext *> CParser::DeclaratorContext::gccDeclaratorExtension() {
  return getRuleContexts<CParser::GccDeclaratorExtensionContext>();
}

CParser::GccDeclaratorExtensionContext* CParser::DeclaratorContext::gccDeclaratorExtension(size_t i) {
  return getRuleContext<CParser::GccDeclaratorExtensionContext>(i);
}


size_t CParser::DeclaratorContext::getRuleIndex() const {
  return CParser::RuleDeclarator;
}

void CParser::DeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarator(this);
}

void CParser::DeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarator(this);
}


antlrcpp::Any CParser::DeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDeclarator(this);
  else
    return visitor->visitChildren(this);
}

CParser::DeclaratorContext* CParser::declarator() {
  DeclaratorContext *_localctx = _tracker.createInstance<DeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 94, CParser::RuleDeclarator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(747);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::Star

    || _la == CParser::Caret) {
      setState(746);
      pointer();
    }
    setState(749);
    directDeclarator(0);
    setState(753);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(750);
        gccDeclaratorExtension(); 
      }
      setState(755);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DirectDeclaratorContext ------------------------------------------------------------------

CParser::DirectDeclaratorContext::DirectDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::DirectDeclaratorContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}

tree::TerminalNode* CParser::DirectDeclaratorContext::LeftParen() {
  return getToken(CParser::LeftParen, 0);
}

CParser::DeclaratorContext* CParser::DirectDeclaratorContext::declarator() {
  return getRuleContext<CParser::DeclaratorContext>(0);
}

tree::TerminalNode* CParser::DirectDeclaratorContext::RightParen() {
  return getToken(CParser::RightParen, 0);
}

tree::TerminalNode* CParser::DirectDeclaratorContext::Colon() {
  return getToken(CParser::Colon, 0);
}

tree::TerminalNode* CParser::DirectDeclaratorContext::DigitSequence() {
  return getToken(CParser::DigitSequence, 0);
}

CParser::PointerContext* CParser::DirectDeclaratorContext::pointer() {
  return getRuleContext<CParser::PointerContext>(0);
}

CParser::DirectDeclaratorContext* CParser::DirectDeclaratorContext::directDeclarator() {
  return getRuleContext<CParser::DirectDeclaratorContext>(0);
}

CParser::TypeSpecifierContext* CParser::DirectDeclaratorContext::typeSpecifier() {
  return getRuleContext<CParser::TypeSpecifierContext>(0);
}

tree::TerminalNode* CParser::DirectDeclaratorContext::LeftBracket() {
  return getToken(CParser::LeftBracket, 0);
}

tree::TerminalNode* CParser::DirectDeclaratorContext::RightBracket() {
  return getToken(CParser::RightBracket, 0);
}

CParser::TypeQualifierListContext* CParser::DirectDeclaratorContext::typeQualifierList() {
  return getRuleContext<CParser::TypeQualifierListContext>(0);
}

CParser::AssignmentExpressionContext* CParser::DirectDeclaratorContext::assignmentExpression() {
  return getRuleContext<CParser::AssignmentExpressionContext>(0);
}

tree::TerminalNode* CParser::DirectDeclaratorContext::Static() {
  return getToken(CParser::Static, 0);
}

tree::TerminalNode* CParser::DirectDeclaratorContext::Star() {
  return getToken(CParser::Star, 0);
}

CParser::ParameterTypeListContext* CParser::DirectDeclaratorContext::parameterTypeList() {
  return getRuleContext<CParser::ParameterTypeListContext>(0);
}

CParser::IdentifierListContext* CParser::DirectDeclaratorContext::identifierList() {
  return getRuleContext<CParser::IdentifierListContext>(0);
}


size_t CParser::DirectDeclaratorContext::getRuleIndex() const {
  return CParser::RuleDirectDeclarator;
}

void CParser::DirectDeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDirectDeclarator(this);
}

void CParser::DirectDeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDirectDeclarator(this);
}


antlrcpp::Any CParser::DirectDeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDirectDeclarator(this);
  else
    return visitor->visitChildren(this);
}


CParser::DirectDeclaratorContext* CParser::directDeclarator() {
   return directDeclarator(0);
}

CParser::DirectDeclaratorContext* CParser::directDeclarator(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::DirectDeclaratorContext *_localctx = _tracker.createInstance<DirectDeclaratorContext>(_ctx, parentState);
  CParser::DirectDeclaratorContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 96;
  enterRecursionRule(_localctx, 96, CParser::RuleDirectDeclarator, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(773);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx)) {
    case 1: {
      setState(757);
      match(CParser::Identifier);
      break;
    }

    case 2: {
      setState(758);
      match(CParser::LeftParen);
      setState(759);
      declarator();
      setState(760);
      match(CParser::RightParen);
      break;
    }

    case 3: {
      setState(762);
      match(CParser::Identifier);
      setState(763);
      match(CParser::Colon);
      setState(764);
      match(CParser::DigitSequence);
      break;
    }

    case 4: {
      setState(765);
      match(CParser::LeftParen);
      setState(767);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__0)
        | (1ULL << CParser::T__4)
        | (1ULL << CParser::T__5)
        | (1ULL << CParser::T__6)
        | (1ULL << CParser::T__7)
        | (1ULL << CParser::Char)
        | (1ULL << CParser::Double)
        | (1ULL << CParser::Enum)
        | (1ULL << CParser::Float)
        | (1ULL << CParser::Int)
        | (1ULL << CParser::Long)
        | (1ULL << CParser::Short)
        | (1ULL << CParser::Signed)
        | (1ULL << CParser::Struct)
        | (1ULL << CParser::Typeof)
        | (1ULL << CParser::Union)
        | (1ULL << CParser::Unsigned)
        | (1ULL << CParser::Void)
        | (1ULL << CParser::Atomic)
        | (1ULL << CParser::Bool)
        | (1ULL << CParser::Complex))) != 0) || _la == CParser::Identifier) {
        setState(766);
        typeSpecifier(0);
      }
      setState(769);
      pointer();
      setState(770);
      directDeclarator(0);
      setState(771);
      match(CParser::RightParen);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(820);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(818);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(775);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(776);
          match(CParser::LeftBracket);
          setState(778);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CParser::T__8)
            | (1ULL << CParser::T__9)
            | (1ULL << CParser::Const)
            | (1ULL << CParser::Restrict)
            | (1ULL << CParser::Volatile)
            | (1ULL << CParser::Atomic))) != 0)) {
            setState(777);
            typeQualifierList(0);
          }
          setState(781);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CParser::T__0)
            | (1ULL << CParser::T__1)
            | (1ULL << CParser::T__2)
            | (1ULL << CParser::T__3)
            | (1ULL << CParser::Sizeof)
            | (1ULL << CParser::Alignof)
            | (1ULL << CParser::Generic)
            | (1ULL << CParser::LeftParen))) != 0) || ((((_la - 75) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 75)) & ((1ULL << (CParser::Plus - 75))
            | (1ULL << (CParser::PlusPlus - 75))
            | (1ULL << (CParser::Minus - 75))
            | (1ULL << (CParser::MinusMinus - 75))
            | (1ULL << (CParser::Star - 75))
            | (1ULL << (CParser::And - 75))
            | (1ULL << (CParser::AndAnd - 75))
            | (1ULL << (CParser::Not - 75))
            | (1ULL << (CParser::Tilde - 75))
            | (1ULL << (CParser::Identifier - 75))
            | (1ULL << (CParser::Constant - 75))
            | (1ULL << (CParser::DigitSequence - 75))
            | (1ULL << (CParser::StringLiteral - 75)))) != 0)) {
            setState(780);
            assignmentExpression();
          }
          setState(783);
          match(CParser::RightBracket);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(784);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(785);
          match(CParser::LeftBracket);
          setState(786);
          match(CParser::Static);
          setState(788);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CParser::T__8)
            | (1ULL << CParser::T__9)
            | (1ULL << CParser::Const)
            | (1ULL << CParser::Restrict)
            | (1ULL << CParser::Volatile)
            | (1ULL << CParser::Atomic))) != 0)) {
            setState(787);
            typeQualifierList(0);
          }
          setState(790);
          assignmentExpression();
          setState(791);
          match(CParser::RightBracket);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(793);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(794);
          match(CParser::LeftBracket);
          setState(795);
          typeQualifierList(0);
          setState(796);
          match(CParser::Static);
          setState(797);
          assignmentExpression();
          setState(798);
          match(CParser::RightBracket);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(800);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(801);
          match(CParser::LeftBracket);
          setState(803);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CParser::T__8)
            | (1ULL << CParser::T__9)
            | (1ULL << CParser::Const)
            | (1ULL << CParser::Restrict)
            | (1ULL << CParser::Volatile)
            | (1ULL << CParser::Atomic))) != 0)) {
            setState(802);
            typeQualifierList(0);
          }
          setState(805);
          match(CParser::Star);
          setState(806);
          match(CParser::RightBracket);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(807);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(808);
          match(CParser::LeftParen);
          setState(809);
          parameterTypeList();
          setState(810);
          match(CParser::RightParen);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(812);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(813);
          match(CParser::LeftParen);
          setState(815);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CParser::Identifier) {
            setState(814);
            identifierList(0);
          }
          setState(817);
          match(CParser::RightParen);
          break;
        }

        } 
      }
      setState(822);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- GccDeclaratorExtensionContext ------------------------------------------------------------------

CParser::GccDeclaratorExtensionContext::GccDeclaratorExtensionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::GccDeclaratorExtensionContext::LeftParen() {
  return getToken(CParser::LeftParen, 0);
}

tree::TerminalNode* CParser::GccDeclaratorExtensionContext::RightParen() {
  return getToken(CParser::RightParen, 0);
}

std::vector<tree::TerminalNode *> CParser::GccDeclaratorExtensionContext::StringLiteral() {
  return getTokens(CParser::StringLiteral);
}

tree::TerminalNode* CParser::GccDeclaratorExtensionContext::StringLiteral(size_t i) {
  return getToken(CParser::StringLiteral, i);
}

CParser::GccAttributeSpecifierContext* CParser::GccDeclaratorExtensionContext::gccAttributeSpecifier() {
  return getRuleContext<CParser::GccAttributeSpecifierContext>(0);
}


size_t CParser::GccDeclaratorExtensionContext::getRuleIndex() const {
  return CParser::RuleGccDeclaratorExtension;
}

void CParser::GccDeclaratorExtensionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGccDeclaratorExtension(this);
}

void CParser::GccDeclaratorExtensionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGccDeclaratorExtension(this);
}


antlrcpp::Any CParser::GccDeclaratorExtensionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitGccDeclaratorExtension(this);
  else
    return visitor->visitChildren(this);
}

CParser::GccDeclaratorExtensionContext* CParser::gccDeclaratorExtension() {
  GccDeclaratorExtensionContext *_localctx = _tracker.createInstance<GccDeclaratorExtensionContext>(_ctx, getState());
  enterRule(_localctx, 98, CParser::RuleGccDeclaratorExtension);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(832);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::T__13:
      case CParser::T__14: {
        enterOuterAlt(_localctx, 1);
        setState(823);
        _la = _input->LA(1);
        if (!(_la == CParser::T__13

        || _la == CParser::T__14)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(824);
        match(CParser::LeftParen);
        setState(826); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(825);
          match(CParser::StringLiteral);
          setState(828); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == CParser::StringLiteral);
        setState(830);
        match(CParser::RightParen);
        break;
      }

      case CParser::T__15: {
        enterOuterAlt(_localctx, 2);
        setState(831);
        gccAttributeSpecifier();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GccAttributeSpecifierContext ------------------------------------------------------------------

CParser::GccAttributeSpecifierContext::GccAttributeSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> CParser::GccAttributeSpecifierContext::LeftParen() {
  return getTokens(CParser::LeftParen);
}

tree::TerminalNode* CParser::GccAttributeSpecifierContext::LeftParen(size_t i) {
  return getToken(CParser::LeftParen, i);
}

CParser::GccAttributeListContext* CParser::GccAttributeSpecifierContext::gccAttributeList() {
  return getRuleContext<CParser::GccAttributeListContext>(0);
}

std::vector<tree::TerminalNode *> CParser::GccAttributeSpecifierContext::RightParen() {
  return getTokens(CParser::RightParen);
}

tree::TerminalNode* CParser::GccAttributeSpecifierContext::RightParen(size_t i) {
  return getToken(CParser::RightParen, i);
}


size_t CParser::GccAttributeSpecifierContext::getRuleIndex() const {
  return CParser::RuleGccAttributeSpecifier;
}

void CParser::GccAttributeSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGccAttributeSpecifier(this);
}

void CParser::GccAttributeSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGccAttributeSpecifier(this);
}


antlrcpp::Any CParser::GccAttributeSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitGccAttributeSpecifier(this);
  else
    return visitor->visitChildren(this);
}

CParser::GccAttributeSpecifierContext* CParser::gccAttributeSpecifier() {
  GccAttributeSpecifierContext *_localctx = _tracker.createInstance<GccAttributeSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 100, CParser::RuleGccAttributeSpecifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(834);
    match(CParser::T__15);
    setState(835);
    match(CParser::LeftParen);
    setState(836);
    match(CParser::LeftParen);
    setState(837);
    gccAttributeList();
    setState(838);
    match(CParser::RightParen);
    setState(839);
    match(CParser::RightParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GccAttributeListContext ------------------------------------------------------------------

CParser::GccAttributeListContext::GccAttributeListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::GccAttributeContext *> CParser::GccAttributeListContext::gccAttribute() {
  return getRuleContexts<CParser::GccAttributeContext>();
}

CParser::GccAttributeContext* CParser::GccAttributeListContext::gccAttribute(size_t i) {
  return getRuleContext<CParser::GccAttributeContext>(i);
}

std::vector<tree::TerminalNode *> CParser::GccAttributeListContext::Comma() {
  return getTokens(CParser::Comma);
}

tree::TerminalNode* CParser::GccAttributeListContext::Comma(size_t i) {
  return getToken(CParser::Comma, i);
}


size_t CParser::GccAttributeListContext::getRuleIndex() const {
  return CParser::RuleGccAttributeList;
}

void CParser::GccAttributeListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGccAttributeList(this);
}

void CParser::GccAttributeListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGccAttributeList(this);
}


antlrcpp::Any CParser::GccAttributeListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitGccAttributeList(this);
  else
    return visitor->visitChildren(this);
}

CParser::GccAttributeListContext* CParser::gccAttributeList() {
  GccAttributeListContext *_localctx = _tracker.createInstance<GccAttributeListContext>(_ctx, getState());
  enterRule(_localctx, 102, CParser::RuleGccAttributeList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(850);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(841);
      gccAttribute();
      setState(846);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CParser::Comma) {
        setState(842);
        match(CParser::Comma);
        setState(843);
        gccAttribute();
        setState(848);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);

      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GccAttributeContext ------------------------------------------------------------------

CParser::GccAttributeContext::GccAttributeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::GccAttributeContext::Comma() {
  return getToken(CParser::Comma, 0);
}

std::vector<tree::TerminalNode *> CParser::GccAttributeContext::LeftParen() {
  return getTokens(CParser::LeftParen);
}

tree::TerminalNode* CParser::GccAttributeContext::LeftParen(size_t i) {
  return getToken(CParser::LeftParen, i);
}

std::vector<tree::TerminalNode *> CParser::GccAttributeContext::RightParen() {
  return getTokens(CParser::RightParen);
}

tree::TerminalNode* CParser::GccAttributeContext::RightParen(size_t i) {
  return getToken(CParser::RightParen, i);
}

CParser::ArgumentExpressionListContext* CParser::GccAttributeContext::argumentExpressionList() {
  return getRuleContext<CParser::ArgumentExpressionListContext>(0);
}


size_t CParser::GccAttributeContext::getRuleIndex() const {
  return CParser::RuleGccAttribute;
}

void CParser::GccAttributeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGccAttribute(this);
}

void CParser::GccAttributeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGccAttribute(this);
}


antlrcpp::Any CParser::GccAttributeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitGccAttribute(this);
  else
    return visitor->visitChildren(this);
}

CParser::GccAttributeContext* CParser::gccAttribute() {
  GccAttributeContext *_localctx = _tracker.createInstance<GccAttributeContext>(_ctx, getState());
  enterRule(_localctx, 104, CParser::RuleGccAttribute);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(861);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::T__0:
      case CParser::T__1:
      case CParser::T__2:
      case CParser::T__3:
      case CParser::T__4:
      case CParser::T__5:
      case CParser::T__6:
      case CParser::T__7:
      case CParser::T__8:
      case CParser::T__9:
      case CParser::T__10:
      case CParser::T__11:
      case CParser::T__12:
      case CParser::T__13:
      case CParser::T__14:
      case CParser::T__15:
      case CParser::T__16:
      case CParser::Auto:
      case CParser::Break:
      case CParser::Case:
      case CParser::Char:
      case CParser::Const:
      case CParser::Continue:
      case CParser::Default:
      case CParser::Do:
      case CParser::Double:
      case CParser::Else:
      case CParser::Enum:
      case CParser::Extern:
      case CParser::Float:
      case CParser::For:
      case CParser::Goto:
      case CParser::If:
      case CParser::Inline:
      case CParser::Int:
      case CParser::Long:
      case CParser::Register:
      case CParser::Restrict:
      case CParser::Return:
      case CParser::Short:
      case CParser::Signed:
      case CParser::Sizeof:
      case CParser::Static:
      case CParser::Struct:
      case CParser::Switch:
      case CParser::Typedef:
      case CParser::Typeof:
      case CParser::Union:
      case CParser::Unsigned:
      case CParser::Void:
      case CParser::Volatile:
      case CParser::While:
      case CParser::Alignas:
      case CParser::Alignof:
      case CParser::Atomic:
      case CParser::Bool:
      case CParser::Complex:
      case CParser::Generic:
      case CParser::Imaginary:
      case CParser::Noreturn:
      case CParser::StaticAssert:
      case CParser::ThreadLocal:
      case CParser::LeftBracket:
      case CParser::RightBracket:
      case CParser::LeftBrace:
      case CParser::RightBrace:
      case CParser::Less:
      case CParser::LessEqual:
      case CParser::Greater:
      case CParser::GreaterEqual:
      case CParser::LeftShift:
      case CParser::RightShift:
      case CParser::Plus:
      case CParser::PlusPlus:
      case CParser::Minus:
      case CParser::MinusMinus:
      case CParser::Star:
      case CParser::Div:
      case CParser::Mod:
      case CParser::And:
      case CParser::Or:
      case CParser::AndAnd:
      case CParser::OrOr:
      case CParser::Caret:
      case CParser::Not:
      case CParser::Tilde:
      case CParser::Question:
      case CParser::Colon:
      case CParser::Semi:
      case CParser::Assign:
      case CParser::StarAssign:
      case CParser::DivAssign:
      case CParser::ModAssign:
      case CParser::PlusAssign:
      case CParser::MinusAssign:
      case CParser::LeftShiftAssign:
      case CParser::RightShiftAssign:
      case CParser::AndAssign:
      case CParser::XorAssign:
      case CParser::OrAssign:
      case CParser::Equal:
      case CParser::NotEqual:
      case CParser::Arrow:
      case CParser::Dot:
      case CParser::Ellipsis:
      case CParser::Identifier:
      case CParser::Constant:
      case CParser::DigitSequence:
      case CParser::StringLiteral:
      case CParser::ComplexDefine:
      case CParser::IncludeDirective:
      case CParser::LineAfterPreprocessing:
      case CParser::LineDirective:
      case CParser::PragmaDirective:
      case CParser::Whitespace:
      case CParser::Newline:
      case CParser::BlockComment:
      case CParser::LineComment: {
        enterOuterAlt(_localctx, 1);
        setState(852);
        _la = _input->LA(1);
        if (_la == 0 || _la == Token::EOF || (((((_la - 63) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 63)) & ((1ULL << (CParser::LeftParen - 63))
          | (1ULL << (CParser::RightParen - 63))
          | (1ULL << (CParser::Comma - 63)))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(858);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CParser::LeftParen) {
          setState(853);
          match(CParser::LeftParen);
          setState(855);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CParser::T__0)
            | (1ULL << CParser::T__1)
            | (1ULL << CParser::T__2)
            | (1ULL << CParser::T__3)
            | (1ULL << CParser::Sizeof)
            | (1ULL << CParser::Alignof)
            | (1ULL << CParser::Generic)
            | (1ULL << CParser::LeftParen))) != 0) || ((((_la - 75) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 75)) & ((1ULL << (CParser::Plus - 75))
            | (1ULL << (CParser::PlusPlus - 75))
            | (1ULL << (CParser::Minus - 75))
            | (1ULL << (CParser::MinusMinus - 75))
            | (1ULL << (CParser::Star - 75))
            | (1ULL << (CParser::And - 75))
            | (1ULL << (CParser::AndAnd - 75))
            | (1ULL << (CParser::Not - 75))
            | (1ULL << (CParser::Tilde - 75))
            | (1ULL << (CParser::Identifier - 75))
            | (1ULL << (CParser::Constant - 75))
            | (1ULL << (CParser::DigitSequence - 75))
            | (1ULL << (CParser::StringLiteral - 75)))) != 0)) {
            setState(854);
            argumentExpressionList(0);
          }
          setState(857);
          match(CParser::RightParen);
        }
        break;
      }

      case CParser::RightParen:
      case CParser::Comma: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NestedParenthesesBlockContext ------------------------------------------------------------------

CParser::NestedParenthesesBlockContext::NestedParenthesesBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> CParser::NestedParenthesesBlockContext::LeftParen() {
  return getTokens(CParser::LeftParen);
}

tree::TerminalNode* CParser::NestedParenthesesBlockContext::LeftParen(size_t i) {
  return getToken(CParser::LeftParen, i);
}

std::vector<CParser::NestedParenthesesBlockContext *> CParser::NestedParenthesesBlockContext::nestedParenthesesBlock() {
  return getRuleContexts<CParser::NestedParenthesesBlockContext>();
}

CParser::NestedParenthesesBlockContext* CParser::NestedParenthesesBlockContext::nestedParenthesesBlock(size_t i) {
  return getRuleContext<CParser::NestedParenthesesBlockContext>(i);
}

std::vector<tree::TerminalNode *> CParser::NestedParenthesesBlockContext::RightParen() {
  return getTokens(CParser::RightParen);
}

tree::TerminalNode* CParser::NestedParenthesesBlockContext::RightParen(size_t i) {
  return getToken(CParser::RightParen, i);
}


size_t CParser::NestedParenthesesBlockContext::getRuleIndex() const {
  return CParser::RuleNestedParenthesesBlock;
}

void CParser::NestedParenthesesBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNestedParenthesesBlock(this);
}

void CParser::NestedParenthesesBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNestedParenthesesBlock(this);
}


antlrcpp::Any CParser::NestedParenthesesBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitNestedParenthesesBlock(this);
  else
    return visitor->visitChildren(this);
}

CParser::NestedParenthesesBlockContext* CParser::nestedParenthesesBlock() {
  NestedParenthesesBlockContext *_localctx = _tracker.createInstance<NestedParenthesesBlockContext>(_ctx, getState());
  enterRule(_localctx, 106, CParser::RuleNestedParenthesesBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(870);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__0)
      | (1ULL << CParser::T__1)
      | (1ULL << CParser::T__2)
      | (1ULL << CParser::T__3)
      | (1ULL << CParser::T__4)
      | (1ULL << CParser::T__5)
      | (1ULL << CParser::T__6)
      | (1ULL << CParser::T__7)
      | (1ULL << CParser::T__8)
      | (1ULL << CParser::T__9)
      | (1ULL << CParser::T__10)
      | (1ULL << CParser::T__11)
      | (1ULL << CParser::T__12)
      | (1ULL << CParser::T__13)
      | (1ULL << CParser::T__14)
      | (1ULL << CParser::T__15)
      | (1ULL << CParser::T__16)
      | (1ULL << CParser::Auto)
      | (1ULL << CParser::Break)
      | (1ULL << CParser::Case)
      | (1ULL << CParser::Char)
      | (1ULL << CParser::Const)
      | (1ULL << CParser::Continue)
      | (1ULL << CParser::Default)
      | (1ULL << CParser::Do)
      | (1ULL << CParser::Double)
      | (1ULL << CParser::Else)
      | (1ULL << CParser::Enum)
      | (1ULL << CParser::Extern)
      | (1ULL << CParser::Float)
      | (1ULL << CParser::For)
      | (1ULL << CParser::Goto)
      | (1ULL << CParser::If)
      | (1ULL << CParser::Inline)
      | (1ULL << CParser::Int)
      | (1ULL << CParser::Long)
      | (1ULL << CParser::Register)
      | (1ULL << CParser::Restrict)
      | (1ULL << CParser::Return)
      | (1ULL << CParser::Short)
      | (1ULL << CParser::Signed)
      | (1ULL << CParser::Sizeof)
      | (1ULL << CParser::Static)
      | (1ULL << CParser::Struct)
      | (1ULL << CParser::Switch)
      | (1ULL << CParser::Typedef)
      | (1ULL << CParser::Typeof)
      | (1ULL << CParser::Union)
      | (1ULL << CParser::Unsigned)
      | (1ULL << CParser::Void)
      | (1ULL << CParser::Volatile)
      | (1ULL << CParser::While)
      | (1ULL << CParser::Alignas)
      | (1ULL << CParser::Alignof)
      | (1ULL << CParser::Atomic)
      | (1ULL << CParser::Bool)
      | (1ULL << CParser::Complex)
      | (1ULL << CParser::Generic)
      | (1ULL << CParser::Imaginary)
      | (1ULL << CParser::Noreturn)
      | (1ULL << CParser::StaticAssert)
      | (1ULL << CParser::ThreadLocal)
      | (1ULL << CParser::LeftParen))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & ((1ULL << (CParser::LeftBracket - 65))
      | (1ULL << (CParser::RightBracket - 65))
      | (1ULL << (CParser::LeftBrace - 65))
      | (1ULL << (CParser::RightBrace - 65))
      | (1ULL << (CParser::Less - 65))
      | (1ULL << (CParser::LessEqual - 65))
      | (1ULL << (CParser::Greater - 65))
      | (1ULL << (CParser::GreaterEqual - 65))
      | (1ULL << (CParser::LeftShift - 65))
      | (1ULL << (CParser::RightShift - 65))
      | (1ULL << (CParser::Plus - 65))
      | (1ULL << (CParser::PlusPlus - 65))
      | (1ULL << (CParser::Minus - 65))
      | (1ULL << (CParser::MinusMinus - 65))
      | (1ULL << (CParser::Star - 65))
      | (1ULL << (CParser::Div - 65))
      | (1ULL << (CParser::Mod - 65))
      | (1ULL << (CParser::And - 65))
      | (1ULL << (CParser::Or - 65))
      | (1ULL << (CParser::AndAnd - 65))
      | (1ULL << (CParser::OrOr - 65))
      | (1ULL << (CParser::Caret - 65))
      | (1ULL << (CParser::Not - 65))
      | (1ULL << (CParser::Tilde - 65))
      | (1ULL << (CParser::Question - 65))
      | (1ULL << (CParser::Colon - 65))
      | (1ULL << (CParser::Semi - 65))
      | (1ULL << (CParser::Comma - 65))
      | (1ULL << (CParser::Assign - 65))
      | (1ULL << (CParser::StarAssign - 65))
      | (1ULL << (CParser::DivAssign - 65))
      | (1ULL << (CParser::ModAssign - 65))
      | (1ULL << (CParser::PlusAssign - 65))
      | (1ULL << (CParser::MinusAssign - 65))
      | (1ULL << (CParser::LeftShiftAssign - 65))
      | (1ULL << (CParser::RightShiftAssign - 65))
      | (1ULL << (CParser::AndAssign - 65))
      | (1ULL << (CParser::XorAssign - 65))
      | (1ULL << (CParser::OrAssign - 65))
      | (1ULL << (CParser::Equal - 65))
      | (1ULL << (CParser::NotEqual - 65))
      | (1ULL << (CParser::Arrow - 65))
      | (1ULL << (CParser::Dot - 65))
      | (1ULL << (CParser::Ellipsis - 65))
      | (1ULL << (CParser::Identifier - 65))
      | (1ULL << (CParser::Constant - 65))
      | (1ULL << (CParser::DigitSequence - 65))
      | (1ULL << (CParser::StringLiteral - 65))
      | (1ULL << (CParser::ComplexDefine - 65))
      | (1ULL << (CParser::IncludeDirective - 65))
      | (1ULL << (CParser::LineAfterPreprocessing - 65))
      | (1ULL << (CParser::LineDirective - 65))
      | (1ULL << (CParser::PragmaDirective - 65))
      | (1ULL << (CParser::Whitespace - 65))
      | (1ULL << (CParser::Newline - 65))
      | (1ULL << (CParser::BlockComment - 65))
      | (1ULL << (CParser::LineComment - 65)))) != 0)) {
      setState(868);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case CParser::T__0:
        case CParser::T__1:
        case CParser::T__2:
        case CParser::T__3:
        case CParser::T__4:
        case CParser::T__5:
        case CParser::T__6:
        case CParser::T__7:
        case CParser::T__8:
        case CParser::T__9:
        case CParser::T__10:
        case CParser::T__11:
        case CParser::T__12:
        case CParser::T__13:
        case CParser::T__14:
        case CParser::T__15:
        case CParser::T__16:
        case CParser::Auto:
        case CParser::Break:
        case CParser::Case:
        case CParser::Char:
        case CParser::Const:
        case CParser::Continue:
        case CParser::Default:
        case CParser::Do:
        case CParser::Double:
        case CParser::Else:
        case CParser::Enum:
        case CParser::Extern:
        case CParser::Float:
        case CParser::For:
        case CParser::Goto:
        case CParser::If:
        case CParser::Inline:
        case CParser::Int:
        case CParser::Long:
        case CParser::Register:
        case CParser::Restrict:
        case CParser::Return:
        case CParser::Short:
        case CParser::Signed:
        case CParser::Sizeof:
        case CParser::Static:
        case CParser::Struct:
        case CParser::Switch:
        case CParser::Typedef:
        case CParser::Typeof:
        case CParser::Union:
        case CParser::Unsigned:
        case CParser::Void:
        case CParser::Volatile:
        case CParser::While:
        case CParser::Alignas:
        case CParser::Alignof:
        case CParser::Atomic:
        case CParser::Bool:
        case CParser::Complex:
        case CParser::Generic:
        case CParser::Imaginary:
        case CParser::Noreturn:
        case CParser::StaticAssert:
        case CParser::ThreadLocal:
        case CParser::LeftBracket:
        case CParser::RightBracket:
        case CParser::LeftBrace:
        case CParser::RightBrace:
        case CParser::Less:
        case CParser::LessEqual:
        case CParser::Greater:
        case CParser::GreaterEqual:
        case CParser::LeftShift:
        case CParser::RightShift:
        case CParser::Plus:
        case CParser::PlusPlus:
        case CParser::Minus:
        case CParser::MinusMinus:
        case CParser::Star:
        case CParser::Div:
        case CParser::Mod:
        case CParser::And:
        case CParser::Or:
        case CParser::AndAnd:
        case CParser::OrOr:
        case CParser::Caret:
        case CParser::Not:
        case CParser::Tilde:
        case CParser::Question:
        case CParser::Colon:
        case CParser::Semi:
        case CParser::Comma:
        case CParser::Assign:
        case CParser::StarAssign:
        case CParser::DivAssign:
        case CParser::ModAssign:
        case CParser::PlusAssign:
        case CParser::MinusAssign:
        case CParser::LeftShiftAssign:
        case CParser::RightShiftAssign:
        case CParser::AndAssign:
        case CParser::XorAssign:
        case CParser::OrAssign:
        case CParser::Equal:
        case CParser::NotEqual:
        case CParser::Arrow:
        case CParser::Dot:
        case CParser::Ellipsis:
        case CParser::Identifier:
        case CParser::Constant:
        case CParser::DigitSequence:
        case CParser::StringLiteral:
        case CParser::ComplexDefine:
        case CParser::IncludeDirective:
        case CParser::LineAfterPreprocessing:
        case CParser::LineDirective:
        case CParser::PragmaDirective:
        case CParser::Whitespace:
        case CParser::Newline:
        case CParser::BlockComment:
        case CParser::LineComment: {
          setState(863);
          _la = _input->LA(1);
          if (_la == 0 || _la == Token::EOF || (_la == CParser::LeftParen

          || _la == CParser::RightParen)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          break;
        }

        case CParser::LeftParen: {
          setState(864);
          match(CParser::LeftParen);
          setState(865);
          nestedParenthesesBlock();
          setState(866);
          match(CParser::RightParen);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(872);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PointerContext ------------------------------------------------------------------

CParser::PointerContext::PointerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::PointerContext::Star() {
  return getToken(CParser::Star, 0);
}

CParser::TypeQualifierListContext* CParser::PointerContext::typeQualifierList() {
  return getRuleContext<CParser::TypeQualifierListContext>(0);
}

CParser::PointerContext* CParser::PointerContext::pointer() {
  return getRuleContext<CParser::PointerContext>(0);
}

tree::TerminalNode* CParser::PointerContext::Caret() {
  return getToken(CParser::Caret, 0);
}


size_t CParser::PointerContext::getRuleIndex() const {
  return CParser::RulePointer;
}

void CParser::PointerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPointer(this);
}

void CParser::PointerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPointer(this);
}


antlrcpp::Any CParser::PointerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitPointer(this);
  else
    return visitor->visitChildren(this);
}

CParser::PointerContext* CParser::pointer() {
  PointerContext *_localctx = _tracker.createInstance<PointerContext>(_ctx, getState());
  enterRule(_localctx, 108, CParser::RulePointer);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(891);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 83, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(873);
      match(CParser::Star);
      setState(875);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx)) {
      case 1: {
        setState(874);
        typeQualifierList(0);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(877);
      match(CParser::Star);
      setState(879);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__8)
        | (1ULL << CParser::T__9)
        | (1ULL << CParser::Const)
        | (1ULL << CParser::Restrict)
        | (1ULL << CParser::Volatile)
        | (1ULL << CParser::Atomic))) != 0)) {
        setState(878);
        typeQualifierList(0);
      }
      setState(881);
      pointer();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(882);
      match(CParser::Caret);
      setState(884);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx)) {
      case 1: {
        setState(883);
        typeQualifierList(0);
        break;
      }

      }
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(886);
      match(CParser::Caret);
      setState(888);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__8)
        | (1ULL << CParser::T__9)
        | (1ULL << CParser::Const)
        | (1ULL << CParser::Restrict)
        | (1ULL << CParser::Volatile)
        | (1ULL << CParser::Atomic))) != 0)) {
        setState(887);
        typeQualifierList(0);
      }
      setState(890);
      pointer();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeQualifierListContext ------------------------------------------------------------------

CParser::TypeQualifierListContext::TypeQualifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::TypeQualifierContext* CParser::TypeQualifierListContext::typeQualifier() {
  return getRuleContext<CParser::TypeQualifierContext>(0);
}

CParser::TypeQualifierListContext* CParser::TypeQualifierListContext::typeQualifierList() {
  return getRuleContext<CParser::TypeQualifierListContext>(0);
}


size_t CParser::TypeQualifierListContext::getRuleIndex() const {
  return CParser::RuleTypeQualifierList;
}

void CParser::TypeQualifierListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeQualifierList(this);
}

void CParser::TypeQualifierListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeQualifierList(this);
}


antlrcpp::Any CParser::TypeQualifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitTypeQualifierList(this);
  else
    return visitor->visitChildren(this);
}


CParser::TypeQualifierListContext* CParser::typeQualifierList() {
   return typeQualifierList(0);
}

CParser::TypeQualifierListContext* CParser::typeQualifierList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::TypeQualifierListContext *_localctx = _tracker.createInstance<TypeQualifierListContext>(_ctx, parentState);
  CParser::TypeQualifierListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 110;
  enterRecursionRule(_localctx, 110, CParser::RuleTypeQualifierList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(894);
    typeQualifier();
    _ctx->stop = _input->LT(-1);
    setState(900);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 84, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TypeQualifierListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTypeQualifierList);
        setState(896);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(897);
        typeQualifier(); 
      }
      setState(902);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 84, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ParameterTypeListContext ------------------------------------------------------------------

CParser::ParameterTypeListContext::ParameterTypeListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ParameterListContext* CParser::ParameterTypeListContext::parameterList() {
  return getRuleContext<CParser::ParameterListContext>(0);
}

tree::TerminalNode* CParser::ParameterTypeListContext::Comma() {
  return getToken(CParser::Comma, 0);
}

tree::TerminalNode* CParser::ParameterTypeListContext::Ellipsis() {
  return getToken(CParser::Ellipsis, 0);
}


size_t CParser::ParameterTypeListContext::getRuleIndex() const {
  return CParser::RuleParameterTypeList;
}

void CParser::ParameterTypeListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterTypeList(this);
}

void CParser::ParameterTypeListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterTypeList(this);
}


antlrcpp::Any CParser::ParameterTypeListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitParameterTypeList(this);
  else
    return visitor->visitChildren(this);
}

CParser::ParameterTypeListContext* CParser::parameterTypeList() {
  ParameterTypeListContext *_localctx = _tracker.createInstance<ParameterTypeListContext>(_ctx, getState());
  enterRule(_localctx, 112, CParser::RuleParameterTypeList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(908);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 85, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(903);
      parameterList(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(904);
      parameterList(0);
      setState(905);
      match(CParser::Comma);
      setState(906);
      match(CParser::Ellipsis);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterListContext ------------------------------------------------------------------

CParser::ParameterListContext::ParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ParameterDeclarationContext* CParser::ParameterListContext::parameterDeclaration() {
  return getRuleContext<CParser::ParameterDeclarationContext>(0);
}

CParser::ParameterListContext* CParser::ParameterListContext::parameterList() {
  return getRuleContext<CParser::ParameterListContext>(0);
}

tree::TerminalNode* CParser::ParameterListContext::Comma() {
  return getToken(CParser::Comma, 0);
}


size_t CParser::ParameterListContext::getRuleIndex() const {
  return CParser::RuleParameterList;
}

void CParser::ParameterListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterList(this);
}

void CParser::ParameterListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterList(this);
}


antlrcpp::Any CParser::ParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitParameterList(this);
  else
    return visitor->visitChildren(this);
}


CParser::ParameterListContext* CParser::parameterList() {
   return parameterList(0);
}

CParser::ParameterListContext* CParser::parameterList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::ParameterListContext *_localctx = _tracker.createInstance<ParameterListContext>(_ctx, parentState);
  CParser::ParameterListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 114;
  enterRecursionRule(_localctx, 114, CParser::RuleParameterList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(911);
    parameterDeclaration();
    _ctx->stop = _input->LT(-1);
    setState(918);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 86, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ParameterListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleParameterList);
        setState(913);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(914);
        match(CParser::Comma);
        setState(915);
        parameterDeclaration(); 
      }
      setState(920);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 86, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ParameterDeclarationContext ------------------------------------------------------------------

CParser::ParameterDeclarationContext::ParameterDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DeclarationSpecifiersContext* CParser::ParameterDeclarationContext::declarationSpecifiers() {
  return getRuleContext<CParser::DeclarationSpecifiersContext>(0);
}

CParser::DeclaratorContext* CParser::ParameterDeclarationContext::declarator() {
  return getRuleContext<CParser::DeclaratorContext>(0);
}

CParser::DeclarationSpecifiers2Context* CParser::ParameterDeclarationContext::declarationSpecifiers2() {
  return getRuleContext<CParser::DeclarationSpecifiers2Context>(0);
}

CParser::AbstractDeclaratorContext* CParser::ParameterDeclarationContext::abstractDeclarator() {
  return getRuleContext<CParser::AbstractDeclaratorContext>(0);
}


size_t CParser::ParameterDeclarationContext::getRuleIndex() const {
  return CParser::RuleParameterDeclaration;
}

void CParser::ParameterDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterDeclaration(this);
}

void CParser::ParameterDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterDeclaration(this);
}


antlrcpp::Any CParser::ParameterDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitParameterDeclaration(this);
  else
    return visitor->visitChildren(this);
}

CParser::ParameterDeclarationContext* CParser::parameterDeclaration() {
  ParameterDeclarationContext *_localctx = _tracker.createInstance<ParameterDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 116, CParser::RuleParameterDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(928);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 88, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(921);
      declarationSpecifiers();
      setState(922);
      declarator();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(924);
      declarationSpecifiers2();
      setState(926);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 87, _ctx)) {
      case 1: {
        setState(925);
        abstractDeclarator();
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierListContext ------------------------------------------------------------------

CParser::IdentifierListContext::IdentifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::IdentifierListContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}

CParser::IdentifierListContext* CParser::IdentifierListContext::identifierList() {
  return getRuleContext<CParser::IdentifierListContext>(0);
}

tree::TerminalNode* CParser::IdentifierListContext::Comma() {
  return getToken(CParser::Comma, 0);
}


size_t CParser::IdentifierListContext::getRuleIndex() const {
  return CParser::RuleIdentifierList;
}

void CParser::IdentifierListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifierList(this);
}

void CParser::IdentifierListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifierList(this);
}


antlrcpp::Any CParser::IdentifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitIdentifierList(this);
  else
    return visitor->visitChildren(this);
}


CParser::IdentifierListContext* CParser::identifierList() {
   return identifierList(0);
}

CParser::IdentifierListContext* CParser::identifierList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::IdentifierListContext *_localctx = _tracker.createInstance<IdentifierListContext>(_ctx, parentState);
  CParser::IdentifierListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 118;
  enterRecursionRule(_localctx, 118, CParser::RuleIdentifierList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(931);
    match(CParser::Identifier);
    _ctx->stop = _input->LT(-1);
    setState(938);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 89, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<IdentifierListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleIdentifierList);
        setState(933);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(934);
        match(CParser::Comma);
        setState(935);
        match(CParser::Identifier); 
      }
      setState(940);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 89, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TypeNameContext ------------------------------------------------------------------

CParser::TypeNameContext::TypeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::SpecifierQualifierListContext* CParser::TypeNameContext::specifierQualifierList() {
  return getRuleContext<CParser::SpecifierQualifierListContext>(0);
}

CParser::AbstractDeclaratorContext* CParser::TypeNameContext::abstractDeclarator() {
  return getRuleContext<CParser::AbstractDeclaratorContext>(0);
}


size_t CParser::TypeNameContext::getRuleIndex() const {
  return CParser::RuleTypeName;
}

void CParser::TypeNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeName(this);
}

void CParser::TypeNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeName(this);
}


antlrcpp::Any CParser::TypeNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitTypeName(this);
  else
    return visitor->visitChildren(this);
}

CParser::TypeNameContext* CParser::typeName() {
  TypeNameContext *_localctx = _tracker.createInstance<TypeNameContext>(_ctx, getState());
  enterRule(_localctx, 120, CParser::RuleTypeName);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(941);
    specifierQualifierList();
    setState(943);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 63) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 63)) & ((1ULL << (CParser::LeftParen - 63))
      | (1ULL << (CParser::LeftBracket - 63))
      | (1ULL << (CParser::Star - 63))
      | (1ULL << (CParser::Caret - 63)))) != 0)) {
      setState(942);
      abstractDeclarator();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AbstractDeclaratorContext ------------------------------------------------------------------

CParser::AbstractDeclaratorContext::AbstractDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::PointerContext* CParser::AbstractDeclaratorContext::pointer() {
  return getRuleContext<CParser::PointerContext>(0);
}

CParser::DirectAbstractDeclaratorContext* CParser::AbstractDeclaratorContext::directAbstractDeclarator() {
  return getRuleContext<CParser::DirectAbstractDeclaratorContext>(0);
}

std::vector<CParser::GccDeclaratorExtensionContext *> CParser::AbstractDeclaratorContext::gccDeclaratorExtension() {
  return getRuleContexts<CParser::GccDeclaratorExtensionContext>();
}

CParser::GccDeclaratorExtensionContext* CParser::AbstractDeclaratorContext::gccDeclaratorExtension(size_t i) {
  return getRuleContext<CParser::GccDeclaratorExtensionContext>(i);
}


size_t CParser::AbstractDeclaratorContext::getRuleIndex() const {
  return CParser::RuleAbstractDeclarator;
}

void CParser::AbstractDeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAbstractDeclarator(this);
}

void CParser::AbstractDeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAbstractDeclarator(this);
}


antlrcpp::Any CParser::AbstractDeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitAbstractDeclarator(this);
  else
    return visitor->visitChildren(this);
}

CParser::AbstractDeclaratorContext* CParser::abstractDeclarator() {
  AbstractDeclaratorContext *_localctx = _tracker.createInstance<AbstractDeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 122, CParser::RuleAbstractDeclarator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(956);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 93, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(945);
      pointer();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(947);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::Star

      || _la == CParser::Caret) {
        setState(946);
        pointer();
      }
      setState(949);
      directAbstractDeclarator(0);
      setState(953);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 92, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(950);
          gccDeclaratorExtension(); 
        }
        setState(955);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 92, _ctx);
      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DirectAbstractDeclaratorContext ------------------------------------------------------------------

CParser::DirectAbstractDeclaratorContext::DirectAbstractDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::DirectAbstractDeclaratorContext::LeftParen() {
  return getToken(CParser::LeftParen, 0);
}

CParser::AbstractDeclaratorContext* CParser::DirectAbstractDeclaratorContext::abstractDeclarator() {
  return getRuleContext<CParser::AbstractDeclaratorContext>(0);
}

tree::TerminalNode* CParser::DirectAbstractDeclaratorContext::RightParen() {
  return getToken(CParser::RightParen, 0);
}

std::vector<CParser::GccDeclaratorExtensionContext *> CParser::DirectAbstractDeclaratorContext::gccDeclaratorExtension() {
  return getRuleContexts<CParser::GccDeclaratorExtensionContext>();
}

CParser::GccDeclaratorExtensionContext* CParser::DirectAbstractDeclaratorContext::gccDeclaratorExtension(size_t i) {
  return getRuleContext<CParser::GccDeclaratorExtensionContext>(i);
}

tree::TerminalNode* CParser::DirectAbstractDeclaratorContext::LeftBracket() {
  return getToken(CParser::LeftBracket, 0);
}

tree::TerminalNode* CParser::DirectAbstractDeclaratorContext::RightBracket() {
  return getToken(CParser::RightBracket, 0);
}

CParser::TypeQualifierListContext* CParser::DirectAbstractDeclaratorContext::typeQualifierList() {
  return getRuleContext<CParser::TypeQualifierListContext>(0);
}

CParser::AssignmentExpressionContext* CParser::DirectAbstractDeclaratorContext::assignmentExpression() {
  return getRuleContext<CParser::AssignmentExpressionContext>(0);
}

tree::TerminalNode* CParser::DirectAbstractDeclaratorContext::Static() {
  return getToken(CParser::Static, 0);
}

tree::TerminalNode* CParser::DirectAbstractDeclaratorContext::Star() {
  return getToken(CParser::Star, 0);
}

CParser::ParameterTypeListContext* CParser::DirectAbstractDeclaratorContext::parameterTypeList() {
  return getRuleContext<CParser::ParameterTypeListContext>(0);
}

CParser::DirectAbstractDeclaratorContext* CParser::DirectAbstractDeclaratorContext::directAbstractDeclarator() {
  return getRuleContext<CParser::DirectAbstractDeclaratorContext>(0);
}


size_t CParser::DirectAbstractDeclaratorContext::getRuleIndex() const {
  return CParser::RuleDirectAbstractDeclarator;
}

void CParser::DirectAbstractDeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDirectAbstractDeclarator(this);
}

void CParser::DirectAbstractDeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDirectAbstractDeclarator(this);
}


antlrcpp::Any CParser::DirectAbstractDeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDirectAbstractDeclarator(this);
  else
    return visitor->visitChildren(this);
}


CParser::DirectAbstractDeclaratorContext* CParser::directAbstractDeclarator() {
   return directAbstractDeclarator(0);
}

CParser::DirectAbstractDeclaratorContext* CParser::directAbstractDeclarator(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::DirectAbstractDeclaratorContext *_localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(_ctx, parentState);
  CParser::DirectAbstractDeclaratorContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 124;
  enterRecursionRule(_localctx, 124, CParser::RuleDirectAbstractDeclarator, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1004);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 100, _ctx)) {
    case 1: {
      setState(959);
      match(CParser::LeftParen);
      setState(960);
      abstractDeclarator();
      setState(961);
      match(CParser::RightParen);
      setState(965);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 94, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(962);
          gccDeclaratorExtension(); 
        }
        setState(967);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 94, _ctx);
      }
      break;
    }

    case 2: {
      setState(968);
      match(CParser::LeftBracket);
      setState(970);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__8)
        | (1ULL << CParser::T__9)
        | (1ULL << CParser::Const)
        | (1ULL << CParser::Restrict)
        | (1ULL << CParser::Volatile)
        | (1ULL << CParser::Atomic))) != 0)) {
        setState(969);
        typeQualifierList(0);
      }
      setState(973);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__0)
        | (1ULL << CParser::T__1)
        | (1ULL << CParser::T__2)
        | (1ULL << CParser::T__3)
        | (1ULL << CParser::Sizeof)
        | (1ULL << CParser::Alignof)
        | (1ULL << CParser::Generic)
        | (1ULL << CParser::LeftParen))) != 0) || ((((_la - 75) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 75)) & ((1ULL << (CParser::Plus - 75))
        | (1ULL << (CParser::PlusPlus - 75))
        | (1ULL << (CParser::Minus - 75))
        | (1ULL << (CParser::MinusMinus - 75))
        | (1ULL << (CParser::Star - 75))
        | (1ULL << (CParser::And - 75))
        | (1ULL << (CParser::AndAnd - 75))
        | (1ULL << (CParser::Not - 75))
        | (1ULL << (CParser::Tilde - 75))
        | (1ULL << (CParser::Identifier - 75))
        | (1ULL << (CParser::Constant - 75))
        | (1ULL << (CParser::DigitSequence - 75))
        | (1ULL << (CParser::StringLiteral - 75)))) != 0)) {
        setState(972);
        assignmentExpression();
      }
      setState(975);
      match(CParser::RightBracket);
      break;
    }

    case 3: {
      setState(976);
      match(CParser::LeftBracket);
      setState(977);
      match(CParser::Static);
      setState(979);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__8)
        | (1ULL << CParser::T__9)
        | (1ULL << CParser::Const)
        | (1ULL << CParser::Restrict)
        | (1ULL << CParser::Volatile)
        | (1ULL << CParser::Atomic))) != 0)) {
        setState(978);
        typeQualifierList(0);
      }
      setState(981);
      assignmentExpression();
      setState(982);
      match(CParser::RightBracket);
      break;
    }

    case 4: {
      setState(984);
      match(CParser::LeftBracket);
      setState(985);
      typeQualifierList(0);
      setState(986);
      match(CParser::Static);
      setState(987);
      assignmentExpression();
      setState(988);
      match(CParser::RightBracket);
      break;
    }

    case 5: {
      setState(990);
      match(CParser::LeftBracket);
      setState(991);
      match(CParser::Star);
      setState(992);
      match(CParser::RightBracket);
      break;
    }

    case 6: {
      setState(993);
      match(CParser::LeftParen);
      setState(995);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__0)
        | (1ULL << CParser::T__4)
        | (1ULL << CParser::T__5)
        | (1ULL << CParser::T__6)
        | (1ULL << CParser::T__7)
        | (1ULL << CParser::T__8)
        | (1ULL << CParser::T__9)
        | (1ULL << CParser::T__10)
        | (1ULL << CParser::T__11)
        | (1ULL << CParser::T__12)
        | (1ULL << CParser::T__15)
        | (1ULL << CParser::Auto)
        | (1ULL << CParser::Char)
        | (1ULL << CParser::Const)
        | (1ULL << CParser::Double)
        | (1ULL << CParser::Enum)
        | (1ULL << CParser::Extern)
        | (1ULL << CParser::Float)
        | (1ULL << CParser::Inline)
        | (1ULL << CParser::Int)
        | (1ULL << CParser::Long)
        | (1ULL << CParser::Register)
        | (1ULL << CParser::Restrict)
        | (1ULL << CParser::Short)
        | (1ULL << CParser::Signed)
        | (1ULL << CParser::Static)
        | (1ULL << CParser::Struct)
        | (1ULL << CParser::Typedef)
        | (1ULL << CParser::Typeof)
        | (1ULL << CParser::Union)
        | (1ULL << CParser::Unsigned)
        | (1ULL << CParser::Void)
        | (1ULL << CParser::Volatile)
        | (1ULL << CParser::Alignas)
        | (1ULL << CParser::Atomic)
        | (1ULL << CParser::Bool)
        | (1ULL << CParser::Complex)
        | (1ULL << CParser::Noreturn)
        | (1ULL << CParser::ThreadLocal))) != 0) || _la == CParser::Identifier) {
        setState(994);
        parameterTypeList();
      }
      setState(997);
      match(CParser::RightParen);
      setState(1001);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 99, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(998);
          gccDeclaratorExtension(); 
        }
        setState(1003);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 99, _ctx);
      }
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(1049);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 107, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(1047);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 106, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(1006);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(1007);
          match(CParser::LeftBracket);
          setState(1009);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CParser::T__8)
            | (1ULL << CParser::T__9)
            | (1ULL << CParser::Const)
            | (1ULL << CParser::Restrict)
            | (1ULL << CParser::Volatile)
            | (1ULL << CParser::Atomic))) != 0)) {
            setState(1008);
            typeQualifierList(0);
          }
          setState(1012);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CParser::T__0)
            | (1ULL << CParser::T__1)
            | (1ULL << CParser::T__2)
            | (1ULL << CParser::T__3)
            | (1ULL << CParser::Sizeof)
            | (1ULL << CParser::Alignof)
            | (1ULL << CParser::Generic)
            | (1ULL << CParser::LeftParen))) != 0) || ((((_la - 75) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 75)) & ((1ULL << (CParser::Plus - 75))
            | (1ULL << (CParser::PlusPlus - 75))
            | (1ULL << (CParser::Minus - 75))
            | (1ULL << (CParser::MinusMinus - 75))
            | (1ULL << (CParser::Star - 75))
            | (1ULL << (CParser::And - 75))
            | (1ULL << (CParser::AndAnd - 75))
            | (1ULL << (CParser::Not - 75))
            | (1ULL << (CParser::Tilde - 75))
            | (1ULL << (CParser::Identifier - 75))
            | (1ULL << (CParser::Constant - 75))
            | (1ULL << (CParser::DigitSequence - 75))
            | (1ULL << (CParser::StringLiteral - 75)))) != 0)) {
            setState(1011);
            assignmentExpression();
          }
          setState(1014);
          match(CParser::RightBracket);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(1015);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(1016);
          match(CParser::LeftBracket);
          setState(1017);
          match(CParser::Static);
          setState(1019);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CParser::T__8)
            | (1ULL << CParser::T__9)
            | (1ULL << CParser::Const)
            | (1ULL << CParser::Restrict)
            | (1ULL << CParser::Volatile)
            | (1ULL << CParser::Atomic))) != 0)) {
            setState(1018);
            typeQualifierList(0);
          }
          setState(1021);
          assignmentExpression();
          setState(1022);
          match(CParser::RightBracket);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(1024);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(1025);
          match(CParser::LeftBracket);
          setState(1026);
          typeQualifierList(0);
          setState(1027);
          match(CParser::Static);
          setState(1028);
          assignmentExpression();
          setState(1029);
          match(CParser::RightBracket);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(1031);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(1032);
          match(CParser::LeftBracket);
          setState(1033);
          match(CParser::Star);
          setState(1034);
          match(CParser::RightBracket);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(1035);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(1036);
          match(CParser::LeftParen);
          setState(1038);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CParser::T__0)
            | (1ULL << CParser::T__4)
            | (1ULL << CParser::T__5)
            | (1ULL << CParser::T__6)
            | (1ULL << CParser::T__7)
            | (1ULL << CParser::T__8)
            | (1ULL << CParser::T__9)
            | (1ULL << CParser::T__10)
            | (1ULL << CParser::T__11)
            | (1ULL << CParser::T__12)
            | (1ULL << CParser::T__15)
            | (1ULL << CParser::Auto)
            | (1ULL << CParser::Char)
            | (1ULL << CParser::Const)
            | (1ULL << CParser::Double)
            | (1ULL << CParser::Enum)
            | (1ULL << CParser::Extern)
            | (1ULL << CParser::Float)
            | (1ULL << CParser::Inline)
            | (1ULL << CParser::Int)
            | (1ULL << CParser::Long)
            | (1ULL << CParser::Register)
            | (1ULL << CParser::Restrict)
            | (1ULL << CParser::Short)
            | (1ULL << CParser::Signed)
            | (1ULL << CParser::Static)
            | (1ULL << CParser::Struct)
            | (1ULL << CParser::Typedef)
            | (1ULL << CParser::Typeof)
            | (1ULL << CParser::Union)
            | (1ULL << CParser::Unsigned)
            | (1ULL << CParser::Void)
            | (1ULL << CParser::Volatile)
            | (1ULL << CParser::Alignas)
            | (1ULL << CParser::Atomic)
            | (1ULL << CParser::Bool)
            | (1ULL << CParser::Complex)
            | (1ULL << CParser::Noreturn)
            | (1ULL << CParser::ThreadLocal))) != 0) || _la == CParser::Identifier) {
            setState(1037);
            parameterTypeList();
          }
          setState(1040);
          match(CParser::RightParen);
          setState(1044);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 105, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(1041);
              gccDeclaratorExtension(); 
            }
            setState(1046);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 105, _ctx);
          }
          break;
        }

        } 
      }
      setState(1051);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 107, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TypedefNameContext ------------------------------------------------------------------

CParser::TypedefNameContext::TypedefNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::TypedefNameContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}


size_t CParser::TypedefNameContext::getRuleIndex() const {
  return CParser::RuleTypedefName;
}

void CParser::TypedefNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypedefName(this);
}

void CParser::TypedefNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypedefName(this);
}


antlrcpp::Any CParser::TypedefNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitTypedefName(this);
  else
    return visitor->visitChildren(this);
}

CParser::TypedefNameContext* CParser::typedefName() {
  TypedefNameContext *_localctx = _tracker.createInstance<TypedefNameContext>(_ctx, getState());
  enterRule(_localctx, 126, CParser::RuleTypedefName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1052);
    match(CParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitializerContext ------------------------------------------------------------------

CParser::InitializerContext::InitializerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::AssignmentExpressionContext* CParser::InitializerContext::assignmentExpression() {
  return getRuleContext<CParser::AssignmentExpressionContext>(0);
}

tree::TerminalNode* CParser::InitializerContext::LeftBrace() {
  return getToken(CParser::LeftBrace, 0);
}

CParser::InitializerListContext* CParser::InitializerContext::initializerList() {
  return getRuleContext<CParser::InitializerListContext>(0);
}

tree::TerminalNode* CParser::InitializerContext::RightBrace() {
  return getToken(CParser::RightBrace, 0);
}

tree::TerminalNode* CParser::InitializerContext::Comma() {
  return getToken(CParser::Comma, 0);
}


size_t CParser::InitializerContext::getRuleIndex() const {
  return CParser::RuleInitializer;
}

void CParser::InitializerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitializer(this);
}

void CParser::InitializerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitializer(this);
}


antlrcpp::Any CParser::InitializerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitInitializer(this);
  else
    return visitor->visitChildren(this);
}

CParser::InitializerContext* CParser::initializer() {
  InitializerContext *_localctx = _tracker.createInstance<InitializerContext>(_ctx, getState());
  enterRule(_localctx, 128, CParser::RuleInitializer);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1064);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 108, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1054);
      assignmentExpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1055);
      match(CParser::LeftBrace);
      setState(1056);
      initializerList(0);
      setState(1057);
      match(CParser::RightBrace);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1059);
      match(CParser::LeftBrace);
      setState(1060);
      initializerList(0);
      setState(1061);
      match(CParser::Comma);
      setState(1062);
      match(CParser::RightBrace);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitializerListContext ------------------------------------------------------------------

CParser::InitializerListContext::InitializerListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::InitializerContext* CParser::InitializerListContext::initializer() {
  return getRuleContext<CParser::InitializerContext>(0);
}

CParser::DesignationContext* CParser::InitializerListContext::designation() {
  return getRuleContext<CParser::DesignationContext>(0);
}

CParser::InitializerListContext* CParser::InitializerListContext::initializerList() {
  return getRuleContext<CParser::InitializerListContext>(0);
}

tree::TerminalNode* CParser::InitializerListContext::Comma() {
  return getToken(CParser::Comma, 0);
}


size_t CParser::InitializerListContext::getRuleIndex() const {
  return CParser::RuleInitializerList;
}

void CParser::InitializerListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitializerList(this);
}

void CParser::InitializerListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitializerList(this);
}


antlrcpp::Any CParser::InitializerListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitInitializerList(this);
  else
    return visitor->visitChildren(this);
}


CParser::InitializerListContext* CParser::initializerList() {
   return initializerList(0);
}

CParser::InitializerListContext* CParser::initializerList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::InitializerListContext *_localctx = _tracker.createInstance<InitializerListContext>(_ctx, parentState);
  CParser::InitializerListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 130;
  enterRecursionRule(_localctx, 130, CParser::RuleInitializerList, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1068);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::LeftBracket

    || _la == CParser::Dot) {
      setState(1067);
      designation();
    }
    setState(1070);
    initializer();
    _ctx->stop = _input->LT(-1);
    setState(1080);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 111, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<InitializerListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleInitializerList);
        setState(1072);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1073);
        match(CParser::Comma);
        setState(1075);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CParser::LeftBracket

        || _la == CParser::Dot) {
          setState(1074);
          designation();
        }
        setState(1077);
        initializer(); 
      }
      setState(1082);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 111, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- DesignationContext ------------------------------------------------------------------

CParser::DesignationContext::DesignationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DesignatorListContext* CParser::DesignationContext::designatorList() {
  return getRuleContext<CParser::DesignatorListContext>(0);
}

tree::TerminalNode* CParser::DesignationContext::Assign() {
  return getToken(CParser::Assign, 0);
}


size_t CParser::DesignationContext::getRuleIndex() const {
  return CParser::RuleDesignation;
}

void CParser::DesignationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDesignation(this);
}

void CParser::DesignationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDesignation(this);
}


antlrcpp::Any CParser::DesignationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDesignation(this);
  else
    return visitor->visitChildren(this);
}

CParser::DesignationContext* CParser::designation() {
  DesignationContext *_localctx = _tracker.createInstance<DesignationContext>(_ctx, getState());
  enterRule(_localctx, 132, CParser::RuleDesignation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1083);
    designatorList(0);
    setState(1084);
    match(CParser::Assign);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DesignatorListContext ------------------------------------------------------------------

CParser::DesignatorListContext::DesignatorListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DesignatorContext* CParser::DesignatorListContext::designator() {
  return getRuleContext<CParser::DesignatorContext>(0);
}

CParser::DesignatorListContext* CParser::DesignatorListContext::designatorList() {
  return getRuleContext<CParser::DesignatorListContext>(0);
}


size_t CParser::DesignatorListContext::getRuleIndex() const {
  return CParser::RuleDesignatorList;
}

void CParser::DesignatorListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDesignatorList(this);
}

void CParser::DesignatorListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDesignatorList(this);
}


antlrcpp::Any CParser::DesignatorListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDesignatorList(this);
  else
    return visitor->visitChildren(this);
}


CParser::DesignatorListContext* CParser::designatorList() {
   return designatorList(0);
}

CParser::DesignatorListContext* CParser::designatorList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::DesignatorListContext *_localctx = _tracker.createInstance<DesignatorListContext>(_ctx, parentState);
  CParser::DesignatorListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 134;
  enterRecursionRule(_localctx, 134, CParser::RuleDesignatorList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1087);
    designator();
    _ctx->stop = _input->LT(-1);
    setState(1093);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 112, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<DesignatorListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleDesignatorList);
        setState(1089);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1090);
        designator(); 
      }
      setState(1095);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 112, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- DesignatorContext ------------------------------------------------------------------

CParser::DesignatorContext::DesignatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::DesignatorContext::LeftBracket() {
  return getToken(CParser::LeftBracket, 0);
}

CParser::ConstantExpressionContext* CParser::DesignatorContext::constantExpression() {
  return getRuleContext<CParser::ConstantExpressionContext>(0);
}

tree::TerminalNode* CParser::DesignatorContext::RightBracket() {
  return getToken(CParser::RightBracket, 0);
}

tree::TerminalNode* CParser::DesignatorContext::Dot() {
  return getToken(CParser::Dot, 0);
}

tree::TerminalNode* CParser::DesignatorContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}


size_t CParser::DesignatorContext::getRuleIndex() const {
  return CParser::RuleDesignator;
}

void CParser::DesignatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDesignator(this);
}

void CParser::DesignatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDesignator(this);
}


antlrcpp::Any CParser::DesignatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDesignator(this);
  else
    return visitor->visitChildren(this);
}

CParser::DesignatorContext* CParser::designator() {
  DesignatorContext *_localctx = _tracker.createInstance<DesignatorContext>(_ctx, getState());
  enterRule(_localctx, 136, CParser::RuleDesignator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1102);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::LeftBracket: {
        enterOuterAlt(_localctx, 1);
        setState(1096);
        match(CParser::LeftBracket);
        setState(1097);
        constantExpression();
        setState(1098);
        match(CParser::RightBracket);
        break;
      }

      case CParser::Dot: {
        enterOuterAlt(_localctx, 2);
        setState(1100);
        match(CParser::Dot);
        setState(1101);
        match(CParser::Identifier);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StaticAssertDeclarationContext ------------------------------------------------------------------

CParser::StaticAssertDeclarationContext::StaticAssertDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::StaticAssertDeclarationContext::StaticAssert() {
  return getToken(CParser::StaticAssert, 0);
}

tree::TerminalNode* CParser::StaticAssertDeclarationContext::LeftParen() {
  return getToken(CParser::LeftParen, 0);
}

CParser::ConstantExpressionContext* CParser::StaticAssertDeclarationContext::constantExpression() {
  return getRuleContext<CParser::ConstantExpressionContext>(0);
}

tree::TerminalNode* CParser::StaticAssertDeclarationContext::Comma() {
  return getToken(CParser::Comma, 0);
}

tree::TerminalNode* CParser::StaticAssertDeclarationContext::RightParen() {
  return getToken(CParser::RightParen, 0);
}

tree::TerminalNode* CParser::StaticAssertDeclarationContext::Semi() {
  return getToken(CParser::Semi, 0);
}

std::vector<tree::TerminalNode *> CParser::StaticAssertDeclarationContext::StringLiteral() {
  return getTokens(CParser::StringLiteral);
}

tree::TerminalNode* CParser::StaticAssertDeclarationContext::StringLiteral(size_t i) {
  return getToken(CParser::StringLiteral, i);
}


size_t CParser::StaticAssertDeclarationContext::getRuleIndex() const {
  return CParser::RuleStaticAssertDeclaration;
}

void CParser::StaticAssertDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStaticAssertDeclaration(this);
}

void CParser::StaticAssertDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStaticAssertDeclaration(this);
}


antlrcpp::Any CParser::StaticAssertDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitStaticAssertDeclaration(this);
  else
    return visitor->visitChildren(this);
}

CParser::StaticAssertDeclarationContext* CParser::staticAssertDeclaration() {
  StaticAssertDeclarationContext *_localctx = _tracker.createInstance<StaticAssertDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 138, CParser::RuleStaticAssertDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1104);
    match(CParser::StaticAssert);
    setState(1105);
    match(CParser::LeftParen);
    setState(1106);
    constantExpression();
    setState(1107);
    match(CParser::Comma);
    setState(1109); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1108);
      match(CParser::StringLiteral);
      setState(1111); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == CParser::StringLiteral);
    setState(1113);
    match(CParser::RightParen);
    setState(1114);
    match(CParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

CParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::LabeledStatementContext* CParser::StatementContext::labeledStatement() {
  return getRuleContext<CParser::LabeledStatementContext>(0);
}

CParser::CompoundStatementContext* CParser::StatementContext::compoundStatement() {
  return getRuleContext<CParser::CompoundStatementContext>(0);
}

CParser::ExpressionStatementContext* CParser::StatementContext::expressionStatement() {
  return getRuleContext<CParser::ExpressionStatementContext>(0);
}

CParser::SelectionStatementContext* CParser::StatementContext::selectionStatement() {
  return getRuleContext<CParser::SelectionStatementContext>(0);
}

CParser::IterationStatementContext* CParser::StatementContext::iterationStatement() {
  return getRuleContext<CParser::IterationStatementContext>(0);
}

CParser::JumpStatementContext* CParser::StatementContext::jumpStatement() {
  return getRuleContext<CParser::JumpStatementContext>(0);
}

CParser::AsmStatementContext* CParser::StatementContext::asmStatement() {
  return getRuleContext<CParser::AsmStatementContext>(0);
}


size_t CParser::StatementContext::getRuleIndex() const {
  return CParser::RuleStatement;
}

void CParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void CParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


antlrcpp::Any CParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

CParser::StatementContext* CParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 140, CParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1123);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 115, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1116);
      labeledStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1117);
      compoundStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1118);
      expressionStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1119);
      selectionStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(1120);
      iterationStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(1121);
      jumpStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(1122);
      asmStatement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LabeledStatementContext ------------------------------------------------------------------

CParser::LabeledStatementContext::LabeledStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::LabeledStatementContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}

tree::TerminalNode* CParser::LabeledStatementContext::Colon() {
  return getToken(CParser::Colon, 0);
}

CParser::StatementContext* CParser::LabeledStatementContext::statement() {
  return getRuleContext<CParser::StatementContext>(0);
}

tree::TerminalNode* CParser::LabeledStatementContext::Case() {
  return getToken(CParser::Case, 0);
}

std::vector<CParser::ConstantExpressionContext *> CParser::LabeledStatementContext::constantExpression() {
  return getRuleContexts<CParser::ConstantExpressionContext>();
}

CParser::ConstantExpressionContext* CParser::LabeledStatementContext::constantExpression(size_t i) {
  return getRuleContext<CParser::ConstantExpressionContext>(i);
}

tree::TerminalNode* CParser::LabeledStatementContext::Ellipsis() {
  return getToken(CParser::Ellipsis, 0);
}

tree::TerminalNode* CParser::LabeledStatementContext::Default() {
  return getToken(CParser::Default, 0);
}


size_t CParser::LabeledStatementContext::getRuleIndex() const {
  return CParser::RuleLabeledStatement;
}

void CParser::LabeledStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLabeledStatement(this);
}

void CParser::LabeledStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLabeledStatement(this);
}


antlrcpp::Any CParser::LabeledStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitLabeledStatement(this);
  else
    return visitor->visitChildren(this);
}

CParser::LabeledStatementContext* CParser::labeledStatement() {
  LabeledStatementContext *_localctx = _tracker.createInstance<LabeledStatementContext>(_ctx, getState());
  enterRule(_localctx, 142, CParser::RuleLabeledStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1140);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(1125);
        match(CParser::Identifier);
        setState(1126);
        match(CParser::Colon);
        setState(1127);
        statement();
        break;
      }

      case CParser::Case: {
        enterOuterAlt(_localctx, 2);
        setState(1128);
        match(CParser::Case);
        setState(1129);
        constantExpression();
        setState(1132);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CParser::Ellipsis) {
          setState(1130);
          match(CParser::Ellipsis);
          setState(1131);
          constantExpression();
        }
        setState(1134);
        match(CParser::Colon);
        setState(1135);
        statement();
        break;
      }

      case CParser::Default: {
        enterOuterAlt(_localctx, 3);
        setState(1137);
        match(CParser::Default);
        setState(1138);
        match(CParser::Colon);
        setState(1139);
        statement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompoundStatementContext ------------------------------------------------------------------

CParser::CompoundStatementContext::CompoundStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::CompoundStatementContext::LeftBrace() {
  return getToken(CParser::LeftBrace, 0);
}

tree::TerminalNode* CParser::CompoundStatementContext::RightBrace() {
  return getToken(CParser::RightBrace, 0);
}

CParser::BlockItemListContext* CParser::CompoundStatementContext::blockItemList() {
  return getRuleContext<CParser::BlockItemListContext>(0);
}


size_t CParser::CompoundStatementContext::getRuleIndex() const {
  return CParser::RuleCompoundStatement;
}

void CParser::CompoundStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompoundStatement(this);
}

void CParser::CompoundStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompoundStatement(this);
}


antlrcpp::Any CParser::CompoundStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitCompoundStatement(this);
  else
    return visitor->visitChildren(this);
}

CParser::CompoundStatementContext* CParser::compoundStatement() {
  CompoundStatementContext *_localctx = _tracker.createInstance<CompoundStatementContext>(_ctx, getState());
  enterRule(_localctx, 144, CParser::RuleCompoundStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1142);
    match(CParser::LeftBrace);
    setState(1144);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__0)
      | (1ULL << CParser::T__1)
      | (1ULL << CParser::T__2)
      | (1ULL << CParser::T__3)
      | (1ULL << CParser::T__4)
      | (1ULL << CParser::T__5)
      | (1ULL << CParser::T__6)
      | (1ULL << CParser::T__7)
      | (1ULL << CParser::T__8)
      | (1ULL << CParser::T__9)
      | (1ULL << CParser::T__10)
      | (1ULL << CParser::T__11)
      | (1ULL << CParser::T__12)
      | (1ULL << CParser::T__13)
      | (1ULL << CParser::T__14)
      | (1ULL << CParser::T__15)
      | (1ULL << CParser::T__16)
      | (1ULL << CParser::Auto)
      | (1ULL << CParser::Break)
      | (1ULL << CParser::Case)
      | (1ULL << CParser::Char)
      | (1ULL << CParser::Const)
      | (1ULL << CParser::Continue)
      | (1ULL << CParser::Default)
      | (1ULL << CParser::Do)
      | (1ULL << CParser::Double)
      | (1ULL << CParser::Enum)
      | (1ULL << CParser::Extern)
      | (1ULL << CParser::Float)
      | (1ULL << CParser::For)
      | (1ULL << CParser::Goto)
      | (1ULL << CParser::If)
      | (1ULL << CParser::Inline)
      | (1ULL << CParser::Int)
      | (1ULL << CParser::Long)
      | (1ULL << CParser::Register)
      | (1ULL << CParser::Restrict)
      | (1ULL << CParser::Return)
      | (1ULL << CParser::Short)
      | (1ULL << CParser::Signed)
      | (1ULL << CParser::Sizeof)
      | (1ULL << CParser::Static)
      | (1ULL << CParser::Struct)
      | (1ULL << CParser::Switch)
      | (1ULL << CParser::Typedef)
      | (1ULL << CParser::Typeof)
      | (1ULL << CParser::Union)
      | (1ULL << CParser::Unsigned)
      | (1ULL << CParser::Void)
      | (1ULL << CParser::Volatile)
      | (1ULL << CParser::While)
      | (1ULL << CParser::Alignas)
      | (1ULL << CParser::Alignof)
      | (1ULL << CParser::Atomic)
      | (1ULL << CParser::Bool)
      | (1ULL << CParser::Complex)
      | (1ULL << CParser::Generic)
      | (1ULL << CParser::Noreturn)
      | (1ULL << CParser::StaticAssert)
      | (1ULL << CParser::ThreadLocal)
      | (1ULL << CParser::LeftParen))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (CParser::LeftBrace - 67))
      | (1ULL << (CParser::Plus - 67))
      | (1ULL << (CParser::PlusPlus - 67))
      | (1ULL << (CParser::Minus - 67))
      | (1ULL << (CParser::MinusMinus - 67))
      | (1ULL << (CParser::Star - 67))
      | (1ULL << (CParser::And - 67))
      | (1ULL << (CParser::AndAnd - 67))
      | (1ULL << (CParser::Not - 67))
      | (1ULL << (CParser::Tilde - 67))
      | (1ULL << (CParser::Semi - 67))
      | (1ULL << (CParser::Identifier - 67))
      | (1ULL << (CParser::Constant - 67))
      | (1ULL << (CParser::DigitSequence - 67))
      | (1ULL << (CParser::StringLiteral - 67)))) != 0)) {
      setState(1143);
      blockItemList(0);
    }
    setState(1146);
    match(CParser::RightBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockItemListContext ------------------------------------------------------------------

CParser::BlockItemListContext::BlockItemListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::BlockItemContext* CParser::BlockItemListContext::blockItem() {
  return getRuleContext<CParser::BlockItemContext>(0);
}

CParser::BlockItemListContext* CParser::BlockItemListContext::blockItemList() {
  return getRuleContext<CParser::BlockItemListContext>(0);
}


size_t CParser::BlockItemListContext::getRuleIndex() const {
  return CParser::RuleBlockItemList;
}

void CParser::BlockItemListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockItemList(this);
}

void CParser::BlockItemListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockItemList(this);
}


antlrcpp::Any CParser::BlockItemListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitBlockItemList(this);
  else
    return visitor->visitChildren(this);
}


CParser::BlockItemListContext* CParser::blockItemList() {
   return blockItemList(0);
}

CParser::BlockItemListContext* CParser::blockItemList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::BlockItemListContext *_localctx = _tracker.createInstance<BlockItemListContext>(_ctx, parentState);
  CParser::BlockItemListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 146;
  enterRecursionRule(_localctx, 146, CParser::RuleBlockItemList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1149);
    blockItem();
    _ctx->stop = _input->LT(-1);
    setState(1155);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 119, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<BlockItemListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleBlockItemList);
        setState(1151);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1152);
        blockItem(); 
      }
      setState(1157);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 119, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- BlockItemContext ------------------------------------------------------------------

CParser::BlockItemContext::BlockItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::StatementContext* CParser::BlockItemContext::statement() {
  return getRuleContext<CParser::StatementContext>(0);
}

CParser::DeclarationContext* CParser::BlockItemContext::declaration() {
  return getRuleContext<CParser::DeclarationContext>(0);
}


size_t CParser::BlockItemContext::getRuleIndex() const {
  return CParser::RuleBlockItem;
}

void CParser::BlockItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockItem(this);
}

void CParser::BlockItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockItem(this);
}


antlrcpp::Any CParser::BlockItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitBlockItem(this);
  else
    return visitor->visitChildren(this);
}

CParser::BlockItemContext* CParser::blockItem() {
  BlockItemContext *_localctx = _tracker.createInstance<BlockItemContext>(_ctx, getState());
  enterRule(_localctx, 148, CParser::RuleBlockItem);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1160);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 120, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1158);
      statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1159);
      declaration();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionStatementContext ------------------------------------------------------------------

CParser::ExpressionStatementContext::ExpressionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::ExpressionStatementContext::Semi() {
  return getToken(CParser::Semi, 0);
}

CParser::ExpressionContext* CParser::ExpressionStatementContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}


size_t CParser::ExpressionStatementContext::getRuleIndex() const {
  return CParser::RuleExpressionStatement;
}

void CParser::ExpressionStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionStatement(this);
}

void CParser::ExpressionStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionStatement(this);
}


antlrcpp::Any CParser::ExpressionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitExpressionStatement(this);
  else
    return visitor->visitChildren(this);
}

CParser::ExpressionStatementContext* CParser::expressionStatement() {
  ExpressionStatementContext *_localctx = _tracker.createInstance<ExpressionStatementContext>(_ctx, getState());
  enterRule(_localctx, 150, CParser::RuleExpressionStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1163);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__0)
      | (1ULL << CParser::T__1)
      | (1ULL << CParser::T__2)
      | (1ULL << CParser::T__3)
      | (1ULL << CParser::Sizeof)
      | (1ULL << CParser::Alignof)
      | (1ULL << CParser::Generic)
      | (1ULL << CParser::LeftParen))) != 0) || ((((_la - 75) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 75)) & ((1ULL << (CParser::Plus - 75))
      | (1ULL << (CParser::PlusPlus - 75))
      | (1ULL << (CParser::Minus - 75))
      | (1ULL << (CParser::MinusMinus - 75))
      | (1ULL << (CParser::Star - 75))
      | (1ULL << (CParser::And - 75))
      | (1ULL << (CParser::AndAnd - 75))
      | (1ULL << (CParser::Not - 75))
      | (1ULL << (CParser::Tilde - 75))
      | (1ULL << (CParser::Identifier - 75))
      | (1ULL << (CParser::Constant - 75))
      | (1ULL << (CParser::DigitSequence - 75))
      | (1ULL << (CParser::StringLiteral - 75)))) != 0)) {
      setState(1162);
      expression(0);
    }
    setState(1165);
    match(CParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SelectionStatementContext ------------------------------------------------------------------

CParser::SelectionStatementContext::SelectionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::SelectionStatementContext::If() {
  return getToken(CParser::If, 0);
}

tree::TerminalNode* CParser::SelectionStatementContext::LeftParen() {
  return getToken(CParser::LeftParen, 0);
}

CParser::ExpressionContext* CParser::SelectionStatementContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}

tree::TerminalNode* CParser::SelectionStatementContext::RightParen() {
  return getToken(CParser::RightParen, 0);
}

std::vector<CParser::StatementContext *> CParser::SelectionStatementContext::statement() {
  return getRuleContexts<CParser::StatementContext>();
}

CParser::StatementContext* CParser::SelectionStatementContext::statement(size_t i) {
  return getRuleContext<CParser::StatementContext>(i);
}

tree::TerminalNode* CParser::SelectionStatementContext::Else() {
  return getToken(CParser::Else, 0);
}

tree::TerminalNode* CParser::SelectionStatementContext::Switch() {
  return getToken(CParser::Switch, 0);
}


size_t CParser::SelectionStatementContext::getRuleIndex() const {
  return CParser::RuleSelectionStatement;
}

void CParser::SelectionStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelectionStatement(this);
}

void CParser::SelectionStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelectionStatement(this);
}


antlrcpp::Any CParser::SelectionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitSelectionStatement(this);
  else
    return visitor->visitChildren(this);
}

CParser::SelectionStatementContext* CParser::selectionStatement() {
  SelectionStatementContext *_localctx = _tracker.createInstance<SelectionStatementContext>(_ctx, getState());
  enterRule(_localctx, 152, CParser::RuleSelectionStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1182);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::If: {
        enterOuterAlt(_localctx, 1);
        setState(1167);
        match(CParser::If);
        setState(1168);
        match(CParser::LeftParen);
        setState(1169);
        expression(0);
        setState(1170);
        match(CParser::RightParen);
        setState(1171);
        statement();
        setState(1174);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 122, _ctx)) {
        case 1: {
          setState(1172);
          match(CParser::Else);
          setState(1173);
          statement();
          break;
        }

        }
        break;
      }

      case CParser::Switch: {
        enterOuterAlt(_localctx, 2);
        setState(1176);
        match(CParser::Switch);
        setState(1177);
        match(CParser::LeftParen);
        setState(1178);
        expression(0);
        setState(1179);
        match(CParser::RightParen);
        setState(1180);
        statement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IterationStatementContext ------------------------------------------------------------------

CParser::IterationStatementContext::IterationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::IterationStatementContext::While() {
  return getToken(CParser::While, 0);
}

tree::TerminalNode* CParser::IterationStatementContext::LeftParen() {
  return getToken(CParser::LeftParen, 0);
}

CParser::ExpressionContext* CParser::IterationStatementContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}

tree::TerminalNode* CParser::IterationStatementContext::RightParen() {
  return getToken(CParser::RightParen, 0);
}

CParser::StatementContext* CParser::IterationStatementContext::statement() {
  return getRuleContext<CParser::StatementContext>(0);
}

tree::TerminalNode* CParser::IterationStatementContext::Do() {
  return getToken(CParser::Do, 0);
}

tree::TerminalNode* CParser::IterationStatementContext::Semi() {
  return getToken(CParser::Semi, 0);
}

tree::TerminalNode* CParser::IterationStatementContext::For() {
  return getToken(CParser::For, 0);
}

CParser::ForConditionContext* CParser::IterationStatementContext::forCondition() {
  return getRuleContext<CParser::ForConditionContext>(0);
}


size_t CParser::IterationStatementContext::getRuleIndex() const {
  return CParser::RuleIterationStatement;
}

void CParser::IterationStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIterationStatement(this);
}

void CParser::IterationStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIterationStatement(this);
}


antlrcpp::Any CParser::IterationStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitIterationStatement(this);
  else
    return visitor->visitChildren(this);
}

CParser::IterationStatementContext* CParser::iterationStatement() {
  IterationStatementContext *_localctx = _tracker.createInstance<IterationStatementContext>(_ctx, getState());
  enterRule(_localctx, 154, CParser::RuleIterationStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1204);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::While: {
        enterOuterAlt(_localctx, 1);
        setState(1184);
        match(CParser::While);
        setState(1185);
        match(CParser::LeftParen);
        setState(1186);
        expression(0);
        setState(1187);
        match(CParser::RightParen);
        setState(1188);
        statement();
        break;
      }

      case CParser::Do: {
        enterOuterAlt(_localctx, 2);
        setState(1190);
        match(CParser::Do);
        setState(1191);
        statement();
        setState(1192);
        match(CParser::While);
        setState(1193);
        match(CParser::LeftParen);
        setState(1194);
        expression(0);
        setState(1195);
        match(CParser::RightParen);
        setState(1196);
        match(CParser::Semi);
        break;
      }

      case CParser::For: {
        enterOuterAlt(_localctx, 3);
        setState(1198);
        match(CParser::For);
        setState(1199);
        match(CParser::LeftParen);
        setState(1200);
        forCondition();
        setState(1201);
        match(CParser::RightParen);
        setState(1202);
        statement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForConditionContext ------------------------------------------------------------------

CParser::ForConditionContext::ForConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ForDeclarationContext* CParser::ForConditionContext::forDeclaration() {
  return getRuleContext<CParser::ForDeclarationContext>(0);
}

std::vector<tree::TerminalNode *> CParser::ForConditionContext::Semi() {
  return getTokens(CParser::Semi);
}

tree::TerminalNode* CParser::ForConditionContext::Semi(size_t i) {
  return getToken(CParser::Semi, i);
}

std::vector<CParser::ForExpressionContext *> CParser::ForConditionContext::forExpression() {
  return getRuleContexts<CParser::ForExpressionContext>();
}

CParser::ForExpressionContext* CParser::ForConditionContext::forExpression(size_t i) {
  return getRuleContext<CParser::ForExpressionContext>(i);
}

CParser::ExpressionContext* CParser::ForConditionContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}


size_t CParser::ForConditionContext::getRuleIndex() const {
  return CParser::RuleForCondition;
}

void CParser::ForConditionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForCondition(this);
}

void CParser::ForConditionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForCondition(this);
}


antlrcpp::Any CParser::ForConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitForCondition(this);
  else
    return visitor->visitChildren(this);
}

CParser::ForConditionContext* CParser::forCondition() {
  ForConditionContext *_localctx = _tracker.createInstance<ForConditionContext>(_ctx, getState());
  enterRule(_localctx, 156, CParser::RuleForCondition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1226);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 130, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1206);
      forDeclaration();
      setState(1207);
      match(CParser::Semi);
      setState(1209);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__0)
        | (1ULL << CParser::T__1)
        | (1ULL << CParser::T__2)
        | (1ULL << CParser::T__3)
        | (1ULL << CParser::Sizeof)
        | (1ULL << CParser::Alignof)
        | (1ULL << CParser::Generic)
        | (1ULL << CParser::LeftParen))) != 0) || ((((_la - 75) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 75)) & ((1ULL << (CParser::Plus - 75))
        | (1ULL << (CParser::PlusPlus - 75))
        | (1ULL << (CParser::Minus - 75))
        | (1ULL << (CParser::MinusMinus - 75))
        | (1ULL << (CParser::Star - 75))
        | (1ULL << (CParser::And - 75))
        | (1ULL << (CParser::AndAnd - 75))
        | (1ULL << (CParser::Not - 75))
        | (1ULL << (CParser::Tilde - 75))
        | (1ULL << (CParser::Identifier - 75))
        | (1ULL << (CParser::Constant - 75))
        | (1ULL << (CParser::DigitSequence - 75))
        | (1ULL << (CParser::StringLiteral - 75)))) != 0)) {
        setState(1208);
        forExpression(0);
      }
      setState(1211);
      match(CParser::Semi);
      setState(1213);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__0)
        | (1ULL << CParser::T__1)
        | (1ULL << CParser::T__2)
        | (1ULL << CParser::T__3)
        | (1ULL << CParser::Sizeof)
        | (1ULL << CParser::Alignof)
        | (1ULL << CParser::Generic)
        | (1ULL << CParser::LeftParen))) != 0) || ((((_la - 75) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 75)) & ((1ULL << (CParser::Plus - 75))
        | (1ULL << (CParser::PlusPlus - 75))
        | (1ULL << (CParser::Minus - 75))
        | (1ULL << (CParser::MinusMinus - 75))
        | (1ULL << (CParser::Star - 75))
        | (1ULL << (CParser::And - 75))
        | (1ULL << (CParser::AndAnd - 75))
        | (1ULL << (CParser::Not - 75))
        | (1ULL << (CParser::Tilde - 75))
        | (1ULL << (CParser::Identifier - 75))
        | (1ULL << (CParser::Constant - 75))
        | (1ULL << (CParser::DigitSequence - 75))
        | (1ULL << (CParser::StringLiteral - 75)))) != 0)) {
        setState(1212);
        forExpression(0);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1216);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__0)
        | (1ULL << CParser::T__1)
        | (1ULL << CParser::T__2)
        | (1ULL << CParser::T__3)
        | (1ULL << CParser::Sizeof)
        | (1ULL << CParser::Alignof)
        | (1ULL << CParser::Generic)
        | (1ULL << CParser::LeftParen))) != 0) || ((((_la - 75) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 75)) & ((1ULL << (CParser::Plus - 75))
        | (1ULL << (CParser::PlusPlus - 75))
        | (1ULL << (CParser::Minus - 75))
        | (1ULL << (CParser::MinusMinus - 75))
        | (1ULL << (CParser::Star - 75))
        | (1ULL << (CParser::And - 75))
        | (1ULL << (CParser::AndAnd - 75))
        | (1ULL << (CParser::Not - 75))
        | (1ULL << (CParser::Tilde - 75))
        | (1ULL << (CParser::Identifier - 75))
        | (1ULL << (CParser::Constant - 75))
        | (1ULL << (CParser::DigitSequence - 75))
        | (1ULL << (CParser::StringLiteral - 75)))) != 0)) {
        setState(1215);
        expression(0);
      }
      setState(1218);
      match(CParser::Semi);
      setState(1220);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__0)
        | (1ULL << CParser::T__1)
        | (1ULL << CParser::T__2)
        | (1ULL << CParser::T__3)
        | (1ULL << CParser::Sizeof)
        | (1ULL << CParser::Alignof)
        | (1ULL << CParser::Generic)
        | (1ULL << CParser::LeftParen))) != 0) || ((((_la - 75) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 75)) & ((1ULL << (CParser::Plus - 75))
        | (1ULL << (CParser::PlusPlus - 75))
        | (1ULL << (CParser::Minus - 75))
        | (1ULL << (CParser::MinusMinus - 75))
        | (1ULL << (CParser::Star - 75))
        | (1ULL << (CParser::And - 75))
        | (1ULL << (CParser::AndAnd - 75))
        | (1ULL << (CParser::Not - 75))
        | (1ULL << (CParser::Tilde - 75))
        | (1ULL << (CParser::Identifier - 75))
        | (1ULL << (CParser::Constant - 75))
        | (1ULL << (CParser::DigitSequence - 75))
        | (1ULL << (CParser::StringLiteral - 75)))) != 0)) {
        setState(1219);
        forExpression(0);
      }
      setState(1222);
      match(CParser::Semi);
      setState(1224);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__0)
        | (1ULL << CParser::T__1)
        | (1ULL << CParser::T__2)
        | (1ULL << CParser::T__3)
        | (1ULL << CParser::Sizeof)
        | (1ULL << CParser::Alignof)
        | (1ULL << CParser::Generic)
        | (1ULL << CParser::LeftParen))) != 0) || ((((_la - 75) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 75)) & ((1ULL << (CParser::Plus - 75))
        | (1ULL << (CParser::PlusPlus - 75))
        | (1ULL << (CParser::Minus - 75))
        | (1ULL << (CParser::MinusMinus - 75))
        | (1ULL << (CParser::Star - 75))
        | (1ULL << (CParser::And - 75))
        | (1ULL << (CParser::AndAnd - 75))
        | (1ULL << (CParser::Not - 75))
        | (1ULL << (CParser::Tilde - 75))
        | (1ULL << (CParser::Identifier - 75))
        | (1ULL << (CParser::Constant - 75))
        | (1ULL << (CParser::DigitSequence - 75))
        | (1ULL << (CParser::StringLiteral - 75)))) != 0)) {
        setState(1223);
        forExpression(0);
      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForDeclarationContext ------------------------------------------------------------------

CParser::ForDeclarationContext::ForDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DeclarationSpecifiersContext* CParser::ForDeclarationContext::declarationSpecifiers() {
  return getRuleContext<CParser::DeclarationSpecifiersContext>(0);
}

CParser::InitDeclaratorListContext* CParser::ForDeclarationContext::initDeclaratorList() {
  return getRuleContext<CParser::InitDeclaratorListContext>(0);
}


size_t CParser::ForDeclarationContext::getRuleIndex() const {
  return CParser::RuleForDeclaration;
}

void CParser::ForDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForDeclaration(this);
}

void CParser::ForDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForDeclaration(this);
}


antlrcpp::Any CParser::ForDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitForDeclaration(this);
  else
    return visitor->visitChildren(this);
}

CParser::ForDeclarationContext* CParser::forDeclaration() {
  ForDeclarationContext *_localctx = _tracker.createInstance<ForDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 158, CParser::RuleForDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1232);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 131, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1228);
      declarationSpecifiers();
      setState(1229);
      initDeclaratorList(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1231);
      declarationSpecifiers();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForExpressionContext ------------------------------------------------------------------

CParser::ForExpressionContext::ForExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::AssignmentExpressionContext* CParser::ForExpressionContext::assignmentExpression() {
  return getRuleContext<CParser::AssignmentExpressionContext>(0);
}

CParser::ForExpressionContext* CParser::ForExpressionContext::forExpression() {
  return getRuleContext<CParser::ForExpressionContext>(0);
}

tree::TerminalNode* CParser::ForExpressionContext::Comma() {
  return getToken(CParser::Comma, 0);
}


size_t CParser::ForExpressionContext::getRuleIndex() const {
  return CParser::RuleForExpression;
}

void CParser::ForExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForExpression(this);
}

void CParser::ForExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForExpression(this);
}


antlrcpp::Any CParser::ForExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitForExpression(this);
  else
    return visitor->visitChildren(this);
}


CParser::ForExpressionContext* CParser::forExpression() {
   return forExpression(0);
}

CParser::ForExpressionContext* CParser::forExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::ForExpressionContext *_localctx = _tracker.createInstance<ForExpressionContext>(_ctx, parentState);
  CParser::ForExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 160;
  enterRecursionRule(_localctx, 160, CParser::RuleForExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1235);
    assignmentExpression();
    _ctx->stop = _input->LT(-1);
    setState(1242);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 132, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ForExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleForExpression);
        setState(1237);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1238);
        match(CParser::Comma);
        setState(1239);
        assignmentExpression(); 
      }
      setState(1244);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 132, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- JumpStatementContext ------------------------------------------------------------------

CParser::JumpStatementContext::JumpStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::JumpStatementContext::Goto() {
  return getToken(CParser::Goto, 0);
}

tree::TerminalNode* CParser::JumpStatementContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}

tree::TerminalNode* CParser::JumpStatementContext::Semi() {
  return getToken(CParser::Semi, 0);
}

tree::TerminalNode* CParser::JumpStatementContext::Continue() {
  return getToken(CParser::Continue, 0);
}

tree::TerminalNode* CParser::JumpStatementContext::Break() {
  return getToken(CParser::Break, 0);
}

tree::TerminalNode* CParser::JumpStatementContext::Return() {
  return getToken(CParser::Return, 0);
}

CParser::ExpressionContext* CParser::JumpStatementContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}

CParser::UnaryExpressionContext* CParser::JumpStatementContext::unaryExpression() {
  return getRuleContext<CParser::UnaryExpressionContext>(0);
}


size_t CParser::JumpStatementContext::getRuleIndex() const {
  return CParser::RuleJumpStatement;
}

void CParser::JumpStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJumpStatement(this);
}

void CParser::JumpStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJumpStatement(this);
}


antlrcpp::Any CParser::JumpStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitJumpStatement(this);
  else
    return visitor->visitChildren(this);
}

CParser::JumpStatementContext* CParser::jumpStatement() {
  JumpStatementContext *_localctx = _tracker.createInstance<JumpStatementContext>(_ctx, getState());
  enterRule(_localctx, 162, CParser::RuleJumpStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1261);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 134, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1245);
      match(CParser::Goto);
      setState(1246);
      match(CParser::Identifier);
      setState(1247);
      match(CParser::Semi);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1248);
      match(CParser::Continue);
      setState(1249);
      match(CParser::Semi);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1250);
      match(CParser::Break);
      setState(1251);
      match(CParser::Semi);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1252);
      match(CParser::Return);
      setState(1254);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__0)
        | (1ULL << CParser::T__1)
        | (1ULL << CParser::T__2)
        | (1ULL << CParser::T__3)
        | (1ULL << CParser::Sizeof)
        | (1ULL << CParser::Alignof)
        | (1ULL << CParser::Generic)
        | (1ULL << CParser::LeftParen))) != 0) || ((((_la - 75) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 75)) & ((1ULL << (CParser::Plus - 75))
        | (1ULL << (CParser::PlusPlus - 75))
        | (1ULL << (CParser::Minus - 75))
        | (1ULL << (CParser::MinusMinus - 75))
        | (1ULL << (CParser::Star - 75))
        | (1ULL << (CParser::And - 75))
        | (1ULL << (CParser::AndAnd - 75))
        | (1ULL << (CParser::Not - 75))
        | (1ULL << (CParser::Tilde - 75))
        | (1ULL << (CParser::Identifier - 75))
        | (1ULL << (CParser::Constant - 75))
        | (1ULL << (CParser::DigitSequence - 75))
        | (1ULL << (CParser::StringLiteral - 75)))) != 0)) {
        setState(1253);
        expression(0);
      }
      setState(1256);
      match(CParser::Semi);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(1257);
      match(CParser::Goto);
      setState(1258);
      unaryExpression();
      setState(1259);
      match(CParser::Semi);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AsmStatementContext ------------------------------------------------------------------

CParser::AsmStatementContext::AsmStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::AsmStatementContext::LeftParen() {
  return getToken(CParser::LeftParen, 0);
}

CParser::AsmArgumentContext* CParser::AsmStatementContext::asmArgument() {
  return getRuleContext<CParser::AsmArgumentContext>(0);
}

tree::TerminalNode* CParser::AsmStatementContext::RightParen() {
  return getToken(CParser::RightParen, 0);
}

tree::TerminalNode* CParser::AsmStatementContext::Semi() {
  return getToken(CParser::Semi, 0);
}

CParser::TypeQualifierContext* CParser::AsmStatementContext::typeQualifier() {
  return getRuleContext<CParser::TypeQualifierContext>(0);
}

tree::TerminalNode* CParser::AsmStatementContext::Goto() {
  return getToken(CParser::Goto, 0);
}


size_t CParser::AsmStatementContext::getRuleIndex() const {
  return CParser::RuleAsmStatement;
}

void CParser::AsmStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAsmStatement(this);
}

void CParser::AsmStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAsmStatement(this);
}


antlrcpp::Any CParser::AsmStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitAsmStatement(this);
  else
    return visitor->visitChildren(this);
}

CParser::AsmStatementContext* CParser::asmStatement() {
  AsmStatementContext *_localctx = _tracker.createInstance<AsmStatementContext>(_ctx, getState());
  enterRule(_localctx, 164, CParser::RuleAsmStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1263);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__13)
      | (1ULL << CParser::T__14)
      | (1ULL << CParser::T__16))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(1265);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__8)
      | (1ULL << CParser::T__9)
      | (1ULL << CParser::Const)
      | (1ULL << CParser::Restrict)
      | (1ULL << CParser::Volatile)
      | (1ULL << CParser::Atomic))) != 0)) {
      setState(1264);
      typeQualifier();
    }
    setState(1268);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::Goto) {
      setState(1267);
      match(CParser::Goto);
    }
    setState(1270);
    match(CParser::LeftParen);
    setState(1271);
    asmArgument();
    setState(1272);
    match(CParser::RightParen);
    setState(1273);
    match(CParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AsmArgumentContext ------------------------------------------------------------------

CParser::AsmArgumentContext::AsmArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::AsmStringLiteralContext* CParser::AsmArgumentContext::asmStringLiteral() {
  return getRuleContext<CParser::AsmStringLiteralContext>(0);
}

std::vector<tree::TerminalNode *> CParser::AsmArgumentContext::Colon() {
  return getTokens(CParser::Colon);
}

tree::TerminalNode* CParser::AsmArgumentContext::Colon(size_t i) {
  return getToken(CParser::Colon, i);
}

std::vector<CParser::AsmOperandsContext *> CParser::AsmArgumentContext::asmOperands() {
  return getRuleContexts<CParser::AsmOperandsContext>();
}

CParser::AsmOperandsContext* CParser::AsmArgumentContext::asmOperands(size_t i) {
  return getRuleContext<CParser::AsmOperandsContext>(i);
}

CParser::AsmClobbersContext* CParser::AsmArgumentContext::asmClobbers() {
  return getRuleContext<CParser::AsmClobbersContext>(0);
}

CParser::AsmLabelsContext* CParser::AsmArgumentContext::asmLabels() {
  return getRuleContext<CParser::AsmLabelsContext>(0);
}


size_t CParser::AsmArgumentContext::getRuleIndex() const {
  return CParser::RuleAsmArgument;
}

void CParser::AsmArgumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAsmArgument(this);
}

void CParser::AsmArgumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAsmArgument(this);
}


antlrcpp::Any CParser::AsmArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitAsmArgument(this);
  else
    return visitor->visitChildren(this);
}

CParser::AsmArgumentContext* CParser::asmArgument() {
  AsmArgumentContext *_localctx = _tracker.createInstance<AsmArgumentContext>(_ctx, getState());
  enterRule(_localctx, 166, CParser::RuleAsmArgument);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1275);
    asmStringLiteral();
    setState(1296);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::Colon) {
      setState(1276);
      match(CParser::Colon);
      setState(1278);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::LeftBracket

      || _la == CParser::StringLiteral) {
        setState(1277);
        asmOperands();
      }
      setState(1294);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::Colon) {
        setState(1280);
        match(CParser::Colon);
        setState(1282);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CParser::LeftBracket

        || _la == CParser::StringLiteral) {
          setState(1281);
          asmOperands();
        }
        setState(1292);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CParser::Colon) {
          setState(1284);
          match(CParser::Colon);
          setState(1286);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CParser::StringLiteral) {
            setState(1285);
            asmClobbers();
          }
          setState(1290);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CParser::Colon) {
            setState(1288);
            match(CParser::Colon);
            setState(1289);
            asmLabels();
          }
        }
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AsmOperandsContext ------------------------------------------------------------------

CParser::AsmOperandsContext::AsmOperandsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::AsmOperandContext *> CParser::AsmOperandsContext::asmOperand() {
  return getRuleContexts<CParser::AsmOperandContext>();
}

CParser::AsmOperandContext* CParser::AsmOperandsContext::asmOperand(size_t i) {
  return getRuleContext<CParser::AsmOperandContext>(i);
}

std::vector<tree::TerminalNode *> CParser::AsmOperandsContext::Comma() {
  return getTokens(CParser::Comma);
}

tree::TerminalNode* CParser::AsmOperandsContext::Comma(size_t i) {
  return getToken(CParser::Comma, i);
}


size_t CParser::AsmOperandsContext::getRuleIndex() const {
  return CParser::RuleAsmOperands;
}

void CParser::AsmOperandsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAsmOperands(this);
}

void CParser::AsmOperandsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAsmOperands(this);
}


antlrcpp::Any CParser::AsmOperandsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitAsmOperands(this);
  else
    return visitor->visitChildren(this);
}

CParser::AsmOperandsContext* CParser::asmOperands() {
  AsmOperandsContext *_localctx = _tracker.createInstance<AsmOperandsContext>(_ctx, getState());
  enterRule(_localctx, 168, CParser::RuleAsmOperands);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1298);
    asmOperand();
    setState(1303);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::Comma) {
      setState(1299);
      match(CParser::Comma);
      setState(1300);
      asmOperand();
      setState(1305);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AsmOperandContext ------------------------------------------------------------------

CParser::AsmOperandContext::AsmOperandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::AsmStringLiteralContext* CParser::AsmOperandContext::asmStringLiteral() {
  return getRuleContext<CParser::AsmStringLiteralContext>(0);
}

tree::TerminalNode* CParser::AsmOperandContext::LeftParen() {
  return getToken(CParser::LeftParen, 0);
}

CParser::ExpressionContext* CParser::AsmOperandContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}

tree::TerminalNode* CParser::AsmOperandContext::RightParen() {
  return getToken(CParser::RightParen, 0);
}

tree::TerminalNode* CParser::AsmOperandContext::LeftBracket() {
  return getToken(CParser::LeftBracket, 0);
}

tree::TerminalNode* CParser::AsmOperandContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}

tree::TerminalNode* CParser::AsmOperandContext::RightBracket() {
  return getToken(CParser::RightBracket, 0);
}


size_t CParser::AsmOperandContext::getRuleIndex() const {
  return CParser::RuleAsmOperand;
}

void CParser::AsmOperandContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAsmOperand(this);
}

void CParser::AsmOperandContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAsmOperand(this);
}


antlrcpp::Any CParser::AsmOperandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitAsmOperand(this);
  else
    return visitor->visitChildren(this);
}

CParser::AsmOperandContext* CParser::asmOperand() {
  AsmOperandContext *_localctx = _tracker.createInstance<AsmOperandContext>(_ctx, getState());
  enterRule(_localctx, 170, CParser::RuleAsmOperand);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1319);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::StringLiteral: {
        enterOuterAlt(_localctx, 1);
        setState(1306);
        asmStringLiteral();
        setState(1307);
        match(CParser::LeftParen);
        setState(1308);
        expression(0);
        setState(1309);
        match(CParser::RightParen);
        break;
      }

      case CParser::LeftBracket: {
        enterOuterAlt(_localctx, 2);
        setState(1311);
        match(CParser::LeftBracket);
        setState(1312);
        match(CParser::Identifier);
        setState(1313);
        match(CParser::RightBracket);
        setState(1314);
        asmStringLiteral();
        setState(1315);
        match(CParser::LeftParen);
        setState(1316);
        expression(0);
        setState(1317);
        match(CParser::RightParen);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AsmClobbersContext ------------------------------------------------------------------

CParser::AsmClobbersContext::AsmClobbersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::AsmStringLiteralContext *> CParser::AsmClobbersContext::asmStringLiteral() {
  return getRuleContexts<CParser::AsmStringLiteralContext>();
}

CParser::AsmStringLiteralContext* CParser::AsmClobbersContext::asmStringLiteral(size_t i) {
  return getRuleContext<CParser::AsmStringLiteralContext>(i);
}

std::vector<tree::TerminalNode *> CParser::AsmClobbersContext::Comma() {
  return getTokens(CParser::Comma);
}

tree::TerminalNode* CParser::AsmClobbersContext::Comma(size_t i) {
  return getToken(CParser::Comma, i);
}


size_t CParser::AsmClobbersContext::getRuleIndex() const {
  return CParser::RuleAsmClobbers;
}

void CParser::AsmClobbersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAsmClobbers(this);
}

void CParser::AsmClobbersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAsmClobbers(this);
}


antlrcpp::Any CParser::AsmClobbersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitAsmClobbers(this);
  else
    return visitor->visitChildren(this);
}

CParser::AsmClobbersContext* CParser::asmClobbers() {
  AsmClobbersContext *_localctx = _tracker.createInstance<AsmClobbersContext>(_ctx, getState());
  enterRule(_localctx, 172, CParser::RuleAsmClobbers);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1321);
    asmStringLiteral();
    setState(1326);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::Comma) {
      setState(1322);
      match(CParser::Comma);
      setState(1323);
      asmStringLiteral();
      setState(1328);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AsmLabelsContext ------------------------------------------------------------------

CParser::AsmLabelsContext::AsmLabelsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> CParser::AsmLabelsContext::Identifier() {
  return getTokens(CParser::Identifier);
}

tree::TerminalNode* CParser::AsmLabelsContext::Identifier(size_t i) {
  return getToken(CParser::Identifier, i);
}

std::vector<tree::TerminalNode *> CParser::AsmLabelsContext::Comma() {
  return getTokens(CParser::Comma);
}

tree::TerminalNode* CParser::AsmLabelsContext::Comma(size_t i) {
  return getToken(CParser::Comma, i);
}


size_t CParser::AsmLabelsContext::getRuleIndex() const {
  return CParser::RuleAsmLabels;
}

void CParser::AsmLabelsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAsmLabels(this);
}

void CParser::AsmLabelsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAsmLabels(this);
}


antlrcpp::Any CParser::AsmLabelsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitAsmLabels(this);
  else
    return visitor->visitChildren(this);
}

CParser::AsmLabelsContext* CParser::asmLabels() {
  AsmLabelsContext *_localctx = _tracker.createInstance<AsmLabelsContext>(_ctx, getState());
  enterRule(_localctx, 174, CParser::RuleAsmLabels);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1329);
    match(CParser::Identifier);
    setState(1334);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::Comma) {
      setState(1330);
      match(CParser::Comma);
      setState(1331);
      match(CParser::Identifier);
      setState(1336);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AsmDefinitionContext ------------------------------------------------------------------

CParser::AsmDefinitionContext::AsmDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::SimpleAsmExprContext* CParser::AsmDefinitionContext::simpleAsmExpr() {
  return getRuleContext<CParser::SimpleAsmExprContext>(0);
}


size_t CParser::AsmDefinitionContext::getRuleIndex() const {
  return CParser::RuleAsmDefinition;
}

void CParser::AsmDefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAsmDefinition(this);
}

void CParser::AsmDefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAsmDefinition(this);
}


antlrcpp::Any CParser::AsmDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitAsmDefinition(this);
  else
    return visitor->visitChildren(this);
}

CParser::AsmDefinitionContext* CParser::asmDefinition() {
  AsmDefinitionContext *_localctx = _tracker.createInstance<AsmDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 176, CParser::RuleAsmDefinition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1337);
    simpleAsmExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpleAsmExprContext ------------------------------------------------------------------

CParser::SimpleAsmExprContext::SimpleAsmExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::SimpleAsmExprContext::LeftParen() {
  return getToken(CParser::LeftParen, 0);
}

CParser::AsmStringLiteralContext* CParser::SimpleAsmExprContext::asmStringLiteral() {
  return getRuleContext<CParser::AsmStringLiteralContext>(0);
}

tree::TerminalNode* CParser::SimpleAsmExprContext::RightParen() {
  return getToken(CParser::RightParen, 0);
}


size_t CParser::SimpleAsmExprContext::getRuleIndex() const {
  return CParser::RuleSimpleAsmExpr;
}

void CParser::SimpleAsmExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimpleAsmExpr(this);
}

void CParser::SimpleAsmExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimpleAsmExpr(this);
}


antlrcpp::Any CParser::SimpleAsmExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitSimpleAsmExpr(this);
  else
    return visitor->visitChildren(this);
}

CParser::SimpleAsmExprContext* CParser::simpleAsmExpr() {
  SimpleAsmExprContext *_localctx = _tracker.createInstance<SimpleAsmExprContext>(_ctx, getState());
  enterRule(_localctx, 178, CParser::RuleSimpleAsmExpr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1339);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__13)
      | (1ULL << CParser::T__14)
      | (1ULL << CParser::T__16))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(1340);
    match(CParser::LeftParen);
    setState(1341);
    asmStringLiteral();
    setState(1342);
    match(CParser::RightParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AsmStringLiteralContext ------------------------------------------------------------------

CParser::AsmStringLiteralContext::AsmStringLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> CParser::AsmStringLiteralContext::StringLiteral() {
  return getTokens(CParser::StringLiteral);
}

tree::TerminalNode* CParser::AsmStringLiteralContext::StringLiteral(size_t i) {
  return getToken(CParser::StringLiteral, i);
}


size_t CParser::AsmStringLiteralContext::getRuleIndex() const {
  return CParser::RuleAsmStringLiteral;
}

void CParser::AsmStringLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAsmStringLiteral(this);
}

void CParser::AsmStringLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAsmStringLiteral(this);
}


antlrcpp::Any CParser::AsmStringLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitAsmStringLiteral(this);
  else
    return visitor->visitChildren(this);
}

CParser::AsmStringLiteralContext* CParser::asmStringLiteral() {
  AsmStringLiteralContext *_localctx = _tracker.createInstance<AsmStringLiteralContext>(_ctx, getState());
  enterRule(_localctx, 180, CParser::RuleAsmStringLiteral);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1345); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1344);
      match(CParser::StringLiteral);
      setState(1347); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == CParser::StringLiteral);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompilationUnitContext ------------------------------------------------------------------

CParser::CompilationUnitContext::CompilationUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::CompilationUnitContext::EOF() {
  return getToken(CParser::EOF, 0);
}

CParser::TranslationUnitContext* CParser::CompilationUnitContext::translationUnit() {
  return getRuleContext<CParser::TranslationUnitContext>(0);
}


size_t CParser::CompilationUnitContext::getRuleIndex() const {
  return CParser::RuleCompilationUnit;
}

void CParser::CompilationUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompilationUnit(this);
}

void CParser::CompilationUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompilationUnit(this);
}


antlrcpp::Any CParser::CompilationUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitCompilationUnit(this);
  else
    return visitor->visitChildren(this);
}

CParser::CompilationUnitContext* CParser::compilationUnit() {
  CompilationUnitContext *_localctx = _tracker.createInstance<CompilationUnitContext>(_ctx, getState());
  enterRule(_localctx, 182, CParser::RuleCompilationUnit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1350);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__0)
      | (1ULL << CParser::T__4)
      | (1ULL << CParser::T__5)
      | (1ULL << CParser::T__6)
      | (1ULL << CParser::T__7)
      | (1ULL << CParser::T__8)
      | (1ULL << CParser::T__9)
      | (1ULL << CParser::T__10)
      | (1ULL << CParser::T__11)
      | (1ULL << CParser::T__12)
      | (1ULL << CParser::T__13)
      | (1ULL << CParser::T__14)
      | (1ULL << CParser::T__15)
      | (1ULL << CParser::T__16)
      | (1ULL << CParser::Auto)
      | (1ULL << CParser::Char)
      | (1ULL << CParser::Const)
      | (1ULL << CParser::Double)
      | (1ULL << CParser::Enum)
      | (1ULL << CParser::Extern)
      | (1ULL << CParser::Float)
      | (1ULL << CParser::Inline)
      | (1ULL << CParser::Int)
      | (1ULL << CParser::Long)
      | (1ULL << CParser::Register)
      | (1ULL << CParser::Restrict)
      | (1ULL << CParser::Short)
      | (1ULL << CParser::Signed)
      | (1ULL << CParser::Static)
      | (1ULL << CParser::Struct)
      | (1ULL << CParser::Typedef)
      | (1ULL << CParser::Typeof)
      | (1ULL << CParser::Union)
      | (1ULL << CParser::Unsigned)
      | (1ULL << CParser::Void)
      | (1ULL << CParser::Volatile)
      | (1ULL << CParser::Alignas)
      | (1ULL << CParser::Atomic)
      | (1ULL << CParser::Bool)
      | (1ULL << CParser::Complex)
      | (1ULL << CParser::Noreturn)
      | (1ULL << CParser::StaticAssert)
      | (1ULL << CParser::ThreadLocal)
      | (1ULL << CParser::LeftParen))) != 0) || ((((_la - 79) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 79)) & ((1ULL << (CParser::Star - 79))
      | (1ULL << (CParser::Caret - 79))
      | (1ULL << (CParser::Semi - 79))
      | (1ULL << (CParser::Identifier - 79)))) != 0)) {
      setState(1349);
      translationUnit(0);
    }
    setState(1352);
    match(CParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TranslationUnitContext ------------------------------------------------------------------

CParser::TranslationUnitContext::TranslationUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ExternalDeclarationContext* CParser::TranslationUnitContext::externalDeclaration() {
  return getRuleContext<CParser::ExternalDeclarationContext>(0);
}

CParser::TranslationUnitContext* CParser::TranslationUnitContext::translationUnit() {
  return getRuleContext<CParser::TranslationUnitContext>(0);
}


size_t CParser::TranslationUnitContext::getRuleIndex() const {
  return CParser::RuleTranslationUnit;
}

void CParser::TranslationUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTranslationUnit(this);
}

void CParser::TranslationUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTranslationUnit(this);
}


antlrcpp::Any CParser::TranslationUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitTranslationUnit(this);
  else
    return visitor->visitChildren(this);
}


CParser::TranslationUnitContext* CParser::translationUnit() {
   return translationUnit(0);
}

CParser::TranslationUnitContext* CParser::translationUnit(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::TranslationUnitContext *_localctx = _tracker.createInstance<TranslationUnitContext>(_ctx, parentState);
  CParser::TranslationUnitContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 184;
  enterRecursionRule(_localctx, 184, CParser::RuleTranslationUnit, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1355);
    externalDeclaration();
    _ctx->stop = _input->LT(-1);
    setState(1361);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 150, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TranslationUnitContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTranslationUnit);
        setState(1357);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1358);
        externalDeclaration(); 
      }
      setState(1363);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 150, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ExternalDeclarationContext ------------------------------------------------------------------

CParser::ExternalDeclarationContext::ExternalDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::FunctionDefinitionContext* CParser::ExternalDeclarationContext::functionDefinition() {
  return getRuleContext<CParser::FunctionDefinitionContext>(0);
}

CParser::DeclarationContext* CParser::ExternalDeclarationContext::declaration() {
  return getRuleContext<CParser::DeclarationContext>(0);
}

tree::TerminalNode* CParser::ExternalDeclarationContext::Semi() {
  return getToken(CParser::Semi, 0);
}

CParser::AsmDefinitionContext* CParser::ExternalDeclarationContext::asmDefinition() {
  return getRuleContext<CParser::AsmDefinitionContext>(0);
}


size_t CParser::ExternalDeclarationContext::getRuleIndex() const {
  return CParser::RuleExternalDeclaration;
}

void CParser::ExternalDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExternalDeclaration(this);
}

void CParser::ExternalDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExternalDeclaration(this);
}


antlrcpp::Any CParser::ExternalDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitExternalDeclaration(this);
  else
    return visitor->visitChildren(this);
}

CParser::ExternalDeclarationContext* CParser::externalDeclaration() {
  ExternalDeclarationContext *_localctx = _tracker.createInstance<ExternalDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 186, CParser::RuleExternalDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1368);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 151, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1364);
      functionDefinition();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1365);
      declaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1366);
      match(CParser::Semi);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1367);
      asmDefinition();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDefinitionContext ------------------------------------------------------------------

CParser::FunctionDefinitionContext::FunctionDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DeclaratorContext* CParser::FunctionDefinitionContext::declarator() {
  return getRuleContext<CParser::DeclaratorContext>(0);
}

CParser::CompoundStatementContext* CParser::FunctionDefinitionContext::compoundStatement() {
  return getRuleContext<CParser::CompoundStatementContext>(0);
}

CParser::DeclarationSpecifiersContext* CParser::FunctionDefinitionContext::declarationSpecifiers() {
  return getRuleContext<CParser::DeclarationSpecifiersContext>(0);
}

CParser::DeclarationListContext* CParser::FunctionDefinitionContext::declarationList() {
  return getRuleContext<CParser::DeclarationListContext>(0);
}


size_t CParser::FunctionDefinitionContext::getRuleIndex() const {
  return CParser::RuleFunctionDefinition;
}

void CParser::FunctionDefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDefinition(this);
}

void CParser::FunctionDefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDefinition(this);
}


antlrcpp::Any CParser::FunctionDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitFunctionDefinition(this);
  else
    return visitor->visitChildren(this);
}

CParser::FunctionDefinitionContext* CParser::functionDefinition() {
  FunctionDefinitionContext *_localctx = _tracker.createInstance<FunctionDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 188, CParser::RuleFunctionDefinition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1371);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 152, _ctx)) {
    case 1: {
      setState(1370);
      declarationSpecifiers();
      break;
    }

    }
    setState(1373);
    declarator();
    setState(1375);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__0)
      | (1ULL << CParser::T__4)
      | (1ULL << CParser::T__5)
      | (1ULL << CParser::T__6)
      | (1ULL << CParser::T__7)
      | (1ULL << CParser::T__8)
      | (1ULL << CParser::T__9)
      | (1ULL << CParser::T__10)
      | (1ULL << CParser::T__11)
      | (1ULL << CParser::T__12)
      | (1ULL << CParser::T__15)
      | (1ULL << CParser::Auto)
      | (1ULL << CParser::Char)
      | (1ULL << CParser::Const)
      | (1ULL << CParser::Double)
      | (1ULL << CParser::Enum)
      | (1ULL << CParser::Extern)
      | (1ULL << CParser::Float)
      | (1ULL << CParser::Inline)
      | (1ULL << CParser::Int)
      | (1ULL << CParser::Long)
      | (1ULL << CParser::Register)
      | (1ULL << CParser::Restrict)
      | (1ULL << CParser::Short)
      | (1ULL << CParser::Signed)
      | (1ULL << CParser::Static)
      | (1ULL << CParser::Struct)
      | (1ULL << CParser::Typedef)
      | (1ULL << CParser::Typeof)
      | (1ULL << CParser::Union)
      | (1ULL << CParser::Unsigned)
      | (1ULL << CParser::Void)
      | (1ULL << CParser::Volatile)
      | (1ULL << CParser::Alignas)
      | (1ULL << CParser::Atomic)
      | (1ULL << CParser::Bool)
      | (1ULL << CParser::Complex)
      | (1ULL << CParser::Noreturn)
      | (1ULL << CParser::StaticAssert)
      | (1ULL << CParser::ThreadLocal))) != 0) || _la == CParser::Identifier) {
      setState(1374);
      declarationList(0);
    }
    setState(1377);
    compoundStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationListContext ------------------------------------------------------------------

CParser::DeclarationListContext::DeclarationListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DeclarationContext* CParser::DeclarationListContext::declaration() {
  return getRuleContext<CParser::DeclarationContext>(0);
}

CParser::DeclarationListContext* CParser::DeclarationListContext::declarationList() {
  return getRuleContext<CParser::DeclarationListContext>(0);
}


size_t CParser::DeclarationListContext::getRuleIndex() const {
  return CParser::RuleDeclarationList;
}

void CParser::DeclarationListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarationList(this);
}

void CParser::DeclarationListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarationList(this);
}


antlrcpp::Any CParser::DeclarationListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDeclarationList(this);
  else
    return visitor->visitChildren(this);
}


CParser::DeclarationListContext* CParser::declarationList() {
   return declarationList(0);
}

CParser::DeclarationListContext* CParser::declarationList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::DeclarationListContext *_localctx = _tracker.createInstance<DeclarationListContext>(_ctx, parentState);
  CParser::DeclarationListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 190;
  enterRecursionRule(_localctx, 190, CParser::RuleDeclarationList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1380);
    declaration();
    _ctx->stop = _input->LT(-1);
    setState(1386);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 154, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<DeclarationListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleDeclarationList);
        setState(1382);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1383);
        declaration(); 
      }
      setState(1388);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 154, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool CParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 2: return genericAssocListSempred(dynamic_cast<GenericAssocListContext *>(context), predicateIndex);
    case 4: return postfixExpressionSempred(dynamic_cast<PostfixExpressionContext *>(context), predicateIndex);
    case 5: return argumentExpressionListSempred(dynamic_cast<ArgumentExpressionListContext *>(context), predicateIndex);
    case 9: return multiplicativeExpressionSempred(dynamic_cast<MultiplicativeExpressionContext *>(context), predicateIndex);
    case 10: return additiveExpressionSempred(dynamic_cast<AdditiveExpressionContext *>(context), predicateIndex);
    case 11: return shiftExpressionSempred(dynamic_cast<ShiftExpressionContext *>(context), predicateIndex);
    case 12: return relationalExpressionSempred(dynamic_cast<RelationalExpressionContext *>(context), predicateIndex);
    case 13: return equalityExpressionSempred(dynamic_cast<EqualityExpressionContext *>(context), predicateIndex);
    case 14: return andExpressionSempred(dynamic_cast<AndExpressionContext *>(context), predicateIndex);
    case 15: return exclusiveOrExpressionSempred(dynamic_cast<ExclusiveOrExpressionContext *>(context), predicateIndex);
    case 16: return inclusiveOrExpressionSempred(dynamic_cast<InclusiveOrExpressionContext *>(context), predicateIndex);
    case 17: return logicalAndExpressionSempred(dynamic_cast<LogicalAndExpressionContext *>(context), predicateIndex);
    case 18: return logicalOrExpressionSempred(dynamic_cast<LogicalOrExpressionContext *>(context), predicateIndex);
    case 22: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);
    case 28: return initDeclaratorListSempred(dynamic_cast<InitDeclaratorListContext *>(context), predicateIndex);
    case 31: return typeSpecifierSempred(dynamic_cast<TypeSpecifierContext *>(context), predicateIndex);
    case 34: return structDeclarationListSempred(dynamic_cast<StructDeclarationListContext *>(context), predicateIndex);
    case 37: return structDeclaratorListSempred(dynamic_cast<StructDeclaratorListContext *>(context), predicateIndex);
    case 40: return enumeratorListSempred(dynamic_cast<EnumeratorListContext *>(context), predicateIndex);
    case 48: return directDeclaratorSempred(dynamic_cast<DirectDeclaratorContext *>(context), predicateIndex);
    case 55: return typeQualifierListSempred(dynamic_cast<TypeQualifierListContext *>(context), predicateIndex);
    case 57: return parameterListSempred(dynamic_cast<ParameterListContext *>(context), predicateIndex);
    case 59: return identifierListSempred(dynamic_cast<IdentifierListContext *>(context), predicateIndex);
    case 62: return directAbstractDeclaratorSempred(dynamic_cast<DirectAbstractDeclaratorContext *>(context), predicateIndex);
    case 65: return initializerListSempred(dynamic_cast<InitializerListContext *>(context), predicateIndex);
    case 67: return designatorListSempred(dynamic_cast<DesignatorListContext *>(context), predicateIndex);
    case 73: return blockItemListSempred(dynamic_cast<BlockItemListContext *>(context), predicateIndex);
    case 80: return forExpressionSempred(dynamic_cast<ForExpressionContext *>(context), predicateIndex);
    case 92: return translationUnitSempred(dynamic_cast<TranslationUnitContext *>(context), predicateIndex);
    case 95: return declarationListSempred(dynamic_cast<DeclarationListContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CParser::genericAssocListSempred(GenericAssocListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::postfixExpressionSempred(PostfixExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 10);
    case 2: return precpred(_ctx, 9);
    case 3: return precpred(_ctx, 8);
    case 4: return precpred(_ctx, 7);
    case 5: return precpred(_ctx, 6);
    case 6: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

bool CParser::argumentExpressionListSempred(ArgumentExpressionListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::multiplicativeExpressionSempred(MultiplicativeExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 8: return precpred(_ctx, 3);
    case 9: return precpred(_ctx, 2);
    case 10: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::additiveExpressionSempred(AdditiveExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 11: return precpred(_ctx, 2);
    case 12: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::shiftExpressionSempred(ShiftExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 13: return precpred(_ctx, 2);
    case 14: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::relationalExpressionSempred(RelationalExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 15: return precpred(_ctx, 4);
    case 16: return precpred(_ctx, 3);
    case 17: return precpred(_ctx, 2);
    case 18: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::equalityExpressionSempred(EqualityExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 19: return precpred(_ctx, 2);
    case 20: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::andExpressionSempred(AndExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 21: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::exclusiveOrExpressionSempred(ExclusiveOrExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 22: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::inclusiveOrExpressionSempred(InclusiveOrExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 23: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::logicalAndExpressionSempred(LogicalAndExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 24: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::logicalOrExpressionSempred(LogicalOrExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 25: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 26: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::initDeclaratorListSempred(InitDeclaratorListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 27: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::typeSpecifierSempred(TypeSpecifierContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 28: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::structDeclarationListSempred(StructDeclarationListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 29: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::structDeclaratorListSempred(StructDeclaratorListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 30: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::enumeratorListSempred(EnumeratorListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 31: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::directDeclaratorSempred(DirectDeclaratorContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 32: return precpred(_ctx, 8);
    case 33: return precpred(_ctx, 7);
    case 34: return precpred(_ctx, 6);
    case 35: return precpred(_ctx, 5);
    case 36: return precpred(_ctx, 4);
    case 37: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool CParser::typeQualifierListSempred(TypeQualifierListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 38: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::parameterListSempred(ParameterListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 39: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::identifierListSempred(IdentifierListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 40: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::directAbstractDeclaratorSempred(DirectAbstractDeclaratorContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 41: return precpred(_ctx, 5);
    case 42: return precpred(_ctx, 4);
    case 43: return precpred(_ctx, 3);
    case 44: return precpred(_ctx, 2);
    case 45: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::initializerListSempred(InitializerListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 46: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::designatorListSempred(DesignatorListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 47: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::blockItemListSempred(BlockItemListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 48: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::forExpressionSempred(ForExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 49: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::translationUnitSempred(TranslationUnitContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 50: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::declarationListSempred(DeclarationListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 51: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> CParser::_decisionToDFA;
atn::PredictionContextCache CParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN CParser::_atn;
std::vector<uint16_t> CParser::_serializedATN;

std::vector<std::string> CParser::_ruleNames = {
  "primaryExpression", "genericSelection", "genericAssocList", "genericAssociation", 
  "postfixExpression", "argumentExpressionList", "unaryExpression", "unaryOperator", 
  "castExpression", "multiplicativeExpression", "additiveExpression", "shiftExpression", 
  "relationalExpression", "equalityExpression", "andExpression", "exclusiveOrExpression", 
  "inclusiveOrExpression", "logicalAndExpression", "logicalOrExpression", 
  "conditionalExpression", "assignmentExpression", "assignmentOperator", 
  "expression", "constantExpression", "declaration", "declarationSpecifiers", 
  "declarationSpecifiers2", "declarationSpecifier", "initDeclaratorList", 
  "initDeclarator", "storageClassSpecifier", "typeSpecifier", "structOrUnionSpecifier", 
  "structOrUnion", "structDeclarationList", "structDeclaration", "specifierQualifierList", 
  "structDeclaratorList", "structDeclarator", "enumSpecifier", "enumeratorList", 
  "enumerator", "enumerationConstant", "atomicTypeSpecifier", "typeQualifier", 
  "functionSpecifier", "alignmentSpecifier", "declarator", "directDeclarator", 
  "gccDeclaratorExtension", "gccAttributeSpecifier", "gccAttributeList", 
  "gccAttribute", "nestedParenthesesBlock", "pointer", "typeQualifierList", 
  "parameterTypeList", "parameterList", "parameterDeclaration", "identifierList", 
  "typeName", "abstractDeclarator", "directAbstractDeclarator", "typedefName", 
  "initializer", "initializerList", "designation", "designatorList", "designator", 
  "staticAssertDeclaration", "statement", "labeledStatement", "compoundStatement", 
  "blockItemList", "blockItem", "expressionStatement", "selectionStatement", 
  "iterationStatement", "forCondition", "forDeclaration", "forExpression", 
  "jumpStatement", "asmStatement", "asmArgument", "asmOperands", "asmOperand", 
  "asmClobbers", "asmLabels", "asmDefinition", "simpleAsmExpr", "asmStringLiteral", 
  "compilationUnit", "translationUnit", "externalDeclaration", "functionDefinition", 
  "declarationList"
};

std::vector<std::string> CParser::_literalNames = {
  "", "'__extension__'", "'__builtin_va_arg'", "'__builtin_offsetof'", "'__alignof__'", 
  "'__m128'", "'__m128d'", "'__m128i'", "'__typeof__'", "'__volatile'", 
  "'__volatile__'", "'__inline__'", "'__stdcall'", "'__declspec'", "'asm'", 
  "'__asm'", "'__attribute__'", "'__asm__'", "'auto'", "'break'", "'case'", 
  "'char'", "'const'", "'continue'", "'default'", "'do'", "'double'", "'else'", 
  "'enum'", "'extern'", "'float'", "'for'", "'goto'", "'if'", "'inline'", 
  "'int'", "'long'", "'register'", "'restrict'", "'return'", "'short'", 
  "'signed'", "'sizeof'", "'static'", "'struct'", "'switch'", "'typedef'", 
  "'typeof'", "'union'", "'unsigned'", "'void'", "'volatile'", "'while'", 
  "'_Alignas'", "'_Alignof'", "'_Atomic'", "'_Bool'", "'_Complex'", "'_Generic'", 
  "'_Imaginary'", "'_Noreturn'", "'_Static_assert'", "'_Thread_local'", 
  "'('", "')'", "'['", "']'", "'{'", "'}'", "'<'", "'<='", "'>'", "'>='", 
  "'<<'", "'>>'", "'+'", "'++'", "'-'", "'--'", "'*'", "'/'", "'%'", "'&'", 
  "'|'", "'&&'", "'||'", "'^'", "'!'", "'~'", "'?'", "':'", "';'", "','", 
  "'='", "'*='", "'/='", "'%='", "'+='", "'-='", "'<<='", "'>>='", "'&='", 
  "'^='", "'|='", "'=='", "'!='", "'->'", "'.'", "'...'"
};

std::vector<std::string> CParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "Auto", "Break", "Case", "Char", "Const", "Continue", "Default", "Do", 
  "Double", "Else", "Enum", "Extern", "Float", "For", "Goto", "If", "Inline", 
  "Int", "Long", "Register", "Restrict", "Return", "Short", "Signed", "Sizeof", 
  "Static", "Struct", "Switch", "Typedef", "Typeof", "Union", "Unsigned", 
  "Void", "Volatile", "While", "Alignas", "Alignof", "Atomic", "Bool", "Complex", 
  "Generic", "Imaginary", "Noreturn", "StaticAssert", "ThreadLocal", "LeftParen", 
  "RightParen", "LeftBracket", "RightBracket", "LeftBrace", "RightBrace", 
  "Less", "LessEqual", "Greater", "GreaterEqual", "LeftShift", "RightShift", 
  "Plus", "PlusPlus", "Minus", "MinusMinus", "Star", "Div", "Mod", "And", 
  "Or", "AndAnd", "OrOr", "Caret", "Not", "Tilde", "Question", "Colon", 
  "Semi", "Comma", "Assign", "StarAssign", "DivAssign", "ModAssign", "PlusAssign", 
  "MinusAssign", "LeftShiftAssign", "RightShiftAssign", "AndAssign", "XorAssign", 
  "OrAssign", "Equal", "NotEqual", "Arrow", "Dot", "Ellipsis", "Identifier", 
  "Constant", "DigitSequence", "StringLiteral", "ComplexDefine", "IncludeDirective", 
  "LineAfterPreprocessing", "LineDirective", "PragmaDirective", "Whitespace", 
  "Newline", "BlockComment", "LineComment"
};

dfa::Vocabulary CParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> CParser::_tokenNames;

CParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x7b, 0x570, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x4, 
    0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 0x9, 0x3b, 0x4, 0x3c, 
    0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 0x9, 0x3e, 0x4, 0x3f, 0x9, 
    0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 
    0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 
    0x46, 0x9, 0x46, 0x4, 0x47, 0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 
    0x9, 0x49, 0x4, 0x4a, 0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 
    0x4c, 0x4, 0x4d, 0x9, 0x4d, 0x4, 0x4e, 0x9, 0x4e, 0x4, 0x4f, 0x9, 0x4f, 
    0x4, 0x50, 0x9, 0x50, 0x4, 0x51, 0x9, 0x51, 0x4, 0x52, 0x9, 0x52, 0x4, 
    0x53, 0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x4, 0x55, 0x9, 0x55, 0x4, 0x56, 
    0x9, 0x56, 0x4, 0x57, 0x9, 0x57, 0x4, 0x58, 0x9, 0x58, 0x4, 0x59, 0x9, 
    0x59, 0x4, 0x5a, 0x9, 0x5a, 0x4, 0x5b, 0x9, 0x5b, 0x4, 0x5c, 0x9, 0x5c, 
    0x4, 0x5d, 0x9, 0x5d, 0x4, 0x5e, 0x9, 0x5e, 0x4, 0x5f, 0x9, 0x5f, 0x4, 
    0x60, 0x9, 0x60, 0x4, 0x61, 0x9, 0x61, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x6, 0x2, 0xc6, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0xc7, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0xd0, 0xa, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0xe4, 0xa, 0x2, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0xf3, 0xa, 
    0x4, 0xc, 0x4, 0xe, 0x4, 0xf6, 0xb, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0xff, 0xa, 0x5, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x123, 
    0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x12d, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x7, 0x6, 0x13a, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x13d, 
    0xb, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x7, 0x7, 0x145, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x148, 0xb, 0x7, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x5, 0x8, 0x160, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x171, 0xa, 0xa, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x17f, 0xa, 0xb, 
    0xc, 0xb, 0xe, 0xb, 0x182, 0xb, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x18d, 
    0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x190, 0xb, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 
    0xd, 0x19b, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x19e, 0xb, 0xd, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x7, 0xe, 0x1af, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x1b2, 0xb, 0xe, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x7, 0xf, 0x1bd, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x1c0, 
    0xb, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x7, 0x10, 0x1c8, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0x1cb, 0xb, 
    0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x7, 0x11, 0x1d3, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x1d6, 0xb, 0x11, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 
    0x12, 0x1de, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0x1e1, 0xb, 0x12, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 
    0x1e9, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 0x1ec, 0xb, 0x13, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0x1f4, 
    0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 0x1f7, 0xb, 0x14, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x1ff, 0xa, 0x15, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 
    0x16, 0x207, 0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0x211, 0xa, 0x18, 
    0xc, 0x18, 0xe, 0x18, 0x214, 0xb, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 
    0x1a, 0x5, 0x1a, 0x220, 0xa, 0x1a, 0x3, 0x1b, 0x6, 0x1b, 0x223, 0xa, 
    0x1b, 0xd, 0x1b, 0xe, 0x1b, 0x224, 0x3, 0x1c, 0x6, 0x1c, 0x228, 0xa, 
    0x1c, 0xd, 0x1c, 0xe, 0x1c, 0x229, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x231, 0xa, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x7, 0x1e, 0x239, 0xa, 0x1e, 
    0xc, 0x1e, 0xe, 0x1e, 0x23c, 0xb, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x243, 0xa, 0x1f, 0x3, 0x20, 0x5, 0x20, 
    0x246, 0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x5, 0x20, 0x24e, 0xa, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 
    0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 
    0x25f, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 0x7, 0x21, 0x263, 0xa, 0x21, 
    0xc, 0x21, 0xe, 0x21, 0x266, 0xb, 0x21, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 
    0x26a, 0xa, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x26e, 0xa, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x275, 
    0xa, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 
    0x24, 0x3, 0x24, 0x7, 0x24, 0x27e, 0xa, 0x24, 0xc, 0x24, 0xe, 0x24, 
    0x281, 0xb, 0x24, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x285, 0xa, 0x25, 
    0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x28a, 0xa, 0x25, 0x3, 0x26, 
    0x3, 0x26, 0x5, 0x26, 0x28e, 0xa, 0x26, 0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 
    0x292, 0xa, 0x26, 0x5, 0x26, 0x294, 0xa, 0x26, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x7, 0x27, 0x29c, 0xa, 0x27, 
    0xc, 0x27, 0xe, 0x27, 0x29f, 0xb, 0x27, 0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 
    0x2a3, 0xa, 0x28, 0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 0x2a7, 0xa, 0x28, 
    0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x2ab, 0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 
    0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x2b3, 0xa, 0x29, 
    0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 
    0x29, 0x5, 0x29, 0x2bc, 0xa, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 
    0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x7, 0x2a, 0x2c4, 0xa, 0x2a, 0xc, 0x2a, 
    0xe, 0x2a, 0x2c7, 0xb, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 
    0x3, 0x2b, 0x5, 0x2b, 0x2ce, 0xa, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2d, 
    0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 
    0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x5, 0x2f, 
    0x2df, 0xa, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 
    0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 0x2eb, 
    0xa, 0x30, 0x3, 0x31, 0x5, 0x31, 0x2ee, 0xa, 0x31, 0x3, 0x31, 0x3, 0x31, 
    0x7, 0x31, 0x2f2, 0xa, 0x31, 0xc, 0x31, 0xe, 0x31, 0x2f5, 0xb, 0x31, 
    0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 
    0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 0x302, 
    0xa, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 0x308, 
    0xa, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 0x30d, 0xa, 0x32, 
    0x3, 0x32, 0x5, 0x32, 0x310, 0xa, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 
    0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 0x317, 0xa, 0x32, 0x3, 0x32, 0x3, 0x32, 
    0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 
    0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 0x326, 
    0xa, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 
    0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 0x332, 
    0xa, 0x32, 0x3, 0x32, 0x7, 0x32, 0x335, 0xa, 0x32, 0xc, 0x32, 0xe, 0x32, 
    0x338, 0xb, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x6, 0x33, 0x33d, 
    0xa, 0x33, 0xd, 0x33, 0xe, 0x33, 0x33e, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 
    0x343, 0xa, 0x33, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 
    0x3, 0x34, 0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x7, 0x35, 0x34f, 
    0xa, 0x35, 0xc, 0x35, 0xe, 0x35, 0x352, 0xb, 0x35, 0x3, 0x35, 0x5, 0x35, 
    0x355, 0xa, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x5, 0x36, 0x35a, 
    0xa, 0x36, 0x3, 0x36, 0x5, 0x36, 0x35d, 0xa, 0x36, 0x3, 0x36, 0x5, 0x36, 
    0x360, 0xa, 0x36, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 
    0x7, 0x37, 0x367, 0xa, 0x37, 0xc, 0x37, 0xe, 0x37, 0x36a, 0xb, 0x37, 
    0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x36e, 0xa, 0x38, 0x3, 0x38, 0x3, 0x38, 
    0x5, 0x38, 0x372, 0xa, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 
    0x377, 0xa, 0x38, 0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x37b, 0xa, 0x38, 
    0x3, 0x38, 0x5, 0x38, 0x37e, 0xa, 0x38, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 
    0x3, 0x39, 0x3, 0x39, 0x7, 0x39, 0x385, 0xa, 0x39, 0xc, 0x39, 0xe, 0x39, 
    0x388, 0xb, 0x39, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 
    0x5, 0x3a, 0x38f, 0xa, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 
    0x3, 0x3b, 0x3, 0x3b, 0x7, 0x3b, 0x397, 0xa, 0x3b, 0xc, 0x3b, 0xe, 0x3b, 
    0x39a, 0xb, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 
    0x5, 0x3c, 0x3a1, 0xa, 0x3c, 0x5, 0x3c, 0x3a3, 0xa, 0x3c, 0x3, 0x3d, 
    0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x7, 0x3d, 0x3ab, 
    0xa, 0x3d, 0xc, 0x3d, 0xe, 0x3d, 0x3ae, 0xb, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 
    0x5, 0x3e, 0x3b2, 0xa, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 0x5, 0x3f, 0x3b6, 
    0xa, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x7, 0x3f, 0x3ba, 0xa, 0x3f, 0xc, 0x3f, 
    0xe, 0x3f, 0x3bd, 0xb, 0x3f, 0x5, 0x3f, 0x3bf, 0xa, 0x3f, 0x3, 0x40, 
    0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x7, 0x40, 0x3c6, 0xa, 0x40, 
    0xc, 0x40, 0xe, 0x40, 0x3c9, 0xb, 0x40, 0x3, 0x40, 0x3, 0x40, 0x5, 0x40, 
    0x3cd, 0xa, 0x40, 0x3, 0x40, 0x5, 0x40, 0x3d0, 0xa, 0x40, 0x3, 0x40, 
    0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x5, 0x40, 0x3d6, 0xa, 0x40, 0x3, 0x40, 
    0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 
    0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 
    0x5, 0x40, 0x3e6, 0xa, 0x40, 0x3, 0x40, 0x3, 0x40, 0x7, 0x40, 0x3ea, 
    0xa, 0x40, 0xc, 0x40, 0xe, 0x40, 0x3ed, 0xb, 0x40, 0x5, 0x40, 0x3ef, 
    0xa, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x5, 0x40, 0x3f4, 0xa, 0x40, 
    0x3, 0x40, 0x5, 0x40, 0x3f7, 0xa, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 
    0x3, 0x40, 0x3, 0x40, 0x5, 0x40, 0x3fe, 0xa, 0x40, 0x3, 0x40, 0x3, 0x40, 
    0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 
    0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 
    0x3, 0x40, 0x3, 0x40, 0x5, 0x40, 0x411, 0xa, 0x40, 0x3, 0x40, 0x3, 0x40, 
    0x7, 0x40, 0x415, 0xa, 0x40, 0xc, 0x40, 0xe, 0x40, 0x418, 0xb, 0x40, 
    0x7, 0x40, 0x41a, 0xa, 0x40, 0xc, 0x40, 0xe, 0x40, 0x41d, 0xb, 0x40, 
    0x3, 0x41, 0x3, 0x41, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 
    0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x5, 0x42, 
    0x42b, 0xa, 0x42, 0x3, 0x43, 0x3, 0x43, 0x5, 0x43, 0x42f, 0xa, 0x43, 
    0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x5, 0x43, 0x436, 
    0xa, 0x43, 0x3, 0x43, 0x7, 0x43, 0x439, 0xa, 0x43, 0xc, 0x43, 0xe, 0x43, 
    0x43c, 0xb, 0x43, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x45, 0x3, 0x45, 
    0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x7, 0x45, 0x446, 0xa, 0x45, 0xc, 0x45, 
    0xe, 0x45, 0x449, 0xb, 0x45, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 
    0x3, 0x46, 0x3, 0x46, 0x5, 0x46, 0x451, 0xa, 0x46, 0x3, 0x47, 0x3, 0x47, 
    0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x6, 0x47, 0x458, 0xa, 0x47, 0xd, 0x47, 
    0xe, 0x47, 0x459, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x48, 0x3, 0x48, 
    0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x5, 0x48, 0x466, 
    0xa, 0x48, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 
    0x49, 0x3, 0x49, 0x5, 0x49, 0x46f, 0xa, 0x49, 0x3, 0x49, 0x3, 0x49, 
    0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x5, 0x49, 0x477, 0xa, 0x49, 
    0x3, 0x4a, 0x3, 0x4a, 0x5, 0x4a, 0x47b, 0xa, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 
    0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x7, 0x4b, 0x484, 
    0xa, 0x4b, 0xc, 0x4b, 0xe, 0x4b, 0x487, 0xb, 0x4b, 0x3, 0x4c, 0x3, 0x4c, 
    0x5, 0x4c, 0x48b, 0xa, 0x4c, 0x3, 0x4d, 0x5, 0x4d, 0x48e, 0xa, 0x4d, 
    0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 
    0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x5, 0x4e, 0x499, 0xa, 0x4e, 0x3, 0x4e, 
    0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x5, 0x4e, 0x4a1, 
    0xa, 0x4e, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 
    0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 
    0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 
    0x4f, 0x3, 0x4f, 0x5, 0x4f, 0x4b7, 0xa, 0x4f, 0x3, 0x50, 0x3, 0x50, 
    0x3, 0x50, 0x5, 0x50, 0x4bc, 0xa, 0x50, 0x3, 0x50, 0x3, 0x50, 0x5, 0x50, 
    0x4c0, 0xa, 0x50, 0x3, 0x50, 0x5, 0x50, 0x4c3, 0xa, 0x50, 0x3, 0x50, 
    0x3, 0x50, 0x5, 0x50, 0x4c7, 0xa, 0x50, 0x3, 0x50, 0x3, 0x50, 0x5, 0x50, 
    0x4cb, 0xa, 0x50, 0x5, 0x50, 0x4cd, 0xa, 0x50, 0x3, 0x51, 0x3, 0x51, 
    0x3, 0x51, 0x3, 0x51, 0x5, 0x51, 0x4d3, 0xa, 0x51, 0x3, 0x52, 0x3, 0x52, 
    0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x7, 0x52, 0x4db, 0xa, 0x52, 
    0xc, 0x52, 0xe, 0x52, 0x4de, 0xb, 0x52, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 
    0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x5, 
    0x53, 0x4e9, 0xa, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 
    0x3, 0x53, 0x5, 0x53, 0x4f0, 0xa, 0x53, 0x3, 0x54, 0x3, 0x54, 0x5, 0x54, 
    0x4f4, 0xa, 0x54, 0x3, 0x54, 0x5, 0x54, 0x4f7, 0xa, 0x54, 0x3, 0x54, 
    0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x55, 0x3, 0x55, 0x3, 
    0x55, 0x5, 0x55, 0x501, 0xa, 0x55, 0x3, 0x55, 0x3, 0x55, 0x5, 0x55, 
    0x505, 0xa, 0x55, 0x3, 0x55, 0x3, 0x55, 0x5, 0x55, 0x509, 0xa, 0x55, 
    0x3, 0x55, 0x3, 0x55, 0x5, 0x55, 0x50d, 0xa, 0x55, 0x5, 0x55, 0x50f, 
    0xa, 0x55, 0x5, 0x55, 0x511, 0xa, 0x55, 0x5, 0x55, 0x513, 0xa, 0x55, 
    0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x7, 0x56, 0x518, 0xa, 0x56, 0xc, 0x56, 
    0xe, 0x56, 0x51b, 0xb, 0x56, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 
    0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 
    0x57, 0x3, 0x57, 0x3, 0x57, 0x5, 0x57, 0x52a, 0xa, 0x57, 0x3, 0x58, 
    0x3, 0x58, 0x3, 0x58, 0x7, 0x58, 0x52f, 0xa, 0x58, 0xc, 0x58, 0xe, 0x58, 
    0x532, 0xb, 0x58, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x7, 0x59, 0x537, 
    0xa, 0x59, 0xc, 0x59, 0xe, 0x59, 0x53a, 0xb, 0x59, 0x3, 0x5a, 0x3, 0x5a, 
    0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5c, 0x6, 
    0x5c, 0x544, 0xa, 0x5c, 0xd, 0x5c, 0xe, 0x5c, 0x545, 0x3, 0x5d, 0x5, 
    0x5d, 0x549, 0xa, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5e, 0x3, 0x5e, 
    0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x7, 0x5e, 0x552, 0xa, 0x5e, 0xc, 0x5e, 
    0xe, 0x5e, 0x555, 0xb, 0x5e, 0x3, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 
    0x5, 0x5f, 0x55b, 0xa, 0x5f, 0x3, 0x60, 0x5, 0x60, 0x55e, 0xa, 0x60, 
    0x3, 0x60, 0x3, 0x60, 0x5, 0x60, 0x562, 0xa, 0x60, 0x3, 0x60, 0x3, 0x60, 
    0x3, 0x61, 0x3, 0x61, 0x3, 0x61, 0x3, 0x61, 0x3, 0x61, 0x7, 0x61, 0x56b, 
    0xa, 0x61, 0xc, 0x61, 0xe, 0x61, 0x56e, 0xb, 0x61, 0x3, 0x61, 0x2, 0x20, 
    0x6, 0xa, 0xc, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 
    0x26, 0x2e, 0x3a, 0x40, 0x46, 0x4c, 0x52, 0x62, 0x70, 0x74, 0x78, 0x7e, 
    0x84, 0x88, 0x94, 0xa2, 0xba, 0xc0, 0x62, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 
    0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 
    0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 
    0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 
    0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 
    0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 
    0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 
    0x9e, 0xa0, 0xa2, 0xa4, 0xa6, 0xa8, 0xaa, 0xac, 0xae, 0xb0, 0xb2, 0xb4, 
    0xb6, 0xb8, 0xba, 0xbc, 0xbe, 0xc0, 0x2, 0xf, 0x4, 0x2, 0x6, 0x6, 0x38, 
    0x38, 0x7, 0x2, 0x4d, 0x4d, 0x4f, 0x4f, 0x51, 0x51, 0x54, 0x54, 0x59, 
    0x5a, 0x3, 0x2, 0x5f, 0x69, 0xa, 0x2, 0x7, 0x9, 0x17, 0x17, 0x1c, 0x1c, 
    0x20, 0x20, 0x25, 0x26, 0x2a, 0x2b, 0x33, 0x34, 0x3a, 0x3b, 0x3, 0x2, 
    0x7, 0x9, 0x4, 0x2, 0xa, 0xa, 0x31, 0x31, 0x4, 0x2, 0x2e, 0x2e, 0x32, 
    0x32, 0x7, 0x2, 0xb, 0xc, 0x18, 0x18, 0x28, 0x28, 0x35, 0x35, 0x39, 
    0x39, 0x5, 0x2, 0xd, 0xe, 0x24, 0x24, 0x3e, 0x3e, 0x3, 0x2, 0x10, 0x11, 
    0x4, 0x2, 0x41, 0x42, 0x5e, 0x5e, 0x3, 0x2, 0x41, 0x42, 0x4, 0x2, 0x10, 
    0x11, 0x13, 0x13, 0x2, 0x5ee, 0x2, 0xe3, 0x3, 0x2, 0x2, 0x2, 0x4, 0xe5, 
    0x3, 0x2, 0x2, 0x2, 0x6, 0xec, 0x3, 0x2, 0x2, 0x2, 0x8, 0xfe, 0x3, 0x2, 
    0x2, 0x2, 0xa, 0x122, 0x3, 0x2, 0x2, 0x2, 0xc, 0x13e, 0x3, 0x2, 0x2, 
    0x2, 0xe, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x10, 0x161, 0x3, 0x2, 0x2, 0x2, 
    0x12, 0x170, 0x3, 0x2, 0x2, 0x2, 0x14, 0x172, 0x3, 0x2, 0x2, 0x2, 0x16, 
    0x183, 0x3, 0x2, 0x2, 0x2, 0x18, 0x191, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x19f, 
    0x3, 0x2, 0x2, 0x2, 0x1c, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1c1, 0x3, 
    0x2, 0x2, 0x2, 0x20, 0x1cc, 0x3, 0x2, 0x2, 0x2, 0x22, 0x1d7, 0x3, 0x2, 
    0x2, 0x2, 0x24, 0x1e2, 0x3, 0x2, 0x2, 0x2, 0x26, 0x1ed, 0x3, 0x2, 0x2, 
    0x2, 0x28, 0x1f8, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x206, 0x3, 0x2, 0x2, 0x2, 
    0x2c, 0x208, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x30, 
    0x215, 0x3, 0x2, 0x2, 0x2, 0x32, 0x21f, 0x3, 0x2, 0x2, 0x2, 0x34, 0x222, 
    0x3, 0x2, 0x2, 0x2, 0x36, 0x227, 0x3, 0x2, 0x2, 0x2, 0x38, 0x230, 0x3, 
    0x2, 0x2, 0x2, 0x3a, 0x232, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x242, 0x3, 0x2, 
    0x2, 0x2, 0x3e, 0x24d, 0x3, 0x2, 0x2, 0x2, 0x40, 0x25e, 0x3, 0x2, 0x2, 
    0x2, 0x42, 0x274, 0x3, 0x2, 0x2, 0x2, 0x44, 0x276, 0x3, 0x2, 0x2, 0x2, 
    0x46, 0x278, 0x3, 0x2, 0x2, 0x2, 0x48, 0x289, 0x3, 0x2, 0x2, 0x2, 0x4a, 
    0x293, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x295, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x2a6, 
    0x3, 0x2, 0x2, 0x2, 0x50, 0x2bb, 0x3, 0x2, 0x2, 0x2, 0x52, 0x2bd, 0x3, 
    0x2, 0x2, 0x2, 0x54, 0x2cd, 0x3, 0x2, 0x2, 0x2, 0x56, 0x2cf, 0x3, 0x2, 
    0x2, 0x2, 0x58, 0x2d1, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x2d6, 0x3, 0x2, 0x2, 
    0x2, 0x5c, 0x2de, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x2ea, 0x3, 0x2, 0x2, 0x2, 
    0x60, 0x2ed, 0x3, 0x2, 0x2, 0x2, 0x62, 0x307, 0x3, 0x2, 0x2, 0x2, 0x64, 
    0x342, 0x3, 0x2, 0x2, 0x2, 0x66, 0x344, 0x3, 0x2, 0x2, 0x2, 0x68, 0x354, 
    0x3, 0x2, 0x2, 0x2, 0x6a, 0x35f, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x368, 0x3, 
    0x2, 0x2, 0x2, 0x6e, 0x37d, 0x3, 0x2, 0x2, 0x2, 0x70, 0x37f, 0x3, 0x2, 
    0x2, 0x2, 0x72, 0x38e, 0x3, 0x2, 0x2, 0x2, 0x74, 0x390, 0x3, 0x2, 0x2, 
    0x2, 0x76, 0x3a2, 0x3, 0x2, 0x2, 0x2, 0x78, 0x3a4, 0x3, 0x2, 0x2, 0x2, 
    0x7a, 0x3af, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x3be, 0x3, 0x2, 0x2, 0x2, 0x7e, 
    0x3ee, 0x3, 0x2, 0x2, 0x2, 0x80, 0x41e, 0x3, 0x2, 0x2, 0x2, 0x82, 0x42a, 
    0x3, 0x2, 0x2, 0x2, 0x84, 0x42c, 0x3, 0x2, 0x2, 0x2, 0x86, 0x43d, 0x3, 
    0x2, 0x2, 0x2, 0x88, 0x440, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x450, 0x3, 0x2, 
    0x2, 0x2, 0x8c, 0x452, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x465, 0x3, 0x2, 0x2, 
    0x2, 0x90, 0x476, 0x3, 0x2, 0x2, 0x2, 0x92, 0x478, 0x3, 0x2, 0x2, 0x2, 
    0x94, 0x47e, 0x3, 0x2, 0x2, 0x2, 0x96, 0x48a, 0x3, 0x2, 0x2, 0x2, 0x98, 
    0x48d, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x4a0, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x4b6, 
    0x3, 0x2, 0x2, 0x2, 0x9e, 0x4cc, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x4d2, 0x3, 
    0x2, 0x2, 0x2, 0xa2, 0x4d4, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x4ef, 0x3, 0x2, 
    0x2, 0x2, 0xa6, 0x4f1, 0x3, 0x2, 0x2, 0x2, 0xa8, 0x4fd, 0x3, 0x2, 0x2, 
    0x2, 0xaa, 0x514, 0x3, 0x2, 0x2, 0x2, 0xac, 0x529, 0x3, 0x2, 0x2, 0x2, 
    0xae, 0x52b, 0x3, 0x2, 0x2, 0x2, 0xb0, 0x533, 0x3, 0x2, 0x2, 0x2, 0xb2, 
    0x53b, 0x3, 0x2, 0x2, 0x2, 0xb4, 0x53d, 0x3, 0x2, 0x2, 0x2, 0xb6, 0x543, 
    0x3, 0x2, 0x2, 0x2, 0xb8, 0x548, 0x3, 0x2, 0x2, 0x2, 0xba, 0x54c, 0x3, 
    0x2, 0x2, 0x2, 0xbc, 0x55a, 0x3, 0x2, 0x2, 0x2, 0xbe, 0x55d, 0x3, 0x2, 
    0x2, 0x2, 0xc0, 0x565, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xe4, 0x7, 0x6f, 0x2, 
    0x2, 0xc3, 0xe4, 0x7, 0x70, 0x2, 0x2, 0xc4, 0xc6, 0x7, 0x72, 0x2, 0x2, 
    0xc5, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc7, 
    0xc5, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xe4, 
    0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0x7, 0x41, 0x2, 0x2, 0xca, 0xcb, 0x5, 
    0x2e, 0x18, 0x2, 0xcb, 0xcc, 0x7, 0x42, 0x2, 0x2, 0xcc, 0xe4, 0x3, 0x2, 
    0x2, 0x2, 0xcd, 0xe4, 0x5, 0x4, 0x3, 0x2, 0xce, 0xd0, 0x7, 0x3, 0x2, 
    0x2, 0xcf, 0xce, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd0, 0x3, 0x2, 0x2, 0x2, 
    0xd0, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x7, 0x41, 0x2, 0x2, 0xd2, 
    0xd3, 0x5, 0x92, 0x4a, 0x2, 0xd3, 0xd4, 0x7, 0x42, 0x2, 0x2, 0xd4, 0xe4, 
    0x3, 0x2, 0x2, 0x2, 0xd5, 0xd6, 0x7, 0x4, 0x2, 0x2, 0xd6, 0xd7, 0x7, 
    0x41, 0x2, 0x2, 0xd7, 0xd8, 0x5, 0xe, 0x8, 0x2, 0xd8, 0xd9, 0x7, 0x5e, 
    0x2, 0x2, 0xd9, 0xda, 0x5, 0x7a, 0x3e, 0x2, 0xda, 0xdb, 0x7, 0x42, 0x2, 
    0x2, 0xdb, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 0x7, 0x5, 0x2, 0x2, 
    0xdd, 0xde, 0x7, 0x41, 0x2, 0x2, 0xde, 0xdf, 0x5, 0x7a, 0x3e, 0x2, 0xdf, 
    0xe0, 0x7, 0x5e, 0x2, 0x2, 0xe0, 0xe1, 0x5, 0xe, 0x8, 0x2, 0xe1, 0xe2, 
    0x7, 0x42, 0x2, 0x2, 0xe2, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xc2, 0x3, 
    0x2, 0x2, 0x2, 0xe3, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xc5, 0x3, 0x2, 
    0x2, 0x2, 0xe3, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xcd, 0x3, 0x2, 0x2, 
    0x2, 0xe3, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xd5, 0x3, 0x2, 0x2, 0x2, 
    0xe3, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xe4, 0x3, 0x3, 0x2, 0x2, 0x2, 0xe5, 
    0xe6, 0x7, 0x3c, 0x2, 0x2, 0xe6, 0xe7, 0x7, 0x41, 0x2, 0x2, 0xe7, 0xe8, 
    0x5, 0x2a, 0x16, 0x2, 0xe8, 0xe9, 0x7, 0x5e, 0x2, 0x2, 0xe9, 0xea, 0x5, 
    0x6, 0x4, 0x2, 0xea, 0xeb, 0x7, 0x42, 0x2, 0x2, 0xeb, 0x5, 0x3, 0x2, 
    0x2, 0x2, 0xec, 0xed, 0x8, 0x4, 0x1, 0x2, 0xed, 0xee, 0x5, 0x8, 0x5, 
    0x2, 0xee, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf0, 0xc, 0x3, 0x2, 0x2, 
    0xf0, 0xf1, 0x7, 0x5e, 0x2, 0x2, 0xf1, 0xf3, 0x5, 0x8, 0x5, 0x2, 0xf2, 
    0xef, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf2, 
    0x3, 0x2, 0x2, 0x2, 0xf4, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf5, 0x7, 0x3, 
    0x2, 0x2, 0x2, 0xf6, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf8, 0x5, 0x7a, 
    0x3e, 0x2, 0xf8, 0xf9, 0x7, 0x5c, 0x2, 0x2, 0xf9, 0xfa, 0x5, 0x2a, 0x16, 
    0x2, 0xfa, 0xff, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfc, 0x7, 0x1a, 0x2, 0x2, 
    0xfc, 0xfd, 0x7, 0x5c, 0x2, 0x2, 0xfd, 0xff, 0x5, 0x2a, 0x16, 0x2, 0xfe, 
    0xf7, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xff, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0x100, 0x101, 0x8, 0x6, 0x1, 0x2, 0x101, 0x123, 
    0x5, 0x2, 0x2, 0x2, 0x102, 0x103, 0x7, 0x41, 0x2, 0x2, 0x103, 0x104, 
    0x5, 0x7a, 0x3e, 0x2, 0x104, 0x105, 0x7, 0x42, 0x2, 0x2, 0x105, 0x106, 
    0x7, 0x45, 0x2, 0x2, 0x106, 0x107, 0x5, 0x84, 0x43, 0x2, 0x107, 0x108, 
    0x7, 0x46, 0x2, 0x2, 0x108, 0x123, 0x3, 0x2, 0x2, 0x2, 0x109, 0x10a, 
    0x7, 0x41, 0x2, 0x2, 0x10a, 0x10b, 0x5, 0x7a, 0x3e, 0x2, 0x10b, 0x10c, 
    0x7, 0x42, 0x2, 0x2, 0x10c, 0x10d, 0x7, 0x45, 0x2, 0x2, 0x10d, 0x10e, 
    0x5, 0x84, 0x43, 0x2, 0x10e, 0x10f, 0x7, 0x5e, 0x2, 0x2, 0x10f, 0x110, 
    0x7, 0x46, 0x2, 0x2, 0x110, 0x123, 0x3, 0x2, 0x2, 0x2, 0x111, 0x112, 
    0x7, 0x3, 0x2, 0x2, 0x112, 0x113, 0x7, 0x41, 0x2, 0x2, 0x113, 0x114, 
    0x5, 0x7a, 0x3e, 0x2, 0x114, 0x115, 0x7, 0x42, 0x2, 0x2, 0x115, 0x116, 
    0x7, 0x45, 0x2, 0x2, 0x116, 0x117, 0x5, 0x84, 0x43, 0x2, 0x117, 0x118, 
    0x7, 0x46, 0x2, 0x2, 0x118, 0x123, 0x3, 0x2, 0x2, 0x2, 0x119, 0x11a, 
    0x7, 0x3, 0x2, 0x2, 0x11a, 0x11b, 0x7, 0x41, 0x2, 0x2, 0x11b, 0x11c, 
    0x5, 0x7a, 0x3e, 0x2, 0x11c, 0x11d, 0x7, 0x42, 0x2, 0x2, 0x11d, 0x11e, 
    0x7, 0x45, 0x2, 0x2, 0x11e, 0x11f, 0x5, 0x84, 0x43, 0x2, 0x11f, 0x120, 
    0x7, 0x5e, 0x2, 0x2, 0x120, 0x121, 0x7, 0x46, 0x2, 0x2, 0x121, 0x123, 
    0x3, 0x2, 0x2, 0x2, 0x122, 0x100, 0x3, 0x2, 0x2, 0x2, 0x122, 0x102, 
    0x3, 0x2, 0x2, 0x2, 0x122, 0x109, 0x3, 0x2, 0x2, 0x2, 0x122, 0x111, 
    0x3, 0x2, 0x2, 0x2, 0x122, 0x119, 0x3, 0x2, 0x2, 0x2, 0x123, 0x13b, 
    0x3, 0x2, 0x2, 0x2, 0x124, 0x125, 0xc, 0xc, 0x2, 0x2, 0x125, 0x126, 
    0x7, 0x43, 0x2, 0x2, 0x126, 0x127, 0x5, 0x2e, 0x18, 0x2, 0x127, 0x128, 
    0x7, 0x44, 0x2, 0x2, 0x128, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x129, 0x12a, 
    0xc, 0xb, 0x2, 0x2, 0x12a, 0x12c, 0x7, 0x41, 0x2, 0x2, 0x12b, 0x12d, 
    0x5, 0xc, 0x7, 0x2, 0x12c, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12d, 
    0x3, 0x2, 0x2, 0x2, 0x12d, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x13a, 
    0x7, 0x42, 0x2, 0x2, 0x12f, 0x130, 0xc, 0xa, 0x2, 0x2, 0x130, 0x131, 
    0x7, 0x6d, 0x2, 0x2, 0x131, 0x13a, 0x7, 0x6f, 0x2, 0x2, 0x132, 0x133, 
    0xc, 0x9, 0x2, 0x2, 0x133, 0x134, 0x7, 0x6c, 0x2, 0x2, 0x134, 0x13a, 
    0x7, 0x6f, 0x2, 0x2, 0x135, 0x136, 0xc, 0x8, 0x2, 0x2, 0x136, 0x13a, 
    0x7, 0x4e, 0x2, 0x2, 0x137, 0x138, 0xc, 0x7, 0x2, 0x2, 0x138, 0x13a, 
    0x7, 0x50, 0x2, 0x2, 0x139, 0x124, 0x3, 0x2, 0x2, 0x2, 0x139, 0x129, 
    0x3, 0x2, 0x2, 0x2, 0x139, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x139, 0x132, 
    0x3, 0x2, 0x2, 0x2, 0x139, 0x135, 0x3, 0x2, 0x2, 0x2, 0x139, 0x137, 
    0x3, 0x2, 0x2, 0x2, 0x13a, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x139, 
    0x3, 0x2, 0x2, 0x2, 0x13b, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x13c, 0xb, 0x3, 
    0x2, 0x2, 0x2, 0x13d, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x13f, 0x8, 
    0x7, 0x1, 0x2, 0x13f, 0x140, 0x5, 0x2a, 0x16, 0x2, 0x140, 0x146, 0x3, 
    0x2, 0x2, 0x2, 0x141, 0x142, 0xc, 0x3, 0x2, 0x2, 0x142, 0x143, 0x7, 
    0x5e, 0x2, 0x2, 0x143, 0x145, 0x5, 0x2a, 0x16, 0x2, 0x144, 0x141, 0x3, 
    0x2, 0x2, 0x2, 0x145, 0x148, 0x3, 0x2, 0x2, 0x2, 0x146, 0x144, 0x3, 
    0x2, 0x2, 0x2, 0x146, 0x147, 0x3, 0x2, 0x2, 0x2, 0x147, 0xd, 0x3, 0x2, 
    0x2, 0x2, 0x148, 0x146, 0x3, 0x2, 0x2, 0x2, 0x149, 0x160, 0x5, 0xa, 
    0x6, 0x2, 0x14a, 0x14b, 0x7, 0x4e, 0x2, 0x2, 0x14b, 0x160, 0x5, 0xe, 
    0x8, 0x2, 0x14c, 0x14d, 0x7, 0x50, 0x2, 0x2, 0x14d, 0x160, 0x5, 0xe, 
    0x8, 0x2, 0x14e, 0x14f, 0x5, 0x10, 0x9, 0x2, 0x14f, 0x150, 0x5, 0x12, 
    0xa, 0x2, 0x150, 0x160, 0x3, 0x2, 0x2, 0x2, 0x151, 0x152, 0x7, 0x2c, 
    0x2, 0x2, 0x152, 0x160, 0x5, 0xe, 0x8, 0x2, 0x153, 0x154, 0x7, 0x2c, 
    0x2, 0x2, 0x154, 0x155, 0x7, 0x41, 0x2, 0x2, 0x155, 0x156, 0x5, 0x7a, 
    0x3e, 0x2, 0x156, 0x157, 0x7, 0x42, 0x2, 0x2, 0x157, 0x160, 0x3, 0x2, 
    0x2, 0x2, 0x158, 0x159, 0x9, 0x2, 0x2, 0x2, 0x159, 0x15a, 0x7, 0x41, 
    0x2, 0x2, 0x15a, 0x15b, 0x5, 0x7a, 0x3e, 0x2, 0x15b, 0x15c, 0x7, 0x42, 
    0x2, 0x2, 0x15c, 0x160, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x15e, 0x7, 0x56, 
    0x2, 0x2, 0x15e, 0x160, 0x7, 0x6f, 0x2, 0x2, 0x15f, 0x149, 0x3, 0x2, 
    0x2, 0x2, 0x15f, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x14c, 0x3, 0x2, 
    0x2, 0x2, 0x15f, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x151, 0x3, 0x2, 
    0x2, 0x2, 0x15f, 0x153, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x158, 0x3, 0x2, 
    0x2, 0x2, 0x15f, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x160, 0xf, 0x3, 0x2, 0x2, 
    0x2, 0x161, 0x162, 0x9, 0x3, 0x2, 0x2, 0x162, 0x11, 0x3, 0x2, 0x2, 0x2, 
    0x163, 0x164, 0x7, 0x41, 0x2, 0x2, 0x164, 0x165, 0x5, 0x7a, 0x3e, 0x2, 
    0x165, 0x166, 0x7, 0x42, 0x2, 0x2, 0x166, 0x167, 0x5, 0x12, 0xa, 0x2, 
    0x167, 0x171, 0x3, 0x2, 0x2, 0x2, 0x168, 0x169, 0x7, 0x3, 0x2, 0x2, 
    0x169, 0x16a, 0x7, 0x41, 0x2, 0x2, 0x16a, 0x16b, 0x5, 0x7a, 0x3e, 0x2, 
    0x16b, 0x16c, 0x7, 0x42, 0x2, 0x2, 0x16c, 0x16d, 0x5, 0x12, 0xa, 0x2, 
    0x16d, 0x171, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x171, 0x5, 0xe, 0x8, 0x2, 
    0x16f, 0x171, 0x7, 0x71, 0x2, 0x2, 0x170, 0x163, 0x3, 0x2, 0x2, 0x2, 
    0x170, 0x168, 0x3, 0x2, 0x2, 0x2, 0x170, 0x16e, 0x3, 0x2, 0x2, 0x2, 
    0x170, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x171, 0x13, 0x3, 0x2, 0x2, 0x2, 0x172, 
    0x173, 0x8, 0xb, 0x1, 0x2, 0x173, 0x174, 0x5, 0x12, 0xa, 0x2, 0x174, 
    0x180, 0x3, 0x2, 0x2, 0x2, 0x175, 0x176, 0xc, 0x5, 0x2, 0x2, 0x176, 
    0x177, 0x7, 0x51, 0x2, 0x2, 0x177, 0x17f, 0x5, 0x12, 0xa, 0x2, 0x178, 
    0x179, 0xc, 0x4, 0x2, 0x2, 0x179, 0x17a, 0x7, 0x52, 0x2, 0x2, 0x17a, 
    0x17f, 0x5, 0x12, 0xa, 0x2, 0x17b, 0x17c, 0xc, 0x3, 0x2, 0x2, 0x17c, 
    0x17d, 0x7, 0x53, 0x2, 0x2, 0x17d, 0x17f, 0x5, 0x12, 0xa, 0x2, 0x17e, 
    0x175, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x178, 0x3, 0x2, 0x2, 0x2, 0x17e, 
    0x17b, 0x3, 0x2, 0x2, 0x2, 0x17f, 0x182, 0x3, 0x2, 0x2, 0x2, 0x180, 
    0x17e, 0x3, 0x2, 0x2, 0x2, 0x180, 0x181, 0x3, 0x2, 0x2, 0x2, 0x181, 
    0x15, 0x3, 0x2, 0x2, 0x2, 0x182, 0x180, 0x3, 0x2, 0x2, 0x2, 0x183, 0x184, 
    0x8, 0xc, 0x1, 0x2, 0x184, 0x185, 0x5, 0x14, 0xb, 0x2, 0x185, 0x18e, 
    0x3, 0x2, 0x2, 0x2, 0x186, 0x187, 0xc, 0x4, 0x2, 0x2, 0x187, 0x188, 
    0x7, 0x4d, 0x2, 0x2, 0x188, 0x18d, 0x5, 0x14, 0xb, 0x2, 0x189, 0x18a, 
    0xc, 0x3, 0x2, 0x2, 0x18a, 0x18b, 0x7, 0x4f, 0x2, 0x2, 0x18b, 0x18d, 
    0x5, 0x14, 0xb, 0x2, 0x18c, 0x186, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x189, 
    0x3, 0x2, 0x2, 0x2, 0x18d, 0x190, 0x3, 0x2, 0x2, 0x2, 0x18e, 0x18c, 
    0x3, 0x2, 0x2, 0x2, 0x18e, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x17, 0x3, 
    0x2, 0x2, 0x2, 0x190, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x191, 0x192, 0x8, 
    0xd, 0x1, 0x2, 0x192, 0x193, 0x5, 0x16, 0xc, 0x2, 0x193, 0x19c, 0x3, 
    0x2, 0x2, 0x2, 0x194, 0x195, 0xc, 0x4, 0x2, 0x2, 0x195, 0x196, 0x7, 
    0x4b, 0x2, 0x2, 0x196, 0x19b, 0x5, 0x16, 0xc, 0x2, 0x197, 0x198, 0xc, 
    0x3, 0x2, 0x2, 0x198, 0x199, 0x7, 0x4c, 0x2, 0x2, 0x199, 0x19b, 0x5, 
    0x16, 0xc, 0x2, 0x19a, 0x194, 0x3, 0x2, 0x2, 0x2, 0x19a, 0x197, 0x3, 
    0x2, 0x2, 0x2, 0x19b, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x19a, 0x3, 
    0x2, 0x2, 0x2, 0x19c, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x19, 0x3, 0x2, 
    0x2, 0x2, 0x19e, 0x19c, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a0, 0x8, 0xe, 
    0x1, 0x2, 0x1a0, 0x1a1, 0x5, 0x18, 0xd, 0x2, 0x1a1, 0x1b0, 0x3, 0x2, 
    0x2, 0x2, 0x1a2, 0x1a3, 0xc, 0x6, 0x2, 0x2, 0x1a3, 0x1a4, 0x7, 0x47, 
    0x2, 0x2, 0x1a4, 0x1af, 0x5, 0x18, 0xd, 0x2, 0x1a5, 0x1a6, 0xc, 0x5, 
    0x2, 0x2, 0x1a6, 0x1a7, 0x7, 0x49, 0x2, 0x2, 0x1a7, 0x1af, 0x5, 0x18, 
    0xd, 0x2, 0x1a8, 0x1a9, 0xc, 0x4, 0x2, 0x2, 0x1a9, 0x1aa, 0x7, 0x48, 
    0x2, 0x2, 0x1aa, 0x1af, 0x5, 0x18, 0xd, 0x2, 0x1ab, 0x1ac, 0xc, 0x3, 
    0x2, 0x2, 0x1ac, 0x1ad, 0x7, 0x4a, 0x2, 0x2, 0x1ad, 0x1af, 0x5, 0x18, 
    0xd, 0x2, 0x1ae, 0x1a2, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1a5, 0x3, 0x2, 
    0x2, 0x2, 0x1ae, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1ab, 0x3, 0x2, 
    0x2, 0x2, 0x1af, 0x1b2, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1ae, 0x3, 0x2, 
    0x2, 0x2, 0x1b0, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1b, 0x3, 0x2, 0x2, 
    0x2, 0x1b2, 0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b4, 0x8, 0xf, 0x1, 
    0x2, 0x1b4, 0x1b5, 0x5, 0x1a, 0xe, 0x2, 0x1b5, 0x1be, 0x3, 0x2, 0x2, 
    0x2, 0x1b6, 0x1b7, 0xc, 0x4, 0x2, 0x2, 0x1b7, 0x1b8, 0x7, 0x6a, 0x2, 
    0x2, 0x1b8, 0x1bd, 0x5, 0x1a, 0xe, 0x2, 0x1b9, 0x1ba, 0xc, 0x3, 0x2, 
    0x2, 0x1ba, 0x1bb, 0x7, 0x6b, 0x2, 0x2, 0x1bb, 0x1bd, 0x5, 0x1a, 0xe, 
    0x2, 0x1bc, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x1bc, 0x1b9, 0x3, 0x2, 0x2, 
    0x2, 0x1bd, 0x1c0, 0x3, 0x2, 0x2, 0x2, 0x1be, 0x1bc, 0x3, 0x2, 0x2, 
    0x2, 0x1be, 0x1bf, 0x3, 0x2, 0x2, 0x2, 0x1bf, 0x1d, 0x3, 0x2, 0x2, 0x2, 
    0x1c0, 0x1be, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1c2, 0x8, 0x10, 0x1, 0x2, 
    0x1c2, 0x1c3, 0x5, 0x1c, 0xf, 0x2, 0x1c3, 0x1c9, 0x3, 0x2, 0x2, 0x2, 
    0x1c4, 0x1c5, 0xc, 0x3, 0x2, 0x2, 0x1c5, 0x1c6, 0x7, 0x54, 0x2, 0x2, 
    0x1c6, 0x1c8, 0x5, 0x1c, 0xf, 0x2, 0x1c7, 0x1c4, 0x3, 0x2, 0x2, 0x2, 
    0x1c8, 0x1cb, 0x3, 0x2, 0x2, 0x2, 0x1c9, 0x1c7, 0x3, 0x2, 0x2, 0x2, 
    0x1c9, 0x1ca, 0x3, 0x2, 0x2, 0x2, 0x1ca, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1cb, 
    0x1c9, 0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1cd, 0x8, 0x11, 0x1, 0x2, 0x1cd, 
    0x1ce, 0x5, 0x1e, 0x10, 0x2, 0x1ce, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1cf, 
    0x1d0, 0xc, 0x3, 0x2, 0x2, 0x1d0, 0x1d1, 0x7, 0x58, 0x2, 0x2, 0x1d1, 
    0x1d3, 0x5, 0x1e, 0x10, 0x2, 0x1d2, 0x1cf, 0x3, 0x2, 0x2, 0x2, 0x1d3, 
    0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x1d2, 0x3, 0x2, 0x2, 0x2, 0x1d4, 
    0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d5, 0x21, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1d4, 
    0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1d8, 0x8, 0x12, 0x1, 0x2, 0x1d8, 0x1d9, 
    0x5, 0x20, 0x11, 0x2, 0x1d9, 0x1df, 0x3, 0x2, 0x2, 0x2, 0x1da, 0x1db, 
    0xc, 0x3, 0x2, 0x2, 0x1db, 0x1dc, 0x7, 0x55, 0x2, 0x2, 0x1dc, 0x1de, 
    0x5, 0x20, 0x11, 0x2, 0x1dd, 0x1da, 0x3, 0x2, 0x2, 0x2, 0x1de, 0x1e1, 
    0x3, 0x2, 0x2, 0x2, 0x1df, 0x1dd, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x1e0, 
    0x3, 0x2, 0x2, 0x2, 0x1e0, 0x23, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1df, 0x3, 
    0x2, 0x2, 0x2, 0x1e2, 0x1e3, 0x8, 0x13, 0x1, 0x2, 0x1e3, 0x1e4, 0x5, 
    0x22, 0x12, 0x2, 0x1e4, 0x1ea, 0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1e6, 0xc, 
    0x3, 0x2, 0x2, 0x1e6, 0x1e7, 0x7, 0x56, 0x2, 0x2, 0x1e7, 0x1e9, 0x5, 
    0x22, 0x12, 0x2, 0x1e8, 0x1e5, 0x3, 0x2, 0x2, 0x2, 0x1e9, 0x1ec, 0x3, 
    0x2, 0x2, 0x2, 0x1ea, 0x1e8, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1eb, 0x3, 
    0x2, 0x2, 0x2, 0x1eb, 0x25, 0x3, 0x2, 0x2, 0x2, 0x1ec, 0x1ea, 0x3, 0x2, 
    0x2, 0x2, 0x1ed, 0x1ee, 0x8, 0x14, 0x1, 0x2, 0x1ee, 0x1ef, 0x5, 0x24, 
    0x13, 0x2, 0x1ef, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1f0, 0x1f1, 0xc, 0x3, 
    0x2, 0x2, 0x1f1, 0x1f2, 0x7, 0x57, 0x2, 0x2, 0x1f2, 0x1f4, 0x5, 0x24, 
    0x13, 0x2, 0x1f3, 0x1f0, 0x3, 0x2, 0x2, 0x2, 0x1f4, 0x1f7, 0x3, 0x2, 
    0x2, 0x2, 0x1f5, 0x1f3, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1f6, 0x3, 0x2, 
    0x2, 0x2, 0x1f6, 0x27, 0x3, 0x2, 0x2, 0x2, 0x1f7, 0x1f5, 0x3, 0x2, 0x2, 
    0x2, 0x1f8, 0x1fe, 0x5, 0x26, 0x14, 0x2, 0x1f9, 0x1fa, 0x7, 0x5b, 0x2, 
    0x2, 0x1fa, 0x1fb, 0x5, 0x2e, 0x18, 0x2, 0x1fb, 0x1fc, 0x7, 0x5c, 0x2, 
    0x2, 0x1fc, 0x1fd, 0x5, 0x28, 0x15, 0x2, 0x1fd, 0x1ff, 0x3, 0x2, 0x2, 
    0x2, 0x1fe, 0x1f9, 0x3, 0x2, 0x2, 0x2, 0x1fe, 0x1ff, 0x3, 0x2, 0x2, 
    0x2, 0x1ff, 0x29, 0x3, 0x2, 0x2, 0x2, 0x200, 0x207, 0x5, 0x28, 0x15, 
    0x2, 0x201, 0x202, 0x5, 0xe, 0x8, 0x2, 0x202, 0x203, 0x5, 0x2c, 0x17, 
    0x2, 0x203, 0x204, 0x5, 0x2a, 0x16, 0x2, 0x204, 0x207, 0x3, 0x2, 0x2, 
    0x2, 0x205, 0x207, 0x7, 0x71, 0x2, 0x2, 0x206, 0x200, 0x3, 0x2, 0x2, 
    0x2, 0x206, 0x201, 0x3, 0x2, 0x2, 0x2, 0x206, 0x205, 0x3, 0x2, 0x2, 
    0x2, 0x207, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x208, 0x209, 0x9, 0x4, 0x2, 0x2, 
    0x209, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x20a, 0x20b, 0x8, 0x18, 0x1, 0x2, 
    0x20b, 0x20c, 0x5, 0x2a, 0x16, 0x2, 0x20c, 0x212, 0x3, 0x2, 0x2, 0x2, 
    0x20d, 0x20e, 0xc, 0x3, 0x2, 0x2, 0x20e, 0x20f, 0x7, 0x5e, 0x2, 0x2, 
    0x20f, 0x211, 0x5, 0x2a, 0x16, 0x2, 0x210, 0x20d, 0x3, 0x2, 0x2, 0x2, 
    0x211, 0x214, 0x3, 0x2, 0x2, 0x2, 0x212, 0x210, 0x3, 0x2, 0x2, 0x2, 
    0x212, 0x213, 0x3, 0x2, 0x2, 0x2, 0x213, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x214, 
    0x212, 0x3, 0x2, 0x2, 0x2, 0x215, 0x216, 0x5, 0x28, 0x15, 0x2, 0x216, 
    0x31, 0x3, 0x2, 0x2, 0x2, 0x217, 0x218, 0x5, 0x34, 0x1b, 0x2, 0x218, 
    0x219, 0x5, 0x3a, 0x1e, 0x2, 0x219, 0x21a, 0x7, 0x5d, 0x2, 0x2, 0x21a, 
    0x220, 0x3, 0x2, 0x2, 0x2, 0x21b, 0x21c, 0x5, 0x34, 0x1b, 0x2, 0x21c, 
    0x21d, 0x7, 0x5d, 0x2, 0x2, 0x21d, 0x220, 0x3, 0x2, 0x2, 0x2, 0x21e, 
    0x220, 0x5, 0x8c, 0x47, 0x2, 0x21f, 0x217, 0x3, 0x2, 0x2, 0x2, 0x21f, 
    0x21b, 0x3, 0x2, 0x2, 0x2, 0x21f, 0x21e, 0x3, 0x2, 0x2, 0x2, 0x220, 
    0x33, 0x3, 0x2, 0x2, 0x2, 0x221, 0x223, 0x5, 0x38, 0x1d, 0x2, 0x222, 
    0x221, 0x3, 0x2, 0x2, 0x2, 0x223, 0x224, 0x3, 0x2, 0x2, 0x2, 0x224, 
    0x222, 0x3, 0x2, 0x2, 0x2, 0x224, 0x225, 0x3, 0x2, 0x2, 0x2, 0x225, 
    0x35, 0x3, 0x2, 0x2, 0x2, 0x226, 0x228, 0x5, 0x38, 0x1d, 0x2, 0x227, 
    0x226, 0x3, 0x2, 0x2, 0x2, 0x228, 0x229, 0x3, 0x2, 0x2, 0x2, 0x229, 
    0x227, 0x3, 0x2, 0x2, 0x2, 0x229, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x22a, 
    0x37, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x231, 0x5, 0x3e, 0x20, 0x2, 0x22c, 
    0x231, 0x5, 0x40, 0x21, 0x2, 0x22d, 0x231, 0x5, 0x5a, 0x2e, 0x2, 0x22e, 
    0x231, 0x5, 0x5c, 0x2f, 0x2, 0x22f, 0x231, 0x5, 0x5e, 0x30, 0x2, 0x230, 
    0x22b, 0x3, 0x2, 0x2, 0x2, 0x230, 0x22c, 0x3, 0x2, 0x2, 0x2, 0x230, 
    0x22d, 0x3, 0x2, 0x2, 0x2, 0x230, 0x22e, 0x3, 0x2, 0x2, 0x2, 0x230, 
    0x22f, 0x3, 0x2, 0x2, 0x2, 0x231, 0x39, 0x3, 0x2, 0x2, 0x2, 0x232, 0x233, 
    0x8, 0x1e, 0x1, 0x2, 0x233, 0x234, 0x5, 0x3c, 0x1f, 0x2, 0x234, 0x23a, 
    0x3, 0x2, 0x2, 0x2, 0x235, 0x236, 0xc, 0x3, 0x2, 0x2, 0x236, 0x237, 
    0x7, 0x5e, 0x2, 0x2, 0x237, 0x239, 0x5, 0x3c, 0x1f, 0x2, 0x238, 0x235, 
    0x3, 0x2, 0x2, 0x2, 0x239, 0x23c, 0x3, 0x2, 0x2, 0x2, 0x23a, 0x238, 
    0x3, 0x2, 0x2, 0x2, 0x23a, 0x23b, 0x3, 0x2, 0x2, 0x2, 0x23b, 0x3b, 0x3, 
    0x2, 0x2, 0x2, 0x23c, 0x23a, 0x3, 0x2, 0x2, 0x2, 0x23d, 0x243, 0x5, 
    0x60, 0x31, 0x2, 0x23e, 0x23f, 0x5, 0x60, 0x31, 0x2, 0x23f, 0x240, 0x7, 
    0x5f, 0x2, 0x2, 0x240, 0x241, 0x5, 0x82, 0x42, 0x2, 0x241, 0x243, 0x3, 
    0x2, 0x2, 0x2, 0x242, 0x23d, 0x3, 0x2, 0x2, 0x2, 0x242, 0x23e, 0x3, 
    0x2, 0x2, 0x2, 0x243, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x244, 0x246, 0x7, 0x3, 
    0x2, 0x2, 0x245, 0x244, 0x3, 0x2, 0x2, 0x2, 0x245, 0x246, 0x3, 0x2, 
    0x2, 0x2, 0x246, 0x247, 0x3, 0x2, 0x2, 0x2, 0x247, 0x24e, 0x7, 0x30, 
    0x2, 0x2, 0x248, 0x24e, 0x7, 0x1f, 0x2, 0x2, 0x249, 0x24e, 0x7, 0x2d, 
    0x2, 0x2, 0x24a, 0x24e, 0x7, 0x40, 0x2, 0x2, 0x24b, 0x24e, 0x7, 0x14, 
    0x2, 0x2, 0x24c, 0x24e, 0x7, 0x27, 0x2, 0x2, 0x24d, 0x245, 0x3, 0x2, 
    0x2, 0x2, 0x24d, 0x248, 0x3, 0x2, 0x2, 0x2, 0x24d, 0x249, 0x3, 0x2, 
    0x2, 0x2, 0x24d, 0x24a, 0x3, 0x2, 0x2, 0x2, 0x24d, 0x24b, 0x3, 0x2, 
    0x2, 0x2, 0x24d, 0x24c, 0x3, 0x2, 0x2, 0x2, 0x24e, 0x3f, 0x3, 0x2, 0x2, 
    0x2, 0x24f, 0x250, 0x8, 0x21, 0x1, 0x2, 0x250, 0x25f, 0x9, 0x5, 0x2, 
    0x2, 0x251, 0x252, 0x7, 0x3, 0x2, 0x2, 0x252, 0x253, 0x7, 0x41, 0x2, 
    0x2, 0x253, 0x254, 0x9, 0x6, 0x2, 0x2, 0x254, 0x25f, 0x7, 0x42, 0x2, 
    0x2, 0x255, 0x25f, 0x5, 0x58, 0x2d, 0x2, 0x256, 0x25f, 0x5, 0x42, 0x22, 
    0x2, 0x257, 0x25f, 0x5, 0x50, 0x29, 0x2, 0x258, 0x25f, 0x5, 0x80, 0x41, 
    0x2, 0x259, 0x25a, 0x9, 0x7, 0x2, 0x2, 0x25a, 0x25b, 0x7, 0x41, 0x2, 
    0x2, 0x25b, 0x25c, 0x5, 0x30, 0x19, 0x2, 0x25c, 0x25d, 0x7, 0x42, 0x2, 
    0x2, 0x25d, 0x25f, 0x3, 0x2, 0x2, 0x2, 0x25e, 0x24f, 0x3, 0x2, 0x2, 
    0x2, 0x25e, 0x251, 0x3, 0x2, 0x2, 0x2, 0x25e, 0x255, 0x3, 0x2, 0x2, 
    0x2, 0x25e, 0x256, 0x3, 0x2, 0x2, 0x2, 0x25e, 0x257, 0x3, 0x2, 0x2, 
    0x2, 0x25e, 0x258, 0x3, 0x2, 0x2, 0x2, 0x25e, 0x259, 0x3, 0x2, 0x2, 
    0x2, 0x25f, 0x264, 0x3, 0x2, 0x2, 0x2, 0x260, 0x261, 0xc, 0x3, 0x2, 
    0x2, 0x261, 0x263, 0x5, 0x6e, 0x38, 0x2, 0x262, 0x260, 0x3, 0x2, 0x2, 
    0x2, 0x263, 0x266, 0x3, 0x2, 0x2, 0x2, 0x264, 0x262, 0x3, 0x2, 0x2, 
    0x2, 0x264, 0x265, 0x3, 0x2, 0x2, 0x2, 0x265, 0x41, 0x3, 0x2, 0x2, 0x2, 
    0x266, 0x264, 0x3, 0x2, 0x2, 0x2, 0x267, 0x269, 0x5, 0x44, 0x23, 0x2, 
    0x268, 0x26a, 0x7, 0x6f, 0x2, 0x2, 0x269, 0x268, 0x3, 0x2, 0x2, 0x2, 
    0x269, 0x26a, 0x3, 0x2, 0x2, 0x2, 0x26a, 0x26b, 0x3, 0x2, 0x2, 0x2, 
    0x26b, 0x26d, 0x7, 0x45, 0x2, 0x2, 0x26c, 0x26e, 0x5, 0x46, 0x24, 0x2, 
    0x26d, 0x26c, 0x3, 0x2, 0x2, 0x2, 0x26d, 0x26e, 0x3, 0x2, 0x2, 0x2, 
    0x26e, 0x26f, 0x3, 0x2, 0x2, 0x2, 0x26f, 0x270, 0x7, 0x46, 0x2, 0x2, 
    0x270, 0x275, 0x3, 0x2, 0x2, 0x2, 0x271, 0x272, 0x5, 0x44, 0x23, 0x2, 
    0x272, 0x273, 0x7, 0x6f, 0x2, 0x2, 0x273, 0x275, 0x3, 0x2, 0x2, 0x2, 
    0x274, 0x267, 0x3, 0x2, 0x2, 0x2, 0x274, 0x271, 0x3, 0x2, 0x2, 0x2, 
    0x275, 0x43, 0x3, 0x2, 0x2, 0x2, 0x276, 0x277, 0x9, 0x8, 0x2, 0x2, 0x277, 
    0x45, 0x3, 0x2, 0x2, 0x2, 0x278, 0x279, 0x8, 0x24, 0x1, 0x2, 0x279, 
    0x27a, 0x5, 0x48, 0x25, 0x2, 0x27a, 0x27f, 0x3, 0x2, 0x2, 0x2, 0x27b, 
    0x27c, 0xc, 0x3, 0x2, 0x2, 0x27c, 0x27e, 0x5, 0x48, 0x25, 0x2, 0x27d, 
    0x27b, 0x3, 0x2, 0x2, 0x2, 0x27e, 0x281, 0x3, 0x2, 0x2, 0x2, 0x27f, 
    0x27d, 0x3, 0x2, 0x2, 0x2, 0x27f, 0x280, 0x3, 0x2, 0x2, 0x2, 0x280, 
    0x47, 0x3, 0x2, 0x2, 0x2, 0x281, 0x27f, 0x3, 0x2, 0x2, 0x2, 0x282, 0x284, 
    0x5, 0x4a, 0x26, 0x2, 0x283, 0x285, 0x5, 0x4c, 0x27, 0x2, 0x284, 0x283, 
    0x3, 0x2, 0x2, 0x2, 0x284, 0x285, 0x3, 0x2, 0x2, 0x2, 0x285, 0x286, 
    0x3, 0x2, 0x2, 0x2, 0x286, 0x287, 0x7, 0x5d, 0x2, 0x2, 0x287, 0x28a, 
    0x3, 0x2, 0x2, 0x2, 0x288, 0x28a, 0x5, 0x8c, 0x47, 0x2, 0x289, 0x282, 
    0x3, 0x2, 0x2, 0x2, 0x289, 0x288, 0x3, 0x2, 0x2, 0x2, 0x28a, 0x49, 0x3, 
    0x2, 0x2, 0x2, 0x28b, 0x28d, 0x5, 0x40, 0x21, 0x2, 0x28c, 0x28e, 0x5, 
    0x4a, 0x26, 0x2, 0x28d, 0x28c, 0x3, 0x2, 0x2, 0x2, 0x28d, 0x28e, 0x3, 
    0x2, 0x2, 0x2, 0x28e, 0x294, 0x3, 0x2, 0x2, 0x2, 0x28f, 0x291, 0x5, 
    0x5a, 0x2e, 0x2, 0x290, 0x292, 0x5, 0x4a, 0x26, 0x2, 0x291, 0x290, 0x3, 
    0x2, 0x2, 0x2, 0x291, 0x292, 0x3, 0x2, 0x2, 0x2, 0x292, 0x294, 0x3, 
    0x2, 0x2, 0x2, 0x293, 0x28b, 0x3, 0x2, 0x2, 0x2, 0x293, 0x28f, 0x3, 
    0x2, 0x2, 0x2, 0x294, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x295, 0x296, 0x8, 0x27, 
    0x1, 0x2, 0x296, 0x297, 0x5, 0x4e, 0x28, 0x2, 0x297, 0x29d, 0x3, 0x2, 
    0x2, 0x2, 0x298, 0x299, 0xc, 0x3, 0x2, 0x2, 0x299, 0x29a, 0x7, 0x5e, 
    0x2, 0x2, 0x29a, 0x29c, 0x5, 0x4e, 0x28, 0x2, 0x29b, 0x298, 0x3, 0x2, 
    0x2, 0x2, 0x29c, 0x29f, 0x3, 0x2, 0x2, 0x2, 0x29d, 0x29b, 0x3, 0x2, 
    0x2, 0x2, 0x29d, 0x29e, 0x3, 0x2, 0x2, 0x2, 0x29e, 0x4d, 0x3, 0x2, 0x2, 
    0x2, 0x29f, 0x29d, 0x3, 0x2, 0x2, 0x2, 0x2a0, 0x2a7, 0x5, 0x60, 0x31, 
    0x2, 0x2a1, 0x2a3, 0x5, 0x60, 0x31, 0x2, 0x2a2, 0x2a1, 0x3, 0x2, 0x2, 
    0x2, 0x2a2, 0x2a3, 0x3, 0x2, 0x2, 0x2, 0x2a3, 0x2a4, 0x3, 0x2, 0x2, 
    0x2, 0x2a4, 0x2a5, 0x7, 0x5c, 0x2, 0x2, 0x2a5, 0x2a7, 0x5, 0x30, 0x19, 
    0x2, 0x2a6, 0x2a0, 0x3, 0x2, 0x2, 0x2, 0x2a6, 0x2a2, 0x3, 0x2, 0x2, 
    0x2, 0x2a7, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x2a8, 0x2aa, 0x7, 0x1e, 0x2, 
    0x2, 0x2a9, 0x2ab, 0x7, 0x6f, 0x2, 0x2, 0x2aa, 0x2a9, 0x3, 0x2, 0x2, 
    0x2, 0x2aa, 0x2ab, 0x3, 0x2, 0x2, 0x2, 0x2ab, 0x2ac, 0x3, 0x2, 0x2, 
    0x2, 0x2ac, 0x2ad, 0x7, 0x45, 0x2, 0x2, 0x2ad, 0x2ae, 0x5, 0x52, 0x2a, 
    0x2, 0x2ae, 0x2af, 0x7, 0x46, 0x2, 0x2, 0x2af, 0x2bc, 0x3, 0x2, 0x2, 
    0x2, 0x2b0, 0x2b2, 0x7, 0x1e, 0x2, 0x2, 0x2b1, 0x2b3, 0x7, 0x6f, 0x2, 
    0x2, 0x2b2, 0x2b1, 0x3, 0x2, 0x2, 0x2, 0x2b2, 0x2b3, 0x3, 0x2, 0x2, 
    0x2, 0x2b3, 0x2b4, 0x3, 0x2, 0x2, 0x2, 0x2b4, 0x2b5, 0x7, 0x45, 0x2, 
    0x2, 0x2b5, 0x2b6, 0x5, 0x52, 0x2a, 0x2, 0x2b6, 0x2b7, 0x7, 0x5e, 0x2, 
    0x2, 0x2b7, 0x2b8, 0x7, 0x46, 0x2, 0x2, 0x2b8, 0x2bc, 0x3, 0x2, 0x2, 
    0x2, 0x2b9, 0x2ba, 0x7, 0x1e, 0x2, 0x2, 0x2ba, 0x2bc, 0x7, 0x6f, 0x2, 
    0x2, 0x2bb, 0x2a8, 0x3, 0x2, 0x2, 0x2, 0x2bb, 0x2b0, 0x3, 0x2, 0x2, 
    0x2, 0x2bb, 0x2b9, 0x3, 0x2, 0x2, 0x2, 0x2bc, 0x51, 0x3, 0x2, 0x2, 0x2, 
    0x2bd, 0x2be, 0x8, 0x2a, 0x1, 0x2, 0x2be, 0x2bf, 0x5, 0x54, 0x2b, 0x2, 
    0x2bf, 0x2c5, 0x3, 0x2, 0x2, 0x2, 0x2c0, 0x2c1, 0xc, 0x3, 0x2, 0x2, 
    0x2c1, 0x2c2, 0x7, 0x5e, 0x2, 0x2, 0x2c2, 0x2c4, 0x5, 0x54, 0x2b, 0x2, 
    0x2c3, 0x2c0, 0x3, 0x2, 0x2, 0x2, 0x2c4, 0x2c7, 0x3, 0x2, 0x2, 0x2, 
    0x2c5, 0x2c3, 0x3, 0x2, 0x2, 0x2, 0x2c5, 0x2c6, 0x3, 0x2, 0x2, 0x2, 
    0x2c6, 0x53, 0x3, 0x2, 0x2, 0x2, 0x2c7, 0x2c5, 0x3, 0x2, 0x2, 0x2, 0x2c8, 
    0x2ce, 0x5, 0x56, 0x2c, 0x2, 0x2c9, 0x2ca, 0x5, 0x56, 0x2c, 0x2, 0x2ca, 
    0x2cb, 0x7, 0x5f, 0x2, 0x2, 0x2cb, 0x2cc, 0x5, 0x30, 0x19, 0x2, 0x2cc, 
    0x2ce, 0x3, 0x2, 0x2, 0x2, 0x2cd, 0x2c8, 0x3, 0x2, 0x2, 0x2, 0x2cd, 
    0x2c9, 0x3, 0x2, 0x2, 0x2, 0x2ce, 0x55, 0x3, 0x2, 0x2, 0x2, 0x2cf, 0x2d0, 
    0x7, 0x6f, 0x2, 0x2, 0x2d0, 0x57, 0x3, 0x2, 0x2, 0x2, 0x2d1, 0x2d2, 
    0x7, 0x39, 0x2, 0x2, 0x2d2, 0x2d3, 0x7, 0x41, 0x2, 0x2, 0x2d3, 0x2d4, 
    0x5, 0x7a, 0x3e, 0x2, 0x2d4, 0x2d5, 0x7, 0x42, 0x2, 0x2, 0x2d5, 0x59, 
    0x3, 0x2, 0x2, 0x2, 0x2d6, 0x2d7, 0x9, 0x9, 0x2, 0x2, 0x2d7, 0x5b, 0x3, 
    0x2, 0x2, 0x2, 0x2d8, 0x2df, 0x9, 0xa, 0x2, 0x2, 0x2d9, 0x2df, 0x5, 
    0x66, 0x34, 0x2, 0x2da, 0x2db, 0x7, 0xf, 0x2, 0x2, 0x2db, 0x2dc, 0x7, 
    0x41, 0x2, 0x2, 0x2dc, 0x2dd, 0x7, 0x6f, 0x2, 0x2, 0x2dd, 0x2df, 0x7, 
    0x42, 0x2, 0x2, 0x2de, 0x2d8, 0x3, 0x2, 0x2, 0x2, 0x2de, 0x2d9, 0x3, 
    0x2, 0x2, 0x2, 0x2de, 0x2da, 0x3, 0x2, 0x2, 0x2, 0x2df, 0x5d, 0x3, 0x2, 
    0x2, 0x2, 0x2e0, 0x2e1, 0x7, 0x37, 0x2, 0x2, 0x2e1, 0x2e2, 0x7, 0x41, 
    0x2, 0x2, 0x2e2, 0x2e3, 0x5, 0x7a, 0x3e, 0x2, 0x2e3, 0x2e4, 0x7, 0x42, 
    0x2, 0x2, 0x2e4, 0x2eb, 0x3, 0x2, 0x2, 0x2, 0x2e5, 0x2e6, 0x7, 0x37, 
    0x2, 0x2, 0x2e6, 0x2e7, 0x7, 0x41, 0x2, 0x2, 0x2e7, 0x2e8, 0x5, 0x30, 
    0x19, 0x2, 0x2e8, 0x2e9, 0x7, 0x42, 0x2, 0x2, 0x2e9, 0x2eb, 0x3, 0x2, 
    0x2, 0x2, 0x2ea, 0x2e0, 0x3, 0x2, 0x2, 0x2, 0x2ea, 0x2e5, 0x3, 0x2, 
    0x2, 0x2, 0x2eb, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x2ec, 0x2ee, 0x5, 0x6e, 
    0x38, 0x2, 0x2ed, 0x2ec, 0x3, 0x2, 0x2, 0x2, 0x2ed, 0x2ee, 0x3, 0x2, 
    0x2, 0x2, 0x2ee, 0x2ef, 0x3, 0x2, 0x2, 0x2, 0x2ef, 0x2f3, 0x5, 0x62, 
    0x32, 0x2, 0x2f0, 0x2f2, 0x5, 0x64, 0x33, 0x2, 0x2f1, 0x2f0, 0x3, 0x2, 
    0x2, 0x2, 0x2f2, 0x2f5, 0x3, 0x2, 0x2, 0x2, 0x2f3, 0x2f1, 0x3, 0x2, 
    0x2, 0x2, 0x2f3, 0x2f4, 0x3, 0x2, 0x2, 0x2, 0x2f4, 0x61, 0x3, 0x2, 0x2, 
    0x2, 0x2f5, 0x2f3, 0x3, 0x2, 0x2, 0x2, 0x2f6, 0x2f7, 0x8, 0x32, 0x1, 
    0x2, 0x2f7, 0x308, 0x7, 0x6f, 0x2, 0x2, 0x2f8, 0x2f9, 0x7, 0x41, 0x2, 
    0x2, 0x2f9, 0x2fa, 0x5, 0x60, 0x31, 0x2, 0x2fa, 0x2fb, 0x7, 0x42, 0x2, 
    0x2, 0x2fb, 0x308, 0x3, 0x2, 0x2, 0x2, 0x2fc, 0x2fd, 0x7, 0x6f, 0x2, 
    0x2, 0x2fd, 0x2fe, 0x7, 0x5c, 0x2, 0x2, 0x2fe, 0x308, 0x7, 0x71, 0x2, 
    0x2, 0x2ff, 0x301, 0x7, 0x41, 0x2, 0x2, 0x300, 0x302, 0x5, 0x40, 0x21, 
    0x2, 0x301, 0x300, 0x3, 0x2, 0x2, 0x2, 0x301, 0x302, 0x3, 0x2, 0x2, 
    0x2, 0x302, 0x303, 0x3, 0x2, 0x2, 0x2, 0x303, 0x304, 0x5, 0x6e, 0x38, 
    0x2, 0x304, 0x305, 0x5, 0x62, 0x32, 0x2, 0x305, 0x306, 0x7, 0x42, 0x2, 
    0x2, 0x306, 0x308, 0x3, 0x2, 0x2, 0x2, 0x307, 0x2f6, 0x3, 0x2, 0x2, 
    0x2, 0x307, 0x2f8, 0x3, 0x2, 0x2, 0x2, 0x307, 0x2fc, 0x3, 0x2, 0x2, 
    0x2, 0x307, 0x2ff, 0x3, 0x2, 0x2, 0x2, 0x308, 0x336, 0x3, 0x2, 0x2, 
    0x2, 0x309, 0x30a, 0xc, 0xa, 0x2, 0x2, 0x30a, 0x30c, 0x7, 0x43, 0x2, 
    0x2, 0x30b, 0x30d, 0x5, 0x70, 0x39, 0x2, 0x30c, 0x30b, 0x3, 0x2, 0x2, 
    0x2, 0x30c, 0x30d, 0x3, 0x2, 0x2, 0x2, 0x30d, 0x30f, 0x3, 0x2, 0x2, 
    0x2, 0x30e, 0x310, 0x5, 0x2a, 0x16, 0x2, 0x30f, 0x30e, 0x3, 0x2, 0x2, 
    0x2, 0x30f, 0x310, 0x3, 0x2, 0x2, 0x2, 0x310, 0x311, 0x3, 0x2, 0x2, 
    0x2, 0x311, 0x335, 0x7, 0x44, 0x2, 0x2, 0x312, 0x313, 0xc, 0x9, 0x2, 
    0x2, 0x313, 0x314, 0x7, 0x43, 0x2, 0x2, 0x314, 0x316, 0x7, 0x2d, 0x2, 
    0x2, 0x315, 0x317, 0x5, 0x70, 0x39, 0x2, 0x316, 0x315, 0x3, 0x2, 0x2, 
    0x2, 0x316, 0x317, 0x3, 0x2, 0x2, 0x2, 0x317, 0x318, 0x3, 0x2, 0x2, 
    0x2, 0x318, 0x319, 0x5, 0x2a, 0x16, 0x2, 0x319, 0x31a, 0x7, 0x44, 0x2, 
    0x2, 0x31a, 0x335, 0x3, 0x2, 0x2, 0x2, 0x31b, 0x31c, 0xc, 0x8, 0x2, 
    0x2, 0x31c, 0x31d, 0x7, 0x43, 0x2, 0x2, 0x31d, 0x31e, 0x5, 0x70, 0x39, 
    0x2, 0x31e, 0x31f, 0x7, 0x2d, 0x2, 0x2, 0x31f, 0x320, 0x5, 0x2a, 0x16, 
    0x2, 0x320, 0x321, 0x7, 0x44, 0x2, 0x2, 0x321, 0x335, 0x3, 0x2, 0x2, 
    0x2, 0x322, 0x323, 0xc, 0x7, 0x2, 0x2, 0x323, 0x325, 0x7, 0x43, 0x2, 
    0x2, 0x324, 0x326, 0x5, 0x70, 0x39, 0x2, 0x325, 0x324, 0x3, 0x2, 0x2, 
    0x2, 0x325, 0x326, 0x3, 0x2, 0x2, 0x2, 0x326, 0x327, 0x3, 0x2, 0x2, 
    0x2, 0x327, 0x328, 0x7, 0x51, 0x2, 0x2, 0x328, 0x335, 0x7, 0x44, 0x2, 
    0x2, 0x329, 0x32a, 0xc, 0x6, 0x2, 0x2, 0x32a, 0x32b, 0x7, 0x41, 0x2, 
    0x2, 0x32b, 0x32c, 0x5, 0x72, 0x3a, 0x2, 0x32c, 0x32d, 0x7, 0x42, 0x2, 
    0x2, 0x32d, 0x335, 0x3, 0x2, 0x2, 0x2, 0x32e, 0x32f, 0xc, 0x5, 0x2, 
    0x2, 0x32f, 0x331, 0x7, 0x41, 0x2, 0x2, 0x330, 0x332, 0x5, 0x78, 0x3d, 
    0x2, 0x331, 0x330, 0x3, 0x2, 0x2, 0x2, 0x331, 0x332, 0x3, 0x2, 0x2, 
    0x2, 0x332, 0x333, 0x3, 0x2, 0x2, 0x2, 0x333, 0x335, 0x7, 0x42, 0x2, 
    0x2, 0x334, 0x309, 0x3, 0x2, 0x2, 0x2, 0x334, 0x312, 0x3, 0x2, 0x2, 
    0x2, 0x334, 0x31b, 0x3, 0x2, 0x2, 0x2, 0x334, 0x322, 0x3, 0x2, 0x2, 
    0x2, 0x334, 0x329, 0x3, 0x2, 0x2, 0x2, 0x334, 0x32e, 0x3, 0x2, 0x2, 
    0x2, 0x335, 0x338, 0x3, 0x2, 0x2, 0x2, 0x336, 0x334, 0x3, 0x2, 0x2, 
    0x2, 0x336, 0x337, 0x3, 0x2, 0x2, 0x2, 0x337, 0x63, 0x3, 0x2, 0x2, 0x2, 
    0x338, 0x336, 0x3, 0x2, 0x2, 0x2, 0x339, 0x33a, 0x9, 0xb, 0x2, 0x2, 
    0x33a, 0x33c, 0x7, 0x41, 0x2, 0x2, 0x33b, 0x33d, 0x7, 0x72, 0x2, 0x2, 
    0x33c, 0x33b, 0x3, 0x2, 0x2, 0x2, 0x33d, 0x33e, 0x3, 0x2, 0x2, 0x2, 
    0x33e, 0x33c, 0x3, 0x2, 0x2, 0x2, 0x33e, 0x33f, 0x3, 0x2, 0x2, 0x2, 
    0x33f, 0x340, 0x3, 0x2, 0x2, 0x2, 0x340, 0x343, 0x7, 0x42, 0x2, 0x2, 
    0x341, 0x343, 0x5, 0x66, 0x34, 0x2, 0x342, 0x339, 0x3, 0x2, 0x2, 0x2, 
    0x342, 0x341, 0x3, 0x2, 0x2, 0x2, 0x343, 0x65, 0x3, 0x2, 0x2, 0x2, 0x344, 
    0x345, 0x7, 0x12, 0x2, 0x2, 0x345, 0x346, 0x7, 0x41, 0x2, 0x2, 0x346, 
    0x347, 0x7, 0x41, 0x2, 0x2, 0x347, 0x348, 0x5, 0x68, 0x35, 0x2, 0x348, 
    0x349, 0x7, 0x42, 0x2, 0x2, 0x349, 0x34a, 0x7, 0x42, 0x2, 0x2, 0x34a, 
    0x67, 0x3, 0x2, 0x2, 0x2, 0x34b, 0x350, 0x5, 0x6a, 0x36, 0x2, 0x34c, 
    0x34d, 0x7, 0x5e, 0x2, 0x2, 0x34d, 0x34f, 0x5, 0x6a, 0x36, 0x2, 0x34e, 
    0x34c, 0x3, 0x2, 0x2, 0x2, 0x34f, 0x352, 0x3, 0x2, 0x2, 0x2, 0x350, 
    0x34e, 0x3, 0x2, 0x2, 0x2, 0x350, 0x351, 0x3, 0x2, 0x2, 0x2, 0x351, 
    0x355, 0x3, 0x2, 0x2, 0x2, 0x352, 0x350, 0x3, 0x2, 0x2, 0x2, 0x353, 
    0x355, 0x3, 0x2, 0x2, 0x2, 0x354, 0x34b, 0x3, 0x2, 0x2, 0x2, 0x354, 
    0x353, 0x3, 0x2, 0x2, 0x2, 0x355, 0x69, 0x3, 0x2, 0x2, 0x2, 0x356, 0x35c, 
    0xa, 0xc, 0x2, 0x2, 0x357, 0x359, 0x7, 0x41, 0x2, 0x2, 0x358, 0x35a, 
    0x5, 0xc, 0x7, 0x2, 0x359, 0x358, 0x3, 0x2, 0x2, 0x2, 0x359, 0x35a, 
    0x3, 0x2, 0x2, 0x2, 0x35a, 0x35b, 0x3, 0x2, 0x2, 0x2, 0x35b, 0x35d, 
    0x7, 0x42, 0x2, 0x2, 0x35c, 0x357, 0x3, 0x2, 0x2, 0x2, 0x35c, 0x35d, 
    0x3, 0x2, 0x2, 0x2, 0x35d, 0x360, 0x3, 0x2, 0x2, 0x2, 0x35e, 0x360, 
    0x3, 0x2, 0x2, 0x2, 0x35f, 0x356, 0x3, 0x2, 0x2, 0x2, 0x35f, 0x35e, 
    0x3, 0x2, 0x2, 0x2, 0x360, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x361, 0x367, 0xa, 
    0xd, 0x2, 0x2, 0x362, 0x363, 0x7, 0x41, 0x2, 0x2, 0x363, 0x364, 0x5, 
    0x6c, 0x37, 0x2, 0x364, 0x365, 0x7, 0x42, 0x2, 0x2, 0x365, 0x367, 0x3, 
    0x2, 0x2, 0x2, 0x366, 0x361, 0x3, 0x2, 0x2, 0x2, 0x366, 0x362, 0x3, 
    0x2, 0x2, 0x2, 0x367, 0x36a, 0x3, 0x2, 0x2, 0x2, 0x368, 0x366, 0x3, 
    0x2, 0x2, 0x2, 0x368, 0x369, 0x3, 0x2, 0x2, 0x2, 0x369, 0x6d, 0x3, 0x2, 
    0x2, 0x2, 0x36a, 0x368, 0x3, 0x2, 0x2, 0x2, 0x36b, 0x36d, 0x7, 0x51, 
    0x2, 0x2, 0x36c, 0x36e, 0x5, 0x70, 0x39, 0x2, 0x36d, 0x36c, 0x3, 0x2, 
    0x2, 0x2, 0x36d, 0x36e, 0x3, 0x2, 0x2, 0x2, 0x36e, 0x37e, 0x3, 0x2, 
    0x2, 0x2, 0x36f, 0x371, 0x7, 0x51, 0x2, 0x2, 0x370, 0x372, 0x5, 0x70, 
    0x39, 0x2, 0x371, 0x370, 0x3, 0x2, 0x2, 0x2, 0x371, 0x372, 0x3, 0x2, 
    0x2, 0x2, 0x372, 0x373, 0x3, 0x2, 0x2, 0x2, 0x373, 0x37e, 0x5, 0x6e, 
    0x38, 0x2, 0x374, 0x376, 0x7, 0x58, 0x2, 0x2, 0x375, 0x377, 0x5, 0x70, 
    0x39, 0x2, 0x376, 0x375, 0x3, 0x2, 0x2, 0x2, 0x376, 0x377, 0x3, 0x2, 
    0x2, 0x2, 0x377, 0x37e, 0x3, 0x2, 0x2, 0x2, 0x378, 0x37a, 0x7, 0x58, 
    0x2, 0x2, 0x379, 0x37b, 0x5, 0x70, 0x39, 0x2, 0x37a, 0x379, 0x3, 0x2, 
    0x2, 0x2, 0x37a, 0x37b, 0x3, 0x2, 0x2, 0x2, 0x37b, 0x37c, 0x3, 0x2, 
    0x2, 0x2, 0x37c, 0x37e, 0x5, 0x6e, 0x38, 0x2, 0x37d, 0x36b, 0x3, 0x2, 
    0x2, 0x2, 0x37d, 0x36f, 0x3, 0x2, 0x2, 0x2, 0x37d, 0x374, 0x3, 0x2, 
    0x2, 0x2, 0x37d, 0x378, 0x3, 0x2, 0x2, 0x2, 0x37e, 0x6f, 0x3, 0x2, 0x2, 
    0x2, 0x37f, 0x380, 0x8, 0x39, 0x1, 0x2, 0x380, 0x381, 0x5, 0x5a, 0x2e, 
    0x2, 0x381, 0x386, 0x3, 0x2, 0x2, 0x2, 0x382, 0x383, 0xc, 0x3, 0x2, 
    0x2, 0x383, 0x385, 0x5, 0x5a, 0x2e, 0x2, 0x384, 0x382, 0x3, 0x2, 0x2, 
    0x2, 0x385, 0x388, 0x3, 0x2, 0x2, 0x2, 0x386, 0x384, 0x3, 0x2, 0x2, 
    0x2, 0x386, 0x387, 0x3, 0x2, 0x2, 0x2, 0x387, 0x71, 0x3, 0x2, 0x2, 0x2, 
    0x388, 0x386, 0x3, 0x2, 0x2, 0x2, 0x389, 0x38f, 0x5, 0x74, 0x3b, 0x2, 
    0x38a, 0x38b, 0x5, 0x74, 0x3b, 0x2, 0x38b, 0x38c, 0x7, 0x5e, 0x2, 0x2, 
    0x38c, 0x38d, 0x7, 0x6e, 0x2, 0x2, 0x38d, 0x38f, 0x3, 0x2, 0x2, 0x2, 
    0x38e, 0x389, 0x3, 0x2, 0x2, 0x2, 0x38e, 0x38a, 0x3, 0x2, 0x2, 0x2, 
    0x38f, 0x73, 0x3, 0x2, 0x2, 0x2, 0x390, 0x391, 0x8, 0x3b, 0x1, 0x2, 
    0x391, 0x392, 0x5, 0x76, 0x3c, 0x2, 0x392, 0x398, 0x3, 0x2, 0x2, 0x2, 
    0x393, 0x394, 0xc, 0x3, 0x2, 0x2, 0x394, 0x395, 0x7, 0x5e, 0x2, 0x2, 
    0x395, 0x397, 0x5, 0x76, 0x3c, 0x2, 0x396, 0x393, 0x3, 0x2, 0x2, 0x2, 
    0x397, 0x39a, 0x3, 0x2, 0x2, 0x2, 0x398, 0x396, 0x3, 0x2, 0x2, 0x2, 
    0x398, 0x399, 0x3, 0x2, 0x2, 0x2, 0x399, 0x75, 0x3, 0x2, 0x2, 0x2, 0x39a, 
    0x398, 0x3, 0x2, 0x2, 0x2, 0x39b, 0x39c, 0x5, 0x34, 0x1b, 0x2, 0x39c, 
    0x39d, 0x5, 0x60, 0x31, 0x2, 0x39d, 0x3a3, 0x3, 0x2, 0x2, 0x2, 0x39e, 
    0x3a0, 0x5, 0x36, 0x1c, 0x2, 0x39f, 0x3a1, 0x5, 0x7c, 0x3f, 0x2, 0x3a0, 
    0x39f, 0x3, 0x2, 0x2, 0x2, 0x3a0, 0x3a1, 0x3, 0x2, 0x2, 0x2, 0x3a1, 
    0x3a3, 0x3, 0x2, 0x2, 0x2, 0x3a2, 0x39b, 0x3, 0x2, 0x2, 0x2, 0x3a2, 
    0x39e, 0x3, 0x2, 0x2, 0x2, 0x3a3, 0x77, 0x3, 0x2, 0x2, 0x2, 0x3a4, 0x3a5, 
    0x8, 0x3d, 0x1, 0x2, 0x3a5, 0x3a6, 0x7, 0x6f, 0x2, 0x2, 0x3a6, 0x3ac, 
    0x3, 0x2, 0x2, 0x2, 0x3a7, 0x3a8, 0xc, 0x3, 0x2, 0x2, 0x3a8, 0x3a9, 
    0x7, 0x5e, 0x2, 0x2, 0x3a9, 0x3ab, 0x7, 0x6f, 0x2, 0x2, 0x3aa, 0x3a7, 
    0x3, 0x2, 0x2, 0x2, 0x3ab, 0x3ae, 0x3, 0x2, 0x2, 0x2, 0x3ac, 0x3aa, 
    0x3, 0x2, 0x2, 0x2, 0x3ac, 0x3ad, 0x3, 0x2, 0x2, 0x2, 0x3ad, 0x79, 0x3, 
    0x2, 0x2, 0x2, 0x3ae, 0x3ac, 0x3, 0x2, 0x2, 0x2, 0x3af, 0x3b1, 0x5, 
    0x4a, 0x26, 0x2, 0x3b0, 0x3b2, 0x5, 0x7c, 0x3f, 0x2, 0x3b1, 0x3b0, 0x3, 
    0x2, 0x2, 0x2, 0x3b1, 0x3b2, 0x3, 0x2, 0x2, 0x2, 0x3b2, 0x7b, 0x3, 0x2, 
    0x2, 0x2, 0x3b3, 0x3bf, 0x5, 0x6e, 0x38, 0x2, 0x3b4, 0x3b6, 0x5, 0x6e, 
    0x38, 0x2, 0x3b5, 0x3b4, 0x3, 0x2, 0x2, 0x2, 0x3b5, 0x3b6, 0x3, 0x2, 
    0x2, 0x2, 0x3b6, 0x3b7, 0x3, 0x2, 0x2, 0x2, 0x3b7, 0x3bb, 0x5, 0x7e, 
    0x40, 0x2, 0x3b8, 0x3ba, 0x5, 0x64, 0x33, 0x2, 0x3b9, 0x3b8, 0x3, 0x2, 
    0x2, 0x2, 0x3ba, 0x3bd, 0x3, 0x2, 0x2, 0x2, 0x3bb, 0x3b9, 0x3, 0x2, 
    0x2, 0x2, 0x3bb, 0x3bc, 0x3, 0x2, 0x2, 0x2, 0x3bc, 0x3bf, 0x3, 0x2, 
    0x2, 0x2, 0x3bd, 0x3bb, 0x3, 0x2, 0x2, 0x2, 0x3be, 0x3b3, 0x3, 0x2, 
    0x2, 0x2, 0x3be, 0x3b5, 0x3, 0x2, 0x2, 0x2, 0x3bf, 0x7d, 0x3, 0x2, 0x2, 
    0x2, 0x3c0, 0x3c1, 0x8, 0x40, 0x1, 0x2, 0x3c1, 0x3c2, 0x7, 0x41, 0x2, 
    0x2, 0x3c2, 0x3c3, 0x5, 0x7c, 0x3f, 0x2, 0x3c3, 0x3c7, 0x7, 0x42, 0x2, 
    0x2, 0x3c4, 0x3c6, 0x5, 0x64, 0x33, 0x2, 0x3c5, 0x3c4, 0x3, 0x2, 0x2, 
    0x2, 0x3c6, 0x3c9, 0x3, 0x2, 0x2, 0x2, 0x3c7, 0x3c5, 0x3, 0x2, 0x2, 
    0x2, 0x3c7, 0x3c8, 0x3, 0x2, 0x2, 0x2, 0x3c8, 0x3ef, 0x3, 0x2, 0x2, 
    0x2, 0x3c9, 0x3c7, 0x3, 0x2, 0x2, 0x2, 0x3ca, 0x3cc, 0x7, 0x43, 0x2, 
    0x2, 0x3cb, 0x3cd, 0x5, 0x70, 0x39, 0x2, 0x3cc, 0x3cb, 0x3, 0x2, 0x2, 
    0x2, 0x3cc, 0x3cd, 0x3, 0x2, 0x2, 0x2, 0x3cd, 0x3cf, 0x3, 0x2, 0x2, 
    0x2, 0x3ce, 0x3d0, 0x5, 0x2a, 0x16, 0x2, 0x3cf, 0x3ce, 0x3, 0x2, 0x2, 
    0x2, 0x3cf, 0x3d0, 0x3, 0x2, 0x2, 0x2, 0x3d0, 0x3d1, 0x3, 0x2, 0x2, 
    0x2, 0x3d1, 0x3ef, 0x7, 0x44, 0x2, 0x2, 0x3d2, 0x3d3, 0x7, 0x43, 0x2, 
    0x2, 0x3d3, 0x3d5, 0x7, 0x2d, 0x2, 0x2, 0x3d4, 0x3d6, 0x5, 0x70, 0x39, 
    0x2, 0x3d5, 0x3d4, 0x3, 0x2, 0x2, 0x2, 0x3d5, 0x3d6, 0x3, 0x2, 0x2, 
    0x2, 0x3d6, 0x3d7, 0x3, 0x2, 0x2, 0x2, 0x3d7, 0x3d8, 0x5, 0x2a, 0x16, 
    0x2, 0x3d8, 0x3d9, 0x7, 0x44, 0x2, 0x2, 0x3d9, 0x3ef, 0x3, 0x2, 0x2, 
    0x2, 0x3da, 0x3db, 0x7, 0x43, 0x2, 0x2, 0x3db, 0x3dc, 0x5, 0x70, 0x39, 
    0x2, 0x3dc, 0x3dd, 0x7, 0x2d, 0x2, 0x2, 0x3dd, 0x3de, 0x5, 0x2a, 0x16, 
    0x2, 0x3de, 0x3df, 0x7, 0x44, 0x2, 0x2, 0x3df, 0x3ef, 0x3, 0x2, 0x2, 
    0x2, 0x3e0, 0x3e1, 0x7, 0x43, 0x2, 0x2, 0x3e1, 0x3e2, 0x7, 0x51, 0x2, 
    0x2, 0x3e2, 0x3ef, 0x7, 0x44, 0x2, 0x2, 0x3e3, 0x3e5, 0x7, 0x41, 0x2, 
    0x2, 0x3e4, 0x3e6, 0x5, 0x72, 0x3a, 0x2, 0x3e5, 0x3e4, 0x3, 0x2, 0x2, 
    0x2, 0x3e5, 0x3e6, 0x3, 0x2, 0x2, 0x2, 0x3e6, 0x3e7, 0x3, 0x2, 0x2, 
    0x2, 0x3e7, 0x3eb, 0x7, 0x42, 0x2, 0x2, 0x3e8, 0x3ea, 0x5, 0x64, 0x33, 
    0x2, 0x3e9, 0x3e8, 0x3, 0x2, 0x2, 0x2, 0x3ea, 0x3ed, 0x3, 0x2, 0x2, 
    0x2, 0x3eb, 0x3e9, 0x3, 0x2, 0x2, 0x2, 0x3eb, 0x3ec, 0x3, 0x2, 0x2, 
    0x2, 0x3ec, 0x3ef, 0x3, 0x2, 0x2, 0x2, 0x3ed, 0x3eb, 0x3, 0x2, 0x2, 
    0x2, 0x3ee, 0x3c0, 0x3, 0x2, 0x2, 0x2, 0x3ee, 0x3ca, 0x3, 0x2, 0x2, 
    0x2, 0x3ee, 0x3d2, 0x3, 0x2, 0x2, 0x2, 0x3ee, 0x3da, 0x3, 0x2, 0x2, 
    0x2, 0x3ee, 0x3e0, 0x3, 0x2, 0x2, 0x2, 0x3ee, 0x3e3, 0x3, 0x2, 0x2, 
    0x2, 0x3ef, 0x41b, 0x3, 0x2, 0x2, 0x2, 0x3f0, 0x3f1, 0xc, 0x7, 0x2, 
    0x2, 0x3f1, 0x3f3, 0x7, 0x43, 0x2, 0x2, 0x3f2, 0x3f4, 0x5, 0x70, 0x39, 
    0x2, 0x3f3, 0x3f2, 0x3, 0x2, 0x2, 0x2, 0x3f3, 0x3f4, 0x3, 0x2, 0x2, 
    0x2, 0x3f4, 0x3f6, 0x3, 0x2, 0x2, 0x2, 0x3f5, 0x3f7, 0x5, 0x2a, 0x16, 
    0x2, 0x3f6, 0x3f5, 0x3, 0x2, 0x2, 0x2, 0x3f6, 0x3f7, 0x3, 0x2, 0x2, 
    0x2, 0x3f7, 0x3f8, 0x3, 0x2, 0x2, 0x2, 0x3f8, 0x41a, 0x7, 0x44, 0x2, 
    0x2, 0x3f9, 0x3fa, 0xc, 0x6, 0x2, 0x2, 0x3fa, 0x3fb, 0x7, 0x43, 0x2, 
    0x2, 0x3fb, 0x3fd, 0x7, 0x2d, 0x2, 0x2, 0x3fc, 0x3fe, 0x5, 0x70, 0x39, 
    0x2, 0x3fd, 0x3fc, 0x3, 0x2, 0x2, 0x2, 0x3fd, 0x3fe, 0x3, 0x2, 0x2, 
    0x2, 0x3fe, 0x3ff, 0x3, 0x2, 0x2, 0x2, 0x3ff, 0x400, 0x5, 0x2a, 0x16, 
    0x2, 0x400, 0x401, 0x7, 0x44, 0x2, 0x2, 0x401, 0x41a, 0x3, 0x2, 0x2, 
    0x2, 0x402, 0x403, 0xc, 0x5, 0x2, 0x2, 0x403, 0x404, 0x7, 0x43, 0x2, 
    0x2, 0x404, 0x405, 0x5, 0x70, 0x39, 0x2, 0x405, 0x406, 0x7, 0x2d, 0x2, 
    0x2, 0x406, 0x407, 0x5, 0x2a, 0x16, 0x2, 0x407, 0x408, 0x7, 0x44, 0x2, 
    0x2, 0x408, 0x41a, 0x3, 0x2, 0x2, 0x2, 0x409, 0x40a, 0xc, 0x4, 0x2, 
    0x2, 0x40a, 0x40b, 0x7, 0x43, 0x2, 0x2, 0x40b, 0x40c, 0x7, 0x51, 0x2, 
    0x2, 0x40c, 0x41a, 0x7, 0x44, 0x2, 0x2, 0x40d, 0x40e, 0xc, 0x3, 0x2, 
    0x2, 0x40e, 0x410, 0x7, 0x41, 0x2, 0x2, 0x40f, 0x411, 0x5, 0x72, 0x3a, 
    0x2, 0x410, 0x40f, 0x3, 0x2, 0x2, 0x2, 0x410, 0x411, 0x3, 0x2, 0x2, 
    0x2, 0x411, 0x412, 0x3, 0x2, 0x2, 0x2, 0x412, 0x416, 0x7, 0x42, 0x2, 
    0x2, 0x413, 0x415, 0x5, 0x64, 0x33, 0x2, 0x414, 0x413, 0x3, 0x2, 0x2, 
    0x2, 0x415, 0x418, 0x3, 0x2, 0x2, 0x2, 0x416, 0x414, 0x3, 0x2, 0x2, 
    0x2, 0x416, 0x417, 0x3, 0x2, 0x2, 0x2, 0x417, 0x41a, 0x3, 0x2, 0x2, 
    0x2, 0x418, 0x416, 0x3, 0x2, 0x2, 0x2, 0x419, 0x3f0, 0x3, 0x2, 0x2, 
    0x2, 0x419, 0x3f9, 0x3, 0x2, 0x2, 0x2, 0x419, 0x402, 0x3, 0x2, 0x2, 
    0x2, 0x419, 0x409, 0x3, 0x2, 0x2, 0x2, 0x419, 0x40d, 0x3, 0x2, 0x2, 
    0x2, 0x41a, 0x41d, 0x3, 0x2, 0x2, 0x2, 0x41b, 0x419, 0x3, 0x2, 0x2, 
    0x2, 0x41b, 0x41c, 0x3, 0x2, 0x2, 0x2, 0x41c, 0x7f, 0x3, 0x2, 0x2, 0x2, 
    0x41d, 0x41b, 0x3, 0x2, 0x2, 0x2, 0x41e, 0x41f, 0x7, 0x6f, 0x2, 0x2, 
    0x41f, 0x81, 0x3, 0x2, 0x2, 0x2, 0x420, 0x42b, 0x5, 0x2a, 0x16, 0x2, 
    0x421, 0x422, 0x7, 0x45, 0x2, 0x2, 0x422, 0x423, 0x5, 0x84, 0x43, 0x2, 
    0x423, 0x424, 0x7, 0x46, 0x2, 0x2, 0x424, 0x42b, 0x3, 0x2, 0x2, 0x2, 
    0x425, 0x426, 0x7, 0x45, 0x2, 0x2, 0x426, 0x427, 0x5, 0x84, 0x43, 0x2, 
    0x427, 0x428, 0x7, 0x5e, 0x2, 0x2, 0x428, 0x429, 0x7, 0x46, 0x2, 0x2, 
    0x429, 0x42b, 0x3, 0x2, 0x2, 0x2, 0x42a, 0x420, 0x3, 0x2, 0x2, 0x2, 
    0x42a, 0x421, 0x3, 0x2, 0x2, 0x2, 0x42a, 0x425, 0x3, 0x2, 0x2, 0x2, 
    0x42b, 0x83, 0x3, 0x2, 0x2, 0x2, 0x42c, 0x42e, 0x8, 0x43, 0x1, 0x2, 
    0x42d, 0x42f, 0x5, 0x86, 0x44, 0x2, 0x42e, 0x42d, 0x3, 0x2, 0x2, 0x2, 
    0x42e, 0x42f, 0x3, 0x2, 0x2, 0x2, 0x42f, 0x430, 0x3, 0x2, 0x2, 0x2, 
    0x430, 0x431, 0x5, 0x82, 0x42, 0x2, 0x431, 0x43a, 0x3, 0x2, 0x2, 0x2, 
    0x432, 0x433, 0xc, 0x3, 0x2, 0x2, 0x433, 0x435, 0x7, 0x5e, 0x2, 0x2, 
    0x434, 0x436, 0x5, 0x86, 0x44, 0x2, 0x435, 0x434, 0x3, 0x2, 0x2, 0x2, 
    0x435, 0x436, 0x3, 0x2, 0x2, 0x2, 0x436, 0x437, 0x3, 0x2, 0x2, 0x2, 
    0x437, 0x439, 0x5, 0x82, 0x42, 0x2, 0x438, 0x432, 0x3, 0x2, 0x2, 0x2, 
    0x439, 0x43c, 0x3, 0x2, 0x2, 0x2, 0x43a, 0x438, 0x3, 0x2, 0x2, 0x2, 
    0x43a, 0x43b, 0x3, 0x2, 0x2, 0x2, 0x43b, 0x85, 0x3, 0x2, 0x2, 0x2, 0x43c, 
    0x43a, 0x3, 0x2, 0x2, 0x2, 0x43d, 0x43e, 0x5, 0x88, 0x45, 0x2, 0x43e, 
    0x43f, 0x7, 0x5f, 0x2, 0x2, 0x43f, 0x87, 0x3, 0x2, 0x2, 0x2, 0x440, 
    0x441, 0x8, 0x45, 0x1, 0x2, 0x441, 0x442, 0x5, 0x8a, 0x46, 0x2, 0x442, 
    0x447, 0x3, 0x2, 0x2, 0x2, 0x443, 0x444, 0xc, 0x3, 0x2, 0x2, 0x444, 
    0x446, 0x5, 0x8a, 0x46, 0x2, 0x445, 0x443, 0x3, 0x2, 0x2, 0x2, 0x446, 
    0x449, 0x3, 0x2, 0x2, 0x2, 0x447, 0x445, 0x3, 0x2, 0x2, 0x2, 0x447, 
    0x448, 0x3, 0x2, 0x2, 0x2, 0x448, 0x89, 0x3, 0x2, 0x2, 0x2, 0x449, 0x447, 
    0x3, 0x2, 0x2, 0x2, 0x44a, 0x44b, 0x7, 0x43, 0x2, 0x2, 0x44b, 0x44c, 
    0x5, 0x30, 0x19, 0x2, 0x44c, 0x44d, 0x7, 0x44, 0x2, 0x2, 0x44d, 0x451, 
    0x3, 0x2, 0x2, 0x2, 0x44e, 0x44f, 0x7, 0x6d, 0x2, 0x2, 0x44f, 0x451, 
    0x7, 0x6f, 0x2, 0x2, 0x450, 0x44a, 0x3, 0x2, 0x2, 0x2, 0x450, 0x44e, 
    0x3, 0x2, 0x2, 0x2, 0x451, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x452, 0x453, 0x7, 
    0x3f, 0x2, 0x2, 0x453, 0x454, 0x7, 0x41, 0x2, 0x2, 0x454, 0x455, 0x5, 
    0x30, 0x19, 0x2, 0x455, 0x457, 0x7, 0x5e, 0x2, 0x2, 0x456, 0x458, 0x7, 
    0x72, 0x2, 0x2, 0x457, 0x456, 0x3, 0x2, 0x2, 0x2, 0x458, 0x459, 0x3, 
    0x2, 0x2, 0x2, 0x459, 0x457, 0x3, 0x2, 0x2, 0x2, 0x459, 0x45a, 0x3, 
    0x2, 0x2, 0x2, 0x45a, 0x45b, 0x3, 0x2, 0x2, 0x2, 0x45b, 0x45c, 0x7, 
    0x42, 0x2, 0x2, 0x45c, 0x45d, 0x7, 0x5d, 0x2, 0x2, 0x45d, 0x8d, 0x3, 
    0x2, 0x2, 0x2, 0x45e, 0x466, 0x5, 0x90, 0x49, 0x2, 0x45f, 0x466, 0x5, 
    0x92, 0x4a, 0x2, 0x460, 0x466, 0x5, 0x98, 0x4d, 0x2, 0x461, 0x466, 0x5, 
    0x9a, 0x4e, 0x2, 0x462, 0x466, 0x5, 0x9c, 0x4f, 0x2, 0x463, 0x466, 0x5, 
    0xa4, 0x53, 0x2, 0x464, 0x466, 0x5, 0xa6, 0x54, 0x2, 0x465, 0x45e, 0x3, 
    0x2, 0x2, 0x2, 0x465, 0x45f, 0x3, 0x2, 0x2, 0x2, 0x465, 0x460, 0x3, 
    0x2, 0x2, 0x2, 0x465, 0x461, 0x3, 0x2, 0x2, 0x2, 0x465, 0x462, 0x3, 
    0x2, 0x2, 0x2, 0x465, 0x463, 0x3, 0x2, 0x2, 0x2, 0x465, 0x464, 0x3, 
    0x2, 0x2, 0x2, 0x466, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x467, 0x468, 0x7, 0x6f, 
    0x2, 0x2, 0x468, 0x469, 0x7, 0x5c, 0x2, 0x2, 0x469, 0x477, 0x5, 0x8e, 
    0x48, 0x2, 0x46a, 0x46b, 0x7, 0x16, 0x2, 0x2, 0x46b, 0x46e, 0x5, 0x30, 
    0x19, 0x2, 0x46c, 0x46d, 0x7, 0x6e, 0x2, 0x2, 0x46d, 0x46f, 0x5, 0x30, 
    0x19, 0x2, 0x46e, 0x46c, 0x3, 0x2, 0x2, 0x2, 0x46e, 0x46f, 0x3, 0x2, 
    0x2, 0x2, 0x46f, 0x470, 0x3, 0x2, 0x2, 0x2, 0x470, 0x471, 0x7, 0x5c, 
    0x2, 0x2, 0x471, 0x472, 0x5, 0x8e, 0x48, 0x2, 0x472, 0x477, 0x3, 0x2, 
    0x2, 0x2, 0x473, 0x474, 0x7, 0x1a, 0x2, 0x2, 0x474, 0x475, 0x7, 0x5c, 
    0x2, 0x2, 0x475, 0x477, 0x5, 0x8e, 0x48, 0x2, 0x476, 0x467, 0x3, 0x2, 
    0x2, 0x2, 0x476, 0x46a, 0x3, 0x2, 0x2, 0x2, 0x476, 0x473, 0x3, 0x2, 
    0x2, 0x2, 0x477, 0x91, 0x3, 0x2, 0x2, 0x2, 0x478, 0x47a, 0x7, 0x45, 
    0x2, 0x2, 0x479, 0x47b, 0x5, 0x94, 0x4b, 0x2, 0x47a, 0x479, 0x3, 0x2, 
    0x2, 0x2, 0x47a, 0x47b, 0x3, 0x2, 0x2, 0x2, 0x47b, 0x47c, 0x3, 0x2, 
    0x2, 0x2, 0x47c, 0x47d, 0x7, 0x46, 0x2, 0x2, 0x47d, 0x93, 0x3, 0x2, 
    0x2, 0x2, 0x47e, 0x47f, 0x8, 0x4b, 0x1, 0x2, 0x47f, 0x480, 0x5, 0x96, 
    0x4c, 0x2, 0x480, 0x485, 0x3, 0x2, 0x2, 0x2, 0x481, 0x482, 0xc, 0x3, 
    0x2, 0x2, 0x482, 0x484, 0x5, 0x96, 0x4c, 0x2, 0x483, 0x481, 0x3, 0x2, 
    0x2, 0x2, 0x484, 0x487, 0x3, 0x2, 0x2, 0x2, 0x485, 0x483, 0x3, 0x2, 
    0x2, 0x2, 0x485, 0x486, 0x3, 0x2, 0x2, 0x2, 0x486, 0x95, 0x3, 0x2, 0x2, 
    0x2, 0x487, 0x485, 0x3, 0x2, 0x2, 0x2, 0x488, 0x48b, 0x5, 0x8e, 0x48, 
    0x2, 0x489, 0x48b, 0x5, 0x32, 0x1a, 0x2, 0x48a, 0x488, 0x3, 0x2, 0x2, 
    0x2, 0x48a, 0x489, 0x3, 0x2, 0x2, 0x2, 0x48b, 0x97, 0x3, 0x2, 0x2, 0x2, 
    0x48c, 0x48e, 0x5, 0x2e, 0x18, 0x2, 0x48d, 0x48c, 0x3, 0x2, 0x2, 0x2, 
    0x48d, 0x48e, 0x3, 0x2, 0x2, 0x2, 0x48e, 0x48f, 0x3, 0x2, 0x2, 0x2, 
    0x48f, 0x490, 0x7, 0x5d, 0x2, 0x2, 0x490, 0x99, 0x3, 0x2, 0x2, 0x2, 
    0x491, 0x492, 0x7, 0x23, 0x2, 0x2, 0x492, 0x493, 0x7, 0x41, 0x2, 0x2, 
    0x493, 0x494, 0x5, 0x2e, 0x18, 0x2, 0x494, 0x495, 0x7, 0x42, 0x2, 0x2, 
    0x495, 0x498, 0x5, 0x8e, 0x48, 0x2, 0x496, 0x497, 0x7, 0x1d, 0x2, 0x2, 
    0x497, 0x499, 0x5, 0x8e, 0x48, 0x2, 0x498, 0x496, 0x3, 0x2, 0x2, 0x2, 
    0x498, 0x499, 0x3, 0x2, 0x2, 0x2, 0x499, 0x4a1, 0x3, 0x2, 0x2, 0x2, 
    0x49a, 0x49b, 0x7, 0x2f, 0x2, 0x2, 0x49b, 0x49c, 0x7, 0x41, 0x2, 0x2, 
    0x49c, 0x49d, 0x5, 0x2e, 0x18, 0x2, 0x49d, 0x49e, 0x7, 0x42, 0x2, 0x2, 
    0x49e, 0x49f, 0x5, 0x8e, 0x48, 0x2, 0x49f, 0x4a1, 0x3, 0x2, 0x2, 0x2, 
    0x4a0, 0x491, 0x3, 0x2, 0x2, 0x2, 0x4a0, 0x49a, 0x3, 0x2, 0x2, 0x2, 
    0x4a1, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x4a2, 0x4a3, 0x7, 0x36, 0x2, 0x2, 
    0x4a3, 0x4a4, 0x7, 0x41, 0x2, 0x2, 0x4a4, 0x4a5, 0x5, 0x2e, 0x18, 0x2, 
    0x4a5, 0x4a6, 0x7, 0x42, 0x2, 0x2, 0x4a6, 0x4a7, 0x5, 0x8e, 0x48, 0x2, 
    0x4a7, 0x4b7, 0x3, 0x2, 0x2, 0x2, 0x4a8, 0x4a9, 0x7, 0x1b, 0x2, 0x2, 
    0x4a9, 0x4aa, 0x5, 0x8e, 0x48, 0x2, 0x4aa, 0x4ab, 0x7, 0x36, 0x2, 0x2, 
    0x4ab, 0x4ac, 0x7, 0x41, 0x2, 0x2, 0x4ac, 0x4ad, 0x5, 0x2e, 0x18, 0x2, 
    0x4ad, 0x4ae, 0x7, 0x42, 0x2, 0x2, 0x4ae, 0x4af, 0x7, 0x5d, 0x2, 0x2, 
    0x4af, 0x4b7, 0x3, 0x2, 0x2, 0x2, 0x4b0, 0x4b1, 0x7, 0x21, 0x2, 0x2, 
    0x4b1, 0x4b2, 0x7, 0x41, 0x2, 0x2, 0x4b2, 0x4b3, 0x5, 0x9e, 0x50, 0x2, 
    0x4b3, 0x4b4, 0x7, 0x42, 0x2, 0x2, 0x4b4, 0x4b5, 0x5, 0x8e, 0x48, 0x2, 
    0x4b5, 0x4b7, 0x3, 0x2, 0x2, 0x2, 0x4b6, 0x4a2, 0x3, 0x2, 0x2, 0x2, 
    0x4b6, 0x4a8, 0x3, 0x2, 0x2, 0x2, 0x4b6, 0x4b0, 0x3, 0x2, 0x2, 0x2, 
    0x4b7, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x4b8, 0x4b9, 0x5, 0xa0, 0x51, 0x2, 
    0x4b9, 0x4bb, 0x7, 0x5d, 0x2, 0x2, 0x4ba, 0x4bc, 0x5, 0xa2, 0x52, 0x2, 
    0x4bb, 0x4ba, 0x3, 0x2, 0x2, 0x2, 0x4bb, 0x4bc, 0x3, 0x2, 0x2, 0x2, 
    0x4bc, 0x4bd, 0x3, 0x2, 0x2, 0x2, 0x4bd, 0x4bf, 0x7, 0x5d, 0x2, 0x2, 
    0x4be, 0x4c0, 0x5, 0xa2, 0x52, 0x2, 0x4bf, 0x4be, 0x3, 0x2, 0x2, 0x2, 
    0x4bf, 0x4c0, 0x3, 0x2, 0x2, 0x2, 0x4c0, 0x4cd, 0x3, 0x2, 0x2, 0x2, 
    0x4c1, 0x4c3, 0x5, 0x2e, 0x18, 0x2, 0x4c2, 0x4c1, 0x3, 0x2, 0x2, 0x2, 
    0x4c2, 0x4c3, 0x3, 0x2, 0x2, 0x2, 0x4c3, 0x4c4, 0x3, 0x2, 0x2, 0x2, 
    0x4c4, 0x4c6, 0x7, 0x5d, 0x2, 0x2, 0x4c5, 0x4c7, 0x5, 0xa2, 0x52, 0x2, 
    0x4c6, 0x4c5, 0x3, 0x2, 0x2, 0x2, 0x4c6, 0x4c7, 0x3, 0x2, 0x2, 0x2, 
    0x4c7, 0x4c8, 0x3, 0x2, 0x2, 0x2, 0x4c8, 0x4ca, 0x7, 0x5d, 0x2, 0x2, 
    0x4c9, 0x4cb, 0x5, 0xa2, 0x52, 0x2, 0x4ca, 0x4c9, 0x3, 0x2, 0x2, 0x2, 
    0x4ca, 0x4cb, 0x3, 0x2, 0x2, 0x2, 0x4cb, 0x4cd, 0x3, 0x2, 0x2, 0x2, 
    0x4cc, 0x4b8, 0x3, 0x2, 0x2, 0x2, 0x4cc, 0x4c2, 0x3, 0x2, 0x2, 0x2, 
    0x4cd, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x4ce, 0x4cf, 0x5, 0x34, 0x1b, 0x2, 
    0x4cf, 0x4d0, 0x5, 0x3a, 0x1e, 0x2, 0x4d0, 0x4d3, 0x3, 0x2, 0x2, 0x2, 
    0x4d1, 0x4d3, 0x5, 0x34, 0x1b, 0x2, 0x4d2, 0x4ce, 0x3, 0x2, 0x2, 0x2, 
    0x4d2, 0x4d1, 0x3, 0x2, 0x2, 0x2, 0x4d3, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x4d4, 
    0x4d5, 0x8, 0x52, 0x1, 0x2, 0x4d5, 0x4d6, 0x5, 0x2a, 0x16, 0x2, 0x4d6, 
    0x4dc, 0x3, 0x2, 0x2, 0x2, 0x4d7, 0x4d8, 0xc, 0x3, 0x2, 0x2, 0x4d8, 
    0x4d9, 0x7, 0x5e, 0x2, 0x2, 0x4d9, 0x4db, 0x5, 0x2a, 0x16, 0x2, 0x4da, 
    0x4d7, 0x3, 0x2, 0x2, 0x2, 0x4db, 0x4de, 0x3, 0x2, 0x2, 0x2, 0x4dc, 
    0x4da, 0x3, 0x2, 0x2, 0x2, 0x4dc, 0x4dd, 0x3, 0x2, 0x2, 0x2, 0x4dd, 
    0xa3, 0x3, 0x2, 0x2, 0x2, 0x4de, 0x4dc, 0x3, 0x2, 0x2, 0x2, 0x4df, 0x4e0, 
    0x7, 0x22, 0x2, 0x2, 0x4e0, 0x4e1, 0x7, 0x6f, 0x2, 0x2, 0x4e1, 0x4f0, 
    0x7, 0x5d, 0x2, 0x2, 0x4e2, 0x4e3, 0x7, 0x19, 0x2, 0x2, 0x4e3, 0x4f0, 
    0x7, 0x5d, 0x2, 0x2, 0x4e4, 0x4e5, 0x7, 0x15, 0x2, 0x2, 0x4e5, 0x4f0, 
    0x7, 0x5d, 0x2, 0x2, 0x4e6, 0x4e8, 0x7, 0x29, 0x2, 0x2, 0x4e7, 0x4e9, 
    0x5, 0x2e, 0x18, 0x2, 0x4e8, 0x4e7, 0x3, 0x2, 0x2, 0x2, 0x4e8, 0x4e9, 
    0x3, 0x2, 0x2, 0x2, 0x4e9, 0x4ea, 0x3, 0x2, 0x2, 0x2, 0x4ea, 0x4f0, 
    0x7, 0x5d, 0x2, 0x2, 0x4eb, 0x4ec, 0x7, 0x22, 0x2, 0x2, 0x4ec, 0x4ed, 
    0x5, 0xe, 0x8, 0x2, 0x4ed, 0x4ee, 0x7, 0x5d, 0x2, 0x2, 0x4ee, 0x4f0, 
    0x3, 0x2, 0x2, 0x2, 0x4ef, 0x4df, 0x3, 0x2, 0x2, 0x2, 0x4ef, 0x4e2, 
    0x3, 0x2, 0x2, 0x2, 0x4ef, 0x4e4, 0x3, 0x2, 0x2, 0x2, 0x4ef, 0x4e6, 
    0x3, 0x2, 0x2, 0x2, 0x4ef, 0x4eb, 0x3, 0x2, 0x2, 0x2, 0x4f0, 0xa5, 0x3, 
    0x2, 0x2, 0x2, 0x4f1, 0x4f3, 0x9, 0xe, 0x2, 0x2, 0x4f2, 0x4f4, 0x5, 
    0x5a, 0x2e, 0x2, 0x4f3, 0x4f2, 0x3, 0x2, 0x2, 0x2, 0x4f3, 0x4f4, 0x3, 
    0x2, 0x2, 0x2, 0x4f4, 0x4f6, 0x3, 0x2, 0x2, 0x2, 0x4f5, 0x4f7, 0x7, 
    0x22, 0x2, 0x2, 0x4f6, 0x4f5, 0x3, 0x2, 0x2, 0x2, 0x4f6, 0x4f7, 0x3, 
    0x2, 0x2, 0x2, 0x4f7, 0x4f8, 0x3, 0x2, 0x2, 0x2, 0x4f8, 0x4f9, 0x7, 
    0x41, 0x2, 0x2, 0x4f9, 0x4fa, 0x5, 0xa8, 0x55, 0x2, 0x4fa, 0x4fb, 0x7, 
    0x42, 0x2, 0x2, 0x4fb, 0x4fc, 0x7, 0x5d, 0x2, 0x2, 0x4fc, 0xa7, 0x3, 
    0x2, 0x2, 0x2, 0x4fd, 0x512, 0x5, 0xb6, 0x5c, 0x2, 0x4fe, 0x500, 0x7, 
    0x5c, 0x2, 0x2, 0x4ff, 0x501, 0x5, 0xaa, 0x56, 0x2, 0x500, 0x4ff, 0x3, 
    0x2, 0x2, 0x2, 0x500, 0x501, 0x3, 0x2, 0x2, 0x2, 0x501, 0x510, 0x3, 
    0x2, 0x2, 0x2, 0x502, 0x504, 0x7, 0x5c, 0x2, 0x2, 0x503, 0x505, 0x5, 
    0xaa, 0x56, 0x2, 0x504, 0x503, 0x3, 0x2, 0x2, 0x2, 0x504, 0x505, 0x3, 
    0x2, 0x2, 0x2, 0x505, 0x50e, 0x3, 0x2, 0x2, 0x2, 0x506, 0x508, 0x7, 
    0x5c, 0x2, 0x2, 0x507, 0x509, 0x5, 0xae, 0x58, 0x2, 0x508, 0x507, 0x3, 
    0x2, 0x2, 0x2, 0x508, 0x509, 0x3, 0x2, 0x2, 0x2, 0x509, 0x50c, 0x3, 
    0x2, 0x2, 0x2, 0x50a, 0x50b, 0x7, 0x5c, 0x2, 0x2, 0x50b, 0x50d, 0x5, 
    0xb0, 0x59, 0x2, 0x50c, 0x50a, 0x3, 0x2, 0x2, 0x2, 0x50c, 0x50d, 0x3, 
    0x2, 0x2, 0x2, 0x50d, 0x50f, 0x3, 0x2, 0x2, 0x2, 0x50e, 0x506, 0x3, 
    0x2, 0x2, 0x2, 0x50e, 0x50f, 0x3, 0x2, 0x2, 0x2, 0x50f, 0x511, 0x3, 
    0x2, 0x2, 0x2, 0x510, 0x502, 0x3, 0x2, 0x2, 0x2, 0x510, 0x511, 0x3, 
    0x2, 0x2, 0x2, 0x511, 0x513, 0x3, 0x2, 0x2, 0x2, 0x512, 0x4fe, 0x3, 
    0x2, 0x2, 0x2, 0x512, 0x513, 0x3, 0x2, 0x2, 0x2, 0x513, 0xa9, 0x3, 0x2, 
    0x2, 0x2, 0x514, 0x519, 0x5, 0xac, 0x57, 0x2, 0x515, 0x516, 0x7, 0x5e, 
    0x2, 0x2, 0x516, 0x518, 0x5, 0xac, 0x57, 0x2, 0x517, 0x515, 0x3, 0x2, 
    0x2, 0x2, 0x518, 0x51b, 0x3, 0x2, 0x2, 0x2, 0x519, 0x517, 0x3, 0x2, 
    0x2, 0x2, 0x519, 0x51a, 0x3, 0x2, 0x2, 0x2, 0x51a, 0xab, 0x3, 0x2, 0x2, 
    0x2, 0x51b, 0x519, 0x3, 0x2, 0x2, 0x2, 0x51c, 0x51d, 0x5, 0xb6, 0x5c, 
    0x2, 0x51d, 0x51e, 0x7, 0x41, 0x2, 0x2, 0x51e, 0x51f, 0x5, 0x2e, 0x18, 
    0x2, 0x51f, 0x520, 0x7, 0x42, 0x2, 0x2, 0x520, 0x52a, 0x3, 0x2, 0x2, 
    0x2, 0x521, 0x522, 0x7, 0x43, 0x2, 0x2, 0x522, 0x523, 0x7, 0x6f, 0x2, 
    0x2, 0x523, 0x524, 0x7, 0x44, 0x2, 0x2, 0x524, 0x525, 0x5, 0xb6, 0x5c, 
    0x2, 0x525, 0x526, 0x7, 0x41, 0x2, 0x2, 0x526, 0x527, 0x5, 0x2e, 0x18, 
    0x2, 0x527, 0x528, 0x7, 0x42, 0x2, 0x2, 0x528, 0x52a, 0x3, 0x2, 0x2, 
    0x2, 0x529, 0x51c, 0x3, 0x2, 0x2, 0x2, 0x529, 0x521, 0x3, 0x2, 0x2, 
    0x2, 0x52a, 0xad, 0x3, 0x2, 0x2, 0x2, 0x52b, 0x530, 0x5, 0xb6, 0x5c, 
    0x2, 0x52c, 0x52d, 0x7, 0x5e, 0x2, 0x2, 0x52d, 0x52f, 0x5, 0xb6, 0x5c, 
    0x2, 0x52e, 0x52c, 0x3, 0x2, 0x2, 0x2, 0x52f, 0x532, 0x3, 0x2, 0x2, 
    0x2, 0x530, 0x52e, 0x3, 0x2, 0x2, 0x2, 0x530, 0x531, 0x3, 0x2, 0x2, 
    0x2, 0x531, 0xaf, 0x3, 0x2, 0x2, 0x2, 0x532, 0x530, 0x3, 0x2, 0x2, 0x2, 
    0x533, 0x538, 0x7, 0x6f, 0x2, 0x2, 0x534, 0x535, 0x7, 0x5e, 0x2, 0x2, 
    0x535, 0x537, 0x7, 0x6f, 0x2, 0x2, 0x536, 0x534, 0x3, 0x2, 0x2, 0x2, 
    0x537, 0x53a, 0x3, 0x2, 0x2, 0x2, 0x538, 0x536, 0x3, 0x2, 0x2, 0x2, 
    0x538, 0x539, 0x3, 0x2, 0x2, 0x2, 0x539, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x53a, 
    0x538, 0x3, 0x2, 0x2, 0x2, 0x53b, 0x53c, 0x5, 0xb4, 0x5b, 0x2, 0x53c, 
    0xb3, 0x3, 0x2, 0x2, 0x2, 0x53d, 0x53e, 0x9, 0xe, 0x2, 0x2, 0x53e, 0x53f, 
    0x7, 0x41, 0x2, 0x2, 0x53f, 0x540, 0x5, 0xb6, 0x5c, 0x2, 0x540, 0x541, 
    0x7, 0x42, 0x2, 0x2, 0x541, 0xb5, 0x3, 0x2, 0x2, 0x2, 0x542, 0x544, 
    0x7, 0x72, 0x2, 0x2, 0x543, 0x542, 0x3, 0x2, 0x2, 0x2, 0x544, 0x545, 
    0x3, 0x2, 0x2, 0x2, 0x545, 0x543, 0x3, 0x2, 0x2, 0x2, 0x545, 0x546, 
    0x3, 0x2, 0x2, 0x2, 0x546, 0xb7, 0x3, 0x2, 0x2, 0x2, 0x547, 0x549, 0x5, 
    0xba, 0x5e, 0x2, 0x548, 0x547, 0x3, 0x2, 0x2, 0x2, 0x548, 0x549, 0x3, 
    0x2, 0x2, 0x2, 0x549, 0x54a, 0x3, 0x2, 0x2, 0x2, 0x54a, 0x54b, 0x7, 
    0x2, 0x2, 0x3, 0x54b, 0xb9, 0x3, 0x2, 0x2, 0x2, 0x54c, 0x54d, 0x8, 0x5e, 
    0x1, 0x2, 0x54d, 0x54e, 0x5, 0xbc, 0x5f, 0x2, 0x54e, 0x553, 0x3, 0x2, 
    0x2, 0x2, 0x54f, 0x550, 0xc, 0x3, 0x2, 0x2, 0x550, 0x552, 0x5, 0xbc, 
    0x5f, 0x2, 0x551, 0x54f, 0x3, 0x2, 0x2, 0x2, 0x552, 0x555, 0x3, 0x2, 
    0x2, 0x2, 0x553, 0x551, 0x3, 0x2, 0x2, 0x2, 0x553, 0x554, 0x3, 0x2, 
    0x2, 0x2, 0x554, 0xbb, 0x3, 0x2, 0x2, 0x2, 0x555, 0x553, 0x3, 0x2, 0x2, 
    0x2, 0x556, 0x55b, 0x5, 0xbe, 0x60, 0x2, 0x557, 0x55b, 0x5, 0x32, 0x1a, 
    0x2, 0x558, 0x55b, 0x7, 0x5d, 0x2, 0x2, 0x559, 0x55b, 0x5, 0xb2, 0x5a, 
    0x2, 0x55a, 0x556, 0x3, 0x2, 0x2, 0x2, 0x55a, 0x557, 0x3, 0x2, 0x2, 
    0x2, 0x55a, 0x558, 0x3, 0x2, 0x2, 0x2, 0x55a, 0x559, 0x3, 0x2, 0x2, 
    0x2, 0x55b, 0xbd, 0x3, 0x2, 0x2, 0x2, 0x55c, 0x55e, 0x5, 0x34, 0x1b, 
    0x2, 0x55d, 0x55c, 0x3, 0x2, 0x2, 0x2, 0x55d, 0x55e, 0x3, 0x2, 0x2, 
    0x2, 0x55e, 0x55f, 0x3, 0x2, 0x2, 0x2, 0x55f, 0x561, 0x5, 0x60, 0x31, 
    0x2, 0x560, 0x562, 0x5, 0xc0, 0x61, 0x2, 0x561, 0x560, 0x3, 0x2, 0x2, 
    0x2, 0x561, 0x562, 0x3, 0x2, 0x2, 0x2, 0x562, 0x563, 0x3, 0x2, 0x2, 
    0x2, 0x563, 0x564, 0x5, 0x92, 0x4a, 0x2, 0x564, 0xbf, 0x3, 0x2, 0x2, 
    0x2, 0x565, 0x566, 0x8, 0x61, 0x1, 0x2, 0x566, 0x567, 0x5, 0x32, 0x1a, 
    0x2, 0x567, 0x56c, 0x3, 0x2, 0x2, 0x2, 0x568, 0x569, 0xc, 0x3, 0x2, 
    0x2, 0x569, 0x56b, 0x5, 0x32, 0x1a, 0x2, 0x56a, 0x568, 0x3, 0x2, 0x2, 
    0x2, 0x56b, 0x56e, 0x3, 0x2, 0x2, 0x2, 0x56c, 0x56a, 0x3, 0x2, 0x2, 
    0x2, 0x56c, 0x56d, 0x3, 0x2, 0x2, 0x2, 0x56d, 0xc1, 0x3, 0x2, 0x2, 0x2, 
    0x56e, 0x56c, 0x3, 0x2, 0x2, 0x2, 0x9d, 0xc7, 0xcf, 0xe3, 0xf4, 0xfe, 
    0x122, 0x12c, 0x139, 0x13b, 0x146, 0x15f, 0x170, 0x17e, 0x180, 0x18c, 
    0x18e, 0x19a, 0x19c, 0x1ae, 0x1b0, 0x1bc, 0x1be, 0x1c9, 0x1d4, 0x1df, 
    0x1ea, 0x1f5, 0x1fe, 0x206, 0x212, 0x21f, 0x224, 0x229, 0x230, 0x23a, 
    0x242, 0x245, 0x24d, 0x25e, 0x264, 0x269, 0x26d, 0x274, 0x27f, 0x284, 
    0x289, 0x28d, 0x291, 0x293, 0x29d, 0x2a2, 0x2a6, 0x2aa, 0x2b2, 0x2bb, 
    0x2c5, 0x2cd, 0x2de, 0x2ea, 0x2ed, 0x2f3, 0x301, 0x307, 0x30c, 0x30f, 
    0x316, 0x325, 0x331, 0x334, 0x336, 0x33e, 0x342, 0x350, 0x354, 0x359, 
    0x35c, 0x35f, 0x366, 0x368, 0x36d, 0x371, 0x376, 0x37a, 0x37d, 0x386, 
    0x38e, 0x398, 0x3a0, 0x3a2, 0x3ac, 0x3b1, 0x3b5, 0x3bb, 0x3be, 0x3c7, 
    0x3cc, 0x3cf, 0x3d5, 0x3e5, 0x3eb, 0x3ee, 0x3f3, 0x3f6, 0x3fd, 0x410, 
    0x416, 0x419, 0x41b, 0x42a, 0x42e, 0x435, 0x43a, 0x447, 0x450, 0x459, 
    0x465, 0x46e, 0x476, 0x47a, 0x485, 0x48a, 0x48d, 0x498, 0x4a0, 0x4b6, 
    0x4bb, 0x4bf, 0x4c2, 0x4c6, 0x4ca, 0x4cc, 0x4d2, 0x4dc, 0x4e8, 0x4ef, 
    0x4f3, 0x4f6, 0x500, 0x504, 0x508, 0x50c, 0x50e, 0x510, 0x512, 0x519, 
    0x529, 0x530, 0x538, 0x545, 0x548, 0x553, 0x55a, 0x55d, 0x561, 0x56c, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

CParser::Initializer CParser::_init;
