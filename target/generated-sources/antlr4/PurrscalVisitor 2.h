
// Generated from Purrscal.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "PurrscalParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by PurrscalParser.
 */
class  PurrscalVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by PurrscalParser.
   */
    virtual antlrcpp::Any visitPurrgram(PurrscalParser::PurrgramContext *context) = 0;

    virtual antlrcpp::Any visitPurrgramSnoot(PurrscalParser::PurrgramSnootContext *context) = 0;

    virtual antlrcpp::Any visitPurrgramPurrameters(PurrscalParser::PurrgramPurrametersContext *context) = 0;

    virtual antlrcpp::Any visitPurrgramKitty(PurrscalParser::PurrgramKittyContext *context) = 0;

    virtual antlrcpp::Any visitCat(PurrscalParser::CatContext *context) = 0;

    virtual antlrcpp::Any visitCatQualities(PurrscalParser::CatQualitiesContext *context) = 0;

    virtual antlrcpp::Any visitDomesticQuality(PurrscalParser::DomesticQualityContext *context) = 0;

    virtual antlrcpp::Any visitDomesticBodies(PurrscalParser::DomesticBodiesContext *context) = 0;

    virtual antlrcpp::Any visitDomesticBody(PurrscalParser::DomesticBodyContext *context) = 0;

    virtual antlrcpp::Any visitDomesticKitty(PurrscalParser::DomesticKittyContext *context) = 0;

    virtual antlrcpp::Any visitDomestic(PurrscalParser::DomesticContext *context) = 0;

    virtual antlrcpp::Any visitBreedQuality(PurrscalParser::BreedQualityContext *context) = 0;

    virtual antlrcpp::Any visitBreedBodies(PurrscalParser::BreedBodiesContext *context) = 0;

    virtual antlrcpp::Any visitBreedBody(PurrscalParser::BreedBodyContext *context) = 0;

    virtual antlrcpp::Any visitKittyBreed(PurrscalParser::KittyBreedContext *context) = 0;

    virtual antlrcpp::Any visitChonkTypespec(PurrscalParser::ChonkTypespecContext *context) = 0;

    virtual antlrcpp::Any visitKittyBreedTypsec(PurrscalParser::KittyBreedTypsecContext *context) = 0;

    virtual antlrcpp::Any visitFluffballTypespec(PurrscalParser::FluffballTypespecContext *context) = 0;

    virtual antlrcpp::Any visitKittenKaboodleTypespec(PurrscalParser::KittenKaboodleTypespecContext *context) = 0;

    virtual antlrcpp::Any visitFluffball(PurrscalParser::FluffballContext *context) = 0;

    virtual antlrcpp::Any visitFluffballDomestic(PurrscalParser::FluffballDomesticContext *context) = 0;

    virtual antlrcpp::Any visitKittenKaboodle(PurrscalParser::KittenKaboodleContext *context) = 0;

    virtual antlrcpp::Any visitKaboodle(PurrscalParser::KaboodleContext *context) = 0;

    virtual antlrcpp::Any visitChonks(PurrscalParser::ChonksContext *context) = 0;

    virtual antlrcpp::Any visitKittenQuality(PurrscalParser::KittenQualityContext *context) = 0;

    virtual antlrcpp::Any visitKittenBodies(PurrscalParser::KittenBodiesContext *context) = 0;

    virtual antlrcpp::Any visitKittenBody(PurrscalParser::KittenBodyContext *context) = 0;

    virtual antlrcpp::Any visitKittenKitties(PurrscalParser::KittenKittiesContext *context) = 0;

    virtual antlrcpp::Any visitKittenKitty(PurrscalParser::KittenKittyContext *context) = 0;

    virtual antlrcpp::Any visitCallQuality(PurrscalParser::CallQualityContext *context) = 0;

    virtual antlrcpp::Any visitCallBody(PurrscalParser::CallBodyContext *context) = 0;

    virtual antlrcpp::Any visitYowlSnoot(PurrscalParser::YowlSnootContext *context) = 0;

    virtual antlrcpp::Any visitBlepSnoot(PurrscalParser::BlepSnootContext *context) = 0;

    virtual antlrcpp::Any visitCallKitty(PurrscalParser::CallKittyContext *context) = 0;

    virtual antlrcpp::Any visitPurrameters(PurrscalParser::PurrametersContext *context) = 0;

    virtual antlrcpp::Any visitPurrameterPurrs(PurrscalParser::PurrameterPurrsContext *context) = 0;

    virtual antlrcpp::Any visitPurrameterPurr(PurrscalParser::PurrameterPurrContext *context) = 0;

    virtual antlrcpp::Any visitPurrameterKitties(PurrscalParser::PurrameterKittiesContext *context) = 0;

    virtual antlrcpp::Any visitPurrameterKitty(PurrscalParser::PurrameterKittyContext *context) = 0;

    virtual antlrcpp::Any visitMew(PurrscalParser::MewContext *context) = 0;

    virtual antlrcpp::Any visitMews(PurrscalParser::MewsContext *context) = 0;

    virtual antlrcpp::Any visitTheBigMew(PurrscalParser::TheBigMewContext *context) = 0;

    virtual antlrcpp::Any visitBlankStare(PurrscalParser::BlankStareContext *context) = 0;

    virtual antlrcpp::Any visitHungryMew(PurrscalParser::HungryMewContext *context) = 0;

    virtual antlrcpp::Any visitLps(PurrscalParser::LpsContext *context) = 0;

    virtual antlrcpp::Any visitRps(PurrscalParser::RpsContext *context) = 0;

    virtual antlrcpp::Any visitSniffMew(PurrscalParser::SniffMewContext *context) = 0;

    virtual antlrcpp::Any visitPawMew(PurrscalParser::PawMewContext *context) = 0;

    virtual antlrcpp::Any visitIgnoreMew(PurrscalParser::IgnoreMewContext *context) = 0;

    virtual antlrcpp::Any visitHowlMew(PurrscalParser::HowlMewContext *context) = 0;

    virtual antlrcpp::Any visitPurrMew(PurrscalParser::PurrMewContext *context) = 0;

    virtual antlrcpp::Any visitBlepCall(PurrscalParser::BlepCallContext *context) = 0;

    virtual antlrcpp::Any visitBlepName(PurrscalParser::BlepNameContext *context) = 0;

    virtual antlrcpp::Any visitYowlCallMew(PurrscalParser::YowlCallMewContext *context) = 0;

    virtual antlrcpp::Any visitYowlName(PurrscalParser::YowlNameContext *context) = 0;

    virtual antlrcpp::Any visitChirps(PurrscalParser::ChirpsContext *context) = 0;

    virtual antlrcpp::Any visitChirp(PurrscalParser::ChirpContext *context) = 0;

    virtual antlrcpp::Any visitMeowMew(PurrscalParser::MeowMewContext *context) = 0;

    virtual antlrcpp::Any visitMrrrMew(PurrscalParser::MrrrMewContext *context) = 0;

    virtual antlrcpp::Any visitMeows(PurrscalParser::MeowsContext *context) = 0;

    virtual antlrcpp::Any visitMeow(PurrscalParser::MeowContext *context) = 0;

    virtual antlrcpp::Any visitChungusWidth(PurrscalParser::ChungusWidthContext *context) = 0;

    virtual antlrcpp::Any visitToeBeanPlaces(PurrscalParser::ToeBeanPlacesContext *context) = 0;

    virtual antlrcpp::Any visitStalkMew(PurrscalParser::StalkMewContext *context) = 0;

    virtual antlrcpp::Any visitPounceMew(PurrscalParser::PounceMewContext *context) = 0;

    virtual antlrcpp::Any visitMrowus(PurrscalParser::MrowusContext *context) = 0;

    virtual antlrcpp::Any visitDemand(PurrscalParser::DemandContext *context) = 0;

    virtual antlrcpp::Any visitChonkDemand(PurrscalParser::ChonkDemandContext *context) = 0;

    virtual antlrcpp::Any visitTrill(PurrscalParser::TrillContext *context) = 0;

    virtual antlrcpp::Any visitKittenExpectation(PurrscalParser::KittenExpectationContext *context) = 0;

    virtual antlrcpp::Any visitFelineExpectation(PurrscalParser::FelineExpectationContext *context) = 0;

    virtual antlrcpp::Any visitThreadExpectation(PurrscalParser::ThreadExpectationContext *context) = 0;

    virtual antlrcpp::Any visitYarnExpectation(PurrscalParser::YarnExpectationContext *context) = 0;

    virtual antlrcpp::Any visitBlepCallExpectation(PurrscalParser::BlepCallExpectationContext *context) = 0;

    virtual antlrcpp::Any visitRollExpectation(PurrscalParser::RollExpectationContext *context) = 0;

    virtual antlrcpp::Any visitParenthesizedExpectation(PurrscalParser::ParenthesizedExpectationContext *context) = 0;

    virtual antlrcpp::Any visitKitten(PurrscalParser::KittenContext *context) = 0;

    virtual antlrcpp::Any visitModifier(PurrscalParser::ModifierContext *context) = 0;

    virtual antlrcpp::Any visitIndices(PurrscalParser::IndicesContext *context) = 0;

    virtual antlrcpp::Any visitIndex(PurrscalParser::IndexContext *context) = 0;

    virtual antlrcpp::Any visitChungus(PurrscalParser::ChungusContext *context) = 0;

    virtual antlrcpp::Any visitFur(PurrscalParser::FurContext *context) = 0;

    virtual antlrcpp::Any visitFeline(PurrscalParser::FelineContext *context) = 0;

    virtual antlrcpp::Any visitHairlessFeline(PurrscalParser::HairlessFelineContext *context) = 0;

    virtual antlrcpp::Any visitSphynxDomestic(PurrscalParser::SphynxDomesticContext *context) = 0;

    virtual antlrcpp::Any visitHairlessFelineDomestic(PurrscalParser::HairlessFelineDomesticContext *context) = 0;

    virtual antlrcpp::Any visitThreadBall(PurrscalParser::ThreadBallContext *context) = 0;

    virtual antlrcpp::Any visitYarnBall(PurrscalParser::YarnBallContext *context) = 0;

    virtual antlrcpp::Any visitRelationalWhisker(PurrscalParser::RelationalWhiskerContext *context) = 0;

    virtual antlrcpp::Any visitAdditiveWhisker(PurrscalParser::AdditiveWhiskerContext *context) = 0;

    virtual antlrcpp::Any visitMultiplicativeWhisker(PurrscalParser::MultiplicativeWhiskerContext *context) = 0;


};

