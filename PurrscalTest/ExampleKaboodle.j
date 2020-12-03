.class public ExampleKaboodle
.super java/lang/Object

.field private static _sysin Ljava/util/Scanner;
.field private static i I
.field private static j I
.field private static mykaboodle [I

;
; Runtime input scanner
;
.method static <clinit>()V

	new	java/util/Scanner
	dup
	getstatic	java/lang/System/in Ljava/io/InputStream;
	invokespecial	java/util/Scanner/<init>(Ljava/io/InputStream;)V
	putstatic	ExampleKaboodle/_sysin Ljava/util/Scanner;
	return

.limit locals 0
.limit stack 3
.end method

;
; Main class constructor
;
.method public <init>()V
.var 0 is this LExampleKaboodle;

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

	bipush	10
	newarray	int
	putstatic	ExampleKaboodle/mykaboodle [I

;
; 011 i:=0
;
	iconst_0
	putstatic	ExampleKaboodle/i I
;
; 012 whilei<10purrplaymyKaboodle[i]:=iOWOi:=i+1OWOnap
;
L001:
	getstatic	ExampleKaboodle/i I
	bipush	10
	if_icmplt	L003
	iconst_0
	goto	L004
L003:
	iconst_1
L004:
	ifeq	L002
;
; 013 myKaboodle[i]:=i
;
	getstatic	ExampleKaboodle/mykaboodle [I
	getstatic	ExampleKaboodle/i I
	getstatic	ExampleKaboodle/i I
	iastore
;
; 014 i:=i+1
;
	getstatic	ExampleKaboodle/i I
	iconst_1
	iadd
	putstatic	ExampleKaboodle/i I
	goto	L001
L002:
;
; 017 i:=0
;
	iconst_0
	putstatic	ExampleKaboodle/i I
;
; 018 j:=0
;
	iconst_0
	putstatic	ExampleKaboodle/j I
;
; 020 whilei<10purrplaywhilej<myKaboodle[i]purrplaymeow('=^.^= ')OWOj:=j+1OW ...
;
L005:
	getstatic	ExampleKaboodle/i I
	bipush	10
	if_icmplt	L007
	iconst_0
	goto	L008
L007:
	iconst_1
L008:
	ifeq	L006
;
; 022 whilej<myKaboodle[i]purrplaymeow('=^.^= ')OWOj:=j+1OWOnap
;
L009:
	getstatic	ExampleKaboodle/j I
	getstatic	ExampleKaboodle/mykaboodle [I
	getstatic	ExampleKaboodle/i I
	iaload
	if_icmplt	L011
	iconst_0
	goto	L012
L011:
	iconst_1
L012:
	ifeq	L010
;
; 023 meow('=^.^= ')
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"=^.^= "
	invokevirtual	java/io/PrintStream/print(Ljava/lang/String;)V
;
; 024 j:=j+1
;
	getstatic	ExampleKaboodle/j I
	iconst_1
	iadd
	putstatic	ExampleKaboodle/j I
	goto	L009
L010:
;
; 027 sniffj<>0pawplaymrrrOWOnap
;
	getstatic	ExampleKaboodle/j I
	iconst_0
	if_icmpne	L014
	iconst_0
	goto	L015
L014:
	iconst_1
L015:
	ifeq	L013
;
; 028 mrrr
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	invokevirtual	java/io/PrintStream.println()V
L013:
;
; 030 j:=0
;
	iconst_0
	putstatic	ExampleKaboodle/j I
;
; 031 i:=i+1
;
	getstatic	ExampleKaboodle/i I
	iconst_1
	iadd
	putstatic	ExampleKaboodle/i I
	goto	L005
L006:

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
