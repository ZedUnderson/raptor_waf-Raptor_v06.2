#include "blacklist.h"
#include "mem_ops.h"
#include "utils.h"
#include "BSD/strsec.h"

//read lines of file
bool blacklist_ip(char * addr)
{
	FILE * arq;
	bool at_list=false;

	arq = fopen("config/blacklist_ip.txt", "r");

	if( arq == NULL )
	{

		DEBUG("error to open() file"); 	 
		return false;
	}

	char line[128];

	while( fgets(line,sizeof line,arq) && at_list==false )
	{    
		if(strnstr(line,addr,128))
			at_list=true;
	}

	if( fclose(arq) == EOF )
	{
		DEBUG("Error in close() file config/blacklist_ip.txt ");
		return false;
	}
	arq=NULL;


	return at_list;
}


