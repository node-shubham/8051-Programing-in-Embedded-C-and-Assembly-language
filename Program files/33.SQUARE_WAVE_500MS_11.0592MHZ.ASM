CSEG AT 0  ;   SQUARE WAVE 11.0592MHZ
	MOV TMOD, #01 ; 	T-0 MODE-1 : 16 BIT MODE
L1: MOV R1,#07      ; 1	
	CPL P1.5		; 1	
	ACALL DELAY				; 2+
	SJMP L1			; 2	
	DELAY: 
	MOV TL0, #00			; 2	
	MOV TH0, #00			; 2 
	SETB TR0				; 1
	WAIT: JNB TF0, WAIT		; 65536 
	CLR TR0					; 1		
	CLR TF0					; 1 
	DJNZ R1, DELAY			; 2*7 + 7*65543 = 458815+ 
	MOV TL0, #4AH ; 5A		; 2  
	MOV TH0, #0F8H			; 2
	SETB TR0				; 1 
	REM: JNB TF0, REM		; x + 1 + 458820
	CLR TR0					; 1
	CLR TF0					; 1
	RET						; 2
END	   		
	
	;	 x + 458820 + 5 + 2 = x + 458827
	; =>(x + 458827)*1.085069444 = 500000
	; => x + 458827 = 460800
	; => x = 1973
	; 	RESULT: 500.016ms delay under delay subroutine
	; 	450800 machine cycles = 500000uS
	; 	considering instruction time : 1.085069444