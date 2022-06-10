procedure prueba2 is
	
	integer1:Integer;
	integer2:Integer;
	integer3:Integer;
	integer4:Integer;
	float1: Float;
begin
	integer1:= 4 + 40;
   	integer2:= 47;
	integer3:= 60 * 1;
	integer4:= 10 / 2; -----Primer error, dividir por 0
	float1 := 2,2;
	
	--ERROR EN LA DEFINICION DEL IF
   	iff integer3 < integer2 then
   		integer4 := 69;
   	end if;

   	--Prueba de comentario
   	while integer1 > integer2 loop
   		integer2:= 70;   	
   	end loop;
	integer2:=  integer1 + float1;   
end Prueba2;


