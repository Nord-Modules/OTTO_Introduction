//Used for Modbus communication with Ignition. Variables and code is used to initialize the mission in fleet
PROGRAM _INIT	

END_PROGRAM

PROGRAM _CYCLIC
(* This snippet is not necessary for prototyping and I am not sure how B&R handles overflow, in either case, overflow protection is a good practice!
	IF modbus.Create_mission_0 := 4294967295 THEN// maximum size of UINT (OVERFLOW PROTECTION)
		modbus.Create_mission_0 := 0;
	END_IF
	IF modbus.Create_mission_1 := 4294967295 THEN// maximum size of UINT (OVERFLOW PROTECTION)
		modbus.Create_mission_1 := 0;
	END_IF *)
	IF EDGEPOS (io.Mission_startButton) THEN
		counter := counter + 1;
	END_IF
	modbus.Mission_create_0 := counter  ;
	
END_PROGRAM
