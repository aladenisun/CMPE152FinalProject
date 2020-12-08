.class public ExampleSniff
.super java/lang/Object

.field private static _sysin Ljava/util/Scanner;
.field private static i I
.field private static j I
.field private static k I
.field private static p Z
.field private static q Z
.field private static str Ljava/lang/String;
.field private static txt Ljava/lang/String;
.field private static x F
.field private static y F

;
; Runtime input scanner
;
.method static <clinit>()V

	new	java/util/Scanner
	dup
	getstatic	java/lang/System/in Ljava/io/InputStream;
	invokespecial	java/util/Scanner/<init>(Ljava/io/InputStream;)V
	putstatic	ExampleSniff/_sysin Ljava/util/Scanner;
	return

.limit locals 0
.limit stack 3
.end method

;
; Main class constructor
;
.method public <init>()V
.var 0 is this LExampleSniff;

	aload_0
	invokespecial	java/lang/Object/<init>()V
	return

.limit locals 1
.limit stack 1
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

;
; 010 i:=1
;
	iconst_1
	putstatic	ExampleSniff/i I
;
; 011 j:=2
;
	iconst_2
	putstatic	ExampleSniff/j I
;
; 013 sniffi=jpawx:=3.14ignorex:=-5
;
	getstatic	ExampleSniff/i I
	getstatic	ExampleSniff/j I
	if_icmpeq	L002
	iconst_0
	goto	L003
L002:
	iconst_1
L003:
	ifeq	L004
;
; 013 x:=3.14
;
	ldc	3.14
	putstatic	ExampleSniff/x F
	goto	L001
L004:
;
; 014 x:=-5
;
	iconst_5
	ineg
	i2f
	putstatic	ExampleSniff/x F
L001:
;
; 016 sniffi<>jpawy:=3.14ignorey:=-5
;
	getstatic	ExampleSniff/i I
	getstatic	ExampleSniff/j I
	if_icmpne	L006
	iconst_0
	goto	L007
L006:
	iconst_1
L007:
	ifeq	L008
;
; 016 y:=3.14
;
	ldc	3.14
	putstatic	ExampleSniff/y F
	goto	L005
L008:
;
; 017 y:=-5
;
	iconst_5
	ineg
	i2f
	putstatic	ExampleSniff/y F
L005:
;
; 019 mrrr('i = ',i,', j = ',j,', x = ',x:5:2,', y = ',y:5:2)
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"i = %d, j = %d, x = %5.2f, y = %5.2f\n"
	iconst_4
	anewarray	java/lang/Object
	dup
	iconst_0
	getstatic	ExampleSniff/i I
	invokestatic	java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	dup
	iconst_1
	getstatic	ExampleSniff/j I
	invokestatic	java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	dup
	iconst_2
	getstatic	ExampleSniff/x F
	invokestatic	java/lang/Float/valueOf(F)Ljava/lang/Float;
	aastore
	dup
	iconst_3
	getstatic	ExampleSniff/y F
	invokestatic	java/lang/Float/valueOf(F)Ljava/lang/Float;
	aastore
	invokevirtual	java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;
	pop
;
; 021 sniffi=jpawplayx:=-7napignoreplayx:=8OWOnap
;
	getstatic	ExampleSniff/i I
	getstatic	ExampleSniff/j I
	if_icmpeq	L010
	iconst_0
	goto	L011
L010:
	iconst_1
L011:
	ifeq	L012
;
; 022 x:=-7
;
	bipush	7
	ineg
	i2f
	putstatic	ExampleSniff/x F
	goto	L009
L012:
;
; 025 x:=8
;
	bipush	8
	i2f
	putstatic	ExampleSniff/x F
L009:
;
; 028 sniffi<>jpawplayy:=14napignoreplayy:=-2OWOnap
;
	getstatic	ExampleSniff/i I
	getstatic	ExampleSniff/j I
	if_icmpne	L014
	iconst_0
	goto	L015
L014:
	iconst_1
L015:
	ifeq	L016
;
; 029 y:=14
;
	bipush	14
	i2f
	putstatic	ExampleSniff/y F
	goto	L013
L016:
;
; 032 y:=-2
;
	iconst_2
	ineg
	i2f
	putstatic	ExampleSniff/y F
L013:
;
; 035 mrrr('i = ',i,', j = ',j,', x = ',x:5:2,', y = ',y:5:2)
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"i = %d, j = %d, x = %5.2f, y = %5.2f\n"
	iconst_4
	anewarray	java/lang/Object
	dup
	iconst_0
	getstatic	ExampleSniff/i I
	invokestatic	java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	dup
	iconst_1
	getstatic	ExampleSniff/j I
	invokestatic	java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	dup
	iconst_2
	getstatic	ExampleSniff/x F
	invokestatic	java/lang/Float/valueOf(F)Ljava/lang/Float;
	aastore
	dup
	iconst_3
	getstatic	ExampleSniff/y F
	invokestatic	java/lang/Float/valueOf(F)Ljava/lang/Float;
	aastore
	invokevirtual	java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;
	pop
;
; 037 p:=i=j
;
	getstatic	ExampleSniff/i I
	getstatic	ExampleSniff/j I
	if_icmpeq	L017
	iconst_0
	goto	L018
L017:
	iconst_1
L018:
	putstatic	ExampleSniff/p Z
;
; 038 sniffppawx:=55.55ignoreplayx:=77.77OWOy:=88.88OWOnap
;
	getstatic	ExampleSniff/p Z
	ifeq	L020
;
; 038 x:=55.55
;
	ldc	55.55
	putstatic	ExampleSniff/x F
	goto	L019
L020:
;
; 040 x:=77.77
;
	ldc	77.77
	putstatic	ExampleSniff/x F
;
; 041 y:=88.88
;
	ldc	88.88
	putstatic	ExampleSniff/y F
L019:
;
; 044 mrrr('i = ',i,', j = ',j,', x = ',x:5:2,', y = ',y:5:2)
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"i = %d, j = %d, x = %5.2f, y = %5.2f\n"
	iconst_4
	anewarray	java/lang/Object
	dup
	iconst_0
	getstatic	ExampleSniff/i I
	invokestatic	java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	dup
	iconst_1
	getstatic	ExampleSniff/j I
	invokestatic	java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	dup
	iconst_2
	getstatic	ExampleSniff/x F
	invokestatic	java/lang/Float/valueOf(F)Ljava/lang/Float;
	aastore
	dup
	iconst_3
	getstatic	ExampleSniff/y F
	invokestatic	java/lang/Float/valueOf(F)Ljava/lang/Float;
	aastore
	invokevirtual	java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;
	pop
;
; 046 q:=i<=j
;
	getstatic	ExampleSniff/i I
	getstatic	ExampleSniff/j I
	if_icmple	L021
	iconst_0
	goto	L022
L021:
	iconst_1
L022:
	putstatic	ExampleSniff/q Z
;
; 047 k:=10
;
	bipush	10
	putstatic	ExampleSniff/k I
;
; 049 sniffppawi:=33ignoresniffrollqpawi:=44ignoresniffi=jpawi:=55ignorei:=6
;
	getstatic	ExampleSniff/p Z
	ifeq	L024
;
; 049 i:=33
;
	bipush	33
	putstatic	ExampleSniff/i I
	goto	L023
L024:
;
; 049 sniffrollqpawi:=44ignoresniffi=jpawi:=55ignorei:=6
;
	getstatic	ExampleSniff/q Z
	iconst_1
	ixor
	ifeq	L026
;
; 049 i:=44
;
	bipush	44
	putstatic	ExampleSniff/i I
	goto	L025
L026:
;
; 049 sniffi=jpawi:=55ignorei:=6
;
	getstatic	ExampleSniff/i I
	getstatic	ExampleSniff/j I
	if_icmpeq	L028
	iconst_0
	goto	L029
L028:
	iconst_1
L029:
	ifeq	L030
;
; 049 i:=55
;
	bipush	55
	putstatic	ExampleSniff/i I
	goto	L027
L030:
;
; 049 i:=6
;
	bipush	6
	putstatic	ExampleSniff/i I
L027:
L025:
L023:
;
; 050 sniffrollppawsniffqpawj:=9ignorej:=-9
;
	getstatic	ExampleSniff/p Z
	iconst_1
	ixor
	ifeq	L031
;
; 050 sniffqpawj:=9ignorej:=-9
;
	getstatic	ExampleSniff/q Z
	ifeq	L033
;
; 050 j:=9
;
	bipush	9
	putstatic	ExampleSniff/j I
	goto	L032
L033:
;
; 050 j:=-9
;
	bipush	9
	ineg
	putstatic	ExampleSniff/j I
L032:
L031:
;
; 051 sniffppawsniffqpawk:=11ignorek:=12
;
	getstatic	ExampleSniff/p Z
	ifeq	L034
;
; 051 sniffqpawk:=11ignorek:=12
;
	getstatic	ExampleSniff/q Z
	ifeq	L036
;
; 051 k:=11
;
	bipush	11
	putstatic	ExampleSniff/k I
	goto	L035
L036:
;
; 051 k:=12
;
	bipush	12
	putstatic	ExampleSniff/k I
L035:
L034:
;
; 053 mrrr('i = ',i,', j = ',j,', x = ',x:5:2,', y = ',y:5:2)
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"i = %d, j = %d, x = %5.2f, y = %5.2f\n"
	iconst_4
	anewarray	java/lang/Object
	dup
	iconst_0
	getstatic	ExampleSniff/i I
	invokestatic	java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	dup
	iconst_1
	getstatic	ExampleSniff/j I
	invokestatic	java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	dup
	iconst_2
	getstatic	ExampleSniff/x F
	invokestatic	java/lang/Float/valueOf(F)Ljava/lang/Float;
	aastore
	dup
	iconst_3
	getstatic	ExampleSniff/y F
	invokestatic	java/lang/Float/valueOf(F)Ljava/lang/Float;
	aastore
	invokevirtual	java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;
	pop
;
; 054 mrrr('k = ',k)
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"k = %d\n"
	iconst_1
	anewarray	java/lang/Object
	dup
	iconst_0
	getstatic	ExampleSniff/k I
	invokestatic	java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	invokevirtual	java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;
	pop
;
; 056 mrrr
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	invokevirtual	java/io/PrintStream.println()V
;
; 057 sniffrollppawmeow('Good-bye')
;
	getstatic	ExampleSniff/p Z
	iconst_1
	ixor
	ifeq	L037
;
; 057 meow('Good-bye')
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"Good-bye"
	invokevirtual	java/io/PrintStream/print(Ljava/lang/String;)V
L037:
;
; 058 sniffrollppawsniffqpawsniffi<>jpawsniffx<ypawmrrr(', world!')
;
	getstatic	ExampleSniff/p Z
	iconst_1
	ixor
	ifeq	L038
;
; 058 sniffqpawsniffi<>jpawsniffx<ypawmrrr(', world!')
;
	getstatic	ExampleSniff/q Z
	ifeq	L039
;
; 058 sniffi<>jpawsniffx<ypawmrrr(', world!')
;
	getstatic	ExampleSniff/i I
	getstatic	ExampleSniff/j I
	if_icmpne	L041
	iconst_0
	goto	L042
L041:
	iconst_1
L042:
	ifeq	L040
;
; 058 sniffx<ypawmrrr(', world!')
;
	getstatic	ExampleSniff/x F
	getstatic	ExampleSniff/y F
	fcmpg
	iflt	L044
	iconst_0
	goto	L045
L044:
	iconst_1
L045:
	ifeq	L043
;
; 058 mrrr(', world!')
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	", world!\n"
	invokevirtual	java/io/PrintStream/print(Ljava/lang/String;)V
L043:
L040:
L039:
L038:

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
.limit stack 7
.end method
