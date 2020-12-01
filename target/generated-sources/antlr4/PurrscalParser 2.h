
// Generated from Purrscal.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  PurrscalParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, PURRGRAM = 19, OWO = 20, 
    UWU = 21, DOMESTIC = 22, BREED = 23, KITTEN = 24, YOWL = 25, BLEP = 26, 
    PLAY = 27, NAP = 28, KABOODLE = 29, SNIFF = 30, PAW = 31, IGNORE = 32, 
    HOWL = 33, UNTIL = 34, WHILE = 35, PURR = 36, ROLL = 37, MEOW = 38, 
    MRRR = 39, STALK = 40, POUNCE = 41, KITTY = 42, SPHYNX = 43, HAIRLESS_FELINE = 44, 
    NEWLINE = 45, WS = 46, QUOTE = 47, THREAD = 48, YARN = 49, COMMENT = 50
  };

  enum {
    RulePurrgram = 0, RulePurrgramSnoot = 1, RulePurrgramPurrameters = 2, 
    RulePurrgramKitty = 3, RuleCat = 4, RuleCatQualities = 5, RuleDomesticQuality = 6, 
    RuleDomesticBodies = 7, RuleDomesticBody = 8, RuleDomesticKitty = 9, 
    RuleDomestic = 10, RuleBreedQuality = 11, RuleBreedBodies = 12, RuleBreedBody = 13, 
    RuleKittyBreed = 14, RuleBreed = 15, RuleChonk = 16, RuleFluffball = 17, 
    RuleFluffballDomestic = 18, RuleKittenKaboodle = 19, RuleKaboodle = 20, 
    RuleChonks = 21, RuleKittenQuality = 22, RuleKittenBodies = 23, RuleKittenBody = 24, 
    RuleKittenKitties = 25, RuleKittenKitty = 26, RuleCallQuality = 27, 
    RuleCallBody = 28, RuleYowlSnoot = 29, RuleBlepSnoot = 30, RuleCallKitty = 31, 
    RulePurrameters = 32, RulePurrameterPurrs = 33, RulePurrameterPurr = 34, 
    RulePurrameterKitties = 35, RulePurrameterKitty = 36, RuleMew = 37, 
    RuleMews = 38, RuleTheBigMew = 39, RuleBlankStare = 40, RuleHungryMew = 41, 
    RuleLps = 42, RuleRps = 43, RuleSniffMew = 44, RulePawMew = 45, RuleIgnoreMew = 46, 
    RuleHowlMew = 47, RulePurrMew = 48, RuleBlepCall = 49, RuleBlepName = 50, 
    RuleYowlCallMew = 51, RuleYowlName = 52, RuleChirps = 53, RuleChirp = 54, 
    RuleMeowMew = 55, RuleMrrrMew = 56, RuleMeows = 57, RuleMeow = 58, RuleChungusWidth = 59, 
    RuleToeBeanPlaces = 60, RuleStalkMew = 61, RulePounceMew = 62, RuleMrowus = 63, 
    RuleDemand = 64, RuleChonkDemand = 65, RuleTrill = 66, RuleExpectation = 67, 
    RuleKitten = 68, RuleModifier = 69, RuleIndices = 70, RuleIndex = 71, 
    RuleChungus = 72, RuleFur = 73, RuleFeline = 74, RuleHairlessFeline = 75, 
    RuleSphynxDomestic = 76, RuleHairlessFelineDomestic = 77, RuleThreadBall = 78, 
    RuleYarnBall = 79, RuleRelationalWhisker = 80, RuleAdditiveWhisker = 81, 
    RuleMultiplicativeWhisker = 82
  };

  PurrscalParser(antlr4::TokenStream *input);
  ~PurrscalParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class PurrgramContext;
  class PurrgramSnootContext;
  class PurrgramPurrametersContext;
  class PurrgramKittyContext;
  class CatContext;
  class CatQualitiesContext;
  class DomesticQualityContext;
  class DomesticBodiesContext;
  class DomesticBodyContext;
  class DomesticKittyContext;
  class DomesticContext;
  class BreedQualityContext;
  class BreedBodiesContext;
  class BreedBodyContext;
  class KittyBreedContext;
  class BreedContext;
  class ChonkContext;
  class FluffballContext;
  class FluffballDomesticContext;
  class KittenKaboodleContext;
  class KaboodleContext;
  class ChonksContext;
  class KittenQualityContext;
  class KittenBodiesContext;
  class KittenBodyContext;
  class KittenKittiesContext;
  class KittenKittyContext;
  class CallQualityContext;
  class CallBodyContext;
  class YowlSnootContext;
  class BlepSnootContext;
  class CallKittyContext;
  class PurrametersContext;
  class PurrameterPurrsContext;
  class PurrameterPurrContext;
  class PurrameterKittiesContext;
  class PurrameterKittyContext;
  class MewContext;
  class MewsContext;
  class TheBigMewContext;
  class BlankStareContext;
  class HungryMewContext;
  class LpsContext;
  class RpsContext;
  class SniffMewContext;
  class PawMewContext;
  class IgnoreMewContext;
  class HowlMewContext;
  class PurrMewContext;
  class BlepCallContext;
  class BlepNameContext;
  class YowlCallMewContext;
  class YowlNameContext;
  class ChirpsContext;
  class ChirpContext;
  class MeowMewContext;
  class MrrrMewContext;
  class MeowsContext;
  class MeowContext;
  class ChungusWidthContext;
  class ToeBeanPlacesContext;
  class StalkMewContext;
  class PounceMewContext;
  class MrowusContext;
  class DemandContext;
  class ChonkDemandContext;
  class TrillContext;
  class ExpectationContext;
  class KittenContext;
  class ModifierContext;
  class IndicesContext;
  class IndexContext;
  class ChungusContext;
  class FurContext;
  class FelineContext;
  class HairlessFelineContext;
  class SphynxDomesticContext;
  class HairlessFelineDomesticContext;
  class ThreadBallContext;
  class YarnBallContext;
  class RelationalWhiskerContext;
  class AdditiveWhiskerContext;
  class MultiplicativeWhiskerContext; 

  class  PurrgramContext : public antlr4::ParserRuleContext {
  public:
    PurrgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PurrgramSnootContext *purrgramSnoot();
    CatContext *cat();
    antlr4::tree::TerminalNode *UWU();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PurrgramContext* purrgram();

  class  PurrgramSnootContext : public antlr4::ParserRuleContext {
  public:
    PurrgramSnootContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PURRGRAM();
    PurrgramKittyContext *purrgramKitty();
    antlr4::tree::TerminalNode *OWO();
    PurrgramPurrametersContext *purrgramPurrameters();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PurrgramSnootContext* purrgramSnoot();

  class  PurrgramPurrametersContext : public antlr4::ParserRuleContext {
  public:
    PurrgramPurrametersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> KITTY();
    antlr4::tree::TerminalNode* KITTY(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PurrgramPurrametersContext* purrgramPurrameters();

  class  PurrgramKittyContext : public antlr4::ParserRuleContext {
  public:
    SymtabEntry * entry = nullptr;
    PurrgramKittyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KITTY();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PurrgramKittyContext* purrgramKitty();

  class  CatContext : public antlr4::ParserRuleContext {
  public:
    CatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CatQualitiesContext *catQualities();
    TheBigMewContext *theBigMew();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CatContext* cat();

  class  CatQualitiesContext : public antlr4::ParserRuleContext {
  public:
    CatQualitiesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DomesticQualityContext *domesticQuality();
    std::vector<antlr4::tree::TerminalNode *> OWO();
    antlr4::tree::TerminalNode* OWO(size_t i);
    BreedQualityContext *breedQuality();
    KittenQualityContext *kittenQuality();
    CallQualityContext *callQuality();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CatQualitiesContext* catQualities();

  class  DomesticQualityContext : public antlr4::ParserRuleContext {
  public:
    DomesticQualityContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DOMESTIC();
    DomesticBodiesContext *domesticBodies();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DomesticQualityContext* domesticQuality();

  class  DomesticBodiesContext : public antlr4::ParserRuleContext {
  public:
    DomesticBodiesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<DomesticBodyContext *> domesticBody();
    DomesticBodyContext* domesticBody(size_t i);
    std::vector<antlr4::tree::TerminalNode *> OWO();
    antlr4::tree::TerminalNode* OWO(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DomesticBodiesContext* domesticBodies();

  class  DomesticBodyContext : public antlr4::ParserRuleContext {
  public:
    DomesticBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DomesticKittyContext *domesticKitty();
    DomesticContext *domestic();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DomesticBodyContext* domesticBody();

  class  DomesticKittyContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    SymtabEntry * entry = nullptr;
    DomesticKittyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KITTY();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DomesticKittyContext* domesticKitty();

  class  DomesticContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    Object value = nullptr;
    DomesticContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KITTY();
    HairlessFelineContext *hairlessFeline();
    FurContext *fur();
    ThreadBallContext *threadBall();
    YarnBallContext *yarnBall();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DomesticContext* domestic();

  class  BreedQualityContext : public antlr4::ParserRuleContext {
  public:
    BreedQualityContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BREED();
    BreedBodiesContext *breedBodies();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BreedQualityContext* breedQuality();

  class  BreedBodiesContext : public antlr4::ParserRuleContext {
  public:
    BreedBodiesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<BreedBodyContext *> breedBody();
    BreedBodyContext* breedBody(size_t i);
    std::vector<antlr4::tree::TerminalNode *> OWO();
    antlr4::tree::TerminalNode* OWO(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BreedBodiesContext* breedBodies();

  class  BreedBodyContext : public antlr4::ParserRuleContext {
  public:
    BreedBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    KittyBreedContext *kittyBreed();
    BreedContext *breed();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BreedBodyContext* breedBody();

  class  KittyBreedContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    SymtabEntry * entry = nullptr;
    KittyBreedContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KITTY();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  KittyBreedContext* kittyBreed();

  class  BreedContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    BreedContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    BreedContext() = default;
    void copyFrom(BreedContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ChonkTypespecContext : public BreedContext {
  public:
    ChonkTypespecContext(BreedContext *ctx);

    ChonkContext *chonk();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  BreedContext* breed();

  class  ChonkContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    ChonkContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ChonkContext() = default;
    void copyFrom(ChonkContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  KittenKaboodleTypespecContext : public ChonkContext {
  public:
    KittenKaboodleTypespecContext(ChonkContext *ctx);

    KittenKaboodleContext *kittenKaboodle();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FluffballTypespecContext : public ChonkContext {
  public:
    FluffballTypespecContext(ChonkContext *ctx);

    FluffballContext *fluffball();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  KittyBreedTypsecContext : public ChonkContext {
  public:
    KittyBreedTypsecContext(ChonkContext *ctx);

    KittyBreedContext *kittyBreed();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ChonkContext* chonk();

  class  FluffballContext : public antlr4::ParserRuleContext {
  public:
    FluffballContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FluffballDomesticContext *> fluffballDomestic();
    FluffballDomesticContext* fluffballDomestic(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FluffballContext* fluffball();

  class  FluffballDomesticContext : public antlr4::ParserRuleContext {
  public:
    FluffballDomesticContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DomesticKittyContext *domesticKitty();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FluffballDomesticContext* fluffballDomestic();

  class  KittenKaboodleContext : public antlr4::ParserRuleContext {
  public:
    KittenKaboodleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<DomesticContext *> domestic();
    DomesticContext* domestic(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  KittenKaboodleContext* kittenKaboodle();

  class  KaboodleContext : public antlr4::ParserRuleContext {
  public:
    KaboodleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BreedContext *breed();
    antlr4::tree::TerminalNode *KABOODLE();
    ChonksContext *chonks();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  KaboodleContext* kaboodle();

  class  ChonksContext : public antlr4::ParserRuleContext {
  public:
    ChonksContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ChonkContext *> chonk();
    ChonkContext* chonk(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ChonksContext* chonks();

  class  KittenQualityContext : public antlr4::ParserRuleContext {
  public:
    KittenQualityContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KITTEN();
    KittenBodiesContext *kittenBodies();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  KittenQualityContext* kittenQuality();

  class  KittenBodiesContext : public antlr4::ParserRuleContext {
  public:
    KittenBodiesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<KittenBodyContext *> kittenBody();
    KittenBodyContext* kittenBody(size_t i);
    std::vector<antlr4::tree::TerminalNode *> OWO();
    antlr4::tree::TerminalNode* OWO(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  KittenBodiesContext* kittenBodies();

  class  KittenBodyContext : public antlr4::ParserRuleContext {
  public:
    KittenBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    KittenKittiesContext *kittenKitties();
    BreedContext *breed();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  KittenBodyContext* kittenBody();

  class  KittenKittiesContext : public antlr4::ParserRuleContext {
  public:
    KittenKittiesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<KittenKittyContext *> kittenKitty();
    KittenKittyContext* kittenKitty(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  KittenKittiesContext* kittenKitties();

  class  KittenKittyContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    SymtabEntry * entry = nullptr;
    KittenKittyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KITTY();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  KittenKittyContext* kittenKitty();

  class  CallQualityContext : public antlr4::ParserRuleContext {
  public:
    CallQualityContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<CallBodyContext *> callBody();
    CallBodyContext* callBody(size_t i);
    std::vector<antlr4::tree::TerminalNode *> OWO();
    antlr4::tree::TerminalNode* OWO(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CallQualityContext* callQuality();

  class  CallBodyContext : public antlr4::ParserRuleContext {
  public:
    CallBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OWO();
    CatContext *cat();
    YowlSnootContext *yowlSnoot();
    BlepSnootContext *blepSnoot();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CallBodyContext* callBody();

  class  YowlSnootContext : public antlr4::ParserRuleContext {
  public:
    YowlSnootContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *YOWL();
    CallKittyContext *callKitty();
    PurrametersContext *purrameters();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  YowlSnootContext* yowlSnoot();

  class  BlepSnootContext : public antlr4::ParserRuleContext {
  public:
    BlepSnootContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BLEP();
    CallKittyContext *callKitty();
    KittyBreedContext *kittyBreed();
    PurrametersContext *purrameters();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlepSnootContext* blepSnoot();

  class  CallKittyContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    SymtabEntry * entry = nullptr;
    CallKittyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KITTY();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CallKittyContext* callKitty();

  class  PurrametersContext : public antlr4::ParserRuleContext {
  public:
    PurrametersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PurrameterPurrsContext *purrameterPurrs();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PurrametersContext* purrameters();

  class  PurrameterPurrsContext : public antlr4::ParserRuleContext {
  public:
    PurrameterPurrsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<PurrameterPurrContext *> purrameterPurr();
    PurrameterPurrContext* purrameterPurr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> OWO();
    antlr4::tree::TerminalNode* OWO(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PurrameterPurrsContext* purrameterPurrs();

  class  PurrameterPurrContext : public antlr4::ParserRuleContext {
  public:
    PurrameterPurrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PurrameterKittiesContext *purrameterKitties();
    KittyBreedContext *kittyBreed();
    antlr4::tree::TerminalNode *KITTEN();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PurrameterPurrContext* purrameterPurr();

  class  PurrameterKittiesContext : public antlr4::ParserRuleContext {
  public:
    PurrameterKittiesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<PurrameterKittyContext *> purrameterKitty();
    PurrameterKittyContext* purrameterKitty(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PurrameterKittiesContext* purrameterKitties();

  class  PurrameterKittyContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    SymtabEntry * entry = nullptr;
    PurrameterKittyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KITTY();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PurrameterKittyContext* purrameterKitty();

  class  MewContext : public antlr4::ParserRuleContext {
  public:
    MewContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TheBigMewContext *theBigMew();
    HungryMewContext *hungryMew();
    SniffMewContext *sniffMew();
    HowlMewContext *howlMew();
    PurrMewContext *purrMew();
    MeowMewContext *meowMew();
    MrrrMewContext *mrrrMew();
    StalkMewContext *stalkMew();
    PounceMewContext *pounceMew();
    YowlCallMewContext *yowlCallMew();
    BlankStareContext *blankStare();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MewContext* mew();

  class  MewsContext : public antlr4::ParserRuleContext {
  public:
    MewsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<MewContext *> mew();
    MewContext* mew(size_t i);
    std::vector<antlr4::tree::TerminalNode *> OWO();
    antlr4::tree::TerminalNode* OWO(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MewsContext* mews();

  class  TheBigMewContext : public antlr4::ParserRuleContext {
  public:
    TheBigMewContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PLAY();
    MewsContext *mews();
    antlr4::tree::TerminalNode *NAP();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TheBigMewContext* theBigMew();

  class  BlankStareContext : public antlr4::ParserRuleContext {
  public:
    BlankStareContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlankStareContext* blankStare();

  class  HungryMewContext : public antlr4::ParserRuleContext {
  public:
    HungryMewContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LpsContext *lps();
    RpsContext *rps();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  HungryMewContext* hungryMew();

  class  LpsContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    LpsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    KittenContext *kitten();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LpsContext* lps();

  class  RpsContext : public antlr4::ParserRuleContext {
  public:
    RpsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DemandContext *demand();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RpsContext* rps();

  class  SniffMewContext : public antlr4::ParserRuleContext {
  public:
    SniffMewContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SNIFF();
    DemandContext *demand();
    antlr4::tree::TerminalNode *PAW();
    PawMewContext *pawMew();
    antlr4::tree::TerminalNode *IGNORE();
    IgnoreMewContext *ignoreMew();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SniffMewContext* sniffMew();

  class  PawMewContext : public antlr4::ParserRuleContext {
  public:
    PawMewContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MewContext *mew();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PawMewContext* pawMew();

  class  IgnoreMewContext : public antlr4::ParserRuleContext {
  public:
    IgnoreMewContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MewContext *mew();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IgnoreMewContext* ignoreMew();

  class  HowlMewContext : public antlr4::ParserRuleContext {
  public:
    HowlMewContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HOWL();
    MewsContext *mews();
    antlr4::tree::TerminalNode *UNTIL();
    DemandContext *demand();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  HowlMewContext* howlMew();

  class  PurrMewContext : public antlr4::ParserRuleContext {
  public:
    PurrMewContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHILE();
    DemandContext *demand();
    antlr4::tree::TerminalNode *PURR();
    MewContext *mew();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PurrMewContext* purrMew();

  class  BlepCallContext : public antlr4::ParserRuleContext {
  public:
    BlepCallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlepNameContext *blepName();
    ChirpsContext *chirps();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlepCallContext* blepCall();

  class  BlepNameContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    SymtabEntry * entry = nullptr;
    BlepNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KITTY();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlepNameContext* blepName();

  class  YowlCallMewContext : public antlr4::ParserRuleContext {
  public:
    YowlCallMewContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    YowlNameContext *yowlName();
    ChirpsContext *chirps();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  YowlCallMewContext* yowlCallMew();

  class  YowlNameContext : public antlr4::ParserRuleContext {
  public:
    SymtabEntry * entry = nullptr;
    YowlNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KITTY();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  YowlNameContext* yowlName();

  class  ChirpsContext : public antlr4::ParserRuleContext {
  public:
    ChirpsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ChirpContext *> chirp();
    ChirpContext* chirp(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ChirpsContext* chirps();

  class  ChirpContext : public antlr4::ParserRuleContext {
  public:
    ChirpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DemandContext *demand();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ChirpContext* chirp();

  class  MeowMewContext : public antlr4::ParserRuleContext {
  public:
    MeowMewContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MEOW();
    MeowsContext *meows();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MeowMewContext* meowMew();

  class  MrrrMewContext : public antlr4::ParserRuleContext {
  public:
    MrrrMewContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MRRR();
    MeowsContext *meows();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MrrrMewContext* mrrrMew();

  class  MeowsContext : public antlr4::ParserRuleContext {
  public:
    MeowsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<MeowContext *> meow();
    MeowContext* meow(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MeowsContext* meows();

  class  MeowContext : public antlr4::ParserRuleContext {
  public:
    MeowContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DemandContext *demand();
    ChungusWidthContext *chungusWidth();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MeowContext* meow();

  class  ChungusWidthContext : public antlr4::ParserRuleContext {
  public:
    ChungusWidthContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SphynxDomesticContext *sphynxDomestic();
    FurContext *fur();
    ToeBeanPlacesContext *toeBeanPlaces();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ChungusWidthContext* chungusWidth();

  class  ToeBeanPlacesContext : public antlr4::ParserRuleContext {
  public:
    ToeBeanPlacesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SphynxDomesticContext *sphynxDomestic();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToeBeanPlacesContext* toeBeanPlaces();

  class  StalkMewContext : public antlr4::ParserRuleContext {
  public:
    StalkMewContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STALK();
    MrowusContext *mrowus();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StalkMewContext* stalkMew();

  class  PounceMewContext : public antlr4::ParserRuleContext {
  public:
    PounceMewContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *POUNCE();
    MrowusContext *mrowus();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PounceMewContext* pounceMew();

  class  MrowusContext : public antlr4::ParserRuleContext {
  public:
    MrowusContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<KittenContext *> kitten();
    KittenContext* kitten(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MrowusContext* mrowus();

  class  DemandContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    DemandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ChonkDemandContext *> chonkDemand();
    ChonkDemandContext* chonkDemand(size_t i);
    RelationalWhiskerContext *relationalWhisker();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DemandContext* demand();

  class  ChonkDemandContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    ChonkDemandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TrillContext *> trill();
    TrillContext* trill(size_t i);
    FurContext *fur();
    std::vector<AdditiveWhiskerContext *> additiveWhisker();
    AdditiveWhiskerContext* additiveWhisker(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ChonkDemandContext* chonkDemand();

  class  TrillContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    TrillContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpectationContext *> expectation();
    ExpectationContext* expectation(size_t i);
    std::vector<MultiplicativeWhiskerContext *> multiplicativeWhisker();
    MultiplicativeWhiskerContext* multiplicativeWhisker(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TrillContext* trill();

  class  ExpectationContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    ExpectationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpectationContext() = default;
    void copyFrom(ExpectationContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  BlepCallExpectationContext : public ExpectationContext {
  public:
    BlepCallExpectationContext(ExpectationContext *ctx);

    BlepCallContext *blepCall();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  KittenExpectationContext : public ExpectationContext {
  public:
    KittenExpectationContext(ExpectationContext *ctx);

    KittenContext *kitten();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParenthesizedExpectationContext : public ExpectationContext {
  public:
    ParenthesizedExpectationContext(ExpectationContext *ctx);

    DemandContext *demand();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  YarnExpectationContext : public ExpectationContext {
  public:
    YarnExpectationContext(ExpectationContext *ctx);

    YarnBallContext *yarnBall();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RollExpectationContext : public ExpectationContext {
  public:
    RollExpectationContext(ExpectationContext *ctx);

    antlr4::tree::TerminalNode *ROLL();
    ExpectationContext *expectation();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ThreadExpectationContext : public ExpectationContext {
  public:
    ThreadExpectationContext(ExpectationContext *ctx);

    ThreadBallContext *threadBall();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FelineExpectationContext : public ExpectationContext {
  public:
    FelineExpectationContext(ExpectationContext *ctx);

    FelineContext *feline();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpectationContext* expectation();

  class  KittenContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    SymtabEntry * entry = nullptr;
    KittenContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    KittenKittyContext *kittenKitty();
    std::vector<ModifierContext *> modifier();
    ModifierContext* modifier(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  KittenContext* kitten();

  class  ModifierContext : public antlr4::ParserRuleContext {
  public:
    ModifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IndicesContext *indices();
    ChungusContext *chungus();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ModifierContext* modifier();

  class  IndicesContext : public antlr4::ParserRuleContext {
  public:
    IndicesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<IndexContext *> index();
    IndexContext* index(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IndicesContext* indices();

  class  IndexContext : public antlr4::ParserRuleContext {
  public:
    IndexContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DemandContext *demand();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IndexContext* index();

  class  ChungusContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    SymtabEntry * entry = nullptr;
    ChungusContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KITTY();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ChungusContext* chungus();

  class  FurContext : public antlr4::ParserRuleContext {
  public:
    FurContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FurContext* fur();

  class  FelineContext : public antlr4::ParserRuleContext {
  public:
    FelineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    HairlessFelineContext *hairlessFeline();
    FurContext *fur();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FelineContext* feline();

  class  HairlessFelineContext : public antlr4::ParserRuleContext {
  public:
    HairlessFelineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SphynxDomesticContext *sphynxDomestic();
    HairlessFelineDomesticContext *hairlessFelineDomestic();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  HairlessFelineContext* hairlessFeline();

  class  SphynxDomesticContext : public antlr4::ParserRuleContext {
  public:
    SphynxDomesticContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SPHYNX();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SphynxDomesticContext* sphynxDomestic();

  class  HairlessFelineDomesticContext : public antlr4::ParserRuleContext {
  public:
    HairlessFelineDomesticContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HAIRLESS_FELINE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  HairlessFelineDomesticContext* hairlessFelineDomestic();

  class  ThreadBallContext : public antlr4::ParserRuleContext {
  public:
    ThreadBallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *THREAD();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ThreadBallContext* threadBall();

  class  YarnBallContext : public antlr4::ParserRuleContext {
  public:
    YarnBallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *YARN();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  YarnBallContext* yarnBall();

  class  RelationalWhiskerContext : public antlr4::ParserRuleContext {
  public:
    RelationalWhiskerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RelationalWhiskerContext* relationalWhisker();

  class  AdditiveWhiskerContext : public antlr4::ParserRuleContext {
  public:
    AdditiveWhiskerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AdditiveWhiskerContext* additiveWhisker();

  class  MultiplicativeWhiskerContext : public antlr4::ParserRuleContext {
  public:
    MultiplicativeWhiskerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MultiplicativeWhiskerContext* multiplicativeWhisker();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

