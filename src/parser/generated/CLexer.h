
// Generated from C.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  CLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, Auto = 19, Break = 20, 
    Case = 21, Char = 22, Const = 23, Continue = 24, Default = 25, Do = 26, 
    Double = 27, Else = 28, Enum = 29, Extern = 30, Float = 31, For = 32, 
    Goto = 33, If = 34, Inline = 35, Int = 36, Long = 37, Register = 38, 
    Restrict = 39, Return = 40, Short = 41, Signed = 42, Sizeof = 43, Static = 44, 
    Struct = 45, Switch = 46, Typedef = 47, Typeof = 48, Union = 49, Unsigned = 50, 
    Void = 51, Volatile = 52, While = 53, Alignas = 54, Alignof = 55, Atomic = 56, 
    Bool = 57, Complex = 58, Generic = 59, Imaginary = 60, Noreturn = 61, 
    StaticAssert = 62, ThreadLocal = 63, LeftParen = 64, RightParen = 65, 
    LeftBracket = 66, RightBracket = 67, LeftBrace = 68, RightBrace = 69, 
    Less = 70, LessEqual = 71, Greater = 72, GreaterEqual = 73, LeftShift = 74, 
    RightShift = 75, Plus = 76, PlusPlus = 77, Minus = 78, MinusMinus = 79, 
    Star = 80, Div = 81, Mod = 82, And = 83, Or = 84, AndAnd = 85, OrOr = 86, 
    Caret = 87, Not = 88, Tilde = 89, Question = 90, Colon = 91, Semi = 92, 
    Comma = 93, Assign = 94, StarAssign = 95, DivAssign = 96, ModAssign = 97, 
    PlusAssign = 98, MinusAssign = 99, LeftShiftAssign = 100, RightShiftAssign = 101, 
    AndAssign = 102, XorAssign = 103, OrAssign = 104, Equal = 105, NotEqual = 106, 
    Arrow = 107, Dot = 108, Ellipsis = 109, Identifier = 110, Constant = 111, 
    DigitSequence = 112, StringLiteral = 113, ComplexDefine = 114, IncludeDirective = 115, 
    LineAfterPreprocessing = 116, LineDirective = 117, PragmaDirective = 118, 
    Whitespace = 119, Newline = 120, BlockComment = 121, LineComment = 122
  };

  CLexer(antlr4::CharStream *input);
  ~CLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

