.class public PurrscalDemo
.super java/lang/Object

.field private static _sysin Ljava/util/Scanner;
.field private static catbasket [I
.field private static i I
.field private static meowworld Ljava/lang/String;
.field private static shoutmark C

;
; Runtime input scanner
;
.method static <clinit>()V

	new	java/util/Scanner
	dup
	getstatic	java/lang/System/in Ljava/io/InputStream;
	invokespecial	java/util/Scanner/<init>(Ljava/io/InputStream;)V
	putstatic	PurrscalDemo/_sysin Ljava/util/Scanner;
	return

.limit locals 0
.limit stack 3
.end method

;
; Main class constructor
;
.method public <init>()V
.var 0 is this LPurrscalDemo;

	aload_0
	invokespecial	java/lang/Object/<init>()V
	return

.limit locals 1
.limit stack 1
.end method

;
; YOWL printcats
;
.method private static printcats(I)V

.var 1 is i I
.var 0 is numbermeows I
;
; 016 i:=0
;
	iconst_0
	istore_1
;
; 018 while(i<numberMeows)purrplaymeow('=^.^= ')OWOi:=i+1OWOnap
;
L001:
	iload_1
	iload_0
	if_icmplt	L003
	iconst_0
	goto	L004
L003:
	iconst_1
L004:
	ifeq	L002
;
; 019 meow('=^.^= ')
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"=^.^= "
	invokevirtual	java/io/PrintStream/print(Ljava/lang/String;)V
;
; 020 i:=i+1
;
	iload_1
	iconst_1
	iadd
	istore_1
	goto	L001
L002:
;
; 022 mrrr
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	invokevirtual	java/io/PrintStream.println()V

	return

.limit locals 2
.limit stack 2
.end method

;
; BLEP basketfull
;
.method private static basketfull([I)I

.var 0 is basket [I
.var 3 is basketfull I
.var 2 is full Z
.var 1 is i I
;
; 031 full:=alive
;
	iconst_1
	istore_2
;
; 032 i:=0
;
	iconst_0
	istore_1
;
; 033 howlplaysniffbasket[i]=0pawplayfull:=deadnapOWOi:=i+1OWOnapOWOuntili=6
;
L005:
;
; 034 sniffbasket[i]=0pawplayfull:=deadnap
;
	aload_0
	iload_1
	iaload
	iconst_0
	if_icmpeq	L008
	iconst_0
	goto	L009
L008:
	iconst_1
L009:
	ifeq	L007
;
; 035 full:=dead
;
	iconst_0
	istore_2
L007:
;
; 037 i:=i+1
;
	iload_1
	iconst_1
	iadd
	istore_1
	iload_1
	bipush	6
	if_icmpeq	L010
	iconst_0
	goto	L011
L010:
	iconst_1
L011:
	ifne	L006
	goto	L005
L006:
;
; 041 snifffullpawi:=1ignorei:=0
;
	iload_2
	ifeq	L013
;
; 041 i:=1
;
	iconst_1
	istore_1
	goto	L012
L013:
;
; 041 i:=0
;
	iconst_0
	istore_1
L012:
;
; 042 basketFull:=i
;
	iload_1
	istore_3

	iload_3
	ireturn

.limit locals 4
.limit stack 2
.end method

;
; MAIN
;
.method public static main([Ljava/lang/String;)V
.var 0 is args [Ljava/lang/String;
.var 1 is _start Ljava/time/Instant;
.var 2 is _end Ljava/time/Instant;
.var 3 is _elapsed J

	invokestatic	java/time/Instant/now()Ljava/time/Instant;
	astore_1

	bipush	6
	newarray	int
	putstatic	PurrscalDemo/catbasket [I

;
; 046 meowWorld:='Meow, World'
;
	ldc	"Meow, World"
	putstatic	PurrscalDemo/meowworld Ljava/lang/String;
;
; 047 shoutMark:='!'
;
	bipush	33
	putstatic	PurrscalDemo/shoutmark C
;
; 049 meow(meowWorld)
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"%s"
	iconst_1
	anewarray	java/lang/Object
	dup
	iconst_0
	getstatic	PurrscalDemo/meowworld Ljava/lang/String;
	aastore
	invokevirtual	java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;
	pop
;
; 050 meow(shoutMark)
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"%c"
	iconst_1
	anewarray	java/lang/Object
	dup
	iconst_0
	getstatic	PurrscalDemo/shoutmark C
	invokestatic	java/lang/Character/valueOf(C)Ljava/lang/Character;
	aastore
	invokevirtual	java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;
	pop
;
; 051 mrrr(' =^.^=')
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	" =^.^=\n"
	invokevirtual	java/io/PrintStream/print(Ljava/lang/String;)V
;
; 053 i:=0
;
	iconst_0
	putstatic	PurrscalDemo/i I
;
; 055 whilebasketFull(catBasket)=0purrplaycatBasket[i]:=i+1OWOi:=i+1OWOnap
;
L014:
	getstatic	PurrscalDemo/catbasket [I
	invokestatic	PurrscalDemo/basketfull([I)I
	iconst_0
	if_icmpeq	L016
	iconst_0
	goto	L017
L016:
	iconst_1
L017:
	ifeq	L015
;
; 056 catBasket[i]:=i+1
;
	getstatic	PurrscalDemo/catbasket [I
	getstatic	PurrscalDemo/i I
	getstatic	PurrscalDemo/i I
	iconst_1
	iadd
	iastore
;
; 057 i:=i+1
;
	getstatic	PurrscalDemo/i I
	iconst_1
	iadd
	putstatic	PurrscalDemo/i I
	goto	L014
L015:
;
; 060 i:=0
;
	iconst_0
	putstatic	PurrscalDemo/i I
;
; 062 while(i<=5)purrplayprintCats(catBasket[i])OWOi:=i+1OWOnap
;
L018:
	getstatic	PurrscalDemo/i I
	iconst_5
	if_icmple	L020
	iconst_0
	goto	L021
L020:
	iconst_1
L021:
	ifeq	L019
;
; 063 printCats(catBasket[i])
;
	getstatic	PurrscalDemo/catbasket [I
	getstatic	PurrscalDemo/i I
	iaload
	invokestatic	PurrscalDemo/printcats(I)V
;
; 064 i:=i+1
;
	getstatic	PurrscalDemo/i I
	iconst_1
	iadd
	putstatic	PurrscalDemo/i I
	goto	L018
L019:

	invokestatic	java/time/Instant/now()Ljava/time/Instant;
	astore_2
	aload_1
	aload_2
	invokestatic	java/time/Duration/between(Ljava/time/temporal/Temporal;Ljava/time/temporal/Temporal;)Ljava/time/Duration;
	invokevirtual	java/time/Duration/toMillis()J
	lstore_3
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"\n[%,d milliseconds execution time.]\n"
	iconst_1
	anewarray	java/lang/Object
	dup
	iconst_0
	lload_3
	invokestatic	java/lang/Long/valueOf(J)Ljava/lang/Long;
	aastore
	invokevirtual	java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;
	pop

	return

.limit locals 6
.limit stack 8
.end method
