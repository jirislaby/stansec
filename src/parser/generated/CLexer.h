
// Generated from C.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  CLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, Auto = 18, Break = 19, Case = 20, 
    Char = 21, Const = 22, Continue = 23, Default = 24, Do = 25, Double = 26, 
    Else = 27, Enum = 28, Extern = 29, Float = 30, For = 31, Goto = 32, 
    If = 33, Inline = 34, Int = 35, Long = 36, Register = 37, Restrict = 38, 
    Return = 39, Short = 40, Signed = 41, Sizeof = 42, Static = 43, Struct = 44, 
    Switch = 45, Typedef = 46, Typeof = 47, Union = 48, Unsigned = 49, Void = 50, 
    Volatile = 51, While = 52, Alignas = 53, Alignof = 54, Atomic = 55, 
    Bool = 56, Complex = 57, Generic = 58, Imaginary = 59, Noreturn = 60, 
    StaticAssert = 61, ThreadLocal = 62, LeftParen = 63, RightParen = 64, 
    LeftBracket = 65, RightBracket = 66, LeftBrace = 67, RightBrace = 68, 
    Less = 69, LessEqual = 70, Greater = 71, GreaterEqual = 72, LeftShift = 73, 
    RightShift = 74, Plus = 75, PlusPlus = 76, Minus = 77, MinusMinus = 78, 
    Star = 79, Div = 80, Mod = 81, And = 82, Or = 83, AndAnd = 84, OrOr = 85, 
    Caret = 86, Not = 87, Tilde = 88, Question = 89, Colon = 90, Semi = 91, 
    Comma = 92, Assign = 93, StarAssign = 94, DivAssign = 95, ModAssign = 96, 
    PlusAssign = 97, MinusAssign = 98, LeftShiftAssign = 99, RightShiftAssign = 100, 
    AndAssign = 101, XorAssign = 102, OrAssign = 103, Equal = 104, NotEqual = 105, 
    Arrow = 106, Dot = 107, Ellipsis = 108, Identifier = 109, Constant = 110, 
    DigitSequence = 111, StringLiteral = 112, ComplexDefine = 113, IncludeDirective = 114, 
    LineAfterPreprocessing = 115, LineDirective = 116, PragmaDirective = 117, 
    Whitespace = 118, Newline = 119, BlockComment = 120, LineComment = 121
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

