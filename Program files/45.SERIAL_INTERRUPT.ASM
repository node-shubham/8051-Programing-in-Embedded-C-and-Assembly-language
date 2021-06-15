CSEG AT 0
	LJMP MAIN

CSEG AT 23H ; ISR FOR SERIAL INTERRUPT 	
	LJMP ISR

CSEG AT 30H
	MAIN:
	MOV TMOD, #0X20 ; Timer 0 mode 2 (auto reload) 
	MOV TH1, #-3	 ; baud rate: 9600  
	MOV SCON, #0X50 ; serial mode 1 
	MOV IE, #0X90
	SETB TR1	   ; run timer	
	MOV P0,#00H  ; making it o/p port
	MOV P1,#0FFH  ; making it i/p port  
	MOV P2,#00H  ; making it o/p port
	REP:
		MOV A, P1
		MOV P2, A
	SJMP REP	
	
	ISR:
	MOV A, SBUF
	MOV P0, A
	CLR RI
	RETI
END	