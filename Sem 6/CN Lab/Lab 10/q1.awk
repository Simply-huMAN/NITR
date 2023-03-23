BEGIN {
	cbr=0;
	ftp=0;
}

{
	if($5=="tcp"){
		ftp=ftp+1;
	}
	if($5=="cbr"){
		cbr=cbr+1;
	}
}

END {
	printf("------------Total number of packets-------------\n");
	printf("Number of ftp packets: %d\n",ftp);
	printf("Number of cbr packets: %d\n",cbr);
}
