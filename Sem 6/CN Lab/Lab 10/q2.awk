BEGIN {
		max_time_ftp = 0;
		max_time_cbr = 0;
}
{
	if($5=="tcp"){
		if($1=="r" && $4=="8"){
			time_taken = $2 - $10;
			if(time_taken>max_time_ftp) max_time_ftp = time_taken;
		}
	}
}
{
	if($1=="+" && $4=="8"){
		time_taken = $2-$10;
		if(time_taken>max_time_cbr) max_time_cbr = time_taken;
	}
}
END{
	print("Max time taken by ftp packets: ",max_time_ftp);
	print("Max time taken by cbr packets: ",max_time_cbr);
}
