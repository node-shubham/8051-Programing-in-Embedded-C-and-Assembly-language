CSEG AT 0  ; 1ms delay 11.0592MHZ
	MOV TMOD, #01 	; 2 	T-0 MODE-1 : 16 BIT MODE
	L1: 
	MOV TL0, #75h	; 2		[8]
	MOV TH0, #0FCh	; 2		[9]
	CPL P1.5		; 1		[10]
	ACALL DELAY ; 2			[1]
	SJMP L1		; 2			[7]
	DELAY: 
	SETB TR0	; 1			[2]
	WAIT: JNB TF0, WAIT ;	[3] X+1
	CLR TR0		; 1			[4]
	CLR TF0		; 1			[5]
	RET			; 2			[6]
END	   		
		; 2+1+X+1+1+1+2+2+2+2+1 = (15+X)*1.085uS 
		; => (15+X)*1.085uS = 1000uS
		; => (15+X) = 921.66
		; => 	 X = 906
		; so, 906 = 0x038A
		; 0xFFFF - 0x038A = 0xFC75