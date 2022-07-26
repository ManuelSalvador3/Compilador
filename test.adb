procedure Prueba1 is
	
	integer1:Integer;
	integer2:Integer;
	integer3:Integer;
	integer4:Integer;
	integer5:Integer;
	
begin
	integer1:= 4 + 40;
   	integer2:= 40;
	integer3:= 20 * 4;
	integer4:= 20 / 5;
	integer5:= 14 - 2;

	Put_Line(integer1);
	Put_Line(integer5);

	while integer1 > integer2 loop
   		integer2:= 70;   	
   	end loop;

	Put_Line(integer2);
	--<
   	if integer3 > integer4 then
   		integer3:=88;
		--integer5:= 33;
   	end if;

   	--> 
   	--Prueba de comentario
	--integer3:Float;
	--integer4:Float;

	for integer1 in 1..10 loop
		integer1:= 10;
	end loop;

	integer2:= 71;   
	Put_Line(integer2);
end Prueba1;
