PROGRAM _INIT
	(* Insert code here *)
	io.handshake.PA_FAULT_STATUS := TRUE; //No error in the beginning
	io.handshake.ROBOT_ENABLE := TRUE; //Attachnment indicates OTTO has control
	
	
	timer.PT := T#1s;
		
END_PROGRAM

PROGRAM _CYCLIC
	
	//OTTO GIVES CONTROL TO ATTACHMENT
	IF io.handshake.PA_ENABLE THEN 
		io.handshake.ROBOT_ENABLE := FALSE;
		io.LED := TRUE;
		timer.IN := TRUE;
	END_IF;
	
	//ATTACHMENT GIVES CONTROL BACK TO OTTO
		IF timer.Q THEN
			timer.IN := FALSE;
			io.handshake.ROBOT_ENABLE := TRUE;
			io.LED := FALSE;
		END_IF
	
	timer();
END_PROGRAM
