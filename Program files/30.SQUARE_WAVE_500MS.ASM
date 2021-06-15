CSEG AT 0  ; 500ms delay  SQUARE WAVE
	MOV TMOD, #01 ; 	T-0 MODE-1 : 16 BIT MODE
L1: MOV R1,#07      ; 1	(from sjmp : 458825 + (41176))
	CPL P1.5		; 1	(458826 + (41176))
	ACALL DELAY				; 2 = 2+ (total: 458828 + (41176)) ****
	SJMP L1			; 2	(from end : 458824 + (41176))
	DELAY: 
	MOV TL0, #00			; 2	= 2+
	MOV TH0, #00			; 2 = 4+
	SETB TR0				; 1 = 5+
	WAIT: JNB TF0, WAIT		; 65536 = 65541+
	CLR TR0					; 1	= 65542+	
	CLR TF0					; 1 = 65543+
	DJNZ R1, DELAY			; 2*7(Y) + 7(Y)*65543 = 458815+ 
	MOV TL0, #027H		; 2 = 458815+  
	MOV TH0, #05FH		; 2	= 458817+
	SETB TR0			; 1 = 458818+ 
	REM: JNB TF0, REM	; x + 458818
	CLR TR0			; 1 = 458819 + x(41176)
	CLR TF0			; 1 = 458820 + x(41176)
	RET				; 2 = 458822 + x(41176)
END	   		
	
	; 	RESULT: 500.018ms SQUARE WAVE