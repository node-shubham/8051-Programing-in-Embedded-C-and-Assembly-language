CSEG AT 0  ;   SQUARE WAVE 11.0592MHZ
	MOV TMOD, #01 ; 	T-0 MODE-1 : 16 BIT MODE
L1: MOV R1,#14      ; 1	
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
	DJNZ R1, DELAY			; 2*14 + 14*65543 = 917630+ 
	MOV TL0, #89H 	 		; 2  
	MOV TH0, #0F0H			; 2
	SETB TR0				; 1 
	REM: JNB TF0, REM		; x + 1 + 917635
	CLR TR0					; 1
	CLR TF0					; 1
	RET						; 2
END	   		
	
	;	 x + 917640 + 2 = x + 917642
	; =>(x + 917642)*1.085069444 = 1000000
	; => x + 917642 = 921600
	; => x = 3958
	; 	RESULT: 1000.031 ms delay under delay subroutine
	; 	921600 machine cycles = 1000000uS
	; 	considering instruction time : 1.085069444
	; 	-31uS  