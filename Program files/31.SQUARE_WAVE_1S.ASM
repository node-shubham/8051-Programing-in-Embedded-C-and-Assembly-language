CSEG AT 0  ; 1s delay  SQUARE WAVE
	MOV TMOD, #01 ; 	T-0 MODE-1 : 16 BIT MODE
L1: MOV R1,#0FH      ; 1	(from sjmp : 983187 + x())
	CPL P1.5		; 1	(983188 + x())
	ACALL DELAY				; 2 = (total: 983190+ x(16810)) ****
	SJMP L1			; 2	(from end : 983186 + x())
	DELAY: 
	MOV TL0, #00			; 2	= 2+
	MOV TH0, #00			; 2 = 4+
	SETB TR0				; 1 = 5+
	WAIT: JNB TF0, WAIT		; 65536 = 65541+
	CLR TR0					; 1	= 65542+	
	CLR TF0					; 1 = 65543+
	DJNZ R1, DELAY			; 2*15(Y) + 15(Y)*65543 = 983175+ 
	MOV TL0, #055H		; 2  	(SETTING TH0,TH0 FOR X=16810) 
	MOV TH0, #0BEH		; 2	
	SETB TR0			; 1 =  983180+
	REM: JNB TF0, REM	; x + 983180+
	CLR TR0			; 1 
	CLR TF0			; 1 
	RET				; 2 = 983184 + x()
END	   		
	
	; 	RESULT: 1000.028ms SQUARE WAVE   		
	
	