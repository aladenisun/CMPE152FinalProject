
// Generated from Purrscal.g4 by ANTLR 4.7.2


#include "PurrscalVisitor.h"

#include "PurrscalParser.h"


using namespace antlrcpp;
using namespace antlr4;

PurrscalParser::PurrscalParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

PurrscalParser::~PurrscalParser() {
  delete _interpreter;
}

std::string PurrscalParser::getGrammarFileName() const {
  return "Purrscal.g4";
}

const std::vector<std::string>& PurrscalParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& PurrscalParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- PurrgramContext ------------------------------------------------------------------

PurrscalParser::PurrgramContext::PurrgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PurrscalParser::PurrgramSnootContext* PurrscalParser::PurrgramContext::purrgramSnoot() {
  return getRuleContext<PurrscalParser::PurrgramSnootContext>(0);
}

PurrscalParser::CatContext* PurrscalParser::PurrgramContext::cat() {
  return getRuleContext<PurrscalParser::CatContext>(0);
}

tree::TerminalNode* PurrscalParser::PurrgramContext::UWU() {
  return getToken(PurrscalParser::UWU, 0);
}


size_t PurrscalParser::PurrgramContext::getRuleIndex() const {
  return PurrscalParser::RulePurrgram;
}


antlrcpp::Any PurrscalParser::PurrgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitPurrgram(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::PurrgramContext* PurrscalParser::purrgram() {
  PurrgramContext *_localctx = _tracker.createInstance<PurrgramContext>(_ctx, getState());
  enterRule(_localctx, 0, PurrscalParser::RulePurrgram);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(166);
    purrgramSnoot();
    setState(167);
    cat();
    setState(168);
    match(PurrscalParser::UWU);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PurrgramSnootContext ------------------------------------------------------------------

PurrscalParser::PurrgramSnootContext::PurrgramSnootContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PurrscalParser::PurrgramSnootContext::PURRGRAM() {
  return getToken(PurrscalParser::PURRGRAM, 0);
}

PurrscalParser::PurrgramKittyContext* PurrscalParser::PurrgramSnootContext::purrgramKitty() {
  return getRuleContext<PurrscalParser::PurrgramKittyContext>(0);
}

tree::TerminalNode* PurrscalParser::PurrgramSnootContext::OWO() {
  return getToken(PurrscalParser::OWO, 0);
}

PurrscalParser::PurrgramPurrametersContext* PurrscalParser::PurrgramSnootContext::purrgramPurrameters() {
  return getRuleContext<PurrscalParser::PurrgramPurrametersContext>(0);
}


size_t PurrscalParser::PurrgramSnootContext::getRuleIndex() const {
  return PurrscalParser::RulePurrgramSnoot;
}


antlrcpp::Any PurrscalParser::PurrgramSnootContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitPurrgramSnoot(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::PurrgramSnootContext* PurrscalParser::purrgramSnoot() {
  PurrgramSnootContext *_localctx = _tracker.createInstance<PurrgramSnootContext>(_ctx, getState());
  enterRule(_localctx, 2, PurrscalParser::RulePurrgramSnoot);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(170);
    match(PurrscalParser::PURRGRAM);
    setState(171);
    purrgramKitty();
    setState(173);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PurrscalParser::T__0) {
      setState(172);
      purrgramPurrameters();
    }
    setState(175);
    match(PurrscalParser::OWO);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PurrgramPurrametersContext ------------------------------------------------------------------

PurrscalParser::PurrgramPurrametersContext::PurrgramPurrametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> PurrscalParser::PurrgramPurrametersContext::KITTY() {
  return getTokens(PurrscalParser::KITTY);
}

tree::TerminalNode* PurrscalParser::PurrgramPurrametersContext::KITTY(size_t i) {
  return getToken(PurrscalParser::KITTY, i);
}


size_t PurrscalParser::PurrgramPurrametersContext::getRuleIndex() const {
  return PurrscalParser::RulePurrgramPurrameters;
}


antlrcpp::Any PurrscalParser::PurrgramPurrametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitPurrgramPurrameters(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::PurrgramPurrametersContext* PurrscalParser::purrgramPurrameters() {
  PurrgramPurrametersContext *_localctx = _tracker.createInstance<PurrgramPurrametersContext>(_ctx, getState());
  enterRule(_localctx, 4, PurrscalParser::RulePurrgramPurrameters);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(177);
    match(PurrscalParser::T__0);
    setState(178);
    match(PurrscalParser::KITTY);
    setState(183);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PurrscalParser::T__1) {
      setState(179);
      match(PurrscalParser::T__1);
      setState(180);
      match(PurrscalParser::KITTY);
      setState(185);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(186);
    match(PurrscalParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PurrgramKittyContext ------------------------------------------------------------------

PurrscalParser::PurrgramKittyContext::PurrgramKittyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PurrscalParser::PurrgramKittyContext::KITTY() {
  return getToken(PurrscalParser::KITTY, 0);
}


size_t PurrscalParser::PurrgramKittyContext::getRuleIndex() const {
  return PurrscalParser::RulePurrgramKitty;
}


antlrcpp::Any PurrscalParser::PurrgramKittyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitPurrgramKitty(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::PurrgramKittyContext* PurrscalParser::purrgramKitty() {
  PurrgramKittyContext *_localctx = _tracker.createInstance<PurrgramKittyContext>(_ctx, getState());
  enterRule(_localctx, 6, PurrscalParser::RulePurrgramKitty);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(188);
    match(PurrscalParser::KITTY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CatContext ------------------------------------------------------------------

PurrscalParser::CatContext::CatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PurrscalParser::CatQualitiesContext* PurrscalParser::CatContext::catQualities() {
  return getRuleContext<PurrscalParser::CatQualitiesContext>(0);
}

PurrscalParser::TheBigMewContext* PurrscalParser::CatContext::theBigMew() {
  return getRuleContext<PurrscalParser::TheBigMewContext>(0);
}


size_t PurrscalParser::CatContext::getRuleIndex() const {
  return PurrscalParser::RuleCat;
}


antlrcpp::Any PurrscalParser::CatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitCat(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::CatContext* PurrscalParser::cat() {
  CatContext *_localctx = _tracker.createInstance<CatContext>(_ctx, getState());
  enterRule(_localctx, 8, PurrscalParser::RuleCat);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(190);
    catQualities();
    setState(191);
    theBigMew();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CatQualitiesContext ------------------------------------------------------------------

PurrscalParser::CatQualitiesContext::CatQualitiesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PurrscalParser::DomesticQualityContext* PurrscalParser::CatQualitiesContext::domesticQuality() {
  return getRuleContext<PurrscalParser::DomesticQualityContext>(0);
}

std::vector<tree::TerminalNode *> PurrscalParser::CatQualitiesContext::OWO() {
  return getTokens(PurrscalParser::OWO);
}

tree::TerminalNode* PurrscalParser::CatQualitiesContext::OWO(size_t i) {
  return getToken(PurrscalParser::OWO, i);
}

PurrscalParser::BreedQualityContext* PurrscalParser::CatQualitiesContext::breedQuality() {
  return getRuleContext<PurrscalParser::BreedQualityContext>(0);
}

PurrscalParser::KittenQualityContext* PurrscalParser::CatQualitiesContext::kittenQuality() {
  return getRuleContext<PurrscalParser::KittenQualityContext>(0);
}

PurrscalParser::CallQualityContext* PurrscalParser::CatQualitiesContext::callQuality() {
  return getRuleContext<PurrscalParser::CallQualityContext>(0);
}


size_t PurrscalParser::CatQualitiesContext::getRuleIndex() const {
  return PurrscalParser::RuleCatQualities;
}


antlrcpp::Any PurrscalParser::CatQualitiesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitCatQualities(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::CatQualitiesContext* PurrscalParser::catQualities() {
  CatQualitiesContext *_localctx = _tracker.createInstance<CatQualitiesContext>(_ctx, getState());
  enterRule(_localctx, 10, PurrscalParser::RuleCatQualities);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(196);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PurrscalParser::DOMESTIC) {
      setState(193);
      domesticQuality();
      setState(194);
      match(PurrscalParser::OWO);
    }
    setState(201);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PurrscalParser::BREED) {
      setState(198);
      breedQuality();
      setState(199);
      match(PurrscalParser::OWO);
    }
    setState(206);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PurrscalParser::KITTEN) {
      setState(203);
      kittenQuality();
      setState(204);
      match(PurrscalParser::OWO);
    }
    setState(211);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PurrscalParser::YOWL

    || _la == PurrscalParser::BLEP) {
      setState(208);
      callQuality();
      setState(209);
      match(PurrscalParser::OWO);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DomesticQualityContext ------------------------------------------------------------------

PurrscalParser::DomesticQualityContext::DomesticQualityContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PurrscalParser::DomesticQualityContext::DOMESTIC() {
  return getToken(PurrscalParser::DOMESTIC, 0);
}

PurrscalParser::DomesticBodiesContext* PurrscalParser::DomesticQualityContext::domesticBodies() {
  return getRuleContext<PurrscalParser::DomesticBodiesContext>(0);
}


size_t PurrscalParser::DomesticQualityContext::getRuleIndex() const {
  return PurrscalParser::RuleDomesticQuality;
}


antlrcpp::Any PurrscalParser::DomesticQualityContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitDomesticQuality(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::DomesticQualityContext* PurrscalParser::domesticQuality() {
  DomesticQualityContext *_localctx = _tracker.createInstance<DomesticQualityContext>(_ctx, getState());
  enterRule(_localctx, 12, PurrscalParser::RuleDomesticQuality);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(213);
    match(PurrscalParser::DOMESTIC);
    setState(214);
    domesticBodies();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DomesticBodiesContext ------------------------------------------------------------------

PurrscalParser::DomesticBodiesContext::DomesticBodiesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PurrscalParser::DomesticBodyContext *> PurrscalParser::DomesticBodiesContext::domesticBody() {
  return getRuleContexts<PurrscalParser::DomesticBodyContext>();
}

PurrscalParser::DomesticBodyContext* PurrscalParser::DomesticBodiesContext::domesticBody(size_t i) {
  return getRuleContext<PurrscalParser::DomesticBodyContext>(i);
}

std::vector<tree::TerminalNode *> PurrscalParser::DomesticBodiesContext::OWO() {
  return getTokens(PurrscalParser::OWO);
}

tree::TerminalNode* PurrscalParser::DomesticBodiesContext::OWO(size_t i) {
  return getToken(PurrscalParser::OWO, i);
}


size_t PurrscalParser::DomesticBodiesContext::getRuleIndex() const {
  return PurrscalParser::RuleDomesticBodies;
}


antlrcpp::Any PurrscalParser::DomesticBodiesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitDomesticBodies(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::DomesticBodiesContext* PurrscalParser::domesticBodies() {
  DomesticBodiesContext *_localctx = _tracker.createInstance<DomesticBodiesContext>(_ctx, getState());
  enterRule(_localctx, 14, PurrscalParser::RuleDomesticBodies);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(216);
    domesticBody();
    setState(221);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(217);
        match(PurrscalParser::OWO);
        setState(218);
        domesticBody(); 
      }
      setState(223);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DomesticBodyContext ------------------------------------------------------------------

PurrscalParser::DomesticBodyContext::DomesticBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PurrscalParser::DomesticKittyContext* PurrscalParser::DomesticBodyContext::domesticKitty() {
  return getRuleContext<PurrscalParser::DomesticKittyContext>(0);
}

PurrscalParser::DomesticContext* PurrscalParser::DomesticBodyContext::domestic() {
  return getRuleContext<PurrscalParser::DomesticContext>(0);
}


size_t PurrscalParser::DomesticBodyContext::getRuleIndex() const {
  return PurrscalParser::RuleDomesticBody;
}


antlrcpp::Any PurrscalParser::DomesticBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitDomesticBody(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::DomesticBodyContext* PurrscalParser::domesticBody() {
  DomesticBodyContext *_localctx = _tracker.createInstance<DomesticBodyContext>(_ctx, getState());
  enterRule(_localctx, 16, PurrscalParser::RuleDomesticBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(224);
    domesticKitty();
    setState(225);
    match(PurrscalParser::T__3);
    setState(226);
    domestic();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DomesticKittyContext ------------------------------------------------------------------

PurrscalParser::DomesticKittyContext::DomesticKittyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PurrscalParser::DomesticKittyContext::KITTY() {
  return getToken(PurrscalParser::KITTY, 0);
}


size_t PurrscalParser::DomesticKittyContext::getRuleIndex() const {
  return PurrscalParser::RuleDomesticKitty;
}


antlrcpp::Any PurrscalParser::DomesticKittyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitDomesticKitty(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::DomesticKittyContext* PurrscalParser::domesticKitty() {
  DomesticKittyContext *_localctx = _tracker.createInstance<DomesticKittyContext>(_ctx, getState());
  enterRule(_localctx, 18, PurrscalParser::RuleDomesticKitty);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(228);
    match(PurrscalParser::KITTY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DomesticContext ------------------------------------------------------------------

PurrscalParser::DomesticContext::DomesticContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PurrscalParser::DomesticContext::KITTY() {
  return getToken(PurrscalParser::KITTY, 0);
}

PurrscalParser::HairlessFelineContext* PurrscalParser::DomesticContext::hairlessFeline() {
  return getRuleContext<PurrscalParser::HairlessFelineContext>(0);
}

PurrscalParser::FurContext* PurrscalParser::DomesticContext::fur() {
  return getRuleContext<PurrscalParser::FurContext>(0);
}

PurrscalParser::ThreadBallContext* PurrscalParser::DomesticContext::threadBall() {
  return getRuleContext<PurrscalParser::ThreadBallContext>(0);
}

PurrscalParser::YarnBallContext* PurrscalParser::DomesticContext::yarnBall() {
  return getRuleContext<PurrscalParser::YarnBallContext>(0);
}


size_t PurrscalParser::DomesticContext::getRuleIndex() const {
  return PurrscalParser::RuleDomestic;
}


antlrcpp::Any PurrscalParser::DomesticContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitDomestic(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::DomesticContext* PurrscalParser::domestic() {
  DomesticContext *_localctx = _tracker.createInstance<DomesticContext>(_ctx, getState());
  enterRule(_localctx, 20, PurrscalParser::RuleDomestic);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(239);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PurrscalParser::T__9:
      case PurrscalParser::T__10:
      case PurrscalParser::KITTY:
      case PurrscalParser::SPHYNX:
      case PurrscalParser::HAIRLESS_FELINE: {
        enterOuterAlt(_localctx, 1);
        setState(231);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PurrscalParser::T__9

        || _la == PurrscalParser::T__10) {
          setState(230);
          fur();
        }
        setState(235);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case PurrscalParser::KITTY: {
            setState(233);
            match(PurrscalParser::KITTY);
            break;
          }

          case PurrscalParser::SPHYNX:
          case PurrscalParser::HAIRLESS_FELINE: {
            setState(234);
            hairlessFeline();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

      case PurrscalParser::THREAD: {
        enterOuterAlt(_localctx, 2);
        setState(237);
        threadBall();
        break;
      }

      case PurrscalParser::YARN: {
        enterOuterAlt(_localctx, 3);
        setState(238);
        yarnBall();
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

//----------------- BreedQualityContext ------------------------------------------------------------------

PurrscalParser::BreedQualityContext::BreedQualityContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PurrscalParser::BreedQualityContext::BREED() {
  return getToken(PurrscalParser::BREED, 0);
}

PurrscalParser::BreedBodiesContext* PurrscalParser::BreedQualityContext::breedBodies() {
  return getRuleContext<PurrscalParser::BreedBodiesContext>(0);
}


size_t PurrscalParser::BreedQualityContext::getRuleIndex() const {
  return PurrscalParser::RuleBreedQuality;
}


antlrcpp::Any PurrscalParser::BreedQualityContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitBreedQuality(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::BreedQualityContext* PurrscalParser::breedQuality() {
  BreedQualityContext *_localctx = _tracker.createInstance<BreedQualityContext>(_ctx, getState());
  enterRule(_localctx, 22, PurrscalParser::RuleBreedQuality);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(241);
    match(PurrscalParser::BREED);
    setState(242);
    breedBodies();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreedBodiesContext ------------------------------------------------------------------

PurrscalParser::BreedBodiesContext::BreedBodiesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PurrscalParser::BreedBodyContext *> PurrscalParser::BreedBodiesContext::breedBody() {
  return getRuleContexts<PurrscalParser::BreedBodyContext>();
}

PurrscalParser::BreedBodyContext* PurrscalParser::BreedBodiesContext::breedBody(size_t i) {
  return getRuleContext<PurrscalParser::BreedBodyContext>(i);
}

std::vector<tree::TerminalNode *> PurrscalParser::BreedBodiesContext::OWO() {
  return getTokens(PurrscalParser::OWO);
}

tree::TerminalNode* PurrscalParser::BreedBodiesContext::OWO(size_t i) {
  return getToken(PurrscalParser::OWO, i);
}


size_t PurrscalParser::BreedBodiesContext::getRuleIndex() const {
  return PurrscalParser::RuleBreedBodies;
}


antlrcpp::Any PurrscalParser::BreedBodiesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitBreedBodies(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::BreedBodiesContext* PurrscalParser::breedBodies() {
  BreedBodiesContext *_localctx = _tracker.createInstance<BreedBodiesContext>(_ctx, getState());
  enterRule(_localctx, 24, PurrscalParser::RuleBreedBodies);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(244);
    breedBody();
    setState(249);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(245);
        match(PurrscalParser::OWO);
        setState(246);
        breedBody(); 
      }
      setState(251);
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

//----------------- BreedBodyContext ------------------------------------------------------------------

PurrscalParser::BreedBodyContext::BreedBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PurrscalParser::KittyBreedContext* PurrscalParser::BreedBodyContext::kittyBreed() {
  return getRuleContext<PurrscalParser::KittyBreedContext>(0);
}

PurrscalParser::BreedContext* PurrscalParser::BreedBodyContext::breed() {
  return getRuleContext<PurrscalParser::BreedContext>(0);
}


size_t PurrscalParser::BreedBodyContext::getRuleIndex() const {
  return PurrscalParser::RuleBreedBody;
}


antlrcpp::Any PurrscalParser::BreedBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitBreedBody(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::BreedBodyContext* PurrscalParser::breedBody() {
  BreedBodyContext *_localctx = _tracker.createInstance<BreedBodyContext>(_ctx, getState());
  enterRule(_localctx, 26, PurrscalParser::RuleBreedBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(252);
    kittyBreed();
    setState(253);
    match(PurrscalParser::T__3);
    setState(254);
    breed();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KittyBreedContext ------------------------------------------------------------------

PurrscalParser::KittyBreedContext::KittyBreedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PurrscalParser::KittyBreedContext::KITTY() {
  return getToken(PurrscalParser::KITTY, 0);
}


size_t PurrscalParser::KittyBreedContext::getRuleIndex() const {
  return PurrscalParser::RuleKittyBreed;
}


antlrcpp::Any PurrscalParser::KittyBreedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitKittyBreed(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::KittyBreedContext* PurrscalParser::kittyBreed() {
  KittyBreedContext *_localctx = _tracker.createInstance<KittyBreedContext>(_ctx, getState());
  enterRule(_localctx, 28, PurrscalParser::RuleKittyBreed);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(256);
    match(PurrscalParser::KITTY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreedContext ------------------------------------------------------------------

PurrscalParser::BreedContext::BreedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PurrscalParser::BreedContext::getRuleIndex() const {
  return PurrscalParser::RuleBreed;
}

void PurrscalParser::BreedContext::copyFrom(BreedContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->type = ctx->type;
}

//----------------- ChonkTypespecContext ------------------------------------------------------------------

PurrscalParser::ChonkContext* PurrscalParser::ChonkTypespecContext::chonk() {
  return getRuleContext<PurrscalParser::ChonkContext>(0);
}

PurrscalParser::ChonkTypespecContext::ChonkTypespecContext(BreedContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PurrscalParser::ChonkTypespecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitChonkTypespec(this);
  else
    return visitor->visitChildren(this);
}
PurrscalParser::BreedContext* PurrscalParser::breed() {
  BreedContext *_localctx = _tracker.createInstance<BreedContext>(_ctx, getState());
  enterRule(_localctx, 30, PurrscalParser::RuleBreed);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<BreedContext *>(_tracker.createInstance<PurrscalParser::ChonkTypespecContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(258);
    chonk();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ChonkContext ------------------------------------------------------------------

PurrscalParser::ChonkContext::ChonkContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PurrscalParser::ChonkContext::getRuleIndex() const {
  return PurrscalParser::RuleChonk;
}

void PurrscalParser::ChonkContext::copyFrom(ChonkContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->type = ctx->type;
}

//----------------- KittenKaboodleTypespecContext ------------------------------------------------------------------

PurrscalParser::KittenKaboodleContext* PurrscalParser::KittenKaboodleTypespecContext::kittenKaboodle() {
  return getRuleContext<PurrscalParser::KittenKaboodleContext>(0);
}

PurrscalParser::KittenKaboodleTypespecContext::KittenKaboodleTypespecContext(ChonkContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PurrscalParser::KittenKaboodleTypespecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitKittenKaboodleTypespec(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FluffballTypespecContext ------------------------------------------------------------------

PurrscalParser::FluffballContext* PurrscalParser::FluffballTypespecContext::fluffball() {
  return getRuleContext<PurrscalParser::FluffballContext>(0);
}

PurrscalParser::FluffballTypespecContext::FluffballTypespecContext(ChonkContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PurrscalParser::FluffballTypespecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitFluffballTypespec(this);
  else
    return visitor->visitChildren(this);
}
//----------------- KittyBreedTypsecContext ------------------------------------------------------------------

PurrscalParser::KittyBreedContext* PurrscalParser::KittyBreedTypsecContext::kittyBreed() {
  return getRuleContext<PurrscalParser::KittyBreedContext>(0);
}

PurrscalParser::KittyBreedTypsecContext::KittyBreedTypsecContext(ChonkContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PurrscalParser::KittyBreedTypsecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitKittyBreedTypsec(this);
  else
    return visitor->visitChildren(this);
}
PurrscalParser::ChonkContext* PurrscalParser::chonk() {
  ChonkContext *_localctx = _tracker.createInstance<ChonkContext>(_ctx, getState());
  enterRule(_localctx, 32, PurrscalParser::RuleChonk);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(263);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<ChonkContext *>(_tracker.createInstance<PurrscalParser::KittyBreedTypsecContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(260);
      kittyBreed();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<ChonkContext *>(_tracker.createInstance<PurrscalParser::FluffballTypespecContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(261);
      fluffball();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<ChonkContext *>(_tracker.createInstance<PurrscalParser::KittenKaboodleTypespecContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(262);
      kittenKaboodle();
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

//----------------- FluffballContext ------------------------------------------------------------------

PurrscalParser::FluffballContext::FluffballContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PurrscalParser::FluffballDomesticContext *> PurrscalParser::FluffballContext::fluffballDomestic() {
  return getRuleContexts<PurrscalParser::FluffballDomesticContext>();
}

PurrscalParser::FluffballDomesticContext* PurrscalParser::FluffballContext::fluffballDomestic(size_t i) {
  return getRuleContext<PurrscalParser::FluffballDomesticContext>(i);
}


size_t PurrscalParser::FluffballContext::getRuleIndex() const {
  return PurrscalParser::RuleFluffball;
}


antlrcpp::Any PurrscalParser::FluffballContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitFluffball(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::FluffballContext* PurrscalParser::fluffball() {
  FluffballContext *_localctx = _tracker.createInstance<FluffballContext>(_ctx, getState());
  enterRule(_localctx, 34, PurrscalParser::RuleFluffball);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(265);
    match(PurrscalParser::T__0);
    setState(266);
    fluffballDomestic();
    setState(271);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PurrscalParser::T__1) {
      setState(267);
      match(PurrscalParser::T__1);
      setState(268);
      fluffballDomestic();
      setState(273);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(274);
    match(PurrscalParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FluffballDomesticContext ------------------------------------------------------------------

PurrscalParser::FluffballDomesticContext::FluffballDomesticContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PurrscalParser::DomesticKittyContext* PurrscalParser::FluffballDomesticContext::domesticKitty() {
  return getRuleContext<PurrscalParser::DomesticKittyContext>(0);
}


size_t PurrscalParser::FluffballDomesticContext::getRuleIndex() const {
  return PurrscalParser::RuleFluffballDomestic;
}


antlrcpp::Any PurrscalParser::FluffballDomesticContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitFluffballDomestic(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::FluffballDomesticContext* PurrscalParser::fluffballDomestic() {
  FluffballDomesticContext *_localctx = _tracker.createInstance<FluffballDomesticContext>(_ctx, getState());
  enterRule(_localctx, 36, PurrscalParser::RuleFluffballDomestic);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(276);
    domesticKitty();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KittenKaboodleContext ------------------------------------------------------------------

PurrscalParser::KittenKaboodleContext::KittenKaboodleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PurrscalParser::DomesticContext *> PurrscalParser::KittenKaboodleContext::domestic() {
  return getRuleContexts<PurrscalParser::DomesticContext>();
}

PurrscalParser::DomesticContext* PurrscalParser::KittenKaboodleContext::domestic(size_t i) {
  return getRuleContext<PurrscalParser::DomesticContext>(i);
}


size_t PurrscalParser::KittenKaboodleContext::getRuleIndex() const {
  return PurrscalParser::RuleKittenKaboodle;
}


antlrcpp::Any PurrscalParser::KittenKaboodleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitKittenKaboodle(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::KittenKaboodleContext* PurrscalParser::kittenKaboodle() {
  KittenKaboodleContext *_localctx = _tracker.createInstance<KittenKaboodleContext>(_ctx, getState());
  enterRule(_localctx, 38, PurrscalParser::RuleKittenKaboodle);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(278);
    domestic();
    setState(279);
    match(PurrscalParser::T__4);
    setState(280);
    domestic();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KaboodleContext ------------------------------------------------------------------

PurrscalParser::KaboodleContext::KaboodleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PurrscalParser::BreedContext* PurrscalParser::KaboodleContext::breed() {
  return getRuleContext<PurrscalParser::BreedContext>(0);
}

tree::TerminalNode* PurrscalParser::KaboodleContext::KABOODLE() {
  return getToken(PurrscalParser::KABOODLE, 0);
}

PurrscalParser::ChonksContext* PurrscalParser::KaboodleContext::chonks() {
  return getRuleContext<PurrscalParser::ChonksContext>(0);
}


size_t PurrscalParser::KaboodleContext::getRuleIndex() const {
  return PurrscalParser::RuleKaboodle;
}


antlrcpp::Any PurrscalParser::KaboodleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitKaboodle(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::KaboodleContext* PurrscalParser::kaboodle() {
  KaboodleContext *_localctx = _tracker.createInstance<KaboodleContext>(_ctx, getState());
  enterRule(_localctx, 40, PurrscalParser::RuleKaboodle);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(282);
    breed();
    setState(283);
    match(PurrscalParser::KABOODLE);
    setState(284);
    match(PurrscalParser::T__5);
    setState(285);
    chonks();
    setState(286);
    match(PurrscalParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ChonksContext ------------------------------------------------------------------

PurrscalParser::ChonksContext::ChonksContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PurrscalParser::ChonkContext *> PurrscalParser::ChonksContext::chonk() {
  return getRuleContexts<PurrscalParser::ChonkContext>();
}

PurrscalParser::ChonkContext* PurrscalParser::ChonksContext::chonk(size_t i) {
  return getRuleContext<PurrscalParser::ChonkContext>(i);
}


size_t PurrscalParser::ChonksContext::getRuleIndex() const {
  return PurrscalParser::RuleChonks;
}


antlrcpp::Any PurrscalParser::ChonksContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitChonks(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::ChonksContext* PurrscalParser::chonks() {
  ChonksContext *_localctx = _tracker.createInstance<ChonksContext>(_ctx, getState());
  enterRule(_localctx, 42, PurrscalParser::RuleChonks);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(288);
    chonk();
    setState(293);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PurrscalParser::T__1) {
      setState(289);
      match(PurrscalParser::T__1);
      setState(290);
      chonk();
      setState(295);
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

//----------------- KittenQualityContext ------------------------------------------------------------------

PurrscalParser::KittenQualityContext::KittenQualityContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PurrscalParser::KittenQualityContext::KITTEN() {
  return getToken(PurrscalParser::KITTEN, 0);
}

PurrscalParser::KittenBodiesContext* PurrscalParser::KittenQualityContext::kittenBodies() {
  return getRuleContext<PurrscalParser::KittenBodiesContext>(0);
}


size_t PurrscalParser::KittenQualityContext::getRuleIndex() const {
  return PurrscalParser::RuleKittenQuality;
}


antlrcpp::Any PurrscalParser::KittenQualityContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitKittenQuality(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::KittenQualityContext* PurrscalParser::kittenQuality() {
  KittenQualityContext *_localctx = _tracker.createInstance<KittenQualityContext>(_ctx, getState());
  enterRule(_localctx, 44, PurrscalParser::RuleKittenQuality);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(296);
    match(PurrscalParser::KITTEN);
    setState(297);
    kittenBodies();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KittenBodiesContext ------------------------------------------------------------------

PurrscalParser::KittenBodiesContext::KittenBodiesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PurrscalParser::KittenBodyContext *> PurrscalParser::KittenBodiesContext::kittenBody() {
  return getRuleContexts<PurrscalParser::KittenBodyContext>();
}

PurrscalParser::KittenBodyContext* PurrscalParser::KittenBodiesContext::kittenBody(size_t i) {
  return getRuleContext<PurrscalParser::KittenBodyContext>(i);
}

std::vector<tree::TerminalNode *> PurrscalParser::KittenBodiesContext::OWO() {
  return getTokens(PurrscalParser::OWO);
}

tree::TerminalNode* PurrscalParser::KittenBodiesContext::OWO(size_t i) {
  return getToken(PurrscalParser::OWO, i);
}


size_t PurrscalParser::KittenBodiesContext::getRuleIndex() const {
  return PurrscalParser::RuleKittenBodies;
}


antlrcpp::Any PurrscalParser::KittenBodiesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitKittenBodies(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::KittenBodiesContext* PurrscalParser::kittenBodies() {
  KittenBodiesContext *_localctx = _tracker.createInstance<KittenBodiesContext>(_ctx, getState());
  enterRule(_localctx, 46, PurrscalParser::RuleKittenBodies);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(299);
    kittenBody();
    setState(304);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(300);
        match(PurrscalParser::OWO);
        setState(301);
        kittenBody(); 
      }
      setState(306);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KittenBodyContext ------------------------------------------------------------------

PurrscalParser::KittenBodyContext::KittenBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PurrscalParser::KittenKittiesContext* PurrscalParser::KittenBodyContext::kittenKitties() {
  return getRuleContext<PurrscalParser::KittenKittiesContext>(0);
}

PurrscalParser::BreedContext* PurrscalParser::KittenBodyContext::breed() {
  return getRuleContext<PurrscalParser::BreedContext>(0);
}


size_t PurrscalParser::KittenBodyContext::getRuleIndex() const {
  return PurrscalParser::RuleKittenBody;
}


antlrcpp::Any PurrscalParser::KittenBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitKittenBody(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::KittenBodyContext* PurrscalParser::kittenBody() {
  KittenBodyContext *_localctx = _tracker.createInstance<KittenBodyContext>(_ctx, getState());
  enterRule(_localctx, 48, PurrscalParser::RuleKittenBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(307);
    kittenKitties();
    setState(308);
    match(PurrscalParser::T__7);
    setState(309);
    breed();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KittenKittiesContext ------------------------------------------------------------------

PurrscalParser::KittenKittiesContext::KittenKittiesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PurrscalParser::KittenKittyContext *> PurrscalParser::KittenKittiesContext::kittenKitty() {
  return getRuleContexts<PurrscalParser::KittenKittyContext>();
}

PurrscalParser::KittenKittyContext* PurrscalParser::KittenKittiesContext::kittenKitty(size_t i) {
  return getRuleContext<PurrscalParser::KittenKittyContext>(i);
}


size_t PurrscalParser::KittenKittiesContext::getRuleIndex() const {
  return PurrscalParser::RuleKittenKitties;
}


antlrcpp::Any PurrscalParser::KittenKittiesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitKittenKitties(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::KittenKittiesContext* PurrscalParser::kittenKitties() {
  KittenKittiesContext *_localctx = _tracker.createInstance<KittenKittiesContext>(_ctx, getState());
  enterRule(_localctx, 50, PurrscalParser::RuleKittenKitties);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(311);
    kittenKitty();
    setState(316);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PurrscalParser::T__1) {
      setState(312);
      match(PurrscalParser::T__1);
      setState(313);
      kittenKitty();
      setState(318);
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

//----------------- KittenKittyContext ------------------------------------------------------------------

PurrscalParser::KittenKittyContext::KittenKittyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PurrscalParser::KittenKittyContext::KITTY() {
  return getToken(PurrscalParser::KITTY, 0);
}


size_t PurrscalParser::KittenKittyContext::getRuleIndex() const {
  return PurrscalParser::RuleKittenKitty;
}


antlrcpp::Any PurrscalParser::KittenKittyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitKittenKitty(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::KittenKittyContext* PurrscalParser::kittenKitty() {
  KittenKittyContext *_localctx = _tracker.createInstance<KittenKittyContext>(_ctx, getState());
  enterRule(_localctx, 52, PurrscalParser::RuleKittenKitty);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(319);
    match(PurrscalParser::KITTY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CallQualityContext ------------------------------------------------------------------

PurrscalParser::CallQualityContext::CallQualityContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PurrscalParser::CallBodyContext *> PurrscalParser::CallQualityContext::callBody() {
  return getRuleContexts<PurrscalParser::CallBodyContext>();
}

PurrscalParser::CallBodyContext* PurrscalParser::CallQualityContext::callBody(size_t i) {
  return getRuleContext<PurrscalParser::CallBodyContext>(i);
}

std::vector<tree::TerminalNode *> PurrscalParser::CallQualityContext::OWO() {
  return getTokens(PurrscalParser::OWO);
}

tree::TerminalNode* PurrscalParser::CallQualityContext::OWO(size_t i) {
  return getToken(PurrscalParser::OWO, i);
}


size_t PurrscalParser::CallQualityContext::getRuleIndex() const {
  return PurrscalParser::RuleCallQuality;
}


antlrcpp::Any PurrscalParser::CallQualityContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitCallQuality(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::CallQualityContext* PurrscalParser::callQuality() {
  CallQualityContext *_localctx = _tracker.createInstance<CallQualityContext>(_ctx, getState());
  enterRule(_localctx, 54, PurrscalParser::RuleCallQuality);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(321);
    callBody();
    setState(326);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(322);
        match(PurrscalParser::OWO);
        setState(323);
        callBody(); 
      }
      setState(328);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CallBodyContext ------------------------------------------------------------------

PurrscalParser::CallBodyContext::CallBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PurrscalParser::CallBodyContext::OWO() {
  return getToken(PurrscalParser::OWO, 0);
}

PurrscalParser::CatContext* PurrscalParser::CallBodyContext::cat() {
  return getRuleContext<PurrscalParser::CatContext>(0);
}

PurrscalParser::YowlSnootContext* PurrscalParser::CallBodyContext::yowlSnoot() {
  return getRuleContext<PurrscalParser::YowlSnootContext>(0);
}

PurrscalParser::BlepSnootContext* PurrscalParser::CallBodyContext::blepSnoot() {
  return getRuleContext<PurrscalParser::BlepSnootContext>(0);
}


size_t PurrscalParser::CallBodyContext::getRuleIndex() const {
  return PurrscalParser::RuleCallBody;
}


antlrcpp::Any PurrscalParser::CallBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitCallBody(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::CallBodyContext* PurrscalParser::callBody() {
  CallBodyContext *_localctx = _tracker.createInstance<CallBodyContext>(_ctx, getState());
  enterRule(_localctx, 56, PurrscalParser::RuleCallBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(331);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PurrscalParser::YOWL: {
        setState(329);
        yowlSnoot();
        break;
      }

      case PurrscalParser::BLEP: {
        setState(330);
        blepSnoot();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(333);
    match(PurrscalParser::OWO);
    setState(334);
    cat();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- YowlSnootContext ------------------------------------------------------------------

PurrscalParser::YowlSnootContext::YowlSnootContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PurrscalParser::YowlSnootContext::YOWL() {
  return getToken(PurrscalParser::YOWL, 0);
}

PurrscalParser::CallKittyContext* PurrscalParser::YowlSnootContext::callKitty() {
  return getRuleContext<PurrscalParser::CallKittyContext>(0);
}

PurrscalParser::PurrametersContext* PurrscalParser::YowlSnootContext::purrameters() {
  return getRuleContext<PurrscalParser::PurrametersContext>(0);
}


size_t PurrscalParser::YowlSnootContext::getRuleIndex() const {
  return PurrscalParser::RuleYowlSnoot;
}


antlrcpp::Any PurrscalParser::YowlSnootContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitYowlSnoot(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::YowlSnootContext* PurrscalParser::yowlSnoot() {
  YowlSnootContext *_localctx = _tracker.createInstance<YowlSnootContext>(_ctx, getState());
  enterRule(_localctx, 58, PurrscalParser::RuleYowlSnoot);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(336);
    match(PurrscalParser::YOWL);
    setState(337);
    callKitty();
    setState(339);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PurrscalParser::T__0) {
      setState(338);
      purrameters();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlepSnootContext ------------------------------------------------------------------

PurrscalParser::BlepSnootContext::BlepSnootContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PurrscalParser::BlepSnootContext::BLEP() {
  return getToken(PurrscalParser::BLEP, 0);
}

PurrscalParser::CallKittyContext* PurrscalParser::BlepSnootContext::callKitty() {
  return getRuleContext<PurrscalParser::CallKittyContext>(0);
}

PurrscalParser::KittyBreedContext* PurrscalParser::BlepSnootContext::kittyBreed() {
  return getRuleContext<PurrscalParser::KittyBreedContext>(0);
}

PurrscalParser::PurrametersContext* PurrscalParser::BlepSnootContext::purrameters() {
  return getRuleContext<PurrscalParser::PurrametersContext>(0);
}


size_t PurrscalParser::BlepSnootContext::getRuleIndex() const {
  return PurrscalParser::RuleBlepSnoot;
}


antlrcpp::Any PurrscalParser::BlepSnootContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitBlepSnoot(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::BlepSnootContext* PurrscalParser::blepSnoot() {
  BlepSnootContext *_localctx = _tracker.createInstance<BlepSnootContext>(_ctx, getState());
  enterRule(_localctx, 60, PurrscalParser::RuleBlepSnoot);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(341);
    match(PurrscalParser::BLEP);
    setState(342);
    callKitty();
    setState(344);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PurrscalParser::T__0) {
      setState(343);
      purrameters();
    }
    setState(346);
    match(PurrscalParser::T__7);
    setState(347);
    kittyBreed();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CallKittyContext ------------------------------------------------------------------

PurrscalParser::CallKittyContext::CallKittyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PurrscalParser::CallKittyContext::KITTY() {
  return getToken(PurrscalParser::KITTY, 0);
}


size_t PurrscalParser::CallKittyContext::getRuleIndex() const {
  return PurrscalParser::RuleCallKitty;
}


antlrcpp::Any PurrscalParser::CallKittyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitCallKitty(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::CallKittyContext* PurrscalParser::callKitty() {
  CallKittyContext *_localctx = _tracker.createInstance<CallKittyContext>(_ctx, getState());
  enterRule(_localctx, 62, PurrscalParser::RuleCallKitty);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(349);
    match(PurrscalParser::KITTY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PurrametersContext ------------------------------------------------------------------

PurrscalParser::PurrametersContext::PurrametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PurrscalParser::PurrameterPurrsContext* PurrscalParser::PurrametersContext::purrameterPurrs() {
  return getRuleContext<PurrscalParser::PurrameterPurrsContext>(0);
}


size_t PurrscalParser::PurrametersContext::getRuleIndex() const {
  return PurrscalParser::RulePurrameters;
}


antlrcpp::Any PurrscalParser::PurrametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitPurrameters(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::PurrametersContext* PurrscalParser::purrameters() {
  PurrametersContext *_localctx = _tracker.createInstance<PurrametersContext>(_ctx, getState());
  enterRule(_localctx, 64, PurrscalParser::RulePurrameters);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(351);
    match(PurrscalParser::T__0);
    setState(352);
    purrameterPurrs();
    setState(353);
    match(PurrscalParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PurrameterPurrsContext ------------------------------------------------------------------

PurrscalParser::PurrameterPurrsContext::PurrameterPurrsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PurrscalParser::PurrameterPurrContext *> PurrscalParser::PurrameterPurrsContext::purrameterPurr() {
  return getRuleContexts<PurrscalParser::PurrameterPurrContext>();
}

PurrscalParser::PurrameterPurrContext* PurrscalParser::PurrameterPurrsContext::purrameterPurr(size_t i) {
  return getRuleContext<PurrscalParser::PurrameterPurrContext>(i);
}

std::vector<tree::TerminalNode *> PurrscalParser::PurrameterPurrsContext::OWO() {
  return getTokens(PurrscalParser::OWO);
}

tree::TerminalNode* PurrscalParser::PurrameterPurrsContext::OWO(size_t i) {
  return getToken(PurrscalParser::OWO, i);
}


size_t PurrscalParser::PurrameterPurrsContext::getRuleIndex() const {
  return PurrscalParser::RulePurrameterPurrs;
}


antlrcpp::Any PurrscalParser::PurrameterPurrsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitPurrameterPurrs(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::PurrameterPurrsContext* PurrscalParser::purrameterPurrs() {
  PurrameterPurrsContext *_localctx = _tracker.createInstance<PurrameterPurrsContext>(_ctx, getState());
  enterRule(_localctx, 66, PurrscalParser::RulePurrameterPurrs);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(355);
    purrameterPurr();
    setState(360);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PurrscalParser::OWO) {
      setState(356);
      match(PurrscalParser::OWO);
      setState(357);
      purrameterPurr();
      setState(362);
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

//----------------- PurrameterPurrContext ------------------------------------------------------------------

PurrscalParser::PurrameterPurrContext::PurrameterPurrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PurrscalParser::PurrameterKittiesContext* PurrscalParser::PurrameterPurrContext::purrameterKitties() {
  return getRuleContext<PurrscalParser::PurrameterKittiesContext>(0);
}

PurrscalParser::KittyBreedContext* PurrscalParser::PurrameterPurrContext::kittyBreed() {
  return getRuleContext<PurrscalParser::KittyBreedContext>(0);
}

tree::TerminalNode* PurrscalParser::PurrameterPurrContext::KITTEN() {
  return getToken(PurrscalParser::KITTEN, 0);
}


size_t PurrscalParser::PurrameterPurrContext::getRuleIndex() const {
  return PurrscalParser::RulePurrameterPurr;
}


antlrcpp::Any PurrscalParser::PurrameterPurrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitPurrameterPurr(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::PurrameterPurrContext* PurrscalParser::purrameterPurr() {
  PurrameterPurrContext *_localctx = _tracker.createInstance<PurrameterPurrContext>(_ctx, getState());
  enterRule(_localctx, 68, PurrscalParser::RulePurrameterPurr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(364);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PurrscalParser::KITTEN) {
      setState(363);
      match(PurrscalParser::KITTEN);
    }
    setState(366);
    purrameterKitties();
    setState(367);
    match(PurrscalParser::T__7);
    setState(368);
    kittyBreed();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PurrameterKittiesContext ------------------------------------------------------------------

PurrscalParser::PurrameterKittiesContext::PurrameterKittiesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PurrscalParser::PurrameterKittyContext *> PurrscalParser::PurrameterKittiesContext::purrameterKitty() {
  return getRuleContexts<PurrscalParser::PurrameterKittyContext>();
}

PurrscalParser::PurrameterKittyContext* PurrscalParser::PurrameterKittiesContext::purrameterKitty(size_t i) {
  return getRuleContext<PurrscalParser::PurrameterKittyContext>(i);
}


size_t PurrscalParser::PurrameterKittiesContext::getRuleIndex() const {
  return PurrscalParser::RulePurrameterKitties;
}


antlrcpp::Any PurrscalParser::PurrameterKittiesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitPurrameterKitties(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::PurrameterKittiesContext* PurrscalParser::purrameterKitties() {
  PurrameterKittiesContext *_localctx = _tracker.createInstance<PurrameterKittiesContext>(_ctx, getState());
  enterRule(_localctx, 70, PurrscalParser::RulePurrameterKitties);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(370);
    purrameterKitty();
    setState(375);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PurrscalParser::T__1) {
      setState(371);
      match(PurrscalParser::T__1);
      setState(372);
      purrameterKitty();
      setState(377);
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

//----------------- PurrameterKittyContext ------------------------------------------------------------------

PurrscalParser::PurrameterKittyContext::PurrameterKittyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PurrscalParser::PurrameterKittyContext::KITTY() {
  return getToken(PurrscalParser::KITTY, 0);
}


size_t PurrscalParser::PurrameterKittyContext::getRuleIndex() const {
  return PurrscalParser::RulePurrameterKitty;
}


antlrcpp::Any PurrscalParser::PurrameterKittyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitPurrameterKitty(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::PurrameterKittyContext* PurrscalParser::purrameterKitty() {
  PurrameterKittyContext *_localctx = _tracker.createInstance<PurrameterKittyContext>(_ctx, getState());
  enterRule(_localctx, 72, PurrscalParser::RulePurrameterKitty);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(378);
    match(PurrscalParser::KITTY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MewContext ------------------------------------------------------------------

PurrscalParser::MewContext::MewContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PurrscalParser::TheBigMewContext* PurrscalParser::MewContext::theBigMew() {
  return getRuleContext<PurrscalParser::TheBigMewContext>(0);
}

PurrscalParser::HungryMewContext* PurrscalParser::MewContext::hungryMew() {
  return getRuleContext<PurrscalParser::HungryMewContext>(0);
}

PurrscalParser::SniffMewContext* PurrscalParser::MewContext::sniffMew() {
  return getRuleContext<PurrscalParser::SniffMewContext>(0);
}

PurrscalParser::HowlMewContext* PurrscalParser::MewContext::howlMew() {
  return getRuleContext<PurrscalParser::HowlMewContext>(0);
}

PurrscalParser::PurrMewContext* PurrscalParser::MewContext::purrMew() {
  return getRuleContext<PurrscalParser::PurrMewContext>(0);
}

PurrscalParser::MeowMewContext* PurrscalParser::MewContext::meowMew() {
  return getRuleContext<PurrscalParser::MeowMewContext>(0);
}

PurrscalParser::MrrrMewContext* PurrscalParser::MewContext::mrrrMew() {
  return getRuleContext<PurrscalParser::MrrrMewContext>(0);
}

PurrscalParser::StalkMewContext* PurrscalParser::MewContext::stalkMew() {
  return getRuleContext<PurrscalParser::StalkMewContext>(0);
}

PurrscalParser::PounceMewContext* PurrscalParser::MewContext::pounceMew() {
  return getRuleContext<PurrscalParser::PounceMewContext>(0);
}

PurrscalParser::YowlCallMewContext* PurrscalParser::MewContext::yowlCallMew() {
  return getRuleContext<PurrscalParser::YowlCallMewContext>(0);
}

PurrscalParser::BlankStareContext* PurrscalParser::MewContext::blankStare() {
  return getRuleContext<PurrscalParser::BlankStareContext>(0);
}


size_t PurrscalParser::MewContext::getRuleIndex() const {
  return PurrscalParser::RuleMew;
}


antlrcpp::Any PurrscalParser::MewContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitMew(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::MewContext* PurrscalParser::mew() {
  MewContext *_localctx = _tracker.createInstance<MewContext>(_ctx, getState());
  enterRule(_localctx, 74, PurrscalParser::RuleMew);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(391);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(380);
      theBigMew();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(381);
      hungryMew();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(382);
      sniffMew();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(383);
      howlMew();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(384);
      purrMew();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(385);
      meowMew();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(386);
      mrrrMew();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(387);
      stalkMew();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(388);
      pounceMew();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(389);
      yowlCallMew();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(390);
      blankStare();
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

//----------------- MewsContext ------------------------------------------------------------------

PurrscalParser::MewsContext::MewsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PurrscalParser::MewContext *> PurrscalParser::MewsContext::mew() {
  return getRuleContexts<PurrscalParser::MewContext>();
}

PurrscalParser::MewContext* PurrscalParser::MewsContext::mew(size_t i) {
  return getRuleContext<PurrscalParser::MewContext>(i);
}

std::vector<tree::TerminalNode *> PurrscalParser::MewsContext::OWO() {
  return getTokens(PurrscalParser::OWO);
}

tree::TerminalNode* PurrscalParser::MewsContext::OWO(size_t i) {
  return getToken(PurrscalParser::OWO, i);
}


size_t PurrscalParser::MewsContext::getRuleIndex() const {
  return PurrscalParser::RuleMews;
}


antlrcpp::Any PurrscalParser::MewsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitMews(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::MewsContext* PurrscalParser::mews() {
  MewsContext *_localctx = _tracker.createInstance<MewsContext>(_ctx, getState());
  enterRule(_localctx, 76, PurrscalParser::RuleMews);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(393);
    mew();
    setState(398);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PurrscalParser::OWO) {
      setState(394);
      match(PurrscalParser::OWO);
      setState(395);
      mew();
      setState(400);
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

//----------------- TheBigMewContext ------------------------------------------------------------------

PurrscalParser::TheBigMewContext::TheBigMewContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PurrscalParser::TheBigMewContext::PLAY() {
  return getToken(PurrscalParser::PLAY, 0);
}

PurrscalParser::MewsContext* PurrscalParser::TheBigMewContext::mews() {
  return getRuleContext<PurrscalParser::MewsContext>(0);
}

tree::TerminalNode* PurrscalParser::TheBigMewContext::NAP() {
  return getToken(PurrscalParser::NAP, 0);
}


size_t PurrscalParser::TheBigMewContext::getRuleIndex() const {
  return PurrscalParser::RuleTheBigMew;
}


antlrcpp::Any PurrscalParser::TheBigMewContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitTheBigMew(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::TheBigMewContext* PurrscalParser::theBigMew() {
  TheBigMewContext *_localctx = _tracker.createInstance<TheBigMewContext>(_ctx, getState());
  enterRule(_localctx, 78, PurrscalParser::RuleTheBigMew);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(401);
    match(PurrscalParser::PLAY);
    setState(402);
    mews();
    setState(403);
    match(PurrscalParser::NAP);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlankStareContext ------------------------------------------------------------------

PurrscalParser::BlankStareContext::BlankStareContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PurrscalParser::BlankStareContext::getRuleIndex() const {
  return PurrscalParser::RuleBlankStare;
}


antlrcpp::Any PurrscalParser::BlankStareContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitBlankStare(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::BlankStareContext* PurrscalParser::blankStare() {
  BlankStareContext *_localctx = _tracker.createInstance<BlankStareContext>(_ctx, getState());
  enterRule(_localctx, 80, PurrscalParser::RuleBlankStare);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- HungryMewContext ------------------------------------------------------------------

PurrscalParser::HungryMewContext::HungryMewContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PurrscalParser::LpsContext* PurrscalParser::HungryMewContext::lps() {
  return getRuleContext<PurrscalParser::LpsContext>(0);
}

PurrscalParser::RpsContext* PurrscalParser::HungryMewContext::rps() {
  return getRuleContext<PurrscalParser::RpsContext>(0);
}


size_t PurrscalParser::HungryMewContext::getRuleIndex() const {
  return PurrscalParser::RuleHungryMew;
}


antlrcpp::Any PurrscalParser::HungryMewContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitHungryMew(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::HungryMewContext* PurrscalParser::hungryMew() {
  HungryMewContext *_localctx = _tracker.createInstance<HungryMewContext>(_ctx, getState());
  enterRule(_localctx, 82, PurrscalParser::RuleHungryMew);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(407);
    lps();
    setState(408);
    match(PurrscalParser::T__3);
    setState(409);
    rps();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LpsContext ------------------------------------------------------------------

PurrscalParser::LpsContext::LpsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PurrscalParser::KittenContext* PurrscalParser::LpsContext::kitten() {
  return getRuleContext<PurrscalParser::KittenContext>(0);
}


size_t PurrscalParser::LpsContext::getRuleIndex() const {
  return PurrscalParser::RuleLps;
}


antlrcpp::Any PurrscalParser::LpsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitLps(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::LpsContext* PurrscalParser::lps() {
  LpsContext *_localctx = _tracker.createInstance<LpsContext>(_ctx, getState());
  enterRule(_localctx, 84, PurrscalParser::RuleLps);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(411);
    kitten();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RpsContext ------------------------------------------------------------------

PurrscalParser::RpsContext::RpsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PurrscalParser::DemandContext* PurrscalParser::RpsContext::demand() {
  return getRuleContext<PurrscalParser::DemandContext>(0);
}


size_t PurrscalParser::RpsContext::getRuleIndex() const {
  return PurrscalParser::RuleRps;
}


antlrcpp::Any PurrscalParser::RpsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitRps(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::RpsContext* PurrscalParser::rps() {
  RpsContext *_localctx = _tracker.createInstance<RpsContext>(_ctx, getState());
  enterRule(_localctx, 86, PurrscalParser::RuleRps);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(413);
    demand();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SniffMewContext ------------------------------------------------------------------

PurrscalParser::SniffMewContext::SniffMewContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PurrscalParser::SniffMewContext::SNIFF() {
  return getToken(PurrscalParser::SNIFF, 0);
}

PurrscalParser::DemandContext* PurrscalParser::SniffMewContext::demand() {
  return getRuleContext<PurrscalParser::DemandContext>(0);
}

tree::TerminalNode* PurrscalParser::SniffMewContext::PAW() {
  return getToken(PurrscalParser::PAW, 0);
}

PurrscalParser::PawMewContext* PurrscalParser::SniffMewContext::pawMew() {
  return getRuleContext<PurrscalParser::PawMewContext>(0);
}

tree::TerminalNode* PurrscalParser::SniffMewContext::IGNORE() {
  return getToken(PurrscalParser::IGNORE, 0);
}

PurrscalParser::IgnoreMewContext* PurrscalParser::SniffMewContext::ignoreMew() {
  return getRuleContext<PurrscalParser::IgnoreMewContext>(0);
}


size_t PurrscalParser::SniffMewContext::getRuleIndex() const {
  return PurrscalParser::RuleSniffMew;
}


antlrcpp::Any PurrscalParser::SniffMewContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitSniffMew(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::SniffMewContext* PurrscalParser::sniffMew() {
  SniffMewContext *_localctx = _tracker.createInstance<SniffMewContext>(_ctx, getState());
  enterRule(_localctx, 88, PurrscalParser::RuleSniffMew);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(415);
    match(PurrscalParser::SNIFF);
    setState(416);
    demand();
    setState(417);
    match(PurrscalParser::PAW);
    setState(418);
    pawMew();
    setState(421);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      setState(419);
      match(PurrscalParser::IGNORE);
      setState(420);
      ignoreMew();
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

//----------------- PawMewContext ------------------------------------------------------------------

PurrscalParser::PawMewContext::PawMewContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PurrscalParser::MewContext* PurrscalParser::PawMewContext::mew() {
  return getRuleContext<PurrscalParser::MewContext>(0);
}


size_t PurrscalParser::PawMewContext::getRuleIndex() const {
  return PurrscalParser::RulePawMew;
}


antlrcpp::Any PurrscalParser::PawMewContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitPawMew(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::PawMewContext* PurrscalParser::pawMew() {
  PawMewContext *_localctx = _tracker.createInstance<PawMewContext>(_ctx, getState());
  enterRule(_localctx, 90, PurrscalParser::RulePawMew);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(423);
    mew();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IgnoreMewContext ------------------------------------------------------------------

PurrscalParser::IgnoreMewContext::IgnoreMewContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PurrscalParser::MewContext* PurrscalParser::IgnoreMewContext::mew() {
  return getRuleContext<PurrscalParser::MewContext>(0);
}


size_t PurrscalParser::IgnoreMewContext::getRuleIndex() const {
  return PurrscalParser::RuleIgnoreMew;
}


antlrcpp::Any PurrscalParser::IgnoreMewContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitIgnoreMew(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::IgnoreMewContext* PurrscalParser::ignoreMew() {
  IgnoreMewContext *_localctx = _tracker.createInstance<IgnoreMewContext>(_ctx, getState());
  enterRule(_localctx, 92, PurrscalParser::RuleIgnoreMew);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(425);
    mew();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- HowlMewContext ------------------------------------------------------------------

PurrscalParser::HowlMewContext::HowlMewContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PurrscalParser::HowlMewContext::HOWL() {
  return getToken(PurrscalParser::HOWL, 0);
}

PurrscalParser::MewsContext* PurrscalParser::HowlMewContext::mews() {
  return getRuleContext<PurrscalParser::MewsContext>(0);
}

tree::TerminalNode* PurrscalParser::HowlMewContext::UNTIL() {
  return getToken(PurrscalParser::UNTIL, 0);
}

PurrscalParser::DemandContext* PurrscalParser::HowlMewContext::demand() {
  return getRuleContext<PurrscalParser::DemandContext>(0);
}


size_t PurrscalParser::HowlMewContext::getRuleIndex() const {
  return PurrscalParser::RuleHowlMew;
}


antlrcpp::Any PurrscalParser::HowlMewContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitHowlMew(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::HowlMewContext* PurrscalParser::howlMew() {
  HowlMewContext *_localctx = _tracker.createInstance<HowlMewContext>(_ctx, getState());
  enterRule(_localctx, 94, PurrscalParser::RuleHowlMew);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(427);
    match(PurrscalParser::HOWL);
    setState(428);
    mews();
    setState(429);
    match(PurrscalParser::UNTIL);
    setState(430);
    demand();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PurrMewContext ------------------------------------------------------------------

PurrscalParser::PurrMewContext::PurrMewContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PurrscalParser::PurrMewContext::WHILE() {
  return getToken(PurrscalParser::WHILE, 0);
}

PurrscalParser::DemandContext* PurrscalParser::PurrMewContext::demand() {
  return getRuleContext<PurrscalParser::DemandContext>(0);
}

tree::TerminalNode* PurrscalParser::PurrMewContext::PURR() {
  return getToken(PurrscalParser::PURR, 0);
}

PurrscalParser::MewContext* PurrscalParser::PurrMewContext::mew() {
  return getRuleContext<PurrscalParser::MewContext>(0);
}


size_t PurrscalParser::PurrMewContext::getRuleIndex() const {
  return PurrscalParser::RulePurrMew;
}


antlrcpp::Any PurrscalParser::PurrMewContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitPurrMew(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::PurrMewContext* PurrscalParser::purrMew() {
  PurrMewContext *_localctx = _tracker.createInstance<PurrMewContext>(_ctx, getState());
  enterRule(_localctx, 96, PurrscalParser::RulePurrMew);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(432);
    match(PurrscalParser::WHILE);
    setState(433);
    demand();
    setState(434);
    match(PurrscalParser::PURR);
    setState(435);
    mew();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlepCallContext ------------------------------------------------------------------

PurrscalParser::BlepCallContext::BlepCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PurrscalParser::BlepNameContext* PurrscalParser::BlepCallContext::blepName() {
  return getRuleContext<PurrscalParser::BlepNameContext>(0);
}

PurrscalParser::ChirpsContext* PurrscalParser::BlepCallContext::chirps() {
  return getRuleContext<PurrscalParser::ChirpsContext>(0);
}


size_t PurrscalParser::BlepCallContext::getRuleIndex() const {
  return PurrscalParser::RuleBlepCall;
}


antlrcpp::Any PurrscalParser::BlepCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitBlepCall(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::BlepCallContext* PurrscalParser::blepCall() {
  BlepCallContext *_localctx = _tracker.createInstance<BlepCallContext>(_ctx, getState());
  enterRule(_localctx, 98, PurrscalParser::RuleBlepCall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(437);
    blepName();
    setState(438);
    match(PurrscalParser::T__0);
    setState(440);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PurrscalParser::T__0)
      | (1ULL << PurrscalParser::T__9)
      | (1ULL << PurrscalParser::T__10)
      | (1ULL << PurrscalParser::ROLL)
      | (1ULL << PurrscalParser::KITTY)
      | (1ULL << PurrscalParser::SPHYNX)
      | (1ULL << PurrscalParser::HAIRLESS_FELINE)
      | (1ULL << PurrscalParser::THREAD)
      | (1ULL << PurrscalParser::YARN))) != 0)) {
      setState(439);
      chirps();
    }
    setState(442);
    match(PurrscalParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlepNameContext ------------------------------------------------------------------

PurrscalParser::BlepNameContext::BlepNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PurrscalParser::BlepNameContext::KITTY() {
  return getToken(PurrscalParser::KITTY, 0);
}


size_t PurrscalParser::BlepNameContext::getRuleIndex() const {
  return PurrscalParser::RuleBlepName;
}


antlrcpp::Any PurrscalParser::BlepNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitBlepName(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::BlepNameContext* PurrscalParser::blepName() {
  BlepNameContext *_localctx = _tracker.createInstance<BlepNameContext>(_ctx, getState());
  enterRule(_localctx, 100, PurrscalParser::RuleBlepName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(444);
    match(PurrscalParser::KITTY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- YowlCallMewContext ------------------------------------------------------------------

PurrscalParser::YowlCallMewContext::YowlCallMewContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PurrscalParser::YowlNameContext* PurrscalParser::YowlCallMewContext::yowlName() {
  return getRuleContext<PurrscalParser::YowlNameContext>(0);
}

PurrscalParser::ChirpsContext* PurrscalParser::YowlCallMewContext::chirps() {
  return getRuleContext<PurrscalParser::ChirpsContext>(0);
}


size_t PurrscalParser::YowlCallMewContext::getRuleIndex() const {
  return PurrscalParser::RuleYowlCallMew;
}


antlrcpp::Any PurrscalParser::YowlCallMewContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitYowlCallMew(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::YowlCallMewContext* PurrscalParser::yowlCallMew() {
  YowlCallMewContext *_localctx = _tracker.createInstance<YowlCallMewContext>(_ctx, getState());
  enterRule(_localctx, 102, PurrscalParser::RuleYowlCallMew);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(446);
    yowlName();
    setState(447);
    match(PurrscalParser::T__0);
    setState(449);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PurrscalParser::T__0)
      | (1ULL << PurrscalParser::T__9)
      | (1ULL << PurrscalParser::T__10)
      | (1ULL << PurrscalParser::ROLL)
      | (1ULL << PurrscalParser::KITTY)
      | (1ULL << PurrscalParser::SPHYNX)
      | (1ULL << PurrscalParser::HAIRLESS_FELINE)
      | (1ULL << PurrscalParser::THREAD)
      | (1ULL << PurrscalParser::YARN))) != 0)) {
      setState(448);
      chirps();
    }
    setState(451);
    match(PurrscalParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- YowlNameContext ------------------------------------------------------------------

PurrscalParser::YowlNameContext::YowlNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PurrscalParser::YowlNameContext::KITTY() {
  return getToken(PurrscalParser::KITTY, 0);
}


size_t PurrscalParser::YowlNameContext::getRuleIndex() const {
  return PurrscalParser::RuleYowlName;
}


antlrcpp::Any PurrscalParser::YowlNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitYowlName(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::YowlNameContext* PurrscalParser::yowlName() {
  YowlNameContext *_localctx = _tracker.createInstance<YowlNameContext>(_ctx, getState());
  enterRule(_localctx, 104, PurrscalParser::RuleYowlName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(453);
    match(PurrscalParser::KITTY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ChirpsContext ------------------------------------------------------------------

PurrscalParser::ChirpsContext::ChirpsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PurrscalParser::ChirpContext *> PurrscalParser::ChirpsContext::chirp() {
  return getRuleContexts<PurrscalParser::ChirpContext>();
}

PurrscalParser::ChirpContext* PurrscalParser::ChirpsContext::chirp(size_t i) {
  return getRuleContext<PurrscalParser::ChirpContext>(i);
}


size_t PurrscalParser::ChirpsContext::getRuleIndex() const {
  return PurrscalParser::RuleChirps;
}


antlrcpp::Any PurrscalParser::ChirpsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitChirps(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::ChirpsContext* PurrscalParser::chirps() {
  ChirpsContext *_localctx = _tracker.createInstance<ChirpsContext>(_ctx, getState());
  enterRule(_localctx, 106, PurrscalParser::RuleChirps);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(455);
    chirp();
    setState(460);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PurrscalParser::T__1) {
      setState(456);
      match(PurrscalParser::T__1);
      setState(457);
      chirp();
      setState(462);
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

//----------------- ChirpContext ------------------------------------------------------------------

PurrscalParser::ChirpContext::ChirpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PurrscalParser::DemandContext* PurrscalParser::ChirpContext::demand() {
  return getRuleContext<PurrscalParser::DemandContext>(0);
}


size_t PurrscalParser::ChirpContext::getRuleIndex() const {
  return PurrscalParser::RuleChirp;
}


antlrcpp::Any PurrscalParser::ChirpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitChirp(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::ChirpContext* PurrscalParser::chirp() {
  ChirpContext *_localctx = _tracker.createInstance<ChirpContext>(_ctx, getState());
  enterRule(_localctx, 108, PurrscalParser::RuleChirp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(463);
    demand();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MeowMewContext ------------------------------------------------------------------

PurrscalParser::MeowMewContext::MeowMewContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PurrscalParser::MeowMewContext::MEOW() {
  return getToken(PurrscalParser::MEOW, 0);
}

PurrscalParser::MeowsContext* PurrscalParser::MeowMewContext::meows() {
  return getRuleContext<PurrscalParser::MeowsContext>(0);
}


size_t PurrscalParser::MeowMewContext::getRuleIndex() const {
  return PurrscalParser::RuleMeowMew;
}


antlrcpp::Any PurrscalParser::MeowMewContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitMeowMew(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::MeowMewContext* PurrscalParser::meowMew() {
  MeowMewContext *_localctx = _tracker.createInstance<MeowMewContext>(_ctx, getState());
  enterRule(_localctx, 110, PurrscalParser::RuleMeowMew);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(465);
    match(PurrscalParser::MEOW);
    setState(466);
    meows();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MrrrMewContext ------------------------------------------------------------------

PurrscalParser::MrrrMewContext::MrrrMewContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PurrscalParser::MrrrMewContext::MRRR() {
  return getToken(PurrscalParser::MRRR, 0);
}

PurrscalParser::MeowsContext* PurrscalParser::MrrrMewContext::meows() {
  return getRuleContext<PurrscalParser::MeowsContext>(0);
}


size_t PurrscalParser::MrrrMewContext::getRuleIndex() const {
  return PurrscalParser::RuleMrrrMew;
}


antlrcpp::Any PurrscalParser::MrrrMewContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitMrrrMew(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::MrrrMewContext* PurrscalParser::mrrrMew() {
  MrrrMewContext *_localctx = _tracker.createInstance<MrrrMewContext>(_ctx, getState());
  enterRule(_localctx, 112, PurrscalParser::RuleMrrrMew);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(468);
    match(PurrscalParser::MRRR);
    setState(470);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PurrscalParser::T__0) {
      setState(469);
      meows();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MeowsContext ------------------------------------------------------------------

PurrscalParser::MeowsContext::MeowsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PurrscalParser::MeowContext *> PurrscalParser::MeowsContext::meow() {
  return getRuleContexts<PurrscalParser::MeowContext>();
}

PurrscalParser::MeowContext* PurrscalParser::MeowsContext::meow(size_t i) {
  return getRuleContext<PurrscalParser::MeowContext>(i);
}


size_t PurrscalParser::MeowsContext::getRuleIndex() const {
  return PurrscalParser::RuleMeows;
}


antlrcpp::Any PurrscalParser::MeowsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitMeows(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::MeowsContext* PurrscalParser::meows() {
  MeowsContext *_localctx = _tracker.createInstance<MeowsContext>(_ctx, getState());
  enterRule(_localctx, 114, PurrscalParser::RuleMeows);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(472);
    match(PurrscalParser::T__0);
    setState(473);
    meow();
    setState(478);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PurrscalParser::T__1) {
      setState(474);
      match(PurrscalParser::T__1);
      setState(475);
      meow();
      setState(480);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(481);
    match(PurrscalParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MeowContext ------------------------------------------------------------------

PurrscalParser::MeowContext::MeowContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PurrscalParser::DemandContext* PurrscalParser::MeowContext::demand() {
  return getRuleContext<PurrscalParser::DemandContext>(0);
}

PurrscalParser::ChungusWidthContext* PurrscalParser::MeowContext::chungusWidth() {
  return getRuleContext<PurrscalParser::ChungusWidthContext>(0);
}


size_t PurrscalParser::MeowContext::getRuleIndex() const {
  return PurrscalParser::RuleMeow;
}


antlrcpp::Any PurrscalParser::MeowContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitMeow(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::MeowContext* PurrscalParser::meow() {
  MeowContext *_localctx = _tracker.createInstance<MeowContext>(_ctx, getState());
  enterRule(_localctx, 116, PurrscalParser::RuleMeow);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(483);
    demand();
    setState(486);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PurrscalParser::T__7) {
      setState(484);
      match(PurrscalParser::T__7);
      setState(485);
      chungusWidth();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ChungusWidthContext ------------------------------------------------------------------

PurrscalParser::ChungusWidthContext::ChungusWidthContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PurrscalParser::SphynxDomesticContext* PurrscalParser::ChungusWidthContext::sphynxDomestic() {
  return getRuleContext<PurrscalParser::SphynxDomesticContext>(0);
}

PurrscalParser::FurContext* PurrscalParser::ChungusWidthContext::fur() {
  return getRuleContext<PurrscalParser::FurContext>(0);
}

PurrscalParser::ToeBeanPlacesContext* PurrscalParser::ChungusWidthContext::toeBeanPlaces() {
  return getRuleContext<PurrscalParser::ToeBeanPlacesContext>(0);
}


size_t PurrscalParser::ChungusWidthContext::getRuleIndex() const {
  return PurrscalParser::RuleChungusWidth;
}


antlrcpp::Any PurrscalParser::ChungusWidthContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitChungusWidth(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::ChungusWidthContext* PurrscalParser::chungusWidth() {
  ChungusWidthContext *_localctx = _tracker.createInstance<ChungusWidthContext>(_ctx, getState());
  enterRule(_localctx, 118, PurrscalParser::RuleChungusWidth);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(489);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PurrscalParser::T__9

    || _la == PurrscalParser::T__10) {
      setState(488);
      fur();
    }
    setState(491);
    sphynxDomestic();
    setState(494);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PurrscalParser::T__7) {
      setState(492);
      match(PurrscalParser::T__7);
      setState(493);
      toeBeanPlaces();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ToeBeanPlacesContext ------------------------------------------------------------------

PurrscalParser::ToeBeanPlacesContext::ToeBeanPlacesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PurrscalParser::SphynxDomesticContext* PurrscalParser::ToeBeanPlacesContext::sphynxDomestic() {
  return getRuleContext<PurrscalParser::SphynxDomesticContext>(0);
}


size_t PurrscalParser::ToeBeanPlacesContext::getRuleIndex() const {
  return PurrscalParser::RuleToeBeanPlaces;
}


antlrcpp::Any PurrscalParser::ToeBeanPlacesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitToeBeanPlaces(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::ToeBeanPlacesContext* PurrscalParser::toeBeanPlaces() {
  ToeBeanPlacesContext *_localctx = _tracker.createInstance<ToeBeanPlacesContext>(_ctx, getState());
  enterRule(_localctx, 120, PurrscalParser::RuleToeBeanPlaces);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(496);
    sphynxDomestic();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StalkMewContext ------------------------------------------------------------------

PurrscalParser::StalkMewContext::StalkMewContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PurrscalParser::StalkMewContext::STALK() {
  return getToken(PurrscalParser::STALK, 0);
}

PurrscalParser::MrowusContext* PurrscalParser::StalkMewContext::mrowus() {
  return getRuleContext<PurrscalParser::MrowusContext>(0);
}


size_t PurrscalParser::StalkMewContext::getRuleIndex() const {
  return PurrscalParser::RuleStalkMew;
}


antlrcpp::Any PurrscalParser::StalkMewContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitStalkMew(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::StalkMewContext* PurrscalParser::stalkMew() {
  StalkMewContext *_localctx = _tracker.createInstance<StalkMewContext>(_ctx, getState());
  enterRule(_localctx, 122, PurrscalParser::RuleStalkMew);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(498);
    match(PurrscalParser::STALK);
    setState(499);
    mrowus();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PounceMewContext ------------------------------------------------------------------

PurrscalParser::PounceMewContext::PounceMewContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PurrscalParser::PounceMewContext::POUNCE() {
  return getToken(PurrscalParser::POUNCE, 0);
}

PurrscalParser::MrowusContext* PurrscalParser::PounceMewContext::mrowus() {
  return getRuleContext<PurrscalParser::MrowusContext>(0);
}


size_t PurrscalParser::PounceMewContext::getRuleIndex() const {
  return PurrscalParser::RulePounceMew;
}


antlrcpp::Any PurrscalParser::PounceMewContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitPounceMew(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::PounceMewContext* PurrscalParser::pounceMew() {
  PounceMewContext *_localctx = _tracker.createInstance<PounceMewContext>(_ctx, getState());
  enterRule(_localctx, 124, PurrscalParser::RulePounceMew);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(501);
    match(PurrscalParser::POUNCE);
    setState(502);
    mrowus();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MrowusContext ------------------------------------------------------------------

PurrscalParser::MrowusContext::MrowusContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PurrscalParser::KittenContext *> PurrscalParser::MrowusContext::kitten() {
  return getRuleContexts<PurrscalParser::KittenContext>();
}

PurrscalParser::KittenContext* PurrscalParser::MrowusContext::kitten(size_t i) {
  return getRuleContext<PurrscalParser::KittenContext>(i);
}


size_t PurrscalParser::MrowusContext::getRuleIndex() const {
  return PurrscalParser::RuleMrowus;
}


antlrcpp::Any PurrscalParser::MrowusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitMrowus(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::MrowusContext* PurrscalParser::mrowus() {
  MrowusContext *_localctx = _tracker.createInstance<MrowusContext>(_ctx, getState());
  enterRule(_localctx, 126, PurrscalParser::RuleMrowus);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(504);
    match(PurrscalParser::T__0);
    setState(505);
    kitten();
    setState(510);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PurrscalParser::T__1) {
      setState(506);
      match(PurrscalParser::T__1);
      setState(507);
      kitten();
      setState(512);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(513);
    match(PurrscalParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DemandContext ------------------------------------------------------------------

PurrscalParser::DemandContext::DemandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PurrscalParser::ChonkDemandContext *> PurrscalParser::DemandContext::chonkDemand() {
  return getRuleContexts<PurrscalParser::ChonkDemandContext>();
}

PurrscalParser::ChonkDemandContext* PurrscalParser::DemandContext::chonkDemand(size_t i) {
  return getRuleContext<PurrscalParser::ChonkDemandContext>(i);
}

PurrscalParser::RelationalWhiskerContext* PurrscalParser::DemandContext::relationalWhisker() {
  return getRuleContext<PurrscalParser::RelationalWhiskerContext>(0);
}


size_t PurrscalParser::DemandContext::getRuleIndex() const {
  return PurrscalParser::RuleDemand;
}


antlrcpp::Any PurrscalParser::DemandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitDemand(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::DemandContext* PurrscalParser::demand() {
  DemandContext *_localctx = _tracker.createInstance<DemandContext>(_ctx, getState());
  enterRule(_localctx, 128, PurrscalParser::RuleDemand);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(515);
    chonkDemand();
    setState(519);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PurrscalParser::T__3)
      | (1ULL << PurrscalParser::T__11)
      | (1ULL << PurrscalParser::T__12)
      | (1ULL << PurrscalParser::T__13)
      | (1ULL << PurrscalParser::T__14)
      | (1ULL << PurrscalParser::T__15))) != 0)) {
      setState(516);
      relationalWhisker();
      setState(517);
      chonkDemand();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ChonkDemandContext ------------------------------------------------------------------

PurrscalParser::ChonkDemandContext::ChonkDemandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PurrscalParser::TrillContext *> PurrscalParser::ChonkDemandContext::trill() {
  return getRuleContexts<PurrscalParser::TrillContext>();
}

PurrscalParser::TrillContext* PurrscalParser::ChonkDemandContext::trill(size_t i) {
  return getRuleContext<PurrscalParser::TrillContext>(i);
}

PurrscalParser::FurContext* PurrscalParser::ChonkDemandContext::fur() {
  return getRuleContext<PurrscalParser::FurContext>(0);
}

std::vector<PurrscalParser::AdditiveWhiskerContext *> PurrscalParser::ChonkDemandContext::additiveWhisker() {
  return getRuleContexts<PurrscalParser::AdditiveWhiskerContext>();
}

PurrscalParser::AdditiveWhiskerContext* PurrscalParser::ChonkDemandContext::additiveWhisker(size_t i) {
  return getRuleContext<PurrscalParser::AdditiveWhiskerContext>(i);
}


size_t PurrscalParser::ChonkDemandContext::getRuleIndex() const {
  return PurrscalParser::RuleChonkDemand;
}


antlrcpp::Any PurrscalParser::ChonkDemandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitChonkDemand(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::ChonkDemandContext* PurrscalParser::chonkDemand() {
  ChonkDemandContext *_localctx = _tracker.createInstance<ChonkDemandContext>(_ctx, getState());
  enterRule(_localctx, 130, PurrscalParser::RuleChonkDemand);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(522);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      setState(521);
      fur();
      break;
    }

    }
    setState(524);
    trill();
    setState(530);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PurrscalParser::T__9

    || _la == PurrscalParser::T__10) {
      setState(525);
      additiveWhisker();
      setState(526);
      trill();
      setState(532);
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

//----------------- TrillContext ------------------------------------------------------------------

PurrscalParser::TrillContext::TrillContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PurrscalParser::ExpectationContext *> PurrscalParser::TrillContext::expectation() {
  return getRuleContexts<PurrscalParser::ExpectationContext>();
}

PurrscalParser::ExpectationContext* PurrscalParser::TrillContext::expectation(size_t i) {
  return getRuleContext<PurrscalParser::ExpectationContext>(i);
}

std::vector<PurrscalParser::MultiplicativeWhiskerContext *> PurrscalParser::TrillContext::multiplicativeWhisker() {
  return getRuleContexts<PurrscalParser::MultiplicativeWhiskerContext>();
}

PurrscalParser::MultiplicativeWhiskerContext* PurrscalParser::TrillContext::multiplicativeWhisker(size_t i) {
  return getRuleContext<PurrscalParser::MultiplicativeWhiskerContext>(i);
}


size_t PurrscalParser::TrillContext::getRuleIndex() const {
  return PurrscalParser::RuleTrill;
}


antlrcpp::Any PurrscalParser::TrillContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitTrill(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::TrillContext* PurrscalParser::trill() {
  TrillContext *_localctx = _tracker.createInstance<TrillContext>(_ctx, getState());
  enterRule(_localctx, 132, PurrscalParser::RuleTrill);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(533);
    expectation();
    setState(539);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PurrscalParser::T__16

    || _la == PurrscalParser::T__17) {
      setState(534);
      multiplicativeWhisker();
      setState(535);
      expectation();
      setState(541);
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

//----------------- ExpectationContext ------------------------------------------------------------------

PurrscalParser::ExpectationContext::ExpectationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PurrscalParser::ExpectationContext::getRuleIndex() const {
  return PurrscalParser::RuleExpectation;
}

void PurrscalParser::ExpectationContext::copyFrom(ExpectationContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->type = ctx->type;
}

//----------------- BlepCallExpectationContext ------------------------------------------------------------------

PurrscalParser::BlepCallContext* PurrscalParser::BlepCallExpectationContext::blepCall() {
  return getRuleContext<PurrscalParser::BlepCallContext>(0);
}

PurrscalParser::BlepCallExpectationContext::BlepCallExpectationContext(ExpectationContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PurrscalParser::BlepCallExpectationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitBlepCallExpectation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- KittenExpectationContext ------------------------------------------------------------------

PurrscalParser::KittenContext* PurrscalParser::KittenExpectationContext::kitten() {
  return getRuleContext<PurrscalParser::KittenContext>(0);
}

PurrscalParser::KittenExpectationContext::KittenExpectationContext(ExpectationContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PurrscalParser::KittenExpectationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitKittenExpectation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesizedExpectationContext ------------------------------------------------------------------

PurrscalParser::DemandContext* PurrscalParser::ParenthesizedExpectationContext::demand() {
  return getRuleContext<PurrscalParser::DemandContext>(0);
}

PurrscalParser::ParenthesizedExpectationContext::ParenthesizedExpectationContext(ExpectationContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PurrscalParser::ParenthesizedExpectationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitParenthesizedExpectation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- YarnExpectationContext ------------------------------------------------------------------

PurrscalParser::YarnBallContext* PurrscalParser::YarnExpectationContext::yarnBall() {
  return getRuleContext<PurrscalParser::YarnBallContext>(0);
}

PurrscalParser::YarnExpectationContext::YarnExpectationContext(ExpectationContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PurrscalParser::YarnExpectationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitYarnExpectation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RollExpectationContext ------------------------------------------------------------------

tree::TerminalNode* PurrscalParser::RollExpectationContext::ROLL() {
  return getToken(PurrscalParser::ROLL, 0);
}

PurrscalParser::ExpectationContext* PurrscalParser::RollExpectationContext::expectation() {
  return getRuleContext<PurrscalParser::ExpectationContext>(0);
}

PurrscalParser::RollExpectationContext::RollExpectationContext(ExpectationContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PurrscalParser::RollExpectationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitRollExpectation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ThreadExpectationContext ------------------------------------------------------------------

PurrscalParser::ThreadBallContext* PurrscalParser::ThreadExpectationContext::threadBall() {
  return getRuleContext<PurrscalParser::ThreadBallContext>(0);
}

PurrscalParser::ThreadExpectationContext::ThreadExpectationContext(ExpectationContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PurrscalParser::ThreadExpectationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitThreadExpectation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FelineExpectationContext ------------------------------------------------------------------

PurrscalParser::FelineContext* PurrscalParser::FelineExpectationContext::feline() {
  return getRuleContext<PurrscalParser::FelineContext>(0);
}

PurrscalParser::FelineExpectationContext::FelineExpectationContext(ExpectationContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PurrscalParser::FelineExpectationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitFelineExpectation(this);
  else
    return visitor->visitChildren(this);
}
PurrscalParser::ExpectationContext* PurrscalParser::expectation() {
  ExpectationContext *_localctx = _tracker.createInstance<ExpectationContext>(_ctx, getState());
  enterRule(_localctx, 134, PurrscalParser::RuleExpectation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(553);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<ExpectationContext *>(_tracker.createInstance<PurrscalParser::KittenExpectationContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(542);
      kitten();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<ExpectationContext *>(_tracker.createInstance<PurrscalParser::FelineExpectationContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(543);
      feline();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<ExpectationContext *>(_tracker.createInstance<PurrscalParser::ThreadExpectationContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(544);
      threadBall();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<ExpectationContext *>(_tracker.createInstance<PurrscalParser::YarnExpectationContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(545);
      yarnBall();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<ExpectationContext *>(_tracker.createInstance<PurrscalParser::BlepCallExpectationContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(546);
      blepCall();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<ExpectationContext *>(_tracker.createInstance<PurrscalParser::RollExpectationContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(547);
      match(PurrscalParser::ROLL);
      setState(548);
      expectation();
      break;
    }

    case 7: {
      _localctx = dynamic_cast<ExpectationContext *>(_tracker.createInstance<PurrscalParser::ParenthesizedExpectationContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(549);
      match(PurrscalParser::T__0);
      setState(550);
      demand();
      setState(551);
      match(PurrscalParser::T__2);
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

//----------------- KittenContext ------------------------------------------------------------------

PurrscalParser::KittenContext::KittenContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PurrscalParser::KittenKittyContext* PurrscalParser::KittenContext::kittenKitty() {
  return getRuleContext<PurrscalParser::KittenKittyContext>(0);
}

std::vector<PurrscalParser::ModifierContext *> PurrscalParser::KittenContext::modifier() {
  return getRuleContexts<PurrscalParser::ModifierContext>();
}

PurrscalParser::ModifierContext* PurrscalParser::KittenContext::modifier(size_t i) {
  return getRuleContext<PurrscalParser::ModifierContext>(i);
}


size_t PurrscalParser::KittenContext::getRuleIndex() const {
  return PurrscalParser::RuleKitten;
}


antlrcpp::Any PurrscalParser::KittenContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitKitten(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::KittenContext* PurrscalParser::kitten() {
  KittenContext *_localctx = _tracker.createInstance<KittenContext>(_ctx, getState());
  enterRule(_localctx, 136, PurrscalParser::RuleKitten);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(555);
    kittenKitty();
    setState(559);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PurrscalParser::T__5

    || _la == PurrscalParser::T__8) {
      setState(556);
      modifier();
      setState(561);
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

//----------------- ModifierContext ------------------------------------------------------------------

PurrscalParser::ModifierContext::ModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PurrscalParser::IndicesContext* PurrscalParser::ModifierContext::indices() {
  return getRuleContext<PurrscalParser::IndicesContext>(0);
}

PurrscalParser::ChungusContext* PurrscalParser::ModifierContext::chungus() {
  return getRuleContext<PurrscalParser::ChungusContext>(0);
}


size_t PurrscalParser::ModifierContext::getRuleIndex() const {
  return PurrscalParser::RuleModifier;
}


antlrcpp::Any PurrscalParser::ModifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitModifier(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::ModifierContext* PurrscalParser::modifier() {
  ModifierContext *_localctx = _tracker.createInstance<ModifierContext>(_ctx, getState());
  enterRule(_localctx, 138, PurrscalParser::RuleModifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(568);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PurrscalParser::T__5: {
        enterOuterAlt(_localctx, 1);
        setState(562);
        match(PurrscalParser::T__5);
        setState(563);
        indices();
        setState(564);
        match(PurrscalParser::T__6);
        break;
      }

      case PurrscalParser::T__8: {
        enterOuterAlt(_localctx, 2);
        setState(566);
        match(PurrscalParser::T__8);
        setState(567);
        chungus();
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

//----------------- IndicesContext ------------------------------------------------------------------

PurrscalParser::IndicesContext::IndicesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PurrscalParser::IndexContext *> PurrscalParser::IndicesContext::index() {
  return getRuleContexts<PurrscalParser::IndexContext>();
}

PurrscalParser::IndexContext* PurrscalParser::IndicesContext::index(size_t i) {
  return getRuleContext<PurrscalParser::IndexContext>(i);
}


size_t PurrscalParser::IndicesContext::getRuleIndex() const {
  return PurrscalParser::RuleIndices;
}


antlrcpp::Any PurrscalParser::IndicesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitIndices(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::IndicesContext* PurrscalParser::indices() {
  IndicesContext *_localctx = _tracker.createInstance<IndicesContext>(_ctx, getState());
  enterRule(_localctx, 140, PurrscalParser::RuleIndices);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(570);
    index();
    setState(575);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PurrscalParser::T__1) {
      setState(571);
      match(PurrscalParser::T__1);
      setState(572);
      index();
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

//----------------- IndexContext ------------------------------------------------------------------

PurrscalParser::IndexContext::IndexContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PurrscalParser::DemandContext* PurrscalParser::IndexContext::demand() {
  return getRuleContext<PurrscalParser::DemandContext>(0);
}


size_t PurrscalParser::IndexContext::getRuleIndex() const {
  return PurrscalParser::RuleIndex;
}


antlrcpp::Any PurrscalParser::IndexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitIndex(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::IndexContext* PurrscalParser::index() {
  IndexContext *_localctx = _tracker.createInstance<IndexContext>(_ctx, getState());
  enterRule(_localctx, 142, PurrscalParser::RuleIndex);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(578);
    demand();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ChungusContext ------------------------------------------------------------------

PurrscalParser::ChungusContext::ChungusContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PurrscalParser::ChungusContext::KITTY() {
  return getToken(PurrscalParser::KITTY, 0);
}


size_t PurrscalParser::ChungusContext::getRuleIndex() const {
  return PurrscalParser::RuleChungus;
}


antlrcpp::Any PurrscalParser::ChungusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitChungus(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::ChungusContext* PurrscalParser::chungus() {
  ChungusContext *_localctx = _tracker.createInstance<ChungusContext>(_ctx, getState());
  enterRule(_localctx, 144, PurrscalParser::RuleChungus);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(580);
    match(PurrscalParser::KITTY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FurContext ------------------------------------------------------------------

PurrscalParser::FurContext::FurContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PurrscalParser::FurContext::getRuleIndex() const {
  return PurrscalParser::RuleFur;
}


antlrcpp::Any PurrscalParser::FurContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitFur(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::FurContext* PurrscalParser::fur() {
  FurContext *_localctx = _tracker.createInstance<FurContext>(_ctx, getState());
  enterRule(_localctx, 146, PurrscalParser::RuleFur);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(582);
    _la = _input->LA(1);
    if (!(_la == PurrscalParser::T__9

    || _la == PurrscalParser::T__10)) {
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

//----------------- FelineContext ------------------------------------------------------------------

PurrscalParser::FelineContext::FelineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PurrscalParser::HairlessFelineContext* PurrscalParser::FelineContext::hairlessFeline() {
  return getRuleContext<PurrscalParser::HairlessFelineContext>(0);
}

PurrscalParser::FurContext* PurrscalParser::FelineContext::fur() {
  return getRuleContext<PurrscalParser::FurContext>(0);
}


size_t PurrscalParser::FelineContext::getRuleIndex() const {
  return PurrscalParser::RuleFeline;
}


antlrcpp::Any PurrscalParser::FelineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitFeline(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::FelineContext* PurrscalParser::feline() {
  FelineContext *_localctx = _tracker.createInstance<FelineContext>(_ctx, getState());
  enterRule(_localctx, 148, PurrscalParser::RuleFeline);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(585);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PurrscalParser::T__9

    || _la == PurrscalParser::T__10) {
      setState(584);
      fur();
    }
    setState(587);
    hairlessFeline();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- HairlessFelineContext ------------------------------------------------------------------

PurrscalParser::HairlessFelineContext::HairlessFelineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PurrscalParser::SphynxDomesticContext* PurrscalParser::HairlessFelineContext::sphynxDomestic() {
  return getRuleContext<PurrscalParser::SphynxDomesticContext>(0);
}

PurrscalParser::HairlessFelineDomesticContext* PurrscalParser::HairlessFelineContext::hairlessFelineDomestic() {
  return getRuleContext<PurrscalParser::HairlessFelineDomesticContext>(0);
}


size_t PurrscalParser::HairlessFelineContext::getRuleIndex() const {
  return PurrscalParser::RuleHairlessFeline;
}


antlrcpp::Any PurrscalParser::HairlessFelineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitHairlessFeline(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::HairlessFelineContext* PurrscalParser::hairlessFeline() {
  HairlessFelineContext *_localctx = _tracker.createInstance<HairlessFelineContext>(_ctx, getState());
  enterRule(_localctx, 150, PurrscalParser::RuleHairlessFeline);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(591);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PurrscalParser::SPHYNX: {
        enterOuterAlt(_localctx, 1);
        setState(589);
        sphynxDomestic();
        break;
      }

      case PurrscalParser::HAIRLESS_FELINE: {
        enterOuterAlt(_localctx, 2);
        setState(590);
        hairlessFelineDomestic();
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

//----------------- SphynxDomesticContext ------------------------------------------------------------------

PurrscalParser::SphynxDomesticContext::SphynxDomesticContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PurrscalParser::SphynxDomesticContext::SPHYNX() {
  return getToken(PurrscalParser::SPHYNX, 0);
}


size_t PurrscalParser::SphynxDomesticContext::getRuleIndex() const {
  return PurrscalParser::RuleSphynxDomestic;
}


antlrcpp::Any PurrscalParser::SphynxDomesticContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitSphynxDomestic(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::SphynxDomesticContext* PurrscalParser::sphynxDomestic() {
  SphynxDomesticContext *_localctx = _tracker.createInstance<SphynxDomesticContext>(_ctx, getState());
  enterRule(_localctx, 152, PurrscalParser::RuleSphynxDomestic);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(593);
    match(PurrscalParser::SPHYNX);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- HairlessFelineDomesticContext ------------------------------------------------------------------

PurrscalParser::HairlessFelineDomesticContext::HairlessFelineDomesticContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PurrscalParser::HairlessFelineDomesticContext::HAIRLESS_FELINE() {
  return getToken(PurrscalParser::HAIRLESS_FELINE, 0);
}


size_t PurrscalParser::HairlessFelineDomesticContext::getRuleIndex() const {
  return PurrscalParser::RuleHairlessFelineDomestic;
}


antlrcpp::Any PurrscalParser::HairlessFelineDomesticContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitHairlessFelineDomestic(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::HairlessFelineDomesticContext* PurrscalParser::hairlessFelineDomestic() {
  HairlessFelineDomesticContext *_localctx = _tracker.createInstance<HairlessFelineDomesticContext>(_ctx, getState());
  enterRule(_localctx, 154, PurrscalParser::RuleHairlessFelineDomestic);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(595);
    match(PurrscalParser::HAIRLESS_FELINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ThreadBallContext ------------------------------------------------------------------

PurrscalParser::ThreadBallContext::ThreadBallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PurrscalParser::ThreadBallContext::THREAD() {
  return getToken(PurrscalParser::THREAD, 0);
}


size_t PurrscalParser::ThreadBallContext::getRuleIndex() const {
  return PurrscalParser::RuleThreadBall;
}


antlrcpp::Any PurrscalParser::ThreadBallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitThreadBall(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::ThreadBallContext* PurrscalParser::threadBall() {
  ThreadBallContext *_localctx = _tracker.createInstance<ThreadBallContext>(_ctx, getState());
  enterRule(_localctx, 156, PurrscalParser::RuleThreadBall);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(597);
    match(PurrscalParser::THREAD);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- YarnBallContext ------------------------------------------------------------------

PurrscalParser::YarnBallContext::YarnBallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PurrscalParser::YarnBallContext::YARN() {
  return getToken(PurrscalParser::YARN, 0);
}


size_t PurrscalParser::YarnBallContext::getRuleIndex() const {
  return PurrscalParser::RuleYarnBall;
}


antlrcpp::Any PurrscalParser::YarnBallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitYarnBall(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::YarnBallContext* PurrscalParser::yarnBall() {
  YarnBallContext *_localctx = _tracker.createInstance<YarnBallContext>(_ctx, getState());
  enterRule(_localctx, 158, PurrscalParser::RuleYarnBall);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(599);
    match(PurrscalParser::YARN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationalWhiskerContext ------------------------------------------------------------------

PurrscalParser::RelationalWhiskerContext::RelationalWhiskerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PurrscalParser::RelationalWhiskerContext::getRuleIndex() const {
  return PurrscalParser::RuleRelationalWhisker;
}


antlrcpp::Any PurrscalParser::RelationalWhiskerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitRelationalWhisker(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::RelationalWhiskerContext* PurrscalParser::relationalWhisker() {
  RelationalWhiskerContext *_localctx = _tracker.createInstance<RelationalWhiskerContext>(_ctx, getState());
  enterRule(_localctx, 160, PurrscalParser::RuleRelationalWhisker);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(601);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PurrscalParser::T__3)
      | (1ULL << PurrscalParser::T__11)
      | (1ULL << PurrscalParser::T__12)
      | (1ULL << PurrscalParser::T__13)
      | (1ULL << PurrscalParser::T__14)
      | (1ULL << PurrscalParser::T__15))) != 0))) {
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

//----------------- AdditiveWhiskerContext ------------------------------------------------------------------

PurrscalParser::AdditiveWhiskerContext::AdditiveWhiskerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PurrscalParser::AdditiveWhiskerContext::getRuleIndex() const {
  return PurrscalParser::RuleAdditiveWhisker;
}


antlrcpp::Any PurrscalParser::AdditiveWhiskerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitAdditiveWhisker(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::AdditiveWhiskerContext* PurrscalParser::additiveWhisker() {
  AdditiveWhiskerContext *_localctx = _tracker.createInstance<AdditiveWhiskerContext>(_ctx, getState());
  enterRule(_localctx, 162, PurrscalParser::RuleAdditiveWhisker);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(603);
    _la = _input->LA(1);
    if (!(_la == PurrscalParser::T__9

    || _la == PurrscalParser::T__10)) {
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

//----------------- MultiplicativeWhiskerContext ------------------------------------------------------------------

PurrscalParser::MultiplicativeWhiskerContext::MultiplicativeWhiskerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PurrscalParser::MultiplicativeWhiskerContext::getRuleIndex() const {
  return PurrscalParser::RuleMultiplicativeWhisker;
}


antlrcpp::Any PurrscalParser::MultiplicativeWhiskerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PurrscalVisitor*>(visitor))
    return parserVisitor->visitMultiplicativeWhisker(this);
  else
    return visitor->visitChildren(this);
}

PurrscalParser::MultiplicativeWhiskerContext* PurrscalParser::multiplicativeWhisker() {
  MultiplicativeWhiskerContext *_localctx = _tracker.createInstance<MultiplicativeWhiskerContext>(_ctx, getState());
  enterRule(_localctx, 164, PurrscalParser::RuleMultiplicativeWhisker);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(605);
    _la = _input->LA(1);
    if (!(_la == PurrscalParser::T__16

    || _la == PurrscalParser::T__17)) {
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

// Static vars and initialization.
std::vector<dfa::DFA> PurrscalParser::_decisionToDFA;
atn::PredictionContextCache PurrscalParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN PurrscalParser::_atn;
std::vector<uint16_t> PurrscalParser::_serializedATN;

std::vector<std::string> PurrscalParser::_ruleNames = {
  "purrgram", "purrgramSnoot", "purrgramPurrameters", "purrgramKitty", "cat", 
  "catQualities", "domesticQuality", "domesticBodies", "domesticBody", "domesticKitty", 
  "domestic", "breedQuality", "breedBodies", "breedBody", "kittyBreed", 
  "breed", "chonk", "fluffball", "fluffballDomestic", "kittenKaboodle", 
  "kaboodle", "chonks", "kittenQuality", "kittenBodies", "kittenBody", "kittenKitties", 
  "kittenKitty", "callQuality", "callBody", "yowlSnoot", "blepSnoot", "callKitty", 
  "purrameters", "purrameterPurrs", "purrameterPurr", "purrameterKitties", 
  "purrameterKitty", "mew", "mews", "theBigMew", "blankStare", "hungryMew", 
  "lps", "rps", "sniffMew", "pawMew", "ignoreMew", "howlMew", "purrMew", 
  "blepCall", "blepName", "yowlCallMew", "yowlName", "chirps", "chirp", 
  "meowMew", "mrrrMew", "meows", "meow", "chungusWidth", "toeBeanPlaces", 
  "stalkMew", "pounceMew", "mrowus", "demand", "chonkDemand", "trill", "expectation", 
  "kitten", "modifier", "indices", "index", "chungus", "fur", "feline", 
  "hairlessFeline", "sphynxDomestic", "hairlessFelineDomestic", "threadBall", 
  "yarnBall", "relationalWhisker", "additiveWhisker", "multiplicativeWhisker"
};

std::vector<std::string> PurrscalParser::_literalNames = {
  "", "'('", "','", "')'", "'='", "'..'", "'['", "']'", "':'", "'.'", "'-'", 
  "'+'", "'!='", "'<'", "'<='", "'>'", "'>='", "'*'", "'/'", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "'''"
};

std::vector<std::string> PurrscalParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "PURRGRAM", "OWO", "UWU", "DOMESTIC", "BREED", "KITTEN", "YOWL", "BLEP", 
  "PLAY", "NAP", "KABOODLE", "SNIFF", "PAW", "IGNORE", "HOWL", "UNTIL", 
  "WHILE", "PURR", "ROLL", "MEOW", "MRRR", "STALK", "POUNCE", "KITTY", "SPHYNX", 
  "HAIRLESS_FELINE", "NEWLINE", "WS", "QUOTE", "THREAD", "YARN", "COMMENT"
};

dfa::Vocabulary PurrscalParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> PurrscalParser::_tokenNames;

PurrscalParser::Initializer::Initializer() {
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
    0x3, 0x34, 0x262, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
    0x53, 0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0xb0, 0xa, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0xb8, 
    0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0xbb, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x5, 0x7, 0xc7, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 
    0xcc, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0xd1, 0xa, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0xd6, 0xa, 0x7, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0xde, 0xa, 0x9, 
    0xc, 0x9, 0xe, 0x9, 0xe1, 0xb, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x5, 0xc, 0xea, 0xa, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x5, 0xc, 0xee, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xf2, 
    0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x7, 0xe, 0xfa, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0xfd, 0xb, 0xe, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x10a, 0xa, 0x12, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0x110, 0xa, 0x13, 
    0xc, 0x13, 0xe, 0x13, 0x113, 0xb, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 
    0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x7, 0x17, 0x126, 0xa, 0x17, 0xc, 0x17, 0xe, 0x17, 0x129, 
    0xb, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 
    0x19, 0x7, 0x19, 0x131, 0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 0x134, 0xb, 
    0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x7, 0x1b, 0x13d, 0xa, 0x1b, 0xc, 0x1b, 0xe, 0x1b, 0x140, 
    0xb, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x7, 
    0x1d, 0x147, 0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 0x14a, 0xb, 0x1d, 0x3, 
    0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x14e, 0xa, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x156, 0xa, 0x1f, 
    0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x15b, 0xa, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 
    0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x7, 0x23, 0x169, 
    0xa, 0x23, 0xc, 0x23, 0xe, 0x23, 0x16c, 0xb, 0x23, 0x3, 0x24, 0x5, 0x24, 
    0x16f, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 
    0x3, 0x25, 0x3, 0x25, 0x7, 0x25, 0x178, 0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 
    0x17b, 0xb, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
    0x27, 0x3, 0x27, 0x5, 0x27, 0x18a, 0xa, 0x27, 0x3, 0x28, 0x3, 0x28, 
    0x3, 0x28, 0x7, 0x28, 0x18f, 0xa, 0x28, 0xc, 0x28, 0xe, 0x28, 0x192, 
    0xb, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 
    0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 
    0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 
    0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x1a8, 0xa, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 
    0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 
    0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x33, 
    0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x1bb, 0xa, 0x33, 0x3, 0x33, 0x3, 0x33, 
    0x3, 0x34, 0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x5, 0x35, 0x1c4, 
    0xa, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 0x37, 0x3, 
    0x37, 0x3, 0x37, 0x7, 0x37, 0x1cd, 0xa, 0x37, 0xc, 0x37, 0xe, 0x37, 
    0x1d0, 0xb, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 
    0x3, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 0x1d9, 0xa, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 
    0x3, 0x3b, 0x3, 0x3b, 0x7, 0x3b, 0x1df, 0xa, 0x3b, 0xc, 0x3b, 0xe, 0x3b, 
    0x1e2, 0xb, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 
    0x5, 0x3c, 0x1e9, 0xa, 0x3c, 0x3, 0x3d, 0x5, 0x3d, 0x1ec, 0xa, 0x3d, 
    0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x5, 0x3d, 0x1f1, 0xa, 0x3d, 0x3, 0x3e, 
    0x3, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x3, 
    0x40, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x7, 0x41, 0x1ff, 
    0xa, 0x41, 0xc, 0x41, 0xe, 0x41, 0x202, 0xb, 0x41, 0x3, 0x41, 0x3, 0x41, 
    0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x5, 0x42, 0x20a, 0xa, 0x42, 
    0x3, 0x43, 0x5, 0x43, 0x20d, 0xa, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 
    0x3, 0x43, 0x7, 0x43, 0x213, 0xa, 0x43, 0xc, 0x43, 0xe, 0x43, 0x216, 
    0xb, 0x43, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x7, 0x44, 0x21c, 
    0xa, 0x44, 0xc, 0x44, 0xe, 0x44, 0x21f, 0xb, 0x44, 0x3, 0x45, 0x3, 0x45, 
    0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 
    0x45, 0x3, 0x45, 0x3, 0x45, 0x5, 0x45, 0x22c, 0xa, 0x45, 0x3, 0x46, 
    0x3, 0x46, 0x7, 0x46, 0x230, 0xa, 0x46, 0xc, 0x46, 0xe, 0x46, 0x233, 
    0xb, 0x46, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 
    0x47, 0x5, 0x47, 0x23b, 0xa, 0x47, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 
    0x7, 0x48, 0x240, 0xa, 0x48, 0xc, 0x48, 0xe, 0x48, 0x243, 0xb, 0x48, 
    0x3, 0x49, 0x3, 0x49, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4b, 0x3, 0x4b, 0x3, 
    0x4c, 0x5, 0x4c, 0x24c, 0xa, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4d, 
    0x3, 0x4d, 0x5, 0x4d, 0x252, 0xa, 0x4d, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4f, 
    0x3, 0x4f, 0x3, 0x50, 0x3, 0x50, 0x3, 0x51, 0x3, 0x51, 0x3, 0x52, 0x3, 
    0x52, 0x3, 0x53, 0x3, 0x53, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x2, 0x2, 
    0x55, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 
    0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 
    0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 
    0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 
    0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 
    0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 
    0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9e, 0xa0, 0xa2, 0xa4, 0xa6, 0x2, 
    0x5, 0x3, 0x2, 0xc, 0xd, 0x4, 0x2, 0x6, 0x6, 0xe, 0x12, 0x3, 0x2, 0x13, 
    0x14, 0x2, 0x24b, 0x2, 0xa8, 0x3, 0x2, 0x2, 0x2, 0x4, 0xac, 0x3, 0x2, 
    0x2, 0x2, 0x6, 0xb3, 0x3, 0x2, 0x2, 0x2, 0x8, 0xbe, 0x3, 0x2, 0x2, 0x2, 
    0xa, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xe, 0xd7, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0xda, 0x3, 0x2, 0x2, 0x2, 0x12, 0xe2, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0xe6, 0x3, 0x2, 0x2, 0x2, 0x16, 0xf1, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0xf3, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xf6, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x102, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x104, 0x3, 0x2, 0x2, 0x2, 0x22, 0x109, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0x10b, 0x3, 0x2, 0x2, 0x2, 0x26, 0x116, 0x3, 0x2, 0x2, 0x2, 0x28, 0x118, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x122, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x30, 0x12d, 0x3, 0x2, 
    0x2, 0x2, 0x32, 0x135, 0x3, 0x2, 0x2, 0x2, 0x34, 0x139, 0x3, 0x2, 0x2, 
    0x2, 0x36, 0x141, 0x3, 0x2, 0x2, 0x2, 0x38, 0x143, 0x3, 0x2, 0x2, 0x2, 
    0x3a, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x152, 0x3, 0x2, 0x2, 0x2, 0x3e, 
    0x157, 0x3, 0x2, 0x2, 0x2, 0x40, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x42, 0x161, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x165, 0x3, 0x2, 0x2, 0x2, 0x46, 0x16e, 0x3, 
    0x2, 0x2, 0x2, 0x48, 0x174, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x17c, 0x3, 0x2, 
    0x2, 0x2, 0x4c, 0x189, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x18b, 0x3, 0x2, 0x2, 
    0x2, 0x50, 0x193, 0x3, 0x2, 0x2, 0x2, 0x52, 0x197, 0x3, 0x2, 0x2, 0x2, 
    0x54, 0x199, 0x3, 0x2, 0x2, 0x2, 0x56, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x58, 
    0x19f, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x1a9, 
    0x3, 0x2, 0x2, 0x2, 0x5e, 0x1ab, 0x3, 0x2, 0x2, 0x2, 0x60, 0x1ad, 0x3, 
    0x2, 0x2, 0x2, 0x62, 0x1b2, 0x3, 0x2, 0x2, 0x2, 0x64, 0x1b7, 0x3, 0x2, 
    0x2, 0x2, 0x66, 0x1be, 0x3, 0x2, 0x2, 0x2, 0x68, 0x1c0, 0x3, 0x2, 0x2, 
    0x2, 0x6a, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x1c9, 0x3, 0x2, 0x2, 0x2, 
    0x6e, 0x1d1, 0x3, 0x2, 0x2, 0x2, 0x70, 0x1d3, 0x3, 0x2, 0x2, 0x2, 0x72, 
    0x1d6, 0x3, 0x2, 0x2, 0x2, 0x74, 0x1da, 0x3, 0x2, 0x2, 0x2, 0x76, 0x1e5, 
    0x3, 0x2, 0x2, 0x2, 0x78, 0x1eb, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x1f2, 0x3, 
    0x2, 0x2, 0x2, 0x7c, 0x1f4, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x1f7, 0x3, 0x2, 
    0x2, 0x2, 0x80, 0x1fa, 0x3, 0x2, 0x2, 0x2, 0x82, 0x205, 0x3, 0x2, 0x2, 
    0x2, 0x84, 0x20c, 0x3, 0x2, 0x2, 0x2, 0x86, 0x217, 0x3, 0x2, 0x2, 0x2, 
    0x88, 0x22b, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x22d, 0x3, 0x2, 0x2, 0x2, 0x8c, 
    0x23a, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x23c, 0x3, 0x2, 0x2, 0x2, 0x90, 0x244, 
    0x3, 0x2, 0x2, 0x2, 0x92, 0x246, 0x3, 0x2, 0x2, 0x2, 0x94, 0x248, 0x3, 
    0x2, 0x2, 0x2, 0x96, 0x24b, 0x3, 0x2, 0x2, 0x2, 0x98, 0x251, 0x3, 0x2, 
    0x2, 0x2, 0x9a, 0x253, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x255, 0x3, 0x2, 0x2, 
    0x2, 0x9e, 0x257, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x259, 0x3, 0x2, 0x2, 0x2, 
    0xa2, 0x25b, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x25d, 0x3, 0x2, 0x2, 0x2, 0xa6, 
    0x25f, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa9, 0x5, 0x4, 0x3, 0x2, 0xa9, 0xaa, 
    0x5, 0xa, 0x6, 0x2, 0xaa, 0xab, 0x7, 0x17, 0x2, 0x2, 0xab, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0xac, 0xad, 0x7, 0x15, 0x2, 0x2, 0xad, 0xaf, 0x5, 0x8, 
    0x5, 0x2, 0xae, 0xb0, 0x5, 0x6, 0x4, 0x2, 0xaf, 0xae, 0x3, 0x2, 0x2, 
    0x2, 0xaf, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 0x3, 0x2, 0x2, 0x2, 
    0xb1, 0xb2, 0x7, 0x16, 0x2, 0x2, 0xb2, 0x5, 0x3, 0x2, 0x2, 0x2, 0xb3, 
    0xb4, 0x7, 0x3, 0x2, 0x2, 0xb4, 0xb9, 0x7, 0x2c, 0x2, 0x2, 0xb5, 0xb6, 
    0x7, 0x4, 0x2, 0x2, 0xb6, 0xb8, 0x7, 0x2c, 0x2, 0x2, 0xb7, 0xb5, 0x3, 
    0x2, 0x2, 0x2, 0xb8, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xb7, 0x3, 0x2, 
    0x2, 0x2, 0xb9, 0xba, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbc, 0x3, 0x2, 0x2, 
    0x2, 0xbb, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x7, 0x5, 0x2, 0x2, 
    0xbd, 0x7, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbf, 0x7, 0x2c, 0x2, 0x2, 0xbf, 
    0x9, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc1, 0x5, 0xc, 0x7, 0x2, 0xc1, 0xc2, 
    0x5, 0x50, 0x29, 0x2, 0xc2, 0xb, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc4, 0x5, 
    0xe, 0x8, 0x2, 0xc4, 0xc5, 0x7, 0x16, 0x2, 0x2, 0xc5, 0xc7, 0x3, 0x2, 
    0x2, 0x2, 0xc6, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 0x3, 0x2, 0x2, 
    0x2, 0xc7, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 0x5, 0x18, 0xd, 0x2, 
    0xc9, 0xca, 0x7, 0x16, 0x2, 0x2, 0xca, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xcb, 
    0xc8, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xd0, 
    0x3, 0x2, 0x2, 0x2, 0xcd, 0xce, 0x5, 0x2e, 0x18, 0x2, 0xce, 0xcf, 0x7, 
    0x16, 0x2, 0x2, 0xcf, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xcd, 0x3, 0x2, 
    0x2, 0x2, 0xd0, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd5, 0x3, 0x2, 0x2, 
    0x2, 0xd2, 0xd3, 0x5, 0x38, 0x1d, 0x2, 0xd3, 0xd4, 0x7, 0x16, 0x2, 0x2, 
    0xd4, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd5, 
    0xd6, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd8, 
    0x7, 0x18, 0x2, 0x2, 0xd8, 0xd9, 0x5, 0x10, 0x9, 0x2, 0xd9, 0xf, 0x3, 
    0x2, 0x2, 0x2, 0xda, 0xdf, 0x5, 0x12, 0xa, 0x2, 0xdb, 0xdc, 0x7, 0x16, 
    0x2, 0x2, 0xdc, 0xde, 0x5, 0x12, 0xa, 0x2, 0xdd, 0xdb, 0x3, 0x2, 0x2, 
    0x2, 0xde, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xdd, 0x3, 0x2, 0x2, 0x2, 
    0xdf, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe0, 0x11, 0x3, 0x2, 0x2, 0x2, 0xe1, 
    0xdf, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe3, 0x5, 0x14, 0xb, 0x2, 0xe3, 0xe4, 
    0x7, 0x6, 0x2, 0x2, 0xe4, 0xe5, 0x5, 0x16, 0xc, 0x2, 0xe5, 0x13, 0x3, 
    0x2, 0x2, 0x2, 0xe6, 0xe7, 0x7, 0x2c, 0x2, 0x2, 0xe7, 0x15, 0x3, 0x2, 
    0x2, 0x2, 0xe8, 0xea, 0x5, 0x94, 0x4b, 0x2, 0xe9, 0xe8, 0x3, 0x2, 0x2, 
    0x2, 0xe9, 0xea, 0x3, 0x2, 0x2, 0x2, 0xea, 0xed, 0x3, 0x2, 0x2, 0x2, 
    0xeb, 0xee, 0x7, 0x2c, 0x2, 0x2, 0xec, 0xee, 0x5, 0x98, 0x4d, 0x2, 0xed, 
    0xeb, 0x3, 0x2, 0x2, 0x2, 0xed, 0xec, 0x3, 0x2, 0x2, 0x2, 0xee, 0xf2, 
    0x3, 0x2, 0x2, 0x2, 0xef, 0xf2, 0x5, 0x9e, 0x50, 0x2, 0xf0, 0xf2, 0x5, 
    0xa0, 0x51, 0x2, 0xf1, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xef, 0x3, 0x2, 
    0x2, 0x2, 0xf1, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf2, 0x17, 0x3, 0x2, 0x2, 
    0x2, 0xf3, 0xf4, 0x7, 0x19, 0x2, 0x2, 0xf4, 0xf5, 0x5, 0x1a, 0xe, 0x2, 
    0xf5, 0x19, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xfb, 0x5, 0x1c, 0xf, 0x2, 0xf7, 
    0xf8, 0x7, 0x16, 0x2, 0x2, 0xf8, 0xfa, 0x5, 0x1c, 0xf, 0x2, 0xf9, 0xf7, 
    0x3, 0x2, 0x2, 0x2, 0xfa, 0xfd, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xf9, 0x3, 
    0x2, 0x2, 0x2, 0xfb, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfc, 0x1b, 0x3, 0x2, 
    0x2, 0x2, 0xfd, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 0x5, 0x1e, 0x10, 
    0x2, 0xff, 0x100, 0x7, 0x6, 0x2, 0x2, 0x100, 0x101, 0x5, 0x20, 0x11, 
    0x2, 0x101, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x102, 0x103, 0x7, 0x2c, 0x2, 
    0x2, 0x103, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x104, 0x105, 0x5, 0x22, 0x12, 
    0x2, 0x105, 0x21, 0x3, 0x2, 0x2, 0x2, 0x106, 0x10a, 0x5, 0x1e, 0x10, 
    0x2, 0x107, 0x10a, 0x5, 0x24, 0x13, 0x2, 0x108, 0x10a, 0x5, 0x28, 0x15, 
    0x2, 0x109, 0x106, 0x3, 0x2, 0x2, 0x2, 0x109, 0x107, 0x3, 0x2, 0x2, 
    0x2, 0x109, 0x108, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x23, 0x3, 0x2, 0x2, 0x2, 
    0x10b, 0x10c, 0x7, 0x3, 0x2, 0x2, 0x10c, 0x111, 0x5, 0x26, 0x14, 0x2, 
    0x10d, 0x10e, 0x7, 0x4, 0x2, 0x2, 0x10e, 0x110, 0x5, 0x26, 0x14, 0x2, 
    0x10f, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x110, 0x113, 0x3, 0x2, 0x2, 0x2, 
    0x111, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x111, 0x112, 0x3, 0x2, 0x2, 0x2, 
    0x112, 0x114, 0x3, 0x2, 0x2, 0x2, 0x113, 0x111, 0x3, 0x2, 0x2, 0x2, 
    0x114, 0x115, 0x7, 0x5, 0x2, 0x2, 0x115, 0x25, 0x3, 0x2, 0x2, 0x2, 0x116, 
    0x117, 0x5, 0x14, 0xb, 0x2, 0x117, 0x27, 0x3, 0x2, 0x2, 0x2, 0x118, 
    0x119, 0x5, 0x16, 0xc, 0x2, 0x119, 0x11a, 0x7, 0x7, 0x2, 0x2, 0x11a, 
    0x11b, 0x5, 0x16, 0xc, 0x2, 0x11b, 0x29, 0x3, 0x2, 0x2, 0x2, 0x11c, 
    0x11d, 0x5, 0x20, 0x11, 0x2, 0x11d, 0x11e, 0x7, 0x1f, 0x2, 0x2, 0x11e, 
    0x11f, 0x7, 0x8, 0x2, 0x2, 0x11f, 0x120, 0x5, 0x2c, 0x17, 0x2, 0x120, 
    0x121, 0x7, 0x9, 0x2, 0x2, 0x121, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x122, 0x127, 
    0x5, 0x22, 0x12, 0x2, 0x123, 0x124, 0x7, 0x4, 0x2, 0x2, 0x124, 0x126, 
    0x5, 0x22, 0x12, 0x2, 0x125, 0x123, 0x3, 0x2, 0x2, 0x2, 0x126, 0x129, 
    0x3, 0x2, 0x2, 0x2, 0x127, 0x125, 0x3, 0x2, 0x2, 0x2, 0x127, 0x128, 
    0x3, 0x2, 0x2, 0x2, 0x128, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x129, 0x127, 0x3, 
    0x2, 0x2, 0x2, 0x12a, 0x12b, 0x7, 0x1a, 0x2, 0x2, 0x12b, 0x12c, 0x5, 
    0x30, 0x19, 0x2, 0x12c, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x132, 0x5, 
    0x32, 0x1a, 0x2, 0x12e, 0x12f, 0x7, 0x16, 0x2, 0x2, 0x12f, 0x131, 0x5, 
    0x32, 0x1a, 0x2, 0x130, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x131, 0x134, 0x3, 
    0x2, 0x2, 0x2, 0x132, 0x130, 0x3, 0x2, 0x2, 0x2, 0x132, 0x133, 0x3, 
    0x2, 0x2, 0x2, 0x133, 0x31, 0x3, 0x2, 0x2, 0x2, 0x134, 0x132, 0x3, 0x2, 
    0x2, 0x2, 0x135, 0x136, 0x5, 0x34, 0x1b, 0x2, 0x136, 0x137, 0x7, 0xa, 
    0x2, 0x2, 0x137, 0x138, 0x5, 0x20, 0x11, 0x2, 0x138, 0x33, 0x3, 0x2, 
    0x2, 0x2, 0x139, 0x13e, 0x5, 0x36, 0x1c, 0x2, 0x13a, 0x13b, 0x7, 0x4, 
    0x2, 0x2, 0x13b, 0x13d, 0x5, 0x36, 0x1c, 0x2, 0x13c, 0x13a, 0x3, 0x2, 
    0x2, 0x2, 0x13d, 0x140, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x13c, 0x3, 0x2, 
    0x2, 0x2, 0x13e, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x35, 0x3, 0x2, 0x2, 
    0x2, 0x140, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x141, 0x142, 0x7, 0x2c, 0x2, 
    0x2, 0x142, 0x37, 0x3, 0x2, 0x2, 0x2, 0x143, 0x148, 0x5, 0x3a, 0x1e, 
    0x2, 0x144, 0x145, 0x7, 0x16, 0x2, 0x2, 0x145, 0x147, 0x5, 0x3a, 0x1e, 
    0x2, 0x146, 0x144, 0x3, 0x2, 0x2, 0x2, 0x147, 0x14a, 0x3, 0x2, 0x2, 
    0x2, 0x148, 0x146, 0x3, 0x2, 0x2, 0x2, 0x148, 0x149, 0x3, 0x2, 0x2, 
    0x2, 0x149, 0x39, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x148, 0x3, 0x2, 0x2, 0x2, 
    0x14b, 0x14e, 0x5, 0x3c, 0x1f, 0x2, 0x14c, 0x14e, 0x5, 0x3e, 0x20, 0x2, 
    0x14d, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14c, 0x3, 0x2, 0x2, 0x2, 
    0x14e, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x150, 0x7, 0x16, 0x2, 0x2, 
    0x150, 0x151, 0x5, 0xa, 0x6, 0x2, 0x151, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x152, 
    0x153, 0x7, 0x1b, 0x2, 0x2, 0x153, 0x155, 0x5, 0x40, 0x21, 0x2, 0x154, 
    0x156, 0x5, 0x42, 0x22, 0x2, 0x155, 0x154, 0x3, 0x2, 0x2, 0x2, 0x155, 
    0x156, 0x3, 0x2, 0x2, 0x2, 0x156, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x157, 0x158, 
    0x7, 0x1c, 0x2, 0x2, 0x158, 0x15a, 0x5, 0x40, 0x21, 0x2, 0x159, 0x15b, 
    0x5, 0x42, 0x22, 0x2, 0x15a, 0x159, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x15b, 
    0x3, 0x2, 0x2, 0x2, 0x15b, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x15d, 
    0x7, 0xa, 0x2, 0x2, 0x15d, 0x15e, 0x5, 0x1e, 0x10, 0x2, 0x15e, 0x3f, 
    0x3, 0x2, 0x2, 0x2, 0x15f, 0x160, 0x7, 0x2c, 0x2, 0x2, 0x160, 0x41, 
    0x3, 0x2, 0x2, 0x2, 0x161, 0x162, 0x7, 0x3, 0x2, 0x2, 0x162, 0x163, 
    0x5, 0x44, 0x23, 0x2, 0x163, 0x164, 0x7, 0x5, 0x2, 0x2, 0x164, 0x43, 
    0x3, 0x2, 0x2, 0x2, 0x165, 0x16a, 0x5, 0x46, 0x24, 0x2, 0x166, 0x167, 
    0x7, 0x16, 0x2, 0x2, 0x167, 0x169, 0x5, 0x46, 0x24, 0x2, 0x168, 0x166, 
    0x3, 0x2, 0x2, 0x2, 0x169, 0x16c, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x168, 
    0x3, 0x2, 0x2, 0x2, 0x16a, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x45, 0x3, 
    0x2, 0x2, 0x2, 0x16c, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x16f, 0x7, 
    0x1a, 0x2, 0x2, 0x16e, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x16f, 0x3, 
    0x2, 0x2, 0x2, 0x16f, 0x170, 0x3, 0x2, 0x2, 0x2, 0x170, 0x171, 0x5, 
    0x48, 0x25, 0x2, 0x171, 0x172, 0x7, 0xa, 0x2, 0x2, 0x172, 0x173, 0x5, 
    0x1e, 0x10, 0x2, 0x173, 0x47, 0x3, 0x2, 0x2, 0x2, 0x174, 0x179, 0x5, 
    0x4a, 0x26, 0x2, 0x175, 0x176, 0x7, 0x4, 0x2, 0x2, 0x176, 0x178, 0x5, 
    0x4a, 0x26, 0x2, 0x177, 0x175, 0x3, 0x2, 0x2, 0x2, 0x178, 0x17b, 0x3, 
    0x2, 0x2, 0x2, 0x179, 0x177, 0x3, 0x2, 0x2, 0x2, 0x179, 0x17a, 0x3, 
    0x2, 0x2, 0x2, 0x17a, 0x49, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x179, 0x3, 0x2, 
    0x2, 0x2, 0x17c, 0x17d, 0x7, 0x2c, 0x2, 0x2, 0x17d, 0x4b, 0x3, 0x2, 
    0x2, 0x2, 0x17e, 0x18a, 0x5, 0x50, 0x29, 0x2, 0x17f, 0x18a, 0x5, 0x54, 
    0x2b, 0x2, 0x180, 0x18a, 0x5, 0x5a, 0x2e, 0x2, 0x181, 0x18a, 0x5, 0x60, 
    0x31, 0x2, 0x182, 0x18a, 0x5, 0x62, 0x32, 0x2, 0x183, 0x18a, 0x5, 0x70, 
    0x39, 0x2, 0x184, 0x18a, 0x5, 0x72, 0x3a, 0x2, 0x185, 0x18a, 0x5, 0x7c, 
    0x3f, 0x2, 0x186, 0x18a, 0x5, 0x7e, 0x40, 0x2, 0x187, 0x18a, 0x5, 0x68, 
    0x35, 0x2, 0x188, 0x18a, 0x5, 0x52, 0x2a, 0x2, 0x189, 0x17e, 0x3, 0x2, 
    0x2, 0x2, 0x189, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x189, 0x180, 0x3, 0x2, 
    0x2, 0x2, 0x189, 0x181, 0x3, 0x2, 0x2, 0x2, 0x189, 0x182, 0x3, 0x2, 
    0x2, 0x2, 0x189, 0x183, 0x3, 0x2, 0x2, 0x2, 0x189, 0x184, 0x3, 0x2, 
    0x2, 0x2, 0x189, 0x185, 0x3, 0x2, 0x2, 0x2, 0x189, 0x186, 0x3, 0x2, 
    0x2, 0x2, 0x189, 0x187, 0x3, 0x2, 0x2, 0x2, 0x189, 0x188, 0x3, 0x2, 
    0x2, 0x2, 0x18a, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x190, 0x5, 0x4c, 
    0x27, 0x2, 0x18c, 0x18d, 0x7, 0x16, 0x2, 0x2, 0x18d, 0x18f, 0x5, 0x4c, 
    0x27, 0x2, 0x18e, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x192, 0x3, 0x2, 
    0x2, 0x2, 0x190, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x190, 0x191, 0x3, 0x2, 
    0x2, 0x2, 0x191, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x192, 0x190, 0x3, 0x2, 0x2, 
    0x2, 0x193, 0x194, 0x7, 0x1d, 0x2, 0x2, 0x194, 0x195, 0x5, 0x4e, 0x28, 
    0x2, 0x195, 0x196, 0x7, 0x1e, 0x2, 0x2, 0x196, 0x51, 0x3, 0x2, 0x2, 
    0x2, 0x197, 0x198, 0x3, 0x2, 0x2, 0x2, 0x198, 0x53, 0x3, 0x2, 0x2, 0x2, 
    0x199, 0x19a, 0x5, 0x56, 0x2c, 0x2, 0x19a, 0x19b, 0x7, 0x6, 0x2, 0x2, 
    0x19b, 0x19c, 0x5, 0x58, 0x2d, 0x2, 0x19c, 0x55, 0x3, 0x2, 0x2, 0x2, 
    0x19d, 0x19e, 0x5, 0x8a, 0x46, 0x2, 0x19e, 0x57, 0x3, 0x2, 0x2, 0x2, 
    0x19f, 0x1a0, 0x5, 0x82, 0x42, 0x2, 0x1a0, 0x59, 0x3, 0x2, 0x2, 0x2, 
    0x1a1, 0x1a2, 0x7, 0x20, 0x2, 0x2, 0x1a2, 0x1a3, 0x5, 0x82, 0x42, 0x2, 
    0x1a3, 0x1a4, 0x7, 0x21, 0x2, 0x2, 0x1a4, 0x1a7, 0x5, 0x5c, 0x2f, 0x2, 
    0x1a5, 0x1a6, 0x7, 0x22, 0x2, 0x2, 0x1a6, 0x1a8, 0x5, 0x5e, 0x30, 0x2, 
    0x1a7, 0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a8, 0x3, 0x2, 0x2, 0x2, 
    0x1a8, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x1a9, 0x1aa, 0x5, 0x4c, 0x27, 0x2, 
    0x1aa, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x1ab, 0x1ac, 0x5, 0x4c, 0x27, 0x2, 
    0x1ac, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1ae, 0x7, 0x23, 0x2, 0x2, 
    0x1ae, 0x1af, 0x5, 0x4e, 0x28, 0x2, 0x1af, 0x1b0, 0x7, 0x24, 0x2, 0x2, 
    0x1b0, 0x1b1, 0x5, 0x82, 0x42, 0x2, 0x1b1, 0x61, 0x3, 0x2, 0x2, 0x2, 
    0x1b2, 0x1b3, 0x7, 0x25, 0x2, 0x2, 0x1b3, 0x1b4, 0x5, 0x82, 0x42, 0x2, 
    0x1b4, 0x1b5, 0x7, 0x26, 0x2, 0x2, 0x1b5, 0x1b6, 0x5, 0x4c, 0x27, 0x2, 
    0x1b6, 0x63, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1b8, 0x5, 0x66, 0x34, 0x2, 
    0x1b8, 0x1ba, 0x7, 0x3, 0x2, 0x2, 0x1b9, 0x1bb, 0x5, 0x6c, 0x37, 0x2, 
    0x1ba, 0x1b9, 0x3, 0x2, 0x2, 0x2, 0x1ba, 0x1bb, 0x3, 0x2, 0x2, 0x2, 
    0x1bb, 0x1bc, 0x3, 0x2, 0x2, 0x2, 0x1bc, 0x1bd, 0x7, 0x5, 0x2, 0x2, 
    0x1bd, 0x65, 0x3, 0x2, 0x2, 0x2, 0x1be, 0x1bf, 0x7, 0x2c, 0x2, 0x2, 
    0x1bf, 0x67, 0x3, 0x2, 0x2, 0x2, 0x1c0, 0x1c1, 0x5, 0x6a, 0x36, 0x2, 
    0x1c1, 0x1c3, 0x7, 0x3, 0x2, 0x2, 0x1c2, 0x1c4, 0x5, 0x6c, 0x37, 0x2, 
    0x1c3, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1c4, 0x3, 0x2, 0x2, 0x2, 
    0x1c4, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1c5, 0x1c6, 0x7, 0x5, 0x2, 0x2, 
    0x1c6, 0x69, 0x3, 0x2, 0x2, 0x2, 0x1c7, 0x1c8, 0x7, 0x2c, 0x2, 0x2, 
    0x1c8, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x1c9, 0x1ce, 0x5, 0x6e, 0x38, 0x2, 
    0x1ca, 0x1cb, 0x7, 0x4, 0x2, 0x2, 0x1cb, 0x1cd, 0x5, 0x6e, 0x38, 0x2, 
    0x1cc, 0x1ca, 0x3, 0x2, 0x2, 0x2, 0x1cd, 0x1d0, 0x3, 0x2, 0x2, 0x2, 
    0x1ce, 0x1cc, 0x3, 0x2, 0x2, 0x2, 0x1ce, 0x1cf, 0x3, 0x2, 0x2, 0x2, 
    0x1cf, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x1d0, 0x1ce, 0x3, 0x2, 0x2, 0x2, 0x1d1, 
    0x1d2, 0x5, 0x82, 0x42, 0x2, 0x1d2, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x1d3, 
    0x1d4, 0x7, 0x28, 0x2, 0x2, 0x1d4, 0x1d5, 0x5, 0x74, 0x3b, 0x2, 0x1d5, 
    0x71, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1d8, 0x7, 0x29, 0x2, 0x2, 0x1d7, 
    0x1d9, 0x5, 0x74, 0x3b, 0x2, 0x1d8, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1d8, 
    0x1d9, 0x3, 0x2, 0x2, 0x2, 0x1d9, 0x73, 0x3, 0x2, 0x2, 0x2, 0x1da, 0x1db, 
    0x7, 0x3, 0x2, 0x2, 0x1db, 0x1e0, 0x5, 0x76, 0x3c, 0x2, 0x1dc, 0x1dd, 
    0x7, 0x4, 0x2, 0x2, 0x1dd, 0x1df, 0x5, 0x76, 0x3c, 0x2, 0x1de, 0x1dc, 
    0x3, 0x2, 0x2, 0x2, 0x1df, 0x1e2, 0x3, 0x2, 0x2, 0x2, 0x1e0, 0x1de, 
    0x3, 0x2, 0x2, 0x2, 0x1e0, 0x1e1, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1e3, 
    0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1e0, 0x3, 0x2, 0x2, 0x2, 0x1e3, 0x1e4, 
    0x7, 0x5, 0x2, 0x2, 0x1e4, 0x75, 0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1e8, 0x5, 
    0x82, 0x42, 0x2, 0x1e6, 0x1e7, 0x7, 0xa, 0x2, 0x2, 0x1e7, 0x1e9, 0x5, 
    0x78, 0x3d, 0x2, 0x1e8, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1e9, 0x3, 
    0x2, 0x2, 0x2, 0x1e9, 0x77, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1ec, 0x5, 0x94, 
    0x4b, 0x2, 0x1eb, 0x1ea, 0x3, 0x2, 0x2, 0x2, 0x1eb, 0x1ec, 0x3, 0x2, 
    0x2, 0x2, 0x1ec, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1ed, 0x1f0, 0x5, 0x9a, 
    0x4e, 0x2, 0x1ee, 0x1ef, 0x7, 0xa, 0x2, 0x2, 0x1ef, 0x1f1, 0x5, 0x7a, 
    0x3e, 0x2, 0x1f0, 0x1ee, 0x3, 0x2, 0x2, 0x2, 0x1f0, 0x1f1, 0x3, 0x2, 
    0x2, 0x2, 0x1f1, 0x79, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1f3, 0x5, 0x9a, 
    0x4e, 0x2, 0x1f3, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x1f4, 0x1f5, 0x7, 0x2a, 
    0x2, 0x2, 0x1f5, 0x1f6, 0x5, 0x80, 0x41, 0x2, 0x1f6, 0x7d, 0x3, 0x2, 
    0x2, 0x2, 0x1f7, 0x1f8, 0x7, 0x2b, 0x2, 0x2, 0x1f8, 0x1f9, 0x5, 0x80, 
    0x41, 0x2, 0x1f9, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x1fa, 0x1fb, 0x7, 0x3, 
    0x2, 0x2, 0x1fb, 0x200, 0x5, 0x8a, 0x46, 0x2, 0x1fc, 0x1fd, 0x7, 0x4, 
    0x2, 0x2, 0x1fd, 0x1ff, 0x5, 0x8a, 0x46, 0x2, 0x1fe, 0x1fc, 0x3, 0x2, 
    0x2, 0x2, 0x1ff, 0x202, 0x3, 0x2, 0x2, 0x2, 0x200, 0x1fe, 0x3, 0x2, 
    0x2, 0x2, 0x200, 0x201, 0x3, 0x2, 0x2, 0x2, 0x201, 0x203, 0x3, 0x2, 
    0x2, 0x2, 0x202, 0x200, 0x3, 0x2, 0x2, 0x2, 0x203, 0x204, 0x7, 0x5, 
    0x2, 0x2, 0x204, 0x81, 0x3, 0x2, 0x2, 0x2, 0x205, 0x209, 0x5, 0x84, 
    0x43, 0x2, 0x206, 0x207, 0x5, 0xa2, 0x52, 0x2, 0x207, 0x208, 0x5, 0x84, 
    0x43, 0x2, 0x208, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x209, 0x206, 0x3, 0x2, 
    0x2, 0x2, 0x209, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x20a, 0x83, 0x3, 0x2, 0x2, 
    0x2, 0x20b, 0x20d, 0x5, 0x94, 0x4b, 0x2, 0x20c, 0x20b, 0x3, 0x2, 0x2, 
    0x2, 0x20c, 0x20d, 0x3, 0x2, 0x2, 0x2, 0x20d, 0x20e, 0x3, 0x2, 0x2, 
    0x2, 0x20e, 0x214, 0x5, 0x86, 0x44, 0x2, 0x20f, 0x210, 0x5, 0xa4, 0x53, 
    0x2, 0x210, 0x211, 0x5, 0x86, 0x44, 0x2, 0x211, 0x213, 0x3, 0x2, 0x2, 
    0x2, 0x212, 0x20f, 0x3, 0x2, 0x2, 0x2, 0x213, 0x216, 0x3, 0x2, 0x2, 
    0x2, 0x214, 0x212, 0x3, 0x2, 0x2, 0x2, 0x214, 0x215, 0x3, 0x2, 0x2, 
    0x2, 0x215, 0x85, 0x3, 0x2, 0x2, 0x2, 0x216, 0x214, 0x3, 0x2, 0x2, 0x2, 
    0x217, 0x21d, 0x5, 0x88, 0x45, 0x2, 0x218, 0x219, 0x5, 0xa6, 0x54, 0x2, 
    0x219, 0x21a, 0x5, 0x88, 0x45, 0x2, 0x21a, 0x21c, 0x3, 0x2, 0x2, 0x2, 
    0x21b, 0x218, 0x3, 0x2, 0x2, 0x2, 0x21c, 0x21f, 0x3, 0x2, 0x2, 0x2, 
    0x21d, 0x21b, 0x3, 0x2, 0x2, 0x2, 0x21d, 0x21e, 0x3, 0x2, 0x2, 0x2, 
    0x21e, 0x87, 0x3, 0x2, 0x2, 0x2, 0x21f, 0x21d, 0x3, 0x2, 0x2, 0x2, 0x220, 
    0x22c, 0x5, 0x8a, 0x46, 0x2, 0x221, 0x22c, 0x5, 0x96, 0x4c, 0x2, 0x222, 
    0x22c, 0x5, 0x9e, 0x50, 0x2, 0x223, 0x22c, 0x5, 0xa0, 0x51, 0x2, 0x224, 
    0x22c, 0x5, 0x64, 0x33, 0x2, 0x225, 0x226, 0x7, 0x27, 0x2, 0x2, 0x226, 
    0x22c, 0x5, 0x88, 0x45, 0x2, 0x227, 0x228, 0x7, 0x3, 0x2, 0x2, 0x228, 
    0x229, 0x5, 0x82, 0x42, 0x2, 0x229, 0x22a, 0x7, 0x5, 0x2, 0x2, 0x22a, 
    0x22c, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x220, 0x3, 0x2, 0x2, 0x2, 0x22b, 
    0x221, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x222, 0x3, 0x2, 0x2, 0x2, 0x22b, 
    0x223, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x224, 0x3, 0x2, 0x2, 0x2, 0x22b, 
    0x225, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x227, 0x3, 0x2, 0x2, 0x2, 0x22c, 
    0x89, 0x3, 0x2, 0x2, 0x2, 0x22d, 0x231, 0x5, 0x36, 0x1c, 0x2, 0x22e, 
    0x230, 0x5, 0x8c, 0x47, 0x2, 0x22f, 0x22e, 0x3, 0x2, 0x2, 0x2, 0x230, 
    0x233, 0x3, 0x2, 0x2, 0x2, 0x231, 0x22f, 0x3, 0x2, 0x2, 0x2, 0x231, 
    0x232, 0x3, 0x2, 0x2, 0x2, 0x232, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x233, 0x231, 
    0x3, 0x2, 0x2, 0x2, 0x234, 0x235, 0x7, 0x8, 0x2, 0x2, 0x235, 0x236, 
    0x5, 0x8e, 0x48, 0x2, 0x236, 0x237, 0x7, 0x9, 0x2, 0x2, 0x237, 0x23b, 
    0x3, 0x2, 0x2, 0x2, 0x238, 0x239, 0x7, 0xb, 0x2, 0x2, 0x239, 0x23b, 
    0x5, 0x92, 0x4a, 0x2, 0x23a, 0x234, 0x3, 0x2, 0x2, 0x2, 0x23a, 0x238, 
    0x3, 0x2, 0x2, 0x2, 0x23b, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x23c, 0x241, 0x5, 
    0x90, 0x49, 0x2, 0x23d, 0x23e, 0x7, 0x4, 0x2, 0x2, 0x23e, 0x240, 0x5, 
    0x90, 0x49, 0x2, 0x23f, 0x23d, 0x3, 0x2, 0x2, 0x2, 0x240, 0x243, 0x3, 
    0x2, 0x2, 0x2, 0x241, 0x23f, 0x3, 0x2, 0x2, 0x2, 0x241, 0x242, 0x3, 
    0x2, 0x2, 0x2, 0x242, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x243, 0x241, 0x3, 0x2, 
    0x2, 0x2, 0x244, 0x245, 0x5, 0x82, 0x42, 0x2, 0x245, 0x91, 0x3, 0x2, 
    0x2, 0x2, 0x246, 0x247, 0x7, 0x2c, 0x2, 0x2, 0x247, 0x93, 0x3, 0x2, 
    0x2, 0x2, 0x248, 0x249, 0x9, 0x2, 0x2, 0x2, 0x249, 0x95, 0x3, 0x2, 0x2, 
    0x2, 0x24a, 0x24c, 0x5, 0x94, 0x4b, 0x2, 0x24b, 0x24a, 0x3, 0x2, 0x2, 
    0x2, 0x24b, 0x24c, 0x3, 0x2, 0x2, 0x2, 0x24c, 0x24d, 0x3, 0x2, 0x2, 
    0x2, 0x24d, 0x24e, 0x5, 0x98, 0x4d, 0x2, 0x24e, 0x97, 0x3, 0x2, 0x2, 
    0x2, 0x24f, 0x252, 0x5, 0x9a, 0x4e, 0x2, 0x250, 0x252, 0x5, 0x9c, 0x4f, 
    0x2, 0x251, 0x24f, 0x3, 0x2, 0x2, 0x2, 0x251, 0x250, 0x3, 0x2, 0x2, 
    0x2, 0x252, 0x99, 0x3, 0x2, 0x2, 0x2, 0x253, 0x254, 0x7, 0x2d, 0x2, 
    0x2, 0x254, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x255, 0x256, 0x7, 0x2e, 0x2, 
    0x2, 0x256, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x257, 0x258, 0x7, 0x32, 0x2, 
    0x2, 0x258, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x259, 0x25a, 0x7, 0x33, 0x2, 
    0x2, 0x25a, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x25b, 0x25c, 0x9, 0x3, 0x2, 0x2, 
    0x25c, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x25d, 0x25e, 0x9, 0x2, 0x2, 0x2, 0x25e, 
    0xa5, 0x3, 0x2, 0x2, 0x2, 0x25f, 0x260, 0x9, 0x4, 0x2, 0x2, 0x260, 0xa7, 
    0x3, 0x2, 0x2, 0x2, 0x2f, 0xaf, 0xb9, 0xc6, 0xcb, 0xd0, 0xd5, 0xdf, 
    0xe9, 0xed, 0xf1, 0xfb, 0x109, 0x111, 0x127, 0x132, 0x13e, 0x148, 0x14d, 
    0x155, 0x15a, 0x16a, 0x16e, 0x179, 0x189, 0x190, 0x1a7, 0x1ba, 0x1c3, 
    0x1ce, 0x1d8, 0x1e0, 0x1e8, 0x1eb, 0x1f0, 0x200, 0x209, 0x20c, 0x214, 
    0x21d, 0x22b, 0x231, 0x23a, 0x241, 0x24b, 0x251, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

PurrscalParser::Initializer PurrscalParser::_init;
