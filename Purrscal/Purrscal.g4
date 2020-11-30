grammar Purrscal;

purrgram 	: purrgramSnoot cat UWU ;

purrgramSnoot     : PURRGRAM purrgramKitty purrgramPurrameters? OWO ; 
purrgramPurrameters : '(' KITTY ( ',' KITTY )* ')' ;

purrgramKitty   locals [ SymtabEntry *entry = nullptr ]
    : KITTY ;

cat         : catQualities theBigMew ;
catQualities  : ( domesticQuality OWO )? ( breedQuality OWO )? 
                ( kittenQuality OWO )? ( callQuality OWO )? ;

domesticQuality   : DOMESTIC domesticBodies ;
domesticBodies : domesticBody ( OWO domesticBody )* ;
domesticBody   : domesticKitty '=' domestic;

domesticKitty  locals [ Typespec *type = nullptr, SymtabEntry *entry = nullptr ]
    : KITTY ;

domestic            locals [ Typespec *type = nullptr, Object value = nullptr ]  
    : fur? ( KITTY | hairlessFeline )
    | threadBall
    | yarnBall
    ;

breedQuality   : BREED breedBodies ;
breedBodies : breedBody ( OWO breedBody )* ;
breedBody   : kittyBreed '=' breed ;

kittyBreed      locals [ Typespec *type = nullptr, SymtabEntry *entry = nullptr ]
    : KITTY ;

breed   locals [ Typespec *type = nullptr ]
    : chonk        # chonkTypespec
    ;

chonk          locals [ Typespec *type = nullptr ] 
    : kittyBreed          # kittyBreedTypsec
    | fluffball           # fluffballTypespec
    | kittenKaboodle      # kittenKaboodleTypespec
    ;

fluffball         : '(' fluffballDomestic ( ',' fluffballDomestic )* ')' ;
fluffballDomestic : domesticKitty ;
kittenKaboodle : domestic '..' domestic ;

kaboodle
    : breed KABOODLE '[' chonks ']' ;
chonks : chonk ( ',' chonk )* ;

kittenQuality  : KITTEN kittenBodies ;
kittenBodies   : kittenBody ( OWO kittenBody )* ;
kittenBody     : kittenKitties ':' breed ;
kittenKitties  : kittenKitty ( ',' kittenKitty )* ;

kittenKitty  locals [ Typespec *type = nullptr, SymtabEntry *entry = nullptr ] 
    : KITTY ;

callQuality   : callBody ( OWO callBody)* ;
callBody      : ( yowlSnoot | blepSnoot ) OWO cat ;
yowlSnoot     : YOWL callKitty purrameters? ;
blepSnoot     : BLEP  callKitty purrameters? ':' kittyBreed ;

callKitty   locals [ Typespec *type = nullptr, SymtabEntry *entry = nullptr ]
    : KITTY ;

purrameters        : '(' purrameterPurrs ')' ;
purrameterPurrs    : purrameterPurr ( OWO purrameterPurr )* ;
purrameterPurr     : KITTEN? purrameterKitties ':' kittyBreed ;
purrameterKitties  : purrameterKitty ( ',' purrameterKitty )* ;

purrameterKitty   locals [ Typespec *type = nullptr, SymtabEntry *entry = nullptr ]
    : KITTY ;

mew : theBigMew
    | hungryMew
    | sniffMew
    | howlMew
    | purrMew
    | meowMew
    | mrrrMew
    | stalkMew
    | pounceMew
    | yowlCallMew
    | blankStare
    ;

mews : mew ( OWO mew )* ;

theBigMew  : PLAY mews NAP ;
blankStare : ;

hungryMew : lps '=' rps ;
lps                 locals [ Typespec *type = nullptr ] 
    : kitten ;
rps : demand ;

sniffMew  : SNIFF demand PAW pawMew ( IGNORE ignoreMew )? ;
pawMew    : mew ;
ignoreMew : mew ;

howlMew  : HOWL mews UNTIL demand ;
purrMew  : WHILE demand PURR mew ;

blepCall : blepName '(' chirps? ')' ;
blepName    locals [ Typespec *type = nullptr, SymtabEntry *entry = nullptr ] 
    : KITTY ;

yowlCallMew : yowlName '(' chirps? ')' ;
yowlName   locals [ SymtabEntry *entry = nullptr ] 
    : KITTY ;

chirps    : chirp ( ',' chirp )* ;
chirp     : demand ;

meowMew         : MEOW meows ;
mrrrMew         : MRRR meows? ;
meows           : '(' meow (',' meow)* ')' ;
meow            : demand (':' chungusWidth)? ;
chungusWidth    : fur? sphynxDomestic (':' toeBeanPlaces)? ;
toeBeanPlaces   : sphynxDomestic ;

stalkMew   : STALK mrowus ;
pounceMew  : POUNCE mrowus ;
mrowus     : '(' kitten ( ',' kitten )* ')' ;

demand          locals [ Typespec *type = nullptr ] 
    : chonkDemand (relationalWhisker chonkDemand)? ;

chonkDemand    locals [ Typespec *type = nullptr ] 
    : fur? trill (additiveWhisker trill)* ;

trill                locals [ Typespec *type = nullptr ]
    : expectation (multiplicativeWhisker expectation)* ;

expectation              locals [ Typespec *type = nullptr ] 
    : kitten            # kittenExpectation
    | feline            # felineExpectation
    | threadBall    	# threadExpectation
    | yarnBall       	# yarnExpectation
    | blepCall         	# blepCallExpectation
    | ROLL expectation  # rollExpectation
    | '(' demand ')'   	# parenthesizedExpectation
    ;

kitten        locals [ Typespec *type = nullptr, SymtabEntry *entry = nullptr ] 
    : kittenKitty modifier* ;

modifier  : '[' indices ']' | '.' chungus ;
indices   : index ( ',' index )* ;
index     : demand ; 

chungus           locals [ Typespec *type = nullptr, SymtabEntry *entry = nullptr ]     
    : KITTY ;

fur : '-' | '+' ;

feline            		  : fur? hairlessFeline ;
hairlessFeline     		  : sphynxDomestic | hairlessFelineDomestic ;
sphynxDomestic    		  : SPHYNX ;
hairlessFelineDomestic    : HAIRLESS_FELINE;

threadBall : THREAD ;
yarnBall   : YARN ;

relationalWhisker     : '=' | '!=' | '<' | '<=' | '>' | '>=' ;
additiveWhisker       : '+' | '-' ;
multiplicativeWhisker : '*' | '/' ;

fragment A : ('a' | 'A') ;
fragment B : ('b' | 'B') ;
fragment C : ('c' | 'C') ;
fragment D : ('d' | 'D') ;
fragment E : ('e' | 'E') ;
fragment F : ('f' | 'F') ;
fragment G : ('g' | 'G') ;
fragment H : ('h' | 'H') ;
fragment I : ('i' | 'I') ;
fragment J : ('j' | 'J') ;
fragment K : ('k' | 'K') ;
fragment L : ('l' | 'L') ;
fragment M : ('m' | 'M') ;
fragment N : ('n' | 'N') ;
fragment O : ('o' | 'O') ;
fragment P : ('p' | 'P') ;
fragment Q : ('q' | 'Q') ;
fragment R : ('r' | 'R') ;
fragment S : ('s' | 'S') ;
fragment T : ('t' | 'T') ;
fragment U : ('u' | 'U') ;
fragment V : ('v' | 'V') ;
fragment W : ('w' | 'W') ;
fragment X : ('x' | 'X') ;
fragment Y : ('y' | 'Y') ;
fragment Z : ('z' | 'Z') ;

PURRGRAM  : P U R R G R A M ;
OWO		  : O W O ;
UWU 	  : U W U ;
DOMESTIC  : D O M E S T I C ;
BREED	  : B R E E D ;
KITTEN	  : K I T T E N ;
YOWL	  : Y O W L ;
BLEP 	  : B L E P ;
PLAY 	  : P L A Y ;
NAP		  : N A P ;
KABOODLE  : K A B O O D L E ;
SNIFF	  : S N I F F ;
PAW		  : P A W ;
IGNORE	  : I G N O R E ;
HOWL 	  : H O W L ;
UNTIL     : U N T I L ;
WHILE     : W H I L E ;
PURR	  : P U R R ;
ROLL	  : R O L L ;
MEOW      : M E O W ;
MRRR      : M R R R ;
STALK     : S T A L K ;
POUNCE    : P O U N C E ;

KITTY	   : [a-zA-Z][a-zA-Z0-9]* ;
SPHYNX     : [0-9]+ ;

HAIRLESS_FELINE : SPHYNX '.' SPHYNX
           		| SPHYNX('e' | 'E') ('+' | '-')? SPHYNX
           		| SPHYNX '.' SPHYNX ('e' | 'E') ('+' | '-')? SPHYNX
           		;

NEWLINE : '\r'? '\n' -> skip  ;
WS      : [ \t]+ -> skip ; 

QUOTE     : '\'' ;
THREAD : QUOTE THREAD_THRD QUOTE ;
YARN   : QUOTE YARN_THRD* QUOTE ;

fragment THREAD_THRD : ~('\'')   // any non-quote character
                	 ;

fragment YARN_THRD	: QUOTE QUOTE  // two consecutive quotes
                	| ~('\'')      // any non-quote character
                	;

COMMENT : '{' COMMENT_CHARACTER* '}' -> skip ;

fragment COMMENT_CHARACTER : ~('}') ;
                     