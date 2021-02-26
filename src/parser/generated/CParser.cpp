
// Generated from C.g4 by ANTLR 4.9.1


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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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

    default:
      break;
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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
    genericAssocList();
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

std::vector<CParser::GenericAssociationContext *> CParser::GenericAssocListContext::genericAssociation() {
  return getRuleContexts<CParser::GenericAssociationContext>();
}

CParser::GenericAssociationContext* CParser::GenericAssocListContext::genericAssociation(size_t i) {
  return getRuleContext<CParser::GenericAssociationContext>(i);
}

std::vector<tree::TerminalNode *> CParser::GenericAssocListContext::Comma() {
  return getTokens(CParser::Comma);
}

tree::TerminalNode* CParser::GenericAssocListContext::Comma(size_t i) {
  return getToken(CParser::Comma, i);
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
  GenericAssocListContext *_localctx = _tracker.createInstance<GenericAssocListContext>(_ctx, getState());
  enterRule(_localctx, 4, CParser::RuleGenericAssocList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(234);
    genericAssociation();
    setState(239);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::Comma) {
      setState(235);
      match(CParser::Comma);
      setState(236);
      genericAssociation();
      setState(241);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(249);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(242);
      typeName();
      setState(243);
      match(CParser::Colon);
      setState(244);
      assignmentExpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(246);
      match(CParser::Default);
      setState(247);
      match(CParser::Colon);
      setState(248);
      assignmentExpression();
      break;
    }

    default:
      break;
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

tree::TerminalNode* CParser::PostfixExpressionContext::RightBrace() {
  return getToken(CParser::RightBrace, 0);
}

CParser::InitializerListContext* CParser::PostfixExpressionContext::initializerList() {
  return getRuleContext<CParser::InitializerListContext>(0);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(289);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      setState(252);
      primaryExpression();
      break;
    }

    case 2: {
      setState(253);
      match(CParser::LeftParen);
      setState(254);
      typeName();
      setState(255);
      match(CParser::RightParen);
      setState(256);
      match(CParser::LeftBrace);
      setState(258);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__0)
        | (1ULL << CParser::T__1)
        | (1ULL << CParser::T__2)
        | (1ULL << CParser::T__3)
        | (1ULL << CParser::T__4)
        | (1ULL << CParser::Sizeof)
        | (1ULL << CParser::Alignof))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 67)) & ((1ULL << (CParser::Generic - 67))
        | (1ULL << (CParser::LeftParen - 67))
        | (1ULL << (CParser::LeftBracket - 67))
        | (1ULL << (CParser::LeftBrace - 67))
        | (1ULL << (CParser::Plus - 67))
        | (1ULL << (CParser::PlusPlus - 67))
        | (1ULL << (CParser::Minus - 67))
        | (1ULL << (CParser::MinusMinus - 67))
        | (1ULL << (CParser::Star - 67))
        | (1ULL << (CParser::And - 67))
        | (1ULL << (CParser::AndAnd - 67))
        | (1ULL << (CParser::Not - 67))
        | (1ULL << (CParser::Tilde - 67))
        | (1ULL << (CParser::Dot - 67))
        | (1ULL << (CParser::Identifier - 67))
        | (1ULL << (CParser::Constant - 67))
        | (1ULL << (CParser::DigitSequence - 67))
        | (1ULL << (CParser::StringLiteral - 67)))) != 0)) {
        setState(257);
        initializerList(0);
      }
      setState(260);
      match(CParser::RightBrace);
      break;
    }

    case 3: {
      setState(262);
      match(CParser::LeftParen);
      setState(263);
      typeName();
      setState(264);
      match(CParser::RightParen);
      setState(265);
      match(CParser::LeftBrace);
      setState(266);
      initializerList(0);
      setState(267);
      match(CParser::Comma);
      setState(268);
      match(CParser::RightBrace);
      break;
    }

    case 4: {
      setState(270);
      match(CParser::T__0);
      setState(271);
      match(CParser::LeftParen);
      setState(272);
      typeName();
      setState(273);
      match(CParser::RightParen);
      setState(274);
      match(CParser::LeftBrace);
      setState(276);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__0)
        | (1ULL << CParser::T__1)
        | (1ULL << CParser::T__2)
        | (1ULL << CParser::T__3)
        | (1ULL << CParser::T__4)
        | (1ULL << CParser::Sizeof)
        | (1ULL << CParser::Alignof))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 67)) & ((1ULL << (CParser::Generic - 67))
        | (1ULL << (CParser::LeftParen - 67))
        | (1ULL << (CParser::LeftBracket - 67))
        | (1ULL << (CParser::LeftBrace - 67))
        | (1ULL << (CParser::Plus - 67))
        | (1ULL << (CParser::PlusPlus - 67))
        | (1ULL << (CParser::Minus - 67))
        | (1ULL << (CParser::MinusMinus - 67))
        | (1ULL << (CParser::Star - 67))
        | (1ULL << (CParser::And - 67))
        | (1ULL << (CParser::AndAnd - 67))
        | (1ULL << (CParser::Not - 67))
        | (1ULL << (CParser::Tilde - 67))
        | (1ULL << (CParser::Dot - 67))
        | (1ULL << (CParser::Identifier - 67))
        | (1ULL << (CParser::Constant - 67))
        | (1ULL << (CParser::DigitSequence - 67))
        | (1ULL << (CParser::StringLiteral - 67)))) != 0)) {
        setState(275);
        initializerList(0);
      }
      setState(278);
      match(CParser::RightBrace);
      break;
    }

    case 5: {
      setState(280);
      match(CParser::T__0);
      setState(281);
      match(CParser::LeftParen);
      setState(282);
      typeName();
      setState(283);
      match(CParser::RightParen);
      setState(284);
      match(CParser::LeftBrace);
      setState(285);
      initializerList(0);
      setState(286);
      match(CParser::Comma);
      setState(287);
      match(CParser::RightBrace);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(314);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(312);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(291);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(292);
          match(CParser::LeftBracket);
          setState(293);
          expression(0);
          setState(294);
          match(CParser::RightBracket);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(296);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(297);
          match(CParser::LeftParen);
          setState(299);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CParser::T__0)
            | (1ULL << CParser::T__1)
            | (1ULL << CParser::T__2)
            | (1ULL << CParser::T__3)
            | (1ULL << CParser::T__4)
            | (1ULL << CParser::Sizeof)
            | (1ULL << CParser::Alignof))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 67)) & ((1ULL << (CParser::Generic - 67))
            | (1ULL << (CParser::LeftParen - 67))
            | (1ULL << (CParser::Plus - 67))
            | (1ULL << (CParser::PlusPlus - 67))
            | (1ULL << (CParser::Minus - 67))
            | (1ULL << (CParser::MinusMinus - 67))
            | (1ULL << (CParser::Star - 67))
            | (1ULL << (CParser::And - 67))
            | (1ULL << (CParser::AndAnd - 67))
            | (1ULL << (CParser::Not - 67))
            | (1ULL << (CParser::Tilde - 67))
            | (1ULL << (CParser::Identifier - 67))
            | (1ULL << (CParser::Constant - 67))
            | (1ULL << (CParser::DigitSequence - 67))
            | (1ULL << (CParser::StringLiteral - 67)))) != 0)) {
            setState(298);
            argumentExpressionList();
          }
          setState(301);
          match(CParser::RightParen);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(302);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(303);
          match(CParser::Dot);
          setState(304);
          match(CParser::Identifier);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(305);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(306);
          match(CParser::Arrow);
          setState(307);
          match(CParser::Identifier);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(308);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(309);
          match(CParser::PlusPlus);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(310);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(311);
          match(CParser::MinusMinus);
          break;
        }

        default:
          break;
        } 
      }
      setState(316);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
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

std::vector<CParser::AssignmentExpressionContext *> CParser::ArgumentExpressionListContext::assignmentExpression() {
  return getRuleContexts<CParser::AssignmentExpressionContext>();
}

CParser::AssignmentExpressionContext* CParser::ArgumentExpressionListContext::assignmentExpression(size_t i) {
  return getRuleContext<CParser::AssignmentExpressionContext>(i);
}

std::vector<tree::TerminalNode *> CParser::ArgumentExpressionListContext::Comma() {
  return getTokens(CParser::Comma);
}

tree::TerminalNode* CParser::ArgumentExpressionListContext::Comma(size_t i) {
  return getToken(CParser::Comma, i);
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
  ArgumentExpressionListContext *_localctx = _tracker.createInstance<ArgumentExpressionListContext>(_ctx, getState());
  enterRule(_localctx, 10, CParser::RuleArgumentExpressionList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(317);
    assignmentExpression();
    setState(322);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::Comma) {
      setState(318);
      match(CParser::Comma);
      setState(319);
      assignmentExpression();
      setState(324);
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

CParser::GccBuiltinContext* CParser::UnaryExpressionContext::gccBuiltin() {
  return getRuleContext<CParser::GccBuiltinContext>(0);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(348);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(325);
      postfixExpression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(326);
      match(CParser::PlusPlus);
      setState(327);
      unaryExpression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(328);
      match(CParser::MinusMinus);
      setState(329);
      unaryExpression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(330);
      unaryOperator();
      setState(331);
      castExpression();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(333);
      match(CParser::Sizeof);
      setState(334);
      unaryExpression();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(335);
      match(CParser::Sizeof);
      setState(336);
      match(CParser::LeftParen);
      setState(337);
      typeName();
      setState(338);
      match(CParser::RightParen);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(340);
      _la = _input->LA(1);
      if (!(_la == CParser::T__3

      || _la == CParser::Alignof)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(341);
      match(CParser::LeftParen);
      setState(342);
      typeName();
      setState(343);
      match(CParser::RightParen);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(345);
      match(CParser::AndAnd);
      setState(346);
      match(CParser::Identifier);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(347);
      gccBuiltin();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GccBuiltinContext ------------------------------------------------------------------

CParser::GccBuiltinContext::GccBuiltinContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::GccBuiltinContext::LeftParen() {
  return getToken(CParser::LeftParen, 0);
}

std::vector<CParser::TypeNameContext *> CParser::GccBuiltinContext::typeName() {
  return getRuleContexts<CParser::TypeNameContext>();
}

CParser::TypeNameContext* CParser::GccBuiltinContext::typeName(size_t i) {
  return getRuleContext<CParser::TypeNameContext>(i);
}

tree::TerminalNode* CParser::GccBuiltinContext::Comma() {
  return getToken(CParser::Comma, 0);
}

tree::TerminalNode* CParser::GccBuiltinContext::RightParen() {
  return getToken(CParser::RightParen, 0);
}


size_t CParser::GccBuiltinContext::getRuleIndex() const {
  return CParser::RuleGccBuiltin;
}

void CParser::GccBuiltinContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGccBuiltin(this);
}

void CParser::GccBuiltinContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGccBuiltin(this);
}


antlrcpp::Any CParser::GccBuiltinContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitGccBuiltin(this);
  else
    return visitor->visitChildren(this);
}

CParser::GccBuiltinContext* CParser::gccBuiltin() {
  GccBuiltinContext *_localctx = _tracker.createInstance<GccBuiltinContext>(_ctx, getState());
  enterRule(_localctx, 14, CParser::RuleGccBuiltin);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(350);
    match(CParser::T__4);
    setState(351);
    match(CParser::LeftParen);
    setState(352);
    typeName();
    setState(353);
    match(CParser::Comma);
    setState(354);
    typeName();
    setState(355);
    match(CParser::RightParen);
   
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
  enterRule(_localctx, 16, CParser::RuleUnaryOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(357);
    _la = _input->LA(1);
    if (!(((((_la - 84) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 84)) & ((1ULL << (CParser::Plus - 84))
      | (1ULL << (CParser::Minus - 84))
      | (1ULL << (CParser::Star - 84))
      | (1ULL << (CParser::And - 84))
      | (1ULL << (CParser::Not - 84))
      | (1ULL << (CParser::Tilde - 84)))) != 0))) {
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

CParser::UnaryExpressionContext* CParser::CastExpressionContext::unaryExpression() {
  return getRuleContext<CParser::UnaryExpressionContext>(0);
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
  enterRule(_localctx, 18, CParser::RuleCastExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(372);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(359);
      unaryExpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(360);
      match(CParser::LeftParen);
      setState(361);
      typeName();
      setState(362);
      match(CParser::RightParen);
      setState(363);
      castExpression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(365);
      match(CParser::T__0);
      setState(366);
      match(CParser::LeftParen);
      setState(367);
      typeName();
      setState(368);
      match(CParser::RightParen);
      setState(369);
      castExpression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(371);
      match(CParser::DigitSequence);
      break;
    }

    default:
      break;
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
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, CParser::RuleMultiplicativeExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(375);
    castExpression();
    _ctx->stop = _input->LT(-1);
    setState(388);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(386);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<MultiplicativeExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleMultiplicativeExpression);
          setState(377);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(378);
          match(CParser::Star);
          setState(379);
          castExpression();
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<MultiplicativeExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleMultiplicativeExpression);
          setState(380);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(381);
          match(CParser::Div);
          setState(382);
          castExpression();
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<MultiplicativeExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleMultiplicativeExpression);
          setState(383);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(384);
          match(CParser::Mod);
          setState(385);
          castExpression();
          break;
        }

        default:
          break;
        } 
      }
      setState(390);
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
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, CParser::RuleAdditiveExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(392);
    multiplicativeExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(402);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(400);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<AdditiveExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleAdditiveExpression);
          setState(394);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(395);
          match(CParser::Plus);
          setState(396);
          multiplicativeExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<AdditiveExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleAdditiveExpression);
          setState(397);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(398);
          match(CParser::Minus);
          setState(399);
          multiplicativeExpression(0);
          break;
        }

        default:
          break;
        } 
      }
      setState(404);
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
  size_t startState = 24;
  enterRecursionRule(_localctx, 24, CParser::RuleShiftExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(406);
    additiveExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(416);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(414);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ShiftExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleShiftExpression);
          setState(408);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(409);
          match(CParser::LeftShift);
          setState(410);
          additiveExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ShiftExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleShiftExpression);
          setState(411);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(412);
          match(CParser::RightShift);
          setState(413);
          additiveExpression(0);
          break;
        }

        default:
          break;
        } 
      }
      setState(418);
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
  size_t startState = 26;
  enterRecursionRule(_localctx, 26, CParser::RuleRelationalExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(420);
    shiftExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(436);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(434);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelationalExpression);
          setState(422);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(423);
          match(CParser::Less);
          setState(424);
          shiftExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelationalExpression);
          setState(425);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(426);
          match(CParser::Greater);
          setState(427);
          shiftExpression(0);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelationalExpression);
          setState(428);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(429);
          match(CParser::LessEqual);
          setState(430);
          shiftExpression(0);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelationalExpression);
          setState(431);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(432);
          match(CParser::GreaterEqual);
          setState(433);
          shiftExpression(0);
          break;
        }

        default:
          break;
        } 
      }
      setState(438);
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
  size_t startState = 28;
  enterRecursionRule(_localctx, 28, CParser::RuleEqualityExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(440);
    relationalExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(450);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(448);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<EqualityExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleEqualityExpression);
          setState(442);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(443);
          match(CParser::Equal);
          setState(444);
          relationalExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<EqualityExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleEqualityExpression);
          setState(445);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(446);
          match(CParser::NotEqual);
          setState(447);
          relationalExpression(0);
          break;
        }

        default:
          break;
        } 
      }
      setState(452);
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
  size_t startState = 30;
  enterRecursionRule(_localctx, 30, CParser::RuleAndExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(454);
    equalityExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(461);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<AndExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleAndExpression);
        setState(456);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(457);
        match(CParser::And);
        setState(458);
        equalityExpression(0); 
      }
      setState(463);
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
  size_t startState = 32;
  enterRecursionRule(_localctx, 32, CParser::RuleExclusiveOrExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(465);
    andExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(472);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExclusiveOrExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExclusiveOrExpression);
        setState(467);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(468);
        match(CParser::Caret);
        setState(469);
        andExpression(0); 
      }
      setState(474);
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
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, CParser::RuleInclusiveOrExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(476);
    exclusiveOrExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(483);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<InclusiveOrExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleInclusiveOrExpression);
        setState(478);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(479);
        match(CParser::Or);
        setState(480);
        exclusiveOrExpression(0); 
      }
      setState(485);
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
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, CParser::RuleLogicalAndExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(487);
    inclusiveOrExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(494);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LogicalAndExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogicalAndExpression);
        setState(489);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(490);
        match(CParser::AndAnd);
        setState(491);
        inclusiveOrExpression(0); 
      }
      setState(496);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
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
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, CParser::RuleLogicalOrExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(498);
    logicalAndExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(505);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LogicalOrExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogicalOrExpression);
        setState(500);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(501);
        match(CParser::OrOr);
        setState(502);
        logicalAndExpression(0); 
      }
      setState(507);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
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

tree::TerminalNode* CParser::ConditionalExpressionContext::Colon() {
  return getToken(CParser::Colon, 0);
}

CParser::ConditionalExpressionContext* CParser::ConditionalExpressionContext::conditionalExpression() {
  return getRuleContext<CParser::ConditionalExpressionContext>(0);
}

CParser::ExpressionContext* CParser::ConditionalExpressionContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
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
  enterRule(_localctx, 40, CParser::RuleConditionalExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(508);
    logicalOrExpression(0);
    setState(515);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      setState(509);
      match(CParser::Question);
      setState(511);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__0)
        | (1ULL << CParser::T__1)
        | (1ULL << CParser::T__2)
        | (1ULL << CParser::T__3)
        | (1ULL << CParser::T__4)
        | (1ULL << CParser::Sizeof)
        | (1ULL << CParser::Alignof))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 67)) & ((1ULL << (CParser::Generic - 67))
        | (1ULL << (CParser::LeftParen - 67))
        | (1ULL << (CParser::Plus - 67))
        | (1ULL << (CParser::PlusPlus - 67))
        | (1ULL << (CParser::Minus - 67))
        | (1ULL << (CParser::MinusMinus - 67))
        | (1ULL << (CParser::Star - 67))
        | (1ULL << (CParser::And - 67))
        | (1ULL << (CParser::AndAnd - 67))
        | (1ULL << (CParser::Not - 67))
        | (1ULL << (CParser::Tilde - 67))
        | (1ULL << (CParser::Identifier - 67))
        | (1ULL << (CParser::Constant - 67))
        | (1ULL << (CParser::DigitSequence - 67))
        | (1ULL << (CParser::StringLiteral - 67)))) != 0)) {
        setState(510);
        expression(0);
      }
      setState(513);
      match(CParser::Colon);
      setState(514);
      conditionalExpression();
      break;
    }

    default:
      break;
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
  enterRule(_localctx, 42, CParser::RuleAssignmentExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(523);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(517);
      conditionalExpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(518);
      unaryExpression();
      setState(519);
      assignmentOperator();
      setState(520);
      assignmentExpression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(522);
      match(CParser::DigitSequence);
      break;
    }

    default:
      break;
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
  enterRule(_localctx, 44, CParser::RuleAssignmentOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(525);
    _la = _input->LA(1);
    if (!(((((_la - 102) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 102)) & ((1ULL << (CParser::Assign - 102))
      | (1ULL << (CParser::StarAssign - 102))
      | (1ULL << (CParser::DivAssign - 102))
      | (1ULL << (CParser::ModAssign - 102))
      | (1ULL << (CParser::PlusAssign - 102))
      | (1ULL << (CParser::MinusAssign - 102))
      | (1ULL << (CParser::LeftShiftAssign - 102))
      | (1ULL << (CParser::RightShiftAssign - 102))
      | (1ULL << (CParser::AndAssign - 102))
      | (1ULL << (CParser::XorAssign - 102))
      | (1ULL << (CParser::OrAssign - 102)))) != 0))) {
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
  size_t startState = 46;
  enterRecursionRule(_localctx, 46, CParser::RuleExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(528);
    assignmentExpression();
    _ctx->stop = _input->LT(-1);
    setState(535);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpression);
        setState(530);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(531);
        match(CParser::Comma);
        setState(532);
        assignmentExpression(); 
      }
      setState(537);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
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
  enterRule(_localctx, 48, CParser::RuleConstantExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(538);
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
  enterRule(_localctx, 50, CParser::RuleDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(550);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(540);
      declarationSpecifiers();
       typedefLock(); 
      setState(542);
      initDeclaratorList();
      setState(543);
      match(CParser::Semi);
       typedefUnlock(true); 
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(546);
      declarationSpecifiers();
      setState(547);
      match(CParser::Semi);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(549);
      staticAssertDeclaration();
      break;
    }

    default:
      break;
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
  enterRule(_localctx, 52, CParser::RuleDeclarationSpecifiers);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(553); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(552);
              declarationSpecifier();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(555); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
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
  enterRule(_localctx, 54, CParser::RuleDeclarationSpecifiers2);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(558); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(557);
              declarationSpecifier();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(560); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
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

CParser::GccAttributeSpecifierContext* CParser::DeclarationSpecifierContext::gccAttributeSpecifier() {
  return getRuleContext<CParser::GccAttributeSpecifierContext>(0);
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
  enterRule(_localctx, 56, CParser::RuleDeclarationSpecifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(568);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(562);
      storageClassSpecifier();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(563);
      typeSpecifier(0);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(564);
      typeQualifier();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(565);
      functionSpecifier();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(566);
      alignmentSpecifier();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(567);
      gccAttributeSpecifier();
      break;
    }

    default:
      break;
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

std::vector<CParser::InitDeclaratorContext *> CParser::InitDeclaratorListContext::initDeclarator() {
  return getRuleContexts<CParser::InitDeclaratorContext>();
}

CParser::InitDeclaratorContext* CParser::InitDeclaratorListContext::initDeclarator(size_t i) {
  return getRuleContext<CParser::InitDeclaratorContext>(i);
}

std::vector<tree::TerminalNode *> CParser::InitDeclaratorListContext::Comma() {
  return getTokens(CParser::Comma);
}

tree::TerminalNode* CParser::InitDeclaratorListContext::Comma(size_t i) {
  return getToken(CParser::Comma, i);
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
  InitDeclaratorListContext *_localctx = _tracker.createInstance<InitDeclaratorListContext>(_ctx, getState());
  enterRule(_localctx, 58, CParser::RuleInitDeclaratorList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(570);
    initDeclarator();
    setState(575);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::Comma) {
      setState(571);
      match(CParser::Comma);
      setState(572);
      initDeclarator();
      setState(577);
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
  enterRule(_localctx, 60, CParser::RuleInitDeclarator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(583);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(578);
      declarator();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(579);
      declarator();
      setState(580);
      match(CParser::Assign);
      setState(581);
      initializer();
      break;
    }

    default:
      break;
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
  enterRule(_localctx, 62, CParser::RuleStorageClassSpecifier);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(595);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::T__0:
      case CParser::Typedef: {
        enterOuterAlt(_localctx, 1);
        setState(586);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CParser::T__0) {
          setState(585);
          match(CParser::T__0);
        }
        setState(588);
        match(CParser::Typedef);
         inTypedef = true; 
        break;
      }

      case CParser::Extern: {
        enterOuterAlt(_localctx, 2);
        setState(590);
        match(CParser::Extern);
        break;
      }

      case CParser::Static: {
        enterOuterAlt(_localctx, 3);
        setState(591);
        match(CParser::Static);
        break;
      }

      case CParser::ThreadLocal: {
        enterOuterAlt(_localctx, 4);
        setState(592);
        match(CParser::ThreadLocal);
        break;
      }

      case CParser::Auto: {
        enterOuterAlt(_localctx, 5);
        setState(593);
        match(CParser::Auto);
        break;
      }

      case CParser::Register: {
        enterOuterAlt(_localctx, 6);
        setState(594);
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

CParser::TypeNameContext* CParser::TypeSpecifierContext::typeName() {
  return getRuleContext<CParser::TypeNameContext>(0);
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
  size_t startState = 64;
  enterRecursionRule(_localctx, 64, CParser::RuleTypeSpecifier, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(618);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      setState(598);
      _la = _input->LA(1);
      if (!(((((_la - 6) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 6)) & ((1ULL << (CParser::T__5 - 6))
        | (1ULL << (CParser::T__6 - 6))
        | (1ULL << (CParser::T__7 - 6))
        | (1ULL << (CParser::T__8 - 6))
        | (1ULL << (CParser::T__9 - 6))
        | (1ULL << (CParser::T__10 - 6))
        | (1ULL << (CParser::T__11 - 6))
        | (1ULL << (CParser::T__12 - 6))
        | (1ULL << (CParser::Char - 6))
        | (1ULL << (CParser::Double - 6))
        | (1ULL << (CParser::Float - 6))
        | (1ULL << (CParser::Int - 6))
        | (1ULL << (CParser::Long - 6))
        | (1ULL << (CParser::Short - 6))
        | (1ULL << (CParser::Signed - 6))
        | (1ULL << (CParser::Unsigned - 6))
        | (1ULL << (CParser::Void - 6))
        | (1ULL << (CParser::Bool - 6))
        | (1ULL << (CParser::Complex - 6)))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      break;
    }

    case 2: {
      setState(599);
      match(CParser::T__0);
      setState(600);
      match(CParser::LeftParen);
      setState(601);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__10)
        | (1ULL << CParser::T__11)
        | (1ULL << CParser::T__12))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(602);
      match(CParser::RightParen);
      break;
    }

    case 3: {
      setState(603);
      match(CParser::T__13);
      break;
    }

    case 4: {
      setState(604);
      atomicTypeSpecifier();
      break;
    }

    case 5: {
      setState(605);
      structOrUnionSpecifier();
      break;
    }

    case 6: {
      setState(606);
      enumSpecifier();
      break;
    }

    case 7: {
      setState(607);
      typedefName();
      break;
    }

    case 8: {
      setState(608);
      _la = _input->LA(1);
      if (!(_la == CParser::T__14

      || _la == CParser::Typeof)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(609);
      match(CParser::LeftParen);
      setState(610);
      constantExpression();
      setState(611);
      match(CParser::RightParen);
      break;
    }

    case 9: {
      setState(613);
      _la = _input->LA(1);
      if (!(_la == CParser::T__14

      || _la == CParser::Typeof)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(614);
      match(CParser::LeftParen);
      setState(615);
      typeName();
      setState(616);
      match(CParser::RightParen);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(624);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TypeSpecifierContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTypeSpecifier);
        setState(620);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(621);
        pointer(); 
      }
      setState(626);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
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

std::vector<CParser::GccAttributeSpecifierContext *> CParser::StructOrUnionSpecifierContext::gccAttributeSpecifier() {
  return getRuleContexts<CParser::GccAttributeSpecifierContext>();
}

CParser::GccAttributeSpecifierContext* CParser::StructOrUnionSpecifierContext::gccAttributeSpecifier(size_t i) {
  return getRuleContext<CParser::GccAttributeSpecifierContext>(i);
}

tree::TerminalNode* CParser::StructOrUnionSpecifierContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}

std::vector<CParser::StructDeclarationContext *> CParser::StructOrUnionSpecifierContext::structDeclaration() {
  return getRuleContexts<CParser::StructDeclarationContext>();
}

CParser::StructDeclarationContext* CParser::StructOrUnionSpecifierContext::structDeclaration(size_t i) {
  return getRuleContext<CParser::StructDeclarationContext>(i);
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
  enterRule(_localctx, 66, CParser::RuleStructOrUnionSpecifier);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(651);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(627);
      structOrUnion();
      setState(629);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::T__24) {
        setState(628);
        gccAttributeSpecifier();
      }
      setState(632);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::Identifier) {
        setState(631);
        match(CParser::Identifier);
      }
      setState(634);
      match(CParser::LeftBrace);
      setState(638);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(635);
          structDeclaration(); 
        }
        setState(640);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx);
      }
      setState(641);
      match(CParser::RightBrace);
      setState(643);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx)) {
      case 1: {
        setState(642);
        gccAttributeSpecifier();
        break;
      }

      default:
        break;
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(645);
      structOrUnion();
      setState(647);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::T__24) {
        setState(646);
        gccAttributeSpecifier();
      }
      setState(649);
      match(CParser::Identifier);
      break;
    }

    default:
      break;
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
  enterRule(_localctx, 68, CParser::RuleStructOrUnion);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(653);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(663);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(655);
      specifierQualifierList();
      setState(657);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::T__24 || ((((_la - 72) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 72)) & ((1ULL << (CParser::LeftParen - 72))
        | (1ULL << (CParser::Star - 72))
        | (1ULL << (CParser::Caret - 72))
        | (1ULL << (CParser::Colon - 72))
        | (1ULL << (CParser::Identifier - 72)))) != 0)) {
        setState(656);
        structDeclaratorList();
      }
      setState(659);
      match(CParser::Semi);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(661);
      match(CParser::Semi);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(662);
      staticAssertDeclaration();
      break;
    }

    default:
      break;
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

std::vector<CParser::TypeSpecifierContext *> CParser::SpecifierQualifierListContext::typeSpecifier() {
  return getRuleContexts<CParser::TypeSpecifierContext>();
}

CParser::TypeSpecifierContext* CParser::SpecifierQualifierListContext::typeSpecifier(size_t i) {
  return getRuleContext<CParser::TypeSpecifierContext>(i);
}

std::vector<CParser::TypeQualifierContext *> CParser::SpecifierQualifierListContext::typeQualifier() {
  return getRuleContexts<CParser::TypeQualifierContext>();
}

CParser::TypeQualifierContext* CParser::SpecifierQualifierListContext::typeQualifier(size_t i) {
  return getRuleContext<CParser::TypeQualifierContext>(i);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(667); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(667);
              _errHandler->sync(this);
              switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx)) {
              case 1: {
                setState(665);
                typeSpecifier(0);
                break;
              }

              case 2: {
                setState(666);
                typeQualifier();
                break;
              }

              default:
                break;
              }
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(669); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
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

std::vector<CParser::StructDeclaratorContext *> CParser::StructDeclaratorListContext::structDeclarator() {
  return getRuleContexts<CParser::StructDeclaratorContext>();
}

CParser::StructDeclaratorContext* CParser::StructDeclaratorListContext::structDeclarator(size_t i) {
  return getRuleContext<CParser::StructDeclaratorContext>(i);
}

std::vector<tree::TerminalNode *> CParser::StructDeclaratorListContext::Comma() {
  return getTokens(CParser::Comma);
}

tree::TerminalNode* CParser::StructDeclaratorListContext::Comma(size_t i) {
  return getToken(CParser::Comma, i);
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
  StructDeclaratorListContext *_localctx = _tracker.createInstance<StructDeclaratorListContext>(_ctx, getState());
  enterRule(_localctx, 74, CParser::RuleStructDeclaratorList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(671);
    structDeclarator();
    setState(676);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::Comma) {
      setState(672);
      match(CParser::Comma);
      setState(673);
      structDeclarator();
      setState(678);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(685);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(679);
      declarator();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(681);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::T__24 || ((((_la - 72) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 72)) & ((1ULL << (CParser::LeftParen - 72))
        | (1ULL << (CParser::Star - 72))
        | (1ULL << (CParser::Caret - 72))
        | (1ULL << (CParser::Identifier - 72)))) != 0)) {
        setState(680);
        declarator();
      }
      setState(683);
      match(CParser::Colon);
      setState(684);
      constantExpression();
      break;
    }

    default:
      break;
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

std::vector<CParser::GccAttributeSpecifierContext *> CParser::EnumSpecifierContext::gccAttributeSpecifier() {
  return getRuleContexts<CParser::GccAttributeSpecifierContext>();
}

CParser::GccAttributeSpecifierContext* CParser::EnumSpecifierContext::gccAttributeSpecifier(size_t i) {
  return getRuleContext<CParser::GccAttributeSpecifierContext>(i);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(719);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(687);
      match(CParser::Enum);
      setState(689);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::T__24) {
        setState(688);
        gccAttributeSpecifier();
      }
      setState(692);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::Identifier) {
        setState(691);
        match(CParser::Identifier);
      }
      setState(694);
      match(CParser::LeftBrace);
      setState(695);
      enumeratorList(0);
      setState(696);
      match(CParser::RightBrace);
      setState(698);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx)) {
      case 1: {
        setState(697);
        gccAttributeSpecifier();
        break;
      }

      default:
        break;
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(700);
      match(CParser::Enum);
      setState(702);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::T__24) {
        setState(701);
        gccAttributeSpecifier();
      }
      setState(705);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::Identifier) {
        setState(704);
        match(CParser::Identifier);
      }
      setState(707);
      match(CParser::LeftBrace);
      setState(708);
      enumeratorList(0);
      setState(709);
      match(CParser::Comma);
      setState(710);
      match(CParser::RightBrace);
      setState(712);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx)) {
      case 1: {
        setState(711);
        gccAttributeSpecifier();
        break;
      }

      default:
        break;
      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(714);
      match(CParser::Enum);
      setState(716);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::T__24) {
        setState(715);
        gccAttributeSpecifier();
      }
      setState(718);
      match(CParser::Identifier);
      break;
    }

    default:
      break;
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

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(722);
    enumerator();
    _ctx->stop = _input->LT(-1);
    setState(729);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 64, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<EnumeratorListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleEnumeratorList);
        setState(724);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(725);
        match(CParser::Comma);
        setState(726);
        enumerator(); 
      }
      setState(731);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 64, _ctx);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(737);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(732);
      enumerationConstant();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(733);
      enumerationConstant();
      setState(734);
      match(CParser::Assign);
      setState(735);
      constantExpression();
      break;
    }

    default:
      break;
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(739);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(741);
    match(CParser::Atomic);
    setState(742);
    match(CParser::LeftParen);
    setState(743);
    typeName();
    setState(744);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(746);
    _la = _input->LA(1);
    if (!(((((_la - 16) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 16)) & ((1ULL << (CParser::T__15 - 16))
      | (1ULL << (CParser::T__16 - 16))
      | (1ULL << (CParser::Const - 16))
      | (1ULL << (CParser::Restrict - 16))
      | (1ULL << (CParser::Volatile - 16))
      | (1ULL << (CParser::Atomic - 16)))) != 0))) {
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(753);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::T__17:
      case CParser::T__18:
      case CParser::T__19:
      case CParser::Inline:
      case CParser::Noreturn: {
        enterOuterAlt(_localctx, 1);
        setState(748);
        _la = _input->LA(1);
        if (!(((((_la - 18) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 18)) & ((1ULL << (CParser::T__17 - 18))
          | (1ULL << (CParser::T__18 - 18))
          | (1ULL << (CParser::T__19 - 18))
          | (1ULL << (CParser::Inline - 18))
          | (1ULL << (CParser::Noreturn - 18)))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

      case CParser::T__20: {
        enterOuterAlt(_localctx, 2);
        setState(749);
        match(CParser::T__20);
        setState(750);
        match(CParser::LeftParen);
        setState(751);
        match(CParser::Identifier);
        setState(752);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(765);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(755);
      match(CParser::Alignas);
      setState(756);
      match(CParser::LeftParen);
      setState(757);
      typeName();
      setState(758);
      match(CParser::RightParen);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(760);
      match(CParser::Alignas);
      setState(761);
      match(CParser::LeftParen);
      setState(762);
      constantExpression();
      setState(763);
      match(CParser::RightParen);
      break;
    }

    default:
      break;
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

CParser::GccAttributeSpecifierContext* CParser::DeclaratorContext::gccAttributeSpecifier() {
  return getRuleContext<CParser::GccAttributeSpecifierContext>(0);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(768);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::Star

    || _la == CParser::Caret) {
      setState(767);
      pointer();
    }
    setState(771);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::T__24) {
      setState(770);
      gccAttributeSpecifier();
    }
    setState(773);
    directDeclarator(0);
    setState(777);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(774);
        gccDeclaratorExtension(); 
      }
      setState(779);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(798);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx)) {
    case 1: {
      setState(781);
      dynamic_cast<DirectDeclaratorContext *>(_localctx)->identifierToken = match(CParser::Identifier);
       addTypeName(dynamic_cast<DirectDeclaratorContext *>(_localctx)->identifierToken); 
      break;
    }

    case 2: {
      setState(783);
      match(CParser::LeftParen);
      setState(784);
      declarator();
      setState(785);
      match(CParser::RightParen);
      break;
    }

    case 3: {
      setState(787);
      dynamic_cast<DirectDeclaratorContext *>(_localctx)->identifierToken = match(CParser::Identifier);
      setState(788);
      match(CParser::Colon);
      setState(789);
      match(CParser::DigitSequence);
      break;
    }

    case 4: {
      setState(790);
      match(CParser::LeftParen);
      setState(792);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx)) {
      case 1: {
        setState(791);
        typeSpecifier(0);
        break;
      }

      default:
        break;
      }
      setState(794);
      pointer();
      setState(795);
      directDeclarator(0);
      setState(796);
      match(CParser::RightParen);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(849);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(847);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 78, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(800);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(801);
          match(CParser::LeftBracket);
          setState(803);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (((((_la - 16) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 16)) & ((1ULL << (CParser::T__15 - 16))
            | (1ULL << (CParser::T__16 - 16))
            | (1ULL << (CParser::Const - 16))
            | (1ULL << (CParser::Restrict - 16))
            | (1ULL << (CParser::Volatile - 16))
            | (1ULL << (CParser::Atomic - 16)))) != 0)) {
            setState(802);
            typeQualifierList(0);
          }
          setState(806);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CParser::T__0)
            | (1ULL << CParser::T__1)
            | (1ULL << CParser::T__2)
            | (1ULL << CParser::T__3)
            | (1ULL << CParser::T__4)
            | (1ULL << CParser::Sizeof)
            | (1ULL << CParser::Alignof))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 67)) & ((1ULL << (CParser::Generic - 67))
            | (1ULL << (CParser::LeftParen - 67))
            | (1ULL << (CParser::Plus - 67))
            | (1ULL << (CParser::PlusPlus - 67))
            | (1ULL << (CParser::Minus - 67))
            | (1ULL << (CParser::MinusMinus - 67))
            | (1ULL << (CParser::Star - 67))
            | (1ULL << (CParser::And - 67))
            | (1ULL << (CParser::AndAnd - 67))
            | (1ULL << (CParser::Not - 67))
            | (1ULL << (CParser::Tilde - 67))
            | (1ULL << (CParser::Identifier - 67))
            | (1ULL << (CParser::Constant - 67))
            | (1ULL << (CParser::DigitSequence - 67))
            | (1ULL << (CParser::StringLiteral - 67)))) != 0)) {
            setState(805);
            assignmentExpression();
          }
          setState(808);
          match(CParser::RightBracket);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(809);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(810);
          match(CParser::LeftBracket);
          setState(811);
          match(CParser::Static);
          setState(813);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (((((_la - 16) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 16)) & ((1ULL << (CParser::T__15 - 16))
            | (1ULL << (CParser::T__16 - 16))
            | (1ULL << (CParser::Const - 16))
            | (1ULL << (CParser::Restrict - 16))
            | (1ULL << (CParser::Volatile - 16))
            | (1ULL << (CParser::Atomic - 16)))) != 0)) {
            setState(812);
            typeQualifierList(0);
          }
          setState(815);
          assignmentExpression();
          setState(816);
          match(CParser::RightBracket);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(818);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(819);
          match(CParser::LeftBracket);
          setState(820);
          typeQualifierList(0);
          setState(821);
          match(CParser::Static);
          setState(822);
          assignmentExpression();
          setState(823);
          match(CParser::RightBracket);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(825);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(826);
          match(CParser::LeftBracket);
          setState(828);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (((((_la - 16) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 16)) & ((1ULL << (CParser::T__15 - 16))
            | (1ULL << (CParser::T__16 - 16))
            | (1ULL << (CParser::Const - 16))
            | (1ULL << (CParser::Restrict - 16))
            | (1ULL << (CParser::Volatile - 16))
            | (1ULL << (CParser::Atomic - 16)))) != 0)) {
            setState(827);
            typeQualifierList(0);
          }
          setState(830);
          match(CParser::Star);
          setState(831);
          match(CParser::RightBracket);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(832);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(833);
          match(CParser::LeftParen);
           typedefLock(); 
          setState(835);
          parameterTypeList();
           typedefUnlock(); 
          setState(837);
          match(CParser::RightParen);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(839);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(840);
          match(CParser::LeftParen);
           typedefLock(); 
          setState(843);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CParser::Identifier) {
            setState(842);
            identifierList(0);
          }
           typedefUnlock(); 
          setState(846);
          match(CParser::RightParen);
          break;
        }

        default:
          break;
        } 
      }
      setState(851);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(861);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::T__21:
      case CParser::T__22:
      case CParser::T__23: {
        enterOuterAlt(_localctx, 1);
        setState(852);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CParser::T__21)
          | (1ULL << CParser::T__22)
          | (1ULL << CParser::T__23))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(853);
        match(CParser::LeftParen);
        setState(855); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(854);
          match(CParser::StringLiteral);
          setState(857); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == CParser::StringLiteral);
        setState(859);
        match(CParser::RightParen);
        break;
      }

      case CParser::T__24: {
        enterOuterAlt(_localctx, 2);
        setState(860);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(863);
    match(CParser::T__24);
    setState(864);
    match(CParser::LeftParen);
    setState(865);
    match(CParser::LeftParen);
    setState(866);
    gccAttributeList();
    setState(867);
    match(CParser::RightParen);
    setState(868);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(879);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 83, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(870);
      gccAttribute();
      setState(875);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CParser::Comma) {
        setState(871);
        match(CParser::Comma);
        setState(872);
        gccAttribute();
        setState(877);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);

      break;
    }

    default:
      break;
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(890);
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
      case CParser::T__17:
      case CParser::T__18:
      case CParser::T__19:
      case CParser::T__20:
      case CParser::T__21:
      case CParser::T__22:
      case CParser::T__23:
      case CParser::T__24:
      case CParser::T__25:
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
        setState(881);
        _la = _input->LA(1);
        if (_la == 0 || _la == Token::EOF || (((((_la - 72) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 72)) & ((1ULL << (CParser::LeftParen - 72))
          | (1ULL << (CParser::RightParen - 72))
          | (1ULL << (CParser::Comma - 72)))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(887);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CParser::LeftParen) {
          setState(882);
          match(CParser::LeftParen);
          setState(884);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CParser::T__0)
            | (1ULL << CParser::T__1)
            | (1ULL << CParser::T__2)
            | (1ULL << CParser::T__3)
            | (1ULL << CParser::T__4)
            | (1ULL << CParser::Sizeof)
            | (1ULL << CParser::Alignof))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 67)) & ((1ULL << (CParser::Generic - 67))
            | (1ULL << (CParser::LeftParen - 67))
            | (1ULL << (CParser::Plus - 67))
            | (1ULL << (CParser::PlusPlus - 67))
            | (1ULL << (CParser::Minus - 67))
            | (1ULL << (CParser::MinusMinus - 67))
            | (1ULL << (CParser::Star - 67))
            | (1ULL << (CParser::And - 67))
            | (1ULL << (CParser::AndAnd - 67))
            | (1ULL << (CParser::Not - 67))
            | (1ULL << (CParser::Tilde - 67))
            | (1ULL << (CParser::Identifier - 67))
            | (1ULL << (CParser::Constant - 67))
            | (1ULL << (CParser::DigitSequence - 67))
            | (1ULL << (CParser::StringLiteral - 67)))) != 0)) {
            setState(883);
            argumentExpressionList();
          }
          setState(886);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(899);
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
      | (1ULL << CParser::T__17)
      | (1ULL << CParser::T__18)
      | (1ULL << CParser::T__19)
      | (1ULL << CParser::T__20)
      | (1ULL << CParser::T__21)
      | (1ULL << CParser::T__22)
      | (1ULL << CParser::T__23)
      | (1ULL << CParser::T__24)
      | (1ULL << CParser::T__25)
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
      | (1ULL << CParser::Alignof))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (CParser::Atomic - 64))
      | (1ULL << (CParser::Bool - 64))
      | (1ULL << (CParser::Complex - 64))
      | (1ULL << (CParser::Generic - 64))
      | (1ULL << (CParser::Imaginary - 64))
      | (1ULL << (CParser::Noreturn - 64))
      | (1ULL << (CParser::StaticAssert - 64))
      | (1ULL << (CParser::ThreadLocal - 64))
      | (1ULL << (CParser::LeftParen - 64))
      | (1ULL << (CParser::LeftBracket - 64))
      | (1ULL << (CParser::RightBracket - 64))
      | (1ULL << (CParser::LeftBrace - 64))
      | (1ULL << (CParser::RightBrace - 64))
      | (1ULL << (CParser::Less - 64))
      | (1ULL << (CParser::LessEqual - 64))
      | (1ULL << (CParser::Greater - 64))
      | (1ULL << (CParser::GreaterEqual - 64))
      | (1ULL << (CParser::LeftShift - 64))
      | (1ULL << (CParser::RightShift - 64))
      | (1ULL << (CParser::Plus - 64))
      | (1ULL << (CParser::PlusPlus - 64))
      | (1ULL << (CParser::Minus - 64))
      | (1ULL << (CParser::MinusMinus - 64))
      | (1ULL << (CParser::Star - 64))
      | (1ULL << (CParser::Div - 64))
      | (1ULL << (CParser::Mod - 64))
      | (1ULL << (CParser::And - 64))
      | (1ULL << (CParser::Or - 64))
      | (1ULL << (CParser::AndAnd - 64))
      | (1ULL << (CParser::OrOr - 64))
      | (1ULL << (CParser::Caret - 64))
      | (1ULL << (CParser::Not - 64))
      | (1ULL << (CParser::Tilde - 64))
      | (1ULL << (CParser::Question - 64))
      | (1ULL << (CParser::Colon - 64))
      | (1ULL << (CParser::Semi - 64))
      | (1ULL << (CParser::Comma - 64))
      | (1ULL << (CParser::Assign - 64))
      | (1ULL << (CParser::StarAssign - 64))
      | (1ULL << (CParser::DivAssign - 64))
      | (1ULL << (CParser::ModAssign - 64))
      | (1ULL << (CParser::PlusAssign - 64))
      | (1ULL << (CParser::MinusAssign - 64))
      | (1ULL << (CParser::LeftShiftAssign - 64))
      | (1ULL << (CParser::RightShiftAssign - 64))
      | (1ULL << (CParser::AndAssign - 64))
      | (1ULL << (CParser::XorAssign - 64))
      | (1ULL << (CParser::OrAssign - 64))
      | (1ULL << (CParser::Equal - 64))
      | (1ULL << (CParser::NotEqual - 64))
      | (1ULL << (CParser::Arrow - 64))
      | (1ULL << (CParser::Dot - 64))
      | (1ULL << (CParser::Ellipsis - 64))
      | (1ULL << (CParser::Identifier - 64))
      | (1ULL << (CParser::Constant - 64))
      | (1ULL << (CParser::DigitSequence - 64))
      | (1ULL << (CParser::StringLiteral - 64))
      | (1ULL << (CParser::ComplexDefine - 64))
      | (1ULL << (CParser::IncludeDirective - 64))
      | (1ULL << (CParser::LineAfterPreprocessing - 64))
      | (1ULL << (CParser::LineDirective - 64))
      | (1ULL << (CParser::PragmaDirective - 64))
      | (1ULL << (CParser::Whitespace - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 128)) & ((1ULL << (CParser::Newline - 128))
      | (1ULL << (CParser::BlockComment - 128))
      | (1ULL << (CParser::LineComment - 128)))) != 0)) {
      setState(897);
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
        case CParser::T__17:
        case CParser::T__18:
        case CParser::T__19:
        case CParser::T__20:
        case CParser::T__21:
        case CParser::T__22:
        case CParser::T__23:
        case CParser::T__24:
        case CParser::T__25:
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
          setState(892);
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
          setState(893);
          match(CParser::LeftParen);
          setState(894);
          nestedParenthesesBlock();
          setState(895);
          match(CParser::RightParen);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(901);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(920);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 93, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(902);
      match(CParser::Star);
      setState(904);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 89, _ctx)) {
      case 1: {
        setState(903);
        typeQualifierList(0);
        break;
      }

      default:
        break;
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(906);
      match(CParser::Star);
      setState(908);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 16) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 16)) & ((1ULL << (CParser::T__15 - 16))
        | (1ULL << (CParser::T__16 - 16))
        | (1ULL << (CParser::Const - 16))
        | (1ULL << (CParser::Restrict - 16))
        | (1ULL << (CParser::Volatile - 16))
        | (1ULL << (CParser::Atomic - 16)))) != 0)) {
        setState(907);
        typeQualifierList(0);
      }
      setState(910);
      pointer();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(911);
      match(CParser::Caret);
      setState(913);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 91, _ctx)) {
      case 1: {
        setState(912);
        typeQualifierList(0);
        break;
      }

      default:
        break;
      }
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(915);
      match(CParser::Caret);
      setState(917);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 16) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 16)) & ((1ULL << (CParser::T__15 - 16))
        | (1ULL << (CParser::T__16 - 16))
        | (1ULL << (CParser::Const - 16))
        | (1ULL << (CParser::Restrict - 16))
        | (1ULL << (CParser::Volatile - 16))
        | (1ULL << (CParser::Atomic - 16)))) != 0)) {
        setState(916);
        typeQualifierList(0);
      }
      setState(919);
      pointer();
      break;
    }

    default:
      break;
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

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(923);
    typeQualifier();
    _ctx->stop = _input->LT(-1);
    setState(929);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 94, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TypeQualifierListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTypeQualifierList);
        setState(925);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(926);
        typeQualifier(); 
      }
      setState(931);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 94, _ctx);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(937);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 95, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(932);
      parameterList();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(933);
      parameterList();
      setState(934);
      match(CParser::Comma);
      setState(935);
      match(CParser::Ellipsis);
      break;
    }

    default:
      break;
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

std::vector<CParser::ParameterDeclarationContext *> CParser::ParameterListContext::parameterDeclaration() {
  return getRuleContexts<CParser::ParameterDeclarationContext>();
}

CParser::ParameterDeclarationContext* CParser::ParameterListContext::parameterDeclaration(size_t i) {
  return getRuleContext<CParser::ParameterDeclarationContext>(i);
}

std::vector<tree::TerminalNode *> CParser::ParameterListContext::Comma() {
  return getTokens(CParser::Comma);
}

tree::TerminalNode* CParser::ParameterListContext::Comma(size_t i) {
  return getToken(CParser::Comma, i);
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
  ParameterListContext *_localctx = _tracker.createInstance<ParameterListContext>(_ctx, getState());
  enterRule(_localctx, 114, CParser::RuleParameterList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(939);
    parameterDeclaration();
    setState(944);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 96, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(940);
        match(CParser::Comma);
        setState(941);
        parameterDeclaration(); 
      }
      setState(946);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 96, _ctx);
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
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(954);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 98, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(947);
      declarationSpecifiers();
      setState(948);
      declarator();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(950);
      declarationSpecifiers2();
      setState(952);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 72) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 72)) & ((1ULL << (CParser::LeftParen - 72))
        | (1ULL << (CParser::LeftBracket - 72))
        | (1ULL << (CParser::Star - 72))
        | (1ULL << (CParser::Caret - 72)))) != 0)) {
        setState(951);
        abstractDeclarator();
      }
      break;
    }

    default:
      break;
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

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(957);
    match(CParser::Identifier);
    _ctx->stop = _input->LT(-1);
    setState(964);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 99, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<IdentifierListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleIdentifierList);
        setState(959);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(960);
        match(CParser::Comma);
        setState(961);
        match(CParser::Identifier); 
      }
      setState(966);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 99, _ctx);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(967);
    specifierQualifierList();
    setState(969);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 72) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 72)) & ((1ULL << (CParser::LeftParen - 72))
      | (1ULL << (CParser::LeftBracket - 72))
      | (1ULL << (CParser::Star - 72))
      | (1ULL << (CParser::Caret - 72)))) != 0)) {
      setState(968);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(982);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 103, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(971);
      pointer();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(973);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::Star

      || _la == CParser::Caret) {
        setState(972);
        pointer();
      }
      setState(975);
      directAbstractDeclarator(0);
      setState(979);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__21)
        | (1ULL << CParser::T__22)
        | (1ULL << CParser::T__23)
        | (1ULL << CParser::T__24))) != 0)) {
        setState(976);
        gccDeclaratorExtension();
        setState(981);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    default:
      break;
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1030);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 110, _ctx)) {
    case 1: {
      setState(985);
      match(CParser::LeftParen);
      setState(986);
      abstractDeclarator();
      setState(987);
      match(CParser::RightParen);
      setState(991);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 104, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(988);
          gccDeclaratorExtension(); 
        }
        setState(993);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 104, _ctx);
      }
      break;
    }

    case 2: {
      setState(994);
      match(CParser::LeftBracket);
      setState(996);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 16) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 16)) & ((1ULL << (CParser::T__15 - 16))
        | (1ULL << (CParser::T__16 - 16))
        | (1ULL << (CParser::Const - 16))
        | (1ULL << (CParser::Restrict - 16))
        | (1ULL << (CParser::Volatile - 16))
        | (1ULL << (CParser::Atomic - 16)))) != 0)) {
        setState(995);
        typeQualifierList(0);
      }
      setState(999);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__0)
        | (1ULL << CParser::T__1)
        | (1ULL << CParser::T__2)
        | (1ULL << CParser::T__3)
        | (1ULL << CParser::T__4)
        | (1ULL << CParser::Sizeof)
        | (1ULL << CParser::Alignof))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 67)) & ((1ULL << (CParser::Generic - 67))
        | (1ULL << (CParser::LeftParen - 67))
        | (1ULL << (CParser::Plus - 67))
        | (1ULL << (CParser::PlusPlus - 67))
        | (1ULL << (CParser::Minus - 67))
        | (1ULL << (CParser::MinusMinus - 67))
        | (1ULL << (CParser::Star - 67))
        | (1ULL << (CParser::And - 67))
        | (1ULL << (CParser::AndAnd - 67))
        | (1ULL << (CParser::Not - 67))
        | (1ULL << (CParser::Tilde - 67))
        | (1ULL << (CParser::Identifier - 67))
        | (1ULL << (CParser::Constant - 67))
        | (1ULL << (CParser::DigitSequence - 67))
        | (1ULL << (CParser::StringLiteral - 67)))) != 0)) {
        setState(998);
        assignmentExpression();
      }
      setState(1001);
      match(CParser::RightBracket);
      break;
    }

    case 3: {
      setState(1002);
      match(CParser::LeftBracket);
      setState(1003);
      match(CParser::Static);
      setState(1005);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 16) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 16)) & ((1ULL << (CParser::T__15 - 16))
        | (1ULL << (CParser::T__16 - 16))
        | (1ULL << (CParser::Const - 16))
        | (1ULL << (CParser::Restrict - 16))
        | (1ULL << (CParser::Volatile - 16))
        | (1ULL << (CParser::Atomic - 16)))) != 0)) {
        setState(1004);
        typeQualifierList(0);
      }
      setState(1007);
      assignmentExpression();
      setState(1008);
      match(CParser::RightBracket);
      break;
    }

    case 4: {
      setState(1010);
      match(CParser::LeftBracket);
      setState(1011);
      typeQualifierList(0);
      setState(1012);
      match(CParser::Static);
      setState(1013);
      assignmentExpression();
      setState(1014);
      match(CParser::RightBracket);
      break;
    }

    case 5: {
      setState(1016);
      match(CParser::LeftBracket);
      setState(1017);
      match(CParser::Star);
      setState(1018);
      match(CParser::RightBracket);
      break;
    }

    case 6: {
      setState(1019);
      match(CParser::LeftParen);
      setState(1021);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 108, _ctx)) {
      case 1: {
        setState(1020);
        parameterTypeList();
        break;
      }

      default:
        break;
      }
      setState(1023);
      match(CParser::RightParen);
      setState(1027);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 109, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(1024);
          gccDeclaratorExtension(); 
        }
        setState(1029);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 109, _ctx);
      }
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(1075);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 117, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(1073);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 116, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(1032);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(1033);
          match(CParser::LeftBracket);
          setState(1035);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (((((_la - 16) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 16)) & ((1ULL << (CParser::T__15 - 16))
            | (1ULL << (CParser::T__16 - 16))
            | (1ULL << (CParser::Const - 16))
            | (1ULL << (CParser::Restrict - 16))
            | (1ULL << (CParser::Volatile - 16))
            | (1ULL << (CParser::Atomic - 16)))) != 0)) {
            setState(1034);
            typeQualifierList(0);
          }
          setState(1038);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CParser::T__0)
            | (1ULL << CParser::T__1)
            | (1ULL << CParser::T__2)
            | (1ULL << CParser::T__3)
            | (1ULL << CParser::T__4)
            | (1ULL << CParser::Sizeof)
            | (1ULL << CParser::Alignof))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 67)) & ((1ULL << (CParser::Generic - 67))
            | (1ULL << (CParser::LeftParen - 67))
            | (1ULL << (CParser::Plus - 67))
            | (1ULL << (CParser::PlusPlus - 67))
            | (1ULL << (CParser::Minus - 67))
            | (1ULL << (CParser::MinusMinus - 67))
            | (1ULL << (CParser::Star - 67))
            | (1ULL << (CParser::And - 67))
            | (1ULL << (CParser::AndAnd - 67))
            | (1ULL << (CParser::Not - 67))
            | (1ULL << (CParser::Tilde - 67))
            | (1ULL << (CParser::Identifier - 67))
            | (1ULL << (CParser::Constant - 67))
            | (1ULL << (CParser::DigitSequence - 67))
            | (1ULL << (CParser::StringLiteral - 67)))) != 0)) {
            setState(1037);
            assignmentExpression();
          }
          setState(1040);
          match(CParser::RightBracket);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(1041);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(1042);
          match(CParser::LeftBracket);
          setState(1043);
          match(CParser::Static);
          setState(1045);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (((((_la - 16) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 16)) & ((1ULL << (CParser::T__15 - 16))
            | (1ULL << (CParser::T__16 - 16))
            | (1ULL << (CParser::Const - 16))
            | (1ULL << (CParser::Restrict - 16))
            | (1ULL << (CParser::Volatile - 16))
            | (1ULL << (CParser::Atomic - 16)))) != 0)) {
            setState(1044);
            typeQualifierList(0);
          }
          setState(1047);
          assignmentExpression();
          setState(1048);
          match(CParser::RightBracket);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(1050);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(1051);
          match(CParser::LeftBracket);
          setState(1052);
          typeQualifierList(0);
          setState(1053);
          match(CParser::Static);
          setState(1054);
          assignmentExpression();
          setState(1055);
          match(CParser::RightBracket);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(1057);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(1058);
          match(CParser::LeftBracket);
          setState(1059);
          match(CParser::Star);
          setState(1060);
          match(CParser::RightBracket);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(1061);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(1062);
          match(CParser::LeftParen);
          setState(1064);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 114, _ctx)) {
          case 1: {
            setState(1063);
            parameterTypeList();
            break;
          }

          default:
            break;
          }
          setState(1066);
          match(CParser::RightParen);
          setState(1070);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 115, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(1067);
              gccDeclaratorExtension(); 
            }
            setState(1072);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 115, _ctx);
          }
          break;
        }

        default:
          break;
        } 
      }
      setState(1077);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 117, _ctx);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1078);

    if (!( isTypeName(getCurrentToken()) )) throw FailedPredicateException(this, " isTypeName(getCurrentToken()) ");
    setState(1079);
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

tree::TerminalNode* CParser::InitializerContext::RightBrace() {
  return getToken(CParser::RightBrace, 0);
}

CParser::InitializerListContext* CParser::InitializerContext::initializerList() {
  return getRuleContext<CParser::InitializerListContext>(0);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1093);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 118, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1081);
      assignmentExpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1082);
      match(CParser::LeftBrace);
      setState(1083);
      match(CParser::RightBrace);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1084);
      match(CParser::LeftBrace);
      setState(1085);
      initializerList(0);
      setState(1086);
      match(CParser::RightBrace);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1088);
      match(CParser::LeftBrace);
      setState(1089);
      initializerList(0);
      setState(1090);
      match(CParser::Comma);
      setState(1091);
      match(CParser::RightBrace);
      break;
    }

    default:
      break;
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1097);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::LeftBracket

    || _la == CParser::Dot) {
      setState(1096);
      designation();
    }
    setState(1099);
    initializer();
    _ctx->stop = _input->LT(-1);
    setState(1109);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 121, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<InitializerListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleInitializerList);
        setState(1101);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1102);
        match(CParser::Comma);
        setState(1104);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CParser::LeftBracket

        || _la == CParser::Dot) {
          setState(1103);
          designation();
        }
        setState(1106);
        initializer(); 
      }
      setState(1111);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 121, _ctx);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1112);
    designatorList(0);
    setState(1113);
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

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1116);
    designator();
    _ctx->stop = _input->LT(-1);
    setState(1122);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 122, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<DesignatorListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleDesignatorList);
        setState(1118);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1119);
        designator(); 
      }
      setState(1124);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 122, _ctx);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1131);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::LeftBracket: {
        enterOuterAlt(_localctx, 1);
        setState(1125);
        match(CParser::LeftBracket);
        setState(1126);
        constantExpression();
        setState(1127);
        match(CParser::RightBracket);
        break;
      }

      case CParser::Dot: {
        enterOuterAlt(_localctx, 2);
        setState(1129);
        match(CParser::Dot);
        setState(1130);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1133);
    match(CParser::StaticAssert);
    setState(1134);
    match(CParser::LeftParen);
    setState(1135);
    constantExpression();
    setState(1136);
    match(CParser::Comma);
    setState(1138); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1137);
      match(CParser::StringLiteral);
      setState(1140); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == CParser::StringLiteral);
    setState(1142);
    match(CParser::RightParen);
    setState(1143);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1152);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 125, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1145);
      labeledStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1146);
      compoundStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1147);
      expressionStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1148);
      selectionStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(1149);
      iterationStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(1150);
      jumpStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(1151);
      asmStatement();
      break;
    }

    default:
      break;
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1169);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(1154);
        match(CParser::Identifier);
        setState(1155);
        match(CParser::Colon);
        setState(1156);
        statement();
        break;
      }

      case CParser::Case: {
        enterOuterAlt(_localctx, 2);
        setState(1157);
        match(CParser::Case);
        setState(1158);
        constantExpression();
        setState(1161);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CParser::Ellipsis) {
          setState(1159);
          match(CParser::Ellipsis);
          setState(1160);
          constantExpression();
        }
        setState(1163);
        match(CParser::Colon);
        setState(1164);
        statement();
        break;
      }

      case CParser::Default: {
        enterOuterAlt(_localctx, 3);
        setState(1166);
        match(CParser::Default);
        setState(1167);
        match(CParser::Colon);
        setState(1168);
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

std::vector<CParser::BlockItemContext *> CParser::CompoundStatementContext::blockItem() {
  return getRuleContexts<CParser::BlockItemContext>();
}

CParser::BlockItemContext* CParser::CompoundStatementContext::blockItem(size_t i) {
  return getRuleContext<CParser::BlockItemContext>(i);
}

std::vector<CParser::LabelDeclarationContext *> CParser::CompoundStatementContext::labelDeclaration() {
  return getRuleContexts<CParser::LabelDeclarationContext>();
}

CParser::LabelDeclarationContext* CParser::CompoundStatementContext::labelDeclaration(size_t i) {
  return getRuleContext<CParser::LabelDeclarationContext>(i);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(1193);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 131, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1171);
      match(CParser::LeftBrace);
      setState(1175);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 128, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(1172);
          blockItem(); 
        }
        setState(1177);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 128, _ctx);
      }
      setState(1178);
      match(CParser::RightBrace);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1179);
      match(CParser::LeftBrace);
      setState(1181); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(1180);
                labelDeclaration();
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(1183); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 129, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(1188);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 130, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(1185);
          blockItem(); 
        }
        setState(1190);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 130, _ctx);
      }
      setState(1191);
      match(CParser::RightBrace);
      break;
    }

    default:
      break;
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
  enterRule(_localctx, 146, CParser::RuleBlockItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1197);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 132, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1195);
      statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1196);
      declaration();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LabelDeclarationContext ------------------------------------------------------------------

CParser::LabelDeclarationContext::LabelDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::IdentifierListContext* CParser::LabelDeclarationContext::identifierList() {
  return getRuleContext<CParser::IdentifierListContext>(0);
}

tree::TerminalNode* CParser::LabelDeclarationContext::Semi() {
  return getToken(CParser::Semi, 0);
}


size_t CParser::LabelDeclarationContext::getRuleIndex() const {
  return CParser::RuleLabelDeclaration;
}

void CParser::LabelDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLabelDeclaration(this);
}

void CParser::LabelDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLabelDeclaration(this);
}


antlrcpp::Any CParser::LabelDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitLabelDeclaration(this);
  else
    return visitor->visitChildren(this);
}

CParser::LabelDeclarationContext* CParser::labelDeclaration() {
  LabelDeclarationContext *_localctx = _tracker.createInstance<LabelDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 148, CParser::RuleLabelDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1199);
    match(CParser::T__25);
    setState(1200);
    identifierList(0);
    setState(1201);
    match(CParser::Semi);
   
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1204);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__0)
      | (1ULL << CParser::T__1)
      | (1ULL << CParser::T__2)
      | (1ULL << CParser::T__3)
      | (1ULL << CParser::T__4)
      | (1ULL << CParser::Sizeof)
      | (1ULL << CParser::Alignof))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (CParser::Generic - 67))
      | (1ULL << (CParser::LeftParen - 67))
      | (1ULL << (CParser::Plus - 67))
      | (1ULL << (CParser::PlusPlus - 67))
      | (1ULL << (CParser::Minus - 67))
      | (1ULL << (CParser::MinusMinus - 67))
      | (1ULL << (CParser::Star - 67))
      | (1ULL << (CParser::And - 67))
      | (1ULL << (CParser::AndAnd - 67))
      | (1ULL << (CParser::Not - 67))
      | (1ULL << (CParser::Tilde - 67))
      | (1ULL << (CParser::Identifier - 67))
      | (1ULL << (CParser::Constant - 67))
      | (1ULL << (CParser::DigitSequence - 67))
      | (1ULL << (CParser::StringLiteral - 67)))) != 0)) {
      setState(1203);
      expression(0);
    }
    setState(1206);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1223);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::If: {
        enterOuterAlt(_localctx, 1);
        setState(1208);
        match(CParser::If);
        setState(1209);
        match(CParser::LeftParen);
        setState(1210);
        expression(0);
        setState(1211);
        match(CParser::RightParen);
        setState(1212);
        statement();
        setState(1215);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 134, _ctx)) {
        case 1: {
          setState(1213);
          match(CParser::Else);
          setState(1214);
          statement();
          break;
        }

        default:
          break;
        }
        break;
      }

      case CParser::Switch: {
        enterOuterAlt(_localctx, 2);
        setState(1217);
        match(CParser::Switch);
        setState(1218);
        match(CParser::LeftParen);
        setState(1219);
        expression(0);
        setState(1220);
        match(CParser::RightParen);
        setState(1221);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1245);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::While: {
        enterOuterAlt(_localctx, 1);
        setState(1225);
        match(CParser::While);
        setState(1226);
        match(CParser::LeftParen);
        setState(1227);
        expression(0);
        setState(1228);
        match(CParser::RightParen);
        setState(1229);
        statement();
        break;
      }

      case CParser::Do: {
        enterOuterAlt(_localctx, 2);
        setState(1231);
        match(CParser::Do);
        setState(1232);
        statement();
        setState(1233);
        match(CParser::While);
        setState(1234);
        match(CParser::LeftParen);
        setState(1235);
        expression(0);
        setState(1236);
        match(CParser::RightParen);
        setState(1237);
        match(CParser::Semi);
        break;
      }

      case CParser::For: {
        enterOuterAlt(_localctx, 3);
        setState(1239);
        match(CParser::For);
        setState(1240);
        match(CParser::LeftParen);
        setState(1241);
        forCondition();
        setState(1242);
        match(CParser::RightParen);
        setState(1243);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1267);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 142, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1247);
      forDeclaration();
      setState(1248);
      match(CParser::Semi);
      setState(1250);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__0)
        | (1ULL << CParser::T__1)
        | (1ULL << CParser::T__2)
        | (1ULL << CParser::T__3)
        | (1ULL << CParser::T__4)
        | (1ULL << CParser::Sizeof)
        | (1ULL << CParser::Alignof))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 67)) & ((1ULL << (CParser::Generic - 67))
        | (1ULL << (CParser::LeftParen - 67))
        | (1ULL << (CParser::Plus - 67))
        | (1ULL << (CParser::PlusPlus - 67))
        | (1ULL << (CParser::Minus - 67))
        | (1ULL << (CParser::MinusMinus - 67))
        | (1ULL << (CParser::Star - 67))
        | (1ULL << (CParser::And - 67))
        | (1ULL << (CParser::AndAnd - 67))
        | (1ULL << (CParser::Not - 67))
        | (1ULL << (CParser::Tilde - 67))
        | (1ULL << (CParser::Identifier - 67))
        | (1ULL << (CParser::Constant - 67))
        | (1ULL << (CParser::DigitSequence - 67))
        | (1ULL << (CParser::StringLiteral - 67)))) != 0)) {
        setState(1249);
        forExpression(0);
      }
      setState(1252);
      match(CParser::Semi);
      setState(1254);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__0)
        | (1ULL << CParser::T__1)
        | (1ULL << CParser::T__2)
        | (1ULL << CParser::T__3)
        | (1ULL << CParser::T__4)
        | (1ULL << CParser::Sizeof)
        | (1ULL << CParser::Alignof))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 67)) & ((1ULL << (CParser::Generic - 67))
        | (1ULL << (CParser::LeftParen - 67))
        | (1ULL << (CParser::Plus - 67))
        | (1ULL << (CParser::PlusPlus - 67))
        | (1ULL << (CParser::Minus - 67))
        | (1ULL << (CParser::MinusMinus - 67))
        | (1ULL << (CParser::Star - 67))
        | (1ULL << (CParser::And - 67))
        | (1ULL << (CParser::AndAnd - 67))
        | (1ULL << (CParser::Not - 67))
        | (1ULL << (CParser::Tilde - 67))
        | (1ULL << (CParser::Identifier - 67))
        | (1ULL << (CParser::Constant - 67))
        | (1ULL << (CParser::DigitSequence - 67))
        | (1ULL << (CParser::StringLiteral - 67)))) != 0)) {
        setState(1253);
        forExpression(0);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1257);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__0)
        | (1ULL << CParser::T__1)
        | (1ULL << CParser::T__2)
        | (1ULL << CParser::T__3)
        | (1ULL << CParser::T__4)
        | (1ULL << CParser::Sizeof)
        | (1ULL << CParser::Alignof))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 67)) & ((1ULL << (CParser::Generic - 67))
        | (1ULL << (CParser::LeftParen - 67))
        | (1ULL << (CParser::Plus - 67))
        | (1ULL << (CParser::PlusPlus - 67))
        | (1ULL << (CParser::Minus - 67))
        | (1ULL << (CParser::MinusMinus - 67))
        | (1ULL << (CParser::Star - 67))
        | (1ULL << (CParser::And - 67))
        | (1ULL << (CParser::AndAnd - 67))
        | (1ULL << (CParser::Not - 67))
        | (1ULL << (CParser::Tilde - 67))
        | (1ULL << (CParser::Identifier - 67))
        | (1ULL << (CParser::Constant - 67))
        | (1ULL << (CParser::DigitSequence - 67))
        | (1ULL << (CParser::StringLiteral - 67)))) != 0)) {
        setState(1256);
        expression(0);
      }
      setState(1259);
      match(CParser::Semi);
      setState(1261);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__0)
        | (1ULL << CParser::T__1)
        | (1ULL << CParser::T__2)
        | (1ULL << CParser::T__3)
        | (1ULL << CParser::T__4)
        | (1ULL << CParser::Sizeof)
        | (1ULL << CParser::Alignof))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 67)) & ((1ULL << (CParser::Generic - 67))
        | (1ULL << (CParser::LeftParen - 67))
        | (1ULL << (CParser::Plus - 67))
        | (1ULL << (CParser::PlusPlus - 67))
        | (1ULL << (CParser::Minus - 67))
        | (1ULL << (CParser::MinusMinus - 67))
        | (1ULL << (CParser::Star - 67))
        | (1ULL << (CParser::And - 67))
        | (1ULL << (CParser::AndAnd - 67))
        | (1ULL << (CParser::Not - 67))
        | (1ULL << (CParser::Tilde - 67))
        | (1ULL << (CParser::Identifier - 67))
        | (1ULL << (CParser::Constant - 67))
        | (1ULL << (CParser::DigitSequence - 67))
        | (1ULL << (CParser::StringLiteral - 67)))) != 0)) {
        setState(1260);
        forExpression(0);
      }
      setState(1263);
      match(CParser::Semi);
      setState(1265);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__0)
        | (1ULL << CParser::T__1)
        | (1ULL << CParser::T__2)
        | (1ULL << CParser::T__3)
        | (1ULL << CParser::T__4)
        | (1ULL << CParser::Sizeof)
        | (1ULL << CParser::Alignof))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 67)) & ((1ULL << (CParser::Generic - 67))
        | (1ULL << (CParser::LeftParen - 67))
        | (1ULL << (CParser::Plus - 67))
        | (1ULL << (CParser::PlusPlus - 67))
        | (1ULL << (CParser::Minus - 67))
        | (1ULL << (CParser::MinusMinus - 67))
        | (1ULL << (CParser::Star - 67))
        | (1ULL << (CParser::And - 67))
        | (1ULL << (CParser::AndAnd - 67))
        | (1ULL << (CParser::Not - 67))
        | (1ULL << (CParser::Tilde - 67))
        | (1ULL << (CParser::Identifier - 67))
        | (1ULL << (CParser::Constant - 67))
        | (1ULL << (CParser::DigitSequence - 67))
        | (1ULL << (CParser::StringLiteral - 67)))) != 0)) {
        setState(1264);
        forExpression(0);
      }
      break;
    }

    default:
      break;
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1273);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 143, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1269);
      declarationSpecifiers();
      setState(1270);
      initDeclaratorList();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1272);
      declarationSpecifiers();
      break;
    }

    default:
      break;
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

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1276);
    assignmentExpression();
    _ctx->stop = _input->LT(-1);
    setState(1283);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 144, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ForExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleForExpression);
        setState(1278);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1279);
        match(CParser::Comma);
        setState(1280);
        assignmentExpression(); 
      }
      setState(1285);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 144, _ctx);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1302);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 146, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1286);
      match(CParser::Goto);
      setState(1287);
      match(CParser::Identifier);
      setState(1288);
      match(CParser::Semi);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1289);
      match(CParser::Continue);
      setState(1290);
      match(CParser::Semi);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1291);
      match(CParser::Break);
      setState(1292);
      match(CParser::Semi);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1293);
      match(CParser::Return);
      setState(1295);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__0)
        | (1ULL << CParser::T__1)
        | (1ULL << CParser::T__2)
        | (1ULL << CParser::T__3)
        | (1ULL << CParser::T__4)
        | (1ULL << CParser::Sizeof)
        | (1ULL << CParser::Alignof))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 67)) & ((1ULL << (CParser::Generic - 67))
        | (1ULL << (CParser::LeftParen - 67))
        | (1ULL << (CParser::Plus - 67))
        | (1ULL << (CParser::PlusPlus - 67))
        | (1ULL << (CParser::Minus - 67))
        | (1ULL << (CParser::MinusMinus - 67))
        | (1ULL << (CParser::Star - 67))
        | (1ULL << (CParser::And - 67))
        | (1ULL << (CParser::AndAnd - 67))
        | (1ULL << (CParser::Not - 67))
        | (1ULL << (CParser::Tilde - 67))
        | (1ULL << (CParser::Identifier - 67))
        | (1ULL << (CParser::Constant - 67))
        | (1ULL << (CParser::DigitSequence - 67))
        | (1ULL << (CParser::StringLiteral - 67)))) != 0)) {
        setState(1294);
        expression(0);
      }
      setState(1297);
      match(CParser::Semi);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(1298);
      match(CParser::Goto);
      setState(1299);
      unaryExpression();
      setState(1300);
      match(CParser::Semi);
      break;
    }

    default:
      break;
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

std::vector<CParser::AsmQualifierContext *> CParser::AsmStatementContext::asmQualifier() {
  return getRuleContexts<CParser::AsmQualifierContext>();
}

CParser::AsmQualifierContext* CParser::AsmStatementContext::asmQualifier(size_t i) {
  return getRuleContext<CParser::AsmQualifierContext>(i);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1323);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 148, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1304);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__21)
        | (1ULL << CParser::T__22)
        | (1ULL << CParser::T__23))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(1308);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__15)
        | (1ULL << CParser::T__16)
        | (1ULL << CParser::T__17)
        | (1ULL << CParser::T__18)
        | (1ULL << CParser::Inline)
        | (1ULL << CParser::Volatile))) != 0)) {
        setState(1305);
        asmQualifier();
        setState(1310);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(1311);
      match(CParser::LeftParen);
      setState(1312);
      asmArgument();
      setState(1313);
      match(CParser::RightParen);
      setState(1314);
      match(CParser::Semi);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1316);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__21)
        | (1ULL << CParser::T__22)
        | (1ULL << CParser::T__23))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(1317);
      match(CParser::Goto);
      setState(1318);
      match(CParser::LeftParen);
      setState(1319);
      asmArgument();
      setState(1320);
      match(CParser::RightParen);
      setState(1321);
      match(CParser::Semi);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AsmQualifierContext ------------------------------------------------------------------

CParser::AsmQualifierContext::AsmQualifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::AsmQualifierContext::Inline() {
  return getToken(CParser::Inline, 0);
}

tree::TerminalNode* CParser::AsmQualifierContext::Volatile() {
  return getToken(CParser::Volatile, 0);
}


size_t CParser::AsmQualifierContext::getRuleIndex() const {
  return CParser::RuleAsmQualifier;
}

void CParser::AsmQualifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAsmQualifier(this);
}

void CParser::AsmQualifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAsmQualifier(this);
}


antlrcpp::Any CParser::AsmQualifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitAsmQualifier(this);
  else
    return visitor->visitChildren(this);
}

CParser::AsmQualifierContext* CParser::asmQualifier() {
  AsmQualifierContext *_localctx = _tracker.createInstance<AsmQualifierContext>(_ctx, getState());
  enterRule(_localctx, 166, CParser::RuleAsmQualifier);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1325);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__15)
      | (1ULL << CParser::T__16)
      | (1ULL << CParser::T__17)
      | (1ULL << CParser::T__18)
      | (1ULL << CParser::Inline)
      | (1ULL << CParser::Volatile))) != 0))) {
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
  enterRule(_localctx, 168, CParser::RuleAsmArgument);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1327);
    asmStringLiteral();
    setState(1348);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::Colon) {
      setState(1328);
      match(CParser::Colon);
      setState(1330);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::LeftBracket

      || _la == CParser::StringLiteral) {
        setState(1329);
        asmOperands();
      }
      setState(1346);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::Colon) {
        setState(1332);
        match(CParser::Colon);
        setState(1334);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CParser::LeftBracket

        || _la == CParser::StringLiteral) {
          setState(1333);
          asmOperands();
        }
        setState(1344);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CParser::Colon) {
          setState(1336);
          match(CParser::Colon);
          setState(1338);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CParser::StringLiteral) {
            setState(1337);
            asmClobbers();
          }
          setState(1342);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CParser::Colon) {
            setState(1340);
            match(CParser::Colon);
            setState(1341);
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
  enterRule(_localctx, 170, CParser::RuleAsmOperands);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1350);
    asmOperand();
    setState(1355);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::Comma) {
      setState(1351);
      match(CParser::Comma);
      setState(1352);
      asmOperand();
      setState(1357);
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
  enterRule(_localctx, 172, CParser::RuleAsmOperand);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1371);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::StringLiteral: {
        enterOuterAlt(_localctx, 1);
        setState(1358);
        asmStringLiteral();
        setState(1359);
        match(CParser::LeftParen);
        setState(1360);
        expression(0);
        setState(1361);
        match(CParser::RightParen);
        break;
      }

      case CParser::LeftBracket: {
        enterOuterAlt(_localctx, 2);
        setState(1363);
        match(CParser::LeftBracket);
        setState(1364);
        match(CParser::Identifier);
        setState(1365);
        match(CParser::RightBracket);
        setState(1366);
        asmStringLiteral();
        setState(1367);
        match(CParser::LeftParen);
        setState(1368);
        expression(0);
        setState(1369);
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
  enterRule(_localctx, 174, CParser::RuleAsmClobbers);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1373);
    asmStringLiteral();
    setState(1378);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::Comma) {
      setState(1374);
      match(CParser::Comma);
      setState(1375);
      asmStringLiteral();
      setState(1380);
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
  enterRule(_localctx, 176, CParser::RuleAsmLabels);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1381);
    match(CParser::Identifier);
    setState(1386);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::Comma) {
      setState(1382);
      match(CParser::Comma);
      setState(1383);
      match(CParser::Identifier);
      setState(1388);
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
  enterRule(_localctx, 178, CParser::RuleAsmDefinition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1389);
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
  enterRule(_localctx, 180, CParser::RuleSimpleAsmExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1391);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__21)
      | (1ULL << CParser::T__22)
      | (1ULL << CParser::T__23))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(1392);
    match(CParser::LeftParen);
    setState(1393);
    asmStringLiteral();
    setState(1394);
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
  enterRule(_localctx, 182, CParser::RuleAsmStringLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1397); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1396);
      match(CParser::StringLiteral);
      setState(1399); 
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

std::vector<CParser::ExternalDeclarationContext *> CParser::CompilationUnitContext::externalDeclaration() {
  return getRuleContexts<CParser::ExternalDeclarationContext>();
}

CParser::ExternalDeclarationContext* CParser::CompilationUnitContext::externalDeclaration(size_t i) {
  return getRuleContext<CParser::ExternalDeclarationContext>(i);
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
  enterRule(_localctx, 184, CParser::RuleCompilationUnit);

  	inTypedef = false;
  	typedefMutex = -1;


#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1404);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 161, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1401);
        externalDeclaration(); 
      }
      setState(1406);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 161, _ctx);
    }
    setState(1407);
    match(CParser::EOF);
   _ctx->stop = _input->LT(-1);

    	dumpTypes();

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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1413);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 162, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1409);
      functionDefinition();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1410);
      declaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1411);
      match(CParser::Semi);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1412);
      asmDefinition();
      break;
    }

    default:
      break;
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1416);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 163, _ctx)) {
    case 1: {
      setState(1415);
      declarationSpecifiers();
      break;
    }

    default:
      break;
    }
    setState(1418);
    declarator();
    setState(1420);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 164, _ctx)) {
    case 1: {
      setState(1419);
      declarationList(0);
      break;
    }

    default:
      break;
    }
    setState(1422);
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

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1425);
    declaration();
    _ctx->stop = _input->LT(-1);
    setState(1431);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 165, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<DeclarationListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleDeclarationList);
        setState(1427);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1428);
        declaration(); 
      }
      setState(1433);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 165, _ctx);
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
    case 4: return postfixExpressionSempred(dynamic_cast<PostfixExpressionContext *>(context), predicateIndex);
    case 10: return multiplicativeExpressionSempred(dynamic_cast<MultiplicativeExpressionContext *>(context), predicateIndex);
    case 11: return additiveExpressionSempred(dynamic_cast<AdditiveExpressionContext *>(context), predicateIndex);
    case 12: return shiftExpressionSempred(dynamic_cast<ShiftExpressionContext *>(context), predicateIndex);
    case 13: return relationalExpressionSempred(dynamic_cast<RelationalExpressionContext *>(context), predicateIndex);
    case 14: return equalityExpressionSempred(dynamic_cast<EqualityExpressionContext *>(context), predicateIndex);
    case 15: return andExpressionSempred(dynamic_cast<AndExpressionContext *>(context), predicateIndex);
    case 16: return exclusiveOrExpressionSempred(dynamic_cast<ExclusiveOrExpressionContext *>(context), predicateIndex);
    case 17: return inclusiveOrExpressionSempred(dynamic_cast<InclusiveOrExpressionContext *>(context), predicateIndex);
    case 18: return logicalAndExpressionSempred(dynamic_cast<LogicalAndExpressionContext *>(context), predicateIndex);
    case 19: return logicalOrExpressionSempred(dynamic_cast<LogicalOrExpressionContext *>(context), predicateIndex);
    case 23: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);
    case 32: return typeSpecifierSempred(dynamic_cast<TypeSpecifierContext *>(context), predicateIndex);
    case 40: return enumeratorListSempred(dynamic_cast<EnumeratorListContext *>(context), predicateIndex);
    case 48: return directDeclaratorSempred(dynamic_cast<DirectDeclaratorContext *>(context), predicateIndex);
    case 55: return typeQualifierListSempred(dynamic_cast<TypeQualifierListContext *>(context), predicateIndex);
    case 59: return identifierListSempred(dynamic_cast<IdentifierListContext *>(context), predicateIndex);
    case 62: return directAbstractDeclaratorSempred(dynamic_cast<DirectAbstractDeclaratorContext *>(context), predicateIndex);
    case 63: return typedefNameSempred(dynamic_cast<TypedefNameContext *>(context), predicateIndex);
    case 65: return initializerListSempred(dynamic_cast<InitializerListContext *>(context), predicateIndex);
    case 67: return designatorListSempred(dynamic_cast<DesignatorListContext *>(context), predicateIndex);
    case 80: return forExpressionSempred(dynamic_cast<ForExpressionContext *>(context), predicateIndex);
    case 95: return declarationListSempred(dynamic_cast<DeclarationListContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CParser::postfixExpressionSempred(PostfixExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 10);
    case 1: return precpred(_ctx, 9);
    case 2: return precpred(_ctx, 8);
    case 3: return precpred(_ctx, 7);
    case 4: return precpred(_ctx, 6);
    case 5: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

bool CParser::multiplicativeExpressionSempred(MultiplicativeExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return precpred(_ctx, 3);
    case 7: return precpred(_ctx, 2);
    case 8: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::additiveExpressionSempred(AdditiveExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 9: return precpred(_ctx, 2);
    case 10: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::shiftExpressionSempred(ShiftExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 11: return precpred(_ctx, 2);
    case 12: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::relationalExpressionSempred(RelationalExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 13: return precpred(_ctx, 4);
    case 14: return precpred(_ctx, 3);
    case 15: return precpred(_ctx, 2);
    case 16: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::equalityExpressionSempred(EqualityExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 17: return precpred(_ctx, 2);
    case 18: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::andExpressionSempred(AndExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 19: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::exclusiveOrExpressionSempred(ExclusiveOrExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 20: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::inclusiveOrExpressionSempred(InclusiveOrExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 21: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::logicalAndExpressionSempred(LogicalAndExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 22: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::logicalOrExpressionSempred(LogicalOrExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 23: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 24: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::typeSpecifierSempred(TypeSpecifierContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 25: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::enumeratorListSempred(EnumeratorListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 26: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::directDeclaratorSempred(DirectDeclaratorContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 27: return precpred(_ctx, 8);
    case 28: return precpred(_ctx, 7);
    case 29: return precpred(_ctx, 6);
    case 30: return precpred(_ctx, 5);
    case 31: return precpred(_ctx, 4);
    case 32: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool CParser::typeQualifierListSempred(TypeQualifierListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 33: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::identifierListSempred(IdentifierListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 34: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::directAbstractDeclaratorSempred(DirectAbstractDeclaratorContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 35: return precpred(_ctx, 5);
    case 36: return precpred(_ctx, 4);
    case 37: return precpred(_ctx, 3);
    case 38: return precpred(_ctx, 2);
    case 39: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::typedefNameSempred(TypedefNameContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 40: return  isTypeName(getCurrentToken()) ;

  default:
    break;
  }
  return true;
}

bool CParser::initializerListSempred(InitializerListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 41: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::designatorListSempred(DesignatorListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 42: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::forExpressionSempred(ForExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 43: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::declarationListSempred(DeclarationListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 44: return precpred(_ctx, 1);

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
  "postfixExpression", "argumentExpressionList", "unaryExpression", "gccBuiltin", 
  "unaryOperator", "castExpression", "multiplicativeExpression", "additiveExpression", 
  "shiftExpression", "relationalExpression", "equalityExpression", "andExpression", 
  "exclusiveOrExpression", "inclusiveOrExpression", "logicalAndExpression", 
  "logicalOrExpression", "conditionalExpression", "assignmentExpression", 
  "assignmentOperator", "expression", "constantExpression", "declaration", 
  "declarationSpecifiers", "declarationSpecifiers2", "declarationSpecifier", 
  "initDeclaratorList", "initDeclarator", "storageClassSpecifier", "typeSpecifier", 
  "structOrUnionSpecifier", "structOrUnion", "structDeclaration", "specifierQualifierList", 
  "structDeclaratorList", "structDeclarator", "enumSpecifier", "enumeratorList", 
  "enumerator", "enumerationConstant", "atomicTypeSpecifier", "typeQualifier", 
  "functionSpecifier", "alignmentSpecifier", "declarator", "directDeclarator", 
  "gccDeclaratorExtension", "gccAttributeSpecifier", "gccAttributeList", 
  "gccAttribute", "nestedParenthesesBlock", "pointer", "typeQualifierList", 
  "parameterTypeList", "parameterList", "parameterDeclaration", "identifierList", 
  "typeName", "abstractDeclarator", "directAbstractDeclarator", "typedefName", 
  "initializer", "initializerList", "designation", "designatorList", "designator", 
  "staticAssertDeclaration", "statement", "labeledStatement", "compoundStatement", 
  "blockItem", "labelDeclaration", "expressionStatement", "selectionStatement", 
  "iterationStatement", "forCondition", "forDeclaration", "forExpression", 
  "jumpStatement", "asmStatement", "asmQualifier", "asmArgument", "asmOperands", 
  "asmOperand", "asmClobbers", "asmLabels", "asmDefinition", "simpleAsmExpr", 
  "asmStringLiteral", "compilationUnit", "externalDeclaration", "functionDefinition", 
  "declarationList"
};

std::vector<std::string> CParser::_literalNames = {
  "", "'__extension__'", "'__builtin_va_arg'", "'__builtin_offsetof'", "'__alignof__'", 
  "'__builtin_types_compatible_p'", "'__signed'", "'__signed__'", "'__complex'", 
  "'__complex__'", "'__int128'", "'__m128'", "'__m128d'", "'__m128i'", "'__builtin_va_list'", 
  "'__typeof__'", "'__volatile'", "'__volatile__'", "'__inline'", "'__inline__'", 
  "'__stdcall'", "'__declspec'", "'asm'", "'__asm'", "'__asm__'", "'__attribute__'", 
  "'__label__'", "'auto'", "'break'", "'case'", "'char'", "'const'", "'continue'", 
  "'default'", "'do'", "'double'", "'else'", "'enum'", "'extern'", "'float'", 
  "'for'", "'goto'", "'if'", "'inline'", "'int'", "'long'", "'register'", 
  "'restrict'", "'return'", "'short'", "'signed'", "'sizeof'", "'static'", 
  "'struct'", "'switch'", "'typedef'", "'typeof'", "'union'", "'unsigned'", 
  "'void'", "'volatile'", "'while'", "'_Alignas'", "'_Alignof'", "'_Atomic'", 
  "'_Bool'", "'_Complex'", "'_Generic'", "'_Imaginary'", "'_Noreturn'", 
  "'_Static_assert'", "'_Thread_local'", "'('", "')'", "'['", "']'", "'{'", 
  "'}'", "'<'", "'<='", "'>'", "'>='", "'<<'", "'>>'", "'+'", "'++'", "'-'", 
  "'--'", "'*'", "'/'", "'%'", "'&'", "'|'", "'&&'", "'||'", "'^'", "'!'", 
  "'~'", "'\u003F'", "':'", "';'", "','", "'='", "'*='", "'/='", "'%='", 
  "'+='", "'-='", "'<<='", "'>>='", "'&='", "'^='", "'|='", "'=='", "'!='", 
  "'->'", "'.'", "'...'"
};

std::vector<std::string> CParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "Auto", "Break", "Case", "Char", "Const", 
  "Continue", "Default", "Do", "Double", "Else", "Enum", "Extern", "Float", 
  "For", "Goto", "If", "Inline", "Int", "Long", "Register", "Restrict", 
  "Return", "Short", "Signed", "Sizeof", "Static", "Struct", "Switch", "Typedef", 
  "Typeof", "Union", "Unsigned", "Void", "Volatile", "While", "Alignas", 
  "Alignof", "Atomic", "Bool", "Complex", "Generic", "Imaginary", "Noreturn", 
  "StaticAssert", "ThreadLocal", "LeftParen", "RightParen", "LeftBracket", 
  "RightBracket", "LeftBrace", "RightBrace", "Less", "LessEqual", "Greater", 
  "GreaterEqual", "LeftShift", "RightShift", "Plus", "PlusPlus", "Minus", 
  "MinusMinus", "Star", "Div", "Mod", "And", "Or", "AndAnd", "OrOr", "Caret", 
  "Not", "Tilde", "Question", "Colon", "Semi", "Comma", "Assign", "StarAssign", 
  "DivAssign", "ModAssign", "PlusAssign", "MinusAssign", "LeftShiftAssign", 
  "RightShiftAssign", "AndAssign", "XorAssign", "OrAssign", "Equal", "NotEqual", 
  "Arrow", "Dot", "Ellipsis", "Identifier", "Constant", "DigitSequence", 
  "StringLiteral", "ComplexDefine", "IncludeDirective", "LineAfterPreprocessing", 
  "LineDirective", "PragmaDirective", "Whitespace", "Newline", "BlockComment", 
  "LineComment"
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
    0x3, 0x84, 0x59d, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
    0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0xf0, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0xf3, 
    0xb, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x5, 0x5, 0xfc, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x105, 0xa, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x5, 0x6, 0x117, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x5, 0x6, 0x124, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x12e, 0xa, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x13b, 0xa, 0x6, 0xc, 0x6, 
    0xe, 0x6, 0x13e, 0xb, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x143, 
    0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x146, 0xb, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 
    0x8, 0x15f, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x177, 0xa, 0xb, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x185, 0xa, 0xc, 0xc, 0xc, 
    0xe, 0xc, 0x188, 0xb, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0x193, 0xa, 0xd, 
    0xc, 0xd, 0xe, 0xd, 0x196, 0xb, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0x1a1, 
    0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x1a4, 0xb, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0x1b5, 
    0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x1b8, 0xb, 0xf, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x7, 0x10, 0x1c3, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0x1c6, 0xb, 
    0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x7, 0x11, 0x1ce, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x1d1, 0xb, 0x11, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 
    0x12, 0x1d9, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0x1dc, 0xb, 0x12, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 
    0x1e4, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 0x1e7, 0xb, 0x13, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0x1ef, 
    0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 0x1f2, 0xb, 0x14, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 0x1fa, 0xa, 0x15, 
    0xc, 0x15, 0xe, 0x15, 0x1fd, 0xb, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x5, 0x16, 0x202, 0xa, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x206, 
    0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 
    0x17, 0x5, 0x17, 0x20e, 0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x7, 0x19, 0x218, 
    0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 0x21b, 0xb, 0x19, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 
    0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x229, 0xa, 0x1b, 
    0x3, 0x1c, 0x6, 0x1c, 0x22c, 0xa, 0x1c, 0xd, 0x1c, 0xe, 0x1c, 0x22d, 
    0x3, 0x1d, 0x6, 0x1d, 0x231, 0xa, 0x1d, 0xd, 0x1d, 0xe, 0x1d, 0x232, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 
    0x1e, 0x23b, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x7, 0x1f, 
    0x240, 0xa, 0x1f, 0xc, 0x1f, 0xe, 0x1f, 0x243, 0xb, 0x1f, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x24a, 0xa, 0x20, 
    0x3, 0x21, 0x5, 0x21, 0x24d, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x256, 0xa, 0x21, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 
    0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 
    0x22, 0x3, 0x22, 0x5, 0x22, 0x26d, 0xa, 0x22, 0x3, 0x22, 0x3, 0x22, 
    0x7, 0x22, 0x271, 0xa, 0x22, 0xc, 0x22, 0xe, 0x22, 0x274, 0xb, 0x22, 
    0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x278, 0xa, 0x23, 0x3, 0x23, 0x5, 0x23, 
    0x27b, 0xa, 0x23, 0x3, 0x23, 0x3, 0x23, 0x7, 0x23, 0x27f, 0xa, 0x23, 
    0xc, 0x23, 0xe, 0x23, 0x282, 0xb, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 
    0x286, 0xa, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x28a, 0xa, 0x23, 
    0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x28e, 0xa, 0x23, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x294, 0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 
    0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x29a, 0xa, 0x25, 0x3, 0x26, 0x3, 0x26, 
    0x6, 0x26, 0x29e, 0xa, 0x26, 0xd, 0x26, 0xe, 0x26, 0x29f, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x7, 0x27, 0x2a5, 0xa, 0x27, 0xc, 0x27, 0xe, 0x27, 
    0x2a8, 0xb, 0x27, 0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 0x2ac, 0xa, 0x28, 
    0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 0x2b0, 0xa, 0x28, 0x3, 0x29, 0x3, 0x29, 
    0x5, 0x29, 0x2b4, 0xa, 0x29, 0x3, 0x29, 0x5, 0x29, 0x2b7, 0xa, 0x29, 
    0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x2bd, 0xa, 0x29, 
    0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x2c1, 0xa, 0x29, 0x3, 0x29, 0x5, 0x29, 
    0x2c4, 0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 
    0x5, 0x29, 0x2cb, 0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x2cf, 
    0xa, 0x29, 0x3, 0x29, 0x5, 0x29, 0x2d2, 0xa, 0x29, 0x3, 0x2a, 0x3, 0x2a, 
    0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x7, 0x2a, 0x2da, 0xa, 0x2a, 
    0xc, 0x2a, 0xe, 0x2a, 0x2dd, 0xb, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 
    0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x2e4, 0xa, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 
    0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x3, 
    0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x5, 0x2f, 
    0x2f4, 0xa, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 
    0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 0x300, 
    0xa, 0x30, 0x3, 0x31, 0x5, 0x31, 0x303, 0xa, 0x31, 0x3, 0x31, 0x5, 0x31, 
    0x306, 0xa, 0x31, 0x3, 0x31, 0x3, 0x31, 0x7, 0x31, 0x30a, 0xa, 0x31, 
    0xc, 0x31, 0xe, 0x31, 0x30d, 0xb, 0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 
    0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 
    0x32, 0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 0x31b, 0xa, 0x32, 0x3, 0x32, 
    0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 0x321, 0xa, 0x32, 0x3, 0x32, 
    0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 0x326, 0xa, 0x32, 0x3, 0x32, 0x5, 0x32, 
    0x329, 0xa, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 
    0x5, 0x32, 0x330, 0xa, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 
    0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 
    0x32, 0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 0x33f, 0xa, 0x32, 0x3, 0x32, 
    0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 
    0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 
    0x34e, 0xa, 0x32, 0x3, 0x32, 0x3, 0x32, 0x7, 0x32, 0x352, 0xa, 0x32, 
    0xc, 0x32, 0xe, 0x32, 0x355, 0xb, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 
    0x6, 0x33, 0x35a, 0xa, 0x33, 0xd, 0x33, 0xe, 0x33, 0x35b, 0x3, 0x33, 
    0x3, 0x33, 0x5, 0x33, 0x360, 0xa, 0x33, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 
    0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 
    0x35, 0x7, 0x35, 0x36c, 0xa, 0x35, 0xc, 0x35, 0xe, 0x35, 0x36f, 0xb, 
    0x35, 0x3, 0x35, 0x5, 0x35, 0x372, 0xa, 0x35, 0x3, 0x36, 0x3, 0x36, 
    0x3, 0x36, 0x5, 0x36, 0x377, 0xa, 0x36, 0x3, 0x36, 0x5, 0x36, 0x37a, 
    0xa, 0x36, 0x3, 0x36, 0x5, 0x36, 0x37d, 0xa, 0x36, 0x3, 0x37, 0x3, 0x37, 
    0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x7, 0x37, 0x384, 0xa, 0x37, 0xc, 0x37, 
    0xe, 0x37, 0x387, 0xb, 0x37, 0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x38b, 
    0xa, 0x38, 0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x38f, 0xa, 0x38, 0x3, 0x38, 
    0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x394, 0xa, 0x38, 0x3, 0x38, 0x3, 0x38, 
    0x5, 0x38, 0x398, 0xa, 0x38, 0x3, 0x38, 0x5, 0x38, 0x39b, 0xa, 0x38, 
    0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x7, 0x39, 0x3a2, 
    0xa, 0x39, 0xc, 0x39, 0xe, 0x39, 0x3a5, 0xb, 0x39, 0x3, 0x3a, 0x3, 0x3a, 
    0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 0x3ac, 0xa, 0x3a, 0x3, 0x3b, 
    0x3, 0x3b, 0x3, 0x3b, 0x7, 0x3b, 0x3b1, 0xa, 0x3b, 0xc, 0x3b, 0xe, 0x3b, 
    0x3b4, 0xb, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 
    0x5, 0x3c, 0x3bb, 0xa, 0x3c, 0x5, 0x3c, 0x3bd, 0xa, 0x3c, 0x3, 0x3d, 
    0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x7, 0x3d, 0x3c5, 
    0xa, 0x3d, 0xc, 0x3d, 0xe, 0x3d, 0x3c8, 0xb, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 
    0x5, 0x3e, 0x3cc, 0xa, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 0x5, 0x3f, 0x3d0, 
    0xa, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x7, 0x3f, 0x3d4, 0xa, 0x3f, 0xc, 0x3f, 
    0xe, 0x3f, 0x3d7, 0xb, 0x3f, 0x5, 0x3f, 0x3d9, 0xa, 0x3f, 0x3, 0x40, 
    0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x7, 0x40, 0x3e0, 0xa, 0x40, 
    0xc, 0x40, 0xe, 0x40, 0x3e3, 0xb, 0x40, 0x3, 0x40, 0x3, 0x40, 0x5, 0x40, 
    0x3e7, 0xa, 0x40, 0x3, 0x40, 0x5, 0x40, 0x3ea, 0xa, 0x40, 0x3, 0x40, 
    0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x5, 0x40, 0x3f0, 0xa, 0x40, 0x3, 0x40, 
    0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 
    0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 
    0x5, 0x40, 0x400, 0xa, 0x40, 0x3, 0x40, 0x3, 0x40, 0x7, 0x40, 0x404, 
    0xa, 0x40, 0xc, 0x40, 0xe, 0x40, 0x407, 0xb, 0x40, 0x5, 0x40, 0x409, 
    0xa, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x5, 0x40, 0x40e, 0xa, 0x40, 
    0x3, 0x40, 0x5, 0x40, 0x411, 0xa, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 
    0x3, 0x40, 0x3, 0x40, 0x5, 0x40, 0x418, 0xa, 0x40, 0x3, 0x40, 0x3, 0x40, 
    0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 
    0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 
    0x3, 0x40, 0x3, 0x40, 0x5, 0x40, 0x42b, 0xa, 0x40, 0x3, 0x40, 0x3, 0x40, 
    0x7, 0x40, 0x42f, 0xa, 0x40, 0xc, 0x40, 0xe, 0x40, 0x432, 0xb, 0x40, 
    0x7, 0x40, 0x434, 0xa, 0x40, 0xc, 0x40, 0xe, 0x40, 0x437, 0xb, 0x40, 
    0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 
    0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 
    0x3, 0x42, 0x3, 0x42, 0x5, 0x42, 0x448, 0xa, 0x42, 0x3, 0x43, 0x3, 0x43, 
    0x5, 0x43, 0x44c, 0xa, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 
    0x3, 0x43, 0x5, 0x43, 0x453, 0xa, 0x43, 0x3, 0x43, 0x7, 0x43, 0x456, 
    0xa, 0x43, 0xc, 0x43, 0xe, 0x43, 0x459, 0xb, 0x43, 0x3, 0x44, 0x3, 0x44, 
    0x3, 0x44, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x7, 
    0x45, 0x463, 0xa, 0x45, 0xc, 0x45, 0xe, 0x45, 0x466, 0xb, 0x45, 0x3, 
    0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x5, 0x46, 
    0x46e, 0xa, 0x46, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 
    0x6, 0x47, 0x475, 0xa, 0x47, 0xd, 0x47, 0xe, 0x47, 0x476, 0x3, 0x47, 
    0x3, 0x47, 0x3, 0x47, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 
    0x48, 0x3, 0x48, 0x3, 0x48, 0x5, 0x48, 0x483, 0xa, 0x48, 0x3, 0x49, 
    0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x5, 
    0x49, 0x48c, 0xa, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 
    0x3, 0x49, 0x3, 0x49, 0x5, 0x49, 0x494, 0xa, 0x49, 0x3, 0x4a, 0x3, 0x4a, 
    0x7, 0x4a, 0x498, 0xa, 0x4a, 0xc, 0x4a, 0xe, 0x4a, 0x49b, 0xb, 0x4a, 
    0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x6, 0x4a, 0x4a0, 0xa, 0x4a, 0xd, 0x4a, 
    0xe, 0x4a, 0x4a1, 0x3, 0x4a, 0x7, 0x4a, 0x4a5, 0xa, 0x4a, 0xc, 0x4a, 
    0xe, 0x4a, 0x4a8, 0xb, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x5, 0x4a, 0x4ac, 
    0xa, 0x4a, 0x3, 0x4b, 0x3, 0x4b, 0x5, 0x4b, 0x4b0, 0xa, 0x4b, 0x3, 0x4c, 
    0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4d, 0x5, 0x4d, 0x4b7, 0xa, 0x4d, 
    0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 
    0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x5, 0x4e, 0x4c2, 0xa, 0x4e, 0x3, 0x4e, 
    0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x5, 0x4e, 0x4ca, 
    0xa, 0x4e, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 
    0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 
    0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 
    0x4f, 0x3, 0x4f, 0x5, 0x4f, 0x4e0, 0xa, 0x4f, 0x3, 0x50, 0x3, 0x50, 
    0x3, 0x50, 0x5, 0x50, 0x4e5, 0xa, 0x50, 0x3, 0x50, 0x3, 0x50, 0x5, 0x50, 
    0x4e9, 0xa, 0x50, 0x3, 0x50, 0x5, 0x50, 0x4ec, 0xa, 0x50, 0x3, 0x50, 
    0x3, 0x50, 0x5, 0x50, 0x4f0, 0xa, 0x50, 0x3, 0x50, 0x3, 0x50, 0x5, 0x50, 
    0x4f4, 0xa, 0x50, 0x5, 0x50, 0x4f6, 0xa, 0x50, 0x3, 0x51, 0x3, 0x51, 
    0x3, 0x51, 0x3, 0x51, 0x5, 0x51, 0x4fc, 0xa, 0x51, 0x3, 0x52, 0x3, 0x52, 
    0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x7, 0x52, 0x504, 0xa, 0x52, 
    0xc, 0x52, 0xe, 0x52, 0x507, 0xb, 0x52, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 
    0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x5, 
    0x53, 0x512, 0xa, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 
    0x3, 0x53, 0x5, 0x53, 0x519, 0xa, 0x53, 0x3, 0x54, 0x3, 0x54, 0x7, 0x54, 
    0x51d, 0xa, 0x54, 0xc, 0x54, 0xe, 0x54, 0x520, 0xb, 0x54, 0x3, 0x54, 
    0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 
    0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x5, 0x54, 0x52e, 
    0xa, 0x54, 0x3, 0x55, 0x3, 0x55, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x5, 
    0x56, 0x535, 0xa, 0x56, 0x3, 0x56, 0x3, 0x56, 0x5, 0x56, 0x539, 0xa, 
    0x56, 0x3, 0x56, 0x3, 0x56, 0x5, 0x56, 0x53d, 0xa, 0x56, 0x3, 0x56, 
    0x3, 0x56, 0x5, 0x56, 0x541, 0xa, 0x56, 0x5, 0x56, 0x543, 0xa, 0x56, 
    0x5, 0x56, 0x545, 0xa, 0x56, 0x5, 0x56, 0x547, 0xa, 0x56, 0x3, 0x57, 
    0x3, 0x57, 0x3, 0x57, 0x7, 0x57, 0x54c, 0xa, 0x57, 0xc, 0x57, 0xe, 0x57, 
    0x54f, 0xb, 0x57, 0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 
    0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x3, 
    0x58, 0x3, 0x58, 0x5, 0x58, 0x55e, 0xa, 0x58, 0x3, 0x59, 0x3, 0x59, 
    0x3, 0x59, 0x7, 0x59, 0x563, 0xa, 0x59, 0xc, 0x59, 0xe, 0x59, 0x566, 
    0xb, 0x59, 0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x7, 0x5a, 0x56b, 0xa, 0x5a, 
    0xc, 0x5a, 0xe, 0x5a, 0x56e, 0xb, 0x5a, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5c, 
    0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5d, 0x6, 0x5d, 0x578, 
    0xa, 0x5d, 0xd, 0x5d, 0xe, 0x5d, 0x579, 0x3, 0x5e, 0x7, 0x5e, 0x57d, 
    0xa, 0x5e, 0xc, 0x5e, 0xe, 0x5e, 0x580, 0xb, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 
    0x3, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 0x5, 0x5f, 0x588, 0xa, 0x5f, 
    0x3, 0x60, 0x5, 0x60, 0x58b, 0xa, 0x60, 0x3, 0x60, 0x3, 0x60, 0x5, 0x60, 
    0x58f, 0xa, 0x60, 0x3, 0x60, 0x3, 0x60, 0x3, 0x61, 0x3, 0x61, 0x3, 0x61, 
    0x3, 0x61, 0x3, 0x61, 0x7, 0x61, 0x598, 0xa, 0x61, 0xc, 0x61, 0xe, 0x61, 
    0x59b, 0xb, 0x61, 0x3, 0x61, 0x2, 0x18, 0xa, 0x16, 0x18, 0x1a, 0x1c, 
    0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x30, 0x42, 0x52, 0x62, 0x70, 0x78, 
    0x7e, 0x84, 0x88, 0xa2, 0xc0, 0x62, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 
    0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 
    0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 
    0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 
    0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 
    0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 
    0x88, 0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9e, 
    0xa0, 0xa2, 0xa4, 0xa6, 0xa8, 0xaa, 0xac, 0xae, 0xb0, 0xb2, 0xb4, 0xb6, 
    0xb8, 0xba, 0xbc, 0xbe, 0xc0, 0x2, 0xf, 0x4, 0x2, 0x6, 0x6, 0x41, 0x41, 
    0x7, 0x2, 0x56, 0x56, 0x58, 0x58, 0x5a, 0x5a, 0x5d, 0x5d, 0x62, 0x63, 
    0x3, 0x2, 0x68, 0x72, 0xa, 0x2, 0x8, 0xf, 0x20, 0x20, 0x25, 0x25, 0x29, 
    0x29, 0x2e, 0x2f, 0x33, 0x34, 0x3c, 0x3d, 0x43, 0x44, 0x3, 0x2, 0xd, 
    0xf, 0x4, 0x2, 0x11, 0x11, 0x3a, 0x3a, 0x4, 0x2, 0x37, 0x37, 0x3b, 0x3b, 
    0x7, 0x2, 0x12, 0x13, 0x21, 0x21, 0x31, 0x31, 0x3e, 0x3e, 0x42, 0x42, 
    0x5, 0x2, 0x14, 0x16, 0x2d, 0x2d, 0x47, 0x47, 0x3, 0x2, 0x18, 0x1a, 
    0x4, 0x2, 0x4a, 0x4b, 0x67, 0x67, 0x3, 0x2, 0x4a, 0x4b, 0x5, 0x2, 0x12, 
    0x15, 0x2d, 0x2d, 0x3e, 0x3e, 0x2, 0x62b, 0x2, 0xe3, 0x3, 0x2, 0x2, 
    0x2, 0x4, 0xe5, 0x3, 0x2, 0x2, 0x2, 0x6, 0xec, 0x3, 0x2, 0x2, 0x2, 0x8, 
    0xfb, 0x3, 0x2, 0x2, 0x2, 0xa, 0x123, 0x3, 0x2, 0x2, 0x2, 0xc, 0x13f, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x10, 0x160, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x167, 0x3, 0x2, 0x2, 0x2, 0x14, 0x176, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0x178, 0x3, 0x2, 0x2, 0x2, 0x18, 0x189, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0x197, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1a5, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0x1b9, 0x3, 0x2, 0x2, 0x2, 0x20, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0x1d2, 0x3, 0x2, 0x2, 0x2, 0x24, 0x1dd, 0x3, 0x2, 0x2, 0x2, 0x26, 0x1e8, 
    0x3, 0x2, 0x2, 0x2, 0x28, 0x1f3, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x1fe, 0x3, 
    0x2, 0x2, 0x2, 0x2c, 0x20d, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x20f, 0x3, 0x2, 
    0x2, 0x2, 0x30, 0x211, 0x3, 0x2, 0x2, 0x2, 0x32, 0x21c, 0x3, 0x2, 0x2, 
    0x2, 0x34, 0x228, 0x3, 0x2, 0x2, 0x2, 0x36, 0x22b, 0x3, 0x2, 0x2, 0x2, 
    0x38, 0x230, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x23a, 0x3, 0x2, 0x2, 0x2, 0x3c, 
    0x23c, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x249, 0x3, 0x2, 0x2, 0x2, 0x40, 0x255, 
    0x3, 0x2, 0x2, 0x2, 0x42, 0x26c, 0x3, 0x2, 0x2, 0x2, 0x44, 0x28d, 0x3, 
    0x2, 0x2, 0x2, 0x46, 0x28f, 0x3, 0x2, 0x2, 0x2, 0x48, 0x299, 0x3, 0x2, 
    0x2, 0x2, 0x4a, 0x29d, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x2a1, 0x3, 0x2, 0x2, 
    0x2, 0x4e, 0x2af, 0x3, 0x2, 0x2, 0x2, 0x50, 0x2d1, 0x3, 0x2, 0x2, 0x2, 
    0x52, 0x2d3, 0x3, 0x2, 0x2, 0x2, 0x54, 0x2e3, 0x3, 0x2, 0x2, 0x2, 0x56, 
    0x2e5, 0x3, 0x2, 0x2, 0x2, 0x58, 0x2e7, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x2ec, 
    0x3, 0x2, 0x2, 0x2, 0x5c, 0x2f3, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x2ff, 0x3, 
    0x2, 0x2, 0x2, 0x60, 0x302, 0x3, 0x2, 0x2, 0x2, 0x62, 0x320, 0x3, 0x2, 
    0x2, 0x2, 0x64, 0x35f, 0x3, 0x2, 0x2, 0x2, 0x66, 0x361, 0x3, 0x2, 0x2, 
    0x2, 0x68, 0x371, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x37c, 0x3, 0x2, 0x2, 0x2, 
    0x6c, 0x385, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x39a, 0x3, 0x2, 0x2, 0x2, 0x70, 
    0x39c, 0x3, 0x2, 0x2, 0x2, 0x72, 0x3ab, 0x3, 0x2, 0x2, 0x2, 0x74, 0x3ad, 
    0x3, 0x2, 0x2, 0x2, 0x76, 0x3bc, 0x3, 0x2, 0x2, 0x2, 0x78, 0x3be, 0x3, 
    0x2, 0x2, 0x2, 0x7a, 0x3c9, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x3d8, 0x3, 0x2, 
    0x2, 0x2, 0x7e, 0x408, 0x3, 0x2, 0x2, 0x2, 0x80, 0x438, 0x3, 0x2, 0x2, 
    0x2, 0x82, 0x447, 0x3, 0x2, 0x2, 0x2, 0x84, 0x449, 0x3, 0x2, 0x2, 0x2, 
    0x86, 0x45a, 0x3, 0x2, 0x2, 0x2, 0x88, 0x45d, 0x3, 0x2, 0x2, 0x2, 0x8a, 
    0x46d, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x46f, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x482, 
    0x3, 0x2, 0x2, 0x2, 0x90, 0x493, 0x3, 0x2, 0x2, 0x2, 0x92, 0x4ab, 0x3, 
    0x2, 0x2, 0x2, 0x94, 0x4af, 0x3, 0x2, 0x2, 0x2, 0x96, 0x4b1, 0x3, 0x2, 
    0x2, 0x2, 0x98, 0x4b6, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x4c9, 0x3, 0x2, 0x2, 
    0x2, 0x9c, 0x4df, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x4f5, 0x3, 0x2, 0x2, 0x2, 
    0xa0, 0x4fb, 0x3, 0x2, 0x2, 0x2, 0xa2, 0x4fd, 0x3, 0x2, 0x2, 0x2, 0xa4, 
    0x518, 0x3, 0x2, 0x2, 0x2, 0xa6, 0x52d, 0x3, 0x2, 0x2, 0x2, 0xa8, 0x52f, 
    0x3, 0x2, 0x2, 0x2, 0xaa, 0x531, 0x3, 0x2, 0x2, 0x2, 0xac, 0x548, 0x3, 
    0x2, 0x2, 0x2, 0xae, 0x55d, 0x3, 0x2, 0x2, 0x2, 0xb0, 0x55f, 0x3, 0x2, 
    0x2, 0x2, 0xb2, 0x567, 0x3, 0x2, 0x2, 0x2, 0xb4, 0x56f, 0x3, 0x2, 0x2, 
    0x2, 0xb6, 0x571, 0x3, 0x2, 0x2, 0x2, 0xb8, 0x577, 0x3, 0x2, 0x2, 0x2, 
    0xba, 0x57e, 0x3, 0x2, 0x2, 0x2, 0xbc, 0x587, 0x3, 0x2, 0x2, 0x2, 0xbe, 
    0x58a, 0x3, 0x2, 0x2, 0x2, 0xc0, 0x592, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xe4, 
    0x7, 0x78, 0x2, 0x2, 0xc3, 0xe4, 0x7, 0x79, 0x2, 0x2, 0xc4, 0xc6, 0x7, 
    0x7b, 0x2, 0x2, 0xc5, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 0x3, 0x2, 
    0x2, 0x2, 0xc7, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc8, 0x3, 0x2, 0x2, 
    0x2, 0xc8, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0x7, 0x4a, 0x2, 0x2, 
    0xca, 0xcb, 0x5, 0x30, 0x19, 0x2, 0xcb, 0xcc, 0x7, 0x4b, 0x2, 0x2, 0xcc, 
    0xe4, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xe4, 0x5, 0x4, 0x3, 0x2, 0xce, 0xd0, 
    0x7, 0x3, 0x2, 0x2, 0xcf, 0xce, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd0, 0x3, 
    0x2, 0x2, 0x2, 0xd0, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x7, 0x4a, 
    0x2, 0x2, 0xd2, 0xd3, 0x5, 0x92, 0x4a, 0x2, 0xd3, 0xd4, 0x7, 0x4b, 0x2, 
    0x2, 0xd4, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd6, 0x7, 0x4, 0x2, 0x2, 
    0xd6, 0xd7, 0x7, 0x4a, 0x2, 0x2, 0xd7, 0xd8, 0x5, 0xe, 0x8, 0x2, 0xd8, 
    0xd9, 0x7, 0x67, 0x2, 0x2, 0xd9, 0xda, 0x5, 0x7a, 0x3e, 0x2, 0xda, 0xdb, 
    0x7, 0x4b, 0x2, 0x2, 0xdb, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 0x7, 
    0x5, 0x2, 0x2, 0xdd, 0xde, 0x7, 0x4a, 0x2, 0x2, 0xde, 0xdf, 0x5, 0x7a, 
    0x3e, 0x2, 0xdf, 0xe0, 0x7, 0x67, 0x2, 0x2, 0xe0, 0xe1, 0x5, 0xe, 0x8, 
    0x2, 0xe1, 0xe2, 0x7, 0x4b, 0x2, 0x2, 0xe2, 0xe4, 0x3, 0x2, 0x2, 0x2, 
    0xe3, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xe3, 
    0xc5, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xcd, 
    0x3, 0x2, 0x2, 0x2, 0xe3, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xd5, 0x3, 
    0x2, 0x2, 0x2, 0xe3, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xe4, 0x3, 0x3, 0x2, 
    0x2, 0x2, 0xe5, 0xe6, 0x7, 0x45, 0x2, 0x2, 0xe6, 0xe7, 0x7, 0x4a, 0x2, 
    0x2, 0xe7, 0xe8, 0x5, 0x2c, 0x17, 0x2, 0xe8, 0xe9, 0x7, 0x67, 0x2, 0x2, 
    0xe9, 0xea, 0x5, 0x6, 0x4, 0x2, 0xea, 0xeb, 0x7, 0x4b, 0x2, 0x2, 0xeb, 
    0x5, 0x3, 0x2, 0x2, 0x2, 0xec, 0xf1, 0x5, 0x8, 0x5, 0x2, 0xed, 0xee, 
    0x7, 0x67, 0x2, 0x2, 0xee, 0xf0, 0x5, 0x8, 0x5, 0x2, 0xef, 0xed, 0x3, 
    0x2, 0x2, 0x2, 0xf0, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xef, 0x3, 0x2, 
    0x2, 0x2, 0xf1, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf2, 0x7, 0x3, 0x2, 0x2, 
    0x2, 0xf3, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf5, 0x5, 0x7a, 0x3e, 0x2, 
    0xf5, 0xf6, 0x7, 0x65, 0x2, 0x2, 0xf6, 0xf7, 0x5, 0x2c, 0x17, 0x2, 0xf7, 
    0xfc, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 0x7, 0x23, 0x2, 0x2, 0xf9, 0xfa, 
    0x7, 0x65, 0x2, 0x2, 0xfa, 0xfc, 0x5, 0x2c, 0x17, 0x2, 0xfb, 0xf4, 0x3, 
    0x2, 0x2, 0x2, 0xfb, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xfc, 0x9, 0x3, 0x2, 
    0x2, 0x2, 0xfd, 0xfe, 0x8, 0x6, 0x1, 0x2, 0xfe, 0x124, 0x5, 0x2, 0x2, 
    0x2, 0xff, 0x100, 0x7, 0x4a, 0x2, 0x2, 0x100, 0x101, 0x5, 0x7a, 0x3e, 
    0x2, 0x101, 0x102, 0x7, 0x4b, 0x2, 0x2, 0x102, 0x104, 0x7, 0x4e, 0x2, 
    0x2, 0x103, 0x105, 0x5, 0x84, 0x43, 0x2, 0x104, 0x103, 0x3, 0x2, 0x2, 
    0x2, 0x104, 0x105, 0x3, 0x2, 0x2, 0x2, 0x105, 0x106, 0x3, 0x2, 0x2, 
    0x2, 0x106, 0x107, 0x7, 0x4f, 0x2, 0x2, 0x107, 0x124, 0x3, 0x2, 0x2, 
    0x2, 0x108, 0x109, 0x7, 0x4a, 0x2, 0x2, 0x109, 0x10a, 0x5, 0x7a, 0x3e, 
    0x2, 0x10a, 0x10b, 0x7, 0x4b, 0x2, 0x2, 0x10b, 0x10c, 0x7, 0x4e, 0x2, 
    0x2, 0x10c, 0x10d, 0x5, 0x84, 0x43, 0x2, 0x10d, 0x10e, 0x7, 0x67, 0x2, 
    0x2, 0x10e, 0x10f, 0x7, 0x4f, 0x2, 0x2, 0x10f, 0x124, 0x3, 0x2, 0x2, 
    0x2, 0x110, 0x111, 0x7, 0x3, 0x2, 0x2, 0x111, 0x112, 0x7, 0x4a, 0x2, 
    0x2, 0x112, 0x113, 0x5, 0x7a, 0x3e, 0x2, 0x113, 0x114, 0x7, 0x4b, 0x2, 
    0x2, 0x114, 0x116, 0x7, 0x4e, 0x2, 0x2, 0x115, 0x117, 0x5, 0x84, 0x43, 
    0x2, 0x116, 0x115, 0x3, 0x2, 0x2, 0x2, 0x116, 0x117, 0x3, 0x2, 0x2, 
    0x2, 0x117, 0x118, 0x3, 0x2, 0x2, 0x2, 0x118, 0x119, 0x7, 0x4f, 0x2, 
    0x2, 0x119, 0x124, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11b, 0x7, 0x3, 0x2, 
    0x2, 0x11b, 0x11c, 0x7, 0x4a, 0x2, 0x2, 0x11c, 0x11d, 0x5, 0x7a, 0x3e, 
    0x2, 0x11d, 0x11e, 0x7, 0x4b, 0x2, 0x2, 0x11e, 0x11f, 0x7, 0x4e, 0x2, 
    0x2, 0x11f, 0x120, 0x5, 0x84, 0x43, 0x2, 0x120, 0x121, 0x7, 0x67, 0x2, 
    0x2, 0x121, 0x122, 0x7, 0x4f, 0x2, 0x2, 0x122, 0x124, 0x3, 0x2, 0x2, 
    0x2, 0x123, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x123, 0xff, 0x3, 0x2, 0x2, 0x2, 
    0x123, 0x108, 0x3, 0x2, 0x2, 0x2, 0x123, 0x110, 0x3, 0x2, 0x2, 0x2, 
    0x123, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x124, 0x13c, 0x3, 0x2, 0x2, 0x2, 
    0x125, 0x126, 0xc, 0xc, 0x2, 0x2, 0x126, 0x127, 0x7, 0x4c, 0x2, 0x2, 
    0x127, 0x128, 0x5, 0x30, 0x19, 0x2, 0x128, 0x129, 0x7, 0x4d, 0x2, 0x2, 
    0x129, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12b, 0xc, 0xb, 0x2, 0x2, 
    0x12b, 0x12d, 0x7, 0x4a, 0x2, 0x2, 0x12c, 0x12e, 0x5, 0xc, 0x7, 0x2, 
    0x12d, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12e, 0x3, 0x2, 0x2, 0x2, 
    0x12e, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x13b, 0x7, 0x4b, 0x2, 0x2, 
    0x130, 0x131, 0xc, 0xa, 0x2, 0x2, 0x131, 0x132, 0x7, 0x76, 0x2, 0x2, 
    0x132, 0x13b, 0x7, 0x78, 0x2, 0x2, 0x133, 0x134, 0xc, 0x9, 0x2, 0x2, 
    0x134, 0x135, 0x7, 0x75, 0x2, 0x2, 0x135, 0x13b, 0x7, 0x78, 0x2, 0x2, 
    0x136, 0x137, 0xc, 0x8, 0x2, 0x2, 0x137, 0x13b, 0x7, 0x57, 0x2, 0x2, 
    0x138, 0x139, 0xc, 0x7, 0x2, 0x2, 0x139, 0x13b, 0x7, 0x59, 0x2, 0x2, 
    0x13a, 0x125, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x12a, 0x3, 0x2, 0x2, 0x2, 
    0x13a, 0x130, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x133, 0x3, 0x2, 0x2, 0x2, 
    0x13a, 0x136, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x138, 0x3, 0x2, 0x2, 0x2, 
    0x13b, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x13a, 0x3, 0x2, 0x2, 0x2, 
    0x13c, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x13d, 0xb, 0x3, 0x2, 0x2, 0x2, 0x13e, 
    0x13c, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x144, 0x5, 0x2c, 0x17, 0x2, 0x140, 
    0x141, 0x7, 0x67, 0x2, 0x2, 0x141, 0x143, 0x5, 0x2c, 0x17, 0x2, 0x142, 
    0x140, 0x3, 0x2, 0x2, 0x2, 0x143, 0x146, 0x3, 0x2, 0x2, 0x2, 0x144, 
    0x142, 0x3, 0x2, 0x2, 0x2, 0x144, 0x145, 0x3, 0x2, 0x2, 0x2, 0x145, 
    0xd, 0x3, 0x2, 0x2, 0x2, 0x146, 0x144, 0x3, 0x2, 0x2, 0x2, 0x147, 0x15f, 
    0x5, 0xa, 0x6, 0x2, 0x148, 0x149, 0x7, 0x57, 0x2, 0x2, 0x149, 0x15f, 
    0x5, 0xe, 0x8, 0x2, 0x14a, 0x14b, 0x7, 0x59, 0x2, 0x2, 0x14b, 0x15f, 
    0x5, 0xe, 0x8, 0x2, 0x14c, 0x14d, 0x5, 0x12, 0xa, 0x2, 0x14d, 0x14e, 
    0x5, 0x14, 0xb, 0x2, 0x14e, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x150, 
    0x7, 0x35, 0x2, 0x2, 0x150, 0x15f, 0x5, 0xe, 0x8, 0x2, 0x151, 0x152, 
    0x7, 0x35, 0x2, 0x2, 0x152, 0x153, 0x7, 0x4a, 0x2, 0x2, 0x153, 0x154, 
    0x5, 0x7a, 0x3e, 0x2, 0x154, 0x155, 0x7, 0x4b, 0x2, 0x2, 0x155, 0x15f, 
    0x3, 0x2, 0x2, 0x2, 0x156, 0x157, 0x9, 0x2, 0x2, 0x2, 0x157, 0x158, 
    0x7, 0x4a, 0x2, 0x2, 0x158, 0x159, 0x5, 0x7a, 0x3e, 0x2, 0x159, 0x15a, 
    0x7, 0x4b, 0x2, 0x2, 0x15a, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x15c, 
    0x7, 0x5f, 0x2, 0x2, 0x15c, 0x15f, 0x7, 0x78, 0x2, 0x2, 0x15d, 0x15f, 
    0x5, 0x10, 0x9, 0x2, 0x15e, 0x147, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x148, 
    0x3, 0x2, 0x2, 0x2, 0x15e, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x14c, 
    0x3, 0x2, 0x2, 0x2, 0x15e, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x151, 
    0x3, 0x2, 0x2, 0x2, 0x15e, 0x156, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x15b, 
    0x3, 0x2, 0x2, 0x2, 0x15e, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x15f, 0xf, 0x3, 
    0x2, 0x2, 0x2, 0x160, 0x161, 0x7, 0x7, 0x2, 0x2, 0x161, 0x162, 0x7, 
    0x4a, 0x2, 0x2, 0x162, 0x163, 0x5, 0x7a, 0x3e, 0x2, 0x163, 0x164, 0x7, 
    0x67, 0x2, 0x2, 0x164, 0x165, 0x5, 0x7a, 0x3e, 0x2, 0x165, 0x166, 0x7, 
    0x4b, 0x2, 0x2, 0x166, 0x11, 0x3, 0x2, 0x2, 0x2, 0x167, 0x168, 0x9, 
    0x3, 0x2, 0x2, 0x168, 0x13, 0x3, 0x2, 0x2, 0x2, 0x169, 0x177, 0x5, 0xe, 
    0x8, 0x2, 0x16a, 0x16b, 0x7, 0x4a, 0x2, 0x2, 0x16b, 0x16c, 0x5, 0x7a, 
    0x3e, 0x2, 0x16c, 0x16d, 0x7, 0x4b, 0x2, 0x2, 0x16d, 0x16e, 0x5, 0x14, 
    0xb, 0x2, 0x16e, 0x177, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x170, 0x7, 0x3, 
    0x2, 0x2, 0x170, 0x171, 0x7, 0x4a, 0x2, 0x2, 0x171, 0x172, 0x5, 0x7a, 
    0x3e, 0x2, 0x172, 0x173, 0x7, 0x4b, 0x2, 0x2, 0x173, 0x174, 0x5, 0x14, 
    0xb, 0x2, 0x174, 0x177, 0x3, 0x2, 0x2, 0x2, 0x175, 0x177, 0x7, 0x7a, 
    0x2, 0x2, 0x176, 0x169, 0x3, 0x2, 0x2, 0x2, 0x176, 0x16a, 0x3, 0x2, 
    0x2, 0x2, 0x176, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x176, 0x175, 0x3, 0x2, 
    0x2, 0x2, 0x177, 0x15, 0x3, 0x2, 0x2, 0x2, 0x178, 0x179, 0x8, 0xc, 0x1, 
    0x2, 0x179, 0x17a, 0x5, 0x14, 0xb, 0x2, 0x17a, 0x186, 0x3, 0x2, 0x2, 
    0x2, 0x17b, 0x17c, 0xc, 0x5, 0x2, 0x2, 0x17c, 0x17d, 0x7, 0x5a, 0x2, 
    0x2, 0x17d, 0x185, 0x5, 0x14, 0xb, 0x2, 0x17e, 0x17f, 0xc, 0x4, 0x2, 
    0x2, 0x17f, 0x180, 0x7, 0x5b, 0x2, 0x2, 0x180, 0x185, 0x5, 0x14, 0xb, 
    0x2, 0x181, 0x182, 0xc, 0x3, 0x2, 0x2, 0x182, 0x183, 0x7, 0x5c, 0x2, 
    0x2, 0x183, 0x185, 0x5, 0x14, 0xb, 0x2, 0x184, 0x17b, 0x3, 0x2, 0x2, 
    0x2, 0x184, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x184, 0x181, 0x3, 0x2, 0x2, 
    0x2, 0x185, 0x188, 0x3, 0x2, 0x2, 0x2, 0x186, 0x184, 0x3, 0x2, 0x2, 
    0x2, 0x186, 0x187, 0x3, 0x2, 0x2, 0x2, 0x187, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0x188, 0x186, 0x3, 0x2, 0x2, 0x2, 0x189, 0x18a, 0x8, 0xd, 0x1, 0x2, 
    0x18a, 0x18b, 0x5, 0x16, 0xc, 0x2, 0x18b, 0x194, 0x3, 0x2, 0x2, 0x2, 
    0x18c, 0x18d, 0xc, 0x4, 0x2, 0x2, 0x18d, 0x18e, 0x7, 0x56, 0x2, 0x2, 
    0x18e, 0x193, 0x5, 0x16, 0xc, 0x2, 0x18f, 0x190, 0xc, 0x3, 0x2, 0x2, 
    0x190, 0x191, 0x7, 0x58, 0x2, 0x2, 0x191, 0x193, 0x5, 0x16, 0xc, 0x2, 
    0x192, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x192, 0x18f, 0x3, 0x2, 0x2, 0x2, 
    0x193, 0x196, 0x3, 0x2, 0x2, 0x2, 0x194, 0x192, 0x3, 0x2, 0x2, 0x2, 
    0x194, 0x195, 0x3, 0x2, 0x2, 0x2, 0x195, 0x19, 0x3, 0x2, 0x2, 0x2, 0x196, 
    0x194, 0x3, 0x2, 0x2, 0x2, 0x197, 0x198, 0x8, 0xe, 0x1, 0x2, 0x198, 
    0x199, 0x5, 0x18, 0xd, 0x2, 0x199, 0x1a2, 0x3, 0x2, 0x2, 0x2, 0x19a, 
    0x19b, 0xc, 0x4, 0x2, 0x2, 0x19b, 0x19c, 0x7, 0x54, 0x2, 0x2, 0x19c, 
    0x1a1, 0x5, 0x18, 0xd, 0x2, 0x19d, 0x19e, 0xc, 0x3, 0x2, 0x2, 0x19e, 
    0x19f, 0x7, 0x55, 0x2, 0x2, 0x19f, 0x1a1, 0x5, 0x18, 0xd, 0x2, 0x1a0, 
    0x19a, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x1a1, 
    0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1a0, 0x3, 0x2, 0x2, 0x2, 0x1a2, 
    0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a3, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x1a4, 0x1a2, 
    0x3, 0x2, 0x2, 0x2, 0x1a5, 0x1a6, 0x8, 0xf, 0x1, 0x2, 0x1a6, 0x1a7, 
    0x5, 0x1a, 0xe, 0x2, 0x1a7, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1a9, 
    0xc, 0x6, 0x2, 0x2, 0x1a9, 0x1aa, 0x7, 0x50, 0x2, 0x2, 0x1aa, 0x1b5, 
    0x5, 0x1a, 0xe, 0x2, 0x1ab, 0x1ac, 0xc, 0x5, 0x2, 0x2, 0x1ac, 0x1ad, 
    0x7, 0x52, 0x2, 0x2, 0x1ad, 0x1b5, 0x5, 0x1a, 0xe, 0x2, 0x1ae, 0x1af, 
    0xc, 0x4, 0x2, 0x2, 0x1af, 0x1b0, 0x7, 0x51, 0x2, 0x2, 0x1b0, 0x1b5, 
    0x5, 0x1a, 0xe, 0x2, 0x1b1, 0x1b2, 0xc, 0x3, 0x2, 0x2, 0x1b2, 0x1b3, 
    0x7, 0x53, 0x2, 0x2, 0x1b3, 0x1b5, 0x5, 0x1a, 0xe, 0x2, 0x1b4, 0x1a8, 
    0x3, 0x2, 0x2, 0x2, 0x1b4, 0x1ab, 0x3, 0x2, 0x2, 0x2, 0x1b4, 0x1ae, 
    0x3, 0x2, 0x2, 0x2, 0x1b4, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b8, 
    0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1b4, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1b7, 
    0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1b8, 0x1b6, 0x3, 
    0x2, 0x2, 0x2, 0x1b9, 0x1ba, 0x8, 0x10, 0x1, 0x2, 0x1ba, 0x1bb, 0x5, 
    0x1c, 0xf, 0x2, 0x1bb, 0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1bc, 0x1bd, 0xc, 
    0x4, 0x2, 0x2, 0x1bd, 0x1be, 0x7, 0x73, 0x2, 0x2, 0x1be, 0x1c3, 0x5, 
    0x1c, 0xf, 0x2, 0x1bf, 0x1c0, 0xc, 0x3, 0x2, 0x2, 0x1c0, 0x1c1, 0x7, 
    0x74, 0x2, 0x2, 0x1c1, 0x1c3, 0x5, 0x1c, 0xf, 0x2, 0x1c2, 0x1bc, 0x3, 
    0x2, 0x2, 0x2, 0x1c2, 0x1bf, 0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1c6, 0x3, 
    0x2, 0x2, 0x2, 0x1c4, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1c5, 0x3, 
    0x2, 0x2, 0x2, 0x1c5, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1c6, 0x1c4, 0x3, 0x2, 
    0x2, 0x2, 0x1c7, 0x1c8, 0x8, 0x11, 0x1, 0x2, 0x1c8, 0x1c9, 0x5, 0x1e, 
    0x10, 0x2, 0x1c9, 0x1cf, 0x3, 0x2, 0x2, 0x2, 0x1ca, 0x1cb, 0xc, 0x3, 
    0x2, 0x2, 0x1cb, 0x1cc, 0x7, 0x5d, 0x2, 0x2, 0x1cc, 0x1ce, 0x5, 0x1e, 
    0x10, 0x2, 0x1cd, 0x1ca, 0x3, 0x2, 0x2, 0x2, 0x1ce, 0x1d1, 0x3, 0x2, 
    0x2, 0x2, 0x1cf, 0x1cd, 0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1d0, 0x3, 0x2, 
    0x2, 0x2, 0x1d0, 0x21, 0x3, 0x2, 0x2, 0x2, 0x1d1, 0x1cf, 0x3, 0x2, 0x2, 
    0x2, 0x1d2, 0x1d3, 0x8, 0x12, 0x1, 0x2, 0x1d3, 0x1d4, 0x5, 0x20, 0x11, 
    0x2, 0x1d4, 0x1da, 0x3, 0x2, 0x2, 0x2, 0x1d5, 0x1d6, 0xc, 0x3, 0x2, 
    0x2, 0x1d6, 0x1d7, 0x7, 0x61, 0x2, 0x2, 0x1d7, 0x1d9, 0x5, 0x20, 0x11, 
    0x2, 0x1d8, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d9, 0x1dc, 0x3, 0x2, 0x2, 
    0x2, 0x1da, 0x1d8, 0x3, 0x2, 0x2, 0x2, 0x1da, 0x1db, 0x3, 0x2, 0x2, 
    0x2, 0x1db, 0x23, 0x3, 0x2, 0x2, 0x2, 0x1dc, 0x1da, 0x3, 0x2, 0x2, 0x2, 
    0x1dd, 0x1de, 0x8, 0x13, 0x1, 0x2, 0x1de, 0x1df, 0x5, 0x22, 0x12, 0x2, 
    0x1df, 0x1e5, 0x3, 0x2, 0x2, 0x2, 0x1e0, 0x1e1, 0xc, 0x3, 0x2, 0x2, 
    0x1e1, 0x1e2, 0x7, 0x5e, 0x2, 0x2, 0x1e2, 0x1e4, 0x5, 0x22, 0x12, 0x2, 
    0x1e3, 0x1e0, 0x3, 0x2, 0x2, 0x2, 0x1e4, 0x1e7, 0x3, 0x2, 0x2, 0x2, 
    0x1e5, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1e6, 0x3, 0x2, 0x2, 0x2, 
    0x1e6, 0x25, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1e5, 0x3, 0x2, 0x2, 0x2, 0x1e8, 
    0x1e9, 0x8, 0x14, 0x1, 0x2, 0x1e9, 0x1ea, 0x5, 0x24, 0x13, 0x2, 0x1ea, 
    0x1f0, 0x3, 0x2, 0x2, 0x2, 0x1eb, 0x1ec, 0xc, 0x3, 0x2, 0x2, 0x1ec, 
    0x1ed, 0x7, 0x5f, 0x2, 0x2, 0x1ed, 0x1ef, 0x5, 0x24, 0x13, 0x2, 0x1ee, 
    0x1eb, 0x3, 0x2, 0x2, 0x2, 0x1ef, 0x1f2, 0x3, 0x2, 0x2, 0x2, 0x1f0, 
    0x1ee, 0x3, 0x2, 0x2, 0x2, 0x1f0, 0x1f1, 0x3, 0x2, 0x2, 0x2, 0x1f1, 
    0x27, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1f0, 0x3, 0x2, 0x2, 0x2, 0x1f3, 0x1f4, 
    0x8, 0x15, 0x1, 0x2, 0x1f4, 0x1f5, 0x5, 0x26, 0x14, 0x2, 0x1f5, 0x1fb, 
    0x3, 0x2, 0x2, 0x2, 0x1f6, 0x1f7, 0xc, 0x3, 0x2, 0x2, 0x1f7, 0x1f8, 
    0x7, 0x60, 0x2, 0x2, 0x1f8, 0x1fa, 0x5, 0x26, 0x14, 0x2, 0x1f9, 0x1f6, 
    0x3, 0x2, 0x2, 0x2, 0x1fa, 0x1fd, 0x3, 0x2, 0x2, 0x2, 0x1fb, 0x1f9, 
    0x3, 0x2, 0x2, 0x2, 0x1fb, 0x1fc, 0x3, 0x2, 0x2, 0x2, 0x1fc, 0x29, 0x3, 
    0x2, 0x2, 0x2, 0x1fd, 0x1fb, 0x3, 0x2, 0x2, 0x2, 0x1fe, 0x205, 0x5, 
    0x28, 0x15, 0x2, 0x1ff, 0x201, 0x7, 0x64, 0x2, 0x2, 0x200, 0x202, 0x5, 
    0x30, 0x19, 0x2, 0x201, 0x200, 0x3, 0x2, 0x2, 0x2, 0x201, 0x202, 0x3, 
    0x2, 0x2, 0x2, 0x202, 0x203, 0x3, 0x2, 0x2, 0x2, 0x203, 0x204, 0x7, 
    0x65, 0x2, 0x2, 0x204, 0x206, 0x5, 0x2a, 0x16, 0x2, 0x205, 0x1ff, 0x3, 
    0x2, 0x2, 0x2, 0x205, 0x206, 0x3, 0x2, 0x2, 0x2, 0x206, 0x2b, 0x3, 0x2, 
    0x2, 0x2, 0x207, 0x20e, 0x5, 0x2a, 0x16, 0x2, 0x208, 0x209, 0x5, 0xe, 
    0x8, 0x2, 0x209, 0x20a, 0x5, 0x2e, 0x18, 0x2, 0x20a, 0x20b, 0x5, 0x2c, 
    0x17, 0x2, 0x20b, 0x20e, 0x3, 0x2, 0x2, 0x2, 0x20c, 0x20e, 0x7, 0x7a, 
    0x2, 0x2, 0x20d, 0x207, 0x3, 0x2, 0x2, 0x2, 0x20d, 0x208, 0x3, 0x2, 
    0x2, 0x2, 0x20d, 0x20c, 0x3, 0x2, 0x2, 0x2, 0x20e, 0x2d, 0x3, 0x2, 0x2, 
    0x2, 0x20f, 0x210, 0x9, 0x4, 0x2, 0x2, 0x210, 0x2f, 0x3, 0x2, 0x2, 0x2, 
    0x211, 0x212, 0x8, 0x19, 0x1, 0x2, 0x212, 0x213, 0x5, 0x2c, 0x17, 0x2, 
    0x213, 0x219, 0x3, 0x2, 0x2, 0x2, 0x214, 0x215, 0xc, 0x3, 0x2, 0x2, 
    0x215, 0x216, 0x7, 0x67, 0x2, 0x2, 0x216, 0x218, 0x5, 0x2c, 0x17, 0x2, 
    0x217, 0x214, 0x3, 0x2, 0x2, 0x2, 0x218, 0x21b, 0x3, 0x2, 0x2, 0x2, 
    0x219, 0x217, 0x3, 0x2, 0x2, 0x2, 0x219, 0x21a, 0x3, 0x2, 0x2, 0x2, 
    0x21a, 0x31, 0x3, 0x2, 0x2, 0x2, 0x21b, 0x219, 0x3, 0x2, 0x2, 0x2, 0x21c, 
    0x21d, 0x5, 0x2a, 0x16, 0x2, 0x21d, 0x33, 0x3, 0x2, 0x2, 0x2, 0x21e, 
    0x21f, 0x5, 0x36, 0x1c, 0x2, 0x21f, 0x220, 0x8, 0x1b, 0x1, 0x2, 0x220, 
    0x221, 0x5, 0x3c, 0x1f, 0x2, 0x221, 0x222, 0x7, 0x66, 0x2, 0x2, 0x222, 
    0x223, 0x8, 0x1b, 0x1, 0x2, 0x223, 0x229, 0x3, 0x2, 0x2, 0x2, 0x224, 
    0x225, 0x5, 0x36, 0x1c, 0x2, 0x225, 0x226, 0x7, 0x66, 0x2, 0x2, 0x226, 
    0x229, 0x3, 0x2, 0x2, 0x2, 0x227, 0x229, 0x5, 0x8c, 0x47, 0x2, 0x228, 
    0x21e, 0x3, 0x2, 0x2, 0x2, 0x228, 0x224, 0x3, 0x2, 0x2, 0x2, 0x228, 
    0x227, 0x3, 0x2, 0x2, 0x2, 0x229, 0x35, 0x3, 0x2, 0x2, 0x2, 0x22a, 0x22c, 
    0x5, 0x3a, 0x1e, 0x2, 0x22b, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x22c, 0x22d, 
    0x3, 0x2, 0x2, 0x2, 0x22d, 0x22b, 0x3, 0x2, 0x2, 0x2, 0x22d, 0x22e, 
    0x3, 0x2, 0x2, 0x2, 0x22e, 0x37, 0x3, 0x2, 0x2, 0x2, 0x22f, 0x231, 0x5, 
    0x3a, 0x1e, 0x2, 0x230, 0x22f, 0x3, 0x2, 0x2, 0x2, 0x231, 0x232, 0x3, 
    0x2, 0x2, 0x2, 0x232, 0x230, 0x3, 0x2, 0x2, 0x2, 0x232, 0x233, 0x3, 
    0x2, 0x2, 0x2, 0x233, 0x39, 0x3, 0x2, 0x2, 0x2, 0x234, 0x23b, 0x5, 0x40, 
    0x21, 0x2, 0x235, 0x23b, 0x5, 0x42, 0x22, 0x2, 0x236, 0x23b, 0x5, 0x5a, 
    0x2e, 0x2, 0x237, 0x23b, 0x5, 0x5c, 0x2f, 0x2, 0x238, 0x23b, 0x5, 0x5e, 
    0x30, 0x2, 0x239, 0x23b, 0x5, 0x66, 0x34, 0x2, 0x23a, 0x234, 0x3, 0x2, 
    0x2, 0x2, 0x23a, 0x235, 0x3, 0x2, 0x2, 0x2, 0x23a, 0x236, 0x3, 0x2, 
    0x2, 0x2, 0x23a, 0x237, 0x3, 0x2, 0x2, 0x2, 0x23a, 0x238, 0x3, 0x2, 
    0x2, 0x2, 0x23a, 0x239, 0x3, 0x2, 0x2, 0x2, 0x23b, 0x3b, 0x3, 0x2, 0x2, 
    0x2, 0x23c, 0x241, 0x5, 0x3e, 0x20, 0x2, 0x23d, 0x23e, 0x7, 0x67, 0x2, 
    0x2, 0x23e, 0x240, 0x5, 0x3e, 0x20, 0x2, 0x23f, 0x23d, 0x3, 0x2, 0x2, 
    0x2, 0x240, 0x243, 0x3, 0x2, 0x2, 0x2, 0x241, 0x23f, 0x3, 0x2, 0x2, 
    0x2, 0x241, 0x242, 0x3, 0x2, 0x2, 0x2, 0x242, 0x3d, 0x3, 0x2, 0x2, 0x2, 
    0x243, 0x241, 0x3, 0x2, 0x2, 0x2, 0x244, 0x24a, 0x5, 0x60, 0x31, 0x2, 
    0x245, 0x246, 0x5, 0x60, 0x31, 0x2, 0x246, 0x247, 0x7, 0x68, 0x2, 0x2, 
    0x247, 0x248, 0x5, 0x82, 0x42, 0x2, 0x248, 0x24a, 0x3, 0x2, 0x2, 0x2, 
    0x249, 0x244, 0x3, 0x2, 0x2, 0x2, 0x249, 0x245, 0x3, 0x2, 0x2, 0x2, 
    0x24a, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x24b, 0x24d, 0x7, 0x3, 0x2, 0x2, 0x24c, 
    0x24b, 0x3, 0x2, 0x2, 0x2, 0x24c, 0x24d, 0x3, 0x2, 0x2, 0x2, 0x24d, 
    0x24e, 0x3, 0x2, 0x2, 0x2, 0x24e, 0x24f, 0x7, 0x39, 0x2, 0x2, 0x24f, 
    0x256, 0x8, 0x21, 0x1, 0x2, 0x250, 0x256, 0x7, 0x28, 0x2, 0x2, 0x251, 
    0x256, 0x7, 0x36, 0x2, 0x2, 0x252, 0x256, 0x7, 0x49, 0x2, 0x2, 0x253, 
    0x256, 0x7, 0x1d, 0x2, 0x2, 0x254, 0x256, 0x7, 0x30, 0x2, 0x2, 0x255, 
    0x24c, 0x3, 0x2, 0x2, 0x2, 0x255, 0x250, 0x3, 0x2, 0x2, 0x2, 0x255, 
    0x251, 0x3, 0x2, 0x2, 0x2, 0x255, 0x252, 0x3, 0x2, 0x2, 0x2, 0x255, 
    0x253, 0x3, 0x2, 0x2, 0x2, 0x255, 0x254, 0x3, 0x2, 0x2, 0x2, 0x256, 
    0x41, 0x3, 0x2, 0x2, 0x2, 0x257, 0x258, 0x8, 0x22, 0x1, 0x2, 0x258, 
    0x26d, 0x9, 0x5, 0x2, 0x2, 0x259, 0x25a, 0x7, 0x3, 0x2, 0x2, 0x25a, 
    0x25b, 0x7, 0x4a, 0x2, 0x2, 0x25b, 0x25c, 0x9, 0x6, 0x2, 0x2, 0x25c, 
    0x26d, 0x7, 0x4b, 0x2, 0x2, 0x25d, 0x26d, 0x7, 0x10, 0x2, 0x2, 0x25e, 
    0x26d, 0x5, 0x58, 0x2d, 0x2, 0x25f, 0x26d, 0x5, 0x44, 0x23, 0x2, 0x260, 
    0x26d, 0x5, 0x50, 0x29, 0x2, 0x261, 0x26d, 0x5, 0x80, 0x41, 0x2, 0x262, 
    0x263, 0x9, 0x7, 0x2, 0x2, 0x263, 0x264, 0x7, 0x4a, 0x2, 0x2, 0x264, 
    0x265, 0x5, 0x32, 0x1a, 0x2, 0x265, 0x266, 0x7, 0x4b, 0x2, 0x2, 0x266, 
    0x26d, 0x3, 0x2, 0x2, 0x2, 0x267, 0x268, 0x9, 0x7, 0x2, 0x2, 0x268, 
    0x269, 0x7, 0x4a, 0x2, 0x2, 0x269, 0x26a, 0x5, 0x7a, 0x3e, 0x2, 0x26a, 
    0x26b, 0x7, 0x4b, 0x2, 0x2, 0x26b, 0x26d, 0x3, 0x2, 0x2, 0x2, 0x26c, 
    0x257, 0x3, 0x2, 0x2, 0x2, 0x26c, 0x259, 0x3, 0x2, 0x2, 0x2, 0x26c, 
    0x25d, 0x3, 0x2, 0x2, 0x2, 0x26c, 0x25e, 0x3, 0x2, 0x2, 0x2, 0x26c, 
    0x25f, 0x3, 0x2, 0x2, 0x2, 0x26c, 0x260, 0x3, 0x2, 0x2, 0x2, 0x26c, 
    0x261, 0x3, 0x2, 0x2, 0x2, 0x26c, 0x262, 0x3, 0x2, 0x2, 0x2, 0x26c, 
    0x267, 0x3, 0x2, 0x2, 0x2, 0x26d, 0x272, 0x3, 0x2, 0x2, 0x2, 0x26e, 
    0x26f, 0xc, 0x3, 0x2, 0x2, 0x26f, 0x271, 0x5, 0x6e, 0x38, 0x2, 0x270, 
    0x26e, 0x3, 0x2, 0x2, 0x2, 0x271, 0x274, 0x3, 0x2, 0x2, 0x2, 0x272, 
    0x270, 0x3, 0x2, 0x2, 0x2, 0x272, 0x273, 0x3, 0x2, 0x2, 0x2, 0x273, 
    0x43, 0x3, 0x2, 0x2, 0x2, 0x274, 0x272, 0x3, 0x2, 0x2, 0x2, 0x275, 0x277, 
    0x5, 0x46, 0x24, 0x2, 0x276, 0x278, 0x5, 0x66, 0x34, 0x2, 0x277, 0x276, 
    0x3, 0x2, 0x2, 0x2, 0x277, 0x278, 0x3, 0x2, 0x2, 0x2, 0x278, 0x27a, 
    0x3, 0x2, 0x2, 0x2, 0x279, 0x27b, 0x7, 0x78, 0x2, 0x2, 0x27a, 0x279, 
    0x3, 0x2, 0x2, 0x2, 0x27a, 0x27b, 0x3, 0x2, 0x2, 0x2, 0x27b, 0x27c, 
    0x3, 0x2, 0x2, 0x2, 0x27c, 0x280, 0x7, 0x4e, 0x2, 0x2, 0x27d, 0x27f, 
    0x5, 0x48, 0x25, 0x2, 0x27e, 0x27d, 0x3, 0x2, 0x2, 0x2, 0x27f, 0x282, 
    0x3, 0x2, 0x2, 0x2, 0x280, 0x27e, 0x3, 0x2, 0x2, 0x2, 0x280, 0x281, 
    0x3, 0x2, 0x2, 0x2, 0x281, 0x283, 0x3, 0x2, 0x2, 0x2, 0x282, 0x280, 
    0x3, 0x2, 0x2, 0x2, 0x283, 0x285, 0x7, 0x4f, 0x2, 0x2, 0x284, 0x286, 
    0x5, 0x66, 0x34, 0x2, 0x285, 0x284, 0x3, 0x2, 0x2, 0x2, 0x285, 0x286, 
    0x3, 0x2, 0x2, 0x2, 0x286, 0x28e, 0x3, 0x2, 0x2, 0x2, 0x287, 0x289, 
    0x5, 0x46, 0x24, 0x2, 0x288, 0x28a, 0x5, 0x66, 0x34, 0x2, 0x289, 0x288, 
    0x3, 0x2, 0x2, 0x2, 0x289, 0x28a, 0x3, 0x2, 0x2, 0x2, 0x28a, 0x28b, 
    0x3, 0x2, 0x2, 0x2, 0x28b, 0x28c, 0x7, 0x78, 0x2, 0x2, 0x28c, 0x28e, 
    0x3, 0x2, 0x2, 0x2, 0x28d, 0x275, 0x3, 0x2, 0x2, 0x2, 0x28d, 0x287, 
    0x3, 0x2, 0x2, 0x2, 0x28e, 0x45, 0x3, 0x2, 0x2, 0x2, 0x28f, 0x290, 0x9, 
    0x8, 0x2, 0x2, 0x290, 0x47, 0x3, 0x2, 0x2, 0x2, 0x291, 0x293, 0x5, 0x4a, 
    0x26, 0x2, 0x292, 0x294, 0x5, 0x4c, 0x27, 0x2, 0x293, 0x292, 0x3, 0x2, 
    0x2, 0x2, 0x293, 0x294, 0x3, 0x2, 0x2, 0x2, 0x294, 0x295, 0x3, 0x2, 
    0x2, 0x2, 0x295, 0x296, 0x7, 0x66, 0x2, 0x2, 0x296, 0x29a, 0x3, 0x2, 
    0x2, 0x2, 0x297, 0x29a, 0x7, 0x66, 0x2, 0x2, 0x298, 0x29a, 0x5, 0x8c, 
    0x47, 0x2, 0x299, 0x291, 0x3, 0x2, 0x2, 0x2, 0x299, 0x297, 0x3, 0x2, 
    0x2, 0x2, 0x299, 0x298, 0x3, 0x2, 0x2, 0x2, 0x29a, 0x49, 0x3, 0x2, 0x2, 
    0x2, 0x29b, 0x29e, 0x5, 0x42, 0x22, 0x2, 0x29c, 0x29e, 0x5, 0x5a, 0x2e, 
    0x2, 0x29d, 0x29b, 0x3, 0x2, 0x2, 0x2, 0x29d, 0x29c, 0x3, 0x2, 0x2, 
    0x2, 0x29e, 0x29f, 0x3, 0x2, 0x2, 0x2, 0x29f, 0x29d, 0x3, 0x2, 0x2, 
    0x2, 0x29f, 0x2a0, 0x3, 0x2, 0x2, 0x2, 0x2a0, 0x4b, 0x3, 0x2, 0x2, 0x2, 
    0x2a1, 0x2a6, 0x5, 0x4e, 0x28, 0x2, 0x2a2, 0x2a3, 0x7, 0x67, 0x2, 0x2, 
    0x2a3, 0x2a5, 0x5, 0x4e, 0x28, 0x2, 0x2a4, 0x2a2, 0x3, 0x2, 0x2, 0x2, 
    0x2a5, 0x2a8, 0x3, 0x2, 0x2, 0x2, 0x2a6, 0x2a4, 0x3, 0x2, 0x2, 0x2, 
    0x2a6, 0x2a7, 0x3, 0x2, 0x2, 0x2, 0x2a7, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x2a8, 
    0x2a6, 0x3, 0x2, 0x2, 0x2, 0x2a9, 0x2b0, 0x5, 0x60, 0x31, 0x2, 0x2aa, 
    0x2ac, 0x5, 0x60, 0x31, 0x2, 0x2ab, 0x2aa, 0x3, 0x2, 0x2, 0x2, 0x2ab, 
    0x2ac, 0x3, 0x2, 0x2, 0x2, 0x2ac, 0x2ad, 0x3, 0x2, 0x2, 0x2, 0x2ad, 
    0x2ae, 0x7, 0x65, 0x2, 0x2, 0x2ae, 0x2b0, 0x5, 0x32, 0x1a, 0x2, 0x2af, 
    0x2a9, 0x3, 0x2, 0x2, 0x2, 0x2af, 0x2ab, 0x3, 0x2, 0x2, 0x2, 0x2b0, 
    0x4f, 0x3, 0x2, 0x2, 0x2, 0x2b1, 0x2b3, 0x7, 0x27, 0x2, 0x2, 0x2b2, 
    0x2b4, 0x5, 0x66, 0x34, 0x2, 0x2b3, 0x2b2, 0x3, 0x2, 0x2, 0x2, 0x2b3, 
    0x2b4, 0x3, 0x2, 0x2, 0x2, 0x2b4, 0x2b6, 0x3, 0x2, 0x2, 0x2, 0x2b5, 
    0x2b7, 0x7, 0x78, 0x2, 0x2, 0x2b6, 0x2b5, 0x3, 0x2, 0x2, 0x2, 0x2b6, 
    0x2b7, 0x3, 0x2, 0x2, 0x2, 0x2b7, 0x2b8, 0x3, 0x2, 0x2, 0x2, 0x2b8, 
    0x2b9, 0x7, 0x4e, 0x2, 0x2, 0x2b9, 0x2ba, 0x5, 0x52, 0x2a, 0x2, 0x2ba, 
    0x2bc, 0x7, 0x4f, 0x2, 0x2, 0x2bb, 0x2bd, 0x5, 0x66, 0x34, 0x2, 0x2bc, 
    0x2bb, 0x3, 0x2, 0x2, 0x2, 0x2bc, 0x2bd, 0x3, 0x2, 0x2, 0x2, 0x2bd, 
    0x2d2, 0x3, 0x2, 0x2, 0x2, 0x2be, 0x2c0, 0x7, 0x27, 0x2, 0x2, 0x2bf, 
    0x2c1, 0x5, 0x66, 0x34, 0x2, 0x2c0, 0x2bf, 0x3, 0x2, 0x2, 0x2, 0x2c0, 
    0x2c1, 0x3, 0x2, 0x2, 0x2, 0x2c1, 0x2c3, 0x3, 0x2, 0x2, 0x2, 0x2c2, 
    0x2c4, 0x7, 0x78, 0x2, 0x2, 0x2c3, 0x2c2, 0x3, 0x2, 0x2, 0x2, 0x2c3, 
    0x2c4, 0x3, 0x2, 0x2, 0x2, 0x2c4, 0x2c5, 0x3, 0x2, 0x2, 0x2, 0x2c5, 
    0x2c6, 0x7, 0x4e, 0x2, 0x2, 0x2c6, 0x2c7, 0x5, 0x52, 0x2a, 0x2, 0x2c7, 
    0x2c8, 0x7, 0x67, 0x2, 0x2, 0x2c8, 0x2ca, 0x7, 0x4f, 0x2, 0x2, 0x2c9, 
    0x2cb, 0x5, 0x66, 0x34, 0x2, 0x2ca, 0x2c9, 0x3, 0x2, 0x2, 0x2, 0x2ca, 
    0x2cb, 0x3, 0x2, 0x2, 0x2, 0x2cb, 0x2d2, 0x3, 0x2, 0x2, 0x2, 0x2cc, 
    0x2ce, 0x7, 0x27, 0x2, 0x2, 0x2cd, 0x2cf, 0x5, 0x66, 0x34, 0x2, 0x2ce, 
    0x2cd, 0x3, 0x2, 0x2, 0x2, 0x2ce, 0x2cf, 0x3, 0x2, 0x2, 0x2, 0x2cf, 
    0x2d0, 0x3, 0x2, 0x2, 0x2, 0x2d0, 0x2d2, 0x7, 0x78, 0x2, 0x2, 0x2d1, 
    0x2b1, 0x3, 0x2, 0x2, 0x2, 0x2d1, 0x2be, 0x3, 0x2, 0x2, 0x2, 0x2d1, 
    0x2cc, 0x3, 0x2, 0x2, 0x2, 0x2d2, 0x51, 0x3, 0x2, 0x2, 0x2, 0x2d3, 0x2d4, 
    0x8, 0x2a, 0x1, 0x2, 0x2d4, 0x2d5, 0x5, 0x54, 0x2b, 0x2, 0x2d5, 0x2db, 
    0x3, 0x2, 0x2, 0x2, 0x2d6, 0x2d7, 0xc, 0x3, 0x2, 0x2, 0x2d7, 0x2d8, 
    0x7, 0x67, 0x2, 0x2, 0x2d8, 0x2da, 0x5, 0x54, 0x2b, 0x2, 0x2d9, 0x2d6, 
    0x3, 0x2, 0x2, 0x2, 0x2da, 0x2dd, 0x3, 0x2, 0x2, 0x2, 0x2db, 0x2d9, 
    0x3, 0x2, 0x2, 0x2, 0x2db, 0x2dc, 0x3, 0x2, 0x2, 0x2, 0x2dc, 0x53, 0x3, 
    0x2, 0x2, 0x2, 0x2dd, 0x2db, 0x3, 0x2, 0x2, 0x2, 0x2de, 0x2e4, 0x5, 
    0x56, 0x2c, 0x2, 0x2df, 0x2e0, 0x5, 0x56, 0x2c, 0x2, 0x2e0, 0x2e1, 0x7, 
    0x68, 0x2, 0x2, 0x2e1, 0x2e2, 0x5, 0x32, 0x1a, 0x2, 0x2e2, 0x2e4, 0x3, 
    0x2, 0x2, 0x2, 0x2e3, 0x2de, 0x3, 0x2, 0x2, 0x2, 0x2e3, 0x2df, 0x3, 
    0x2, 0x2, 0x2, 0x2e4, 0x55, 0x3, 0x2, 0x2, 0x2, 0x2e5, 0x2e6, 0x7, 0x78, 
    0x2, 0x2, 0x2e6, 0x57, 0x3, 0x2, 0x2, 0x2, 0x2e7, 0x2e8, 0x7, 0x42, 
    0x2, 0x2, 0x2e8, 0x2e9, 0x7, 0x4a, 0x2, 0x2, 0x2e9, 0x2ea, 0x5, 0x7a, 
    0x3e, 0x2, 0x2ea, 0x2eb, 0x7, 0x4b, 0x2, 0x2, 0x2eb, 0x59, 0x3, 0x2, 
    0x2, 0x2, 0x2ec, 0x2ed, 0x9, 0x9, 0x2, 0x2, 0x2ed, 0x5b, 0x3, 0x2, 0x2, 
    0x2, 0x2ee, 0x2f4, 0x9, 0xa, 0x2, 0x2, 0x2ef, 0x2f0, 0x7, 0x17, 0x2, 
    0x2, 0x2f0, 0x2f1, 0x7, 0x4a, 0x2, 0x2, 0x2f1, 0x2f2, 0x7, 0x78, 0x2, 
    0x2, 0x2f2, 0x2f4, 0x7, 0x4b, 0x2, 0x2, 0x2f3, 0x2ee, 0x3, 0x2, 0x2, 
    0x2, 0x2f3, 0x2ef, 0x3, 0x2, 0x2, 0x2, 0x2f4, 0x5d, 0x3, 0x2, 0x2, 0x2, 
    0x2f5, 0x2f6, 0x7, 0x40, 0x2, 0x2, 0x2f6, 0x2f7, 0x7, 0x4a, 0x2, 0x2, 
    0x2f7, 0x2f8, 0x5, 0x7a, 0x3e, 0x2, 0x2f8, 0x2f9, 0x7, 0x4b, 0x2, 0x2, 
    0x2f9, 0x300, 0x3, 0x2, 0x2, 0x2, 0x2fa, 0x2fb, 0x7, 0x40, 0x2, 0x2, 
    0x2fb, 0x2fc, 0x7, 0x4a, 0x2, 0x2, 0x2fc, 0x2fd, 0x5, 0x32, 0x1a, 0x2, 
    0x2fd, 0x2fe, 0x7, 0x4b, 0x2, 0x2, 0x2fe, 0x300, 0x3, 0x2, 0x2, 0x2, 
    0x2ff, 0x2f5, 0x3, 0x2, 0x2, 0x2, 0x2ff, 0x2fa, 0x3, 0x2, 0x2, 0x2, 
    0x300, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x301, 0x303, 0x5, 0x6e, 0x38, 0x2, 
    0x302, 0x301, 0x3, 0x2, 0x2, 0x2, 0x302, 0x303, 0x3, 0x2, 0x2, 0x2, 
    0x303, 0x305, 0x3, 0x2, 0x2, 0x2, 0x304, 0x306, 0x5, 0x66, 0x34, 0x2, 
    0x305, 0x304, 0x3, 0x2, 0x2, 0x2, 0x305, 0x306, 0x3, 0x2, 0x2, 0x2, 
    0x306, 0x307, 0x3, 0x2, 0x2, 0x2, 0x307, 0x30b, 0x5, 0x62, 0x32, 0x2, 
    0x308, 0x30a, 0x5, 0x64, 0x33, 0x2, 0x309, 0x308, 0x3, 0x2, 0x2, 0x2, 
    0x30a, 0x30d, 0x3, 0x2, 0x2, 0x2, 0x30b, 0x309, 0x3, 0x2, 0x2, 0x2, 
    0x30b, 0x30c, 0x3, 0x2, 0x2, 0x2, 0x30c, 0x61, 0x3, 0x2, 0x2, 0x2, 0x30d, 
    0x30b, 0x3, 0x2, 0x2, 0x2, 0x30e, 0x30f, 0x8, 0x32, 0x1, 0x2, 0x30f, 
    0x310, 0x7, 0x78, 0x2, 0x2, 0x310, 0x321, 0x8, 0x32, 0x1, 0x2, 0x311, 
    0x312, 0x7, 0x4a, 0x2, 0x2, 0x312, 0x313, 0x5, 0x60, 0x31, 0x2, 0x313, 
    0x314, 0x7, 0x4b, 0x2, 0x2, 0x314, 0x321, 0x3, 0x2, 0x2, 0x2, 0x315, 
    0x316, 0x7, 0x78, 0x2, 0x2, 0x316, 0x317, 0x7, 0x65, 0x2, 0x2, 0x317, 
    0x321, 0x7, 0x7a, 0x2, 0x2, 0x318, 0x31a, 0x7, 0x4a, 0x2, 0x2, 0x319, 
    0x31b, 0x5, 0x42, 0x22, 0x2, 0x31a, 0x319, 0x3, 0x2, 0x2, 0x2, 0x31a, 
    0x31b, 0x3, 0x2, 0x2, 0x2, 0x31b, 0x31c, 0x3, 0x2, 0x2, 0x2, 0x31c, 
    0x31d, 0x5, 0x6e, 0x38, 0x2, 0x31d, 0x31e, 0x5, 0x62, 0x32, 0x2, 0x31e, 
    0x31f, 0x7, 0x4b, 0x2, 0x2, 0x31f, 0x321, 0x3, 0x2, 0x2, 0x2, 0x320, 
    0x30e, 0x3, 0x2, 0x2, 0x2, 0x320, 0x311, 0x3, 0x2, 0x2, 0x2, 0x320, 
    0x315, 0x3, 0x2, 0x2, 0x2, 0x320, 0x318, 0x3, 0x2, 0x2, 0x2, 0x321, 
    0x353, 0x3, 0x2, 0x2, 0x2, 0x322, 0x323, 0xc, 0xa, 0x2, 0x2, 0x323, 
    0x325, 0x7, 0x4c, 0x2, 0x2, 0x324, 0x326, 0x5, 0x70, 0x39, 0x2, 0x325, 
    0x324, 0x3, 0x2, 0x2, 0x2, 0x325, 0x326, 0x3, 0x2, 0x2, 0x2, 0x326, 
    0x328, 0x3, 0x2, 0x2, 0x2, 0x327, 0x329, 0x5, 0x2c, 0x17, 0x2, 0x328, 
    0x327, 0x3, 0x2, 0x2, 0x2, 0x328, 0x329, 0x3, 0x2, 0x2, 0x2, 0x329, 
    0x32a, 0x3, 0x2, 0x2, 0x2, 0x32a, 0x352, 0x7, 0x4d, 0x2, 0x2, 0x32b, 
    0x32c, 0xc, 0x9, 0x2, 0x2, 0x32c, 0x32d, 0x7, 0x4c, 0x2, 0x2, 0x32d, 
    0x32f, 0x7, 0x36, 0x2, 0x2, 0x32e, 0x330, 0x5, 0x70, 0x39, 0x2, 0x32f, 
    0x32e, 0x3, 0x2, 0x2, 0x2, 0x32f, 0x330, 0x3, 0x2, 0x2, 0x2, 0x330, 
    0x331, 0x3, 0x2, 0x2, 0x2, 0x331, 0x332, 0x5, 0x2c, 0x17, 0x2, 0x332, 
    0x333, 0x7, 0x4d, 0x2, 0x2, 0x333, 0x352, 0x3, 0x2, 0x2, 0x2, 0x334, 
    0x335, 0xc, 0x8, 0x2, 0x2, 0x335, 0x336, 0x7, 0x4c, 0x2, 0x2, 0x336, 
    0x337, 0x5, 0x70, 0x39, 0x2, 0x337, 0x338, 0x7, 0x36, 0x2, 0x2, 0x338, 
    0x339, 0x5, 0x2c, 0x17, 0x2, 0x339, 0x33a, 0x7, 0x4d, 0x2, 0x2, 0x33a, 
    0x352, 0x3, 0x2, 0x2, 0x2, 0x33b, 0x33c, 0xc, 0x7, 0x2, 0x2, 0x33c, 
    0x33e, 0x7, 0x4c, 0x2, 0x2, 0x33d, 0x33f, 0x5, 0x70, 0x39, 0x2, 0x33e, 
    0x33d, 0x3, 0x2, 0x2, 0x2, 0x33e, 0x33f, 0x3, 0x2, 0x2, 0x2, 0x33f, 
    0x340, 0x3, 0x2, 0x2, 0x2, 0x340, 0x341, 0x7, 0x5a, 0x2, 0x2, 0x341, 
    0x352, 0x7, 0x4d, 0x2, 0x2, 0x342, 0x343, 0xc, 0x6, 0x2, 0x2, 0x343, 
    0x344, 0x7, 0x4a, 0x2, 0x2, 0x344, 0x345, 0x8, 0x32, 0x1, 0x2, 0x345, 
    0x346, 0x5, 0x72, 0x3a, 0x2, 0x346, 0x347, 0x8, 0x32, 0x1, 0x2, 0x347, 
    0x348, 0x7, 0x4b, 0x2, 0x2, 0x348, 0x352, 0x3, 0x2, 0x2, 0x2, 0x349, 
    0x34a, 0xc, 0x5, 0x2, 0x2, 0x34a, 0x34b, 0x7, 0x4a, 0x2, 0x2, 0x34b, 
    0x34d, 0x8, 0x32, 0x1, 0x2, 0x34c, 0x34e, 0x5, 0x78, 0x3d, 0x2, 0x34d, 
    0x34c, 0x3, 0x2, 0x2, 0x2, 0x34d, 0x34e, 0x3, 0x2, 0x2, 0x2, 0x34e, 
    0x34f, 0x3, 0x2, 0x2, 0x2, 0x34f, 0x350, 0x8, 0x32, 0x1, 0x2, 0x350, 
    0x352, 0x7, 0x4b, 0x2, 0x2, 0x351, 0x322, 0x3, 0x2, 0x2, 0x2, 0x351, 
    0x32b, 0x3, 0x2, 0x2, 0x2, 0x351, 0x334, 0x3, 0x2, 0x2, 0x2, 0x351, 
    0x33b, 0x3, 0x2, 0x2, 0x2, 0x351, 0x342, 0x3, 0x2, 0x2, 0x2, 0x351, 
    0x349, 0x3, 0x2, 0x2, 0x2, 0x352, 0x355, 0x3, 0x2, 0x2, 0x2, 0x353, 
    0x351, 0x3, 0x2, 0x2, 0x2, 0x353, 0x354, 0x3, 0x2, 0x2, 0x2, 0x354, 
    0x63, 0x3, 0x2, 0x2, 0x2, 0x355, 0x353, 0x3, 0x2, 0x2, 0x2, 0x356, 0x357, 
    0x9, 0xb, 0x2, 0x2, 0x357, 0x359, 0x7, 0x4a, 0x2, 0x2, 0x358, 0x35a, 
    0x7, 0x7b, 0x2, 0x2, 0x359, 0x358, 0x3, 0x2, 0x2, 0x2, 0x35a, 0x35b, 
    0x3, 0x2, 0x2, 0x2, 0x35b, 0x359, 0x3, 0x2, 0x2, 0x2, 0x35b, 0x35c, 
    0x3, 0x2, 0x2, 0x2, 0x35c, 0x35d, 0x3, 0x2, 0x2, 0x2, 0x35d, 0x360, 
    0x7, 0x4b, 0x2, 0x2, 0x35e, 0x360, 0x5, 0x66, 0x34, 0x2, 0x35f, 0x356, 
    0x3, 0x2, 0x2, 0x2, 0x35f, 0x35e, 0x3, 0x2, 0x2, 0x2, 0x360, 0x65, 0x3, 
    0x2, 0x2, 0x2, 0x361, 0x362, 0x7, 0x1b, 0x2, 0x2, 0x362, 0x363, 0x7, 
    0x4a, 0x2, 0x2, 0x363, 0x364, 0x7, 0x4a, 0x2, 0x2, 0x364, 0x365, 0x5, 
    0x68, 0x35, 0x2, 0x365, 0x366, 0x7, 0x4b, 0x2, 0x2, 0x366, 0x367, 0x7, 
    0x4b, 0x2, 0x2, 0x367, 0x67, 0x3, 0x2, 0x2, 0x2, 0x368, 0x36d, 0x5, 
    0x6a, 0x36, 0x2, 0x369, 0x36a, 0x7, 0x67, 0x2, 0x2, 0x36a, 0x36c, 0x5, 
    0x6a, 0x36, 0x2, 0x36b, 0x369, 0x3, 0x2, 0x2, 0x2, 0x36c, 0x36f, 0x3, 
    0x2, 0x2, 0x2, 0x36d, 0x36b, 0x3, 0x2, 0x2, 0x2, 0x36d, 0x36e, 0x3, 
    0x2, 0x2, 0x2, 0x36e, 0x372, 0x3, 0x2, 0x2, 0x2, 0x36f, 0x36d, 0x3, 
    0x2, 0x2, 0x2, 0x370, 0x372, 0x3, 0x2, 0x2, 0x2, 0x371, 0x368, 0x3, 
    0x2, 0x2, 0x2, 0x371, 0x370, 0x3, 0x2, 0x2, 0x2, 0x372, 0x69, 0x3, 0x2, 
    0x2, 0x2, 0x373, 0x379, 0xa, 0xc, 0x2, 0x2, 0x374, 0x376, 0x7, 0x4a, 
    0x2, 0x2, 0x375, 0x377, 0x5, 0xc, 0x7, 0x2, 0x376, 0x375, 0x3, 0x2, 
    0x2, 0x2, 0x376, 0x377, 0x3, 0x2, 0x2, 0x2, 0x377, 0x378, 0x3, 0x2, 
    0x2, 0x2, 0x378, 0x37a, 0x7, 0x4b, 0x2, 0x2, 0x379, 0x374, 0x3, 0x2, 
    0x2, 0x2, 0x379, 0x37a, 0x3, 0x2, 0x2, 0x2, 0x37a, 0x37d, 0x3, 0x2, 
    0x2, 0x2, 0x37b, 0x37d, 0x3, 0x2, 0x2, 0x2, 0x37c, 0x373, 0x3, 0x2, 
    0x2, 0x2, 0x37c, 0x37b, 0x3, 0x2, 0x2, 0x2, 0x37d, 0x6b, 0x3, 0x2, 0x2, 
    0x2, 0x37e, 0x384, 0xa, 0xd, 0x2, 0x2, 0x37f, 0x380, 0x7, 0x4a, 0x2, 
    0x2, 0x380, 0x381, 0x5, 0x6c, 0x37, 0x2, 0x381, 0x382, 0x7, 0x4b, 0x2, 
    0x2, 0x382, 0x384, 0x3, 0x2, 0x2, 0x2, 0x383, 0x37e, 0x3, 0x2, 0x2, 
    0x2, 0x383, 0x37f, 0x3, 0x2, 0x2, 0x2, 0x384, 0x387, 0x3, 0x2, 0x2, 
    0x2, 0x385, 0x383, 0x3, 0x2, 0x2, 0x2, 0x385, 0x386, 0x3, 0x2, 0x2, 
    0x2, 0x386, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x387, 0x385, 0x3, 0x2, 0x2, 0x2, 
    0x388, 0x38a, 0x7, 0x5a, 0x2, 0x2, 0x389, 0x38b, 0x5, 0x70, 0x39, 0x2, 
    0x38a, 0x389, 0x3, 0x2, 0x2, 0x2, 0x38a, 0x38b, 0x3, 0x2, 0x2, 0x2, 
    0x38b, 0x39b, 0x3, 0x2, 0x2, 0x2, 0x38c, 0x38e, 0x7, 0x5a, 0x2, 0x2, 
    0x38d, 0x38f, 0x5, 0x70, 0x39, 0x2, 0x38e, 0x38d, 0x3, 0x2, 0x2, 0x2, 
    0x38e, 0x38f, 0x3, 0x2, 0x2, 0x2, 0x38f, 0x390, 0x3, 0x2, 0x2, 0x2, 
    0x390, 0x39b, 0x5, 0x6e, 0x38, 0x2, 0x391, 0x393, 0x7, 0x61, 0x2, 0x2, 
    0x392, 0x394, 0x5, 0x70, 0x39, 0x2, 0x393, 0x392, 0x3, 0x2, 0x2, 0x2, 
    0x393, 0x394, 0x3, 0x2, 0x2, 0x2, 0x394, 0x39b, 0x3, 0x2, 0x2, 0x2, 
    0x395, 0x397, 0x7, 0x61, 0x2, 0x2, 0x396, 0x398, 0x5, 0x70, 0x39, 0x2, 
    0x397, 0x396, 0x3, 0x2, 0x2, 0x2, 0x397, 0x398, 0x3, 0x2, 0x2, 0x2, 
    0x398, 0x399, 0x3, 0x2, 0x2, 0x2, 0x399, 0x39b, 0x5, 0x6e, 0x38, 0x2, 
    0x39a, 0x388, 0x3, 0x2, 0x2, 0x2, 0x39a, 0x38c, 0x3, 0x2, 0x2, 0x2, 
    0x39a, 0x391, 0x3, 0x2, 0x2, 0x2, 0x39a, 0x395, 0x3, 0x2, 0x2, 0x2, 
    0x39b, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x39c, 0x39d, 0x8, 0x39, 0x1, 0x2, 
    0x39d, 0x39e, 0x5, 0x5a, 0x2e, 0x2, 0x39e, 0x3a3, 0x3, 0x2, 0x2, 0x2, 
    0x39f, 0x3a0, 0xc, 0x3, 0x2, 0x2, 0x3a0, 0x3a2, 0x5, 0x5a, 0x2e, 0x2, 
    0x3a1, 0x39f, 0x3, 0x2, 0x2, 0x2, 0x3a2, 0x3a5, 0x3, 0x2, 0x2, 0x2, 
    0x3a3, 0x3a1, 0x3, 0x2, 0x2, 0x2, 0x3a3, 0x3a4, 0x3, 0x2, 0x2, 0x2, 
    0x3a4, 0x71, 0x3, 0x2, 0x2, 0x2, 0x3a5, 0x3a3, 0x3, 0x2, 0x2, 0x2, 0x3a6, 
    0x3ac, 0x5, 0x74, 0x3b, 0x2, 0x3a7, 0x3a8, 0x5, 0x74, 0x3b, 0x2, 0x3a8, 
    0x3a9, 0x7, 0x67, 0x2, 0x2, 0x3a9, 0x3aa, 0x7, 0x77, 0x2, 0x2, 0x3aa, 
    0x3ac, 0x3, 0x2, 0x2, 0x2, 0x3ab, 0x3a6, 0x3, 0x2, 0x2, 0x2, 0x3ab, 
    0x3a7, 0x3, 0x2, 0x2, 0x2, 0x3ac, 0x73, 0x3, 0x2, 0x2, 0x2, 0x3ad, 0x3b2, 
    0x5, 0x76, 0x3c, 0x2, 0x3ae, 0x3af, 0x7, 0x67, 0x2, 0x2, 0x3af, 0x3b1, 
    0x5, 0x76, 0x3c, 0x2, 0x3b0, 0x3ae, 0x3, 0x2, 0x2, 0x2, 0x3b1, 0x3b4, 
    0x3, 0x2, 0x2, 0x2, 0x3b2, 0x3b0, 0x3, 0x2, 0x2, 0x2, 0x3b2, 0x3b3, 
    0x3, 0x2, 0x2, 0x2, 0x3b3, 0x75, 0x3, 0x2, 0x2, 0x2, 0x3b4, 0x3b2, 0x3, 
    0x2, 0x2, 0x2, 0x3b5, 0x3b6, 0x5, 0x36, 0x1c, 0x2, 0x3b6, 0x3b7, 0x5, 
    0x60, 0x31, 0x2, 0x3b7, 0x3bd, 0x3, 0x2, 0x2, 0x2, 0x3b8, 0x3ba, 0x5, 
    0x38, 0x1d, 0x2, 0x3b9, 0x3bb, 0x5, 0x7c, 0x3f, 0x2, 0x3ba, 0x3b9, 0x3, 
    0x2, 0x2, 0x2, 0x3ba, 0x3bb, 0x3, 0x2, 0x2, 0x2, 0x3bb, 0x3bd, 0x3, 
    0x2, 0x2, 0x2, 0x3bc, 0x3b5, 0x3, 0x2, 0x2, 0x2, 0x3bc, 0x3b8, 0x3, 
    0x2, 0x2, 0x2, 0x3bd, 0x77, 0x3, 0x2, 0x2, 0x2, 0x3be, 0x3bf, 0x8, 0x3d, 
    0x1, 0x2, 0x3bf, 0x3c0, 0x7, 0x78, 0x2, 0x2, 0x3c0, 0x3c6, 0x3, 0x2, 
    0x2, 0x2, 0x3c1, 0x3c2, 0xc, 0x3, 0x2, 0x2, 0x3c2, 0x3c3, 0x7, 0x67, 
    0x2, 0x2, 0x3c3, 0x3c5, 0x7, 0x78, 0x2, 0x2, 0x3c4, 0x3c1, 0x3, 0x2, 
    0x2, 0x2, 0x3c5, 0x3c8, 0x3, 0x2, 0x2, 0x2, 0x3c6, 0x3c4, 0x3, 0x2, 
    0x2, 0x2, 0x3c6, 0x3c7, 0x3, 0x2, 0x2, 0x2, 0x3c7, 0x79, 0x3, 0x2, 0x2, 
    0x2, 0x3c8, 0x3c6, 0x3, 0x2, 0x2, 0x2, 0x3c9, 0x3cb, 0x5, 0x4a, 0x26, 
    0x2, 0x3ca, 0x3cc, 0x5, 0x7c, 0x3f, 0x2, 0x3cb, 0x3ca, 0x3, 0x2, 0x2, 
    0x2, 0x3cb, 0x3cc, 0x3, 0x2, 0x2, 0x2, 0x3cc, 0x7b, 0x3, 0x2, 0x2, 0x2, 
    0x3cd, 0x3d9, 0x5, 0x6e, 0x38, 0x2, 0x3ce, 0x3d0, 0x5, 0x6e, 0x38, 0x2, 
    0x3cf, 0x3ce, 0x3, 0x2, 0x2, 0x2, 0x3cf, 0x3d0, 0x3, 0x2, 0x2, 0x2, 
    0x3d0, 0x3d1, 0x3, 0x2, 0x2, 0x2, 0x3d1, 0x3d5, 0x5, 0x7e, 0x40, 0x2, 
    0x3d2, 0x3d4, 0x5, 0x64, 0x33, 0x2, 0x3d3, 0x3d2, 0x3, 0x2, 0x2, 0x2, 
    0x3d4, 0x3d7, 0x3, 0x2, 0x2, 0x2, 0x3d5, 0x3d3, 0x3, 0x2, 0x2, 0x2, 
    0x3d5, 0x3d6, 0x3, 0x2, 0x2, 0x2, 0x3d6, 0x3d9, 0x3, 0x2, 0x2, 0x2, 
    0x3d7, 0x3d5, 0x3, 0x2, 0x2, 0x2, 0x3d8, 0x3cd, 0x3, 0x2, 0x2, 0x2, 
    0x3d8, 0x3cf, 0x3, 0x2, 0x2, 0x2, 0x3d9, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x3da, 
    0x3db, 0x8, 0x40, 0x1, 0x2, 0x3db, 0x3dc, 0x7, 0x4a, 0x2, 0x2, 0x3dc, 
    0x3dd, 0x5, 0x7c, 0x3f, 0x2, 0x3dd, 0x3e1, 0x7, 0x4b, 0x2, 0x2, 0x3de, 
    0x3e0, 0x5, 0x64, 0x33, 0x2, 0x3df, 0x3de, 0x3, 0x2, 0x2, 0x2, 0x3e0, 
    0x3e3, 0x3, 0x2, 0x2, 0x2, 0x3e1, 0x3df, 0x3, 0x2, 0x2, 0x2, 0x3e1, 
    0x3e2, 0x3, 0x2, 0x2, 0x2, 0x3e2, 0x409, 0x3, 0x2, 0x2, 0x2, 0x3e3, 
    0x3e1, 0x3, 0x2, 0x2, 0x2, 0x3e4, 0x3e6, 0x7, 0x4c, 0x2, 0x2, 0x3e5, 
    0x3e7, 0x5, 0x70, 0x39, 0x2, 0x3e6, 0x3e5, 0x3, 0x2, 0x2, 0x2, 0x3e6, 
    0x3e7, 0x3, 0x2, 0x2, 0x2, 0x3e7, 0x3e9, 0x3, 0x2, 0x2, 0x2, 0x3e8, 
    0x3ea, 0x5, 0x2c, 0x17, 0x2, 0x3e9, 0x3e8, 0x3, 0x2, 0x2, 0x2, 0x3e9, 
    0x3ea, 0x3, 0x2, 0x2, 0x2, 0x3ea, 0x3eb, 0x3, 0x2, 0x2, 0x2, 0x3eb, 
    0x409, 0x7, 0x4d, 0x2, 0x2, 0x3ec, 0x3ed, 0x7, 0x4c, 0x2, 0x2, 0x3ed, 
    0x3ef, 0x7, 0x36, 0x2, 0x2, 0x3ee, 0x3f0, 0x5, 0x70, 0x39, 0x2, 0x3ef, 
    0x3ee, 0x3, 0x2, 0x2, 0x2, 0x3ef, 0x3f0, 0x3, 0x2, 0x2, 0x2, 0x3f0, 
    0x3f1, 0x3, 0x2, 0x2, 0x2, 0x3f1, 0x3f2, 0x5, 0x2c, 0x17, 0x2, 0x3f2, 
    0x3f3, 0x7, 0x4d, 0x2, 0x2, 0x3f3, 0x409, 0x3, 0x2, 0x2, 0x2, 0x3f4, 
    0x3f5, 0x7, 0x4c, 0x2, 0x2, 0x3f5, 0x3f6, 0x5, 0x70, 0x39, 0x2, 0x3f6, 
    0x3f7, 0x7, 0x36, 0x2, 0x2, 0x3f7, 0x3f8, 0x5, 0x2c, 0x17, 0x2, 0x3f8, 
    0x3f9, 0x7, 0x4d, 0x2, 0x2, 0x3f9, 0x409, 0x3, 0x2, 0x2, 0x2, 0x3fa, 
    0x3fb, 0x7, 0x4c, 0x2, 0x2, 0x3fb, 0x3fc, 0x7, 0x5a, 0x2, 0x2, 0x3fc, 
    0x409, 0x7, 0x4d, 0x2, 0x2, 0x3fd, 0x3ff, 0x7, 0x4a, 0x2, 0x2, 0x3fe, 
    0x400, 0x5, 0x72, 0x3a, 0x2, 0x3ff, 0x3fe, 0x3, 0x2, 0x2, 0x2, 0x3ff, 
    0x400, 0x3, 0x2, 0x2, 0x2, 0x400, 0x401, 0x3, 0x2, 0x2, 0x2, 0x401, 
    0x405, 0x7, 0x4b, 0x2, 0x2, 0x402, 0x404, 0x5, 0x64, 0x33, 0x2, 0x403, 
    0x402, 0x3, 0x2, 0x2, 0x2, 0x404, 0x407, 0x3, 0x2, 0x2, 0x2, 0x405, 
    0x403, 0x3, 0x2, 0x2, 0x2, 0x405, 0x406, 0x3, 0x2, 0x2, 0x2, 0x406, 
    0x409, 0x3, 0x2, 0x2, 0x2, 0x407, 0x405, 0x3, 0x2, 0x2, 0x2, 0x408, 
    0x3da, 0x3, 0x2, 0x2, 0x2, 0x408, 0x3e4, 0x3, 0x2, 0x2, 0x2, 0x408, 
    0x3ec, 0x3, 0x2, 0x2, 0x2, 0x408, 0x3f4, 0x3, 0x2, 0x2, 0x2, 0x408, 
    0x3fa, 0x3, 0x2, 0x2, 0x2, 0x408, 0x3fd, 0x3, 0x2, 0x2, 0x2, 0x409, 
    0x435, 0x3, 0x2, 0x2, 0x2, 0x40a, 0x40b, 0xc, 0x7, 0x2, 0x2, 0x40b, 
    0x40d, 0x7, 0x4c, 0x2, 0x2, 0x40c, 0x40e, 0x5, 0x70, 0x39, 0x2, 0x40d, 
    0x40c, 0x3, 0x2, 0x2, 0x2, 0x40d, 0x40e, 0x3, 0x2, 0x2, 0x2, 0x40e, 
    0x410, 0x3, 0x2, 0x2, 0x2, 0x40f, 0x411, 0x5, 0x2c, 0x17, 0x2, 0x410, 
    0x40f, 0x3, 0x2, 0x2, 0x2, 0x410, 0x411, 0x3, 0x2, 0x2, 0x2, 0x411, 
    0x412, 0x3, 0x2, 0x2, 0x2, 0x412, 0x434, 0x7, 0x4d, 0x2, 0x2, 0x413, 
    0x414, 0xc, 0x6, 0x2, 0x2, 0x414, 0x415, 0x7, 0x4c, 0x2, 0x2, 0x415, 
    0x417, 0x7, 0x36, 0x2, 0x2, 0x416, 0x418, 0x5, 0x70, 0x39, 0x2, 0x417, 
    0x416, 0x3, 0x2, 0x2, 0x2, 0x417, 0x418, 0x3, 0x2, 0x2, 0x2, 0x418, 
    0x419, 0x3, 0x2, 0x2, 0x2, 0x419, 0x41a, 0x5, 0x2c, 0x17, 0x2, 0x41a, 
    0x41b, 0x7, 0x4d, 0x2, 0x2, 0x41b, 0x434, 0x3, 0x2, 0x2, 0x2, 0x41c, 
    0x41d, 0xc, 0x5, 0x2, 0x2, 0x41d, 0x41e, 0x7, 0x4c, 0x2, 0x2, 0x41e, 
    0x41f, 0x5, 0x70, 0x39, 0x2, 0x41f, 0x420, 0x7, 0x36, 0x2, 0x2, 0x420, 
    0x421, 0x5, 0x2c, 0x17, 0x2, 0x421, 0x422, 0x7, 0x4d, 0x2, 0x2, 0x422, 
    0x434, 0x3, 0x2, 0x2, 0x2, 0x423, 0x424, 0xc, 0x4, 0x2, 0x2, 0x424, 
    0x425, 0x7, 0x4c, 0x2, 0x2, 0x425, 0x426, 0x7, 0x5a, 0x2, 0x2, 0x426, 
    0x434, 0x7, 0x4d, 0x2, 0x2, 0x427, 0x428, 0xc, 0x3, 0x2, 0x2, 0x428, 
    0x42a, 0x7, 0x4a, 0x2, 0x2, 0x429, 0x42b, 0x5, 0x72, 0x3a, 0x2, 0x42a, 
    0x429, 0x3, 0x2, 0x2, 0x2, 0x42a, 0x42b, 0x3, 0x2, 0x2, 0x2, 0x42b, 
    0x42c, 0x3, 0x2, 0x2, 0x2, 0x42c, 0x430, 0x7, 0x4b, 0x2, 0x2, 0x42d, 
    0x42f, 0x5, 0x64, 0x33, 0x2, 0x42e, 0x42d, 0x3, 0x2, 0x2, 0x2, 0x42f, 
    0x432, 0x3, 0x2, 0x2, 0x2, 0x430, 0x42e, 0x3, 0x2, 0x2, 0x2, 0x430, 
    0x431, 0x3, 0x2, 0x2, 0x2, 0x431, 0x434, 0x3, 0x2, 0x2, 0x2, 0x432, 
    0x430, 0x3, 0x2, 0x2, 0x2, 0x433, 0x40a, 0x3, 0x2, 0x2, 0x2, 0x433, 
    0x413, 0x3, 0x2, 0x2, 0x2, 0x433, 0x41c, 0x3, 0x2, 0x2, 0x2, 0x433, 
    0x423, 0x3, 0x2, 0x2, 0x2, 0x433, 0x427, 0x3, 0x2, 0x2, 0x2, 0x434, 
    0x437, 0x3, 0x2, 0x2, 0x2, 0x435, 0x433, 0x3, 0x2, 0x2, 0x2, 0x435, 
    0x436, 0x3, 0x2, 0x2, 0x2, 0x436, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x437, 0x435, 
    0x3, 0x2, 0x2, 0x2, 0x438, 0x439, 0x6, 0x41, 0x2a, 0x2, 0x439, 0x43a, 
    0x7, 0x78, 0x2, 0x2, 0x43a, 0x81, 0x3, 0x2, 0x2, 0x2, 0x43b, 0x448, 
    0x5, 0x2c, 0x17, 0x2, 0x43c, 0x43d, 0x7, 0x4e, 0x2, 0x2, 0x43d, 0x448, 
    0x7, 0x4f, 0x2, 0x2, 0x43e, 0x43f, 0x7, 0x4e, 0x2, 0x2, 0x43f, 0x440, 
    0x5, 0x84, 0x43, 0x2, 0x440, 0x441, 0x7, 0x4f, 0x2, 0x2, 0x441, 0x448, 
    0x3, 0x2, 0x2, 0x2, 0x442, 0x443, 0x7, 0x4e, 0x2, 0x2, 0x443, 0x444, 
    0x5, 0x84, 0x43, 0x2, 0x444, 0x445, 0x7, 0x67, 0x2, 0x2, 0x445, 0x446, 
    0x7, 0x4f, 0x2, 0x2, 0x446, 0x448, 0x3, 0x2, 0x2, 0x2, 0x447, 0x43b, 
    0x3, 0x2, 0x2, 0x2, 0x447, 0x43c, 0x3, 0x2, 0x2, 0x2, 0x447, 0x43e, 
    0x3, 0x2, 0x2, 0x2, 0x447, 0x442, 0x3, 0x2, 0x2, 0x2, 0x448, 0x83, 0x3, 
    0x2, 0x2, 0x2, 0x449, 0x44b, 0x8, 0x43, 0x1, 0x2, 0x44a, 0x44c, 0x5, 
    0x86, 0x44, 0x2, 0x44b, 0x44a, 0x3, 0x2, 0x2, 0x2, 0x44b, 0x44c, 0x3, 
    0x2, 0x2, 0x2, 0x44c, 0x44d, 0x3, 0x2, 0x2, 0x2, 0x44d, 0x44e, 0x5, 
    0x82, 0x42, 0x2, 0x44e, 0x457, 0x3, 0x2, 0x2, 0x2, 0x44f, 0x450, 0xc, 
    0x3, 0x2, 0x2, 0x450, 0x452, 0x7, 0x67, 0x2, 0x2, 0x451, 0x453, 0x5, 
    0x86, 0x44, 0x2, 0x452, 0x451, 0x3, 0x2, 0x2, 0x2, 0x452, 0x453, 0x3, 
    0x2, 0x2, 0x2, 0x453, 0x454, 0x3, 0x2, 0x2, 0x2, 0x454, 0x456, 0x5, 
    0x82, 0x42, 0x2, 0x455, 0x44f, 0x3, 0x2, 0x2, 0x2, 0x456, 0x459, 0x3, 
    0x2, 0x2, 0x2, 0x457, 0x455, 0x3, 0x2, 0x2, 0x2, 0x457, 0x458, 0x3, 
    0x2, 0x2, 0x2, 0x458, 0x85, 0x3, 0x2, 0x2, 0x2, 0x459, 0x457, 0x3, 0x2, 
    0x2, 0x2, 0x45a, 0x45b, 0x5, 0x88, 0x45, 0x2, 0x45b, 0x45c, 0x7, 0x68, 
    0x2, 0x2, 0x45c, 0x87, 0x3, 0x2, 0x2, 0x2, 0x45d, 0x45e, 0x8, 0x45, 
    0x1, 0x2, 0x45e, 0x45f, 0x5, 0x8a, 0x46, 0x2, 0x45f, 0x464, 0x3, 0x2, 
    0x2, 0x2, 0x460, 0x461, 0xc, 0x3, 0x2, 0x2, 0x461, 0x463, 0x5, 0x8a, 
    0x46, 0x2, 0x462, 0x460, 0x3, 0x2, 0x2, 0x2, 0x463, 0x466, 0x3, 0x2, 
    0x2, 0x2, 0x464, 0x462, 0x3, 0x2, 0x2, 0x2, 0x464, 0x465, 0x3, 0x2, 
    0x2, 0x2, 0x465, 0x89, 0x3, 0x2, 0x2, 0x2, 0x466, 0x464, 0x3, 0x2, 0x2, 
    0x2, 0x467, 0x468, 0x7, 0x4c, 0x2, 0x2, 0x468, 0x469, 0x5, 0x32, 0x1a, 
    0x2, 0x469, 0x46a, 0x7, 0x4d, 0x2, 0x2, 0x46a, 0x46e, 0x3, 0x2, 0x2, 
    0x2, 0x46b, 0x46c, 0x7, 0x76, 0x2, 0x2, 0x46c, 0x46e, 0x7, 0x78, 0x2, 
    0x2, 0x46d, 0x467, 0x3, 0x2, 0x2, 0x2, 0x46d, 0x46b, 0x3, 0x2, 0x2, 
    0x2, 0x46e, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x46f, 0x470, 0x7, 0x48, 0x2, 
    0x2, 0x470, 0x471, 0x7, 0x4a, 0x2, 0x2, 0x471, 0x472, 0x5, 0x32, 0x1a, 
    0x2, 0x472, 0x474, 0x7, 0x67, 0x2, 0x2, 0x473, 0x475, 0x7, 0x7b, 0x2, 
    0x2, 0x474, 0x473, 0x3, 0x2, 0x2, 0x2, 0x475, 0x476, 0x3, 0x2, 0x2, 
    0x2, 0x476, 0x474, 0x3, 0x2, 0x2, 0x2, 0x476, 0x477, 0x3, 0x2, 0x2, 
    0x2, 0x477, 0x478, 0x3, 0x2, 0x2, 0x2, 0x478, 0x479, 0x7, 0x4b, 0x2, 
    0x2, 0x479, 0x47a, 0x7, 0x66, 0x2, 0x2, 0x47a, 0x8d, 0x3, 0x2, 0x2, 
    0x2, 0x47b, 0x483, 0x5, 0x90, 0x49, 0x2, 0x47c, 0x483, 0x5, 0x92, 0x4a, 
    0x2, 0x47d, 0x483, 0x5, 0x98, 0x4d, 0x2, 0x47e, 0x483, 0x5, 0x9a, 0x4e, 
    0x2, 0x47f, 0x483, 0x5, 0x9c, 0x4f, 0x2, 0x480, 0x483, 0x5, 0xa4, 0x53, 
    0x2, 0x481, 0x483, 0x5, 0xa6, 0x54, 0x2, 0x482, 0x47b, 0x3, 0x2, 0x2, 
    0x2, 0x482, 0x47c, 0x3, 0x2, 0x2, 0x2, 0x482, 0x47d, 0x3, 0x2, 0x2, 
    0x2, 0x482, 0x47e, 0x3, 0x2, 0x2, 0x2, 0x482, 0x47f, 0x3, 0x2, 0x2, 
    0x2, 0x482, 0x480, 0x3, 0x2, 0x2, 0x2, 0x482, 0x481, 0x3, 0x2, 0x2, 
    0x2, 0x483, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x484, 0x485, 0x7, 0x78, 0x2, 
    0x2, 0x485, 0x486, 0x7, 0x65, 0x2, 0x2, 0x486, 0x494, 0x5, 0x8e, 0x48, 
    0x2, 0x487, 0x488, 0x7, 0x1f, 0x2, 0x2, 0x488, 0x48b, 0x5, 0x32, 0x1a, 
    0x2, 0x489, 0x48a, 0x7, 0x77, 0x2, 0x2, 0x48a, 0x48c, 0x5, 0x32, 0x1a, 
    0x2, 0x48b, 0x489, 0x3, 0x2, 0x2, 0x2, 0x48b, 0x48c, 0x3, 0x2, 0x2, 
    0x2, 0x48c, 0x48d, 0x3, 0x2, 0x2, 0x2, 0x48d, 0x48e, 0x7, 0x65, 0x2, 
    0x2, 0x48e, 0x48f, 0x5, 0x8e, 0x48, 0x2, 0x48f, 0x494, 0x3, 0x2, 0x2, 
    0x2, 0x490, 0x491, 0x7, 0x23, 0x2, 0x2, 0x491, 0x492, 0x7, 0x65, 0x2, 
    0x2, 0x492, 0x494, 0x5, 0x8e, 0x48, 0x2, 0x493, 0x484, 0x3, 0x2, 0x2, 
    0x2, 0x493, 0x487, 0x3, 0x2, 0x2, 0x2, 0x493, 0x490, 0x3, 0x2, 0x2, 
    0x2, 0x494, 0x91, 0x3, 0x2, 0x2, 0x2, 0x495, 0x499, 0x7, 0x4e, 0x2, 
    0x2, 0x496, 0x498, 0x5, 0x94, 0x4b, 0x2, 0x497, 0x496, 0x3, 0x2, 0x2, 
    0x2, 0x498, 0x49b, 0x3, 0x2, 0x2, 0x2, 0x499, 0x497, 0x3, 0x2, 0x2, 
    0x2, 0x499, 0x49a, 0x3, 0x2, 0x2, 0x2, 0x49a, 0x49c, 0x3, 0x2, 0x2, 
    0x2, 0x49b, 0x499, 0x3, 0x2, 0x2, 0x2, 0x49c, 0x4ac, 0x7, 0x4f, 0x2, 
    0x2, 0x49d, 0x49f, 0x7, 0x4e, 0x2, 0x2, 0x49e, 0x4a0, 0x5, 0x96, 0x4c, 
    0x2, 0x49f, 0x49e, 0x3, 0x2, 0x2, 0x2, 0x4a0, 0x4a1, 0x3, 0x2, 0x2, 
    0x2, 0x4a1, 0x49f, 0x3, 0x2, 0x2, 0x2, 0x4a1, 0x4a2, 0x3, 0x2, 0x2, 
    0x2, 0x4a2, 0x4a6, 0x3, 0x2, 0x2, 0x2, 0x4a3, 0x4a5, 0x5, 0x94, 0x4b, 
    0x2, 0x4a4, 0x4a3, 0x3, 0x2, 0x2, 0x2, 0x4a5, 0x4a8, 0x3, 0x2, 0x2, 
    0x2, 0x4a6, 0x4a4, 0x3, 0x2, 0x2, 0x2, 0x4a6, 0x4a7, 0x3, 0x2, 0x2, 
    0x2, 0x4a7, 0x4a9, 0x3, 0x2, 0x2, 0x2, 0x4a8, 0x4a6, 0x3, 0x2, 0x2, 
    0x2, 0x4a9, 0x4aa, 0x7, 0x4f, 0x2, 0x2, 0x4aa, 0x4ac, 0x3, 0x2, 0x2, 
    0x2, 0x4ab, 0x495, 0x3, 0x2, 0x2, 0x2, 0x4ab, 0x49d, 0x3, 0x2, 0x2, 
    0x2, 0x4ac, 0x93, 0x3, 0x2, 0x2, 0x2, 0x4ad, 0x4b0, 0x5, 0x8e, 0x48, 
    0x2, 0x4ae, 0x4b0, 0x5, 0x34, 0x1b, 0x2, 0x4af, 0x4ad, 0x3, 0x2, 0x2, 
    0x2, 0x4af, 0x4ae, 0x3, 0x2, 0x2, 0x2, 0x4b0, 0x95, 0x3, 0x2, 0x2, 0x2, 
    0x4b1, 0x4b2, 0x7, 0x1c, 0x2, 0x2, 0x4b2, 0x4b3, 0x5, 0x78, 0x3d, 0x2, 
    0x4b3, 0x4b4, 0x7, 0x66, 0x2, 0x2, 0x4b4, 0x97, 0x3, 0x2, 0x2, 0x2, 
    0x4b5, 0x4b7, 0x5, 0x30, 0x19, 0x2, 0x4b6, 0x4b5, 0x3, 0x2, 0x2, 0x2, 
    0x4b6, 0x4b7, 0x3, 0x2, 0x2, 0x2, 0x4b7, 0x4b8, 0x3, 0x2, 0x2, 0x2, 
    0x4b8, 0x4b9, 0x7, 0x66, 0x2, 0x2, 0x4b9, 0x99, 0x3, 0x2, 0x2, 0x2, 
    0x4ba, 0x4bb, 0x7, 0x2c, 0x2, 0x2, 0x4bb, 0x4bc, 0x7, 0x4a, 0x2, 0x2, 
    0x4bc, 0x4bd, 0x5, 0x30, 0x19, 0x2, 0x4bd, 0x4be, 0x7, 0x4b, 0x2, 0x2, 
    0x4be, 0x4c1, 0x5, 0x8e, 0x48, 0x2, 0x4bf, 0x4c0, 0x7, 0x26, 0x2, 0x2, 
    0x4c0, 0x4c2, 0x5, 0x8e, 0x48, 0x2, 0x4c1, 0x4bf, 0x3, 0x2, 0x2, 0x2, 
    0x4c1, 0x4c2, 0x3, 0x2, 0x2, 0x2, 0x4c2, 0x4ca, 0x3, 0x2, 0x2, 0x2, 
    0x4c3, 0x4c4, 0x7, 0x38, 0x2, 0x2, 0x4c4, 0x4c5, 0x7, 0x4a, 0x2, 0x2, 
    0x4c5, 0x4c6, 0x5, 0x30, 0x19, 0x2, 0x4c6, 0x4c7, 0x7, 0x4b, 0x2, 0x2, 
    0x4c7, 0x4c8, 0x5, 0x8e, 0x48, 0x2, 0x4c8, 0x4ca, 0x3, 0x2, 0x2, 0x2, 
    0x4c9, 0x4ba, 0x3, 0x2, 0x2, 0x2, 0x4c9, 0x4c3, 0x3, 0x2, 0x2, 0x2, 
    0x4ca, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x4cb, 0x4cc, 0x7, 0x3f, 0x2, 0x2, 
    0x4cc, 0x4cd, 0x7, 0x4a, 0x2, 0x2, 0x4cd, 0x4ce, 0x5, 0x30, 0x19, 0x2, 
    0x4ce, 0x4cf, 0x7, 0x4b, 0x2, 0x2, 0x4cf, 0x4d0, 0x5, 0x8e, 0x48, 0x2, 
    0x4d0, 0x4e0, 0x3, 0x2, 0x2, 0x2, 0x4d1, 0x4d2, 0x7, 0x24, 0x2, 0x2, 
    0x4d2, 0x4d3, 0x5, 0x8e, 0x48, 0x2, 0x4d3, 0x4d4, 0x7, 0x3f, 0x2, 0x2, 
    0x4d4, 0x4d5, 0x7, 0x4a, 0x2, 0x2, 0x4d5, 0x4d6, 0x5, 0x30, 0x19, 0x2, 
    0x4d6, 0x4d7, 0x7, 0x4b, 0x2, 0x2, 0x4d7, 0x4d8, 0x7, 0x66, 0x2, 0x2, 
    0x4d8, 0x4e0, 0x3, 0x2, 0x2, 0x2, 0x4d9, 0x4da, 0x7, 0x2a, 0x2, 0x2, 
    0x4da, 0x4db, 0x7, 0x4a, 0x2, 0x2, 0x4db, 0x4dc, 0x5, 0x9e, 0x50, 0x2, 
    0x4dc, 0x4dd, 0x7, 0x4b, 0x2, 0x2, 0x4dd, 0x4de, 0x5, 0x8e, 0x48, 0x2, 
    0x4de, 0x4e0, 0x3, 0x2, 0x2, 0x2, 0x4df, 0x4cb, 0x3, 0x2, 0x2, 0x2, 
    0x4df, 0x4d1, 0x3, 0x2, 0x2, 0x2, 0x4df, 0x4d9, 0x3, 0x2, 0x2, 0x2, 
    0x4e0, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x4e1, 0x4e2, 0x5, 0xa0, 0x51, 0x2, 
    0x4e2, 0x4e4, 0x7, 0x66, 0x2, 0x2, 0x4e3, 0x4e5, 0x5, 0xa2, 0x52, 0x2, 
    0x4e4, 0x4e3, 0x3, 0x2, 0x2, 0x2, 0x4e4, 0x4e5, 0x3, 0x2, 0x2, 0x2, 
    0x4e5, 0x4e6, 0x3, 0x2, 0x2, 0x2, 0x4e6, 0x4e8, 0x7, 0x66, 0x2, 0x2, 
    0x4e7, 0x4e9, 0x5, 0xa2, 0x52, 0x2, 0x4e8, 0x4e7, 0x3, 0x2, 0x2, 0x2, 
    0x4e8, 0x4e9, 0x3, 0x2, 0x2, 0x2, 0x4e9, 0x4f6, 0x3, 0x2, 0x2, 0x2, 
    0x4ea, 0x4ec, 0x5, 0x30, 0x19, 0x2, 0x4eb, 0x4ea, 0x3, 0x2, 0x2, 0x2, 
    0x4eb, 0x4ec, 0x3, 0x2, 0x2, 0x2, 0x4ec, 0x4ed, 0x3, 0x2, 0x2, 0x2, 
    0x4ed, 0x4ef, 0x7, 0x66, 0x2, 0x2, 0x4ee, 0x4f0, 0x5, 0xa2, 0x52, 0x2, 
    0x4ef, 0x4ee, 0x3, 0x2, 0x2, 0x2, 0x4ef, 0x4f0, 0x3, 0x2, 0x2, 0x2, 
    0x4f0, 0x4f1, 0x3, 0x2, 0x2, 0x2, 0x4f1, 0x4f3, 0x7, 0x66, 0x2, 0x2, 
    0x4f2, 0x4f4, 0x5, 0xa2, 0x52, 0x2, 0x4f3, 0x4f2, 0x3, 0x2, 0x2, 0x2, 
    0x4f3, 0x4f4, 0x3, 0x2, 0x2, 0x2, 0x4f4, 0x4f6, 0x3, 0x2, 0x2, 0x2, 
    0x4f5, 0x4e1, 0x3, 0x2, 0x2, 0x2, 0x4f5, 0x4eb, 0x3, 0x2, 0x2, 0x2, 
    0x4f6, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x4f7, 0x4f8, 0x5, 0x36, 0x1c, 0x2, 
    0x4f8, 0x4f9, 0x5, 0x3c, 0x1f, 0x2, 0x4f9, 0x4fc, 0x3, 0x2, 0x2, 0x2, 
    0x4fa, 0x4fc, 0x5, 0x36, 0x1c, 0x2, 0x4fb, 0x4f7, 0x3, 0x2, 0x2, 0x2, 
    0x4fb, 0x4fa, 0x3, 0x2, 0x2, 0x2, 0x4fc, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x4fd, 
    0x4fe, 0x8, 0x52, 0x1, 0x2, 0x4fe, 0x4ff, 0x5, 0x2c, 0x17, 0x2, 0x4ff, 
    0x505, 0x3, 0x2, 0x2, 0x2, 0x500, 0x501, 0xc, 0x3, 0x2, 0x2, 0x501, 
    0x502, 0x7, 0x67, 0x2, 0x2, 0x502, 0x504, 0x5, 0x2c, 0x17, 0x2, 0x503, 
    0x500, 0x3, 0x2, 0x2, 0x2, 0x504, 0x507, 0x3, 0x2, 0x2, 0x2, 0x505, 
    0x503, 0x3, 0x2, 0x2, 0x2, 0x505, 0x506, 0x3, 0x2, 0x2, 0x2, 0x506, 
    0xa3, 0x3, 0x2, 0x2, 0x2, 0x507, 0x505, 0x3, 0x2, 0x2, 0x2, 0x508, 0x509, 
    0x7, 0x2b, 0x2, 0x2, 0x509, 0x50a, 0x7, 0x78, 0x2, 0x2, 0x50a, 0x519, 
    0x7, 0x66, 0x2, 0x2, 0x50b, 0x50c, 0x7, 0x22, 0x2, 0x2, 0x50c, 0x519, 
    0x7, 0x66, 0x2, 0x2, 0x50d, 0x50e, 0x7, 0x1e, 0x2, 0x2, 0x50e, 0x519, 
    0x7, 0x66, 0x2, 0x2, 0x50f, 0x511, 0x7, 0x32, 0x2, 0x2, 0x510, 0x512, 
    0x5, 0x30, 0x19, 0x2, 0x511, 0x510, 0x3, 0x2, 0x2, 0x2, 0x511, 0x512, 
    0x3, 0x2, 0x2, 0x2, 0x512, 0x513, 0x3, 0x2, 0x2, 0x2, 0x513, 0x519, 
    0x7, 0x66, 0x2, 0x2, 0x514, 0x515, 0x7, 0x2b, 0x2, 0x2, 0x515, 0x516, 
    0x5, 0xe, 0x8, 0x2, 0x516, 0x517, 0x7, 0x66, 0x2, 0x2, 0x517, 0x519, 
    0x3, 0x2, 0x2, 0x2, 0x518, 0x508, 0x3, 0x2, 0x2, 0x2, 0x518, 0x50b, 
    0x3, 0x2, 0x2, 0x2, 0x518, 0x50d, 0x3, 0x2, 0x2, 0x2, 0x518, 0x50f, 
    0x3, 0x2, 0x2, 0x2, 0x518, 0x514, 0x3, 0x2, 0x2, 0x2, 0x519, 0xa5, 0x3, 
    0x2, 0x2, 0x2, 0x51a, 0x51e, 0x9, 0xb, 0x2, 0x2, 0x51b, 0x51d, 0x5, 
    0xa8, 0x55, 0x2, 0x51c, 0x51b, 0x3, 0x2, 0x2, 0x2, 0x51d, 0x520, 0x3, 
    0x2, 0x2, 0x2, 0x51e, 0x51c, 0x3, 0x2, 0x2, 0x2, 0x51e, 0x51f, 0x3, 
    0x2, 0x2, 0x2, 0x51f, 0x521, 0x3, 0x2, 0x2, 0x2, 0x520, 0x51e, 0x3, 
    0x2, 0x2, 0x2, 0x521, 0x522, 0x7, 0x4a, 0x2, 0x2, 0x522, 0x523, 0x5, 
    0xaa, 0x56, 0x2, 0x523, 0x524, 0x7, 0x4b, 0x2, 0x2, 0x524, 0x525, 0x7, 
    0x66, 0x2, 0x2, 0x525, 0x52e, 0x3, 0x2, 0x2, 0x2, 0x526, 0x527, 0x9, 
    0xb, 0x2, 0x2, 0x527, 0x528, 0x7, 0x2b, 0x2, 0x2, 0x528, 0x529, 0x7, 
    0x4a, 0x2, 0x2, 0x529, 0x52a, 0x5, 0xaa, 0x56, 0x2, 0x52a, 0x52b, 0x7, 
    0x4b, 0x2, 0x2, 0x52b, 0x52c, 0x7, 0x66, 0x2, 0x2, 0x52c, 0x52e, 0x3, 
    0x2, 0x2, 0x2, 0x52d, 0x51a, 0x3, 0x2, 0x2, 0x2, 0x52d, 0x526, 0x3, 
    0x2, 0x2, 0x2, 0x52e, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x52f, 0x530, 0x9, 0xe, 
    0x2, 0x2, 0x530, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x531, 0x546, 0x5, 0xb8, 
    0x5d, 0x2, 0x532, 0x534, 0x7, 0x65, 0x2, 0x2, 0x533, 0x535, 0x5, 0xac, 
    0x57, 0x2, 0x534, 0x533, 0x3, 0x2, 0x2, 0x2, 0x534, 0x535, 0x3, 0x2, 
    0x2, 0x2, 0x535, 0x544, 0x3, 0x2, 0x2, 0x2, 0x536, 0x538, 0x7, 0x65, 
    0x2, 0x2, 0x537, 0x539, 0x5, 0xac, 0x57, 0x2, 0x538, 0x537, 0x3, 0x2, 
    0x2, 0x2, 0x538, 0x539, 0x3, 0x2, 0x2, 0x2, 0x539, 0x542, 0x3, 0x2, 
    0x2, 0x2, 0x53a, 0x53c, 0x7, 0x65, 0x2, 0x2, 0x53b, 0x53d, 0x5, 0xb0, 
    0x59, 0x2, 0x53c, 0x53b, 0x3, 0x2, 0x2, 0x2, 0x53c, 0x53d, 0x3, 0x2, 
    0x2, 0x2, 0x53d, 0x540, 0x3, 0x2, 0x2, 0x2, 0x53e, 0x53f, 0x7, 0x65, 
    0x2, 0x2, 0x53f, 0x541, 0x5, 0xb2, 0x5a, 0x2, 0x540, 0x53e, 0x3, 0x2, 
    0x2, 0x2, 0x540, 0x541, 0x3, 0x2, 0x2, 0x2, 0x541, 0x543, 0x3, 0x2, 
    0x2, 0x2, 0x542, 0x53a, 0x3, 0x2, 0x2, 0x2, 0x542, 0x543, 0x3, 0x2, 
    0x2, 0x2, 0x543, 0x545, 0x3, 0x2, 0x2, 0x2, 0x544, 0x536, 0x3, 0x2, 
    0x2, 0x2, 0x544, 0x545, 0x3, 0x2, 0x2, 0x2, 0x545, 0x547, 0x3, 0x2, 
    0x2, 0x2, 0x546, 0x532, 0x3, 0x2, 0x2, 0x2, 0x546, 0x547, 0x3, 0x2, 
    0x2, 0x2, 0x547, 0xab, 0x3, 0x2, 0x2, 0x2, 0x548, 0x54d, 0x5, 0xae, 
    0x58, 0x2, 0x549, 0x54a, 0x7, 0x67, 0x2, 0x2, 0x54a, 0x54c, 0x5, 0xae, 
    0x58, 0x2, 0x54b, 0x549, 0x3, 0x2, 0x2, 0x2, 0x54c, 0x54f, 0x3, 0x2, 
    0x2, 0x2, 0x54d, 0x54b, 0x3, 0x2, 0x2, 0x2, 0x54d, 0x54e, 0x3, 0x2, 
    0x2, 0x2, 0x54e, 0xad, 0x3, 0x2, 0x2, 0x2, 0x54f, 0x54d, 0x3, 0x2, 0x2, 
    0x2, 0x550, 0x551, 0x5, 0xb8, 0x5d, 0x2, 0x551, 0x552, 0x7, 0x4a, 0x2, 
    0x2, 0x552, 0x553, 0x5, 0x30, 0x19, 0x2, 0x553, 0x554, 0x7, 0x4b, 0x2, 
    0x2, 0x554, 0x55e, 0x3, 0x2, 0x2, 0x2, 0x555, 0x556, 0x7, 0x4c, 0x2, 
    0x2, 0x556, 0x557, 0x7, 0x78, 0x2, 0x2, 0x557, 0x558, 0x7, 0x4d, 0x2, 
    0x2, 0x558, 0x559, 0x5, 0xb8, 0x5d, 0x2, 0x559, 0x55a, 0x7, 0x4a, 0x2, 
    0x2, 0x55a, 0x55b, 0x5, 0x30, 0x19, 0x2, 0x55b, 0x55c, 0x7, 0x4b, 0x2, 
    0x2, 0x55c, 0x55e, 0x3, 0x2, 0x2, 0x2, 0x55d, 0x550, 0x3, 0x2, 0x2, 
    0x2, 0x55d, 0x555, 0x3, 0x2, 0x2, 0x2, 0x55e, 0xaf, 0x3, 0x2, 0x2, 0x2, 
    0x55f, 0x564, 0x5, 0xb8, 0x5d, 0x2, 0x560, 0x561, 0x7, 0x67, 0x2, 0x2, 
    0x561, 0x563, 0x5, 0xb8, 0x5d, 0x2, 0x562, 0x560, 0x3, 0x2, 0x2, 0x2, 
    0x563, 0x566, 0x3, 0x2, 0x2, 0x2, 0x564, 0x562, 0x3, 0x2, 0x2, 0x2, 
    0x564, 0x565, 0x3, 0x2, 0x2, 0x2, 0x565, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x566, 
    0x564, 0x3, 0x2, 0x2, 0x2, 0x567, 0x56c, 0x7, 0x78, 0x2, 0x2, 0x568, 
    0x569, 0x7, 0x67, 0x2, 0x2, 0x569, 0x56b, 0x7, 0x78, 0x2, 0x2, 0x56a, 
    0x568, 0x3, 0x2, 0x2, 0x2, 0x56b, 0x56e, 0x3, 0x2, 0x2, 0x2, 0x56c, 
    0x56a, 0x3, 0x2, 0x2, 0x2, 0x56c, 0x56d, 0x3, 0x2, 0x2, 0x2, 0x56d, 
    0xb3, 0x3, 0x2, 0x2, 0x2, 0x56e, 0x56c, 0x3, 0x2, 0x2, 0x2, 0x56f, 0x570, 
    0x5, 0xb6, 0x5c, 0x2, 0x570, 0xb5, 0x3, 0x2, 0x2, 0x2, 0x571, 0x572, 
    0x9, 0xb, 0x2, 0x2, 0x572, 0x573, 0x7, 0x4a, 0x2, 0x2, 0x573, 0x574, 
    0x5, 0xb8, 0x5d, 0x2, 0x574, 0x575, 0x7, 0x4b, 0x2, 0x2, 0x575, 0xb7, 
    0x3, 0x2, 0x2, 0x2, 0x576, 0x578, 0x7, 0x7b, 0x2, 0x2, 0x577, 0x576, 
    0x3, 0x2, 0x2, 0x2, 0x578, 0x579, 0x3, 0x2, 0x2, 0x2, 0x579, 0x577, 
    0x3, 0x2, 0x2, 0x2, 0x579, 0x57a, 0x3, 0x2, 0x2, 0x2, 0x57a, 0xb9, 0x3, 
    0x2, 0x2, 0x2, 0x57b, 0x57d, 0x5, 0xbc, 0x5f, 0x2, 0x57c, 0x57b, 0x3, 
    0x2, 0x2, 0x2, 0x57d, 0x580, 0x3, 0x2, 0x2, 0x2, 0x57e, 0x57c, 0x3, 
    0x2, 0x2, 0x2, 0x57e, 0x57f, 0x3, 0x2, 0x2, 0x2, 0x57f, 0x581, 0x3, 
    0x2, 0x2, 0x2, 0x580, 0x57e, 0x3, 0x2, 0x2, 0x2, 0x581, 0x582, 0x7, 
    0x2, 0x2, 0x3, 0x582, 0xbb, 0x3, 0x2, 0x2, 0x2, 0x583, 0x588, 0x5, 0xbe, 
    0x60, 0x2, 0x584, 0x588, 0x5, 0x34, 0x1b, 0x2, 0x585, 0x588, 0x7, 0x66, 
    0x2, 0x2, 0x586, 0x588, 0x5, 0xb4, 0x5b, 0x2, 0x587, 0x583, 0x3, 0x2, 
    0x2, 0x2, 0x587, 0x584, 0x3, 0x2, 0x2, 0x2, 0x587, 0x585, 0x3, 0x2, 
    0x2, 0x2, 0x587, 0x586, 0x3, 0x2, 0x2, 0x2, 0x588, 0xbd, 0x3, 0x2, 0x2, 
    0x2, 0x589, 0x58b, 0x5, 0x36, 0x1c, 0x2, 0x58a, 0x589, 0x3, 0x2, 0x2, 
    0x2, 0x58a, 0x58b, 0x3, 0x2, 0x2, 0x2, 0x58b, 0x58c, 0x3, 0x2, 0x2, 
    0x2, 0x58c, 0x58e, 0x5, 0x60, 0x31, 0x2, 0x58d, 0x58f, 0x5, 0xc0, 0x61, 
    0x2, 0x58e, 0x58d, 0x3, 0x2, 0x2, 0x2, 0x58e, 0x58f, 0x3, 0x2, 0x2, 
    0x2, 0x58f, 0x590, 0x3, 0x2, 0x2, 0x2, 0x590, 0x591, 0x5, 0x92, 0x4a, 
    0x2, 0x591, 0xbf, 0x3, 0x2, 0x2, 0x2, 0x592, 0x593, 0x8, 0x61, 0x1, 
    0x2, 0x593, 0x594, 0x5, 0x34, 0x1b, 0x2, 0x594, 0x599, 0x3, 0x2, 0x2, 
    0x2, 0x595, 0x596, 0xc, 0x3, 0x2, 0x2, 0x596, 0x598, 0x5, 0x34, 0x1b, 
    0x2, 0x597, 0x595, 0x3, 0x2, 0x2, 0x2, 0x598, 0x59b, 0x3, 0x2, 0x2, 
    0x2, 0x599, 0x597, 0x3, 0x2, 0x2, 0x2, 0x599, 0x59a, 0x3, 0x2, 0x2, 
    0x2, 0x59a, 0xc1, 0x3, 0x2, 0x2, 0x2, 0x59b, 0x599, 0x3, 0x2, 0x2, 0x2, 
    0xa8, 0xc7, 0xcf, 0xe3, 0xf1, 0xfb, 0x104, 0x116, 0x123, 0x12d, 0x13a, 
    0x13c, 0x144, 0x15e, 0x176, 0x184, 0x186, 0x192, 0x194, 0x1a0, 0x1a2, 
    0x1b4, 0x1b6, 0x1c2, 0x1c4, 0x1cf, 0x1da, 0x1e5, 0x1f0, 0x1fb, 0x201, 
    0x205, 0x20d, 0x219, 0x228, 0x22d, 0x232, 0x23a, 0x241, 0x249, 0x24c, 
    0x255, 0x26c, 0x272, 0x277, 0x27a, 0x280, 0x285, 0x289, 0x28d, 0x293, 
    0x299, 0x29d, 0x29f, 0x2a6, 0x2ab, 0x2af, 0x2b3, 0x2b6, 0x2bc, 0x2c0, 
    0x2c3, 0x2ca, 0x2ce, 0x2d1, 0x2db, 0x2e3, 0x2f3, 0x2ff, 0x302, 0x305, 
    0x30b, 0x31a, 0x320, 0x325, 0x328, 0x32f, 0x33e, 0x34d, 0x351, 0x353, 
    0x35b, 0x35f, 0x36d, 0x371, 0x376, 0x379, 0x37c, 0x383, 0x385, 0x38a, 
    0x38e, 0x393, 0x397, 0x39a, 0x3a3, 0x3ab, 0x3b2, 0x3ba, 0x3bc, 0x3c6, 
    0x3cb, 0x3cf, 0x3d5, 0x3d8, 0x3e1, 0x3e6, 0x3e9, 0x3ef, 0x3ff, 0x405, 
    0x408, 0x40d, 0x410, 0x417, 0x42a, 0x430, 0x433, 0x435, 0x447, 0x44b, 
    0x452, 0x457, 0x464, 0x46d, 0x476, 0x482, 0x48b, 0x493, 0x499, 0x4a1, 
    0x4a6, 0x4ab, 0x4af, 0x4b6, 0x4c1, 0x4c9, 0x4df, 0x4e4, 0x4e8, 0x4eb, 
    0x4ef, 0x4f3, 0x4f5, 0x4fb, 0x505, 0x511, 0x518, 0x51e, 0x52d, 0x534, 
    0x538, 0x53c, 0x540, 0x542, 0x544, 0x546, 0x54d, 0x55d, 0x564, 0x56c, 
    0x579, 0x57e, 0x587, 0x58a, 0x58e, 0x599, 
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
