
// Generated from C.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"




class  CLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    Auto = 27, Break = 28, Case = 29, Char = 30, Const = 31, Continue = 32, 
    Default = 33, Do = 34, Double = 35, Else = 36, Enum = 37, Extern = 38, 
    Float = 39, For = 40, Goto = 41, If = 42, Inline = 43, Int = 44, Long = 45, 
    Register = 46, Restrict = 47, Return = 48, Short = 49, Signed = 50, 
    Sizeof = 51, Static = 52, Struct = 53, Switch = 54, Typedef = 55, Typeof = 56, 
    Union = 57, Unsigned = 58, Void = 59, Volatile = 60, While = 61, Alignas = 62, 
    Alignof = 63, Atomic = 64, Bool = 65, Complex = 66, Generic = 67, Imaginary = 68, 
    Noreturn = 69, StaticAssert = 70, ThreadLocal = 71, LeftParen = 72, 
    RightParen = 73, LeftBracket = 74, RightBracket = 75, LeftBrace = 76, 
    RightBrace = 77, Less = 78, LessEqual = 79, Greater = 80, GreaterEqual = 81, 
    LeftShift = 82, RightShift = 83, Plus = 84, PlusPlus = 85, Minus = 86, 
    MinusMinus = 87, Star = 88, Div = 89, Mod = 90, And = 91, Or = 92, AndAnd = 93, 
    OrOr = 94, Caret = 95, Not = 96, Tilde = 97, Question = 98, Colon = 99, 
    Semi = 100, Comma = 101, Assign = 102, StarAssign = 103, DivAssign = 104, 
    ModAssign = 105, PlusAssign = 106, MinusAssign = 107, LeftShiftAssign = 108, 
    RightShiftAssign = 109, AndAssign = 110, XorAssign = 111, OrAssign = 112, 
    Equal = 113, NotEqual = 114, Arrow = 115, Dot = 116, Ellipsis = 117, 
    Identifier = 118, Constant = 119, DigitSequence = 120, StringLiteral = 121, 
    ComplexDefine = 122, IncludeDirective = 123, LineAfterPreprocessing = 124, 
    LineDirective = 125, PragmaDirective = 126, Whitespace = 127, Newline = 128, 
    BlockComment = 129, LineComment = 130
  };

  explicit CLexer(antlr4::CharStream *input);
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

